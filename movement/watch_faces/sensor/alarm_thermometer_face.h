/*
 * MIT License
 *
 * Copyright (c) 2024 Christian Buschau
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

#ifndef ALARM_THERMOMETER_FACE_H_
#define ALARM_THERMOMETER_FACE_H_

#include <limits.h>
#include "movement.h"

/*
 * ALARM THERMOMETER
 *
 * This watch face shows the current temperature in degrees Celsius. Press and
 * hold the alarm button to toggle between Celsius and Fahrenheit. Press and
 * release the alarm button to start a "timer". The watch will sound an alarm
 * when the temperature remains constant for at least 30 seconds and the
 * temperature will stop updating until you press the alarm button. You can
 * cancel the alarm by pressing the button again. If the temperature doesn't
 * remain constant until the low energy timeout is reached, the alarm will stop.
 * This is useful to measure e.g. the room temperature. If you lay off your
 * watch from your wrist, it will take some time until it cools down, and will
 * notify you when the measurement is constant enough.
 * THIS WATCH FACE IS NOT INTENDED TO DIAGNOSE, TREAT, CURE OR PREVENT ANY
 * DISEASE.
 */

#define LAST_SIZE 6

typedef enum {
    MODE_NORMAL,
    MODE_ALARM,
    MODE_FREEZE
} alarm_thermometer_mode_t;

typedef struct {
    int last[LAST_SIZE];
    alarm_thermometer_mode_t mode;
} alarm_thermometer_state_t;

void alarm_thermometer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void alarm_thermometer_face_activate(movement_settings_t *settings, void *context);
bool alarm_thermometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void alarm_thermometer_face_resign(movement_settings_t *settings, void *context);

#define alarm_thermometer_face ((const watch_face_t){ \
    alarm_thermometer_face_setup, \
    alarm_thermometer_face_activate, \
    alarm_thermometer_face_loop, \
    alarm_thermometer_face_resign, \
    NULL, \
})

#endif // ALARM_THERMOMETER_FACE_H_
