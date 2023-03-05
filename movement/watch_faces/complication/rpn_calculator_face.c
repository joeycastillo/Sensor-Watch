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

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rpn_calculator_face.h"

static void draw_number(char *buf, float num) {
    float f = fmodf(num, 1.0) * 100;
    sprintf(buf, "CA  %4d%02d", ((int)num) % 10000, (int) f);
}

static void draw_op(char *buf, rpn_calculator_op_t op) {
    switch (op) {
        case rpn_calculator_op_add:
            sprintf(buf, "CA     Add");
        break;
        case rpn_calculator_op_sub:
            sprintf(buf, "CA     sub");
        break;
        case rpn_calculator_op_mul:
            sprintf(buf, "CA    n&ul");
        break;
        case rpn_calculator_op_div:
            sprintf(buf, "CA     div");
        break;
        case rpn_calculator_op_pow:
            sprintf(buf, "CA     pow");
        break;
        case rpn_calculator_op_sqrt:
            sprintf(buf, "CA    sqrt");
        break;
        case rpn_calculator_op_pi:
            sprintf(buf, "CA      pi");
            break;
        default:
            break;
    }
}

static void printf_stack(rpn_calculator_state_t *state) {
    printf("Stack: [%f, %f, %f, %f], top: %d\n",
        state->stack[0],
        state->stack[1],
        state->stack[2],
        state->stack[3],
        state->top
    );
}

static void next_op(rpn_calculator_state_t *state) {
    state->op += 1;
    state->op = state->op % RPN_CALCULATOR_MAX_OPS;
}

// increase a digit of a floating point number
// FIXME: this converts the number to string and back, there might
// be better ways to do this
static float inc_digit(float num, uint8_t position) {
    char buf[8];
    if (position > 5) {
        return 0.0;
    }
    // inverse position (rtl)
    position = 5 - position;
    float f = fmodf(num, 1.0) * 100;
    sprintf(buf, "%04d%02d", ((int)num) % 10000, (int) f);
    uint8_t digit = buf[position] - '0';
    digit = (digit + 1) % 10;
    buf[position] = digit + '0';
    printf("buf: %s\n", buf);
    return strtof(buf, NULL) / 100.0;
}

static void stack_push(rpn_calculator_state_t *state, float f) {
    printf_stack(state);
    printf("push: %f\n", f);
    state->top++;
    if (state->top >= RPN_CALCULATOR_STACK_SIZE) {
        // FIXME: implement this using a circular buffer?
        for (int i=0; i<RPN_CALCULATOR_STACK_SIZE-1; i++) {
            state->stack[i] = state->stack[i+1];
        }
    }
    state->stack[state->top] = f;
}

static float stack_peek(rpn_calculator_state_t *state) {
    if (state->top > -1) {
        return state->stack[state->top];
    }
    return 0;
}

static float stack_pop(rpn_calculator_state_t *state) {
    printf_stack(state);
    float f = stack_peek(state);
    state->stack[state->top] = 0;
    printf("pop: %f\n", f);
    if (state->top > -1) {
        state->top--;
    } else {
        state->top = -1; // empty
    }
    return f;
}

