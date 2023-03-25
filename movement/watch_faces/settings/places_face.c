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
#include "places_face.h"

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

// STATIC HELPER FUNCTION DECLARATION /////////////////////////////////////////

// (descriptions in the function definitions below)
static void _convert_name_struct_to_string(char *buf, places_name_t name);
static void _places_face_update_display(movement_event_t event, places_state_t *state);
static void _places_face_advance_name_digit(places_state_t *state);
static void _data_load_place_from_register(places_state_t *state);
static void _data_load_place_from_file(places_state_t *state);
static void _data_save_place_to_register(places_state_t *state);
static void _data_save_place_to_file(places_state_t *state);
static bool _quick_ticks_running;
static void _abort_quick_ticks();

// MOVEMENT WATCH FACE FUNCTIONS //////////////////////////////////////////////

void places_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(places_state_t));
        memset(*context_ptr, 0, sizeof(places_state_t));
        places_state_t *state = (places_state_t *)*context_ptr;
    
        for (uint8_t i = 0; i < 5; i++) {
            state->places[i].name.d01 = 12;
            state->places[i].name.d02 = 15;
            state->places[i].name.d03 =  3;
            state->places[i].name.d04 = 28;
            state->places[i].name.d05 =  i + 29;
        }

        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void places_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    if (watch_tick_animation_is_running()) watch_stop_tick_animation();
    movement_request_tick_frequency(4);
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

}

