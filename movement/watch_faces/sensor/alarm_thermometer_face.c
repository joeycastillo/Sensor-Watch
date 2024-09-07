/*
 * MIT License
 *
 * Copyright (c) 2024 Christian Buschau
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

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "alarm_thermometer_face.h"
#include "thermistor_driver.h"

static float _alarm_thermometer_face_update(bool in_fahrenheit) {
    thermistor_driver_enable();
    float temperature_c = thermistor_driver_get_temperature();
    char buf[14];
    if (in_fahrenheit) {
        sprintf(buf, "%4.1f#F", temperature_c * 1.8 + 32.0);
    } else {
        sprintf(buf, "%4.1f#C", temperature_c);
    }
    watch_display_string(buf, 4);
    thermistor_driver_disable();
    return temperature_c;
}

static void _alarm_thermometer_face_clear(int last[]) {
    for (size_t i = 0; i < LAST_SIZE; i++) {
        last[i] = INT_MIN;
    }
}

void alarm_thermometer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(alarm_thermometer_state_t));
        memset(*context_ptr, 0, sizeof(alarm_thermometer_state_t));
    }
}

void alarm_thermometer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    alarm_thermometer_state_t *state = (alarm_thermometer_state_t *)context;
    state->mode = MODE_NORMAL;
    _alarm_thermometer_face_clear(state->last);
    watch_display_string("AT", 0);
}

bool alarm_thermometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    alarm_thermometer_state_t *state = (alarm_thermometer_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _alarm_thermometer_face_update(settings->bit.use_imperial_units);
            break;
        case EVENT_TICK:
            if (watch_rtc_get_date_time().unit.second % 5 == 0) {
                switch (state->mode) {
                    case MODE_NORMAL:
                        _alarm_thermometer_face_update(settings->bit.use_imperial_units);
                        break;
                    case MODE_ALARM:
                        for (size_t i = LAST_SIZE - 1; i > 0; i--) {
                            state->last[i] = state->last[i - 1];
                        }
                        state->last[0] = roundf(_alarm_thermometer_face_update(settings->bit.use_imperial_units) * 10.0f);
                        bool constant = true;
                        for (size_t i = 1; i < LAST_SIZE; i++) {
                            if (state->last[i - 1] != state->last[i]) {
                                constant = false;
                                break;
                            }
                        }
                        if (constant) {
                            state->mode = MODE_FREEZE;
                            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                            movement_play_alarm();
                        }
                        break;
                    case MODE_FREEZE:
                        break;
                }
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case MODE_NORMAL:
                    state->mode = MODE_ALARM;
                    watch_set_indicator(WATCH_INDICATOR_BELL);
                    _alarm_thermometer_face_clear(state->last);
                    break;
                case MODE_FREEZE:
                    state->mode = MODE_NORMAL;
                    watch_clear_indicator(WATCH_INDICATOR_BELL);
                    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                    break;
                case MODE_ALARM:
                    state->mode = MODE_NORMAL;
                    watch_clear_indicator(WATCH_INDICATOR_BELL);
                    _alarm_thermometer_face_update(settings->bit.use_imperial_units);
                    break;
            }
            if (settings->bit.button_should_sound) {
                watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode != MODE_FREEZE) {
                settings->bit.use_imperial_units = !settings->bit.use_imperial_units;
                _alarm_thermometer_face_update(settings->bit.use_imperial_units);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            if (!watch_tick_animation_is_running()) {
                state->mode = MODE_NORMAL;
                watch_clear_indicator(WATCH_INDICATOR_BELL);
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                watch_start_tick_animation(1000);
            }
            if (watch_rtc_get_date_time().unit.minute % 5 == 0) {
                _alarm_thermometer_face_update(settings->bit.use_imperial_units);
                watch_display_string("  ", 8);
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void alarm_thermometer_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
