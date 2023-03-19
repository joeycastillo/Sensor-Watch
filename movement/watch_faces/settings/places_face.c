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

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "filesystem.h"
#include "places_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

// Modes
#define PLACE 0
#define DECIMAL 1
#define DMS 2
#define OLC 3
#define GEO 4
#define DATA 5

// STATIC HELPER FUNCTIONS ////////////////////////////////////////////////////

// convert and write Place Name struct to char array
static void _name_struct_to_string(char *buf, places_name_t name);

// converts decimal LatLon struct to integer
static int32_t _ll_decimal_struct_to_int(places_ll_decimal_t val);

// convert decimal LatLon integer to struct
static places_ll_decimal_t _ll_decimal_int_to_struct(int32_t val);

// converts DMS LatLon struct to integer
static int32_t _ll_dms_struct_to_int(places_ll_dms_t val);

// convert DMS LatLon integer to struct
static places_ll_dms_t _ll_dms_int_to_struct(int32_t val);

// convert and write Open Location Code struct to char array
static void _olc_struct_to_array(uint8_t *buf, places_olc_t pluscode);

// convert DMS LatLon struct to decimal integer
static int32_t _ll_dms_struct_to_decimal_int( places_ll_dms_t val );

// convert decimal LatLon struct to DMS integer
static int32_t _ll_decimal_struct_to_dms_int( places_ll_decimal_t val );

// convert LatLon integer to Open Location Code string and write to char array
static places_olc_t _ll_decimal_ints_to_olc(int32_t lat, int32_t lon);

// convert Open Location Code struct to LatLon Coordinate struct
static places_ll_coordinate_t _ll_olc_to_decimal_coordinate(places_olc_t pluscode);

static places_geohash_t _ll_decimal_ints_to_geohash(int32_t latitude, int32_t longitude);
static places_ll_coordinate_t _ll_geohash_to_decimal_coordinate(places_geohash_t geohash);

// Display Place Name
static void _places_face_update_name_display(movement_event_t event, places_state_t *state);

// Display Decimal Latitude & Longitude
static void _places_face_update_latlon_display(movement_event_t event, places_state_t *state);

// Display Latitude & Longitude in Degrees, Minutes, Seconds
static void _places_face_update_dms_display(movement_event_t event, places_state_t *state);

// Display Open Location Code
static void _places_face_update_code_display(movement_event_t event, places_state_t *state);

// manage display formats
static void _places_face_update_display(movement_event_t event, places_state_t *state);

// Place Name Editor
static void _places_face_advance_name_digit(places_state_t *state);

// Decimal LatLon Editor
static void _places_face_advance_latlon_digit(places_state_t *state);

// DMS LatLon Editor
static void _places_face_advance_dms_digit(places_state_t *state);

// Open Location Code Editor
static void _places_face_advance_olc_digit(places_state_t *state);

// Editor Manager
static void _places_face_advance_digit(places_state_t *state);

static void _load_place_from_memory(places_state_t *state);

static void _save_place_to_memory(places_state_t *state);

// DATA MANAGEMENT FUNCTIONS

static void _load_place_from_register(places_state_t *state);

static void _save_place_to_register(places_state_t *state);

static void _load_place_from_file(places_state_t *state);

static void _save_place_to_file(places_state_t *state);

// MOVEMENT WATCH FACE FUNCTIONS //////////////////////////////////////////////

