/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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

#ifndef DUAL_TIMER_FACE_H_
#define DUAL_TIMER_FACE_H_

/*
 * DUAL TIMER
 * ==========
 * 
 * Inspired by special ops and tactical trope targeted watches like the Nixon Regulus
 * that feature two chronographs for timing two simultaneous events, here is a watch
 * face that expands upon Andreas Nebinger's Stock Stopwatch Face code to implement this 
 * functionality.
 * 
 * ALARM starts/stops timer A, resets on the next start
 * LIGHT starts/stops timer B, resets on the next start
 * 
 * When a timer is running, tapping MODE toggles between displaying timers A or B, as
 * indicated at the top of the display.
 * 
 * The currently selected timer shows minutes, seconds, and 100ths of seconds until the
 * timed event passes the hour mark. Then it shows hours, minutes, and seconds. Once
 * it runs for more than a day it shows days, hours, and minutes. The blinking colon
 * indicates that the timer is running.
 * 
 * The longest time span the timers are able to track as 99 days and 23:59:59:99 hours and
 * they will simply stop.
 * 
 * If the other timer that is not currently selected is also running then a plus sign is
 * blinking next to the A or B indicator. Its progress is indicated by showing the timer's
 * currently highest time unit ( 100ths of seconds if less than a second, seconds if less
 * than a minute, minutes if less than an hour, hours if less than a day, days if more than
 * a day).
 * 
 * Please Note: If at least one timer is running then the default function of the MODE
 * button to move to the next watch face is disabled to be able to use it to toggle between
 * the timers. In this case LONG PRESSING MODE will move to the next face instead of moving
 * back to the default watch face.
 *
 * IMPORTANT: This watch face uses the same TC2 callback counter as the Stock Stopwatch
 * watch-face. It works through calling a global handler function. The two watch-faces
 * therefore can't coexist within the same firmware. If you want to compile this watch-face
 * then you need to remove the line <../watch_faces/complication/stock_stopwatch_face.c \>
 * from the Makefile.
 */

#include "movement.h"

typedef struct {
    uint8_t centiseconds : 7;  // 0-59
    uint8_t seconds : 6;  // 0-59
    uint8_t minutes : 6;  // 0-59
    uint8_t hours : 5;    // 0-23
    uint8_t days : 7;    // 0-99
} dual_timer_duration_t;

typedef struct {
    uint32_t start_ticks[2];
    uint32_t stop_ticks[2];
    dual_timer_duration_t duration[2];
    bool running[2];
    bool show;
} dual_timer_state_t;

void dual_timer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void dual_timer_face_activate(movement_settings_t *settings, void *context);
bool dual_timer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void dual_timer_face_resign(movement_settings_t *settings, void *context);

#if __EMSCRIPTEN__
void em_dual_timer_cb_handler(void *userData);
#else
void TC2_Handler(void);
#endif

#define dual_timer_face ((const watch_face_t){ \
    dual_timer_face_setup, \
    dual_timer_face_activate, \
    dual_timer_face_loop, \
    dual_timer_face_resign, \
    NULL, \
})

#endif // DUAL_TIMER_FACE_H_

