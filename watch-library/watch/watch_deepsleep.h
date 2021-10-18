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
#ifndef _WATCH_DEEPSLEEP_H_INCLUDED
#define _WATCH_DEEPSLEEP_H_INCLUDED
////< @file watch_deepsleep.h

#include "watch.h"

// These are declared in watch_rtc.c.
extern ext_irq_cb_t btn_alarm_callback;
extern ext_irq_cb_t a2_callback;
extern ext_irq_cb_t a4_callback;

/** @addtogroup deepsleep Deep Sleep Control
  * @brief This section covers functions related to preparing for and entering BACKUP mode, the
  *        deepest sleep mode available on the SAM L22
  */
/// @{

/** @brief Registers a callback on one of the RTC's external wake pins, which can wake the device
  *        from deep sleep (aka BACKUP) mode.
  * @param pin Either pin BTN_ALARM, A2, or A4. These are the three external wake pins. If the pin
  *            is BTN_ALARM, this function also enables an internal pull down on that pin.
  * @param callback The callback to be called if this pin triggers outside of deep sleep mode. If
  *                 this is NULL, no callback will be called even in normal mode, but the interrupt
  *                 will still be enabled so that it can wake from deep sleep or backup mode.
  * @param level The level you wish to scan for: true for rising, false for falling. Note that you
  *              cannot scan for both rising and falling edges like you can with the external interrupt
  *              pins; with the external wake interrupt, you can only get one or the other.
  * @note When in normal or STANDBY mode, this will function much like a standard external interrupt
  *       situation: these pins will wake from standby, and your callback will be called. However,
  *       if the device enters deep sleep and one of these pins wakes the device, your callback
  *       WILL NOT be called, as the device is basically waking from reset at that point.
  * @warning As of the current SAM L22 silicon revision (rev B), the BTN_ALARM pin cannot wake the
  *          device from BACKUP mode. You can still use this function to register a BTN_ALARM interrupt
  *          in normal or deep sleep mode, but to wake from BACKUP, you will need to use pin A2 or A4.
  */
void watch_register_extwake_callback(uint8_t pin, ext_irq_cb_t callback, bool level);

/** @brief Unregisters the RTC interrupt on one of the EXTWAKE pins. This will prevent a value change on
  *        one of these pins from waking the device from shallow and deep sleep modes.
  * @param pin Either pin BTN_ALARM, A2, or A4. If the pin is BTN_ALARM, this function DOES NOT disable
  *            the internal pull down on that pin.
  */
void watch_disable_extwake_interrupt(uint8_t pin);

/** @brief Stores data in one of the RTC's backup registers, which retain their data in deep sleep mode.
  * @param data An unsigned 32 bit integer with the data you wish to store.
  * @param reg A register from 0-7.
  */
void watch_store_backup_data(uint32_t data, uint8_t reg);

/** @brief Gets 32 bits of data from the RTC's backup register.
  * @param reg A register from 0-7.
  * @return An unsigned 32 bit integer with the from the backup register.
  */
uint32_t watch_get_backup_data(uint8_t reg);

/** @brief Enters a shallow sleep mode by disabling all pins and peripherals except the RTC and (optionally)
  *        the LCD. You can wake from this mode by pressing the ALARM button, if you have an registered an
  *        external wake callback on the ALARM button. When your app wakes from this shallow sleep mode, your
  *        app_setup method will be called, since this function will have disabled things you set up.
  * @param display_on if true, leaves the LCD on to display whatever content was on-screen. If false, disables
  *                   the segment LCD controller for additional power savings.
  * @details This shallow sleep mode is not the lowest power mode available (see watch_enter_deep_sleep), but
  *          it has the benefit of retaining your application state and being able to wake from the ALARM button.
  *          It also provides an option for displaying a message to the user when asleep. Note that whether you
  *          want to wake from the ALARM button, the A2 RTC interrupt or the A4 interrupt, you must configure
  *          this by calling watch_register_extwake_callback first.
  *
  *          Power consumption in shallow sleep mode varies a bit with the battery voltage and the temperature,
  *          but at 3 V and 25~30° C you can roughly estimate:
  *           * < 12µA current draw with the LCD controller on
  *           * < 6µA current draw with the LCD controller off
  */
void watch_enter_shallow_sleep(bool display_on);

/** @brief Enters the SAM L22's lowest-power mode, BACKUP.
  * @details This function does some housekeeping before entering BACKUP mode. It first disables all
  *          peripherals except for the RTC, and disables the tick interrupt (since that would wake
  *          us up from deep sleep). It also sets an external wake source on the ALARM button, if one
  *          was not already set. If you wish to wake from another source, such as one of the external
  *          wake interrupt pins on the 9-pin connector, set that up prior to calling this function.
  * @note If you have a callback set for an external wake interrupt, it will be called if triggered while
  *       in ACTIVE, IDLE or STANDBY modes, but it *will not be called* when waking from BACKUP.
  *       Waking from backup is effectively like waking from reset, except that your @ref
  *       app_wake_from_deep_sleep function will be called.
  * @warning On current revisions of the SAM L22 silicon, the ALARM_BTN pin (PA02 RTC/IN2) cannot wake
  *          the device from deep sleep mode. There is an errata note (Reference: 15010) that says that
  *          due to a silicon bug, RTC/IN2 is not functional in BACKUP. As a result, you should not call
  *          this function unless you have a device on the nine-pin connector with an external interrupt
  *          on pin A2 or A4 (i.e. an accelerometer with an interrupt pin).
  */
void watch_enter_deep_sleep();
/// @}
#endif
