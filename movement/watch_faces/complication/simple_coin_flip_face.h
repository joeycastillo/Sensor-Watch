/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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

#ifndef SIMPLE_COIN_FLIP_FACE_H_
#define SIMPLE_COIN_FLIP_FACE_H_

#include "movement.h"

/*
 * A extremely simple coin flip face.
 *
 * Press ALARM or LIGHT to flip a coin, after a short animation it will display
 * "Heads" or "Tails". Long-press to flip again (you can change a #define to
 * allow a short-press to reflip as well, if you'd like).
 *
 * This is for people who want a simpler UI than probability_face or
 * randonaut_face. While those have more features, this one is more immediately
 * obvious - useful, for instance, if you are using a coin flip to agree on
 * something with someone, and want the operation to be clear to someone who
 * has not had anything explained to them.
 */

typedef struct {
    uint8_t animation_frame;
} simple_coin_flip_state_t;

void simple_coin_flip_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void simple_coin_flip_face_activate(movement_settings_t *settings, void *context);
bool simple_coin_flip_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void simple_coin_flip_face_resign(movement_settings_t *settings, void *context);

#define simple_coin_flip_face ((const watch_face_t){ \
    simple_coin_flip_face_setup, \
    simple_coin_flip_face_activate, \
    simple_coin_flip_face_loop, \
    simple_coin_flip_face_resign, \
    NULL, \
})

#endif // SIMPLE_COIN_FLIP_FACE_H_

