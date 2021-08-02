/**
  * Header file for Sensor Watch application
  * 
  * Ideally you should implement your app entirely within these functions, as well as any
  * interrupt callbacks you register with the watch API. The general flow is as follows:
  * 
  * 1. main.c configures the watch
  * 2. main.c calls your app_init() function. 
  *      - You may wish to enable some functionality and peripherals here.
  *      - You should definitely set up some wake-up sources here.
  * 3. main.c calls your app_loop() function. 
  *      - Run code and update your UI here.
  * 4. main.c calls your app_prepare_for_sleep() function.
  *      - Consider resetting any state that was set in your wakeup callback here.
  *      - You may also want to disable / depower external sensors or peripherals here.
  * 5. main.c enters the STANDBY sleep mode.
  *      - No user code will run, and the watch will enter a low power mode.
  *      - The watch will remain in this state until something from (2) wakes it.
  * 6. main.c calls your app_wake_from_sleep() function.
  *      - You may wish to re-enable any peripherals you disabled.
  *      - After this, execution resumes at step (3).
  */

#include "watch.h"

void app_init();
void app_loop();
void app_prepare_for_sleep();
void app_wake_from_sleep();
