#include <stdio.h>
#include <string.h>
#include <math.h>
#include "watch.h"
#include "watch_utility.h"

const int8_t UTC_OFFSET = 4; // set to your current UTC offset to see correct beats time
const uint8_t BEAT_REFRESH_FREQUENCY = 8;

typedef enum ApplicationMode {
    MODE_CLOCK = 0, // Displays month, day and current time.
    MODE_BEATS,
    MODE_SET,       // (ST) Set time and date
    NUM_MODES       // Last item in the enum, it's the number of cases.
} ApplicationMode;


typedef struct ApplicationState {
    // Internal application state
    ApplicationMode mode;   // Current mode
    bool mode_changed;      // Lets us perform one-time setup for a given mode
    uint16_t mode_ticks;    // Timeout for the mode (returns to clock after timeout expires)
    uint8_t light_ticks;    // Timeout for the light
    bool led_on;            // Indicates that the LED is on
    uint8_t page;           // Tracks the current page in log, prefs or settings.
    uint8_t last_second;    // lets us see when the second changed, for subsecond timing
    uint8_t subsecond;      // a value from 0 to (BEAT_REFRESH_FREQUENCY - 1) indicating the fractional second
} ApplicationState;

void do_clock_mode(void);
void do_beats_mode(void);
void do_set_time_mode(void);
void set_time_mode_handle_primary_button(void);
void set_time_mode_handle_secondary_button(void);

float clock2beats(uint16_t, uint16_t, uint16_t, int16_t);

void cb_light_pressed(void);
void cb_mode_pressed(void);
void cb_alarm_pressed(void);
void cb_tick(void);
void cb_fast_tick(void);

ApplicationState application_state;
char buf[16] = {0};

/**
 * @brief Zeroes out the application state struct.
 */
void app_init(void) {
    memset(&application_state, 0, sizeof(application_state));
}

void app_wake_from_backup(void) {
    // This app does not support BACKUP mode.
}

