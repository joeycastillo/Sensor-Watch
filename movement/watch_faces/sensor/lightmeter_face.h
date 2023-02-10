/*
 * MIT License
 *
 * Copyright (c) 2023 CC
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

#ifndef LIGHTMETER_FACE_H_
#define LIGHTMETER_FACE_H_

#include "movement.h"
#include "opt3001.h"

typedef struct {
    int asdf;
} lightmeter_state_t;

static const opt3001_Config_t lightmeter_takeNewReading = { 
    .RangeNumber = 0B1100,
    .ConversionTime = 0B1,
	.Latch = 0B1,
	.ModeOfConversionOperation = 0B01
};

static const opt3001_Config_t lightmeter_off = { 
	.ModeOfConversionOperation = 0B00
};

void lightmeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void lightmeter_face_activate(movement_settings_t *settings, void *context);
bool lightmeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void lightmeter_face_resign(movement_settings_t *settings, void *context);

#define lightmeter_face ((const watch_face_t){ \
    lightmeter_face_setup, \
    lightmeter_face_activate, \
    lightmeter_face_loop, \
    lightmeter_face_resign, \
    NULL, \
})

#endif // LIGHTMETER_FACE_H_
