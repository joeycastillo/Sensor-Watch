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

#include "watch_private.h"
#include "watch_private_cdc.h"
#include "watch_utility.h"
#include "tusb.h"

void _watch_init(void) {
    // disable the LED pin (it may have been enabled by the bootloader)
    watch_disable_digital_output(GPIO(GPIO_PORTA, 20));

    // RAM should be back-biased in STANDBY
    PM->STDBYCFG.bit.BBIASHS = 1;

    // Use switching regulator for lower power consumption.
    SUPC->VREG.bit.SEL = 1;

    // per Microchip datasheet clarification DS80000782,
    // work around silicon erratum 1.7.2, which causes the microcontroller to lock up on leaving standby:
    // request that the voltage regulator run in standby, and also that it switch to PL0.
    SUPC->VREG.bit.RUNSTDBY = 1;
    SUPC->VREG.bit.STDBYPL0 = 1;
    while(!SUPC->STATUS.bit.VREGRDY); // wait for voltage regulator to become ready

    // check the battery voltage...
    watch_enable_adc();
    uint16_t battery_voltage = watch_get_vcc_voltage();
    watch_disable_adc();
    // ...because we can enable the more efficient low power regulator if the system voltage is > 2.5V
    // still, enable LPEFF only if the battery voltage is comfortably above this threshold.
    if (battery_voltage >= 2700) {
        SUPC->VREG.bit.LPEFF = 1;
    } else {
        SUPC->VREG.bit.LPEFF = 0;
    }

    // set up the brownout detector (low battery warning)
    NVIC_DisableIRQ(SYSTEM_IRQn);
    NVIC_ClearPendingIRQ(SYSTEM_IRQn);
    NVIC_EnableIRQ(SYSTEM_IRQn);
    SUPC->BOD33.bit.ENABLE = 0;     // BOD33 must be disabled to change its configuration
    SUPC->BOD33.bit.VMON = 0;       // Monitor VDD in active and standby mode
    SUPC->BOD33.bit.ACTCFG = 1;     // Enable sampling mode when active
    SUPC->BOD33.bit.RUNSTDBY = 1;   // Enable sampling mode in standby
    SUPC->BOD33.bit.STDBYCFG = 1;   // Run in standby
    SUPC->BOD33.bit.RUNBKUP = 0;    // Don't run in backup mode
    SUPC->BOD33.bit.PSEL = 0x9;     // Check battery level every second (we'll change this before entering sleep)
    SUPC->BOD33.bit.LEVEL = 34;     // Detect brownout at 2.6V (1.445V + level * 34mV)
    SUPC->BOD33.bit.ACTION = 0x2;   // Generate an interrupt when BOD33 is triggered
    SUPC->BOD33.bit.HYST = 0;       // Disable hysteresis
    while(!SUPC->STATUS.bit.B33SRDY); // wait for BOD33 to sync

    // Enable interrupt on BOD33 detect
    SUPC->INTENSET.bit.BOD33DET = 1;
    SUPC->BOD33.bit.ENABLE = 1;

    // External wake depends on RTC; calendar is a required module.
    _watch_rtc_init();

    // set up state
    btn_alarm_callback = NULL;
    a2_callback = NULL;
    a4_callback = NULL;
}

static inline void _watch_wait_for_entropy() {
    while (!hri_trng_get_INTFLAG_reg(TRNG, TRNG_INTFLAG_DATARDY));
}

// this function is called by arc4random to get entropy for random number generation.
int getentropy(void *buf, size_t buflen);

// let's use the SAM L22's true random number generator to seed the PRNG!
int getentropy(void *buf, size_t buflen) {
    hri_mclk_set_APBCMASK_TRNG_bit(MCLK);
    hri_trng_set_CTRLA_ENABLE_bit(TRNG);

    size_t i = 0;
    while(i < buflen / 4) {
        _watch_wait_for_entropy();
        ((uint32_t *)buf)[i++] = hri_trng_read_DATA_reg(TRNG);
    }

    // but what if they asked for an awkward number of bytes?
    if (buflen % 4) {
        // all good: let's fill in one, two or three bytes at the end of the buffer.
        _watch_wait_for_entropy();
        uint32_t last_little_bit = hri_trng_read_DATA_reg(TRNG);
        for(size_t j = 0; j <= (buflen % 4); j++) {
            ((uint8_t *)buf)[i * 4 + j] = (last_little_bit >> (j * 8)) & 0xFF;
        }
    }

    watch_disable_TRNG();
    hri_mclk_clear_APBCMASK_TRNG_bit(MCLK);

    return 0;
}

