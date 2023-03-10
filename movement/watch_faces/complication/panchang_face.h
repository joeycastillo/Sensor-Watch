/*
 * MIT License
 *
 * Copyright (c) 2023 Navaneeth Bhardwaj
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

#ifndef PANCHANG_FACE_H_
#define PANCHANG_FACE_H_

#include "movement.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

typedef enum {
    DAY_PANCHANG,
    RAHU_KALAM,
}panchang_views_t;

typedef struct {
    // Anything you need to keep track of, put it here!
    panchang_views_t curr_view;
} panchang_state_t;

void panchang_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void panchang_face_activate(movement_settings_t *settings, void *context);
bool panchang_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void panchang_face_resign(movement_settings_t *settings, void *context);

#define panchang_face ((const watch_face_t){ \
    panchang_face_setup, \
    panchang_face_activate, \
    panchang_face_loop, \
    panchang_face_resign, \
    NULL, \
})

#endif // PANCHANG_FACE_H_

