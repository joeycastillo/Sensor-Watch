/*
 * MIT License
 *
 * Copyright (c) 2022 Niclas Hoyer
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

#ifndef RPN_CALCULATOR_FACE_H_
#define RPN_CALCULATOR_FACE_H_

/*
 * RPN CALCULATOR face
 *
 * A calculator face using reverse polish notation (RPN).
 *
 * For usage instructions, please refer to the wiki:
 * https://www.sensorwatch.net/docs/watchfaces/complication/#rpn-calculator
 */

#include "movement.h"

#define RPN_CALCULATOR_STACK_SIZE 4
#define RPN_CALCULATOR_MAX_OPS 7;

typedef enum {
    rpn_calculator_op_add,
    rpn_calculator_op_sub,
    rpn_calculator_op_mul,
    rpn_calculator_op_div,
    rpn_calculator_op_pow,
    rpn_calculator_op_sqrt,
    rpn_calculator_op_pi
} rpn_calculator_op_t;

typedef enum {
    rpn_calculator_waiting,
    rpn_calculator_op,
    rpn_calculator_number,
    rpn_calculator_err,
} rpn_calculator_mode_t;

typedef struct {
    rpn_calculator_mode_t mode;
    rpn_calculator_op_t op;
    float stack[RPN_CALCULATOR_STACK_SIZE];
    int8_t top;
    uint8_t selection;
} rpn_calculator_state_t;

void rpn_calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void rpn_calculator_face_activate(movement_settings_t *settings, void *context);
bool rpn_calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void rpn_calculator_face_resign(movement_settings_t *settings, void *context);

#define rpn_calculator_face ((const watch_face_t){ \
    rpn_calculator_face_setup, \
    rpn_calculator_face_activate, \
    rpn_calculator_face_loop, \
    rpn_calculator_face_resign, \
    NULL, \
})

#endif // RPN_CALCULATOR_FACE_H_

