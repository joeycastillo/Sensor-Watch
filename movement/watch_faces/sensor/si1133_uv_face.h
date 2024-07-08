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

#ifndef SI1133_UV_FACE_H_
#define SI1133_UV_FACE_H_

#include "movement.h"
#include "si1133.h"

typedef enum {
    si1133_mode_measuring,
    si1133_mode_setting
} si1133_mode;

typedef enum {
    si1133_hist_current,
    si1133_hist_last_ten,
    si1133_hist_all,
} si1133_hist_mode;

typedef enum {
    si1133_adcmux_setting,
    si1133_sw_gain_setting,
    si1133_hw_gain_setting
} si1133_setting;

#define SI1133_HIST_LEN 128

typedef struct {
    si1133_mode mode;
    si1133_setting setting;
    bool flipflop;
    uint8_t readings;
    bool needs_setup;
    si1133_adcmux current_mux;
    si1133_hw_gain current_hw_gain;
    si1133_sw_gain current_sw_gain;
    si1133_hist_mode hist_mode;
    uint16_t history[SI1133_HIST_LEN];
    size_t hist_loc;
} si1133_uv_state_t;

void si1133_uv_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void si1133_uv_face_activate(movement_settings_t *settings, void *context);
bool si1133_uv_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void si1133_uv_face_resign(movement_settings_t *settings, void *context);

#define si1133_uv_face ((const watch_face_t){ \
    si1133_uv_face_setup, \
    si1133_uv_face_activate, \
    si1133_uv_face_loop, \
    si1133_uv_face_resign, \
    NULL, \
})

#endif // SI1133_UV_FACE_H_

