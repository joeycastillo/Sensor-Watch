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
////< @file watch_gpio.h

/** @addtogroup gpio Digital Input and Output
  * @brief This section covers functions related to general-purpose input and output signals.
  */
/// @{
/** @brief Configures the selected pin for digital input.
  * @param pin The pin that you wish to act as an input.
  */
void watch_enable_digital_input(const uint8_t pin);

/** @brief Disables any digital input, along with any pull-up or pull-down configuration.
  * @param pin The pin that you wish to disable.
  */
void watch_disable_digital_input(const uint8_t pin);

/** @brief Enables a pull-up resistor on the selected pin.
  * @param pin The pin that you wish to configure.
  */
void watch_enable_pull_up(const uint8_t pin);

/** @brief Enables a pull-down resistor on the selected pin.
  * @param pin The pin that you wish to configure.
  */
void watch_enable_pull_down(const uint8_t pin);

/** @brief Gets the level of the selected pin.
  * @param pin The pin whose value you wish to read.
  * @return true if the pin was logic high; otherwise, false.
  */
bool watch_get_pin_level(const uint8_t pin);

/** @brief Configures the selected pin for digital output.
  * @param pin The pin that you wish to act as an output.
  */
void watch_enable_digital_output(const uint8_t pin);

/** @brief Disables digital output on the selected pin.
  * @param pin The pin that you wish disable.
  */
void watch_disable_digital_output(const uint8_t pin);

/** @brief Sets the level of the selected pin.
  * @param pin The pin whose value you wish to set.
  * @param level The level you wish to set: true for high, false for low.
  */
void watch_set_pin_level(const uint8_t pin, const bool level);
/// @}
