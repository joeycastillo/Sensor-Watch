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

#if __EMSCRIPTEN__
#include <time.h>
#else
#include "saml22j18a.h"
#endif

#include <stdlib.h>
#include <string.h>
#include "simple_coin_flip_face.h"

#define SIMPLE_COIN_FLIP_REQUIRE_LONG_PRESS_FOR_REFLIP true

void simple_coin_flip_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(simple_coin_flip_state_t));
        memset(*context_ptr, 0, sizeof(simple_coin_flip_state_t));
    }
}

void simple_coin_flip_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static uint32_t get_random(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

static void animation_0() {
    watch_display_string("  ", 8);
    watch_set_pixel(0, 3);
    watch_set_pixel(0, 6);
}

static void animation_1() {
    watch_display_string("  ", 8);
    watch_set_pixel(1, 3);
    watch_set_pixel(1, 5);
}

static void animation_2() {
    watch_display_string("  ", 8);
    watch_set_pixel(2, 2);
    watch_set_pixel(2, 4);
}

bool simple_coin_flip_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    simple_coin_flip_state_t *state = (simple_coin_flip_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string("flip", 5);
            state->animation_frame = 0;
            break;
        case EVENT_TICK:
            switch (state->animation_frame) {
                case 0:
                case 7:
                    return true;
                case 1:
                    movement_request_tick_frequency(8);
                    watch_display_string("      ", 4);
                    // fallthrough
                case 5:
                    animation_0();
                    break;
                case 2:
                case 4:
                    animation_1();
                    break;
                case 3:
                    animation_2();
                    break;
                case 6:
                    movement_request_tick_frequency(1);
                    if (get_random(2)) {
                        watch_display_string("Heads ", 4);
                    } else {
                        watch_display_string(" Tails", 4);
                    }
                    break;
            }
            state->animation_frame++;
            break;
        case EVENT_LIGHT_BUTTON_UP:
        case EVENT_ALARM_BUTTON_UP:
            if (!SIMPLE_COIN_FLIP_REQUIRE_LONG_PRESS_FOR_REFLIP || state->animation_frame == 0) {
                state->animation_frame = 1;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
        case EVENT_LIGHT_LONG_PRESS:
            state->animation_frame = 1;
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void simple_coin_flip_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

