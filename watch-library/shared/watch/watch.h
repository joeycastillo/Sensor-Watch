/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/// @file watch.h

#ifndef WATCH_H_
#define WATCH_H_
#include <stdint.h>
#include <stdbool.h>
#include "driver_init.h"

/** @mainpage Sensor Watch Documentation
 *  @brief This documentation covers most of the functions you will use to interact with the Sensor Watch
           hardware. It is divided into the following sections:
            - @ref app - This section covers the functions that you will implement in your app.c file when designing a
                         Sensor Watch app.
            - @ref rtc - This section covers functions related to the SAM L22's real-time clock peripheral, including
                         date, time and alarm functions.
            - @ref slcd - This section covers functions related to the Segment LCD display driver, which is responsible
                          for displaying strings of characters and indicators on the main watch display.
            - @ref buttons - This section covers functions related to the three buttons: Light, Mode and Alarm.
            - @ref led - This section covers functions related to the bi-color red/green LED mounted behind the LCD.
            - @ref buzzer - This section covers functions related to the piezo buzzer.
            - @ref adc - This section covers functions related to the SAM L22's analog-to-digital converter, as well as
                         configuring and reading values from the five analog-capable pins on the 9-pin connector.
            - @ref gpio - This section covers functions related to general-purpose input and output signals.
            - @ref i2c - This section covers functions related to the SAM L22's built-I2C driver, including configuring
                         the I2C bus, putting values directly on the bus and reading data from registers on I2C devices.
            - @ref debug - This section covers functions related to the debug UART, available on pin D1 of the 9-pin connector.
            - @ref deepsleep - This section covers functions related to preparing for and entering BACKUP mode, the
                               deepest sleep mode available on the SAM L22.
 */

#include "watch_app.h"
#include "watch_rtc.h"
#include "watch_slcd.h"
#include "watch_extint.h"
#include "watch_led.h"
#include "watch_buzzer.h"
#include "watch_adc.h"
#include "watch_gpio.h"
#include "watch_i2c.h"
#include "watch_uart.h"
#include "watch_deepsleep.h"

#include "watch_private.h"

/** @brief Returns true when the battery voltage dips below 2.5V.
  * @details A CR2016 battery will have a nominal voltage between 2.9 and 3 volts for most of its lifespan. Once the battery
  *          discharges to about 60%, the voltage will drift slightly lower; this may manifest as a dimmer LED. By the time
  *          the battery voltage has fallen to 2.5 volts, it will have probably less than 10% of its capacity remaining, and
  *          you can expect the voltage to drop relatively quickly as the battery dies.
  */
bool watch_is_battery_low(void);

/** @brief Returns true if either the buzzer or the LED driver is enabled.
  * @details Both the buzzer and the LED use the TCC peripheral to drive their behavior. This function returns true if that
  *          peripheral is enabled. You can use this function to determine whether you need to call the watch_disable_leds or
  *          or watch_enable_buzzer functions before using these peripherals.
  */
bool watch_is_buzzer_or_led_enabled(void);

#endif /* WATCH_H_ */