/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_adc_sync.h>

#include <hal_ext_irq.h>

#include <hal_calendar.h>

#include <hal_i2c_m_sync.h>

#include <hal_delay.h>
#include <hal_pwm.h>
#include <hpl_tc_base.h>

#include <hal_pwm.h>
#include <hpl_tcc.h>
#include <hal_slcd_sync.h>

extern struct adc_sync_descriptor ADC_0;

extern struct calendar_descriptor CALENDAR_0;

extern struct i2c_m_sync_desc I2C_0;

extern struct pwm_descriptor PWM_0;

extern struct pwm_descriptor       PWM_1;
extern struct slcd_sync_descriptor SEGMENT_LCD_0;

void ADC_0_PORT_init(void);
void ADC_0_CLOCK_init(void);
void ADC_0_init(void);

void CALENDAR_0_CLOCK_init(void);
void CALENDAR_0_init(void);

void I2C_0_CLOCK_init(void);
void I2C_0_init(void);
void I2C_0_PORT_init(void);

void delay_driver_init(void);

void PWM_0_PORT_init(void);
void PWM_0_CLOCK_init(void);
void PWM_0_init(void);

void PWM_1_PORT_init(void);
void PWM_1_CLOCK_init(void);
void PWM_1_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
