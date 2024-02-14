/*
 * MIT License
 *
 * Copyright (c) 2023 Tobias Raayoni Last / @randogoth
 * Copyright (c) 2022 Joey Castillo (sunrise_sunset_face)
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

#ifndef planetary_hours_face_H_
#define planetary_hours_face_H_

/*
 * PLANETARY HOURS face
 * 
 * Background
 *
 * Both the 24 hour day and the order of our weekdays have quite esoteric roots.
 * The ancient Egyptians divided the day up into 12 hours of sunlight and 12 hours
 * of night time. Obviously the length of these hours varied throughout the year.
 * 
 * The Greeks assigned each hour a ruler of the planetary gods in the ancient
 * "Chaldean" order from slowest (Chronos for Saturn) to fastest (Selene for Moon).
 * Because 24 hours cannot be equally divided by seven, the planetary rulers carried
 * over to the first hour of the next day, effectively ruling over the entire day 
 * and lending the whole day their name. The seven day week was born.
 * 
 * PLANETARY HOUR CHART COMPLICATION
 * 
 * This complication watch face displays the start time of the current planetary hour 
 * according to the given location and day of the year. The number of the current
 * planetary hour (1 - 24) is indicated at the top right.
 * 
 * Short pressing the ALARM button flips through the start times of the following 
 * planetary hours, long pressing it flips backwards in time. A long press of the 
 * LIGHT button immediately switches back to the start time of the current hour.
 * The Bell indicator always marks the current planetary hour in the list.
 * The LAP indicator shows up when the hours of the next phase are part of the 
 * upcoming day instead of the current one. This happens when the watch face is 
 * launched after sunset.
 * 
 * The planetary ruler of the current hour and day is displayed at the top in 
 * Latin or Greek shorthand notation:
 * 
 * Saturn (SA) / Chronos (CH) / ♄
 * Jupiter (JU) / Zeus (ZE) / ♃
 * Mars (MA) / Ares (AR) / ♂
 * Sol (SO) / Helios (HE) / ☉
 * Venus (VE) / Aphrodite (AF) / ♀
 * Mercury (ME) / Hermes (HR) / ☿
 * Luna (LU) / Selene (SE) / ☾
 * 
 * A short press of the LIGHT button toggles between Latin and Greek ruler shorthand
 * notation.
 * 
 * (IMPORTANT: Make sure the watch's time, timezone and location are set correctly for this
 * watch face to work properly!)
 */

#include "movement.h"
#include "sunrise_sunset_face.h"

typedef struct {
    // Anything you need to keep track of, put it here!
    uint32_t planetary_hours[24];
    uint32_t phase_start;
    uint32_t phase_end;
    uint32_t phase_next;
    bool next;
    double utc_offset;
    bool no_location;
    int8_t hour;
    int8_t ruler;
    bool start_at_night;
    bool skip_to_current;
    sunrise_sunset_state_t sunstate;
} planetary_hours_state_t;

void planetary_hours_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void planetary_hours_face_activate(movement_settings_t *settings, void *context);
bool planetary_hours_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void planetary_hours_face_resign(movement_settings_t *settings, void *context);

#define planetary_hours_face ((const watch_face_t){ \
    planetary_hours_face_setup, \
    planetary_hours_face_activate, \
    planetary_hours_face_loop, \
    planetary_hours_face_resign, \
    NULL, \
})

#endif // planetary_hours_face_H_

