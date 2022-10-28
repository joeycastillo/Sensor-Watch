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

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calculator_face.h"

void calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(calculator_state_t));
        memset(*context_ptr, 0, sizeof(calculator_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

static void calculator_face_display_number(double num) {
    char buf[9] = {0};
    bool negative = num < 0;
    int max_digits = negative ? 5 : 6;

    printf("%f\n", num);
    if (negative) {
        num = -num;
    }

    // Can we reasonably represent this number without a decimal point?
    if (num == 0 || (num >= 0.5 && fabs(num - (int)num) < 0.0001)) {
        if (floor(log10(num)) + 1 <= max_digits) {
            if (negative) {
                sprintf(buf, "  -%-5d", (int)round(num));
            } else {
                sprintf(buf, "  %-6d", (int)round(num));
            }
            watch_clear_colon();
            watch_display_string(buf, 2);
            return;
        }
    }

    // Is this a floating point number where scientific
    // notation won't get us much? (i.e. between 0.1 and 1)
    if (num < 1 && num >= 0.0999) {
        // Display as boring floating point number... (e.g. 0.25)
        int digits = (int)round(num * 10000);
        sprintf(buf, "   0%04d", digits);
        if (negative) {
            buf[2 ] = '-';
        }
        watch_set_colon();
        watch_display_string(buf, 2);
        return;
    }

    // Fall back to scientific notation

    // Calculate exponent
    int exponent = 0;
    while (num < 1) {
        num *= 10;
        --exponent;
    }

    while (num >= 10) {
        num /= 10;
        ++exponent;
    }

    if (exponent < -9) {
        sprintf(buf, "  small ");
        watch_clear_colon();
        watch_display_string(buf, 2);
        return;
    }

    if (exponent > 39) {
        sprintf(buf, "   big  ");
        watch_clear_colon();
        watch_display_string(buf, 2);
        return;
    }

    sprintf(buf, "%2d%c%05d", exponent, negative ? '-' : ' ', (int)round(num * 10000));
    watch_set_colon();
    watch_display_string(buf, 2);
}

#define S(x) (state->x)
#define C S(stack[state->stack_index])
#define PUSH(x) (state->stack[++state->stack_index] = x)
#define POP() (state->stack[state->stack_index--])

void calculator_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    calculator_state_t *state = (calculator_state_t *)context;
    state->min = state->max = NAN;
}

static void fn_number(calculator_state_t *state) {
    PUSH(8);
    S(min) = S(max) = NAN;
    S(mode) = NUMBER;
}

static void fn_add(calculator_state_t *state) {
    PUSH(POP() + POP());
}

static void fn_sub(calculator_state_t *state) {
    float a = POP();
    float b = POP();
    PUSH(b - a);
}

static void fn_mul(calculator_state_t *state) {
    PUSH(POP() * POP());
}

static void fn_div(calculator_state_t *state) {
    float a = POP();
    float b = POP();
    PUSH(b / a);
}

struct {
    char name[2];
    void (*func)(calculator_state_t *);
} functions[] = {
    {{'n', 'o'}, fn_number},
    {{'+', ' '}, fn_add},
    {{'-', ' '}, fn_sub},
    {{'*', ' '}, fn_mul},
    {{'/', ' '}, fn_div},
};

#define FUNCTIONS_LEN (sizeof(functions) / sizeof(functions[0]))

static void show_fn(calculator_state_t *state) {
    char *name = functions[S(fn_index)].name;
    char buf[3] = {name[0], name[1], '\0'};
    watch_display_string(buf, 0);
}


bool calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    calculator_state_t *state = (calculator_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            calculator_face_display_number(C);
            show_fn(state);
            break;
        case EVENT_TICK:
            // Blink?
            break;
        case EVENT_MODE_BUTTON_UP:
            if (S(mode) == NUMBER) {
                S(max) = C;
                if (isnan(S(min))) {
                    if (C > 0) {
                        C = 0;
                    } else if (C == 0) {
                        C = -8;
                    } else {
                        C *= 10;
                    }
                } else {
                    C = (S(max) + S(min)) / 2;
                    if (fabs(S(max) - S(min)) > 1.5) {
                        C = round(C);
                    }
                }
                calculator_face_display_number(C);
            } else {
                movement_move_to_next_face();
                return false;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (S(mode) == NUMBER) {
                S(mode) = OPERATION;
            } else {
                functions[S(fn_index)].func(state);
                calculator_face_display_number(C);
            }

            S(fn_index) = 0;
            show_fn(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
            if (S(mode) == NUMBER) {
                S(min) = C;
                if (isnan(S(max))) {
                    if (C < 0) {
                        C = 0;
                    } else if (C == 0) {
                        C = 8;
                    } else {
                        C *= 10;
                    }
                } else {
                    C = (S(max) + S(min)) / 2;
                    if (fabs(S(max) - S(min)) > 1.5) {
                        C = round(C);
                    }
                }
                calculator_face_display_number(C);
            } else {
                S(fn_index) = (S(fn_index) + 1) % FUNCTIONS_LEN;
                show_fn(state);
            }
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void calculator_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

