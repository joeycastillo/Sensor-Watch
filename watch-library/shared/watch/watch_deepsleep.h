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

/** @addtogroup deepsleep Sleep Control
  * @brief This section covers functions related to the various sleep modes available to the watch,
  *        including Sleep, Deep Sleep, and BACKUP mode.
  * @details These terms changed meaning a bit over the course of development; if you are coming
  *          to this documentation after having worked with an earlier version of the library,
  *          these definitions should clarify the terminology. Terms in all caps are modes of the
  *          SAM L22; terms in Title Case are specific implementations in this library.
  *           - ACTIVE mode is the mode the SAM L22 is in when both the main clock and the CPU are
  *             running. It is the most power-hungry mode. If you ever call delay_ms to wait a beat,
  *             the watch will remain in ACTIVE mode while taking that delay. In addition, whenever
  *             your `app_loop` function returns false, the device will remain in ACTIVE mode and
  *             call your `app_loop` function again.
  *           - STANDBY mode turns off the main clock and halts the CPU. Since the PWM driver is
  *             run from the main clock, it also stops the buzzer and any dimming of the LEDs.
  *             In this mode, the watch can wake from any interrupt source. Whenever your `app_loop`
  *             function returns true, the watch enters STANDBY mode until the next tick or other
  *             interrupt. This mode uses much less power than ACTIVE mode.
  *           - Sleep Mode is a special case of STANDBY mode. In this mode, the watch turns off
  *             almost all peripherals (including the external interrupt controller), and disables
  *             all pins except for the external wake pins. In this mode the watch can only wake
  *             from the RTC alarm interrupt or an external wake pin (A2, A4 or the alarm button),
  *             but the display remains on and your app's state is retained. You can enter this
  *             mode by calling `watch_enter_sleep_mode`. It consumes an order of magnitude less
  *             power than STANDBY mode.
  *           - Deep Sleep Mode is identical to sleep mode, but it also turns off the LCD to save
  *             a bit more power. You can enter this mode by calling `watch_enter_deep_sleep_mode`.
  *           - BACKUP mode is the lowest possible power mode on the SAM L22. It turns off all pins
  *             and peripherals except for the RTC. It also turns off the RAM, obliterating your
  *             application's state. The only way to wake from this mode is by setting an external
  *             wake interrupt on pin A2 or pin A4, and when you do wake it will be much like a
  *             wake from reset. You can enter this mode by calling `watch_enter_backup_mode`.
  */
/// @{

/** @brief Registers a callback on one of the RTC's external wake pins, which can wake the device
  *        from Sleep, Deep Sleep and BACKUP modes (but see warning re: BACKUP mode).
  * @param pin Either pin BTN_ALARM, A2, or A4. These are the three external wake pins. If the pin
  *            is BTN_ALARM, this function also enables an internal pull down on that pin.
  * @param callback The callback to be called if this pin triggers outside of BACKUP mode. If this is
  *                 NULL, no callback will be called even in normal modes, but the interrupt will
  *                 still be enabled so that it can wake the device.
  * @param level The level you wish to scan for: true for rising, false for falling. Note that you
  *              cannot scan for both rising and falling edges like you can with the external interrupt
  *              pins; with the external wake interrupt, you can only get one or the other.
  * @note When in ACTIVE, STANDBY and Sleep / Deep sleep modes, this will function much like a standard
  *       external interrupt situation: these pins will wake the device, and your callback will be
  *       called. However, if the device enters BACKUP mode and one of these pins wakes the device, your
  *       callback WILL NOT be called, as the device is basically waking from reset at that point.
  * @warning As of the current SAM L22 silicon revision (rev B), the BTN_ALARM pin cannot wake the
  *          device from BACKUP mode. You can still use this function to register a BTN_ALARM interrupt
  *          in normal or deep sleep mode, but to wake from BACKUP, you will need to use pin A2 or A4.
  */
void watch_register_extwake_callback(uint8_t pin, ext_irq_cb_t callback, bool level);

