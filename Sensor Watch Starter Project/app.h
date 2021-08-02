/**
  * Header file for Sensor Watch application
  *
  * You should be able to write a watch app by simply implementing these functions
  * and declaring callbacks for various GPIO and peripheral interrupts. The main.c
  * file takes care of calling these functions for you. The general flow:
  *
  * 1. Your app_init() function is called.
  *      - This method should only be used to set your initial application state.
  * 2. If your app is waking from BACKUP, app_wake_from_deep_sleep()  is called.
  *      - If you saved state in the RTC's backup registers, you can restore it here.
  * 3. Your app_setup() method is called.
  *      - You may wish to enable some functionality and peripherals here.
  *      - You should definitely set up some interrupts here.
  * 4. The main run loop begins: your app_loop() function is called.
  *      - Run code and update your UI here.
  *      - Return true if your app is prepared to enter STANDBY mode.
  * 5. This step differs depending on the value returned by app_loop:
  *      - If you returned false, execution resumes at (4).
  *      - If you returned true, app_prepare_for_sleep() is called; execution moves on to (6).
  * 6. The microcontroller enters the STANDBY sleep mode.
  *      - No user code will run, and the watch will enter a low power mode.
  *      - The watch will remain in this state until an interrupt wakes it.
  * 7. Once woken from STANDBY, your app_wake_from_sleep() function is called.
  *      - After this, execution resumes at (4).
  */

void app_init();
void app_wake_from_deep_sleep();
void app_setup();
bool app_loop();
void app_prepare_for_sleep();
void app_wake_from_sleep();
