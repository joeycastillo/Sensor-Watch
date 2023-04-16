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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "calc.h"
#include "calc_fns.h"

#define CALC_NAN (0.0/0.0)

/* calc_init 
 * Initialize calculator
 */
int calc_init(calc_state_t *cs) {    
    memset(cs->stack, CALC_NAN, N_STACK*sizeof(cs->stack[0]));
    cs->s = 0; 
    cs->mem = 0.0;
    return 0;
}

/* calc_input_function
 * Try to execute the token as a calculator function
 */
int calc_input_function(calc_state_t *cs, char *token) {
    for(uint8_t idx=0; idx<sizeof(calc_dict)/sizeof(calc_dict[0]); idx++) {
        for(uint8_t idxn=0; idxn<calc_dict[idx].n_names; idxn++) {
            if(0 == strcmp(calc_dict[idx].names[idxn], token)) { // Found a match
                return (*calc_dict[idx].fn)(cs); // Run calculator function
            }
        }
    }
    return -1; // Unrecognized function name
}

/* calc_input_float
 * Read the token as a float.
 * For convenience, numerals can be written in binary:
 * 0     1    2    3    4    5    6    7    8    9
 * .     -    -.   --   -..  -.-  --.  ---  -... -..-
 * e     t    n    m    d    k    g    o    b    x
 * 
 * Exponent signs must be entered as "p".
 * Decimal place "." can be entered as "h" (code ....)
 * Sign "-" can be entered as "Ch digraph" (code ----)
 * 
 * e.g. "4.2e-3" can be entered directly or as "4h2pC3"
 * similarly, "0.0042" can be "eheedn"
 */ 
#define REPCHAR(X,Y) for(idx=0; idx<strlen(token); idx++) \
    if(X==token[idx]) token[idx] = Y
int calc_input_float(calc_state_t *cs, char *token) {
    uint8_t idx;
    REPCHAR('e', '0');
    REPCHAR('t', '1');
    REPCHAR('n', '2');
    REPCHAR('m', '3');
    REPCHAR('d', '4');
    REPCHAR('k', '5');
    REPCHAR('g', '6');
    REPCHAR('o', '7');
    REPCHAR('b', '8');
    REPCHAR('x', '9');
    REPCHAR('h', '.');
    REPCHAR('C', '-');
    REPCHAR('p', 'E');
    
    char *endptr;
    double d = calc_strtof(token, &endptr);
    if(!endptr || (uint8_t)(endptr-token)<strlen(token)) return -1; // Bad format
    if(cs->s >= N_STACK) return -2; // Stack full
    cs->stack[cs->s++] = d;
    return 0;
}

/* calc_input
 * Manipulate the stack using the entered token.
 * If the token isn't a calculator function, try to convert it to a number and
 * add it to the stack.
 *
 * Return values: 
 *  0 if function completed successfully.
 * -1 if token isn't a calculator function and couldn't convert to float.
 * -2 if stack is too full or too empty
 * -3 for something else
 */
int calc_input(calc_state_t *cs, char *token) {
    int retval = calc_input_function(cs, token);
    if(-1 == retval) retval = calc_input_float(cs, token);
    return retval;
}
