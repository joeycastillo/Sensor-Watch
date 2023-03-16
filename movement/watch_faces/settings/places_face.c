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
#include "places_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

// Modes
#define PLACE 0
#define DECIMAL 1
#define DMS 2
#define OLC 3
#define DATA 4

// STATIC HELPER FUNCTIONS ////////////////////////////////////////////////////

// converts decimal LatLon struct to integer
static int32_t _ll_decimal_struct_to_int(places_ll_decimal_t val);

// convert decimal LatLon integer to struct
static places_ll_decimal_t _ll_decimal_int_to_struct(int32_t val);

// converts DMS LatLon struct to integer
static int32_t _ll_dms_struct_to_int(places_ll_dms_t val);

// convert DMS LatLon integer to struct
static places_ll_dms_t _ll_dms_int_to_struct(int32_t val);

// convert Open Location Code char array to struct
static places_olc_t _olc_string_to_struct(char *buf);

// convert and write Open Location Code struct to char array
static void _olc_struct_to_string(char *buf, places_olc_t pluscode);

// convert DMS LatLon struct to decimal integer
static int32_t _ll_dms_struct_to_decimal_int( places_ll_dms_t val );

// convert decimal LatLon struct to DMS integer
static int32_t _ll_decimal_struct_to_dms_int( places_ll_decimal_t val );

// convert LatLon integer to Open Location Code string and write to char array
static void _ll_decimal_int_to_olc(char *buf, int32_t lat, int32_t lon);

// convert Open Location Code char array to LatLon Coordinate struct
static places_ll_coordinate_t _ll_olc_to_decimal_coordinate(char *buf);

// Display Decimal Latitude & Longitude
static void _places_face_update_latlon_display(movement_event_t event, places_state_t *state);

// Display Latitude & Longitude in Degrees, Minutes, Seconds
static void _places_face_update_dms_display(movement_event_t event, places_state_t *state);

// Display Open Location Code
static void _places_face_update_olc_display(movement_event_t event, places_state_t *state);

// manage display formats
static void _places_face_update_display(movement_event_t event, places_state_t *state);

// Decimal LatLon Editor
static void _places_face_advance_latlon_digit(places_state_t *state);

// DMS LatLon Editor
static void _places_face_advance_dms_digit(places_state_t *state);

// Open Location Code Editor
static void _places_face_advance_olc_digit(places_state_t *state);

// Editor Manager
static void _places_face_advance_digit(places_state_t *state);

// DATA MANAGEMENT FUNCTIONS
static void _places_face_update_location_register(places_state_t *state);

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

    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->working_latitude = _ll_decimal_int_to_struct(movement_location.bit.latitude * 10000);
    state->working_longitude = _ll_decimal_int_to_struct(movement_location.bit.longitude * 10000);
}

