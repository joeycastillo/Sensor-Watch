/*
 * MIT License
 *
 * Copyright (c) 2022 Josh Berson, building on Wesley Ellis’ countdown_face.c
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

//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>
// #include <threads.h>

#include "interval_face.h"
#include "watch.h"
#include "watch_utility.h"

/*
    UI Notes
    º When the timer is inactive, Light advances the caret
    º When the timer is active or paused, Light activates the light
    º Light long press activates the light
    º When the timer is inactive and the caret active, Alarm advances the value of the selected field
    º When the timer is inactive and the caret inactive, Alarm shifts the timer status to active
    º When the timer is active or paused, Alarm toggles the timer status between active and paused
    º When the timer is inactive, Alarm long press toggles between the two modes, second and minute
    º When the timer is active or paused, Alarm long press shifts the timer status to inactive
      (and resets the counters)
    º In second mode, splits are in seconds, adjusted by 1s
    º In minute mode, splits are in minutes, adjusted by 5m

    TODO
    º Manage activity states
    º Update display
    º Background tasks
*/

//
// Private
//

// FIXME REWRITE, INTEGRATE
static
void _interval_face_restart(interval_face_state_t *state, movement_settings_t *settings) {
    watch_date_time now = watch_rtc_get_date_time();
    int8_t length = (int8_t) get_length(state);

    state->mode = tomato_run;
    state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    state->target_ts = watch_utility_offset_timestamp(state->now_ts, 0, length, 0);
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(state->target_ts, get_tz_offset(settings));
    movement_schedule_background_task(target_dt);
    watch_set_indicator(WATCH_INDICATOR_BELL);
}


static
void _interval_face_update_display(movement_settings_t *settings, interval_face_state_t *state) {
    const char[] legend = { 'I', 'S', 0, 0, 0, 'I', 'M', 0 };
    const char[] activity_status = { ' ', 'A', 'P' };

    (void) settings;

    watch_clear_display();

    uint8_t offset = state->mode * INTERVAL_FACE_MODE_OFFSET;

    // if active ... if paused 

    static char lcdbuf[11];
    sprintf(lcdbuf, "%s %c%2d%2d%2d",
        &legend[offset],
        activity_status[state->status],
        // if active ... if paused ...
        state->mode ? 'o' : ' ',
        hour, state->minute);

    watch_set_colon();
    watch_display_string(lcdbuf, 0);
}

//
// Exported
//

void interval_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(interval_face_state_t));
        interval_face_state_t *state = (interval_face_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(interval_face_state_t));

        state->data = { 30, 30, 8, 1, 1, 25, 5, 2, 60, 5 };
        state->mode = 0;
        state->caret = 0;
        state->status = 0;
        state->rounds_remaining = 0;
        state->current_split = 0;
        state->seconds_remaining = 0;
    }
}

void interval_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
void interval_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    interval_face_state_t *state = (interval_face_state_t *)context;
    state->caret = 0;
}

bool interval_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    interval_face_state_t *state = (interval_face_state_t *)context;

    bool rc = false;
    if ( state->mode ) {
        watch_date_time now = watch_rtc_get_date_time();
        rc = state->hour==now.unit.hour && state->minute==now.unit.minute;
        // We’re at the mercy of the wants_background_task handler
        // In Safari, the emulator triggers at the ›end‹ of the minute
        // Converting to Unix timestamps and taking a difference between now and wake
        // is not an easy win — because the timestamp for wake has to rely on now
        // for its date. So first we’d have to see if the TOD of wake is after that
        // of now. If it is, take tomorrow’s date, calculating month and year rollover
        // if need be.
    }
    return rc;
}

bool interval_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    interval_face_state_t *state = (interval_face_state_t *)context;
    uint8_t offset = state->mode * INTERVAL_FACE_MODE_OFFSET;

    switch (event.event_type) {
    case EVENT_ACTIVATE:
    case EVENT_TICK:
        _interval_face_update_display(settings, state);
        break;
    case EVENT_LIGHT_BUTTON_UP:
        if ( state->status == INTERVAL_FACE_ACTIVITY_STATE_OFF ) {
            state->caret = (state->caret + 1) % INTERVAL_FACE_CARET_MODULO;
        }
        else {
            movement_illuminate_led();
        }
        _interval_face_update_display(settings, state);
        break;
    case EVENT_LIGHT_LONG_PRESS:
        movement_illuminate_led();
        _interval_face_update_display(settings, state);
        break;
    case EVENT_ALARM_BUTTON_UP:
        // When the adjust caret is inactive, cycle the timer status
        // Off —› Active —› Paused —› Active ...
        // To switch from Active or Paused to Off, long press
        if ( state->caret == INTERVAL_FACE_CARET_NONE ) {
            switch ( state->status ) {
            case INTERVAL_FACE_ACTIVITY_STATE_OFF:
                state->status = INTERVAL_FACE_ACTIVITY_STATE_ACTIVE;
                break;
            case INTERVAL_FACE_ACTIVITY_STATE_ACTIVE:
                state->status = INTERVAL_FACE_ACTIVITY_STATE_PAUSED;
                break;
            case INTERVAL_FACE_ACTIVITY_STATE_PAUSED:
                state->status = INTERVAL_FACE_ACTIVITY_STATE_ACTIVE;
                break;
            default: break;
            }
            switch ( state->status ) {
            case INTERVAL_FACE_ACTIVITY_STATE_ACTIVE:
                state->rounds_remaining = state->data[offset + INTERVAL_FACE_CARET_N_ROUNDS];
                state->current_split = 0;
                state->seconds_remaining
                    = state->data[offset + INTERVAL_FACE_SPLIT_A]
                        * state->data[offset + INTERVAL_FACE_SCALE_FACTOR];
                break;
                // TODO
            case INTERVAL_FACE_ACTIVITY_STATE_PAUSED:
                // TODO
                break;
            default: break;
            }
        }
        // Otherwise advance the value of the selected field,
        // indexing by caret and mode
        else {
            uint8_t *ptr = &( state->data[offset + (state->caret - 1)] );
            uint8_t step = state->data[offset + INTERVAL_FACE_ADJUST_STEP];
            *ptr = (*ptr + step) % 90; // Max 90 clicks per split, max 90 rounds
        }
        _interval_face_update_display(settings, state);
        break;
    case EVENT_ALARM_LONG_PRESS:
        // If the timer is Active or Paused, reset it
        if ( state->status ) {
            state->status = 0;
            state->rounds_remaining = 0;
            state->current_split = 0;
            state->seconds_remaining = 0;
            break;
        }
        // Otherwise switch timer modes (seconds to minutes, minutes to seconds)
        else {
            state->mode ^= 1;            
        }
        _interval_face_update_display(settings, state);
        break;
    case EVENT_BACKGROUND_TASK:
        // TODO
        for ( int i = 0; i < 3; ++i ) {
            movement_play_signal();
            watch_buzzer_play_note(BUZZER_NOTE_REST, 500);
        }
        break;
    case EVENT_MODE_BUTTON_UP:
        movement_move_to_next_face();
        break;
    case EVENT_TIMEOUT:
        movement_move_to_face(0);
        break;
    case EVENT_LOW_ENERGY_UPDATE:
    default:
      break;
    }

    return true;
}