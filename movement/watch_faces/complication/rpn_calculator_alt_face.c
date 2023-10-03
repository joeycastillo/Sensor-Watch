/*
 * MIT License
 *
 * Copyright (c) 2022 James Haggerty
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

#include "rpn_calculator_alt_face.h"

static void show_fn(calculator_state_t *state, uint8_t subsecond);

void rpn_calculator_alt_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(calculator_state_t));
        memset(*context_ptr, 0, sizeof(calculator_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

static void show_number(double num) {
    char buf[9] = {0};
    bool negative = num < 0;
    int max_digits = negative ? 5 : 6;

    // Add back in for debugging...
    // printf("%f\n", num);

    if (isnan(num)) {
        watch_clear_colon();
        watch_display_string("  nan   ", 2);
        return;
    }

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

#define C (s->stack[s->stack_size - 1])
#define PUSH(x) (s->stack[++s->stack_size - 1] = x)
#define POP() (s->stack[s->stack_size-- - 1])

void rpn_calculator_alt_face_activate(movement_settings_t *settings, void *context) {
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

// Binary-ish search to find the right number. direction is +1 if it should be bigger, -1 if it should be smaller.
static void adjust_number(calculator_state_t *s, int direction) {
    if (direction > 0) {
        s->min = C;
    } else {
        s->max = C;
    }

    // If the direction we want to go has no bound (i.e. isnan),
    // then first get the sign right (moving to 0, then +-10), and
    // after than go up by *10.
    if (isnan(direction > 0 ? s->max : s->min)) {
        if (direction * C < 0) {
            C = 0;
        } else if (C == 0) {
            C = direction * 10;
        } else {
            C *= 10;
        }
    } else {
        // We have a higher and lower bound. Split them.
        C = (s->max + s->min) / 2;
        // Subtract 0.1 so we don't apply most significant rounding to things that are _exactly_ 1/10/100 apart.
        double mag = log10(fabs(s->max - s->min)) - 0.1;
        if (mag > 0.0) {
            // i.e. the different is >= 2, which means we want to round aggressively
            // to not show people complicated looking numbers.
            // e.g. this takes a number like 3.2 to 3, or a number like 464 to 500
            // (depending on how fine-grained 'mag' tells us to be).
            float div = pow(10, floor(mag));
            int sign = C < 0 ? -1 : 1;
            C = sign * floor(fabs(C) / div) * div;
        }
    }
}

static void fn_number(calculator_state_t *s) {
    PUSH(10);
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
    PUSH(b - a);
}

static void fn_mul(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(a * b);
}

static void fn_div(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(b / a);
}

static void fn_pow(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(pow(b, a));
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

static void fn_pop(calculator_state_t *s) {
    --s->stack_size;
}

static void fn_swap(calculator_state_t *s) {
    double a = POP();
    double b = POP();
    PUSH(a);
    PUSH(b);
}

static void fn_duplicate(calculator_state_t *s) {
    double a = POP();
    PUSH(a);
    PUSH(a);
}

static void fn_clear(calculator_state_t *s) {
    s->stack_size = 0;
}

static void fn_size(calculator_state_t *s) {
    double a = s->stack_size;
    PUSH(a);
}

struct {
    char name[2];
    uint8_t input;
    uint8_t output;
    void (*func)(calculator_state_t *);
} functions[] = {
    {{'n', 'o'}, 0, 1, fn_number},
    {{'*', ' '}, 2, 1, fn_add},  // First position * actually looks like a '+'.
    {{'-', ' '}, 2, 1, fn_sub},
    {{'H', ' '}, 2, 1, fn_mul},  // For actual *, we throw in the middle vertical segment onto the H.
    {{'/', ' '}, 2, 1, fn_div},  // There's also some minor hackery on '/'.
    {{'P', 'o'}, 2, 1, fn_pow},
    {{'S', 'r'}, 1, 1, fn_sqrt},
    {{'L', 'n'}, 1, 1, fn_log},
    {{'L', 'o'}, 1, 1, fn_log10},
    {{'e', ' '}, 0, 1, fn_e},
    {{'P', 'i'}, 0, 1, fn_pi},
    {{'C', 'o'}, 1, 1, fn_cos},
    {{'S', 'i'}, 1, 1, fn_sin},
    {{'T', 'a'}, 1, 1, fn_tan},
    // Stack operations. Accessible via secondary_fn_index (i.e. alarm long press).
    {{'P', 'O'}, 1, 0, fn_pop},  // This ends up displaying the same as 'POW'. But at least it's in a different place.
    {{'S', 'W'}, 2, 2, fn_swap},
    {{'d', 'u'}, 1, 1, fn_duplicate},  // Uppercase 'D' is a bit too 'O' for me.
    {{'C', 'L'}, 1, 0, fn_clear},  // Operation lie - takes _everything_ off the stack, but a check of 1 is sufficient.
    {{'L', 'E'}, 1, 0, fn_size},
};

#define FUNCTIONS_LEN (sizeof(functions) / sizeof(functions[0]))
#define SECONDARY_FN_INDEX (FUNCTIONS_LEN - 4)

// Show the function name (using day display)
static void show_fn(calculator_state_t *s, uint8_t subsecond) {
    if (subsecond % 2) {
        // blink
        watch_display_string("  ", 0);
        return;
    }

    char *name = functions[s->fn_index].name;
    char buf[3] = {name[0], name[1], '\0'};
    watch_display_string(buf, 0);
    // The first position has a bunch of segments, and I have minor
    // disagreements with the character set choices in watch_display_string,
    // so we tweak a little here.
    switch (buf[0]) {
        case 'H':
            // Use the middle segment lines to make our 'H' a '*'-ish thing.
            watch_set_pixel(1, 14);
            break;
        case '/':
            // Add a middle bar to division.
            watch_set_pixel(1, 15);
            break;
        default:
            break;
    }
}

// Show the top of the stack (using everything except day display).
static void show_stack_top(calculator_state_t *s) {
    if (s->stack_size > 0) {
        show_number(C);
    } else {
        watch_display_string("  ------", 2);
        watch_clear_colon();
    }
}

bool rpn_calculator_alt_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    calculator_state_t *s = (calculator_state_t *)context;
    (void) settings;

    int proposed_stack_size;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            change_mode(s, CALC_OPERATION);
            show_stack_top(s);
            break;
        case EVENT_TICK:
            if (s->mode == CALC_OPERATION) {
                show_fn(s, event.subsecond);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            if (s->mode == CALC_NUMBER) {
                adjust_number(s, -1);
                show_stack_top(s);
            } else {
                movement_move_to_next_face();
                return false;
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            proposed_stack_size = s->stack_size - functions[s->fn_index].input;

            if (s->mode == CALC_NUMBER) {
                change_mode(s, CALC_OPERATION);
            } else if (proposed_stack_size < 0 || proposed_stack_size + functions[s->fn_index].output > CALC_MAX_STACK_SIZE) {
                movement_play_signal();
                break;
            } else {
                functions[s->fn_index].func(s);
                show_stack_top(s);
                s->fn_index = 0;
                show_fn(s, 0);
            }

            break;
        case EVENT_ALARM_BUTTON_UP:
            if (s->mode == CALC_NUMBER) {
                adjust_number(s, 1);
                show_stack_top(s);
            } else {
                s->fn_index = (s->fn_index + 1) % FUNCTIONS_LEN;
                show_fn(s, 0);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (s->mode == CALC_OPERATION) {
                if (s->fn_index == 0) {
                    s->fn_index = SECONDARY_FN_INDEX;
                } else {
                    s->fn_index = 0;
                }
                show_fn(s, 0);
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void rpn_calculator_alt_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

