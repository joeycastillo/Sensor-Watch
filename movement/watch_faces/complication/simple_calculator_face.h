/*
 * MIT License
 *
 * Copyright (c) 2024 Patrick McGuire
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

#ifndef SIMPLE_CALCULATOR_FACE_H_
#define SIMPLE_CALCULATOR_FACE_H_

#include "movement.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

#define OPERATIONS_COUNT 6
#define MAX_PLACEHOLDERS 6

typedef struct {
    uint8_t hundredths;
    uint8_t tenths;
    uint8_t ones;
    uint8_t tens;
    uint8_t hundreds;
    uint8_t thousands;
} calculator_number_t;

typedef enum {
    PLACEHOLDER_HUNDREDTHS,
    PLACEHOLDER_TENTHS,
    PLACEHOLDER_ONES,
    PLACEHOLDER_TENS,
    PLACEHOLDER_HUNDREDS,
    PLACEHOLDER_THOUSANDS
} calculator_placeholder_t;

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MULT,
    OP_DIV,
    OP_ROOT,
    OP_POWER,
} calculator_operation_t;

typedef enum {
    MODE_ENTERING_FIRST_NUM,
    MODE_CHOOSING,
    MODE_ENTERING_SECOND_NUM,
    MODE_VIEW_RESULTS
} calculator_mode_t;

typedef struct {
    calculator_number_t first_num;
    calculator_number_t second_num;
    calculator_number_t result;
    calculator_operation_t operation;
    calculator_mode_t mode;
    calculator_placeholder_t placeholder;
} simple_calculator_state_t;

void simple_calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void simple_calculator_face_activate(movement_settings_t *settings, void *context);
bool simple_calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void simple_calculator_face_resign(movement_settings_t *settings, void *context);

#define simple_calculator_face ((const watch_face_t){ \
    simple_calculator_face_setup, \
    simple_calculator_face_activate, \
    simple_calculator_face_loop, \
    simple_calculator_face_resign, \
    NULL, \
})

#endif // SIMPLE_CALCULATOR_FACE_H_

