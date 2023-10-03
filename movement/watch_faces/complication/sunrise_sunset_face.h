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

#ifndef SUNRISE_SUNSET_FACE_H_
#define SUNRISE_SUNSET_FACE_H_

/*
 * SUNRISE & SUNSET FACE
 *
 * The Sunrise/Sunset face is designed to display the next sunrise or sunset
 * for a given location. It also functions as an interface for setting the
 * location register, which other watch faces can use for various purposes.
 *
 * Refer to the wiki for usage instructions:
 *  https://www.sensorwatch.net/docs/watchfaces/complication/#sunrisesunset
 */

#include "movement.h"

typedef struct {
    uint8_t sign: 1;    // 0-1
    uint8_t hundreds: 1;    // 0-1, ignored for latitude
    uint8_t tens: 4;        // 0-9 (must wrap at 10)
    uint8_t ones: 4;        // 0-9 (must wrap at 10)
    uint8_t tenths: 4;      // 0-9 (must wrap at 10)
    uint8_t hundredths: 4;  // 0-9 (must wrap at 10)
} sunrise_sunset_lat_lon_settings_t;

typedef struct {
    uint8_t page;
    uint8_t rise_index;
    uint8_t active_digit;
    bool location_changed;
    watch_date_time rise_set_expires;
    sunrise_sunset_lat_lon_settings_t working_latitude;
    sunrise_sunset_lat_lon_settings_t working_longitude;
} sunrise_sunset_state_t;

void sunrise_sunset_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void sunrise_sunset_face_activate(movement_settings_t *settings, void *context);
bool sunrise_sunset_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void sunrise_sunset_face_resign(movement_settings_t *settings, void *context);

#define sunrise_sunset_face ((const watch_face_t){ \
    sunrise_sunset_face_setup, \
    sunrise_sunset_face_activate, \
    sunrise_sunset_face_loop, \
    sunrise_sunset_face_resign, \
    NULL, \
})

#endif // SUNRISE_SUNSET_FACE_H_
