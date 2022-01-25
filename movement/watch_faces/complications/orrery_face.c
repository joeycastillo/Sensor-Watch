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
#include "vsop87a_micro.h"

static const char orrery_celestial_body_names[][3] = {"ME", "VE", "LU", "MA", "JU", "SA", "UR", "NE"};

double jd2et(double jd) {
    return (jd - 2451545.0) / 365250.0;
}

static void _orrery_face_recalculate(movement_settings_t *settings, orrery_state_t *state) {
    watch_date_time date_time = watch_rtc_get_date_time();
    time_t timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
    date_time = watch_utility_date_time_from_unix_time(timestamp, 0);

	double et = jd2et(2451545.0);
    double r[3];
    printf("Calculateding\n");

    switch(state->active_body) {
        case ORRERY_CELESTIAL_BODY_MERCURY:
            vsop87a_micro_getMercury(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_VENUS:
            vsop87a_micro_getVenus(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_MARS:
            vsop87a_micro_getMars(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_LUNA:
            break;
        case ORRERY_CELESTIAL_BODY_JUPITER:
            vsop87a_micro_getJupiter(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_SATURN:
            vsop87a_micro_getSaturn(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_URANUS:
            vsop87a_micro_getUranus(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_NEPTUNE:
            vsop87a_micro_getNeptune(et, r);
            break;
        case ORRERY_CELESTIAL_BODY_NUM_BODIES:
            // will not happen, just silencing warning
            break;
    }
    printf("Calculated: %f, %f, %f\n", r[0], r[1], r[2]);
}

static void _orrery_face_update(movement_event_t event, movement_settings_t *settings, orrery_state_t *state) {
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
            state->mode = ORRERY_MODE_DISPLAYING_RIGHT_ASCENSION;
            // fall through
        case ORRERY_MODE_DISPLAYING_RIGHT_ASCENSION:
            watch_set_colon();
            watch_display_string("RA  203213", 0);
            break;
        case ORRERY_MODE_DISPLAYING_DECLINATION:
            watch_clear_colon();
            watch_display_string("DE  154453", 0);
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
                case ORRERY_MODE_DISPLAYING_RIGHT_ASCENSION:
                    state->mode = ORRERY_MODE_DISPLAYING_DECLINATION;
                    break;
                case ORRERY_MODE_DISPLAYING_DECLINATION:
                    state->mode = ORRERY_MODE_DISPLAYING_RIGHT_ASCENSION;
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
