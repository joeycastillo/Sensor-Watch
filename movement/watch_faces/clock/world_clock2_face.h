/*
 * MIT License
 *
 * Copyright (c) 2023 Konrad Rieck
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

#ifndef WORLD_CLOCK2_FACE_H_
#define WORLD_CLOCK2_FACE_H_

/* Number of zones. See movement_timezone_offsets. */
#define NUM_TIME_ZONES  41

#include "movement.h"

typedef enum {
    WORLD_CLOCK2_MODE_DISPLAY,
    WORLD_CLOCK2_MODE_SETTINGS
} world_clock2_mode_t;

typedef struct {
    bool selected;
} world_clock2_zone_t;

typedef struct {
    world_clock2_zone_t zones[NUM_TIME_ZONES];
    world_clock2_mode_t current_mode;
    uint8_t current_zone;
    uint32_t previous_date_time;
} world_clock2_state_t;

void world_clock2_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr);
void world_clock2_face_activate(movement_settings_t *settings, void *context);
bool world_clock2_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void world_clock2_face_resign(movement_settings_t *settings, void *context);

#define world_clock2_face ((const watch_face_t){ \
    world_clock2_face_setup, \
    world_clock2_face_activate, \
    world_clock2_face_loop, \
    world_clock2_face_resign, \
    NULL, \
})

#endif /* WORLD_CLOCK2_FACE_H_ */
