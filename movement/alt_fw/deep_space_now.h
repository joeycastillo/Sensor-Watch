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

#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "movement_faces.h"

// Preset Goldstone (GO), Madrid (MA), and Canberra (CA) time zones.
// Also prepopulate the Day One register with Voyager 1's launch (September 5, 1977)

#define MOVEMENT_CUSTOM_BOOT_COMMANDS() { \
    /* Standard Time */\
    watch_store_backup_data(0x1e0c0c, 4);\
    watch_store_backup_data(0x010115, 5);\
    watch_store_backup_data(0x130105, 6);\
    /* Daylight Saving Time */\
    /*\
    watch_store_backup_data(0x1f0c0c, 4);\
    watch_store_backup_data(0x020115, 5);\
    watch_store_backup_data(0x110105, 6);\
    */\
    watch_store_backup_data(0x0597b9, 2);\
}

const watch_face_t watch_faces[] = {
    simple_clock_face,
    mars_time_face,
    world_clock_face,
    world_clock_face,
    world_clock_face,
    day_one_face,

    preferences_face,
    set_time_face,
};

#define MOVEMENT_NUM_FACES (sizeof(watch_faces) / sizeof(watch_face_t))

#define SIGNAL_TUNE_DEFAULT

#endif // MOVEMENT_CONFIG_H_
