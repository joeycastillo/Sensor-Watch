#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include "watch_hpt.h"
#include <stdio.h>

// the performance.now timestamp when the timer was enabled
volatile double simhpt_enabled_timestamp = 0;
// the number of counts previously accumulated from other instances of running
volatile uint32_t simhpt_paused_count = 0;
// whether the callback needs to be invoked
volatile bool simhpt_callback_enabled;
// the timestamp the callback needs to be invoked at
volatile uint32_t simhpt_callback_timestamp;
volatile bool simhpt_running = false;
void (*simhpt_callback_function)(HPT_CALLBACK_CAUSE cause) = 0;

long simhpt_overflow_timeout_handle = 0;
long simhpt_compare_timeout_handle = 0;

const double OVERFLOW_MSECS = (double)(UINT32_MAX) * (1024.0 / 1000.0); // this might be backwards, but it's close enough who cares

#define HPT_DEBUG

static void cb_overflow(void *_unused)
{
#ifdef HPT_DEBUG
    printf("hpt-isr-overflow cause=%s\r\n", (char *)_unused);
#endif
    // fire off an interrupt
    if (simhpt_callback_function)
    {
        HPT_CALLBACK_CAUSE cause;
        cause.compare_match = false;
        cause.overflow = true;
        cause._padding = 0;
        (*simhpt_callback_function)(cause);
    }
    // schedule another overflow
    simhpt_overflow_timeout_handle = emscripten_set_timeout(&cb_overflow, OVERFLOW_MSECS, "repeat");
}

volatile bool cb_compare_updated_timeout = false;

static void cb_compare(void *_unused)
{
#ifdef HPT_DEBUG
    printf("hpt-isr-compare\r\n");
#endif

    // keep track of whether the callback function set a new callback time or cleared it
    // if they did not, we need to automatically trigger another one when the timer overflows
    cb_compare_updated_timeout = false;
    // fire off an interrupt
    if (simhpt_callback_function)
    {
        HPT_CALLBACK_CAUSE cause;
        cause.compare_match = true;
        cause.overflow = false;
        cause._padding = 0;
        (*simhpt_callback_function)(cause);
    }

    // they did not set a new timeout or clear it as a result of this callback, so set a new one automatically
    if (cb_compare_updated_timeout == false)
    {
        simhpt_compare_timeout_handle = emscripten_set_timeout(&cb_compare, OVERFLOW_MSECS, 0);
    }
}

void watch_hpt_init(void (*callback_function)(HPT_CALLBACK_CAUSE cause))
{
    simhpt_callback_function = callback_function;
    simhpt_paused_count = 0;
    simhpt_running = false;
    simhpt_enabled_timestamp = 0;
    simhpt_overflow_timeout_handle = 0;
    simhpt_callback_enabled = false;
    simhpt_callback_timestamp = 0;
    simhpt_compare_timeout_handle = 0;
}

void watch_hpt_enable(void)
{
    if (!simhpt_running)
    {
#ifdef HPT_DEBUG
        printf("enabling hpt\r\n");
#endif
        simhpt_enabled_timestamp = emscripten_performance_now();
        simhpt_running = true;

        uint32_t timer_value = simhpt_paused_count;
#ifdef HPT_DEBUG
        printf("stored ticks: %d\r\n", timer_value);
#endif

        // I am at my wits end here. I cannot figure out why emscripten invokes this callback method almost immediately
        // if I use a fake value for msec_until_next_overflow of "UINT32_MAX", it seems to work
        // If i use the real value it's supposed to be, which is like, 99% of UINT32_MAX, it does not.
        // It must be a bug with how emscripten or javascript handles extremely long timeout values.
        // I think definitely, because JS uses a signed 32-bit integer for the delay, meaning it will do weird shit with these large values.
        //
        // We'll have to work around that limitation by chaining timeouts together and counting manually
        //
        // For now, just never send overflow events when running in the simulator. Still good for like, 49 days.
        //
        // uint32_t ticks_until_next_overflow = UINT32_MAX - timer_value;
        // double msec_until_next_overflow_actual = ((double)ticks_until_next_overflow) / 1.024;
        // double msec_until_next_overflow = OVERFLOW_MSECS / 2.0;
        // // always set an overflow timeout
        // // double msec_until_overflow = (double)(UINT32_MAX - timer_value) / 1.024;
        //  printf("msec until overflow fake: %f\r\n", msec_until_next_overflow);
        //  printf("msec until overflow calc: %f\r\n", msec_until_next_overflow_actual);
        // simhpt_overflow_timeout_handle = emscripten_set_timeout(&cb_overflow, 10.0*60.0*1000.0, "enable");

        // see if/when we need to in voke the callback timeout
        if (simhpt_callback_enabled)
        {
            double sec_until_callback = (double)(simhpt_callback_timestamp - timer_value) / 1024.0;
            if (sec_until_callback < 0)
            {
                // roll it forward one overflow amount
                sec_until_callback += ((double)UINT32_MAX) / 1024.0;
            }
            simhpt_compare_timeout_handle = emscripten_set_timeout(&cb_compare, sec_until_callback * 1000.0, 0);
        }
    }
}
void watch_hpt_disable(void)
{
    if (simhpt_running)
    {
#ifdef HPT_DEBUG
        printf("hpt disabled\r\n");
#endif
        if (simhpt_overflow_timeout_handle)
        {
            emscripten_clear_timeout(simhpt_overflow_timeout_handle);
        }
        if (simhpt_compare_timeout_handle)
        {
            emscripten_clear_timeout(simhpt_compare_timeout_handle);
        }

        double msec_active_for = emscripten_performance_now() - simhpt_enabled_timestamp;
        double ticks_active_for = msec_active_for * 1.024;
        simhpt_paused_count += ticks_active_for;
        simhpt_running = false;
    }
}

uint32_t watch_hpt_get(void)
{
    if (simhpt_running)
    {
        double msec = emscripten_performance_now() - simhpt_enabled_timestamp;
        double ticks = msec * 1.024;
        uint64_t accumulated_ticks = ((uint64_t)ticks) + simhpt_paused_count;
#ifdef HPT_DEBUG
        printf("hpt-get-running: %d\r\n", accumulated_ticks);
#endif
        return accumulated_ticks;
    }
    else
    {
#ifdef HPT_DEBUG
        printf("hpt-get-paused: %d\r\n", simhpt_paused_count);
#endif
        return simhpt_paused_count;
    }
}

uint32_t watch_hpt_get_fast(void)
{
    return watch_hpt_get();
}
void watch_hpt_schedule_callback(uint32_t timestamp)
{
    cb_compare_updated_timeout = true;

    uint32_t current_time = watch_hpt_get();
    double seconds_until_callback = 0.0;
    if (timestamp > current_time)
    {
        // no problem, schedule as normal
        seconds_until_callback = ((double)(timestamp - current_time)) / 1024.0;
    }
    else
    {
        // compare will still occur, but it will be next time around
        seconds_until_callback = ((double)(timestamp - current_time) + (OVERFLOW_MSECS / 1000.0)) / 1024.0;
    }

    // save these values to they can pause and resume the timer and the callbacks will be re-scheduled.
    simhpt_callback_enabled = true;
    simhpt_callback_timestamp = timestamp;

    emscripten_clear_timeout(simhpt_compare_timeout_handle);
    emscripten_set_timeout(&cb_compare, seconds_until_callback * 1000.0, 0);
}
void watch_hpt_disable_scheduled_callback(void)
{
    cb_compare_updated_timeout = true;

    simhpt_callback_enabled = false;
    emscripten_clear_timeout(simhpt_compare_timeout_handle);
}
