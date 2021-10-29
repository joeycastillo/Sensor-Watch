#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "watch.h"
#include "movement.h"
#include "movement_config.h"

movement_state_t movement_state;
void * watch_face_contexts[MOVEMENT_NUM_FACES];
const int32_t movement_le_inactivity_deadlines[8] = {INT_MAX, 3600, 7200, 21600, 43200, 86400, 172800, 604800};
const int32_t movement_timeout_inactivity_deadlines[4] = {60, 120, 300, 1800};
movement_event_t event;

void cb_mode_btn_interrupt();
void cb_light_btn_interrupt();
void cb_alarm_btn_interrupt();
void cb_alarm_btn_extwake();
void cb_alarm_fired();
void cb_tick();

static inline void _movement_reset_inactivity_countdown() {
    movement_state.le_mode_ticks = movement_le_inactivity_deadlines[movement_state.settings.bit.le_interval];
    movement_state.timeout_ticks = movement_timeout_inactivity_deadlines[movement_state.settings.bit.to_interval];
}

void _movement_handle_background_tasks() {
    for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
        // For each face, if the watch face wants a background task...
        if (watch_faces[i].wants_background_task != NULL && watch_faces[i].wants_background_task(&movement_state.settings, watch_face_contexts[i])) {
            // ...we give it one. pretty straightforward!
            movement_event_t background_event = { EVENT_BACKGROUND_TASK, 0 };
            watch_faces[i].loop(background_event, &movement_state.settings, watch_face_contexts[i]);
        }
    }
    movement_state.needs_background_tasks_handled = false;
}

void movement_request_tick_frequency(uint8_t freq) {
    watch_rtc_disable_all_periodic_callbacks();
    movement_state.subsecond = 0;
    movement_state.tick_frequency = freq;
    watch_rtc_register_periodic_callback(cb_tick, freq);
}

void movement_illuminate_led() {
    watch_set_led_color(movement_state.settings.bit.led_red_color ? (0xF | movement_state.settings.bit.led_red_color << 4) : 0,
                        movement_state.settings.bit.led_green_color ? (0xF | movement_state.settings.bit.led_green_color << 4) : 0);
    movement_state.led_on = true;
    movement_state.light_ticks = movement_state.settings.bit.led_duration * 2;
}

void movement_move_to_face(uint8_t watch_face_index) {
    movement_state.watch_face_changed = true;
    movement_state.next_watch_face = watch_face_index;
}

void movement_move_to_next_face() {
    movement_move_to_face((movement_state.current_watch_face + 1) % MOVEMENT_NUM_FACES);
}

void app_init() {
    memset(&movement_state, 0, sizeof(movement_state));

    movement_state.settings.bit.led_green_color = 0xF;
    movement_state.settings.bit.button_should_sound = true;
    movement_state.settings.bit.le_interval = 1;
    movement_state.settings.bit.led_duration = 1;
    _movement_reset_inactivity_countdown();
}

void app_wake_from_backup() {
    // This app does not support BACKUP mode.
}

void app_setup() {
    static bool is_first_launch = true;

    if (is_first_launch) {
        for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
            watch_face_contexts[i] = NULL;
            is_first_launch = false;
        }

        // set up the 1 minute alarm (for background tasks and low power updates)
        watch_date_time alarm_time;
        alarm_time.reg = 0;
        alarm_time.unit.second = 59; // after a match, the alarm fires at the next rising edge of CLK_RTC_CNT, so 59 seconds lets us update at :00
        watch_rtc_register_alarm_callback(cb_alarm_fired, alarm_time, ALARM_MATCH_SS);
    }
    if (movement_state.le_mode_ticks != -1) {
        watch_disable_extwake_interrupt(BTN_ALARM);

        watch_enable_external_interrupts();
        watch_register_interrupt_callback(BTN_MODE, cb_mode_btn_interrupt, INTERRUPT_TRIGGER_BOTH);
        watch_register_interrupt_callback(BTN_LIGHT, cb_light_btn_interrupt, INTERRUPT_TRIGGER_BOTH);
        watch_register_interrupt_callback(BTN_ALARM, cb_alarm_btn_interrupt, INTERRUPT_TRIGGER_BOTH);

        watch_enable_buzzer();
        watch_enable_leds();
        watch_enable_display();

        movement_request_tick_frequency(1);

        for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
            watch_faces[i].setup(&movement_state.settings, &watch_face_contexts[i]);
        }

        watch_faces[0].activate(&movement_state.settings, watch_face_contexts[0]);
        event.subsecond = 0;
        event.event_type = EVENT_ACTIVATE;
    }
}

