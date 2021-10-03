#include <stdio.h>
#include <string.h>
#include "watch.h"
#include "launcher.h"
#include "launcher_config.h"

LauncherState launcher_state;
void * widget_contexts[LAUNCHER_NUM_WIDGETS];

void launcher_request_tick_frequency(uint8_t freq) {
    watch_rtc_disable_all_periodic_callbacks();
    watch_rtc_register_periodic_callback(cb_tick, freq);
}

void launcher_illuminate_led() {
    launcher_state.light_ticks = 3;
}


void app_init() {
    memset(&launcher_state, 0, sizeof(launcher_state));
    launcher_state.launcher_settings.bit.led_green_color = 0xF;
}

void app_wake_from_deep_sleep() {
    // This app does not support deep sleep mode.
}

void app_setup() {
    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_BOTH);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_BOTH);
    watch_register_interrupt_callback(BTN_ALARM, cb_alarm_pressed, INTERRUPT_TRIGGER_BOTH);

    watch_enable_buzzer();
    watch_enable_leds();
    watch_enable_display();

    launcher_request_tick_frequency(1);

    for(uint8_t i = 0; i < LAUNCHER_NUM_WIDGETS; i++) {
        widgets[i].setup(&launcher_state.launcher_settings, widget_contexts[i]);
    }
}

void app_prepare_for_sleep() {
}

void app_wake_from_sleep() {
}

LauncherEvent event;

bool app_loop() {
    // play a beep if the widget has changed in response to a user's press of the MODE button
    if (launcher_state.widget_changed) {
        // low note for nonzero case, high note for return to clock
        watch_buzzer_play_note(launcher_state.current_widget ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 100);
        launcher_state.widget_changed = false;
    }

    // If the LED is off and should be on, turn it on
    if (launcher_state.light_ticks > 0 && !launcher_state.led_on) {
        watch_set_led_color(launcher_state.launcher_settings.bit.led_red_color, launcher_state.launcher_settings.bit.led_green_color);
        launcher_state.led_on = true;
    }

    // if the LED is on and should be off, turn it off
    if (launcher_state.led_on && launcher_state.light_ticks == 0) {
        // unless the user is holding down the LIGHT button, in which case, give them more time.
        if (watch_get_pin_level(BTN_LIGHT)) {
            launcher_state.light_ticks = 3;
        } else {
            watch_set_led_off();
            launcher_state.led_on = false;
        }
    }

    if (event) {
        event = 0;
        widgets[launcher_state.current_widget].loop(event, &launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
    }

    if (launcher_state.led_on) return false;

    return true;
}

void move_to_next_widget() {
    launcher_state.widget_changed = true;
    widgets[launcher_state.current_widget].resign(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
    launcher_state.current_widget = (launcher_state.current_widget + 1) % LAUNCHER_NUM_WIDGETS;
    widgets[launcher_state.current_widget].activate(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
}

void move_to_first_widget() {
    launcher_state.widget_changed = true;
    widgets[launcher_state.current_widget].resign(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
    launcher_state.current_widget = 0;
    widgets[0].activate(&launcher_state.launcher_settings, widget_contexts[0]);
}

void cb_light_pressed() {
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    if (launcher_state.light_down_timestamp) {
        uint8_t diff = (61 + date_time.time.sec) - launcher_state.light_down_timestamp;
        if (diff > 1) event = EVENT_LIGHT_LONG_PRESS;
        else event = EVENT_LIGHT_BUTTON_UP;
        launcher_state.light_down_timestamp = 0;
    } else {
        launcher_state.light_down_timestamp = date_time.time.sec + 1;
        event = EVENT_LIGHT_BUTTON_DOWN;
    }
}

void cb_mode_pressed() {
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    if (launcher_state.mode_down_timestamp) {
        uint8_t diff = (61 + date_time.time.sec) - launcher_state.mode_down_timestamp;
        if (diff > 1) event = EVENT_MODE_LONG_PRESS;
        else event = EVENT_MODE_BUTTON_UP;
        launcher_state.mode_down_timestamp = 0;
    } else {
        launcher_state.mode_down_timestamp = date_time.time.sec + 1;
        event = EVENT_MODE_BUTTON_DOWN;
    }
}

void cb_alarm_pressed() {
    struct calendar_date_time date_time;
    watch_get_date_time(&date_time);
    if (launcher_state.alarm_down_timestamp) {
        uint8_t diff = (61 + date_time.time.sec) - launcher_state.alarm_down_timestamp;
        if (diff > 1) event = EVENT_ALARM_LONG_PRESS;
        else event = EVENT_ALARM_BUTTON_UP;
        launcher_state.alarm_down_timestamp = 0;
    } else {
        launcher_state.alarm_down_timestamp = date_time.time.sec + 1;
        event = EVENT_ALARM_BUTTON_DOWN;
    }
}

void cb_tick() {
    event = EVENT_TICK;
}
