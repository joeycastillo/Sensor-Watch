#include <stdio.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"

// this is a very basic app to confirm that SPI is working, tested with board OSO-MISC-21-017 and a GD25Q16C Flash chip.

void app_init(void) {
    watch_enable_spi();
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
    uint8_t get_id_command[1] = {0x9F};
    uint8_t buf[3] = {0};

    watch_set_pin_level(A3, false);

    // should print 0, 0, 0
    watch_spi_send(get_id_command, 1);
    printf("blank: %x, %x, %x\n", buf[0], buf[1], buf[2]);

    // should print c8, 40, 15
    watch_spi_receive(buf, 3);
    printf("ident: %x, %x, %x\n", buf[0], buf[1], buf[2]);

    watch_set_pin_level(A3, true);

    delay_ms(100);

    return false;
}
