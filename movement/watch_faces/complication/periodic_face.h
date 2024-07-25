/*
 * MIT License
 *
 * Copyright (c) 2023 PrimmR
 * Copyright (c) 2024 David Volovskiy
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

#ifndef PERIODIC_FACE_H_
#define PERIODIC_FACE_H_

#include "movement.h"

/*
 * Periodic Table Face
 * Allows for viewing data of the Periodic Table on your wrist.
 * When looking at an element, it'll show you the atomic number on the center of the screen,
 * symbol on the right, and it's group on the top-right.
 * Pressing the mode button will cycle through the pages.
 *   Page 1: Atomic Mass
 *   Page 2: Year Discovered
 *   Page 3: Electronegativity
 *   Page 4: Full Name of the Element
 * 
 * Controls:
 *    Mode Press
 *        On Title: Next Screen
 *        Else: Cycle through info of an element
 *    Mode Hold
 *        On Title: First Screen
 *        On Element Symbol Screen: Go to Title Screen
 *        Else: Go to Symbol Screen of current element
 *    If you are in a subscreen and just keep holding MODE, you will go through all of these menus without needing to depress.
 * 
 *    Light Press
 *        On Title or Element Symbol Screen: Previous Element
 *                                     Else: Display currenlt-selected element symbol page
 *    Light Hold
 *        On Title Screen or Element Symbol: Fast Cycle through Previous Elements
 *                                     Else: Activate LED backlight
 *
 *    Alarm Press
 *        On Title or Element Symbol Screen: Next Element
 *                                     Else: Display currenlt-selected element symbol page
 *    Alarm Hold
 *        On Title Screen or Element Symbol: Fast Cycle through Next Elements
 */

#define MODE_VIEW 0
#define MODE_SELECT 1

typedef struct {
    uint8_t atomic_num;
    uint8_t mode;
    uint8_t selection_index;
} periodic_state_t;

void periodic_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void periodic_face_activate(movement_settings_t *settings, void *context);
bool periodic_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void periodic_face_resign(movement_settings_t *settings, void *context);

#define periodic_face ((const watch_face_t){ \
    periodic_face_setup, \
    periodic_face_activate, \
    periodic_face_loop, \
    periodic_face_resign, \
    NULL, \
})

#endif // PERIODIC_FACE_H_

