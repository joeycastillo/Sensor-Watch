/*
 * MIT License
 *
 * Copyright (c) 2023 tslil clingman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "habit_face.h"
#include "watch_private_display.h"
#include "watch_rtc.h"
#include "watch_slcd.h"
#include "watch_utility.h"
#include <stdlib.h>
#include <string.h>

static inline uint32_t today_unix(const uint32_t utc_offset) {
  const watch_date_time dt = watch_rtc_get_date_time();
  return watch_utility_convert_to_unix_time(dt.unit.year + 2020, dt.unit.month,
                                            dt.unit.day, 0, 0, 0, utc_offset);
}

static inline uint32_t days_since_unix(const uint32_t since,
                                       const uint32_t until) {
  return (until - since) / (60 * 60 * 24);
}

typedef struct {
  uint16_t total_count;
  uint8_t lookback;
  uint32_t last_update;
  bool display_total;
} habit_state_t;

void habit_face_setup(movement_settings_t *settings, uint8_t watch_face_index,
                      void **context_ptr) {
  (void)settings;
  (void)watch_face_index;
  if (*context_ptr == NULL) {
    *context_ptr = malloc(sizeof(habit_state_t));
    memset(*context_ptr, 0, sizeof(habit_state_t));
    habit_state_t *state = (habit_state_t *)*context_ptr;
    state->lookback = 0;
    state->last_update = watch_utility_offset_timestamp(
        today_unix(settings->bit.time_zone), -24, 0, 0);
  }
}

static inline void display_state(habit_state_t *state) {
  const bool can_do = (state->lookback & 1) == 0;
  char buf[16];

  if (can_do) {
    watch_clear_indicator(WATCH_INDICATOR_LAP);
  } else {
    watch_set_indicator(WATCH_INDICATOR_LAP);
  }

  if (state->display_total) {
    sprintf(buf, "HA  %03dtot", state->total_count);
    watch_display_string(buf, 0);
  } else {
    sprintf(buf, "HA      d%c", can_do ? 'o' : 'n');
    uint8_t copy = state->lookback;
    for (uint8_t c = 0; copy; copy >>= 2, c++) {
      switch (copy & 3) {
      case 0:
        break;
      case 1:
        buf[4 + c] = 'I';
        break;
      case 2:
        buf[4 + c] = '1';
        break;
      case 3:
        buf[4 + c] = '|';
        break;
      }
    }
    watch_display_string(buf, 0);
    if (can_do) {
      const uint64_t segmap = Segment_Map[4] >> 48;
      watch_set_pixel((segmap & 0xFF) >> 6, segmap & 0x3F);
    }
  }
}

void habit_face_activate(movement_settings_t *settings, void *context) {
  (void)settings;
  habit_state_t *state = (habit_state_t *)context;
  display_state(state);
}

bool habit_face_loop(movement_event_t event, movement_settings_t *settings,
                     void *context) {
  habit_state_t *state = (habit_state_t *)context;

  const uint32_t today_now_unix = today_unix(settings->bit.time_zone);
  const bool can_do = (state->lookback & 1) == 0;

  switch (event.event_type) {
  case EVENT_ACTIVATE:
  case EVENT_TICK: {
    display_state(state);
    if (today_now_unix > state->last_update) {
      uint8_t num_shifts = days_since_unix(state->last_update, today_now_unix);
      if (num_shifts > 7)
        num_shifts = 7;
      state->lookback <<= num_shifts;
      state->last_update = today_now_unix;
    }
    break;
  }
  case EVENT_LIGHT_BUTTON_UP: {
    state->display_total = !state->display_total;
    display_state(state);
    break;
  }
  case EVENT_ALARM_BUTTON_UP: {
    if (can_do) {
      state->lookback |= 1;
      state->total_count++;
      state->last_update = today_now_unix;
      display_state(state);
    };
    break;
  }
  case EVENT_TIMEOUT: {
    movement_move_to_face(0);
    break;
  }
  default:
    return movement_default_loop_handler(event, settings);
  }
  return true;
}

void habit_face_resign(movement_settings_t *settings, void *context) {
  (void)settings;
  (void)context;
}
