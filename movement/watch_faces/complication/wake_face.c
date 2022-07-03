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
#include "wake_face.h"
#include "watch.h"
#include "watch_utility.h"

// TODO
// update_display, loop

static inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static void _wake_face_adjust(wake_face_state_t *state) {
    switch(state->caret) {
    case wake_face_caret_display:
        break;
    case wake_face_caret_hour:
        state->hour = (state->hour + 1) % 24;
        break;
    case wake_face_caret_minute:
        // Step 10min per click
        state->minute = (state->minute + 10) % 60;
        break;
    case wake_face_caret_signal:
        state->wake_mode ^= wake_face_mode_signal;
        break;
    case wake_face_caret_led:
        state->wake_mode ^= wake_face_mode_led;
        break;
    default:
        // If we get here, something has gone wrong
        break;
    }
    return;
}

static void _wake_face_update_display(wake_face_state_t *state) {
    // TODO
}

void wake_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wake_face_state_t));
        wake_face_state_t *state = (wake_face_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(wake_face_state_t));

        // Default wake-up time: 5am, default wake mode: off
        state->mode = wake_face_mode_off;
        state->hour = 5;
        state->minute = 0;
    }
}

void wake_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    // Always welcome the user in display mode
    wake_face_state_t *state = (wake_face_state_t *)context;
    state->caret = wake_face_caret_display;
}

bool wake_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    wake_state_t *state = (wake_state_t *)context;

    switch (event.event_type) {
    case EVENT_ACTIVATE:
    case EVENT_TICK:
        _wake_face_update_display(state);
        break;

    case EVENT_MODE_BUTTON_UP:
        movement_move_to_next_face();
        break;

    case EVENT_LIGHT_BUTTON_UP:
        // The light button steps the caret
        state->caret = (state->caret + 1) % WAKE_FACE_CARET_POSITIONS;
        _wake_face_update_display(state);
        break;

    case EVENT_LIGHT_LONG_PRESS:
        // Long press to activate the light
        movement_illuminate_led();
        break;

    case EVENT_ALARM_BUTTON_UP:
        // When we’re in adjust mode (caret ≠ display),
        // the alarm button iterates the value of the selected element
        _wake_face_adjust(state);
        _wake_face_update_display(state);
        break;

    case EVENT_BACKGROUND_TASK:
        if (state->wake_mode & wake_face_mode_signal)
            movement_play_signal();

        // TODO: This is not right. We want it to CONTINUE for 30s
        // Might need to fork it?
        if (state->wake_mode & wake_face_mode_led) {
            if (event.subsecond % 2 == 0)
                watch_set_led_off();
            else
                watch_set_led_yellow();
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
    // Nothing to do: We tidy up the UI in wake_face_activate()
}

bool wake_face_wants_background_task(movement_settings_t *settings, void *context) {
    // Called at the top of every minute
    // TODO: Risk of interrupt timing aliasing causing us to miss the wake time
    // should be vanishingly small, but need to check this in practice

    wake_state_t *state = (wake_state_t *)context;
    watch_date_time time = watch_rtc_get_date_time();

    return time.hour==state.hour && time.minute==state.minute;
}