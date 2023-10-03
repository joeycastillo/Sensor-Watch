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

#ifndef ORRERY_FACE_H_
#define ORRERY_FACE_H_

/*
 * ORRERY face
 *
 * The Orrery watch face is similar to the Astronomy watch face in that it
 * calculates properties of the planets, but instead of calculating their
 * positions in the sky, this watch face calculates their absolute locations
 * in the solar system. This is only useful if you want to plot the planets
 * on graph paper, but hey, you never know!
 * 
 * The controls are identical to the Astronomy watch face: while the title
 * screen (“Orrery”) is displayed, you can advance through the available
 * planets with repeated short presses on the Alarm button. The available
 * planets:
 * 
 *     ME - Mercury
 *     VE - Venus
 *     EA - Earth
 *     LU - Luna, the Earth’s moon
 *     MA - Mars
 *     JU - Jupiter
 *     SA - Saturn
 *     UR - Uranus
 *     NE - Neptune
 * 
 * Note that the sun is not available in this menu, as the sun is always at
 * (0,0,0) in this calculation.
 * 
 * Long press on the Alarm button to calculate the planet’s location, and
 * after a flashing “C” (for Calculating), you will be presented with the
 * planet’s X coordinate in astronomical units. Short press Alarm to cycle
 * through the X, Y and Z coordinates, and then long press Alarm to return
 * to planet selection.
 * 
 * The large numbers represent the whole number part, and the two smaller
 * numbers (in the seconds place) represent the decimal portion. So if you
 * see “SA X 736” and “SA Y -662”, you can read that as an X coordinate of
 * 7.36 AU and a Y coordinate of -6.62 AU. You can literally draw a dot at
 * (0, 0) to represent the sun, and a dot at (7.36, -6.62) to represent
 * Saturn. (The Z coordinates tend to be pretty close to zero, as the
 * planets largely orbit on a single plane, the ecliptic.)
 */

#include "movement.h"

typedef enum {
    ORRERY_MODE_SELECTING_BODY = 0,
    ORRERY_MODE_CALCULATING,
    ORRERY_MODE_DISPLAYING_X,
    ORRERY_MODE_DISPLAYING_Y,
    ORRERY_MODE_DISPLAYING_Z,
    ORRERY_MODE_NUM_MODES
} orrery_mode_t;

typedef struct {
    orrery_mode_t mode;
    uint8_t active_body_index;
    double coords[3];
    uint8_t animation_state;
} orrery_state_t;

void orrery_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void orrery_face_activate(movement_settings_t *settings, void *context);
bool orrery_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void orrery_face_resign(movement_settings_t *settings, void *context);

#define orrery_face ((const watch_face_t){ \
    orrery_face_setup, \
    orrery_face_activate, \
    orrery_face_loop, \
    orrery_face_resign, \
    NULL, \
})

#endif // ORRERY_FACE_H_
