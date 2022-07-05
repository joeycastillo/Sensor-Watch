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
#include <threads.h>

#include "wake_face.h"
#include "watch.h"
#include "watch_utility.h"

/*
    TODO — make it actually work

    UI Notes
    º Light advances hour by 1
    º Light long press advances hour by 6
    º Alarm advances minute by 10
    º Alarm long press cycles through signal modes
*/

//
// Private
//

static
inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static
void _wake_face_adjust(movement_settings_t *settings, wake_face_state_t *state, wake_face_action_t action) {
    (void) settings;
    switch(action) {
    case wake_face_action_hour_fwd:
        // 1h steps
        state->hour = (state->hour + 1) % 24;
        break;
    case wake_face_action_hour_6h:
        // 6h steps
        state->hour = (state->hour + 6) % 24;
        break;
    case wake_face_action_minute_fwd:
        // 10min steps
        state->minute = (state->minute + 10) % 60;
        break;
    case wake_face_action_mode_fwd:
        state->mode = (state->mode + 1) % WAKE_FACE_MODES;
        break;
    default:
        break;
    }
    return;
}

static
void _wake_face_update_display(movement_settings_t *settings, wake_face_state_t *state) {
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

    static char lcdbuf[11];
    sprintf(lcdbuf, "WA%c %2d%02d  ",
        state->mode ? 'o' : ' ',
        hour, state->minute);

    watch_set_colon();
    watch_display_string(lcdbuf, 0);
}

static
void *_wake_face_led(void *thrd_id) {
    uint8_t DURATION_SECONDS = (uint8_t)((int)thrd_id * 8);
        // The sleep() we’re using comes from
        // watch-library/hardware/hal/include/hal_sleep.h:62
        // and is defined for an arg of type uint8_t

    fprintf(stderr, "_wake_face_led(): Entered\n");

    watch_set_led_yellow();
    sleep(DURATION_SECONDS);
    watch_set_led_off();
    fprintf(stderr, "_wake_face_led(): Completed LED activation\n");

    thrd_exit(EXIT_SUCCESS);
}

//
// Exported
//

void wake_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wake_face_state_t));
        wake_face_state_t *state = (wake_face_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(wake_face_state_t));

        // Default wake time: 5am, default mode: none
        state->hour = 5;
        state->minute = 0;
        state->mode = wake_face_mode_none;
    }
}

void wake_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    wake_face_state_t *state = (wake_face_state_t *)context;

    switch (event.event_type) {
    case EVENT_ACTIVATE:
    case EVENT_TICK:
        _wake_face_update_display(settings, state);
        break;

    case EVENT_MODE_BUTTON_UP:
        movement_move_to_next_face();
        break;

    case EVENT_LIGHT_BUTTON_UP:
        _wake_face_adjust(settings, state, wake_face_action_hour_fwd);
        _wake_face_update_display(settings, state);
        break;

    case EVENT_LIGHT_LONG_PRESS:
        _wake_face_adjust(settings, state, wake_face_action_hour_6h);
        _wake_face_update_display(settings, state);
        break;

    case EVENT_ALARM_LONG_PRESS:
        _wake_face_adjust(settings, state, wake_face_action_mode_fwd);
        _wake_face_update_display(settings, state);
        break;

    case EVENT_ALARM_BUTTON_UP:
        _wake_face_adjust(settings, state, wake_face_action_minute_fwd);
        _wake_face_update_display(settings, state);
        break;

    case EVENT_BACKGROUND_TASK:
        // Spawn a thread to activate the LED
        if ( state->mode ) {
            thrd_t led_thread;
            int rc = thrd_create(&led_thread, (thrd_start_t) _wake_face_led, (void *)state->mode);
                // We use the thread id arg to pass the signal mode
            if (rc == thrd_error)
                fprintf(stderr, "wake_face_loop(): Could not spawn LED thread\n");
        }
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

void wake_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

void wake_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    wake_face_state_t *state = (wake_face_state_t *)context;

    watch_date_time now = watch_rtc_get_date_time();
    return now.unit.hour==state->hour && now.unit.minute==state->minute;
}