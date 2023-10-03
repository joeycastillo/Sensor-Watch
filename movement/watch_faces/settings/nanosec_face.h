/*
 * MIT License
 *
 * Copyright (c) 2022 Mikhail Svarichevsky https://3.14.by/
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

#ifndef NANOSEC_FACE_H_
#define NANOSEC_FACE_H_

/*
 * NANOSEC face
 *
 * The goal of nanosec face is dramatic improvement of SensorWatch accuracy.
 * Minimum goal is <60 seconds of error per year. Full success is if we can
 * reach <15 seconds per year (<0.47ppm error).
 *
 * Best used in conjunction with the FINETUNE face.
 *
 * It implements temperature correction using tempco from datasheet (and
 * allows to adjust these) and allows to introduce offset fix. Therefore
 * requires temperature sensor board.
 *
 * Most users will need to apply profile 3 ("default") or 2 ("conservative
 * datasheet"), and tune first parameter "static offset" (as it's different
 * for every crystal sample).
 *
 * Frequency correction is dithered over 31 correction intervals (31x10
 * minutes or ~5 hours), to allow <0.1ppm correction resolution.
 *  * 1ppm is 0.0864 sec per day.
 *  * 0.1ppm is 0.00864 sec per day.
 *
 * To stay under 1ppm error you would need calibration of your specific
 * instance of quartz crystal after some "burn-in" (ideally 1 year).
 *
 * Should improve TOTP experience.
 *
 * Default funing fork tempco: -0.034 ppm/°C², centered around 25°C
 * We add optional cubic coefficient, which was measured in practice on my sample.
 *
 * Cadence (CD) - how many minutes between corrections. Default 10 minutes.
 * Every minute might be too much. Every hour - slightly less power
 * consumption but also less precision.
 *
 * Can compensate crystal aging (ppm/year) - but you really should be worrying
 * about it on second/third years of watch calibration.
 *
 * For full usage instructions, please refer to the wiki:
 *  https://www.sensorwatch.net/docs/watchfaces/nanosec/
 */

#include "movement.h"

#define nanosec_profile_count 5
typedef struct {
    // Correction profiles:
    // 0 - static hardware correction.
    // 1 - static correction with dithering.
    // 2 - datasheet quadratic correction (universal).
    // 3 - cubic correction conservative (likely universal).
    // 4 - cubic correction finetuned (sample-specific).
    int8_t correction_profile;
    int16_t freq_correction; // Static correction - multiplied by 100
    int16_t center_temperature; // Multiplied by 100, +25.0 -> +2500
    int16_t quadratic_tempco; // 0.034 -> 3400, multiplied by 100000. Stored positive, used as negative.
    int16_t cubic_tempco; // default 0, 0.000136 -> 1360, multiplied by 10000000. Stored positive, used positive.
    int8_t correction_cadence;
    uint32_t last_correction_time; // Not used at the moment - but will in the future
    int16_t aging_ppm_pa; // multiplied by 100. Aging per year. 
} nanosec_state_t;

void nanosec_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void nanosec_face_activate(movement_settings_t *settings, void *context);
bool nanosec_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void nanosec_face_resign(movement_settings_t *settings, void *context);
bool nanosec_face_wants_background_task(movement_settings_t *settings, void *context);
void nanosec_ui_save(void);
void nanosec_save(void);
float nanosec_get_aging(void);


#define nanosec_face ((const watch_face_t) { \
    nanosec_face_setup, \
    nanosec_face_activate, \
    nanosec_face_loop, \
    nanosec_face_resign, \
    nanosec_face_wants_background_task, \
})

#endif // NANOSEC_FACE_H_

