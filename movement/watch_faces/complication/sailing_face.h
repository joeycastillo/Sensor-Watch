/*
 * MIT License
 *
 * Copyright (c) 2023 Jan H. Voigt
 * Copyright (c) 2022 Wesley Ellis
 * Copyright (c) 2022 Niclas Hoyer
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

#ifndef SAILING_FACE_H_
#define SAILING_FACE_H_

/*
 * SAILING face
 * Implements a sailing timer.
 *
 * Usage:
 *
 * Waiting mode:
 * LIGHT button enters settings
 * ALARM button starts the timer (sailing mode).
 *
 * Sailing mode:
 * ALARM button switches to next programmed start signal.
 * Long press on LIGHT button resets timer and enters waiting mode.
 * Countdown to zero, then switch to counting mode.
 *
 * Counting mode:
 * After the start signal (0s), the duration of the race is counted (like a stopwatch timer).
 * ALARM button increases the lap counter, ALARM long press resets lap counter.
 * Long press on LIGHT button resets timer and enters waiting mode.
 *
 * Setting mode:
 * ALARM button increases active (blinking) signal. Goes to 0 if upper boundary
 * (11 or whatever the signal left to the active one is set to) is met.
 * 10 is printed vertically (letter o plus top segment).
 * ALARM button long press resets to default minutes (5-4-1-0).
 * LIGHT button cycles through the signals.
 * Long press on LIGHT button cycles through sound modes:
 * - Bell indicator: Sound at start (0s) only.
 * - Signal indicator: Sound at each programmed signal and at start.
 * - Bell+Signal: Sound at each minute, at 30s and at 10s countdown.
 * - No indicator: No sound.
 */

#include "movement.h"

typedef enum {
    sl_waiting,
    sl_running,
    sl_setting,
    sl_counting
} sailing_mode_t;

typedef struct {
    uint8_t watch_face_index;
    uint32_t target_ts;
    uint32_t now_ts;
    uint32_t nextbeep_ts;
    uint8_t index;
    uint8_t minutes[6];
    uint8_t selection;
    sailing_mode_t mode;
} sailing_state_t;


void sailing_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void sailing_face_activate(movement_settings_t *settings, void *context);
bool sailing_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void sailing_face_resign(movement_settings_t *settings, void *context);

#define sailing_face ((const watch_face_t){ \
    sailing_face_setup, \
    sailing_face_activate, \
    sailing_face_loop, \
    sailing_face_resign, \
    NULL, \
})

#endif // sailing_FACE_H_
