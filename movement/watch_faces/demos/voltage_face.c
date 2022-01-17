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
#include "voltage_face.h"
#include "watch.h"

static void _voltage_face_update_display(void) {
    char buf[14];
    float voltage = (float)watch_get_vcc_voltage() / 1000.0;
    sprintf(buf, "BA  %4.2f V", voltage);
    // printf("%s\n", buf);
    watch_display_string(buf, 0);
}

void voltage_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    (void) context_ptr;
}

void voltage_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_enable_adc();
    // if we set the reference voltage here, watch_get_vcc_voltage won't do it over and over
    watch_set_analog_reference_voltage(ADC_REFERENCE_INTREF);
}

bool voltage_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_date_time date_time;
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_ACTIVATE:
            _voltage_face_update_display();
            break;
        case EVENT_TICK:
            date_time = watch_rtc_get_date_time();
            if (date_time.unit.second % 5 == 4) {
                watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            } else if (date_time.unit.second % 5 == 0) {
                _voltage_face_update_display();
                watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            watch_display_string("BA  SLEEP ", 0);
            break;
        default:
            break;
    }

    return true;
}

void voltage_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // make sure to restore the default in the end.
    watch_set_analog_reference_voltage(ADC_REFERENCE_VCC);
    watch_disable_adc();
}
