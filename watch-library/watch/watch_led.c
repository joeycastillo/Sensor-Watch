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

 bool PWM_0_enabled = false;

void watch_enable_led(bool pwm) {
    if (pwm) {
        if (PWM_0_enabled) return;

        PWM_0_init();
        pwm_set_parameters(&PWM_0, 10000, 0);
        pwm_enable(&PWM_0);

        PWM_0_enabled = true;
    } else {
        watch_enable_digital_output(RED);
        watch_enable_digital_output(GREEN);
    }
    watch_set_led_off();
}

void watch_disable_led(bool pwm) {
    if (pwm) {
        if (!PWM_0_enabled) return;
        pwm_disable(&PWM_0);
        PWM_0_enabled = false;
    }

    watch_disable_digital_output(RED);
    watch_disable_digital_output(GREEN);
}

void watch_set_led_color(uint16_t red, uint16_t green) {
    if (PWM_0_enabled) {
        TC3->COUNT16.CC[0].reg = red;
        TC3->COUNT16.CC[1].reg = green;
    }
}

void watch_set_led_red() {
    if (PWM_0_enabled) {
        watch_set_led_color(65535, 0);
    } else {
        watch_set_pin_level(RED, true);
        watch_set_pin_level(GREEN, false);
    }
}

void watch_set_led_green() {
    if (PWM_0_enabled) {
        watch_set_led_color(65535, 0);
    } else {
        watch_set_pin_level(RED, false);
        watch_set_pin_level(GREEN, true);
    }
}

void watch_set_led_yellow() {
    if (PWM_0_enabled) {
        watch_set_led_color(65535, 65535);
    } else {
        watch_set_pin_level(RED, true);
        watch_set_pin_level(GREEN, true);
    }
}

void watch_set_led_off() {
    if (PWM_0_enabled) {
        watch_set_led_color(0, 0);
    } else {
        watch_set_pin_level(RED, false);
        watch_set_pin_level(GREEN, false);
    }
}
