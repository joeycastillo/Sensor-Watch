/*
 * MIT License
 *
 * Copyright (c) 2022 Jeremy O'Brien
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

#ifndef TAROT_FACE_H_
#define TAROT_FACE_H_

#include "movement.h"

#define MAX_CARDS_TO_DRAW 10

typedef struct {
    uint8_t drawn_cards[MAX_CARDS_TO_DRAW];
    uint8_t current_card;
    uint8_t animation_frame;
    uint8_t num_cards_to_draw;
    bool is_picking;
} tarot_state_t;

void tarot_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tarot_face_activate(movement_settings_t *settings, void *context);
bool tarot_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tarot_face_resign(movement_settings_t *settings, void *context);

#define tarot_face ((const watch_face_t){ \
    tarot_face_setup, \
    tarot_face_activate, \
    tarot_face_loop, \
    tarot_face_resign, \
    NULL, \
})

#endif // TAROT_FACE_H_
