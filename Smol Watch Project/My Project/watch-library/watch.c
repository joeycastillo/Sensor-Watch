/*
 * watch.c
 *
 * Created: 4/25/2021 10:22:10 AM
 *  Author: joeycastillo
 */ 

#include "watch.h"
#include "driver_init.h"

void watch_init(Watch *watch) {
}

void watch_enable_led() {
	PWM_0_init();
	pwm_set_parameters(&PWM_0, 10000, 0);
	pwm_enable(&PWM_0);
}

void watch_disable_led() {
	gpio_set_pin_function(RED, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_function(GREEN, GPIO_PIN_FUNCTION_OFF);

	pwm_disable(&PWM_0);
}

void watch_set_led_color(uint16_t red, uint16_t green) {
	TC3->COUNT16.CC[0].reg = red;
	TC3->COUNT16.CC[1].reg = green;
}

void watch_set_led_red() {
	watch_set_led_color(65535, 0);
}

void watch_set_led_green() {
	watch_set_led_color(0, 65535);
}

void watch_enable_date_time() {
	CALENDAR_0_init();
	calendar_enable(&CALENDAR_0);
}

void watch_set_date_time(struct calendar_date_time date_time) {
	calendar_set_date(&CALENDAR_0, &date_time.date);
	calendar_set_time(&CALENDAR_0, &date_time.time);
}

void watch_get_date_time(struct calendar_date_time *date_time) {
	calendar_get_date_time(&CALENDAR_0, date_time);
}

void watch_enable_analog(const uint8_t pin) {
	ADC_0_init(); // todo: only call this once
	switch (pin) {
		case A0:
		gpio_set_pin_function(A0, PINMUX_PB04B_ADC_AIN12);
		break;
		case A1:
		gpio_set_pin_function(A1, PINMUX_PB01B_ADC_AIN9);
		break;
		case A2:
		gpio_set_pin_function(A2, PINMUX_PB02B_ADC_AIN10);
		break;
		default:
		return;
	}
	gpio_set_pin_direction(pin, GPIO_DIRECTION_OFF);
}

void watch_enable_digital_input(const uint8_t pin) {
	gpio_set_pin_direction(pin, GPIO_DIRECTION_IN);
	gpio_set_pin_function(pin, GPIO_PIN_FUNCTION_OFF);
}

void watch_enable_digital_output(const uint8_t pin) {
	gpio_set_pin_direction(pin, GPIO_DIRECTION_OUT);
	gpio_set_pin_function(pin, GPIO_PIN_FUNCTION_OFF);
}

struct io_descriptor *I2C_0_io;

void watch_enable_i2c() {
	I2C_0_init();
	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
}

void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length) {
	i2c_m_sync_set_slaveaddr(&I2C_0, addr, I2C_M_SEVEN);
	io_write(I2C_0_io, buf, length);
}

void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length) {
	i2c_m_sync_set_slaveaddr(&I2C_0, addr, I2C_M_SEVEN);
	io_read(I2C_0_io, buf, length);
}
