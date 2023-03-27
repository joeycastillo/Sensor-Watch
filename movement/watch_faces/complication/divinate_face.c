/*
 * MIT License
 *
 * Copyright (c) 2023 <#author_name#>
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

static const uint64_t geomantic = 0x4ABF39D25E76C180;
static const uint32_t badua = 0b11111010010010000101000000000000;

static uint32_t _get_true_entropy(void);
static uint8_t _divine_bit();
static nibble_t _geomancy_pick_figure();
static tribble_t _iching_pick_trigram();
static uint8_t _iching_form_hexagram();
uint8_t _roll_dice(uint8_t sides);
static void _divination_token_display(char* output_str, uint8_t code, uint8_t bit_length, char zero_char, char one_char);
static void _geomancy_display(nibble_t code);
static void divinate_face_display(divinate_state_t *state);

static nibble_t _geomancy_pick_figure() {
    uint8_t index = (_divine_bit() << 3) | (_divine_bit() << 2) | (_divine_bit() << 1) | _divine_bit();
    nibble_t figure = {(geomantic >> (4 * (15 - index))) & 0xF};
    return figure;
}

static tribble_t _iching_pick_trigram() {
    uint8_t index = (_divine_bit() << 2) | (_divine_bit() << 1) | _divine_bit();
    tribble_t trigram = {(badua >> (3 * index)) & 0b111};
    return trigram;
}

static uint8_t _iching_form_hexagram() {
    tribble_t inner = _iching_pick_trigram();
    tribble_t outer = _iching_pick_trigram();
    uint8_t hexagram = (inner.bits << 3) | outer.bits;
}

uint8_t _roll_dice(uint8_t sides) {
    uint8_t bits_needed = 0;
    uint8_t temp_sides = sides - 1;
    while (temp_sides > 0) {
        bits_needed++;
        temp_sides >>= 1; // Shift right to check the next bit
    }
    uint8_t result = 0;
    for (int i = 0; i < bits_needed; i++) {
        result <<= 1; // Shift left to make room for the next bit
        result |= _divine_bit(); // Add the next bit to the result
    }
    return result + 1; // Add 1 to convert the range from 0 to sides-1 to 1 to sides
}

static void _divination_token_display(char* output_str, uint8_t code, uint8_t bit_length, char zero_char, char one_char) {
    char str[bit_length+1];
    for (uint8_t i = 0; i < bit_length; i++) {
        if (code & (1 << (bit_length - 1 - i))) {
            str[i] = one_char;
        } else {
            str[i] = zero_char;
        }
    }
    str[bit_length] = '\0';
    printf("bits: %s\n", str);
    strcpy(output_str, str);
}

static void _geomancy_display(nibble_t code) {
    // draw geomantic figures
    watch_display_string("      ", 4);
    watch_set_pixel(1, 18 + (code.bits >> 3 & 1));
    watch_set_pixel(1, 19 - (code.bits >> 3 & 1));
    watch_set_pixel(2, 20 + (code.bits >> 2 & 1));
    watch_set_pixel(0, 21 - (code.bits >> 2 & 1));
    watch_set_pixel(1, 20 - (code.bits >> 2 & 1));
    watch_set_pixel(0, 22 + (code.bits >> 1 & 1));
    watch_set_pixel(1, 23 - (code.bits >> 1 & 1));
    watch_set_pixel(2, 1 + (code.bits & 1));
    watch_set_pixel(0, (code.bits & 1));
}

static uint8_t _divine_bit() {
    uint32_t stalks;
    uint8_t pile = 0;

    // get 32 random bits
    do {
        stalks = _get_true_entropy();
    } while (stalks >= INT32_MAX || stalks <= 0);

    // Divide the stalks into two piles, alternating ends
    for (uint8_t i = 0; i < 16; i++) {
        pile ^= (stalks >> (31 - 2*i)) & 1;
        pile ^= (stalks >> (30 - 2*i)) & 1;
    }
    // Take the XOR of the pile results
    uint8_t result_xor = pile;
    // Output 1 if result_xor is 1, 0 otherwise
    return result_xor;
}

static uint32_t _get_true_entropy(void) {
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

static void divinate_face_display(divinate_state_t *state) {
    char buf[10];
    char token[6];
    uint8_t bits;
    printf("%d\n", state->mode);
    switch ( state->mode ) {
        case 0: // 1 coin
            bits = state->one_coin;
            printf("%s\n", state->binary[0][bits]);
            sprintf(buf, "di1c%s", state->binary[0][bits]);
            break;
        case 1: // 2 coins
            bits = (state->two_coins[0] << 1) | (state->two_coins[1]);
            _divination_token_display(token, bits, 2, '0', '8');
            sprintf(buf, "di2c%s", token);
            break;
        case 2: // 3 coin
            bits = (state->three_coins[0] << 2) | (state->three_coins[1] << 1) | (state->three_coins[2]);
            _divination_token_display(token, bits, 3, '0', '8');
            sprintf(buf, "di3c%s", token);
            break;
        case 3: // 4 coins
            bits = (state->four_coins[0] << 2) |(state->four_coins[1] << 2) | (state->four_coins[2] << 1) | (state->four_coins[3]);
            _divination_token_display(token, bits, 4, '0', '8');
            sprintf(buf, "di4c%s", token);
            break;
        case 4: // dice
            break;
        case 5: // I Ching
            break;
        case 6: // Geomancy
            break;
        default:
            break;
    }
    watch_display_string(buf, 0);
}

void divinate_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(divinate_state_t));
        memset(*context_ptr, 0, sizeof(divinate_state_t));
        divinate_state_t *state = (divinate_state_t *)context_ptr;
        sprintf(state->binary[0][1], "YES   ");
        sprintf(state->binary[0][0], "    NO");
        sprintf(state->binary[1][1], "heads ");
        sprintf(state->binary[1][0], " tails");
        sprintf(state->binary[2][1], "8     ");
        sprintf(state->binary[2][0], "     0");
        
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void divinate_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    divinate_state_t *state = (divinate_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
}

bool divinate_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    divinate_state_t *state = (divinate_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            state->mode = (state->mode + 1) % 7;
            divinate_face_display(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
            divinate_face_display(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            state->setup = !state->setup;
            divinate_face_display(state);
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void divinate_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

