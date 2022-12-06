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

#ifndef NANOSEC_FACE_H_
#define NANOSEC_FACE_H_

#include "movement.h"

#define nanosec_profile_count 5
typedef union {
    //0 - static hardware correction. 
    //1 - static correction with dithering. 
    //2 - datasheet quadratic correction (universal). 
    //3 - cubic correction conservative (likely universal). 
    //4 - cubic correction finetuned (sample-specific).
    int8_t correction_profile;
    int16_t freq_correction;//Static correction - multiplied by 100
    int16_t center_temperature;//Multiplied by 100, +25.0->+2500
    int16_t quadratic_tempco;//0.034 -> 3400, multiplied by 100000. Stored positive, used as negative.
    int16_t cubic_tempco;//default 0, 0.000136 -> 1360, multiplied by 10000000. Stored positive, used positive.
} nanosec_state_t;

void nanosec_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void nanosec_face_activate(movement_settings_t *settings, void *context);
bool nanosec_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void nanosec_face_resign(movement_settings_t *settings, void *context);
bool nanosec_face_wants_background_task(movement_settings_t *settings, void *context);
void nanosec_internal_write_RTC_correction(int16_t value, int16_t sign);
void nanosec_save(void);
void nanosec_init_profile(void);
void nanosec_next_edit_screen(void);

#define nanosec_face ((const watch_face_t){ \
    nanosec_face_setup, \
    nanosec_face_activate, \
    nanosec_face_loop, \
    nanosec_face_resign, \
    nanosec_face_wants_background_task, \
})

#endif // NANOSEC_FACE_H_

