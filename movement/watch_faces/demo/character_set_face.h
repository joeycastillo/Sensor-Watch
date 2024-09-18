/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef CHARACTER_SET_FACE_H_
#define CHARACTER_SET_FACE_H_

/*
 * CHARACTER SET FACE
 *
 * This watch face displays all of the characters in the Sensor Watch character
 * set. You can advance from one character to the next with a short press of the
 * ALARM button.
 *
 * This watch face may be useful to watch face developers, in that it can help
 * them to understand which characters will work in different positions.
 */

#include "movement.h"

void character_set_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void character_set_face_activate(movement_settings_t *settings, void *context);
bool character_set_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void character_set_face_resign(movement_settings_t *settings, void *context);

#define character_set_face ((const watch_face_t){ \
    character_set_face_setup, \
    character_set_face_activate, \
    character_set_face_loop, \
    character_set_face_resign, \
    NULL, \
})

#endif // CHARACTER_SET_FACE_H_
