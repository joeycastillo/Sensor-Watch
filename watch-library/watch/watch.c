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

#include "watch.h"

#include "watch_rtc.c"
#include "watch_slcd.c"
#include "watch_extint.c"
#include "watch_led.c"
#include "watch_buzzer.c"
#include "watch_adc.c"
#include "watch_gpio.c"
#include "watch_i2c.c"
#include "watch_uart.c"
#include "watch_deepsleep.c"
#include "watch_private.c"

uint32_t watch_get_cpu_speed() {
    uint8_t fsel = hri_oscctrl_get_OSC16MCTRL_FSEL_bf(OSCCTRL, OSCCTRL_OSC16MCTRL_MASK);
    switch (fsel) {
        case OSCCTRL_OSC16MCTRL_FSEL_4_Val:
            return 4000000;
            break;
        case OSCCTRL_OSC16MCTRL_FSEL_8_Val:
            return 8000000;
            break;
        case OSCCTRL_OSC16MCTRL_FSEL_12_Val:
            return 12000000;
            break;
        case OSCCTRL_OSC16MCTRL_FSEL_16_Val:
            return 16000000;
            break;
    }
    return 0;
}
