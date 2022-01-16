/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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
 *
 * Sunrise/sunset calculations are public domain code by Paul Schlyter, December 1992
 *
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sunrise_sunset_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "sunriset.h"

static void _sunrise_sunset_face_update() {
    char buf[14];
    double rise, set, minutes;
    // TODO: allow user to set location, using London for now.
    double lat = 51.509865;
    double lon = -0.118092;
    // TODO: account for time zone, currently only operates in GMT.
    watch_date_time date_time = watch_rtc_get_date_time(); // the current date / time
    watch_date_time scratch_time; // scratchpad, contains different values at different times
    scratch_time.reg = date_time.reg;
        
    for(int i = 0; i < 2; i++) {
        uint8_t result = sun_rise_set(scratch_time.unit.year + WATCH_RTC_REFERENCE_YEAR, scratch_time.unit.month, scratch_time.unit.day, lon, lat, &rise, &set);

        if (result != 0) {
            watch_clear_colon();
            watch_clear_indicator(WATCH_INDICATOR_PM);
            watch_clear_indicator(WATCH_INDICATOR_24H);
            sprintf(buf, "%s%d none ", (result == 1) ? "SE" : "rI", scratch_time.unit.day);
            watch_display_string(buf, 0);
            return;
        }

        watch_set_colon();
        // TODO: account for user's 12H/24H preference
        watch_set_indicator(WATCH_INDICATOR_24H);

        minutes = 60.0 * fmod(rise, 1);
        scratch_time.unit.hour = floor(rise);
        scratch_time.unit.minute = floor(minutes);
        scratch_time.unit.second = 60.0 * fmod(minutes, 1);

        if (date_time.reg < scratch_time.reg) {
            // display today's sunrise, it hasn't happened yet
            sprintf(buf, "rI%2d%2d%02d%02d", scratch_time.unit.day, scratch_time.unit.hour, scratch_time.unit.minute, scratch_time.unit.second);
            watch_display_string(buf, 0);
            return;
        }

        minutes = 60.0 * fmod(set, 1);
        scratch_time.unit.hour = floor(set);
        scratch_time.unit.minute = floor(minutes);
        scratch_time.unit.second = 60.0 * fmod(minutes, 1);

        if (date_time.reg < scratch_time.reg) {
            // display today's sunset, it hasn't happened yet
            sprintf(buf, "SE%2d%02d%02d%02d", scratch_time.unit.day, scratch_time.unit.hour, scratch_time.unit.minute, scratch_time.unit.second);
            watch_display_string(buf, 0);
            return;
        }

        // it's after sunset. we need to display sunrise for tomorrow.
        uint32_t timestamp = watch_utility_date_time_to_unix_time(date_time, 0);
        timestamp += 86400;
        scratch_time = watch_utility_date_time_from_unix_time(timestamp, 0);
    }
}

void sunrise_sunset_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(sunrise_sunset_state_t));
        memset(*context_ptr, 0, sizeof(sunrise_sunset_state_t));
    }
}

void sunrise_sunset_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    sunrise_sunset_state_t *state = (sunrise_sunset_state_t *)context;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->latitude = movement_location.bit.latitude;
    state->longitude = movement_location.bit.longitude;
}

bool sunrise_sunset_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            break;
        case EVENT_LOW_ENERGY_UPDATE:
        case EVENT_TICK:
            _sunrise_sunset_face_update();
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            break;
        case EVENT_ALARM_BUTTON_UP:
            break;
        case EVENT_ALARM_LONG_PRESS:
            // TODO: settings mode, to set the user's location.
            break;
        case EVENT_TIMEOUT:
            // TODO: return home if we're on a settings page.
        default:
            break;
    }

    return true;
}

void sunrise_sunset_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(1);
}
