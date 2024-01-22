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
#include "toss_up_face.h"
#if __EMSCRIPTEN__
#include <time.h>
#else
#include "saml22j18a.h"
#endif

static const char heads[] = { '8', 'h', '4', 'E', '(' };
static const char tails[] = { '0', '+', 'N', '3', ')' };
static const uint8_t dd[] = {2, 4, 6, 8, 10,12,20,24,30,32,36,48,99}; 

static void _roll_dice_multiple(char* result, uint8_t* dice, uint8_t num_dice);
static void _sort_coins(char* token, uint8_t num_bits, uint8_t bits, char* heads, char* tails);
void _display_coins(char* token, bool* bit_array, uint8_t length, toss_up_state_t *state);
static void _toss_up_face_display(toss_up_state_t *state);
static void _dice_animation(toss_up_state_t *state);
static void _coin_animation(toss_up_state_t *state);

// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////

void toss_up_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(toss_up_state_t));
        memset(*context_ptr, 0, sizeof(toss_up_state_t));
        toss_up_state_t *state = (toss_up_state_t *)*context_ptr;

        // defaults
        state->coin_num = 1;
        state->dice_num = 1;
        state->dice_sides[0] = 6;
        state->dice_sides[1] = 6;
        state->dice_sides[2] = 6;
        state->coin_style[0] = '8';
        state->coin_style[1] = '0';
    }
}

