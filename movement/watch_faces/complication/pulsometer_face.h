/*
 * MIT License
 *
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

#ifndef PULSOMETER_FACE_H_
#define PULSOMETER_FACE_H_

#include "movement.h"

typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} pulsometer_state_t;

void pulsometer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void pulsometer_face_activate(movement_settings_t *settings, void *context);
bool pulsometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void pulsometer_face_resign(movement_settings_t *settings, void *context);

#define pulsometer_face ((const watch_face_t){ \
    pulsometer_face_setup, \
    pulsometer_face_activate, \
    pulsometer_face_loop, \
    pulsometer_face_resign, \
    NULL, \
})

#endif // PULSOMETER_FACE_H_
