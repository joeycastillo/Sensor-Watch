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

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "simple_calculator_face.h"

void simple_calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(simple_calculator_state_t));
        memset(*context_ptr, 0, sizeof(simple_calculator_state_t));
    }
}

static void reset_to_zero(calculator_number_t *number) {
    number->negative = false;
    number->hundredths = 0;
    number->tenths = 0;
    number->ones = 0;
    number->tens = 0;
    number->hundreds = 0;
    number->thousands = 0;
}

void simple_calculator_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    simple_calculator_state_t *state = (simple_calculator_state_t *)context;
    state->placeholder = PLACEHOLDER_ONES;
    state->mode = MODE_ENTERING_FIRST_NUM;
    reset_to_zero(&state->second_num);
    reset_to_zero(&state->result);
    movement_request_tick_frequency(4);
}

static void increment_placeholder(calculator_number_t *number, calculator_placeholder_t placeholder) {
    uint8_t *digits[] = {
        &number->hundredths,
        &number->tenths,
        &number->ones,
        &number->tens,
        &number->hundreds,
        &number->thousands
    };
    *digits[placeholder] = (*digits[placeholder] + 1) % 10;
}

static float convert_to_float(calculator_number_t number) {
    float result = 0.0;

    // Add the whole number portion
    result += number.thousands * 1000.0f;
    result += number.hundreds * 100.0f;
    result += number.tens * 10.0f;
    result += number.ones * 1.0f;

    // Add the fractional portion
    result += number.tenths * 0.1f;
    result += number.hundredths * 0.01f;

    // Round to nearest hundredth
    result = roundf(result * 100) / 100;
    
    // Handle negative numbers
    if (number.negative) result = -result;
    //printf("convert_to_float results = %f\n", result); // For debugging

    return result;
}

static char* update_display_number(calculator_number_t *number, char *display_string, uint8_t which_num) {
    char sign = ' ';
    if (number->negative) sign = '-';

    sprintf(display_string, "CA%d%c%d%d%d%d%d%d",
            which_num,
            sign,
            number->thousands,
            number->hundreds,
            number->tens,
            number->ones,
            number->tenths,
            number->hundredths);

    return display_string;
}

static void set_operation(simple_calculator_state_t *state) {
    switch (state->operation) {
        case OP_ADD:
            watch_display_string("       Add", 0);
            break;
        case OP_SUB:
            watch_display_string("       sub", 0);
            break;
        case OP_MULT:
            watch_display_string("      n&ul", 0);
            break;
        case OP_DIV:
            watch_display_string("       div", 0);
            break;
        case OP_ROOT:
            watch_display_string("      root", 0);
            break;
        case OP_POWER:
            watch_display_string("       pow", 0);
            break;
    }
}

static void cycle_operation(simple_calculator_state_t *state) {
    state->operation = (state->operation + 1) % OPERATIONS_COUNT; // Assuming there are 6 operations
}


static calculator_number_t convert_to_string(float number) {
    calculator_number_t result;

    // Handle negative numbers
    if (number < 0) {
        number = -number;
        result.negative = true;
    } else result.negative = false;

    // Get each digit from each placeholder
    int int_part = (int)number;

    float decimal_part_float = ((number - int_part) * 100); // two decimal places
    //printf("decimal_part_float = %f\n", decimal_part_float); //For debugging

    int decimal_part = round(decimal_part_float);
    //printf("decimal_part = %d\n", decimal_part); //For debugging

    result.thousands = int_part / 1000 % 10;
    result.hundreds = int_part / 100 % 10;
    result.tens = int_part / 10 % 10;
    result.ones = int_part % 10;

    result.tenths = decimal_part / 10 % 10;
    result.hundredths = decimal_part % 10;

    return result;
}

