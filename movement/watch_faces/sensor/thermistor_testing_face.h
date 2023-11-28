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

#ifndef THERMISTOR_TESTING_FACE_H_
#define THERMISTOR_TESTING_FACE_H_

/*
 * THERMISTOR TESTING FACE
 *
 * This watch face is designed for testing temperature sensor boards.
 * It displays temperature readings at a relatively fast rate of 8 Hz,
 * and disables low energy mode so my testing device doesn't sleep.
 * You more than likely want to use thermistor_readout_face instead.
 *
 * Press ALARM to toggle display of metric vs. imperial units.
 */

#include "movement.h"

void thermistor_testing_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void thermistor_testing_face_activate(movement_settings_t *settings, void *context);
bool thermistor_testing_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void thermistor_testing_face_resign(movement_settings_t *settings, void *context);

#define thermistor_testing_face ((const watch_face_t){ \
    thermistor_testing_face_setup, \
    thermistor_testing_face_activate, \
    thermistor_testing_face_loop, \
    thermistor_testing_face_resign, \
    NULL, \
})

#endif // THERMISTOR_TESTING_FACE_H_
