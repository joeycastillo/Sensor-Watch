/* Auto-generated config file hpl_tc_config.h */
#ifndef HPL_TC_CONFIG_H
#define HPL_TC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#ifndef CONF_TC0_ENABLE
#define CONF_TC0_ENABLE 1
#endif

#include "peripheral_clk_config.h"

// <h> Basic configuration

// <o> Prescaler
// <0x0=> No division
// <0x1=> Divide by 2
// <0x2=> Divide by 4
// <0x3=> Divide by 8
// <0x4=> Divide by 16
// <0x5=> Divide by 64
// <0x6=> Divide by 256
// <0x7=> Divide by 1024
// <i> This defines the prescaler value
// <id> timer_prescaler
#ifndef CONF_TC0_PRESCALER
#define CONF_TC0_PRESCALER 0x3
#endif

// <o> Length of one timer tick in uS <0-4294967295>
// <id> timer_tick
#ifndef CONF_TC0_TIMER_TICK
#define CONF_TC0_TIMER_TICK 1000
#endif
// </h>

// <e> Advanced configuration
// <id> timer_advanced_configuration
#ifndef CONF_TC0__ADVANCED_CONFIGURATION_ENABLE
#define CONF_TC0__ADVANCED_CONFIGURATION_ENABLE 0
#endif

// <y> Prescaler and Counter Synchronization Selection
// <TC_CTRLA_PRESCSYNC_GCLK_Val"> Reload or reset counter on next GCLK
// <TC_CTRLA_PRESCSYNC_PRESC_Val"> Reload or reset counter on next prescaler clock
// <TC_CTRLA_PRESCSYNC_RESYNC_Val"> Reload or reset counter on next GCLK and reset prescaler counter
// <i> These bits select if on retrigger event, the Counter should be cleared or reloaded on the next GCLK_TCx clock or on the next prescaled GCLK_TCx clock.
// <id> tc_arch_presync
#ifndef CONF_TC0_PRESCSYNC
#define CONF_TC0_PRESCSYNC TC_CTRLA_PRESCSYNC_GCLK_Val
#endif

// <q> Run in standby
// <i> Indicates whether the module will continue to run in standby sleep mode
// <id> tc_arch_runstdby
#ifndef CONF_TC0_RUNSTDBY
#define CONF_TC0_RUNSTDBY 0
#endif

// <q> Run in debug mode
// <i> Indicates whether the module will run in debug mode
// <id> tc_arch_dbgrun
#ifndef CONF_TC0_DBGRUN
#define CONF_TC0_DBGRUN 0
#endif

// <q> Run on demand
// <i> Run if requested by some other peripheral in the device
// <id> tc_arch_ondemand
#ifndef CONF_TC0_ONDEMAND
#define CONF_TC0_ONDEMAND 0
#endif

// </e>

// <e> Event control
// <id> timer_event_control
#ifndef CONF_TC0_EVENT_CONTROL_ENABLE
#define CONF_TC0_EVENT_CONTROL_ENABLE 0
#endif

// <q> Output Event On Match or Capture on Channel 0
// <i> Enable output of event on timer tick
// <id> tc_arch_mceo0
#ifndef CONF_TC0_MCEO0
#define CONF_TC0_MCEO0 0
#endif

// <q> Output Event On Match or Capture on Channel 1
// <i> Enable output of event on timer tick
// <id> tc_arch_mceo1
#ifndef CONF_TC0_MCEO1
#define CONF_TC0_MCEO1 0
#endif

// <q> Output Event On Timer Tick
// <i> Enable output of event on timer tick
// <id> tc_arch_ovfeo
#ifndef CONF_TC0_OVFEO
#define CONF_TC0_OVFEO 0
#endif

// <q> Event Input
// <i> Enable asynchronous input events
// <id> tc_arch_tcei
#ifndef CONF_TC0_TCEI
#define CONF_TC0_TCEI 0
#endif

// <q> Inverted Event Input
// <i> Invert the asynchronous input events
// <id> tc_arch_tcinv
#ifndef CONF_TC0_TCINV
#define CONF_TC0_TCINV 0
#endif

// <o> Event action
// <0=> Event action disabled
// <1=> Start, restart or re-trigger TC on event
// <2=> Count on event
// <3=> Start on event
// <4=> Time stamp capture
// <5=> Period captured in CC0, pulse width in CC1
// <6=> Period captured in CC1, pulse width in CC0
// <7=> Pulse width capture
// <i> Event which will be performed on an event
//<id> tc_arch_evact
#ifndef CONF_TC0_EVACT
#define CONF_TC0_EVACT 0
#endif
// </e>

// Default values which the driver needs in order to work correctly

// Mode set to 32-bit
#ifndef CONF_TC0_MODE
#define CONF_TC0_MODE TC_CTRLA_MODE_COUNT32_Val
#endif

// CC 1 register set to 0
#ifndef CONF_TC0_CC1
#define CONF_TC0_CC1 0
#endif

#ifndef CONF_TC0_ALOCK
#define CONF_TC0_ALOCK 0
#endif

// Not used in 32-bit mode
#define CONF_TC0_PER 0

// Calculating correct top value based on requested tick interval.
#define CONF_TC0_PRESCALE (1 << CONF_TC0_PRESCALER)

// Prescaler set to 64
#if CONF_TC0_PRESCALER > 0x4
#undef CONF_TC0_PRESCALE
#define CONF_TC0_PRESCALE 64
#endif

// Prescaler set to 256
#if CONF_TC0_PRESCALER > 0x5
#undef CONF_TC0_PRESCALE
#define CONF_TC0_PRESCALE 256
#endif

// Prescaler set to 1024
#if CONF_TC0_PRESCALER > 0x6
#undef CONF_TC0_PRESCALE
#define CONF_TC0_PRESCALE 1024
#endif

#ifndef CONF_TC0_CC0
#define CONF_TC0_CC0                                                                                                   \
	(uint32_t)(((float)CONF_TC0_TIMER_TICK / 1000000.f) / (1.f / (CONF_GCLK_TC0_FREQUENCY / CONF_TC0_PRESCALE)))
#endif

// <<< end of configuration section >>>

#endif // HPL_TC_CONFIG_H
