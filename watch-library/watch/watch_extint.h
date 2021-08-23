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
////< @file watch_extint.h

#include "hal_ext_irq.h"

/** @addtogroup buttons Buttons
  * @brief This section covers functions related to the three buttons: Light, Mode and Alarm.
  * @details The buttons are the core input UI of the watch, and the way the user will interact with
  *          your application. They are active high, pulled down by the microcontroller, and triggered
  *          when one of the "pushers" brings a tab from the metal frame into contact with the edge
  *          of the board. Note that the buttons can only wake the watch from STANDBY mode (except maybe for the
  *          ALARM button; still working on that one). The external interrupt controller runs in
             STANDBY mode, but it does not runin BACKUP mode; to wake from BACKUP, buttons will not cut it,
  */
/// @{
/** @brief Enables the external interrupt controller for use with the buttons.
  * @note The BTN_ALARM button runs off of an interrupt in the the RTC controller, not the EIC. If your
  *       application ONLY makes use of the alarm button, you do not need to call this method; you can
  *       save ~5µA by leaving the EIC disabled and only registering a callback for BTN_ALARM.
  */
void watch_enable_buttons();

/** @brief Configures an external interrupt on one of the button pins.
  * @param pin One of pins BTN_LIGHT, BTN_MODE or BTN_ALARM.
  * @param callback The function you wish to have called when the button is pressed.
  * @note The BTN_ALARM button runs off of an interrupt in the the RTC controller, not the EIC. This
  *       implementation detail should not make any difference to your app,
  */
void watch_register_button_callback(const uint8_t pin, ext_irq_cb_t callback);
/// @}
