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

#ifndef VOLTAGE_FACE_H_
#define VOLTAGE_FACE_H_

/*
 * VOLTAGE face
 *
 * This watch face is very simple and has no controls to speak of. It displays
 * the battery voltage as measured by the SAM L22’s ADC.
 *
 * Note that the Simple Clock watch face includes a low battery warning, so you
 * don’t technically need to this watch face unless you want to track the
 * battery level.
 */

#include "movement.h"

void voltage_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void voltage_face_activate(movement_settings_t *settings, void *context);
bool voltage_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void voltage_face_resign(movement_settings_t *settings, void *context);

#define voltage_face ((const watch_face_t){ \
    voltage_face_setup, \
    voltage_face_activate, \
    voltage_face_loop, \
    voltage_face_resign, \
    NULL, \
})

#endif // VOLTAGE_FACE_H_
