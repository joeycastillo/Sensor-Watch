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
#include "thermistor_readout_face.h"
#include "thermistor_driver.h"
#include "watch.h"

static void _thermistor_readout_face_update_display(bool in_fahrenheit) {
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

void thermistor_readout_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    (void) context_ptr;
}

void thermistor_readout_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_display_string("TE", 0);
}

bool thermistor_readout_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) context;
    watch_date_time date_time = watch_rtc_get_date_time();
    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_DOWN:
            settings->bit.use_imperial_units = !settings->bit.use_imperial_units;
            _thermistor_readout_face_update_display(settings->bit.use_imperial_units);
            break;
        case EVENT_ACTIVATE:
            // force a measurement to be taken immediately.
            date_time.unit.second = 0;
            // fall through
        case EVENT_TICK:
            if (date_time.unit.second % 5 == 4) {
                // Not 100% on this, but I like the idea of using the signal indicator to indicate that we're sensing data.
                // In this case we turn the indicator on a second before the reading is taken, and clear it when we're done.
                // In reality the measurement takes a fraction of a second, but this is just to show something is happening.
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            } else if (date_time.unit.second % 5 == 0) {
                _thermistor_readout_face_update_display(settings->bit.use_imperial_units);
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // clear seconds area and start tick animation if necessary
            if (!watch_tick_animation_is_running()) {
                watch_display_string("  ", 8);
                watch_start_tick_animation(1000);
            }
            // update every 5 minutes
            if (date_time.unit.minute % 5 == 0) {
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                _thermistor_readout_face_update_display(settings->bit.use_imperial_units);
                watch_display_string("  ", 8);
            }
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void thermistor_readout_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
