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

#include "watch_adc.h"
#include "driver_init.h"

static void _watch_sync_adc(void) {
    while (ADC->SYNCBUSY.reg);
}

static uint16_t _watch_get_analog_value(uint16_t channel) {
    if (ADC->INPUTCTRL.bit.MUXPOS != channel) {
        ADC->INPUTCTRL.bit.MUXPOS = channel;
        _watch_sync_adc();
    }

    ADC->SWTRIG.bit.START = 1;
    while (!ADC->INTFLAG.bit.RESRDY); // wait for "result ready" flag

    return ADC->RESULT.reg;
}

void watch_enable_adc(void) {
    MCLK->APBCMASK.reg |= MCLK_APBCMASK_ADC;
    GCLK->PCHCTRL[ADC_GCLK_ID].reg = GCLK_PCHCTRL_GEN_GCLK0 | GCLK_PCHCTRL_CHEN;

    uint16_t calib_reg = 0;
    calib_reg = ADC_CALIB_BIASREFBUF((*(uint32_t *)ADC_FUSES_BIASREFBUF_ADDR >> ADC_FUSES_BIASREFBUF_Pos)) |
                ADC_CALIB_BIASCOMP((*(uint32_t *)ADC_FUSES_BIASCOMP_ADDR >> ADC_FUSES_BIASCOMP_Pos));

    if (!ADC->SYNCBUSY.bit.SWRST) {
        if (ADC->CTRLA.bit.ENABLE) {
            ADC->CTRLA.bit.ENABLE = 0;
            _watch_sync_adc();
        }
        ADC->CTRLA.bit.SWRST = 1;
    }
    _watch_sync_adc();

    if (USB->DEVICE.CTRLA.bit.ENABLE) {
        // if USB is enabled, we are running an 8 MHz clock.
        // divide by 16 for a 500kHz ADC clock.
        ADC->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV16_Val;
    } else {
        // otherwise it's 4 Mhz. divide by 8 for a 500kHz ADC clock.
        ADC->CTRLB.bit.PRESCALER = ADC_CTRLB_PRESCALER_DIV8_Val;
    }
    ADC->CALIB.reg = calib_reg;
    ADC->REFCTRL.bit.REFSEL = ADC_REFCTRL_REFSEL_INTVCC2_Val;
    ADC->INPUTCTRL.bit.MUXNEG = ADC_INPUTCTRL_MUXNEG_GND_Val;
    ADC->CTRLC.bit.RESSEL = ADC_CTRLC_RESSEL_16BIT_Val;
    ADC->AVGCTRL.bit.SAMPLENUM = ADC_AVGCTRL_SAMPLENUM_16_Val;
    ADC->SAMPCTRL.bit.SAMPLEN = 0;
    ADC->INTENSET.reg = ADC_INTENSET_RESRDY;
    ADC->CTRLA.bit.ENABLE = 1;
    _watch_sync_adc();
    // throw away one measurement after reference change (the channel doesn't matter).
    _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC);
}

void watch_enable_analog_input(const uint8_t pin) {
    gpio_set_pin_direction(pin, GPIO_DIRECTION_OFF);
    switch (pin) {
        case A0:
            gpio_set_pin_function(pin, PINMUX_PB04B_ADC_AIN12);
            break;
        case A1:
            gpio_set_pin_function(pin, PINMUX_PB01B_ADC_AIN9);
            break;
        case A2:
            gpio_set_pin_function(pin, PINMUX_PB02B_ADC_AIN10);
            break;
        case A3:
            gpio_set_pin_function(pin, PINMUX_PB03B_ADC_AIN11);
            break;
        case A4:
            gpio_set_pin_function(pin, PINMUX_PB00B_ADC_AIN8);
            break;
#ifdef TEMPSENSE
        case TEMPSENSE:
            gpio_set_pin_function(pin, PINMUX_PA03B_ADC_AIN1);
            break;
#endif
#ifdef IRSENSE
        case IRSENSE:
            gpio_set_pin_function(pin, PINMUX_PA04B_ADC_AIN4);
            break;
#endif
        default:
            return;
    }
}

