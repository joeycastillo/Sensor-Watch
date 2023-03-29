/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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
#include "divinate_face.h"
#if __EMSCRIPTEN__
#include <time.h>
#else
#include "saml22j18a.h"
#endif

static const char heads[] = { '8', 'h', '4', 'E', '(' };
static const char tails[] = { '0', '+', 'n', '3', ')' };
static const uint8_t dd[] = {2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,28,30,32,34,36,48,50,60}; 

static void _roll_dice_multiple(char* result, uint8_t* dice, uint8_t num_dice);
static void _sort_coins(char* token, uint8_t num_bits, uint8_t bits, char* heads, char* tails);
void _display_coins(char* token, bool* bit_array, uint8_t length, divinate_state_t *state);
static void _divinate_face_display(divinate_state_t *state);
static bool _quick_ticks_running;
static void _abort_quick_ticks();

// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////

void divinate_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    divinate_state_t *state = (divinate_state_t *)context;
}

bool divinate_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    divinate_state_t *state = (divinate_state_t *)context;
    uint8_t i = 0;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string("di  Coins", 0);
            break;
        case EVENT_TICK:
            if (_quick_ticks_running) {
                if (watch_get_pin_level(BTN_LIGHT)) {
                    state->dd = (state->dd + 1) % 31;
                    state->dice_sides[state->dice_num-1] = dd[state->dd];
                    state->dice[state->dice_num-1] = dd[state->dd];
                    _divinate_face_display(state);
                }
                else _abort_quick_ticks();
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            _abort_quick_ticks();
            if ( state->mode <= 1 ) state->mode = 2;
            else if ( state->mode >= 2 ) state->mode = 0;
            _divinate_face_display(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            _abort_quick_ticks();
            switch (state->mode) {
                case 0:
                    state->mode++;
                case 1:
                    for (i = 0; i < state->coin_num; i++) {
                        state->coins[i] = divine_bit();
                    }             
                    break;
                case 2:
                    state->mode++;
                case 3:
                    for (i = 0; i < state->dice_num; i++) {
                        state->dice[i] = roll_dice(state->dice_sides[i]);
                    }  
                    break;
                default:
                    break;
            }
            _divinate_face_display(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            switch (state->mode) {
                case 0:
                    state->coin_style[0] = heads[0];
                    state->coin_style[1] = tails[0];
                    state->coinface = 0;
                    break;
                case 1:
                    state->coinface = (state->coinface + 1) % 5;
                    state->coin_style[0] = heads[state->coinface];
                    state->coin_style[1] = tails[state->coinface];         
                    break;
                case 2:
                    state->dice_sides[0] = 6;
                    state->dice_sides[1] = 6;
                    state->dice_sides[2] = 6;
                    state->dd = 0;
                    break;
                case 3:
                    state->dd = (state->dd + 1) % 32;
                    state->dice_sides[state->dice_num-1] = dd[state->dd];
                    state->dice[state->dice_num-1] = dd[state->dd];
                    _quick_ticks_running = true;
                    break;
                default:
                    break;
            }
            printf("%d\n", _quick_ticks_running);
            _divinate_face_display(state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            switch (state->mode) {
                case 0:
                    state->coin_num = 1;
                    break;
                case 1:
                    state->coin_num = (state->coin_num % 6) + 1;             
                    break;
                case 2:
                    state->dice_num = 1;
                    break;
                case 3:
                    state->dice_num = (state->dice_num % 3) + 1;
                    state->dd = 0;
                    break;
                default:
                    break;
            }
            _divinate_face_display(state);
            break;
        case EVENT_ALARM_LONG_UP:
            _abort_quick_ticks();
            break;
        case EVENT_LIGHT_LONG_UP:
            _abort_quick_ticks();
            break;
        case EVENT_TIMEOUT:
            _abort_quick_ticks();
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void divinate_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static void _divinate_face_display(divinate_state_t *state) {
    char buf[10];
    char token[7] = {0};
    watch_clear_display();
    switch ( state->mode ) {
        case 0: // coins title
            sprintf(buf, "di  Coins");
            break;
        case 1: // coins divination
            _display_coins(token, state->coins, state->coin_num, state);
            sprintf(buf, "    %s", token);
            break;
        case 2: // dice title
            sprintf(buf, "di  Dice");
            break;
        case 3: // dice divination
            _roll_dice_multiple(token, state->dice, state->dice_num + 1);
            sprintf(buf, "    %s", token);
            break;
        default:
            break;
    }
    watch_display_string(buf, 0);
}

uint8_t roll_dice(uint8_t sides) {
    uint8_t bits_needed = 0;
    uint8_t temp_sides = sides - 1;
    uint8_t result = 0;
    while (temp_sides > 0) {
        bits_needed++;
        temp_sides >>= 1; // Shift right to check the next bit
    }
    do {
        result = 0;
        for (int i = 0; i < bits_needed; i++) {
            result <<= 1; // Shift left to make room for the next bit
            result |= divine_bit(); // Add the next bit to the result
        }
    } while ( result > sides -1 );
    return result + 1; // Add 1 to convert the range from 0 to sides-1 to 1 to sides
}

uint8_t divine_bit() {
    uint32_t stalks;
    do {
        stalks = get_true_entropy();
    } while (stalks >= INT32_MAX || stalks <= 0);

    uint8_t pile1_xor = 0;
    uint8_t pile2_xor = 0;
    // Divide the stalks into two piles, alternating ends
    for (uint8_t i = 0; i < 16; i++) {
        uint8_t left_bit = (stalks >> (31 - 2*i)) & 1;
        uint8_t right_bit = (stalks >> (30 - 2*i)) & 1;
        if (i % 2 == 0) {
            pile1_xor ^= left_bit;
            pile2_xor ^= right_bit;
        } else {
            pile1_xor ^= right_bit;
            pile2_xor ^= left_bit;
        }
    }
    // Take the XOR of the pile results
    uint8_t result_xor = pile1_xor ^ pile2_xor;
    // Output 1 if result_xor is 1, 0 otherwise
    return result_xor;
}

uint32_t get_true_entropy(void) {
    #if __EMSCRIPTEN__
    return rand() % INT32_MAX;
    #else
    hri_mclk_set_APBCMASK_TRNG_bit(MCLK);
    hri_trng_set_CTRLA_ENABLE_bit(TRNG);

    while (!hri_trng_get_INTFLAG_reg(TRNG, TRNG_INTFLAG_DATARDY)); // Wait for TRNG data to be ready

    hri_trng_clear_CTRLA_ENABLE_bit(TRNG);
    hri_mclk_clear_APBCMASK_TRNG_bit(MCLK);
    return hri_trng_read_DATA_reg(TRNG); // Read a single 32-bit word from TRNG and return it
    #endif
}

void divinate_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(divinate_state_t));
        memset(*context_ptr, 0, sizeof(divinate_state_t));
        divinate_state_t *state = (divinate_state_t *)*context_ptr;

        state->coin_num = 1;
        state->dice_num = 1;
        state->dice_sides[0] = 6;
        state->dice_sides[1] = 6;
        state->dice_sides[2] = 6;
        state->coin_style[0] = '8';
        state->coin_style[1] = '0';
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

// STATIC FUNCTIONS ///////////////////////////////////////////////////////////

static void _roll_dice_multiple(char* result, uint8_t* dice, uint8_t num_dice) {
    // initialize the result array to all spaces
    memset(result, ' ', 6);

    // roll the dice and write the result to the result array
    for (uint8_t i = 0; i < num_dice-1; i++) {
        uint8_t dice_result = dice[i];
        uint8_t tens_digit = dice_result / 10;
        uint8_t ones_digit = dice_result % 10;
        result[(i * 2)] = tens_digit == 0 ? ' ' : (char)('0' + tens_digit);
        result[(i * 2) + 1] = (char)('0' + ones_digit);
    }
}

static void _sort_coins(char* token, uint8_t num_bits, uint8_t bits, char* heads, char* tails) {
    uint8_t num_ones = 0;
    for (uint8_t i = 0; i < num_bits; i++) {
        if ((bits >> i) & 1) {
            *token++ = heads;
            num_ones++;
        }
    }
    if ( num_bits < 6 ) {
        for (uint8_t i = 0; i < (6 - num_bits); i++) {
            *token++ = ' ';
        }
    }
    for (uint8_t i = 0; i < (num_bits - num_ones); i++) {

        *token++ = tails;
    }
}

void _display_coins(char* token, bool* bit_array, uint8_t length, divinate_state_t *state) {
    uint8_t bits = 0;
    for (uint8_t i = 0; i < length; i++) {
        if (bit_array[i]) {
            bits |= (1 << (length - 1 - i));
        }
    }
    _sort_coins(token, length, bits, state->coin_style[0], state->coin_style[1]);
}

static void _abort_quick_ticks() {
    if (_quick_ticks_running) {
        _quick_ticks_running = false;
    }
}