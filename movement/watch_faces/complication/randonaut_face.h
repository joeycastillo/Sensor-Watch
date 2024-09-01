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

#ifndef RANDONAUT_FACE_H_
#define RANDONAUT_FACE_H_

/*
 * RANDONAUT face
 * ==============
 *
 * Randonauting is a way to turn the world around you into an adventure and get the user outside 
 * of their day-to-day routine by using a random number generator to derive a coordinate to journey 
 * to. In Randonauts lore so-called "Blind Spots" are places you cannot reach methodologically. They
 * may exist in your own backyard for your whole life and you will never even notice them, because 
 * you simply have no reason to go to that exact place or look in its direction. Since the very 
 * limitations of our behavioral algorithms are the reason for the existence of blindspots, they 
 * can only be found using a randomizer.
 * 
 * This watch face generates a random location based on the watch's location and a set radius using
 * the official Randonautica Blind Spot algorithm.
 * 
 * The ALARM button starts the random location generation and then automatically displays the found
 * Blind Spot.
 * 
 * By pressing ALARM again the user can flip through different pieces of information about the Blind
 * Spot: Distance (DI), Bearing Degree (BE), Latitude degrees and decimal digits (LA), Longitude 
 * degrees and decimal digits (LO).
 * 
 * Pressing LIGHT switches between generating a new blind spot ("Rando") and displaying the info of
 * the last generated one ("Point").
 * 
 * LONG PRESSING LIGHT toggles setup mode. Here pressing LIGHT switches between setting the desired
 * radius (RA) and setting the random number generator (RNG) for generating the blind spot. 
 * 
 * ALARM changes the values respectively:
 * 
 * - The radius can be set in 500 meter steps between 1000 and 10,000 meters
 * 
 * - The RNG can be set to "true" which utilizes the SAML22J's internal True Random Number Generator
 * - Setting it to "psudo" will use the pseudorandom number generation algorithm arc4random
 * - Setting it to "chance" will randomly chose either of the RNGs for each generation (default)
 *
 * LONG PRESSING ALARM toggles DATA mode in which the currently generated Blind Spot coordinate can
 * be written to the <place.loc> file on the watch (press ALARM) and set as active high precision 
 * location used by other watch faces. It does not overwrite the low precision location information
 * in the watch register commonly used for astronomical watch faces.
 * 
 */

#include "movement.h"
#include "place_face.h"

typedef struct {
    uint8_t mode :3;
    uint8_t location_format :3;
    uint8_t rng: 2;
} randonaut_face_mode_t;

typedef struct {
    int32_t latitude : 26;
    int32_t longitude : 26;
    uint16_t distance : 14;
    uint16_t bearing : 9;
} randonaut_coordinate_t;

typedef struct {
    // Anything you need to keep track of, put it here!
    coordinate_t location;
    randonaut_coordinate_t point;
    uint16_t radius : 14;
    uint32_t entropy;
    bool quantum;
    bool chance;
    randonaut_face_mode_t face;
    char scratchpad[10];
} randonaut_state_t;

void randonaut_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void randonaut_face_activate(movement_settings_t *settings, void *context);
bool randonaut_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void randonaut_face_resign(movement_settings_t *settings, void *context);

#define randonaut_face ((const watch_face_t){ \
    randonaut_face_setup, \
    randonaut_face_activate, \
    randonaut_face_loop, \
    randonaut_face_resign, \
    NULL, \
})

#endif // RANDONAUT_FACE_H_

