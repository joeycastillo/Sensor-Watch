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
 *  o Optionally edit and execute `utils/totp_face_helper.py` to
 *    properly transform all your credentials to the expected format.
 * OR
 *  o Find your secret key(s) and convert them to the required format.
 *      o Use https://cryptii.com/pipes/base32-to-hex to convert base32 to hex
 *      o Use https://github.com/susam/mintotp to generate test codes for verification
 *  o Edit global variables in "totp_face.c" to configure your stored keys:
 *      o "keys", and the members of "totp_parameters_t": "key_size",
 *        "time_step", and "algorithm" set the cryptographic parameters
 *        for each secret key.
 *      o The member "label" of "totp_parameters_t" sets the two-letter label
 *        for each key (This replaces the day-of-week indicator)
 *      o Once finished, remove the five provided examples.
 *
 * If you have more than one secret key, press ALARM to cycle through them.
 */

#include "movement.h"
#include "TOTP.h"

typedef struct {
    uint32_t timestamp;
    uint8_t steps;
    uint32_t current_code;
    uint8_t current_index;
    uint16_t current_key_offset;
} totp_state_t;

typedef struct {
    char label[2];
    uint8_t key_size;
    uint8_t time_step;
    hmac_alg algorithm;
} totp_parameters_t;

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

/* A key size of 20 bytes, a time-step of 30 seconds and the algorithm
 * SHA1 seem to be the most common parameters in the wild.
 */
#define CREDENTIAL(...) ((const totp_parameters_t) { \
    .key_size = 20, \
    .time_step = 30, \
    .algorithm = SHA1, \
    __VA_ARGS__ \
})

#endif // TOTP_FACE_H_
