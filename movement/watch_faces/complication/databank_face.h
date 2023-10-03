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

#ifndef DATABANK_FACE_H_
#define DATABANK_FACE_H_

/*
 * DATABANK face
 *
 * Displays some pre-defined data that you might want to remember
 * Math constants, birthdays, phone numbers...
 *
 * Usage: Edit the global variable `pi_data` in "databank_face.c"
 * to the define the data that will be displayed. Each "item" contains
 * a two-letter label (using the day-of-week display), then a longer
 * string that will be displayed one "word" (six characters) at a time.
 *
 * Short-press ALARM to display the next word.
 * Short-press LIGHT to display the previous word.
 * Long-press ALARM to display the next item.
 * Long-press LIGHT to display the previous item.
 */

#include "movement.h"

void databank_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void databank_face_activate(movement_settings_t *settings, void *context);
bool databank_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void databank_face_resign(movement_settings_t *settings, void *context);

#define databank_face ((const watch_face_t){ \
    databank_face_setup, \
    databank_face_activate, \
    databank_face_loop, \
    databank_face_resign, \
    NULL, \
})

#endif // DATABANK_FACE_H_
