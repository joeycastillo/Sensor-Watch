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
#include "tap_tempo_face.h"
#include "watch.h"

#define TICK_FREQUENCY 64
#define MIN_BPM 20
#define MAX_BPM 300
#define TAP_TIMEOUT_TICKS (TICK_FREQUENCY * 3)  // 3 seconds timeout between taps
#define NUM_TAPS 4        // Rolling window of 4 taps (3 intervals)

static uint32_t _tick_count = 0;

// Pendulum animation frames - swings left to right and back
// Using 'O' as the pendulum weight (displays well on 7-segment)
static const char* pendulum_frames[] = {
    "[   ",  // frame 0 - left
    " i  ",  // frame 1
    "  1 ",  // frame 2
    "   ]",  // frame 3 - right
    "  1 ",  // frame 4 - swinging back
    " i  ",  // frame 5
};
#define NUM_PENDULUM_FRAMES 6
#define NUM_BEATS 4

// Calculate BPM from current tap data, returns 0 if not enough taps
static uint16_t _calculate_bpm(tap_tempo_state_t *state) {
    if (state->tap_count < 2) return 0;

    uint32_t total_interval = 0;
    uint8_t num_intervals;

    if (state->tap_count < NUM_TAPS) {
        // Buffer not full - timestamps are sequential at indices 0 to tap_count-1
        num_intervals = state->tap_count - 1;
        for (uint8_t i = 0; i < num_intervals; i++) {
            total_interval += state->tap_timestamps[i + 1] - state->tap_timestamps[i];
        }
    } else {
        // Buffer full - head points to oldest, read in circular order
        num_intervals = NUM_TAPS - 1;
        for (uint8_t i = 0; i < num_intervals; i++) {
            uint8_t older_idx = (state->tap_head + i) % NUM_TAPS;
            uint8_t newer_idx = (state->tap_head + i + 1) % NUM_TAPS;
            total_interval += state->tap_timestamps[newer_idx] - state->tap_timestamps[older_idx];
        }
    }

    if (num_intervals == 0 || total_interval == 0) return 0;

    uint32_t avg_interval = total_interval / num_intervals;

    // BPM = (60 * TICK_FREQUENCY) / interval, rounded to nearest
    uint16_t bpm = ((60 * TICK_FREQUENCY) + (avg_interval / 2)) / avg_interval;

    if (bpm < MIN_BPM) bpm = MIN_BPM;
    if (bpm > MAX_BPM) bpm = MAX_BPM;

    return bpm;
}

static void _tap_tempo_display(tap_tempo_state_t *state) {
    char buf[11];  // 10 chars + null terminator

    if (state->bpm > 0) {
        // Display layout (10 chars total for positions 0-9):
        // Positions 0-3: Pendulum animation (4 chars)
        // Positions 4-6: BPM value (3 digits)
        // Positions 7-8: spaces
        // Position 9: Beat count (1 digit)

        uint16_t bpm = state->bpm;
        if (bpm > 999) bpm = 999;
        uint8_t beat = (state->beat_count % NUM_BEATS) + 1;

        // Build the display string character by character
        // Pendulum (positions 0-3)
        const char *pend = pendulum_frames[state->pendulum_frame];
        buf[0] = pend[0];
        buf[1] = pend[1];
        buf[2] = pend[2];
        buf[3] = pend[3];

        // BPM (positions 4-6) - right aligned
        buf[4] = (bpm >= 100) ? ('0' + (bpm / 100)) : ' ';
        buf[5] = (bpm >= 10)  ? ('0' + ((bpm / 10) % 10)) : ' ';
        buf[6] = '0' + (bpm % 10);

        // Space at position 7
        buf[7] = ' ';

        // Beat counter (positions 8-9)
        buf[8] = ' ';
        buf[9] = '0' + beat;

        buf[10] = '\0';
        watch_display_string(buf, 0);

    } else {
        // Initial state - "tP" then spaces
        watch_display_string("t AptEnnPO", 0);
    }
}

static void _tap_tempo_reset(tap_tempo_state_t *state) {
    state->bpm = 0;
    state->tap_count = 0;
    state->tap_head = 0;
    state->pendulum_frame = 0;
    state->beat_count = 0;
    state->last_frame_tick = 0;
    state->ticks_per_beat = 0;
    memset(state->tap_timestamps, 0, sizeof(state->tap_timestamps));
}

