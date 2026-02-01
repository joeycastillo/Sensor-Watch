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
#include "stebbs_face.h"
#include "watch.h"

#define TICK_FREQUENCY 4

// Bottom text to scroll (6 chars visible at a time, positions 4-9)
// Padded with spaces so it scrolls in and out cleanly
#define SCROLL_TEXT "      StEbbS Watch"
#define SCROLL_TEXT_LEN 18

// Animation states
#define STATE_SCROLLING  0
#define STATE_BLINKING   1
#define STATE_FIREWORKS  2

// Fireworks loops 3 times
#define FIREWORKS_LOOPS 3

// Fireworks animation frames for top 4 positions
static const char* fireworks_frames[] = {
    "    ",  // frame 0 - dark
    "  . ",  // frame 1 - spark rising
    "  ' ",  // frame 2 - spark
    "  * ",  // frame 3 - burst begins
    " ***",  // frame 4 - explosion
    "* * ",  // frame 5 - expanding
    "*  *",  // frame 6 - peak
    "'  '",  // frame 7 - fading
    ".  .",  // frame 8 - embers
    "    ",  // frame 9 - done
};
#define NUM_FIREWORKS_FRAMES 10

// Get loading bar string based on progress (0-4 segments filled)
static void _get_loading_bar(char *buf, uint8_t scroll_pos) {
    // Map scroll position to 0-4 filled segments using fixed thresholds
    // scroll_pos goes from 0 to SCROLL_TEXT_LEN-1 (0-17)
    int filled = 0;
    if (scroll_pos >= 4) filled = 1;
    if (scroll_pos >= 8) filled = 2;
    if (scroll_pos >= 12) filled = 3;
    if (scroll_pos >= 16) filled = 4;

    // Use underscore for filled segments (bottom segment on 7-seg)
    for (int i = 0; i < 4; i++) {
        buf[i] = (i < filled) ? '_' : ' ';
    }
    buf[4] = '\0';
}

static void _get_time_string(char *buf, movement_settings_t *settings) {
    watch_date_time date_time = watch_rtc_get_date_time();
    uint8_t hour = date_time.unit.hour;

    if (!settings->bit.clock_mode_24h) {
        if (hour == 0) hour = 12;
        else if (hour > 12) hour -= 12;
    }

    // Format: HHMMSS (colon is separate segment)
    sprintf(buf, "%2d%02d%02d", hour, date_time.unit.minute, date_time.unit.second);
}

static void _stebbs_display(stebbs_state_t *state, movement_settings_t *settings) {
    char display_buf[11];
    char bottom_buf[7];
    char top_buf[5];

    // Top animation (positions 0-3)
    if (state->anim_state == STATE_FIREWORKS) {
        memcpy(top_buf, fireworks_frames[state->fireworks_frame], 4);
        top_buf[4] = '\0';
    } else if (state->anim_state == STATE_SCROLLING) {
        _get_loading_bar(top_buf, state->scroll_pos);
    } else {
        // During blinking, keep loading bar full
        strcpy(top_buf, "____");
    }
    memcpy(display_buf, top_buf, 4);

    // Bottom content (positions 4-9)
    if (state->anim_state == STATE_SCROLLING) {
        watch_clear_colon();
        // Scroll text - no wraparound
        for (int i = 0; i < 6; i++) {
            int idx = state->scroll_pos + i;
            if (idx < SCROLL_TEXT_LEN) {
                bottom_buf[i] = SCROLL_TEXT[idx];
            } else {
                bottom_buf[i] = ' ';  // Past end of text, show space
            }
        }
        bottom_buf[6] = '\0';
    } else if (state->anim_state == STATE_FIREWORKS) {
        // During fireworks, always show time with colon
        watch_set_colon();
        _get_time_string(bottom_buf, settings);
    } else {
        // Blinking time
        if (state->blink_on) {
            watch_set_colon();
            _get_time_string(bottom_buf, settings);
        } else {
            watch_clear_colon();
            strcpy(bottom_buf, "      ");
        }
    }

    memcpy(display_buf + 4, bottom_buf, 6);
    display_buf[10] = '\0';

    watch_display_string(display_buf, 0);
}

void stebbs_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(stebbs_state_t));
        stebbs_state_t *state = (stebbs_state_t *)*context_ptr;
        state->scroll_pos = 0;
        state->fireworks_frame = 0;
        state->fireworks_ticks = 0;
        state->anim_state = STATE_SCROLLING;
        state->blink_count = 0;
        state->blink_on = true;
        state->paused = false;
    }
}

void stebbs_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(TICK_FREQUENCY);
}

bool stebbs_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    stebbs_state_t *state = (stebbs_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _stebbs_display(state, settings);
            break;

        case EVENT_TICK:
            if (!state->paused) {
                if (state->anim_state == STATE_SCROLLING) {
                    state->scroll_pos++;
                    // When text has fully scrolled off
                    if (state->scroll_pos >= SCROLL_TEXT_LEN) {
                        state->anim_state = STATE_BLINKING;
                        state->blink_count = 0;
                        state->blink_on = true;
                        state->scroll_pos = 0;
                    }
                } else if (state->anim_state == STATE_BLINKING) {
                    // Toggle blink
                    state->blink_on = !state->blink_on;
                    if (!state->blink_on) {
                        state->blink_count++;
                    }
                    // After 3 blinks, switch to fireworks for the finale
                    if (state->blink_count >= 3 && state->blink_on) {
                        state->anim_state = STATE_FIREWORKS;
                        state->fireworks_frame = 0;
                        state->fireworks_ticks = 0;
                    }
                } else if (state->anim_state == STATE_FIREWORKS) {
                    // Advance fireworks animation
                    state->fireworks_frame++;

                    // Check if we completed a loop
                    if (state->fireworks_frame >= NUM_FIREWORKS_FRAMES) {
                        state->fireworks_frame = 0;
                        state->fireworks_ticks++;  // Using ticks as loop counter

                        // After 3 complete loops, restart the whole sequence
                        if (state->fireworks_ticks >= FIREWORKS_LOOPS) {
                            state->anim_state = STATE_SCROLLING;
                            state->scroll_pos = 0;
                            state->fireworks_frame = 0;
                            state->fireworks_ticks = 0;
                            state->blink_count = 0;
                        }
                    }
                }
            }
            _stebbs_display(state, settings);
            break;

        case EVENT_ALARM_BUTTON_UP:
            // Toggle pause
            state->paused = !state->paused;
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

        case EVENT_LOW_ENERGY_UPDATE:
            // In low energy mode, just show static time
            {
                char buf[11];
                char time_buf[7];
                watch_set_colon();
                _get_time_string(time_buf, settings);
                sprintf(buf, "St  %s", time_buf);
                watch_display_string(buf, 0);
            }
            break;

        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void stebbs_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    movement_request_tick_frequency(1);
    watch_clear_colon();
}
