/*
 * MIT License
 *
 * Copyright (c) 2023 Þorsteinn Jón Gautason
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

#ifndef DISCGOLF_FACE_H_
#define DISCGOLF_FACE_H_

/*
 * DISC GOLF face
 *
 * Keep track of scores in discgolf or golf!
 * The watch face operates in three different modes:
 *
 *  - dg_setting: Select a course
 *      Enter this mode by holding down the light button. The screen will display
 *      the label for the hole and the lowest score since last boot.
 *      Press alarm to loop through the holes. Press the light button to make a
 *      selection. This will reset all scores and start a new game in dg_idle mode.
 *
 *  -dg_idle: We're playing a hole
 *      This either shows your current score relative to par, or the score for a
 *      particular hole.
 *      At the start of a game, press alarm to loop through the holes and leave it
 *      your starting hole. For optimal experience, play the course linearly after that
 *      If you're viewing the hole you're supposed to be playing, the watch face will
 *      display your score relative to par.
 *      Use the alarm button to view other holes than the one you're playing, in which
 *      case the input score for that hole will be displayed, in case it needs changing.
 *      Long press the alarm button to snap back to currently playing hole.
 *      To input scores for a hole in this mode, press the light button.
 *
 *  -dg_scoring: Input score for a hole
 *      In this mode, if the score is 0 (hasn't been entered during this round),
 *      it will blink, indicating we're in scoring mode. Press the alarm button
 *      to increment the score up until 15, in which case it loops back to 0.
 *      Press the light button to save the score for that hole, advance one hole
 *      if you're not editing an already input score, and returning to idle mode.
 *
 *  When all scores have been entered, the LAP indicator turns on. At that point, if we enter
 *  dg_setting to select a course, the score for that round is evaluated against the current
 *  lowest score for that course, and saved if it is better.
*/

#include "movement.h"
#define courses 11

typedef enum {
  dg_setting,                   // We are selecting a course
  dg_scoring,                   // We are inputting our score
  dg_idle,                      // We have input our score and are playing a hole
} discgolf_mode_t;

typedef struct {
    uint8_t course;             // Index for course selection, from 0
    uint8_t hole;               // Index for current hole, from 1
    uint8_t playing;            // Current hole
    int scores[18];             // Scores for each played hole
    discgolf_mode_t mode;       // Watch face mode
} discgolf_state_t;

void discgolf_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void discgolf_face_activate(movement_settings_t *settings, void *context);
bool discgolf_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void discgolf_face_resign(movement_settings_t *settings, void *context);

#define discgolf_face ((const watch_face_t){ \
    discgolf_face_setup, \
    discgolf_face_activate, \
    discgolf_face_loop, \
    discgolf_face_resign, \
    NULL, \
})

#endif // DISCGOLF_FACE_H_
