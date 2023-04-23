/*
 * MIT License
 *
 * Copyright (c) 2023 Joseph Komosa | @jokomo24
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
    // Store the "first" period and the total cycles since, to calulate the average menstrual cycle.
    // Store the shortest and longest cycle to calculate the fertility window, after tracking for >= 8
    // months, using The Calender Method.
    union {
        struct {
            uint8_t first_day : 5;
            uint8_t first_month : 4;
            uint8_t first_year : 6; // 0-63 (representing 2020-2083)
            uint8_t prev_day : 5;
            uint8_t prev_month : 4;
            uint8_t prev_year : 6; // 0-63 (representing 2020-2083)
        } bit;
        uint32_t reg;
    } dates;
    union {
        struct {
            uint8_t shortest_cycle : 6; // For step 2 of The Calender Method 
            uint8_t longest_cycle : 7; // For step 3 of The Calender Method 
            uint8_t average_cycle : 6; // The average menstrual cycle lasts 28 days, but normal cycles can vary from 21 to 35 days
            uint16_t total_cycles : 13;
        } bit; 
        uint32_t reg;
    } cycles;
    uint8_t current_page;
    uint8_t backup_register_dt;
    uint8_t backup_register_cy;
    uint8_t days_since_period; // Days since the last period
    bool period_today;
    bool reset_tracking;
} menstrual_cycle_state_t;

void menstrual_cycle_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void menstrual_cycle_face_activate(movement_settings_t *settings, void *context);
bool menstrual_cycle_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void menstrual_cycle_face_resign(movement_settings_t *settings, void *context);

#define menstrual_cycle_face ((const watch_face_t){ \
    menstrual_cycle_face_setup, \
    menstrual_cycle_face_activate, \
    menstrual_cycle_face_loop, \
    menstrual_cycle_face_resign, \
    NULL, \
})

#endif // MENSTRUAL_CYCLE_FACE_H_