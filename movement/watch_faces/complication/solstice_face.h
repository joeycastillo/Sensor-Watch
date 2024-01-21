/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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

#ifndef SOLSTICE_FACE_H_
#define SOLSTICE_FACE_H_

#include "movement.h"

/*
 * A face for telling the dates and times of solstices and equinoxes
 *
 * It shows the upcoming solstice or equinox by default. The upper right number
 * is the year, and the bottom numbers are the date in MMDD format. Use the
 * alarm / light buttons to go forwards / backwards in time. Long press the
 * alarm button to show the time of the event, including what weekday it is on,
 * in your local timezone (DST is not handled).
 *
 * Supports the years 2020 - 2083. The calculations are reasonably accurate for
 * years between 1000 and 3000, but limitations in the sensor watch libraries
 * (which could easily be worked around) prevent making use of that.
 */

typedef struct {
    watch_date_time datetimes[4];
    uint8_t year;
    uint8_t index;
} solstice_state_t;

void solstice_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void solstice_face_activate(movement_settings_t *settings, void *context);
bool solstice_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void solstice_face_resign(movement_settings_t *settings, void *context);

#define solstice_face ((const watch_face_t){ \
    solstice_face_setup, \
    solstice_face_activate, \
    solstice_face_loop, \
    solstice_face_resign, \
    NULL, \
})

#endif // SOLSTICE_FACE_H_

