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

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "filesystem.h"
#include "place_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

// STATIC HELPER FUNCTION DECLARATION /////////////////////////////////////////

// (descriptions in the function definitions below)
static int32_t _convert_decimal_struct_to_int(place_format_decimal_latlon_t val);
static place_format_decimal_latlon_t _convert_decimal_int_to_struct(int32_t val);
static int32_t _convert_dms_struct_to_int(place_format_dms_latlon_t val);
static place_format_dms_latlon_t _convert_dms_int_to_struct(int32_t val);
static int32_t _convert_dms_struct_to_decimal_int( place_format_dms_latlon_t val );
static int32_t _convert_decimal_struct_to_dms_int( place_format_decimal_latlon_t val );
static place_format_olc_t _convert_decimal_ints_to_olc(int32_t lat, int32_t lon);
static place_coordinate_t _convert_olc_to_decimal_coordinate(place_format_olc_t pluscode);
static place_format_geohash_t _convert_decimal_ints_to_geohash(int32_t latitude, int32_t longitude);
static place_coordinate_t _convert_geohash_to_decimal_coordinate(place_format_geohash_t geohash);
static void _place_face_update_latlon_display(movement_event_t event, place_state_t *state);
static void _place_face_update_dms_display(movement_event_t event, place_state_t *state);
static void _place_face_update_code_display(movement_event_t event, place_state_t *state);
static void _place_face_update_display(movement_event_t event, place_state_t *state);
static void _place_face_advance_latlon_digit(place_state_t *state);
static void _place_face_advance_dms_digit(place_state_t *state);
static void _place_face_advance_olc_digit(place_state_t *state);
static void _place_face_advance_digit(place_state_t *state);
static void _data_load_place_from_memory(place_state_t *state);
static void _data_load_place_from_register(place_state_t *state);
static void _data_load_place_from_file(place_state_t *state);
static void _data_save_place_to_memory(place_state_t *state);
static void _data_save_place_to_register(place_state_t *state);
static void _data_save_place_to_file(place_state_t *state);

// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////

/** @brief converts latitude and longitude coordinate into a ten digit Open Location Code
 */
void place_latlon_to_olc(char *pluscode, double latitude, double longitude) {
    place_format_olc_t olc;
    int32_t lat, lon;
    lat = (double)round(latitude * 100000);
    lon = (double)round(latitude * 100000);
    olc = _convert_decimal_ints_to_olc(lat, lon);
    pluscode[0] = olc_alphabet[olc.lat1];
    pluscode[1] = olc_alphabet[olc.lon1];
    pluscode[2] = olc_alphabet[olc.lat2];
    pluscode[3] = olc_alphabet[olc.lon2];
    pluscode[4] = olc_alphabet[olc.lat3];
    pluscode[5] = olc_alphabet[olc.lon3];
    pluscode[6] = olc_alphabet[olc.lat4];
    pluscode[7] = olc_alphabet[olc.lon4];
    pluscode[9] = olc_alphabet[olc.lat5];
    pluscode[10] = olc_alphabet[olc.lon5];
    pluscode[8] = '+';
}

/** @brief converts latitude and longitude coordinate into a ten digit Geohash
 */
void place_latlon_to_geohash(char *hash, double latitude, double longitude) {
    place_format_geohash_t geohash;
    int32_t lat, lon;
    lat = (double)round(latitude * 100000);
    lon = (double)round(latitude * 100000);
    geohash = _convert_decimal_ints_to_geohash(lat, lon);
    hash[0] = geohash_alphabet[geohash.d01];
    hash[1] = geohash_alphabet[geohash.d02];
    hash[2] = geohash_alphabet[geohash.d03];
    hash[3] = geohash_alphabet[geohash.d04];
    hash[4] = geohash_alphabet[geohash.d05];
    hash[5] = geohash_alphabet[geohash.d06];
    hash[6] = geohash_alphabet[geohash.d07];
    hash[7] = geohash_alphabet[geohash.d08];
    hash[9] = geohash_alphabet[geohash.d09];
    hash[10] = geohash_alphabet[geohash.d10];
}

// MOVEMENT WATCH FACE FUNCTIONS //////////////////////////////////////////////

