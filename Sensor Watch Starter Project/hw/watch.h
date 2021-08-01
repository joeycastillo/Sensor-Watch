/*
 * Watch.h
 *
 * Created: 4/25/2021 8:29:16 AM
 *  Author: joeycastillo
 */ 


#ifndef WATCH_H_
#define WATCH_H_
#include <stdint.h>
#include "driver_init.h"
#include "hpl_calendar.h"
#include "hal_ext_irq.h"

void watch_init();

void watch_enable_display();
void watch_display_pixel(uint8_t com, uint8_t seg);
void watch_display_string(char *string, uint8_t position);

void watch_enable_led();
void watch_disable_led();
void watch_set_led_color(uint16_t red, uint16_t green);
void watch_set_led_red();
void watch_set_led_green();
void watch_set_led_off();

void watch_enable_date_time();
void watch_set_date_time(struct calendar_date_time date_time);
void watch_get_date_time(struct calendar_date_time *date_time);

void watch_enable_tick_callback(ext_irq_cb_t callback);

void watch_enable_analog(const uint8_t pin);

void watch_enable_buttons();
void watch_register_button_callback(const uint32_t pin, ext_irq_cb_t callback);

void watch_enable_digital_input(const uint8_t pin);
void watch_enable_pull_up(const uint8_t pin);
void watch_enable_pull_down(const uint8_t pin);
bool watch_get_pin_level(const uint8_t pin, const bool level);

void watch_enable_digital_output(const uint8_t pin);
void watch_set_pin_level(const uint8_t pin, const bool level);

struct io_descriptor *I2C_0_io;

void watch_enable_i2c();
void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length);
void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length);

#endif /* WATCH_H_ */