bool places_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    places_state_t *state = (places_state_t *)context;
    state->mode = DECIMAL;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            state->page = 0;
            state->active_digit = 0;
            movement_request_tick_frequency(4);
            _places_face_update_display(event, context);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            // if entering low energy mode, start tick animation
            if (event.event_type == EVENT_LOW_ENERGY_UPDATE && !watch_tick_animation_is_running()) watch_start_tick_animation(1000);
            // check if we need to update the display
            else _places_face_update_display(event, state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            if ( !state->edit )
                movement_illuminate_led();
            else
                state->active_digit++;
            switch ( state->mode ) {
                case PLACE: // Place Name
                    break;
                case DECIMAL: // Decimal LatLon
                    switch ( state->page ) {
                        case 0:
                            if (state->active_digit == 1) state->active_digit++; // max latitude is +- 90, no hundreds place              
                        case 2:
                            if (state->active_digit > 3) {
                                state->active_digit = 1;
                                state->page++;
                            }
                            break;
                        case 1:
                        case 3:
                            if (state->active_digit > 5) {
                                state->active_digit = 0;
                                state->page = ( state->page + 1 ) % 4;
                            }
                            break;
                    }
                    break;
                case DMS: // DMS LatLon
                    switch ( state->page ) {
                        case 0:
                            if (state->active_digit == 1) state->active_digit++; // max latitude is +- 90, no hundreds place              
                        case 2:
                            if (state->active_digit > 3) {
                                state->active_digit = 2;
                                state->page++;
                            }
                            break;
                        case 1:
                        case 3:
                            if (state->active_digit > 5) {
                                state->active_digit = 0;
                                state->page = ( state->page + 1 ) % 4;
                            }
                            break;
                    }
                    break;
                case OLC: // Open Location Code
                    switch ( state->page ) {
                        case 0:
                        case 2:
                            if (state->active_digit > 5) {
                                state->active_digit = 1;
                                state->page++;
                            }
                            break;
                        case 1:
                        case 3:
                            if (state->active_digit > 5) {
                                state->active_digit = 1;
                                state->page = ( state->page + 1 ) % 4;
                            }
                            break;
                    }
                    break;
                case DATA: // Data Management
                    break;
            }
            _places_face_update_display(event, context);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            state->edit = !state->edit;
            switch ( state->page ) {
                case 0:
                case 2:
                    state->active_digit = 0;
                    if ( state->mode == OLC )
                        state->active_digit = 1;  
                    break;
                default:
                    state->active_digit = ( state->mode == DMS ? 2 : 1);
                    break;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if ( state->edit )
                _places_face_advance_digit(state);
            else {
                state->page = (state->page + 1) % (state->mode == OLC ? 2 : 4);
            }
            _places_face_update_display(event, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            // should become selector
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
    _places_face_update_location_register(state);

    // handle any cleanup before your watch face goes off-screen.
}

// PRIVATE STATIC FUNCTIONS ///////////////////////////////////////////////////

// CONVERSION FUNCTIONS

// Decimal Latitude & Longitude Format (DD.DDDDD)

static int32_t _ll_decimal_struct_to_int(places_ll_decimal_t val) {
    // converts decimal LatLon struct to integer
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

// Open Location Code / PlusCode (12345678+9C)

static places_olc_t _olc_string_to_struct(char *buf) {
    // convert Open Location Code char array to struct
    places_olc_t retval;
    uint8_t values[10];
    for (int8_t i = 0; i < 10; i++) {
        const char *ptr = strchr(olc_alphabet, buf[i]);
        values[i] = ptr - olc_alphabet;
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

static void _olc_struct_to_string(char *buf, places_olc_t pluscode) {
    // convert and write Open Location Code struct to char array
    buf[0] = olc_alphabet[pluscode.lat1];
    buf[1] = olc_alphabet[pluscode.lon1];
    buf[2] = olc_alphabet[pluscode.lat2];
    buf[3] = olc_alphabet[pluscode.lon2];
    buf[4] = olc_alphabet[pluscode.lat3];
    buf[5] = olc_alphabet[pluscode.lon3];
    buf[6] = olc_alphabet[pluscode.lat4];
    buf[7] = olc_alphabet[pluscode.lon4];
    buf[8] = olc_alphabet[pluscode.lat5];
    buf[9] = olc_alphabet[pluscode.lon5];
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

static void _ll_decimal_int_to_olc(char *buf, int32_t lat, int32_t lon) {
    // convert LatLon integer to Open Location Code string and write to char array
    double latitude = (double)lat / 100000;
    double longitude = (double)lon / 100000;
    int a = (latitude + 90) * 1e6;
    int b = (longitude + 180) * 1e6;
    buf[10] = '\0';
    for (int8_t i = 9; i > -1; i--) {
        buf[i] = olc_alphabet[b / 125 % 20];
        int d = b;
        b = a;
        a = d / 20;
    }
}

static places_ll_coordinate_t _ll_olc_to_decimal_coordinate(char *buf) {
    // convert Open Location Code char array to LatLon Coordinate struct
    double lat = 0, lon = 0;
    double deg = 20;
    places_ll_coordinate_t retval;
    for (int8_t i = 0; i < 10; i++) {
        const char *ptr = strchr(olc_alphabet, buf[i]);
        uint8_t value = ptr - olc_alphabet;
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

// WATCH DISPLAY FUNCTIONS

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
            sprintf(buf, "LA o%c %c%c  ", state->working_latitude.sign ? '-' : '+', lln[1], lln[2] );
            break;
        case 1:
            sprintf(buf, "LA d,%c%c%c%c%c", lln[3], lln[4],lln[5], lln[6],lln[7]);
            break;
        case 2: // Longitude
            sprintf(buf, "LO o%c%c%c%c  ", state->working_longitude.sign ? '-' : '+', lln[0], lln[1], lln[2] );
            break;
        case 3:
            sprintf(buf, "LO d,%c%c%c%c%c", lln[3], lln[4],lln[5], lln[6],lln[7]);
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
            sprintf(buf, "LA o%c %c%c  ", state->working_dms_latitude.sign ? 'S' : 'N', lln[1], lln[2] );
            break;
        case 1:
            sprintf(buf, "LA,   %c%c%c%c", lln[3], lln[4], lln[5], lln[6]);
            break;
        case 2: // Longitude
            sprintf(buf, "LO o%c%c%c%c  ", state->working_dms_longitude.sign ? 'W' : 'E', lln[0], lln[1], lln[2] );
            break;
        case 3:
            sprintf(buf, "LO,   %c%c%c%c", lln[3], lln[4], lln[5], lln[6]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
    watch_set_pixel(2, 7);
    watch_set_pixel(2, 8);
}

// Display Open Location Code
static void _places_face_update_olc_display(movement_event_t event, places_state_t *state) {
    char buf[12];
    char olc[11] = {0};
    watch_clear_display();
    _olc_struct_to_string(olc, state->working_pluscode);
    
    char help[3];
    if ( state->edit )
        sprintf(help, "%c%c", olc[state->active_digit + ( state->page == 0 ? -1 : 4)], ' ');
    else
        sprintf(help, "OL");

    switch (state->page) {
        case 0: // OLC Digits 1-5
            sprintf(buf, "%c%c 1 %c%c%c%c%c", help[0], help[1], olc[0], olc[1], olc[2], olc[3], olc[4]);
            break;
        case 1: // OLC Digits 2-10
            sprintf(buf, "%c%c 2 %c%c%c%c%c", help[0], help[1], olc[5], olc[6], olc[7], olc[8], olc[9]);
            break;
    }
    if (state->edit && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

// manage display formats
static void _places_face_update_display(movement_event_t event, places_state_t *state) {
    switch ( state->mode ) {
        case PLACE:
        case DECIMAL:
            _places_face_update_latlon_display(event, state);
            break;
        case DMS:
            _places_face_update_dms_display(event, state);
            break;
        case OLC:
            _places_face_update_olc_display(event, state);
            break;
        case DATA:
            break;
    }
    
}

// DATA EDITOR FUNCTIONS

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

// Editor Manager
static void _places_face_advance_digit(places_state_t *state) {
    switch ( state->mode ) {
        case PLACE:
        case DECIMAL:
            _places_face_advance_latlon_digit(state);
            break;
        case DMS:
            _places_face_advance_dms_digit(state);
            break;
        case OLC:
            _places_face_advance_olc_digit(state);
            break;
        case DATA:
            break;
    }
}

// DATA MANAGEMENT FUNCTIONS

static void _places_face_update_location_register(places_state_t *state) {
    if (state->location_changed) {
        movement_location_t movement_location;
        int16_t lat = _ll_decimal_struct_to_int(state->working_latitude);
        int16_t lon = _ll_decimal_struct_to_int(state->working_longitude);
        movement_location.bit.latitude = lat;
        movement_location.bit.longitude = lon;
        watch_store_backup_data(movement_location.reg, 1);
        state->location_changed = false;
    }
}