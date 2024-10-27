/*
 * MIT License
 *
 * Copyright (c) 2024 Ruben Nic
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

#ifndef CLOSE_ENOUGH_CLOCK_FACE_H_
#define CLOSE_ENOUGH_CLOCK_FACE_H_

/*
 * CLOSE ENOUGH CLOCK FACE
 *
 * Displays the current time; but only in periods of 5.
 * Just in the in the formats of:
 * - "10 past 5"
 * - "15 to 7"
 * - "6 o'clock"
 *
 */

#include "movement.h"

typedef struct {
    int prev_five_minute_period;
    int prev_min_checked;
    uint8_t last_battery_check;
    bool battery_low;
    bool alarm_enabled;
} close_enough_clock_state_t;

void close_enough_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void close_enough_clock_face_activate(movement_settings_t *settings, void *context);
bool close_enough_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void close_enough_clock_face_resign(movement_settings_t *settings, void *context);

#define close_enough_clock_face ((const watch_face_t){ \
    close_enough_clock_face_setup, \
    close_enough_clock_face_activate, \
    close_enough_clock_face_loop, \
    close_enough_clock_face_resign, \
    NULL, \
})

#endif // CLOSE_ENOUGH_CLOCK_FACE_H_
