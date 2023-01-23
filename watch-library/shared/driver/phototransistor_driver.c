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

#include "phototransistor_driver.h"
#include "watch.h"
#include "watch_utility.h"

void phototransistor_driver_enable(void) {
    // Enable the ADC peripheral, which we'll use to read the phototransistor value.
    watch_enable_adc();
    // Enable analog circuitry on the sense pin, which is tied to the phototransistor's base.
    watch_enable_analog_input(PHOTOTRANSISTOR_SENSE_PIN);
    // Enable digital output on the enable pin, which is the power to the phototransistor circuit.
    watch_enable_digital_output(PHOTOTRANSISTOR_ENABLE_PIN);
    // and make sure it's off.
    // watch_set_pin_level(PHOTOTRANSISTOR_ENABLE_PIN, !PHOTOTRANSISTOR_ENABLE_VALUE);
    watch_set_pin_level(PHOTOTRANSISTOR_ENABLE_PIN, PHOTOTRANSISTOR_ENABLE_VALUE);
}

void phototransistor_driver_disable(void) {
    // Disable the ADC peripheral.
    watch_disable_adc();
    // Disable analog circuitry on the sense pin to save power.
    watch_disable_analog_input(PHOTOTRANSISTOR_SENSE_PIN);
    // Disable the enable pin's output circuitry.
    watch_disable_digital_output(PHOTOTRANSISTOR_ENABLE_PIN);
}

uint16_t phototransistor_driver_get_light_level(void) {
    // set the enable pin to the level that powers the phototransistor circuit.
    // watch_set_pin_level(PHOTOTRANSISTOR_ENABLE_PIN, PHOTOTRANSISTOR_ENABLE_VALUE);
    // get the sense pin level
    uint16_t value = watch_get_analog_pin_level(PHOTOTRANSISTOR_SENSE_PIN);
    // and then set the enable pin to the opposite value to power down the phototransistor circuit.
    // watch_set_pin_level(PHOTOTRANSISTOR_ENABLE_PIN, !PHOTOTRANSISTOR_ENABLE_VALUE);

    return value;
}
