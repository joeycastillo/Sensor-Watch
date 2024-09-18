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
#include "thermistor_logging_face.h"
#include "thermistor_driver.h"
#include "watch.h"

static void _thermistor_logging_face_log_data(thermistor_logger_state_t *logger_state) {
    thermistor_driver_enable();
    watch_date_time date_time = watch_rtc_get_date_time();
    size_t pos = logger_state->data_points % THERMISTOR_LOGGING_NUM_DATA_POINTS;

    logger_state->data[pos].timestamp.reg = date_time.reg;
    logger_state->data[pos].temperature_c = thermistor_driver_get_temperature();
    logger_state->data_points++;

    thermistor_driver_disable();
}

static void _thermistor_logging_face_update_display(thermistor_logger_state_t *logger_state, bool in_fahrenheit, bool clock_mode_24h, bool clock_24h_leading_zero) {
    int8_t pos = (logger_state->data_points - 1 - logger_state->display_index) % THERMISTOR_LOGGING_NUM_DATA_POINTS;
    char buf[14];
    bool set_leading_zero = false;

    watch_clear_indicator(WATCH_INDICATOR_24H);
    watch_clear_indicator(WATCH_INDICATOR_PM);
    watch_clear_colon();

    if (pos < 0) {
        sprintf(buf, "TL%2dno dat", logger_state->display_index);
    } else if (logger_state->ts_ticks) {
        watch_date_time date_time = logger_state->data[pos].timestamp;
        watch_set_colon();
        if (!clock_mode_24h) {
            if (date_time.unit.hour > 11) watch_set_indicator(WATCH_INDICATOR_PM);
            date_time.unit.hour %= 12;
            if (date_time.unit.hour == 0) date_time.unit.hour = 12;
        } else if (!clock_24h_leading_zero) {
            watch_set_indicator(WATCH_INDICATOR_24H);
        } else if (date_time.unit.hour < 10) {
            set_leading_zero = true;
        }
        sprintf(buf, "AT%2d%2d%02d%02d", date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    } else {
        if (in_fahrenheit) {
            sprintf(buf, "TL%2d%4.1f#F", logger_state->display_index, logger_state->data[pos].temperature_c * 1.8 + 32.0);
        } else {
            sprintf(buf, "TL%2d%4.1f#C", logger_state->display_index, logger_state->data[pos].temperature_c);
        }
    }

    watch_display_string(buf, 0);
    if (set_leading_zero)
        watch_display_string("0", 4);
}

void thermistor_logging_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(thermistor_logger_state_t));
        memset(*context_ptr, 0, sizeof(thermistor_logger_state_t));
    }
}

void thermistor_logging_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    thermistor_logger_state_t *logger_state = (thermistor_logger_state_t *)context;
    logger_state->display_index = 0;
    logger_state->ts_ticks = 0;
}

bool thermistor_logging_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    thermistor_logger_state_t *logger_state = (thermistor_logger_state_t *)context;
    switch (event.event_type) {
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // light button shows the timestamp, but if you need the light, long press it.
            movement_illuminate_led();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            logger_state->ts_ticks = 2;
            _thermistor_logging_face_update_display(logger_state, settings->bit.use_imperial_units, settings->bit.clock_mode_24h, settings->bit.clock_24h_leading_zero);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            logger_state->display_index = (logger_state->display_index + 1) % THERMISTOR_LOGGING_NUM_DATA_POINTS;
            logger_state->ts_ticks = 0;
            // fall through
        case EVENT_ACTIVATE:
            _thermistor_logging_face_update_display(logger_state, settings->bit.use_imperial_units, settings->bit.clock_mode_24h, settings->bit.clock_24h_leading_zero);
            break;
        case EVENT_TICK:
            if (logger_state->ts_ticks && --logger_state->ts_ticks == 0) {
                _thermistor_logging_face_update_display(logger_state, settings->bit.use_imperial_units, settings->bit.clock_mode_24h, settings->bit.clock_24h_leading_zero);
            }
            break;
        case EVENT_BACKGROUND_TASK:
            _thermistor_logging_face_log_data(logger_state);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void thermistor_logging_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool thermistor_logging_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // this will get called at the top of each minute, so all we check is if we're at the top of the hour as well.
    // if we are, we ask for a background task.
    return watch_rtc_get_date_time().unit.minute == 0;
}
