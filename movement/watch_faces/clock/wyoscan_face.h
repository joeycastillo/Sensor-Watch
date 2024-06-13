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

/*
 * WYOSCAN .5 hz watchface
 *
 * This is a recreation of the Wyoscan watch, which was a $175 watch in 2014.
 * It was an f-91w pcb replacement.
 * 
 * Video: https://user-images.githubusercontent.com/1795778/252550124-e07f0ed1-e328-4337-a654-fa1ee65d883f.mp4
 * Background information: https://artmetropole.com/shop/11460
 * Demo of what it looks like: https://www.o-r-g.com/apps/wyoscan
 *
 * 8 frames per number * 6 numbers + the trailing 16 frames = 64 frames
 * at 32 frames per second, this is a 2-second cycle time or 0.5 Hz.
 *
 * It is giving me a stack overflow after about 2.5 cycles of the time display
 * in the emulator, but it works fine on the watch.
 *
 * I'd like to make something for the low energy mode, but I haven't thought
 * about how that might work, right now it just freezes in low energy mode
 * until you press the 12-24HR button.
 *
 * There are no controls; it simply animates as long as the page is active.
 *
 */

#include "movement.h"

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

