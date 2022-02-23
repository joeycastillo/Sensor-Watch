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
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "astronomy_face.h"
#include "watch_utility.h"

#define NUM_AVAILABLE_BODIES 9

static const char astronomy_available_celestial_bodies[NUM_AVAILABLE_BODIES] = {
    ASTRO_BODY_SUN,
    ASTRO_BODY_MERCURY,
    ASTRO_BODY_VENUS,
    ASTRO_BODY_MOON,
    ASTRO_BODY_MARS,
    ASTRO_BODY_JUPITER,
    ASTRO_BODY_SATURN,
    ASTRO_BODY_URANUS,
    ASTRO_BODY_NEPTUNE
};

static const char astronomy_celestial_body_names[NUM_AVAILABLE_BODIES][3] = {
    "SO",   // Sol
    "ME",   // Mercury
    "VE",   // Venus
    "LU",   // Moon (Luna)
    "MA",   // Mars
    "JU",   // Jupiter
    "SA",   // Saturn
    "UR",   // Uranus
    "NE"    // Neptune
};

static void _astronomy_face_recalculate(movement_settings_t *settings, astronomy_state_t *state) {
    watch_date_time date_time = watch_rtc_get_date_time();
    uint32_t timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
    date_time = watch_utility_date_time_from_unix_time(timestamp, 0);
    double jd = astro_convert_date_to_julian_date(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);

    astro_equatorial_coordinates_t radec_precession = astro_get_ra_dec(jd, astronomy_available_celestial_bodies[state->active_body_index], state->latitude_radians, state->longitude_radians, true);
    printf("\nParams to convert: %f %f %f %f %f\n",
            jd,
            astro_radians_to_degrees(state->latitude_radians),
            astro_radians_to_degrees(state->longitude_radians),
            astro_radians_to_degrees(radec_precession.right_ascension),
            astro_radians_to_degrees(radec_precession.declination));

    astro_horizontal_coordinates_t horiz = astro_ra_dec_to_alt_az(jd, state->latitude_radians, state->longitude_radians, radec_precession.right_ascension, radec_precession.declination);
    astro_equatorial_coordinates_t radec = astro_get_ra_dec(jd, astronomy_available_celestial_bodies[state->active_body_index], state->latitude_radians, state->longitude_radians, false);
    state->altitude = astro_radians_to_degrees(horiz.altitude);
    state->azimuth = astro_radians_to_degrees(horiz.azimuth);
    state->right_ascension = astro_radians_to_hms(radec.right_ascension);
    state->declination = astro_radians_to_dms(radec.declination);
    state->distance = radec.distance;

    printf("Calculated coordinates for %s on %f: \n\tRA  = %f / %2dh %2dm %2ds\n\tDec = %f / %3d° %3d' %3d\"\n\tAzi = %f\n\tAlt = %f\n\tDst = %f AU\n",
            astronomy_celestial_body_names[state->active_body_index],
            jd,
            astro_radians_to_degrees(radec.right_ascension),
            state->right_ascension.hours,
            state->right_ascension.minutes,
            state->right_ascension.seconds,
            astro_radians_to_degrees(radec_precession.declination),
            state->declination.degrees,
            state->declination.minutes,
            state->declination.seconds,
            state->altitude,
            state->azimuth,
            state->distance);
}

