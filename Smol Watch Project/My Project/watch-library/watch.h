/*
 * Watch.h
 *
 * Created: 4/25/2021 8:29:16 AM
 *  Author: joeycastillo
 */ 


#ifndef WATCH_H_
#define WATCH_H_
#include <stdint.h>
#include "hpl_calendar.h"
#include "hal_ext_irq.h"

typedef struct Watch {
	bool display_enabled;
	bool led_enabled;
	bool buzzer_enabled;
	bool calendar_enabled;
	bool adc_enabled;
	bool i2c_enabled;
	bool spi_enabled;
	bool eic_enabled;

	uint8_t num_chars;
	const uint64_t* segment_map;
} Watch;

void watch_init(Watch *watch);

void watch_enable_display(Watch *watch);
void watch_display_pixel(Watch *watch, uint8_t com, uint8_t seg);
void watch_display_string(Watch *watch, char *string, uint8_t position);

void watch_enable_led(Watch *watch);
void watch_disable_led(Watch *watch);
void watch_set_led_color(uint16_t red, uint16_t green);
void watch_set_led_red();
void watch_set_led_green();

void watch_enable_date_time(Watch *watch);
void watch_set_date_time(struct calendar_date_time date_time);
void watch_get_date_time(struct calendar_date_time *date_time);

void watch_enable_analog(Watch *watch, const uint8_t pin);

void watch_enable_interrupts(Watch *watch);
void watch_register_interrupt_callback(Watch *watch, const uint32_t pin, ext_irq_cb_t callback);

void watch_enable_digital_input(const uint8_t pin);
void watch_enable_digital_output(const uint8_t pin);

struct io_descriptor *I2C_0_io;

void watch_enable_i2c(Watch *watch);
void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length);
void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length);

#endif /* WATCH_H_ */