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
#ifndef _WATCH_APP_H_INCLUDED
#define _WATCH_APP_H_INCLUDED
////< @file watch_app.h

/** @addtogroup app Application Framework
  * @brief This section covers the functions that you will implement in your app.c file when designing a Sensor Watch app.
  * @details You should be able to write a watch app by simply implementing these functions and declaring callbacks for
  *          various GPIO and peripheral interrupts. The main.c file takes care of calling these functions for you. The
  *          general flow:
  *
  *            1. Your app_init() function is called.
  *               - This method should only be used to set your initial application state.
  *            2. If your app is waking from BACKUP, app_wake_from_backup() is called.
  *               - If you saved state in the RTC's backup registers, you can restore it here.
  *            3. Your app_setup() method is called.
  *               - You may wish to enable some functionality and peripherals here.
  *               - You should definitely set up some interrupts here.
  *            4. The main run loop begins: your app_loop() function is called.
  *               - Run code and update your UI here.
  *               - Return true if your app is prepared to enter STANDBY mode.
  *            5. This step differs depending on the value returned by app_loop:
  *               - If you returned false, execution resumes at (4).
  *               - If you returned true, app_prepare_for_standby() is called; execution moves on to (6).
  *            6. The microcontroller enters STANDBY mode.
  *               - No user code will run, and the watch will enter a low power mode.
  *               - The watch will remain in this state until an interrupt wakes it.
  *            7. Once woken from STANDBY, your app_wake_from_standby() function is called.
  *               - After this, execution resumes at (4).
  */
/// @{
/** @brief A function you will implement to initialize your application state. The app_init function is called before
  *        anything else. Use it to set up any internal data structures or application state required by your app,
  *        but don't configure any peripherals just yet.
  */
void app_init(void);

/** @brief A function you will implement to wake from BACKUP mode, which wipes the system's RAM, and with it, your
  *        application's state. You may have chosen to store some important application state in the RTC's backup
  *        registers prior to entering this mode. You may restore that state here.
  */
void app_wake_from_backup(void);

/** @brief A function you will implement to set up your application. The app_setup function is like setup() in Arduino.
  *        It is called once when the program begins. You should set pin modes and enable any peripherals you want to
  *        set up (real-time clock, I2C, etc.) Depending on your application, you may or may not want to configure
  *        sensors on your sensor board here. For example, a low-power accelerometer that will run at all times should
  *        be configured here, whereas you may want to enable a more power-hungry sensor only when you need it.
  * @note If your app enters the ultra-low power BACKUP sleep mode, this function will be called again when it wakes
  *       from that deep sleep state. In this state, the RTC will still be configured with the correct date and time.
  */
void app_setup(void);

/** @brief A function you will implement to serve as the app's main run loop. This method will be called repeatedly,
           or if you enter STANDBY mode, as soon as the device wakes from sleep.
  * @return You should return true if your app is prepared to enter STANDBY mode. If you return false, your app's
  *         app_loop method will be called again immediately. Note that in STANDBY mode, the watch will consume only
  *         about 95 microamperes of power, whereas if you return false and keep the app awake, it will consume about
  *         355 microamperes. This is the difference between months of battery life and days. As much as possible,
  *         you should limit the amount of time your app spends awake.
  * @note Only the RTC, the segment LCD controller and the external interrupt controller run in STANDBY mode. If you
  *       are using, e.g. the PWM function to set a custom LED color, you should return false here until you are
  *       finished with that operation. Note however that the peripherals will continue running after waking up,
  *       so e.g. the I2C controller, if configured, will sleep in STANDBY. But you can use it again as soon as your
  *       app wakes up.
  */
bool app_loop(void);

/** @brief A function you will implement to prepare to enter STANDBY mode. The app_prepare_for_standby function is
 *         called after your app_loop function returns true, and just before the watch enters STANDBY mode. In this
 *         mode most peripherals are shut down, and no code will run until the watch receives an interrupt (generally
 *         either the 1Hz tick or a press on one of the buttons).
 * @note If you are PWM'ing the LED or playing a sound on the buzzer, the TC/TCC peripherals that drive those operations
 *       will not run in STANDBY. BUT! the output pins will retain the state they had when entering standby. This means
 *       you could end up entering standby with an LED on and draining power, or with a DC potential across the piezo
 *       buzzer that could damage it if left in this state. If your app_loop does not prevent sleep during these
 *       activities, you should make sure to disable these outputs in app_prepare_for_standby.
 */
void app_prepare_for_standby(void);

/** @brief A method you will implement to configure the app after waking from STANDBY mode.
  */
void app_wake_from_standby(void);

/// @}
#endif
