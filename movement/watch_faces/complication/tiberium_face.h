/*
 * MIT License
 *
 * Copyright (c) 2026 Stebbs
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

#ifndef TIBERIUM_FACE_H_
#define TIBERIUM_FACE_H_

/*
 * TIBERIUM HARVESTER FACE
 *
 * A Command & Conquer inspired harvester animation.
 * Watch the harvester collect tiberium and fill the refinery!
 *
 * ALARM button toggles between harvester view and refinery tank view.
 */

#include "movement.h"

typedef struct {
    uint8_t frame;            // Harvester animation frame
    uint8_t counter;          // Tiberium counter (counts down from 30)
    uint8_t view_mode;        // 0 = harvester, 1 = refinery
    uint8_t anim_state;       // 0 = gathering, 1 = explosion
    uint8_t explosion_frame;  // Explosion animation frame
    uint8_t explosion_loops;  // How many times explosion has looped
    bool blink_on;            // Blink state for refinery fill
    bool paused;
} tiberium_state_t;

void tiberium_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tiberium_face_activate(movement_settings_t *settings, void *context);
bool tiberium_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tiberium_face_resign(movement_settings_t *settings, void *context);

#define tiberium_face ((const watch_face_t){ \
    tiberium_face_setup, \
    tiberium_face_activate, \
    tiberium_face_loop, \
    tiberium_face_resign, \
    NULL, \
})

#endif // TIBERIUM_FACE_H_
