/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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
 * PLACES FACE
 * ===========
 *
 * Based on and expanded from the Sunrise/Sunset face. Initially just intended to outsource 
 * the location setting functionality to its own face it has become an advanced managing
 * application for location data that also serves as a converter between different coordinate
 * notation formats.
 * 
 * Using the ALARM button the user can flip through 5 available place slots.
 * 
 * With the LIGHT button each place coordinate can be shown and edited in 5 different display modes:
 * 
 * 1. Place Name
 * 2. Decimal Latitude and Longitude (WGS84) up to 5 decimal points
 * 3. Latitude and Longitude (WGS84) in traditional DD°MM'SS" notation
 * 4. Ten digit Open Location Code (aka. PlusCode) format
 * 5. Ten digit Geohash format
 * 
 * (please also refer to the notes on precision below)
 *
 * A LONG PRESS of the LIGHT button toggles editing mode for each of the selected notations.
 * 
 * A LONG PRESS of the ALARM button toggles one of three auxiliary modes (LAP indicator):
 * 
 * 1) DATA import/export when in Place Name mode.
 * 2) DIGIT INFO when Open Location Code or Geohash are selected.
 * 3) REMAIN when any of the Latitude and Longitude modes are selected.
 * 
 * Auxiliary Mode: Data Import and Export
 * ======================================
 * 
 * In this mode ALARM toggles between File and Registry and LIGHT toggles between 'R' for
 * read and 'W' for write.
 * 
 * Coordinates can be read or stored from/to the selected place slot either from the traditional 
 * internal location register or a file on the LFS file system ("place.loc").
 * 
 * The actual read/write operation is triggered by a LONG PRESS of the LIGHT button.
 * LONG PRESS of ALARM leaves this mode without any changes and returns to the Place Name.
 * 
 * Auxiliary Mode: Digit Info
 * ==========================
 * 
 * To work around the limitation of how ambiguously alphanumeric characters are displayed on 
 * the main seven segment digits of the watch face ( S or 5, G or 6?) Digit Info mode can be 
 * activated when in OLC or Geohash mode (shows LAP when toggled).
 * 
 * Now the LIGHT button can be used to flip through the alphaumeric letters. The selected one
 * is now also shown in the much easier to read alphanumeric 8 segment weekday digit above.
 * In addition the '24H' indicator is active when the selected digit represents a number and 
 * the 'PM' indicator for a letter. 
 * 
 * This mode is also automatically activated when editing an OLC or Geohash code.
 * 
 * Auxiliary Mode: Remain
 * ======================
 * 
 * When this mode (LAP) is activated on the decimal or DMS Latitude & Longitude modes the 
 * automatic switching to the next place when pressing ALARM is prevented.
 * 
 * Instead the display remains at the current place and ALARM cycles the available screens
 * for easier recollection of the available coordinate information.
 * 
 * Notes on Coordinate Precision
 * =============================
 * 
 * The common WGS84 Latitude and Longitude degrees naturally do not represent meters in distance 
 * on the ground. 1° Longitude on the equatorial line equals a width of 111.32 kilometers, but 
 * at 40° latitude further North or South it is approximately 85 kilometers wide. The closer to 
 * the poles the narrower (and more precise) the latitude degrees get.
 * 
 * The Sensor Watch's traditional 16bit location register only stores latitudes and longitudes 
 * with two decimal points. That equals a longitudal precision of 36 arc seconds, or ~1111 meters
 * at the equator - precise enough for astronomical calculations, but not if you want to store the 
 * location of let's say a building.
 * 
 * Hence we propose the <place.loc> file that serves the same purpose, but with a precision of 
 * five decimal digits. That equals 0.04 arc seconds or 1.11 meters at the equator.
 * 
 * Please also note that the different notations of this watch face also have varying magnitudes 
 * of precision:
 * 
 * | Format             | Notation               | Precision at Equator | Precision at 67° N/S |
 * | ------------------ | ---------------------- | -------------------- | -------------------- |
 * | 2d. Decimal LatLon | 29.98, 31.13           |           1111.320 m |            435.125 m |
 * | 5d. Decimal LatLon | 29.97916, 31.13417     |              1.111 m |              0.435 m |
 * | DMS LatLon         | N 29°58′45″, E 31°8′3″ |             30.833 m |             12.083 m |
 * | Open Location Code | 7GXHX4HM+MM            |             13.875 m |             13.875 m |
 * | Geohash            | stq4s3x1qu             |              1.189 m |              0.596 m |
 * 
 * Since all notations are internally converted into degrees with 5 decimal points, expect some
 * rounding errors when editing or loading the coordinates in other notation formats.
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
    double max;
    double min;
} places_format_geohash_interval;

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

