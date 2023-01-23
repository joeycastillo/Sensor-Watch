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
#include "chirpy_tx.h"

typedef enum {
    CDM_CHOOSE = 0,
    CDM_CHIRPING,
} chirpy_demo_mode_t;

typedef enum {
    CDP_SCALE = 0,
    CDP_INFO_SHORT,
    CDP_INFO_LONG,
} chirpy_demo_program_t;

typedef struct {
    // Current mode
    chirpy_demo_mode_t mode;

    // Selected program
    chirpy_demo_program_t program;

    // Helps us handle 1/64 ticks during transmission; including countdown timer
    chirpy_tick_state_t tick_state;

    // Used by chirpy encoder during transmission
    chirpy_encoder_state_t encoder_state;

} chirpy_demo_state_t;

static uint8_t long_data_str[] = 
    "There once was a ship that put to sea\n" \
    "The name of the ship was the Billy of Tea\n" \
    "The winds blew up, her bow dipped down\n" \
    "O blow, my bully boys, blow (huh)\n" \
    "\n" \
    "Soon may the Wellerman come\n" \
    "To bring us sugar and tea and rum\n" \
    "One day, when the tonguin' is done\n" \
    "We'll take our leave and go\n";    

static uint16_t short_data_len = 20;

static uint8_t short_data[] = {
    0x27, 0x00,
    0x0c, 0x42, 0xa3, 0xd4, 0x06, 0x54, 0x00, 0x00, 0x02,
    0x0c, 0x6b, 0x05, 0x5a, 0x09, 0xd8, 0x00, 0xf5, 0x00, 
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
    state->mode = CDM_CHOOSE;
    state->program = CDP_SCALE;
}


static void _cdf_update_lcd(chirpy_demo_state_t *state) {
    watch_display_string("CH", 0);
    if (state->program == CDP_SCALE)
        watch_display_string(" SCALE", 4);
    else if (state->program == CDP_INFO_SHORT)
        watch_display_string("SHORT ", 4);
    else if (state->program == CDP_INFO_LONG)
        watch_display_string(" LOng ", 4);
    else
        watch_display_string("----  ", 4);
}

static void _cdf_quit_chirping(chirpy_demo_state_t *state) {
    state->mode = CDM_CHOOSE;
    watch_set_buzzer_off();
    watch_clear_indicator(WATCH_INDICATOR_BELL);
    movement_request_tick_frequency(1);
}

static void _cdf_scale_tick(void *context) {

    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;
    chirpy_tick_state_t *tick_state = &state->tick_state;

    // Scale goes in 200Hz increments from 700 Hz to 12.3 kHz -> 58 steps
    if (tick_state->seq_pos == 58) {
        _cdf_quit_chirping(state);
        return;
    }
    uint32_t freq = 700 + tick_state->seq_pos * 200;
    uint32_t period = 1000000 / freq;
    watch_set_buzzer_period(period);
    watch_set_buzzer_on();
    ++tick_state->seq_pos;
}

static void _cdf_data_tick(void *context) {

    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    uint8_t tone = chirpy_get_next_tone(&state->encoder_state);
    // Transmission over?
    if (tone == 255) {
        _cdf_quit_chirping(state);
        return;
    }
    uint16_t period = chirpy_get_tone_period(tone);
    watch_set_buzzer_period(period);
    watch_set_buzzer_on();
}

static uint8_t *curr_data_ptr;
static uint16_t curr_data_ix;
static uint16_t curr_data_len;

static uint8_t _cdf_get_next_byte(uint8_t *next_byte) {
    if (curr_data_ix == curr_data_len)
        return 0;
    *next_byte = curr_data_ptr[curr_data_ix];
    ++curr_data_ix;
    return 1;
}

static void _cdf_countdown_tick(void *context) {

    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;
    chirpy_tick_state_t *tick_state = &state->tick_state;

    // Countdown over: start actual broadcast
    if (tick_state->seq_pos == 8 * 3) {
        tick_state->tick_compare = 3;
        tick_state->tick_count = -1;
        tick_state->seq_pos = 0;
        if (state->program == CDP_SCALE) {
            tick_state->tick_fun = _cdf_scale_tick;
        }
        else {
            // Set up the encoder
            chirpy_init_encoder(&state->encoder_state, _cdf_get_next_byte);
            tick_state->tick_fun = _cdf_data_tick;
            // Set up the data
            curr_data_ix = 0;
            if (state->program == CDP_INFO_SHORT) {
                curr_data_ptr = short_data;
                curr_data_len = short_data_len;
            }
            else if (state->program == CDP_INFO_LONG) {
                curr_data_ptr = long_data_str;
                curr_data_len = strlen((const char*)long_data_str);
            }
        }
        return;
    }
    // Sound or turn off buzzer
    if ((tick_state->seq_pos % 8) == 0) {
        watch_set_buzzer_period(NotePeriods[BUZZER_NOTE_A5]);
        watch_set_buzzer_on();
    }
    else if ((tick_state->seq_pos % 8) == 1) {
        watch_set_buzzer_off();
    }
    ++tick_state->seq_pos;
}

static void _cdm_setup_chirp(chirpy_demo_state_t *state) {
    // We want frequent callbacks from now on
    movement_request_tick_frequency(64);
    watch_set_indicator(WATCH_INDICATOR_BELL);
    state->mode = CDM_CHIRPING;
    // Set up tick state; start with countdown
    state->tick_state.tick_count = -1;
    state->tick_state.tick_compare = 8;
    state->tick_state.seq_pos = 0;
    state->tick_state.tick_fun = _cdf_countdown_tick;
}

bool chirpy_demo_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    chirpy_demo_state_t *state = (chirpy_demo_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _cdf_update_lcd(state);
            break;
        case EVENT_MODE_BUTTON_UP:
            // Do not exit face while we're chirping
            if (state->mode != CDM_CHIRPING) {
                movement_move_to_next_face();
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // We don't do light.
            break;
        case EVENT_ALARM_BUTTON_UP:
            // If in choose mode: select next program
            if (state->mode == CDM_CHOOSE) {
                if (state->program == CDP_SCALE)
                    state->program = CDP_INFO_SHORT;
                else if (state->program == CDP_INFO_SHORT)
                    state->program = CDP_INFO_LONG;
                else if (state->program == CDP_INFO_LONG)
                    state->program = CDP_SCALE;
                _cdf_update_lcd(state);
            }
            // If chirping: stoppit
            else if (state->mode == CDM_CHIRPING) {
                _cdf_quit_chirping(state);
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            // If in choose mode: start chirping
            if (state->mode == CDM_CHOOSE) {
                _cdm_setup_chirp(state);
            }
            break;
        case EVENT_TICK:
            if (state->mode == CDM_CHIRPING) {
                ++state->tick_state.tick_count;
                if (state->tick_state.tick_count == state->tick_state.tick_compare) {
                    state->tick_state.tick_count = 0;
                    state->tick_state.tick_fun(context);
                }
            }
            break;
        case EVENT_TIMEOUT:
            // Do not time out while we're chirping
            if (state->mode != CDM_CHIRPING) {
                movement_move_to_face(0);
            }
        default:
            break;
    }

    // Return true if the watch can enter standby mode. False needed when chirping.
    if (state->mode == CDM_CHIRPING)
        return false;
    else
        return true;
}

void chirpy_demo_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

