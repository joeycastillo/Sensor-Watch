/*
 * MIT License
 *
 * Copyright (c) 2024 James Haggerty <james@gruemail.com>
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

#ifndef NONARY_CLOCK_FACE_H_
#define NONARY_CLOCK_FACE_H_

/*
 * Balanced Nonary Clock Face
 *
 * Like simple clock face, but... confusing?
 *
 * What's the point of having a customisable wrist watch unless you have bizarre timing schemes?
 * This maintains the normal concept of hours, but divides each hour into
 * 9*9*9*9 seconds, so that we can display the time in nonary.
 *
 * But not just any nonary, this is _balanced_ nonary, such that our digit
 * values are -4, -3, -2, -1, 0, 1, 2, 3, 4
 *
 * Midday is therefore 00:00:00. An example of counting before midday
 * and after:
 *
 *  00:00:0(-4)
 *  00:00:0(-3)
 *  00:00:0(-2)
 *  00:00:0(-1)
 *  00:00:00
 *  00:00:01
 *  00:00:02
 *  00:00:03
 *  00:00:04
 *  00:00:1(-4)
 *  00:00:1(-3)
 *  00:00:1(-2)
 *  00:00:1(-1)
 *  00:00:10
 *  00:00:11
 *  etc.
 *
 *  This has the advantage that you can always see what hour/minute you're closer to.
 *
 *  But wait - how can we display the negative digits? Well, to do this
 *  we use the top 'bar' in a digit as the negative sign, and for those
 *  numbers compress them into the bottom 4 segments, and then simply use
 *  the number of other segments filled as the digit. So, counting
 *  from -4 to 4:
 *         __   __  __  __  __
 *         __   __         |  |       __   __   __|
 *        |__|, __|,__|,__,|__|,   |,   |,|  |,|  |
 *
 * Sadly, because the top and the bottom segments are tied, we can't
 * easily use the same digit for positive and negative values without
 * running into 'normal' numbers in confusing ways.
 */

#include "movement.h"

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;
} nonary_clock_state_t;

void nonary_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void nonary_clock_face_activate(movement_settings_t *settings, void *context);
bool nonary_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void nonary_clock_face_resign(movement_settings_t *settings, void *context);
bool nonary_clock_face_wants_background_task(movement_settings_t *settings, void *context);

#define nonary_clock_face ((const watch_face_t){ \
    nonary_clock_face_setup, \
    nonary_clock_face_activate, \
    nonary_clock_face_loop, \
    nonary_clock_face_resign, \
    nonary_clock_face_wants_background_task, \
})

#endif
