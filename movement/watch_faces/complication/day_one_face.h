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

#ifndef DAY_ONE_FACE_H_
#define DAY_ONE_FACE_H_

#include "movement.h"

// The Day One face is designed to count the days since or until a given date. It also functions as an
// interface for setting the birth date register, which other watch faces can use for various purposes.

typedef enum {
    PAGE_DISPLAY,
    PAGE_YEAR,
    PAGE_MONTH,
    PAGE_DAY
} day_one_page_t;

typedef struct {
    day_one_page_t current_page;
    uint16_t birth_year;
    uint8_t birth_month;
    uint8_t birth_day;
    bool birthday_changed;
} day_one_state_t;

void day_one_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void day_one_face_activate(movement_settings_t *settings, void *context);
bool day_one_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void day_one_face_resign(movement_settings_t *settings, void *context);

#define day_one_face ((const watch_face_t){ \
    day_one_face_setup, \
    day_one_face_activate, \
    day_one_face_loop, \
    day_one_face_resign, \
    NULL, \
})

#endif // DAY_ONE_FACE_H_