static void run_op(rpn_calculator_state_t *state) {
    printf_stack(state);
    bool op_found = false;
    // ops without parameters
    switch (state->op)  {
        case rpn_calculator_op_pi:
            stack_push(state, M_PI);
            op_found = true;
            break;
        default:
            break;
    }
    if (op_found) {
        state->mode = rpn_calculator_waiting;
        return;
    }

    // ops with one parameter
    if (state->top < 0) {
        state->mode = rpn_calculator_err;
        return;
    }
    float right = stack_pop(state);
    printf("right: %f\n", right);
    switch (state->op)  {
        case rpn_calculator_op_sqrt:
            stack_push(state, sqrt(right));
            op_found = true;
            break;
        default:
            break;
    }
    if (op_found) {
        state->mode = rpn_calculator_waiting;
        return;
    }

    // ops with two parameters
    if (state->top < 0) {
        // no parameter left -> error
        state->mode = rpn_calculator_err;
        return;
    }
    float left = stack_pop(state);
    printf("left: %f\n", left);
    switch (state->op)  {
        case rpn_calculator_op_add:
            stack_push(state, left + right);
            op_found = true;
            break;
        case rpn_calculator_op_sub:
            stack_push(state, left - right);
            op_found = true;
            break;
        case rpn_calculator_op_mul:
            stack_push(state, left * right);
            op_found = true;
            break;
        case rpn_calculator_op_div:
            stack_push(state, left / right);
            op_found = true;
            break;
        case rpn_calculator_op_pow:
            stack_push(state, powf(left, right));
            op_found = true;
            break;
        default:
            break;
    }
    if (op_found) {
        state->mode = rpn_calculator_waiting;
        return;
    }
    state->mode = rpn_calculator_err;
}

static void draw(rpn_calculator_state_t *state, uint8_t subsecond) {
    char buf[16];
    switch (state->mode) {
        case rpn_calculator_err:
            sprintf(buf, "CA   err  ");
            break;
        case rpn_calculator_number:
            draw_number(buf, stack_peek(state));
            uint8_t i = 4 + (5 - state->selection);
            if (buf[i] == ' ') {
                buf[i] = '0';
            }
            if (subsecond % 2) {
                buf[i] = ' ';
            }
            break;
        case rpn_calculator_waiting:
            printf_stack(state);
            draw_number(buf, stack_peek(state));
            break;
        case rpn_calculator_op:
            draw_op(buf, state->op);
            break;
        default:
            break;
    }
    watch_display_string(buf, 0);
}

void rpn_calculator_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(rpn_calculator_state_t));
        memset(*context_ptr, 0, sizeof(rpn_calculator_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
        rpn_calculator_state_t *state = *context_ptr;
        state->top = -1;
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void rpn_calculator_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // Handle any tasks related to your watch face coming on screen.
}

bool rpn_calculator_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    rpn_calculator_state_t *state = (rpn_calculator_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            draw(state, event.subsecond);
            break;
        case EVENT_TICK:
            if (state->mode == rpn_calculator_number) {
                draw(state, event.subsecond);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            switch (state->mode) {
                case rpn_calculator_number:
                    state->mode = rpn_calculator_waiting;
                    draw(state, event.subsecond);
                    movement_request_tick_frequency(1);
                    break;
                default:
                    state->mode = rpn_calculator_waiting;
                    movement_request_tick_frequency(1);
                    movement_move_to_next_face();
                break;
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            switch (state->mode) {
                case rpn_calculator_waiting:
                    state->mode = rpn_calculator_op;
                    draw(state, event.subsecond);
                    break;
                case rpn_calculator_number:
                    state->selection = (state->selection + 1) % 6;
                    draw(state, event.subsecond);
                    break;
                case rpn_calculator_op:
                    next_op(state);
                    draw(state, event.subsecond);
                    break;
                default:
                    movement_illuminate_led();
                    break;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case rpn_calculator_waiting:
                    state->mode = rpn_calculator_number;
                    state->selection = 2;
                    stack_push(state, 0);
                    draw(state, event.subsecond);
                    movement_request_tick_frequency(4);
                    break;
                case rpn_calculator_number:
                    state->stack[state->top] = inc_digit(state->stack[state->top], state->selection);
                    printf_stack(state);
                    draw(state, event.subsecond);
                    break;
                case rpn_calculator_err:
                    state->mode = rpn_calculator_waiting;
                    draw(state, event.subsecond);
                    break;
                case rpn_calculator_op:
                    run_op(state);
                    draw(state, event.subsecond);
                    break;
                default:
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            state->mode = rpn_calculator_waiting;
            movement_request_tick_frequency(1);
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

void rpn_calculator_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}