void watch_disable_TRNG() {
    // per Microchip datasheet clarification DS80000782,
    // silicon erratum 1.16.1 indicates that the TRNG may leave internal components powered after being disabled.
    // the workaround is to disable the TRNG by clearing the control register, twice.
    hri_trng_write_CTRLA_reg(TRNG, 0);
    hri_trng_write_CTRLA_reg(TRNG, 0);
}


void _watch_enable_tcc(void) {
    // clock TCC0 with the main clock (8 MHz) and enable the peripheral clock.
    hri_gclk_write_PCHCTRL_reg(GCLK, TCC0_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK0_Val | GCLK_PCHCTRL_CHEN);
    hri_mclk_set_APBCMASK_TCC0_bit(MCLK);
    // disable and reset TCC0.
    hri_tcc_clear_CTRLA_ENABLE_bit(TCC0);
    hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_ENABLE);
    hri_tcc_write_CTRLA_reg(TCC0, TCC_CTRLA_SWRST);
    hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_SWRST);
    // divide the clock down to 1 MHz
    if (hri_usbdevice_get_CTRLA_ENABLE_bit(USB)) {
        // if USB is enabled, we are running an 8 MHz clock.
        hri_tcc_write_CTRLA_reg(TCC0, TCC_CTRLA_PRESCALER_DIV8);
    } else {
        // otherwise it's 4 Mhz.
        hri_tcc_write_CTRLA_reg(TCC0, TCC_CTRLA_PRESCALER_DIV4);
    }
    // We're going to use normal PWM mode, which means period is controlled by PER, and duty cycle is controlled by
    // each compare channel's value:
    //  * Buzzer tones are set by setting PER to the desired period for a given frequency, and CC[1] to half of that
    //    period (i.e. a square wave with a 50% duty cycle).
    //  * LEDs on CC[2] and CC[3] can be set to any value from 0 (off) to PER (fully on).
    hri_tcc_write_WAVE_reg(TCC0, TCC_WAVE_WAVEGEN_NPWM);
    #ifdef WATCH_INVERT_LED_POLARITY
    // This is here for the dev board, which uses a common anode LED (instead of common cathode like the actual watch).
    hri_tcc_set_WAVE_reg(TCC0, (1 << (TCC_WAVE_POL0_Pos + WATCH_RED_TCC_CHANNEL)) |
                               (1 << (TCC_WAVE_POL0_Pos + WATCH_GREEN_TCC_CHANNEL)));
    #endif
    // The buzzer will set the period depending on the tone it wants to play, but we have to set some period here to
    // get the LED working. Almost any period will do, tho it should be below 20000 (i.e. 50 Hz) to avoid flickering.
    hri_tcc_write_PER_reg(TCC0, 1024);
    // Set the duty cycle of all pins to 0: LED's off, buzzer not buzzing.
    hri_tcc_write_CC_reg(TCC0, WATCH_BUZZER_TCC_CHANNEL, 0);
    hri_tcc_write_CC_reg(TCC0, WATCH_RED_TCC_CHANNEL, 0);
    hri_tcc_write_CC_reg(TCC0, WATCH_GREEN_TCC_CHANNEL, 0);
    // Enable the TCC
    hri_tcc_set_CTRLA_ENABLE_bit(TCC0);
    hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_ENABLE);

    // enable LED PWM pins (the LED driver assumes if the TCC is on, the pins are enabled)
    gpio_set_pin_direction(RED, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(RED, WATCH_RED_TCC_PINMUX);
    gpio_set_pin_direction(GREEN, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(GREEN, WATCH_GREEN_TCC_PINMUX);
}

void _watch_disable_tcc(void) {
    // disable all PWM pins
    gpio_set_pin_direction(BUZZER, GPIO_DIRECTION_OFF);
    gpio_set_pin_function(BUZZER, GPIO_PIN_FUNCTION_OFF);
    gpio_set_pin_direction(RED, GPIO_DIRECTION_OFF);
    gpio_set_pin_function(RED, GPIO_PIN_FUNCTION_OFF);
    gpio_set_pin_direction(GREEN, GPIO_DIRECTION_OFF);
    gpio_set_pin_function(GREEN, GPIO_PIN_FUNCTION_OFF);

    // disable the TCC
    hri_tcc_clear_CTRLA_ENABLE_bit(TCC0);
    hri_mclk_clear_APBCMASK_TCC0_bit(MCLK);
}    

void _watch_enable_tc0(void) {
    // before we init TinyUSB, we are going to need a periodic callback to handle TinyUSB tasks.
    // TC2 and TC3 are reserved for devices on the 9-pin connector, so let's use TC0.
    // clock TC0 with the 8 MHz clock on GCLK0.
    hri_gclk_write_PCHCTRL_reg(GCLK, TC0_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK0_Val | GCLK_PCHCTRL_CHEN);
    // and enable the peripheral clock.
    hri_mclk_set_APBCMASK_TC0_bit(MCLK);
    // disable and reset TC0.
    hri_tc_clear_CTRLA_ENABLE_bit(TC0);
    hri_tc_wait_for_sync(TC0, TC_SYNCBUSY_ENABLE);
    hri_tc_write_CTRLA_reg(TC0, TC_CTRLA_SWRST);
    hri_tc_wait_for_sync(TC0, TC_SYNCBUSY_SWRST);
    hri_tc_write_CTRLA_reg(TC0, TC_CTRLA_PRESCALER_DIV1024 | // divide the 8 MHz clock by 1024 to count at 7812.5 Hz
                                TC_CTRLA_MODE_COUNT8 |       // count in 8-bit mode
                                TC_CTRLA_RUNSTDBY);          // run in standby, just in case we figure that out
    hri_tccount8_write_PER_reg(TC0, 10);                     // 7812.5 Hz / 10 = 781.125 Hz
    // set an interrupt on overflow; this will call TC0_Handler below.
    hri_tc_set_INTEN_OVF_bit(TC0);

    // set priority higher than TC1
    NVIC_SetPriority(TC0_IRQn, 5);
    NVIC_ClearPendingIRQ(TC0_IRQn);
    NVIC_EnableIRQ(TC0_IRQn);

    // Start the timer
    hri_tc_set_CTRLA_ENABLE_bit(TC0);
}

void _watch_disable_tc0(void) {
    NVIC_DisableIRQ(TC0_IRQn);
    NVIC_ClearPendingIRQ(TC0_IRQn);
    hri_tc_clear_CTRLA_ENABLE_bit(TC0);
    hri_tc_wait_for_sync(TC0, TC_SYNCBUSY_ENABLE);
    hri_tc_write_CTRLA_reg(TC0, TC_CTRLA_SWRST);
    hri_tc_wait_for_sync(TC0, TC_SYNCBUSY_SWRST);
}

void _watch_enable_tc1(void) {
    hri_gclk_write_PCHCTRL_reg(GCLK, TC1_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK0_Val | GCLK_PCHCTRL_CHEN);
    // and enable the peripheral clock.
    hri_mclk_set_APBCMASK_TC1_bit(MCLK);
    // disable and reset TC1.
    hri_tc_clear_CTRLA_ENABLE_bit(TC1);
    hri_tc_wait_for_sync(TC1, TC_SYNCBUSY_ENABLE);
    hri_tc_write_CTRLA_reg(TC1, TC_CTRLA_SWRST);
    hri_tc_wait_for_sync(TC1, TC_SYNCBUSY_SWRST);
    hri_tc_write_CTRLA_reg(TC1, TC_CTRLA_PRESCALER_DIV1024 | // divide the 8 MHz clock by 1024 to count at 7812.5 Hz
                                TC_CTRLA_MODE_COUNT8 |       // count in 8-bit mode
                                TC_CTRLA_RUNSTDBY);          // run in standby, just in case we figure that out
    hri_tccount8_write_PER_reg(TC1, 20);                     // 7812.5 Hz / 50 = 156.25 Hz
    // set an interrupt on overflow; this will call TC1_Handler below.
    hri_tc_set_INTEN_OVF_bit(TC1);

    // set priority lower than TC0
    NVIC_SetPriority(TC1_IRQn, 6);
    NVIC_ClearPendingIRQ(TC1_IRQn);
    NVIC_EnableIRQ(TC1_IRQn);

    // Start the timer
    hri_tc_set_CTRLA_ENABLE_bit(TC1);
}

void _watch_disable_tc1(void) {
    NVIC_DisableIRQ(TC1_IRQn);
    NVIC_ClearPendingIRQ(TC1_IRQn);
    hri_tc_clear_CTRLA_ENABLE_bit(TC1);
    hri_tc_wait_for_sync(TC1, TC_SYNCBUSY_ENABLE);
    hri_tc_write_CTRLA_reg(TC1, TC_CTRLA_SWRST);
    hri_tc_wait_for_sync(TC1, TC_SYNCBUSY_SWRST);
}

void TC0_Handler(void) {
    tud_task();
    TC0->COUNT8.INTFLAG.reg |= TC_INTFLAG_OVF;
}

void TC1_Handler(void) {
    cdc_task();
    TC1->COUNT8.INTFLAG.reg |= TC_INTFLAG_OVF;
}

void _watch_enable_usb(void) {
    // disable USB, just in case.
    hri_usb_clear_CTRLA_ENABLE_bit(USB);

    // bump clock up to 8 MHz
    hri_oscctrl_write_OSC16MCTRL_FSEL_bf(OSCCTRL, OSCCTRL_OSC16MCTRL_FSEL_8_Val);

    // reset flags and disable DFLL
    OSCCTRL->INTFLAG.reg = OSCCTRL_INTFLAG_DFLLRDY;
    OSCCTRL->DFLLCTRL.reg = 0;
    while (!(OSCCTRL->STATUS.reg & OSCCTRL_STATUS_DFLLRDY));

    // set the coarse and fine values to speed up frequency lock.
    uint32_t coarse =(*((uint32_t *)NVMCTRL_OTP5)) >> 26;
    OSCCTRL->DFLLVAL.reg = OSCCTRL_DFLLVAL_COARSE(coarse) |
                           OSCCTRL_DFLLVAL_FINE(0x200);
    // set coarse and fine steps, and multiplier (48 MHz = 32768 Hz * 1465)
    OSCCTRL->DFLLMUL.reg = OSCCTRL_DFLLMUL_CSTEP( 1 ) |
                           OSCCTRL_DFLLMUL_FSTEP( 1 ) |
                           OSCCTRL_DFLLMUL_MUL( 1465 );
    // set closed loop mode, chill cycle disable and USB clock recovery mode, and enable the DFLL.
    OSCCTRL->DFLLCTRL.reg = OSCCTRL_DFLLCTRL_MODE | OSCCTRL_DFLLCTRL_CCDIS | OSCCTRL_DFLLCTRL_ONDEMAND | OSCCTRL_DFLLCTRL_RUNSTDBY | OSCCTRL_DFLLCTRL_USBCRM | OSCCTRL_DFLLCTRL_ENABLE;
    while (!(OSCCTRL->STATUS.reg & OSCCTRL_STATUS_DFLLRDY));

    // assign DFLL to GCLK1
    GCLK->GENCTRL[1].reg = GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_DFLL48M) | GCLK_GENCTRL_DIV(1) | GCLK_GENCTRL_GENEN;// | GCLK_GENCTRL_OE;
    while (GCLK->SYNCBUSY.bit.GENCTRL1); // wait for generator control 1 to sync

    // assign GCLK1 to USB
    hri_gclk_write_PCHCTRL_reg(GCLK, USB_GCLK_ID, GCLK_PCHCTRL_GEN_GCLK1_Val | GCLK_PCHCTRL_CHEN);
    hri_mclk_set_AHBMASK_USB_bit(MCLK);
    hri_mclk_set_APBBMASK_USB_bit(MCLK);

    // USB Pin Init
    gpio_set_pin_direction(PIN_PA24, GPIO_DIRECTION_OUT);
    gpio_set_pin_level(PIN_PA24, false);
    gpio_set_pin_pull_mode(PIN_PA24, GPIO_PULL_OFF);
    gpio_set_pin_direction(PIN_PA25, GPIO_DIRECTION_OUT);
    gpio_set_pin_level(PIN_PA25, false);
    gpio_set_pin_pull_mode(PIN_PA25, GPIO_PULL_OFF);

    gpio_set_pin_function(PIN_PA24, PINMUX_PA24G_USB_DM);
    gpio_set_pin_function(PIN_PA25, PINMUX_PA25G_USB_DP);

    _watch_enable_tc0();

    tusb_init();

    _watch_enable_tc1();
}

