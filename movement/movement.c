#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "watch.h"
#include "movement.h"
#include "movement_config.h"

movement_state_t movement_state;
void * watch_face_contexts[MOVEMENT_NUM_FACES];
const int32_t movement_screensaver_deadlines[8] = {INT_MAX, 3600, 7200, 21600, 43200, 86400, 172800, 604800};
movement_event_t event;

void cb_mode_btn_interrupt();
void cb_light_btn_interrupt();
void cb_alarm_btn_interrupt();
void cb_alarm_btn_extwake();
void cb_alarm_fired();
void cb_tick();

static inline void _movement_reset_screensaver_countdown() {
    // for testing, make the timeout happen 60x faster.
    movement_state.screensaver_ticks = movement_screensaver_deadlines[movement_state.movement_settings.bit.screensaver_interval] / 60;
}

void movement_request_tick_frequency(uint8_t freq) {
    watch_rtc_disable_all_periodic_callbacks();
    movement_state.subsecond = 0;
    movement_state.tick_frequency = freq;
    watch_rtc_register_periodic_callback(cb_tick, freq);
}

void movement_illuminate_led() {
    movement_state.light_ticks = 3;
}

void movement_move_to_face(uint8_t watch_face_index) {
    movement_state.watch_face_changed = true;
    movement_state.next_face = watch_face_index;
}

void movement_move_to_next_face() {
    movement_move_to_face((movement_state.current_watch_face + 1) % MOVEMENT_NUM_FACES);
}

void app_init() {
    memset(&movement_state, 0, sizeof(movement_state));

    movement_state.movement_settings.bit.led_green_color = 0xF;
    movement_state.movement_settings.bit.button_should_sound = true;
    movement_state.movement_settings.bit.screensaver_interval = 1;
    _movement_reset_screensaver_countdown();
}

void app_wake_from_deep_sleep() {
    // This app does not support deep sleep mode.
}

void app_setup() {
    static bool is_first_launch = true;

    if (is_first_launch) {
        for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
            watch_face_contexts[i] = NULL;
            is_first_launch = false;
        }
    }
    if (movement_state.screensaver_ticks != -1) {
        watch_disable_extwake_interrupt(BTN_ALARM);
        watch_rtc_disable_alarm_callback();

        watch_enable_external_interrupts();
        watch_register_interrupt_callback(BTN_MODE, cb_mode_btn_interrupt, INTERRUPT_TRIGGER_BOTH);
        watch_register_interrupt_callback(BTN_LIGHT, cb_light_btn_interrupt, INTERRUPT_TRIGGER_BOTH);
        watch_register_interrupt_callback(BTN_ALARM, cb_alarm_btn_interrupt, INTERRUPT_TRIGGER_BOTH);

        watch_enable_buzzer();
        watch_enable_leds();
        watch_enable_display();

        movement_request_tick_frequency(1);

        for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
            watch_faces[i].setup(&movement_state.movement_settings, &watch_face_contexts[i]);
        }

        watch_faces[0].activate(&movement_state.movement_settings, watch_face_contexts[0]);
        event.subsecond = 0;
        event.event_type = EVENT_ACTIVATE;
    }
}

void app_prepare_for_sleep() {
}

void app_wake_from_sleep() {
}

