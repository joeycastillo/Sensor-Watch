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

#ifndef SET_TIME_FACE_H_
#define SET_TIME_FACE_H_

/*
 * SET TIME face
 *
 * The default method for adjusting Sensor Watch time.
 *
 * The Time Set watch face allows you to set the time on Sensor Watch. Use
 * the LIGHT button to advance through the field you are setting, and the
 * ALARM button to change the value in that field. The fields are, in order:
 * Hour, Minute, Second, Year, Month, Day and Time Zone.
 *
 * For features like World Clock and Sunrise/Sunset to work correctly, you
 * must set the time to your local time, and the time zone to your local time
 * zone. This allows Sensor Watch to correctly offset the time. This also
 * means that when daylight savings time starts or ends, you must update
 * both the time and the time zone on this screen.
 */

#include "movement.h"

void set_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void set_time_face_activate(movement_settings_t *settings, void *context);
bool set_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void set_time_face_resign(movement_settings_t *settings, void *context);

#define set_time_face ((const watch_face_t){ \
    set_time_face_setup, \
    set_time_face_activate, \
    set_time_face_loop, \
    set_time_face_resign, \
    NULL, \
})

#endif // SET_TIME_FACE_H_
