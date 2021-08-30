#include <stdio.h>
#include <string.h>
#include <math.h>
#include "watch.h"
#include "bme280.h"

#include "app.h"

ApplicationState application_state;
char buf[16] = {0};

/**
 * @brief Zeroes out the application state struct.
 */
void app_init() {
    memset(&application_state, 0, sizeof(application_state));
}

void app_wake_from_deep_sleep() {
    // This app does not support deep sleep mode.
}

void app_setup() {
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    if (date_time.date.year < 2020) {
        date_time.date.year = 2020;
        watch_set_date_time(date_time);
    }

    watch_enable_buttons();
    watch_register_button_callback(BTN_MODE, cb_mode_pressed);
    watch_register_button_callback(BTN_LIGHT, cb_light_pressed);
    watch_register_button_callback(BTN_ALARM, cb_alarm_pressed);

    watch_enable_buzzer();
    watch_enable_led(false);

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

    watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_CONTROL_HUMID, BME280_CONTROL_HUMID_SAMPLING_NONE);
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
    // play a beep if the mode has changed in response to a user's press of the MODE button
    if (application_state.mode_changed) {
        // low note for nonzero case, high note for return to clock
        watch_buzzer_play_note(application_state.mode ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 100);
        application_state.mode_changed = false;
    }

    // If the user is not in clock mode and the mode timeout has expired, return them to clock mode
    if (application_state.mode != MODE_CLOCK && application_state.mode_ticks == 0) {
        application_state.mode = MODE_CLOCK;
        application_state.mode_changed = true;
    }

    // If the LED is off and should be on, turn it on
    if (application_state.light_ticks > 0 && !application_state.led_on) {
        watch_set_led_green();
        application_state.led_on = true;
    }

    // if the LED is on and should be off, turn it off
    if (application_state.led_on && application_state.light_ticks == 0) {
        // unless the user is holding down the LIGHT button, in which case, give them more time.
        if (watch_get_pin_level(BTN_LIGHT)) {
            application_state.light_ticks = 3;
        } else {
            watch_set_led_off();
            application_state.led_on = false;
        }
    }

    switch (application_state.mode) {
        case MODE_CLOCK:
            do_clock_mode();
            break;
        case MODE_TEMP:
            do_temp_mode();
            break;
        case MODE_LOG:
            do_log_mode();
            break;
        case MODE_PREFS:
            do_prefs_mode();
            break;
        case MODE_SET:
            do_set_time_mode();
            break;
        case NUM_MODES:
            // dummy case, just silences a warning
            break;
    }

    application_state.mode_changed = false;

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

    if (application_state.is_fahrenheit) {
        return (((t_fine * 5 + 128) >> 8) / 100.0) * 1.8 + 32;
    } else {
        return ((t_fine * 5 + 128) >> 8) / 100.0;
    }
}

/**
 * Reads the humidity from the BME280
 * @param t_fine - the t_fine measurement from a call to read_temperature
 * @return a float indicating the relative humidity as a percentage from 0-100.
 * @todo the returned value is glitchy, need to fix.
 */
float read_humidity(int32_t t_fine) {
    int32_t adc_value = watch_i2c_read16(BME280_ADDRESS, BME280_REGISTER_HUMID_DATA);

    // again, cribbed from Adafruit's BME280 driver. they sell a great breakout board for this sensor!
    int32_t v_x1_u32r = (t_fine - ((int32_t)76800));
    v_x1_u32r = (((((adc_value << 14) - (((int32_t)application_state.dig_H4) << 20) - (((int32_t)application_state.dig_H5) * v_x1_u32r)) +
                ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)application_state.dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)application_state.dig_H3)) >> 11) +
                ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)application_state.dig_H2) + 8192) >> 14));
    v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)application_state.dig_H1)) >> 4));
    v_x1_u32r = (v_x1_u32r < 0) ? 0 : v_x1_u32r;
    v_x1_u32r = (v_x1_u32r > 419430400) ? 419430400 : v_x1_u32r;
    float h = (v_x1_u32r >> 12);

    return h / 1024.0;
}

void log_data() {
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    uint8_t hour = date_time.time.hour;
    int8_t temperature = read_temperature(NULL);

    for(int i = 0; i < MAX_DATA_POINTS - 1; i++) {
        application_state.logged_data[i] = application_state.logged_data[i + 1];
    }
    application_state.logged_data[MAX_DATA_POINTS - 1].is_valid = true;
    application_state.logged_data[MAX_DATA_POINTS - 1].hour = hour;
    application_state.logged_data[MAX_DATA_POINTS - 1].temperature = temperature;
}

void do_clock_mode() {
    struct calendar_date_time date_time;
    const char months[12][3] = {"JA", "FE", "MR", "AR", "MA", "JN", "JL", "AU", "SE", "OC", "NO", "dE"};

    watch_get_date_time(&date_time);
    watch_display_string((char *)months[date_time.date.month - 1], 0);
    sprintf(buf, "%2d%2d%02d%02d", date_time.date.day, date_time.time.hour, date_time.time.min, date_time.time.sec);
    watch_display_string(buf, 2);
    watch_set_colon();
}

