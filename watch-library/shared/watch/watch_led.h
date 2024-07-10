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
#ifndef _WATCH_LED_H_INCLUDED
#define _WATCH_LED_H_INCLUDED
////< @file watch_led.h

#include "watch.h"

/** @addtogroup led LED Control
  * @brief This section covers functions related to the bi-color red/green LED mounted behind the LCD.
  * @details The SAM L22 is an exceedingly power efficient chip, whereas the LED's are relatively power-
  *          hungry. The green LED, at full power, consumes more power than the whole chip in active mode,
  *          and the red LED consumes about twelve times as much power! The LED's should thus be used only
  *          sparingly in order to preserve battery life.
  * @note Some watches use a red/blue LED instead of a red/green LED. You will be able to determine this
  *       easily when you double tap the reset button: if the pulsing bootloader LED is red, you have a
  *       red/green edition; if it is blue, you have a red/blue edition. For red/blue watches, build your
  *       project with the command `make COLOR=BLUE`, and the watch library will automatically swap the pins
  *       so that watch_set_led_red sets the red LED, and watch_set_led_green sets the blue one.
  */
/// @{
/** @brief Enables the bi-color LED.
  * @note The TCC peripheral that drives the LEDs does not run in STANDBY mode — but the outputs do! This
  *       means that if you set either red, green or both LEDs to full power, they will shine even when
  *       your app is asleep. If, however, you set a custom color using watch_set_led_color, the color will
  *       not display correctly in STANDBY mode. You will need to keep your app running while the LED is on.
  */
void watch_enable_leds(void);

/** @brief Disables the LEDs.
  * @note This method will also disable the buzzer, since the buzzer and LED both make use of the same
  *       peripheral to drive their PWM behavior.
  */
void watch_disable_leds(void);

/** @brief Sets the LED to a custom color by modulating each output's duty cycle.
  * @param red The red value from 0-255.
  * @param green The green value from 0-255. If your watch has a red/blue LED, this will be the blue value.
  * @note If you are displaying a custom color, you will need to prevent your app from going to sleep
  *       while the LED is on; otherwise, the color will not display correctly. You can do this by
  *       returning false in your app_loop method.
  */
void watch_set_led_color(uint8_t red, uint8_t green);

/** @brief On boards with an RGB LED, sets the LED to a custom color by modulating each output's duty cycle.
  * @param red The red value from 0-255.
  * @param green The green value from 0-255.
  * @param blue The blue value from 0-255.
  * @note If you are displaying a custom color, you will need to prevent your app from going to sleep
  *       while the LED is on; otherwise, the color will not display correctly. You can do this by
  *       returning false in your app_loop method.
  */
void watch_set_led_color_rgb(uint8_t red, uint8_t green, uint8_t blue);

/** @brief Sets the red LED to full brightness, and turns the green LED off.
  * @details Of the two LED's in the RG bi-color LED, the red LED is the less power-efficient one (~4.5 mA).
  */
void watch_set_led_red(void);

/** @brief Sets the green LED to full brightness, and turns the red LED off.
  * @details Of the two LED's in the RG bi-color LED, the green LED is the more power-efficient one (~0.44 mA).
  * @note If your watch has a red/blue LED, this method will set the LED to blue.
  */
void watch_set_led_green(void);

/** @brief Sets both red and green LEDs to full brightness.
  * @details The total current draw between the two LED's in this mode will be ~5 mA, which is more than the
  *          watch draws in any other mode. Take care not to drain the battery.
  * @note If your watch has a red/blue LED, this method will set the LED to pink.
  */
void watch_set_led_yellow(void);

/** @brief Turns both the red and the green LEDs off. */
void watch_set_led_off(void);

/// @}
#endif
