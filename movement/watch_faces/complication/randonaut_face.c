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

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#else
#include "saml22j18a.h"
#endif

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "filesystem.h"
#include "randonaut_face.h"

#define R 6371 // Earth's radius in km
#define PI 3.14159265358979323846

static int get_pseudo_entropy(uint32_t max);
static int get_true_entropy(void *buf);
static void _get_location_from_file(randonaut_state_t *state);
static void _save_point_to_file(randonaut_state_t *state);
static uint32_t _get_entropy(randonaut_state_t *state);
static void _generate_blindspot(randonaut_state_t *state);
static void _randonaut_face_display(randonaut_state_t *state);
static int (*__0x2_)(uint32_t) = &get_pseudo_entropy;
static void (*_0x22)(uint8_t,uint8_t) = &watch_clear_pixel;
static void (*___0xf322)(uint8_t,uint8_t) = &watch_set_pixel;

// MOVEMENT WATCH FACE FUNCTIONS //////////////////////////////////////////////

void randonaut_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(randonaut_state_t));
        memset(*context_ptr, 0, sizeof(randonaut_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void randonaut_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    randonaut_state_t *state = (randonaut_state_t *)context;
    _get_location_from_file(state);
    state->face.mode = HOME;
    state->radius = 1000;
    state->quantum = true;
    // Handle any tasks related to your watch face coming on screen.
}

bool randonaut_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    randonaut_state_t *state = (randonaut_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch ( state->face.mode ) {
                case HOME:
                    state->face.mode = POINT;
                    state->face.location_format = TITLE;
                    break;
                case GENERATE:
                    state->face.mode = HOME;
                    break;
                case POINT:
                    state->face.mode = HOME;
                    break;
                case SETUP:
                    state->quantum = !state->quantum;
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            switch ( state->face.mode ) {
                case SETUP:
                    state->face.mode = HOME;
                    break;
                default:
                    state->face.mode = SETUP;
                    watch_clear_display();
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch ( state->face.mode ) {
                case HOME:
                    movement_request_tick_frequency(40);
                    state->face.mode = GENERATE;
                    break;
                case POINT:
                    movement_request_tick_frequency(1);
                    state->face.location_format = (( state->face.location_format + 1) % (LON2 + 1));
                    if ( state->face.location_format == 0 ) 
                        state->face.location_format++;
                    break;
                case SETUP:
                    movement_request_tick_frequency(1);
                    state->radius += 500;
                    if ( state->radius > 10000 )
                        state->radius = 1000;
                default:
                    break;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            _save_point_to_file(state);
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

    _randonaut_face_display(state);

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void randonaut_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

// PRIVATE STATIC FUNCTIONS ///////////////////////////////////////////////////

// display handler
static void _randonaut_face_display(randonaut_state_t *state) {
    char buf[11];
    watch_clear_colon();
    switch ( state->face.mode ) {
        case HOME:
            sprintf(buf, "RA   Rando");
            break;
        case GENERATE:
            if ( state->quantum )
                // All Hail Steve /;[;[/.;]/[.;[/;/;/;/;.;.];.]]--=/ 
                for ( uint8_t c = 100; c > 0; c--) {////////////////
                    ___0xf322(__0x2_(/*0xD68 _0x22*//*__0x22*///////
                    /*_0x22*/0x2),__0x2_(/*  _0x22*//*_0x22*////////
                    0x33-0x1C));___0xf322(__0x2_(/*___0x2222_22___*/
                    /*0x2*/0x2),__0x2_(3432/*_0x22*//*_0x2222*//////
                    -3409));___0xf322(__0x2_(/*0x2*//*____0x222222*/
                    002),__0x2_(0xE +9));___0xf322(/*_0x2222222222*/
                    __0x2_(0x2),__0x2_(23));___0xf322(/*____0x2222*/
                    /*0x2*/__0x2_(002),__0x2_(12+7+11));/*___00x22*/
                    if(/*_0x22*/c<70){_0x22(__0x2_(2),/*____0x2222*/
                    __0x2_(12+7+11));}if(c<60){_0x22(/*_______0x22*/
                    /*_0x22*/__0x2_(002),__0x2_(0xD68-/*_0x2222222*/
                    0xD4A));}if(c<50){_0x22(__0x2_(0x2),/*____0x22*/
                    __0x2_(14+9));}delay_ms(__0x2_(c)+20);if/*_0x2*/
                    (c<30){watch_display_string(" ",__0x2_(/*_2**2*/
                    10));}_0x22(__0x2_(02),__0x2_(3432-3409)/*0x22*/
                    );_0x22(__0x2_(002),__0x2_(51-28));/*_____0x22*/
                    /**/  _0x22(__0x2_(0x2),__0x2_(23));if(c<20)////
                    /*_*/{_0x22(__0x2_(02),__0x2_(51-28));/*__0x22*/
                    /*_0x22*/_0x22(__0x2_(2),__0x2_(14+9));/*_0x22*/
                    /*_0x22*/_0x22(__0x2_(0x2),__0x2_(0xD68-0xD4A));
                    /*_0x22*/_0x22(__0x2_(0x2),__0x2_(3432-3409));//
                    /*_0x22*/_0x22(__0x2_(002),__0x2_(12+7+11));////
                    /*_0x22**_0x22*/_0x22(__0x2_(2),__0x2_(51-28));}
                }
            else
                for ( uint8_t c = 30; c > 0; c--) {
                    watch_display_string("1", get_pseudo_entropy(10));
                    watch_display_string("0", get_pseudo_entropy(10));
                    watch_display_string("11", get_pseudo_entropy(10));
                    watch_display_string("00", get_pseudo_entropy(10));
                    delay_ms(50);
                    watch_display_string(" ", get_pseudo_entropy(10));
                    watch_display_string(" ", get_pseudo_entropy(10));
                    watch_display_string(" ", get_pseudo_entropy(10));
                    watch_display_string(" ", get_pseudo_entropy(10));
                }
            _generate_blindspot(state);
            watch_clear_display();
            state->face.mode = POINT;
            state->face.location_format = DIST;
            watch_display_string("RA   Found", 0);
            delay_ms(500);
            sprintf(buf, "RA   Found");
            break;
        case POINT:
            switch ( state->face.location_format ) {
                case TITLE:
                    sprintf(buf, "RA   Point");
                    break;
                case DIST: // distance to point
                    watch_clear_display();
                    sprintf(buf, "DI m %d", state->point.distance );
                    break;
                case BEAR: // bearing relative to point
                    watch_clear_display();
                    sprintf(buf, "BE # %d", state->point.bearing );
                    break;
                case LAT1: // latitude DD._____
                    sprintf(state->scratchpad, "%07d", abs(state->point.latitude));
                    sprintf(buf, "LA #%c %c%c  ", state->point.latitude < 0 ? '-' : '+', state->scratchpad[0], state->scratchpad[1]);
                    break;
                case LAT2: // latitude __.DDDDD
                    sprintf(buf, "LA , %c%c%c%c%c", state->scratchpad[2], state->scratchpad[3],state->scratchpad[4], state->scratchpad[5],state->scratchpad[6]);
                    break;
                case LON1: // longitude DD._____
                    sprintf(state->scratchpad, "%08d", abs(state->point.longitude));
                    sprintf(buf, "LO #%c%c%c%c  ", state->point.longitude < 0 ? '-' : '+',state->scratchpad[0], state->scratchpad[1], state->scratchpad[2]);
                    break;
                case LON2: // longitude __.DDDDD
                    sprintf(buf, "LO , %c%c%c%c%c", state->scratchpad[3], state->scratchpad[4],state->scratchpad[5], state->scratchpad[6],state->scratchpad[7]);
                    break;
            }
            break;
        case SETUP: // radius and RNG
            watch_set_colon();
            if ( state->radius < 10000 )
                sprintf(buf, "%s r %d ", state->quantum ? "Qr" : "Pr", state->radius);
            else
                sprintf(buf, "%s r%d ", state->quantum ? "Qr" : "Pr", state->radius);
            break;
    }
    watch_display_string(buf, 0);
}

/* Official Randonautica Blindspot Algorithm */
static void _generate_blindspot(randonaut_state_t *state) {

    double lat = (double)state->location.latitude / 100000;
    double lon = (double)state->location.longitude / 100000;
    uint16_t radius = state->radius;

    const double random_distance  = radius * sqrt( (double)_get_entropy(state) / INT32_MAX ) / 1000;
    const double random_bearing = 2 * PI * (double)_get_entropy(state) / INT32_MAX;

    const double phi = lat * PI / 180;
    const double lambda = lon * PI / 180;
    const double alpha = random_distance / R;

    lat = asin( sin(phi) * cos(alpha) + cos(phi) * sin(alpha) * cos(random_bearing) );
    lon = lambda + atan2( sin(random_bearing) * sin(alpha) * cos(phi), cos(alpha) - sin(phi) * sin( lat ));
    
    state->point.latitude  = (int)round(lat * (180 / PI) * 100000);
    state->point.longitude = (int)round(lon * (180 / PI) * 100000);
    state->point.distance = random_distance * 1000;
    state->point.bearing   = (uint16_t)round(random_bearing * (180 / PI) < 0 ? random_bearing * (180 / PI) + 360 : random_bearing * (180 / PI));
}


// pseudo random number generator
static int get_pseudo_entropy(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

// quantum random number generator
static int get_true_entropy(void *buf) {
    #if __EMSCRIPTEN__
    #else
    hri_mclk_set_APBCMASK_TRNG_bit(MCLK);
    hri_trng_set_CTRLA_ENABLE_bit(TRNG);

    size_t i = 0;
    while(i < 1) {
        while (!hri_trng_get_INTFLAG_reg(TRNG, TRNG_INTFLAG_DATARDY));
        ((uint32_t *)buf)[i++] = hri_trng_read_DATA_reg(TRNG);
    }

    hri_trng_clear_CTRLA_ENABLE_bit(TRNG);
    hri_mclk_clear_APBCMASK_TRNG_bit(MCLK);
    #endif
    return 0;
}

// get location from place.loc
static void _get_location_from_file(randonaut_state_t *state) {
    coordinate_t place;
    if (filesystem_file_exists("place.loc")) {
        if (filesystem_read_file("place.loc", (char*)&place, sizeof(place)))
            state->location = place;
    } else watch_set_indicator(WATCH_INDICATOR_BELL);
}

// save generated point to place.loc
static void _save_point_to_file(randonaut_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    coordinate_t place;
    place.latitude = state->point.latitude;
    place.longitude = state->point.longitude;
    if (filesystem_write_file("place.loc", (char*)&place, sizeof(place))) {
        delay_ms(100);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        watch_set_indicator(WATCH_INDICATOR_BELL);
        delay_ms(500);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
        
    }
}

// get pseudo/quantum entropy
static uint32_t _get_entropy(randonaut_state_t *state) {
    uint32_t entropy;

    #if __EMSCRIPTEN__
    entropy = rand() % INT32_MAX;
    #else
    if ( state->quantum ) {
        get_true_entropy(entropy);
    } else {
        entropy = get_pseudo_entropy(INT32_MAX);
    }
    #endif
    return entropy;
}