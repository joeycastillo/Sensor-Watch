/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021-2022 Joey Castillo <joeycastillo@utexas.edu> <jose.castillo@gmail.com>
 * Copyright © 2022 Alexsander Akers <me@a2.io>
 * Copyright © 2022 TheOnePerson <a.nebinger@web.de>
 * Copyright © 2023 Alex Utter <ooterness@gmail.com>
 * Copyright © 2024 Matheus Afonso Martins Moreira <matheus.a.m.moreira@gmail.com>
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

#ifndef CLOCK_FACE_H_
#define CLOCK_FACE_H_

/*
 * CLOCK FACE
 *
 * Displays the current local time, just like the original watch.
 * This is the default display mode in most watch configurations.
 *
 * Long-press ALARM to toggle the hourly chime.
 *
 */

#include "movement.h"

void clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void clock_face_activate(movement_settings_t *settings, void *context);
bool clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void clock_face_resign(movement_settings_t *settings, void *context);
bool clock_face_wants_background_task(movement_settings_t *settings, void *context);

#define clock_face ((const watch_face_t) { \
    clock_face_setup, \
    clock_face_activate, \
    clock_face_loop, \
    clock_face_resign, \
    clock_face_wants_background_task, \
})

#endif // CLOCK_FACE_H_
