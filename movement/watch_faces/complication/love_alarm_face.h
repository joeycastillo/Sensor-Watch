/*
 * MIT License
 *
 * Copyright (c) 2026 Stebbs
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

#ifndef LOVE_ALARM_FACE_H_
#define LOVE_ALARM_FACE_H_

/*
 * LOVE ALARM FACE
 *
 * A romantic alarm that plays a custom melody when it goes off.
 * Set a time and when the alarm triggers, a love animation plays
 * along with the melody from fun.'s "The Gambler".
 *
 * LIGHT button: Enter/cycle through settings (hour, minute)
 * ALARM button: Increment value / toggle enabled when not setting
 * Long press ALARM: Toggle alarm on/off
 */

#include "movement.h"

typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t setting_state;      // 0 = not setting, 1 = hour, 2 = minute
    uint8_t anim_frame;         // Animation frame during alarm
    uint8_t melody_loops;       // How many times melody has played
    int8_t alarm_handled_minute;
    bool enabled;
    bool is_setting;
    bool alarm_playing;
    bool quick_ticks;
} love_alarm_state_t;

void love_alarm_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void love_alarm_face_activate(movement_settings_t *settings, void *context);
bool love_alarm_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void love_alarm_face_resign(movement_settings_t *settings, void *context);
bool love_alarm_face_wants_background_task(movement_settings_t *settings, void *context);

#define love_alarm_face ((const watch_face_t){ \
    love_alarm_face_setup, \
    love_alarm_face_activate, \
    love_alarm_face_loop, \
    love_alarm_face_resign, \
    love_alarm_face_wants_background_task, \
})

#endif // LOVE_ALARM_FACE_H_
