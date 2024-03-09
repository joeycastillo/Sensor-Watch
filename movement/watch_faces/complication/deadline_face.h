/*
 * MIT License
 *
 * Copyright (c) 2023-2024 Konrad Rieck
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
 * OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DEADLINE_FACE_H_
#define DEADLINE_FACE_H_

#include "movement.h"

/* Modes of face */
typedef enum {
    DEADLINE_FACE_RUNNING = 0,
    DEADLINE_FACE_SETTING
} deadline_mode_t;

/* Number of deadline dates */
#define DEADLINE_FACE_DATES (4)

/* Deadline configuration */
typedef struct {
    deadline_mode_t mode:1;
    uint8_t current_page:3;
    uint8_t current_index:2;
    uint8_t alarm_enabled:1;
    uint8_t tick_freq;
    uint8_t face_idx;
    uint32_t deadlines[DEADLINE_FACE_DATES];
} deadline_state_t;

void deadline_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void deadline_face_activate(movement_settings_t *settings, void *context);
bool deadline_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void deadline_face_resign(movement_settings_t *settings, void *context);
bool deadline_face_wants_background_task(movement_settings_t *settings, void *context);

#define deadline_face ((const watch_face_t){ \
    deadline_face_setup, \
    deadline_face_activate, \
    deadline_face_loop, \
    deadline_face_resign, \
    deadline_face_wants_background_task \
})

#endif                          // DEADLINE_FACE_H_
