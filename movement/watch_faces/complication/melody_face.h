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

#ifndef MELODY_FACE_H_
#define MELODY_FACE_H_

/*
 * MELODY FACE
 *
 * A music player face for testing and playing melodies on the buzzer.
 * Holds multiple tunes that you can cycle through and play/stop.
 *
 * Display: "MU" identifier, track number, scrolling track name.
 * BELL indicator lights up when a tune is playing.
 *
 * LIGHT button: Next track (cycles through available tunes)
 * ALARM button: Play / Stop toggle
 * MODE button: Move to next watch face
 */

#include "movement.h"

typedef struct {
    uint8_t current_track;    // 0-based index into tune array
    uint8_t scroll_pos;       // current scroll offset for name
    bool playing;             // is a tune currently playing?
} melody_state_t;

void melody_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void melody_face_activate(movement_settings_t *settings, void *context);
bool melody_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void melody_face_resign(movement_settings_t *settings, void *context);

#define melody_face ((const watch_face_t){ \
    melody_face_setup, \
    melody_face_activate, \
    melody_face_loop, \
    melody_face_resign, \
    NULL, \
})

#endif // MELODY_FACE_H_
