/*
 * MIT License
 *
 * Copyright (c) 2022 Andrew Mike
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

#ifndef TALLY_FACE_H_
#define TALLY_FACE_H_

/*
 * TALLY face
 *
 * Tally face is designed to act as a tally counter.
 *
 * Alarm
 *    Press: Decrement
 *    Hold : Fast Decrement
 *
 * Light
 *    Press: Increment
 *    Hold : On initial value: Cycles through other initial values.
 *                       Else: Fast Increment
 *
 * Mode
 *    Press: Next face
 *    Hold : On initial value: Go to first face.
 *                       Else: Resets counter
 * 
 * Incrementing or Decrementing the tally will beep if Beeping is set in the global Preferences
 */

#include "movement.h"

typedef struct {
    int16_t tally_idx;
    uint8_t tally_default_idx;
} tally_state_t;

//#define TALLY_FACE_PRESETS_MTG
//#define TALLY_FACE_PRESETS_YUGIOH


void tally_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tally_face_activate(movement_settings_t *settings, void *context);
bool tally_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tally_face_resign(movement_settings_t *settings, void *context);

void print_tally(tally_state_t *state, bool sound_on);

#define tally_face ((const watch_face_t){ \
    tally_face_setup, \
    tally_face_activate, \
    tally_face_loop, \
    tally_face_resign, \
    NULL, \
})

#endif // TALLY_FACE_H_
