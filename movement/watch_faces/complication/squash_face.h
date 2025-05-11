/*
 * MIT License
 *
 * Copyright (c) 2025 Johan Oskarsson
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

#ifndef SQUASH_FACE_H_
#define SQUASH_FACE_H_

#include "movement.h"

/*
 * Squash Scoring Face
 *
 * Keep track of scores in a squash match:
 * - Light button: Increment player 1's score
 * - Alarm button: Increment player 2's score
 * - Mode button long press: Reset scores
 * - Mode button: Switch to next watch face
 */

typedef struct {
    uint8_t player1_score;
    uint8_t player2_score;
    uint8_t player1_games;
    uint8_t player2_games;
    bool is_game_over;
} squash_state_t;

void squash_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void squash_face_activate(movement_settings_t *settings, void *context);
bool squash_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void squash_face_resign(movement_settings_t *settings, void *context);

#define squash_face ((const watch_face_t){ \
    squash_face_setup, \
    squash_face_activate, \
    squash_face_loop, \
    squash_face_resign, \
    NULL, \
})

#endif // SQUASH_FACE_H_

