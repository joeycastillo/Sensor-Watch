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

#ifndef ASTRONOMY_FACE_H_
#define ASTRONOMY_FACE_H_

#include "movement.h"
#include "astrolib.h"

typedef enum {
    ASTRONOMY_MODE_SELECTING_BODY = 0,
    ASTRONOMY_MODE_CALCULATING,
    ASTRONOMY_MODE_DISPLAYING_ALT,
    ASTRONOMY_MODE_DISPLAYING_AZI,
    ASTRONOMY_MODE_DISPLAYING_RA,
    ASTRONOMY_MODE_DISPLAYING_DEC,
    ASTRONOMY_MODE_DISPLAYING_DIST,
    ASTRONOMY_MODE_NUM_MODES
} astronomy_mode_t;

typedef struct {
    astronomy_mode_t mode;
    uint8_t active_body_index;
    uint8_t animation_state;
    double latitude_radians;    // this is the user location
    double longitude_radians;   // but in radians
    astro_angle_hms_t right_ascension;
    astro_angle_dms_t declination;
    double altitude;    // in decimal degrees
    double azimuth;     // in decimal degrees
    double distance;    // in AU
} astronomy_state_t;

void astronomy_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void astronomy_face_activate(movement_settings_t *settings, void *context);
bool astronomy_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void astronomy_face_resign(movement_settings_t *settings, void *context);

#define astronomy_face ((const watch_face_t){ \
    astronomy_face_setup, \
    astronomy_face_activate, \
    astronomy_face_loop, \
    astronomy_face_resign, \
    NULL, \
})

#endif // ASTRONOMY_FACE_H_
