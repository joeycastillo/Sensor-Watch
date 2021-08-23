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
////< @file watch_deepsleep.h

/** @addtogroup deepsleep Deep Sleep Control
  * @brief This section covers functions related to preparing for and entering BACKUP mode, the
  *        deepest sleep mode available on the SAM L22
  */
/// @{
/** @brief Registers a callback on one of the RTC's external wake pins, which can wake the device
  * from deep sleep mode.
  * @param pin Either pin A2 or pin D1, the two external wake pins on the nine-pin connector.
  * @param callback The callback to be called if this pin triggers outside of deep sleep mode.
  * @note When in normal or STANDBY mode, this will function much like a standard external interrupt
  *       situation: these pins will wake from standby, and your callback will be called. However,
  *       if the device enters deep sleep and one of these pins wakes the device, your callback
  *       WILL NOT be called.
  */
void watch_register_extwake_callback(uint8_t pin, ext_irq_cb_t callback);

/** @brief Stores data in one of the RTC's backup registers, which retain their data in deep sleep.
  * @param data An unsigned 32 bit integer with the data you wish to store.
  * @param reg A register from 0-7.
  */
void watch_store_backup_data(uint32_t data, uint8_t reg);

/** @brief Gets 32 bits of data from the RTC's backup register, which retains its data in deep sleep.
  * @param reg A register from 0-7.
  * @return An unsigned 32 bit integer with the from the backup register.
  */
uint32_t watch_get_backup_data(uint8_t reg);

/** @brief Enters the SAM L22's lowest-power mode, BACKUP.
  * @details This function does some housekeeping before entering BACKUP mode. It first disables all
  *          peripherals except for the RTC, and disables the tick interrupt (since that would wake)
  *          us up from deep sleep. It also sets an external wake source on the ALARM button, if one
  *          was not already set. If you wish to wake from another source, such as one of the external
  *          wake interrupt pins on the 9-pin connector, set that up prior to calling this function.
  * @note If you have a callback set for an external wake interrupt, it will be called if triggered while
  *       in ACTIVE, IDLE or STANDBY modes, but it *will not be called* when waking from BACKUP.
  *       Waking from backup is effectively like waking from reset, except that your @ref
  *       app_wake_from_deep_sleep function will be called.
  * @warning In initial testing, it seems like the ALARM_BTN pin (PA02 RTC/IN2) cannot wake the device
  *          from deep sleep mode. There is an errata note (Reference: 15010, linked) that says that
  *          due to a silicon bug, PB01 cannot be used as RTC/IN2. It seems though that this bug may
  *          also affect PA02. As a result — and I'm very bummed about this — you cannot use deep sleep
  *          mode unless you set up an external wake interrupt using a device on the nine-pin connector
  *          (i.e. an accelerometer with an interrupt pin). Otherwise your only option for waking will
  *          be to unscrew the watch case and press the reset button on the back of the board.
  *          http://ww1.microchip.com/downloads/en/DeviceDoc/SAM_L22_Family_Errata_DS80000782B.pdf
  */
void watch_enter_deep_sleep();
/// @}