void places_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(places_state_t));
        memset(*context_ptr, 0, sizeof(places_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void places_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    places_state_t *state = (places_state_t *)context;
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

    state->modes[PLACE].max_page = 0;
    state->modes[PLACE].page[0].min_digit = 1;
    state->modes[PLACE].page[0].max_digit = 5;

    state->modes[DECIMAL].max_page = 3;
    state->modes[DECIMAL].page[0].min_digit = 0;
    state->modes[DECIMAL].page[0].max_digit = 3;
    state->modes[DECIMAL].page[1].min_digit = 1;
    state->modes[DECIMAL].page[1].max_digit = 5;
    state->modes[DECIMAL].page[2].min_digit = 0;
    state->modes[DECIMAL].page[2].max_digit = 3;
    state->modes[DECIMAL].page[3].min_digit = 1;
    state->modes[DECIMAL].page[3].max_digit = 5;

    state->modes[DMS].max_page = 3;
    state->modes[DMS].page[0].min_digit = 0;
    state->modes[DMS].page[0].max_digit = 3;
    state->modes[DMS].page[1].min_digit = 0;
    state->modes[DMS].page[1].max_digit = 3;
    state->modes[DMS].page[2].min_digit = 0;
    state->modes[DMS].page[2].max_digit = 3;
    state->modes[DMS].page[3].min_digit = 0;
    state->modes[DMS].page[3].max_digit = 3;

    state->modes[OLC].max_page = 1;
    state->modes[OLC].page[0].min_digit = 1;
    state->modes[OLC].page[0].max_digit = 5;
    state->modes[OLC].page[1].min_digit = 1;
    state->modes[OLC].page[1].max_digit = 5;

    state->modes[GEO].max_page = 1;
    state->modes[GEO].page[0].min_digit = 1;
    state->modes[GEO].page[0].max_digit = 5;
    state->modes[GEO].page[1].min_digit = 1;
    state->modes[GEO].page[1].max_digit = 5;

    state->modes[DATA].max_page = 1;
    state->modes[DATA].page[0].min_digit = 0;
    state->modes[DATA].page[0].max_digit = 1;

}

bool places_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    places_state_t *state = (places_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            state->page = 0;
            state->active_digit = 0;
            state->place = 0;
            movement_request_tick_frequency(4);
            _places_face_update_display(event, context);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            // if entering low energy mode, start tick animation
            if (event.event_type == EVENT_LOW_ENERGY_UPDATE && !watch_tick_animation_is_running()) watch_start_tick_animation(1000);
            // check if we need to update the display
            if ( state->edit || state->remain ) {
                if ( state->mode != DATA )
                    _places_face_update_display(event, state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if ( state->edit || state->remain )
                state->active_digit++;
            else {
                state->place++;
                _load_place_from_memory(state);
            }

            if ( state->mode == DECIMAL || state->mode == DMS ) 
                if ( state->page == 0 && state->active_digit == 1 )
                    state->active_digit++;
            
            if ( state->active_digit > state->modes[state->mode].page[state->page].max_digit ) {
                if ( state->page == state->modes[state->mode].max_page ) {
                    state->page = 0;
                    state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                } else {
                    state->page++;
                    state->active_digit = state->modes[state->mode].page[state->page].min_digit;
                }
            }

            if ( state->mode == DATA ) {
                state->page = 0;
                switch ( state->active_digit ) {
                    case 0:
                        watch_display_string("R  ", 0);
                        state->write = false;
                        break;
                    case 1:
                        watch_display_string("W  ", 0);
                        state->write = true;
                        break;
                }
            }
            state->place %= 5;
            _places_face_update_display(event, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
           if ( state->mode == DATA ) {
                if ( !state->file && !state->registry )
                    state->mode = PLACE;
                else {
                    if ( state->registry && state->write )
                        _save_place_to_register(state);
                    if ( state->registry && !state->write )
                        _load_place_from_register(state);   
                    if ( state->file && state->write )
                        _save_place_to_file(state);
                    if ( state->file && !state->write )
                        _load_place_from_file(state);
                    state->remain = false;
                }
            } else {
                state->edit = !state->edit;
                state->active_digit = state->modes[state->mode].page[state->page].min_digit;
            }
            if ( !state->edit ) { // leaving edit mode saves data in state
                _save_place_to_memory(state);
                state->active_digit = 0;
            }
            _places_face_update_display(event, state);
            break;
        case EVENT_ALARM_BUTTON_UP:
             if ( state->edit )
                _places_face_advance_digit(state);
            else
                state->page++;
            if ( state->page > state->modes[state->mode].max_page ) {
                state->page = 0;
                if ( !state->remain )
                    state->mode = (state->mode + 1) % 5;
            }
            
            if ( state->mode == DATA ) {
                switch ( state->page ) {
                    case 0:
                        watch_display_string(" file ", 4);
                        state->file = true;
                        state->registry = false;
                        break;
                    case 1:
                        watch_display_string(" regst", 4);
                        state->file = false;
                        state->registry = true;
                        break;
                }
                break;
            }
            _places_face_update_display(event, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if ( state->mode != DATA )
                state->remain = !state->remain;
            if ( state->remain ) {
                switch ( state->mode ) {
                    case PLACE:
                        state->mode = DATA;
                        watch_display_string("R  ", 0);
                        watch_display_string(" file ", 4);
                        state->write = false;
                        state->file = true;
                        state->registry = false;
                        break;
                    case DATA:
                        state->file = false;
                        state->registry = false;
                        state->remain = false;
                        state->mode = PLACE;
                        break;
                }
            }
            _places_face_update_display(event, state);
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

void places_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    places_state_t *state = (places_state_t *)context;
    state->page = 0;
    state->active_digit = 0;

    // handle any cleanup before your watch face goes off-screen.
}

// PRIVATE STATIC FUNCTIONS ///////////////////////////////////////////////////

// CONVERSION FUNCTIONS

// Place Descriptor (ABCDE)

static void _name_struct_to_string(char *buf, places_name_t name) {
    buf[0] = name_alphabet[name.d1];
    buf[1] = name_alphabet[name.d2];
    buf[2] = name_alphabet[name.d3];
    buf[3] = name_alphabet[name.d4];
    buf[4] = name_alphabet[name.d5];
}

// Decimal Latitude & Longitude Format (DD.DDDDD)

// converts decimal LatLon struct to integer
static int32_t _ll_decimal_struct_to_int(places_ll_decimal_t val) {
    int32_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds * 10000000 +
                            val.tens     * 1000000 +
                            val.ones     * 100000 +
                            val.d1       * 10000 +
                            val.d2       * 1000+
                            val.d3       * 100+
                            val.d4       * 10 +
                            val.d5       * 1
                        );
    return retval;
}

// converts decimal LatLon struct to integer
static int16_t _ll_decimal_struct_to_int16(places_ll_decimal_t val) {
    if ( val.d5 >=5 && val.d4 < 9 ) val.d4++;
    else if ( val.d4 < 9 ) val.d4--;
    if ( val.d3 >=5 && val.d3 < 9) val.d3++;
    else if ( val.d3 < 9 ) val.d3--;
    if ( val.d3 > 8 && val.d2 < 9) val.d2++;
    else if ( val.d2 < 9 ) val.d2--;
    int16_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds * 10000 +
                            val.tens     * 1000 +
                            val.ones     * 100 +
                            val.d1       * 10 +
                            val.d2       * 1
                        );
    return retval;
}

static places_ll_decimal_t _ll_decimal_int_to_struct(int32_t val) {
    // convert decimal LatLon integer to struct
    places_ll_decimal_t retval;

    retval.sign = val < 0;
    val = abs(val);
    retval.d5 = val % 10;
    val /= 10;
    retval.d4 = val % 10;
    val /= 10;
    retval.d3 = val % 10;
    val /= 10;
    retval.d2 = val % 10;
    val /= 10;
    retval.d1 = val % 10;
    val /= 10;
    retval.ones = val % 10;
    val /= 10;
    retval.tens = val % 10;
    val /= 10;
    retval.hundreds = val % 10;

    return retval;
}

// Latitude & Longitude in Degrees, Minutes, Seconds (DD° MM' SS")

static int32_t _ll_dms_struct_to_int(places_ll_dms_t val) {
    // converts DMS LatLon struct to integer
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

static places_ll_dms_t _ll_dms_int_to_struct(int32_t val) {
    // convert DMS LatLon integer to struct
    places_ll_dms_t retval;

    retval.sign = val < 0;
    val = abs(val);
    retval.secs_ones = val % 10;
    val /= 10;
    retval.secs_tens = val % 10;
    val /= 10;
    retval.mins_ones = val % 10;
    val /= 10;
    retval.mins_tens = val % 10;
    val /= 10;
    retval.ones = val % 10;
    val /= 10;
    retval.tens = val % 10;
    val /= 10;
    retval.hundreds = val % 10;

    return retval;
}

static void _olc_struct_to_array(uint8_t *buf, places_olc_t pluscode) {
    // convert and write Open Location Code struct to char array
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
}

static void _geohash_struct_to_array(uint8_t *buf, places_geohash_t hash) {
    buf[0] = hash.d1;
    buf[1] = hash.d2;
    buf[2] = hash.d3;
    buf[3] = hash.d4;
    buf[4] = hash.d5;
    buf[5] = hash.d6;
    buf[6] = hash.d7;
    buf[7] = hash.d8;
    buf[8] = hash.d9;
    buf[9] = hash.d10;
}

// Conversion between Decimal and DMS Latitude & Longitude

static int32_t _ll_dms_struct_to_decimal_int( places_ll_dms_t val ) {
    // convert DMS LatLon struct to decimal integer
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

static int32_t _ll_decimal_struct_to_dms_int( places_ll_decimal_t val ) {
    // convert decimal LatLon struct to DMS integer
    places_ll_dms_t dms;
    double coord = (double)abs(_ll_decimal_struct_to_int(val)) / 100000;
    
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
    return _ll_dms_struct_to_int(dms);

}

// Conversion between Decimal Latitude & Longitude and Open Location Code

// convert LatLon integer to Open Location Code struct
static places_olc_t _ll_decimal_ints_to_olc(int32_t lat, int32_t lon) {
    uint8_t values[10];
    places_olc_t retval;
    double latitude = (double)lat / 100000;
    double longitude = (double)lon / 100000;
    int a = (latitude + 90) * 1e6;
    int b = (longitude + 180) * 1e6;
    for (int8_t i = 9; i > -1; i--) {
        values[i] = b / 125 % 20;
        int d = b;
        b = a;
        a = d / 20;
    }
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

static places_ll_coordinate_t _ll_olc_to_decimal_coordinate(places_olc_t pluscode) {
    // convert Open Location Code char array to LatLon Coordinate struct
    double lat = 0, lon = 0;
    double deg = 20;
    uint8_t buf[10];
    places_ll_coordinate_t retval;
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
    retval.latitude = _ll_decimal_int_to_struct((int32_t)((lat - 90) * 100000));
    retval.longitude = _ll_decimal_int_to_struct((int32_t)((lon - 180) * 100000));
    return retval;
}

// convert LatLon integer to Geohash struct
static places_geohash_t _ll_decimal_ints_to_geohash(int32_t latitude, int32_t longitude) {
    uint8_t hash[10] = {0};
    double lat = (double)latitude / 100000;
    double lng = (double)longitude / 100000;

    /*  C implementation created by Derek Smith
     *  https://github.com/simplegeo/libgeohash/
     *  Copyright (c) 2010, SimpleGeo
     */
                        
    places_geohash_interval lat_interval = {90, -90};
    places_geohash_interval lng_interval = {180, -180};

    places_geohash_interval *interval;
    double coord, mid;
    int is_even = 1;
    unsigned int hashChar = 0;
    int i;
    for(i = 1; i <= 50; i++) {
        if(is_even) {
            interval = &lng_interval;
            coord = lng;                   
        } else { 
            interval = &lat_interval;
            coord = lat;   
        }
        
        mid = (interval->low + interval->high) / 2.0;
        hashChar = hashChar << 1;
        
        if(coord > mid) {
            
            interval->low = mid;
            hashChar |= 0x01;
            
        } else
            interval->high = mid;
        
        if(!(i % 5)) {
            hash[(i - 1) / 5] = hashChar;
            hashChar = 0;
        }
        
        is_even = !is_even;
    }
            
    places_geohash_t geohash;
    geohash.d1 = hash[0];
    geohash.d2 = hash[1];
    geohash.d3 = hash[2];
    geohash.d4 = hash[3];
    geohash.d5 = hash[4];
    geohash.d6 = hash[5];
    geohash.d7 = hash[6];
    geohash.d8 = hash[7];
    geohash.d9 = hash[8];
    geohash.d10 = hash[9];
    return geohash;
}

// convert Geohash struct to LatLon Coordinate
static places_ll_coordinate_t _ll_geohash_to_decimal_coordinate(places_geohash_t geohash) {
    
    uint8_t hash[10];
    _geohash_struct_to_array(hash, geohash);
    
    /*  C implementation created by Derek Smith
     *  https://github.com/simplegeo/libgeohash/
     *  Copyright (c) 2010, SimpleGeo
     */

    unsigned int char_mapIndex;
    places_geohash_interval lat_interval = {90, -90};
    places_geohash_interval lng_interval = {180, -180};
    places_geohash_interval *interval;

    int is_even = 1;
    double delta;
    int i, j;
    for(i = 0; i < 10; i++) {
    
        char_mapIndex = hash[i];
        
        if(char_mapIndex < 0)
            break;
    
        // Interpret the last 5 bits of the integer
        for(j = 0; j < 5; j++) {
        
            interval = is_even ? &lng_interval : &lat_interval;
        
            delta = (interval->high - interval->low) / 2.0;
        
            if((char_mapIndex << j) & 0x0010)
                interval->low += delta;
            else
                interval->high -= delta;
        
            is_even = !is_even;
        }
    }
    places_ll_coordinate_t retval;
    retval.latitude = _ll_decimal_int_to_struct(
        (int32_t)((lat_interval.high - ((lat_interval.high - lat_interval.low) / 2.0)) * 100000)
    );
    retval.longitude = _ll_decimal_int_to_struct(
        (int32_t)((lng_interval.high - ((lng_interval.high - lng_interval.low) / 2.0)) * 100000)
    );

    return retval;
}

// WATCH DISPLAY FUNCTIONS

// Display Place Name
static void _places_face_update_name_display(movement_event_t event, places_state_t *state) {
    char buf[12];
    char name[6] = {0};
    watch_clear_display();
    _name_struct_to_string(name, state->working_name);
    
    char help[3];
    sprintf(help, "PL");

    sprintf(buf, "%c%c %d %c%c%c%c%c", help[0], help[1], state->place + 1, name[0], name[1], name[2], name[3], name[4]);
    
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

// Display Decimal Latitude & Longitude
static void _places_face_update_latlon_display(movement_event_t event, places_state_t *state) {
    char buf[12];
    char lln[9];
    watch_clear_display();

    if ( state->page < 2 )
        sprintf(lln, "%08d", abs( _ll_decimal_struct_to_int(state->working_latitude)));
    else
        sprintf(lln, "%08d", abs( _ll_decimal_struct_to_int(state->working_longitude)));

    switch (state->page) {
        case 0: // Latitude
            sprintf(buf, "LA %d%c %c%c  ", state->place + 1, state->working_latitude.sign ? '-' : '+', lln[1], lln[2] );
            break;
        case 1:
            sprintf(buf, "LA %d,%c%c%c%c%c", state->place + 1, lln[3], lln[4],lln[5], lln[6],lln[7]);
            break;
        case 2: // Longitude
            sprintf(buf, "LO %d%c%c%c%c  ", state->place + 1, state->working_longitude.sign ? '-' : '+', lln[0], lln[1], lln[2] );
            break;
        case 3:
            sprintf(buf, "LO %d,%c%c%c%c%c", state->place + 1, lln[3], lln[4],lln[5], lln[6],lln[7]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

// Display Latitude & Longitude in Degrees, Minutes, Seconds
static void _places_face_update_dms_display(movement_event_t event, places_state_t *state) {
    char buf[12];
    char lln[8];
    watch_clear_display();
    if ( state->page < 2 ) 
        sprintf(lln, "%07d", abs( _ll_dms_struct_to_int(state->working_dms_latitude)));
    else
        sprintf(lln, "%07d", abs( _ll_dms_struct_to_int(state->working_dms_longitude)));
    
    switch (state->page) {
        case 0: // Latitude
            sprintf(buf, "LA %d%c %c%c d", state->place + 1, state->working_dms_latitude.sign ? 'S' : 'N', lln[1], lln[2] );
            break;
        case 1:
            watch_set_colon();
            sprintf(buf, "LA %d%c%c%c%cMS", state->place + 1, lln[3], lln[4], lln[5], lln[6]);
            break;
        case 2: // Longitude
            sprintf(buf, "LO %d%c%c%c%c d", state->place + 1, state->working_dms_longitude.sign ? 'W' : 'E', lln[0], lln[1], lln[2] );
            break;
        case 3:
            watch_set_colon();
            sprintf(buf, "LO %d%c%c%c%cMS", state->place + 1, lln[3], lln[4], lln[5], lln[6]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
    if ( state->page % 2 == 0) {
        watch_set_pixel(1, 2);
        watch_set_pixel(2, 2);
        watch_set_pixel(1, 3);
        watch_set_pixel(2, 3);
    }
}

// Display Open Location Code or Geohash
static void _places_face_update_code_display(movement_event_t event, places_state_t *state) {
    bool fix = false;
    char buf[12];
    uint8_t code_array[10];
    char code_string[11] = {0};
    char help[3];

    watch_clear_display();

    uint8_t index = state->active_digit + ( state->page == 0 ? -1 : 4);
    switch ( state->mode ) {
        case OLC:
            _olc_struct_to_array(code_array, state->working_pluscode);
            for ( uint8_t i = 0; i < 10; i++)
                code_string[i] = olc_alphabet[code_array[i]];
            if ( code_array[index] > 7 )
                //watch_set_indicator(WATCH_INDICATOR_LAP);
            break;
        case GEO:
            _geohash_struct_to_array(code_array, state->working_geohash);
            for ( uint8_t i = 0; i < 10; i++)
                code_string[i] = geohash_alphabet[code_array[i]];
            if ( code_array[index] > 9 )
                //watch_set_indicator(WATCH_INDICATOR_LAP);
            break;
    }
    if ( state->active_digit > 0 ) {
        char letter_digit = code_string[index];
            if ( code_array[index] == 27 ) {
                letter_digit = ' ';
                fix = true;
            }
            sprintf(help, "%c ", letter_digit);
    } else {
        sprintf(help, (state->mode == OLC ? "OL" : "GH"));
    }

    switch (state->page) {
        case 0: // OLC Digits 1-5
            sprintf(buf, "%c%c %d %c%c%c%c%c", help[0], help[1], state->place + 1, code_string[0], code_string[1], code_string[2], code_string[3], code_string[4]);
            break;
        case 1: // OLC Digits 2-10
            sprintf(buf, "%c%c %d %c%c%c%c%c", help[0], help[1], state->place + 1, code_string[5], code_string[6], code_string[7], code_string[8], code_string[9]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }

    if (state->remain && state->active_digit > 0 && event.subsecond == 1) {
        buf[state->active_digit + 4] = '-';
    }

    watch_display_string(buf, 0);
    if ( state->page % 2 == 0) {
        watch_set_pixel(0, 18);
    } else {
        watch_set_pixel(0, 19);
    }

    if ( fix ) {
        watch_set_pixel(0, 14);
        watch_set_pixel(1, 14);
        watch_set_pixel(1, 13);
    }
}

// manage display formats
static void _places_face_update_display(movement_event_t event, places_state_t *state) {
    switch ( state->mode ) {
        case PLACE:
            _places_face_update_name_display(event, state);
            break;
        case DECIMAL:
            _places_face_update_latlon_display(event, state);
            break;
        case DMS:
            _places_face_update_dms_display(event, state);
            break;
        case OLC:
        case GEO:
            _places_face_update_code_display(event, state);
            break;
        case DATA:
            break;
    }  
    if ( state->remain)
        watch_set_indicator(WATCH_INDICATOR_LAP);
    else
        watch_clear_indicator(WATCH_INDICATOR_LAP);
}

// DATA EDITOR FUNCTIONS

// Place Name Editor
static void _places_face_advance_name_digit(places_state_t *state) {
    switch (state->active_digit) {
        case 0:
            // we skip this digit
            break;
        case 1:
            state->working_name.d1 = (state->working_name.d1 + 1) % 38;
            break;
        case 2:
            state->working_name.d2 = (state->working_name.d2 + 1) % 38;
            break;
        case 3:
            state->working_name.d3 = (state->working_name.d3 + 1) % 38;
            break;
        case 4:
            state->working_name.d4 = (state->working_name.d4 + 1) % 38;
            break;
        case 5:
            state->working_name.d5 = (state->working_name.d5 + 1) % 38;
            break;
    }
}

// Decimal LatLon Editor
static void _places_face_advance_latlon_digit(places_state_t *state) {
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
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) {
                        // prevent latitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_latitude.ones = 0;
                        state->working_latitude.d1 = 0;
                        state->working_latitude.d2 = 0;
                        state->working_latitude.d3 = 0;
                        state->working_latitude.d4 = 0;
                        state->working_latitude.d5 = 0;
                    }
                    break;
                case 3:
                    state->working_latitude.ones = (state->working_latitude.ones + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) 
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
                    state->working_latitude.d1 = (state->working_latitude.d1 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d1 = 0;
                    break;
                case 2:
                    state->working_latitude.d2 = (state->working_latitude.d2 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d2 = 0;
                    break;
                case 3:
                    state->working_latitude.d3 = (state->working_latitude.d3 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d3 = 0;
                    break;
                case 4:
                    state->working_latitude.d4 = (state->working_latitude.d4 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d4 = 0;
                    break;
                case 5:
                    state->working_latitude.d5 = (state->working_latitude.d5 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_latitude)) > 9000000) 
                        state->working_latitude.d5 = 0;
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
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) {
                        // prevent longitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_longitude.tens = 0;
                        state->working_longitude.ones = 0;
                        state->working_longitude.d1 = 0;
                        state->working_longitude.d2 = 0;
                        state->working_longitude.d3 = 0;
                        state->working_longitude.d4 = 0;
                        state->working_longitude.d5 = 0;
                    }
                    break;
                case 2:
                    state->working_longitude.tens = (state->working_longitude.tens + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) {
                        state->working_longitude.tens = 0;

                    }
                    break;
                case 3:
                    state->working_longitude.ones = (state->working_longitude.ones + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) 
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
                    state->working_longitude.d1 = (state->working_longitude.d1 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d1 = 0;
                    break;
                case 2:
                    state->working_longitude.d2 = (state->working_longitude.d2 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d2 = 0;
                    break;
                case 3:
                    state->working_longitude.d3 = (state->working_longitude.d3 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d3 = 0;
                    break;
                case 4:
                    state->working_longitude.d4 = (state->working_longitude.d4 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d4 = 0;
                    break;
                case 5:
                    state->working_longitude.d5 = (state->working_longitude.d5 + 1) % 10;
                    if (abs(_ll_decimal_struct_to_int(state->working_longitude)) > 18000000) 
                        state->working_longitude.d5 = 0;
                    break;
            }
            break;
    }
}

// DMS LatLon Editor
static void _places_face_advance_dms_digit(places_state_t *state) {
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
                    if (abs(_ll_dms_struct_to_int(state->working_dms_latitude)) > 900000) {
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
                    if (abs(_ll_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.ones = 0;
                    break;
            }
            break;
        case 1: // latitude first five decimal digits
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    // we skip this digit
                case 2:
                    state->working_dms_latitude.mins_tens = (state->working_dms_latitude.mins_tens + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.mins_tens = 0;
                    break;
                case 3:
                    state->working_dms_latitude.mins_ones = (state->working_dms_latitude.mins_ones + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.mins_ones = 0;
                    break;
                case 4:
                    state->working_dms_latitude.secs_tens = (state->working_dms_latitude.secs_tens + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
                        state->working_dms_latitude.secs_tens = 0;
                    break;
                case 5:
                    state->working_dms_latitude.secs_ones = (state->working_dms_latitude.secs_ones + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_latitude)) > 900000) 
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
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000) {
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
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000)
                        state->working_dms_longitude.tens = 0;
                    break;
                case 3:
                    state->working_dms_longitude.ones = (state->working_dms_longitude.ones + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.ones = 0;
                    break;
            }
            break;
        case 3: // longitude first five decimal digits
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    // we skip this digit
                case 2:
                    state->working_dms_longitude.mins_tens = (state->working_dms_longitude.mins_tens + 1) % 6;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.mins_tens = 0;
                    break;
                case 3:
                    state->working_dms_longitude.mins_ones = (state->working_dms_longitude.mins_ones + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.mins_ones = 0;
                    break;
                case 4:
                    state->working_dms_longitude.secs_tens = (state->working_dms_longitude.secs_tens + 1) % 6;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.secs_tens = 0;
                    break;
                case 5:
                    state->working_dms_longitude.secs_ones = (state->working_dms_longitude.secs_ones + 1) % 10;
                    if (abs(_ll_dms_struct_to_int(state->working_dms_longitude)) > 1800000) 
                        state->working_dms_longitude.secs_ones = 0;
                    break;
            }
            break;
    }
}

// Open Location Code Editor
static void _places_face_advance_olc_digit(places_state_t *state) {
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
static void _places_face_advance_geohash_digit(places_state_t *state) {
    switch (state->page) {
        case 0: // digits 1 - 5
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_geohash.d1 = (state->working_geohash.d1 + 1) % 32;
                    break;
                case 2:
                    state->working_geohash.d2 = (state->working_geohash.d2 + 1) % 32;
                    break;
                case 3:
                    state->working_geohash.d3 = (state->working_geohash.d3 + 1) % 32;
                    break;
                case 4:
                    state->working_geohash.d4 = (state->working_geohash.d4 + 1) % 32;
                    break;
                case 5:
                    state->working_geohash.d5 = (state->working_geohash.d5 + 1) % 32;
                    break;
            }
            break;
        case 1: // digits 6 - 10
            switch (state->active_digit) {
                case 0:
                    // we skip this digit
                    break;
                case 1:
                    state->working_geohash.d6 = (state->working_geohash.d6 + 1) % 32;
                    break;
                case 2:
                    state->working_geohash.d7 = (state->working_geohash.d7 + 1) % 32;
                    break;
                case 3:
                    state->working_geohash.d8 = (state->working_geohash.d8 + 1) % 32;
                    break;
                case 4:
                    state->working_geohash.d9 = (state->working_geohash.d9 + 1) % 32;
                    break;
                case 5:
                    state->working_geohash.d10 = (state->working_geohash.d10 + 1) % 32;
                    break;
            }
            break;
    }
}

// Editor Manager
static void _places_face_advance_digit(places_state_t *state) {
    switch ( state->mode ) {
        case PLACE:
            _places_face_advance_name_digit(state);
        case DECIMAL:
            _places_face_advance_latlon_digit(state);
            break;
        case DMS:
            _places_face_advance_dms_digit(state);
            break;
        case OLC:
            _places_face_advance_olc_digit(state);
            break;
        case GEO:
            _places_face_advance_geohash_digit(state);
            break;
        case DATA:
            break;
    }
}

// DATA MANAGEMENT FUNCTIONS

// load place from state array and populate working structs
static void _load_place_from_memory(places_state_t *state) {
    state->working_name = state->places[state->place].name;
    state->working_latitude = state->places[state->place].latitude;
    state->working_longitude = state->places[state->place].longitude;
    state->working_dms_latitude = _ll_dms_int_to_struct(_ll_decimal_struct_to_dms_int(state->working_latitude));
    state->working_dms_longitude = _ll_dms_int_to_struct(_ll_decimal_struct_to_dms_int(state->working_longitude));
    state->working_pluscode = _ll_decimal_ints_to_olc(_ll_decimal_struct_to_int(state->working_latitude), _ll_decimal_struct_to_int(state->working_longitude));
    state->working_geohash = _ll_decimal_ints_to_geohash(_ll_decimal_struct_to_int(state->working_latitude), _ll_decimal_struct_to_int(state->working_longitude));
}

static void _save_place_to_memory(places_state_t *state) {
    switch ( state->mode ) {
        case PLACE:
            state->places[state->place].name = state->working_name;
            break;
        case DECIMAL:
            state->places[state->place].latitude = state->working_latitude;
            state->places[state->place].longitude = state->working_longitude;
            break;
        case DMS:
            state->places[state->place].latitude  = _ll_decimal_int_to_struct(_ll_dms_struct_to_decimal_int(state->working_dms_latitude));
            state->places[state->place].longitude = _ll_decimal_int_to_struct(_ll_dms_struct_to_decimal_int(state->working_dms_longitude));
            break;
        case OLC:
            state->places[state->place].latitude  = _ll_olc_to_decimal_coordinate(state->working_pluscode).latitude;
            state->places[state->place].longitude = _ll_olc_to_decimal_coordinate(state->working_pluscode).longitude;
            break;
        case GEO:
            state->places[state->place].latitude  = _ll_geohash_to_decimal_coordinate(state->working_geohash).latitude;
            state->places[state->place].longitude = _ll_geohash_to_decimal_coordinate(state->working_geohash).longitude;
            break;
        case DATA:
            break;
    }
    _load_place_from_memory(state);
}

static void _load_place_from_register(places_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->places[state->place].latitude = _ll_decimal_int_to_struct(movement_location.bit.latitude * 1000);
    state->places[state->place].longitude = _ll_decimal_int_to_struct(movement_location.bit.longitude * 1000);
    delay_ms(200);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    watch_display_string("  OK  ", 4);
    delay_ms(1000);
    state->mode = PLACE;
}

static void _save_place_to_register(places_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    movement_location_t movement_location;
    int16_t lat = _ll_decimal_struct_to_int16(state->working_latitude);
    int16_t lon = _ll_decimal_struct_to_int16(state->working_longitude);
    movement_location.bit.latitude = lat;
    movement_location.bit.longitude = lon;
    watch_store_backup_data(movement_location.reg, 1);
    delay_ms(200);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    watch_display_string("  OK  ", 4);
    delay_ms(1000);
    state->mode = PLACE;
}

static void _load_place_from_file(places_state_t *state) {
    places_ll_coordinate_t place;
    if (filesystem_file_exists("place.loc"))
        if (filesystem_read_file("place.loc", (char*)&place, sizeof(place))) {
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            state->places[state->place].latitude = place.latitude;
            state->places[state->place].longitude = place.longitude;
            delay_ms(200);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            watch_display_string("  OK  ", 4);
            delay_ms(1000);
        } else {
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            watch_set_indicator(WATCH_INDICATOR_BELL);
            watch_display_string(" Error", 4);
            delay_ms(2000);
            watch_clear_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        watch_set_indicator(WATCH_INDICATOR_BELL);
        watch_display_string("no   file ", 0);
        delay_ms(2000);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
    state->mode = PLACE;
}

static void _save_place_to_file(places_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    places_ll_coordinate_t place;
    place.latitude = state->places[state->place].latitude;
    place.longitude = state->places[state->place].longitude;
    if (filesystem_write_file("place.loc", (char*)&place, sizeof(place))) {
        delay_ms(200);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        watch_display_string("  OK  ", 4);
        delay_ms(1000);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        watch_set_indicator(WATCH_INDICATOR_BELL);
        watch_display_string(" Error", 4);
        delay_ms(2000);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
        
    }
    state->mode = PLACE;
}