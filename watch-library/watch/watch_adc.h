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
////< @file watch_adc.h

/** @addtogroup adc Analog Input
  * @brief This section covers functions related to the SAM L22's analog-to-digital converter,
  *        as well as configuring and reading values from the five analog-capable pins on the
  *        9-pin connector.
  */
/// @{
/** @brief Enables the ADC peripheral. You must call this before attempting to read a value
  *        from an analog pin.
  */
void watch_enable_adc();

/** @brief Configures the selected pin for analog input.
  * @param pin One of pins A0-A4.
  */
void watch_enable_analog_input(const uint8_t pin);

/** @brief Reads an analog value from one of the pins.
  * @param pin One of pins A0-A4.
  * @return a 16-bit unsigned integer from 0-65535 representing the sampled value, unless you
  *         have changed the number of samples. @see watch_set_num_analog_samples for details
  *         on how that function changes the values returned from this one.
  **/
uint16_t watch_get_analog_pin_level(const uint8_t pin);

/** @brief Sets the number of samples to accumulate when measuring a pin level. Default is 16.
  * @param samples A power of 2 <= 1024. Specifically: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512
                   or 1024. Any other value will be ignored.
  * @details The SAM L22's ADC has a resolution of 12 bits. By default, the watch configures
  *          the ADC to take 16 samples of the analog input and accumulate them in the result
  *          register; this effectively gives us a 16-bit resolution, at the cost of taking 16
  *          ADC cycles to complete a measurement. If you are measuring a slowly changing signal
  *          like a thermistor output or an ambient light sensor this is probably fine, even
  *          desirable. If you are measuring something a bit more fast-paced, like an analog
  *          accelerometer, you may wish to exchange precision for speed. In this case you may
  *          call this function to configure the ADC to accumulate fewer samples. HOWEVER! Note
  *          that this may change the range of values returned from watch_get_analog_pin_level:
  *            - For watch_set_num_analog_samples(1), the returned value will be 12 bits (0-4095).
  *            - For watch_set_num_analog_samples(2), the returned value will be 13 bits (0-8191).
  *            - For watch_set_num_analog_samples(4), the returned value will be 14 bits (0-16383).
  *            - For watch_set_num_analog_samples(8), the returned value will be 15 bits (0-32767).
  *         For sampling values over 16, the returned value will still be 16 bits (0-65535); the
  *         ADC will automatically divide the measured value by whatever factor is necessary to fit
  *         the result in 16 bits.
  * @see watch_get_analog_pin_level
  **/
void watch_set_num_analog_samples(uint16_t samples);

/** @brief Sets the length of time spent sampling, which allows measurement of higher impedance inputs.
  *        Default is 1.
  * @param cycles The number of ADC cycles to sample, between 1 and 64.
  * @see this article by Thea Flowers: https://blog.thea.codes/getting-the-most-out-of-the-samd21-adc/
  *      which is where I learned all of this.
  * @details To measure an analog value, the SAM L22 must charge a capacitor to the analog voltage
  *          presented at the input. This takes time. Importantly, the higher the input impedance,
  *          the more time this takes. As a basic example: if you are using a thermistor tied to
  *          VCC to measure temperature, the capacitor has to charge through the thermistor. The
  *          higher the resistor value, the higher the input impedance, and the more time we need
  *          to allow for the measurement. By default, the ADC is configured to run on a 500 kHz
  *          clock with a sample time of one cycle. This is appropriate for an input impedance up
  *          to about 28kΩ. Setting the sampling time to 4 cycles allows for an input impedance up
  *          to 123kΩ. Setting the sampling time to the maximum of 64 cycles theoretically allows
  *          for input impedance up to 2 MΩ. (I based these numbers on the calculator in the linked
  *          blog post; it also has a ton of great info on the SAM D21 ADC, which is similar to the
  *          SAM L22's).
  **/
void watch_set_analog_sampling_length(uint8_t cycles);

/** @brief Disables the analog circuitry on the selected pin.
  * @param pin One of pins A0-A4.
  */
void watch_disable_analog_input(const uint8_t pin);

/** @brief Disables the ADC peripheral.
  * @note You will need to call watch_enable_adc to re-enable the ADC peripheral. When you do, it will
  *       have the default settings of 16 samples and 1 measurement cycle; if you customized these
  *       parameters, you will need to set them up again.
  **/
void watch_disable_adc();

/// @}