// This is the main function for setting the first_num and second_num
// WISH: there must be a way to pass less to this function?
static void set_number(calculator_number_t *number, calculator_placeholder_t placeholder, char *display_string, char *temp_display_string, movement_event_t event, uint8_t which_num) {

    // Create the display index
    uint8_t display_index;

    // Update display string with current number and copy into temp string
    update_display_number(number, display_string, which_num);
    strcpy(temp_display_string, display_string);
    
    // Determine the display index based on the placeholder
    display_index = 9 - placeholder;
    
    // Blink selected placeholder
    // Check if `event.subsecond` is even
    if (event.subsecond % 2 == 0) {
        // Replace the character at the index corresponding to the current placeholder with a space
        temp_display_string[display_index] = ' ';
    }
    
    // Display the (possibly modified) string
    watch_display_string(temp_display_string, 0);
} 

static void view_results(simple_calculator_state_t *state, char *display_string) {

    // Initialize float variables to do the math
    float first_num_float, second_num_float, result_float = 0.0f;

    // Convert the passed numbers to floats
    first_num_float = convert_to_float(state->first_num);
    second_num_float = convert_to_float(state->second_num);
    
    // Perform the calculation based on the selected operation
    switch (state->operation) {
        case OP_ADD:
            result_float = first_num_float + second_num_float;
            break;
        case OP_SUB:
            result_float = first_num_float - second_num_float;
            break;
        case OP_MULT:
            result_float = first_num_float * second_num_float;
            break;
        case OP_DIV:
            if (second_num_float != 0) {
                result_float = first_num_float / second_num_float;
            } else {
                state->mode = MODE_ERROR;
                return;
            }
            break;
        case OP_ROOT:
            if (first_num_float >= 0) {
                result_float = sqrtf(first_num_float);
            } else {
                state->mode = MODE_ERROR;
                return;
            }
            break;
        case OP_POWER:
            result_float = powf(first_num_float, second_num_float);
            break;
        default:
            result_float = 0.0f;
            break;
    }

    // Be sure the result can fit on the watch display, else error
    if (result_float > 9999.99 || result_float < -9999.99) {
        state->mode = MODE_ERROR;
        return;
    }
    
    result_float = roundf(result_float * 100.0f) / 100.0f; // Might not be needed

    //printf("result as float = %f\n", result_float); // For debugging
    
    // Convert the float result to a string
    // This isn't strictly necessary, but allows easily reusing the result as
    // the next calculation's first_num
    state->result = convert_to_string(result_float);
    
    // Update the display with the result
    update_display_number(&state->result, display_string, 3);

    //printf("display_string = %s\n", display_string); // For debugging

    watch_display_string(display_string, 0);
}

// Used both when returning from errors and when long pressing MODE
static void reset_all(simple_calculator_state_t *state) {
    reset_to_zero(&state->first_num);
    reset_to_zero(&state->second_num);
    state->mode = MODE_ENTERING_FIRST_NUM;
    state->operation = OP_ADD;
    state->placeholder = PLACEHOLDER_ONES;
}

