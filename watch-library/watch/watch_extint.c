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

void watch_enable_external_interrupts() {
    // Configure EIC to use GCLK3 (the 32.768 kHz crystal)
    hri_gclk_write_PCHCTRL_reg(GCLK, EIC_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK3_Val | (1 << GCLK_PCHCTRL_CHEN_Pos));
    // Enable AHB clock for the EIC
    hri_mclk_set_APBAMASK_EIC_bit(MCLK);
    // call HAL's external interrupt init function
    ext_irq_init();
}

void watch_disable_external_interrupts() {
    ext_irq_deinit();
    hri_mclk_clear_APBAMASK_EIC_bit(MCLK);
}

void watch_register_interrupt_callback(const uint8_t pin, ext_irq_cb_t callback, watch_interrupt_trigger trigger) {
    uint8_t config_index;
    uint8_t sense_pos;
    switch (pin) {
        case A0:
            // for EIC channels 8-15, we need to set the SENSE value in CONFIG[1]
            config_index = (WATCH_A0_EIC_CHANNEL > 7) ? 1 : 0;
            // either way the index in CONFIG[n] must be 0-7
            sense_pos = 4 * (WATCH_A0_EIC_CHANNEL % 8);
            break;
        case A1:
            config_index = (WATCH_A1_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_A1_EIC_CHANNEL % 8);
            break;
        case A2:
            config_index = (WATCH_A2_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_A2_EIC_CHANNEL % 8);
            break;
        case A3:
            config_index = (WATCH_A3_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_A3_EIC_CHANNEL % 8);
            break;
        case A4:
            config_index = (WATCH_A4_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_A4_EIC_CHANNEL % 8);
            break;
        case BTN_ALARM:
            // for the buttons, we need an internal pull-down.
            gpio_set_pin_pull_mode(pin, GPIO_PULL_DOWN);
            config_index = (WATCH_BTN_ALARM_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_BTN_ALARM_EIC_CHANNEL % 8);
            break;
        case BTN_LIGHT:
            gpio_set_pin_pull_mode(pin, GPIO_PULL_DOWN);
            config_index = (WATCH_BTN_LIGHT_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_BTN_LIGHT_EIC_CHANNEL % 8);
            break;
        case BTN_MODE:
            gpio_set_pin_pull_mode(pin, GPIO_PULL_DOWN);
            config_index = (WATCH_BTN_MODE_EIC_CHANNEL > 7) ? 1 : 0;
            sense_pos = 4 * (WATCH_BTN_MODE_EIC_CHANNEL % 8);
            break;
        default:
            return;
    }

    gpio_set_pin_direction(pin, GPIO_DIRECTION_IN);
    gpio_set_pin_function(pin, GPIO_PIN_FUNCTION_A);

    // EIC configuration register is enable-protected, so we have to disable it first...
    if (hri_eic_get_CTRLA_reg(EIC, EIC_CTRLA_ENABLE)) {
        hri_eic_clear_CTRLA_ENABLE_bit(EIC);
        // ...and wait for it to synchronize.
        hri_eic_wait_for_sync(EIC, EIC_SYNCBUSY_ENABLE);
    }
    // now update the configuration...
    hri_eic_config_reg_t config = EIC->CONFIG[config_index].reg;
    config &= ~(7 << sense_pos);
    config |= trigger << (sense_pos);
    hri_eic_write_CONFIG_reg(EIC, config_index, config);
    // ...and re-enable the EIC
    hri_eic_set_CTRLA_ENABLE_bit(EIC);

    ext_irq_register(pin, callback);
}

inline void watch_register_button_callback(const uint8_t pin, ext_irq_cb_t callback) {
    watch_register_interrupt_callback(pin, callback, INTERRUPT_TRIGGER_RISING);
}

inline void watch_enable_buttons() {
    watch_enable_external_interrupts();
}
