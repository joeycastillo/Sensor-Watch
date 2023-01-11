/*
 * MIT License
 *
 * Copyright (c) 2022 Jeremy O'Brien
 * Base code copied from Spencer Bywater's probability face
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
#include "tarot_face.h"

#define NUM_TAROT_CARDS 22
#define TAROT_ANIMATION_TICK_FREQUENCY 8


// --------------
// Custom methods
// --------------

static char *major_arcana[NUM_TAROT_CARDS] = {
    " FOOL ",
    "Mgcian",
    "HiPrst",
    "Empres",
    "Empror",
    "Hiroph",
    "Lovers",
    "Chriot",
    "Strgth",
    "Hermit",
    " Frtun",
    "Justce",
    "HngMan",
    " Death",
    " tmprn",
    " Devil",
    " Tower",
    "  Star",
    " MOON ",
    "  Sun ",
    "Jdgmnt",
    " World",
};

static void tarot_display(tarot_state_t *state) {
    char buf[8];

    if (state->drawn_cards[0] != 0xff) {
        sprintf(buf, "%d", state->current_card + 1);
        watch_display_string(buf, 3);
        sprintf(buf, "%s", major_arcana[state->drawn_cards[state->current_card]]);
        watch_display_string(buf, 4);
    }
}

static uint8_t draw_one_card(void) {
    // Emulator: use rand. Hardware: use arc4random.
#if __EMSCRIPTEN__
    return rand() % NUM_TAROT_CARDS;
#else
    return arc4random_uniform(NUM_TAROT_CARDS);
#endif
}

static void pick_cards(tarot_state_t *state) {
    // this is all a bit verbose but I prefer simplicity over clever tricks
    state->drawn_cards[0] = draw_one_card();

    state->drawn_cards[1] = draw_one_card();
    while (state->drawn_cards[1] == state->drawn_cards[0])
        state->drawn_cards[1] = draw_one_card();

    state->drawn_cards[2] = draw_one_card();
    while (state->drawn_cards[2] == state->drawn_cards[1] ||
            state->drawn_cards[2] == state->drawn_cards[0])
        state->drawn_cards[2] = draw_one_card();

    state->current_card = 0;
}

static void display_animation(tarot_state_t *state) {
    if (state->is_picking) {
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
            state->is_picking = false;
            movement_request_tick_frequency(1);
            tarot_display(state);
        }
    }
}


// ---------------------------
// Standard watch face methods
// ---------------------------
void tarot_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tarot_state_t));
        memset(*context_ptr, 0, sizeof(tarot_state_t));
    }
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
}

void tarot_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    tarot_state_t *state = (tarot_state_t *)context;

    watch_display_string("TA", 0);
    state->current_card = 0;
    state->drawn_cards[0] = 0xff;
}

bool tarot_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    tarot_state_t *state = (tarot_state_t *)context;

    if (state->is_picking && event.event_type != EVENT_TICK) {
        return true;
    }

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string(" DRAW ", 4);
            break;
        case EVENT_TICK:
            display_animation(state);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // Change how many sides the die has
            if (state->drawn_cards[0] != 0xff) {
                state->current_card = (state->current_card + 1) % 3;
                tarot_display(state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Draw cards
            watch_display_string("      ", 4);
            pick_cards(state);
            state->is_picking = true;
            // card picking animation begins on next tick and new cards will be displayed on completion
            movement_request_tick_frequency(TAROT_ANIMATION_TICK_FREQUENCY);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            watch_display_string("SLEEP ", 4);
            break;
        default:
            break;
    }

    return true;
}

void tarot_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
