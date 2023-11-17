/*
 * MIT License
 *
 * Copyright (c) 2023 Christian Chapman
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

#ifndef MORSECALC_FACE_H_
#define MORSECALC_FACE_H_

#define MORSECALC_TOKEN_LEN 32
#define MORSECODE_LEN 5

#include "movement.h"
#include "calc.h"

/*
 * MC International Morse Code binary tree
 * Levels of the tree are concatenated.
 * '.' = 0 and '-' = 1. 
 *
 * Capitals denote special characters:
 * C = Ch digraph
 * V = VERIFY (ITU-R "UNDERSTOOD")
 * R = REPEAT
 * W = WAIT
 * S = START TRANSMISSION
 * E = END OF WORK
 */
static const char MORSECODE_TREE[] = " etianmsurwdkgohvf\0l\0pjbxcyzq\0C\x35\x34V\x33\0R\0\x32W\0+\0\0\0\0\x31\x36=/\0\0S(\0\x37\0\0\0\x38\0\x39\x30\0\0\0\0\0E\0\0\0\0\0\0?_\0\0\0\0\"\0\0.\0\0\0\0@\0\0\0'\0\0-\0\0\0\0\0\0\0\0;!\0)\0\0\0\0\0,\0\0\0\0:\0\0\0\0\0\0";

void morsecalc_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void morsecalc_face_activate(movement_settings_t *settings, void *context);
bool morsecalc_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void morsecalc_face_resign(movement_settings_t *settings, void *context);

typedef struct {
	calc_state_t *cs;
	unsigned int mc; // Morse code character
	char token[MORSECALC_TOKEN_LEN];
	uint8_t idxt;
	uint8_t led_is_on;
} morsecalc_state_t;

void morsecalc_reset_token(morsecalc_state_t *mcs);
void morsecalc_input(morsecalc_state_t *mcs);

#define morsecalc_face ((const watch_face_t){ \
    morsecalc_face_setup, \
    morsecalc_face_activate, \
    morsecalc_face_loop, \
    morsecalc_face_resign, \
    NULL, \
    NULL, \
})

#endif // MORSECALC_FACE_H_
