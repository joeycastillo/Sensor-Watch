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

#ifndef STEBBS_FACE_H_
#define STEBBS_FACE_H_

/*
 * STEBBS WATCH FACE
 *
 * A scrolling text watch face that displays "Stebbs Watch XX:XX"
 * where XX:XX is the current time.
 *
 * The text scrolls continuously across the display.
 *
 * Usage:
 * - LIGHT button: Illuminate LED
 * - MODE button: Move to next watch face
 * - ALARM button: Pause/resume scrolling
 */

#include "movement.h"

typedef struct {
    uint8_t scroll_pos;       // Current scroll position
    uint8_t fireworks_frame;  // Current fireworks animation frame
    uint8_t fireworks_ticks;  // Ticks elapsed during fireworks
    uint8_t anim_state;       // 0 = scrolling, 1 = blinking, 2 = fireworks
    uint8_t blink_count;      // Number of blinks completed
    bool blink_on;            // Current blink state
    bool paused;              // Animation paused
} stebbs_state_t;

void stebbs_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void stebbs_face_activate(movement_settings_t *settings, void *context);
bool stebbs_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void stebbs_face_resign(movement_settings_t *settings, void *context);

#define stebbs_face ((const watch_face_t){ \
    stebbs_face_setup, \
    stebbs_face_activate, \
    stebbs_face_loop, \
    stebbs_face_resign, \
    NULL, \
})

#endif // STEBBS_FACE_H_
