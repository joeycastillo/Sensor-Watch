/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define MOVEMENT_LONG_PRESS_TICKS 64

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "watch.h"
#include "filesystem.h"
#include "movement.h"
#include "shell.h"

#ifndef MOVEMENT_FIRMWARE
#include "movement_config.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_STANDARD
#include "movement_config.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_BACKER
#include "alt_fw/backer.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_ALT_TIME
#include "alt_fw/alt_time.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_FOCUS
#include "alt_fw/focus.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_THE_BACKPACKER
#include "alt_fw/the_backpacker.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_THE_ATHLETE
#include "alt_fw/the_athlete.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_THE_STARGAZER
#include "alt_fw/the_stargazer.h"
#elif MOVEMENT_FIRMWARE == MOVEMENT_FIRMWARE_DEEP_SPACE_NOW
#include "alt_fw/deep_space_now.h"
#endif

#include "movement_custom_signal_tunes.h"

// Default to no secondary face behaviour.
#ifndef MOVEMENT_SECONDARY_FACE_INDEX
#define MOVEMENT_SECONDARY_FACE_INDEX 0
#endif

// Set default LED colors if not set
#ifndef MOVEMENT_DEFAULT_RED_COLOR
#define MOVEMENT_DEFAULT_RED_COLOR 0x0
#endif
#ifndef MOVEMENT_DEFAULT_GREEN_COLOR
#define MOVEMENT_DEFAULT_GREEN_COLOR 0xF
#endif

// Default to 12h mode
#ifndef MOVEMENT_DEFAULT_24H_MODE
#define MOVEMENT_DEFAULT_24H_MODE false
#endif

// Default to mode button sounding on press
#ifndef MOVEMENT_DEFAULT_BUTTON_SOUND
#define MOVEMENT_DEFAULT_BUTTON_SOUND true
#endif

// Default to switch back to main watch face after 60 seconds
#ifndef MOVEMENT_DEFAULT_TIMEOUT_INTERVAL
#define MOVEMENT_DEFAULT_TIMEOUT_INTERVAL 0
#endif

// Default to switch to low energy mode after 2 hours
#ifndef MOVEMENT_DEFAULT_LOW_ENERGY_INTERVAL
#define MOVEMENT_DEFAULT_LOW_ENERGY_INTERVAL 2
#endif

// Default to 1 second led duration
#ifndef MOVEMENT_DEFAULT_LED_DURATION
#define MOVEMENT_DEFAULT_LED_DURATION 1
#endif

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

movement_state_t movement_state;
void * watch_face_contexts[MOVEMENT_NUM_FACES];
watch_date_time scheduled_tasks[MOVEMENT_NUM_FACES];
const int32_t movement_le_inactivity_deadlines[8] = {INT_MAX, 600, 3600, 7200, 21600, 43200, 86400, 604800};
const int16_t movement_timeout_inactivity_deadlines[4] = {60, 120, 300, 1800};
movement_event_t event;