void app_prepare_for_standby() {
}

void app_wake_from_standby() {
}

typedef struct {
    BuzzerNote note;
    uint16_t duration;
    char lyric[7];
} SongNote;

const BuzzerNote beeps[] = {
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_F5SHARP_G5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_C5,
    BUZZER_NOTE_C5,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_D5SHARP_E5FLAT,
    BUZZER_NOTE_F5SHARP_G5FLAT,
    BUZZER_NOTE_REST,
};

const SongNote melody[] = {
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    200,    ""},
    // {BUZZER_NOTE_F5SHARP_G5FLAT,    300,    ""},
    // {BUZZER_NOTE_REST,              20,     ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_C5,                200,    ""},
    // {BUZZER_NOTE_C5,                300,    ""},
    // {BUZZER_NOTE_REST,              20,     ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    // {BUZZER_NOTE_D5SHARP_E5FLAT,    200,    ""},
    // {BUZZER_NOTE_F5SHARP_G5FLAT,    300,    ""},
    {BUZZER_NOTE_REST,              20,     "      "},
    {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    {BUZZER_NOTE_D5SHARP_E5FLAT,    300,    ""},
    {BUZZER_NOTE_C5,                200,    ""},
    {BUZZER_NOTE_C5,                300,    ""},
    {BUZZER_NOTE_REST,              20,     ""},

    {BUZZER_NOTE_D5SHARP_E5FLAT,    400,    " dig  "},
    {BUZZER_NOTE_REST,              10,     ""},
    {BUZZER_NOTE_C5,                200,    " thru "},
    {BUZZER_NOTE_C5,                200,    " the  "},
    {BUZZER_NOTE_C5,                200,    " ditch"},
    {BUZZER_NOTE_C5,                200,    "  es  "},
    {BUZZER_NOTE_C5,                200,    " and  "},
    {BUZZER_NOTE_D5SHARP_E5FLAT,    500,    " burn "},
    {BUZZER_NOTE_REST,              10,     ""},
    {BUZZER_NOTE_C5,                200,    " thru "},
    {BUZZER_NOTE_C5,                200,    " the  "},
    {BUZZER_NOTE_C5,                200,    " Witch"},
    {BUZZER_NOTE_C5,                200,    "  es  "},
    {BUZZER_NOTE_C5,                200,    " 1    "},
    {BUZZER_NOTE_D5SHARP_E5FLAT,    500,    " S1aN7"},
    {BUZZER_NOTE_REST,              10,     ""},
    {BUZZER_NOTE_C5,                200,    " 1n   "},
    {BUZZER_NOTE_C5,                200,    " the  "},
    {BUZZER_NOTE_C5,                200,    " back "},
    {BUZZER_NOTE_C5,                200,    "  OF  "},
    {BUZZER_NOTE_C5,                300,    "  n&y "},
    {BUZZER_NOTE_REST,              20,     ""},
    {BUZZER_NOTE_D5SHARP_E5FLAT,    250,    " drAG "},
    {BUZZER_NOTE_F5,                400,    "   U  "},
    {BUZZER_NOTE_G5,                250,    "   LA "},
    {BUZZER_NOTE_F5,                600,    "    AA"},

    {BUZZER_NOTE_REST,              50, ""},
};

void cb_flash() {
    watch_set_led_color(rand() % 128 + 127, rand() % 128);
}

