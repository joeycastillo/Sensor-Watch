/*
 * MIT License
 *
 * Copyright © 2023-2025 Lionel Ringenbach <ucodia@live.com>
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

#ifndef FLOWTIME_CLOCK_FACE_H_
#define FLOWTIME_CLOCK_FACE_H_

/*
 * FLOWTIME CLOCK FACE
 *
 * Displays the current flowtime.
 *
 * Holding ALARM button will show the real time.
 *
 */

#include "movement.h"

void flowtime_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void flowtime_clock_face_activate(movement_settings_t *settings, void *context);
bool flowtime_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void flowtime_clock_face_resign(movement_settings_t *settings, void *context);

#define flowtime_clock_face ((const watch_face_t) { \
    flowtime_clock_face_setup, \
    flowtime_clock_face_activate, \
    flowtime_clock_face_loop, \
    flowtime_clock_face_resign, \
    NULL, \
})

#endif // FLOWTIME_CLOCK_FACE_H_