void app_setup(void) {
    watch_enable_external_interrupts();
    watch_register_interrupt_callback(BTN_MODE, cb_mode_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_interrupt_callback(BTN_LIGHT, cb_light_pressed, INTERRUPT_TRIGGER_RISING);
    watch_register_extwake_callback(BTN_ALARM, cb_alarm_pressed, true);

    watch_enable_buzzer();
    watch_enable_leds();
    watch_enable_display();

    watch_rtc_register_tick_callback(cb_tick);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

static void update_tick_frequency(void) {
    watch_rtc_disable_all_periodic_callbacks();
    if (application_state.mode == MODE_BEATS) {
        watch_rtc_register_periodic_callback(cb_fast_tick, BEAT_REFRESH_FREQUENCY);
    } else {
        watch_rtc_register_tick_callback(cb_tick);
    }
}

bool app_loop(void) {
    // play a beep if the mode has changed in response to a user's press of the MODE button
    if (application_state.mode_changed) {
        // low note for nonzero case, high note for return to clock
        watch_buzzer_play_note(application_state.mode ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 100);
        update_tick_frequency();
        application_state.mode_changed = false;
    }

    // If the user is not in clock mode and the mode timeout has expired, return them to clock mode
    if (application_state.mode != MODE_CLOCK && application_state.mode_ticks == 0) {
        application_state.mode = MODE_CLOCK;
        application_state.mode_changed = true;
        update_tick_frequency();
    }

    // If the LED is off and should be on, turn it on
    if (application_state.light_ticks > 0 && !application_state.led_on) {
        watch_set_led_green();
        application_state.led_on = true;
    }

    // if the LED is on and should be off, turn it off
    if (application_state.led_on && application_state.light_ticks == 0) {
        // unless the user is holding down the LIGHT button, in which case, give them more time.
        if (watch_get_pin_level(BTN_LIGHT)) {
            application_state.light_ticks = 3;
        } else {
            watch_set_led_off();
            application_state.led_on = false;
        }
    }

    switch (application_state.mode) {
        case MODE_CLOCK:
            do_clock_mode();
            break;
        case MODE_BEATS:
            do_beats_mode();
            break;
        case MODE_SET:
            do_set_time_mode();
            break;
        case NUM_MODES:
            // dummy case, just silences a warning
            break;
    }

    application_state.mode_changed = false;

    return true;
}

void do_clock_mode(void) {
    watch_date_time date_time = watch_rtc_get_date_time();
    const char months[12][3] = {"JA", "FE", "MR", "AR", "MA", "JN", "JL", "AU", "SE", "OC", "NO", "dE"};

    watch_display_string((char *)months[date_time.unit.month - 1], 0);
    sprintf(buf, "%2d%2d%02d%02d", date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    watch_display_string(buf, 2);
    watch_set_colon();

}

void do_beats_mode(void) {
    watch_clear_colon();

    watch_date_time date_time = watch_rtc_get_date_time();
    float beats = clock2beats(date_time.unit.hour, date_time.unit.minute, date_time.unit.second, UTC_OFFSET);
    sprintf(buf, "bt  %6.0f", beats * 100);

    watch_display_string(buf, 0);
}

float clock2beats(uint16_t hours, uint16_t minutes, uint16_t seconds, int16_t utc_offset) {
    float beats = seconds + ((float)application_state.subsecond / (float)BEAT_REFRESH_FREQUENCY);
    beats += 60 * minutes;
    beats += (float)hours * 60 * 60;
    beats += (1 - utc_offset) * 60 * 60; // offset from utc + 1 since beats in in UTC+1

    beats /= 86.4; // convert to beats
    while(beats > 1000) beats -= 1000; // beats %= 1000 but for a float

    return beats;
}

void do_set_time_mode(void) {
    watch_date_time date_time = watch_rtc_get_date_time();

    watch_display_string("          ", 0);
    switch (application_state.page) {
        case 0: // hour
            sprintf(buf, "ST t%2d", date_time.unit.hour);
            break;
        case 1: // minute
            sprintf(buf, "ST t  %02d", date_time.unit.minute);
            break;
        case 2: // second
            sprintf(buf, "ST t    %02d", date_time.unit.second);
            break;
        case 3: // year
            sprintf(buf, "ST d%2d", date_time.unit.year + 20);
            break;
        case 4: // month
            sprintf(buf, "ST d  %02d", date_time.unit.month);
            break;
        case 5: // day
            sprintf(buf, "ST d    %02d", date_time.unit.day);
            break;
    }
    watch_display_string(buf, 0);
    watch_set_pixel(1, 12); // required for T in position 1
}

void set_time_mode_handle_primary_button(void) {
    application_state.page++;
    if (application_state.page == 6) application_state.page = 0;
}

void set_time_mode_handle_secondary_button(void) {
    watch_date_time date_time = watch_rtc_get_date_time();

    switch (application_state.page) {
        case 0: // hour
            date_time.unit.hour = (date_time.unit.hour + 1) % 24;
            break;
        case 1: // minute
            date_time.unit.minute = (date_time.unit.minute + 1) % 60;
            break;
        case 2: // second
            date_time.unit.second = 0;
            break;
        case 3: // year
            // only allow 2021-2030. fix this sometime next decade
            date_time.unit.year = ((date_time.unit.year % 10) + 1);
            break;
        case 4: // month
            date_time.unit.month = ((date_time.unit.month + 1) % 12);
            break;
        case 5: // day
            date_time.unit.day = date_time.unit.day + 1;
            break;
    }
    if (date_time.unit.day > days_in_month(date_time.unit.month, date_time.unit.year + WATCH_RTC_REFERENCE_YEAR))
        date_time.unit.day = 1;
    watch_rtc_set_date_time(date_time);
}

void cb_mode_pressed(void) {
    application_state.mode = (application_state.mode + 1) % NUM_MODES;
    application_state.mode_changed = true;
    application_state.mode_ticks = 300;
    application_state.page = 0;
}

void cb_light_pressed(void) {
    switch (application_state.mode) {
        case MODE_SET:
            set_time_mode_handle_secondary_button();
            break;
        default:
            application_state.light_ticks = 3;
            break;
    }
}

void cb_alarm_pressed(void) {
    switch (application_state.mode) {
        case MODE_SET:
            set_time_mode_handle_primary_button();
            break;
        default:
            break;
    }
}

void cb_tick(void) {
    if (application_state.light_ticks > 0) {
        application_state.light_ticks--;
    }
    if (application_state.mode_ticks > 0) {
        application_state.mode_ticks--;
    }
}

void cb_fast_tick(void) {
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second != application_state.last_second) {
        application_state.last_second = date_time.unit.second;
        application_state.subsecond = 0;
    } else {
        application_state.subsecond++;
    }
}
