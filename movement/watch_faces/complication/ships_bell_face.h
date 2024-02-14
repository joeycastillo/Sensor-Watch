/*
 * MIT License
 *
 * Copyright (c) 2023 buckket
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

#ifndef SHIPS_BELL_FACE_H_
#define SHIPS_BELL_FACE_H_

/*
 * SHIP'S BELL face
 * A ship's bell complication.
 *
 * See: https://en.wikipedia.org/wiki/Ship%27s_bell#Simpler_system
 *
 * Similar to the default hourly signal of the simple_clock_face this complication will use the buzzer to signal
 * the time in half-hour intervals according to the scheme mentioned above.
 *
 * Additionally, the user can specify one of the three watches
 * of the standard merchant watch system to only receive signals during this watch.
 *
 * If no watch is specified all signals are emitted.
 *
 * Usage:
 *   - short press Alarm button: Turn on/off bell
 *   - long press Alarm button: Cycle through the watches (All/1/2/3)
 */

#include "movement.h"

typedef struct {
    bool bell_enabled;
    uint8_t on_watch;
} ships_bell_state_t;

void ships_bell_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void ships_bell_face_activate(movement_settings_t *settings, void *context);
bool ships_bell_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void ships_bell_face_resign(movement_settings_t *settings, void *context);
bool ships_bell_face_wants_background_task(movement_settings_t *settings, void *context);

#define ships_bell_face ((const watch_face_t){ \
    ships_bell_face_setup, \
    ships_bell_face_activate, \
    ships_bell_face_loop, \
    ships_bell_face_resign, \
    ships_bell_face_wants_background_task, \
})

#endif // SHIPS_BELL_FACE_H_
