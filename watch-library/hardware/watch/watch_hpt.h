#ifndef WATCH_HPT_H__
#define WATCH_HPT_H__

#include <inttypes.h>

/**
 * Defines the reasons the HPT callback is being invoked. More than one flag may be set.
*/
typedef struct {
    /**
     * The callback is being invoked because of an error in the comparison (?)
    */
    bool cmp_error :1;
    /**
     * The callback is being invoked because the count is equal to the scheduled timestamp
    */
    bool compare_match :1;
    /**
     * The callbac is being invoked because the counter overflowed and reset to zero.
    */
    bool overflow :1;

    // not used
    uint8_t _padding :5;
} HPT_CALLBACK_CAUSE;

/**
 * watch_hpt provides low-level access to the high-precision timer.
 * 
 * These methods are not intended to be used by watch faces. See the 
 * "movement_hpt_*" faces in movement.h instead.
*/

/**
 * Performs one-time setup of the peripherals used by the high-precision timer.
 * 
 * Does not enable the timer.
*/
void watch_hpt_init();

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
 * - timestamp: the counter value at which the callback should be triggered.
 * - callback_function: a pointer to a callback function that should be invoked when a HPT event occurs. Pass null (0) to disable callbacks
 * - enabled_triggers: a set of flags indicating which counter events should trigger the callback
 * 
 * Replaces any previously registered callback function.
*/
void watch_hpt_register_callback(uint32_t timestamp, void (*callback_function)(HPT_CALLBACK_CAUSE cause), HPT_CALLBACK_CAUSE enabled_triggers);

#endif