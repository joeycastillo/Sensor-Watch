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

static const char olc_alphabet[20] = "23456789CFGHJMPQRUWX";
static const char name_alphabet[38] = "_0123456789 AbCdEFGHIJKLMNOPQRSTUVWXYZ";
static const char geohash_alphabet[32] =  "0123456789bCdEfGhjkmnpqrstuVwxyz";

typedef struct {
    uint8_t sign: 1;        // 0-1
    uint8_t hundreds: 1;    // 0-1
    uint8_t tens: 4;        // 0-9
    uint8_t ones: 4;        // 0-9
    uint8_t d01: 4;         // 0-9
    uint8_t d02: 4;         // 0-9
    uint8_t d03: 4;         // 0-9
    uint8_t d04: 4;         // 0-9
    uint8_t d05: 4;         // 0-9
} places_format_decimal_latlon_t;

typedef struct {
    uint8_t sign: 1;        // 0-1
    uint8_t hundreds: 1;    // 0-1
    uint8_t tens: 4;        // 0-9
    uint8_t ones: 4;        // 0-9
    uint8_t mins_tens: 3;   // 0-5
    uint8_t mins_ones: 4;   // 0-9
    uint8_t secs_tens: 3;   // 0-5
    uint8_t secs_ones: 4;   // 0-9
} places_format_dms_latlon_t;

typedef struct {
    uint8_t lat1: 5;        // 2-X
    uint8_t lon1: 5;        // 2-X
    uint8_t lat2: 5;        // 2-X
    uint8_t lon2: 5;        // 2-X
    uint8_t lat3: 5;        // 2-X
    uint8_t lon3: 5;        // 2-X
    uint8_t lat4: 5;        // 2-X
    uint8_t lon4: 5;        // 2-X
    uint8_t lat5: 5;        // 2-X
    uint8_t lon5: 5;        // 2-X
} places_format_olc_t;

typedef struct {
    uint8_t d01: 6;          // 0-z
    uint8_t d02: 6;          // 0-z 
    uint8_t d03: 6;          // 0-z
    uint8_t d04: 6;          // 0-z
    uint8_t d05: 6;          // 0-z
    uint8_t d06: 6;          // 0-z
    uint8_t d07: 6;          // 0-z
    uint8_t d08: 6;          // 0-z
    uint8_t d09: 6;          // 0-z
    uint8_t d10: 6;          // 0-z
} places_format_geohash_t;

typedef struct {
    double high;
    double low;
} places_format_geohash_interval;

typedef struct {
    uint8_t d01;
    uint8_t d02;
    uint8_t d03;
    uint8_t d04;
    uint8_t d05;
} places_name_t;

typedef struct {
    places_format_decimal_latlon_t latitude;
    places_format_decimal_latlon_t longitude;
    places_name_t name;
} places_coordinate_t;

typedef struct {
    uint8_t min_digit : 1;
    uint8_t max_digit : 3;
} places_mode_schema_page_t;

typedef struct {
    uint8_t max_page : 3;
    places_mode_schema_page_t page[4];
} places_mode_schema_mode_t;

enum places_modes_e {
    PLACE = 0,
    DECIMAL,
    DMS,
    OLC,
    GEO,
    DATA
};

typedef struct {
    enum places_modes_e mode;
    uint8_t place: 3;
    uint8_t page : 3;
    int8_t active_digit: 4;
    bool edit;
    bool digit_info;
    places_name_t working_name;
    places_format_decimal_latlon_t working_latitude;
    places_format_decimal_latlon_t working_longitude;
    places_format_dms_latlon_t working_dms_latitude;
    places_format_dms_latlon_t working_dms_longitude;
    places_format_olc_t working_pluscode;
    places_format_geohash_t working_geohash;
    places_coordinate_t places[5];
    bool file;
    bool registry;
    bool write;
    places_mode_schema_mode_t modes[6];
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

