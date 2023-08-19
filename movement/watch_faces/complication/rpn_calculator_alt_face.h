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

#define CALC_MAX_STACK_SIZE 20

enum calculator_mode {
    CALC_OPERATION = 0,
    CALC_NUMBER,
};

typedef struct {
    double stack[CALC_MAX_STACK_SIZE];
    uint8_t stack_size;  // this is the current stack top + 1 (so that '0' means nothing on the stack)
    uint8_t fn_index;

    double min;
    double max;

    enum calculator_mode mode;
} calculator_state_t;

void rpn_calculator_alt_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void rpn_calculator_alt_face_activate(movement_settings_t *settings, void *context);
bool rpn_calculator_alt_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void rpn_calculator_alt_face_resign(movement_settings_t *settings, void *context);

#define rpn_calculator_alt_face ((const watch_face_t){ \
    rpn_calculator_alt_face_setup, \
    rpn_calculator_alt_face_activate, \
    rpn_calculator_alt_face_loop, \
    rpn_calculator_alt_face_resign, \
    NULL, \
    NULL, \
})

#endif // CALCULATOR_FACE_H_

