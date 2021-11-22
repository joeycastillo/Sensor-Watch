/*
 * MIT License
 *
 * Copyright (c) 2021 Joey Castillo
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

#ifndef _WATCH_UTILITY_H_INCLUDED
#define _WATCH_UTILITY_H_INCLUDED
////< @file watch_utility.h

#include "watch.h"

/** @addtogroup utility Utility Functions
  * @brief This section covers various useful functions that don't fit anywhere else.
  **/
/// @{
/** @brief Returns a two-letter weekday for the given timestamp, suitable for display
  *        in positions 0-1 of the watch face
  * @param date_time The watch_date_time whose weekday you want.
  */
const char * watch_utility_get_weekday(watch_date_time date_time);

/** @brief Returns a temperature in degrees Celsius for a given thermistor voltage divider circuit.
  * @param value The raw analog reading from the thermistor pin (0-65535)
  * @param highside True if the thermistor is connected to VCC and the series resistor is connected
  *                 to GND; false if the thermistor is connected to GND and the series resistor is
  *                 connected to VCC.
  * @param b_coefficient From your thermistor's data sheet, the B25/85 coefficient. A typical value
  *                      will be between 2000 and 5000.
  * @param nominal_temperature From your thermistor's data sheet, the temperature (in Celsius) at
  *                            which the thermistor's resistance is at its nominal value.
  * @param nominal_resistance The thermistor's resistance at the nominal temperature.
  * @param series_resistance The value of the other resistor in the voltage divider.
  * @note Ported from Adafruit's MIT-licensed CircuitPython thermistor code, (c) 2017 Scott Shawcroft:
  *       https://github.com/adafruit/Adafruit_CircuitPython_Thermistor/blob/main/adafruit_thermistor.py
  */
float watch_utility_thermistor_temperature(uint16_t value, bool highside, float b_coefficient, float nominal_temperature, float nominal_resistance, float series_resistance);

#endif
