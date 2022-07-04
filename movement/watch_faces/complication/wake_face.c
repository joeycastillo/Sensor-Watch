/*
 * MIT License
 *
 * Copyright (c) 2022 Josh Berson
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
// #include <unistd.h>
#include <threads.h>

#include "wake_face.h"
#include "watch.h"
#include "watch_utility.h"

/*
    TODO — make it actually work

    UI Notes

    º Alarm long press steps adjustment caret — display (no selection), hour, minute, signal mode
    º Alarm press through values for the above
    º Signal modes: None, piezo, LED, both
    º Minute adjustment is in steps of 10min
    º Light long press toggles “dismiss next” flag
*/

//
// Private
//

static const int WAKE_FACE_MODES = 4;
static const int WAKE_FACE_CARET_POSITIONS = 4;

static
inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static
void _wake_face_adjust(movement_settings_t *settings, wake_face_state_t *state) {
    switch(state->caret) {
    case wake_face_caret_hour:
        state->hour = (state->hour + 1) % 24;
        break;
    case wake_face_caret_minute:
        // Step 10min per click
        state->minute = (state->minute + 10) % 60;
        break;
    case wake_face_caret_mode:
        state->mode = (state->mode + 1) % WAKE_FACE_MODES;
        if (state->mode == wake_face_mode_none)
            movement_cancel_background_task();
        else {
            watch_date_time now = watch_rtc_get_date_time();
            uint32_t now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
            uint32_t wake_ts = watch_utility_offset_timestamp(now_ts, state->hour, state->minute, 0);
            watch_date_time wake_dt = watch_utility_date_time_from_unix_time(wake_ts, get_tz_offset(settings));;
            movement_schedule_background_task(wake_dt);
        }
        break;
    case wake_face_caret_display:
    default:
        break;
    }
    return;
}

static
void _wake_face_update_display(movement_event_t *event, movement_settings_t *settings, wake_face_state_t *state) {
    static char lcdbuf[11];

    uint32_t subsecond = event->subsecond;
    bool clock_mode_24h = settings->bit.clock_mode_24h;
    uint8_t hour = state->hour;

    watch_clear_display();
    watch_set_colon();
    watch_clear_indicator(WATCH_INDICATOR_PM);
    watch_clear_indicator(WATCH_INDICATOR_24H);
    watch_clear_indicator(WATCH_INDICATOR_BELL);
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    watch_clear_indicator(WATCH_INDICATOR_LAP);

    if (clock_mode_24h)
        watch_set_indicator(WATCH_INDICATOR_24H);
    else {
        if (hour >= 12)
            watch_set_indicator(WATCH_INDICATOR_PM);
        hour = hour % 12 ? hour % 12 : 12;
    }
    if (state->mode & wake_face_mode_piezo)
        watch_set_indicator(WATCH_INDICATOR_BELL);
    if (state->mode & wake_face_mode_led)
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    if (state->dismiss_next)
        watch_set_indicator(WATCH_INDICATOR_LAP);
        // Show LAP if the “dismiss the next wake” flag is set

    sprintf(lcdbuf, "WA  %2d%02d  ", hour, state->minute);

    // Flash the hour, minute, and legend to indicate presence of the caret
    if (subsecond % 4 == 0) {
        fprintf(stderr, "_wake_face_update_display(): subsecond % 4 == 0\n");
        switch (state->caret) {
        case wake_face_caret_hour:
            lcdbuf[4] = lcdbuf[5] = ' ';
            fprintf(stderr, "_wake_face_update_display(): Blanked the hour\n");
            break;
        case wake_face_caret_minute:
            lcdbuf[6] = lcdbuf[7] = ' ';
            fprintf(stderr, "_wake_face_update_display(): Blanked the minute\n");
            break;
        case wake_face_caret_mode:
            lcdbuf[0] = lcdbuf[1] = ' ';
            fprintf(stderr, "_wake_face_update_display(): Blanked the legend\n");
            break;
        case wake_face_caret_display:
        default:
            break;
        }
    }

    watch_set_colon();
    watch_display_string(lcdbuf, 0);
}

static
void *_wake_face_led(void *thrd_id) {
    const uint8_t DURATION_SECONDS = 8;
        // The sleep() we’re using comes from
        // watch-library/hardware/hal/include/hal_sleep.h:62
        // and is defined for an arg of type uint8_t

    // TODO: Add flashing using a loop to sleep for 500ms, toggling the light?
    // But perhaps a solid light is less intrusive
    // We want the signal to be ›just‹ intrusive enough
    // Warrants real-world testing

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
        state->mode = wake_face_mode_none;
        state->hour = 5;
        state->minute = 0;
        state->dismiss_next = false;
    }
}

void wake_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    // Always welcome the user in display mode (no selector caret)
    wake_face_state_t *state = (wake_face_state_t *)context;
    state->caret = wake_face_caret_display;
}

bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    wake_face_state_t *state = (wake_face_state_t *)context;

    switch (event.event_type) {
    case EVENT_ACTIVATE:
    case EVENT_TICK:
        _wake_face_update_display(&event, settings, state);
        break;

    case EVENT_MODE_BUTTON_UP:
        movement_move_to_next_face();
        break;

    case EVENT_ALARM_LONG_PRESS:
        // Alarm long press button steps the caret
        state->caret = (state->caret + 1) % WAKE_FACE_CARET_POSITIONS;
        movement_request_tick_frequency(4);
        _wake_face_update_display(&event, settings, state);
        break;

    case EVENT_ALARM_BUTTON_UP:
        // The alarm button iterates the value of the selected UI element
        // (mode, hour, minute)
        _wake_face_adjust(settings, state);
        _wake_face_update_display(&event, settings, state);
        break;

    case EVENT_LIGHT_BUTTON_UP:
        movement_illuminate_led();
        break;

    case EVENT_LIGHT_LONG_PRESS:
        // Light long press toggles the dismiss next flag
        state->dismiss_next = !state->dismiss_next;
        _wake_face_update_display(&event, settings, state);
        break;

    case EVENT_BACKGROUND_TASK:
        // If the dismiss next flag is set, reset it and skip the signals
        if (state->dismiss_next) {
            state->dismiss_next = false;
            fprintf(stderr, "wake_face_loop(): Reset the dismiss_next flag\n");
            break;
        }

        // Spawn a thread to activate the LED
        if (state->mode & wake_face_mode_led) {
            static thrd_t led_thread;
            int rc = thrd_create(&led_thread, (thrd_start_t) _wake_face_led, (void *)0);
            if (rc == thrd_error)
                fprintf(stderr, "wake_face_loop(): Could not spawn LED thread\n");
        }

        if (state->mode & wake_face_mode_piezo)
            movement_play_signal();

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
    // Nothing to do — we position the caret in wake_face_activate()
}
