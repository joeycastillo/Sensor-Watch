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
#include "spiflash.h"

#define ACCELEROMETER_RANGE LIS2DW_RANGE_4_G
#define ACCELEROMETER_LPMODE LIS2DW_LP_MODE_2
#define ACCELEROMETER_FILTER LIS2DW_BANDWIDTH_FILTER_DIV2
#define ACCELEROMETER_LOW_NOISE true
#define SECONDS_TO_RECORD 15

static const char activity_types[][3] = {
    "TE",   // Testing
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
};

static void update(accelerometer_data_acquisition_state_t *state);
static void update_settings(accelerometer_data_acquisition_state_t *state);
static void advance_current_setting(accelerometer_data_acquisition_state_t *state);
static void start_reading(accelerometer_data_acquisition_state_t *state, movement_settings_t *settings);
static void continue_reading(accelerometer_data_acquisition_state_t *state);
static void finish_reading(accelerometer_data_acquisition_state_t *state);
static bool wait_for_flash_ready(void);
static int16_t get_next_available_page(void);
static void write_buffer_to_page(uint8_t *buf, uint16_t page);
static void write_page(accelerometer_data_acquisition_state_t *state);
static void log_data_point(accelerometer_data_acquisition_state_t *state, lis2dw_reading_t reading, uint8_t centiseconds);

void accelerometer_data_acquisition_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    accelerometer_data_acquisition_state_t *state = (accelerometer_data_acquisition_state_t *)*context_ptr;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(accelerometer_data_acquisition_state_t));
        memset(*context_ptr, 0, sizeof(accelerometer_data_acquisition_state_t));
        state = (accelerometer_data_acquisition_state_t *)*context_ptr;
        state->beep_with_countdown = true;
        state->countdown_length = 3;
    }
    spi_flash_init();
    wait_for_flash_ready();
    uint8_t buf[256] = {0xFF};
    spi_flash_read_data(0, buf, 256);
    if (buf[0] & 0xF0) {
        // mark first four pages as used
        buf[0] = 0x0F;
        wait_for_flash_ready();
        watch_set_pin_level(A3, false);
        spi_flash_command(CMD_ENABLE_WRITE);
        wait_for_flash_ready();
        spi_flash_write_data(0, buf, 256);
    }

}

void accelerometer_data_acquisition_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    accelerometer_data_acquisition_state_t *state = (accelerometer_data_acquisition_state_t *)context;
    state->next_available_page = get_next_available_page();
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
                    if (state->repeat_ticks > 0) {
                        state->repeat_ticks--;
                        if (state->repeat_ticks == 0) {
                            state->countdown_ticks = state->countdown_length;
                            state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN;
                        }
                    }
                    break;
                case ACCELEROMETER_DATA_ACQUISITION_MODE_COUNTDOWN:
                    if (state->next_available_page < 0) {
                        state->countdown_ticks = 0;
                        state->repeat_ticks = 0;
                        state->mode = ACCELEROMETER_DATA_ACQUISITION_MODE_IDLE;
                    }
                    if (state->countdown_ticks > 0) {
                        state->countdown_ticks--;
                        printf("countdown: %d\n", state->countdown_ticks);
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
        case EVENT_LIGHT_BUTTON_DOWN:
            // don't light up every time light is hit
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

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

    // special case: display full if full, <1% if nearly full
    if (state->next_available_page < 0) watch_display_string(" FUL", 6);
    else if (state->next_available_page > 8110) watch_display_string("<1", 6);

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
    char buf[13];
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
            if (state->repeat_interval == 0) {
                watch_display_string("rE  none  ", 0);
            } else {
                sprintf(buf, "rE  %2dn&in", state->repeat_interval / 60);
                watch_display_string(buf, 0);
            }
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
            if (state->repeat_interval == 0) state->repeat_interval = 60;
            else if (state->repeat_interval == 60) state->repeat_interval = 600;
            else if (state->repeat_interval == 600) state->repeat_interval = 1800;
            else if (state->repeat_interval == 1800) state->repeat_interval = 3600;
            else state->repeat_interval = 0;
            break;
    }
}

static int16_t get_next_available_page(void) {
    uint8_t buf[256] = {0};

    uint16_t page = 0;
    for(int16_t i = 0; i < 4; i++) {
        wait_for_flash_ready();
        spi_flash_read_data(i * 256, buf, 256);
        for(int16_t j = 0; j < 256; j++) {
            if(buf[j] == 0) {
                page += 8;
            } else {
                page += __builtin_clz(((uint32_t)buf[j]) << 24);
                break;
            }
        }
    }

    if (page >= 8192) return -1;

    return page;
}

