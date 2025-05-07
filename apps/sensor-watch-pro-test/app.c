#include <stdio.h>
#include <string.h>
#include "watch.h"
#include "spiflash.h"

bool has_ticked = false;
extern struct io_descriptor *uart_io;

// array of lcd pins from pins.h
const uint8_t lcd_pins[] = {
    SLCD26, // SEG23
    SLCD25, // SEG22
    SLCD24, // SEG21
    SLCD23, // SEG20
    SLCD22, // SEG19
    SLCD21, // SEG18
    SLCD20, // SEG17
    SLCD19, // SEG16
    SLCD18, // SEG15
    SLCD17, // SEG14
    SLCD16, // SEG13
    SLCD15, // SEG12
    SLCD14, // SEG11
    SLCD13, // SEG10
    SLCD12, // SEG9
    SLCD11, // SEG8
    SLCD10, // SEG7
    SLCD9,  // SEG6
    SLCD8,  // SEG5
    SLCD7,  // SEG4
    SLCD6,  // SEG3
    SLCD5,  // SEG2
    SLCD4,  // SEG1
    SLCD3,  // SEG0
    SLCD2,  // COM2
    SLCD1,  // COM1
    SLCD0,  // COM0
};

void cb_tick(void);
void cb_tick(void) {
    has_ticked = true;
    watch_rtc_disable_periodic_callback(8);
}

void pass_if(bool passed);
void pass_if(bool passed) {
    if (passed) {
        watch_set_led_green();
        delay_ms(100);
        watch_set_led_off();
    } else {
        watch_set_led_red();
        delay_ms(100);
        watch_set_led_off();
    }
}

void app_init(void) {
}

void app_wake_from_backup(void) {
}

static void enable_irda_uart() {
    gpio_set_pin_direction(IR_ENABLE, GPIO_DIRECTION_OUT);
    gpio_set_pin_level(IR_ENABLE, false);

    SERCOM_USART_CTRLA_Type ctrla;
    SERCOM_USART_CTRLB_Type ctrlb;
    ctrla.reg = SERCOM_USART_CTRLA_DORD | SERCOM_USART_CTRLA_MODE(1);
    ctrlb.reg = SERCOM_USART_CTRLB_CHSIZE(0) | SERCOM_USART_CTRLB_ENC;

    MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM0;
    GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].reg = GCLK_PCHCTRL_GEN(0) | GCLK_PCHCTRL_CHEN;

    while (0 == (GCLK->PCHCTRL[SERCOM0_GCLK_ID_CORE].reg & GCLK_PCHCTRL_CHEN));

	usart_sync_init(&USART_0, SERCOM0, (void *)NULL);

    SERCOM0->USART.CTRLA.reg &= ~SERCOM_USART_CTRLA_ENABLE;

    gpio_set_pin_direction(IRSENSE, GPIO_DIRECTION_IN);
    gpio_set_pin_function(IRSENSE, PINMUX_PA04D_SERCOM0_PAD0);
    ctrla.reg |= SERCOM_USART_CTRLA_RXPO(0);
    ctrlb.reg |= SERCOM_USART_CTRLB_RXEN;

    SERCOM0->USART.CTRLA.reg = ctrla.reg;
    SERCOM0->USART.CTRLB.reg = ctrlb.reg;

    if (hri_usbdevice_get_CTRLA_ENABLE_bit(USB)) {
        uint64_t br = 65536 - ((65536 * 16.0f * 600) / 8000000);
        SERCOM0->USART.BAUD.reg = (uint16_t)br;
    } else {
        uint64_t br = 65536 - ((65536 * 16.0f * 600) / 4000000);
        SERCOM0->USART.BAUD.reg = (uint16_t)br;
    }

    SERCOM0->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;

	usart_sync_enable(&USART_0);
    usart_sync_get_io_descriptor(&USART_0, &uart_io);
}

