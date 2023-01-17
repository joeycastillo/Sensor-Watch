/*
 * MIT License
 *
 * Copyright (c) 2023 Gabor L Ugray
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
#include "chirpy_demo_face.h"

const uint16_t chirpy_tone_periods[] = { 417, 385, 358, 334, 313, 295, 278, 264, 251, 239, 228, 218, 209, 201, 193, 186, 455, 179 };

// Data sequence has 4 + 16 + 2 + 16 + 2 = 40 items
#define INFO_SEQ_LEN 54
const uint8_t info_seq[] = {
    17, 16, 17, 16,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    1, 8, 4, 15, 13, 12, 2, 6, 5, 11, 7, 0, 3, 14, 10, 9,
    7, 12, 6, 8, 10, 4, 15, 3, 14, 5, 11, 0, 13, 1, 2, 9,
    16, 17
};

void chirpy_demo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(chirpy_demo_state_t));
        memset(*context_ptr, 0, sizeof(chirpy_demo_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void chirpy_demo_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    memset(context, 0, sizeof(chirpy_demo_state_t));
    state->mode = CDM_SCALE;
    movement_request_tick_frequency(64);
}


static void _cdf_update_lcd(chirpy_demo_state_t *state) {

    const char *mode_names[] = {"SC", "21"};
    const char *mode_str = mode_names[state->mode];

    // Assemble & write to LCD
    char buf[11];
    sprintf(buf, "CH%s PLAY ", mode_str);
    watch_display_string(buf, 0);
}

static void _cdf_clear_chirp(chirpy_demo_state_t *state) {
    state->tick_fun = 0;
    watch_set_buzzer_off();
    watch_clear_indicator(WATCH_INDICATOR_BELL);
}

static void _cdf_scale_tick(void *context) {

    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    // Scale goes in 200Hz increments from 1000 Hz to 12 kHz -> 56 steps
    if (state->seq_pos == 56) {
        _cdf_clear_chirp(state);
        return;
    }
    uint32_t freq = 1000 + state->seq_pos * 200;
    uint32_t period = 1000000 / freq;
    watch_set_buzzer_period(period);
    watch_set_buzzer_on();
}

static void _cdf_info_tick(void *context) {

    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    // Data over
    if (state->seq_pos == INFO_SEQ_LEN) {
        _cdf_clear_chirp(state);
        return;
    }
    uint8_t tone_ix = info_seq[state->seq_pos];
    uint16_t period = chirpy_tone_periods[tone_ix];
    watch_set_buzzer_period(period);
    watch_set_buzzer_on();
}

static void _cdf_countdown_tick(void *context) {

    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    // Countdown over: start actual broadcast
    if (state->seq_pos == 4 * 3) {
        if (state->mode == CDM_SCALE) {
            state->tick_compare = 8;
            state->tick_count = 0;
            state->seq_pos = 0;
            state->tick_fun = _cdf_scale_tick;
        }
        else {
            state->tick_compare = 3;
            state->tick_count = 0;
            state->seq_pos = 0;
            state->tick_fun = _cdf_info_tick;
        }
        return;
    }
    // Sound or turn off buzzer
    if ((state->seq_pos % 4) == 0) {
        watch_set_buzzer_period(NotePeriods[BUZZER_NOTE_A5]);
        watch_set_buzzer_on();
    }
    else if ((state->seq_pos % 4) == 1) {
        watch_set_buzzer_off();
    }
}
bool chirpy_demo_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    bool can_enter_standby = true;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _cdf_update_lcd(state);
            movement_request_tick_frequency(64);
            break;
        case EVENT_MODE_BUTTON_UP:
            // Do not exit face while we're chirping
            if (state->tick_fun == 0) {
                movement_move_to_next_face();
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // Cycle through modes, unless we're currently chirping
            if (state->tick_fun == 0) {
                state->mode = (state->mode + 1) % CDM_COUNT;
                _cdf_update_lcd(state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            // If currently chirping: stop
            if (state->tick_fun != 0) {
                _cdf_clear_chirp(state);
            }
            // Start chirping countdown
            else {
                state->tick_count = 0;
                state->tick_compare = 16;
                state->seq_pos = 0;
                state->tick_fun = _cdf_countdown_tick;
                watch_set_indicator(WATCH_INDICATOR_BELL);
                can_enter_standby = false;
            }
            break;
        case EVENT_TICK:
            if (state->tick_fun != 0) {
                can_enter_standby = false;
                ++state->tick_count;
                if (state->tick_count == state->tick_compare) {
                    state->tick_count = 0;
                    state->tick_fun(context);
                    ++state->seq_pos;
                }
            }
            break;
        case EVENT_TIMEOUT:
            // Do not time out while we're chirping
            if (state->tick_fun == 0) {
                movement_move_to_face(0);
            }
        default:
            break;
    }

    return can_enter_standby;
}

void chirpy_demo_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

