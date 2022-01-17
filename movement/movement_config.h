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

#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "simple_clock_face.h"
#include "world_clock_face.h"
#include "preferences_face.h"
#include "set_time_face.h"
#include "pulsometer_face.h"
#include "thermistor_readout_face.h"
#include "thermistor_logging_face.h"
#include "character_set_face.h"
#include "beats_face.h"
#include "day_one_face.h"
#include "voltage_face.h"
#include "stopwatch_face.h"
#include "totp_face.h"
#include "lis2dh_logging_face.h"
#include "demo_face.h"
#include "hello_there_face.h"
#include "sunrise_sunset_face.h"
#include "countdown_face.h"

#define MOVEMENT_NUM_FACES 4
watch_face_t watch_faces[MOVEMENT_NUM_FACES];

__attribute__((constructor)) 
static void initialize_watch_faces(void) {
    watch_faces[0] = simple_clock_face;
    watch_faces[1] = preferences_face;
    watch_faces[2] = set_time_face;
    watch_faces[3] = totp_face;
}

#endif // MOVEMENT_CONFIG_H_
