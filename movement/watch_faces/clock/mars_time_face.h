/*
 * MIT License
 *
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

#ifndef MARS_TIME_FACE_H_
#define MARS_TIME_FACE_H_

/*
 * MARS TIME face
 *
 * This watch face is dedicated to Martian timekeeping.
 * It has several modes, and can display either a time or a date.
 *
 * Pressing the ALARM button cycles through different time zones on Mars:
 *   MC - Mars Coordinated Time, the time at Airy-0 Crater on the Martian prime meridian
 *   ZH - Local mean solar time for the Zhurong rover
 *   PE - LMST for the Perseverance rover
 *   IN - LMST for the Insight lander
 *   CU - LMST for the Curiosity rover
 *
 * Press the LIGHT button to toggle between displaying time and date:
 *   MC S - the Mars Sol Date, Martian days since December 29, 1873
 *   ZH Sol - Mission sol for the Zhurong rover
 *   PE Sol - Mission sol for the Perseverance rover
 *   IN S - Mission sol for the InSight lander
 *   CU S - Mission sol for the Curiosity rover
 *
 * Note that where the mission sol is below 1000, this watch face displays
 * the word “Sol” on the bottom line. When the mission sol is over 1000, the
 * word “Sol” will not fit and so it displays a stylized letter S at the top
 * right.
 */

#include "movement.h"

typedef enum {
    MARS_TIME_MERIDIAN,
    MARS_TIME_ZHURONG_SITE,
    MARS_TIME_PERSEVERANCE_SITE,
    MARS_TIME_INSIGHT_SITE,
    MARS_TIME_CURIOSITY_SITE,
    MARS_TIME_NUM_SITES,
} mars_time_site_t;

typedef struct {
    mars_time_site_t current_site;
    bool displaying_sol;
} mars_time_state_t;

void mars_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void mars_time_face_activate(movement_settings_t *settings, void *context);
bool mars_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void mars_time_face_resign(movement_settings_t *settings, void *context);

#define mars_time_face ((const watch_face_t){ \
    mars_time_face_setup, \
    mars_time_face_activate, \
    mars_time_face_loop, \
    mars_time_face_resign, \
    NULL, \
})

#endif // MARS_TIME_FACE_H_

