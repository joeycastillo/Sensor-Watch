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

// initialize the Watch struct, set power options and global settings
void watch_init();

// getters for figuring out if functionality is enabled
bool watch_is_display_enabled();
bool watch_is_led_enabled();
bool watch_is_buzzer_enabled();
bool watch_is_calendar_enabled();
bool watch_is_adc_enabled();
bool watch_is_i2c_enabled();
bool watch_is_spi_enabled();
bool watch_is_eic_enabled();

// the watch can standby as long as there are no PWM's active and either the RTC or the EIC is active.
bool watch_can_enter_standby();

// the watch can enter deep sleep as long as the RTC is enabled (so we have a wake source)
bool watch_can_enter_backup();

// display-oriented methods
void watch_enable_display();
void watch_display_pixel(uint8_t com, uint8_t seg);
void watch_display_string(char *string, uint8_t position);

// LED-oriented methods
// enable the TC for PWM of the LED's, including the clock source and pin mux
void watch_enable_led();
// disable the TC's clock source and assign the LED pins no function. Call this before re-entering standby.
void watch_disable_led();
// sets the LED color to some combination of red and green.
void watch_set_led_color(uint8_t red, uint8_t green);
// sets the red LED to an indicator level of brightness (may not make the screen readable in the dark)
void watch_set_led_red();
// sets the green LED to an indicator level of brightness (may not make the screen readable in the dark)
void watch_set_led_green();
// sets both red and green LEDs to 0% intensity (but does not disable the TC).
void watch_set_led_off();

// buzzer
void watch_enable_buzzer();
void watch_disable_buzzer();

// calendar, RTC and external wake functions
// enable the RTC peripheral
void watch_enable_date_time();
// set the date and time
void watch_set_date_time(struct calendar_date_time date_time);
// get the date and time from the RTC
void watch_get_date_time(struct calendar_date_time *date_time);
// enable a one-second tick callback from the RTC.
void watch_enable_tick(ext_irq_cb_t callback);

// analog-related functions
void watch_enable_analog(const uint8_t pin);

// external interrupt functions (todo: rename for clarity)
void watch_enable_buttons();
// enable external interrupt callback for a given pin
void watch_register_button_callback(const uint32_t pin, ext_irq_cb_t callback);

// digital IO functions
void watch_enable_digital_input(const uint8_t pin);
void watch_enable_digital_output(const uint8_t pin);

// I2C functions
void watch_enable_i2c();
void watch_i2c_send(int16_t addr, uint8_t *buf, uint16_t length);
void watch_i2c_receive(int16_t addr, uint8_t *buf, uint16_t length);

#endif /* WATCH_H_ */