bool app_loop() {
    if (movement_state.watch_face_changed) {
        if (movement_state.settings.bit.button_should_sound) {
            watch_buzzer_play_note(beeps[movement_state.note_count++], 50);
            if (movement_state.note_count >= sizeof(beeps)) {
                movement_state.note_count = 0;
                movement_state.play_song = true;
            }
        }
        watch_faces[movement_state.current_watch_face].resign(&movement_state.settings, watch_face_contexts[movement_state.current_watch_face]);
        movement_state.current_watch_face = movement_state.next_watch_face;
        watch_clear_display();
        watch_faces[movement_state.current_watch_face].activate(&movement_state.settings, watch_face_contexts[movement_state.current_watch_face]);
        event.subsecond = 0;
        event.event_type = EVENT_ACTIVATE;
        movement_state.watch_face_changed = false;
    }

    if (movement_state.play_song) {
        watch_faces[movement_state.current_watch_face].resign(&movement_state.settings, watch_face_contexts[movement_state.current_watch_face]);
        watch_clear_display();
        movement_state.play_song = false;
        for(size_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
            if(i == 7) {
                watch_enable_leds();
                watch_rtc_register_periodic_callback(cb_flash, 8);
            }
            watch_display_string(melody[i].lyric, 4);
            watch_buzzer_play_note(melody[i].note, melody[i].duration);
            delay_ms(5);
        }
        watch_rtc_disable_periodic_callback(8);
        watch_set_led_off();
        movement_state.current_watch_face = 0;
        watch_faces[0].activate(&movement_state.settings, watch_face_contexts[0]);
        movement_request_tick_frequency(1);
        event.event_type = EVENT_ACTIVATE;
        event.subsecond = 0;
        movement_state.watch_face_changed = false;
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

    // if we have timed out of our timeout countdown, give the app a hint that they can resign.
    if (movement_state.timeout_ticks == 0) {
        event.event_type = EVENT_TIMEOUT;
        movement_state.note_count = 0;
    }

    // handle background tasks, if the alarm handler told us we need to
    if (movement_state.needs_background_tasks_handled) _movement_handle_background_tasks();

    // if we have timed out of our low energy mode countdown, enter low energy mode.
    if (movement_state.le_mode_ticks == 0) {
        movement_state.le_mode_ticks = -1;
        watch_register_extwake_callback(BTN_ALARM, cb_alarm_btn_extwake, true);
        event.event_type = EVENT_NONE;
        event.subsecond = 0;

        // this is a little mini-runloop.
        // as long as le_mode_ticks is -1 (i.e. we are in low energy mode), we wake up here, update the screen, and go right back to sleep.
        while (movement_state.le_mode_ticks == -1) {
            // we also have to handle background tasks here in the mini-runloop
            if (movement_state.needs_background_tasks_handled) _movement_handle_background_tasks();

            event.event_type = EVENT_LOW_ENERGY_UPDATE;
            watch_faces[movement_state.current_watch_face].loop(event, &movement_state.settings, watch_face_contexts[movement_state.current_watch_face]);
            watch_enter_sleep_mode();
        }
        // as soon as le_mode_ticks is reset by the extwake handler, we bail out of the loop and reactivate ourselves.
        event.event_type = EVENT_ACTIVATE;
        // this is a hack tho: waking from sleep mode, app_setup does get called, but it happens before we have reset our ticks.
        // need to figure out if there's a better heuristic for determining how we woke up.
        app_setup();
    }

    static bool can_sleep = true;

    if (event.event_type) {
        event.subsecond = movement_state.subsecond;
        can_sleep = watch_faces[movement_state.current_watch_face].loop(event, &movement_state.settings, watch_face_contexts[movement_state.current_watch_face]);
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
    _movement_reset_inactivity_countdown();
    event.event_type = _figure_out_button_event(EVENT_LIGHT_BUTTON_DOWN, &movement_state.light_down_timestamp);
}

void cb_mode_btn_interrupt() {
    _movement_reset_inactivity_countdown();
    event.event_type = _figure_out_button_event(EVENT_MODE_BUTTON_DOWN, &movement_state.mode_down_timestamp);
}

void cb_alarm_btn_interrupt() {
    _movement_reset_inactivity_countdown();
    event.event_type = _figure_out_button_event(EVENT_ALARM_BUTTON_DOWN, &movement_state.alarm_down_timestamp);
}

void cb_alarm_btn_extwake() {
    // wake up!
    _movement_reset_inactivity_countdown();
}

void cb_alarm_fired() {
    movement_state.needs_background_tasks_handled = true;
}

void cb_tick() {
    event.event_type = EVENT_TICK;
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second != movement_state.last_second) {
        // TODO: since we time the LED with the 1 Hz tick, the actual time lit can vary depending on whether the
        // user hit it just before or just after a tick. If we time this with the system tick we can do better.
        if (movement_state.light_ticks) movement_state.light_ticks--;

        // TODO: can we consolidate these two ticks?
        if (movement_state.settings.bit.le_interval && movement_state.le_mode_ticks > 0) movement_state.le_mode_ticks--;
        if (movement_state.timeout_ticks > 0) movement_state.timeout_ticks--;

        movement_state.last_second = date_time.unit.second;
        movement_state.subsecond = 0;
    } else {
        movement_state.subsecond++;
    }
}