bool simple_calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    simple_calculator_state_t *state = (simple_calculator_state_t *)context;
    char display_string[10];
    char temp_display_string[10];  // Temporary buffer for blinking effect

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK: 
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    // See the WISH for this function above
                    set_number(&state->first_num, 
                            state->placeholder,
                            display_string, 
                            temp_display_string, 
                            event,
                            1);
                    break;                

                case MODE_CHOOSING:
                    set_operation(state);
                    break;

                case MODE_ENTERING_SECOND_NUM:
                    // If doing a square root calculation, skip to results
                    if (state->operation == OP_ROOT) {
                        state->mode = MODE_VIEW_RESULTS;
                    } else {
                        // See the WISH for this function above
                        set_number(&state->second_num, 
                            state->placeholder,
                            display_string, 
                            temp_display_string, 
                            event,
                            2);
                    }
                    break;

                case MODE_VIEW_RESULTS:
                    view_results(state, display_string);
                    break;

                case MODE_ERROR:
                    watch_display_string("CA  Error ", 0);
                    break;
            }
            break;

        case EVENT_LIGHT_BUTTON_DOWN:
            break;

        case EVENT_LIGHT_BUTTON_UP:
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                case MODE_ENTERING_SECOND_NUM:
                    // Move to the next placeholder when the light button is pressed
                    state->placeholder = (state->placeholder + 1) % MAX_PLACEHOLDERS; // Loop back to the start after PLACEHOLDER_THOUSANDS
                    break;
                case MODE_CHOOSING:
                    cycle_operation(state);
                    break;
                case MODE_ERROR:
                    reset_all(state);
                    break;
                case MODE_VIEW_RESULTS:
                    break;
            }
            break;

        case EVENT_LIGHT_LONG_PRESS:
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    // toggle negative on state->first_num
                    state->first_num.negative = !state->first_num.negative;
                    break;
                case MODE_ENTERING_SECOND_NUM:
                    // toggle negative on state->second_num
                    state->second_num.negative = !state->second_num.negative;
                    break;
                case MODE_ERROR:
                    reset_all(state);
                    break;
                case MODE_CHOOSING:
                case MODE_VIEW_RESULTS:
                    break;
            }
            break;

        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    // Increment the digit in the current placeholder
                    increment_placeholder(&state->first_num, state->placeholder);
                    update_display_number(&state->first_num, display_string, 1);

                    //printf("display_string = %s\n", display_string); // For debugging

                    break;
                case MODE_CHOOSING:
                    // Confirm and select the current operation
                    state->mode = MODE_ENTERING_SECOND_NUM;                
                    break;
                case MODE_ENTERING_SECOND_NUM:
                    // Increment the digit in the current placeholder
                    increment_placeholder(&state->second_num, state->placeholder);
                    update_display_number(&state->second_num, display_string, 2);

                    //printf("display_string = %s\n", display_string); // For debugging

                    break;
                case MODE_ERROR:
                    reset_all(state);
                    break;
                case MODE_VIEW_RESULTS:
                    break;
            }
            break;

        case EVENT_ALARM_LONG_PRESS:
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    reset_to_zero(&state->first_num);
                    break;
                case MODE_ENTERING_SECOND_NUM:
                    reset_to_zero(&state->second_num);
                    break;
                case MODE_ERROR:
                    reset_all(state);
                    break;
                case MODE_CHOOSING:
                case MODE_VIEW_RESULTS:
                    break;
            }
            break;

        case EVENT_MODE_BUTTON_DOWN:
            break;

        case EVENT_MODE_BUTTON_UP:
            if (state->mode == MODE_ERROR) {
                reset_all(state);
            } else if (state->mode == MODE_ENTERING_FIRST_NUM &&
                    state->first_num.hundredths == 0 &&
                    state->first_num.tenths == 0 &&
                    state->first_num.ones== 0 &&
                    state->first_num.tens == 0 &&
                    state->first_num.hundreds == 0 &&
                    state->first_num.thousands == 0) { 
                movement_move_to_next_face();
            } else {
                // Reset the placeholder and proceed to the next MODE
                state->placeholder = PLACEHOLDER_ONES;
                state->mode = (state->mode + 1) % 4;
                // When looping back to MODE_ENTERING_FIRST_NUM, reuse the
                // previous calculation's results as the next calculation's
                // first_num; also reset other numbers
                if (state->mode == MODE_ENTERING_FIRST_NUM) {
                    state->first_num = state->result;
                    reset_to_zero(&state->second_num);
                    reset_to_zero(&state->result);
                }
            }
            break;

        case EVENT_MODE_LONG_PRESS:
            // Move to next face if first number is 0
            if (state->first_num.hundredths == 0 &&
                    state->first_num.tenths == 0 &&
                    state->first_num.ones== 0 &&
                    state->first_num.tens == 0 &&
                    state->first_num.hundreds == 0 &&
                    state->first_num.thousands == 0) { 
                movement_move_to_face(0);
            // otherwise, start over
            } else {
                reset_all(state);
            }
            break;

        case EVENT_TIMEOUT:
            movement_request_tick_frequency(1);
            movement_move_to_face(0);
            break;

        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void simple_calculator_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(1);
}

