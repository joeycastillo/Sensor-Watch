/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

struct slcd_sync_descriptor SEGMENT_LCD_0;

struct i2c_m_sync_desc I2C_0;

struct spi_m_sync_descriptor SPI_0;

void I2C_0_PORT_init(void) {

	gpio_set_pin_pull_mode(SDA,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SDA, PINMUX_PB30C_SERCOM1_PAD0);

	gpio_set_pin_pull_mode(SCL,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SCL, PINMUX_PB31C_SERCOM1_PAD1);
}

void I2C_0_CLOCK_init(void) {
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_SLOW, CONF_GCLK_SERCOM1_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM1_bit(MCLK);
}

void I2C_0_init(void) {
	I2C_0_CLOCK_init();
	i2c_m_sync_init(&I2C_0, SERCOM1);
	I2C_0_PORT_init();
}

void SPI_0_PORT_init(void) {

	gpio_set_pin_level(A2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(A2, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(A2, PINMUX_PB02C_SERCOM3_PAD0);

	// Set pin direction to input
	gpio_set_pin_direction(A4, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(A4,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(A4, PINMUX_PB00C_SERCOM3_PAD2);

	gpio_set_pin_level(A1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(A1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(A1, PINMUX_PB01C_SERCOM3_PAD3);

	gpio_set_pin_level(A3,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(A3, GPIO_DIRECTION_OUT);
}

void SPI_0_CLOCK_init(void) {
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_SLOW, CONF_GCLK_SERCOM3_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM3_bit(MCLK);
}

void SPI_0_init(void) {
	SPI_0_CLOCK_init();
	spi_m_sync_init(&SPI_0, SERCOM3);
	SPI_0_PORT_init();
}

void delay_driver_init(void) {
	delay_init(SysTick);
}

void SEGMENT_LCD_0_PORT_init(void) {
	gpio_set_pin_function(SLCD0, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD1, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD2, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD3, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD4, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD5, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD6, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD7, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD8, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD9, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD10, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD11, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD12, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD13, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD14, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD15, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD16, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD17, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD18, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD19, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD20, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD21, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD22, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD23, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD24, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD25, GPIO_PIN_FUNCTION_B);
	gpio_set_pin_function(SLCD26, GPIO_PIN_FUNCTION_B);
}

/**
 * \brief SLCD initialization function
 *
 * Enables SLCD peripheral, clocks and initializes SLCD driver
 */
void SEGMENT_LCD_0_init(void) {
	hri_mclk_set_APBCMASK_SLCD_bit(SLCD);
	slcd_sync_init(&SEGMENT_LCD_0, SLCD);
	SEGMENT_LCD_0_PORT_init();
}
