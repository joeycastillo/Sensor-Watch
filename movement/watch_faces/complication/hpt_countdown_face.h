/*
 * MIT License
 *
 * Copyright (c) 2024 <#author_name#>
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

#ifndef HPT_COUNTDOWN_FACE_H_
#define HPT_COUNTDOWN_FACE_H_

#include "movement.h"

/*
 * hpt_countdown_face: A countdown timer implemented using the high-precision timer
 *
 * Counts down up to 29h59m59s. Auto-repeat feature.
 * ALARM: Starts or pauses countdown. In setting mode, increments current digit
 * LIGHT: Short press while timer is reset to enter/exit setting mode. Short press while timer is paused to reset. Long press at any time to toggle auto-repeat
 * MODE: In setting mode, moves between digits.
 * 
 * When auto-repeat mode is enabled, "LAP" is shown on display with the number of repeats triggered in the top right. When reaching target time, countdown will be reset automatically.
 * 
 * When not in auto-repeat mode, display will start counting *up* and show a minus sign until paused and reset.
 */

typedef struct {
    // configured number of hours, up to 29 i guess
    uint8_t set_hours :5;
    // configured number of minutes, up to 59
    uint8_t set_minutes :6;
    // configured number of seconds up to 59
    uint8_t set_seconds :6;

    // 17 bits

    bool auto_repeat :1;
    bool running :1;

    // 19 bits

    /**
     * 0 = not setting anything
     * 1 = seconds-ones
     * 2= seconds-tens
     * 3=minutes-ones
     * 4=minutes-tens
     * 5=hours-ones
     * 6=hours-tens
     * 7=unused
    */
    uint8_t setting_mode :3;
    uint8_t repeat_count :5;
    
    // 27 bits

    uint8_t _padding :5;

    // 32 bits (aligned)

    // the target timestamp we are counting down to
    uint64_t target;

    // while paused, the number of milliseconds (really, 1024hz time ticks) remaining in the countdown
    // signed in case the timer was paused after it has expired.
    int64_t paused_ms_left;
    
    // the ID of this face, for background task management
    uint8_t watch_face_index;

} hpt_countdown_state_t;

void hpt_countdown_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void hpt_countdown_face_activate(movement_settings_t *settings, void *context);
bool hpt_countdown_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void hpt_countdown_face_resign(movement_settings_t *settings, void *context);

#define hpt_countdown_face ((const watch_face_t){ \
    hpt_countdown_face_setup, \
    hpt_countdown_face_activate, \
    hpt_countdown_face_loop, \
    hpt_countdown_face_resign, \
    NULL, \
})

#endif // HPT_COUNTDOWN_FACE_H_

