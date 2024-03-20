/* SPDX-License-Identifier: MIT */

/*
 * MIT License
 *
 * Copyright © 2021-2022 Joey Castillo <joeycastillo@utexas.edu> <jose.castillo@gmail.com>
 * Copyright © 2022 Alexsander Akers <me@a2.io>
 * Copyright © 2023 Alex Utter <ooterness@gmail.com>
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

#ifndef PULSOMETER_FACE_H_
#define PULSOMETER_FACE_H_

/*
 * PULSOMETER face
 *
 * The pulsometer implements a classic mechanical watch complication.
 * A mechanical pulsometer involves a chronograph with a scale that
 * allows the user to compute the number of heart beats per minute
 * in less time. The scale is calibrated, or graduated, for a fixed
 * number of heart beats, most often 30. The user starts the chronograph
 * and simultaneously begins counting the heart beats. The movement of
 * the chronograph's seconds hand over time automatically performs the
 * computations required. When the calibrated number of heart beats
 * is reached, the chronograph is stopped and the seconds hand shows
 * the heart rate.
 *
 * The Sensor Watch pulsometer improves this design with user calibration:
 * it can be graduated to any value between 1 and 39 pulsations per minute.
 * The default is still 30, mirroring the classic pulsometer calibration.
 * This feature allows the user to reconfigure the pulsometer to count
 * many other types of periodic minutely events, making it more versatile.
 * For example, it can be set to 5 respirations per minute to turn it into
 * an asthmometer, a nearly identical mechanical watch complication
 * that doctors might use to quickly measure respiratory rate.
 *
 * To use the pulsometer, hold the ALARM button and count the pulses.
 * When the calibrated number of pulses is reached, release the button.
 * The display will show the number of pulses per minute.
 *
 * In order to measure heart rate, feel for a pulse using the hand with
 * the watch while holding the button down with the other.
 * The pulse can be easily felt on the carotid artery of the neck.
 *
 * In order to measure breathing rate, simply hold the ALARM button
 * and count the number of breaths.
 *
 * To calibrate the pulsometer, press LIGHT
 * to cycle to the next integer calibration.
 * Long press LIGHT to cycle it by 10.
 */

#include "movement.h"

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
