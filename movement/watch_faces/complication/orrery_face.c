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
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "orrery_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "vsop87a_micro.h" // smaller size, less accurate
#include "vsop87a_milli.h"
#include "astrolib.h"

static const char orrery_celestial_body_names[][3] = {"ME", "VE", "EA", "MO", "MA", "JU", "SA", "UR", "NE"};

// TODO: fractional julian date, this is in libastro
static uint32_t _julian_date(uint16_t year, uint16_t month, uint16_t day) {
    return (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100))/4 + day - 32075;
}

static void _orrery_face_recalculate(movement_settings_t *settings, orrery_state_t *state) {
    watch_date_time date_time = watch_rtc_get_date_time();
    uint32_t timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
    date_time = watch_utility_date_time_from_unix_time(timestamp, 0);

    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    // int16_t lat_centi = (int16_t)movement_location.bit.latitude;
    // int16_t lon_centi = (int16_t)movement_location.bit.longitude;

    int16_t lat_centi = 4070;
    int16_t lon_centi = -7395;

    double lat = (double)lat_centi / 100.0;
    double lon = (double)lon_centi / 100.0;

    uint32_t jd = _julian_date(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day);
    astro_equatorial_coordinates_t radec;
    astro_equatorial_coordinates_t radec_precession;
    astro_horizontal_coordinates_t horiz;

    switch(state->active_body) {
        case ORRERY_CELESTIAL_BODY_MERCURY:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_MERCURY, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_MERCURY, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_VENUS:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_VENUS, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_VENUS, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_EARTH:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_EARTH, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_EARTH, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_MARS:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_MARS, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_MARS, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_LUNA:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_MOON, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_MOON, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_JUPITER:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_JUPITER, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_JUPITER, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_SATURN:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_SATURN, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_SATURN, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_URANUS:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_URANUS, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_URANUS, lat, lon, false);
            break;
        case ORRERY_CELESTIAL_BODY_NEPTUNE:
            radec_precession = astro_get_ra_dec(jd, ASTRO_BODY_NEPTUNE, lat, lon, true);
            radec = astro_get_ra_dec(jd, ASTRO_BODY_NEPTUNE, lat, lon, false);
            break;
        default:
            // will not happen, just silencing warning
            return;
    }
    state->coords[0] = radec.right_ascension * 180 / M_PI;
    state->coords[1] = radec.declination * 180 / M_PI;
    state->coords[2] = radec.distance;

    printf("\nParams to convert: %ld %f %f %f %f\n", jd, lat, lon, radec_precession.right_ascension * 180 / M_PI, radec_precession.declination * 180 / M_PI);
    horiz = astro_convert_equatorial_coordinates_to_horizontal(jd, lat * (M_PI / 180.0), lon * (M_PI / 180.0), radec_precession.right_ascension, radec_precession.declination);
    printf("Calculated coordinates for %s on %ld: \n\tRA  = %f\n\tDec = %f\n\tAzi = %f\n\tAlt = %f\n\tDst = %f AU\n",
            orrery_celestial_body_names[state->active_body],
            jd,
            radec.right_ascension * 180 / M_PI,
            radec.declination * 180 / M_PI,
            horiz.azimuth * 180 / M_PI,
            horiz.altitude * 180 / M_PI,
            radec.distance);
}

static void _orrery_face_update(movement_event_t event, movement_settings_t *settings, orrery_state_t *state) {
    char buf[11];
    switch (state->mode) {
        case ORRERY_MODE_SELECTING_BODY:
            watch_clear_colon();
            watch_display_string("Orrery", 4);
            if (event.subsecond % 2) {
                watch_display_string((char *)orrery_celestial_body_names[state->active_body], 0);
            } else {
                watch_display_string("  ", 0);
            }
            if (event.subsecond == 0) {
                watch_display_string("  ", 2);
                switch (state->animation_state) {
                    case 0:
                        watch_set_pixel(0, 7);
                        watch_set_pixel(2, 6);
                        break;
                    case 1:
                        watch_set_pixel(1, 7);
                        watch_set_pixel(2, 9);
                        break;
                    case 2:
                        watch_set_pixel(2, 7);
                        watch_set_pixel(0, 9);
                        break;
                }
                state->animation_state = (state->animation_state + 1) % 3;
            }
            break;
        case ORRERY_MODE_CALCULATING:
            _orrery_face_recalculate(settings, state);
            state->mode = ORRERY_MODE_DISPLAYING_X;
            // fall through
        case ORRERY_MODE_DISPLAYING_X:
            sprintf(buf, "rA  %6d", (int16_t)round(state->coords[0] * 100));
            watch_display_string(buf, 0);
            break;
        case ORRERY_MODE_DISPLAYING_Y:
            sprintf(buf, "dE  %6d", (int16_t)round(state->coords[1] * 100));
            watch_display_string(buf, 0);
            break;
        case ORRERY_MODE_DISPLAYING_Z:
            sprintf(buf, "dI  %6d", (int16_t)round(state->coords[2] * 100));
            watch_display_string(buf, 0);
            break;
        case ORRERY_MODE_NUM_MODES:
            // this case does not happen, but we need it to silence a warning.
            break;
    }
}

void orrery_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(orrery_state_t));
        memset(*context_ptr, 0, sizeof(orrery_state_t));
    }
}

void orrery_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    orrery_state_t *state = (orrery_state_t *)context;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->latitude = movement_location.bit.latitude;
    state->longitude = movement_location.bit.longitude;
    movement_request_tick_frequency(4);
}

bool orrery_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    orrery_state_t *state = (orrery_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            _orrery_face_update(event, settings, state);
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
            switch (state->mode) {
                case ORRERY_MODE_SELECTING_BODY:
                    // advance to next celestial body (move to calculations with a long press)
                    state->active_body = (state->active_body + 1) % ORRERY_CELESTIAL_BODY_NUM_BODIES;
                    break;
                case ORRERY_MODE_CALCULATING:
                    // ignore button press during calculations
                    break;
                case ORRERY_MODE_DISPLAYING_X:
                    state->mode = ORRERY_MODE_DISPLAYING_Y;
                    break;
                case ORRERY_MODE_DISPLAYING_Y:
                    state->mode = ORRERY_MODE_DISPLAYING_Z;
                    break;
                case ORRERY_MODE_DISPLAYING_Z:
                    state->mode = ORRERY_MODE_DISPLAYING_X;
                    break;
                case ORRERY_MODE_NUM_MODES:
                    break;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode == ORRERY_MODE_SELECTING_BODY) {
                // celestial body selected! this triggers a calculation in the update method.
                state->mode = ORRERY_MODE_CALCULATING;
            } else if (state->mode != ORRERY_MODE_CALCULATING) {
                // in all modes except "doing a calculation", return to the selection screen.
                state->mode = ORRERY_MODE_SELECTING_BODY;
            }
            break;
        case EVENT_TIMEOUT:
            // TODO: return home if we're on a settings page.
        default:
            break;
    }

    return true;
}

void orrery_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(1);
}
