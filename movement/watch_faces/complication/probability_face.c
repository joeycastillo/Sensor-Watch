/*
 * MIT License
 *
 * Copyright (c) 2022 Spencer Bywater
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

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include "probability_face.h"

#define DEFAULT_DICE_SIDES 2
#define PROBABILITY_ANIMATION_TICK_FREQUENCY 8
const uint16_t NUM_DICE_TYPES = 8; // Keep this consistent with # of dice types below
const uint16_t DICE_TYPES[] = {2, 4, 6, 8, 10, 12, 20, 100};


// --------------
// Custom methods
// --------------

static void display_dice_roll(probability_state_t *state) {
    char buf[8];
    if (state->rolled_value == 0) {
        if (state->dice_sides == 100) {
            sprintf(buf, " C    ");
        } else {
            sprintf(buf, "%2d    ", state->dice_sides);
        }
    } else if (state->dice_sides == 2) {
        if (state->rolled_value == 1) {
            sprintf(buf, "%2d   H", state->dice_sides);
        } else {
            sprintf(buf, "%2d   T", state->dice_sides);
        }
    } else if (state->dice_sides == 100) {
        sprintf(buf, " C %3d", state->rolled_value);
    } else {
        sprintf(buf, "%2d %3d", state->dice_sides, state->rolled_value);
    }
    watch_display_string(buf, 4);
}

static void generate_random_number(probability_state_t *state) {
    // Emulator: use rand. Hardware: use arc4random.
    #if __EMSCRIPTEN__
    state->rolled_value = rand() % state->dice_sides + 1;
    #else
    state->rolled_value = arc4random_uniform(state->dice_sides) + 1;
    #endif
}

static void display_dice_roll_animation(probability_state_t *state) {
    if (state->is_rolling) {
        if (state->animation_frame == 0) {
            watch_display_string("   ", 7);
            watch_set_pixel(1, 4);
            watch_set_pixel(1, 6);
            state->animation_frame = 1;
        } else if (state->animation_frame == 1) {
            watch_clear_pixel(1, 4);
            watch_clear_pixel(1, 6);
            watch_set_pixel(2, 4);
            watch_set_pixel(0, 6);
            state->animation_frame = 2;
        } else if (state->animation_frame == 2) {
            watch_clear_pixel(2, 4);
            watch_clear_pixel(0, 6);
            watch_set_pixel(2, 5);
            watch_set_pixel(0, 5);
            state->animation_frame = 3;
        } else if (state->animation_frame == 3) {
            state->animation_frame = 0;
            state->is_rolling = false;
            movement_request_tick_frequency(1);
            display_dice_roll(state);
        }
    }
}


// ---------------------------
// Standard watch face methods
// ---------------------------
void probability_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(probability_state_t));
        memset(*context_ptr, 0, sizeof(probability_state_t));
    }
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
}

void probability_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    probability_state_t *state = (probability_state_t *)context;

    state->dice_sides = DEFAULT_DICE_SIDES;
    state->rolled_value = 0;
    watch_display_string("PR", 0);
}

bool probability_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    probability_state_t *state = (probability_state_t *)context;

    if (state->is_rolling && event.event_type != EVENT_TICK) {
        return true;
    }

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            display_dice_roll(state);
            break;
        case EVENT_TICK:
            display_dice_roll_animation(state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // Change how many sides the die has
            for (int i = 0; i < NUM_DICE_TYPES; i++) {
                if (DICE_TYPES[i] == state->dice_sides) {
                    if (i == NUM_DICE_TYPES - 1) {
                        state->dice_sides = DICE_TYPES[0];
                    } else {
                        state->dice_sides = DICE_TYPES[i + 1];
                    }
                    break;
                }
            }
            state->rolled_value = 0;
            display_dice_roll(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Roll the die
            generate_random_number(state);
            state->is_rolling = true;
            // Dice rolling animation begins on next tick and new roll will be displayed on completion
            movement_request_tick_frequency(PROBABILITY_ANIMATION_TICK_FREQUENCY);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            watch_display_string("SLEEP ", 4);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void probability_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
