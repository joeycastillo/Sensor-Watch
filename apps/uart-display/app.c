#include <stdio.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"

/*
Beginnings of a program to take UART input and update the screen accordingly.
Use alongside a prpgram that communicates with the watch over the UART pins.
This CircuitPython script turns the LED red in response to pressing the LIGHT button,
and turns it off when the MODE button is pressed:

```
import board
import busio

uart = busio.UART(board.TX, board.RX, baudrate=19200)

while True:
    uart.write(b"\x00")
    data = uart.read(1)

    if data is not None:
        data_string = ''.join([chr(b) for b in data])
        print(data_string, end="")
        if data_string[0] == 'L':
            uart.write(b"R")
        elif data_string[0] == 'M':
            uart.write(b"O")
```
*/


char button_pressed = 0;

static void cb_light_pressed(void) {
    button_pressed = 'L';
}

static void cb_mode_pressed(void) {
    button_pressed = 'M';
}

static void cb_alarm_pressed(void) {
    button_pressed = 'A';
}

void app_init(void) {
    watch_enable_leds();
    watch_enable_buzzer();

    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_display();

    watch_enable_uart(A2, A1, 19200);
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    char buf[3];

    if (button_pressed) {
        sprintf(buf, "%c", button_pressed);
        printf("%s\n", buf);
        watch_uart_puts(buf);
        button_pressed = 0;
    }
    char char_received = watch_uart_getc();
    if (char_received) {
        switch (char_received) {
            case 'R':
                watch_set_led_red();
                break;
            case 'G':
                watch_set_led_green();
                break;
            case 'Y':
                watch_set_led_yellow();
                break;
            case 'O':
                watch_set_led_off();
                break;
            case 'U':
                // receive a display update?
                break;
        }
    }

    return false;
}
