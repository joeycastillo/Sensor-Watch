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

#ifndef PULSOMETER_FACE_H_
#define PULSOMETER_FACE_H_

/*
 * PULSOMETER face
 *
 * The Pulsometer is an implementation of a sort of a classic mechanical
 * watch complication. A classic pulsometer complication involves a
 * chronograph with a scale calibrated for counting a certain number of
 * heartbeats (often 30). You start it and begin counting heartbeats, and
 * stop it after counting the specified number of beats. Once stopped,
 * the needle will point to your heart rate.
 * 
 * The pulsometer on Sensor Watch flashes its instructions at launch:
 * “Hold Alarm + count 30 beats.” Using the hand on the side where you wear
 * your watch, touch your carotid artery (in your neck) and feel for your
 * pulse. Once you find it, use your other hand to press and hold the Alarm
 * button, and count your heartbeats. When you reach 30 beats, release the
 * Alarm button. The display will show a number such as “60 bpm”; this is
 * your heart rate in beats per minute.
 * 
 * Two notes:
 *  o For the first few seconds of a measurement, the display will read “Hi”.
 *    This indicates that it’s too early for the measured value to be a valid
 *    heart rate. Once the measurement is below 240 bpm, the display will update.
 *  o If you hold the button down for more than 45 seconds, the display will
 *    read “Lo”. If it took this long for you to count 30 heartbeats, this
 *    indicates that your heart rate is below 40 beats per minute.
 */

#include "movement.h"

typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} pulsometer_state_t;

void pulsometer_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void pulsometer_face_activate(movement_settings_t *settings, void *context);
bool pulsometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void pulsometer_face_resign(movement_settings_t *settings, void *context);

#define pulsometer_face ((const watch_face_t){ \
    pulsometer_face_setup, \
    pulsometer_face_activate, \
    pulsometer_face_loop, \
    pulsometer_face_resign, \
    NULL, \
})

#endif // PULSOMETER_FACE_H_
