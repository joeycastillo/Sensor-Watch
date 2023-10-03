/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef MOON_PHASE_FACE_H_
#define MOON_PHASE_FACE_H_

/*
 * MOON PHASE face
 *
 * The Moon Phase face is similar to the Sunrise/Sunset face: it displays the
 * current phase of the moon, along with the day of the month and a graphical
 * representation of the moon on the top row.
 * 
 * This graphical representation is a bit abstract. The segments that turn on
 * represent the shape of the moon, waxing from the bottom right and waning at
 * the top left. A small crescent at the bottom right will grow into a larger
 * crescent, then add lines in the center for a quarter and half moon. All
 * segments are on during a full moon. Then gradually the segments at the
 * bottom right will turn off, until all that remains is a small waning
 * crescent at the top left.
 * 
 * All segments turn off during a new moon.
 * 
 * On this screen you may press the Alarm button repeatedly to move forward
 * in time: the day of the month at the top right will advance by one day for
 * each button press, and both the text and the graphical representation will
 * display the moon phase for that day. Try pressing the Alarm button 27 times
 * now, just to visualize what the moon will look like over the next month.
 */

#include "movement.h"

typedef struct {
    uint32_t offset;
} moon_phase_state_t;

void moon_phase_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void moon_phase_face_activate(movement_settings_t *settings, void *context);
bool moon_phase_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void moon_phase_face_resign(movement_settings_t *settings, void *context);

#define moon_phase_face ((const watch_face_t){ \
    moon_phase_face_setup, \
    moon_phase_face_activate, \
    moon_phase_face_loop, \
    moon_phase_face_resign, \
    NULL, \
})

#endif // MOON_PHASE_FACE_H_