void toss_up_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool toss_up_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    toss_up_state_t *state = (toss_up_state_t *)context;
    uint8_t i = 0;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_display_string("    Coins ", 0);
            break;
        case EVENT_TICK:
            if ( state->animate ) {
                state->animation = (state->animation + 1);
                _toss_up_face_display(state);
            } 
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if ( state->animate ) break;
            // change between coins and dice
            if ( state->mode <= 1 ) state->mode = 2;
            else if ( state->mode >= 2 ) state->mode = 0;
            _toss_up_face_display(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // toss
            if ( state->animate ) break;
            switch (state->mode) {
                case 0:
                    state->mode++;
                    // fall through
                case 1:
                    state->animate = true;
                    for (i = 0; i < state->coin_num; i++) {
                        state->coins[i] = divine_bit();
                    }             
                    break;
                case 2:
                    state->mode++;
                    // fall through
                case 3:
                    state->animate = true;
                    for (i = 0; i < state->dice_num; i++) {
                        state->dice[i] = roll_dice(state->dice_sides[i]);
                    }  
                    break;
                default:
                    break;
            }
            _toss_up_face_display(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if ( state->animate ) break;
            state->animate = false;
            switch (state->mode) {
                case 0: // change to default coin style
                    state->coin_style[0] = heads[0];
                    state->coin_style[1] = tails[0];
                    state->coinface = 0;
                    break;
                case 1: // change the coin style
                    state->coinface = (state->coinface + 1) % 5;
                    state->coin_style[0] = heads[state->coinface];
                    state->coin_style[1] = tails[state->coinface];         
                    break;
                case 2: // change to default dice sides
                    state->dice_sides[0] = 6;
                    state->dice_sides[1] = 6;
                    state->dice_sides[2] = 6;
                    state->dd = 0;
                    break;
                case 3: // change the sides of the dice
                    state->dd = (state->dd + 1) % 13;
                    state->dice_sides[state->dice_num-1] = dd[state->dd];
                    state->dice[state->dice_num-1] = dd[state->dd];
                    break;
                default:
                    break;
            }
            _toss_up_face_display(state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if ( state->animate ) break;
            state->animate = false;
            switch (state->mode) {
                case 0: // back to one coin
                    state->coin_num = 1;
                    break;
                case 1: // up to 6 coins total
                    state->coin_num = (state->coin_num % 6) + 1;             
                    break;
                case 2: // back to one dice
                    state->dice_num = 1;
                    break;
                case 3: // add up to 3 dice total
                    state->dice_num = (state->dice_num % 3) + 1;
                    state->dd = 0;
                    break;
                default:
                    break;
            }
            _toss_up_face_display(state);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void toss_up_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

// STATIC FUNCTIONS ///////////////////////////////////////////////////////////

/** @brief handles the display 
 */
static void _toss_up_face_display(toss_up_state_t *state) {
    char buf[11] = {0};
    char token[7] = {0};
    switch ( state->mode ) {
        case 0: // coins title
            sprintf(buf, "    Coins ");
            break;
        case 1: // coins divination
            _coin_animation(state);
            if ( !state->animate ) {
                watch_clear_display();
                _display_coins(token, state->coins, state->coin_num, state);
                sprintf(buf, "    %s", token);
            }
            break;
        case 2: // dice title
            sprintf(buf, "    Dice ");
            break;
        case 3: // dice divination
            _dice_animation(state);
            if ( !state->animate ) {
                _roll_dice_multiple(token, state->dice, state->dice_num + 1);
                sprintf(buf, "    %s", token);
            }
            break;
        default:
            break;
    }
    watch_display_string(buf, 0);
}

/** @brief divination method to derive a bit from 32 TRNG bits
 */
uint8_t divine_bit(void) {
    uint32_t stalks;
    do { // modulo bias filter
        stalks = get_true_entropy(); // get 32 TRNG bits as stalks
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

/** @brief get 32 True Random Number bits
 */
uint32_t get_true_entropy(void) {
    #if __EMSCRIPTEN__
    return rand() % INT32_MAX;
    #else
    hri_mclk_set_APBCMASK_TRNG_bit(MCLK);
    hri_trng_set_CTRLA_ENABLE_bit(TRNG);

    while (!hri_trng_get_INTFLAG_reg(TRNG, TRNG_INTFLAG_DATARDY)); // Wait for TRNG data to be ready

    watch_disable_TRNG();

    hri_mclk_clear_APBCMASK_TRNG_bit(MCLK);
    return hri_trng_read_DATA_reg(TRNG); // Read a single 32-bit word from TRNG and return it
    #endif
}

// COIN FUNCTIONS /////////////////////////////////////////////////////////////

/** @brief sort tossed coins into a pile of heads and a pile of tails
 */
static void _sort_coins(char* token, uint8_t num_bits, uint8_t bits, char* heads, char* tails) {
    uint8_t num_ones = 0;
    for (uint8_t i = 0; i < num_bits; i++) {
        if ((bits >> i) & 1) {
            *token++ = *heads;
            num_ones++;
        }
    }
    if ( num_bits < 6 ) {
        for (uint8_t i = 0; i < (6 - num_bits); i++) {
            *token++ = ' ';
        }
    }
    for (uint8_t i = 0; i < (num_bits - num_ones); i++) {

        *token++ = *tails;
    }
}

/** @brief convert bool array of coinflips to integer for sorting
 */
void _display_coins(char* token, bool* bit_array, uint8_t length, toss_up_state_t *state) {
    uint8_t bits = 0;
    for (uint8_t i = 0; i < length; i++) {
        if (bit_array[i]) {
            bits |= (1 << (length - 1 - i));
        }
    }
    _sort_coins(token, length, bits, &state->coin_style[0], &state->coin_style[1]);
}

/** @brief coin animation
 */
static void _coin_animation(toss_up_state_t *state) {
    bool heads = false;
    bool tails = false;
    for (uint8_t i = 0; i < state->coin_num; i++) {
        if (state->coins[i] == true) {
            heads = true;
        } else {
            tails = true;
        }
    }
    movement_request_tick_frequency(32);
    switch ( state->animation ) {
        case 0:
            watch_display_string("      ", 4);
            if ( heads ) {
                watch_set_pixel(0, 18);
                watch_set_pixel(2, 18);
            } else {
                state->animation = 12;
            }
            break;
        case 1:
            if ( heads ) {
                watch_set_pixel(1, 18);
            }
            break;
        case 2:
            if ( heads ) {
                watch_set_pixel(0, 19);
                watch_set_pixel(2, 19);
            }
            break;
        case 3:
            if ( heads ) {
                watch_clear_pixel(0, 18);
                watch_clear_pixel(2, 18);
            }
            break;
        case 4:
            if ( heads ) {
                watch_clear_pixel(1, 18);
            }
            break;
        case 5:
            if ( heads ) {
                watch_clear_pixel(0, 19);
                watch_clear_pixel(2, 19);
                watch_set_pixel(1, 17);
                watch_set_pixel(0, 20);
            }
            break;
        case 6:
            if ( heads ) {
                watch_set_pixel(2, 20);
                watch_set_pixel(0, 21);
            }
            break;
        case 7:
            if ( heads ) {
                watch_set_pixel(1, 21);
                watch_set_pixel(2, 21);
            }
            break;
        case 8:
            if ( heads ) {
                watch_clear_pixel(1, 17);
                watch_clear_pixel(0, 20);
            }
            break;
        case 9:
            if ( heads ) {
                watch_clear_pixel(2, 20);
                watch_clear_pixel(0, 21);
            }
            break;
        case 10:
            if ( heads ) {
                watch_clear_pixel(1, 21);
                watch_clear_pixel(2, 21);
                watch_set_pixel(1, 22);
                watch_set_pixel(2, 22);
            }
            break;
        case 11:
            if ( heads ) {
                watch_set_pixel(0, 22);
            }
            break;
        case 12:
            if ( heads ) {
                watch_set_pixel(2, 23);
                watch_set_pixel(0, 23);
            }
            if ( tails ) {
                watch_set_pixel(0, 18);
                watch_set_pixel(2, 18);
            }
            break;
        case 13:
            if ( heads ) {
                watch_clear_pixel(1, 22);
                watch_clear_pixel(2, 22);
            }
            if ( tails ) {
                watch_set_pixel(1, 18);
            }
            break;
        case 14:
            if ( heads ) {
                watch_clear_pixel(0, 22);
            }
            if ( tails ) {
                watch_set_pixel(0, 19);
                watch_set_pixel(2, 19);
            }
            break;
        case 15:
            if ( heads ) {
                watch_clear_pixel(2, 23);
                watch_clear_pixel(0, 23);
                watch_set_pixel(2, 0);
                watch_set_pixel(1, 0);
            }
            if ( tails ) {
                watch_clear_pixel(0, 18);
                watch_clear_pixel(2, 18);
            }
            break;
        case 16:
            if ( heads ) {
                watch_set_pixel(2, 1);
                watch_set_pixel(0, 0);
            }
            if ( tails ) {
                watch_clear_pixel(1, 18);
            }
            break;
        case 17:
            if ( heads ) {
                watch_set_pixel(2, 10);
                watch_set_pixel(0, 1);
            }
            if ( tails ) {
                watch_clear_pixel(0, 19);
                watch_clear_pixel(2, 19);
                watch_set_pixel(1, 17);
                watch_set_pixel(0, 20);
            }
            break;
        case 18:
            if ( heads ) {
                watch_clear_pixel(2, 0);
                watch_clear_pixel(1, 0);
            }
            if ( tails ) {
                watch_set_pixel(2, 20);
                watch_set_pixel(0, 21);
            }
            break;
        case 19:
            if ( heads ) {
                watch_clear_pixel(2, 1);
                watch_clear_pixel(0, 0);
            }
            if ( tails ) {
                watch_set_pixel(1, 21);
                watch_set_pixel(2, 21);
            }
            break;
        case 20:
            if ( heads ) {
                watch_set_pixel(2, 1);
                watch_set_pixel(0, 0);
            }
            if ( tails ) {
                watch_clear_pixel(1, 17);
                watch_clear_pixel(0, 20);
            }
            break;
        case 21:
            if ( heads ) {
                watch_set_pixel(2, 0);
                watch_set_pixel(1, 0);
            }
            if ( tails ) {
                watch_clear_pixel(2, 20);
                watch_clear_pixel(0, 21);
            }
            break;
        case 22:
            if ( heads ) {
                watch_clear_pixel(2, 10);
                watch_clear_pixel(0, 1);
            }
            if ( tails ) {
                watch_clear_pixel(1, 21);
                watch_clear_pixel(2, 21);
                watch_set_pixel(1, 22);
                watch_set_pixel(2, 22);
            }
            break;
        case 23:
            if ( heads ) {
                watch_clear_pixel(2, 1);
                watch_clear_pixel(0, 0);
            }
            if ( tails ) {
                watch_set_pixel(0, 22);
            }
            break;
        case 24:
            if ( heads ) {
                watch_set_pixel(2, 23);
                watch_set_pixel(0, 23);
                watch_clear_pixel(2, 0);
                watch_clear_pixel(1, 0);
            }
            if ( tails ) {
                watch_set_pixel(2, 23);
                watch_set_pixel(0, 23);
            }
            break;
        case 25:
            if ( heads ) {
                watch_set_pixel(0, 22);
            }
            if ( tails ) {
                watch_clear_pixel(1, 22);
                watch_clear_pixel(2, 22);
            }
            break;
        case 26:
            if ( heads ) {
                watch_set_pixel(1, 22);
                watch_set_pixel(2, 22);
            }
            if ( tails ) {
                watch_clear_pixel(0, 22);
            }
            break;
        case 27:
            if ( heads ) {
                watch_clear_pixel(2, 23);
                watch_clear_pixel(0, 23);
            }
            if ( tails ) {
                watch_clear_pixel(2, 23);
                watch_clear_pixel(0, 23);
                watch_set_pixel(2, 0);
                watch_set_pixel(1, 0);
            }
            break;
        case 28:
            if ( heads ) {
                watch_clear_pixel(0, 22);
            }
            if ( tails ) {
                watch_set_pixel(2, 1);
                watch_set_pixel(0, 0);
            }
            break;
        case 29:
            if ( heads ) {
                watch_set_pixel(1, 21);
                watch_set_pixel(2, 21);
                watch_clear_pixel(1, 22);
                watch_clear_pixel(2, 22);
            }
            if ( tails ) {
                watch_set_pixel(2, 10);
                watch_set_pixel(0, 1);
            }
            break;
        case 30:
            if ( heads ) {
                watch_set_pixel(2, 20);
                watch_set_pixel(0, 21);
            }
            if ( tails ) {
                watch_clear_pixel(1, 0);
                watch_clear_pixel(2, 0);
            }
            break;
        case 31:
            if ( heads ) {
                watch_set_pixel(1, 17);
                watch_set_pixel(0, 20);
            }
            if ( tails ) {
                watch_clear_pixel(2, 1);
                watch_clear_pixel(0, 0);
            }
            break;
        case 32:
            if ( heads ) {
                watch_clear_pixel(1, 21);
                watch_clear_pixel(2, 21);
            }
            if ( tails ) {
                watch_clear_pixel(2, 10);
                watch_clear_pixel(0, 1);
                watch_set_pixel(0, 2);
                watch_set_pixel(1, 2);
            }
            break;
        case 33:
            if ( heads ) {
                watch_clear_pixel(2, 20);
                watch_clear_pixel(0, 21);
            }
            if ( tails ) {
                watch_set_pixel(2, 2);
                watch_set_pixel(0, 3);
            }
            break;
        case 34:
            if ( heads ) {
                watch_set_pixel(0, 19);
                watch_set_pixel(2, 19);
                watch_clear_pixel(1, 17);
                watch_clear_pixel(0, 20);
            }
            if ( tails ) {
                watch_set_pixel(2, 3);
                watch_set_pixel(0, 4);
            }
            break;
        case 35:
            if ( heads ) {
                watch_set_pixel(1, 18);
            }
            if ( tails ) {
                watch_clear_pixel(1, 2);
                watch_clear_pixel(0, 2);
            }
            break;
        case 36:
            if ( heads ) {
                watch_set_pixel(0, 18);
                watch_set_pixel(2, 18);
            }
            if ( tails ) {
                watch_clear_pixel(2, 2);
                watch_clear_pixel(0, 3);
            }
            break;
        case 37:
            if ( heads ) {
                watch_clear_pixel(0, 19);
                watch_clear_pixel(2, 19);
            }
            if ( tails ) {
                watch_clear_pixel(2, 3);
                watch_clear_pixel(0, 4);
                watch_set_pixel(1, 4);
                watch_set_pixel(0, 5);
            }
            break;
        case 38:
            if ( heads ) {
                watch_clear_pixel(1, 18);
            }
            if ( tails ) {
                watch_set_pixel(2, 4);
                watch_set_pixel(0, 6);
            }
            break;
        case 39:
            if ( heads ) {
                watch_clear_pixel(0, 18);
                watch_clear_pixel(2, 18);
            }
            if ( tails ) {
                watch_set_pixel(1, 6);
                watch_set_pixel(2, 5);
            }
            state->animate = false;
            state->animation = 0;
            movement_request_tick_frequency(1);
    }
}

// DICE FUNCTIONS /////////////////////////////////////////////////////////////

/** @brief rolls a dice
 */
uint8_t roll_dice(uint8_t sides) {
    uint8_t bits_needed = 0;
    uint8_t temp_sides = sides - 1;
    uint8_t result = 0;
    while (temp_sides > 0) {
        bits_needed++; // how many bits do we need to represent this number?
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

/** @brief roll multiple dice and print a char array for displaying them
 */
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

/** @brief dice animation
 */
static void _dice_animation(toss_up_state_t *state) {
    watch_display_string("      ", 4);
    for (uint8_t i = 0; i < state->dice_num; i++) {
        watch_display_string("0",i*2 + 5);
    }
    movement_request_tick_frequency(16);
    switch ( state->animation ) {
        case 0:
            watch_clear_pixel(1, 17);
            watch_clear_pixel(0, 0);
            watch_clear_pixel(1, 6);
            break;
        case 1:
            watch_clear_pixel(2, 20);
            watch_clear_pixel(1, 0);
            watch_clear_pixel(0, 6);
            break;
        case 2:
            watch_clear_pixel(2, 21);
            watch_clear_pixel(2, 0);
            watch_clear_pixel(0, 5);
            break;
        case 3:
            watch_clear_pixel(1, 21);
            watch_clear_pixel(2, 1);
            watch_clear_pixel(1, 4);
            break;
        case 4:
            watch_clear_pixel(0, 21);
            watch_clear_pixel(2, 10);
            watch_clear_pixel(2, 4);
            break;
        case 5:
            watch_clear_pixel(0, 20);
            watch_clear_pixel(0, 1);
            watch_clear_pixel(2, 5);
            break;
        case 6:
            watch_clear_pixel(1, 17);
            watch_clear_pixel(0, 0);
            watch_clear_pixel(1, 6);
            break;
        case 7:
            watch_clear_pixel(2, 20);
            watch_clear_pixel(1, 0);
            watch_clear_pixel(0, 6);
            break;
        case 8:
            watch_clear_pixel(2, 21);
            watch_clear_pixel(2, 0);
            watch_clear_pixel(0, 5);
            break;
        case 9:
            watch_clear_pixel(1, 21);
            watch_clear_pixel(2, 1);
            watch_clear_pixel(1, 4);
            break;
        case 10:
            watch_clear_pixel(0, 21);
            watch_clear_pixel(2, 10);
            watch_clear_pixel(2, 4);
            break;
        case 11:
            watch_clear_pixel(0, 20);
            watch_clear_pixel(0, 1);
            watch_clear_pixel(2, 5);
            state->animate = false;
            state->animation = 0;
            movement_request_tick_frequency(1);
    }
}