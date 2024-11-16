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

#include <stdlib.h>
#include <string.h>
#include "lis2dw_logging_face.h"
#include "lis2dw.h"
#include "watch.h"

// This watch face is just for testing; if we want to build accelerometer support, it will likely have to be part of Movement itself.
// The watch face only logs events when it is on screen and not in low energy mode, so you should set LE mode to Never when using it
// and make it the first watch face in the list (so we come back to it from other modes).
// On an interrupt, it flashes the Signal icon, and displays the axis or axes that were over the threshold.
// The main display contains, from left to right, the number of interrupt events that were detected in each of the last three minutes.
// Pressing the alarm button enters the log mode, where the main display shows the number of interrupts detected in each of the last
// 24 hours (the hour is shown in the top right digit and AM/PM indicator, if the clock is set to 12 hour mode)

static void _lis2dw_logging_face_update_display(movement_settings_t *settings, lis2dw_logger_state_t *logger_state, lis2dw_wakeup_source wakeup_source) {
    char buf[14];
    char time_indication_character;
    int8_t pos;
    watch_date_time date_time;
    bool set_leading_zero = false;

    if (logger_state->log_ticks) {
        pos = (logger_state->data_points - 1 - logger_state->display_index) % LIS2DW_LOGGING_NUM_DATA_POINTS;
        if (pos < 0) {
            watch_clear_colon();
            sprintf(buf, "NO   data ");
        } else {
            date_time = logger_state->data[pos].timestamp;
            watch_set_colon();
            if (!settings->bit.clock_mode_24h) {
                if (date_time.unit.hour > 11) watch_set_indicator(WATCH_INDICATOR_PM);
                date_time.unit.hour %= 12;
                if (date_time.unit.hour == 0) date_time.unit.hour = 12;
            } else if (!settings->bit.clock_24h_leading_zero) {
                watch_set_indicator(WATCH_INDICATOR_24H);
            } else if (date_time.unit.hour < 10) {
                set_leading_zero = true;
            }
            switch (logger_state->axis_index) {
                case 0:
                    sprintf(buf, "3A%2d%02d%4lu", date_time.unit.hour, date_time.unit.minute, logger_state->data[pos].x_interrupts + logger_state->data[pos].y_interrupts + logger_state->data[pos].z_interrupts);
                    break;
                case 1:
                    sprintf(buf, "XA%2d%02d%4lu", date_time.unit.hour, date_time.unit.minute, logger_state->data[pos].x_interrupts);
                    break;
                case 2:
                    sprintf(buf, "YA%2d%02d%4lu", date_time.unit.hour, date_time.unit.minute, logger_state->data[pos].y_interrupts);
                    break;
                case 3:
                    sprintf(buf, "ZA%2d%02d%4lu", date_time.unit.hour, date_time.unit.minute, logger_state->data[pos].z_interrupts);
                    break;
            }
        }
    } else {
        date_time = watch_rtc_get_date_time();
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_PM);
        watch_clear_indicator(WATCH_INDICATOR_24H);
        if ((59 - date_time.unit.second) < 10) time_indication_character = '0' + (59 - date_time.unit.second);
        else time_indication_character = (date_time.unit.second % 2) ? 'i' : '_';
        sprintf(buf, "%c%c%c%c%2d%2d%2d",
            (wakeup_source & LIS2DW_WAKEUP_SRC_WAKEUP_Y) ? 'Y' : ' ',
            (wakeup_source & LIS2DW_WAKEUP_SRC_WAKEUP_X) ? 'X' : ' ',
            (wakeup_source & LIS2DW_WAKEUP_SRC_WAKEUP_Z) ? 'Z' : ' ',
            time_indication_character,
            logger_state->interrupts[0],
            logger_state->interrupts[1],
            logger_state->interrupts[2]);
    }
    watch_display_string(buf, 0);
    if (set_leading_zero)
        watch_display_string("0", 4);
    printf("%s\n", buf);
}

