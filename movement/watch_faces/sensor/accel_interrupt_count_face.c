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
#include "accel_interrupt_count_face.h"
#include "lis2dw.h"
#include "watch.h"

// hacky hacky!
uint32_t *ptr_to_count = 0;

void accel_interrupt_handler(void);
void accel_interrupt_handler(void) {
    (*ptr_to_count)++;
}

static void _accel_interrupt_count_face_update_display(accel_interrupt_count_state_t *state) {
    char buf[11];

    if (state->running) {
        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
    }

    // "AC"celerometer "IN"terrupts
    snprintf(buf, 11, "AC1N%6ld", state->count);
    watch_display_string(buf, 0);
    printf("%s\n", buf);
}

static void _accel_interrupt_count_face_configure_threshold(uint8_t threshold) {
    lis2dw_configure_wakeup_int1(threshold, false, true);
}

void accel_interrupt_count_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(accel_interrupt_count_state_t));
        memset(*context_ptr, 0, sizeof(accel_interrupt_count_state_t));
        ptr_to_count = &((accel_interrupt_count_state_t *)*context_ptr)->count;
        watch_enable_i2c();
        lis2dw_begin();
        lis2dw_set_low_power_mode(LIS2DW_LP_MODE_2); // lowest power 14-bit mode, 25 Hz is 3.5 µA @ 1.8V w/ low noise, 3µA without
        lis2dw_set_low_noise_mode(true); // consumes a little more power
        lis2dw_set_range(LIS2DW_CTRL6_VAL_RANGE_4G);
        lis2dw_set_data_rate(LIS2DW_DATA_RATE_25_HZ); // is this enough?

        // threshold is 1/64th of full scale, so for a FS of ±4G this is 1.25G
        ((accel_interrupt_count_state_t *)*context_ptr)->threshold = 10;
        _accel_interrupt_count_face_configure_threshold(((accel_interrupt_count_state_t *)*context_ptr)->threshold);
    }
}

void accel_interrupt_count_face_activate(movement_settings_t *settings, void *context) {
    accel_interrupt_count_state_t *state = (accel_interrupt_count_state_t *)context;

    // never in settings mode at the start
    state->is_setting = false;

    // force LE interval to never sleep
    settings->bit.le_interval = 0;
}

bool accel_interrupt_count_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    accel_interrupt_count_state_t *state = (accel_interrupt_count_state_t *)context;

    if (state->is_setting) {
        switch (event.event_type) {
            case EVENT_LIGHT_BUTTON_DOWN:
                state->new_threshold = (state->new_threshold + 1) % 64;
                // fall through
            case EVENT_TICK:
                {
                    char buf[11];
                    snprintf(buf, 11, "TH  %4d  ", state->new_threshold);
                    watch_display_string(buf, 0);
                    printf("%s\n", buf);
                }
                break;
            case EVENT_ALARM_BUTTON_UP:
                lis2dw_configure_wakeup_int1(state->threshold, false, true);
                state->threshold = state->new_threshold;
                state->is_setting = false;
                break;
            default:
                movement_default_loop_handler(event, settings);
                break;
        }
    } else {
        switch (event.event_type) {
            case EVENT_LIGHT_BUTTON_DOWN:
                movement_illuminate_led();

                // if stopped, reset the count
                if (!state->running) {
                    state->count = 0;
                }
                _accel_interrupt_count_face_update_display(state);
                break;
            case EVENT_ALARM_BUTTON_UP:
                if (state->running) {
                    state->running = false;
                    watch_register_interrupt_callback(A4, NULL, INTERRUPT_TRIGGER_RISING);
                } else {
                    state->running = true;
                    watch_register_interrupt_callback(A4, accel_interrupt_handler, INTERRUPT_TRIGGER_RISING);
                }
                _accel_interrupt_count_face_update_display(state);
                break;
            case EVENT_ACTIVATE:
            case EVENT_TICK:
                _accel_interrupt_count_face_update_display(state);
                break;
            case EVENT_ALARM_LONG_PRESS:
                if (!state->running) {
                    state->new_threshold = state->threshold;
                    state->is_setting = true;
                }
                return false;
            default:
                movement_default_loop_handler(event, settings);
                break;
        }
    }

    return true;
}

void accel_interrupt_count_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool accel_interrupt_count_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    return false;
}
