/*
 * MIT License
 *
 * Copyright (c) 2023 <#author_name#>
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

#ifndef DIVINATE_FACE_H_
#define DIVINATE_FACE_H_

#include "movement.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

// available characters: 8, C, 0, E, G, H, I, O, r, S, Z, ), d, e, g, h, l, n, +, 0, 

typedef struct {
    uint8_t bits : 4;
} nibble_t;

typedef struct {
    uint8_t bits : 3;
} tribble_t;

typedef struct {
    // Anything you need to keep track of, put it here!
    uint32_t entropy;
    uint8_t mode : 4; // 1 coin, 2 coins, 3 coins, 4 coins, dice, iching, geomnc
    bool setup;
    char binary[3][2][7];
    bool one_coin;
    bool two_coins[2];
    bool three_coins[2];
    bool four_coins[2];
    uint8_t dice;
    uint8_t iching : 6;
    uint8_t geomancy : 4;
} divinate_state_t;

void divinate_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void divinate_face_activate(movement_settings_t *settings, void *context);
bool divinate_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void divinate_face_resign(movement_settings_t *settings, void *context);

#define divinate_face ((const watch_face_t){ \
    divinate_face_setup, \
    divinate_face_activate, \
    divinate_face_loop, \
    divinate_face_resign, \
    NULL, \
})

#endif // DIVINATE_FACE_H_

