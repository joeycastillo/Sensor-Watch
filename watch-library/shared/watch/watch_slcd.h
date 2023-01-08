/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
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
#ifndef _WATCH_SLCD_H_INCLUDED
#define _WATCH_SLCD_H_INCLUDED
////< @file watch_slcd.h

#include "watch.h"

/** @addtogroup slcd Segment LCD Display
  * @brief This section covers functions related to the Segment LCD display driver, which is responsible
  *        for displaying strings of characters and indicators on the main watch display.
  * @details The segment LCD controller consumes about 3 microamperes of power with no segments on, and
  *          about 4 microamperes with all segments on. There is also a slight power impact associated
  *          with updating the screen (about 1 microampere to update at 1 Hz). For the absolute lowest
  *          power operation, update the display only when its contents have changed, and disable the
  *          SLCD peripheral when the screen is not in use.
  *          For a map of all common and segment pins, see <a href="segmap.html">segmap.html</a>. You can
  *          hover over any segment in that diagram to view the common and segment pins associated with
  *          each segment of the display.
  */
/// @{

/// An enum listing the icons and indicators available on the watch.
typedef enum WatchIndicatorSegment {
    WATCH_INDICATOR_SIGNAL = 0, ///< The hourly signal indicator; also useful for indicating that sensors are on.
    WATCH_INDICATOR_BELL,       ///< The small bell indicating that an alarm is set.
    WATCH_INDICATOR_PM,         ///< The PM indicator, indicating that a time is in the afternoon.
    WATCH_INDICATOR_24H,        ///< The 24H indicator, indicating that the watch is in a 24-hour mode.
    WATCH_INDICATOR_LAP         ///< The LAP indicator; the F-91W uses this in its stopwatch UI.
} WatchIndicatorSegment;

/** @brief Enables the Segment LCD display.
  * Call this before attempting to set pixels or display strings.
  */
void watch_enable_display(void);

/** @brief Sets a pixel. Use this to manually set a pixel with a given common and segment number.
  *        See <a href="segmap.html">segmap.html</a>.
  * @param com the common pin, numbered from 0-2.
  * @param seg the segment pin, numbered from 0-23.
  */
void watch_set_pixel(uint8_t com, uint8_t seg);

/** @brief Clears a pixel. Use this to manually clear a pixel with a given common and segment number.
  *        See <a href="segmap.html">segmap.html</a>.
  * @param com the common pin, numbered from 0-2.
  * @param seg the segment pin, numbered from 0-23.
  */
void watch_clear_pixel(uint8_t com, uint8_t seg);

/** @brief Clears all segments of the display, including incicators and the colon.
  */
void watch_clear_display(void);

/** @brief Displays a string at the given position, starting from the top left. There are ten digits.
           A space in any position will clear that digit.
  * @param string A null-terminated string.
  * @param position The position where you wish to start displaying the string. The day of week digits
  *                 are positions 0 and 1; the day of month digits are positions 2 and 3, and the main
  *                 clock line occupies positions 4-9.
  * @note This method does not clear the display; if for example you display a two-character string at
          position 0, positions 2-9 will retain whatever state they were previously displaying.
  */
void watch_display_string(char *string, uint8_t position);

void watch_display_segment(uint8_t position, uint8_t bit_pos, bool on);

uint64_t watch_convert_char_to_segdata(uint8_t character, uint8_t position);

void watch_display_invert(bool);

/** @brief Turns the colon segment on.
  */
void watch_set_colon(void);

/** @brief Turns the colon segment off.
  */
void watch_clear_colon(void);

/** @brief Sets an indicator on the LCD. Use this to turn on one of the indicator segments.
  * @param indicator One of the indicator segments from the enum. @see WatchIndicatorSegment
  */
void watch_set_indicator(WatchIndicatorSegment indicator);

/** @brief Clears an indicator on the LCD. Use this to turn off one of the indicator segments.
  * @param indicator One of the indicator segments from the enum. @see WatchIndicatorSegment
  */
void watch_clear_indicator(WatchIndicatorSegment indicator);

/** @brief Clears all indicator segments.
  * @see WatchIndicatorSegment
  */
void watch_clear_all_indicators(void);

/** @brief Blinks a single character in position 7. Does not affect other positions.
  * @details Six of the seven segments in position 7 (and only position 7) are capable of autonomous
  *          blinking. This blinking does not require any CPU resources, and will continue even in
  *          STANDBY and Sleep mode (but not Deep Sleep mode, since that mode turns off the LCD).
  * @param character The character you wish to blink.
  * @param duration The duration of the on/off cycle in milliseconds, from 50 to ~4250 ms.
  * @note Segment B of position 7 cannot blink autonomously, so not all characters will work well.
  *       Supported characters for blinking:
  *        * Punctuation: underscore, apostrophe, comma, hyphen, equals sign, tilde (top segment only)
  *        * Numbers: 5, 6, ampersand (lowercase 7)
  *        * Letters: b, C, c, E, F, h, i, L, l, n, o, S, t
  */
void watch_start_character_blink(char character, uint32_t duration);

/** @brief Stops and clears all blinking segments.
  * @details This will stop all blinking in position 7, and clear all segments in that digit.
  */
void watch_stop_blink(void);

/** @brief Begins a two-segment "tick-tock" animation in position 8.
  * @details Six of the seven segments in position 8 (and only position 8) are capable of autonomous
  *          animation. This animation is very basic, and consists of moving a bit pattern forward
  *          or backward in a shift register whose positions map to fixed segments on the LCD. Given
  *          this constraint, an animation across all six segments does not make sense; so the watch
  *          library offers only a simple "tick/tock" in segments D and E. This animation does not
  *          require any CPU resources, and will continue even in STANDBY and Sleep mode (but not Deep
  *          Sleep mode, since that mode turns off the LCD).
  * @param duration The duration of each frame in ms. 500 milliseconds produces a classic tick/tock.
  */
void watch_start_tick_animation(uint32_t duration);

/** @brief Checks if the tick animation is currently running.
  * @return true if the animation is running; false otherwise.
  */
bool watch_tick_animation_is_running(void);

/** @brief Stops the tick/tock animation and clears all animating segments.
  * @details This will stop the animation and clear all segments in position 8.
  */
void watch_stop_tick_animation(void);
/// @}
#endif
