/*
 * MIT License
 *
 * Copyright (c) 2022 <#author_name#>
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

#ifndef CALCULATOR_FACE_H_
#define CALCULATOR_FACE_H_

#include "movement.h"

#define CALC_STACK_SIZE 10

enum calculator_mode {
    OPERATION = 0,
    NUMBER,
};

typedef struct {
    double stack[CALC_STACK_SIZE];
    uint8_t stack_index;
    uint8_t fn_index;

    double min;
    double max;

    enum calculator_mode mode;
} calculator_state_t;

void calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void calculator_face_activate(movement_settings_t *settings, void *context);
bool calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void calculator_face_resign(movement_settings_t *settings, void *context);

#define calculator_face ((const watch_face_t){ \
    calculator_face_setup, \
    calculator_face_activate, \
    calculator_face_loop, \
    calculator_face_resign, \
    NULL, \
})

#endif // CALCULATOR_FACE_H_
