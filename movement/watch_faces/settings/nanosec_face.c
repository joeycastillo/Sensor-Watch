/*
 * MIT License
 *
 * Copyright (c) 2022 Mikhail Svarichevsky https://3.14.by/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "thermistor_driver.h"
#include "nanosec_face.h"
#include "filesystem.h"
#include "watch_utility.h"

int16_t freq_correction_residual = 0; // Dithering 0.1ppm correction, does not need to be configured.
int16_t freq_correction_previous = -30000;
#define dithering 31

nanosec_state_t nanosec_state;

#define nanosec_max_screen 7
int8_t nanosec_screen = 0;
bool nanosec_changed = false; // We try to avoid saving settings when no changes were made, for example when just browsing through face

const float voltage_coefficient = 0.241666667 * dithering; // 10 * ppm/V. Nominal frequency is at 3V.

static void nanosec_init_profile(void) {
    nanosec_changed = true;
    nanosec_state.correction_cadence = 10;
    watch_date_time date_time = watch_rtc_get_date_time();
    nanosec_state.last_correction_time = watch_utility_date_time_to_unix_time(date_time, 0);

    // init data after changing profile - do that once per profile selection
    switch (nanosec_state.correction_profile) {
        case 0: // No tempco, no dithering
            nanosec_state.freq_correction = 0;
            nanosec_state.center_temperature = 2500;
            nanosec_state.quadratic_tempco = 0;
            nanosec_state.cubic_tempco = 0;
            nanosec_state.aging_ppm_pa = 0;
            break;
        case 1: // No tempco, with dithering
            nanosec_state.freq_correction = 0;
            nanosec_state.center_temperature = 2500;
            nanosec_state.quadratic_tempco = 0;
            nanosec_state.cubic_tempco = 0;
            nanosec_state.aging_ppm_pa = 0;
            break;
        case 2: // Datasheet correction
            nanosec_state.freq_correction = 0;
            nanosec_state.center_temperature = 2500;
            nanosec_state.quadratic_tempco = 3400;
            nanosec_state.cubic_tempco = 0;
            nanosec_state.aging_ppm_pa = 0;
            break;
        case 3: // Datasheet correction + cubic coefficient
            nanosec_state.freq_correction = 0;
            nanosec_state.center_temperature = 2500;
            nanosec_state.quadratic_tempco = 3400;
            nanosec_state.cubic_tempco = 1360;
            nanosec_state.aging_ppm_pa = 0;
            break;
        case 4: // Full custom
            nanosec_state.freq_correction = 1768;
            nanosec_state.center_temperature = 2653;
            nanosec_state.quadratic_tempco = 4091;
            nanosec_state.cubic_tempco = 1359;
            nanosec_state.aging_ppm_pa = 0;
            break;
    }
}

static void nanosec_internal_write_RTC_correction(int16_t value, int16_t sign) {
    if (sign == 0) {
        if (value == freq_correction_previous)
            return; // Do not write same correction value twice
        freq_correction_previous = value;
    } else {
        if (value == -freq_correction_previous)
            return; // Do not write same correction value twice
        freq_correction_previous = -value;
    }

    watch_rtc_freqcorr_write(value, sign);
}

// Receives clock correction, already corrected for temperature and battery voltage, multiplied by "dithering"
static void apply_RTC_correction(int16_t correction) {
    correction += freq_correction_residual;
    int32_t correction_lr = (int32_t)correction * 2 / dithering; // int division
    if (correction_lr & 1) {
        if (correction_lr > 0) {
            correction_lr++;
        } else {
            correction_lr--;
        }
    }
    correction_lr >>= 1;
    freq_correction_residual = correction - correction_lr * dithering;

    // Warning! Freqcorr is not signed int8!!
    // First we clamp it to 8-bit range
    if (correction_lr > 127) {
        nanosec_internal_write_RTC_correction(127, 0);
    } else if (correction_lr < -127) {
        nanosec_internal_write_RTC_correction(127, 1);
    } else if (correction_lr < 0) {
        nanosec_internal_write_RTC_correction(abs(correction_lr), 1);
    } else { // correction
        nanosec_internal_write_RTC_correction(correction_lr, 0);
    }
}

// User-related saves
void nanosec_ui_save(void) {
    if (nanosec_changed)
        nanosec_save();
}

// This is low-level save function, that can be used by other faces
void nanosec_save(void) {
    if (nanosec_state.correction_profile == 0) {
        freq_correction_residual = 0;
        apply_RTC_correction(nanosec_state.freq_correction * 1.0f * dithering / 100); // Will be divided by dithering inside, final resolution is mere 1ppm
    }

    filesystem_write_file("nanosec.ini", (char*)&nanosec_state, sizeof(nanosec_state));
    nanosec_changed = false;
}

void nanosec_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    (void) settings;

    if (*context_ptr == NULL) {
        if (filesystem_get_file_size("nanosec.ini") != sizeof(nanosec_state)) {
            // No previous ini or old version of ini file - create new config file
            nanosec_state.correction_profile = 3;
            nanosec_init_profile();
            nanosec_ui_save();
        } else {
            filesystem_read_file("nanosec.ini", (char*)&nanosec_state, sizeof(nanosec_state));
        }

        freq_correction_residual = 0;
        nanosec_screen = 0;

        *context_ptr = (void *)1; // No need to re-read from filesystem when exiting low power mode
    }
}

void nanosec_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // Handle any tasks related to your watch face coming on screen.
    nanosec_changed = false;
}

static void nanosec_update_display() {
    char buf[14];

    switch (nanosec_screen) {
        case 0:
            sprintf(buf, "FC  %6d", nanosec_state.freq_correction);
            break;
        case 1:
            sprintf(buf, "T0  %6d", nanosec_state.center_temperature);
            break;
        case 2:
            sprintf(buf, "2C  %6d", nanosec_state.quadratic_tempco);
            break;
        case 3:
            sprintf(buf, "3C  %6d", nanosec_state.cubic_tempco);
            break;
        case 4: // Profile
            sprintf(buf, "PR      P%1d", nanosec_state.correction_profile);
            break;
        case 5: // Cadence
            sprintf(buf, "CD      %2d", nanosec_state.correction_cadence);
            break;
        case 6: // Aging
            sprintf(buf, "AA  %6d", nanosec_state.aging_ppm_pa);
            break;
    }
    watch_display_string(buf, 0);
}

static void value_increase(int16_t delta) {
    nanosec_changed = true;

    switch (nanosec_screen) {
        case 0:
            nanosec_state.freq_correction += delta;
            break;
        case 1:
            nanosec_state.center_temperature += delta;
            break;
        case 2:
            nanosec_state.quadratic_tempco += delta;
            break;
        case 3:
            nanosec_state.cubic_tempco += delta;
            break;
        case 4: // Profile
            nanosec_state.correction_profile = (nanosec_state.correction_profile + delta) % nanosec_profile_count;
            // if ALARM decreases profile below 0, roll back around
            if (nanosec_state.correction_profile < 0) {
                nanosec_state.correction_profile += nanosec_profile_count;
            }
            break;
        case 5: // Cadence
            switch (nanosec_state.correction_cadence) {
                case 1:
                    nanosec_state.correction_cadence = (delta > 0) ? 5 : 60;
                    break;
                case 5:
                    nanosec_state.correction_cadence = (delta > 0) ? 10 : 1;
                    break;
                case 10:
                    nanosec_state.correction_cadence = (delta > 0) ? 20 : 5;
                    break;
                case 20:
                    nanosec_state.correction_cadence = (delta > 0) ? 60 : 10;
                    break;
                case 60:
                    nanosec_state.correction_cadence = (delta > 0) ? 1 : 20;
                    break;
            }
            break;
        case 6: // Aging
            nanosec_state.aging_ppm_pa += delta;
            break;
    }

    nanosec_update_display();
}

static void nanosec_next_edit_screen(void) {
    nanosec_screen = (nanosec_screen + 1) % nanosec_max_screen;
    nanosec_update_display();
}

float nanosec_get_aging() // Returns aging correction in ppm
{
    watch_date_time date_time = watch_rtc_get_date_time();
    float years = (watch_utility_date_time_to_unix_time(date_time, 0) - nanosec_state.last_correction_time) / 31536000.0f; // Years passed since finetune
    return years*nanosec_state.aging_ppm_pa/100.0f;
}


bool nanosec_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            nanosec_screen = 0; // Start at page 0
            nanosec_update_display();
            break;
        case EVENT_TICK:
            break;
        case EVENT_MODE_BUTTON_UP:
            if (nanosec_screen == 0) { // we can exit face only on the 0th page
                nanosec_ui_save();
                movement_move_to_next_face();
            } else {
                nanosec_next_edit_screen();
            }
            break;
        case EVENT_MODE_LONG_PRESS:
            nanosec_next_edit_screen();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            value_increase(1);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (nanosec_screen == 4) { // If we are in profile - apply profiles
                nanosec_init_profile();
                nanosec_screen = 0;
                nanosec_update_display();
            } else {
                value_increase(50);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            value_increase(-1);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (nanosec_screen == 4) { // If we are in profile - still decrease by 1
                value_increase(-1);
            } else {
                value_increase(-50);
            }
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        case EVENT_BACKGROUND_TASK:
            // Here we measure temperature and do main frequency correction
            thermistor_driver_enable();
            float temperature_c = thermistor_driver_get_temperature();
            float voltage = (float)watch_get_vcc_voltage() / 1000.0;
            thermistor_driver_disable();
            // L22 correction scaling is 0.95367ppm per 1 in FREQCORR
            // At wrong temperature crystall starting to run slow, negative correction will speed up frequency to correct
            // Default 32kHz correciton factor is -0.034, centered around 25°C
            float dt = temperature_c - nanosec_state.center_temperature / 100.0;

            int16_t correction = round((
                        nanosec_state.freq_correction / 100.0f * dithering +
                        (-nanosec_state.quadratic_tempco / 100000.0 * dithering) * dt * dt +
                        (nanosec_state.cubic_tempco / 10000000.0 * dithering) * dt * dt * dt +
                        (voltage - 3.0) * voltage_coefficient +
                        nanosec_get_aging() * dithering
                        ) / 0.95367); // 1 correction unit is 0.095367ppm.

            apply_RTC_correction(correction);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void nanosec_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    nanosec_ui_save();
}

// Background freq correction
bool nanosec_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    if (nanosec_state.correction_profile == 0)
        return 0; // No need for background correction if we are on profile 0 - static hardware correction.
    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute % nanosec_state.correction_cadence == 0;
}
