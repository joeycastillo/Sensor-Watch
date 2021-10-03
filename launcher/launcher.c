#include <stdio.h>
#include <string.h>
#include "watch.h"
#include "launcher.h"
#include "launcher_config.h"

LauncherState launcher_state;
void * widget_contexts[LAUNCHER_NUM_WIDGETS];

void cb_mode_pressed();
void cb_light_pressed();
void cb_alarm_pressed();
void cb_tick();

void launcher_request_tick_frequency(uint8_t freq) {
    // FIXME: there is an issue where after changing tick frequencies on a widget switch, something glitchy happens on the next one.
    watch_rtc_disable_all_periodic_callbacks();
    launcher_state.subsecond = 0;
    launcher_state.tick_frequency = freq;
    watch_rtc_register_periodic_callback(cb_tick, freq);
}

void launcher_illuminate_led() {
    launcher_state.light_ticks = 3;
}

void launcher_move_to_widget(uint8_t widget_index) {
    launcher_state.widget_changed = true;
    widgets[launcher_state.current_widget].resign(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
    launcher_state.current_widget = widget_index;
    watch_clear_display();
    widgets[launcher_state.current_widget].activate(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
    widgets[launcher_state.current_widget].loop(EVENT_ACTIVATE, &launcher_state.launcher_settings, launcher_state.subsecond, widget_contexts[launcher_state.current_widget]);
}

void launcher_move_to_next_widget() {
    launcher_move_to_widget((launcher_state.current_widget + 1) % LAUNCHER_NUM_WIDGETS);
}

void app_init() {
    memset(&launcher_state, 0, sizeof(launcher_state));
    launcher_state.launcher_settings.bit.led_green_color = 0xF;
    watch_date_time date_time = watch_rtc_get_date_time();
    watch_rtc_set_date_time(date_time);
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
        widgets[i].setup(&launcher_state.launcher_settings, &widget_contexts[i]);
    }

    launcher_move_to_widget(0);
}

void app_prepare_for_sleep() {
}

void app_wake_from_sleep() {
}

LauncherEvent event;

bool app_loop() {
    // play a beep if the widget has changed in response to a user's press of the MODE button
    if (launcher_state.widget_changed) {
        // low note for nonzero case, high note for return to widget 0
        watch_buzzer_play_note(launcher_state.current_widget ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 50);
        launcher_state.widget_changed = false;
    }

    // If the LED is off and should be on, turn it on
    if (launcher_state.light_ticks > 0 && !launcher_state.led_on) {
        watch_set_led_color(launcher_state.launcher_settings.bit.led_red_color ? (0xF | launcher_state.launcher_settings.bit.led_red_color << 4) : 0,
                            launcher_state.launcher_settings.bit.led_green_color ? (0xF | launcher_state.launcher_settings.bit.led_green_color << 4) : 0);
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
        widgets[launcher_state.current_widget].loop(event, &launcher_state.launcher_settings, launcher_state.subsecond, widget_contexts[launcher_state.current_widget]);
        event = 0;
    }


    if (launcher_state.led_on) return false;

    return true;
}

LauncherEvent _figure_out_button_event(LauncherEvent button_down_event, uint8_t *down_timestamp) {
    watch_date_time date_time = watch_rtc_get_date_time();
    if (*down_timestamp) {
        uint8_t diff = ((61 + date_time.unit.second) - *down_timestamp) % 60;
        *down_timestamp = 0;
        if (diff > 1) return button_down_event + 2;
        else return button_down_event + 1;
    } else {
        *down_timestamp = date_time.unit.second + 1;
        return button_down_event;
    }
}

void cb_light_pressed() {
    event = _figure_out_button_event(EVENT_LIGHT_BUTTON_DOWN, &launcher_state.light_down_timestamp);
}

void cb_mode_pressed() {
    event = _figure_out_button_event(EVENT_MODE_BUTTON_DOWN, &launcher_state.mode_down_timestamp);
}

void cb_alarm_pressed() {
    event = _figure_out_button_event(EVENT_ALARM_BUTTON_DOWN, &launcher_state.alarm_down_timestamp);
}

void cb_tick() {
    event = EVENT_TICK;
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second != launcher_state.last_second) {
        if (launcher_state.light_ticks) launcher_state.light_ticks--;

        launcher_state.last_second = date_time.unit.second;
        launcher_state.subsecond = 0;
    } else {
        launcher_state.subsecond++;
    }
}
