/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger, based on the work of Joey Castillo
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

#ifndef TIME_LEFT_FACE_H_
#define TIME_LEFT_FACE_H_

/*
 * TIME LEFT face
 *
 * The Time Left Face helps you to visualize how far you have proceeded in a certain
 * time span. Much like the Day One Face, you can set your beginning date. In addition
 * to that, you also set your target or destination date. You can then use the face
 * to display your progress in different ways.
 * 
 * Usage:
 * 
 * - Long pressing of the light button starts the settings mode:
 *   - First, you set the beginning date (indicated by a 'b' in the upper right corner).
 *   - Start by setting the year (indicated by the letter 'YR'). Use the alarm button
 *     to cycle the value. Short pressing the light button brings you to the next
 *     settings page.
 *   - Set the values in this order:
 *     a. beginning date (indicated by a 'b'): year - month - day
 *     b. destination date (indicated by a 'd'): year - month - day
 *   - After cycling through all settings pages, the face resumes to display mode.
 * 
 * - In display mode, use the alarm button (short press) to cycle through these four
 *   types of display:
 *   a. number of days left ('DL') until the destination date is reached.
 *   b. remaining days expressed as percentage of total time span. The value is shown
 *      with two decimals, using the colon as decimal point.
 *   c. number of days passed ('DA') since the beginning date.
 *   d. number of days passed expressed as percentage of total time span. (Two decimal
 *      points.)
 *
 * What is this for?
 *
 * You can use this watch face to be reminded of any kind of progess between a set
 * start and end date. The brave among us can use it as a kind of memento mori
 * visualization. Set your date of birth and look up the average life expectancy of
 * your age cohort based on publicly available mortality tables. Then, set the
 * statistically expected day of death as the target date and you will be able to
 * see how much of your time has passed and how much is still to come.
 * 
 */

#include "movement.h"

typedef struct {
    uint8_t current_page;
    uint16_t current_year;
    movement_birthdate_t birth_date;
    movement_birthdate_t birth_date_when_activated;
    movement_birthdate_t target_date;
} time_left_state_t;

void time_left_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void time_left_face_activate(movement_settings_t *settings, void *context);
bool time_left_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void time_left_face_resign(movement_settings_t *settings, void *context);

#define time_left_face ((const watch_face_t){ \
    time_left_face_setup, \
    time_left_face_activate, \
    time_left_face_loop, \
    time_left_face_resign, \
    NULL, \
})

#endif // TIME_LEFT_FACE_H_
