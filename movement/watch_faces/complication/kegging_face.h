/*
 * MIT License
 *
 * Copyright (c) 2024 Patrick McGuire
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

#ifndef KEGGING_FACE_H_
#define KEGGING_FACE_H_

#include "movement.h"

/*
 * Kegging Tracker
 *
 * This complication helps me keep track of beer kegging quantities. It can be
 * used to calculate the total barrels kegged and the number of barrels that
 * can still be kegged in relation to the number of barrels the cleaning
 * chemicals can support.
 *
 * 1/2 kegs = 1/2 barrel
 * sixtels = 1/6 barrel
 * cleaning chemicals are good for up to 20BBLs
 *
 * How to use it:
 * TBD
 *
 */

typedef struct {
    // Anything you need to keep track of, put it here!
    bool using; // Whether the face is currently in use
    int8_t watch_face_index;
    uint8_t half_kegs;  // Number of half-kegs (1/2 BBL each)
    uint8_t sixtels;    // Number of sixtels (1/6 BBL each)
} kegging_state_t;

void kegging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void kegging_face_activate(movement_settings_t *settings, void *context);
bool kegging_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void kegging_face_resign(movement_settings_t *settings, void *context);

#define kegging_face ((const watch_face_t){ \
    kegging_face_setup, \
    kegging_face_activate, \
    kegging_face_loop, \
    kegging_face_resign, \
    NULL, \
})

#endif // KEGGING_FACE_H_

