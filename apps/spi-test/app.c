#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"
#include "watch_utility.h"
#include "spiflash.h"
#include "lis2dw.h"

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
            uint16_t accel : 14;        // X acceleration value, raw, offset by 16384
        } x;
        struct {
            uint16_t lpmode : 2;        // low power mode (see lis2dw_low_power_mode_t)
            uint16_t accel : 14;        // Y acceleration value, raw, offset by 16384
        } y;
        struct {
            uint16_t filter : 2;        // bandwidth filtering selection (see lis2dw_bandwidth_filtering_mode_t)
            uint16_t accel : 14;        // Z acceleration value, raw, offset by 16384
        } z;
        uint32_t counter : 16;          // number of centiseconds since timestamp in header
    } data;
    uint64_t value;
} accelerometer_data_acquisition_record_t;

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

static void print_records_at_page(uint16_t page) {
    accelerometer_data_acquisition_record_t records[32];
    static uint64_t timestamp = 0;
    // static uint16_t temperature = 0;
    static lis2dw_range_t range = LIS2DW_RANGE_2_G;
    static double lsb_value = 1;
    static bool printing_header = false;

    wait_for_flash_ready();
    spi_flash_read_data(page * 256, (void *)records, 256);
    for(int i = 0; i < 32; i++) {
        switch (records[i].header.info.record_type) {
            case ACCELEROMETER_DATA_ACQUISITION_HEADER:
                printing_header = true;
                timestamp = records[i].header.timestamp;
                // temperature = records[i].header.info.temperature;
                printf("%c%c.%lld.", records[i].header.char1, records[i].header.char2, timestamp);
                range = records[i].header.info.range;
                break;
            case ACCELEROMETER_DATA_ACQUISITION_DATA:
                if (printing_header) {
                    printing_header = false;
                    uint8_t filter = 0;
                    switch (records[i].data.z.filter) {
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
                    switch (range) {
                        case LIS2DW_RANGE_16_G:
                            lsb_value = (records[i].data.y.lpmode == LIS2DW_LP_MODE_1) ? 7.808 : 1.952;
                            range = 16;
                            break;
                        case LIS2DW_RANGE_8_G:
                            lsb_value = (records[i].data.y.lpmode == LIS2DW_LP_MODE_1) ? 3.904 : 0.976;
                            range = 8;
                            break;
                        case LIS2DW_RANGE_4_G:
                            lsb_value = (records[i].data.y.lpmode == LIS2DW_LP_MODE_1) ? 1.952 : 0.488;
                            range = 4;
                            break;
                        case LIS2DW_RANGE_2_G:
                            lsb_value = (records[i].data.y.lpmode == LIS2DW_LP_MODE_1) ? 0.976 : 0.244;
                            range = 2;
                            break;
                    }
                    printf("RANGE%d_LP%d_FILT%d.CSV\n", range, records[i].data.y.lpmode + 1, filter);
                    printf("timestamp,accX,accY,accZ\n");
                }
                printf("%lld,%f,%f,%f\n",
                        (timestamp * 100 + records[i].data.counter) * 10,
                        9.80665 * ((double)(records[i].data.x.accel - 8192)) * lsb_value / 1000,
                        9.80665 * ((double)(records[i].data.y.accel - 8192)) * lsb_value / 1000,
                        9.80665 * ((double)(records[i].data.z.accel - 8192)) * lsb_value / 1000);
                break;
            case ACCELEROMETER_DATA_ACQUISITION_INVALID:
            case ACCELEROMETER_DATA_ACQUISITION_DELETED:
                // don't print anything
                break;
        }
        records[i].header.info.record_type = ACCELEROMETER_DATA_ACQUISITION_DELETED;
    }

    // uncomment this to mark all pages deleted
    // write_buffer_to_page((uint8_t *)records, page);
}

static void print_records() {
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
            for(int k = start; k < 8; k++) {
                if ((pages_written & 0x80) == 0) {
                    print_records_at_page(i * 2048 + j * 8 + k);
                }
                pages_written <<= 1;
            }
        }
    }

    printf("=== END ===\n");
}

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    spi_flash_init();
    delay_ms(5000);

    // bool erase = false;
    // if (erase) {
    //     printf("Erasing...\n");
    //     wait_for_flash_ready();
    //     watch_set_pin_level(A3, false);
    //     spi_flash_command(CMD_ENABLE_WRITE);
    //     wait_for_flash_ready();
    //     watch_set_pin_level(A3, false);
    //     spi_flash_command(CMD_CHIP_ERASE);
    //     delay_ms(10000);
    // }
 
    print_records();
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    delay_ms(5000);

    return true;
}
