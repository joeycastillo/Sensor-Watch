/*
 * MIT License
 *
 * Copyright © 2023-2025 Lionel Ringenbach <ucodia@live.com>
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

#include "flowtime.h"
#include "watch.h"
#include <stdint.h>
#include <stdlib.h>

static uint32_t *random_sequence(uint32_t n, uint32_t seed) {
  uint32_t *result = malloc(n * sizeof(uint32_t));
  if (!result)
    return NULL;
  uint32_t state = seed;
  for (uint32_t i = 0; i < n; i++) {
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    int j = (uint32_t)(((double)state / 4294967296) * (i + 1));
    result[i] = result[j];
    result[j] = i;
  }
  return result;
}

watch_date_time date_to_flowtime(watch_date_time *date) {
  static uint32_t cached_hours_seed = 0;
  static uint32_t cached_minutes_seed = 0;
  static uint32_t *cached_hours_sequence = NULL;
  static uint32_t *cached_minutes_sequence = NULL;

  uint32_t hoursSeed = (date->unit.year + WATCH_RTC_REFERENCE_YEAR) * 10000 + 
                       date->unit.month * 100 + 
                       date->unit.day;
  uint32_t minutesSeed = hoursSeed * 100 + date->unit.hour;

  if (hoursSeed != cached_hours_seed) {
    free(cached_hours_sequence);
    cached_hours_sequence = random_sequence(24, hoursSeed);
    cached_hours_seed = hoursSeed;
  }

  if (minutesSeed != cached_minutes_seed) {
    free(cached_minutes_sequence);
    cached_minutes_sequence = random_sequence(60, minutesSeed);
    cached_minutes_seed = minutesSeed;
  }

  watch_date_time flowtime = *date;
  flowtime.unit.hour = cached_hours_sequence[date->unit.hour];
  flowtime.unit.minute = cached_minutes_sequence[date->unit.minute];

  return flowtime;
}
