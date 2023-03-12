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

#ifndef NEXT_planetary_FACE_H_
#define NEXT_planetary_FACE_H_

#include "movement.h"
#include "planetary_face.h"
#include "sunrise_sunset_face.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

typedef struct {
    // Anything you need to keep track of, put it here!
    uint32_t planetary_hours[24];
    uint32_t phase_start;
    uint32_t phase_end;
    uint32_t phase_next;
    bool next;
    double utc_offset;
    bool no_location;
    int8_t hour;
    bool greek;
    bool start_at_night;
    bool skip_to_current;
    sunrise_sunset_state_t sunstate;
} next_planetary_state_t;

void next_planetary_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void next_planetary_face_activate(movement_settings_t *settings, void *context);
bool next_planetary_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void next_planetary_face_resign(movement_settings_t *settings, void *context);

#define next_planetary_face ((const watch_face_t){ \
    next_planetary_face_setup, \
    next_planetary_face_activate, \
    next_planetary_face_loop, \
    next_planetary_face_resign, \
    NULL, \
})

#endif // NEXT_planetary_FACE_H_

