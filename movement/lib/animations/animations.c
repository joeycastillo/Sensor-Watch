/*
 * MIT License
 *
 * Copyright (c) 2023 Konrad Rieck
 * Copyright (c) 2023 Willy Hardy
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
#include "animated_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"
#include "animations.h"

/* Config for word clock */
static char *scroll_ten_words[] = {
    "", "", "tWENtY", "thIRtY", "FORtY", "FIFtY"
};

static char *scroll_words[] = {
    "tWELVE", "ONE", "tWO", "thREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGht", "NINE", "tEN",
    "ELEVEN", "tWELVE", "thIRtEEN", "FOURtEEN", "FIFtEEN", "SIXtEEN", "SEVENtEEN", "EIGhtEEN",
    "NINEtEEN"
};

static watch_date_time _convert_12h_mode(watch_date_time date_time)
{
    // if we are in 12 hour mode, do some cleanup.
    if (date_time.unit.hour < 12) {
        watch_clear_indicator(WATCH_INDICATOR_PM);
    } else {
        watch_set_indicator(WATCH_INDICATOR_PM);
    }
    date_time.unit.hour %= 12;
    if (date_time.unit.hour == 0)
        date_time.unit.hour = 12;

    return date_time;
}

static void _scroll_clock_init(movement_settings_t *settings, animated_clock_state_t *state)
{
    char buf[20];

    watch_clear_colon();
    movement_request_tick_frequency(4);
    state->tick = 0;
    state->previous_date_time = 0;

    watch_date_time date_time = watch_rtc_get_date_time();
    if (!settings->bit.clock_mode_24h)
        date_time = _convert_12h_mode(date_time);

    /* Display weekday and day */
    sprintf(buf, "%s%2d", watch_utility_get_weekday(date_time), date_time.unit.day);
    watch_display_string(buf, 0);

    /* Build minutes */
    if (date_time.unit.minute == 0) {
        sprintf(buf, "O:CLOCK");
    } else if (date_time.unit.minute < 20) {
        sprintf(buf, "%s", scroll_words[date_time.unit.minute]);
    } else if (date_time.unit.minute % 10 == 0) {
        sprintf(buf, "%s", scroll_ten_words[date_time.unit.minute / 10]);
    } else {
        sprintf(buf, "%s-%s", scroll_ten_words[date_time.unit.minute / 10],
                scroll_words[date_time.unit.minute % 10]);
    }

    /* Prepare buffer with current time and words */
    snprintf(state->buffer, ANIMATION_BUFFER_SIZE, "%2d%02d00  %s %s  %2d%02d05",
             date_time.unit.hour, date_time.unit.minute,
             scroll_words[date_time.unit.hour % 12], buf,
             date_time.unit.hour, date_time.unit.minute);
}

void ani_scroll_clock(movement_event_t event, movement_settings_t *settings,
                      animated_clock_state_t *state)
{
    uint8_t index;
    (void) event;

    if (state->previous_date_time == REFRESH_FACE)
        _scroll_clock_init(settings, state);

    // Calculate scroll position
    index = state->tick % strlen(state->buffer);

    // Copy scroll buffer into display buffer
    watch_display_string(state->buffer + index, 4);

    state->tick++;
    if (state->tick == strlen(state->buffer) - 6) {
        state->previous_date_time = REFRESH_FACE;
        state->mode = MODE_CLOCK;
    }
}

/*
Slowly render the current time from left to right, 
scanning across its liquid crystal face, completing 1 cycle every 2 seconds.

Created to mimic the wyoscan watch that was produced by Halmos and designed by Dexter Sinister
It looks like this https://www.o-r-g.com/apps/wyoscan

You’ll notice that reading this watch requires more attention than usual, 
as the seven segments of each digit are lit one by one across its display. 
This speed may be adjusted until it reaches the limits of your perception. 
You and your watch are now in tune.

This is a relatively generic way of animating a time display.
If you want to modify the animation, you can change the segment_map
the A-F are corresponding to the segments on the watch face

      A  
    F   B
      G
    E   C
      D

the X's are the frames that will be skipped in the animation
This particular segment_map allocates 8 frames to display each number
this is to achieve the 2 second cycle time.
8 frames per number * 6 numbers + the trailing 16 frames = 64 frames
at 32 frames per second, this is a 2 second cycle time.

I tried to make the animation of each number display similar to if you were 
to draw the number on the watch face with a pen, pausing with 'X'
when your pen might turn a corner or when you might cross over 
a line you've already drawn. It is vaguely top to bottom and counter,
clockwise when possible.
*/

static char *segment_map[] = {
    "AXFEDCBX", // 0
    "BXXXCXXX", // 1
    "ABGEXXXD", // 2
    "ABGXXXCD", // 3
    "FXGBXXXC", // 4
    "AXFXGXCD", // 5
    "AXFEDCXG", // 6
    "AXXBXXCX", // 7
    "AFGCDEXB", // 8
    "AFGBXXCD", // 9
    "XXXXXXXX", // empty
};

