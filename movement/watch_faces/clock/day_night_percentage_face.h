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

#ifndef DAY_NIGHT_PERCENTAGE_FACE_H_
#define DAY_NIGHT_PERCENTAGE_FACE_H_

#include "movement.h"

/*
 * Day/night percentage face
 *
 * Shows the percentage of the way through the day/night the current time is.
 *
 * The time digits show the percentage of the way through the day/night it is,
 * with decimals in the smaller seconds digits. If the day or night will last
 * for a full 24 hours, the text "Etrnal" is displayed instead of a percentage.
 * The "PM" indicator is set when it is currently nighttime. The weekday and
 * day digits display the weekday and day, as one would expect.
 *
 * This face does not currently offer any configuration. You must set the
 * location register with some other face.
 */

typedef struct {
    int result; // -1, 0, 1: result from sun_rise_set, -2: no location set
    double rise;
    double set;
    double daylen;
} day_night_percentage_state_t;

void day_night_percentage_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void day_night_percentage_face_activate(movement_settings_t *settings, void *context);
bool day_night_percentage_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void day_night_percentage_face_resign(movement_settings_t *settings, void *context);

#define day_night_percentage_face ((const watch_face_t){ \
    day_night_percentage_face_setup, \
    day_night_percentage_face_activate, \
    day_night_percentage_face_loop, \
    day_night_percentage_face_resign, \
    NULL, \
})

#endif // DAY_NIGHT_PERCENTAGE_FACE_H_

