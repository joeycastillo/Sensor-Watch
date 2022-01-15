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
#include "demo_face.h"
#include "watch.h"

typedef enum {
    DEMO_FACE_TIME = 0,
    DEMO_FACE_WORLD_TIME,
    DEMO_FACE_BEATS,
    DEMO_FACE_TOTP,
    DEMO_FACE_TEMP_F,
    DEMO_FACE_TEMP_C,
    DEMO_FACE_TEMP_LOG_1,
    DEMO_FACE_TEMP_LOG_2,
    DEMO_FACE_DAY_ONE,
    DEMO_FACE_STOPWATCH,
    DEMO_FACE_PULSOMETER,
    DEMO_FACE_BATTERY_VOLTAGE,
    DEMO_FACE_NUM_FACES
} demo_face_index_t;

void demo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(demo_face_index_t));
        memset(*context_ptr, 0, sizeof(demo_face_index_t));
    }
}

void demo_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(0);
    // ensure the watch never enters low energy mode
    settings->bit.le_interval = 0;
    settings->bit.led_duration = 3;
}

bool demo_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    demo_face_index_t *screen = (demo_face_index_t *)context;
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            *screen = ((*screen) + 1) % DEMO_FACE_NUM_FACES;
            // fall through
        case EVENT_ACTIVATE:
            switch (*screen) {
                case DEMO_FACE_TIME:
                    watch_display_string("TH10101036", 0);
                    watch_set_colon();
                    break;
                case DEMO_FACE_WORLD_TIME:
                    watch_display_string("UT10 21036", 0);
                    watch_set_indicator(WATCH_INDICATOR_PM);
                    break;
                case DEMO_FACE_BEATS:
                    watch_display_string("bt   64125", 0);
                    watch_clear_indicator(WATCH_INDICATOR_PM);
                    watch_clear_colon();
                    break;
                case DEMO_FACE_TOTP:
                    watch_display_string("2F29808494", 0);
                    break;
                case DEMO_FACE_TEMP_F:
                    watch_display_string("TE  72.1#F", 0);
                    break;
                case DEMO_FACE_TEMP_C:
                    watch_display_string("TE  22.3#C", 0);
                    break;
                case DEMO_FACE_TEMP_LOG_1:
                    watch_display_string("TL  43.6#F", 0);
                    break;
                case DEMO_FACE_TEMP_LOG_2:
                    watch_display_string("AT 6100000", 0);
                    watch_set_colon();
                    break;
                case DEMO_FACE_DAY_ONE:
                    watch_clear_colon();
                    watch_display_string("DA   12879", 0);
                    break;
                case DEMO_FACE_STOPWATCH:
                    watch_display_string("ST 01042  ", 0);
                    watch_set_colon();
                    break;
                case DEMO_FACE_PULSOMETER:
                    watch_display_string("    68 bpn", 0);
                    watch_clear_colon();
                    break;
                case DEMO_FACE_BATTERY_VOLTAGE:
                    watch_display_string("BA  2.97 V", 0);
                    break;
                case DEMO_FACE_NUM_FACES:
                    // we won't get here, but silence the warning
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            // ignore timeout
            break;
        default:
            break;
    }

    return true;
}

void demo_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(1);
}
