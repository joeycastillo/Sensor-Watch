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

#ifndef WAKE_FACE_H_
#define WAKE_FACE_H_

#include "movement.h"

// Wake modes
typedef enum {
    wake_face_mode_none,
    wake_face_mode_led,
    WAKE_FACE_MODES,
} wake_face_mode_t;

// UI actions
typedef enum {
    wake_face_action_hour_fwd,
    wake_face_action_hour_6h,
    wake_face_action_minute_fwd,
    wake_face_action_mode_fwd,
} wake_face_action_t;

typedef struct {
    uint32_t hour : 5;
    uint32_t minute : 6;
    uint32_t mode : 2;
} wake_face_state_t;

void wake_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void wake_face_activate(movement_settings_t *settings, void *context);
bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void wake_face_resign(movement_settings_t *settings, void *context);
void wake_face_wants_background_task(movement_settings_t *settings, void *context);

#define wake_face ((const watch_face_t){ \
    wake_face_setup, \
    wake_face_activate, \
    wake_face_loop, \
    wake_face_resign, \
    wake_face_wants_background_task \
})

#endif // WAKE_FACE_H_