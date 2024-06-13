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

#ifndef TOTP_FACE_LFS_H_
#define TOTP_FACE_LFS_H_

/*
 * TOTP-LFS face
 * Time-based one-time password (TOTP) generator using LFS
 *
 * Reads from a file "totp_uris.txt", containing a single secret key in a
 * series of URLs. Each line is what's in a QR code, e.g.:
 *   otpauth://totp/Example:alice@google.com?secret=JBSWY3DPEHPK3PXP&issuer=Example
 *   otpauth://totp/ACME%20Co:john.doe@email.com?secret=HXDMVJECJJWSRB3HWIZR4IFUGFTMXBOZ&issuer=ACME%20Co&algorithm=SHA1&digits=6&period=30
 *
 * This is also the same as what Aegis exports in plain-text format.
 * This face performs minimal sanitisation of input, however.
 *
 * At the moment, to get the records onto the filesystem, start a serial connection and do:
 *   echo otpauth://totp/Example:alice@google.com?secret=JBSWY3DPEHPK3PXP&issuer=Example > totp_uris.txt
 *   echo otpauth://totp/ACME%20Co:john.doe@email.com?secret=HXDMVJECJJWSRB3HWIZR4IFUGFTMXBOZ&issuer=ACME%20Co&algorithm=SHA1&digits=6&period=30 >> totp_uris.txt
 * (note the double >> in the second one)
 *
 * You may want to customise the characters that appear to identify the 2FA
 * code. These are just the first two characters of the issuer, and it's fine
 * to modify the URI.
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
} totp_lfs_state_t;

void totp_face_lfs_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void totp_face_lfs_activate(movement_settings_t *settings, void *context);
bool totp_face_lfs_loop(movement_event_t event, movement_settings_t *settings, void *context);
void totp_face_lfs_resign(movement_settings_t *settings, void *context);

#define totp_face_lfs ((const watch_face_t){ \
    totp_face_lfs_setup, \
    totp_face_lfs_activate, \
    totp_face_lfs_loop, \
    totp_face_lfs_resign, \
    NULL, \
})

#endif // TOTP_FACE_LFS_H_
