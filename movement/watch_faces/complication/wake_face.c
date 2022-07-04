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
#include <unistd.h>
#include <threads.h>

#include "wake_face.h"
#include "watch.h"
#include "watch_utility.h"

// TODO
// UI documentation

//
// Private
//

static void _wake_face_adjust(wake_face_state_t *state) {
    const int WAKE_FACE_MODES = (int)wake_face_mode_both + 1;

    switch(state->caret) {
    case wake_face_caret_mode:
        state->mode = (state->mode + 1) % WAKE_FACE_MODES;
        break;
    case wake_face_caret_hour:
        state->hour = (state->hour + 1) % 24;
        break;
    case wake_face_caret_minute:
        // Step 10min per click
        state->minute = (state->minute + 10) % 60;
        break;
    default:
        // If we get here, we’re in trouble
        break;
    }
    return;
}

static void _wake_face_update_display(wake_face_state_t *state, uint8_t subsecond) {
    static char lcdbuf[14];

    sprintf(lcdbuf, "WA    %2d%02d%c%c", state->hour, state->minute,
        state->mode & wake_face_mode_piezo ? 'P' : ' ',
        state->mode & wake_face_mode_led ? 'L' : ' ' );

    // Flash the hour and minute to indicate presence of the caret
    // My heart says roll the hour and minute in advance, with ?: in sprintf()
    // But this is more efficient computewise
    if (subsecond % 2) {
        if (state->caret == wake_face_caret_hour) {
            lcdbuf[6] = lcdbuf[7] = ' ';
        }
        else if (state->caret == wake_face_caret_minute) {
            lcdbuf[8] = lcdbuf[9] = ' ';
        }
    }

    // In addition to the P and L, show the bell if either signal is on
    watch_set_indicator(WATCH_INDICATOR_BELL);
    if (state->mode == wake_face_mode_none)
        watch_clear_indicator(WATCH_INDICATOR_BELL);

    // Show LAP if the “dismiss the next wake” flag is set
    watch_clear_indicator(WATCH_INDICATOR_LAP);
    if (state->dismiss_once)
        watch_set_indicator(WATCH_INDICATOR_LAP);

    watch_display_string(lcdbuf, 0);
}

static void *_wake_face_led(void *thrd_id) {
    const double DURATION_SECONDS = 8.0;

    // TODO: Add flashing using a loop to sleep for 500ms, toggling the light?
    // But perhaps a solid light is less intrusive
    // We want the signal to be ›just‹ intrusive enough
    // Warrants real-world testing

    watch_set_led_yellow();
    sleep(DURATION_SECONDS);
    watch_set_led_off();
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
        state->dismiss_once = false;
    }
}

void wake_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    // Always welcome the user with the caret on the mode selector
    wake_face_state_t *state = (wake_face_state_t *)context;
    state->caret = wake_face_caret_mode;
}

bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    const int WAKE_FACE_CARET_POSITIONS = (int)wake_face_caret_minute + 1;

    (void) settings;
    wake_state_t *state = (wake_state_t *)context;

    switch (event.event_type) {
    case EVENT_ACTIVATE:
    case EVENT_TICK:
        _wake_face_update_display(state, event.subsecond);
        break;

    case EVENT_MODE_BUTTON_UP:
        movement_move_to_next_face();
        break;

    case EVENT_LIGHT_BUTTON_UP:
        // The light button steps the caret
        state->caret = (state->caret + 1) % WAKE_FACE_CARET_POSITIONS;
        _wake_face_update_display(state, event.subsecond);
        break;

    case EVENT_LIGHT_LONG_PRESS:
        // Long press to activate the light
        movement_illuminate_led();
        break;

    case EVENT_ALARM_BUTTON_UP:
        // The alarm button iterates the value of the selected UI element
        // (mode, hour, minute)
        _wake_face_adjust(state);
        _wake_face_update_display(state, event.subsecond);
        break;

    case EVENT_ALARM_LONG_PRESS:
        // Long press toggles the “dismiss just for the next scheduled wake”
        state->dismiss_once = !state->dismiss_once;
        _wake_face_update_display(state, event.subsecond);
        break;

    case EVENT_BACKGROUND_TASK:
        // If the dismiss flag is set, reset it and skip the signals
        if (state->dismiss_once) {
            state->dismiss_once = false;
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

bool wake_face_wants_background_task(movement_settings_t *settings, void *context) {
    // Called at the top of every minute
    // TODO: Risk of interrupt timing aliasing causing us to miss the wake time
    // should be vanishingly small, but need to check this in practice

    (void) settings;

    wake_state_t *state = (wake_state_t *)context;
    watch_date_time time = watch_rtc_get_date_time();

    return time.hour==state.hour && time.minute==state.minute;
}