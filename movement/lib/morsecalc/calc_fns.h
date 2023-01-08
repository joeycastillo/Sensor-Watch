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
    char *name; // Token to use to run this function
    calc_fn_t fn; // Pointer to function 
} calc_dict_entry_t;
static const calc_dict_entry_t calc_dict[] = {
    // Stack and register control
    {"x", &calc_delete},
    {"xxx", &calc_clear_stack},
    {"xxx", &calc_init},
    {"f", &calc_flip},
    {"mc", &calc_mem_clear},
    {"mr", &calc_mem_recall},
    {"ma", &calc_mem_add},
    {"ms", &calc_mem_subtract},

    // Basic operations
    {"a", &calc_add}, 
    {"s", &calc_subtract},
    {"n", &calc_negate},
    {"m", &calc_multiply},
    {"d", &calc_divide},
    {"i", &calc_invert},
    
    // Constants
    {"e", &calc_e}, 
    {"pi", &calc_pi},  
    
    // Exponential/logarithmic
    {"exp", &calc_exp},
    {"pow", &calc_pow}, 
    {"ln", &calc_ln}, 
    {"log", &calc_log},
    {"sqrt", &calc_sqrt},
    
    // Trigonometric 
    {"sin", &calc_sin},
    {"cos", &calc_cos},
    {"tan", &calc_tan},
    {"ason", &calc_asin},
    {"acos", &calc_acos},
    {"atan", &calc_atan}, 
    {"atan2", &calc_atan2},
    {"sind", &calc_sind},
    {"cosd", &calc_cosd},
    {"tand", &calc_tand},
    {"asind", &calc_asind},
    {"acosd", &calc_acosd},
    {"atand", &calc_atand}, 
    {"atan2d", &calc_atan2d}, 
}; 
