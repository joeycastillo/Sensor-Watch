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

#include <stdlib.h>
#include <string.h>
#include "accelerometer_data_acquisition_face.h"
#include "watch_utility.h"
#include "lis2dw.h"

#define ACCELEROMETER_RANGE LIS2DW_RANGE_4_G
#define ACCELEROMETER_LPMODE LIS2DW_LP_MODE_1
#define ACCELEROMETER_FILTER LIS2DW_BANDWIDTH_FILTER_DIV2
#define ACCELEROMETER_LOW_NOISE true
#define SECONDS_TO_RECORD 15

static const char activity_types[][3] = {
    "ID",   // Idle
    "OF",   // Off-wrist
    "SL",   // Sleeping
    "WH",   // Washing Hands
    "WA",   // Walking
    "WB",   // Walking with Beverage
    "JO",   // Jogging
    "RU",   // Running
    "BI",   // Biking
    "HI",   // Hiking
    "EL",   // Elliptical
    "SU",   // Stairs Up
    "SD",   // Stairs Down
    "WL",   // Weight Lifting
    "TE",   // Testing
};

static void update(accelerometer_data_acquisition_state_t *state);
static void update_settings(accelerometer_data_acquisition_state_t *state);
static void advance_current_setting(accelerometer_data_acquisition_state_t *state);
static void start_reading(accelerometer_data_acquisition_state_t *state, movement_settings_t *settings);
static void continue_reading(accelerometer_data_acquisition_state_t *state);
static void finish_reading(accelerometer_data_acquisition_state_t *state);

void accelerometer_data_acquisition_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(accelerometer_data_acquisition_state_t));
        memset(*context_ptr, 0, sizeof(accelerometer_data_acquisition_state_t));
        accelerometer_data_acquisition_state_t *state = (accelerometer_data_acquisition_state_t *)*context_ptr;
        state->beep_with_countdown = true;
        state->countdown_length = 3;
    }
}

void accelerometer_data_acquisition_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    accelerometer_data_acquisition_state_t *state = (accelerometer_data_acquisition_state_t *)context;
    state->next_available_page = 123;
}

