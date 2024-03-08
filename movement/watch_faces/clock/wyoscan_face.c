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

#include <stdlib.h>
#include <string.h>
#include "wyoscan_face.h"
#include "watch_private_display.h"

/*
Slowly render the current time from left to right, 
scanning across its liquid crystal face, completing 1 cycle every 2 seconds.

Created to mimic the wyoscan watch that was produced by Halmos and designed by Dexter Sinister
It looks like this https://www.o-r-g.com/apps/wyoscan

You’ll notice that reading this watch requires more attention than usual, 
as the seven segments of each digit are lit one by one across its display. 
This speed may be adjusted until it reaches the limits of your perception. 
You and your watch are now in tune.

This is a relatively generic way of animating a time display.
If you want to modify the animation, you can change the segment_map
the A-F are corresponding to the segments on the watch face
  A  
F   B
  G
E   C
  D
the X's are the frames that will be skipped in the animation
This particular segment_map allocates 8 frames to display each number
this is to achieve the 2 second cycle time.
8 frames per number * 6 numbers + the trailing 16 frames = 64 frames
at 32 frames per second, this is a 2 second cycle time.

I tried to make the animation of each number display similar to if you were 
to draw the number on the watch face with a pen, pausing with 'X'
when your pen might turn a corner or when you might cross over 
a line you've already drawn. It is vaguely top to bottom and counter,
clockwise when possible.
*/
static char *segment_map[] = {
    "AXFBDEXC",  // 0
    "BXXXCXXX",  // 1
    "ABGEXXXD",  // 2
    "ABGXXXCD",  // 3
    "FXGBXXXC",  // 4
    "AXFXGXCD",  // 5
    "AXFEDCXG",  // 6
    "AXXBXXCX",  // 7
    "AFGCDEXB",  // 8
    "AFGBXXCD"   // 9
};

/*
This is the mapping of input to the watch_set_pixel() function
for each position in hhmmss it defines the 2 dimention input at each of A-F*/
static const int32_t clock_mapping[6][7][2] = {
    // hour 1
    {{1,18}, {2,19}, {0,19}, {1,18}, {0,18}, {2,18}, {1,19}},
    // hour 2
    {{2,20}, {2,21}, {1,21}, {0,21}, {0,20}, {1,17}, {1,20}},
    // minute 1
    {{0,22}, {2,23}, {0,23}, {0,22}, {1,22}, {2,22}, {1,23}},
    // minute 2
    {{2,1}, {2,10}, {0,1}, {0,0}, {1,0}, {2,0}, {1,1}},
    // second 1
    {{2,2}, {2,3}, {0,4}, {0,3}, {0,2}, {1,2}, {1,3}},
    // second 2
    {{2,4}, {2,5}, {1,6}, {0,6}, {0,5}, {1,4}, {1,5}},
};

void wyoscan_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wyoscan_state_t));
        memset(*context_ptr, 0, sizeof(wyoscan_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void wyoscan_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    wyoscan_state_t *state = (wyoscan_state_t *)context;
    movement_request_tick_frequency(32);
    state->total_frames = 64;
}

bool wyoscan_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    wyoscan_state_t *state = (wyoscan_state_t *)context;

    watch_date_time date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            break;
        case EVENT_TICK:            
            if (!state->animate) {
                date_time = watch_rtc_get_date_time();
                state->start = 0; 
                state->end = 0;
                state->animation = 0;
                state->animate = true;
                state->time_digits[0] = date_time.unit.hour / 10;
                state->time_digits[1] = date_time.unit.hour % 10;
                state->time_digits[2] = date_time.unit.minute / 10;
                state->time_digits[3] = date_time.unit.minute % 10;
                state->time_digits[4] = date_time.unit.second / 10;
                state->time_digits[5] = date_time.unit.second % 10;
            }
            if ( state->animate ) {
                // if we have reached the max number of illuminated segments, we clear the oldest one
                if ((state->end + 1) % MAX_ILLUMINATED_SEGMENTS == state->start) {
                    // clear the oldest pixel if it's not 'X'
                    if (state->illuminated_segments[state->start][0] != 99 && state->illuminated_segments[state->start][1] != 99) {
                        watch_clear_pixel(state->illuminated_segments[state->start][0], state->illuminated_segments[state->start][1]);
                    }
                    // increment the start index to point to the next oldest pixel
                    state->start = (state->start + 1) % MAX_ILLUMINATED_SEGMENTS;
                }
                if (state->animation < state->total_frames - MAX_ILLUMINATED_SEGMENTS) {
                    if (state->animation % 32 == 0) {
                        if (state->colon) {
                            watch_set_colon();
                        } else {
                            watch_clear_colon();
                        }
                        state->colon = !state->colon;
                    }
                    
                    // calculate the start position for the current frame
                    state->position = (state->animation / 8) % 6;
                    // calculate the current segment for the current digit
                    state->segment = state->animation % strlen(segment_map[state->time_digits[state->position]]);
                    // get the segments for the current digit
                    state->segments = segment_map[state->time_digits[state->position]];
                    
                    if (state->segments[state->segment] == 'X') {
                        // if 'X', skip this frame
                        state->illuminated_segments[state->end][0] = 99;
                        state->illuminated_segments[state->end][1] = 99;
                        state->end = (state->end + 1) % MAX_ILLUMINATED_SEGMENTS;
                        state->animation = (state->animation + 1);
                        break;
                    }

                    // calculate the animation frame
                    state->x = clock_mapping[state->position][state->segments[state->segment]-'A'][0];
                    state->y = clock_mapping[state->position][state->segments[state->segment]-'A'][1];
                    
                    // set the new pixel
                    watch_set_pixel(state->x, state->y);
                    
                    // store this pixel in the buffer
                    state->illuminated_segments[state->end][0] = state->x;
                    state->illuminated_segments[state->end][1] = state->y;
                    // increment the end index to the next position
                    state->end = (state->end + 1) % MAX_ILLUMINATED_SEGMENTS;
                } 
                else if (state->animation >= state->total_frames - MAX_ILLUMINATED_SEGMENTS && state->animation < state->total_frames) {
                    state->end = (state->end + 1) % MAX_ILLUMINATED_SEGMENTS;
                }
                else {
                    // reset the animation state
                    state->animate = false;
                }
                state->animation = (state->animation + 1);
            } 
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        case EVENT_ALARM_LONG_PRESS:
            break;
        case EVENT_BACKGROUND_TASK:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void wyoscan_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

