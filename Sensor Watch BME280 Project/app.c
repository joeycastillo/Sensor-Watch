#include <stdio.h>
#include <string.h>
#include "watch.h"
#include "app.h"
#include "bme280.h"

typedef enum ApplicationMode {
    MODE_TEMPERATURE = 0,
    MODE_HUMIDITY,
    MODE_OFF,
} ApplicationMode;

typedef struct ApplicationState {
    ApplicationMode mode;
    bool light_on;
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint8_t dig_H1;
    int16_t dig_H2;
    uint8_t dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t dig_H6;
} ApplicationState;

ApplicationState application_state;


void cb_mode_pressed();
void cb_tick();

float read_temperature(int32_t *p_t_fine);
float read_humidity(int32_t t_fine);

/**
 * @brief Zeroes out the application state struct.
 */
void app_init() {
    memset(&application_state, 0, sizeof(application_state));
}

/**
 * @todo stash the BME280's calibration values in backup memory so we don't have to ask again
 */
void app_wake_from_deep_sleep() {
}

/**
 * Enables the MODE button, the display and the sensor, and grabs calibration data.
 */
void app_setup() {
    watch_enable_buttons();
    watch_register_button_callback(BTN_MODE, cb_mode_pressed);

    // pin A0 powers the sensor on this board.
    watch_enable_digital_output(A0);
    watch_set_pin_level(A0, true);
    delay_ms(10);

    watch_enable_i2c();

    watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_SOFTRESET, BME280_SOFT_RESET_CODE);
    delay_ms(10);
    application_state.dig_T1 = watch_i2c_read16(BME280_ADDRESS, BME280_REGISTER_DIG_T1);
    application_state.dig_T2 = (int16_t)watch_i2c_read16(BME280_ADDRESS, BME280_REGISTER_DIG_T2);
    application_state.dig_T3 = (int16_t)watch_i2c_read16(BME280_ADDRESS, BME280_REGISTER_DIG_T3);
    application_state.dig_H1 = watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H1);
    application_state.dig_H2 = (int16_t)watch_i2c_read16(BME280_ADDRESS, BME280_REGISTER_DIG_H2);
    application_state.dig_H3 = watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H3);
    application_state.dig_H4 = ((int8_t)watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H4) << 4) |
                                (watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H4 + 1) & 0xF);
    application_state.dig_H5 = ((int8_t)watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H5 + 1) << 4) |
                                (watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H5) >> 4);
    application_state.dig_H6 = (int8_t)watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_DIG_H6);

    watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_CONTROL_HUMID, BME280_CONTROL_HUMID_SAMPLING_X16);
    watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_CONTROL, BME280_CONTROL_TEMPERATURE_SAMPLING_X16 |
                                                              BME280_CONTROL_PRESSURE_SAMPLING_NONE |
                                                              BME280_CONTROL_MODE_FORCED);

    watch_enable_display();

    watch_register_tick_callback(cb_tick);
}

/**
 * Nothing to do here.
 */
void app_prepare_for_sleep() {
}

/**
 * @todo restore the BME280's calibration values from backup memory
 */
void app_wake_from_sleep() {
}

/**
 * Displays the temperature and humidity on screen, or a string indicating no measurements are being taken.
 */
bool app_loop() {
    int32_t t_fine;
    float temperature;
    float humidity;
    char buf[11] = {0};

    switch (application_state.mode) {
        case MODE_TEMPERATURE:
            // take one reading
            watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_CONTROL, BME280_CONTROL_TEMPERATURE_SAMPLING_X16 |
                                                                      BME280_CONTROL_MODE_FORCED);
            // wait for reading to finish
            while(watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_STATUS) & BME280_STATUS_UPDATING_MASK);
            temperature = read_temperature(NULL);
            sprintf(buf, "TE  %4.1f#C", temperature);
            watch_display_string(buf, 0);
            watch_clear_pixel(1, 16);
            break;
        case MODE_HUMIDITY:
            // take one reading
            watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_CONTROL, BME280_CONTROL_TEMPERATURE_SAMPLING_X16 |
                                                                      BME280_CONTROL_MODE_FORCED);
            // wait for reading to finish
            while(watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_STATUS) & BME280_STATUS_UPDATING_MASK);
            temperature = read_temperature(&t_fine);
            humidity = read_humidity(t_fine);
            sprintf(buf, "HU  rH %3d", (int)humidity);
            watch_display_string(buf, 0);
            watch_set_pixel(1, 16);
            break;
        case MODE_OFF:
            watch_display_string("    Sleep ", 0);
            watch_clear_pixel(1, 16);
    }

    return true;
}

