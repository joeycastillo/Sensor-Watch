/*
 * MIT License
 *
 * Copyright (c) 2022 Shogo Okamoto
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

#ifndef COUNTER_FACE_H_
#define COUNTER_FACE_H_

/*
 * COUNTER face
 *
 * Counter face is designed to count the number of running laps during exercises.
 *
 * Usage:
 * Short-press ALARM to increment the counter (loops at 99)
 * Long-press ALARM to reset the counter.
 * Long-press LIGHT to toggle sound.
 */

#include "movement.h"

typedef struct {
    uint8_t counter_idx;
    bool beep_on;
} counter_state_t;


void counter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void counter_face_activate(movement_settings_t *settings, void *context);
bool counter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void counter_face_resign(movement_settings_t *settings, void *context);

void print_counter(counter_state_t *state);
void beep_counter(counter_state_t *state);

#define counter_face ((const watch_face_t){ \
    counter_face_setup, \
    counter_face_activate, \
    counter_face_loop, \
    counter_face_resign, \
    NULL, \
})

#endif // COUNTER_FACE_H_
