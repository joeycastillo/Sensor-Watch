/*
 * MIT License
 *
 * Copyright (c) 2024 Patrick McGuire
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
#include "kegging_face.h"

void kegging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(kegging_state_t));
        kegging_state_t *state = (kegging_state_t *) *context_ptr;
        memset(state, 0, sizeof(kegging_state_t));  // Initialize counters to 0
        state->watch_face_index = watch_face_index;
        state->using = false;
    }
}

void kegging_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    kegging_state_t *state = (kegging_state_t *)context;
    state->using = false;

    // Handle any tasks related to your watch face coming on screen.
}

bool kegging_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    kegging_state_t *state = (kegging_state_t *)context;
    char buf[14];

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Display initial values
            watch_display_string("     keg  ", 0);
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            // Wake up the display and disable LED
            if (!state->using) {
                state->half_kegs--;
                state->using = true;
            }
            break;

        case EVENT_LIGHT_BUTTON_UP:
            // Increment half-kegs count
            state->half_kegs++;
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        case EVENT_LIGHT_LONG_UP:
            // Decrement half-kegs count
            state->half_kegs--;
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        case EVENT_LIGHT_REALLY_LONG_PRESS:
            // Reset half-keg count
            state->half_kegs = 0;
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        case EVENT_ALARM_BUTTON_DOWN:
            // Wake up the display
            if (!state->using) {
                state->sixtels--;
                state->using = true;
            }
            break;

        case EVENT_ALARM_BUTTON_UP:
            // Increment sixtels count
            state->sixtels++;
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        case EVENT_ALARM_LONG_UP:
            // Decrement sixtels count
            state->sixtels--;
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        case EVENT_ALARM_REALLY_LONG_PRESS:
            // Reset sixtels count
            state->sixtels = 0;
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

         case EVENT_MODE_LONG_PRESS:
            // Show total BBLs and remaining BBLs
            if (state->half_kegs == 0 && state->sixtels == 0) {
                movement_move_to_face(0);
            } else {
                int8_t total_bbls = (state->half_kegs / 2) + (state->sixtels / 6);
                int8_t remaining_bbls = 20 - total_bbls;
                watch_clear_display();
                sprintf(buf, "be C%-3d%3d", total_bbls, remaining_bbls);
                watch_display_string(buf, 0);
            }
            break;
            
        case EVENT_MODE_LONG_UP:
            // Show totals again
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        case EVENT_MODE_REALLY_LONG_PRESS:
            if (state->half_kegs == 0 && state->sixtels == 0) movement_move_to_face(0);
            break;

        case EVENT_MODE_REALLY_LONG_UP:
            // Show totals again
            sprintf(buf, "H  s%-3d%3d", state->half_kegs, state->sixtels);
            watch_display_string(buf, 0);
            break;

        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void kegging_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

