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
 * Copyright © 2024 Max Zettlmeißl <max@zettlmeissl.de>
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
#include "base32.h"

#ifndef TOTP_FACE_MAX_KEY_LENGTH
#define TOTP_FACE_MAX_KEY_LENGTH 128
#endif

typedef struct {
    unsigned char labels[2];
    hmac_alg algorithm;
    uint32_t period;
    size_t encoded_key_length;
    unsigned char *encoded_key;
} totp_t;

#define CREDENTIAL(label, key_array, algo, timestep) \
    (const totp_t) { \
        .encoded_key = ((unsigned char *) key_array), \
        .encoded_key_length = sizeof(key_array) - 1, \
        .period = (timestep), \
        .labels = (#label), \
        .algorithm = (algo), \
    }

////////////////////////////////////////////////////////////////////////////////
// Enter your TOTP key data below

static totp_t credentials[] = {
    CREDENTIAL(2F, "JBSWY3DPEHPK3PXP", SHA1, 30),
    CREDENTIAL(AC, "JBSWY3DPEHPK3PXP", SHA1, 30),
};

// END OF KEY DATA.
////////////////////////////////////////////////////////////////////////////////

static inline totp_t *totp_at(size_t i) {
    return &credentials[i];
}

static inline totp_t *totp_current(totp_state_t *totp_state) {
    return totp_at(totp_state->current_index);
}

static inline size_t totp_total(void) {
    return sizeof(credentials) / sizeof(*credentials);
}

static void totp_validate_key_lengths(void) {
    for (size_t n = totp_total(), i = 0; i < n; ++i) {
        totp_t *totp = totp_at(i);

        if (UNBASE32_LEN(totp->encoded_key_length) > TOTP_FACE_MAX_KEY_LENGTH) {
            // Key exceeds static limits, turn it off by zeroing the length
            totp->encoded_key_length = 0;
        }
    }
}

static void totp_generate(totp_state_t *totp_state) {
    totp_t *totp = totp_current(totp_state);

    if (totp->encoded_key_length <= 0) {
        // Key exceeded static limits and was turned off
        totp_state->current_decoded_key_length = 0;
        return;
    }

    totp_state->current_decoded_key_length = base32_decode(totp->encoded_key, totp_state->current_decoded_key);

    if (totp_state->current_decoded_key_length == 0) {
        // Decoding failed for some reason
        // Not a base 32 string?
        return;
    }

    TOTP(
        totp_state->current_decoded_key,
        totp_state->current_decoded_key_length,
        totp->period,
        totp->algorithm
    );
}

static void totp_display_error(totp_state_t *totp_state) {
    char buf[10 + 1];
    totp_t *totp = totp_current(totp_state);

    snprintf(buf, sizeof(buf), "%c%c  ERROR ", totp->labels[0], totp->labels[1]);
    watch_display_string(buf, 0);
}

static void totp_display_code(totp_state_t *totp_state) {
    char buf[14];
    div_t result;
    uint8_t valid_for;
    totp_t *totp = totp_current(totp_state);

    result = div(totp_state->timestamp, totp->period);
    if (result.quot != totp_state->steps) {
        totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
        totp_state->steps = result.quot;
    }
    valid_for = totp->period - result.rem;
    sprintf(buf, "%c%c%2d%06lu", totp->labels[0], totp->labels[1], valid_for, totp_state->current_code);

    watch_display_string(buf, 0);
}

static void totp_display(totp_state_t *totp_state) {
    if (totp_state->current_decoded_key_length > 0) {
        totp_display_code(totp_state);
    } else {
        totp_display_error(totp_state);
    }
}

static void totp_generate_and_display(totp_state_t *totp_state) {
    totp_generate(totp_state);
    totp_display(totp_state);
}

static inline uint32_t totp_compute_base_timestamp(movement_settings_t *settings) {
    return watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
}

void totp_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    totp_validate_key_lengths();

    if (*context_ptr == NULL) {
        totp_state_t *totp = malloc(sizeof(totp_state_t));
        totp->current_decoded_key = malloc(TOTP_FACE_MAX_KEY_LENGTH);
        *context_ptr = totp;
    }
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    totp_state_t *totp = (totp_state_t *) context;

    totp->timestamp = totp_compute_base_timestamp(settings);
    totp->steps = 0;
    totp->current_code = 0;
    totp->current_index = 0;
    totp->current_decoded_key_length = 0;
    // totp->current_decoded_key is already initialized in setup

    totp_generate_and_display(totp);
}

bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    totp_state_t *totp_state = (totp_state_t *) context;

    switch (event.event_type) {
        case EVENT_TICK:
            totp_state->timestamp++;
            // fall through
        case EVENT_ACTIVATE:
            totp_display(totp_state);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (totp_state->current_index + 1 < totp_total()) {
                totp_state->current_index++;
            } else {
                // wrap around to first key
                totp_state->current_index = 0;
            }

            totp_generate_and_display(totp_state);

            break;
        case EVENT_LIGHT_BUTTON_UP:
            if (totp_state->current_index == 0) {
                // Wrap around to the last credential.
                totp_state->current_index = totp_total() - 1;
            } else {
                totp_state->current_index--;
            }

            totp_generate_and_display(totp_state);

            break;
        case EVENT_ALARM_BUTTON_DOWN:
        case EVENT_ALARM_LONG_PRESS:
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_LONG_PRESS:
            movement_illuminate_led();
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
