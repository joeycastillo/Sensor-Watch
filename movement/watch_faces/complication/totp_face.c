/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021 Wesley Ellis (https://github.com/tahnok)
 * Copyright © 2021-2023 Joey Castillo <joeycastillo@utexas.edu>
 * Copyright © 2022 Jack Bond-Preston <jackbondpreston@outlook.com>
 * Copyright © 2023 Alex Utter <ooterness@gmail.com>
 * Copyright © 2023 Emilien Court <emilien.court@telecomnancy.net>
 * Copyright © 2023 Jeremy O'Brien <neutral@fastmail.com>
 * Copyright © 2024 Matheus Afonso Martins Moreira <matheus.a.m.moreira@gmail.com> (https://www.matheusmoreira.com/)
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
#include "totp_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "TOTP.h"

typedef struct {
    unsigned char labels[2];
    hmac_alg algorithm;
    uint32_t period;
    size_t key_length;
    uint8_t *key;
} totp_t;

#define TOTP_INITIALIZER(label_1, label_2, key_array, algo, timestep) \
    (const totp_t) { \
        .key = (key_array), \
        .key_length = sizeof(key_array), \
        .period = (timestep), \
        .labels = { (label_1), (label_2) }, \
        .algorithm = (algo), \
    }

////////////////////////////////////////////////////////////////////////////////
// Enter your TOTP key data below

static uint8_t key_1[] = {
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef, // 1 - JBSWY3DPEHPK3PXP
};

static uint8_t key_2[] = {
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef, // 2 - JBSWY3DPEHPK3PXP
};

static totp_t totp_data[] = {
    TOTP_INITIALIZER('2', 'F', key_1, SHA1, 30),
    TOTP_INITIALIZER('A', 'C', key_2, SHA1, 30),
};

// END OF KEY DATA.
////////////////////////////////////////////////////////////////////////////////

static inline totp_t *_totp_current(totp_state_t *totp_state) {
    return &totp_data[totp_state->current_index];
}

static inline size_t _totp_num(void) {
    return sizeof(totp_data) / sizeof(*totp_data);
}

static void _update_display(totp_state_t *totp_state) {
    char buf[14];
    div_t result;
    uint8_t valid_for;
    totp_t *totp = _totp_current(totp_state);

    result = div(totp_state->timestamp, totp->period);
    if (result.quot != totp_state->steps) {
        totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
        totp_state->steps = result.quot;
    }
    valid_for = totp->period - result.rem;
    sprintf(buf, "%c%c%2d%06lu", totp->labels[0], totp->labels[1], valid_for, totp_state->current_code);

    watch_display_string(buf, 0);
}

void totp_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(totp_state_t));
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(totp_state_t));
    totp_state_t *totp_state = (totp_state_t *)context;
    totp_t *totp = _totp_current(totp_state);
    TOTP(totp->key, totp->key_length, totp->period, totp->algorithm);
    totp_state->timestamp = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
    totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
}

bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    totp_state_t *totp_state = (totp_state_t *)context;

    switch (event.event_type) {
        case EVENT_TICK:
            totp_state->timestamp++;
            // fall through
        case EVENT_ACTIVATE:
            _update_display(totp_state);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (totp_state->current_index + 1 < _totp_num()) {
                totp_state->current_index++;
            } else {
                // wrap around to first key
                totp_state->current_index = 0;
            }
            totp_t *totp = _totp_current(totp_state);
            TOTP(totp->key, totp->key_length, totp->period, totp->algorithm);
            _update_display(totp_state);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
        case EVENT_ALARM_LONG_PRESS:
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void totp_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
