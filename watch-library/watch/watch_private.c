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

void _watch_init() {
    // disable the LED pin (it may have been enabled by the bootloader)
    watch_disable_digital_output(RED);

    // Use switching regulator for lower power consumption.
    SUPC->VREG.bit.SEL = 1;
    while(!SUPC->STATUS.bit.VREGRDY);

    // External wake depends on RTC; calendar is a required module.
    CALENDAR_0_init();
    calendar_enable(&CALENDAR_0);

    // Not sure if this belongs in every app -- is there a power impact?
    delay_driver_init();

    // set up state
    btn_alarm_callback = NULL;
    a2_callback = NULL;
    a4_callback = NULL;
}
