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
#define MORSECALC_TOKEN_LEN 9

#include "movement.h"
#include "calc.h"
#include "mc.h"

void morsecalc_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void morsecalc_face_activate(movement_settings_t *settings, void *context);
bool morsecalc_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void morsecalc_face_resign(movement_settings_t *settings, void *context);

typedef struct {
	calc_state_t *cs;
	mc_state_t *mc; 
	char token[MORSECALC_TOKEN_LEN];
	uint8_t idxt;
} morsecalc_state_t;

void morsecalc_print_float(double d);
void morsecalc_print_token(morsecalc_state_t *mcs);
void morsecalc_print_stack(morsecalc_state_t *mcs);
void morsecalc_reset_token(morsecalc_state_t *mcs);
void morsecalc_input(morsecalc_state_t *mcs, char c);

#define morsecalc_face ((const watch_face_t){ \
    morsecalc_face_setup, \
    morsecalc_face_activate, \
    morsecalc_face_loop, \
    morsecalc_face_resign, \
    NULL, \
})

#endif // MORSECALC_FACE_H_
