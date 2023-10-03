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

#ifndef FINETUNE_FACE_H_
#define FINETUNE_FACE_H_

/*
 * FINETUNE face
 *
 * FineTune face allows to align watch with sub-second precision in 25/250ms
 * accuracy. Counts time since previous finetune, and allows to calculate &
 * apply ppm correction for nanosec.
 *
 * Best used in conjunction with the NANOSEC face.
 *
 * Main screen - adjust delay (light/alarm)
 * Long MODE press - show hours since previous finetune
 * Long MODE press - show calculated ppm correction.
 *  You can apply it with long LIGHT, or just reset finetune timer with long ALARM.
 *
 * Finetune will apply crystal aging correction on every finetune save
 * (as aging is calculated since "last finetune" timestamp); but you should
 * worry about aging only on second/third years of watch calibration (if you
 * are really looking at less than 10 seconds per year of error).
 *
 * Warning, do not use at the first second of a month, as you might stay at
 * the same month and it will surprise you. Just wait 1 second...We are not
 * fully replicating RTC timer behavior when RTC is off.
 * Simulating months and years is... too much complexity.
 *
 * For full usage instructions, please refer to the wiki:
 *  https://www.sensorwatch.net/docs/watchfaces/nanosec/
 */

#include "movement.h"

typedef struct {
    // Anything you need to keep track of, put it here!
    uint8_t unused;
} finetune_state_t;

void finetune_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void finetune_face_activate(movement_settings_t *settings, void *context);
bool finetune_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void finetune_face_resign(movement_settings_t *settings, void *context);

#define finetune_face ((const watch_face_t){ \
    finetune_face_setup, \
    finetune_face_activate, \
    finetune_face_loop, \
    finetune_face_resign, \
    NULL, \
})

#endif // FINETUNE_FACE_H_

