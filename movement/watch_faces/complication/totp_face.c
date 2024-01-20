/*
 * MIT License
 *
 * Copyright (c) 2022 Wesley Ellis (https://github.com/tahnok)
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

////////////////////////////////////////////////////////////////////////////////
// Enter your TOTP key data below

/* You can optionally edit and execute `utils/totp_face_helper.py` to
 * properly transform all your credentials to the expected format.
 *
 * The default key size is 20, the default algorithm is SHA1 and
 * the default time-step is 30 seconds.
 *
 * A label is made up of two characters (Which can be entered as a string.)
 * Due to the structure of the display, the first character can be
 * displayed as anything but an uppercase R.
 * The second character can be displayed as the letters A, B, C, D, E,
 * F, H, I, J, L, N, O, R, T, U and X, and the numbers 0, 1, 3, 7 and 8.
 * (See: https://www.sensorwatch.net/docs/wig/display/)
 *
 * Ignore the initializer-overrides warning for the credentials array.
 * It is wanted behaviour in this instance.
 */
#pragma GCC diagnostic ignored "-Winitializer-overrides"
const static totp_parameters_t credentials[] = {
    CREDENTIAL(.label = "2F", .key_size = 10),
    CREDENTIAL(.label = "AC", .key_size = 10),
    CREDENTIAL(.label = "GL"), // Using the default key size (20).
    CREDENTIAL(.label = "TF", .key_size = 35, .algorithm = SHA512),
    CREDENTIAL(.label = "EB", .time_step = 40),
};

static uint8_t keys[] = {
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef, // 2F - JBSWY3DPEHPK3PXP
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef, // AC - JBSWY3DPEHPK3PXP
    0x75, 0x1f, 0xf2, 0xbb, 0xd5, 0x72, 0xd1, 0xef, 0xa2, 0x1d, 0x93, 0x95, 0x8d, 0xe2, 0x3c, 0x0c, 0x8d, 0x87, 0xd1, 0x7e, // GL - OUP7FO6VOLI67IQ5SOKY3YR4BSGYPUL6
    0xf9, 0x86, 0x3a, 0xdd, 0xd7, 0xc6, 0xb2, 0x79, 0x9b, 0x5d, 0xdc, 0xea, 0xc3, 0xbd, 0xc4, 0xef, 0x15, 0x0a, 0xeb, 0xa3, 0x6d, 0x79, 0x00, 0x48, 0xa0, 0x15, 0xd8, 0xf1, 0xaa, 0xd1, 0x2b, 0x97, 0x57, 0x4f, 0xa4, // TF - 7GDDVXOXY2ZHTG253TVMHPOE54KQV25DNV4QASFACXMPDKWRFOLVOT5E
    0xd4, 0xcf, 0xd8, 0x5c, 0xca, 0xc7, 0x8c, 0x29, 0x75, 0xd5, 0x8b, 0xf6, 0xa3, 0xdb, 0xad, 0x6b, 0x27, 0x58, 0x1b, 0xbf, // EB - 2TH5QXGKY6GCS5OVRP3KHW5NNMTVQG57
};
// END OF KEY DATA.
////////////////////////////////////////////////////////////////////////////////

#define NUMBER_OF_CREDENTIALS (sizeof(credentials) / sizeof(totp_parameters_t))

static void _update_display(totp_state_t *totp_state) {
    char buf[14];
    div_t result;
    uint8_t valid_for;

    result = div(totp_state->timestamp, credentials[totp_state->current_index].time_step);
    if (result.quot != totp_state->steps) {
        totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
        totp_state->steps = result.quot;
    }
    valid_for = credentials[totp_state->current_index].time_step - result.rem;
    sprintf(buf, "%c%c%2d%06lu", credentials[totp_state->current_index].label[0], credentials[totp_state->current_index].label[1], valid_for, totp_state->current_code);

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
    TOTP(keys, credentials[0].key_size, credentials[0].time_step, credentials[0].algorithm);
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
            if (totp_state->current_index + 1 < NUMBER_OF_CREDENTIALS) {
                totp_state->current_key_offset += credentials[totp_state->current_index].key_size;
                totp_state->current_index++;
            } else {
                // Wrap around to the first credential.
                totp_state->current_key_offset = 0;
                totp_state->current_index = 0;
            }
            TOTP(keys + totp_state->current_key_offset, credentials[totp_state->current_index].key_size, credentials[totp_state->current_index].time_step, credentials[totp_state->current_index].algorithm);
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
