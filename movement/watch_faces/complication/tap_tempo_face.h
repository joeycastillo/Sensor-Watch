/*
 * MIT License
 *
 * Copyright (c) 2024 Your Name
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

#ifndef TAP_TEMPO_FACE_H_
#define TAP_TEMPO_FACE_H_

/*
 * TAP TEMPO BPM FACE
 *
 * A tap tempo watch face inspired by the Akai MPC.
 * Tap the ALARM button to set BPM - keeps updating with each tap!
 *
 * Display layout:
 * - Positions 0-3: Pendulum animation (swings left-right-left per beat)
 * - Positions 4-6: BPM value (e.g., "120")
 *
 * Uses a rolling window of last 4 taps (3 intervals) to calculate BPM.
 * Keep tapping to refine the tempo - it never locks in!
 *
 * Usage:
 * - ALARM button: Tap to set/update tempo (updates after 2+ taps)
 * - LIGHT button: Reset and clear the current tempo
 * - MODE button: Move to next watch face
 */

#include "movement.h"

typedef struct {
    uint16_t bpm;                    // Current BPM (20-300 range)
    uint32_t tap_timestamps[4];      // Circular buffer of last 4 taps (in ticks)
    uint8_t tap_count;               // Number of taps received so far
    uint8_t tap_head;                // Head of circular buffer
    uint32_t last_frame_tick;        // Tick count at last pendulum frame change
    uint32_t ticks_per_beat;         // Calculated ticks between beats
    uint8_t pendulum_frame;          // Current pendulum animation frame (0-5)
    uint8_t beat_count;              // Current beat in measure (0-3 for beats 1-4)
} tap_tempo_state_t;

void tap_tempo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tap_tempo_face_activate(movement_settings_t *settings, void *context);
bool tap_tempo_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tap_tempo_face_resign(movement_settings_t *settings, void *context);

#define tap_tempo_face ((const watch_face_t){ \
    tap_tempo_face_setup, \
    tap_tempo_face_activate, \
    tap_tempo_face_loop, \
    tap_tempo_face_resign, \
    NULL, \
})

#endif // TAP_TEMPO_FACE_H_
