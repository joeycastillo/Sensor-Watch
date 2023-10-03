/*
 * MIT License
 *
 * Copyright (c) 2022 Raymundo Cassani
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

#ifndef TACHYMETER_FACE_H_
#define TACHYMETER_FACE_H_

/*
 * TACHYMETER face
 *
 * The Tachymeter complication emulates the tachymeter function often
 * present in watches, that computes the average speed in [units per hour]
 * for a given distance given in [units].
 *
 * Use case:
 *     User sets the distance
 *     User starts the tachymeter when the trip begins
 *     User stops the tachymeter when the trip ends
 *     The watch presents the average speed and trip duration in seconds
 * 
 * Usage:
 *     Go to tachymeter face, TC is shown in the Weekday Digits
 *     A steady d in the Day Digits indicates the distance to be used.
 *         To edit the distance:
 *         Long-press the Alarm button, the distance edition page (d will blink)
 *         Use the Light button to change the editing (blinking) digit, and press Alarm to increase its value
 *         Once done, long-press the Alarm button to exit the distance edition page
 *     Press the Alarm button to start the tachymeter.
 *         A running animation will appear in the Day Digits
 *     Press the Alarm button to stop the tachymeter
 *     The average speed and total time information will alternate.
 *         The average speed will be shown alongside /h in the Day Digits;
 *         and the total time will be shown alongside t in the Day Digits.
 *     Long press the Light button to return to the distance d page,
 *         and restart the tachymeter from there.
 *     Long-press the light button in the steady distance page to reset
 *         the distance to 1.00
 * 
 * Pending design points
 * o movement_request_tick_frequency(4) is used to obtain a 4Hz ticking, thus
 *   having a time resolution of 250 ms. Not sure if using event.subsecond`
 *   is the proper way to get the fractions of second for the start and
 *   final times.
 * o For distance and average speed, the Second Digits (position 8 and 9)
 *   can be seen as decimals, thus possible to show distances as short as
 *   0.01 km (or miles) and speeds as low as 0.01 km/h (or mph). However,
 *   if the same idea is used for the total time (showing hundredths),
 *   this limits the display to 9999.99 seconds (~2h:45m).
 */

#include "movement.h"

typedef struct {
    uint8_t thousands: 4;   // 0-9 (must wrap at 10)
    uint8_t hundreds: 4;    // 0-9 (must wrap at 10)
    uint8_t tens: 4;        // 0-9 (must wrap at 10)
    uint8_t ones: 4;        // 0-9 (must wrap at 10)
    uint8_t tenths: 4;      // 0-9 (must wrap at 10)
    uint8_t hundredths: 4;  // 0-9 (must wrap at 10)
} distance_digits_t;

typedef struct {
    bool running;                  // tachymeter status
    bool editing;                  // editing distance
    uint8_t active_digit;          // active digit at editing distance
    uint8_t animation_state;       // running animation state
    watch_date_time start_seconds; // start_seconds
    int8_t start_subsecond;        // start_subsecond count (each count = 250 ms)
    distance_digits_t dist_digits; // distance digitwise
    uint32_t distance;             // distance
    uint32_t total_time;           // total_time = now - start_time (in cs)
    uint32_t total_speed;          // 3600 * 100 * distance / total_time
} tachymeter_state_t;

void tachymeter_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void tachymeter_face_activate(movement_settings_t *settings, void *context);
bool tachymeter_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void tachymeter_face_resign(movement_settings_t *settings, void *context);

#define tachymeter_face ((const watch_face_t){ \
    tachymeter_face_setup, \
    tachymeter_face_activate, \
    tachymeter_face_loop, \
    tachymeter_face_resign, \
    NULL, \
})

#endif // TACHYMETER_FACE_H_

