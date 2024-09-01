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

/*
 * ASTRONOMY face
 *
 * The Astronomy watch face is among the most complex watch faces in the
 * Movement collection. It allows you to calculate the locations of celestial
 * bodies in the sky, as well as distance in astronomical units (or, in the
 * case of the Moon, distance in kilometers).
 * 
 * When you arrive at the Astronomy watch face, you’ll see its name (“Astro”)
 * and an animation of two objects orbiting each other. You will also see “SO”
 * (for Sol) flashing in the top left. The flashing letters indicate the
 * currently selected celestial body. Short press Alarm to advance through
 * the available celestial bodies:
 * 
 *     SO - Sol, the sun
 *     ME - Mercury
 *     VE - Venus
 *     LU - Luna, the Earth’s moon
 *     MA - Mars
 *     JU - Jupiter
 *     SA - Saturn
 *     UR - Uranus
 *     NE - Neptune
 * 
 * Once you’ve selected the celestial body whose parameters you wish to
 * calculate, long press the Alarm button and release it. The letter “C” will
 * flash while the calculation is performed.
 * 
 * When the calculation is complete, the screen will display the altitude
 * (“aL”) of the celestial body. You can cycle through the available parameters
 * with repeated short presses on the Alarm button:
 * 
 *     aL - Altitude (in degrees), the elevation over the horizon. If negative, it is below the horizon.
 *     aZ - Azimuth (in degrees), the cardinal direction relative to true north.
 *     rA - Right Ascension (in hours/minutes/seconds)
 *     dE - Declination (in degrees/minutes/seconds)
 *     di - Distance (the digits in the top right will display either aU for astronomical units, or K for kilometers)
 * 
 * Long press on the Alarm button to select another celestial body.
 */

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
