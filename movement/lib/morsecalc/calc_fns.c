/*
 * MIT License
 *
 * Copyright (c) 2023 Christian Chapman
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

#include <string.h>
#include <math.h>

#include "calc_fns.h" 

#define STACK_CHECK_0_IN_1_OUT if(cs->s >= N_STACK) return -2
#define STACK_CHECK_1_IN_0_OUT if(cs->s < 1) return -2
#define STACK_CHECK_1_IN_1_OUT if(cs->s < 1) return -2
#define STACK_CHECK_2_IN_1_OUT if(cs->s < 2) return -2
#define STACK_CHECK_2_IN_2_OUT if(cs->s < 2) return -2

static const double to_rad = M_PI/180;
static const double to_deg = 180/M_PI;

// Stack and memory control
int calc_delete(calc_state_t *cs) {
    if(cs->s < 1) return -2; // Check stack
    cs->s--; 
    return 0;
}
int calc_clear_stack(calc_state_t *cs) {
    memset(cs->stack, (0.0/0.0), N_STACK*sizeof(cs->stack[0]));
    cs->s = 0; 
    return 0;
}
int calc_flip(calc_state_t *cs) {
    STACK_CHECK_2_IN_2_OUT;
    double buff = cs->stack[cs->s-2];
    cs->stack[cs->s-2] = cs->stack[cs->s-1];
    cs->stack[cs->s-1] = buff;
    return 0;
}
int calc_mem_clear(calc_state_t *cs) {
    cs->mem = 0.0;
    return 0;
}
int calc_mem_recall(calc_state_t *cs) { 
    STACK_CHECK_0_IN_1_OUT;
    cs->stack[cs->s++] = cs->mem;
    return 0;
}
int calc_mem_add(calc_state_t *cs) {
    STACK_CHECK_1_IN_0_OUT;
    cs->mem += cs->stack[cs->s-1];
    cs->s--;
    return 0;
}
int calc_mem_subtract(calc_state_t *cs) {
    STACK_CHECK_1_IN_0_OUT;
    cs->mem -= cs->stack[cs->s-1];
    cs->s--;
    return 0;
}

// Basic operations
int calc_add(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT; 
    cs->stack[cs->s-2] += cs->stack[cs->s-1];
    cs->s--;
    return 0;
}
int calc_subtract(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT; 
    cs->stack[cs->s-2] -= cs->stack[cs->s-1];
    cs->s--;
    return 0;
}
int calc_negate(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = -cs->stack[cs->s-1];
    return 0;
}
int calc_multiply(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT; 
    cs->stack[cs->s-2] *= cs->stack[cs->s-1];
    cs->s--;
    return 0;
}
int calc_divide(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT;
    cs->stack[cs->s-2] /= cs->stack[cs->s-1];
    cs->s--;
    return 0;
}

int calc_invert(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = 1.0/cs->stack[cs->s-1];
    return 0;
}

// Constants
int calc_e(calc_state_t *cs) {
    STACK_CHECK_0_IN_1_OUT;
    cs->stack[cs->s++] = M_E;
    return 0;
}
int calc_pi(calc_state_t *cs) {
    STACK_CHECK_0_IN_1_OUT;
    cs->stack[cs->s++] = M_PI;
    return 0;
}

// Exponential/logarithmic
int calc_exp(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = exp(cs->stack[cs->s-1]);
    return 0;
}
int calc_pow(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT;
    cs->stack[cs->s-2] = pow(cs->stack[cs->s-2], cs->stack[cs->s-1]);
    cs->s--;
    return 0;
}
int calc_ln(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = log(cs->stack[cs->s-1]);
    return 0;
}
int calc_log(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = log10(cs->stack[cs->s-1]);
    return 0;
}
int calc_sqrt(calc_state_t *cs)  {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = sqrt(cs->stack[cs->s-1]);
    return 0;
}

// Trigonometric
int calc_sin(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = sin(cs->stack[cs->s-1]);
    return 0;
}
int calc_cos(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = cos(cs->stack[cs->s-1]);
    return 0;
}
int calc_tan(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = tan(cs->stack[cs->s-1]);
    return 0;
} 
int calc_asin(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = asin(cs->stack[cs->s-1]);
    return 0;
}
int calc_acos(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = acos(cs->stack[cs->s-1]);
    return 0;
}
int calc_atan(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = atan(cs->stack[cs->s-1]);
    return 0;
}
int calc_atan2(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT;
    cs->stack[cs->s-2] = atan2(cs->stack[cs->s-2], cs->stack[cs->s-1]);
    cs->s--;
    return 0;
}

int calc_sind(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = sin(cs->stack[cs->s-1]*to_rad);
    return 0;
}
int calc_cosd(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = cos(cs->stack[cs->s-1]*to_rad);
    return 0;
}
int calc_tand(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = tan(cs->stack[cs->s-1]*to_rad);
    return 0;
}
int calc_asind(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = asin(cs->stack[cs->s-1])*to_deg;
    return 0;
}
int calc_acosd(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = acos(cs->stack[cs->s-1])*to_deg;
    return 0;
}
int calc_atand(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT; 
    cs->stack[cs->s-1] = atan(cs->stack[cs->s-1])*to_deg;
    return 0;
}
int calc_atan2d(calc_state_t *cs) {
    STACK_CHECK_2_IN_1_OUT;
    cs->stack[cs->s-2] = atan2(cs->stack[cs->s-2], cs->stack[cs->s-1])*to_deg;
    cs->s--;
    return 0;
}
int calc_torad(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT;
    cs->stack[cs->s-1] = cs->stack[cs->s-1]*to_rad;
    return 0;
}
int calc_todeg(calc_state_t *cs) {
    STACK_CHECK_1_IN_1_OUT;
    cs->stack[cs->s-1] = cs->stack[cs->s-1]*to_deg;
    return 0;
}

