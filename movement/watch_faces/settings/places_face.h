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

#ifndef PLACES_FACE_H_
#define PLACES_FACE_H_

#include "movement.h"
#include "place_face.h"

/*
 * PLACES FACE
 * ===========
 * 
 * This is an optional addition to the Place Face to manage up to 5 locations. It is inspired by 
 * the Casio FA-1500 World Time watch where you can swap the current timezone with another one while
 * traveling.
 * 
 * The ALARM button flips through the 5 available place slots.
 * 
 * Slot 1 is the currently active location (saved in <place.loc> and register).
 * 
 * When one of the places 2 - 5 is selected, long pressing ALARM swaps the place with slot 1 
 * making it the active location.
 * 
 * Editing Mode
 * ============
 * 
 * A LONG PRESS of the LIGHT button toggles editing mode for the currently selected place slot and
 * allows to change its default name LOC # to something else.
 * 
 * In this mode LIGHT moves the cursor and ALARM changes the letter cycling through the available
 * alphanumeric characters. 
 */

static const char name_alphabet[39] = " AbCdEFGHIJKLMNOPQRSTUVWXYZ_0123456789";

typedef struct {
    uint8_t d01 : 6;
    uint8_t d02 : 6;
    uint8_t d03 : 6;
    uint8_t d04 : 6;
    uint8_t d05 : 6;
} places_name_t;

typedef struct {
    coordinate_t location;
    places_name_t name;
} places_coordinate_t;

typedef struct {
    uint8_t place: 3;
    int8_t active_digit: 4;
    bool edit;
    bool swap;
    places_coordinate_t clipboard;
    places_coordinate_t places[5];
} places_state_t;

// PUBLIC WATCH FACE FUNCTIONS ////////////////////////////////////////////////

void places_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void places_face_activate(movement_settings_t *settings, void *context);
bool places_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void places_face_resign(movement_settings_t *settings, void *context);

#define places_face ((const watch_face_t){ \
    places_face_setup, \
    places_face_activate, \
    places_face_loop, \
    places_face_resign, \
    NULL, \
})

#endif // PLACES_FACE_H_