bool accelerometer_data_acquisition_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    accelerometer_data_acquisition_state_t *state = (accelerometer_data_acquisition_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            switch (state->mode) {
                case ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE:
                    update(state);
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN:
                    if (state->countdown_ticks > 0) {
                        state->countdown_ticks--;
                        if (state->countdown_ticks == 0) {
                            // at zero, begin reading
                            state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_SENSING;
                            state->reading_ticks = SECONDS_TO_RECORD + 1;
                            // also beep if the user asked for it
                            if (state->beep_with_countdown) watch_buzzer_play_note(BUZZER_NOTE_C6, 75);
                            start_reading(state, settings);
                        } else if (state->countdown_ticks < 3) {
                            // beep for last two ticks before reading
                            if (state->beep_with_countdown) watch_buzzer_play_note(BUZZER_NOTE_C5, 75);
                        }
                    }
                    update(state);
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_SENSING:
                    if (state->reading_ticks > 0) {
                        state->reading_ticks--;
                        if (state->reading_ticks > 0) {
                            continue_reading(state);
                        } else {
                            finish_reading(state);
                            state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE;
                            watch_buzzer_play_note(BUZZER_NOTE_C4, 125);
                            watch_buzzer_play_note(BUZZER_NOTE_REST, 50);
                            watch_buzzer_play_note(BUZZER_NOTE_C4, 125);
                        }
                    }
                    update(state);
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_SETTINGS:
                    update_settings(state);
                    break;
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch (state->mode) {
                case ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE:
                    state->activity_type_index = (state->activity_type_index + 1) % (sizeof(activity_types) / sizeof(activity_types[0]));
                    update(state);
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_SETTINGS:
                    state->settings_page++;
                    if (state->settings_page > ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_REPEAT) {
                        state->settings_page = 0;
                        state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE;
                        update(state);
                    } else {
                        update_settings(state);
                    }
                    break;
                default:
                    break;
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            printf("Alarm up! Mode is %d\n", state->mode);
            switch (state->mode) {
                case ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE:
                    state->countdown_ticks = state->countdown_length;
                    printf("Setting countdown ticks to %d\n", state->countdown_ticks);
                    state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN;
                    printf("and mode to %d\n", state->mode);
                    update(state);
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN:
                    // cancel countdown
                    state->countdown_ticks = 0;
                    state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE;
                    update(state);
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_SETTINGS:
                    advance_current_setting(state);
                    update_settings(state);
                    break;
                default:
                    break;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            printf("Alarm long\n");
            if (state->mode == ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE) {
                state->repeat_ticks = 0;
                state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_SETTINGS;
                update_settings(state);
            }
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void accelerometer_data_acquisition_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    accelerometer_data_acquisition_state_t *state = (accelerometer_data_acquisition_state_t *)context;
    if (state->reading_ticks) {
        state->reading_ticks = 0;
        finish_reading(state);
    }
    state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE;
    state->settings_page = 0;
    state->countdown_ticks = 0;
    state->repeat_ticks = 0;
    state->reading_ticks = 0;
}

static void update(accelerometer_data_acquisition_state_t *state) {
    char buf[14];
    uint8_t ticks = 0;
    switch (state->mode) {
        case ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE:
            ticks = state->countdown_length;
            break;
        case ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN:
            ticks = state->countdown_ticks;
            break;
        case ACCELEROMETER_DATA_ACQUISITION_MODE_SENSING:
            ticks = state->reading_ticks;
            break;
        default:
            ticks = 0;
            break;
    }
    sprintf(buf, "%s%2dre%2d#o",
            activity_types[state->activity_type_index],
            ticks,
            (8192 - state->next_available_page) / 82);
    watch_display_string(buf, 0);

    watch_set_colon();

    // special case: display full if full
    if (state->next_available_page < 0) watch_display_string(" FUL", 6);

    // Bell if beep enabled
    if (state->beep_with_countdown) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);

    // Signal if sensing
    if (state->reading_ticks) watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else watch_clear_indicator(WATCH_INDICATOR_SIGNAL);

    // LAP if repeating
    if (state->repeat_ticks) watch_set_indicator(WATCH_INDICATOR_LAP);
    else watch_clear_indicator(WATCH_INDICATOR_LAP);

}

static void update_settings(accelerometer_data_acquisition_state_t *state) {
    printf("TODO: Settings screen\n");
    char buf[12];
    watch_clear_colon();
    if (state->beep_with_countdown) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);
    switch (state->settings_page) {
        case ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_SOUND:
            sprintf(buf, "SO  Beep %c", state->beep_with_countdown ? 'Y' : 'N');
            watch_display_string(buf, 0);
            break;
        case ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_DELAY:
            sprintf(buf, "DL  %2d SeC", state->countdown_length);
            watch_display_string(buf, 0);
            break;
        case ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_REPEAT:
            watch_display_string("rE  no1n&p", 0);
            break;
    }
}

static void advance_current_setting(accelerometer_data_acquisition_state_t *state) {
    switch (state->settings_page) {
        case ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_SOUND:
            state->beep_with_countdown = !state->beep_with_countdown;
            break;
        case ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_DELAY:
            // this is so lazy, i'm sorry
            if (state->countdown_length == 1) state->countdown_length = 3;
            else if (state->countdown_length == 3) state->countdown_length = 10;
            else if (state->countdown_length == 10) state->countdown_length = 30;
            else state->countdown_length = 1;
            break;
        case ACCELEROMETER_DATA_ACQUISITION_SETTINGS_PAGE_REPEAT:
            // TODO: repeat setting
            break;
    }
}

bool deleteme = false;

static void start_reading(accelerometer_data_acquisition_state_t *state, movement_settings_t *settings) {
    (void) state;
    watch_enable_i2c();
    lis2dw_begin();
    lis2dw_set_data_rate(LIS2DW_DATA_RATE_25_HZ);
    lis2dw_set_range(ACCELEROMETER_RANGE);
    lis2dw_set_low_power_mode(ACCELEROMETER_LPMODE);
    lis2dw_set_bandwidth_filtering(ACCELEROMETER_FILTER);
    if (ACCELEROMETER_LOW_NOISE) lis2dw_set_low_noise_mode(true);
    lis2dw_enable_fifo();

    accelerometer_data_acquisition_record_t record;
    watch_date_time date_time = watch_rtc_get_date_time();
    state->starting_timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
    record.header.info.record_type = ACCELEROMETER_DATA_ACQUISITION_HEADER;
    record.header.info.range = ACCELEROMETER_RANGE;
    record.header.info.temperature = lis2dw_get_temperature();
    record.header.char1 = activity_types[state->activity_type_index][0];
    record.header.char2 = activity_types[state->activity_type_index][1];
    record.header.timestamp = state->starting_timestamp;

    uint8_t range = 0;

    switch (record.header.info.range) {
        case LIS2DW_RANGE_16_G:
            range = 16;
            break;
        case LIS2DW_RANGE_8_G:
            range = 8;
            break;
        case LIS2DW_RANGE_4_G:
            range = 4;
            break;
        case LIS2DW_RANGE_2_G:
            range = 2;
            break;
    }

    state->records[state->pos++] = record;

    printf("TRAINING_%c%c_%d_RANGE%d_", record.header.char1, record.header.char2, record.header.timestamp, range);

    deleteme = true;
}

static void _write_page(accelerometer_data_acquisition_state_t *state) {
    if (state->next_available_page > 0) {
        // write_buffer_to_page((uint8_t *)records, next_available_page);
        // wait_for_flash_ready();
    }
    // state->next_available_page = get_next_available_page();
    state->next_available_page++;
    state->pos = 0;
    memset(state->records, 0xFF, sizeof(state->records));
}

static void _log_data_point(accelerometer_data_acquisition_state_t *state, lis2dw_reading_t reading) {
    accelerometer_data_acquisition_record_t record;
    record.data.x.record_type = ACCELEROMETER_DATA_ACQUISITION_DATA;
    record.data.y.lpmode = ACCELEROMETER_LPMODE;
    record.data.z.filter = ACCELEROMETER_FILTER;
    record.data.x.accel = reading.x;
    record.data.y.accel = reading.y;
    record.data.z.accel = reading.z;
    record.data.counter = SECONDS_TO_RECORD - state->reading_ticks + 1;
    state->records[state->pos++] = record;
    if (deleteme) {
        deleteme = false;
        uint8_t filter = 0;
        switch (record.data.z.filter) {
            case LIS2DW_BANDWIDTH_FILTER_DIV2:
                filter = 2;
                break;
            case LIS2DW_BANDWIDTH_FILTER_DIV4:
                filter = 4;
                break;
            case LIS2DW_BANDWIDTH_FILTER_DIV10:
                filter = 10;
                break;
            case LIS2DW_BANDWIDTH_FILTER_DIV20:
                filter = 20;
                break;
        }
        printf("LP%d_FILT%d.CSV\n", record.data.y.lpmode + 1, filter);
    }
    printf("%d, %d, %d, %d\n", record.data.counter, record.data.x.accel, record.data.y.accel, record.data.z.accel);
    if (state->pos >= 32) {
        _write_page(state);
    }
}

static void continue_reading(accelerometer_data_acquisition_state_t *state) {
    lis2dw_fifo_t fifo;

    lis2dw_read_fifo(&fifo);
    for(int i = 0; i < fifo.count; i++) {
        _log_data_point(state, fifo.readings[i]);
    }
}

static void finish_reading(accelerometer_data_acquisition_state_t *state) {
    printf("finishing\n");
    if (state->pos != 0) {
        _write_page(state);
    }
    lis2dw_set_data_rate(LIS2DW_DATA_RATE_POWERDOWN);
    watch_disable_i2c();
}
