/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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
#include "day_night_percentage_face.h"
#include "watch_utility.h"
#include "sunriset.h"

// fmod but handle negatives right
static double better_fmod(double x, double y) {
    return fmod(fmod(x, y) + y, y);
}

static void recalculate(watch_date_time utc_now, day_night_percentage_state_t *state) {
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);

    if (movement_location.reg == 0) {
        state->result = -2;
        return;
    }

    // Weird quirky unsigned things were happening when I tried to cast these directly to doubles below.
    // it looks redundant, but extracting them to local int16's seemed to fix it.
    int16_t lat_centi = (int16_t)movement_location.bit.latitude;
    int16_t lon_centi = (int16_t)movement_location.bit.longitude;

    double lat = (double)lat_centi / 100.0;
    double lon = (double)lon_centi / 100.0;

    state->daylen = day_length(utc_now.unit.year + WATCH_RTC_REFERENCE_YEAR, utc_now.unit.month, utc_now.unit.day, lon, lat);

    state->result = sun_rise_set(utc_now.unit.year + WATCH_RTC_REFERENCE_YEAR, utc_now.unit.month, utc_now.unit.day, lon, lat, &state->rise, &state->set);
}

void day_night_percentage_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(day_night_percentage_state_t));
        day_night_percentage_state_t *state = (day_night_percentage_state_t *)*context_ptr;
        watch_date_time utc_now = watch_utility_date_time_convert_zone(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60, 0);
        recalculate(utc_now, state);
    }
}

void day_night_percentage_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool day_night_percentage_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    day_night_percentage_state_t *state = (day_night_percentage_state_t *)context;

    char buf[12];
    watch_date_time date_time = watch_rtc_get_date_time();
    watch_date_time utc_now = watch_utility_date_time_convert_zone(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60, 0);

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            if ((utc_now.unit.hour == 0 && utc_now.unit.minute == 0 && utc_now.unit.second == 0) || state->result == -2) {
                recalculate(utc_now, state);
            }

            if (state->result == -2) {
                watch_display_string("    no Loc", 0);
                break;
            }

            const char* weekday = watch_utility_get_weekday(date_time);
            if (state->result != 0) {
                if (state->result == 1) {
                    watch_clear_indicator(WATCH_INDICATOR_PM);
                } else {
                    watch_set_indicator(WATCH_INDICATOR_PM);
                }
                sprintf(buf, "%s%2dEtrnal", weekday, date_time.unit.day);
                watch_display_string(buf, 0);
            } else {
                double day_hours_decimal = utc_now.unit.hour + (utc_now.unit.minute + (utc_now.unit.second / 60.0)) / 60.0;

                double day_percentage = (24.0 - better_fmod(state->rise - day_hours_decimal, 24.0)) / state->daylen;
                double night_percentage = (24.0 - better_fmod(state->set - day_hours_decimal, 24.0)) / (24 - state->daylen);

                uint16_t percentage;
                if (day_percentage > 0.0 && day_percentage < 1.0) {
                    percentage = day_percentage * 10000;
                    watch_clear_indicator(WATCH_INDICATOR_PM);
                } else {
                    percentage = night_percentage * 10000;
                    watch_set_indicator(WATCH_INDICATOR_PM);
                }
                if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
                    if (!watch_tick_animation_is_running()) watch_start_tick_animation(500);
                    sprintf(buf, "%s%2d  %02d  ", weekday, date_time.unit.day, percentage / 100);
                } else {
                    sprintf(buf, "%s%2d  %04d", weekday, date_time.unit.day, percentage);
                }
                watch_display_string(buf, 0);
            }

            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void day_night_percentage_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

