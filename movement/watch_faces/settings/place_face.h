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

#ifndef place_FACE_H_
#define place_FACE_H_

#include "movement.h"

/*
 * PLACE FACE
 * ==========
 *
 * Based on and expanded from the Sunrise/Sunset face. Outsourced the location setting functionality to 
 * its own face. Also serves as a converter between different coordinate notation formats.
 * 
 * With the LIGHT button each place coordinate can be shown and edited in 4 different display modes:
 * 
 * 1) Decimal Latitude and Longitude (WGS84) up to 5 decimal points
 * 2) Latitude and Longitude (WGS84) in traditional DD°MM'SS" notation
 * 3) Ten digit Open Location Code (aka. PlusCode) format
 * 4) Ten digit Geohash format
 * 
 * Using the ALARM button the user can flip through 2 pages of coordinate info to see the first and
 * second sets of digits.
 * 
 * (please also refer to the notes on precision below)
 *
 * Editing Mode
 * ============
 * 
 * A LONG PRESS of the LIGHT button toggles editing mode for each of the selected notations.
 * 
 * In this mode LIGHT moves the cursor and ALARM changes the letter cycling through the available
 * alphabet or numbers. 
 * 
 * When OLC or Geohash display are edited, Digit Info mode is activated. It serves as a workaround 
 * for the limitation of how ambiguously alphanumeric characters are displayed on the main seven segment 
 * digits of the watch face ( S or 5, I or 1, U or W?).
 * 
 * The selected letter is also shown in the much easier to read alphanumeric 8 segment weekday digit above.
 * In addition the '24H' indicator is active when the selected digit represents a number and the 'PM' 
 * indicator for a letter. 
 * 
 * A LONG PRESS of LIGHT saves the changes.
 * 
 * Coordinates are read or stored to both the traditional internal location register and a file on 
 * the LFS file system ("place.loc"). By default the Watch Face loads the coordinates from file
 * when activated. If no file is present, the coordinates are loaded from the register.
 * (please also see the notes on precision below)
 * 
 * Auxiliary Mode: Digit Info
 * ==========================
 * 
 * A LONG PRESS of the ALARM button toggles Digit Info mode when OLC or Geohash display is active.
 * (LAP indicator is on) It is a means of being able to see the detailed Digit Info as described above
 * but without the risk of accidentally editing any of digits.
 * 
 * Both ALARM and LIGHT buttons can be used to flip through the letters.
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
} place_format_decimal_latlon_t;

typedef struct {
    uint8_t sign: 1;        // 0-1
    uint8_t hundreds: 1;    // 0-1
    uint8_t tens: 4;        // 0-9
    uint8_t ones: 4;        // 0-9
    uint8_t mins_tens: 3;   // 0-5
    uint8_t mins_ones: 4;   // 0-9
    uint8_t secs_tens: 3;   // 0-5
    uint8_t secs_ones: 4;   // 0-9
} place_format_dms_latlon_t;

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
} place_format_olc_t;

typedef struct {
    int32_t latitude : 25;
    int32_t longitude : 25;
} coordinate_t;

typedef struct {
    place_format_decimal_latlon_t latitude;
    place_format_decimal_latlon_t longitude;
} place_coordinate_t;

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
} place_format_geohash_t;

typedef struct {
    double max;
    double min;
} place_format_geohash_interval;

typedef struct {
    uint8_t min_digit : 1;
    uint8_t max_digit : 3;
} place_mode_schema_page_t;

typedef struct {
    uint8_t max_page : 3;
    place_mode_schema_page_t page[4];
} place_mode_schema_mode_t;

enum place_modes_e {
    MODE_DECIMAL = 0,
    MODE_DMS,
    MODE_OLC,
    MODE_GEOHASH
};

typedef struct {
    enum place_modes_e mode;
    uint8_t page : 3;
    int8_t active_digit: 4;
    bool edit;
    bool digit_info;
    place_format_decimal_latlon_t working_latitude;
    place_format_decimal_latlon_t working_longitude;
    place_format_dms_latlon_t working_dms_latitude;
    place_format_dms_latlon_t working_dms_longitude;
    place_format_olc_t working_pluscode;
    place_format_geohash_t working_geohash;
    place_mode_schema_mode_t modes[4];
} place_state_t;

// PUBLIC WATCH FACE FUNCTIONS ////////////////////////////////////////////////

void place_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void place_face_activate(movement_settings_t *settings, void *context);
bool place_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void place_face_resign(movement_settings_t *settings, void *context);

void place_latlon_to_olc(char *pluscode, double latitude, double longitude);
void place_latlon_to_geohash(char *geohash, double latitude, double longitude);

#define place_face ((const watch_face_t){ \
    place_face_setup, \
    place_face_activate, \
    place_face_loop, \
    place_face_resign, \
    NULL, \
})

#endif // place_FACE_H_

