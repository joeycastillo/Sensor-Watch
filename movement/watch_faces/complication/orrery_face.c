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
#include <string.h>
#include <math.h>
#include "orrery_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "vsop87a_micro.h" // smaller size, less accurate
#include "vsop87a_milli.h"
#include "astrolib.h"

#define NUM_AVAILABLE_BODIES 9

static const char orrery_celestial_body_names[NUM_AVAILABLE_BODIES][3] = {
    "ME",   // Mercury
    "VE",   // Venus
    "EA",   // Earth
    "LU",   // Moon (Luna)
    "MA",   // Mars
    "JU",   // Jupiter
    "SA",   // Saturn
    "UR",   // Uranus
    "NE"    // Neptune
};

static void _orrery_face_recalculate(movement_settings_t *settings, orrery_state_t *state) {
    watch_date_time date_time = watch_rtc_get_date_time();
    uint32_t timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
    date_time = watch_utility_date_time_from_unix_time(timestamp, 0);
    double jd = astro_convert_date_to_julian_date(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    double et = astro_convert_jd_to_julian_millenia_since_j2000(jd);
    double r[3] = {0};

    switch(state->active_body_index) {
        case 0:
            vsop87a_milli_getMercury(et, r);
            break;
        case 1:
            vsop87a_milli_getVenus(et, r);
            break;
        case 2:
            vsop87a_milli_getEarth(et, r);
            break;
        case 3:
            {
                 double earth[3];
                 double emb[3];
                 vsop87a_milli_getEarth(et, earth);
                 vsop87a_milli_getEmb(et, emb);
                 vsop87a_milli_getMoon(earth, emb, r);
             }
            break;
        case 4:
            vsop87a_milli_getMars(et, r);
            break;
        case 5:
            vsop87a_milli_getJupiter(et, r);
            break;
        case 6:
            vsop87a_milli_getSaturn(et, r);
            break;
        case 7:
            vsop87a_milli_getUranus(et, r);
            break;
        case 8:
            vsop87a_milli_getNeptune(et, r);
            break;
    }
    state->coords[0] = r[0];
    state->coords[1] = r[1];
    state->coords[2] = r[2];
}

static void _orrery_face_update(movement_event_t event, movement_settings_t *settings, orrery_state_t *state) {
    char buf[11];
    switch (state->mode) {
        case ORRERY_MODE_SELECTING_BODY:
            watch_display_string("Orrery", 4);
            if (event.subsecond % 2) {
                watch_display_string((char *)orrery_celestial_body_names[state->active_body_index], 0);
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
            watch_clear_display();
             // this takes a moment and locks the UI, flash C for "Calculating"
            watch_start_character_blink('C', 100);
            _orrery_face_recalculate(settings, state);
            watch_stop_blink();
            state->mode = ORRERY_MODE_DISPLAYING_X;
            // fall through
        case ORRERY_MODE_DISPLAYING_X:
            sprintf(buf, "%s X%6d", orrery_celestial_body_names[state->active_body_index], (int16_t)round(state->coords[0] * 100));
            watch_display_string(buf, 0);
            break;
        case ORRERY_MODE_DISPLAYING_Y:
            sprintf(buf, "%s Y%6d", orrery_celestial_body_names[state->active_body_index], (int16_t)round(state->coords[1] * 100));
            watch_display_string(buf, 0);
            break;
        case ORRERY_MODE_DISPLAYING_Z:
            sprintf(buf, "%s Z%6d", orrery_celestial_body_names[state->active_body_index], (int16_t)round(state->coords[2] * 100));
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
    (void) context;
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
        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case ORRERY_MODE_SELECTING_BODY:
                    // advance to next celestial body (move to calculations with a long press)
                    state->active_body_index = (state->active_body_index + 1) % NUM_AVAILABLE_BODIES;
                    break;
                case ORRERY_MODE_CALCULATING:
                    // ignore button press during calculations
                    break;
                case ORRERY_MODE_DISPLAYING_Z:
                    // at last mode, wrap around
                    state->mode = ORRERY_MODE_DISPLAYING_X;
                    break;
                default:
                    // otherwise, advance to next mode
                    state->mode++;
                    break;
            }
            _orrery_face_update(event, settings, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode == ORRERY_MODE_SELECTING_BODY) {
                // celestial body selected! this triggers a calculation in the update method.
                state->mode = ORRERY_MODE_CALCULATING;
                movement_request_tick_frequency(1);
                _orrery_face_update(event, settings, state);
            } else if (state->mode != ORRERY_MODE_CALCULATING) {
                // in all modes except "doing a calculation", return to the selection screen.
                state->mode = ORRERY_MODE_SELECTING_BODY;
                movement_request_tick_frequency(4);
                _orrery_face_update(event, settings, state);
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void orrery_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    orrery_state_t *state = (orrery_state_t *)context;
    state->mode = ORRERY_MODE_SELECTING_BODY;
}