bool app_loop() {
    if (movement_state.watch_face_changed) {
        if (movement_state.movement_settings.bit.button_should_sound) {
            // low note for nonzero case, high note for return to watch_face 0
            watch_buzzer_play_note(movement_state.next_face ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 50);
        }
        watch_faces[movement_state.current_watch_face].resign(&movement_state.movement_settings, watch_face_contexts[movement_state.current_watch_face]);
        movement_state.current_watch_face = movement_state.next_face;
        watch_clear_display();
        watch_faces[movement_state.current_watch_face].activate(&movement_state.movement_settings, watch_face_contexts[movement_state.current_watch_face]);
        event.subsecond = 0;
        event.event_type = EVENT_ACTIVATE;
        movement_state.watch_face_changed = false;
    }

    // If the LED is off and should be on, turn it on
    if (movement_state.light_ticks > 0 && !movement_state.led_on) {
        watch_set_led_color(movement_state.movement_settings.bit.led_red_color ? (0xF | movement_state.movement_settings.bit.led_red_color << 4) : 0,
                            movement_state.movement_settings.bit.led_green_color ? (0xF | movement_state.movement_settings.bit.led_green_color << 4) : 0);
        movement_state.led_on = true;

    }

    // if the LED is on and should be off, turn it off
    if (movement_state.led_on && movement_state.light_ticks == 0) {
        // unless the user is holding down the LIGHT button, in which case, give them more time.
        if (watch_get_pin_level(BTN_LIGHT)) {
            movement_state.light_ticks = 3;
        } else {
            watch_set_led_off();
            movement_state.led_on = false;
        }
    }

    // if we have timed out of our screensaver countdown, enter screensaver mode.
    if (movement_state.screensaver_ticks == 0) {
        movement_state.screensaver_ticks = -1;
        watch_date_time alarm_time;
        alarm_time.reg = 0;
        alarm_time.unit.second = 59; // after a match, the alarm fires at the next rising edge of CLK_RTC_CNT, so 59 seconds lets us update at :00
        watch_rtc_register_alarm_callback(cb_alarm_fired, alarm_time, ALARM_MATCH_SS);
        watch_register_extwake_callback(BTN_ALARM, cb_alarm_btn_extwake, true);
        event.event_type = EVENT_NONE;
        event.subsecond = 0;

        // this is a little mini-runloop.
        // as long as screensaver_ticks is -1 (i.e. screensaver is active), we wake up here, update the screen, and go right back to sleep.
        while (movement_state.screensaver_ticks == -1) {
            event.event_type = EVENT_SCREENSAVER;
            watch_faces[movement_state.current_watch_face].loop(event, &movement_state.movement_settings, watch_face_contexts[movement_state.current_watch_face]);
            watch_enter_shallow_sleep(true);
        }
        // as soon as screensaver_ticks is reset by the extwake handler, we bail out of the loop and reactivate ourselves.
        event.event_type = EVENT_ACTIVATE;
        // this is a hack tho: waking from shallow sleep, app_setup does get called, but it happens before we have reset our ticks.
        // need to figure out if there's a better heuristic for determining how we woke up.
        app_setup();
    }

    static bool can_sleep = true;

    if (event.event_type) {
        event.subsecond = movement_state.subsecond;
        can_sleep = watch_faces[movement_state.current_watch_face].loop(event, &movement_state.movement_settings, watch_face_contexts[movement_state.current_watch_face]);
        event.event_type = EVENT_NONE;
        event.subsecond = 0;
    }

    return can_sleep && !movement_state.led_on;
}

movement_event_type_t _figure_out_button_event(movement_event_type_t button_down_event_type, uint8_t *down_timestamp) {
    watch_date_time date_time = watch_rtc_get_date_time();
    if (*down_timestamp) {
        uint8_t diff = ((61 + date_time.unit.second) - *down_timestamp) % 60;
        *down_timestamp = 0;
        if (diff > 1) return button_down_event_type + 2;
        else return button_down_event_type + 1;
    } else {
        *down_timestamp = date_time.unit.second + 1;
        return button_down_event_type;
    }
}

void cb_light_btn_interrupt() {
    _movement_reset_screensaver_countdown();
    event.event_type = _figure_out_button_event(EVENT_LIGHT_BUTTON_DOWN, &movement_state.light_down_timestamp);
}

void cb_mode_btn_interrupt() {
    _movement_reset_screensaver_countdown();
    event.event_type = _figure_out_button_event(EVENT_MODE_BUTTON_DOWN, &movement_state.mode_down_timestamp);
}

void cb_alarm_btn_interrupt() {
    _movement_reset_screensaver_countdown();
    event.event_type = _figure_out_button_event(EVENT_ALARM_BUTTON_DOWN, &movement_state.alarm_down_timestamp);
}

void cb_alarm_btn_extwake() {
    // wake up!
    _movement_reset_screensaver_countdown();
}

void cb_alarm_fired() {
    event.event_type = EVENT_SCREENSAVER;
}

void cb_tick() {
    event.event_type = EVENT_TICK;
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second != movement_state.last_second) {
        if (movement_state.light_ticks) movement_state.light_ticks--;
        if (movement_state.movement_settings.bit.screensaver_interval && movement_state.screensaver_ticks > 0) movement_state.screensaver_ticks--;

        movement_state.last_second = date_time.unit.second;
        movement_state.subsecond = 0;
    } else {
        movement_state.subsecond++;
    }
}
