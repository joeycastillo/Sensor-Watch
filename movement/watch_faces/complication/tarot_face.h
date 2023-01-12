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

/*
 * Tarot card watch face
 *
 * Draw from a deck of the 22 major arcana tarot cards.
 *
 * In tarot reading, a card orientation can be upright or inverted, and the
 * interpertation of the card can change depending on this state. This face
 * lights the alarm indicator to show when a card is inverted. Just ignore it
 * if you prefer not to deal with card inversions.
 *
 * When "Draw" is shown:
 * - Light button: cycle # of cards to draw
 * - Alarm button: shuffle deck and draw cards
 *
 * After cards are drawn/showing:
 * - Light button: view the next drawn card
 * - Alarm button: shuffle and re-draw new cards
 * - Light button (long press): go back to Draw screen,
 *   for choosing different # of cards to draw.
 */

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
