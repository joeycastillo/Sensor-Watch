#include <stdio.h>
#include <string.h>
#include "watch.h"

typedef struct {
    bool beep;
    bool play;
    uint8_t press_count;
} ApplicationState;

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
    {BUZZER_NOTE_C5,                200,    " and  "},
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
    {BUZZER_NOTE_C5,                200,    " and  "},
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

};

ApplicationState application_state;

void cb_tick() {
    watch_set_led_color(rand() % 128 + 127, rand() % 128);
}

void cb_alarm_pressed() {
    application_state.beep = true;
}

void app_init() {
    memset(&application_state, 0, sizeof(application_state));
}

void app_wake_from_backup() {
}

void app_setup() {
    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_alarm_pressed, INTERRUPT_TRIGGER_RISING);

    watch_enable_display();
    application_state.play = false;

    watch_enable_buzzer();
    watch_set_indicator(WATCH_INDICATOR_PM);
    watch_set_colon();
    watch_display_string("    1117  ", 0);
}

void app_prepare_for_standby() {
}

void app_wake_from_standby() {
}

bool app_loop() {
    if (application_state.beep) {
        watch_buzzer_play_note(beeps[application_state.press_count++], 50);
        if (application_state.press_count % 2) {
            watch_clear_indicator(WATCH_INDICATOR_PM);
            watch_set_colon();
            watch_display_string("ST  000000", 0);
        } else {
            watch_set_indicator(WATCH_INDICATOR_PM);
            watch_set_colon();
            watch_display_string("    1117  ", 0);
        }
        if (application_state.press_count >= sizeof(beeps)) {
            application_state.press_count = 0;
            application_state.play = true;
        }
        application_state.beep = false;
    }
    if (application_state.play) {
        watch_clear_display();
        application_state.play = false;
        for(size_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
            if(i == 7) {
                watch_enable_leds();
                watch_rtc_register_periodic_callback(cb_tick, 8);
            }
            watch_display_string(melody[i].lyric, 4);
            watch_buzzer_play_note(melody[i].note, melody[i].duration);
            delay_ms(5);
        }
        watch_rtc_disable_periodic_callback(8);
        watch_set_led_off();
        watch_set_indicator(WATCH_INDICATOR_PM);
        watch_set_colon();
        watch_display_string("    1117  ", 0);
    }

    return true;
}
