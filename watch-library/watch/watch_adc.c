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

 static bool ADC_0_ENABLED = false;

void watch_enable_analog(const uint8_t pin) {
    if (!ADC_0_ENABLED) ADC_0_init();
    ADC_0_ENABLED = true;

    gpio_set_pin_direction(pin, GPIO_DIRECTION_OFF);
    switch (pin) {
        case A0:
            gpio_set_pin_function(A0, PINMUX_PB04B_ADC_AIN12);
            break;
        case A1:
            gpio_set_pin_function(A1, PINMUX_PB01B_ADC_AIN9);
            break;
        case A2:
            gpio_set_pin_function(A2, PINMUX_PB02B_ADC_AIN10);
            break;
        default:
            return;
    }
}
