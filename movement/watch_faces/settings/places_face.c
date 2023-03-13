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
#include "places_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define LAST_PAGE 1

static int16_t _places_face_latlon_from_struct(places_location_state_t val) {
    int16_t retval = (val.sign ? -1 : 1) *
                        (
                            val.hundreds * 10000 +
                            val.tens * 1000 +
                            val.ones * 100 +
                            val.tenths * 10 +
                            val.hundredths
                        );
    return retval;
}

static places_location_state_t _places_face_struct_from_latlon(int16_t val) {
    places_location_state_t retval;

    retval.sign = val < 0;
    val = abs(val);
    retval.hundredths = val % 10;
    val /= 10;
    retval.tenths = val % 10;
    val /= 10;
    retval.ones = val % 10;
    val /= 10;
    retval.tens = val % 10;
    val /= 10;
    retval.hundreds = val % 10;

    return retval;
}

static void _places_face_update_location_register(places_state_t *state) {
    if (state->location_changed) {
        movement_location_t movement_location;
        int16_t lat = _places_face_latlon_from_struct(state->working_latitude);
        int16_t lon = _places_face_latlon_from_struct(state->working_longitude);
        movement_location.bit.latitude = lat;
        movement_location.bit.longitude = lon;
        watch_store_backup_data(movement_location.reg, 1);
        state->location_changed = false;
    }
}

static void _places_face_update_latlon_settings_display(movement_event_t event, places_state_t *state) {
    char buf[12];

    switch (state->page) {
        case 0:
            sprintf(buf, "LA  %c %04d", state->working_latitude.sign ? '-' : '+', abs(_places_face_latlon_from_struct(state->working_latitude)));
            break;
        case 1:
            sprintf(buf, "LO  %c%05d", state->working_longitude.sign ? '-' : '+', abs(_places_face_latlon_from_struct(state->working_longitude)));
            break;
    }
    if (event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

static void _places_face_advance_latlon_digit(places_state_t *state) {
    state->location_changed = true;
    switch (state->page) {
        case 0: // latitude
            switch (state->active_digit) {
                case 0:
                    state->working_latitude.sign++;
                    break;
                case 1:
                    // we skip this digit
                    break;
                case 2:
                    state->working_latitude.tens = (state->working_latitude.tens + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_latitude)) > 9000) {
                        // prevent latitude from going over ±90.
                        // TODO: perform these checks when advancing the digit?
                        state->working_latitude.ones = 0;
                        state->working_latitude.tenths = 0;
                        state->working_latitude.hundredths = 0;
                    }
                    break;
                case 3:
                    state->working_latitude.ones = (state->working_latitude.ones + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_latitude)) > 9000) state->working_latitude.ones = 0;
                    break;
                case 4:
                    state->working_latitude.tenths = (state->working_latitude.tenths + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_latitude)) > 9000) state->working_latitude.tenths = 0;
                    break;
                case 5:
                    state->working_latitude.hundredths = (state->working_latitude.hundredths + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_latitude)) > 9000) state->working_latitude.hundredths = 0;
                    break;
            }
            break;
        case 1: // longitude
            switch (state->active_digit) {
                case 0:
                    state->working_longitude.sign++;
                    break;
                case 1:
                    state->working_longitude.hundreds = (state->working_longitude.hundreds + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_longitude)) > 18000) {
                        // prevent longitude from going over ±180
                        state->working_longitude.tens = 8;
                        state->working_longitude.ones = 0;
                        state->working_longitude.tenths = 0;
                        state->working_longitude.hundredths = 0;
                    }
                    break;
                case 2:
                    state->working_longitude.tens = (state->working_longitude.tens + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.tens = 0;
                    break;
                case 3:
                    state->working_longitude.ones = (state->working_longitude.ones + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.ones = 0;
                    break;
                case 4:
                    state->working_longitude.tenths = (state->working_longitude.tenths + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.tenths = 0;
                    break;
                case 5:
                    state->working_longitude.hundredths = (state->working_longitude.hundredths + 1) % 10;
                    if (abs(_places_face_latlon_from_struct(state->working_longitude)) > 18000) state->working_longitude.hundredths = 0;
                    break;
            }
            break;
    }
}

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
    state->working_latitude = _places_face_struct_from_latlon(movement_location.bit.latitude);
    state->working_longitude = _places_face_struct_from_latlon(movement_location.bit.longitude);
}

bool places_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    places_state_t *state = (places_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            state->page = 0;
            state->active_digit = 0;
            movement_request_tick_frequency(4);
            _places_face_update_latlon_settings_display(event, context);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            // if entering low energy mode, start tick animation
            if (event.event_type == EVENT_LOW_ENERGY_UPDATE && !watch_tick_animation_is_running()) watch_start_tick_animation(1000);
            // check if we need to update the display
            _places_face_update_latlon_settings_display(event, state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            state->active_digit++;
            if (state->page == 0 && state->active_digit == 1) state->active_digit++; // max latitude is +- 90, no hundreds place
            if (state->active_digit > 5) {
                state->active_digit = 0;
                state->page = (state->page + 1) % 2;
                _places_face_update_location_register(state);
            }
            _places_face_update_latlon_settings_display(event, context);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            state->active_digit--;
            if (state->page == 0 && state->active_digit == 1) state->active_digit--; // max latitude is +- 90, no hundreds place
            if (state->active_digit < 0) {
                state->active_digit = 5;
                state->page = (state->page + 1) % 2;
                _places_face_update_location_register(state);
            }
            _places_face_update_latlon_settings_display(event, context);
            break;
        case EVENT_ALARM_BUTTON_UP:
            _places_face_advance_latlon_digit(state);
            _places_face_update_latlon_settings_display(event, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
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

