/*
 * MIT License
 *
 * Copyright (c) 2023 CarpeNoctem
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

#ifndef FRENCH_REVOLUTIONARY_FACE_H_
#define FRENCH_REVOLUTIONARY_FACE_H_

#include "movement.h"

/*
 * French Revolutionary Decimal Time
 *
 * Similar to the Decimal Time face, but with the day divided into ten hours instead of twenty four.
 * Each hour is divided into one hundred minutes, and those minutes are divided into 100 seconds.
 * I came across this one the Svalbard watch site here: https://svalbard.watch/pages/about_decimal_time.html
 * More info here as well: https://en.wikipedia.org/wiki/Decimal_time
 * 
 * By default, the face just displays the current decimal time. Pressing the alarm button will toggle through other display options:
 * 1) Just decimal time (with dT indicator at top)
 * 2) Decimal time, with dT indicator and date above.
 * 3) Decimal time, with 24-hr time above (where Day and Date would normally be displayed), BUT minutes first then hours.
 *    Sadly, the first character of the date area only goes up to 3 (see https://www.sensorwatch.net/docs/wig/display/#the-day-digits)
 *    I was going to begrudgindly leave this display option out when I realized that, but thought it would be better to have this backwards
 *    representation of the "normal" time than not at all.
 * 
 * A long-press of the light button will toggle the upper time between 12-hr AM/PM and 24-hr mode. I thought of reading the main setting for this,
 * but thought that a person could normally prefer 12hr time, but next to a 10hr day want to see the normal time in the 24hr format.
 * 
 * A long-press of the alarm button will toggle the seconds off and on.
 *
 */

typedef struct {
    bool use_am_pm; // Use 12-hr AM/PM for upper display instead of 24-hr? (Default is 24-hr)
    bool show_seconds;
    bool colon_set_after_splash;
    uint8_t display_type : 2;
} french_revolutionary_state_t;

typedef struct {
    uint8_t second : 8;    // 0-99
    uint8_t minute : 8;    // 0-99
    uint8_t hour : 5;      // 0-10
} fr_decimal_time;

void french_revolutionary_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void french_revolutionary_face_activate(movement_settings_t *settings, void *context);
bool french_revolutionary_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void french_revolutionary_face_resign(movement_settings_t *settings, void *context);
char fix_character_one(char digit);
fr_decimal_time get_decimal_time(watch_date_time *date_time);
void set_display_buffer(char *buf, french_revolutionary_state_t *state, fr_decimal_time *decimal_time, watch_date_time *date_time);


#define french_revolutionary_face ((const watch_face_t){ \
    french_revolutionary_face_setup, \
    french_revolutionary_face_activate, \
    french_revolutionary_face_loop, \
    french_revolutionary_face_resign, \
    NULL, \
})

#endif // FRENCH_REVOLUTIONARY_FACE_H_

