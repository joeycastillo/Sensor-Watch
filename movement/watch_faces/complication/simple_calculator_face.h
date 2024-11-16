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
 * Simple Calculator
 *
 * How to use:
 *
 * Flow:
 * Enter first number -> Select operator -> Enter second number -> View Results
 * 
 * How to read the display:
 * - "CA" is displayed at the top to tell you that you're in the CAlculator
 * - The top-right digit (1, 2, or 3) lets you know whether you're entering the
 *   first number (1), entering the second number (2), or viewing the results (3).
 * - To the right of the top-right digit will show the number's sign. If the
 *   number is negative, a "-" will be displayed, otherwise it is empty.
 * - The 4 large digits to the left are whole numbers and the 2 smaller digits
 *   on the right are the tenths and hundredths decimal places.
 *
 * Entering the first number:
 * - Press ALARM to increment the selected (blinking) digit
 * - Press LIGHT to move to the next placeholder
 * - LONG PRESS the LIGHT button to toggle the number's sign to make it 
 *   negative
 * - LONG PRESS the ALARM button to reset the number to 0
 * - Press MODE to proceed to selecting the operator
 *
 * Selecting the operator:
 * - Press the LIGHT button to cycle through available operators. They are:
 *   + Add
 *   - Subtract
 *   * Multiply
 *   / Divide
 *   sqrtf() Square root
 *   powf() Power (exponent calculation)
 * - Press MODE or ALARM to proceed to entering the second number
 *
 * Entering the second number:
 * - Everything is the same as setting the first number except that pressing
 *   MODE here will proceed to viewing the results
 *
 * Viewing the results:
 * - Pressing MODE will start a new calculation with the result as the first
 *   number. (LONG PRESS ALARM to reset the value to 0)
 *
 * Errors:
 * - An error will be triggered if the result is not able to be displayed, that
 * is, if the value is greater than 9,999.99 or less than -9,999.99.
 * - An error will also be triggered if an impossible operation is selected,
 *   for instance trying to divide by 0 or get the square root of a negative
 *   number.
 * - Exit error mode and start over with any button press.
 *
 */

#define OPERATIONS_COUNT 6
#define MAX_PLACEHOLDERS 6

typedef struct {
    bool negative;
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
    MODE_VIEW_RESULTS,
    MODE_ERROR
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

