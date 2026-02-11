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
#include "melody_face.h"
#include "melody_library.h"
#include "watch.h"

// Static pointer so buzzer callback can update state
static melody_state_t *_active_state = NULL;

static void _melody_finished_callback(void) {
    if (_active_state != NULL) {
        _active_state->playing = false;
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
}

static void _melody_display(melody_state_t *state) {
    char buf[11];
    const melody_tune_t *tune = &melody_tunes[state->current_track];

    // Build display: "MU" + track number + 6-char scrolling name
    uint8_t track_num = state->current_track + 1;

    // Get 6 characters from the scrolling name starting at scroll_pos
    char name_window[7];
    for (int i = 0; i < 6; i++) {
        uint8_t idx = (state->scroll_pos + i) % tune->scroll_name_len;
        name_window[i] = tune->scroll_name[idx];
    }
    name_window[6] = '\0';

    sprintf(buf, "MU%2d%s", track_num, name_window);
    watch_display_string(buf, 0);

    // BELL indicator shows play state
    if (state->playing) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }

    watch_clear_colon();
}

void melody_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(melody_state_t));
        melody_state_t *state = (melody_state_t *)*context_ptr;
        memset(state, 0, sizeof(melody_state_t));
    }
}

void melody_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    melody_state_t *state = (melody_state_t *)context;
    _active_state = state;
    movement_request_tick_frequency(4);
}

bool melody_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    melody_state_t *state = (melody_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _melody_display(state);
            break;

        case EVENT_TICK:
            // Advance scroll position
            {
                const melody_tune_t *tune = &melody_tunes[state->current_track];
                state->scroll_pos = (state->scroll_pos + 1) % tune->scroll_name_len;
            }
            _melody_display(state);
            break;

        case EVENT_LIGHT_BUTTON_UP:
            // Next track - stop if playing
            if (state->playing) {
                watch_buzzer_abort_sequence();
                state->playing = false;
            }
            state->current_track = (state->current_track + 1) % MELODY_NUM_TUNES;
            state->scroll_pos = 0;
            _melody_display(state);
            break;

        case EVENT_ALARM_BUTTON_UP:
            // Play / Stop toggle
            if (state->playing) {
                watch_buzzer_abort_sequence();
                state->playing = false;
            } else {
                state->playing = true;
                const melody_tune_t *tune = &melody_tunes[state->current_track];
                watch_buzzer_play_sequence((int8_t *)tune->sequence, _melody_finished_callback);
            }
            _melody_display(state);
            break;

        case EVENT_TIMEOUT:
            if (!state->playing) {
                movement_move_to_face(0);
            }
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            // Don't illuminate LED
            break;

        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void melody_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    melody_state_t *state = (melody_state_t *)context;

    if (state->playing) {
        watch_buzzer_abort_sequence();
        state->playing = false;
    }
    watch_clear_indicator(WATCH_INDICATOR_BELL);

    _active_state = NULL;
    movement_request_tick_frequency(1);
}