static void _lis2dw_logging_face_log_data(lis2dw_logger_state_t *logger_state) {
    watch_date_time date_time = watch_rtc_get_date_time();
    // we get this call 15 minutes late; i.e. at 6:15 we're logging events for 6:00.
    // so: if we're at the top of the hour, roll the hour back too (7:00 task logs data for 6:45)
    if (date_time.unit.minute == 0) date_time.unit.hour = (date_time.unit.hour + 23) % 24;

    // // then roll the minute back.
    date_time.unit.minute = (date_time.unit.minute + 45) % 60;

    size_t pos = logger_state->data_points % LIS2DW_LOGGING_NUM_DATA_POINTS;
    logger_state->data[pos].timestamp.reg = date_time.reg;
    logger_state->data[pos].x_interrupts = logger_state->x_interrupts_this_hour;
    logger_state->data[pos].y_interrupts = logger_state->y_interrupts_this_hour;
    logger_state->data[pos].z_interrupts = logger_state->z_interrupts_this_hour;
    logger_state->data_points++;
    logger_state->x_interrupts_this_hour = 0;
    logger_state->y_interrupts_this_hour = 0;
    logger_state->z_interrupts_this_hour = 0;
}

void lis2dw_logging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(lis2dw_logger_state_t));
        memset(*context_ptr, 0, sizeof(lis2dw_logger_state_t));
        watch_enable_i2c();
        lis2dw_begin();
        lis2dw_set_low_power_mode(LIS2DW_LP_MODE_2); // lowest power 14-bit mode, 25 Hz is 3.5 µA @ 1.8V w/ low noise, 3µA without
        lis2dw_set_low_noise_mode(true); // consumes a little more power
        lis2dw_set_range(LIS2DW_CTRL6_VAL_RANGE_4G);
        lis2dw_set_data_rate(LIS2DW_DATA_RATE_25_HZ); // is this enough for training?
        // threshold is 1/64th of full scale, so for a FS of ±4G this is 1.25G
        lis2dw_configure_wakeup_int1(10, true, false);
    }
}

void lis2dw_logging_face_activate(movement_settings_t *settings, void *context) {
    lis2dw_logger_state_t *logger_state = (lis2dw_logger_state_t *)context;
    // force two settings: never enter low energy mode, and always snap back to screen 0.
    // this assumes the accelerometer face is first in the watch_faces list.
    settings->bit.le_interval = 0;
    settings->bit.to_always = true;

    logger_state->display_index = 0;
    logger_state->log_ticks = 0;
    watch_enable_digital_input(A4);
}

bool lis2dw_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    lis2dw_logger_state_t *logger_state = (lis2dw_logger_state_t *)context;
    lis2dw_wakeup_source wakeup_source = 0;
    lis2dw_interrupt_source interrupt_source = 0;

    switch (event.event_type) {
        case EVENT_LIGHT_BUTTON_DOWN:
            logger_state->axis_index = (logger_state->axis_index + 1) % 4;
            logger_state->log_ticks = 255;
            _lis2dw_logging_face_update_display(settings, logger_state, wakeup_source);
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (logger_state->log_ticks) logger_state->display_index = (logger_state->display_index + 1) % LIS2DW_LOGGING_NUM_DATA_POINTS;
            logger_state->log_ticks = 255;
            logger_state->axis_index = 0;
            _lis2dw_logging_face_update_display(settings, logger_state, wakeup_source);
            break;
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            if (logger_state->log_ticks > 0) {
                logger_state->log_ticks--;
            } else {
                logger_state->display_index = 0;
            }
            interrupt_source = lis2dw_get_interrupt_source();
            if (interrupt_source) {
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                wakeup_source = lis2dw_get_wakeup_source();
                logger_state->interrupts[0]++;
                if (wakeup_source & LIS2DW_WAKEUP_SRC_WAKEUP_X) logger_state->x_interrupts_this_hour++;
                if (wakeup_source & LIS2DW_WAKEUP_SRC_WAKEUP_Y) logger_state->y_interrupts_this_hour++;
                if (wakeup_source & LIS2DW_WAKEUP_SRC_WAKEUP_Z) logger_state->z_interrupts_this_hour++;
            } else {
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            }
            _lis2dw_logging_face_update_display(settings, logger_state, wakeup_source);
            break;
        case EVENT_BACKGROUND_TASK:
            _lis2dw_logging_face_log_data(logger_state);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void lis2dw_logging_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_disable_digital_input(A4);
}

bool lis2dw_logging_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    lis2dw_logger_state_t *logger_state = (lis2dw_logger_state_t *)context;
    watch_date_time date_time = watch_rtc_get_date_time();

    // this is kind of an abuse of the API, but, let's use the 1 minute tick to shift all our data over.
    logger_state->interrupts[2] = logger_state->interrupts[1];
    logger_state->interrupts[1] = logger_state->interrupts[0];
    logger_state->interrupts[0] = 0;

    // and do our logging task every 15 minutes
    return (date_time.unit.minute % 15) == 0;
}
