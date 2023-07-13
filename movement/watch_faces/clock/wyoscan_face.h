/*
 * MIT License
 *
 * Copyright (c) 2023 <#author_name#>
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

#ifndef WYOSCAN_FACE_H_
#define WYOSCAN_FACE_H_

#include "movement.h"

/*
 * A DESCRIPTION OF YOUR WATCH FACE
 *
 * and a description of how use it
 *
 */

#define MAX_ILLUMINATED_SEGMENTS 16

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;
    uint8_t animation;
    bool animate;
    uint32_t start;
    uint32_t end;
    uint32_t total_frames;
    bool colon;
    uint8_t position, segment;
    char *segments;
    uint8_t x, y;
    uint32_t time_digits[6];
    uint32_t illuminated_segments[MAX_ILLUMINATED_SEGMENTS][2]; 
} wyoscan_state_t;

void wyoscan_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void wyoscan_face_activate(movement_settings_t *settings, void *context);
bool wyoscan_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void wyoscan_face_resign(movement_settings_t *settings, void *context);
bool wyoscan_face_wants_background_task(movement_settings_t *settings, void *context);

#define wyoscan_face ((const watch_face_t){ \
    wyoscan_face_setup, \
    wyoscan_face_activate, \
    wyoscan_face_loop, \
    wyoscan_face_resign, \
    NULL, \
})

#endif // WYOSCAN_FACE_H_

