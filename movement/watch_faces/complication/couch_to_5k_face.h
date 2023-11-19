/*
 * MIT License
 *
 * Copyright (c) 2023 Ekaitz Zarraga <ekaitz@elenq.tech>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef COUCHTO5K_FACE_H_
#define COUCHTO5K_FACE_H_

#include "movement.h"

/*
 * Couch To 5k;
 *
 *
 * The program is designed to train 3 times a week. Each training is a
 * *session*. Each of the rounds you have in the training is an *exercise*.
 *
 * The training goes like this:
 * 5min warm-up walk -> Run X minutes -> Walk Y minutes -> ... -> Stop
 *
 * The watch face shows it like this: The weekday indicator shows if you need
 * to Warm Up (`WU`), run (`rU`), walk (`WA`) or stop (`--`).
 *
 * The month-day indicator shows the session you are in (from 1 to 27).
 *
 * The timer shows the time you have left in the exercise and the exercise you
 * are doing (MM:SS:ee). When an exercise finishes you are notified with an
 * alarm. When the whole session finishes, a different tone is played for a
 * longer period.
 *
 * Pressing the ALARM button pauses/resumes the clock.
 *
 * Pressing the LIGHT button does nothing if the timer is not paused. When it
 * is paused it clears the current session (it restarts it to the beginning)
 * and if it was already cleared or the current session was finished moves to
 * the next session.
 */

typedef enum {
    C25K_WARMUP,
    C25K_RUN,
    C25K_WALK,
    C25K_FINISHED
} exercise_type_t;

typedef struct {
    // Anything you need to keep track of, put it here!
    uint8_t session;
    uint8_t exercise;
    exercise_type_t exercise_type;
    uint16_t timer;
} couch_to_5k_state_t;

void couch_to_5k_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void couch_to_5k_face_activate(movement_settings_t *settings, void *context);
bool couch_to_5k_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void couch_to_5k_face_resign(movement_settings_t *settings, void *context);

#define couch_to_5k_face ((const watch_face_t){ \
    couch_to_5k_face_setup, \
    couch_to_5k_face_activate, \
    couch_to_5k_face_loop, \
    couch_to_5k_face_resign, \
    NULL, \
})

#endif // COUCHTO5K_FACE_H_

