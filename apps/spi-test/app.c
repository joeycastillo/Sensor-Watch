#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"
#include "watch_utility.h"
#include "spiflash.h"

#define ACCELEROMETER_TRAINING_RECORD_DELETED ((uint64_t)(0b00))
#define ACCELEROMETER_TRAINING_RECORD_DATA ((uint64_t)(0b01))
#define ACCELEROMETER_TRAINING_RECORD_HEADER ((uint64_t)(0b10))
#define ACCELEROMETER_TRAINING_RECORD_INVALID ((uint64_t)(0b11))

typedef union {
    struct {
        int16_t temperature : 16;
        int8_t char1 : 8;
        int8_t char2 : 8;
        int32_t timestamp : 32;
    } header;
    struct {
        int16_t x_accel : 16;
        int16_t y_accel : 16;
        int16_t z_accel : 16;
        int32_t counter : 16;
    } data;
    uint64_t value;
} acceleromter_training_record_t;

static void cb_alarm_pressed(void) {
    printf("Alarm button was pressed!\n");
}

static bool wait_for_flash_ready(void) {
    watch_set_pin_level(A3, false);
    bool ok = true;
    uint8_t read_status_response[1] = {0x00};
    do {
        ok = spi_flash_read_command(CMD_READ_STATUS, read_status_response, 1);
    } while ((read_status_response[0] & 0x3) != 0);
    delay_ms(10);
    watch_set_pin_level(A3, true);
    return ok;
}

static void print_records_at_page(uint16_t page) {
    if (page < 477) return;
    acceleromter_training_record_t records[32];
    static uint32_t timestamp;
    static uint16_t temperature;
    wait_for_flash_ready();
    spi_flash_read_data(page * 256, (void *)records, 256);
    for(int i = 0; i < 32; i++) {
        switch (records[i].header.temperature >> 14) {
            case ACCELEROMETER_TRAINING_RECORD_DELETED:
                break;
            case ACCELEROMETER_TRAINING_RECORD_DATA:
                printf("%ld,%d,%d,%d,%d\n", timestamp + records[i].data.counter, records[i].data.x_accel, records[i].data.y_accel, records[i].data.z_accel, temperature);
                break;
            case ACCELEROMETER_TRAINING_RECORD_HEADER:
                printf("=== BEGIN %c%c EVENT AT %d ===\n", records[i].header.char1, records[i].header.char2, records[i].header.timestamp);
                printf("timestamp,x_raw,y_raw,z_raw,temperature\n");
                timestamp = records[i].header.timestamp;
                temperature = records[i].header.temperature & 0x3FFF;
                break;
            case ACCELEROMETER_TRAINING_RECORD_INVALID:
                printf(",,,,\n");
                break;
        }
    }
}

static void print_records() {
    printf("printing records\n");
    uint8_t buf[256];
    for(int16_t i = 0; i < 4; i++) {
        wait_for_flash_ready();
        spi_flash_read_data(i * 256, buf, 256);
        for(int16_t j = 0; j < 256; j++) {
            uint8_t pages_written = buf[j];
            uint8_t start = 0;
            if (i == 0 && j == 0) {
                pages_written <<= 4;
                start = 4;
            }
            for(int k = start; k < 7; k++) {
                if ((pages_written & 0x80) == 0) {
                    print_records_at_page(i * 2048 + j * 8 + k);
                }
                pages_written <<= 1;
            }
        }
    }

}

void app_init(void) {
    delay_ms(5000);
    spi_flash_init();
    watch_register_extwake_callback(BTN_ALARM, cb_alarm_pressed, true);

    bool erase = false;
    if (erase) {
        printf("Erasing...\n");
        wait_for_flash_ready();
        watch_set_pin_level(A3, false);
        spi_flash_command(CMD_ENABLE_WRITE);
        wait_for_flash_ready();
        watch_set_pin_level(A3, false);
        spi_flash_command(CMD_CHIP_ERASE);
        delay_ms(10000);
    }

    uint8_t buf[256] = {0xFF};

    wait_for_flash_ready();
    spi_flash_read_data(0, buf, 256);
    printf("byte 0 was %02x\n", buf[0]);
    if (buf[0] & 0xF0) {
        buf[0] = 0x0F;
        printf("setting it to 0x0F\n");
        wait_for_flash_ready();
        watch_set_pin_level(A3, false);
        spi_flash_command(CMD_ENABLE_WRITE);
        wait_for_flash_ready();
        spi_flash_write_data(0, buf, 256);
    }

    print_records();
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
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

    printf("\tWe wrote 256 bytes to address %ld, which was page %d.\n", address, page);

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

bool app_loop(void) {
    // delay_ms(5000);

    return;
        
    // simulate logging 15 seconds of data
    watch_date_time date_time = watch_rtc_get_date_time();
    acceleromter_training_record_t record;

    record.header.temperature = 0xC30;
    record.header.temperature |= (ACCELEROMETER_TRAINING_RECORD_HEADER << 14);
    record.header.char1 = 'W';
    record.header.char2 = 'A';
    record.header.timestamp = watch_utility_date_time_to_unix_time(date_time, 0);;

    acceleromter_training_record_t records[32];
    memset(records, 0xFF, sizeof(records));
    records[0] = record;
    uint16_t pos = 1;
    uint32_t counter = 0;

    printf("logging 15*25 data points for timestamp %ld\n", record.header.timestamp);
    for(uint8_t i = 0; i < 15; i++) {
        for(uint8_t j = 0; j < 25; j++) {
            record.data.x_accel = arc4random() & 0x3FFF;
            record.data.x_accel |= ACCELEROMETER_TRAINING_RECORD_DATA << 14;
            record.data.y_accel = arc4random() & 0x3FFF;
            record.data.z_accel = arc4random() & 0x3FFF;
            record.data.counter = i;
            records[pos++] = record;
            if (pos >= 32) {
                printf("pos overflowed at counter %ld\n", counter);
                int16_t next_available_page = get_next_available_page();
                if (next_available_page > 0) {
                    write_buffer_to_page((uint8_t *)records, next_available_page);
                    wait_for_flash_ready();
                }
                pos = 0;
                memset(records, 0xFF, sizeof(records));
            }
        }
    }
    if (records[0].header.temperature >> 14 != ACCELEROMETER_TRAINING_RECORD_INVALID) {
        int16_t next_available_page = get_next_available_page();
        if (next_available_page > 0) {
            printf("Partial write\n");
            write_buffer_to_page((uint8_t *)records, next_available_page);
            wait_for_flash_ready();
            delay_ms(10);
        }
    }

    delay_ms(60000);

    return false;
}