/** @brief Unregisters the RTC interrupt on one of the EXTWAKE pins. This will prevent a value change on
  *        one of these pins from waking the device.
  * @param pin Either pin BTN_ALARM, A2, or A4. If the pin is BTN_ALARM, this function DOES NOT disable
  *            the internal pull down on that pin.
  */
void watch_disable_extwake_interrupt(uint8_t pin);

/** @brief Stores data in one of the RTC's backup registers, which retain their data in BACKUP mode.
  * @param data An unsigned 32 bit integer with the data you wish to store.
  * @param reg A register from 0-7.
  */
void watch_store_backup_data(uint32_t data, uint8_t reg);

/** @brief Gets 32 bits of data from the RTC's BACKUP register.
  * @param reg A register from 0-7.
  * @return An unsigned 32 bit integer with the from the backup register.
  */
uint32_t watch_get_backup_data(uint8_t reg);

/** @brief enters Sleep Mode by disabling all pins and peripherals except the RTC and the LCD.
  * @details This sleep mode is not the lowest power mode available, but it has the benefit of allowing you
  *          to display a message to the user while asleep. You can also set an alarm interrupt to wake at a
  *          configfurable interval (every minute, hour or day) to update the display. You can wake from this
  *          mode by pressing the ALARM button, if you registered an extwake callback on the ALARM button.
  *          Also note that when your app wakes from this sleep mode, your app_setup method will be called
  *          again, since this function will have disabled things you set up there.
  *
  *          Note that to wake from either the ALARM button, the A2 interrupt or the A4 interrupt, you
  *          must first configure this by calling watch_register_extwake_callback.
  *
  *          You can estimate the power consumption of this mode to be on the order of 30 microwatts
  *          (about 10 µA at 3 V).
  */
void watch_enter_sleep_mode(void);

/** @brief enters Deep Sleep Mode by disabling all pins and peripherals except the RTC.
  * @details Short of BACKUP mode, this is the lowest power mode you can enter while retaining your
  *          application state (and the ability to wake with the alarm button). Just note that the display
  *          will be completely off, so you should document to the user of your application that they will
  *          need to press the alarm button to wake the device, or use a sensor board with support for
  *          an external wake pin.
  *
  *          All notes from watch_enter_sleep_mode apply here, except for power consumption. You can estimate
  *          the power consumption of this mode to be on the order of 12 microwatts (about 4µA at 3 V).
  */
void watch_enter_deep_sleep_mode(void);

/** @brief Enters the SAM L22's lowest-power mode, BACKUP.
  * @details This function does some housekeeping before entering BACKUP mode. It first disables all pins
  *          and peripherals except for the RTC, and disables the tick interrupt (since that would wake
  *          us up from BACKUP mode). Once again, if you wish to wake from the A2 or the A4 interrupt,
  *          you must first configure this by calling watch_register_extwake_callback.
  * @note If you have a callback set for an external wake interrupt, it will be called if triggered while
  *       in ACTIVE, STANDBY, Sleep and Deep Sleep modes, but it *will not be called* when waking from
  *       BACKUP mode. Waking from backup is effectively like waking from reset, except that your
  *       @ref app_wake_from_backup function will be called.
  * @warning On current revisions of the SAM L22 silicon, the ALARM_BTN pin (PA02 RTC/IN2) cannot wake
  *          the device from deep sleep mode. There is an errata note (Reference: 15010) that says that
  *          due to a silicon bug, RTC/IN2 is not functional in BACKUP. As a result, you should not call
  *          this function unless you have a device on the nine-pin connector with an external interrupt
  *          on pin A2 or A4 (i.e. an accelerometer with an interrupt pin).
  */
void watch_enter_backup_mode(void);

__attribute__((deprecated("Use watch_enter_sleep_mode or watch_enter_deep_sleep_mode instead")))
void watch_enter_shallow_sleep(bool display_on);

__attribute__((deprecated("Use watch_enter_backup_mode instead")))
void watch_enter_deep_sleep(void);
/// @}
#endif
