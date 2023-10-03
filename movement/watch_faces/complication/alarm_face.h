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

#ifndef ALARM_FACE_H_
#define ALARM_FACE_H_

/*
 * ALARM face
 *
 * Implements up to 16 alarm slots on the sensor watch
 *
 * Usage:
 *    - In normal mode, the alarm button cycles through all 16 alarms. 
 *    - Pressing the alarm button long in normal mode toggles the corresponding alarm on or off.
 *      (Whereas pressing the alarm button extra long brings you back to alarm no. 1.)
 *    - Pressing the light button enters setting mode and cycles through the settings of each alarm.
 *      (Long pressing the light button enters setting mode without illuminating the led.)
 *    - In setting mode an alarm slot is selected by pressing the alarm button when the slot number 
 *      in the upper right corner is blinking.
 *    - For each alarm slot, you can select the day. These are the day modes:
 *        - ED = the alarm rings every day
 *        - 1t = the alarm fires only one time and is erased afterwards
 *        - MF = the alarm fires Mondays to Fridays
 *        - WN = the alarm fires on weekends (Sa/Su)
 *        - MO to SU = the alarm fires only on the given day of week
 *    - You can fast cycle through hour or minute setting via long press of the alarm button.
 *    - You can select the tone in which the alarm is played. (Three pitch levels available.)
 *    - You can select how many "beep rounds" are played for each alarm. 1 to 9 rounds, plus extra 
 *      long ('L') and extra short ('o') alarms.
 *    - The simple watch face indicates if any alarm is set within the next 24h by showing the signal
 *      indicator.
 */

#include "movement.h"

#define ALARM_ALARMS 16     // no of available alarm slots (be aware: only 4 bits reserved for this value in struct below)
#define ALARM_DAY_STATES 11 // no of different day settings
#define ALARM_DAY_EACH_DAY 7
#define ALARM_DAY_ONE_TIME 8
#define ALARM_DAY_WORKDAY 9
#define ALARM_DAY_WEEKEND 10
#define ALARM_MAX_BEEP_ROUNDS 11 // maximum number of beeping rounds for an alarm slot (including short and long alarms)
#define ALARM_SETTING_STATES 6

typedef struct {
    uint8_t day : 4;    // day of week: 0=MO, 1=TU, 2=WE, 3=TH, 4=FR, 5=SA, 6=SU, 7=each day, 8=one time alarm, 9=Weekdays, 10=Weekend
    uint8_t hour : 5;
    uint8_t minute : 6;
    uint8_t beeps : 4;
    uint8_t pitch :2;
    bool enabled : 1;
} alarm_setting_t;

typedef struct {
    uint8_t alarm_idx : 4;
    uint8_t alarm_playing_idx : 4;
    uint8_t setting_state : 3;
    int8_t alarm_handled_minute;
    bool alarm_quick_ticks : 1;
    bool is_setting : 1;
    alarm_setting_t alarm[ALARM_ALARMS];
} alarm_state_t;


void alarm_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void alarm_face_activate(movement_settings_t *settings, void *context);
bool alarm_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void alarm_face_resign(movement_settings_t *settings, void *context);
bool alarm_face_wants_background_task(movement_settings_t *settings, void *context);

#define alarm_face ((const watch_face_t){ \
    alarm_face_setup, \
    alarm_face_activate, \
    alarm_face_loop, \
    alarm_face_resign, \
    alarm_face_wants_background_task, \
})

#endif // ALARM_FACE_H_
