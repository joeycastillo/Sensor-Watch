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

#ifndef TEMPCHART_FACE_H_
#define TEMPCHART_FACE_H_

/*
 * TEMPERATURE CHART face
 *
 * Gathers temperature statistics in a chart form.
 * Statistics bins are per hour / per 0.5°C.
 *
 * Saved to file every day at 00:00.
 * Can help improve watch precision in the future. 
 *
 * If you can gather statistics over few months, and then send "tempchart.ini"
 * to "3@14.by", it will help future generations of precision quartz watches.
 */

#include "movement.h"

void tempchart_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tempchart_face_activate(movement_settings_t *settings, void *context);
bool tempchart_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tempchart_face_resign(movement_settings_t *settings, void *context);
bool tempchart_face_wants_background_task(movement_settings_t *settings, void *context);


#define tempchart_face ((const watch_face_t){ \
    tempchart_face_setup, \
    tempchart_face_activate, \
    tempchart_face_loop, \
    tempchart_face_resign, \
    tempchart_face_wants_background_task, \
})

#endif // TEMPCHART_FACE_H_
