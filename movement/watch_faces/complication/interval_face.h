/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger
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

//-----------------------------------------------------------------------------

#ifndef INTERVAL_FACE_H_
#define INTERVAL_FACE_H_

#include "movement.h"

/*
A face for customizable interval timers
*/

#define INTERVAL_TIMERS 9     // no of available customizable timers (be aware: only 4 bits reserved for this value in struct below)

typedef struct {
    uint8_t warmup_minutes;
    uint8_t warmup_seconds;
    uint8_t work_minutes;
    uint8_t work_seconds;
    uint8_t break_minutes;
    uint8_t break_seconds;
    uint8_t cooldown_minutes;
    uint8_t cooldown_seconds;
    uint8_t work_rounds;
    uint8_t full_rounds;
} interval_timer_setting_t;

typedef enum {
    interval_state_intro,
    interval_state_waiting,
    interval_state_setting,
    interval_state_running,
    interval_state_pausing
} interval_timer_state_t;

typedef struct {
    bool is_active;
    uint8_t face_idx;
    uint8_t timer_idx;
    uint8_t timer_running_idx;
    interval_timer_state_t face_state;
    interval_timer_setting_t timer[INTERVAL_TIMERS];
} interval_face_state_t;

void interval_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void interval_face_activate(movement_settings_t *settings, void *context);
bool interval_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void interval_face_resign(movement_settings_t *settings, void *context);

#define interval_face ((const watch_face_t) { \
    interval_face_setup, \
    interval_face_activate, \
    interval_face_loop, \
    interval_face_resign, \
    NULL \
    NULL, \
})

#endif // INTERVAL_FACE_H_
