#include <stdio.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"
#include "spiflash.h"

// this is a very basic app to confirm that SPI is working, tested with board OSO-MISC-21-017 and a GD25Q16C Flash chip.

void app_init(void) {
    spi_flash_init();

    uint8_t buf[3] = {1, 2, 3};
    spi_flash_command(CMD_ENABLE_WRITE);
    // note that you will need to erase the sector to write different values later
    spi_flash_write_data(0, buf, 3);
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

    // should print 1, 2, 3
    spi_flash_read_data(0, buf, 3);
    printf("data: %x, %x, %x\n", buf[0], buf[1], buf[2]);

    delay_ms(100);

    return false;
}
