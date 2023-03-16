/*
 * MIT License
 *
 * Copyright (c) 2023 <#author_name#>
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

#ifndef PLACES_FACE_H_
#define PLACES_FACE_H_

#include "movement.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

static const char olc_alphabet[] = "23456789CFGHJMPQRUWX";
static const char name_alphabet[] = "_0123456789 AbCdEFGHIJKLMNOPQRSTUVWXYZ";

typedef struct {
    uint8_t sign: 1;        // 0-1
    uint8_t hundreds: 1;    // 0-1, ignored for latitude
    uint8_t tens: 4;        // 0-9 (must wrap at 10)
    uint8_t ones: 4;        // 0-9 (must wrap at 10)
    uint8_t d1: 4;          // 0-9 (must wrap at 10)
    uint8_t d2: 4;          // 0-9 (must wrap at 10)
    uint8_t d3: 4;          // 0-9 (must wrap at 10)
    uint8_t d4: 4;          // 0-9 (must wrap at 10)
    uint8_t d5: 4;          // 0-9 (must wrap at 10)
} places_ll_decimal_t;

typedef struct {
    uint8_t sign: 1;        // 0-1
    uint8_t hundreds: 1;    // 0-1, ignored for latitude
    uint8_t tens: 4;        // 0-9 (must wrap at 10)
    uint8_t ones: 4;        // 0-9 (must wrap at 10)
    uint8_t mins_tens: 3;   // 0-5 (must wrap at 60)
    uint8_t mins_ones: 4;   // 0-9 (must wrap at 10)
    uint8_t secs_tens: 3;   // 0-5 (must wrap at 60)
    uint8_t secs_ones: 4;   // 0-9 (must wrap at 10)
} places_ll_dms_t;

typedef struct {
    uint8_t lat1: 5;
    uint8_t lon1: 5;   
    uint8_t lat2: 5;   
    uint8_t lon2: 5;   
    uint8_t lat3: 5;   
    uint8_t lon3: 5;   
    uint8_t lat4: 5;   
    uint8_t lon4: 5;   
    uint8_t lat5: 5;   
    uint8_t lon5: 5;   
} places_olc_t;

typedef struct {
    uint8_t d1;
    uint8_t d2;
    uint8_t d3;
    uint8_t d4;
    uint8_t d5;
} places_name_t;

typedef struct {
    places_ll_decimal_t latitude;
    places_ll_decimal_t longitude;
    places_name_t name;
} places_ll_coordinate_t;

typedef struct {
    uint8_t mode : 3; // 0: name / 1: ll / 2: dms / 3: olc / 4: mgmt
    uint8_t page : 2; // 0-3
    int8_t active_digit: 4; // -1-5
    bool location_changed;
    bool edit;
    bool dms;
    bool olc;
    places_name_t working_name;
    places_ll_decimal_t working_latitude;
    places_ll_decimal_t working_longitude;
    places_ll_dms_t working_dms_latitude;
    places_ll_dms_t working_dms_longitude;
    places_olc_t working_pluscode;
    places_ll_coordinate_t place[5];
} places_state_t;

// PUBLIC WATCH FACE FUNCTIONS ////////////////////////////////////////////////

void places_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void places_face_activate(movement_settings_t *settings, void *context);
bool places_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void places_face_resign(movement_settings_t *settings, void *context);

#define places_face ((const watch_face_t){ \
    places_face_setup, \
    places_face_activate, \
    places_face_loop, \
    places_face_resign, \
    NULL, \
})

#endif // PLACES_FACE_H_