void do_temp_mode() {
    int32_t t_fine;
    float temperature;
    float humidity;

    // take one reading
    watch_i2c_write8(BME280_ADDRESS, BME280_REGISTER_CONTROL, BME280_CONTROL_TEMPERATURE_SAMPLING_X16 |
                                                              BME280_CONTROL_MODE_FORCED);
    // wait for reading to finish
    while(watch_i2c_read8(BME280_ADDRESS, BME280_REGISTER_STATUS) & BME280_STATUS_UPDATING_MASK);
    temperature = read_temperature(&t_fine);
    humidity = read_humidity(t_fine);
    if (application_state.show_humidity) {
        sprintf(buf, "TE%2d%4.1f#%c", (int)(humidity / 10), temperature), application_state.is_fahrenheit ? 'F' : 'C';
    } else {
        sprintf(buf, "TE  %4.1f#%c", temperature, application_state.is_fahrenheit ? 'F' : 'C');
    }
    watch_display_string(buf, 0);
    watch_clear_colon();
}

void do_log_mode() {
    bool is_valid = (uint8_t)(application_state.logged_data[MAX_DATA_POINTS - 1 - application_state.page].is_valid);
    uint8_t hour = (uint8_t)(application_state.logged_data[MAX_DATA_POINTS - 1 - application_state.page].hour);
    int8_t temperature = (int8_t)(application_state.logged_data[MAX_DATA_POINTS - 1 - application_state.page].temperature);
    if (!is_valid) {
        sprintf(buf, "LO%2d------", application_state.page);
        watch_clear_colon();
    } else {
        sprintf(buf, "LO%2d%2d%4d", application_state.page, hour, temperature);
        watch_set_colon();
    }
    watch_display_string(buf, 0);
}

void log_mode_handle_primary_button() {
    application_state.page++;
    if (application_state.page == MAX_DATA_POINTS) application_state.page = 0;
}

void do_prefs_mode() {
    sprintf(buf, "PR  CorF %c", application_state.is_fahrenheit ? 'F' : 'C');
    watch_display_string(buf, 0);
    watch_clear_colon();
}

void prefs_mode_handle_primary_button() {
    // TODO: add rest of preferences (12/24, humidity, LED color, etc.)
    // for now only one, C or F
}

void prefs_mode_handle_secondary_button() {
    application_state.is_fahrenheit = !application_state.is_fahrenheit;
}

void do_set_time_mode() {
    struct calendar_date_time date_time;

    watch_get_date_time(&date_time);
    watch_display_string("          ", 0);
    switch (application_state.page) {
        case 0: // hour
            sprintf(buf, "ST t%2d", date_time.time.hour);
            break;
        case 1: // minute
            sprintf(buf, "ST t  %02d", date_time.time.min);
            break;
        case 2: // second
            sprintf(buf, "ST t    %02d", date_time.time.sec);
            break;
        case 3: // year
            sprintf(buf, "ST d%2d", date_time.date.year - 2000);
            break;
        case 4: // month
            sprintf(buf, "ST d  %02d", date_time.date.month);
            break;
        case 5: // day
            sprintf(buf, "ST d    %02d", date_time.date.day);
            break;
    }
    watch_display_string(buf, 0);
    watch_set_pixel(1, 12); // required for T in position 1
}

void set_time_mode_handle_primary_button() {
    application_state.page++;
    if (application_state.page == 6) application_state.page = 0;
}

void set_time_mode_handle_secondary_button() {
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    const uint8_t days_in_month[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};

    switch (application_state.page) {
        case 0: // hour
            date_time.time.hour = (date_time.time.hour + 1) % 24;
            break;
        case 1: // minute
            date_time.time.min = (date_time.time.min + 1) % 60;
            break;
        case 2: // second
            date_time.time.sec = 0;
            break;
        case 3: // year
            // only allow 2021-2030. fix this sometime next decade
            date_time.date.year = ((date_time.date.year % 10) + 1) + 2020;
            break;
        case 4: // month
            date_time.date.month = ((date_time.date.month + 1) % 12);
            break;
        case 5: // day
            date_time.date.day = date_time.date.day + 1;
            // can't set to the 29th on a leap year. if it's february 29, set to 11:59 on the 28th.
            // and it should roll over.
            if (date_time.date.day > days_in_month[date_time.date.month - 1]) {
                date_time.date.day = 1;
            }
            break;
    }
    watch_set_date_time(date_time);
}

void cb_mode_pressed() {
    application_state.mode = (application_state.mode + 1) % NUM_MODES;
    application_state.mode_changed = true;
    application_state.mode_ticks = 300;
    application_state.page = 0;
}

void cb_light_pressed() {
    switch (application_state.mode) {
        case MODE_PREFS:
            prefs_mode_handle_secondary_button();
            break;
        case MODE_SET:
            set_time_mode_handle_secondary_button();
            break;
        default:
            application_state.light_ticks = 3;
            break;
    }
}

void cb_alarm_pressed() {
    switch (application_state.mode) {
        case MODE_LOG:
            log_mode_handle_primary_button();
            break;
        case MODE_PREFS:
            prefs_mode_handle_primary_button();
            break;
        case MODE_SET:
            set_time_mode_handle_primary_button();
            break;
        default:
            break;
    }
}

void cb_tick() {
    // TODO: use alarm interrupt to trigger data acquisition.
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    if (date_time.time.min == 0 && date_time.time.sec == 0) {
        log_data();
    }

    if (application_state.light_ticks > 0) {
        application_state.light_ticks--;
    }
    if (application_state.mode_ticks > 0) {
        application_state.mode_ticks--;
    }
}
