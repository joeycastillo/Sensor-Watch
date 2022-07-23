/*
 * MIT License
 *
 * Copyright (c) 2022 Josh Berson
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

#ifndef INTERVAL_FACE_H_
#define INTERVAL_FACE_H_

#include "movement.h"

typedef enum {
    INTERVAL_FACE_SPLIT_A,
    INTERVAL_FACE_SPLIT_B,
    INTERVAL_FACE_N_ROUNDS,
    INTERVAL_FACE_SCALE_FACTOR,
    INTERVAL_FACE_ADJUST_STEP,
    INTERVAL_FACE_MODE_OFFSET,
} interval_face_ary_t;

typedef enum {
    INTERVAL_FACE_CARET_NONE,
    INTERVAL_FACE_CARET_SPLIT_A,
    INTERVAL_FACE_CARET_SPLIT_B,
    INTERVAL_FACE_CARET_N_ROUNDS,
    INTERVAL_FACE_CARET_MODULO,
} interval_face_caret_t;

typedef enum {
    INTERVAL_FACE_ACTIVITY_STATE_OFF,
    INTERVAL_FACE_ACTIVITY_STATE_ACTIVE,
    INTERVAL_FACE_ACTIVITY_STATE_PAUSED,
}

typedef struct {
    uint8_t data[INTERVAL_FACE_MODE_OFFSET * 2];
    uint8_t mode;
    uint8_t caret;
    uint8_t status;
    uint8_t rounds_remaining : 7;
    uint8_t current_split : 1;
    uint32_t seconds_remaining;
} interval_face_state_t;

void interval_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void interval_face_activate(movement_settings_t *settings, void *context);
bool interval_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void interval_face_resign(movement_settings_t *settings, void *context);
bool interval_face_wants_background_task(movement_settings_t *settings, void *context);

#define interval_face ((const watch_face_t){ \
    interval_face_setup, \
    interval_face_activate, \
    interval_face_loop, \
    interval_face_resign, \
    interval_face_wants_background_task \
})

#endif // INTERVAL_FACE_H_

