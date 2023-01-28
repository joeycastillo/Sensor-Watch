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


#include "ab_face.h"
#include "movement.h"
#include "watch_utility.h"
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------------------------
// State
// -----------------------------------------------------------------------------

typedef enum {
  AB_READY,
  AB_RUN,
  AB_SETTINGS,
} ab_mode_t;

typedef enum {
  AB_BREAK,
  AB_ACTIVE,
} ab_loop_t;

typedef struct {
  uint32_t target_ts;
  uint8_t active_min, active_sec;
  uint8_t break_min, break_sec;
  ab_mode_t mode;
  ab_loop_t loop;
  int8_t count, starting_count;
  uint8_t settings_page;
} ab_state_t;

// -----------------------------------------------------------------------------
// Helper functions
// -----------------------------------------------------------------------------

static void to_min_sec(ab_state_t *state, uint8_t *min, uint8_t *sec) {
  if (state->loop == AB_ACTIVE) {
    *min = state->active_min;
    *sec = state->active_sec;
  } else {
    *min = state->break_min;
    *sec = state->break_sec;
  }
}

static inline uint32_t now_unix() {
  return watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), 0);
}

static inline void ab_start(ab_state_t *state) {
  uint8_t min, sec;
  to_min_sec(state, &min, &sec);

  state->mode = AB_RUN;
  state->target_ts = watch_utility_offset_timestamp(now_unix(), 0, min, sec);
  watch_date_time target_ts = watch_utility_date_time_from_unix_time(state->target_ts, 0);
  movement_schedule_background_task(target_ts);
}

static inline void ab_cancel() {
  movement_cancel_background_task();
}

static inline void ab_ring(ab_state_t *state) {
  movement_play_signal();
  ab_cancel();
  if (state->loop == AB_ACTIVE) {
    state->loop = AB_BREAK;
    state->count++;
  } else if (state->loop == AB_BREAK) {
    state->loop = AB_ACTIVE;
  }
}

// -----------------------------------------------------------------------------
// Main functions
// -----------------------------------------------------------------------------

static void ab_draw(ab_state_t *state, const uint8_t blink) {
  char buf[16];
  char kind;
  uint8_t min = 0;
  uint8_t sec = 0;

  if (state->loop == AB_BREAK) {
    kind = 'b';
  } else {
    kind = 'A';
  }

  switch (state->mode) {
    case AB_RUN: {
      const uint32_t now = now_unix();
      if (state->target_ts > now) {
        const uint32_t delta = state->target_ts - now;
        const div_t result = div(delta, 60);
        min = result.quot;
        sec = result.rem;
      }
      sprintf(buf, "AB-%c%2d%02d%2d", kind, min, sec, abs(state->count));
      watch_display_string(buf, 0);
      if (state->count < 0) watch_set_indicator(WATCH_INDICATOR_LAP);
      else watch_clear_indicator(WATCH_INDICATOR_LAP);
      break;
    }
    case AB_READY: {
      to_min_sec(state, &min, &sec);
      sprintf(buf, "AB %c%2d%02d%2d", kind, min, sec, abs(state->count));
      watch_display_string(buf, 0);
      break;
    }
    case AB_SETTINGS: {
      const uint8_t blink_idx = state->settings_page < 4 ? ((state->settings_page & 1) << 1)  + 4 : 8;
      if (state->settings_page == 4) kind = 'L';
      to_min_sec(state, &min, &sec);
      sprintf(buf, "ABS%c%02d%02d%02d", kind, min, sec, abs(state->starting_count));
      if (blink) {
        buf[blink_idx] = buf[blink_idx+1] = ' ';
      }
      watch_display_string(buf, 0);
      if (state->starting_count < 0) watch_set_indicator(WATCH_INDICATOR_LAP);
      else watch_clear_indicator(WATCH_INDICATOR_LAP);
      break;
    }
  }
}

void ab_face_setup(movement_settings_t *settings,
                       uint8_t watch_face_index,
                       void **context_ptr) {
  (void)settings;
  (void)watch_face_index;

  if (*context_ptr == NULL) {
    *context_ptr = malloc(sizeof(ab_state_t));
    ab_state_t *state = (ab_state_t *)*context_ptr;
    memset(*context_ptr, 0, sizeof(ab_state_t));
    state->mode = AB_READY;
    state->loop = AB_ACTIVE;
    state->starting_count = -2;
    state->count = state->starting_count;
    state->active_min = 0;
    state->active_sec = 3;
    state->break_min = 0;
    state->break_sec = 2;
    state->settings_page = 0;
  }
}

