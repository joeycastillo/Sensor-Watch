/*
 * MIT License
 *
 * Copyright (c) 2026 Stebbs
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
#include <stdio.h>
#include "tiberium_face.h"
#include "watch.h"

#define TICK_FREQUENCY 8

// View modes
#define VIEW_HARVESTER 0
#define VIEW_REFINERY 1

// Starting count (counts down to 0)
#define START_COUNT 30

// Explosion loops 3 times for grand finale
#define EXPLOSION_LOOPS 3

// Animation states
#define STATE_GATHERING 0
#define STATE_EXPLOSION 1

// Harvester animation - collects from left, deposits right
static const char* harvester_frames[] = {
    "81   3",  // frame 0 - harvester on left, picking up
    "8 1  3",  // frame 1 - moving right
    "8  1 3",  // frame 2
    "8   13",  // frame 3
    "[    8",  // frame 4 - deposit on right
    "[   3]",  // frame 5 - harvester returns
    "[  3 ]",  // frame 6
    "[ 3  ]",  // frame 7
    "[3   ]",  // frame 8
    "8    ]",  // frame 9 - back at left, ready to pick up
};
#define NUM_HARVESTER_FRAMES 10

// Ion cannon explosion animation when countdown hits 0
static const char* explosion_frames[] = {
    "  **  ",  // burst
    " *  * ",  // expand
    "*    *",  // big
    " *  * ",  // contract
    "  **  ",  // small
    ".    .",  // twinkle
    " .  . ",  // fade
    "  ..  ",  // embers
    "      ",  // done
    "  oo  ",  // new stars born
    " o  o ",
    "      ",
};
#define NUM_EXPLOSION_FRAMES 12

// Build refinery tank display - fills left to right (6 chars only)
// Counter goes 30->0, so fullness = (30 - counter) / 30
static void _build_refinery(char *buf, uint8_t counter, bool blink_on) {
    // How full is the refinery? (0 at start, 6 levels when counter=0)
    // counter=30 -> 0 filled, counter=0 -> 6 filled
    uint8_t filled = ((START_COUNT - counter) * 6) / START_COUNT;

    // Refinery tank: [    ] (6 chars)
    // Fill left to right: positions 1,2,3,4 are inner fill area
    strcpy(buf, "[    ]");  // empty tank

    // Fill left to right, newest segment blinks
    if (filled >= 1) {
        if (filled == 1 && !blink_on) { /* blink newest */ }
        else { buf[1] = '0'; }
    }
    if (filled >= 2) {
        buf[1] = '0';  // previous now solid
        if (filled == 2 && !blink_on) { /* blink newest */ }
        else { buf[2] = '0'; }
    }
    if (filled >= 3) {
        buf[1] = '0'; buf[2] = '0';  // previous solid
        if (filled == 3 && !blink_on) { /* blink newest */ }
        else { buf[3] = '0'; }
    }
    if (filled >= 4) {
        buf[1] = '0'; buf[2] = '0'; buf[3] = '0';  // previous solid
        if (filled == 4 && !blink_on) { /* blink newest */ }
        else { buf[4] = '0'; }
    }
    if (filled >= 5) {
        buf[1] = '0'; buf[2] = '0'; buf[3] = '0'; buf[4] = '0';  // all inner solid
        if (filled == 5 && !blink_on) { /* blink newest */ }
        else { buf[5] = '0'; }  // overflow right
    }
    if (filled >= 6) {
        buf[1] = '0'; buf[2] = '0'; buf[3] = '0'; buf[4] = '0'; buf[5] = '0';
        if (filled == 6 && !blink_on) { /* blink newest */ }
        else { buf[0] = '0'; }  // overflow left - FULL!
    }

    buf[6] = '\0';
}

static void _tiberium_display(tiberium_state_t *state) {
    char display_buf[11];

    // Clear display first to prevent ghosting
    watch_clear_display();

    if (state->anim_state == STATE_EXPLOSION) {
        // Show explosion animation across whole display
        sprintf(display_buf, "  00%s", explosion_frames[state->explosion_frame]);
    } else if (state->view_mode == VIEW_REFINERY) {
        // Show refinery filling view with blink and counter
        char refinery_buf[7];
        _build_refinery(refinery_buf, state->counter, state->blink_on);
        sprintf(display_buf, "  %2d%s", state->counter, refinery_buf);
    } else {
        // Show harvester view: counter at top (positions 2-3), harvester at bottom (4-9)
        sprintf(display_buf, "  %2d%s", state->counter, harvester_frames[state->frame]);
    }

    watch_display_string(display_buf, 0);
}

void tiberium_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tiberium_state_t));
        tiberium_state_t *state = (tiberium_state_t *)*context_ptr;
        state->frame = 0;
        state->counter = START_COUNT;  // Start at 30, count down
        state->view_mode = VIEW_HARVESTER;
        state->anim_state = STATE_GATHERING;
        state->explosion_frame = 0;
        state->explosion_loops = 0;
        state->blink_on = true;
        state->paused = false;
    }
}

void tiberium_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(TICK_FREQUENCY);
}

bool tiberium_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    tiberium_state_t *state = (tiberium_state_t *)context;
    (void) settings;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _tiberium_display(state);
            break;

        case EVENT_TICK:
            if (!state->paused) {
                // Toggle blink state for refinery display
                state->blink_on = !state->blink_on;

                if (state->anim_state == STATE_EXPLOSION) {
                    // Run explosion animation
                    state->explosion_frame++;
                    if (state->explosion_frame >= NUM_EXPLOSION_FRAMES) {
                        state->explosion_frame = 0;
                        state->explosion_loops++;
                        // After 3 loops, reset everything
                        if (state->explosion_loops >= EXPLOSION_LOOPS) {
                            state->anim_state = STATE_GATHERING;
                            state->explosion_loops = 0;
                            state->counter = START_COUNT;  // Reset to 30
                            state->frame = 0;
                        }
                    }
                } else {
                    // Normal gathering
                    state->frame++;
                    if (state->frame >= NUM_HARVESTER_FRAMES) {
                        state->frame = 0;
                        // Each full harvester cycle decrements counter
                        if (state->counter > 0) {
                            state->counter--;
                        }
                        if (state->counter == 0) {
                            // Trigger explosion!
                            state->anim_state = STATE_EXPLOSION;
                            state->explosion_frame = 0;
                        }
                    }
                }
            }
            _tiberium_display(state);
            break;

        case EVENT_ALARM_BUTTON_UP:
            // Toggle between harvester and refinery view
            if (state->view_mode == VIEW_HARVESTER) {
                state->view_mode = VIEW_REFINERY;
            } else {
                state->view_mode = VIEW_HARVESTER;
            }
            _tiberium_display(state);
            break;

        case EVENT_LIGHT_BUTTON_UP:
            movement_illuminate_led();
            break;

        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
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

void tiberium_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(1);
}
