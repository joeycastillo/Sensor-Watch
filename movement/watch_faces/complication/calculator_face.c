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

static void show_fn(calculator_state_t *state, uint8_t subsecond);

void calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

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

#define C (s->stack[s->stack_index])
#define PUSH(x) (s->stack[++s->stack_index] = x)
#define POP() (s->stack[s->stack_index--])

void calculator_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    calculator_state_t *s = (calculator_state_t *)context;
    s->min = s->max = NAN;
}

static void change_mode(calculator_state_t *s, enum calculator_mode mode) {
    s->mode = mode;
    s->fn_index = 0;
    show_fn(s, 0);
    // Faster tick in operation mode so we can blink.
    movement_request_tick_frequency(mode == CALC_OPERATION ? 4 : 1);
}

// Binary search to find the right number. direction is +1 if it should be bigger, -1 if it should be smaller.
static void adjust_number(calculator_state_t *s, int direction) {
    if (direction > 0) {
        s->min = C;
    } else {
        s->max = C;
    }

    // If the direction we want to go has no bound (i.e. isnan),
    // then first get the sign right (moving to 0, then +-8), and
    // after than go up by *10.
    if (isnan(direction > 0 ? s->max : s->min)) {
        if (direction * C < 0) {
            C = 0;
        } else if (C == 0) {
            C = direction * 8;
        } else {
            C *= 10;
        }
    } else {
        // We have a higher and lower bound. Split them.
        C = (s->max + s->min) / 2;
        if (fabs(s->max - s->min) > 1.5) {
            // Only start going non-integer when we've eliminated all integer possibles.
            C = round(C);
        }
    }
}

static void fn_number(calculator_state_t *s) {
    PUSH(8);
    s->min = s->max = NAN;
    change_mode(s, CALC_NUMBER);
}

static void fn_add(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(a + b);
}

static void fn_sub(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(a - b);
}

static void fn_mul(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(a * b);
}

static void fn_div(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(a / b);
}

static void fn_pow(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(pow(a, b));
}

static void fn_sqrt(calculator_state_t *s) {
    double x = POP();
    PUSH(sqrt(x));
}

static void fn_log(calculator_state_t *s) {
    double x = POP();
    PUSH(log(x));
}

static void fn_log10(calculator_state_t *s) {
    double x = POP();
    PUSH(log10(x));
}

static void fn_e(calculator_state_t *s) {
    PUSH(M_E);
}

static void fn_sin(calculator_state_t *s) {
    double x = POP();
    PUSH(sin(x));
}

static void fn_cos(calculator_state_t *s) {
    double x = POP();
    PUSH(cos(x));
}

static void fn_tan(calculator_state_t *s) {
    double x = POP();
    PUSH(tan(x));
}

static void fn_pi(calculator_state_t *s) {
    PUSH(M_PI);
}

struct {
    char name[2];
    uint8_t input;
    uint8_t output;
    void (*func)(calculator_state_t *);
} functions[] = {
    {{'n', 'o'}, 0, 1, fn_number},
    {{'+', ' '}, 2, 1, fn_add},
    {{'-', ' '}, 2, 1, fn_sub},
    {{'*', ' '}, 2, 1, fn_mul},
    {{'/', ' '}, 2, 1, fn_div},
    {{'P', 'o'}, 2, 1, fn_pow},
    {{'S', 't'}, 1, 1, fn_sqrt},
    {{'L', 'n'}, 1, 1, fn_log},
    {{'L', 'o'}, 1, 1, fn_log10},
    {{'e', ' '}, 0, 1, fn_e},
    {{'P', 'i'}, 0, 1, fn_pi},
    {{'C', 'o'}, 1, 1, fn_cos},
    {{'S', 'i'}, 1, 1, fn_sin},
    {{'T', 'a'}, 1, 1, fn_tan},
};

#define FUNCTIONS_LEN (sizeof(functions) / sizeof(functions[0]))

static void show_fn(calculator_state_t *s, uint8_t subsecond) {
    if (subsecond % 2) {
        // blink
        watch_display_string("  ", 0);
    } else {
        char *name = functions[s->fn_index].name;
        char buf[3] = {name[0], name[1], '\0'};
        watch_display_string(buf, 0);
    }
}

bool calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    calculator_state_t *s = (calculator_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            if (C == 0 && s->stack_index == 0) {
                fn_number(s);
            } else {
                change_mode(s, CALC_OPERATION);
            }
            calculator_face_display_number(C);
            break;
        case EVENT_TICK:
            if (s->mode == CALC_OPERATION) {
                show_fn(s, event.subsecond);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            if (s->mode == CALC_NUMBER) {
                adjust_number(s, -1);
                calculator_face_display_number(C);
            } else {
                movement_move_to_next_face();
                return false;
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (s->mode == CALC_NUMBER) {
                change_mode(s, CALC_OPERATION);
            } else if (functions[s->fn_index].input <= s->stack_index && s->stack_index + functions[s->fn_index].output < CALC_STACK_SIZE) {
                functions[s->fn_index].func(s);
                calculator_face_display_number(C);
                s->fn_index = 0;
                show_fn(s, 0);
            } else {
                movement_play_signal();
                break;
            }

            break;
        case EVENT_ALARM_BUTTON_UP:
            if (s->mode == CALC_NUMBER) {
                adjust_number(s, 1);
                calculator_face_display_number(C);
            } else {
                s->fn_index = (s->fn_index + 1) % FUNCTIONS_LEN;
                show_fn(s, 0);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (s->mode == CALC_OPERATION) {
                s->fn_index = 0;
                show_fn(s, 0);
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
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

