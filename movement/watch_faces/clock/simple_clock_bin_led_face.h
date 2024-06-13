/*
 * MIT License
 *
 * Copyright (c) 2023 Andreas Nebinger, based on Joey Castillo's simple clock face
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

#ifndef SIIMPLE_CLOCK_BIN_LED_FACE_H_
#define SIIMPLE_CLOCK_BIN_LED_FACE_H_

/*
 * BINARY LED CLOCK FACE
 *
 * A "fork" of the simple clock face, which provides the functionality of showing 
 * the current time by flashing the LED using binary representation.
 *
 * This feature serves as a practical solution to compensate for the admittedly 
 * subpar backlight of the F91w watch and is especially useful if your eyesight
 * is not the best. By pressing and holding the light button long enough, the
 * watch will illuminate the LED to showcase the current time.
 *
 * How to interpret the flashing led:
 * - Firstly, the hour is presented as a binary number, with the lowest bit displayed
 *   first. A short flash signifies 0, while a longer flash represents 1. If you use
 *   the watch in 24h mode, please note that the indicated value may be decreased 
 *   by 12, to keep things simple and short. For example, 22h would be translated
 *   to 10h.
 * - After showing the hour, a lengthier  pause indicates that minutes will be shown 
 *   next.
 * - Similar to the hour representation, minutes are displayed in binary format, 
 *   starting with the lowest bits. A short flash denotes 0, a longer flash 
 *   represents 1.
 */

#include "movement.h"

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;
    uint8_t flashing_state; // bitmap representing the flashing state. Bit 0 = hours showing, bit 1 = minutes showing,
                            // bit 6 = short break between flashing bits, bit 7 = long break between hours and minutes
    uint8_t flashing_value;
    uint8_t ticks;
} simple_clock_bin_led_state_t;

void simple_clock_bin_led_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void simple_clock_bin_led_face_activate(movement_settings_t *settings, void *context);
bool simple_clock_bin_led_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void simple_clock_bin_led_face_resign(movement_settings_t *settings, void *context);
bool simple_clock_bin_led_face_wants_background_task(movement_settings_t *settings, void *context);

#define simple_clock_bin_led_face ((const watch_face_t){ \
    simple_clock_bin_led_face_setup, \
    simple_clock_bin_led_face_activate, \
    simple_clock_bin_led_face_loop, \
    simple_clock_bin_led_face_resign, \
    simple_clock_bin_led_face_wants_background_task, \
})

#endif // SIIMPLE_CLOCK_BIN_LED_FACE_H_

