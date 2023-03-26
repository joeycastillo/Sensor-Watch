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

static nibble_t geomancy_pick_figure() {
    uint8_t index = (divine_bit() << 3) | (divine_bit() << 2) | (divine_bit() << 1) | divine_bit();
    nibble_t figure = {(geomantic >> (4 * (15 - index))) & 0xF};
    return figure;
}

static tribble_t iching_pick_trigram() {
    uint8_t index = (divine_bit() << 2) | (divine_bit() << 1) | divine_bit();
    tribble_t trigram = {(badua >> (3 * index)) & 0b111};
    return trigram;
}

static uint8_t iching_form_hexagram() {
    tribble_t inner = iching_pick_trigram();
    tribble_t outer = iching_pick_trigram();
    uint8_t hexagram = (inner.bits << 3) | outer.bits;
}

uint8_t roll_dice(uint8_t sides) {
    uint8_t bits_needed = 0;
    uint8_t temp_sides = sides - 1;
    while (temp_sides > 0) {
        bits_needed++;
        temp_sides >>= 1; // Shift right to check the next bit
    }
    uint8_t result = 0;
    for (int i = 0; i < bits_needed; i++) {
        result <<= 1; // Shift left to make room for the next bit
        result |= divine_bit(); // Add the next bit to the result
    }
    return result + 1; // Add 1 to convert the range from 0 to sides-1 to 1 to sides
}

static void divination_token_display(char* output_str, uint8_t code, uint8_t bit_length, char zero_char, char one_char) {
    char str[bit_length+1];
    for (uint8_t i = 0; i < bit_length; i++) {
        if (code & (1 << (bit_length - 1 - i))) {
            str[i] = one_char;
        } else {
            str[i] = zero_char;
        }
    }
    str[bit_length] = '\0';
    strcpy(output_str, str);
}

static void geomancy_display(nibble_t code) {
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

uint8_t divine_bit() {
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

void divinate_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(divinate_state_t));
        memset(*context_ptr, 0, sizeof(divinate_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
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
        case EVENT_LIGHT_BUTTON_UP:
            // You can use the Light button for your own purposes. Note that by default, Movement will also
            // illuminate the LED in response to EVENT_LIGHT_BUTTON_DOWN; to suppress that behavior, add an
            // empty case for EVENT_LIGHT_BUTTON_DOWN.
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
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

