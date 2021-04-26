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

#define WATCH_NUM_DISPLAYS (3)

struct WatchDisplay {
	uint8_t num_chars;
	uint8_t* chars;
};

typedef struct Watch {
	struct WatchDisplay displays[WATCH_NUM_DISPLAYS];
} Watch;

void watch_init(Watch *watch);

void watch_enable_led();
void watch_disable_led();
void watch_set_led_color(uint16_t red, uint16_t green);
void watch_set_led_red();
void watch_set_led_green();

void watch_enable_date_time();
void watch_set_date_time(struct calendar_date_time date_time);
void watch_get_date_time(struct calendar_date_time *date_time);

void watch_enable_analog(const uint8_t pin);

void watch_enable_digital_input(const uint8_t pin);
void watch_enable_digital_output(const uint8_t pin);

struct io_descriptor *I2C_0_io;

void watch_enable_i2c();
void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length);
void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length);

#endif /* WATCH_H_ */