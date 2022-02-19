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

#ifndef ACCELEROMETER_DATA_ACQUISITION_FACE_H_
#define ACCELEROMETER_DATA_ACQUISITION_FACE_H_

#include "movement.h"

#define ACCELEROMETER_DATA_ACQUISITION_INVALID ((uint64_t)(0b11))   // all bits are 1 when the flash is erased
#define ACCELEROMETER_DATA_ACQUISITION_HEADER ((uint64_t)(0b10))
#define ACCELEROMETER_DATA_ACQUISITION_DATA ((uint64_t)(0b01))    
#define ACCELEROMETER_DATA_ACQUISITION_DELETED ((uint64_t)(0b00))   // You can always write a 0 to any 1 bit

typedef union {
    struct {
        union {
            int16_t record_type : 2;
            int16_t range : 2;
            int16_t temperature : 12;
        } info;
        int8_t char1 : 8;
        int8_t char2 : 8;
        int32_t timestamp : 32;
    } header;
    struct {
        union {
            int16_t mode : 2;
            int16_t accel : 14;
        } x;
        union {
            int16_t lpmode : 2;
            int16_t accel : 14;
        } y;
        union {
            int16_t filter : 2;
            int16_t accel : 14;
        } z;
        int32_t counter : 16;
    } data;
    uint64_t value;
} accelerometer_data_acquisition_record_t;

typedef enum {
    ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE,
    ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN,
    ACCELEROMETER_DATA_ACQUISITION_MODE_SENSING,
    ACCELEROMETER_DATA_ACQUISITION_MODE_SETTINGS,
} accelerometer_data_acquisition_mode_t;

typedef enum {
    ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_SOUND,
    ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_DELAY,
    ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_REPEAT,
    // ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_NAME,
} accelerometer_data_acquisition_settings_page_t;

typedef struct {
    // mode
    accelerometer_data_acquisition_mode_t mode;
    accelerometer_data_acquisition_settings_page_t settings_page;
    // current settings
    uint8_t activity_type_index;   // active activity type
    bool beep_with_countdown;   // should we beep at the countdown
    uint8_t countdown_length;   // how many seconds to count down
    uint16_t repeat_interval;   // how many seconds to wait for a repeat
    // info about the flash chip
    int16_t next_available_page;
    // transient properties
    uint8_t countdown_ticks;
    uint8_t repeat_ticks;
    uint8_t reading_ticks;
    accelerometer_data_acquisition_record_t records[32];
    uint16_t pos;
} accelerometer_data_acquisition_state_t;

void accelerometer_data_acquisition_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void accelerometer_data_acquisition_face_activate(movement_settings_t *settings, void *context);
bool accelerometer_data_acquisition_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void accelerometer_data_acquisition_face_resign(movement_settings_t *settings, void *context);

#define accelerometer_data_acquisition_face ((const watch_face_t){ \
    accelerometer_data_acquisition_face_setup, \
    accelerometer_data_acquisition_face_activate, \
    accelerometer_data_acquisition_face_loop, \
    accelerometer_data_acquisition_face_resign, \
    NULL, \
})

#endif // ACCELEROMETER_DATA_ACQUISITION_FACE_H_
