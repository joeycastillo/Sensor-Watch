#include <stdio.h>
#include <string.h>
#include "app.h"

// these are implemented in main.c, just want to have access to them here.
void uart_putc(char c);
void uart_puts(char *s);

typedef enum ApplicationMode {
    MODE_HELLO = 0,
    MODE_THERE
} ApplicationMode;

typedef enum LightColor {
    COLOR_OFF = 0,
    COLOR_RED = 1,
    COLOR_GREEN = 2,
    COLOR_YELLOW = 3
} LightColor;

typedef struct ApplicationState {
    ApplicationMode mode;
    LightColor color;
} ApplicationState;

ApplicationState applicationState;

void cb_light_pressed() {
    applicationState.color = (applicationState.color + 1) % 4;
}

void cb_mode_pressed() {
    applicationState.mode = (applicationState.mode + 1) % 2;
}

/**
 * @brief the app_init function is like setup() in Arduino. It is called once when the
 * program begins. You should set pin modes and enable any peripherals you want to
 * set up (real-time clock, I2C, etc.)
 * 
 * @note If your app enters the ultra-low power BACKUP sleep mode, this function will 
 * be called again when it wakes from that deep sleep state. In this state, the RTC will
 * still be configured with the correct date and time.
 */
void app_init() {
    memset(&applicationState, 0, sizeof(applicationState));

    watch_enable_led(false);

    watch_enable_buttons();
    watch_register_button_callback(BTN_LIGHT, cb_light_pressed);
    watch_register_button_callback(BTN_MODE, cb_mode_pressed);

    watch_enable_display();
}

/**
 * @brief the app_prepare_for_sleep function is called before the watch goes into the
 * STANDBY sleep mode. In STANDBY mode, most peripherals are shut down, and no code
 * will run until the watch receives an interrupt (generally either the 1Hz tick or
 * a press on one of the buttons).
 */
void app_prepare_for_sleep() {
}

/**
 * @brief the app_wake_from_sleep function is called after the watch wakes from the
 * STANDBY sleep mode.
 */
void app_wake_from_sleep() {
}

/**
 * @brief the app_loop function is called once on app startup and then again each time
 * the watch STANDBY sleep mode.
 */
void app_loop() {
    switch (applicationState.color) {
        case COLOR_RED:
            watch_set_led_red();
            break;
        case COLOR_GREEN:
            watch_set_led_green();
            break;
        case COLOR_YELLOW:
            watch_set_led_yellow();
            break;
        default:
            applicationState.color = COLOR_OFF;
            watch_set_led_off();
    }
    switch (applicationState.mode) {
        case MODE_HELLO:
            watch_display_string("Hello", 5);
            break;
        case MODE_THERE:
            watch_display_string("there", 5);
            break;
    }
}
