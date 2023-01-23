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

#include <stdint.h>

#ifndef PHOTOTRANSISTOR_DRIVER_H_
#define PHOTOTRANSISTOR_DRIVER_H_

#define PHOTOTRANSISTOR_SENSE_PIN (A4)
#define PHOTOTRANSISTOR_ENABLE_PIN (A0)
#define PHOTOTRANSISTOR_ENABLE_VALUE (true)
#define PHOTOTRANSISTOR_SERIES_RESISTANCE (1000.0)

void phototransistor_driver_enable(void);
void phototransistor_driver_disable(void);
uint16_t phototransistor_driver_get_light_level(void);

#endif // PHOTOTRANSISTOR_DRIVER_H_