static void _handle_tap(tap_tempo_state_t *state) {
    uint32_t now = _tick_count;

    // Check for timeout - if too long since last tap, reset the tap buffer
    if (state->tap_count > 0) {
        // Find the most recent tap's index
        uint8_t last_idx;
        if (state->tap_count < NUM_TAPS) {
            last_idx = state->tap_count - 1;
        } else {
            // In circular buffer, newest is one before head (head points to oldest)
            last_idx = (state->tap_head + NUM_TAPS - 1) % NUM_TAPS;
        }

        if ((now - state->tap_timestamps[last_idx]) > TAP_TIMEOUT_TICKS) {
            // Timeout - start fresh tap measurements but keep current BPM
            state->tap_count = 0;
            state->tap_head = 0;
            // Don't reset BPM - keep the metronome running
        }
    }

    // Record this tap in circular buffer
    if (state->tap_count < NUM_TAPS) {
        // Still filling the buffer
        state->tap_timestamps[state->tap_count] = now;
        state->tap_count++;
        // When buffer becomes full, head points to index 0 (the oldest)
        if (state->tap_count == NUM_TAPS) {
            state->tap_head = 0;
        }
    } else {
        // Buffer is full, overwrite oldest (at head)
        state->tap_timestamps[state->tap_head] = now;
        state->tap_head = (state->tap_head + 1) % NUM_TAPS;
    }

    // Calculate BPM from current taps - only update if we get a valid value
    uint16_t new_bpm = _calculate_bpm(state);
    if (new_bpm > 0) {
        state->bpm = new_bpm;
    }

    if (state->bpm > 0) {
        // Update ticks per beat for animation
        state->ticks_per_beat = (60 * TICK_FREQUENCY) / state->bpm;
        state->last_frame_tick = now;
    }

    // Play a click sound on each tap
    watch_buzzer_play_note(BUZZER_NOTE_C6, 30);
}

static void _update_metronome(tap_tempo_state_t *state) {
    if (state->bpm == 0 || state->ticks_per_beat == 0) return;

    uint32_t elapsed = _tick_count - state->last_frame_tick;

    // Pendulum completes one full swing (6 frames) per beat
    // So each frame takes ticks_per_beat / 6
    uint32_t ticks_per_frame = state->ticks_per_beat / NUM_PENDULUM_FRAMES;
    if (ticks_per_frame == 0) ticks_per_frame = 1;

    if (elapsed >= ticks_per_frame) {
        uint8_t old_frame = state->pendulum_frame;
        state->pendulum_frame = (state->pendulum_frame + 1) % NUM_PENDULUM_FRAMES;
        state->last_frame_tick = _tick_count;

        // When pendulum completes a full swing (back to frame 0), advance beat count
        if (state->pendulum_frame == 0 && old_frame != 0) {
            state->beat_count = (state->beat_count + 1) % NUM_BEATS;

            // Play click on each beat - accent on beat 1
            if (state->beat_count == 0) {
                watch_buzzer_play_note(BUZZER_NOTE_C7, 20);  // Accent on 1
            } else {
                watch_buzzer_play_note(BUZZER_NOTE_G6, 15);  // Regular beat
            }
        }
    }
}

void tap_tempo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(tap_tempo_state_t));
        tap_tempo_state_t *state = (tap_tempo_state_t *)*context_ptr;
        _tap_tempo_reset(state);
    }
}

void tap_tempo_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    tap_tempo_state_t *state = (tap_tempo_state_t *)context;

    // Request high tick frequency for accurate tap timing and smooth animation
    movement_request_tick_frequency(TICK_FREQUENCY);

    // Reset tick counter
    _tick_count = 0;

    // If BPM was previously set, restart the metronome timing
    if (state->bpm > 0) {
        state->last_frame_tick = 0;
        state->pendulum_frame = 0;
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    }

    // Enable buzzer for click sounds
    watch_enable_buzzer();
}

bool tap_tempo_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    tap_tempo_state_t *state = (tap_tempo_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _tap_tempo_display(state);
            break;

        case EVENT_TICK:
            _tick_count++;
            _update_metronome(state);
            _tap_tempo_display(state);
            break;

        case EVENT_ALARM_BUTTON_UP:
            // Handle tap - always updates BPM
            _handle_tap(state);

            // Update indicator
            if (state->bpm > 0) {
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            }

            _tap_tempo_display(state);
            break;

        case EVENT_ALARM_LONG_PRESS:
            // Long press on ALARM resets
            _tap_tempo_reset(state);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            _tap_tempo_display(state);
            watch_buzzer_play_note(BUZZER_NOTE_C5, 100);
            break;

        case EVENT_LIGHT_BUTTON_UP:
            // Reset the tempo
            _tap_tempo_reset(state);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            _tap_tempo_display(state);
            watch_buzzer_play_note(BUZZER_NOTE_C5, 100);
            break;

        case EVENT_LIGHT_LONG_PRESS:
            // Illuminate LED (standard behavior)
            movement_illuminate_led();
            break;

        case EVENT_MODE_BUTTON_UP:
            // Move to next face
            movement_move_to_next_face();
            break;

        case EVENT_TIMEOUT:
            // On timeout, move back to first face
            movement_move_to_face(0);
            break;

        case EVENT_LOW_ENERGY_UPDATE:
            // In low energy mode, just show static BPM if set (10 chars)
            if (state->bpm > 0) {
                char buf[14];
                sprintf(buf, "    %3d   ", state->bpm);
                watch_display_string(buf, 0);
            } else {
                watch_display_string("TP  ---   ", 0);
            }
            break;

        default:
            break;
    }

    // Return false to prevent sleeping during active use
    if (state->bpm > 0) {
        return false;
    }

    return true;
}

void tap_tempo_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // Reset tick frequency to default
    movement_request_tick_frequency(1);

    // Disable buzzer to save power
    watch_disable_buzzer();

    // Clear indicators
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}