void ab_face_activate(movement_settings_t *settings, void *context) {
  (void)(settings);
  ab_state_t *state = (ab_state_t *)context;
  watch_clear_indicator(WATCH_INDICATOR_LAP);
  switch (state->mode) {
    case AB_SETTINGS: {
      movement_request_tick_frequency(4);
      if (state->starting_count < 0) watch_set_indicator(WATCH_INDICATOR_LAP);
      break;
    }
    case AB_RUN: {
      movement_request_tick_frequency(1);
      if (state->count < 0) watch_set_indicator(WATCH_INDICATOR_LAP);
      break;
    }
    case AB_READY: {
      movement_request_tick_frequency(1);
      break;
    }
  }
  watch_set_colon();
}

bool ab_face_loop(movement_event_t event,
                      movement_settings_t *settings,
                      void *context) {
  (void)(settings);
  ab_state_t *state = (ab_state_t *)context;
  const uint8_t blink = event.subsecond % 2;

  switch (event.event_type) {
    case EVENT_ACTIVATE: {
      ab_draw(state, blink);
      break;
    }
    case EVENT_TICK: {
      ab_draw(state, blink);
      break;
    }
    case EVENT_MODE_BUTTON_UP: {
      if (state->mode == AB_SETTINGS) {
        state->mode = AB_READY;
        watch_clear_indicator(WATCH_INDICATOR_LAP);
        ab_cancel();
      }
      movement_move_to_next_face();
      break;
    }
    case EVENT_LIGHT_BUTTON_UP: {
      if (state->mode == AB_READY) {
        ab_cancel();
        state->settings_page = 0;
        state->loop = AB_ACTIVE;
        state->mode = AB_SETTINGS;
        movement_request_tick_frequency(4);
      } else if (state->mode == AB_SETTINGS){
        state->settings_page++;
        if (state->settings_page >= 5) {
          state->mode = AB_READY;
          state->loop = AB_ACTIVE;
          state->count = state->starting_count;
          watch_clear_indicator(WATCH_INDICATOR_LAP);
          movement_request_tick_frequency(1);
        } else {
          state->loop = (state->settings_page < 2) ? AB_ACTIVE : AB_BREAK;
        }
        ab_draw(state, blink);
      }
      break;
    }
    case EVENT_LIGHT_LONG_PRESS: {
      break;
    }
    case EVENT_ALARM_BUTTON_UP: {
      switch (state->mode) {
        case AB_RUN: {
          state->mode = AB_READY;
          ab_cancel();
          break;
        }
        case AB_READY: {
          ab_start(state);
          ab_draw(state, false);
          break;
        }
        case AB_SETTINGS: {
          switch (state->settings_page) {
            case 0: {
              state->active_min = (state->active_min + 1) % 90;
              break;
            }
            case 1: {
              state->active_sec = (state->active_sec + 1) % 60;
              break;
            }
            case 2: {
              state->break_min = (state->break_min + 1) % 90;
              break;
            }
            case 3: {
              state->break_sec = (state->break_sec + 1) % 60;
              break;
            }
            case 4: {
              state->starting_count -= 1;
              break;
            }
          }
          if (state->active_sec == 0 && state->active_min == 0) state->active_sec = 1;
          if (state->break_sec == 0 && state->break_min == 0) state->break_sec = 1;
          break;
        }
      }
      ab_draw(state, blink);
      break;
    }
    case EVENT_ALARM_LONG_PRESS: {
      if (state->mode != AB_SETTINGS) {
        state->count = 0;
      } else {
        switch (state->settings_page) {
          case 0: {
            state->active_min = 0;
            break;
          }
          case 1: {
            state->active_sec = 0;
            break;
          }
          case 2: {
            state->break_min = 0;
            break;
          }
          case 3: {
            state->break_sec = 0;
            break;
          }
          case 4: {
            state->starting_count = 0;
            break;
          }
        }
        if (state->active_sec == 0 && state->active_min == 0) state->active_sec = 1;
        if (state->break_sec == 0 && state->break_min == 0) state->break_sec = 1;
      }
      break;
    }
    case EVENT_BACKGROUND_TASK: {
      ab_ring(state);
      if (state->count != 0) {
        ab_start(state);
      } else {
        ab_cancel();
        state->mode = AB_READY;
        state->loop = AB_ACTIVE;
        state->count = state->starting_count;
        watch_clear_indicator(WATCH_INDICATOR_LAP);
      }
      ab_draw(state, blink);
      break;
    }
    case EVENT_TIMEOUT: {
      movement_move_to_face(0);
      break;
    }
    default: {
      return movement_default_loop_handler(event, settings);
    }
  }

  return true;
}

void ab_face_resign(movement_settings_t *settings, void *context) {
  (void)settings;
  (void)context;
}