void app_setup(void) {
    // Set up tick for RTC test
    watch_rtc_register_periodic_callback(cb_tick, 8);

    // Set up UART for communication with tester
    enable_irda_uart();

    // Set up LED pins
    watch_enable_leds();
    watch_enable_buzzer();

    // Set up buttons with pull-down resistors
    gpio_set_pin_direction(BTN_ALARM, GPIO_DIRECTION_IN);
    gpio_set_pin_pull_mode(BTN_ALARM, GPIO_PULL_DOWN);
    gpio_set_pin_direction(BTN_LIGHT, GPIO_DIRECTION_IN);
    gpio_set_pin_pull_mode(BTN_LIGHT, GPIO_PULL_DOWN);
    gpio_set_pin_direction(BTN_MODE, GPIO_DIRECTION_IN);
    gpio_set_pin_pull_mode(BTN_MODE, GPIO_PULL_DOWN);

    // Set up ADC for thermistor and light sensor tests
    watch_enable_adc();
    watch_enable_analog_input(TEMPSENSE);
    // Pin A0 is the thermistor enable pin
    gpio_set_pin_direction(TS_ENABLE, GPIO_DIRECTION_OUT);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

static bool test_i2c(void) {
    watch_enable_i2c();
    uint16_t device_id = watch_i2c_read8(0x48, 0x0F);
    printf("%d\n", device_id);

    return device_id == 0x75;
}

static bool test_spi(void) {
	gpio_set_pin_level(A3, true);
	gpio_set_pin_direction(A3, GPIO_DIRECTION_OUT);
    watch_enable_spi();
    delay_ms(10);

    watch_set_pin_level(A3, false);
    delay_ms(10);
    uint8_t read_status_response[3] = {0};
    bool ok = spi_flash_read_command(0x9F, read_status_response, 3);
    watch_set_pin_level(A3, true);
    printf("%d %d %d\n", read_status_response[0], read_status_response[1], read_status_response[2]);

    return (read_status_response[0] == 0xC8 && read_status_response[1] == 0x40 && read_status_response[2] == 0x13);
}

bool app_loop(void) {
    uint8_t buf[5] = {0};
    watch_storage_read(10, 0, buf, 4);
    printf("%s\n", (const char *)buf);

    if (strcmp((const char *)buf, "BEEP") == 0) {
        watch_set_led_yellow();
        watch_buzzer_play_note(BUZZER_NOTE_C5, 150);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 25);
        watch_buzzer_play_note(BUZZER_NOTE_E5, 150);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 25);
        watch_buzzer_play_note(BUZZER_NOTE_G5, 150);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 25);
        watch_buzzer_play_note(BUZZER_NOTE_C6, 150);

        watch_storage_erase(10);
        delay_ms(10);
        watch_storage_write(10, 0, (const char *)"9PIN", 4);
        watch_storage_sync();
        watch_storage_read(10, 0, buf, 4);
        delay_ms(10);
        if(strcmp((const char *)buf, (const char *)"9PIN") == 0) {
            watch_set_led_off();
            while(1);
        }
    }

    if (strcmp((const char *)buf, "9PIN") == 0) {
        bool i2c_passed = test_i2c();
        bool spi_passed = test_spi();

        if (i2c_passed && spi_passed) {
            watch_storage_erase(10);
            delay_ms(10);
            watch_storage_write(10, 0, (const char *)"PASS", 4);
            watch_storage_sync();
            watch_storage_read(10, 0, buf, 4);
            delay_ms(10);

            if(strcmp((const char *)buf, (const char *)"PASS") == 0) {
                gpio_set_pin_direction(A0, GPIO_DIRECTION_OUT);
                gpio_set_pin_level(A0, true);
            }
        } else if (i2c_passed) {
            // SPI failed, RED indicator
            watch_set_led_color_rgb(128, 0, 0);
        } else if (spi_passed) {
            // I2C failed, BLUE indicator
            watch_set_led_color_rgb(0, 0, 128);
        } else {
            // both failed, PURPLE indicator
            watch_set_led_color_rgb(64, 0, 128);
        }

        while(1);
    }

    if(strcmp((const char *)buf, (const char *)"PASS") == 0) {
        watch_set_led_green();
        while(1);
    }

    char char_received = watch_uart_getc();

    if (char_received) {
        switch (char_received) {
            // - [X] RTC
            case 'R':
                pass_if(has_ticked);
                break;
            // - [X] LCD pin continuity
            case 'O':
                // Set all LCD pins high
                for (int i = 0; i < 27; i++) {
                    gpio_set_pin_function(lcd_pins[i], GPIO_PIN_FUNCTION_OFF);
                    gpio_set_pin_direction(lcd_pins[i], GPIO_DIRECTION_OUT);
                    gpio_set_pin_level(lcd_pins[i], true);
                }
                // It is the tester's responsibility to check that the pins are high
                break;
            case 'P':
                // Set all LCD pins low
                for (int i = 0; i < 27; i++) {
                    gpio_set_pin_function(lcd_pins[i], GPIO_PIN_FUNCTION_OFF);
                    gpio_set_pin_direction(lcd_pins[i], GPIO_DIRECTION_OUT);
                    gpio_set_pin_level(lcd_pins[i], false);
                }
                // It is the tester's responsibility to check that the pins are low
                break;
            // - [X] LCD pin bridging
            case 'Q':
                {
                    bool passed = true;
                    // Pull all LCD pins up
                    for (int i = 0; i < 27; i++) {
                        gpio_set_pin_function(lcd_pins[i], GPIO_PIN_FUNCTION_OFF);
                        gpio_set_pin_direction(lcd_pins[i], GPIO_DIRECTION_IN);
                        gpio_set_pin_pull_mode(lcd_pins[i], GPIO_PULL_UP);
                    }
                    // SEG23 is adjacent to the green LED.
                    // setting the LED green drives GREEN low.
                    watch_set_led_green();
                    if (!gpio_get_pin_level(SLCD26)) {
                        // If SEG23 is low, then it must be bridged to the green pin
                        pass_if(false);
                    }
                    // SEG13 is adjacent to the blue LED.
                    // setting the LED blue drives BLUE low.
                    watch_set_led_color_rgb(0, 0, 255);
                    if (!gpio_get_pin_level(SLCD16)) {
                        // If SEG13 is low, then it must be bridged to the blue pin
                        pass_if(false);
                    }
                    // SEG12 is adjacent to the red LED.
                    // setting the LED red drives RED low.
                    watch_set_led_red();
                    if (!gpio_get_pin_level(SLCD15)) {
                        // If SEG12 is low, then it must be bridged to the red pin
                        pass_if(false);
                    }
                    watch_set_led_off();
                    // After this, all LCD pins are adjacent. Test if each pin is bridged to the previous one.
                    for (int i = 1; i < 27; i++) {
                        gpio_set_pin_direction(lcd_pins[i - 1], GPIO_DIRECTION_OUT);
                        gpio_set_pin_level(lcd_pins[i - 1], false);
                        if (!gpio_get_pin_level(lcd_pins[i])) {
                            passed = false;
                            break;
                        }
                        gpio_set_pin_direction(lcd_pins[i - 1], GPIO_DIRECTION_IN);
                        gpio_set_pin_pull_mode(lcd_pins[i - 1], GPIO_PULL_UP);
                    }
                    // Special cases:
                    // SLCD0 neighbors VCC
                    gpio_set_pin_direction(SLCD0, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD0, GPIO_PULL_DOWN);
                    if (gpio_get_pin_level(SLCD0)) {
                        passed = false;
                    }
                    // SLCD18 neighbors VCC
                    gpio_set_pin_direction(SLCD18, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD18, GPIO_PULL_DOWN);
                    if (gpio_get_pin_level(SLCD18)) {
                        passed = false;
                    }
                    // SLCD26 neighbors USB_N
                    gpio_set_pin_direction(GPIO(GPIO_PORTA, 24), GPIO_DIRECTION_OUT);
                    gpio_set_pin_level(GPIO(GPIO_PORTA, 24), true);
                    gpio_set_pin_direction(SLCD26, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD26, GPIO_PULL_DOWN);
                    // if SLCD26 is high, then it is bridged to USB_N
                    if (gpio_get_pin_level(SLCD26)) {
                        passed = false;
                    }
                    // SLCD11 neighbors VLCD
                    watch_enable_display();
                    delay_ms(50);
                    gpio_set_pin_function(SLCD11, GPIO_PIN_FUNCTION_OFF);
                    gpio_set_pin_direction(SLCD11, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD11, GPIO_PULL_DOWN);
                    if (gpio_get_pin_level(SLCD11)) {
                        passed = false;
                    }
                    for (int i = 0; i < 27; i++) {
                        gpio_set_pin_function(lcd_pins[i], GPIO_PIN_FUNCTION_OFF);
                        gpio_set_pin_direction(lcd_pins[i], GPIO_DIRECTION_IN);
                        gpio_set_pin_pull_mode(lcd_pins[i], GPIO_PULL_OFF);
                    }

                    pass_if(passed);
                }
                break;
            // - [X] Thermistor high
            case 'U':
                // Set TS_ENABLE high and read the value of TEMPSENSE via the ADC.
                // Pass if the value is near VCC.
                gpio_set_pin_level(TS_ENABLE, true);
                pass_if(watch_get_analog_pin_level(TEMPSENSE) > 65000);
                break;
            // - [X] Thermistor low
            case 'T':
            {
                // Set TS_ENABLE low and read the value of TEMPSENSE via the ADC.
                // Pass if the value is within the realm of reasonable temperatures.
                // 15000 is a few minutes in the freezer, 45000 is holding it a few feet above a stovetop
                gpio_set_pin_level(TS_ENABLE, false);
                uint16_t value = watch_get_analog_pin_level(TEMPSENSE);
                pass_if(value < 45000 && value > 15000);
            }
                break;
            // - [X] VLCD low
            case 'V':
                watch_enable_display();
                SLCD->CTRLA.bit.ENABLE = 0;
                while(SLCD->SYNCBUSY.bit.ENABLE);
                SLCD->CTRLC.bit.CTST = 0x0;
                SLCD->CTRLA.bit.ENABLE = 1;
                while(SLCD->SYNCBUSY.bit.ENABLE);
                break;
            // - [X] VLCD high
            case 'W':
                watch_enable_display();
                SLCD->CTRLA.bit.ENABLE = 0;
                while(SLCD->SYNCBUSY.bit.ENABLE);
                SLCD->CTRLC.bit.CTST = 0xD;
                SLCD->CTRLA.bit.ENABLE = 1;
                while(SLCD->SYNCBUSY.bit.ENABLE);
                break;
            /// TODO: LED
            case 'r':
                watch_set_led_color_rgb(255, 0, 0);
                delay_ms(100);
                watch_set_led_color_rgb(0, 0, 0);
                // It is the tester's responsibility to check the LED color.
                break;
            case 'g':
                watch_set_led_color_rgb(0, 255, 0);
                delay_ms(100);
                watch_set_led_color_rgb(0, 0, 0);
                // It is the tester's responsibility to check the LED color.
                break;
            case 'b':
                watch_set_led_color_rgb(0, 0, 255);
                delay_ms(100);
                watch_set_led_color_rgb(0, 0, 0);
                // It is the tester's responsibility to check the LED color.
                break;
            // - [X] Buttons
            case 'B':
                // Pass if all three buttons are low
                pass_if(!gpio_get_pin_level(BTN_ALARM) && !gpio_get_pin_level(BTN_LIGHT) && !gpio_get_pin_level(BTN_MODE));
                break;
            case 'L':
                // pass if BTN_LIGHT is high and the other two are low
                pass_if(gpio_get_pin_level(BTN_LIGHT) && !gpio_get_pin_level(BTN_ALARM) && !gpio_get_pin_level(BTN_MODE));
                break;
            case 'A':
                // pass if BTN_ALARM is high and the other two are low
                pass_if(gpio_get_pin_level(BTN_ALARM) && !gpio_get_pin_level(BTN_LIGHT) && !gpio_get_pin_level(BTN_MODE));
                break;
            case 'M':
                // pass if BTN_MODE is high and the other two are low
                pass_if(gpio_get_pin_level(BTN_MODE) && !gpio_get_pin_level(BTN_ALARM) && !gpio_get_pin_level(BTN_LIGHT));
                break;

            // - [X] File system
            case 'F':
                watch_storage_erase(10);
                delay_ms(10);
                watch_storage_write(10, 0, (const char *)"BEEP", 4);
                watch_storage_sync();
                watch_storage_read(10, 0, buf, 4);
                delay_ms(10);
                // No need to do anything here; comparison with 'beep' happens at next loop invocation.
                break;
        }
    }

    return false;
}
