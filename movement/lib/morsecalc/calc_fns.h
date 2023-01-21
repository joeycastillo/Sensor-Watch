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

// Dictionary definition
typedef int (*calc_fn_t)(calc_state_t *cs);
typedef struct {
    char *names[3]; // Token to use to run this function
    calc_fn_t fn; // Pointer to function 
} calc_dict_entry_t;

static const calc_dict_entry_t calc_dict[] = {
    // Stack and register control
    {{"x"}, &calc_delete},
    {{"xx"}, &calc_clear_stack},
    {{"xxx"}, &calc_init},
    {{"f"}, &calc_flip},
    {{"mc"}, &calc_mem_clear},
    {{"mr"}, &calc_mem_recall},
    {{"ma"}, &calc_mem_add},
    {{"ms"}, &calc_mem_subtract},

    // Basic operations
    {{"a"}, &calc_add}, 
    {{"s"}, &calc_subtract},
    {{"n"}, &calc_negate},
    {{"m"}, &calc_multiply},
    {{"d"}, &calc_divide},
    {{"i"}, &calc_invert},
    
    // Constants
    {{"e"}, &calc_e}, 
    {{"pi"}, &calc_pi},  
    
    // Exponential/logarithmic
    {{"exp"}, &calc_exp},
    {{"pow"}, &calc_pow}, 
    {{"ln"}, &calc_ln}, 
    {{"log"}, &calc_log},
    {{"sqrt"}, &calc_sqrt},
    
    // Trigonometric 
    {{"sin", "sn"}, &calc_sin},
    {{"cos"}, &calc_cos},
    {{"tan"}, &calc_tan},
    {{"asin"}, &calc_asin},
    {{"acos"}, &calc_acos},
    {{"atan"}, &calc_atan}, 
    {{"atan2"}, &calc_atan2},
    {{"sind"}, &calc_sind},
    {{"cosd"}, &calc_cosd},
    {{"tand"}, &calc_tand},
    {{"asind"}, &calc_asind},
    {{"acosd"}, &calc_acosd},
    {{"atand"}, &calc_atand}, 
    {{"atan2d"}, &calc_atan2d}, 
}; 
