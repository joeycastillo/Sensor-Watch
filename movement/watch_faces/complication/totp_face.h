/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021 Wesley Ellis (https://github.com/tahnok)
 * Copyright © 2021-2022 Joey Castillo <joeycastillo@utexas.edu>
 * Copyright © 2022 Alexsander Akers <me@a2.io>
 * Copyright © 2022 Jack Bond-Preston <jackbondpreston@outlook.com>
 * Copyright © 2023 Alex Utter <ooterness@gmail.com>
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

#ifndef TOTP_FACE_H_
#define TOTP_FACE_H_

/*
 * TOTP face
 * Time-based one-time password (TOTP) generator
 *
 * Generate one-time passwords often used for two-factor authentication.
 * The secret key must be set by hand, by editing "totp_face.c".
 *
 * Available algorithms:
 *  o SHA1 (most TOTP codes use this)
 *  o SHA224
 *  o SHA256
 *  o SHA384
 *  o SHA512
 *
 * Instructions:
 *  o Find your secret key(s) and convert them to the required format.
 *      o Use https://cryptii.com/pipes/base32-to-hex to convert base32 to hex
 *      o Use https://github.com/susam/mintotp to generate test codes for verification
 *  o Edit global variables in "totp_face.c" to configure your stored keys:
 *      o "keys", "key_sizes", "timesteps", and "algorithms" set the
 *        cryptographic parameters for each secret key.
 *      o "labels" sets the two-letter label for each key
 *        (This replaces the day-of-week indicator)
 *      o Once finished, remove the two provided examples.
 *
 * If you have more than one secret key, press ALARM to cycle through them.
 * Press LIGHT to cycle in the other direction or keep it pressed longer to
 * activate the light.
 */

#include "movement.h"

typedef struct {
    uint32_t timestamp;
    uint8_t steps;
    uint32_t current_code;
    uint8_t current_index;
    uint8_t *current_decoded_key;
    size_t current_decoded_key_length;
} totp_state_t;

void totp_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void totp_face_activate(movement_settings_t *settings, void *context);
bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void totp_face_resign(movement_settings_t *settings, void *context);

#define totp_face ((const watch_face_t){ \
    totp_face_setup, \
    totp_face_activate, \
    totp_face_loop, \
    totp_face_resign, \
    NULL, \
})

#endif // TOTP_FACE_H_
