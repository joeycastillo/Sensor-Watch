/*
 * MIT License
 *
 * Copyright (c) 2022 Wesley Ellis
 * Copyright (c) 2022 Joey Castillo
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

#ifndef STOPWATCH_FACE_H_
#define STOPWATCH_FACE_H_

/*
 * STOPWATCH FACE
 *
 * The Stopwatch face provides basic stopwatch functionality: you can start
 * and stop the stopwatch with the alarm button. Pressing the light button
 * when the timer is stopped resets it.
 *
 * This face does not count sub-seconds.
 * See also: "stock_stopwatch_face.h"
 */

#include "movement.h"

typedef struct {
    bool running;
    watch_date_time start_time; // while running, show the difference between this time and now
    uint32_t seconds_counted;   // set this value when paused, and show that instead.
} stopwatch_state_t;

void stopwatch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void stopwatch_face_activate(movement_settings_t *settings, void *context);
bool stopwatch_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void stopwatch_face_resign(movement_settings_t *settings, void *context);

#define stopwatch_face ((const watch_face_t){ \
    stopwatch_face_setup, \
    stopwatch_face_activate, \
    stopwatch_face_loop, \
    stopwatch_face_resign, \
    NULL, \
})

#endif // STOPWATCH_FACE_H_