const int16_t movement_timezone_offsets[] = {
    0,      //  0 :   0:00:00 (UTC)
    60,     //  1 :   1:00:00 (Central European Time)
    120,    //  2 :   2:00:00 (South African Standard Time)
    180,    //  3 :   3:00:00 (Arabia Standard Time)
    210,    //  4 :   3:30:00 (Iran Standard Time)
    240,    //  5 :   4:00:00 (Georgia Standard Time)
    270,    //  6 :   4:30:00 (Afghanistan Time)
    300,    //  7 :   5:00:00 (Pakistan Standard Time)
    330,    //  8 :   5:30:00 (Indian Standard Time)
    345,    //  9 :   5:45:00 (Nepal Time)
    360,    // 10 :   6:00:00 (Kyrgyzstan time)
    390,    // 11 :   6:30:00 (Myanmar Time)
    420,    // 12 :   7:00:00 (Thailand Standard Time)
    480,    // 13 :   8:00:00 (China Standard Time, Australian Western Standard Time)
    525,    // 14 :   8:45:00 (Australian Central Western Standard Time)
    540,    // 15 :   9:00:00 (Japan Standard Time, Korea Standard Time)
    570,    // 16 :   9:30:00 (Australian Central Standard Time)
    600,    // 17 :  10:00:00 (Australian Eastern Standard Time)
    630,    // 18 :  10:30:00 (Lord Howe Standard Time)
    660,    // 19 :  11:00:00 (Solomon Islands Time)
    720,    // 20 :  12:00:00 (New Zealand Standard Time)
    765,    // 21 :  12:45:00 (Chatham Standard Time)
    780,    // 22 :  13:00:00 (Tonga Time)
    825,    // 23 :  13:45:00 (Chatham Daylight Time)
    840,    // 24 :  14:00:00 (Line Islands Time)
    -720,   // 25 : -12:00:00 (Baker Island Time)
    -660,   // 26 : -11:00:00 (Niue Time)
    -600,   // 27 : -10:00:00 (Hawaii-Aleutian Standard Time)
    -570,   // 28 :  -9:30:00 (Marquesas Islands Time)
    -540,   // 29 :  -9:00:00 (Alaska Standard Time)
    -480,   // 30 :  -8:00:00 (Pacific Standard Time)
    -420,   // 31 :  -7:00:00 (Mountain Standard Time)
    -360,   // 32 :  -6:00:00 (Central Standard Time)
    -300,   // 33 :  -5:00:00 (Eastern Standard Time)
    -270,   // 34 :  -4:30:00 (Venezuelan Standard Time)
    -240,   // 35 :  -4:00:00 (Atlantic Standard Time)
    -210,   // 36 :  -3:30:00 (Newfoundland Standard Time)
    -180,   // 37 :  -3:00:00 (Brasilia Time)
    -150,   // 38 :  -2:30:00 (Newfoundland Daylight Time)
    -120,   // 39 :  -2:00:00 (Fernando de Noronha Time)
    -60,    // 40 :  -1:00:00 (Azores Standard Time)
};

const char movement_valid_position_0_chars[] = " AaBbCcDdEeFGgHhIiJKLMNnOoPQrSTtUuWXYZ-='+\\/0123456789";
const char movement_valid_position_1_chars[] = " ABCDEFHlJLNORTtUX-='01378";

void cb_mode_btn_interrupt(void);
void cb_light_btn_interrupt(void);
void cb_alarm_btn_interrupt(void);
void cb_alarm_btn_extwake(void);
void cb_alarm_fired(void);
void cb_fast_tick(void);
void cb_tick(void);

static inline void _movement_reset_inactivity_countdown(void) {
    movement_state.le_mode_ticks = movement_le_inactivity_deadlines[movement_state.settings.bit.le_interval];
    movement_state.timeout_ticks = movement_timeout_inactivity_deadlines[movement_state.settings.bit.to_interval];
}

static inline void _movement_enable_fast_tick_if_needed(void) {
    if (!movement_state.fast_tick_enabled) {
        movement_state.fast_ticks = 0;
        watch_rtc_register_periodic_callback(cb_fast_tick, 128);
        movement_state.fast_tick_enabled = true;
    }
}

static inline void _movement_disable_fast_tick_if_possible(void) {
    if ((movement_state.light_ticks == -1) &&
        (movement_state.alarm_ticks == -1) &&
        ((movement_state.light_down_timestamp + movement_state.mode_down_timestamp + movement_state.alarm_down_timestamp) == 0)) {
        movement_state.fast_tick_enabled = false;
        watch_rtc_disable_periodic_callback(128);
    }
}

