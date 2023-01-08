/*
 * MIT License
 *
 * Copyright (c) 2022 Raymundo Cassani
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

#ifndef TACHYMETER_FACE_H_
#define TACHYMETER_FACE_H_

#include "movement.h"

typedef struct {
    uint8_t thousands: 4;   // 0-9 (must wrap at 10)
    uint8_t hundreds: 4;    // 0-9 (must wrap at 10)
    uint8_t tens: 4;        // 0-9 (must wrap at 10)
    uint8_t ones: 4;        // 0-9 (must wrap at 10)
    uint8_t tenths: 4;      // 0-9 (must wrap at 10)
    uint8_t hundredths: 4;  // 0-9 (must wrap at 10)
} distance_digits_t;

typedef struct {
    bool running;                  // tachymeter status
    bool editing;                  // editing distance
    uint8_t active_digit;          // active digit at editing distance
    uint8_t animation_state;       // running animation state
    watch_date_time start_seconds; // start_seconds
    int8_t start_subsecond;        // start_subsecond count (each count = 250 ms)
    distance_digits_t dist_digits; // distance digitwise
    uint32_t distance;             // distance
    uint32_t total_time;           // total_time = now - start_time (in cs)
    uint32_t total_speed;          // 3600 * 100 * distance / total_time
} tachymeter_state_t;

void tachymeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tachymeter_face_activate(movement_settings_t *settings, void *context);
bool tachymeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tachymeter_face_resign(movement_settings_t *settings, void *context);

#define tachymeter_face ((const watch_face_t){ \
    tachymeter_face_setup, \
    tachymeter_face_activate, \
    tachymeter_face_loop, \
    tachymeter_face_resign, \
    NULL, \
})

#endif // TACHYMETER_FACE_H_