void place_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(place_state_t));
        memset(*context_ptr, 0, sizeof(place_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void place_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    place_state_t *state = (place_state_t *)context;
    if (watch_tick_animation_is_running()) watch_stop_tick_animation();
    // Handle any tasks related to your watch face coming on screen.

#if __EMSCRIPTEN__
    int16_t browser_lat = EM_ASM_INT({
        return lat;
    });
    int16_t browser_lon = EM_ASM_INT({
        return lon;
    });
    if ((watch_get_backup_data(1) == 0) && (browser_lat || browser_lon)) {
        movement_location_t browser_loc;
        browser_loc.bit.latitude = browser_lat;
        browser_loc.bit.longitude = browser_lon;
        watch_store_backup_data(browser_loc.reg, 1);
    }
#endif

    // Pages & Digits Schema of the different Modes

    state->modes[MODE_DECIMAL].max_page = 3;
    state->modes[MODE_DECIMAL].page[0].min_digit = 0;
    state->modes[MODE_DECIMAL].page[0].max_digit = 3;
    state->modes[MODE_DECIMAL].page[1].min_digit = 1;
    state->modes[MODE_DECIMAL].page[1].max_digit = 5;
    state->modes[MODE_DECIMAL].page[2].min_digit = 0;
    state->modes[MODE_DECIMAL].page[2].max_digit = 3;
    state->modes[MODE_DECIMAL].page[3].min_digit = 1;
    state->modes[MODE_DECIMAL].page[3].max_digit = 5;

    state->modes[MODE_DMS].max_page = 3;
    state->modes[MODE_DMS].page[0].min_digit = 0;
    state->modes[MODE_DMS].page[0].max_digit = 3;
    state->modes[MODE_DMS].page[1].min_digit = 0;
    state->modes[MODE_DMS].page[1].max_digit = 3;
    state->modes[MODE_DMS].page[2].min_digit = 0;
    state->modes[MODE_DMS].page[2].max_digit = 3;
    state->modes[MODE_DMS].page[3].min_digit = 0;
    state->modes[MODE_DMS].page[3].max_digit = 3;

    state->modes[MODE_OLC].max_page = 1;
    state->modes[MODE_OLC].page[0].min_digit = 1;
    state->modes[MODE_OLC].page[0].max_digit = 5;
    state->modes[MODE_OLC].page[1].min_digit = 1;
    state->modes[MODE_OLC].page[1].max_digit = 5;

    state->modes[MODE_GEOHASH].max_page = 1;
    state->modes[MODE_GEOHASH].page[0].min_digit = 1;
    state->modes[MODE_GEOHASH].page[0].max_digit = 5;
    state->modes[MODE_GEOHASH].page[1].min_digit = 1;
    state->modes[MODE_GEOHASH].page[1].max_digit = 5;

}

bool place_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    place_state_t *state = (place_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            state->page = 0;
            state->active_digit = 0;
            movement_request_tick_frequency(4);
            _data_load_place_from_memory(state);
            _place_face_update_display(event, context);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            // if entering low energy mode, start tick animation
            if (event.event_type == EVENT_LOW_ENERGY_UPDATE && !watch_tick_animation_is_running()) watch_start_tick_animation(1000);
            // check if we need to update the display
            if ( state->edit || state->digit_info ) {
                // in Edit or Digit Info modes, refresh every tick to show blinking cursors
                _place_face_update_display(event, state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // flips through the different display modes for each place
            // increments active digit when in Edit or Display Info auxiliary modes
            if ( state->edit || state->digit_info )
                state->active_digit++;
            else {
                state->mode = (state->mode + 1) % 4;
                state->page = 0;
            }

            if ( state->mode <= MODE_DMS ) {
                // skip hundreds digit for latitude degrees
                if ( state->page == 0 && state->active_digit == 1 )
                    state->active_digit++;
            }

            // when max amount of digits per mode is reached flip to next page / wrap around
            if ( state->active_digit > state->modes[state->mode].page[state->page].max_digit ) {
                if ( state->page == state->modes[state->mode].max_page ) {
                    state->page = 0;
                    state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                } else {
                    state->page++;
                    state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                }
            }
            // update display
            _place_face_update_display(event, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // toggle Edit auxiliary mode
            state->edit = !state->edit;
            if ( !state->digit_info )
                state->active_digit = state->modes[state->mode].page[state->page].min_digit;

            if ( !state->edit ) { // leaving edit mode saves data in state
                _data_save_place_to_memory(state);
                if ( !state->digit_info )
                    state->active_digit = 0;
                else {
                    if ( state->active_digit < state->modes[state->mode].page[state->page].min_digit )
                        state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                }
            }
            // update display
            _place_face_update_display(event, state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            // In Edit mode increments the selected digit

             if ( state->edit )
                _place_face_advance_digit(state);
            else {
                if ( state->digit_info )
                    state->active_digit++;
                else
                    state->page++;
            }

            // wraps around pages and goes to the next display mode
            if ( state->page > state->modes[state->mode].max_page ) {
                state->page = 0;
            }

            // when max amount of digits per mode is reached flip to next page / wrap around
            if ( state->active_digit > state->modes[state->mode].page[state->page].max_digit ) {
                if ( state->page == state->modes[state->mode].max_page ) {
                    state->page = 0;
                    state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                } else {
                    state->page++;
                    state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                }
            }

            // update display
            _place_face_update_display(event, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            // Toggles Digit Info mode in alphanumerical shortcode display modes
            // Discards changes in Edit mode

            if ( !state->edit ) {

                // toggle Digit Info auxiliary
                if ( state->mode > MODE_DMS )
                    state->digit_info = !state->digit_info;

                // coming out of Digit Info:
                if ( !state->digit_info ) {
                    if ( !state->edit )
                        state->active_digit = 0;
                // going into Digit Info:
                } else
                    if ( !state->edit )
                        state->active_digit = 1;
                    
            } else {
                // discard changes
                state->edit = false;
                _data_load_place_from_memory(state);
            }
            _place_face_update_display(event, state);
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void place_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    place_state_t *state = (place_state_t *)context;
    state->page = 0;
    state->active_digit = 0;

    // handle any cleanup before your watch face goes off-screen.
}

// PRIVATE STATIC FUNCTION DEFINITIONS ////////////////////////////////////////

// CONVERSION FUNCTIONS

// Decimal Latitude & Longitude Format (DD.DDDDD)

// converts decimal LatLon struct to integer
static int32_t _convert_decimal_struct_to_int(place_format_decimal_latlon_t val) {
    int32_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds * 10000000 +
                            val.tens     * 1000000 +
                            val.ones     * 100000 +
                            val.d01      * 10000 +
                            val.d02      * 1000 +
                            val.d03      * 100 +
                            val.d04      * 10 +
                            val.d05      * 1
                        );
    return retval;
}

// converts decimal LatLon struct to integer
static int16_t _convert_decimal_struct_to_int16(place_format_decimal_latlon_t val) {
    if ( val.d05 >=5 && val.d04 < 9 ) val.d04++;
    else if ( val.d04 < 9 ) val.d04--;
    if ( val.d03 >=5 && val.d03 < 9) val.d03++;
    else if ( val.d03 < 9 ) val.d03--;
    if ( val.d03 > 8 && val.d02 < 9) val.d02++;
    else if ( val.d02 < 9 ) val.d02--;
    int16_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds * 10000 +
                            val.tens     * 1000 +
                            val.ones     * 100 +
                            val.d01      * 10 +
                            val.d02      * 1
                        );
    return retval;
}

// convert decimal LatLon integer to struct
static place_format_decimal_latlon_t _convert_decimal_int_to_struct(int32_t val) {
    place_format_decimal_latlon_t retval;

    retval.sign     = val < 0;  val = abs(val);
    retval.d05      = val % 10; val /= 10;
    retval.d04      = val % 10; val /= 10;
    retval.d03      = val % 10; val /= 10;
    retval.d02      = val % 10; val /= 10;
    retval.d01      = val % 10; val /= 10;
    retval.ones     = val % 10; val /= 10;
    retval.tens     = val % 10; val /= 10;
    retval.hundreds = val % 10;

    return retval;
}

// Latitude & Longitude in Degrees, Minutes, Seconds (DD° MM' SS")

static int32_t _convert_dms_struct_to_int(place_format_dms_latlon_t val) {
    // converts MODE_DMS LatLon struct to integer
    int32_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds  * 1000000 +
                            val.tens      * 100000 +
                            val.ones      * 10000 +
                            val.mins_tens * 1000 +
                            val.mins_ones * 100 +
                            val.secs_tens * 10 +
                            val.secs_ones * 1
                        );
    return retval;
}

// convert MODE_DMS LatLon integer to struct
static place_format_dms_latlon_t _convert_dms_int_to_struct(int32_t val) {
    place_format_dms_latlon_t retval;

    retval.sign      = val < 0;     val = abs(val);
    retval.secs_ones = val % 10;    val /= 10;
    retval.secs_tens = val % 10;    val /= 10;
    retval.mins_ones = val % 10;    val /= 10;
    retval.mins_tens = val % 10;    val /= 10;
    retval.ones      = val % 10;    val /= 10;
    retval.tens      = val % 10;    val /= 10;
    retval.hundreds  = val % 10;

    return retval;
}

// Conversion between Decimal and MODE_DMS Latitude & Longitude

// convert MODE_DMS LatLon struct to decimal integer
static int32_t _convert_dms_struct_to_decimal_int( place_format_dms_latlon_t val ) {
    double retval = (val.sign ? -1 : 1) *
                        (
                            (double)val.hundreds  * 100 +
                            (double)val.tens      * 10 +
                            (double)val.ones      + 
                            ((double)( val.mins_tens * 10 + val.mins_ones ) / 60) +
                            ((double)( val.secs_tens * 10 + val.secs_ones ) / 3600)
                        );
    return (int32_t) round(retval * 100000);
}

// convert decimal LatLon struct to MODE_DMS integer
static int32_t _convert_decimal_struct_to_dms_int( place_format_decimal_latlon_t val ) {
    place_format_dms_latlon_t dms;
    double coord = (double)abs(_convert_decimal_struct_to_int(val)) / 100000;
    
    // conversion
    int sec = (int)round(coord * 3600);
    int deg = sec / 3600;
    sec = abs(sec % 3600);
    int min = sec / 60;
    sec %= 60;

    // fill the struct
    dms.sign = val.sign;
    if ( deg == 0 ) {
        dms.hundreds = dms.tens = dms.ones = 0;
    } else {
        dms.ones = deg % 10;
        dms.tens = ( deg / 10 ) % 10;
        dms.hundreds = ( deg / 10 ) / 10;
    }
    if ( min == 0 ) {
        dms.mins_tens = dms.mins_ones = 0;
    } else {
        dms.mins_ones = min % 10;
        dms.mins_tens = ( min / 10 ) % 10;
    }
    if ( min == 0 ) {
        dms.secs_tens = dms.secs_ones = 0;
    } else {

        dms.secs_ones = sec % 10;
        dms.secs_tens = ( sec / 10 ) % 10;
    }
    return _convert_dms_struct_to_int(dms);
}

// Conversion between Decimal Latitude & Longitude and Open Location Code

// convert LatLon integer to Open Location Code struct
static place_format_olc_t _convert_decimal_ints_to_olc(int32_t lat, int32_t lon) {
    uint8_t values[10];
    place_format_olc_t retval;
    double latitude = (double)lat / 100000;
    double longitude = (double)lon / 100000;

    // Encode a latitude and longitude into a 10-digit (8+2) plus code.
    // This is a short version of the encoding library that does not support other
    // code lengths. If you need more precision or decode functionality, see
    // https://github.com/google/open-location-code/
    // Code from: https://www.mail-archive.com/open-location-code@googlegroups.com/msg00315.html
    int a = (latitude + 90) * 1e6;
    int b = (longitude + 180) * 1e6;
    for (int8_t i = 9; i > -1; i--) {
        values[i] = b / 125 % 20;
        int d = b;
        b = a;
        a = d / 20;
    }

    // fill struct
    retval.lat1 = values[0];
    retval.lon1 = values[1];
    retval.lat2 = values[2];
    retval.lon2 = values[3];
    retval.lat3 = values[4];
    retval.lon3 = values[5];
    retval.lat4 = values[6];
    retval.lon4 = values[7];
    retval.lat5 = values[8];
    retval.lon5 = values[9];
    return retval;
}

// convert Open Location Code char array to LatLon Coordinate struct
static place_coordinate_t _convert_olc_to_decimal_coordinate(place_format_olc_t pluscode) {
    double lat = 0, lon = 0;
    double deg = 20;
    uint8_t buf[10];
    place_coordinate_t retval;

    // crude struct to array conversion
    buf[0] = pluscode.lat1;
    buf[1] = pluscode.lon1;
    buf[2] = pluscode.lat2;
    buf[3] = pluscode.lon2;
    buf[4] = pluscode.lat3;
    buf[5] = pluscode.lon3;
    buf[6] = pluscode.lat4;
    buf[7] = pluscode.lon4;
    buf[8] = pluscode.lat5;
    buf[9] = pluscode.lon5;

    // conversion based on algorithm description found at:
    // https://www.dcode.fr/open-location-code

    for (int8_t i = 0; i < 10; i++) {
        uint8_t value = buf[i];
        switch ( i % 2 ) {
            case 0:
                lat += value * deg;
                break;
            case 1:
                lon += value * deg;
                deg /= 20;
                break;
        }       
    }

    // fill coordinate struct
    retval.latitude = _convert_decimal_int_to_struct((int32_t)((lat - 90) * 100000));
    retval.longitude = _convert_decimal_int_to_struct((int32_t)((lon - 180) * 100000));
    return retval;
}

// convert LatLon integer to Geohash struct
static place_format_geohash_t _convert_decimal_ints_to_geohash(int32_t latitude, int32_t longitude) {
    uint8_t hash[10] = {0};
    double lat = (double)latitude / 100000;
    double lon = (double)longitude / 100000;

    // C implementation created by Lyo Kato
    // https://github.com/lyokato/libgeohash/
    // Copyright (c) 2011 lyo.kato@gmail.com

    #define SET_BIT(bits, mid, range, value, offset) \
    mid = ((range)->max + (range)->min) / 2.0; \
    if ((value) >= mid) { \
        (range)->min = mid; \
        (bits) |= (0x1 << (offset)); \
    } else { \
        (range)->max = mid; \
        (bits) |= (0x0 << (offset)); \
    }
                        
    uint8_t bits = 0;
    double mid;
    place_format_geohash_interval lat_range = {  90,  -90 };
    place_format_geohash_interval lon_range = { 180, -180 };

    double val1, val2, val_tmp;
    place_format_geohash_interval *range1, *range2, *range_tmp;

    val1 = lon; range1 = &lon_range;
    val2 = lat; range2 = &lat_range;

    for (uint8_t i=0; i < 10; i++) {

        bits = 0;
        SET_BIT(bits, mid, range1, val1, 4);
        SET_BIT(bits, mid, range2, val2, 3);
        SET_BIT(bits, mid, range1, val1, 2);
        SET_BIT(bits, mid, range2, val2, 1);
        SET_BIT(bits, mid, range1, val1, 0);

        hash[i] = bits;

        val_tmp   = val1;
        val1      = val2;
        val2      = val_tmp;
        range_tmp = range1;
        range1    = range2;
        range2    = range_tmp;
    }
    
    // fill struct
    place_format_geohash_t geohash;
    geohash.d01 = hash[0];
    geohash.d02 = hash[1];
    geohash.d03 = hash[2];
    geohash.d04 = hash[3];
    geohash.d05 = hash[4];
    geohash.d06 = hash[5];
    geohash.d07 = hash[6];
    geohash.d08 = hash[7];
    geohash.d09 = hash[8];
    geohash.d10 = hash[9];
    return geohash;
}

// convert Geohash struct to LatLon Coordinate
static place_coordinate_t _convert_geohash_to_decimal_coordinate(place_format_geohash_t geohash) {
    
    uint8_t hash[10];
    hash[0] = geohash.d01;
    hash[1] = geohash.d02;
    hash[2] = geohash.d03;
    hash[3] = geohash.d04;
    hash[4] = geohash.d05;
    hash[5] = geohash.d06;
    hash[6] = geohash.d07;
    hash[7] = geohash.d08;
    hash[8] = geohash.d09;
    hash[9] = geohash.d10;
    
    // C implementation created by Lyo Kato
    // https://github.com/lyokato/libgeohash/
    // Copyright (c) 2011 lyo.kato@gmail.com

    #define REFINE_RANGE(range, bits, offset) \
    if (((bits) & (offset)) == (offset)) \
        (range)->min = ((range)->max + (range)->min) / 2.0; \
    else \
        (range)->max = ((range)->max + (range)->min) / 2.0;

    int8_t bits;
    place_format_geohash_interval *range1, *range2, *range_tmp;

    place_format_geohash_interval lat_range = {  90,  -90 };
    place_format_geohash_interval lon_range = { 180, -180 };

    range1 = &lon_range;
    range2 = &lat_range;

    for (uint8_t i=0; i < 10; i++) {

        bits = hash[i];

        REFINE_RANGE(range1, bits, 0x10);
        REFINE_RANGE(range2, bits, 0x08);
        REFINE_RANGE(range1, bits, 0x04);
        REFINE_RANGE(range2, bits, 0x02);
        REFINE_RANGE(range1, bits, 0x01);

        range_tmp = range1;
        range1    = range2;
        range2    = range_tmp;
    }

    // fill struct
    place_coordinate_t retval;
    retval.latitude = _convert_decimal_int_to_struct(
        (int32_t)round((lat_range.max - ((lat_range.max - lat_range.min) / 2.0)) * 100000)
    );
    retval.longitude = _convert_decimal_int_to_struct(
        (int32_t)round((lon_range.max - ((lon_range.max - lon_range.min) / 2.0)) * 100000)
    );

    return retval;
}

// WATCH DISPLAY FUNCTIONS

// Display Decimal Latitude & Longitude
static void _place_face_update_latlon_display(movement_event_t event, place_state_t *state) {
    char buf[12];
    char lln[9];
    watch_clear_display();

    if ( state->page < 2 )
        sprintf(lln, "%08d", abs( _convert_decimal_struct_to_int(state->working_latitude)));
    else
        sprintf(lln, "%08d", abs( _convert_decimal_struct_to_int(state->working_longitude)));

    switch (state->page) {
        case 0: // Latitude
            sprintf(buf, "LA #%c %c%c  ", state->working_latitude.sign ? '-' : '+', lln[1], lln[2] );
            break;
        case 1:
            sprintf(buf, "LA , %c%c%c%c%c", lln[3], lln[4],lln[5], lln[6],lln[7]);
            break;
        case 2: // Longitude
            sprintf(buf, "LO #%c%c%c%c  ", state->working_longitude.sign ? '-' : '+', lln[0], lln[1], lln[2] );
            break;
        case 3:
            sprintf(buf, "LO , %c%c%c%c%c", lln[3], lln[4],lln[5], lln[6],lln[7]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

// Display Latitude & Longitude in Degrees, Minutes, Seconds
static void _place_face_update_dms_display(movement_event_t event, place_state_t *state) {
    char buf[12];
    char lln[8];
    watch_clear_display();
    if ( state->page < 2 ) 
        sprintf(lln, "%07d", abs( _convert_dms_struct_to_int(state->working_dms_latitude)));
    else
        sprintf(lln, "%07d", abs( _convert_dms_struct_to_int(state->working_dms_longitude)));
    
    switch (state->page) {
        case 0: // Latitude
            sprintf(buf, "LA #%c %c%c  ", state->working_dms_latitude.sign ? 'S' : 'N', lln[1], lln[2] );
            break;
        case 1:
            watch_set_colon();
            sprintf(buf, "LA \"%c%c%c%c  ", lln[3], lln[4], lln[5], lln[6]);
            break;
        case 2: // Longitude
            sprintf(buf, "LO #%c%c%c%c  ", state->working_dms_longitude.sign ? 'W' : 'E', lln[0], lln[1], lln[2] );
            break;
        case 3:
            watch_set_colon();
            sprintf(buf, "LO \"%c%c%c%c  ", lln[3], lln[4], lln[5], lln[6]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

// Display Open Location Code or Geohash
static void _place_face_update_code_display(movement_event_t event, place_state_t *state) {
    bool fix = false;
    char buf[12];
    uint8_t code_array[10];
    char code_string[11] = {0};
    char help[3];

    watch_clear_display();

    uint8_t index = state->active_digit + ( state->page == 0 ? -1 : 4);

    // set up letters
    if ( state->mode == MODE_OLC ) {
        // populate array from struct
        code_array[0] = state->working_pluscode.lat1;
        code_array[1] = state->working_pluscode.lon1;
        code_array[2] = state->working_pluscode.lat2;
        code_array[3] = state->working_pluscode.lon2;
        code_array[4] = state->working_pluscode.lat3;
        code_array[5] = state->working_pluscode.lon3;
        code_array[6] = state->working_pluscode.lat4;
        code_array[7] = state->working_pluscode.lon4;
        code_array[8] = state->working_pluscode.lat5;
        code_array[9] = state->working_pluscode.lon5;

        // get letters from alphabet to display
        for ( uint8_t i = 0; i < 10; i++)
            code_string[i] = olc_alphabet[code_array[i]];
    }

    if ( state->mode == MODE_GEOHASH ) {
        // populate array from struct
        code_array[0] = state->working_geohash.d01;
        code_array[1] = state->working_geohash.d02;
        code_array[2] = state->working_geohash.d03;
        code_array[3] = state->working_geohash.d04;
        code_array[4] = state->working_geohash.d05;
        code_array[5] = state->working_geohash.d06;
        code_array[6] = state->working_geohash.d07;
        code_array[7] = state->working_geohash.d08;
        code_array[8] = state->working_geohash.d09;
        code_array[9] = state->working_geohash.d10;

        // get letters from alphabet to display
        for ( uint8_t i = 0; i < 10; i++)
            code_string[i] = geohash_alphabet[code_array[i]];
    }

    // if Digit Info mode is enabled, show PM for letters and 24H for numbers
    if ( state->digit_info || state->edit ) {
        if ( code_array[index] > 7 )
            watch_set_indicator(WATCH_INDICATOR_PM);
        else
            watch_set_indicator(WATCH_INDICATOR_24H);
    }

    // in Edit mode and Digit Info auxiliary modes
    // display currently selected letter also as alphanumeric digit in digit position 0
    if ( state->active_digit > 0 ) {
        char letter_digit = code_string[index];
            if ( code_array[index] == 27 ) {
                letter_digit = ' ';
                fix = true;
            }
            sprintf(help, "%c ", letter_digit);
    } else {
        sprintf(help, (state->mode == MODE_OLC ? "OL" : "GH"));
    }

    // prepare string
    switch (state->page) {
        case 0: // MODE_OLC Digits 1-5
            sprintf(buf, "%c%c 1 %c%c%c%c%c", help[0], help[1], code_string[0], code_string[1], code_string[2], code_string[3], code_string[4]);
            break;
        case 1: // MODE_OLC Digits 2-10
            sprintf(buf, "%c%c 2 %c%c%c%c%c", help[0], help[1], code_string[5], code_string[6], code_string[7], code_string[8], code_string[9]);
            break;
    }

    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    } else {
        // blink also in Digit Info auxiliary mode
        if (state->digit_info && event.subsecond < 1) {
            buf[state->active_digit + 4] = '-';
        }
    }

    watch_display_string(buf, 0);

    // fix the display for the letter 'V' because it is indistinguishable from 'U'
    if ( fix ) {
        watch_set_pixel(0, 14);
        watch_set_pixel(1, 14);
        watch_set_pixel(1, 13);
    }
}

// manage display formats
static void _place_face_update_display(movement_event_t event, place_state_t *state) {
    switch ( state->mode ) {
        case MODE_DECIMAL:
            _place_face_update_latlon_display(event, state);
            break;
        case MODE_DMS:
            _place_face_update_dms_display(event, state);
            break;
        case MODE_OLC:
        case MODE_GEOHASH:
            _place_face_update_code_display(event, state);
            break;
    }

    // show LAP when Digit Info auxiliary mode is enabled
    if ( state->digit_info)
        watch_set_indicator(WATCH_INDICATOR_LAP);
    else
        watch_clear_indicator(WATCH_INDICATOR_LAP);
}

// DATA EDITOR FUNCTIONS

// Decimal LatLon Editor
static void _place_face_advance_latlon_digit(place_state_t *state) {
    switch (state->page) {
        case 0: // latitude degrees
            switch (state->active_digit) {
                case 0:
                    state->working_latitude.sign++;
                    break;
                case 1:
                    // we skip this digit
                    break;
                case 2:
                    state->working_latitude.tens = (state->working_latitude.tens + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) {
                        // prevent latitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_latitude.ones = 0;
                        state->working_latitude.d01 = 0;
                        state->working_latitude.d02 = 0;
                        state->working_latitude.d03 = 0;
                        state->working_latitude.d04 = 0;
                        state->working_latitude.d05 = 0;
                    }
                    break;
                case 3:
                    state->working_latitude.ones = (state->working_latitude.ones + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.ones = 0;
                    break;
            }
            break;
        case 1: // latitude first five decimal digits
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_latitude.d01 = (state->working_latitude.d01 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d01 = 0;
                    break;
                case 2:
                    state->working_latitude.d02 = (state->working_latitude.d02 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d02 = 0;
                    break;
                case 3:
                    state->working_latitude.d03 = (state->working_latitude.d03 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d03 = 0;
                    break;
                case 4:
                    state->working_latitude.d04 = (state->working_latitude.d04 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d04 = 0;
                    break;
                case 5:
                    state->working_latitude.d05 = (state->working_latitude.d05 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d05 = 0;
                    break;
            }
            break;
        case 2: // longitude degrees
            switch (state->active_digit) {
                case 0:
                    state->working_longitude.sign++;
                    break;
                case 1:
                    state->working_longitude.hundreds = (state->working_longitude.hundreds + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) {
                        // prevent longitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_longitude.tens = 0;
                        state->working_longitude.ones = 0;
                        state->working_longitude.d01 = 0;
                        state->working_longitude.d02 = 0;
                        state->working_longitude.d03 = 0;
                        state->working_longitude.d04 = 0;
                        state->working_longitude.d05 = 0;
                    }
                    break;
                case 2:
                    state->working_longitude.tens = (state->working_longitude.tens + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) {
                        state->working_longitude.tens = 0;

                    }
                    break;
                case 3:
                    state->working_longitude.ones = (state->working_longitude.ones + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.ones = 0;
                    break;
            }
            break;
        case 3: // longitude first five decimal digits
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_longitude.d01 = (state->working_longitude.d01 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d01 = 0;
                    break;
                case 2:
                    state->working_longitude.d02 = (state->working_longitude.d02 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d02 = 0;
                    break;
                case 3:
                    state->working_longitude.d03 = (state->working_longitude.d03 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d03 = 0;
                    break;
                case 4:
                    state->working_longitude.d04 = (state->working_longitude.d04 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d04 = 0;
                    break;
                case 5:
                    state->working_longitude.d05 = (state->working_longitude.d05 + 1) % 10;
                    if (abs(_convert_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d05 = 0;
                    break;
            }
            break;
    }
}

// MODE_DMS LatLon Editor
static void _place_face_advance_dms_digit(place_state_t *state) {
    switch (state->page) {
        case 0: // latitude degrees
            switch (state->active_digit) {
                case 0:
                    state->working_dms_latitude.sign++;
                    break;
                case 1:
                    // we skip this digit
                    break;
                case 2:
                    state->working_dms_latitude.tens = (state->working_dms_latitude.tens + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_latitude)) > 900000) {
                        // prevent latitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_dms_latitude.ones = 0;
                        state->working_dms_latitude.mins_tens = 0;
                        state->working_dms_latitude.mins_ones = 0;
                        state->working_dms_latitude.secs_tens = 0;
                        state->working_dms_latitude.secs_ones = 0;
                    }
                    break;
                case 3:
                    state->working_dms_latitude.ones = (state->working_dms_latitude.ones + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.ones = 0;
                    break;
            }
            break;
        case 1: // latitude first five decimal digits
            switch (state->active_digit) {
                case 0:
                    state->working_dms_latitude.mins_tens = (state->working_dms_latitude.mins_tens + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.mins_tens = 0;
                    break;
                case 1:
                    state->working_dms_latitude.mins_ones = (state->working_dms_latitude.mins_ones + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.mins_ones = 0;
                    break;
                case 2:
                    state->working_dms_latitude.secs_tens = (state->working_dms_latitude.secs_tens + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.secs_tens = 0;
                    break;
                case 3:
                    state->working_dms_latitude.secs_ones = (state->working_dms_latitude.secs_ones + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.secs_ones = 0;
                    break;
            }
            break;
        case 2: // longitude degrees
            switch (state->active_digit) {
                case 0:
                    state->working_dms_longitude.sign++;
                    break;
                case 1:
                    state->working_dms_longitude.hundreds = (state->working_dms_longitude.hundreds + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000) {
                        // prevent longitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_dms_longitude.tens = 0;
                        state->working_dms_longitude.ones = 0;
                        state->working_dms_longitude.mins_tens = 0;
                        state->working_dms_longitude.mins_ones = 0;
                        state->working_dms_longitude.secs_tens = 0;
                        state->working_dms_longitude.secs_ones = 0;
                    } 
                    break;
                case 2:
                    state->working_dms_longitude.tens = (state->working_dms_longitude.tens + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000)
                        state->working_dms_longitude.tens = 0;
                    break;
                case 3:
                    state->working_dms_longitude.ones = (state->working_dms_longitude.ones + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.ones = 0;
                    break;
            }
            break;
        case 3: // longitude first five decimal digits
            switch (state->active_digit) {
                case 0:
                    state->working_dms_longitude.mins_tens = (state->working_dms_longitude.mins_tens + 1) % 6;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.mins_tens = 0;
                    break;
                case 1:
                    state->working_dms_longitude.mins_ones = (state->working_dms_longitude.mins_ones + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.mins_ones = 0;
                    break;
                case 2:
                    state->working_dms_longitude.secs_tens = (state->working_dms_longitude.secs_tens + 1) % 6;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.secs_tens = 0;
                    break;
                case 3:
                    state->working_dms_longitude.secs_ones = (state->working_dms_longitude.secs_ones + 1) % 10;
                    if (abs(_convert_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.secs_ones = 0;
                    break;
            }
            break;
    }
}

// Open Location Code Editor
static void _place_face_advance_olc_digit(place_state_t *state) {
    switch (state->page) {
        case 0: // digits 1 - 5
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_pluscode.lat1 = (state->working_pluscode.lat1 + 1) % 20;
                    break;
                case 2:
                    state->working_pluscode.lon1 = (state->working_pluscode.lon1 + 1) % 20;
                    break;
                case 3:
                    state->working_pluscode.lat2 = (state->working_pluscode.lat2 + 1) % 20;
                    break;
                case 4:
                    state->working_pluscode.lon2 = (state->working_pluscode.lon2 + 1) % 20;
                    break;
                case 5:
                    state->working_pluscode.lat3 = (state->working_pluscode.lat3 + 1) % 20;
                    break;
            }
            break;
        case 1: // digits 6 - 10
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_pluscode.lon3 = (state->working_pluscode.lon3 + 1) % 20;
                    break;
                case 2:
                    state->working_pluscode.lat4 = (state->working_pluscode.lat4 + 1) % 20;
                    break;
                case 3:
                    state->working_pluscode.lon4 = (state->working_pluscode.lon4 + 1) % 20;
                    break;
                case 4:
                    state->working_pluscode.lat5 = (state->working_pluscode.lat5 + 1) % 20;
                    break;
                case 5:
                    state->working_pluscode.lon5 = (state->working_pluscode.lon5 + 1) % 20;
                    break;
            }
            break;
    }
}

// Geohash Editor
static void _place_face_advance_geohash_digit(place_state_t *state) {
    switch (state->page) {
        case 0: // digits 1 - 5
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_geohash.d01 = (state->working_geohash.d01 + 1) % 32;
                    break;
                case 2:
                    state->working_geohash.d02 = (state->working_geohash.d02 + 1) % 32;
                    break;
                case 3:
                    state->working_geohash.d03 = (state->working_geohash.d03 + 1) % 32;
                    break;
                case 4:
                    state->working_geohash.d04 = (state->working_geohash.d04 + 1) % 32;
                    break;
                case 5:
                    state->working_geohash.d05 = (state->working_geohash.d05 + 1) % 32;
                    break;
            }
            break;
        case 1: // digits 6 - 10
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_geohash.d06 = (state->working_geohash.d06 + 1) % 32;
                    break;
                case 2:
                    state->working_geohash.d07 = (state->working_geohash.d07 + 1) % 32;
                    break;
                case 3:
                    state->working_geohash.d08 = (state->working_geohash.d08 + 1) % 32;
                    break;
                case 4:
                    state->working_geohash.d09 = (state->working_geohash.d09 + 1) % 32;
                    break;
                case 5:
                    state->working_geohash.d10 = (state->working_geohash.d10 + 1) % 32;
                    break;
            }
            break;
    }
}

// Editor Manager
static void _place_face_advance_digit(place_state_t *state) {
    switch ( state->mode ) {
        case MODE_DECIMAL:
            _place_face_advance_latlon_digit(state);
            break;
        case MODE_DMS:
            _place_face_advance_dms_digit(state);
            break;
        case MODE_OLC:
            _place_face_advance_olc_digit(state);
            break;
        case MODE_GEOHASH:
            _place_face_advance_geohash_digit(state);
            break;
    }
}

// DATA MANAGEMENT FUNCTIONS

// load place from state array and populate working structs
static void _data_load_place_from_memory(place_state_t *state) {
    _data_load_place_from_file(state);
    state->working_dms_latitude = _convert_dms_int_to_struct(_convert_decimal_struct_to_dms_int(state->working_latitude));
    state->working_dms_longitude = _convert_dms_int_to_struct(_convert_decimal_struct_to_dms_int(state->working_longitude));
    state->working_pluscode = _convert_decimal_ints_to_olc(_convert_decimal_struct_to_int(state->working_latitude), _convert_decimal_struct_to_int(state->working_longitude));
    state->working_geohash = _convert_decimal_ints_to_geohash(_convert_decimal_struct_to_int(state->working_latitude), _convert_decimal_struct_to_int(state->working_longitude));
}

// saves last edited place coordinate/code converted into decimal LatLon into state array
static void _data_save_place_to_memory(place_state_t *state) {
    switch ( state->mode ) {
        case MODE_DMS:
            state->working_latitude  = _convert_decimal_int_to_struct(_convert_dms_struct_to_decimal_int(state->working_dms_latitude));
            state->working_longitude = _convert_decimal_int_to_struct(_convert_dms_struct_to_decimal_int(state->working_dms_longitude));
            break;
        case MODE_OLC:
            state->working_latitude  = _convert_olc_to_decimal_coordinate(state->working_pluscode).latitude;
            state->working_longitude = _convert_olc_to_decimal_coordinate(state->working_pluscode).longitude;
            break;
        case MODE_GEOHASH:
            state->working_latitude  = _convert_geohash_to_decimal_coordinate(state->working_geohash).latitude;
            state->working_longitude = _convert_geohash_to_decimal_coordinate(state->working_geohash).longitude;
            break;
    }
    // save to file & register
    _data_save_place_to_file(state);
    _data_save_place_to_register(state);
    // reload working structs
    _data_load_place_from_memory(state);
}

// load coordinate from location register into selected place slot
static void _data_load_place_from_register(place_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->working_latitude = _convert_decimal_int_to_struct(movement_location.bit.latitude * 1000);
    state->working_longitude = _convert_decimal_int_to_struct(movement_location.bit.longitude * 1000);
    delay_ms(100);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

// save coordinate to location register from selected place slot (truncated to 2 decimal points)
static void _data_save_place_to_register(place_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    movement_location_t movement_location;
    int16_t lat = _convert_decimal_struct_to_int16(state->working_latitude);
    int16_t lon = _convert_decimal_struct_to_int16(state->working_longitude);
    movement_location.bit.latitude = lat;
    movement_location.bit.longitude = lon;
    watch_store_backup_data(movement_location.reg, 1);
    delay_ms(100);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

// load coordinate from LFS file into selected place slot
static void _data_load_place_from_file(place_state_t *state) {
    coordinate_t place;
    if (filesystem_file_exists("place.loc"))
        if (filesystem_read_file("place.loc", (char*)&place, sizeof(place))) {
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            state->working_latitude = _convert_decimal_int_to_struct(place.latitude);
            state->working_longitude = _convert_decimal_int_to_struct(place.longitude);
            delay_ms(100);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        } else {
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            watch_set_indicator(WATCH_INDICATOR_BELL);
            _data_load_place_from_register(state);
    } else {
        watch_set_indicator(WATCH_INDICATOR_BELL);
        _data_load_place_from_register(state);
        delay_ms(100);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
}

// save coordinate to LFS file from selected place slot
static void _data_save_place_to_file(place_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    coordinate_t place;
    place.latitude = _convert_decimal_struct_to_int(state->working_latitude);
    place.longitude = _convert_decimal_struct_to_int(state->working_longitude);
    if (filesystem_write_file("place.loc", (char*)&place, sizeof(place))) {
        delay_ms(100);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        delay_ms(100);
        watch_set_indicator(WATCH_INDICATOR_BELL);        
    }
}