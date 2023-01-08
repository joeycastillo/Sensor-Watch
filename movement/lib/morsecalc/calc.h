#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED 

#include <stdint.h>

#define N_STACK 16
#define N_REG 3

typedef struct {
    double stack[N_STACK];
    double reg[N_REG];
    uint8_t s; // # of items in stack 
} calc_state_t;
 
int calc_init(calc_state_t *cs);
int calc_input(calc_state_t *cs, char *token);
int calc_input_function(calc_state_t *cs, char *token);
int calc_input_float(calc_state_t *cs, char *token);
double small_strtof(const char *str, char **endptr);

#endif
