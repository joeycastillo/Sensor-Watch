/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger
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

#ifndef STOCK_STOPWATCH_FACE_H_
#define STOCK_STOPWATCH_FACE_H_

#include "movement.h"

// This watch face relies heavily on static vars in stock_stopwatch.c.
// The disadvantage is that you cannot use more than one instance of this watch face on
// your custom firmware - but then again, who would want that? The advantage is that accessing
// vars is more direct and faster, and we can save some precious cpu cycles  :-) 

typedef struct {
    bool light_on_button;   // determines whether the light button actually triggers the led
    int8_t callback_slot;
} stock_stopwatch_state_t;

void stock_stopwatch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void stock_stopwatch_face_activate(movement_settings_t *settings, void *context);
bool stock_stopwatch_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void stock_stopwatch_face_resign(movement_settings_t *settings, void *context);

#define stock_stopwatch_face ((const watch_face_t){ \
    stock_stopwatch_face_setup, \
    stock_stopwatch_face_activate, \
    stock_stopwatch_face_loop, \
    stock_stopwatch_face_resign, \
    NULL, \
})

#endif // STOCK_STOPWATCH_FACE_H_