void USB_Handler(void) {
    tud_int_handler(0);
}

// USB Descriptors and tinyUSB callbacks follow.

/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

//--------------------------------------------------------------------+
// Device Descriptors
//--------------------------------------------------------------------+
tusb_desc_device_t const desc_device =
{
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,

    // Use Interface Association Descriptor (IAD) for CDC
    // As required by USB Specs IAD's subclass must be common class (2) and protocol must be IAD (1)
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,

    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,

    .idVendor           = 0x1209,
    .idProduct          = 0x2151,
    .bcdDevice          = 0x0100,

    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,

    .bNumConfigurations = 0x01
};

// Invoked when received GET DEVICE DESCRIPTOR
// Application return pointer to descriptor
uint8_t const * tud_descriptor_device_cb(void) {
  return (uint8_t const *) &desc_device;
}

//--------------------------------------------------------------------+
// Configuration Descriptor
//--------------------------------------------------------------------+

enum {
  ITF_NUM_CDC = 0,
  ITF_NUM_CDC_DATA,
  ITF_NUM_TOTAL
};

#define CONFIG_TOTAL_LEN    (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN)

#define EPNUM_CDC_NOTIF   0x81
#define EPNUM_CDC_OUT     0x02
#define EPNUM_CDC_IN      0x82


