
#include "watch_hpt.h"



void (*hpt_isr_callback)(HPT_CALLBACK_CAUSE) = 0;

void __TC2_ISR() {
    // check flags
    HPT_CALLBACK_CAUSE cause;
    cause.overflow = false; // TC2.INTFLAG.OVF
    cause.compare_match = false; // TC2.INTFLAG.MC0
    // clear interrupt flags
    // TC2.INTFLAG = 0xFF
    if(hpt_isr_callback != 0) {
        (*hpt_isr_callback)(cause);
    }
}

void watch_hpt_init(void (*callback_function)(HPT_CALLBACK_CAUSE)) {
    hpt_isr_callback = callback_function;

    // set up clock generator for TC2 at 1024hz

    // Let's use gen 2 for this

    // Setup generator 2 for 1024 output
    // GENCTRL2:
    // SRC = 0x4 - external 32k oscillator
    // DIV = 5 - 32k/ (2^5) = 1k
    // DIVSEL = 1 - divide clock by 2^DIV, not just by DIV. (of course, 32 could easily fit in DIV, but it's a power of two, why not)
    // RUNSTDBY = 0 - this only seems needed if it's powering a pin, which it is not.
    // OE = 0 - no output
    // OOV = 0 - i don't think this matters
    // IDC = 0 - don't think we need to worry about duty cycle
    // GENEN = 0 - don't enable it just yet (actually it might be okay to leave it enabled all the time. Hopefully there is no warm-up time)

    // Configure generator 2 as the source for TC2
    // TC2/3 is peripheral 24
    // PCHCTRL24:
    // WRTLOCK = 0 // don't write lock it (maybe do write lock it?)
    // CHEN = 1 // do enable the channel mapping
    // GEN = 2 -- select generator 2 we just configured

    // Configure TC2 to count up to MAX and generate appropriate interrupts, but don't turn it on

    // TC2.CTRLA:
    // COPEN0 = 0 - not doing any captures
    // COPEN1 = 0
    // CAPTEN0 = 0 - CC0 is our main compare channel not a capture channel
    // CAPTEN1 = 0
    // ALOCK = ? - we should figure out what this is for, maybe this will help with interrupt handling
    // PRESCALER = 0 - input clock is already 1024hz
    // ONDEMAND = 1 - only request clock active when timer is running. This is fine if this is the only peripheral using our clock generator
    // RUNSTDBY = 1 - we do want the timer to continue running in standby, so it may be used to wake up the cpu and perform tasks
    // PRESCSYNC = 0 - we are not using the prescaler anyway, so this doesn't matter
    // MODE = 2 - 32-bit mode
    // ENABLE = 0 don't enable it just yet

    // TC2.COUNT = 0 // just clear it to be safe
    // TC2.CC0 = 0

    // TC2.INTENSET: enabling interrupts
    // OVF = 1 - always enable overflow interrupt
}

void watch_hpt_enable(void) {
    // enable clock generator
    // GENCTRL2.GENEN = 1

    // start timer
    // TC2.ENABLE = 1

    // Don't wait for enable here, it can be waited for on other operations that need it

}

void watch_hpt_disable(void) {
    // stop timer
    // TC2.ENABLE = 0

    // stop clock generator
    // GENCTRL2.GENEN = 0
}

void watch_hpt_schedule_callback(uint32_t timestamp) {
    // set compare channel
    // TC2.CC0 = timestamp
    // enable interrupt
    // TC2.INTENSET.MC0 = 1
}

void watch_hpt_disable_scheduled_callback(void) {
    // disable interrupt
    // TC2.INTENCLR.MC0 = 1
}

uint32_t watch_hpt_get(void) {
    // synchronize a read of the count value
    // TC2.CTRLBSET.CMD = 0x4 - force READSYNC

    // wait for synchronization to complete. Also wait for timer to be enabled if it was *just* turned on
    // while(TC2.SYNCBUSY.COUNT == 1 || TC2.SYNCBUSY.ENABLE == 1);

    // return TC2.COUNT;
    return 0;
}