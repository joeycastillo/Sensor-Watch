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

/* 
 * RPN Calculator alternate face.
 *
 * Operations appear in the 'day' section; ALARM changes between operations when
 * operation is flashing. LIGHT executes current operation.
 *
 * This is the alternate face because it has a non-traditional number entry system which
 * I call 'guess a number'. In number entry mode, the watch tries to guess which number you
 * want, and you respond with 'smaller' (left - MODE) or larger (right - ALARM). This means
 * that when you _are_ entering a number, MODE will no longer move between faces!
 *
 * Example of entering the number 27
 *  - select the NO operation (probably unnecessary, as this is the default),
 *    and execute it by hitting LIGHT.
 *  - you are now in number entry mode; you know this because nothing is flashing.
 *  - Watch displays 10; you hit ALARM to say you want a larger number.
 *  - Watch displays 100; you hit MODE to say you want a smaller number.
 *  - Continuing: 50 -> MODE -> 30 -> MODE -> 20 -> ALARM -> 27
 *  - Hit LIGHT to add the number to the stack (and now 'NO' is flashing
 *    again, indicating you're back in operation selection mode).
 *
 * One other thing to watch out for is how quickly it will switch into scientific notation
 * due to the limitations of the display when you have large numbers or non-integer values.
 * In this mode, the 'colon' serves at the decimal point, and the numbers in the top right
 * are the exponent.
 *
 * As with the main movement firmware, this has the concept of 'secondary' functions which
 * you can jump to by a long hold of ALARM on NO. These are functions to do with stack
 * manipulation (pop, swap, dupe, clear, size (le)). If you're _not_ on NO, a long
 * hold will take you back to it.
 *
 * See 'functions' in "rpn_calculator_alt_face.c" for names of all operations.
 */

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
})

#endif // CALCULATOR_FACE_H_

