#include "thermistor_driver.h"
#include "watch.h"
#include "watch_utility.h"

void thermistor_driver_enable() {
    // Enable the ADC peripheral, which we'll use to read the thermistor value.
    watch_enable_adc();
    // Enable analog circuitry on the sense pin, which is tied to the thermistor resistor divider.
    watch_enable_analog_input(THERMISTOR_SENSE_PIN);
    // Enable digital output on the enable pin, which is the power to the thermistor circuit.
    watch_enable_digital_output(THERMISTOR_ENABLE_PIN);
    // and make sure it's off.
    watch_set_pin_level(THERMISTOR_ENABLE_PIN, !THERMISTOR_ENABLE_VALUE);
}

void thermistor_driver_disable() {
    // Disable the ADC peripheral.
    watch_disable_adc();
    // Disable analog circuitry on the sense pin to save power.
    watch_disable_analog_input(THERMISTOR_SENSE_PIN);
    // Disable the enable pin's output circuitry.
    watch_disable_digital_output(THERMISTOR_ENABLE_PIN);
}

float thermistor_driver_get_temperature() {
    // set the enable pin to the level that powers the thermistor circuit.
    watch_set_pin_level(THERMISTOR_ENABLE_PIN, THERMISTOR_ENABLE_VALUE);
    // get the sense pin level
    uint16_t value = watch_get_analog_pin_level(THERMISTOR_SENSE_PIN);
    // and then set the enable pin to the opposite value to power down the thermistor circuit.
    watch_set_pin_level(THERMISTOR_ENABLE_PIN, !THERMISTOR_ENABLE_VALUE);

    return watch_utility_thermistor_temperature(value, THERMISTOR_HIGH_SIDE, THERMISTOR_B_COEFFICIENT, THERMISTOR_NOMINAL_TEMPERATURE, THERMISTOR_NOMINAL_RESISTANCE, THERMISTOR_SERIES_RESISTANCE);
}
