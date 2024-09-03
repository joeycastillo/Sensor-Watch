/*
 * MIT License
 *
 * Copyright (c) 2024 <David Volovskiy>
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

#ifndef ENDLESS_RUNNER_FACE_H_
#define ENDLESS_RUNNER_FACE_H_

#include "movement.h"

/*
    ENDLESS_RUNNER face

    This is a basic endless-runner, like the [Chrome Dino game](https://en.wikipedia.org/wiki/Dinosaur_Game).
    On the title screen, you can select a difficulty by long-pressing LIGHT or toggle sound by long-pressing ALARM.
    LED or ALARM are used to jump.
    High-score is displayed on the top-right on the title screen. During a game, the current score is displayed.
*/

typedef struct {
    uint16_t hi_score : 10;
    uint8_t difficulty : 3;
    uint8_t month_last_hi_score : 4;
    uint8_t year_last_hi_score : 6;
    uint8_t soundOn : 1;
    /* 24 bits, likely aligned to 32 bits = 4 bytes */
} endless_runner_state_t;

void endless_runner_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void endless_runner_face_activate(movement_settings_t *settings, void *context);
bool endless_runner_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void endless_runner_face_resign(movement_settings_t *settings, void *context);

#define endless_runner_face ((const watch_face_t){ \
    endless_runner_face_setup, \
    endless_runner_face_activate, \
    endless_runner_face_loop, \
    endless_runner_face_resign, \
    NULL, \
})

#endif // ENDLESS_RUNNER_FACE_H_

