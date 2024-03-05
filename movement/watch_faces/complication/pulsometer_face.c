/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021-2022 Joey Castillo <joeycastillo@utexas.edu> <jose.castillo@gmail.com>
 * Copyright © 2023 Jeremy O'Brien <neutral@fastmail.com>
 * Copyright © 2024 Matheus Afonso Martins Moreira <matheus.a.m.moreira@gmail.com> (https://www.matheusmoreira.com/)
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

#include "pulsometer_face.h"
#include "watch.h"

#ifndef PULSOMETER_FACE_TITLE
#define PULSOMETER_FACE_TITLE "PL"
#endif

#ifndef PULSOMETER_FACE_CALIBRATION_DEFAULT
#define PULSOMETER_FACE_CALIBRATION_DEFAULT (30)
#endif

#ifndef PULSOMETER_FACE_CALIBRATION_INCREMENT
#define PULSOMETER_FACE_CALIBRATION_INCREMENT (10)
#endif

// tick frequency will be 2 to this power Hz (0 for 1 Hz, 2 for 4 Hz, etc.)
#ifndef PULSOMETER_FACE_FREQUENCY_FACTOR
#define PULSOMETER_FACE_FREQUENCY_FACTOR (4ul)
#endif

#define PULSOMETER_FACE_FREQUENCY (1 << PULSOMETER_FACE_FREQUENCY_FACTOR)

typedef struct {
    bool measuring;
    int16_t pulses;
    int16_t ticks;
    int8_t calibration;
} pulsometer_state_t;

static void pulsometer_display_title(pulsometer_state_t *pulsometer) {
    watch_display_string(PULSOMETER_FACE_TITLE, 0);
}

static void pulsometer_display_calibration(pulsometer_state_t *pulsometer) {
    char buf[3];
    snprintf(buf, sizeof(buf), "%2hhd", pulsometer->calibration);
    watch_display_string(buf, 2);
}

static void pulsometer_display_measurement(pulsometer_state_t *pulsometer) {
    char buf[7];
    snprintf(buf, sizeof(buf), "%-6hd", pulsometer->pulses);
    watch_display_string(buf, 4);
}

static void pulsometer_indicate(pulsometer_state_t *pulsometer) {
    if (pulsometer->measuring) {
        watch_set_indicator(WATCH_INDICATOR_LAP);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_LAP);
    }
}

static void pulsometer_start_measurement(pulsometer_state_t *pulsometer) {
    pulsometer->measuring = true;
    pulsometer->pulses = INT16_MAX;
    pulsometer->ticks = 0;

    pulsometer_indicate(pulsometer);

    movement_request_tick_frequency(PULSOMETER_FACE_FREQUENCY);
}

static void pulsometer_measure(pulsometer_state_t *pulsometer) {
    if (!pulsometer->measuring) { return; }

    pulsometer->ticks++;

    float ticks_per_minute = 60 << PULSOMETER_FACE_FREQUENCY_FACTOR;
    float pulses_while_button_held = ticks_per_minute / pulsometer->ticks;
    float calibrated_pulses = pulses_while_button_held * pulsometer->calibration;
    calibrated_pulses += 0.5f;

    pulsometer->pulses = (int16_t) calibrated_pulses;

    pulsometer_display_measurement(pulsometer);
}

static void pulsometer_stop_measurement(pulsometer_state_t *pulsometer) {
    movement_request_tick_frequency(1);

    pulsometer->measuring = false;

    pulsometer_display_measurement(pulsometer);
    pulsometer_indicate(pulsometer);
}

static void pulsometer_cycle_calibration(pulsometer_state_t *pulsometer, int8_t increment) {
    if (pulsometer->measuring) { return; }

    if (pulsometer->calibration <= 0) {
        pulsometer->calibration = 1;
    }

    int8_t last = pulsometer->calibration;
    pulsometer->calibration += increment;

    if (pulsometer->calibration > 39) {
        pulsometer->calibration = last == 39? 1 : 39;
    }

    pulsometer_display_calibration(pulsometer);
}

void pulsometer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        pulsometer_state_t *pulsometer = malloc(sizeof(pulsometer_state_t));

        pulsometer->calibration = PULSOMETER_FACE_CALIBRATION_DEFAULT;
        pulsometer->pulses = 0;
        pulsometer->ticks = 0;

        *context_ptr = pulsometer;
    }
}

void pulsometer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    pulsometer_state_t *pulsometer = context;

    pulsometer->measuring = false;

    pulsometer_display_title(pulsometer);
    pulsometer_display_calibration(pulsometer);
    pulsometer_display_measurement(pulsometer);
}

bool pulsometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    pulsometer_state_t *pulsometer = (pulsometer_state_t *) context;

    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_DOWN:
            pulsometer_start_measurement(pulsometer);
            break;
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_ALARM_LONG_UP:
            pulsometer_stop_measurement(pulsometer);
            break;
        case EVENT_TICK:
            pulsometer_measure(pulsometer);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            pulsometer_cycle_calibration(pulsometer, 1);
            break;
        case EVENT_LIGHT_LONG_UP:
            pulsometer_cycle_calibration(pulsometer, PULSOMETER_FACE_CALIBRATION_INCREMENT);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // Inhibit the LED
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void pulsometer_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
