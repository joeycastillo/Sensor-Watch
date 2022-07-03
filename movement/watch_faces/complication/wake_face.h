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

/*
A wake-up alarm face

In contrast to countdown_face, uses _face_wants_background_task()
(like thermistor_logging_face) so the alarm will get checked
even if the watch has gone into deep sleep
*/


// On-wake modes
// off: 0, signal: 1<<0, led: 1<<1, both: ring | flash
typedef enum {
    wake_face_mode_off,
    wake_face_mode_piezo,
    wake_face_mode_led,
    wake_face_mode_both,
} wake_face_mode_t;

#define WAKE_FACE_MODES (4);

// UI caret
typedef enum {
    wake_face_caret_mode,
    wake_face_caret_hour,
    wake_face_caret_minute,
} wake_face_caret_t;

#define WAKE_FACE_CARET_POSITIONS (3);

typedef struct {
    wake_face_mode_t mode;
    wake_face_caret_t caret;
    uint8_t hour;
    uint8_t minute;
} wake_face_state_t;


void wake_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void wake_face_activate(movement_settings_t *settings, void *context);
bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void wake_face_resign(movement_settings_t *settings, void *context);
bool wake_face_wants_background_task(movement_settings_t *settings, void *context);

#define wake_face ((const watch_face_t){ \
    wake_face_setup, \
    wake_face_activate, \
    wake_face_loop, \
    wake_face_resign, \
    wake_face_wants_background_task, \
})

#endif // WAKE_FACE_H_