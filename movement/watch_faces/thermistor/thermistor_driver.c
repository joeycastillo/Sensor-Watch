#include "thermistor_driver.h"
#include "watch.h"

#define THERMISTOR_B_COEFFICIENT (3950.0)
#define THERMISTOR_NOMINAL_TEMPERATURE (25.0)
#define THERMISTOR_NOMINAL_RESISTANCE (10000.0)
#define THERMISTOR_SERIES_RESISTANCE (10000.0)

// TODO: we really need a math library.
uint32_t msb(uint32_t v);
double ln(double y);

void thermistor_driver_enable() {
    // Enable the ADC peripheral, which we'll use to read the thermistor value.
    watch_enable_adc();
    // Enable analog circuitry on pin A1, which is tied to the thermistor resistor divider.
    watch_enable_analog_input(A1);
    // Enable digital output on A0, which is the power to the thermistor circuit.
    watch_enable_digital_output(A0);
}

void thermistor_driver_disable() {
    // Enable the ADC peripheral, which we'll use to read the thermistor value.
    watch_disable_adc();
    // Disable analog circuitry on pin A1 to save power.
    watch_disable_analog_input(A1);
    // Disable A0's output circuitry.
    watch_disable_digital_output(A0);
}

float thermistor_driver_get_temperature() {
    // set A0 high to power the thermistor circuit.
    watch_set_pin_level(A0, true);
    // get the pin level
    uint16_t val = watch_get_analog_pin_level(A1);
    // and then set A0 low to power down the thermistor circuit.
    watch_set_pin_level(A0, false);

    double reading = (double)val;
    reading = (1023.0 * THERMISTOR_SERIES_RESISTANCE) / (reading / 64.0);
    reading -= THERMISTOR_SERIES_RESISTANCE;
    reading = reading / THERMISTOR_NOMINAL_RESISTANCE;
    reading = ln(reading);
    reading /= THERMISTOR_B_COEFFICIENT;
    reading += 1.0 / (THERMISTOR_NOMINAL_TEMPERATURE + 273.15);
    reading = 1.0 / reading;
    reading -= 273.15;

    return reading;
}

uint32_t msb(uint32_t v) {
  static const int pos[32] = {0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9};
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v = (v >> 1) + 1;
  return pos[(v * 0x077CB531UL) >> 27];
}

double ln(double y) {
    int log2;
    double divisor, x, result;

    log2 = msb((int)y); // See: https://stackoverflow.com/a/4970859/6630230
    divisor = (double)(1 << log2);
    x = y / divisor;    // normalized value between [1.0, 2.0]

    result = -1.7417939 + (2.8212026 + (-1.4699568 + (0.44717955 - 0.056570851 * x) * x) * x) * x;
    result += ((double)log2) * 0.69314718; // ln(2) = 0.69314718

    return result;
}

