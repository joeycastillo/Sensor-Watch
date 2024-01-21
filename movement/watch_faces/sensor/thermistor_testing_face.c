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
#include "thermistor_testing_face.h"
#include "thermistor_driver.h"
#include "watch.h"

static void _thermistor_testing_face_update_display(bool in_fahrenheit) {
    thermistor_driver_enable();
    float temperature_c = thermistor_driver_get_temperature();
    char buf[14];
    if (in_fahrenheit) {
        sprintf(buf, "%4.1f#F", temperature_c * 1.8 + 32.0);
    } else {
        sprintf(buf, "%4.1f#C", temperature_c);
    }
    watch_display_string(buf, 4);
    thermistor_driver_disable();
}

void thermistor_testing_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    (void) context_ptr;
    // force one setting: never enter low energy mode.
    // I'm using this watch face to test the temperature sensor boards; there's no need for it.
    settings->bit.le_interval = 0;
}

void thermistor_testing_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_display_string("TE", 0);
    movement_request_tick_frequency(8);
}

bool thermistor_testing_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) context;
    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_DOWN:
            settings->bit.use_imperial_units = !settings->bit.use_imperial_units;
            _thermistor_testing_face_update_display(settings->bit.use_imperial_units);
            break;
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            _thermistor_testing_face_update_display(settings->bit.use_imperial_units);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void thermistor_testing_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
