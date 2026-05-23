/*
 * MIT License
 *
 * Copyright (c) 2024 Your Name
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
#include "sidereal_time_face.h"
#include "astrolib.h"
#include "watch_utility.h"

void sidereal_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(sidereal_time_state_t));
        memset(*context_ptr, 0, sizeof(sidereal_time_state_t));
    }
}

void sidereal_time_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static void _update(movement_settings_t *settings, sidereal_time_state_t *state) {
    (void) state;
    watch_date_time date_time = watch_rtc_get_date_time();
    int32_t utc_offset_seconds = movement_timezone_offsets[settings->bit.time_zone] * 60;
    uint32_t unix_time = watch_utility_date_time_to_unix_time(date_time, utc_offset_seconds);
    watch_date_time utc_dt = watch_utility_date_time_from_unix_time(unix_time, 0);

    double jd = astro_convert_date_to_julian_date(utc_dt.unit.year + WATCH_RTC_REFERENCE_YEAR, utc_dt.unit.month, utc_dt.unit.day, utc_dt.unit.hour, utc_dt.unit.minute, utc_dt.unit.second);
    double gmst = astro_get_GMST(jd);
    
    movement_location_t location;
    location.reg = watch_get_backup_data(1);
    double lon = (double)location.bit.longitude / 100.0;
    
    double lst = gmst + (lon / 15.0);
    while (lst < 0) lst += 24.0;
    while (lst >= 24.0) lst -= 24.0;
    
    uint8_t h = (uint8_t)lst;
    double m_float = (lst - h) * 60.0;
    uint8_t m = (uint8_t)m_float;
    uint8_t s = (uint8_t)((m_float - m) * 60.0);
    
    char buf[16];
    snprintf(buf, sizeof(buf), "ST  %2d%02d%02d", h, m, s);
    watch_display_string(buf, 0);
    watch_set_colon();
    watch_set_indicator(WATCH_INDICATOR_24H);
}

bool sidereal_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    sidereal_time_state_t *state = (sidereal_time_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            _update(settings, state);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            _update(settings, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            movement_illuminate_led();
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void sidereal_time_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
