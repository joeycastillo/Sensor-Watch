/*
 * MIT License
 *
 * Copyright (c) 2024 Ruben Nic
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
#include "close_enough_clock_face.h"
#include "watch.h"
#include "watch_utility.h"

const char *words[12][2] = {
    {"  ", "OC"}, // "HH  OC",
    {" 5", " P"}, // " 5 past HH",
    {"10", " P"}, // "10 past HH",
    {"15", " P"}, // "15 past HH",
    {"20", " P"}, // "20 past HH",
    {"25", " P"}, // "25 past HH",
    {"30", " P"}, // "30 past HH",
    {"35", " P"}, // "35 past HH",
    {"40", " P"}, // "40 past HH",
    {"15", " 2"}, // "15 two HH+1",
    {"10", " 2"}, // "10 two HH+1",
    {" 5", " 2"}, // " 5 two HH+1",
};

static const int hour_switch_index = 9;

static void _update_alarm_indicator(bool settings_alarm_enabled, close_enough_clock_state_t *state) {
    state->alarm_enabled = settings_alarm_enabled;
    if (state->alarm_enabled) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    };
}

void close_enough_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(close_enough_clock_state_t));
    }
}

void close_enough_clock_face_activate(movement_settings_t *settings, void *context) {
    close_enough_clock_state_t *state = (close_enough_clock_state_t *)context;

    if (watch_tick_animation_is_running()) {
        watch_stop_tick_animation();
    }

    if (settings->bit.clock_mode_24h) {
        watch_set_indicator(WATCH_INDICATOR_24H);
    }

    // show alarm indicator if there is an active alarm
    _update_alarm_indicator(settings->bit.alarm_enabled, state);

    // this ensures that none of the five_minute_periods will match, so we always rerender when the face activates
    state->prev_five_minute_period = -1;
    state->prev_min_checked = -1;
}

bool close_enough_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    close_enough_clock_state_t *state = (close_enough_clock_state_t *)context;

    char buf[11];
    watch_date_time date_time;
    bool show_next_hour = false;
    int prev_five_minute_period;
    int prev_min_checked;
    int close_enough_hour;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
            prev_five_minute_period = state->prev_five_minute_period;
            prev_min_checked = state->prev_min_checked;

            // check the battery voltage once a day...
            if (date_time.unit.day != state->last_battery_check) {
                state->last_battery_check = date_time.unit.day;
                watch_enable_adc();
                uint16_t voltage = watch_get_vcc_voltage();
                watch_disable_adc();
                // 2.2 volts will happen when the battery has maybe 5-10% remaining?
                // we can refine this later.
                state->battery_low = (voltage < 2200);
            }

            // ...and set the LAP indicator if low.
            if (state->battery_low) {
                watch_set_indicator(WATCH_INDICATOR_LAP);
            }

            // same minute, skip update
            if (date_time.unit.minute == prev_min_checked) {
                break;
            } else {
                state->prev_min_checked = date_time.unit.minute;
            }

            int five_minute_period = (date_time.unit.minute / 5) % 12;

            // If we are 60% to the next 5 interval, move up to the next period
            if (fmodf(date_time.unit.minute / 5.0f, 1.0f) > 0.5f) {
                // If we are on the last 5 interval and moving to the next period we need to display the next hour because we are wrapping around
                if (five_minute_period == 11) {
                    show_next_hour = true;
                }

                five_minute_period = (five_minute_period + 1) % 12;
            }

            // same five_minute_period, skip update
            if (five_minute_period == prev_five_minute_period) {
                break;
            }

            // we don't want to modify date_time.unit.hour just in case other watch faces use it
            close_enough_hour = date_time.unit.hour;

            // move from "MM(mins) P HH" to "MM(mins) 2 HH+1"
            if (five_minute_period >= hour_switch_index || show_next_hour) {
                close_enough_hour = (close_enough_hour + 1) % 24;
            }

            if (!settings->bit.clock_mode_24h) {
                // if we are in 12 hour mode, do some cleanup.
                if (close_enough_hour < 12) {
                    watch_clear_indicator(WATCH_INDICATOR_PM);
                } else {
                    watch_set_indicator(WATCH_INDICATOR_PM);
                }

                close_enough_hour %= 12;
                if (close_enough_hour == 0) {
                    close_enough_hour = 12;
                }

                date_time.unit.hour %= 12;
                if (date_time.unit.hour == 0) {
                    date_time.unit.hour = 12;
                }
            }

            char first_word[3];
            char second_word[3];
            char third_word[3];
            if (five_minute_period == 0) { // "HH  OC",
                sprintf(first_word, "%2d", close_enough_hour);
                strncpy(second_word, words[five_minute_period][0], 3);
                strncpy(third_word, words[five_minute_period][1], 3);
            } else {
                strncpy(first_word, words[five_minute_period][0], 3);
                strncpy(second_word, words[five_minute_period][1], 3);
                sprintf(third_word, "%2d", close_enough_hour);
            }

            sprintf(
                buf,
                "%s%2d%s%s%s",
                watch_utility_get_weekday(date_time),
                date_time.unit.day,
                first_word,
                second_word,
                third_word
            );

            watch_display_string(buf, 0);
            state->prev_five_minute_period = five_minute_period;

            // handle alarm indicator
            if (state->alarm_enabled != settings->bit.alarm_enabled) {
                _update_alarm_indicator(settings->bit.alarm_enabled, state);
            }

            break;

        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void close_enough_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
