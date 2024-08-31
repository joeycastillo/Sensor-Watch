/*
 * MIT License
 *
 * Copyright (c) 2022 Wesley Ellis
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
#include "si1133_uv_face.h"

void fatal_error(char *error_msg, si1133_fatal_error_codes error_no, uint8_t extra);

void fatal_error(char *error_msg, si1133_fatal_error_codes error_no, uint8_t extra) {
    char buf[13];
    watch_set_colon();
    sprintf(buf, "    %02x%0x   ", error_no, extra);
    watch_display_string(buf, 0);
    uint8_t loops = 60;
    while(loops--) {
        printf("%s\r\n", error_msg);

        watch_set_indicator(WATCH_INDICATOR_BELL);
        watch_set_led_yellow();

        delay_ms(500);
        watch_clear_all_indicators();
        watch_set_led_color(0,0);
        delay_ms(500);
    }
    NVIC_SystemReset();
}

void si1133_uv_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) watch_face_index;
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(si1133_uv_state_t));
        memset(*context_ptr, 0, sizeof(si1133_uv_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
        si1133_uv_state_t *state = (si1133_uv_state_t *)*context_ptr;
        state->mode = si1133_mode_measuring;
        state->needs_setup = true;
        state->current_mux = SI1133_ADCMUX_UV;
        state->current_hw_gain = SI1133_HW_GAIN_11;
        state->current_sw_gain = SI1133_SW_GAIN_0;
        state->hist_mode = si1133_hist_last_ten;
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
    si1133_init();
}

void si1133_uv_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;

    si1133_uv_state_t *state = (si1133_uv_state_t *)context;
    state->needs_setup = true;
}

// this is where we draw the settings
static void settings_draw(si1133_uv_state_t *state) {
    char buf[13];
    switch (state->setting) {
        case si1133_adcmux_setting:
            sprintf(buf, "LI    %02x  ", state->current_mux);
            break;
        case si1133_sw_gain_setting:
            sprintf(buf, "SG    %02x  ", state->current_sw_gain);
            break;
        case si1133_hw_gain_setting:
            sprintf(buf, "HG    %02x  ", state->current_hw_gain);
            break;
    }
    watch_display_string(buf, 0);
}

static void __attribute__((optimize("O0"))) save_history(si1133_uv_state_t *state, uint32_t volatile new_reading) {
    state->history[state->hist_loc] = new_reading;
    state->hist_loc = (state->hist_loc + 1) % SI1133_HIST_LEN;
}

static uint16_t get_history_last_ten(si1133_uv_state_t *state) {
    uint32_t history = 0;
    size_t marker = state->hist_loc;
    for(int i = 0; i < 10; i++) {
        history = history + state->history[marker];
        if (marker == 0) {
            marker = SI1133_HIST_LEN;
        }
        marker--;
    }
    history /= 10;
    return (uint16_t) history;
}

static uint16_t get_history_all(si1133_uv_state_t *state) {
    uint32_t history = 0;
    for(int i = 0; i < SI1133_HIST_LEN; i++) {
        history += state->history[i];
    }
    history /= SI1133_HIST_LEN;
    return (uint16_t) history;
}

static void main_draw(si1133_uv_state_t *state) {
    char buf[13];

    if(state->flipflop) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
    state->flipflop = !state->flipflop;

    if (state->needs_setup) {
        si1133_configure_channel(
                SI1133_CHAN_0,
                state->current_mux,
                SI1133_DECIM_0,
                SI1133_RANGING_OFF,
                state->current_hw_gain,
                state->current_sw_gain,
                SI1133_24_BIT,
                SI1133_POST_SHIFT_0,
                SI1133_THRESH_DISABLE,
                SI1133_COUNTER_DISABLE
                );
        state->needs_setup = false;
    }

    watch_set_indicator(WATCH_INDICATOR_SIGNAL);

    si1133_start_measurement();
    si1133_response0_status status;
    status = si1133_check_errors();
    if (status) {
        if (status == SI1133_ERR_SATURATION) {
            watch_display_string("    overfl", 0);
            //TODO maybe reset if this happens
            goto out;
        } else {
            fatal_error("failed to start mesaurement", SI1133_FORCE_FAIL, status);
        }
    }


    uint32_t ticks = 0;
    uint32_t delay = 50;
    const uint32_t timeout_s = 10;
    uint8_t irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
    while(irq_status != 0x01) {
        delay_ms(delay);
        ticks++;
        if (ticks & 0x80) {
            watch_set_colon();
        } else {
            watch_clear_colon();
        }
        if ((ticks * delay) > (timeout_s * 1000)) {
            fatal_error("timeout!", SI1133_TIMEOUT, 0);
            break;
        }
        irq_status = watch_i2c_read8(SI1133_ADDR, SI1133_REG_IRQ_STATUS);
    }
    printf("ticks %lud\r\n", ticks);

    uint8_t hostout0 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT0);
    uint8_t hostout1 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT1);
    uint8_t hostout2 = watch_i2c_read8(SI1133_ADDR, SI1133_REG_HOSTOUT2);
    uint32_t adccount = (hostout0 << 16) | (hostout1 << 8) | (hostout2);
    save_history(state, adccount);
    uint32_t to_draw = 0;
    uint8_t hist_mode = 0;
    switch(state->hist_mode) {
        case si1133_hist_current:
            to_draw = adccount;
            hist_mode = 1;
            break;
        case si1133_hist_last_ten:
            to_draw = get_history_last_ten(state);
            hist_mode = 0xa;
            break;
        case si1133_hist_all:
            to_draw = get_history_all(state);
            hist_mode = 0x80;
            break;
    }
    sprintf(buf, "%02x%08lx", hist_mode, to_draw);
    watch_display_string(buf, 0);
    printf("reading: %08lx\r\n", adccount);
    printf("reading count: %02x\r\n", state->readings);
    printf("current mux: %02x\r\n", state->current_mux);
    state->readings++;

out:
    watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

static void setting_alarm_button(si1133_uv_state_t *state) {
    switch(state->setting) {
        case si1133_adcmux_setting:
            switch (state->current_mux) {
                case SI1133_ADCMUX_SMALL_IR:
                    state->current_mux = SI1133_ADCMUX_MEDIUM_IR;
                    break;
                case SI1133_ADCMUX_MEDIUM_IR:
                    state->current_mux = SI1133_ADCMUX_LARGE_IR;
                    break;
                case SI1133_ADCMUX_LARGE_IR:
                    state->current_mux = SI1133_ADCMUX_WHITE;
                    break;
                case SI1133_ADCMUX_WHITE:
                    state->current_mux = SI1133_ADCMUX_LARGE_WHITE;
                    break;
                case SI1133_ADCMUX_LARGE_WHITE:
                    state->current_mux = SI1133_ADCMUX_UV;
                    break;
                case SI1133_ADCMUX_UV:
                    state->current_mux = SI1133_ADCMUX_UV_DEEP;
                    break;
                case SI1133_ADCMUX_UV_DEEP:
                    state->current_mux = SI1133_ADCMUX_SMALL_IR;
                    break;
            }
            break;
        case si1133_sw_gain_setting:
            state->current_sw_gain = (state->current_sw_gain + 1) % 8;
            break;
        case si1133_hw_gain_setting:
            state->current_hw_gain = (state->current_hw_gain + 1) % 12;
            break;
    }
    state->needs_setup = true;
}

void measuring_alarm_button(si1133_uv_state_t *state) {
    switch(state->hist_mode) {
        case si1133_hist_all:
            state->hist_mode = si1133_hist_current;
            break;
        case si1133_hist_last_ten:
            state->hist_mode = si1133_hist_all;
            break;
        case si1133_hist_current:
            state->hist_mode = si1133_hist_last_ten;
            break;
    }
}

bool si1133_uv_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    si1133_uv_state_t *state = (si1133_uv_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            switch(state->mode) {
                case si1133_mode_measuring:
                    main_draw(state);
                    break;
                case si1133_mode_setting:
                    settings_draw(state);
                    break;
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            if(state->mode == si1133_mode_setting) {
                switch(state->setting) {
                    case si1133_adcmux_setting:
                        state->setting = si1133_sw_gain_setting;
                        break;
                    case si1133_sw_gain_setting:
                        state->setting = si1133_hw_gain_setting;
                        break;
                    case si1133_hw_gain_setting:
                        state->setting = si1133_adcmux_setting;
                        break;
                }
            } else {
                movement_move_to_next_face();
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch(state->mode) {
                case si1133_mode_measuring:
                    state->mode = si1133_mode_setting;
                    break;
                case si1133_mode_setting:
                    state->mode = si1133_mode_measuring;
                    break;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (state->mode) {
                case si1133_mode_setting:
                    setting_alarm_button(state);
                    break;
                case si1133_mode_measuring:
                    measuring_alarm_button(state);
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            break;
    }

    // return true if the watch can enter standby mode. If you are PWM'ing an LED or buzzing the buzzer here,
    // you should return false since the PWM driver does not operate in standby mode.
    return true;
}

void si1133_uv_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

