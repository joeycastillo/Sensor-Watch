/*
 * MIT License
 *
 * Copyright (c) 2024 Klingon Jane, based on simple_clock_face by:
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

#ifndef PRIME_CLOCK_FACE_H_
#define PRIME_CLOCK_FACE_H_

#include "movement.h"

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    uint8_t indexer;		// Value from 0 to 16 inclusive
    uint16_t seconds_bitfield;		// From master prime bitfield table
    uint8_t next_prime_second;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;
    bool force_print;		// Must print something this round.
    bool next_required;		// Must calculate next_prime_second
    bool mode_24h;
    bool this_minute_displayed;	// Has this minute already been displayed?
    bool this_hour_displayed;	// Has this hour already been displayed?
    uint8_t my_mod;			// Modulus of current time ( 0, 1 or 2 ); there are 3 patterns
} prime_clock_state_t;

void prime_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void prime_clock_face_activate(movement_settings_t *settings, void *context);
bool prime_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void prime_clock_face_resign(movement_settings_t *settings, void *context);
bool prime_clock_face_wants_background_task(movement_settings_t *settings, void *context);

#define prime_clock_face ((const watch_face_t){ \
    prime_clock_face_setup, \
    prime_clock_face_activate, \
    prime_clock_face_loop, \
    prime_clock_face_resign, \
    prime_clock_face_wants_background_task, \
})

#endif // PRIME_CLOCK_FACE_H_
