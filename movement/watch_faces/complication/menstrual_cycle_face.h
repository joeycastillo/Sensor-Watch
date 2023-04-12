/*
 * MIT License
 *
 * Copyright (c) 2022 Joseph Komosa
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

#ifndef MENSTRUAL_CYCLE_FACE_H_
#define MENSTRUAL_CYCLE_FACE_H_

#include "movement.h"

typedef struct {
    union {
        struct {
            uint8_t first_day : 5;
            uint8_t first_month : 4;
            uint8_t first_year : 7; // Decade resolution only, up to 2099
            uint16_t total_cycles : 16;
        } bit; 
        uint32_t reg;
    } average; // Save the date of the first logged period and the total cycles since to calulate the average menstrual cycle
    struct {
        uint8_t current_page : 3;
        uint8_t backup_register : 3;
        bool period_today : 1;
        bool reset_tracking : 1;
    } bits;
    uint8_t days_since; // Days since the last period
} menstrual_cycle_state_t;

void menstrual_cycle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void menstrual_cycle_face_activate(movement_settings_t *settings, void *context);
bool menstrual_cycle_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void menstrual_cycle_face_resign(movement_settings_t *settings, void *context);

uint16_t get_total_days(movement_settings_t *settings, menstrual_cycle_state_t *state);
uint16_t get_days_till_period(movement_settings_t *settings, menstrual_cycle_state_t *state);

#define menstrual_cycle_face ((const watch_face_t){ \
    menstrual_cycle_face_setup, \
    menstrual_cycle_face_activate, \
    menstrual_cycle_face_loop, \
    menstrual_cycle_face_resign, \
    NULL, \
})

#endif // MENSTRUAL_CYCLE_FACE_H_

