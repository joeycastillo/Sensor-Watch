/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger, based on Wesley Ellis’ countdown face.
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

#ifndef TIMER_FACE_H_
#define TIMER_FACE_H_

/*
 * TIMER face
 * Advanced timer/countdown face with pre-set timer lengths
 * 
 * This watch face provides the functionality of starting a countdown by choosing 
 * one out of nine programmable timer presets. A timer/countdown can be 23 hours,
 * 59 minutes, and 59 seconds max. A timer can also be set to auto-repeat, which
 * is indicated by the lap indicator.
 *
 * How to use in NORMAL mode:
 *   - Short-pressing the alarm button cycles through all pre-set timer lengths.
 *     Find the current timer slot number in the upper right-hand corner.
 *   - Long-pressing the alarm button starts the timer.
 *   - Long-pressing the light button initiates settings mode.
 * 
 * How to use in SETTINGS mode:
 *   - There are up to nine slots for storing a timer setting. The current slot is 
 *     indicated by the number in the upper right-hand corner.
 *   - Short-pressing the light button cycles through the settings values of each
 *     timer slot in the following order: hours - minutes - seconds - timer repeat
 *   - Short-pressing the alarm button alters the current settings value.
 *   - Long-pressing the light button resumes to normal mode.
 * 
 */

#include "movement.h"

#define TIMER_SLOTS 9           // offer 9 timer slots

typedef enum {
    waiting,
    running,
    setting,
    pausing
} timer_mode_t;

typedef union {
    struct {
        uint8_t hours;
        uint8_t minutes;
        uint8_t seconds;
        bool repeat;
    } unit;
    uint32_t value;
} timer_setting_t;

typedef struct {
    uint32_t target_ts;
    uint32_t now_ts;
    uint16_t paused_left;
    uint8_t pausing_seconds;
    uint8_t watch_face_index;
    timer_setting_t timers[TIMER_SLOTS]; 
    uint8_t settings_state : 4;
    uint8_t current_timer : 4;
    uint8_t set_timers : 4;
    bool erase_timer_flag : 1;
    timer_mode_t mode : 3;
    bool quick_cycle : 1;
} timer_state_t;

void timer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void timer_face_activate(movement_settings_t *settings, void *context);
bool timer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void timer_face_resign(movement_settings_t *settings, void *context);

#define timer_face ((const watch_face_t){ \
    timer_face_setup, \
    timer_face_activate, \
    timer_face_loop, \
    timer_face_resign, \
    NULL, \
})


#endif // TIMER_FACE_H_
