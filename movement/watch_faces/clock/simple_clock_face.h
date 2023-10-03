/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef SIMPLE_CLOCK_FACE_H_
#define SIMPLE_CLOCK_FACE_H_

/*
 * SIMPLE CLOCK FACE
 *
 * Displays the current time, matching the original operation of the watch.
 * This is the default display mode in most watch configurations.
 *
 * Long-press ALARM to toggle the hourly chime.
 */

#include "movement.h"

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;
} simple_clock_state_t;

void simple_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void simple_clock_face_activate(movement_settings_t *settings, void *context);
bool simple_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void simple_clock_face_resign(movement_settings_t *settings, void *context);
bool simple_clock_face_wants_background_task(movement_settings_t *settings, void *context);

#define simple_clock_face ((const watch_face_t){ \
    simple_clock_face_setup, \
    simple_clock_face_activate, \
    simple_clock_face_loop, \
    simple_clock_face_resign, \
    simple_clock_face_wants_background_task, \
})

#endif // SIMPLE_CLOCK_FACE_H_
