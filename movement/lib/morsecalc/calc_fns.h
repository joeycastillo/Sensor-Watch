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

#include "calc.h"

// Stack and register control
int calc_delete(calc_state_t *cs);
int calc_clear_stack(calc_state_t *cs);
int calc_flip(calc_state_t *cs);
int calc_mem_clear(calc_state_t *cs);
int calc_mem_recall(calc_state_t *cs);
int calc_mem_add(calc_state_t *cs);
int calc_mem_subtract(calc_state_t *cs);

// Basic operations
int calc_add(calc_state_t *cs);
int calc_subtract(calc_state_t *cs);
int calc_negate(calc_state_t *cs);
int calc_multiply(calc_state_t *cs);
int calc_divide(calc_state_t *cs);
int calc_invert(calc_state_t *cs);

// Constants
int calc_e(calc_state_t *cs);
int calc_pi(calc_state_t *cs);

// Exponential/logarithmic
int calc_exp(calc_state_t *cs);
int calc_pow(calc_state_t *cs);
int calc_ln(calc_state_t *cs);
int calc_log(calc_state_t *cs);
int calc_sqrt(calc_state_t *cs);

// Trigonometric
int calc_sin(calc_state_t *cs);
int calc_cos(calc_state_t *cs);
int calc_tan(calc_state_t *cs);
int calc_asin(calc_state_t *cs);
int calc_acos(calc_state_t *cs);
int calc_atan(calc_state_t *cs);
int calc_atan2(calc_state_t *cs);
int calc_sind(calc_state_t *cs);
int calc_cosd(calc_state_t *cs);
int calc_tand(calc_state_t *cs);
int calc_asind(calc_state_t *cs);
int calc_acosd(calc_state_t *cs);
int calc_atand(calc_state_t *cs);
int calc_atan2d(calc_state_t *cs);
int calc_torad(calc_state_t *cs);
int calc_todeg(calc_state_t *cs);

// Dictionary definition
typedef int (*calc_fn_t)(calc_state_t *cs);
typedef struct {
    uint8_t n_names; // Number of aliases
    const char ** names; // Token to use to run this function
    calc_fn_t fn; // Pointer to function 
} calc_dict_entry_t;

static const calc_dict_entry_t calc_dict[] = {
    // Stack and register control
    {1, (const char*[]){"x"}, &calc_delete},
    {1, (const char*[]){"xx"}, &calc_clear_stack},
    {1, (const char*[]){"xxx"}, &calc_init},
    {1, (const char*[]){"f"}, &calc_flip},
    {1, (const char*[]){"mc"}, &calc_mem_clear},
    {1, (const char*[]){"mr"}, &calc_mem_recall},
    {1, (const char*[]){"ma"}, &calc_mem_add},
    {1, (const char*[]){"ms"}, &calc_mem_subtract},

    // Basic operations
    {1, (const char*[]){"a"}, &calc_add}, 
    {1, (const char*[]){"s"}, &calc_subtract},
    {1, (const char*[]){"n"}, &calc_negate},
    {1, (const char*[]){"m"}, &calc_multiply},
    {1, (const char*[]){"d"}, &calc_divide},
    {1, (const char*[]){"i"}, &calc_invert},
    
    // Constants
    {1, (const char*[]){"e"}, &calc_e}, 
    {1, (const char*[]){"pi"}, &calc_pi}, 
    
    // Exponential/logarithmic
    {1, (const char*[]){"exp"}, &calc_exp},
    {1, (const char*[]){"pow"}, &calc_pow}, 
    {1, (const char*[]){"ln"}, &calc_ln}, 
    {1, (const char*[]){"log"}, &calc_log},
    {1, (const char*[]){"sqrt"}, &calc_sqrt},
    
    // Trigonometric 
    {2, (const char*[]){"sin", "sn"}, &calc_sin},
    {1, (const char*[]){"cos"}, &calc_cos},
    {1, (const char*[]){"tan"}, &calc_tan},
    {1, (const char*[]){"asin"}, &calc_asin},
    {1, (const char*[]){"acos"}, &calc_acos},
    {1, (const char*[]){"atan"}, &calc_atan}, 
    {1, (const char*[]){"atan2"}, &calc_atan2},
    {1, (const char*[]){"sind"}, &calc_sind},
    {1, (const char*[]){"cosd"}, &calc_cosd},
    {1, (const char*[]){"tand"}, &calc_tand},
    {1, (const char*[]){"asind"}, &calc_asind},
    {1, (const char*[]){"acosd"}, &calc_acosd},
    {1, (const char*[]){"atand"}, &calc_atand}, 
    {1, (const char*[]){"atan2d"}, &calc_atan2d}, 
    {1, (const char*[]){"tor"}, &calc_torad}, 
    {1, (const char*[]){"tod"}, &calc_todeg}, 
}; 
