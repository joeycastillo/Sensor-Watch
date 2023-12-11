/*
 * MIT License
 *
 * Copyright (c) 2023 Mark Blyth
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

#ifndef MINMAX_FACE_H_
#define MINMAX_FACE_H_

#include "movement.h"
#include "watch.h"

#define LOGGING_DATA_POINTS (24)

/*
 * Log for the min. and max. temperature over the last 24h.
 *
 * Temperature is logged once a minute, every minute. Results are
 * stored, noting the highest and lowest temperatures observed within
 * any given hour. The watch face then displays the minimum or maximum
 * temperature recorded over the last 24h.
 *
 * A long press of the light button changes units between Celsius and
 * Fahrenheit. Pressing the alarm button switches between displaying the
 * minimum and maximum observed temperatures. If no buttons are pressed,
 * the watch face will eventually time out and return home.
 */

typedef struct {
  bool show_min;
  bool have_logged;
  float hourly_mins[LOGGING_DATA_POINTS];
  float hourly_maxs[LOGGING_DATA_POINTS];
} minmax_state_t;

void minmax_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void minmax_face_activate(movement_settings_t *settings, void *context);
bool minmax_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void minmax_face_resign(movement_settings_t *settings, void *context);
bool minmax_face_wants_background_task(movement_settings_t *settings, void *context);

#define minmax_face ((const watch_face_t){ \
    minmax_face_setup, \
    minmax_face_activate, \
    minmax_face_loop, \
    minmax_face_resign, \
    minmax_face_wants_background_task, \
})

#endif // MINMAX_FACE_H_

