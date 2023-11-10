/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
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

#ifndef SAVE_LOAD_FACE_H_
#define SAVE_LOAD_FACE_H_

#include "movement.h"
#include "watch_rtc.h"

/*
 * Save/Load face
 *
 * This allows you to save your settings (including location, birthday, etc) to
 * LFS, which is not wiped when firmware is updated, and then load them again.
 * It provides multiple save slots (four by default).
 *
 * Press ALARM to cycle through save slots. Long press LIGHT to save to the
 * current slot. Long press ALARM to load from the current slot. The date that
 * a save was taken is shown in YYMMDD format , or "no dat" if the slot is
 * empty. The index of the current slot is displayed in the upper right corner.
 *
 * While the time that a save was taken is recorded, it is not currently
 * restored.
 */

typedef struct savefile {
    uint8_t version;
    uint32_t b0;
    uint32_t b1;
    uint32_t b2;
    uint32_t b3;
    uint32_t b4;
    uint32_t b5;
    uint32_t b6;
    uint32_t b7;
    watch_date_time rtc;
} savefile_t;

#define SAVE_LOAD_SLOTS 4

typedef struct {
    uint8_t index;
    uint8_t update_timeout;
    savefile_t slot[SAVE_LOAD_SLOTS];
} save_load_state_t;

void save_load_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void save_load_face_activate(movement_settings_t *settings, void *context);
bool save_load_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void save_load_face_resign(movement_settings_t *settings, void *context);

#define save_load_face ((const watch_face_t){ \
    save_load_face_setup, \
    save_load_face_activate, \
    save_load_face_loop, \
    save_load_face_resign, \
    NULL, \
})

#endif // SAVE_LOAD_FACE_H_

