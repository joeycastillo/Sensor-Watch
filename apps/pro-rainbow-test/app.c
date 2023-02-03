#include <stdio.h>
#include <string.h>
#include "watch.h"

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    watch_enable_leds();
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    static uint8_t red = 0;
    static uint8_t green = 0;
    static uint8_t blue = 255;
    static uint8_t phase = 0;

    switch (phase) {
        case 0:
            red++;
            if (red == 255) phase = 1;
            break;
        case 1:
            green++;
            if (green == 255) phase = 2;
            break;
        case 2:
            red--;
            if (red == 0) phase = 3;
            break;
        case 3:
            blue++;
            if (blue == 255) phase = 4;
            break;
        case 4:
            green--;
            if (green == 0) phase = 5;
            break;
        case 5:
            red++;
            if (red == 255) phase = 6;
            break;
        case 6:
            blue--;
            if (blue == 0) {
                phase = 1;
            }
            break;
    }

    watch_set_led_color_rgb(red, green, blue);
    delay_ms(2);

    return false;
}
