#include <stdio.h>
#include <string.h>
#include <math.h>
#include "watch.h"
#include "tsl2591.h"

#include "app.h"

ApplicationState application_state;
char buf[16] = {0};

void app_init() {
    memset(&application_state, 0, sizeof(application_state));
}

void app_wake_from_deep_sleep() {
    // This app does not support deep sleep mode.
}

void app_setup() {
    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_extwake_callback(BTN_ALARM, cb_alarm_pressed, true);

    watch_enable_buzzer();
    watch_enable_leds();

    // pin A0 powers the sensor on this board.
    watch_enable_digital_output(A0);
    watch_set_pin_level(A0, true);
    delay_ms(10);

    watch_enable_i2c();

    watch_enable_display();

    watch_register_tick_callback(cb_tick);

    delay_ms(5000);
    if (!tsl2591_init()) {
        printf("Sensor init failed?\n");
    }
}

void app_prepare_for_sleep() {
}

void app_wake_from_sleep() {
}

bool app_loop() {
    return true;
}

void cb_mode_pressed() {
    application_state.mode = (application_state.mode + 1) % NUM_MODES;
    application_state.mode_changed = true;
    application_state.mode_ticks = 300;
    application_state.page = 0;
}

void cb_light_pressed() {
    application_state.light_ticks = 3;
}

void cb_alarm_pressed() {
}

void cb_tick() {
    uint16_t result = tsl2591_get_visible_light_reading();
    printf("Visible Light : %d\n\n", result);
    if (application_state.light_ticks > 0) {
        application_state.light_ticks--;
    }
    if (application_state.mode_ticks > 0) {
        application_state.mode_ticks--;
    }
}
