/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
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

#ifndef GEOMANCY_FACE_H_
#define GEOMANCY_FACE_H_

/*
 * GEOMANCY watch face
 *
 * A simple and straightforward watch face for the ancient Eastern geomantic divination system
 * of I Ching and the western system of "Geomancy". It is an optional addition to the Toss Up
 * Face.
 * 
 * The LIGHT button toggles between the two systems of geomancy.
 * 
 * The ALARM button casts an I Ching hexagram or Geomantic figure based on drawing virtual
 * stalks from the True Random Number Generator in the Sensor Watch.
 * 
 * The figures are flipped 90 degrees clockwise, so the left side is the bottom and the
 * right side the top.
 * 
 * LONG PRESSING ALARM toggles the display of the King Wen sequence index for the cast I Ching
 * Hexagram (https://en.wikipedia.org/wiki/King_Wen_sequence )or the abbreviated name for the
 * cast Geomantic Figure:
 * 
 * GF - Greater Fortune (Fortuna Major)
 * LF - Lesser Fortune (Fortuna Minor)
 * PO - Populus
 * VI - Via
 * AL - Albus
 * CO - Conjunctio
 * PA - Puella
 * AM - Amissio
 * PR - Puer
 * RU - Rubeus
 * AQ - Acquisitio
 * LA - Laetitia
 * TR - Tristitia
 * CA - Carcer
 * HD - Head of the Dragon (Caput Draconis)
 * TD - Tail of the Dragon (Cauda Draconis)
 * 
 */

#include "movement.h"

typedef struct {
    uint8_t bits : 4;
} nibble_t;

typedef struct {
    uint8_t bits : 3;
} tribble_t;

typedef struct {
    uint8_t mode : 3;
    uint8_t geomantic_figure;
    uint8_t i_ching_hexagram : 6;
    bool caption;
    uint8_t animation;
    bool animate;
} geomancy_state_t;

void geomancy_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void geomancy_face_activate(movement_settings_t *settings, void *context);
bool geomancy_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void geomancy_face_resign(movement_settings_t *settings, void *context);

#define geomancy_face ((const watch_face_t){ \
    geomancy_face_setup, \
    geomancy_face_activate, \
    geomancy_face_loop, \
    geomancy_face_resign, \
    NULL, \
})

#endif // GEOMANCY_FACE_H_