static void write_buffer_to_page(uint8_t *buf, uint16_t page) {
    uint32_t address = 256 * page;

    wait_for_flash_ready();
    watch_set_pin_level(A3, false);
    spi_flash_command(CMD_ENABLE_WRITE);
    wait_for_flash_ready();
    watch_set_pin_level(A3, false);
    spi_flash_write_data(address, buf, 256);
    wait_for_flash_ready();

    uint8_t buf2[256];
    watch_set_pin_level(A3, false);
    spi_flash_read_data(address, buf2, 256);
    wait_for_flash_ready();

    uint8_t used_pages[256] = {0xFF};
    uint16_t address_to_mark_used = page / 8;
    uint8_t header_page = address_to_mark_used / 256;
    uint8_t used_byte = 0x7F >> (page % 8);
    uint8_t offset_in_buf = address_to_mark_used % 256;

    printf("\twrite 256 bytes to address %ld, page %d.\n", address, page);
    for(int i = 0; i < 256; i++) {
        if (buf[i] != buf2[i]) {
            printf("\tData mismatch detected at offset  %d: %d != %d.\n", i, buf[i], buf2[i]);
        }
    }

    watch_set_pin_level(A3, false);
    spi_flash_read_data(header_page * 256, used_pages, 256);
    used_pages[offset_in_buf] = used_byte;
    watch_set_pin_level(A3, false);
    spi_flash_command(CMD_ENABLE_WRITE);
    wait_for_flash_ready();
    watch_set_pin_level(A3, false);
    spi_flash_write_data(header_page * 256, used_pages, 256);
    wait_for_flash_ready();
}

static bool wait_for_flash_ready(void) {
    watch_set_pin_level(A3, false);
    bool ok = true;
    uint8_t read_status_response[1] = {0x00};
    do {
        ok = spi_flash_read_command(CMD_READ_STATUS, read_status_response, 1);
    } while ((read_status_response[0] & 0x3) != 0);
    delay_ms(1); // why do i need this?
    watch_set_pin_level(A3, true);
    return ok;
}

static void write_page(accelerometer_data_acquisition_state_t *state) {
    if (state->next_available_page > 0) {
        write_buffer_to_page((uint8_t *)(state->records), state->next_available_page);
        wait_for_flash_ready();
        state->next_available_page++;
    }
    state->pos = 0;
    memset(state->records, 0xFF, sizeof(state->records));
}

static void log_data_point(accelerometer_data_acquisition_state_t *state, lis2dw_reading_t reading, uint8_t centiseconds) {
    accelerometer_data_acquisition_record_t record;
    record.data.x.record_type = ACCELEROMETER_DATA_ACQUISITION_DATA;
    record.data.y.lpmode = ACCELEROMETER_LPMODE;
    record.data.z.filter = ACCELEROMETER_FILTER;
    record.data.x.accel = (reading.x >> 2) + 8192;
    record.data.y.accel = (reading.y >> 2) + 8192;
    record.data.z.accel = (reading.z >> 2) + 8192;
    record.data.counter = 100 * (SECONDS_TO_RECORD - state->reading_ticks + 1) + centiseconds;
    printf("logged data point for %d\n", record.data.counter);
    state->records[state->pos++] = record;
    if (state->pos >= 32) {
        write_page(state);
    }
}

static void start_reading(accelerometer_data_acquisition_state_t *state, movement_settings_t *settings) {
    printf("Start reading\n");
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

    state->records[state->pos++] = record;
    lis2dw_fifo_t fifo;
    lis2dw_read_fifo(&fifo); // dump the fifo, this starts a fresh round of data in continue_reading
}

static void continue_reading(accelerometer_data_acquisition_state_t *state) {
    printf("Continue reading\n");
    lis2dw_fifo_t fifo;
    lis2dw_read_fifo(&fifo);

    fifo.count = min(fifo.count, 25); // hacky, but we need a consistent data rate; if we got a 26th data point, chuck it.
    uint8_t offset = 4 * (25 - fifo.count); // also hacky: we're sometimes short at the start. align to beginning of next second.
    // TODO: use the threshold interrupt for this, will mean we get consistent 25 Hz data as the accelerometer sees it.

    for(int i = 0; i < fifo.count; i++) {
        log_data_point(state, fifo.readings[i], i * 4 + offset);
    }
}

static void finish_reading(accelerometer_data_acquisition_state_t *state) {
    printf("Finish reading\n");
    if (state->pos != 0) {
        write_page(state);
    }
    lis2dw_set_data_rate(LIS2DW_DATA_RATE_POWERDOWN);
    watch_disable_i2c();

    state->repeat_ticks = state->repeat_interval;
}
