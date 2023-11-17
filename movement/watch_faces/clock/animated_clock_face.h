/*
 * MIT License
 *
 * Copyright (c) 2023 Konrad Rieck
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

#ifndef ANIMATED_CLOCK_FACE_H_
#define ANIMATED_CLOCK_FACE_H_

#include "movement.h"

/* Magic number to trigger screen refresh */
#define REFRESH_FACE (0xffffffff)

/* Size of animation buffer */
#define ANIMATION_BUFFER_SIZE (64)

typedef enum {
    MODE_CLOCK,
    MODE_PREFERENCES,
    MODE_ANIMATION
} display_mode_t;

typedef struct {
    /* Fields from simple clock face */
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;

    /* Basic configuration of animations */
    display_mode_t mode;
    uint8_t preference_page:3;  // perference pages
    uint8_t interval:3;         // interval in minutes; 0 = disabled

    /* Animation */
    uint16_t tick;
    uint8_t animation;
    char buffer[ANIMATION_BUFFER_SIZE];
} animated_clock_state_t;

void animated_clock_face_setup(movement_settings_t *, uint8_t, void **);
void animated_clock_face_activate(movement_settings_t *, void *);
bool animated_clock_face_loop(movement_event_t, movement_settings_t *, void *);
void animated_clock_face_resign(movement_settings_t *, void *);
bool animated_clock_face_wants_background_task(movement_settings_t *, void *);

#define animated_clock_face ((const watch_face_t){ \
    animated_clock_face_setup, \
    animated_clock_face_activate, \
    animated_clock_face_loop, \
    animated_clock_face_resign, \
    animated_clock_face_wants_background_task, \
})

#endif                          // ANIMATED_CLOCK_FACE_H_
