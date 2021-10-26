#include <stdio.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"

// NOTE: as of this writing (10/25/21) there is no SPI controller functionality in the watch library.
// this is a very basic app to confirm that SPI is working, tested with board OSO-MISC-21-001 and a GD25Q16C Flash chip.
// The updated SPI Flash sensor board design is OSO-MISC-21-017 (it's easier to build, 0603 passives instead of 0402's).

struct io_descriptor *io;
struct spi_m_sync_descriptor SPI_0;

void app_init() {
    // SPI_0_CLOCK_init
    hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
    hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_SLOW, CONF_GCLK_SERCOM3_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
    hri_mclk_set_APBCMASK_SERCOM3_bit(MCLK);

    spi_m_sync_init(&SPI_0, SERCOM3);

    // SPI_0_PORT_init
    gpio_set_pin_level(A3, true);
    gpio_set_pin_direction(A3, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(A3, GPIO_PIN_FUNCTION_OFF);

    gpio_set_pin_level(A2, false);
    gpio_set_pin_direction(A2, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(A2, PINMUX_PB02C_SERCOM3_PAD0);

    gpio_set_pin_direction(A4, GPIO_DIRECTION_IN);
    gpio_set_pin_pull_mode(A4, GPIO_PULL_OFF);
    gpio_set_pin_function(A4, PINMUX_PB00C_SERCOM3_PAD2);

    gpio_set_pin_level(A1, false);
    gpio_set_pin_direction(A1, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(A1, PINMUX_PB01C_SERCOM3_PAD3);

    spi_m_sync_get_io_descriptor(&SPI_0, &io);
    spi_m_sync_enable(&SPI_0);
}

void app_wake_from_backup() {
}

void app_setup() {
}

void app_prepare_for_standby() {
}

void app_wake_from_standby() {
}

static uint8_t get_id_command[4] = {0x9F};

bool app_loop() {
    watch_set_pin_level(A3, false);
    io_write(io, get_id_command, 1);
    uint8_t buf[3] = {0};

    // should print 0, 0, 0
    printf("blank: %x, %x, %x\n", buf[0], buf[1], buf[2]);
    io_read(io, buf, 3);
    watch_set_pin_level(A3, true);
    // should print c8, 40, 15
    printf("ident: %x, %x, %x\n", buf[0], buf[1], buf[2]);

    delay_ms(100);

    return false;
}
