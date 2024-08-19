/*
 * MIT License
 *
 * Copyright (c) 2024 Patrick McGuire, built on wake_face.h by Josh Berson
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

#ifndef BEER_O_CLOCK_FACE_H_
#define BEER_O_CLOCK_FACE_H_

/*
 * BEER_O_CLOCK daily alarm face
 *
 * Basic daily beer alarm clock face.
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
    int8_t ticks;
    bool using;
} beer_o_clock_face_state_t;

void beer_o_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void beer_o_clock_face_activate(movement_settings_t *settings, void *context);
bool beer_o_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void beer_o_clock_face_resign(movement_settings_t *settings, void *context);
bool beer_o_clock_face_wants_background_task(movement_settings_t *settings, void *context);

#define beer_o_clock_face ((const watch_face_t){ \
    beer_o_clock_face_setup, \
    beer_o_clock_face_activate, \
    beer_o_clock_face_loop, \
    beer_o_clock_face_resign, \
    beer_o_clock_face_wants_background_task \
})

#endif // BEER_O_CLOCK_FACE_H_

