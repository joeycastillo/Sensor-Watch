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

#ifndef planetary_time_face_H_
#define planetary_time_face_H_

/*
 * PLANETARY TIME face
 *
 * BACKGROUND
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
 * PLANETARY TIME COMPLICATION
 * 
 * The hour digits of this complication watch-face display the current planetary hour 
 * according to the given location and day of the year (First hour from 12am to 1am,
 * the second hour from 1am to 2am, and so forth).
 * 
 * Like with normal clocks the minutes and seconds help dividing the hour into smaller
 * units. On this watch-face, all units naturally vary in length because the planetary
 * hours are not fixed by duration but by the moments of sunrise and sunset which 
 * obviously vary throughout the year, especially in higher latitudes.
 * 
 * On this watch-face the hours indicated as 12am to 12pm (00:00 - 12:00) are used for
 * the planetary daytime hours between sunrise and sunset and hours indicated as 12pm 
 * to 12am (12:00 - 00:00) are used for the planetary night hours after sunset and before 
 * sunrise.
 * 
 * The planetary ruler of the current hour and day is displayed at the top in Latin or 
 * Greek shorthand notation:
 * 
 * Saturn (SA) / Chronos (CH) / ♄
 * Jupiter (JU) / Zeus (ZE) / ♃
 * Mars (MA) / Ares (AR) / ♂
 * Sol (SO) / Helios (HE) / ☉
 * Venus (VE) / Aphrodite (AF) / ♀
 * Mercury (ME) / Hermes (HR) / ☿
 * Luna (LU) / Selene (SE) / ☾
 * 
 * The ALARM button toggles between displaying the ruler of the hour and the ruler of the day
 * 
 * The LIGHT button toggles between Latin and Greek ruler shorthand notation
 * 
 * (IMPORTANT: Make sure the watch's time, timezone and location are set correctly for this
 * watch face to work properly!)
 */

#include "movement.h"
#include "sunrise_sunset_face.h"

typedef struct {
    // Anything you need to keep track of, put it here!
    uint32_t phase_start;
    uint32_t phase_end;
    bool night;
    double utc_offset;
    double freq;
    uint8_t ruler;
    bool day_ruler;
    bool no_location;
    sunrise_sunset_state_t sunstate;
    watch_date_time scratch;
} planetary_time_state_t;

void planetary_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void planetary_time_face_activate(movement_settings_t *settings, void *context);
bool planetary_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void planetary_time_face_resign(movement_settings_t *settings, void *context);

#define planetary_time_face ((const watch_face_t){ \
    planetary_time_face_setup, \
    planetary_time_face_activate, \
    planetary_time_face_loop, \
    planetary_time_face_resign, \
    NULL, \
})

#endif // planetary_time_face_H_

