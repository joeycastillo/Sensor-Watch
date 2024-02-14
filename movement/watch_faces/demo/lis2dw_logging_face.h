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

#ifndef LIS2DW_LOGGING_FACE_H_
#define LIS2DW_LOGGING_FACE_H_

/*
 * LIS2DW Accelerometer Data Logger
 *
 * This is an experimental watch face for logging data on the “Sensor Watch
 * Motion Express” board. I will add more documentation for this watch face
 * once this sensor board is more widely available.
 */

#include "movement.h"
#include "watch.h"

#define LIS2DW_LOGGING_NUM_DATA_POINTS (96)

typedef struct {
    watch_date_time timestamp;
    uint32_t x_interrupts;
    uint32_t y_interrupts;
    uint32_t z_interrupts;
} lis2dw_logger_data_point_t;

typedef struct {
    uint8_t display_index;  // the index we are displaying on screen
    uint8_t axis_index;     // the index we are displaying on screen
    uint8_t log_ticks;      // when the user taps the ALARM button, we enter log mode
    int32_t data_points;    // the absolute number of data points logged
    uint8_t interrupts[3];  // the number of interrupts we have logged in each of the last 3 minutes
    uint32_t x_interrupts_this_hour;  // the number of interrupts we have logged in the last hour
    uint32_t y_interrupts_this_hour;  // the number of interrupts we have logged in the last hour
    uint32_t z_interrupts_this_hour;  // the number of interrupts we have logged in the last hour
    lis2dw_logger_data_point_t data[LIS2DW_LOGGING_NUM_DATA_POINTS];
} lis2dw_logger_state_t;

void lis2dw_logging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void lis2dw_logging_face_activate(movement_settings_t *settings, void *context);
bool lis2dw_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void lis2dw_logging_face_resign(movement_settings_t *settings, void *context);
bool lis2dw_logging_face_wants_background_task(movement_settings_t *settings, void *context);

#define lis2dw_logging_face ((const watch_face_t){ \
    lis2dw_logging_face_setup, \
    lis2dw_logging_face_activate, \
    lis2dw_logging_face_loop, \
    lis2dw_logging_face_resign, \
    lis2dw_logging_face_wants_background_task, \
})

#endif // LIS2DW_LOGGING_FACE_H_