static void _movement_handle_background_tasks(void) {
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

static void _movement_handle_scheduled_tasks(void) {
    watch_date_time date_time = watch_rtc_get_date_time();
    uint8_t num_active_tasks = 0;

    for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
        if (scheduled_tasks[i].reg) {
            if (scheduled_tasks[i].reg == date_time.reg) {
                scheduled_tasks[i].reg = 0;
                movement_event_t background_event = { EVENT_BACKGROUND_TASK, 0 };
                watch_faces[i].loop(background_event, &movement_state.settings, watch_face_contexts[i]);
                // check if loop scheduled a new task
                if (scheduled_tasks[i].reg) {
                    num_active_tasks++;
                }
            } else {
                num_active_tasks++;
            }
        }
    }

    if (num_active_tasks == 0) {
        movement_state.has_scheduled_background_task = false;
    } else {
        _movement_reset_inactivity_countdown();
    }
}

void movement_request_tick_frequency(uint8_t freq) {
    // Movement uses the 128 Hz tick internally
    if (freq == 128) return;

    // Movement requires at least a 1 Hz tick.
    // If we are asked for an invalid frequency, default back to 1 Hz.
    if (freq == 0 || __builtin_popcount(freq) != 1) freq = 1;

    // disable all callbacks except the 128 Hz one
    watch_rtc_disable_matching_periodic_callbacks(0xFE);

    movement_state.subsecond = 0;
    movement_state.tick_frequency = freq;
    watch_rtc_register_periodic_callback(cb_tick, freq);
}

void movement_illuminate_led(void) {
    if (movement_state.settings.bit.led_duration) {
        watch_set_led_color(movement_state.settings.bit.led_red_color ? (0xF | movement_state.settings.bit.led_red_color << 4) : 0,
                            movement_state.settings.bit.led_green_color ? (0xF | movement_state.settings.bit.led_green_color << 4) : 0);
        movement_state.light_ticks = (movement_state.settings.bit.led_duration * 2 - 1) * 128;
        _movement_enable_fast_tick_if_needed();
    }
}

bool movement_default_loop_handler(movement_event_t event, movement_settings_t *settings) {
    (void)settings;

    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_MODE_LONG_PRESS:
            if (MOVEMENT_SECONDARY_FACE_INDEX && movement_state.current_face_idx == 0) {
                movement_move_to_face(MOVEMENT_SECONDARY_FACE_INDEX);
            } else {
                movement_move_to_face(0);
            }
            break;
        default:
            break;
    }

    return true;
}

void movement_move_to_face(uint8_t watch_face_index) {
    movement_state.watch_face_changed = true;
    movement_state.next_face_idx = watch_face_index;
}

void movement_move_to_next_face(void) {
    uint16_t face_max;
    if (MOVEMENT_SECONDARY_FACE_INDEX) {
        face_max = (movement_state.current_face_idx < (int16_t)MOVEMENT_SECONDARY_FACE_INDEX) ? MOVEMENT_SECONDARY_FACE_INDEX : MOVEMENT_NUM_FACES;
    } else {
        face_max = MOVEMENT_NUM_FACES;
    }
    movement_move_to_face((movement_state.current_face_idx + 1) % face_max);
}

void movement_schedule_background_task(watch_date_time date_time) {
    movement_schedule_background_task_for_face(movement_state.current_face_idx, date_time);
}

void movement_cancel_background_task(void) {
    movement_cancel_background_task_for_face(movement_state.current_face_idx);
}

void movement_schedule_background_task_for_face(uint8_t watch_face_index, watch_date_time date_time) {
    watch_date_time now = watch_rtc_get_date_time();
    if (date_time.reg > now.reg) {
        movement_state.has_scheduled_background_task = true;
        scheduled_tasks[watch_face_index].reg = date_time.reg;
    }
}

void movement_cancel_background_task_for_face(uint8_t watch_face_index) {
    scheduled_tasks[watch_face_index].reg = 0;
    bool other_tasks_scheduled = false;
    for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
        if (scheduled_tasks[i].reg != 0) {
            other_tasks_scheduled = true;
            break;
        }
    }
    movement_state.has_scheduled_background_task = other_tasks_scheduled;
}

void movement_request_wake() {
    movement_state.needs_wake = true;
    _movement_reset_inactivity_countdown();
}

