/*
 * MIT License
 *
 * Copyright (c) 2022 <#author_name#>
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

#ifndef FREQUENCY_CORRECTION_FACE_H_
#define FREQUENCY_CORRECTION_FACE_H_

/*
 * FREQUENCY CORRECTION FACE
 *
 * While active, this face generates a square-wave on pin A1 of the 9-pin
 * connector. The output frequency is adjustable from 64 Hz to 0.5 Hz.
 * Long-press ALARM to cycle through available frequencies.
 *
 * This face also displays the value of the watch's frequency-correction
 * register. This setting varies from -127 to +127. Press LIGHT to increment
 * or ALARM to decrement the setting.
 */

#include "movement.h"

typedef struct {
    uint8_t period_event_output;
} frequency_correction_state_t;

void frequency_correction_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void frequency_correction_face_activate(movement_settings_t *settings, void *context);
bool frequency_correction_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void frequency_correction_face_resign(movement_settings_t *settings, void *context);

#define frequency_correction_face ((const watch_face_t){ \
    frequency_correction_face_setup, \
    frequency_correction_face_activate, \
    frequency_correction_face_loop, \
    frequency_correction_face_resign, \
    NULL, \
})

#endif // FREQUENCY_CORRECTION_FACE_H_

