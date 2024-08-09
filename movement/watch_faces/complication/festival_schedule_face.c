/*
 * MIT License
 *
 * Copyright (c) 2024 <David Volovskiy>
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

#include <stdlib.h>
#include <string.h>
#include "festival_schedule_face.h"
#include "festival_schedule_arr.h"
#include "watch_utility.h"

const char festival_name[2] = "EF";

const char festival_stage[STAGE_COUNT + 1][2] =
{
    [NO_STAGE] = "  ",
    [RANCH_ARENA] = "Rn",
    [SHERWOOD_COURT] = "SH",
    [TRIPOLEE] = "TR",
    [CAROUSEL_CLUB] = "CC",
    [OBSERVATORY] = "OB",
    [HONEYCOMB] = "HC",
    [STAGE_COUNT] = "  "
};

const char festival_genre[GENRE_COUNT + 1][6] =
{
    [NO_GENRE] = " NONE ",
    [BASS] = " BASS ",
    [DUBSTEP] = "DUBStP",
    [DnB] = " dnB  ",
    [HOUSE] = " HOUSE",
    [DANCE] = " DaNCE",
    [TECHNO] = " tECNO",
    [INDIE] = " INdIE",
    [POP] = " POP  ",
    [JAM] = " Jan& ",
    [CHILL] = " Chill",
    [RAP] = "  rAP ",
    [SOUL] = " SOUL ",
    [GENRE_COUNT] = "      "
};

static watch_date_time _starting_time;
static watch_date_time _ending_time;
static bool _quick_ticks_running;
static uint8_t _ts_ticks;
static uint8_t _ts_ticks_purpose;
static const uint8_t _act_arr_size = sizeof(festival_acts) / sizeof(schedule_t);


static uint8_t _get_next_act_num(uint8_t act_num, bool get_prev){
    int increment = get_prev ? -1 : 1;
    uint8_t next_act = act_num;
    do{
       next_act = (next_act + increment + _act_arr_size) % _act_arr_size;
    }
    while (festival_acts[next_act].start_time.reg == 0);
    return next_act;
}


// Returns 0 if they're the same; Positive if dt1 is newer than dt2; Negative o/w
static int _compare_dates_times(watch_date_time dt1, watch_date_time dt2) {
    if (dt1.unit.year != dt2.unit.year) {
        return dt1.unit.year - dt2.unit.year;
    }
    if (dt1.unit.month != dt2.unit.month) {
        return dt1.unit.month - dt2.unit.month;
    }
    if (dt1.unit.day != dt2.unit.day) {
        return dt1.unit.day - dt2.unit.day;
    }
    if (dt1.unit.hour != dt2.unit.hour) {
        return dt1.unit.hour - dt2.unit.hour;
    }
    return dt1.unit.minute - dt2.unit.minute;
}

// Returns -1 if already passed, o/w days until start.
static int16_t _get_days_until(watch_date_time start_time, watch_date_time curr_time){
    start_time.unit.hour = start_time.unit.minute = start_time.unit.second = 0;
    curr_time.unit.hour = curr_time.unit.minute = curr_time.unit.second = 0;
    uint32_t now_timestamp = watch_utility_date_time_to_unix_time(curr_time, 0);
    uint32_t start_timestamp = watch_utility_date_time_to_unix_time(start_time, 0);
    int16_t days_until;
    if (now_timestamp > start_timestamp) // Date already passed
        days_until = -1;
    else
        days_until = (start_timestamp - now_timestamp) / (60 * 60 * 24);
    return days_until;
}

static bool _act_is_playing(uint8_t act_num, watch_date_time curr_time){
    if (act_num == NUM_ACTS) return false;
    return _compare_dates_times(festival_acts[act_num].start_time, curr_time) <= 0 && _compare_dates_times(curr_time, festival_acts[act_num].end_time) < 0;
}

static uint8_t _act_performing_on_stage(uint8_t stage, watch_date_time curr_time)
{
    for (int i = 0; i < NUM_ACTS; i++) {
        if (festival_acts[i].stage == stage && _act_is_playing(i, curr_time))
            return i;
    }
    return NUM_ACTS;
}

static uint8_t _find_first_available_act(uint8_t first_stage_to_check, watch_date_time curr_time, bool reverse)
{
    int increment = reverse ? -1 : 1;
    uint8_t last_stage = (first_stage_to_check - increment + STAGE_COUNT) % STAGE_COUNT;
    for (int i = first_stage_to_check;; i = (i + increment + STAGE_COUNT) % STAGE_COUNT) {
        uint8_t act_num = _act_performing_on_stage(i, curr_time);
        if (act_num != NUM_ACTS)
            return act_num;
        if (i == last_stage) break;
    }
    return NUM_ACTS;
}

static void _display_act(festival_schedule_state_t *state){
    char buf[11];
    uint8_t popularity = festival_acts[state->curr_act].popularity;
    state->curr_screen = SCREEN_ACT;
    if (popularity > 0 && popularity < 40)
        sprintf(buf, "%.2s%2d%.6s", festival_stage[state->curr_stage], festival_acts[state->curr_act].popularity, festival_acts[state->curr_act].artist);
    else
        sprintf(buf, "%.2s  %.6s", festival_stage[state->curr_stage], festival_acts[state->curr_act].artist);
    watch_display_string(buf , 0);
}

static void _display_act_genre(uint8_t act_num, bool show_weekday){
    char buf[11];
    if (show_weekday){
        watch_date_time start_time = festival_acts[act_num].start_time;
        if (start_time.unit.hour < 5)
            start_time.reg = start_time.reg - (1<<17); // Subtract a day if the act starts before 5am.
        sprintf(buf, "%s G%.6s", watch_utility_get_weekday(start_time), festival_genre[festival_acts[act_num].genre]);
        watch_display_string(buf , 0);
    }
    else{
        sprintf(buf, " G%.6s", festival_genre[festival_acts[act_num].genre]);
        watch_display_string(buf , 2);
    }
}

static void _display_act_time(uint8_t act_num, bool clock_mode_24h, bool display_end){
    char buf[11];
    watch_date_time disp_time = display_end ? festival_acts[act_num].end_time : festival_acts[act_num].start_time;
    watch_set_colon();
    if (clock_mode_24h){
        watch_set_indicator(WATCH_INDICATOR_24H);

    }
    else{
        watch_clear_indicator(WATCH_INDICATOR_24H);
        // if we are in 12 hour mode, do some cleanup.
        if (disp_time.unit.hour < 12) {
            watch_clear_indicator(WATCH_INDICATOR_PM);
        } else {
            watch_set_indicator(WATCH_INDICATOR_PM);
        }
        disp_time.unit.hour %= 12;
        if (disp_time.unit.hour == 0) disp_time.unit.hour = 12;
    }
    sprintf(buf, "%s%2d%2d%.2d%s", watch_utility_get_weekday(disp_time), disp_time.unit.day, disp_time.unit.hour, disp_time.unit.minute, display_end ? "Ed" : "St");
    watch_display_string(buf, 0);
}

static void _display_screen(festival_schedule_state_t *state, bool clock_mode_24h){
    _ts_ticks = 10;
    _ts_ticks_purpose = TICK_SCREEN;
    if (state->curr_screen != SCREEN_START_TIME && state->curr_screen != SCREEN_END_TIME)
    {
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_24H);
        watch_clear_indicator(WATCH_INDICATOR_PM);
    }
    switch (state->curr_screen)
    {
    case SCREEN_ACT:
    case SCREENS_COUNT:
        _display_act(state);
        break;
    case SCREEN_GENRE:
        _display_act_genre(state->curr_act, state->cyc_through_all_acts);
        break;
    case SCREEN_START_TIME:
        _display_act_time(state->curr_act, clock_mode_24h, false);
        break;
    case SCREEN_END_TIME:
        _display_act_time(state->curr_act, clock_mode_24h, true);
        break;
    }
}

static watch_date_time _get_starting_time(void){
    watch_date_time date_oldest = festival_acts[0].start_time;
    for (int i = 1; i < NUM_ACTS; i++) {
        if (festival_acts[i].artist[0] == 0) continue;
        watch_date_time date_check = festival_acts[i].start_time;
        if (_compare_dates_times(date_check, date_oldest) < 0)
            date_oldest= date_check;
    }
    return date_oldest;
}

static watch_date_time _get_ending_time(void){
    watch_date_time date_newest = festival_acts[0].end_time;
    for (int i = 1; i < NUM_ACTS; i++) {
        watch_date_time date_check = festival_acts[i].end_time;
        if (_compare_dates_times(date_check, date_newest) > 0)
            date_newest= date_check;
    }
    return date_newest;
}

static bool _festival_occurring(watch_date_time curr_time, bool update_display){
    char buf[15];
    if (_compare_dates_times(_starting_time, curr_time) > 0){
        if (update_display){
            int16_t days_until = _get_days_until(_starting_time, curr_time);
            if (days_until == 0) return true;
            if (days_until <= 999){
                if (days_until > 99) sprintf(buf, "%.2s%02d%3dday", festival_name, _starting_time.unit.year + 20, days_until);
                else sprintf(buf, "%.2s%02d%2d day", festival_name, _starting_time.unit.year + 20, days_until);
            }
            else sprintf(buf, "%.2s%02dWAIT  ", festival_name, _starting_time.unit.year + 20);
            watch_display_string(buf , 0);
        }
        return false;
    }
    else if (_compare_dates_times(_ending_time, curr_time) <= 0){
        if (update_display){
            sprintf(buf, "%.2s%02dOVER  ", festival_name, _starting_time.unit.year + 20);
            watch_display_string(buf , 0);
        }
        return false;
    }
    return true;
}

static void _display_curr_day(watch_date_time curr_time){  // Assumes festival_occurring function was run before it.
    char buf[13];
    int16_t days_until = _get_days_until(curr_time, _starting_time) + 1;
    if (days_until < 100 && days_until >= 0)
        sprintf(buf, "%.2s%02d day%2d", festival_name, _starting_time.unit.year + 20, days_until);
    else
        sprintf(buf, "%.2s%02d LONg ", festival_name, _starting_time.unit.year + 20);
    watch_display_string(buf , 0);
    return;
}

void festival_schedule_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(festival_schedule_state_t));
        memset(*context_ptr, 0, sizeof(festival_schedule_state_t));
        festival_schedule_state_t *state = (festival_schedule_state_t *)*context_ptr;
        state->curr_act = NUM_ACTS;
        state->prev_act = NUM_ACTS + 1;
        state -> prev_day = 0;
        state->cyc_through_all_acts = false;
        state->curr_screen = SCREEN_ACT;
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

static void _cyc_all_acts(festival_schedule_state_t *state, bool clock_mode_24h, bool handling_light){
    state->cyc_through_all_acts = true;
    watch_set_indicator(WATCH_INDICATOR_LAP);
    state->curr_act = _get_next_act_num(state->curr_act, handling_light);
    state->curr_stage = festival_acts[state->curr_act].stage;
    state->curr_screen = SCREEN_ACT;
    _display_screen(state, clock_mode_24h);
    state->showing_title = false;
    return; 
}

static void _handle_btn_up(festival_schedule_state_t *state, bool clock_mode_24h, bool handling_light){
    _ts_ticks = 0;
    _ts_ticks_purpose = TICK_NONE;
    if (state->cyc_through_all_acts){
        _cyc_all_acts(state, clock_mode_24h, handling_light);
        return;
    }
    if (!state->festival_occurring) return;
    watch_date_time curr_time = watch_rtc_get_date_time();
    if (!state->showing_title) state->curr_stage = handling_light ? (state->curr_stage - 1 + STAGE_COUNT) % STAGE_COUNT : (state->curr_stage + 1) % STAGE_COUNT;
    else state->showing_title = false;
    if (SHOW_EMPTY_STAGES)
        state->curr_act = _act_performing_on_stage(state->curr_stage, curr_time);
    else{
        state->curr_act = _find_first_available_act(state->curr_stage, curr_time, handling_light);
        state->curr_stage = festival_acts[state->curr_act].stage;
    }
    state->curr_screen = SCREEN_ACT;
    _display_screen(state, clock_mode_24h);
}

static void _show_title(festival_schedule_state_t *state){
    state->showing_title = true;
    state->curr_act = NUM_ACTS;
    watch_clear_colon();
    watch_clear_all_indicators();
    state->cyc_through_all_acts = false;
    watch_date_time curr_time = watch_rtc_get_date_time();
    state -> prev_day = (curr_time.reg >> 17);
    state -> festival_occurring = _festival_occurring(curr_time, true);
    if (state -> festival_occurring) _display_curr_day(curr_time);
}

static void start_quick_cyc(void){
    _quick_ticks_running = true;
    movement_request_tick_frequency(8);
}

static void handle_ts_ticks(festival_schedule_state_t *state, bool clock_mode_24h){
    static bool _light_held;
    if (_light_held){
        if (!watch_get_pin_level(BTN_LIGHT)) _light_held = false;
        else return;
    }
    if (_ts_ticks != 0){
        --_ts_ticks;
        switch (_ts_ticks_purpose){
            case TICK_NONE:
                _ts_ticks = 0;
                break;
            case TICK_SCREEN:
                if (state->showing_title || state->curr_screen == SCREEN_ACT){
                    _ts_ticks = 0;
                }
                else if (_ts_ticks == 0){
                    if(watch_get_pin_level(BTN_LIGHT)){
                        _ts_ticks = 1; // Give one extra second of delay when the light is on
                        _light_held = true;
                    }
                    else{
                        _ts_ticks_purpose = TICK_NONE;
                        state->curr_screen = SCREEN_ACT;
                        _display_screen(state, clock_mode_24h);
                    }
                }
                break;
            case TICK_LEAVE:
                if (!watch_get_pin_level(BTN_MODE))_ts_ticks = 0;
                else if (_ts_ticks == 0){
                    if(state -> showing_title) movement_move_to_face(0);
                    else{
                        _ts_ticks_purpose = TICK_LEAVE;  // This is unneeded, but explicit that we remain in TICK_LEAVE
                        _ts_ticks = 2;
                        _show_title(state);
                    }
                }
                break;
            case TICK_CYCLE:
                if (_ts_ticks == 0){
                    _ts_ticks_purpose = TICK_NONE;
                    start_quick_cyc();
                }
                break;
        }
    }
}

void festival_schedule_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    _starting_time = _get_starting_time();
    _ending_time = _get_ending_time();
    _quick_ticks_running = false;
    _ts_ticks = 0;
    _ts_ticks_purpose = TICK_NONE;
}

bool festival_schedule_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    festival_schedule_state_t *state = (festival_schedule_state_t *)context;
    watch_date_time curr_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _show_title(state);
            break;
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            if (_quick_ticks_running) {
                if (watch_get_pin_level(BTN_LIGHT)) _handle_btn_up(state, settings->bit.clock_mode_24h, true);
                else if (watch_get_pin_level(BTN_ALARM)) _handle_btn_up(state, settings->bit.clock_mode_24h, false);
                else{
                    _quick_ticks_running = false;
                    movement_request_tick_frequency(1);
                }
            }
            handle_ts_ticks(state, settings->bit.clock_mode_24h);

            if (state->cyc_through_all_acts) break;
            curr_time = watch_rtc_get_date_time();
            bool newDay = ((curr_time.reg >> 17) != (state -> prev_day));
            state -> prev_day = (curr_time.reg >> 17);
            state -> festival_occurring = _festival_occurring(curr_time, (newDay && !state->cyc_through_all_acts));
            if (!state->festival_occurring) break;
            if(state->showing_title){
                if (newDay) _display_curr_day(curr_time);
                break;
            }
            if (!_act_is_playing(state->curr_act, curr_time)){
                if (SHOW_EMPTY_STAGES)   
                    state->curr_act = NUM_ACTS;
                else{
                    state->curr_act = _find_first_available_act(state->curr_stage, curr_time, false);
                    state->curr_stage = festival_acts[state->curr_act].stage;
                } 
            }
            if ((state->curr_stage == state->prev_stage) && (state->curr_act == state->prev_act)) break;
            state->prev_stage = state->curr_stage;
            state->prev_act = state->curr_act;
            _display_act(state);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            _handle_btn_up(state, settings->bit.clock_mode_24h, true);
            break;
        case EVENT_ALARM_BUTTON_UP:
            _handle_btn_up(state, settings->bit.clock_mode_24h, false);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->showing_title){
                _cyc_all_acts(state, settings->bit.clock_mode_24h, false);
                _ts_ticks = 2;
                _ts_ticks_purpose = TICK_CYCLE;
            }
            else if (state->festival_occurring && !state->cyc_through_all_acts) break;
            else start_quick_cyc();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;  // To overwrite the default LED on
        case EVENT_LIGHT_LONG_PRESS:
            if (state->showing_title){
                _cyc_all_acts(state, settings->bit.clock_mode_24h, true);
                _ts_ticks = 2;
                _ts_ticks_purpose = TICK_CYCLE;
            }
            else if (state->curr_screen != SCREEN_ACT || (state->festival_occurring && !state->cyc_through_all_acts))
                movement_illuminate_led(); // Will allow led for see acts' genre and times
            else start_quick_cyc();
            break;
        case EVENT_MODE_LONG_PRESS:
            if (state->curr_screen != SCREEN_ACT){
                state->curr_screen = SCREEN_ACT;
                _display_screen(state, settings->bit.clock_mode_24h);
                _ts_ticks = 2;
                _ts_ticks_purpose = TICK_LEAVE;
            }
            else if (!state->showing_title){
                _ts_ticks = 2;
                _ts_ticks_purpose = TICK_LEAVE;
                _show_title(state);
            }
            else movement_move_to_face(0);
            break;
        case EVENT_MODE_BUTTON_UP:
            if (state->showing_title) movement_move_to_next_face();
            else if (state->curr_act != NUM_ACTS){
                state->curr_screen = (state->curr_screen + 1) % SCREENS_COUNT;
                _display_screen(state, settings->bit.clock_mode_24h);
            }
            break;
        case EVENT_TIMEOUT:
            if (state->cyc_through_all_acts){
                state->cyc_through_all_acts = false;
                _show_title(state);
            }
            break;
        default:
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void festival_schedule_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    festival_schedule_state_t *state = (festival_schedule_state_t *)context;
    state->curr_act = NUM_ACTS;
    state->cyc_through_all_acts = false;
    state->prev_act = NUM_ACTS + 1;

    // handle any cleanup before your watch face goes off-screen.
}

