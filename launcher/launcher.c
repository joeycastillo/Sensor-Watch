#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "watch.h"
#include "launcher.h"
#include "launcher_config.h"

LauncherState launcher_state;
void * widget_contexts[LAUNCHER_NUM_WIDGETS];
const int32_t launcher_screensaver_deadlines[8] = {INT_MAX, 3600, 7200, 21600, 43200, 86400, 172800, 604800};
LauncherEvent event;

void cb_mode_btn_interrupt();
void cb_light_btn_interrupt();
void cb_alarm_btn_interrupt();
void cb_alarm_btn_extwake();
void cb_alarm_fired();
void cb_tick();

static inline void _launcher_reset_screensaver_countdown() {
    // for testing, make the timeout happen 60x faster.
    launcher_state.screensaver_ticks = launcher_screensaver_deadlines[launcher_state.launcher_settings.bit.screensaver_interval] / 60;
}

void launcher_request_tick_frequency(uint8_t freq) {
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
    launcher_state.next_widget = widget_index;
}

void launcher_move_to_next_widget() {
    launcher_move_to_widget((launcher_state.current_widget + 1) % LAUNCHER_NUM_WIDGETS);
}

void app_init() {
    memset(&launcher_state, 0, sizeof(launcher_state));

    launcher_state.launcher_settings.bit.led_green_color = 0xF;
    launcher_state.launcher_settings.bit.button_should_sound = true;
    launcher_state.launcher_settings.bit.screensaver_interval = 1;
    _launcher_reset_screensaver_countdown();
}

void app_wake_from_deep_sleep() {
    // This app does not support deep sleep mode.
}

void app_setup() {
    if (launcher_state.screensaver_ticks != -1) {
        watch_disable_extwake_interrupt(BTN_ALARM);
        watch_rtc_disable_alarm_callback();

        watch_enable_external_interrupts();
        watch_register_interrupt_callback(BTN_MODE, cb_mode_btn_interrupt, INTERRUPT_TRIGGER_BOTH);
        watch_register_interrupt_callback(BTN_LIGHT, cb_light_btn_interrupt, INTERRUPT_TRIGGER_BOTH);
        watch_register_interrupt_callback(BTN_ALARM, cb_alarm_btn_interrupt, INTERRUPT_TRIGGER_BOTH);

        watch_enable_buzzer();
        watch_enable_leds();
        watch_enable_display();

        launcher_request_tick_frequency(1);

        for(uint8_t i = 0; i < LAUNCHER_NUM_WIDGETS; i++) {
            widgets[i].setup(&launcher_state.launcher_settings, &widget_contexts[i]);
        }

        widgets[0].activate(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
        event.value = 0;
        event.bit.event_type = EVENT_ACTIVATE;
    }
}

void app_prepare_for_sleep() {
}

void app_wake_from_sleep() {
}

bool app_loop() {
    if (launcher_state.widget_changed) {
        if (launcher_state.launcher_settings.bit.button_should_sound) {
            // low note for nonzero case, high note for return to widget 0
            watch_buzzer_play_note(launcher_state.current_widget ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 50);
        }
        widgets[launcher_state.current_widget].resign(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
        launcher_state.current_widget = launcher_state.next_widget;
        watch_clear_display();
        widgets[launcher_state.current_widget].activate(&launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
        event.value = 0;
        event.bit.event_type = EVENT_ACTIVATE;
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

    // if we have timed out of our screensaver countdown, enter screensaver mode.
    if (launcher_state.screensaver_ticks == 0) {
        launcher_state.screensaver_ticks = -1;
        watch_date_time alarm_time;
        alarm_time.reg = 0;
        alarm_time.unit.second = 59; // after a match, the alarm fires at the next rising edge of CLK_RTC_CNT, so 59 seconds lets us update at :00
        watch_rtc_register_alarm_callback(cb_alarm_fired, alarm_time, ALARM_MATCH_SS);
        watch_register_extwake_callback(BTN_ALARM, cb_alarm_btn_extwake, true);
        event.value = 0;

        // this is a little mini-runloop.
        // as long as screensaver_ticks is -1 (i.e. screensaver is active), we wake up here, update the screen, and go right back to sleep.
        while (launcher_state.screensaver_ticks == -1) {
            event.bit.event_type = EVENT_SCREENSAVER;
            widgets[launcher_state.current_widget].loop(event, &launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
            watch_enter_shallow_sleep(true);
        }
        // as soon as screensaver_ticks is reset by the extwake handler, we bail out of the loop and reactivate ourselves.
        event.bit.event_type = EVENT_ACTIVATE;
        // this is a hack tho: waking from shallow sleep, app_setup does get called, but it happens before we have reset our ticks.
        // need to figure out if there's a better heuristic for determining how we woke up.
        app_setup();
    }

    bool can_sleep = true;

    if (event.bit.event_type) {
        event.bit.subsecond = launcher_state.subsecond;
        can_sleep = widgets[launcher_state.current_widget].loop(event, &launcher_state.launcher_settings, widget_contexts[launcher_state.current_widget]);
        event.value = 0;
    }

    return can_sleep && !launcher_state.led_on;
}

LauncherEventType _figure_out_button_event(LauncherEventType button_down_event, uint8_t *down_timestamp) {
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

void cb_light_btn_interrupt() {
    _launcher_reset_screensaver_countdown();
    event.bit.event_type = _figure_out_button_event(EVENT_LIGHT_BUTTON_DOWN, &launcher_state.light_down_timestamp);
}

void cb_mode_btn_interrupt() {
    _launcher_reset_screensaver_countdown();
    event.bit.event_type = _figure_out_button_event(EVENT_MODE_BUTTON_DOWN, &launcher_state.mode_down_timestamp);
}

void cb_alarm_btn_interrupt() {
    _launcher_reset_screensaver_countdown();
    event.bit.event_type = _figure_out_button_event(EVENT_ALARM_BUTTON_DOWN, &launcher_state.alarm_down_timestamp);
}

void cb_alarm_btn_extwake() {
    // wake up!
    _launcher_reset_screensaver_countdown();
}

void cb_alarm_fired() {
    event.bit.event_type = EVENT_SCREENSAVER;
}

void cb_tick() {
    event.bit.event_type = EVENT_TICK;
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second != launcher_state.last_second) {
        if (launcher_state.light_ticks) launcher_state.light_ticks--;
        if (launcher_state.launcher_settings.bit.screensaver_interval && launcher_state.screensaver_ticks > 0) launcher_state.screensaver_ticks--;

        launcher_state.last_second = date_time.unit.second;
        launcher_state.subsecond = 0;
    } else {
        launcher_state.subsecond++;
    }
}
