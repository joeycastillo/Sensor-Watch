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

#include <hpl_adc_base.h>

struct slcd_sync_descriptor SEGMENT_LCD_0;

struct adc_sync_descriptor ADC_0;

struct calendar_descriptor CALENDAR_0;

struct i2c_m_sync_desc I2C_0;

struct pwm_descriptor PWM_0;

struct pwm_descriptor PWM_1;

void ADC_0_CLOCK_init(void)
{
	hri_mclk_set_APBCMASK_ADC_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC_GCLK_ID, CONF_GCLK_ADC_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	adc_sync_init(&ADC_0, ADC, (void *)NULL);
}

void EXTERNAL_IRQ_0_init(void) {
	hri_gclk_write_PCHCTRL_reg(GCLK, EIC_GCLK_ID, CONF_GCLK_EIC_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBAMASK_EIC_bit(MCLK);

	// Set pin direction to input
	gpio_set_pin_direction(BTN_ALARM, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(BTN_ALARM,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_DOWN);

	gpio_set_pin_function(BTN_ALARM, PINMUX_PB05A_EIC_EXTINT5);

	// Set pin direction to input
	gpio_set_pin_direction(BTN_LIGHT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(BTN_LIGHT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_DOWN);

	gpio_set_pin_function(BTN_LIGHT, PINMUX_PA22A_EIC_EXTINT6);

	// Set pin direction to input
	gpio_set_pin_direction(BTN_MODE, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(BTN_MODE,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_DOWN);

	gpio_set_pin_function(BTN_MODE, PINMUX_PA23A_EIC_EXTINT7);

	ext_irq_init();
}

void CALENDAR_0_CLOCK_init(void) {
	hri_mclk_set_APBAMASK_RTC_bit(MCLK);
}

void CALENDAR_0_init(void) {
	CALENDAR_0_CLOCK_init();
	calendar_init(&CALENDAR_0, RTC);
}

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

void delay_driver_init(void) {
	delay_init(SysTick);
}

void PWM_0_PORT_init(void) {
	gpio_set_pin_function(RED, PINMUX_PA20E_TC3_WO0);
	gpio_set_pin_function(GREEN, PINMUX_PA21E_TC3_WO1);
}

void PWM_0_CLOCK_init(void) {
	hri_mclk_set_APBCMASK_TC3_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, TC3_GCLK_ID, CONF_GCLK_TC3_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void PWM_0_init(void) {
	PWM_0_CLOCK_init();
	PWM_0_PORT_init();
	pwm_init(&PWM_0, TC3, _tc_get_pwm());
}

void PWM_1_PORT_init(void) {
	gpio_set_pin_function(BUZZER, PINMUX_PA27F_TCC0_WO5);
}

void PWM_1_CLOCK_init(void) {
	hri_mclk_set_APBCMASK_TCC0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, TCC0_GCLK_ID, CONF_GCLK_TCC0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void PWM_1_init(void) {
	PWM_1_CLOCK_init();
	PWM_1_PORT_init();
	pwm_init(&PWM_1, TCC0, _tcc_get_pwm());
}

void SEGMENT_LCD_0_PORT_init(void) {
	gpio_set_pin_function(COM0, PINMUX_PB06B_SLCD_LP0);
	gpio_set_pin_function(COM1, PINMUX_PB07B_SLCD_LP1);
	gpio_set_pin_function(COM2, PINMUX_PB08B_SLCD_LP2);
	gpio_set_pin_function(SEG0, PINMUX_PB09B_SLCD_LP3);
	gpio_set_pin_function(SEG1, PINMUX_PA04B_SLCD_LP4);
	gpio_set_pin_function(SEG2, PINMUX_PA05B_SLCD_LP5);
	gpio_set_pin_function(SEG3, PINMUX_PA06B_SLCD_LP6);
	gpio_set_pin_function(SEG4, PINMUX_PA07B_SLCD_LP7);
	gpio_set_pin_function(SEG5, PINMUX_PA08B_SLCD_LP11);
	gpio_set_pin_function(SEG6, PINMUX_PA09B_SLCD_LP12);
	gpio_set_pin_function(SEG7, PINMUX_PA10B_SLCD_LP13);
	gpio_set_pin_function(SEG8, PINMUX_PA11B_SLCD_LP14);
	gpio_set_pin_function(SEG9, PINMUX_PB11B_SLCD_LP21);
	gpio_set_pin_function(SEG10, PINMUX_PB12B_SLCD_LP22);
	gpio_set_pin_function(SEG11, PINMUX_PB13B_SLCD_LP23);
	gpio_set_pin_function(SEG12, PINMUX_PB14B_SLCD_LP24);
	gpio_set_pin_function(SEG13, PINMUX_PB15B_SLCD_LP25);
	gpio_set_pin_function(SEG14, PINMUX_PA12B_SLCD_LP28);
	gpio_set_pin_function(SEG15, PINMUX_PA13B_SLCD_LP29);
	gpio_set_pin_function(SEG16, PINMUX_PA14B_SLCD_LP30);
	gpio_set_pin_function(SEG17, PINMUX_PA15B_SLCD_LP31);
	gpio_set_pin_function(SEG18, PINMUX_PA16B_SLCD_LP32);
	gpio_set_pin_function(SEG19, PINMUX_PA17B_SLCD_LP33);
	gpio_set_pin_function(SEG20, PINMUX_PA18B_SLCD_LP34);
	gpio_set_pin_function(SEG21, PINMUX_PA19B_SLCD_LP35);
	gpio_set_pin_function(SEG22, PINMUX_PB16B_SLCD_LP42);
	gpio_set_pin_function(SEG23, PINMUX_PB17B_SLCD_LP43);
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
