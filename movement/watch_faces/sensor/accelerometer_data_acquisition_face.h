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

/*
 * ACCELEROMETER DATA ACQUISITION
 *
 * TODO: Add description here, including controls.
 */

#include "movement.h"

#define ACCELEROMETER_DATA_ACQUISITION_INVALID ((uint64_t)(0b11))   // all bits are 1 when the flash is erased
#define ACCELEROMETER_DATA_ACQUISITION_HEADER ((uint64_t)(0b10))
#define ACCELEROMETER_DATA_ACQUISITION_DATA ((uint64_t)(0b01))    
#define ACCELEROMETER_DATA_ACQUISITION_DELETED ((uint64_t)(0b00))   // You can always write a 0 to any 1 bit

typedef union {
    struct {
        struct {
            uint16_t record_type : 2;   // see above, helps us identify record types when reading back
            uint16_t range : 2;         // accelerometer range (see lis2dw_range_t)
            uint16_t temperature : 12;  // raw value from the temperature sensor
        } info;
        uint8_t char1 : 8;              // First character of the activity type
        uint8_t char2 : 8;              // Second character of the activity type
        uint32_t timestamp : 32;        // UNIX timestamp for the measurement
    } header;
    struct {
        struct {
            uint16_t record_type : 2;   // duplicate; this is the same field as info above
            uint16_t accel : 14;        // X acceleration value, raw, offset by 8192
        } x;
        struct {
            uint16_t lpmode : 2;        // low power mode (see lis2dw_low_power_mode_t)
            uint16_t accel : 14;        // Y acceleration value, raw, offset by 8192
        } y;
        struct {
            uint16_t filter : 2;        // bandwidth filtering selection (see lis2dw_bandwidth_filtering_mode_t)
            uint16_t accel : 14;        // Z acceleration value, raw, offset by 8192
        } z;
        uint32_t counter : 16;          // number of centiseconds since timestamp in header
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
    uint32_t starting_timestamp;
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
