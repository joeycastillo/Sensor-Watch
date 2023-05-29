/*
 * MIT License
 *
 * Copyright (c) 2023 Joseph Borne Komosa | @jokomo24
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
    // Store the date of the 'first' and the total cycles since to calulate and store the average menstrual cycle.
    // Store the date of the previous, most recent, period to calculate the cycle length.
    // Store the shortest and longest cycle to calculate the fertility window for The Calender Method.
    // NOTE: Not thrilled about using two registers, but could not find a way to perform The Calender Method
    //       without requiring both the 'first' and 'prev' dates.
    union {
        struct {
            uint8_t first_day : 5;
            uint8_t first_month : 4;
            uint8_t first_year : 6; // 0-63 (representing 2020-2083)
            uint8_t prev_day : 5;
            uint8_t prev_month : 4;
            uint8_t prev_year : 6; // 0-63 (representing 2020-2083)
            uint8_t reserved : 2; // left over bit space
        } bit;
        uint32_t reg; // Tracking's been activated if > 0
    } dates;
    union {
        struct {
            uint8_t shortest_cycle : 6; // For step 2 of The Calender Method 
            uint8_t longest_cycle : 6; // For step 3 of The Calender Method 
            uint8_t average_cycle : 6; // The average menstrual cycle lasts 28 days, but normal cycles can vary from 21 to 35 days
            uint16_t total_cycles : 11; // The total cycles (periods) entered since the start of tracking
            uint8_t reserved : 3; // left over bit space
        } bit; 
        uint32_t reg;
    } cycles;
    uint8_t backup_register_dt;
    uint8_t backup_register_cy;
    uint8_t current_page;
    uint8_t days_prev_period;
    int32_t utc_offset;
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