bool places_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    places_state_t *state = (places_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            movement_request_tick_frequency(4);
            state->active_digit = 1;
            state->place = 0;
            _data_load_place_from_file(state);
            state->clipboard = state->places[state->place];
            _places_face_update_display(event, state);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            // if entering low energy mode, start tick animation
            if (event.event_type == EVENT_LOW_ENERGY_UPDATE && !watch_tick_animation_is_running()) watch_start_tick_animation(1000);
            // check if we need to update the display
            if ( state->edit ) {
                // in Edit or Digit Info modes, refresh every tick to show blinking cursors
                _places_face_update_display(event, state);
                if (_quick_ticks_running) {
                    if (watch_get_pin_level(BTN_ALARM)) _places_face_advance_name_digit(state);
                    else _abort_quick_ticks();
                }
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            _abort_quick_ticks();
            // flips through the different display modes for each place
            // increments active digit when in Edit or Display Info auxiliary modes
            if ( state->edit ) {
                state->active_digit = ((state->active_digit + 1) % 6);
                if ( state->active_digit == 0 ) state->active_digit++;
            }
            // update display
            _places_face_update_display(event, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // toggle Edit auxiliary mode
            state->edit = !state->edit;

            if ( !state->edit ) { // leaving edit mode saves data in state
                state->places[state->place] = state->clipboard;
            }
            // update display
            _places_face_update_display(event, state);
            break;
        case EVENT_ALARM_BUTTON_UP:
            if ( _quick_ticks_running ) {
                _abort_quick_ticks();
                break;
            }
            // Flips through the 5 available places
            // In Edit mode increments the selected digit

            if ( state->edit )
                _places_face_advance_name_digit(state);
            else {
                state->place = (state->place + 1) % 5;
                state->clipboard = state->places[state->place];
            }
            // update display
            _places_face_update_display(event, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if ( state->place != 0 && !state->edit) {
                // swap current place with selected place
                state->places[state->place] = state->places[0];
                state->places[0] = state->clipboard;

                state->clipboard = state->places[state->place];
                _data_save_place_to_register(state);
                _data_save_place_to_file(state);
                
            }
            // Discards changes in Edit mode

            if ( state->edit ) {
                // discard changes
                //state->edit = false;
                //state->clipboard = state->places[state->place];
                _quick_ticks_running = true;
                movement_request_tick_frequency(8);
            }
            _places_face_update_display(event, state);
            break;
        case EVENT_ALARM_LONG_UP:
            _abort_quick_ticks();
            break;
        case EVENT_MODE_BUTTON_UP:
            _abort_quick_ticks();
            movement_move_to_next_face();
            return false;
        case EVENT_TIMEOUT:
            _abort_quick_ticks();
            movement_move_to_face(0);
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
    state->active_digit = 0;
    movement_event_t e = {EVENT_ALARM_BUTTON_UP, 0};
    places_face_loop(e, settings, context);
    // handle any cleanup before your watch face goes off-screen.
}

// PRIVATE STATIC FUNCTION DEFINITIONS ////////////////////////////////////////

/** @brief convert internal place name struct to char array
 */
static void _convert_name_struct_to_string(char *buf, places_name_t name) {
    buf[0] = name_alphabet[name.d01];
    buf[1] = name_alphabet[name.d02];
    buf[2] = name_alphabet[name.d03];
    buf[3] = name_alphabet[name.d04];
    buf[4] = name_alphabet[name.d05];
}

/** @brief Display Place Name
 */
static void _places_face_update_display(movement_event_t event, places_state_t *state) {
    char buf[12];
    char name[6] = {0};
    _convert_name_struct_to_string(name, state->clipboard.name);
    
    sprintf(buf, "PL %d %c%c%c%c%c", state->place + 1, name[0], name[1], name[2], name[3], name[4]);
    
    if (state->edit && !_quick_ticks_running && event.subsecond % 2) {
        buf[state->active_digit + 4] = ' ';
    }
    watch_display_string(buf, 0);
}

/** @brief Place Name Editor
 */
static void _places_face_advance_name_digit(places_state_t *state) {
    switch (state->active_digit) {
        case 0:
            // we skip this digit
            break;
        case 1:
            state->clipboard.name.d01 = (state->clipboard.name.d01 + 1) % 38;
            break;
        case 2:
            state->clipboard.name.d02 = (state->clipboard.name.d02 + 1) % 38;
            break;
        case 3:
            state->clipboard.name.d03 = (state->clipboard.name.d03 + 1) % 38;
            break;
        case 4:
            state->clipboard.name.d04 = (state->clipboard.name.d04 + 1) % 38;
            break;
        case 5:
            state->clipboard.name.d05 = (state->clipboard.name.d05 + 1) % 38;
            break;
    }
}

/** @brief load coordinate from location register into selected place slot
 */
static void _data_load_place_from_register(places_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    movement_location_t movement_location = (movement_location_t) watch_get_backup_data(1);
    state->places[state->place].location.latitude = movement_location.bit.latitude * 1000;
    state->places[state->place].location.longitude = movement_location.bit.longitude * 1000;
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

/** @brief save coordinate to location register from selected place slot (truncated to 2 decimal points)
 */
static void _data_save_place_to_register(places_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    movement_location_t movement_location;
    int16_t lat = state->places[0].location.latitude;
    int16_t lon = state->places[0].location.longitude;
    movement_location.bit.latitude = lat;
    movement_location.bit.longitude = lon;
    watch_store_backup_data(movement_location.reg, 1);
    delay_ms(100);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

/** @brief load coordinate from LFS file into selected place slot
 */
static void _data_load_place_from_file(places_state_t *state) {
    coordinate_t place;
    if (filesystem_file_exists("place.loc"))
        if (filesystem_read_file("place.loc", (char*)&place, sizeof(place))) {
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            state->places[state->place].location = place;
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        } else {
            watch_set_indicator(WATCH_INDICATOR_BELL);
            watch_clear_indicator(WATCH_INDICATOR_BELL);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_set_indicator(WATCH_INDICATOR_BELL);
        _data_load_place_from_register(state);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
}

/** @brief save coordinate to LFS file from selected place slot
 */
static void _data_save_place_to_file(places_state_t *state) {
    watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    coordinate_t place;
    place = state->places[0].location;
    if (filesystem_write_file("place.loc", (char*)&place, sizeof(place))) {
        delay_ms(200);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_set_indicator(WATCH_INDICATOR_BELL);
        delay_ms(1000);
        watch_clear_indicator(WATCH_INDICATOR_BELL);
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
        
    }
}

/** @brief abort quick ticks
 */
static void _abort_quick_ticks() {
    if (_quick_ticks_running) {
        _quick_ticks_running = false;
        movement_request_tick_frequency(4);
    }
}