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

void simple_calculator_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    simple_calculator_state_t *state = (simple_calculator_state_t *)context;
    state->placeholder = PLACEHOLDER_ONES;
    movement_request_tick_frequency(4);
}

static void increment_placeholder(calculator_number_t *number, calculator_placeholder_t placeholder) {
    switch (placeholder) {
        case PLACEHOLDER_HUNDREDTHS:
            number->hundredths = (number->hundredths + 1) % 10;
            break;
        case PLACEHOLDER_TENTHS:
            number->tenths = (number->tenths + 1) % 10;
            break;
        case PLACEHOLDER_ONES:
            number->ones = (number->ones + 1) % 10;
            break;
        case PLACEHOLDER_TENS:
            number->tens = (number->tens + 1) % 10;
            break;
        case PLACEHOLDER_HUNDREDS:
            number->hundreds = (number->hundreds + 1) % 10;
            break;
        case PLACEHOLDER_THOUSANDS:
            number->thousands = (number->thousands + 1) % 10;
            break;
        default:
            break;
    }
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
    return result;
}

static char* update_display_number(calculator_number_t *number, char *display_string) {
    sprintf(display_string, "%d%d%d%d%d%d",
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
        case 0:
            watch_display_string("   Add", 4);
            break;
        case 1:
            watch_display_string("   sub", 4);
            break;
        case 2:
            watch_display_string("  n&ul", 4);
            break;
        case 3:
            watch_display_string("   div", 4);
            break;
        case 4:
            watch_display_string("  root", 4);
            break;
        case 5:
            watch_display_string("   pow", 4);
            break;
    }
}

static void cycle_operation(simple_calculator_state_t *state) {
    state->operation = (state->operation + 1) % 6; // Assuming there are 6 operations
    printf("Current operation: %d\n", state->operation); // For debugging
}


static calculator_number_t convert_to_string(float number) {
    calculator_number_t result;
    int int_part = (int)number;
    float decimal_part_float = ((number - int_part) * 100); // two decimal places
    printf("decimal_part_float = %f\n", decimal_part_float); //For debugging
    int decimal_part = round(decimal_part_float);
    printf("decimal_part = %d\n", decimal_part); //For debugging

    result.thousands = int_part / 1000 % 10;
    result.hundreds = int_part / 100 % 10;
    result.tens = int_part / 10 % 10;
    result.ones = int_part % 10;

    result.tenths = decimal_part / 10 % 10;
    result.hundredths = decimal_part % 10;

    return result;
}

static calculator_number_t reset_to_zero(calculator_number_t *number) {
    number->hundredths = 0;
    number->tenths = 0;
    number->ones = 0;
    number->tens = 0;
    number->hundreds = 0;
    number->thousands = 0;

    return *number;
}

static void set_number(calculator_number_t *number, calculator_placeholder_t placeholder, char *display_string, char *temp_display_string, movement_event_t event) {
    int display_index;
    // Update display string with current number
    update_display_number(number, display_string);
    
    // Copy the updated display string to a temporary buffer
    strcpy(temp_display_string, display_string);
    
    // Determine the display index based on the placeholder
    display_index = 5 - placeholder;
    
    // Blink selected placeholder
    // Check if `event.subsecond` is even
    if (event.subsecond % 2 == 0) {
        // Replace the character at the index corresponding to the current placeholder with a space
        temp_display_string[display_index] = ' ';
    }
    
    // Display the (possibly modified) string
    watch_display_string(temp_display_string, 4);
} 

static void view_results(simple_calculator_state_t *state, char *display_string) {
    float first_num_float, second_num_float, result_float; // For arithmetic operations
    // Convert the numbers to float
    first_num_float = convert_to_float(state->first_num);
    printf("first_num_float = %f\n", first_num_float); // For debugging // For debugging
    second_num_float = convert_to_float(state->second_num);
    printf("second_num_float = %f\n", second_num_float); // For debugging
    
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
                result_float = 0; // Handle division by zero
            }
            break;
        case OP_ROOT:
            result_float = sqrtf(first_num_float);
            break;
        case OP_POWER:
            result_float = powf(first_num_float, second_num_float); // Power operation
            break;
    }
    
    result_float = roundf(result_float * 100.0f) / 100.0f; // Might not be needed
    printf("result as float = %f\n", result_float); // For debugging
    
    // Convert the float result to a string
    state->result = convert_to_string(result_float);
    
    // Update the display with the result
    update_display_number(&state->result, display_string);
    watch_display_string(display_string, 4);
}

bool simple_calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    simple_calculator_state_t *state = (simple_calculator_state_t *)context;
    //float first_num_float, second_num_float, result_float; // For arithmetic operations
    char display_string[7];
    char temp_display_string[7];  // Temporary buffer for blinking effect

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            break;

        case EVENT_TICK: 
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    set_number(&state->first_num, 
                            state->placeholder,
                            display_string, 
                            temp_display_string, 
                            event);
                    break;                

                case MODE_CHOOSING:
                    set_operation(state);
                    break;

                case MODE_ENTERING_SECOND_NUM:
                    set_number(&state->second_num, 
                            state->placeholder,
                            display_string, 
                            temp_display_string, 
                            event);
                    break;

                case MODE_VIEW_RESULTS:
                    view_results(state, display_string);
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
                    state->placeholder = (state->placeholder + 1) % 6; // Loop back to the start after PLACEHOLDER_THOUSANDS
                    break;
                case MODE_CHOOSING:
                    cycle_operation(state);
                    break;
                case MODE_VIEW_RESULTS:
                    break;
            }
            break;

        case EVENT_LIGHT_LONG_PRESS:
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    // toggle negative on state->first_num
                    break;
                case MODE_ENTERING_SECOND_NUM:
                    // toggle negative on state->second_num
                    break;
            }
            break;

        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case MODE_ENTERING_FIRST_NUM:
                    // Increment the digit in the current placeholder
                    increment_placeholder(&state->first_num, state->placeholder);
                    update_display_number(&state->first_num, display_string);
                    break;
                case MODE_CHOOSING:
                    // Confirm and select the current operation
                    printf("Selected operation: %d\n", state->operation); // For debugging
                    state->mode = MODE_ENTERING_SECOND_NUM;                
                    break;
                case MODE_ENTERING_SECOND_NUM:
                    // Increment the digit in the current placeholder
                    increment_placeholder(&state->second_num, state->placeholder);
                    update_display_number(&state->second_num, display_string);
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
            }
            break;

        case EVENT_MODE_BUTTON_DOWN:
            break;

        case EVENT_MODE_BUTTON_UP:
            state->placeholder = PLACEHOLDER_ONES;
            state->mode = (state->mode + 1) % 4;
            if (state->mode == MODE_ENTERING_FIRST_NUM) {
                state->first_num = state->result;
                reset_to_zero(&state->second_num);
            }
            printf("Current mode: %d\n", state->mode); // For debugging
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

