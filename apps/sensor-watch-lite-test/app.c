#include <stdio.h>
#include <string.h>
#include "watch.h"

bool has_ticked = false;

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
        watch_uart_puts("P");
    } else {
        watch_uart_puts("F");
    }
}

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    // Set up tick for RTC test
    watch_rtc_register_periodic_callback(cb_tick, 8);

    // Set up UART for communication with tester
    watch_enable_uart(A4, A1, 19200);

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

    // Set up ADC for thermistor test    
    watch_enable_adc();
    watch_enable_analog_input(A2);
    // Pin A0 is the thermistor enable pin
    gpio_set_pin_direction(A0, GPIO_DIRECTION_OUT);

    watch_set_led_yellow();
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    uint8_t buf[5] = {0};
    watch_storage_read(0, 0, buf, 4);
    printf("%s\n", (const char *)buf);
    if (strcmp((const char *)buf, "PASS") == 0) {
        watch_buzzer_play_note(BUZZER_NOTE_C5, 150);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 25);
        watch_buzzer_play_note(BUZZER_NOTE_E5, 150);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 25);
        watch_buzzer_play_note(BUZZER_NOTE_G5, 150);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 25);
        watch_buzzer_play_note(BUZZER_NOTE_C6, 150);
        watch_set_led_green();
        return true;
    }

    char char_received = watch_uart_getc();

    if (char_received) {
        switch (char_received) {
            // - [X] UART echo
            case 'S':
                // Automatically passes if received by tester
                pass_if(true);
                break;
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
                pass_if(true);
                break;
            case 'P':
                // Set all LCD pins low
                for (int i = 0; i < 27; i++) {
                    gpio_set_pin_function(lcd_pins[i], GPIO_PIN_FUNCTION_OFF);
                    gpio_set_pin_direction(lcd_pins[i], GPIO_DIRECTION_OUT);
                    gpio_set_pin_level(lcd_pins[i], false);
                }
                // It is the tester's responsibility to check that the pins are low
                pass_if(true);
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
                    // SEG23 is adjacent to the red LED.
                    // setting the LED red drives RED low.
                    watch_set_led_red();
                    if (!gpio_get_pin_level(lcd_pins[0])) {
                        // If SEG23 is low, then it must be bridged to the red pin
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
                    // SLCD11 neighbors VCC
                    gpio_set_pin_direction(SLCD11, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD11, GPIO_PULL_DOWN);
                    if (gpio_get_pin_level(SLCD11)) {
                        passed = false;
                    }
                    // SLCD21 neighbors VCC
                    gpio_set_pin_direction(SLCD21, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD21, GPIO_PULL_DOWN);
                    if (gpio_get_pin_level(SLCD21)) {
                        passed = false;
                    }
                    watch_enable_display();
                    delay_ms(50);
                    // SLCD12 neighbors VLCD
                    gpio_set_pin_function(SLCD12, GPIO_PIN_FUNCTION_OFF);
                    gpio_set_pin_direction(SLCD12, GPIO_DIRECTION_IN);
                    gpio_set_pin_pull_mode(SLCD12, GPIO_PULL_DOWN);
                    if (gpio_get_pin_level(SLCD12)) {
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
                // Set A0 high and read the value of A2 via the ADC.
                // Pass if the value is near VCC.
                gpio_set_pin_level(A0, true);
                pass_if(watch_get_analog_pin_level(A2) > 65000);
                break;
            // - [X] Thermistor low
            case 'T':
                {
                    // Set A0 low and read the value of A2 via the ADC.
                    // Pass if the value is within the realm of reasonable temperatures.
                    // 15000 is a few minutes in the freezer, 45000 is holding it a few feet over
                    gpio_set_pin_level(A0, false);
                    uint16_t value = watch_get_analog_pin_level(A2);
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
            // - [X] Buttons
            case 'B':
                // Pass if all three buttons are low
                pass_if(!gpio_get_pin_level(BTN_ALARM) && !gpio_get_pin_level(BTN_LIGHT) && !gpio_get_pin_level(BTN_MODE));
                break;
            case 'L':
                // pass if BTN_LIGHT is high and the other two are low
                pass_if(gpio_get_pin_level(BTN_LIGHT) && !gpio_get_pin_level(BTN_ALARM) && !gpio_get_pin_level(BTN_MODE));
                watch_uart_puts("P");
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
                watch_storage_erase(0);
                watch_storage_write(0, 0, (const char *)"PASS", 4);
                watch_storage_sync();
                watch_storage_read(0, 0, buf, 4);
                delay_ms(10);
                pass_if(strcmp((const char *)buf, (const char *)"PASS") == 0);
                break;

            // - [ ] Buzzer
            case 'Z':
                // reset the board
                break;

        }
    }

    return false;
}
