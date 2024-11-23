/*
 * MIT License
 *
 * Copyright (c) 2024 alanho
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

#ifndef HKTOLL_FACE_H_
#define HKTOLL_FACE_H_

#include "movement.h"

/*
 * HKToll Face
 *
 * A watch face that displays toll rates for Hong Kong's cross-harbour tunnels.
 * Shows rates for Cross Harbour Tunnel (CHT), Western Harbour Tunnel (WHT), 
 * and Eastern Harbour Tunnel (EHT). Press ALARM to cycle between tunnels.
 * Long press ALARM to toggle public holiday mode (indicated by 'H').
 * Rates vary based on time of day and holidays.
 *
 */

typedef enum
{
    CHT           = 0, // 紅磡
    WHT           = 1, // 西隧
    EHT           = 2 // 東隧
} tunnel_index_t;

typedef struct {
    tunnel_index_t tunnel_index; // 0: Hung Hom, 1: West, 2: East
    bool public_holiday; // true if showing public holiday
} hktoll_state_t;

void hktoll_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void hktoll_face_activate(movement_settings_t *settings, void *context);
bool hktoll_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void hktoll_face_resign(movement_settings_t *settings, void *context);
bool hktoll_is_likely_public_holiday(watch_date_time date_time);
uint8_t hktoll_get_toll_for_holiday(watch_date_time date_time);
uint8_t hktoll_get_toll_for_normal_day(watch_date_time date_time, tunnel_index_t tunnel_index);

#define hktoll_face ((const watch_face_t){ \
    hktoll_face_setup, \
    hktoll_face_activate, \
    hktoll_face_loop, \
    hktoll_face_resign, \
    NULL, \
})

#endif // HKTOLL_FACE_H_