/**
 * Reads the temperature from the BME280
 * @param p_t_fine - an optional pointer to an int32_t; if provided, the t_fine measurement
 *                   (required for humidity calculation) will be returned by reference.
 *                   Pass in NULL if you do not care about this value.
 * @return a float indicating the temperature in degrees celsius.
 */
float read_temperature(int32_t *p_t_fine) {
    // read24 reads the bytes into a uint32 which works for little-endian values (MSB is 0)
    uint32_t raw_data = watch_i2c_read24(BME280_ADDRESS, BME280_REGISTER_TEMP_DATA) >> 8;
    // alas the sensor's register layout is big-endian-ish, with a nibble of zeroes at the end of the LSB.
    // this line shuffles everything back into place (swaps LSB and MSB and shifts the zeroes off the end)
    int32_t adc_value = (((raw_data >> 16) | (raw_data & 0xFF00) | (raw_data << 16)) & 0xFFFFFF) >> 4;

    // this bit is cribbed from Adafruit's BME280 driver. support their open source efforts by buying some stuff!
    int32_t var1 = ((((adc_value >> 3) - ((int32_t)application_state.dig_T1 << 1))) * ((int32_t)application_state.dig_T2)) >> 11;
    int32_t var2 = (((((adc_value >> 4) - ((int32_t)application_state.dig_T1)) * ((adc_value >> 4) - ((int32_t)application_state.dig_T1))) >> 12) * ((int32_t)application_state.dig_T3)) >> 14;
    int32_t t_fine = var1 + var2;

    // if we got a pointer to a t_fine, return it by reference (for humidity calculation).
    if (p_t_fine != NULL) *p_t_fine = t_fine;

    return ((t_fine * 5 + 128) >> 8) / 100.0;
}

/**
 * Reads the humidity from the BME280
 * @param t_fine - the t_fine measurement from a call to read_temperature
 * @return a float indicating the relative humidity as a percentage from 0-100.
 * @todo the returned value is glitchy, need to fix.
 */
float read_humidity(int32_t t_fine) {
    int32_t adc_value = watch_i2c_read16(BME280_ADDRESS, BME280_REGISTER_HUMID_DATA);
    // the sensor returns this as big-endian, so swap the bytes.
    adc_value = (adc_value >> 8) | (adc_value << 8);

    // again, cribbed from Adafruit's BME280 driver. they sell a great breakout board for this sensor!
    int32_t v_x1_u32r = v_x1_u32r = (t_fine - ((int32_t)76800));
    v_x1_u32r = (((((adc_value << 14) - (((int32_t)application_state.dig_H4) << 20) - (((int32_t)application_state.dig_H5) * v_x1_u32r)) +
                ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)application_state.dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)application_state.dig_H3)) >> 11) +
                ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)application_state.dig_H2) + 8192) >> 14));
    v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)application_state.dig_H1)) >> 4));
    v_x1_u32r = (v_x1_u32r < 0) ? 0 : v_x1_u32r;
    v_x1_u32r = (v_x1_u32r > 419430400) ? 419430400 : v_x1_u32r;
    float h = (v_x1_u32r >> 12);

    return h / 1024.0;
}

void cb_mode_pressed() {
    application_state.mode = (application_state.mode + 1) % 3;
}

void cb_tick() {
}