static void _astronomy_face_update(movement_event_t event, movement_settings_t *settings, astronomy_state_t *state) {
    char buf[16];
    switch (state->mode) {
        case ASTRONOMY_MODE_SELECTING_BODY:
            watch_clear_colon();
            watch_display_string(" Astro", 4);
            if (event.subsecond % 2) {
                watch_display_string((char *)astronomy_celestial_body_names[state->active_body_index], 0);
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
        case ASTRONOMY_MODE_CALCULATING:
            watch_clear_display();
             // this takes a moment and locks the UI, flash C for "Calculating"
            watch_start_character_blink('C', 100);
            _astronomy_face_recalculate(settings, state);
            watch_stop_blink();
            state->mode = ASTRONOMY_MODE_DISPLAYING_ALT;
            // fall through
        case ASTRONOMY_MODE_DISPLAYING_ALT:
            sprintf(buf, "%saL%6d", astronomy_celestial_body_names[state->active_body_index], (int16_t)round(state->altitude * 100));
            watch_display_string(buf, 0);
            break;
        case ASTRONOMY_MODE_DISPLAYING_AZI:
            sprintf(buf, "%saZ%6d", astronomy_celestial_body_names[state->active_body_index], (int16_t)round(state->azimuth * 100));
            watch_display_string(buf, 0);
            break;
        case ASTRONOMY_MODE_DISPLAYING_RA:
            watch_set_colon();
            sprintf(buf, "ra H%02d%02d%02d", state->right_ascension.hours, state->right_ascension.minutes, state->right_ascension.seconds);
            watch_display_string(buf, 0);
            break;
        case ASTRONOMY_MODE_DISPLAYING_DEC:
            watch_clear_colon();
            sprintf(buf, "de %3d%2d%2d", state->declination.degrees, state->declination.minutes, state->declination.seconds);
            watch_display_string(buf, 0);
            break;
        case ASTRONOMY_MODE_DISPLAYING_DIST:
            if (state->distance >= 0.00668456) {
                // if >= 1,000,000 kilometers (all planets), we display distance in AU.
                sprintf(buf, "diAU%6d", (uint16_t)round(state->distance * 100));
            } else {
                // otherwise distance in kilometers fits in 6 digits. This mode will only happen for Luna.
                sprintf(buf, "di K%6ld", (uint32_t)round(state->distance * 149597871.0));
            }
            watch_display_string(buf, 0);
            break;
        case ASTRONOMY_MODE_NUM_MODES:
            // this case does not happen, but we need it to silence a warning.
            break;
    }
}

void astronomy_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(astronomy_state_t));
        memset(*context_ptr, 0, sizeof(astronomy_state_t));
    }
}

void astronomy_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    astronomy_state_t *state = (astronomy_state_t *)context;
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    int16_t lat_centi = (int16_t)movement_location.bit.latitude;
    int16_t lon_centi = (int16_t)movement_location.bit.longitude;
    double lat = (double)lat_centi / 100.0;
    double lon = (double)lon_centi / 100.0;
    state->latitude_radians = astro_degrees_to_radians(lat);
    state->longitude_radians = astro_degrees_to_radians(lon);

    movement_request_tick_frequency(4);
}

bool astronomy_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    astronomy_state_t *state = (astronomy_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            _astronomy_face_update(event, settings, state);
            break;
        case EVENT_MODE_BUTTON_UP:
            // You shouldn't need to change this case; Mode almost always moves to the next watch face.
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // If you have other uses for the Light button, you can opt not to illuminate the LED for this event.
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case ASTRONOMY_MODE_SELECTING_BODY:
                    // advance to next celestial body (move to calculations with a long press)
                    state->active_body_index = (state->active_body_index + 1) % NUM_AVAILABLE_BODIES;
                    break;
                case ASTRONOMY_MODE_CALCULATING:
                    // ignore button press during calculations
                    break;
                case ASTRONOMY_MODE_DISPLAYING_DIST:
                    // at last mode, wrap around
                    state->mode = ASTRONOMY_MODE_DISPLAYING_ALT;
                    break;
                default:
                    // otherwise, advance to next mode
                    state->mode++;
                    break;
            }
            _astronomy_face_update(event, settings, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode == ASTRONOMY_MODE_SELECTING_BODY) {
                // celestial body selected! this triggers a calculation in the update method.
                state->mode = ASTRONOMY_MODE_CALCULATING;
                movement_request_tick_frequency(1);
                _astronomy_face_update(event, settings, state);
            } else if (state->mode != ASTRONOMY_MODE_CALCULATING) {
                // in all modes except "doing a calculation", return to the selection screen.
                state->mode = ASTRONOMY_MODE_SELECTING_BODY;
                movement_request_tick_frequency(4);
            _astronomy_face_update(event, settings, state);
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // TODO?
            break;
        default:
            break;
    }

    return true;
}

void astronomy_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    astronomy_state_t *state = (astronomy_state_t *)context;
    state->mode = ASTRONOMY_MODE_SELECTING_BODY;
}
