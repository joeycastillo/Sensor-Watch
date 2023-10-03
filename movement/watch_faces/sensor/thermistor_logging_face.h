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

#ifndef THERMISTOR_LOGGING_FACE_H_
#define THERMISTOR_LOGGING_FACE_H_

/*
 * THERMISTOR LOGGING (aka Temperature Log)
 *
 * This watch face automatically logs the temperature once an hour, and
 * maintains a 36-hour log of readings. This watch face is admittedly rather
 * complex, and bears some explanation.
 *
 * The main display shows the letters “TL” in the top left, indicating the
 * name of the watch face. At the top right, it displays the index of the
 * reading; 0 represents the most recent reading taken, 1 represents one
 * hour earlier, etc. The bottom line in this mode displays the logged
 * temperature.
 *
 * A short press of the “Alarm” button advances to the next oldest reading;
 * you will see the number at the top right advance from 0 to 1 to 2, all
 * the way to 35, the oldest reading available.
 *
 * A short press of the “Light” button will briefly display the timestamp
 * of the reading. The letters at the top left will display the word “At”,
 * and the main line will display the timestamp of the currently displayed
 * data point. The number in the top right will display the day of the month
 * for the given data point; for example, you can read “At 22 3:00 PM” as
 * ”At 3:00 PM on the 22nd”.
 *
 * If you need to illuminate the LED to read the data point, long press the
 * Light button and release it.
 */

#include "movement.h"
#include "watch.h"

#define THERMISTOR_LOGGING_NUM_DATA_POINTS (36)

typedef struct {
    watch_date_time timestamp;
    float temperature_c;
} thermistor_logger_data_point_t;

typedef struct {
    uint8_t display_index;  // the index we are displaying on screen
    uint8_t ts_ticks;       // when the user taps the LIGHT button, we show the timestamp for a few ticks.
    int32_t data_points;    // the absolute number of data points logged
    thermistor_logger_data_point_t data[THERMISTOR_LOGGING_NUM_DATA_POINTS];
} thermistor_logger_state_t;

void thermistor_logging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void thermistor_logging_face_activate(movement_settings_t *settings, void *context);
bool thermistor_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void thermistor_logging_face_resign(movement_settings_t *settings, void *context);
bool thermistor_logging_face_wants_background_task(movement_settings_t *settings, void *context);

#define thermistor_logging_face ((const watch_face_t){ \
    thermistor_logging_face_setup, \
    thermistor_logging_face_activate, \
    thermistor_logging_face_loop, \
    thermistor_logging_face_resign, \
    thermistor_logging_face_wants_background_task, \
})

#endif // THERMISTOR_LOGGING_FACE_H_
