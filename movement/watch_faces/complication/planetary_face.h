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

#ifndef PLANETARY_FACE_H_
#define PLANETARY_FACE_H_

#include "movement.h"
#include "sunrise_sunset_face.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

typedef struct {
    // Anything you need to keep track of, put it here!
    uint32_t phase_start;
    uint32_t phase_end;
    bool night;
    double utc_offset;
    double freq;
    bool greek;
    bool day_ruler;
    bool no_location;
    sunrise_sunset_state_t sunstate;
} planetary_state_t;

void planetary_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void planetary_face_activate(movement_settings_t *settings, void *context);
bool planetary_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void planetary_face_resign(movement_settings_t *settings, void *context);

#define planetary_face ((const watch_face_t){ \
    planetary_face_setup, \
    planetary_face_activate, \
    planetary_face_loop, \
    planetary_face_resign, \
    NULL, \
})

#endif // PLANETARY_FACE_H_

