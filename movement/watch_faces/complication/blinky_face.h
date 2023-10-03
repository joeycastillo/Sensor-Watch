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

#ifndef BLINKY_FACE_H_
#define BLINKY_FACE_H_

/*
 * BLINKY LIGHT face
 *
 * The blinky light watch face was designed as a tutorial for making a watch
 * face in Movement, but it actually might be useful to have a blinking light
 * in a pinch.
 *
 * The screen displays the name of the watch face (”BL”), as well as an S at
 * the top right for slow blink or an F for fast blink. The bottom line selects
 * the color: green, red or yellow. You can change the speed of the blinking
 * light by pressing the Alarm button, and change the color with the Light
 * button. A long press on the Alarm button starts the blinking light, and
 * another long press stops it.
 *
 * Note that this will chew through your battery! The green LED uses about
 * 450µA at full brightness, which is 45 times the normal power consumption of
 * the watch. The red LED is an order of magnitude less efficient (4500 µA),
 * and the yellow setting lights both LEDs, which chews through nearly
 * 5 milliamperes. This means that one hour of yellow blinking is likely to
 * eat up between 2 and 3 percent of the battery’s usable life!
 *
 * Still, if you need to signal your location to someone in a dark forest,
 * this watch face could come in handy. Just try to use the green LED as much
 * as you can.
 */

#include "movement.h"

typedef struct {
    bool active;
    bool fast;
    uint8_t color;
} blinky_face_state_t;

void blinky_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void blinky_face_activate(movement_settings_t *settings, void *context);
bool blinky_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void blinky_face_resign(movement_settings_t *settings, void *context);

#define blinky_face ((const watch_face_t){ \
    blinky_face_setup, \
    blinky_face_activate, \
    blinky_face_loop, \
    blinky_face_resign, \
    NULL, \
})

#endif // BLINKY_FACE_H_
