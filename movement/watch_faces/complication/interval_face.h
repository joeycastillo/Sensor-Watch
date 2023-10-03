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

#ifndef INTERVAL_FACE_H_
#define INTERVAL_FACE_H_

/*
 * INTERVAL TIMER face
 *
 * This face brings 9 customizable interval timers to the sensor watch,
 * to be used as hiit training device and/or for time management techniques.
 *
 * - There are 9 interval timer slots, you can cycle through these with the
 *   alarm button (short press). For each timer slot, a short "slideshow"
 *   displaying the relevant details (like length of each phase - see below)
 *   is shown.
 *
 * - To start an interval timer, press and hold the alarm button.
 *
 * - To pause a running timer, press the alarm button (short press).
 *
 * - To completely abort a running timer, press and hold the alarm button.
 *
 * - Press and hold the light button to enter settings mode for each interval
 *   timer slot.
 *
 * - Each interval timer has 1 to 4 phases of customizable length like so:
 *   (1) prepare/warum up --> (2) work --> (3) break --> (4) cool down.
 *   When setting up or running a timer, each of these phases is displayed by
 *   the letters "PR" (prepare), "WO" (work), "BR" (break), "CD" (cool down).
 *
 * - Each of these phases is optional, you can set the corresponding
 *   minutes and seconds to zero. But at least one phase needs to be set, if
 *   you want to use the timer.
 *
 * - You can define the number of rounds either only for the work
 *   phase and/or for the combination of work + break phase. Let's say you
 *   want an interval timer that counts 3 rounds of 30 seconds work, 
 *   followed by 20 seconds rest:
 *         work 30s --> work 30s --> work 30s --> break 20s
 *   You can do this by setting 30s for the "WO"rk phase and setting a 3
 *   in the lower right hand corner of the work page. The "LAP" indicator
 *   lights up at this position, to explain that we are setting laps here.
 *   After that, set the "BR"eak phase to 20s and leave the rest as it is.
 *
 * - If you want to set up a certain number of "full rounds", consisting
 *   of work phase(s) plus breaks, you can do so at the "BR"eak page. The
 *   number in the lower right hand corner determines the number of full
 *   rounds to be counted. A "-" means, that there is no limit and the 
 *   timer keeps alternating between work and break phases.
 *
 * - This watch face comes with several pre-defined interval timers,
 *   suitable for hiit training (timer slots 1 to 4) as well as doing
 *   work according to the pomodoro principle (timer slots 5 to 6).
 *   Feel free to adjust the timer slots to your own needs (or completely 
 *   wipe them ;-)
 */

#include "movement.h"

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
})

#endif // INTERVAL_FACE_H_
