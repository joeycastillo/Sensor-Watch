/*
 * MIT License
 *
 * Copyright (c) 2024 Patrick, building on Josh Berson's wake_face.c
 * Copyright (c) 2022 Josh Berson, building on Wesley Ellis’ countdown_face.c
 * Copyright (c) 2022 Wesley Ellis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
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
#include "beer_o_clock_face.h"
#include "watch.h"
#include "watch_utility.h"

//
// Private
//

static
void _beer_o_clock_face_update_display(movement_settings_t *settings, beer_o_clock_face_state_t *state) {
    (void) settings;
    uint8_t hour = state->hour;

    watch_clear_display();
    if ( settings->bit.clock_mode_24h )
        watch_set_indicator(WATCH_INDICATOR_24H);
    else {
        if ( hour >= 12 )
            watch_set_indicator(WATCH_INDICATOR_PM);
        hour = hour % 12 ? hour % 12 : 12;
    }

    if ( state->mode )
        watch_set_indicator(WATCH_INDICATOR_BELL);

    static char lcdbuf[11];
    sprintf(lcdbuf, "    %2d%02d  ", hour, state->minute);

    watch_set_colon();
    watch_display_string(lcdbuf, 0);
}

//
// Exported
//

void beer_o_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(beer_o_clock_face_state_t));
        beer_o_clock_face_state_t *state = (beer_o_clock_face_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(beer_o_clock_face_state_t));

        state->hour = 17;
        state->minute = 0;
        state->mode = 0;
        state->using = false;
        state->ticks = 0;
    }
}

void beer_o_clock_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    beer_o_clock_face_state_t *state = (beer_o_clock_face_state_t *)context;
    state->using = false;
    state->ticks = 0;

}
void beer_o_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool beer_o_clock_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    beer_o_clock_face_state_t *state = (beer_o_clock_face_state_t *)context;

    bool rc = false;
    if ( state->mode ) {
        watch_date_time now = watch_rtc_get_date_time();
        rc = state->hour==now.unit.hour && state->minute==now.unit.minute;
        // We’re at the mercy of the wants_background_task handler
        // In Safari, the emulator triggers at the ›end‹ of the minute
        // Converting to Unix timestamps and taking a difference between now and
        // beer_o_clock is not an easy win — because the timestamp for 
        // beer_o_clock has to rely on now for its date. So first we’d have to 
        // see if the TOD of beer_o_clock is after that of now. If it is, take 
        // tomorrow’s date, calculating month and year rollover if need be.
    }
    return rc;
}

bool beer_o_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    beer_o_clock_face_state_t *state = (beer_o_clock_face_state_t *)context;

    switch (event.event_type) {
    case EVENT_ACTIVATE:
         watch_display_string("     beer ", 0);
         break;
    case EVENT_TICK:
        if (!state->using) {
            switch (state->ticks % 3) {
                case 0:
                    watch_display_string("     -o-  ", 0);
                    break;
                case 1:
                    watch_display_string("    clock ", 0);
                    break;
                case 2:
                    watch_display_string("     beer ", 0);
                    break;
            }
        }
        state->ticks = (state->ticks + 1) % 3;
        break;
    case EVENT_LIGHT_BUTTON_UP:
        if (!state->using) {
            state->using = true;
            _beer_o_clock_face_update_display(settings, state);
        } else {
            state->hour = (state->hour + 1) % 24;
            _beer_o_clock_face_update_display(settings, state);
        }
        break;
    case EVENT_LIGHT_LONG_PRESS:
        state->hour = (state->hour + 6) % 24;
        _beer_o_clock_face_update_display(settings, state);
        break;
    case EVENT_ALARM_BUTTON_UP:
        if (!state->using) {
            state->using = true;
            _beer_o_clock_face_update_display(settings, state);
        } else {
            state->minute = (state->minute + 5) % 60;
            _beer_o_clock_face_update_display(settings, state);
        }
        break;
    case EVENT_ALARM_LONG_PRESS:
        state->mode ^= 1;
        _beer_o_clock_face_update_display(settings, state);
        break;
    case EVENT_BACKGROUND_TASK:
        movement_play_alarm();
        break;
    case EVENT_TIMEOUT:
        movement_move_to_face(0);
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        // Don't use the LED on this face
        break;
    case EVENT_LOW_ENERGY_UPDATE:
        break;
    default:
        movement_default_loop_handler(event, settings);
        break;
    }

    return true;
}
