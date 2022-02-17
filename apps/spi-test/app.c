#include <stdio.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"
#include "spiflash.h"

// this is a very basic app to confirm that SPI is working, tested with board OSO-MISC-21-017 and a GD25Q16C Flash chip.

static bool wait_for_flash_ready(void) {
    watch_set_pin_level(A3, false);
    bool ok = true;
    uint8_t read_status_response[1] = {0x00};
    do {
        ok = spi_flash_read_command(CMD_READ_STATUS, read_status_response, 1);
    } while (ok && (read_status_response[0] & 0x3) != 0);
    watch_set_pin_level(A3, true);
    return ok;
}

void app_init(void) {
    spi_flash_init();
    delay_ms(5000);
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}


bool app_loop(void) {
    uint8_t buf[3] = {0};
    printf("loop\n");

    wait_for_flash_ready();
    watch_set_pin_level(A3, false);
    spi_flash_read_command(CMD_READ_JEDEC_ID, buf, 3);
    printf("ident: %x, %x, %x\n", buf[0], buf[1], buf[2]);

    watch_set_pin_level(A3, true);
    wait_for_flash_ready();

    delay_ms(10000);

    return false;
}
