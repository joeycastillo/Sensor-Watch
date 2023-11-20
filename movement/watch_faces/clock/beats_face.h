/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Ellis <https://github.com/tahnok>
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

#ifndef BEATS_FACE_H_
#define BEATS_FACE_H_

/*
 * BEATS TIME face
 *
 * The Beat Time face displays the current Swatch Internet Time, or .beat time.
 * This is a decimal time system that divides the day into 1000 beats.
 *
 * The three large digits in the bottom row indicate the current beat, and the
 * two smaller digits (normally the seconds in Simple Clock) indicate the
 * fractional beat; so for example you can read “67214” as “beat 672.14”.
 */

#include "movement.h"

typedef struct {
    int8_t next_subsecond_update;
    uint32_t last_centibeat_displayed;
} beats_face_state_t;

uint32_t clock2beats(uint32_t hours, uint32_t minutes, uint32_t seconds, uint32_t subseconds, int16_t utc_offset);
void beats_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void beats_face_activate(movement_settings_t *settings, void *context);
bool beats_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void beats_face_resign(movement_settings_t *settings, void *context);

#define beats_face ((const watch_face_t){ \
    beats_face_setup, \
    beats_face_activate, \
    beats_face_loop, \
    beats_face_resign, \
    NULL, \
})

#endif // BEATS_FACE_H_