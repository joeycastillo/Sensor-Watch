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

static void _get_location_from_file(randonaut_state_t *state);
static void _save_point_to_file(randonaut_state_t *state);
static void _get_entropy(randonaut_state_t *state);
static void _generate_blindspot(randonaut_state_t *state);
static void _randonaut_face_display(randonaut_state_t *state);
static void _generate_blindspot(randonaut_state_t *state);
static uint32_t _get_pseudo_entropy(uint32_t max);
static uint32_t _get_true_entropy(void);
static void _get_entropy(randonaut_state_t *state);

// MOVEMENT WATCH FACE FUNCTIONS //////////////////////////////////////////////

void randonaut_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
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
    state->face.mode = 0;
    state->radius = 1000;
    _get_entropy(state);
    state->chance = true;
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
                case 0: // home
                    state->face.mode = 2; //point
                    state->face.location_format = 0; // title
                    break;
                case 1: // generate
                    state->face.mode = 0; //home
                    break;
                case 2: // point
                    state->face.mode = 0; //home
                    break;
                case 3: // setup radius
                    state->face.mode = 4; // toggle to RNG
                    break;
                case 4: // setup RNG
                    state->face.mode = 3; // toggle to Radius
                    break;
                case 5: // data processing
                    break;
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            switch ( state->face.mode ) {
                case 3: // setup
                case 4:
                    state->face.mode = 0; //home
                    break;
                default:
                    state->face.mode = 3; //setup
                    watch_clear_display();
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch ( state->face.mode ) {
                case 0: //home
                    state->face.mode = 1; // generate
                    break;
                case 2: // point
                    state->face.location_format = (( state->face.location_format + 1) % (7));
                    if ( state->face.location_format == 0 ) 
                        state->face.location_format++;
                    break;
                case 3: //setup radius
                    state->radius += 500;
                    if ( state->radius > 10000 )
                        state->radius = 1000;
                    break;
                case 4: //setup RNG
                    state->face.rng = (state->face.rng + 1) % 3;
                    switch ( state->face.rng ) {
                        case 0:
                            state->chance = true;
                            break;
                        case 1:
                            state->chance = false;
                            state->quantum = true;
                            break;
                        case 2:
                            state->chance = false;
                            state->quantum = false;
                            break;
                    }
                    break;
                case 5: // data processing
                    _save_point_to_file(state);
                    break;
                default:
                    break;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if ( state->face.mode == 5 )
                state->face.mode = 0; // home
            else
                state->face.mode = 5; // data processing
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

/** @brief display handler
 */
static void _randonaut_face_display(randonaut_state_t *state) {
    char buf[12];
    watch_clear_colon();
    switch ( state->face.mode ) {
        case 0: //home
            sprintf(buf, "RA   Rando");
            break;
        case 1: //generate
            if ( state->quantum )
                // All Hail Steve /;[;[/.;]/[.;[/;/;/;/;.;.];.]]--=/ 
                for ( uint8_t c = 100; c > 0; c--) {
                    watch_set_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(0x33-0x1C));
                    watch_set_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(3432-3409));
                    watch_set_pixel(_get_pseudo_entropy(002),_get_pseudo_entropy(0xE +9));
                    watch_set_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(23));
                    watch_set_pixel(_get_pseudo_entropy(002),_get_pseudo_entropy(12+7+11));
                    if( c < 70 ) {
                        watch_clear_pixel(_get_pseudo_entropy(2),_get_pseudo_entropy(12+7+11));
                    }
                    if ( c < 60 ) {
                        watch_clear_pixel(_get_pseudo_entropy(002),_get_pseudo_entropy(0xD68-0xD4A));
                    }
                    if ( c < 50 ) { 
                        watch_clear_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(14+9));
                    }
                    delay_ms(_get_pseudo_entropy(c)+20);
                    if ( c < 30 ) {
                        watch_display_string(" ",_get_pseudo_entropy(10));
                    }
                    watch_clear_pixel(_get_pseudo_entropy(02),_get_pseudo_entropy(3432-3409));
                    watch_clear_pixel(_get_pseudo_entropy(002),_get_pseudo_entropy(51-28));
                    watch_clear_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(23));
                    if ( c < 20 ) {
                        watch_clear_pixel(_get_pseudo_entropy(02),_get_pseudo_entropy(51-28));
                        watch_clear_pixel(_get_pseudo_entropy(2),_get_pseudo_entropy(14+9));
                        watch_clear_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(0xD68-0xD4A));
                        watch_clear_pixel(_get_pseudo_entropy(0x2),_get_pseudo_entropy(3432-3409));
                        watch_clear_pixel(_get_pseudo_entropy(002),_get_pseudo_entropy(12+7+11));
                        watch_clear_pixel(_get_pseudo_entropy(2),_get_pseudo_entropy(51-28));
                    }
                }
            else
                for ( uint8_t c = 30; c > 0; c--) {
                    watch_display_string("1", _get_pseudo_entropy(10));
                    watch_display_string("0", _get_pseudo_entropy(10));
                    watch_display_string("11", _get_pseudo_entropy(10));
                    watch_display_string("00", _get_pseudo_entropy(10));
                    delay_ms(50);
                    watch_display_string(" ", _get_pseudo_entropy(10));
                    watch_display_string(" ", _get_pseudo_entropy(10));
                    watch_display_string(" ", _get_pseudo_entropy(10));
                    watch_display_string(" ", _get_pseudo_entropy(10));
                }
            _generate_blindspot(state);
            watch_clear_display();
            state->face.mode = 2; // point
            state->face.location_format = 1; // distance
            watch_display_string("RA   Found", 0);
            delay_ms(500);
            sprintf(buf, "RA   Found");
            break;
        case 2: //point
            switch ( state->face.location_format ) {
                case 0:
                    sprintf(buf, "RA   Point");
                    break;
                case 1: // distance to point
                    watch_clear_display();
                    sprintf(buf, "DI m %d", state->point.distance );
                    break;
                case 2: // bearing relative to point
                    watch_clear_display();
                    sprintf(buf, "BE # %d", state->point.bearing );
                    break;
                case 3: // latitude DD._____
                    sprintf(state->scratchpad, "%07d", abs((int32_t)(state->point.latitude)));
                    sprintf(buf, "LA #%c %c%c  ", state->point.latitude < 0 ? '-' : '+', state->scratchpad[0], state->scratchpad[1]);
                    break;
                case 4: // latitude __.DDDDD
                    sprintf(buf, "LA , %c%c%c%c%c", state->scratchpad[2], state->scratchpad[3],state->scratchpad[4], state->scratchpad[5],state->scratchpad[6]);
                    break;
                case 5: // longitude DD._____
                    sprintf(state->scratchpad, "%08d", abs((int32_t)(state->point.longitude)));
                    sprintf(buf, "LO #%c%c%c%c  ", state->point.longitude < 0 ? '-' : '+',state->scratchpad[0], state->scratchpad[1], state->scratchpad[2]);
                    break;
                case 6: // longitude __.DDDDD
                    sprintf(buf, "LO , %c%c%c%c%c", state->scratchpad[3], state->scratchpad[4],state->scratchpad[5], state->scratchpad[6],state->scratchpad[7]);
                    break;
            }
            break;
        case 3: // setup radius
            watch_set_colon();
            if ( state->radius < 10000 )
                sprintf(buf, "RA m %d ", state->radius);
            else
                sprintf(buf, "RA m%d ", state->radius);
            break;
        case 4: // setup RNG
            sprintf(buf, "RN G %s ", state->chance ? "Chnce" : (state->quantum ? "True" : "Psudo"));
            break;
        case 5: // data processing
            sprintf(buf, "WR   File ");
    }
    watch_display_string(buf, 0);
}