static void end_buzzing() {
    movement_state.is_buzzing = false;
}

static void end_buzzing_and_disable_buzzer(void) {
    end_buzzing();
    watch_disable_buzzer();
}

void movement_play_signal(void) {
    void *maybe_disable_buzzer = end_buzzing_and_disable_buzzer;
    if (watch_is_buzzer_or_led_enabled()) {
        maybe_disable_buzzer = end_buzzing;
    } else {
        watch_enable_buzzer();
    }
    movement_state.is_buzzing = true;
    watch_buzzer_play_sequence(signal_tune, maybe_disable_buzzer);
    if (movement_state.le_mode_ticks == -1) {
        // the watch is asleep. wake it up for "1" round through the main loop.
        // the sleep_mode_app_loop will notice the is_buzzing and note that it
        // only woke up to beep and then it will spinlock until the callback
        // turns off the is_buzzing flag.
        movement_state.needs_wake = true;
        movement_state.le_mode_ticks = 1;
    }
}

void movement_play_alarm(void) {
    movement_play_alarm_beeps(5, BUZZER_NOTE_C8);
}

void movement_play_alarm_beeps(uint8_t rounds, BuzzerNote alarm_note) {
    if (rounds == 0) rounds = 1;
    if (rounds > 20) rounds = 20;
    movement_request_wake();
    movement_state.alarm_note = alarm_note;
    // our tone is 0.375 seconds of beep and 0.625 of silence, repeated as given.
    movement_state.alarm_ticks = 128 * rounds - 75;
    _movement_enable_fast_tick_if_needed();
}

uint8_t movement_claim_backup_register(void) {
    if (movement_state.next_available_backup_register >= 8) return 0;
    return movement_state.next_available_backup_register++;
}

void app_init(void) {
#if defined(NO_FREQCORR)
    watch_rtc_freqcorr_write(0, 0);
#elif defined(WATCH_IS_BLUE_BOARD)
    watch_rtc_freqcorr_write(11, 0);
#else
    watch_rtc_freqcorr_write(22, 0);
#endif

    memset(&movement_state, 0, sizeof(movement_state));

    movement_state.settings.bit.clock_mode_24h = MOVEMENT_DEFAULT_24H_MODE;
    movement_state.settings.bit.led_red_color = MOVEMENT_DEFAULT_RED_COLOR;
    movement_state.settings.bit.led_green_color = MOVEMENT_DEFAULT_GREEN_COLOR;
    movement_state.settings.bit.button_should_sound = MOVEMENT_DEFAULT_BUTTON_SOUND;
    movement_state.settings.bit.to_interval = MOVEMENT_DEFAULT_TIMEOUT_INTERVAL;
    movement_state.settings.bit.le_interval = MOVEMENT_DEFAULT_LOW_ENERGY_INTERVAL;
    movement_state.settings.bit.led_duration = MOVEMENT_DEFAULT_LED_DURATION;
    movement_state.light_ticks = -1;
    movement_state.alarm_ticks = -1;
    movement_state.next_available_backup_register = 4;
    _movement_reset_inactivity_countdown();

    filesystem_init();

#if __EMSCRIPTEN__
    int32_t time_zone_offset = EM_ASM_INT({
        return -new Date().getTimezoneOffset();
    });
    for (int i = 0, count = sizeof(movement_timezone_offsets) / sizeof(movement_timezone_offsets[0]); i < count; i++) {
        if (movement_timezone_offsets[i] == time_zone_offset) {
            movement_state.settings.bit.time_zone = i;
            break;
        }
    }
#endif
}

void app_wake_from_backup(void) {
    movement_state.settings.reg = watch_get_backup_data(0);
}

