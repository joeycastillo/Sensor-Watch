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

#ifndef INTERVAL_CHIME_FACE_H_
#define INTERVAL_CHIME_FACE_H_

#include "movement.h"

/*
 * A watch face that chimes at configurable intervals (1, 5, 10, 15, or 30 minutes).
 *
 * Press the Alarm button to toggle the chime on/off.
 * Press the Light button to cycle through intervals (1, 5, 10, 15, 30 min).
 * - When turned on: Plays an ascending power-up sound
 * - When turned off: Plays a descending power-down sound
 * - While active: Chimes using the standard hourly signal at the selected interval
 * - Display shows "rE P" and the interval when active
 */

typedef struct {
    bool is_active;
    uint8_t last_minute;
    uint8_t interval_index;  // 0 = 1min, 1 = 5min, 2 = 10min, 3 = 15min, 4 = 30min
} interval_chime_state_t;

void interval_chime_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void interval_chime_face_activate(movement_settings_t *settings, void *context);
bool interval_chime_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void interval_chime_face_resign(movement_settings_t *settings, void *context);

#define interval_chime_face ((const watch_face_t){ \
    interval_chime_face_setup, \
    interval_chime_face_activate, \
    interval_chime_face_loop, \
    interval_chime_face_resign, \
    NULL, \
})

#endif // INTERVAL_CHIME_FACE_H_
