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
#include "geomancy_face.h"

static const uint64_t geomantic = 0x4ABF39D25E76C180;
static const uint32_t badua = 0b11111010010010000101000000000000;

static void geomancy_face_display();
static nibble_t _geomancy_pick_figure();
static tribble_t _iching_pick_trigram();
static uint8_t _iching_form_hexagram();
static void _geomancy_display(nibble_t code);
static void _display_hexagram(uint8_t hexagram, char* str);

void geomancy_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(geomancy_state_t));
        memset(*context_ptr, 0, sizeof(geomancy_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void geomancy_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    geomancy_state_t *state = (geomancy_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
}

bool geomancy_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    geomancy_state_t *state = (geomancy_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if ( state->mode <= 1 ) state->mode = 2;
            else if ( state->mode >= 2 ) state->mode = 0;
            geomancy_face_display(state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch ( state->mode ) {
                case 0:
                    state->mode++;
                case 1:
                    state->i_ching_hexagram = _iching_form_hexagram();
                    break;
                case 2:
                    state->mode++;
                case 3:
                    state->geomantic_figure = _geomancy_pick_figure().bits;
                    break;
                default:
                    break;
            }
            geomancy_face_display(state);
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

void geomancy_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

static void geomancy_face_display(geomancy_state_t *state) {
    char buf[11] = {0};
    char token[7] = {0};
    nibble_t figure = *((nibble_t*) &state->geomantic_figure);
    watch_clear_display();
    switch ( state->mode ) {
        case 0:
            sprintf(buf, "gm  iching");
            break;
        case 1:
            _display_hexagram(state->i_ching_hexagram, token);
            watch_display_string(token, 4);
            break;
        case 2:
            sprintf(buf, "gm  geomcy");
            break;
        case 3:
            _geomancy_display(figure);
            break;
        default:
            break;
    }
}

static nibble_t _geomancy_pick_figure() {
    uint8_t index = (divine_bit() << 3) | (divine_bit() << 2) | (divine_bit() << 1) | divine_bit();
    nibble_t figure = {(geomantic >> (4 * (15 - index))) & 0xF};
    return figure;
}

static tribble_t _iching_pick_trigram() {
    uint8_t index = (divine_bit() << 2) | (divine_bit() << 1) | divine_bit();
    tribble_t trigram = {(badua >> (3 * index)) & 0b111};
    return trigram;
}

static uint8_t _iching_form_hexagram() {
    tribble_t inner = _iching_pick_trigram();
    tribble_t outer = _iching_pick_trigram();
    uint8_t hexagram = (inner.bits << 3) | outer.bits;
    return hexagram;
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

static void _display_hexagram(uint8_t hexagram, char* str) {
    str[6] = '\0';  // Null-terminate the string
    for (int i = 0; i < 6; i++) {
        if (hexagram & (1 << (5 - i))) {
            str[i] = '\'';
        } else {
            str[i] = '1';
        }
    }
}