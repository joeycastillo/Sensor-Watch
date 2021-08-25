#include <stdio.h>
#include <string.h>
#include "watch.h"

//////////////////////////////////////////////////////////////////////////////////////////
// This section sets up types and storage for our application state.
// You can tear this out and replace it with whatever you want.
typedef enum ApplicationMode {
    MODE_HELLO = 0,
    MODE_THERE
} ApplicationMode;

typedef enum LightColor {
    COLOR_RED = 0,
    COLOR_GREEN,
    COLOR_YELLOW
} LightColor;

typedef struct ApplicationState {
    ApplicationMode mode;
    LightColor color;
    bool light_on;
    uint8_t wake_count;
    bool enter_deep_sleep;
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
    // retrieve our application state from the backup registers
    application_state.mode = (ApplicationMode)watch_get_backup_data(0);
    application_state.color = (LightColor)watch_get_backup_data(1);
    application_state.wake_count = (uint8_t)watch_get_backup_data(2) + 1;
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

    watch_enable_external_interrupts();
    // This starter app demonstrates three different ways of using the button interrupts.
    // The BTN_MODE interrupt only triggers on a rising edge, so the mode changes once per press.
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    // The BTN_LIGHT interrupt triggers on both rising and falling edges. The callback then checks
    // the pin state when triggered: on a button down event, it increments the color and turns the
    // LED on, whereas on a button up event, it turns the light off.
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_BOTH);
    // The BTN_ALARM callback is on an external wake pin; we can avoid using the EIC for this pin
    // by using the extwake interrupt — but note that it can only trigger on either a rising or
    // a falling edge, not both.
    watch_register_extwake_callback(BTN_ALARM, cb_alarm_pressed, true);

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
    application_state.wake_count++;
}

/**
 * @brief the app_loop function is called once on app startup and then again each time
 * the watch STANDBY sleep mode.
 */
bool app_loop() {
    // set the LED to a color
    if (application_state.light_on) {
        switch (application_state.color) {
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
    } else {
        watch_set_led_off();
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

    if (application_state.enter_deep_sleep) {
        application_state.enter_deep_sleep = false;

        // stash our application state in the backup registers
        watch_store_backup_data((uint32_t)application_state.mode, 0);
        watch_store_backup_data((uint32_t)application_state.color, 1);
        watch_store_backup_data((uint32_t)application_state.wake_count, 2);

        // turn off the LED
        watch_set_led_off();

        // wait a moment for the user's finger to be off the button
        delay_ms(1000);

        // nap time :)
        watch_enter_deep_sleep();
    }

    return true;
}


//////////////////////////////////////////////////////////////////////////////////////////
// Implementations for our callback functions. Replace these with whatever functionality
// your app requires.
void cb_light_pressed() {
    // always turn the light off when the pin goes low
    if (watch_get_pin_level(BTN_LIGHT) == 0) {
        application_state.light_on = false;
        return;
    }
    application_state.color = (application_state.color + 1) % 3;
    application_state.light_on = true;
}

void cb_mode_pressed() {
    application_state.mode = (application_state.mode + 1) % 2;
}

void cb_alarm_pressed() {
    // boo: http://ww1.microchip.com/downloads/en/DeviceDoc/SAM_L22_Family_Errata_DS80000782B.pdf
    // Reference 15010. doesn't say it applies to PA02 but it seems it does?
    // anyway can't deep sleep now :(
    // application_state.enter_deep_sleep = true;
}