uint16_t watch_get_analog_pin_level(const uint8_t pin) {
    switch (pin) {
        case A0:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN12_Val);
        case A1:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN9_Val);
        case A2:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN10_Val);
        case A3:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN11_Val);
        case A4:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN8_Val);
#ifdef TEMPSENSE
        case TEMPSENSE:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN1_Val);
#endif
#ifdef IRSENSE
        case IRSENSE:
            return _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_AIN4_Val);
#endif
            default:
            return 0;
    }
}

void watch_set_analog_num_samples(uint16_t samples) {
    // ignore any input that's not a power of 2 (i.e. only one bit set)
    if (__builtin_popcount(samples) != 1) return;
    // if only one bit is set, counting the trailing zeroes is equivalent to log2(samples)
    uint8_t sample_val = __builtin_ctz(samples);
    // make sure the desired value is within range and set it, if so.
    if (sample_val <= ADC_AVGCTRL_SAMPLENUM_1024_Val) {
        ADC->AVGCTRL.bit.SAMPLENUM = sample_val;
        _watch_sync_adc();
    }
}

void watch_set_analog_sampling_length(uint8_t cycles) {
    // for clarity the API asks the user how many cycles they want the measurement to take.
    // but the ADC always needs at least one cycle; it just wants to know how many *extra* cycles we want.
    // so we subtract one from the user-provided value, and clamp to the maximum.
    ADC->SAMPCTRL.bit.SAMPLEN = (cycles - 1) & 0x3F;
    _watch_sync_adc();
}

static inline uint32_t _watch_adc_get_reference_voltage(const watch_adc_reference_voltage reference) {
    switch (reference) {
        case ADC_REFERENCE_INTREF:
            return ADC_REFCTRL_REFSEL_INTREF_Val;
            break;
        case ADC_REFERENCE_VCC_DIV1POINT6:
            return ADC_REFCTRL_REFSEL_INTVCC0_Val;
            break;
        case ADC_REFERENCE_VCC_DIV2:
            return ADC_REFCTRL_REFSEL_INTVCC1_Val;
            break;
        case ADC_REFERENCE_VCC:
            return ADC_REFCTRL_REFSEL_INTVCC2_Val;
            break;
    }

    return 0;
}

void watch_set_analog_reference_voltage(watch_adc_reference_voltage reference) {
    ADC->CTRLA.bit.ENABLE = 0;

    if (reference == ADC_REFERENCE_INTREF) SUPC->VREF.bit.VREFOE = 1;
    else SUPC->VREF.bit.VREFOE = 0;

    ADC->REFCTRL.bit.REFSEL = _watch_adc_get_reference_voltage(reference);
    ADC->CTRLA.bit.ENABLE = 1;
    _watch_sync_adc();
    // throw away one measurement after reference change (the channel doesn't matter).
    _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC);
}

uint16_t watch_get_vcc_voltage(void) {
    // stash the previous reference so we can restore it when we're done.
    uint8_t oldref = ADC->REFCTRL.bit.REFSEL;

    // if we weren't already using the internal reference voltage, select it now.
    if (oldref != ADC_REFERENCE_INTREF) watch_set_analog_reference_voltage(ADC_REFERENCE_INTREF);

    // get the data
    uint32_t raw_val = _watch_get_analog_value(ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC_Val);

    // restore the old reference, if needed.
    if (oldref != ADC_REFERENCE_INTREF) watch_set_analog_reference_voltage(oldref);

    return (uint16_t)((raw_val * 1000) / (1024 * 1 << ADC->AVGCTRL.bit.SAMPLENUM));
}

inline void watch_disable_analog_input(const uint8_t pin) {
    gpio_set_pin_function(pin, GPIO_PIN_FUNCTION_OFF);
}

inline void watch_disable_adc(void) {
    ADC->CTRLA.bit.ENABLE = 0;
    _watch_sync_adc();

    MCLK->APBCMASK.reg &= ~MCLK_APBCMASK_ADC;
}
