
#include "watch_hpt.h"

#include "parts.h"

// user HPT callback
void (*hpt_isr_callback)(HPT_CALLBACK_CAUSE) = 0;

// actual HPT ISR
void TC2_Handler(void)
{
    // check flags
    HPT_CALLBACK_CAUSE cause;
    cause.overflow = TC2->COUNT32.INTFLAG.bit.OVF != 0;      // TC2.INTFLAG.OVF
    cause.compare_match = TC2->COUNT32.INTFLAG.bit.MC0 != 0; // TC2.INTFLAG.MC0
    // clear interrupt flags
    // TC2.INTFLAG = 0xFF
    // silly that you have to write ones these flags to clear them
    TC2->COUNT32.INTFLAG.reg = 0xFF;

    if (hpt_isr_callback != 0)
    {
        (*hpt_isr_callback)(cause);
    }
}

void watch_hpt_init(void (*callback_function)(HPT_CALLBACK_CAUSE))
{
    hpt_isr_callback = callback_function;

    // set up clock generator for TC2 at 1024hz

    // Let's use gen 2 for this

    GCLK_CRITICAL_SECTION_ENTER();

    // Setup generator 2 for 1024 output
    // GENCTRL2:
    // SRC = 0x4 - external 32k oscillator
    // DIV = 4 - 32k/ (2^(4+1)) = 1k
    // DIVSEL = 1 - divide clock by 2^(DIV+1), not just by DIV. (of course, 32 could easily fit in DIV, but it's a power of two, why not)
    // RUNSTDBY = 0 - this only seems needed if it's powering a pin, which it is not.
    // OE = 0 - no output
    // OOV = 0 - i don't think this matters
    // IDC = 0 - don't think we need to worry about duty cycle
    // enable it too
    GCLK->GENCTRL[2].reg =
        GCLK_GENCTRL_SRC_XOSC32K |
        GCLK_GENCTRL_DIV(4) |
        GCLK_GENCTRL_DIVSEL |
        GCLK_GENCTRL_GENEN;

    // Configure generator 2 as the source for TC2
    // TC2/3 is peripheral 24
    // PCHCTRL24:
    // WRTLOCK = 0 // don't write lock it (maybe do write lock it?)
    // CHEN = 1 // do enable the channel mapping
    // GEN = 2 -- select generator 2 we just configured

    GCLK->PCHCTRL[24].reg =
        GCLK_PCHCTRL_CHEN |
        GCLK_PCHCTRL_GEN_GCLK2;

    GCLK_CRITICAL_SECTION_LEAVE();

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
    TC_CRITICAL_SECTION_ENTER();

    // reset counter
    TC2->COUNT32.CTRLA.bit.SWRST = 1;
    while(TC2->COUNT32.SYNCBUSY.bit.SWRST != 0);

    TC2->COUNT32.CTRLA.reg =
        TC_CTRLA_ONDEMAND |
        TC_CTRLA_RUNSTDBY |
        TC_CTRLA_MODE_COUNT32;

    // TC2.COUNT = 0 // just clear it to be safe
    // TC2.CC0 = 0
    TC2->COUNT32.COUNT.bit.COUNT = 0;
    while(TC2->COUNT32.SYNCBUSY.bit.COUNT != 0);
  //  TC2->COUNT32.CC[0].bit.CC = UINT32_MAX -1;
  //  while(TC2->COUNT32.SYNCBUSY.bit.CC0 != 0);

    // enable TC2 interrupt

    NVIC_DisableIRQ(TC2_IRQn);


    // TC2.INTENSET: enabling interrupts
    // OVF = 1 - always enable overflow interrupt
    // disable compare match interrupt to start
    TC2->COUNT32.INTENCLR.bit.MC0 = 1;
    TC2->COUNT32.INTENSET.bit.OVF = 1;
    
    TC2->COUNT32.INTFLAG.reg = 0xFF;

    NVIC_ClearPendingIRQ(TC2_IRQn);
    NVIC_EnableIRQ(TC2_IRQn);

    TC_CRITICAL_SECTION_LEAVE();

}

void watch_hpt_enable(void)
{
    // start timer
    // TC2.ENABLE = 1
    TC_CRITICAL_SECTION_ENTER();
    TC2->COUNT32.CTRLA.bit.ENABLE = 1;
    while (TC2->COUNT32.SYNCBUSY.bit.ENABLE != 0)
        ;
    TC_CRITICAL_SECTION_LEAVE();
}

void watch_hpt_disable(void)
{
    // stop timer
    // TC2.ENABLE = 0
    TC_CRITICAL_SECTION_ENTER();
    TC2->COUNT32.CTRLA.bit.ENABLE = 0;
    while (TC2->COUNT32.SYNCBUSY.bit.ENABLE != 0);
    TC_CRITICAL_SECTION_LEAVE();
}

void watch_hpt_schedule_callback(uint32_t timestamp)
{
    // set compare channel
    // TC2.CC0 = timestamp
    // enable interrupt
    // TC2.INTENSET.MC0 = 1

    TC_CRITICAL_SECTION_ENTER();
    TC2->COUNT32.CC[0].reg = timestamp;
    while(TC2->COUNT32.SYNCBUSY.bit.CC0);
    TC2->COUNT32.INTFLAG.reg = 0xFF;

    TC2->COUNT32.INTENSET.bit.MC0 = 1;
    TC_CRITICAL_SECTION_LEAVE();
}

void watch_hpt_disable_scheduled_callback(void)
{
    // disable interrupt
    // TC2.INTENCLR.MC0 = 1
    TC_CRITICAL_SECTION_ENTER();
    TC2->COUNT32.INTENCLR.bit.MC0 = 1;
    TC_CRITICAL_SECTION_LEAVE();
}

// There is a lot of busy-waiting in here that involves synchronizing stuff between the main CPU and the timer
// For example, when reading from the timer, the count must be synchronized first by executing a "READSYNC" command.
// This command gets executed on the next TC clock cycle, which is running at 1024hz, meaning the CPU might be spinning
// for up to a millisecond just to read the value from the counter.

// This is somewhat unfortunate, because interrupt triggering is much faster than that. I was having trouble with the
// ISR on compare events because I'd schedule an event at like, t=1000, but when I called watch_hpt_get() from inside
// the ISR, I would get some lower value like t=996.

// After adding the appropriate busy-wait checks for synchronization, it started coming back correct. If I scheduled a
// callback at T=1000, I could call watch_hpt_get() inside the ISR and it would return T=1005. A later timestamp is 
// fine, but does this mean that the CPU was just spinning for 5 milliseconds waiting for the timer?

// There's gotta be a faster technique for synchronizing the timer and CPU.

uint32_t watch_hpt_get(void)
{
    // synchronize a read of the count value
    // TC2.CTRLBSET.CMD = 0x4 - force READSYNC
    TC_CRITICAL_SECTION_ENTER();
    TC2->COUNT32.CTRLBSET.reg = TC_CTRLBSET_CMD_READSYNC;

    // wait for command to be executed
    while(TC2->COUNT32.CTRLBSET.bit.CMD);

    // wait for sync to occur?
    while (TC2->COUNT32.SYNCBUSY.bit.CTRLB);
      // this might not be necessary?

    // wait for count to be synchronized
    while (TC2->COUNT32.SYNCBUSY.bit.COUNT);

    // finally safe to read count
    uint32_t count = TC2->COUNT32.COUNT.bit.COUNT;
    TC_CRITICAL_SECTION_LEAVE();
    return count;
}