/*
This is the mapping of input to the watch_set_pixel() function
for each position in hhmmss it defines the 2 dimention input at each of A-F*/
static const int8_t clock_mapping[6][7][2] = {
    // hour 1
    { { 1, 18}, { 2, 19}, { 0, 19}, { 1, 18}, { 0, 18}, { 2, 18}, { 1, 19} },
    // hour 2
    { { 2, 20}, { 2, 21}, { 1, 21}, { 0, 21}, { 0, 20}, { 1, 17}, { 1, 20} },
    // minute 1
    { { 0, 22}, { 2, 23}, { 0, 23}, { 0, 22}, { 1, 22}, { 2, 22}, { 1, 23} },
    // minute 2
    { { 2, 1}, { 2, 10}, { 0, 1}, { 0, 0}, { 1, 0}, { 2, 0}, { 1, 1} },
    // second 1
    { { 2, 2}, { 2, 3}, { 0, 4}, { 0, 3}, { 0, 2}, { 1, 2}, { 1, 3} },
    // second 2
    { { 2, 4}, { 2, 5}, { 1, 6}, { 0, 6}, { 0, 5}, { 1, 4}, { 1, 5} },
};

static void _set_time_digits(movement_settings_t *settings, wyoscan_state_t *istate)
{
    // get new date and time 
    watch_date_time date_time = watch_rtc_get_date_time();
    if (!settings->bit.clock_mode_24h)
        date_time = _convert_12h_mode(date_time);

    istate->time_digits[0] = date_time.unit.hour / 10;
    istate->time_digits[1] = date_time.unit.hour % 10;
    istate->time_digits[2] = date_time.unit.minute / 10;
    istate->time_digits[3] = date_time.unit.minute % 10;
    istate->time_digits[4] = date_time.unit.second / 10;
    istate->time_digits[5] = date_time.unit.second % 10;
}

static void _wyoscan_clock_init(movement_settings_t *settings, animated_clock_state_t *state)
{
    (void) settings;
    char buf[11];

    watch_clear_colon();
    movement_request_tick_frequency(32);
    state->tick = 0;
    state->previous_date_time = 0;

    /* Cast buffer to internal state */
    wyoscan_state_t *istate = (wyoscan_state_t *) state->buffer;
    watch_date_time date_time = watch_rtc_get_date_time();
    if (!settings->bit.clock_mode_24h)
        date_time = _convert_12h_mode(date_time);

    /* Display weekday and day */
    sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time),
            date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    watch_display_string(buf, 0);

    istate->start = 0;
    istate->end = 0;
    istate->colon = false;
    istate->run = WYOSCAN_TOTAL_RUNS;

    _set_time_digits(settings, istate);
}

void ani_wyoscan_clock(movement_event_t event, movement_settings_t *settings,
                       animated_clock_state_t *state)
{
    (void) event;
    /* Cast buffer to internal state */
    wyoscan_state_t *istate = (wyoscan_state_t *) state->buffer;

    if (state->previous_date_time == REFRESH_FACE)
        _wyoscan_clock_init(settings, state);

    // if we have reached the max number of illuminated segments, we clear the oldest one
    if ((istate->end + 1) % WYOSCAN_MAX_ISEGMENTS == istate->start) {
        // clear the oldest pixel if it's not 'X'
        if (istate->illuminated_segments[istate->start][0] != 99
            && istate->illuminated_segments[istate->start][1] != 99 && istate->run > 1) {
            watch_clear_pixel(istate->illuminated_segments[istate->start][0],
                              istate->illuminated_segments[istate->start][1]);
        }
        // increment the start index to point to the next oldest pixel
        istate->start = (istate->start + 1) % WYOSCAN_MAX_ISEGMENTS;
    }

    if (state->tick < WYOSCAN_TOTAL_FRAMES - WYOSCAN_MAX_ISEGMENTS) {
        // Display colon in the middle of the animation only
        if (state->tick % 24 == 12) {
            istate->colon = !istate->colon;
            if (istate->colon)
                watch_set_colon();
            else
                watch_clear_colon();
        }
        // calculate the start position for the current frame
        istate->position = (state->tick / 8) % 6;
        // calculate the current segment for the current digit
        istate->segment = state->tick % strlen(segment_map[istate->time_digits[istate->position]]);
        // get the segments for the current digit
        istate->segments = segment_map[istate->time_digits[istate->position]];

        // Empty first digit if 0 and in 12h mode
        if (istate->position == 0 && istate->time_digits[0] == 0 && !settings->bit.clock_mode_24h)
            istate->segments = segment_map[10];

        if (istate->segments[istate->segment] == 'X') {
            // if 'X', skip this frame
            istate->illuminated_segments[istate->end][0] = 99;
            istate->illuminated_segments[istate->end][1] = 99;
            istate->end = (istate->end + 1) % WYOSCAN_MAX_ISEGMENTS;
            goto next;
        }
        // calculate the animation frame
        istate->x = clock_mapping[istate->position][istate->segments[istate->segment] - 'A'][0];
        istate->y = clock_mapping[istate->position][istate->segments[istate->segment] - 'A'][1];

        // set the new pixel
        watch_set_pixel(istate->x, istate->y);

        // store this pixel in the buffer
        istate->illuminated_segments[istate->end][0] = istate->x;
        istate->illuminated_segments[istate->end][1] = istate->y;
        // increment the end index to the next position
        istate->end = (istate->end + 1) % WYOSCAN_MAX_ISEGMENTS;
    } else if (state->tick >= WYOSCAN_TOTAL_FRAMES - WYOSCAN_MAX_ISEGMENTS
               && state->tick < WYOSCAN_TOTAL_FRAMES) {
        istate->end = (istate->end + 1) % WYOSCAN_MAX_ISEGMENTS;
    } else {
        istate->run--;

        if (istate->run == 0) {
            state->previous_date_time = REFRESH_FACE;
            state->mode = MODE_CLOCK;
        } else {
            state->tick = -1;
            _set_time_digits(settings, istate);
        }
    }

  next:
    state->tick++;
}
