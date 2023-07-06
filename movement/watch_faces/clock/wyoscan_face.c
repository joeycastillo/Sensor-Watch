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
#if __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

/*
Slowly render the current time from left to right, 
scanning across its liquid crystal face, completing 1 cycle every 2 seconds.

Created to mimic the wyoscan watch that was produced by Halmos and designed by Dexter Sinister
It looks like this https://www.o-r-g.com/apps/wyoscan

You’ll notice that reading this watch requires more attention than usual, 
as the seven segments of each digit are lit one by one across its display. 
This speed may be adjusted until it reaches the limits of your perception. 
You and your watch are now in tune.
*/


static char *segment_map[] = {
    "AFBGECD",  // 0
    "BC",       // 1
    "ABGED",    // 2
    "ABGCD",    // 3
    "FGBC",     // 4
    "AFGCD",    // 5
    "AFGEDC",   // 6
    "ABC",      // 7
    "AFBGECD",  // 8
    "AFBGCD"    // 9
};
static int32_t clock_mapping[6][7][2] = {
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
    {{2,2}, {2,3}, {0,4}, {0,6}, {0,5}, {1,4}, {1,5}},
};

static bool colon_state;
static long colon_interval_id = -1;

static void _wyoscan_animation(wyoscan_state_t *state) {
    uint32_t position, segment;
    char *segments;     
    
    // Calculate total_frames
    state->total_frames += MAX_ILLUMINATED_SEGMENTS; // for clearing
    
    movement_request_tick_frequency(32);
    
    if (state->animation < state->total_frames - MAX_ILLUMINATED_SEGMENTS) {
        // calculate the start position for the current frame
        position = (state->animation / 7) % 6;
        // calculate the current segment for the current digit
        segment = state->animation % strlen(segment_map[state->time_digits[position]]);
        // get the segments for the current digit
        segments = segment_map[state->time_digits[position]];
        // calculate the animation frame
        uint32_t x = clock_mapping[position][segments[segment]-'A'][0];
        uint32_t y = clock_mapping[position][segments[segment]-'A'][1];
        
        // if we have reached the max number of illuminated segments, we clear the oldest one
        if ((state->end + 1) % MAX_ILLUMINATED_SEGMENTS == state->start) {
            // clear the oldest pixel
            watch_clear_pixel(state->illuminated_segments[state->start][0], state->illuminated_segments[state->start][1]);
            // increment the start index to point to the next oldest pixel
            state->start = (state->start + 1) % MAX_ILLUMINATED_SEGMENTS;
        }
        
        // set the new pixel
        watch_set_pixel(x, y);
        // store this pixel in the buffer
        state->illuminated_segments[state->end][0] = x;
        state->illuminated_segments[state->end][1] = y;
        // increment the end index to the next position
        state->end = (state->end + 1) % MAX_ILLUMINATED_SEGMENTS;
    } else if (state->animation < state->total_frames) {
        // clear the oldest pixel
        watch_clear_pixel(state->illuminated_segments[state->start][0], state->illuminated_segments[state->start][1]);
        // increment the start index to point to the next oldest pixel
        state->start = (state->start + 1) % MAX_ILLUMINATED_SEGMENTS;
    } else {
        // reset the animation state and request for tick frequency 1
        state->animation = 0;
        state->animate = false;
    }
}

static void watch_invoke_colon_callback(void *userData) {
    colon_state = !colon_state;
    if (colon_state) {
        watch_set_colon();
    } else {
        watch_clear_colon();
    }
}

static bool watch_colon_animation_is_running(void) {
    return colon_interval_id != -1;
}

static void watch_start_colon_animation(uint32_t duration) {
    if (colon_interval_id != -1) return;

    colon_state = true;
    colon_interval_id = emscripten_set_interval(watch_invoke_colon_callback, (double)duration, NULL);
}

void wyoscan_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(wyoscan_state_t));
        memset(*context_ptr, 0, sizeof(wyoscan_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void wyoscan_face_activate(movement_settings_t *settings, void *context) {
    // wyoscan_state_t *state = (wyoscan_state_t *)context;

}

bool wyoscan_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    wyoscan_state_t *state = (wyoscan_state_t *)context;

    watch_date_time date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            break;
        case EVENT_TICK:
            printf("Loop: Received EVENT_TICK\n");            date_time = watch_rtc_get_date_time();
            if (date_time.unit.second % 2 && !state->animate) {
                int i=0;
                state->start = 0; 
                state->end = 0;
                printf("Loop: Preparing to start animation\n");
                state->total_frames = 0;
                for(i = 0; i < 6; i++) {
                    state->total_frames += strlen(segment_map[state->time_digits[i]]);
                }
                state->animate = true;
                state->time_digits[0] = date_time.unit.hour / 10;
                state->time_digits[1] = date_time.unit.hour % 10;
                state->time_digits[2] = date_time.unit.minute / 10;
                state->time_digits[3] = date_time.unit.minute % 10;
                state->time_digits[4] = date_time.unit.second / 10;
                state->time_digits[5] = date_time.unit.second % 10;
            }
            if (!watch_colon_animation_is_running()) {
                printf("Loop: Starting colon animation\n");
                watch_start_colon_animation(1000);
            }
            if ( state->animate ) {
                printf("Loop: Starting animation\n");
                _wyoscan_animation(state);
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

bool wyoscan_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    wyoscan_state_t *state = (wyoscan_state_t *)context;
    if (!state->signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute == 0;
}

