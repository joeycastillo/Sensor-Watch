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

#ifndef WAKE_FACE_H_
#define WAKE_FACE_H_

/*
 * WAKE daily alarm face
 *
 * Basic daily alarm clock face. Seems useful if nothing else in the interest
 * of feature parity with the F-91W’s OEM module, 593.
 *
 * Also experiments with caret-free UI: One button cycles hours, the other
 * minutes, so there’s no toggling between display and adjust modes and no
 * cycling the caret through the UI.
 *   º LIGHT advances hour by 1
 *   º LIGHT long press advances hour by 6
 *   º ALARM advances minute by 10
 *   º ALARM long press cycles through signal modes (just one at the moment)
 */

#include "movement.h"

typedef struct {
    uint32_t hour : 5;
    uint32_t minute : 6;
    uint32_t mode : 1;
} wake_face_state_t;

void wake_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void wake_face_activate(movement_settings_t *settings, void *context);
bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void wake_face_resign(movement_settings_t *settings, void *context);
bool wake_face_wants_background_task(movement_settings_t *settings, void *context);

#define wake_face ((const watch_face_t){ \
    wake_face_setup, \
    wake_face_activate, \
    wake_face_loop, \
    wake_face_resign, \
    wake_face_wants_background_task \
})

#endif // WAKE_FACE_H_

