/*
 * MIT License
 *
 * Copyright (c) 2023 Andreas Nebinger
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

#ifndef INVADERS_FACE_H_
#define INVADERS_FACE_H_

/*
 * Remake of the "famous" Casio Number Invaders Game
 *
 * This is an authentic remake of the invaders game, found on the Casio
 * calculator wristwatch CA-85 or CA-851. There were also some calculators
 * sold with this game, like MG-880.
 * 
 * How to play:
 * 
 * Press the alarm button to start the game.
 * "Invaders" (just digits, tbh) will start coming in from the right hand side.
 * Press the light button to "aim". The digit on the top of the display cycles
 * from 0 to 9. If your aiming digit is identical to one of the invaders,
 * press the alarm button to "shoot". The corresponding invader will disappear.
 * If the invaders reach beneath the very first position, you loose one defense 
 * line. When all three defense lines are gone, the game is over.
 * Also: If you shoot more than 29 times per round, you loose the game.
 * Good to know: There are 16 invaders per wave. There is a short break between
 * waves.
 * 
 * What are the "n" invaders? Ufos!
 * 
 * Whenever the sum of all invaders shot is divisible by 10 the next invader 
 * will be an ufo, represented by the n-symbol. Shooting a ufo gets you extra
 * points. Example: shoot 2, 5, 3 --> ufo next
 * 
 * As for points: the earlier you shoot an invader, the more points you get.
 *
 * Anything else? Long pressing the light button toggles sound on or off. (Not
 * while playing.)
 * 
 */

#include "movement.h"

typedef struct {
    uint16_t highscore;
    bool sound_on;
} invaders_state_t;

void invaders_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void invaders_face_activate(movement_settings_t *settings, void *context);
bool invaders_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void invaders_face_resign(movement_settings_t *settings, void *context);

#define invaders_face ((const watch_face_t){ \
    invaders_face_setup, \
    invaders_face_activate, \
    invaders_face_loop, \
    invaders_face_resign, \
    NULL, \
})

#endif // INVADERS_FACE_H_

