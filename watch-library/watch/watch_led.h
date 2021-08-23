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
////< @file watch_led.h

/** @addtogroup led LED Control
  * @brief This section covers functions related to the bi-color red/green LED mounted behind the LCD.
  * @details The SAM L22 is an exceedingly power efficient chip, whereas the LED's are relatively power-
  *          hungry. The green LED, at full power, consumes more power than the whole chip in active mode,
  *          and the red LED consumes about twelve times as much power! The LED's should thus be used only
  *          sparingly in order to preserve battery life.
  * @todo Explore running the TC3 PWM driver in standby mode; this would require that the user disable it
  *       in app_prepare_for_sleep, but could allow for low power, low duty indicator LED usage.
  */
/// @{
/** @brief Enables the LED.
  * @param pwm if true, enables PWM output for brightness control (required to use @ref watch_set_led_color).
               If false, configures the LED pins as digital outputs.
  * @note The TC driver required for PWM mode does not run in STANDBY mode. You should keep your app awake
          while PWM'ing the LED's, and disable them before going to sleep.
  */
void watch_enable_led(bool pwm);

/** @brief Disables the LEDs.
  * @param pwm if true, disables the PWM output. If false, disables the digital outputs.
  */
void watch_disable_led(bool pwm);

/** @brief Sets the LED to a custom color by modulating each output's duty cycle.
  * @param red The red value.
  * @param green The green value.
  * @note still working on this, 0-65535 works now but these values may change.
  */
void watch_set_led_color(uint16_t red, uint16_t green);

/** @brief Sets the red LED to full brightness, and turns the green LED off.
  * @note Of the two LED's in the RG bi-color LED, the red LED is the less power-efficient one (~4.5 mA).
  */
void watch_set_led_red();

/** @brief Sets the green LED to full brightness, and turns the red LED off.
  * @note Of the two LED's in the RG bi-color LED, the green LED is the more power-efficient one (~0.44 mA).
  */
void watch_set_led_green();

/** @brief Sets both red and green LEDs to full brightness.
  * @note The total current draw between the two LED's in this mode will be ~5 mA, which is more than the
  *       watch draws in any other mode. Take care not to drain the battery.
  */
void watch_set_led_yellow();

/** @brief Turns both the red and the green LEDs off. */
void watch_set_led_off();
/// @}
