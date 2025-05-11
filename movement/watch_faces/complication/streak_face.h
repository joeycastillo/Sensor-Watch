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

#ifndef STREAK_FACE_H_
#define STREAK_FACE_H_

#include "movement.h"

/*
 * STREAK:
 * This watchface let's you document a streak of a daily task.
 * It shows your current streak, your best streak and you can adjust your best streak.
 * If you don't do your task for a day, the counter resets to 0 (at 00:00).
 * 
 * USAGE:
 * streak-face (SF): here you can see your current streak in days.
 * - Alarm Short Press: check your task for today (the bell appears)
 * - Alarm Long Press: reset your current streak (best streak stays)
 * - Light Short Press: switch to best-face (BF)
 * - Light Long Press: undo check for today: bell vanishes. 
 *      if you beat your best today and you undo, it best decrements to your last best.
 *      if you reached equal to your best today and you undo, the best stays the same
 * 
 * best-face (BF): here you can see your all-time best 
 * - Light Short Press: switch to streak-face (SF)
 * - Mode Long Press: switch to setting-best-face (SB)
 * 
 * setting-best-face (SB): here you can set your best manually, e.g. if you changed battery or had to reflash your sensor-watch
 * - Alarm Short Press: increment counter by 1
 * - Alarm Long Press: increment counter by 1 but FAST
 * - Light Long Press: reset counter to 0
 * - Mode Long Press: switch back to best-face (BF)
 * 
 */

typedef enum {
    streak_screen,
    best_screen,
    setting_best_screen
} streak_mode_t;

typedef struct {
    uint8_t check:1;
    uint16_t streak:14;
    uint16_t best:14;
    uint16_t setting_best:14;
    uint16_t last_best:14;
    uint32_t last_check;
    uint32_t pre_last_check;
    streak_mode_t mode;
} streak_state_t;

void streak_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void streak_face_activate(movement_settings_t *settings, void *context);
bool streak_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void streak_face_resign(movement_settings_t *settings, void *context);

#define streak_face ((const watch_face_t){ \
    streak_face_setup, \
    streak_face_activate, \
    streak_face_loop, \
    streak_face_resign, \
    NULL, \
})

#endif // STREAK_FACE_H_