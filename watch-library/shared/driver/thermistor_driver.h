/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef THERMISTOR_DRIVER_H_
#define THERMISTOR_DRIVER_H_

// TODO: Do these belong in movement_config.h? In settings we can set on the watch? In an EEPROM configuration area?
// Think on this. [joey 11/22]
#define THERMISTOR_SENSE_PIN (A2)
#define THERMISTOR_ENABLE_PIN (A0)
#define THERMISTOR_ENABLE_VALUE (false)
#define THERMISTOR_HIGH_SIDE (true)
#define THERMISTOR_B_COEFFICIENT (3380.0)
#define THERMISTOR_NOMINAL_TEMPERATURE (25.0)
#define THERMISTOR_NOMINAL_RESISTANCE (10000.0)
#define THERMISTOR_SERIES_RESISTANCE (10000.0)

void thermistor_driver_enable(void);
void thermistor_driver_disable(void);
float thermistor_driver_get_temperature(void);

#endif // THERMISTOR_DRIVER_H_
