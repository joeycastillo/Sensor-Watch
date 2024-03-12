#ifndef WATCH_HPT_H__
#define WATCH_HPT_H__

#include <inttypes.h>

/**
 * watch_hpt provides low-level access to the high-precision timer.
 * 
 * These methods are not intended to be used by watch faces. See the 
 * "movement_hpt_*" faces in movement.h instead.
*/

/**
 * Enables the high-precision timer and resets its value to zero
*/
void watch_hpt_enable();

/**
 * Stops the high-precision timer and powers it down.
*/
void watch_hpt_disable();

/**
 * Returns the current timetamp of the high-precision timer.
*/
uint32_t watch_hpt_get();

/**
 * Registers the given callback function to be invoked at the given timestamp value.
 * 
 * Replaces any previously registered callback function.
*/
void watch_hpt_register_callback(uint32_t timestamp, void (*callback_function)());

/**
 * Registers the given callback function to be invoked when the high-precision timer overflows.
*/
void watch_hpt_register_overflow(void (*callback_function)());


#endif