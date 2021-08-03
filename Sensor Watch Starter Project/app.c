#include <stdio.h>
#include <string.h>
#include "watch.h"
#include "app.h"

//////////////////////////////////////////////////////////////////////////////////////////
// This section sets up types and storage for our application state.
// You can tear this out and replace it with whatever you want.
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
    uint8_t wake_count;
    bool debounce_wait;
} ApplicationState;

ApplicationState application_state;


//////////////////////////////////////////////////////////////////////////////////////////
// This section defines the callbacks for our button press events (implemented at bottom).
// Add any other callbacks you may need either here or in another file.
void cb_light_pressed();
void cb_mode_pressed();
void cb_alarm_pressed();


//////////////////////////////////////////////////////////////////////////////////////////
// This section contains the required functions for any watch app. You should tear out
// all the code in these functions when writing your app, but you must implement all
// of the functions, even if they are empty stubs. You can also replace the documentation
// lines with documentation that describes what your functions do!

/**
 * @brief the app_init function is called before anything else. Use it to set up any
 * internal data structures or application state required by your app.
 */
void app_init() {
    memset(&application_state, 0, sizeof(application_state));
}

/**
 * @brief the app_wake_from_deep_sleep function is only called if your app is waking from
 * the ultra-low power BACKUP sleep mode. You may have chosen to store some state in the
 * RTC's backup registers prior to entering this mode. You may restore that state here.
 *
 * @see watch_enter_deep_sleep()
 */
void app_wake_from_deep_sleep() {
    // TODO: deep sleep demo
}

/**
 * @brief the app_setup function is like setup() in Arduino. It is called once when the
 * program begins. You should set pin modes and enable any peripherals you want to
 * set up (real-time clock, I2C, etc.) Depending on your application, you may or may not
 * want to configure sensors on your sensor board here. For example, a low-power
 * accelerometer that will run at all times should be configured here, whereas you may
 * want to enable a more power-hungry environmental sensor only when you need it.
 *
 * @note If your app enters the ultra-low power BACKUP sleep mode, this function will
 * be called again when it wakes from that deep sleep state. In this state, the RTC will
 * still be configured with the correct date and time.
 */
void app_setup() {
    watch_enable_led(false); // enable LED with plain digital IO, not PWM

    watch_enable_buttons();
    watch_register_button_callback(BTN_LIGHT, cb_light_pressed);
    watch_register_button_callback(BTN_MODE, cb_mode_pressed);
    watch_register_button_callback(BTN_ALARM, cb_alarm_pressed);

    watch_enable_display();
}

/**
 * @brief the app_prepare_for_sleep function is called before the watch goes into the
 * STANDBY sleep mode. In STANDBY mode, most peripherals are shut down, and no code
 * will run until the watch receives an interrupt (generally either the 1Hz tick or
 * a press on one of the buttons).
 */
void app_prepare_for_sleep() {
    application_state.debounce_wait = false;
}

/**
 * @brief the app_wake_from_sleep function is called after the watch wakes from the
 * STANDBY sleep mode.
 */
void app_wake_from_sleep() {
    application_state.wake_count++;
}

/**
 * @brief the app_loop function is called once on app startup and then again each time
 * the watch STANDBY sleep mode.
 */
bool app_loop() {
    // set the LED to a color
    switch (application_state.color) {
        case COLOR_OFF:
            watch_set_led_off();
            break;
        case COLOR_RED:
            watch_set_led_red();
            break;
        case COLOR_GREEN:
            watch_set_led_green();
            break;
        case COLOR_YELLOW:
            watch_set_led_yellow();
            break;
    }

    // Display the number of times we've woken up (modulo 32 to fit in 2 digits at top right)
    char buf[3] = {0};
    sprintf(buf, "%2d", application_state.wake_count % 32);
    watch_display_string(buf, 2);

    // display "Hello there" text
    switch (application_state.mode) {
        case MODE_HELLO:
            watch_display_string("Hello", 5);
            break;
        case MODE_THERE:
            watch_display_string("there", 5);
            break;
    }

    // Wait a moment to debounce button input
    delay_ms(250);

    return true;
}


//////////////////////////////////////////////////////////////////////////////////////////
// Implementations for our callback functions. Replace these with whatever functionality
// your app requires.
void cb_light_pressed() {
    if (application_state.debounce_wait) return;
    application_state.debounce_wait = true;
    application_state.color = (application_state.color + 1) % 4;
}

void cb_mode_pressed() {
    if (application_state.debounce_wait) return;
    application_state.debounce_wait = true;
    application_state.mode = (application_state.mode + 1) % 2;
}

void cb_alarm_pressed() {
    // TODO: deep sleep demo
}