uint8_t const desc_fs_configuration[] = {
  // Config number, interface count, string index, total length, attribute, power in mA
  TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, 100),

  // Interface number, string index, EP notification address and size, EP data address (out, in) and size.
  TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, 4, EPNUM_CDC_NOTIF, 8, EPNUM_CDC_OUT, EPNUM_CDC_IN, 64),
};

// Invoked when received GET CONFIGURATION DESCRIPTOR
// Application return pointer to descriptor
// Descriptor contents must exist long enough for transfer to complete
uint8_t const * tud_descriptor_configuration_cb(uint8_t index) {
    (void) index; // for multiple configurations
    return desc_fs_configuration;
}

//--------------------------------------------------------------------+
// String Descriptors
//--------------------------------------------------------------------+

// array of pointer to string descriptors
char const* string_desc_arr [] =
{
  (const char[]) { 0x09, 0x04 }, // 0: is supported language is English (0x0409)
  "TinyUSB",                     // 1: Manufacturer
  "TinyUSB Device",              // 2: Product
  "123456",                      // 3: Serials, should use chip ID
  "TinyUSB CDC",                 // 4: CDC Interface
};

static uint16_t _desc_str[32];

// Invoked when received GET STRING DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    (void) langid;

    uint8_t chr_count;

    if ( index == 0) {
        memcpy(&_desc_str[1], string_desc_arr[0], 2);
        chr_count = 1;
    } else {
        // Note: the 0xEE index string is a Microsoft OS 1.0 Descriptors.
        // https://docs.microsoft.com/en-us/windows-hardware/drivers/usbcon/microsoft-defined-usb-descriptors

        if ( !(index < sizeof(string_desc_arr)/sizeof(string_desc_arr[0])) ) return NULL;

        const char* str = string_desc_arr[index];

        // Cap at max char
        chr_count = strlen(str);
        if ( chr_count > 31 ) chr_count = 31;

        // Convert ASCII string into UTF-16
        for(uint8_t i=0; i<chr_count; i++)
        {
            _desc_str[1+i] = str[i];
        }
    }

    // first byte is length (including header), second byte is string type
    _desc_str[0] = (TUSB_DESC_STRING << 8 ) | (2*chr_count + 2);

    return _desc_str;
}
