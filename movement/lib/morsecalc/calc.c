#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "calc.h"
#include "calc_fns.h"

#define CALC_NAN (0.0/0.0)

/* calc_init 
 * Initialize calculator
 */
int calc_init(calc_state_t *cs) {    
    memset(cs->stack, CALC_NAN, N_STACK*sizeof(cs->stack[0]));
    memset(cs->reg, CALC_NAN, N_REG*sizeof(cs->stack[0]));
    cs->s = 0; 
    return 0;
}

/* calc_input_function
 * Try to execut the token as a calculator function
 * TODO: Maybe replace this loop with binary search for token in a sorted calc_dict
 */
int calc_input_function(calc_state_t *cs, char *token) {
    for(uint8_t idx=0; idx<sizeof(calc_dict)/sizeof(calc_dict[0]); idx++) {
        if(0 == strcmp(calc_dict[idx].name, token)) { // Found a match
            return (*calc_dict[idx].fn)(cs); // Run calculator function
        }
    }
    return -1; // Unrecognized function name
}

/* calc_input_float
 * Try to read the token as a float.
 * "p" is "." and "m" is "-".
 * e.g. token == "4p2em3" ---> "4.2e-3"
 * or token == "0p0042" ---> "0.0042"
 */ 
int calc_input_float(calc_state_t *cs, char *token) {
    for(uint8_t idx=0; idx<strlen(token); idx++) 
        if('p'==token[idx]) token[idx] = '.'; // replace p --> .
    for(uint8_t idx=0; idx<strlen(token); idx++) 
        if('m'==token[idx]) token[idx] = '-'; // replace m --> -
    
    char *endptr;
    double d = small_strtof(token, &endptr);
    if(token == endptr) return -1; // Couldn't find a double in the string
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
    if(retval == -1) retval = calc_input_float(cs, token);
    return retval;
}