/** @brief Official Randonautica Blindspot Algorithm
 */
static void _generate_blindspot(randonaut_state_t *state) {

    _get_entropy(state);

    double lat = (double)state->location.latitude / 100000;
    double lon = (double)state->location.longitude / 100000;
    uint16_t radius = state->radius;

    const double random_distance  = radius * sqrt( (double)state->entropy / INT32_MAX ) / 1000.0;
    const double random_bearing = 2.0 * PI * (double)state->entropy / INT32_MAX;

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


/** @brief pseudo random number generator
 */
static uint32_t _get_pseudo_entropy(uint32_t max) {
    #if __EMSCRIPTEN__
    return rand() % max;
    #else
    return arc4random_uniform(max);
    #endif
}

/** @brief true random number generator
 */
static uint32_t _get_true_entropy(void) {
    #if __EMSCRIPTEN__
    return rand() % INT32_MAX;
    #else
    hri_mclk_set_APBCMASK_TRNG_bit(MCLK);
    hri_trng_set_CTRLA_ENABLE_bit(TRNG);

    while (!hri_trng_get_INTFLAG_reg(TRNG, TRNG_INTFLAG_DATARDY)); // Wait for TRNG data to be ready

    watch_disable_TRNG();
    hri_mclk_clear_APBCMASK_TRNG_bit(MCLK);
    return hri_trng_read_DATA_reg(TRNG); // Read a single 32-bit word from TRNG and return it
    #endif
}

/** @brief get location from place.loc
 */
static void _get_location_from_file(randonaut_state_t *state) {
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    coordinate_t place;
    if (filesystem_file_exists("place.loc")) {
        if (filesystem_read_file("place.loc", (char*)&place, sizeof(place)))
            state->location = place;
    } else {
        watch_set_indicator(WATCH_INDICATOR_BELL);
        state->location.latitude = movement_location.bit.latitude * 1000;
        state->location.longitude = movement_location.bit.longitude * 1000;
    }
}

/** @brief save generated point to place.loc
 */
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

/** @brief get pseudo/quantum entropy and filter modulo bias
 */
static void _get_entropy(randonaut_state_t *state) {
    if ( state->chance ) {
        state->quantum = (bool)(state->entropy % 2);
    }   
    do {
        if ( !state->quantum ) {
            state->entropy = _get_pseudo_entropy(INT32_MAX);
        } else {
            state->entropy = _get_true_entropy();
        }
    } while (state->entropy >= INT32_MAX || state->entropy <= 0);
    state->entropy %= INT32_MAX;
}