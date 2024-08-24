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

static void display_keg_counts(uint8_t half_kegs, uint8_t sixtels) {
    char buf[14];
    sprintf(buf, "H  s%-3d%3d", half_kegs, sixtels);
    watch_display_string(buf, 0);
}

static void update_keg_count(uint8_t *keg_count, int8_t increment, bool *using_flag) {
    if (*using_flag) {
        *keg_count += increment;
    } else {
        *using_flag = true;
    }
}

static void reset_keg_count(uint8_t *keg_count, bool *using_flag) {
    if (*using_flag) {
        *keg_count = 0;
    } else {
        *using_flag = true;
    }
}

static void display_bbl_info(uint8_t half_kegs, uint8_t sixtels, bool show_remaining) {
    watch_clear_display();
    float total_bbls = (half_kegs / 2.0f) + (sixtels / 6.0f);
    char buf[14];
    if (show_remaining) {
        float remaining_bbls = 20.0f - total_bbls;
        sprintf(buf, "ch  %3f", remaining_bbls);
    } else {
        sprintf(buf, "br  %3f", total_bbls);
    }
    watch_display_string(buf, 0);
}

bool kegging_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    kegging_state_t *state = (kegging_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Display initial values
            watch_display_string("     keg  ", 0);
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            // Disable LED
            break;

        case EVENT_LIGHT_BUTTON_UP:
            // Increment half-kegs count
            update_keg_count(&(state->half_kegs), 1, &(state->using));
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

        case EVENT_LIGHT_LONG_UP:
            // Decrement half-kegs count
            update_keg_count(&(state->half_kegs), -1, &(state->using));
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

        case EVENT_LIGHT_REALLY_LONG_PRESS:
            // Reset half-keg count
            reset_keg_count(&(state->half_kegs), &(state->using));
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

        case EVENT_ALARM_BUTTON_DOWN:
            // Wake up the display and set state->using = true
            break;

        case EVENT_ALARM_BUTTON_UP:
            // Increment sixtels count
            update_keg_count(&(state->sixtels), 1, &(state->using));
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

        case EVENT_ALARM_LONG_UP:
            // Decrement sixtels count
            update_keg_count(&(state->sixtels), -1, &(state->using));
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

        case EVENT_ALARM_REALLY_LONG_PRESS:
            // Reset sixtels count
            reset_keg_count(&(state->sixtels), &(state->using));
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

         case EVENT_MODE_LONG_PRESS:
            // Show remaining BBLs
            if (state->half_kegs == 0 && state->sixtels == 0) {
                movement_move_to_face(0);
            } else {
                display_bbl_info(state->half_kegs, state->sixtels, true);
            }
            break;

        case EVENT_MODE_REALLY_LONG_PRESS:
            // Show total BBLs
            display_bbl_info(state->half_kegs, state->sixtels, false);
            break;

        case EVENT_MODE_LONG_UP:
        case EVENT_MODE_REALLY_LONG_UP:
            // Show keg counts
            display_keg_counts(state->half_kegs, state->sixtels);
            break;

        case EVENT_LOW_ENERGY_UPDATE:
            // Let the user know low energy mode has been activated
            state->using = false;
            watch_clear_display();
            watch_display_string("     keg  ", 0);
            watch_start_tick_animation(1000);
            break;

        case EVENT_TIMEOUT:
            // Don't timeout
            break;

        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void kegging_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
