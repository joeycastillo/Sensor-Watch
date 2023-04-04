/*
 * MIT License
 *
 * Copyright (c) 2022 <#author_name#>
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
#include "frequency_correction_face.h"

// NOTE: since this face deals directly with the SAM L22's SUPC and RTC registers,
// it won't build for the simulator or really do anything. so let's not.
#ifndef __EMSCRIPTEN__

// Waveform output. Comes out on pin A1 of the 9-pin connector. Output is enabled
// when the watch face is activated and disabled when deactivated.
// * The RTC's PEREOn enables an event at a frequency of 1024/(2^(n+3)), allowing
//   event generation from 128 Hz to 1 Hz.
// * The SUPC's RTCTGL causes the selected output to toggle on an RTC event.
// Putting it together, PEREO0 generates a 64 Hz square wave on A1, PEREO1 a 32 Hz
// wave, on and on to an 0.5 Hz square wave for PEREO7.
static void _enable_output(uint8_t period_event_output) {
    SUPC->BKOUT.bit.EN = 1;
    SUPC->BKOUT.bit.RTCTGL = 1;
    RTC->MODE2.CTRLA.bit.ENABLE = 0;
    while (RTC->MODE2.SYNCBUSY.bit.ENABLE);
    RTC->MODE2.EVCTRL.reg = RTC_MODE2_EVCTRL_PEREO(1 << period_event_output);
    RTC->MODE2.CTRLA.bit.ENABLE = 1;
    while (RTC->MODE2.SYNCBUSY.bit.ENABLE);
}

// The display: "FC" for "Frequency Correction" in the title slot; at the top right,
// the periodic event output that's enabled:: 0 for PEREO0, 1 for PEREO1, etc.
// The main line displays the frequency correction value from -127 to 127.
// Controls: A short press on the Light button increases FREQCORR by 1 and a short
// press on the Alarm button decreases FREQCORR by 1. A long press on ALARM cycles
// through the available output frequencies.
static void _update_display(uint8_t period_event_output) {
    char buf[14];
    sprintf(buf, "FC%2d%6d", period_event_output, (int8_t)RTC->MODE2.FREQCORR.reg);
    watch_display_string(buf, 0);
}

static void _disable_output() {
    SUPC->BKOUT.bit.EN = 0;
    SUPC->BKOUT.bit.RTCTGL = 0;
    RTC->MODE2.CTRLA.bit.ENABLE = 0;
    while (RTC->MODE2.SYNCBUSY.bit.ENABLE);
    RTC->MODE2.EVCTRL.reg = RTC_MODE2_EVCTRL_PEREO(0);
    RTC->MODE2.CTRLA.bit.ENABLE = 1;
    while (RTC->MODE2.SYNCBUSY.bit.ENABLE);
}

void frequency_correction_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(frequency_correction_state_t));
        frequency_correction_state_t *state = (frequency_correction_state_t *)*context_ptr;
        state->period_event_output = 0;
    }
}

void frequency_correction_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    frequency_correction_state_t *state = (frequency_correction_state_t *)context;
    _enable_output(state->period_event_output);
}

bool frequency_correction_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    frequency_correction_state_t *state = (frequency_correction_state_t *)context;
    int8_t freqcorr;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _update_display(state->period_event_output);
            break;
        case EVENT_TICK:
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            freqcorr = RTC->MODE2.FREQCORR.reg;
            if (freqcorr < 127) {
                RTC->MODE2.FREQCORR.reg++;
                while(RTC->MODE2.SYNCBUSY.reg);
            }
            _update_display(state->period_event_output);
            break;
        case EVENT_ALARM_BUTTON_UP:
            freqcorr = RTC->MODE2.FREQCORR.reg;
            if (freqcorr > -127) {
                RTC->MODE2.FREQCORR.reg--;
                while(RTC->MODE2.SYNCBUSY.reg);
            }
            _update_display(state->period_event_output);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->period_event_output = (state->period_event_output + 1) % 8;
            _update_display(state->period_event_output);
            _enable_output(state->period_event_output);
            break;
        case EVENT_TIMEOUT:
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            watch_start_tick_animation(500);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void frequency_correction_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    _disable_output();
}

#else

void frequency_correction_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    (void) context_ptr;
}

void frequency_correction_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool frequency_correction_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    (void) event;

    return true;
}

void frequency_correction_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

#endif
