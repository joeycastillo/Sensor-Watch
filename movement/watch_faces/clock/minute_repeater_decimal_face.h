/*
 * MIT License
 *
 * Copyright (c) 2023 Jonas Termeau - original repetition_minute_face
 * Copyright (c) 2023 Brian Blakley - modified minute_repeater_decimal_face
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

#ifndef MINUTE_REPEATER_DECIMAL_FACE_H_
#define MINUTE_REPEATER_DECIMAL_FACE_H_

#include "movement.h"

/*
 * A hopefully useful complication for friendly neighbors in the dark
 *
 * Originating from 1676 from reverend and mechanician Edward Barlow, and
 * perfected in 1820 by neighbor Abraham Breguet, a minute repeater or 
 * "repetition minute" is a complication in a mechanical watch or clock that
 * chimes the hours and often minutes at the press of a button. There are many
 * types of repeater, from the simple repeater which merely strikes the number
 * of hours, to the minute repeater which chimes the time down to the minute,
 * using separate tones for hours, decimal hours, and minutes. They originated
 * before widespread artificial illumination, to allow the time to be determined
 * in the dark, and were also used by the visually impaired. 
 *
 *
 * How to use it :
 * 
 * Long press the light button to get an auditive reading of the time like so :
 * 0..23 (1..12 if 24-hours format isn't enabled) low beep(s) for the hours
 * 0..9 low-high couple pitched beeps for the tens of minutes
 * 0..9 high pitched beep(s) for the remaining minutes (ones of minutes)
 *
 * Prerequisite : a watch with a working buzzer
 * 
 * ~ Only in the darkness can you see the stars. - Martin Luther King ~
 *
 */

typedef struct {
    uint32_t previous_date_time;
    uint8_t last_battery_check;
    uint8_t watch_face_index;
    bool signal_enabled;
    bool battery_low;
    bool alarm_enabled;
} minute_repeater_decimal_state_t;

void mrd_play_hour_chime(void);
void mrd_play_tens_chime(void);
void mrd_play_minute_chime(void);
void minute_repeater_decimal_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void minute_repeater_decimal_face_activate(movement_settings_t *settings, void *context);
bool minute_repeater_decimal_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void minute_repeater_decimal_face_resign(movement_settings_t *settings, void *context);
bool minute_repeater_decimal_face_wants_background_task(movement_settings_t *settings, void *context);

#define minute_repeater_decimal_face ((const watch_face_t){ \
    minute_repeater_decimal_face_setup, \
    minute_repeater_decimal_face_activate, \
    minute_repeater_decimal_face_loop, \
    minute_repeater_decimal_face_resign, \
    minute_repeater_decimal_face_wants_background_task, \
})

#endif // MINUTE_REPEATER_DECIMAL_FACE_H_
