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

#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "movement_faces.h"

const watch_face_t watch_faces[] = {
    simple_clock_face,
    world_clock_face,
    sunrise_sunset_face,
    moon_phase_face,
    stopwatch_face,
    preferences_face,
    set_time_face,
    thermistor_readout_face,
    voltage_face
};

#define MOVEMENT_NUM_FACES (sizeof(watch_faces) / sizeof(watch_face_t))

/* This allows you to set up multiple "pages" of faces. Pressing the mode
 * button will move through the faces in the current page, and long-pressing
 * mode from the first face on a page will jump to the next page. Pressing mode
 * at the end of a page or long-pressing mode on a face that isn't at the start
 * of a page will return you to the initial page.
 *
 * This allows you to quickly cycle through the faces that are important to
 * you, while hiding and organizing lesser-used faces behind long-presses of
 * the mode button.
 *
 * By default, the second page of faces (temperature and battery voltage) are
 * hidden using MOVEMENT_HIDDEN_FACES_INDEX. If you just want a simple list of
 * faces instead of having some hidden, you can set movement_pages to { 0 } and
 * MOVEMENT_HIDDEN_FACES_INDEX to 0.
 */
const uint8_t movement_pages[] = { 0, MOVEMENT_NUM_FACES - 2 };

#define MOVEMENT_NUM_PAGES (sizeof(movement_pages) / sizeof(*movement_pages))

#define MOVEMENT_HIDDEN_FACES_INDEX MOVEMENT_NUM_FACES - 2

/* Setting this to true will make a long-press of the mode button always jump
 * to the next page, instead of the default behaviour, which is only jumping to
 * the next page if you are on the first face of a page. This is likely most
 * useful if you have a large number of faces, but it has the downside that it
 * can make returning to the first face more difficult. */
#define MOVEMENT_MODE_LONGPRESS_ALWAYS_NEXT_PAGE false

/* Custom hourly chime tune. Check movement_custom_signal_tunes.h for options */
#define SIGNAL_TUNE_DEFAULT

#endif // MOVEMENT_CONFIG_H_