void app_setup(void) {
    watch_store_backup_data(movement_state.settings.reg, 0);

    static bool is_first_launch = true;

    if (is_first_launch) {
        #ifdef MOVEMENT_CUSTOM_BOOT_COMMANDS
        MOVEMENT_CUSTOM_BOOT_COMMANDS()
        #endif

        for(uint8_t i = 0; i < MOVEMENT_NUM_FACES; i++) {
            watch_face_contexts[i] = NULL;
            scheduled_tasks[i].reg = 0;
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
            watch_faces[i].setup(&movement_state.settings, i, &watch_face_contexts[i]);
        }

        watch_faces[movement_state.current_face_idx].activate(&movement_state.settings, watch_face_contexts[movement_state.current_face_idx]);
        event.subsecond = 0;
        event.event_type = EVENT_ACTIVATE;
    }
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

static void _sleep_mode_app_loop(void) {
    movement_state.needs_wake = false;
    // as long as le_mode_ticks is -1 (i.e. we are in low energy mode), we wake up here, update the screen, and go right back to sleep.
    while (movement_state.le_mode_ticks == -1) {
        // we also have to handle background tasks here in the mini-runloop
        if (movement_state.needs_background_tasks_handled) _movement_handle_background_tasks();

        event.event_type = EVENT_LOW_ENERGY_UPDATE;
        watch_faces[movement_state.current_face_idx].loop(event, &movement_state.settings, watch_face_contexts[movement_state.current_face_idx]);

        // if we need to wake immediately, do it!
        if (movement_state.needs_wake) return;
        // otherwise enter sleep mode, and when the extwake handler is called, it will reset le_mode_ticks and force us out at the next loop.
        else watch_enter_sleep_mode();
    }
}

bool app_loop(void) {
    const watch_face_t *wf = &watch_faces[movement_state.current_face_idx];
    bool woke_up_for_buzzer = false;
    if (movement_state.watch_face_changed) {
        if (movement_state.settings.bit.button_should_sound) {
            // low note for nonzero case, high note for return to watch_face 0
            watch_buzzer_play_note(movement_state.next_face_idx ? BUZZER_NOTE_C7 : BUZZER_NOTE_C8, 50);
        }
        wf->resign(&movement_state.settings, watch_face_contexts[movement_state.current_face_idx]);
        movement_state.current_face_idx = movement_state.next_face_idx;
        // we have just updated the face idx, so we must recache the watch face pointer.
        wf = &watch_faces[movement_state.current_face_idx];
        watch_clear_display();
        movement_request_tick_frequency(1);
        wf->activate(&movement_state.settings, watch_face_contexts[movement_state.current_face_idx]);
        event.subsecond = 0;
        event.event_type = EVENT_ACTIVATE;
        movement_state.watch_face_changed = false;
    }

    // if the LED should be off, turn it off
    if (movement_state.light_ticks == 0) {
        // unless the user is holding down the LIGHT button, in which case, give them more time.
        if (watch_get_pin_level(BTN_LIGHT)) {
            movement_state.light_ticks = 1;
        } else {
            watch_set_led_off();
            movement_state.light_ticks = -1;
            _movement_disable_fast_tick_if_possible();
        }
    }

    // handle background tasks, if the alarm handler told us we need to
    if (movement_state.needs_background_tasks_handled) _movement_handle_background_tasks();

    // if we have a scheduled background task, handle that here:
    if (event.event_type == EVENT_TICK && movement_state.has_scheduled_background_task) _movement_handle_scheduled_tasks();

    // if we have timed out of our low energy mode countdown, enter low energy mode.
    if (movement_state.le_mode_ticks == 0) {
        movement_state.le_mode_ticks = -1;
        watch_register_extwake_callback(BTN_ALARM, cb_alarm_btn_extwake, true);
        event.event_type = EVENT_NONE;
        event.subsecond = 0;

        // _sleep_mode_app_loop takes over at this point and loops until le_mode_ticks is reset by the extwake handler,
        // or wake is requested using the movement_request_wake function.
        _sleep_mode_app_loop();
        // as soon as _sleep_mode_app_loop returns, we prepare to reactivate
        // ourselves, but first, we check to see if we woke up for the buzzer:
        if (movement_state.is_buzzing) {
            woke_up_for_buzzer = true;
        }
        event.event_type = EVENT_ACTIVATE;
        // this is a hack tho: waking from sleep mode, app_setup does get called, but it happens before we have reset our ticks.
        // need to figure out if there's a better heuristic for determining how we woke up.
        app_setup();
    }

    // default to being allowed to sleep by the face.
    bool can_sleep = true;

    if (event.event_type) {
        event.subsecond = movement_state.subsecond;
        // the first trip through the loop overrides the can_sleep state
        can_sleep = wf->loop(event, &movement_state.settings, watch_face_contexts[movement_state.current_face_idx]);
        event.event_type = EVENT_NONE;
    }

    // if we have timed out of our timeout countdown, give the app a hint that they can resign.
    if (movement_state.timeout_ticks == 0) {
        movement_state.timeout_ticks = -1;
        if (movement_state.settings.bit.to_always == false) {
            // if "timeout always" is false, give the current watch face a chance to exit gracefully...
            event.event_type = EVENT_TIMEOUT;
        }
        event.subsecond = movement_state.subsecond;
        // if we run through the loop again to time out, we need to reconsider whether or not we can sleep.
        // if the first trip said true, but this trip said false, we need the false to override, thus
        // we will be using boolean AND:
        //
        // first trip  | can sleep | cannot sleep | can sleep    | cannot sleep
        // second trip | can sleep | cannot sleep | cannot sleep | can sleep
        //          && | can sleep | cannot sleep | cannot sleep | cannot sleep
        bool can_sleep2 = wf->loop(event, &movement_state.settings, watch_face_contexts[movement_state.current_face_idx]);
        can_sleep = can_sleep && can_sleep2;
        event.event_type = EVENT_NONE;
        if (movement_state.settings.bit.to_always && movement_state.current_face_idx != 0) {
            // ...but if the user has "timeout always" set, give it the boot.
            movement_move_to_face(0);
        }
    }

    // Now that we've handled all display update tasks, handle the alarm.
    if (movement_state.alarm_ticks >= 0) {
        uint8_t buzzer_phase = (movement_state.alarm_ticks + 80) % 128;
        if(buzzer_phase == 127) {
            // failsafe: buzzer could have been disabled in the meantime
            if (!watch_is_buzzer_or_led_enabled()) watch_enable_buzzer();
            // play 4 beeps plus pause
            for(uint8_t i = 0; i < 4; i++) {
                // TODO: This method of playing the buzzer blocks the UI while it's beeping.
                // It might be better to time it with the fast tick.
                watch_buzzer_play_note(movement_state.alarm_note, (i != 3) ? 50 : 75);
                if (i != 3) watch_buzzer_play_note(BUZZER_NOTE_REST, 50);
            }
        }
        if (movement_state.alarm_ticks == 0) {
            movement_state.alarm_ticks = -1;
            _movement_disable_fast_tick_if_possible();
        }
    }

    // if we are plugged into USB, handle the serial shell
    if (watch_is_usb_enabled()) {
        shell_task();
    }

    event.subsecond = 0;

    // if the watch face changed, we can't sleep because we need to update the display.
    if (movement_state.watch_face_changed) can_sleep = false;

    // if we woke up for the buzzer, stay awake until it's finished.
    if (woke_up_for_buzzer) {
        while(watch_is_buzzer_or_led_enabled());
    }

    // if the LED is on, we need to stay awake to keep the TCC running.
    if (movement_state.light_ticks != -1) can_sleep = false;

    return can_sleep;
}

static movement_event_type_t _figure_out_button_event(bool pin_level, movement_event_type_t button_down_event_type, uint16_t *down_timestamp) {
    // force alarm off if the user pressed a button.
    if (movement_state.alarm_ticks) movement_state.alarm_ticks = 0;

    if (pin_level) {
        // handle rising edge
        _movement_enable_fast_tick_if_needed();
        *down_timestamp = movement_state.fast_ticks + 1;
        return button_down_event_type;
    } else {
        // this line is hack but it handles the situation where the light button was held for more than 20 seconds.
        // fast tick is disabled by then, and the LED would get stuck on since there's no one left decrementing light_ticks.
        if (movement_state.light_ticks == 1) movement_state.light_ticks = 0;
        // now that that's out of the way, handle falling edge
        uint16_t diff = movement_state.fast_ticks - *down_timestamp;
        *down_timestamp = 0;
        _movement_disable_fast_tick_if_possible();
        // any press over a half second is considered a long press. Fire the long-up event
        if (diff > MOVEMENT_LONG_PRESS_TICKS) return button_down_event_type + 3;
        else return button_down_event_type + 1;
    }
}

void cb_light_btn_interrupt(void) {
    bool pin_level = watch_get_pin_level(BTN_LIGHT);
    _movement_reset_inactivity_countdown();
    event.event_type = _figure_out_button_event(pin_level, EVENT_LIGHT_BUTTON_DOWN, &movement_state.light_down_timestamp);
}

void cb_mode_btn_interrupt(void) {
    bool pin_level = watch_get_pin_level(BTN_MODE);
    _movement_reset_inactivity_countdown();
    event.event_type = _figure_out_button_event(pin_level, EVENT_MODE_BUTTON_DOWN, &movement_state.mode_down_timestamp);
}

void cb_alarm_btn_interrupt(void) {
    bool pin_level = watch_get_pin_level(BTN_ALARM);
    _movement_reset_inactivity_countdown();
    event.event_type = _figure_out_button_event(pin_level, EVENT_ALARM_BUTTON_DOWN, &movement_state.alarm_down_timestamp);
}

void cb_alarm_btn_extwake(void) {
    // wake up!
    _movement_reset_inactivity_countdown();
}

void cb_alarm_fired(void) {
    movement_state.needs_background_tasks_handled = true;
}

void cb_fast_tick(void) {
    movement_state.fast_ticks++;
    if (movement_state.light_ticks > 0) movement_state.light_ticks--;
    if (movement_state.alarm_ticks > 0) movement_state.alarm_ticks--;
    // check timestamps and auto-fire the long-press events
    // Notice: is it possible that two or more buttons have an identical timestamp? In this case
    // only one of these buttons would receive the long press event. Don't bother for now...
    if (movement_state.light_down_timestamp > 0)
        if (movement_state.fast_ticks - movement_state.light_down_timestamp == MOVEMENT_LONG_PRESS_TICKS + 1)
            event.event_type = EVENT_LIGHT_LONG_PRESS;
    if (movement_state.mode_down_timestamp > 0)
        if (movement_state.fast_ticks - movement_state.mode_down_timestamp == MOVEMENT_LONG_PRESS_TICKS + 1)
            event.event_type = EVENT_MODE_LONG_PRESS;
    if (movement_state.alarm_down_timestamp > 0)
        if (movement_state.fast_ticks - movement_state.alarm_down_timestamp == MOVEMENT_LONG_PRESS_TICKS + 1)
            event.event_type = EVENT_ALARM_LONG_PRESS;
    // this is just a fail-safe; fast tick should be disabled as soon as the button is up, the LED times out, and/or the alarm finishes.
    // but if for whatever reason it isn't, this forces the fast tick off after 20 seconds.
    if (movement_state.fast_ticks >= 128 * 20) {
        watch_rtc_disable_periodic_callback(128);
        movement_state.fast_tick_enabled = false;
    }
}

void cb_tick(void) {
    event.event_type = EVENT_TICK;
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second != movement_state.last_second) {
        // TODO: can we consolidate these two ticks?
        if (movement_state.settings.bit.le_interval && movement_state.le_mode_ticks > 0) movement_state.le_mode_ticks--;
        if (movement_state.timeout_ticks > 0) movement_state.timeout_ticks--;

        movement_state.last_second = date_time.unit.second;
        movement_state.subsecond = 0;
    } else {
        movement_state.subsecond++;
    }
}
