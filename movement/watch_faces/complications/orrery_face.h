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

#include "movement.h"

typedef enum {
    ORRERY_MODE_SELECTING_BODY = 0,
    ORRERY_MODE_CALCULATING,
    ORRERY_MODE_DISPLAYING_RIGHT_ASCENSION,
    ORRERY_MODE_DISPLAYING_DECLINATION,
    ORRERY_MODE_NUM_MODES
} orrery_mode_t;

typedef enum {
    ORRERY_CELESTIAL_BODY_MERCURY = 0,
    ORRERY_CELESTIAL_BODY_VENUS,
    ORRERY_CELESTIAL_BODY_LUNA,
    ORRERY_CELESTIAL_BODY_MARS,
    ORRERY_CELESTIAL_BODY_JUPITER,
    ORRERY_CELESTIAL_BODY_SATURN,
    ORRERY_CELESTIAL_BODY_URANUS,
    ORRERY_CELESTIAL_BODY_NEPTUNE,
    ORRERY_CELESTIAL_BODY_NUM_BODIES
} orrery_celestial_body_t;

typedef struct {
    orrery_mode_t mode;
    orrery_celestial_body_t active_body;
    ;
    uint8_t animation_state;
    uint16_t latitude;
    uint16_t longitude;
} orrery_state_t;

void orrery_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void orrery_face_activate(movement_settings_t *settings, void *context);
bool orrery_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void orrery_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t orrery_face = {
    orrery_face_setup,
    orrery_face_activate,
    orrery_face_loop,
    orrery_face_resign,
    NULL
};

#endif // ORRERY_FACE_H_
