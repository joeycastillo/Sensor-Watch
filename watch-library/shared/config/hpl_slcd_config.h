/* Auto-generated config file hpl_slcd_config.h */
#ifndef HPL_SLCD_CONFIG_H
#define HPL_SLCD_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <hpl_slcd_cm.h>
#include <peripheral_clk_config.h>
#include "pins.h"

// <h> Standard configuration

// <o> Number of COM Lines
// <i> Number of COM Lines
// <0=>1
// <1=>2
// <2=>3
// <3=>4
// <4=>6
// <5=>8
// <id> slcd_arch_com_num
#ifndef CONF_SLCD_COM_NUM
#define CONF_SLCD_COM_NUM 2
#endif

// <o> Number of Segment Lines <1-44>
// <i> Number of Segment Lines
// <id> slcd_arch_seg_num
#ifndef CONF_SLCD_SEG_NUM
#define CONF_SLCD_SEG_NUM 24
#endif

#if CONF_SLCD_COM_NUM == SLCD_CTRLA_DUTY_SIXTH_Val && CONF_SLCD_SEG_NUM > 42
#warning Segment number should less than or equals to 42
#endif
#if CONF_SLCD_COM_NUM == SLCD_CTRLA_DUTY_EIGHT_Val && CONF_SLCD_SEG_NUM > 40
#warning Segment number should less than or equals to 40
#endif

// <o> Bias
// <i> Bias Settting
// <0=>STATIC
// <1=>HALF
// <2=>THIRD
// <3=>FOURTH
// <id> slcd_arch_bias
#ifndef CONF_SLCD_BIAS
#define CONF_SLCD_BIAS 2
#endif

#if CONF_SLCD_COM_NUM == 0 && CONF_SLCD_BIAS != 0
#warning Recommended Bias for 1 common terminal is STATIC
#elif CONF_SLCD_COM_NUM == 1 && CONF_SLCD_BIAS != 1
#warning Recommended Bias for 2 Common Terminals is HALF
#elif CONF_SLCD_COM_NUM <= 4 && CONF_SLCD_BIAS != 2
#warning Recommended Bias for 3/4/6 Common Terminals is THIRD
#elif CONF_SLCD_COM_NUM == 5 && CONF_SLCD_BIAS != 3
#warning Recommended Bias for 8 Common Terminals is FOURTH
#endif

// <q> Bias Buffer Enable
// <i> Enable Bias Buffer
// <id> slcd_arch_bben
#ifndef CONF_SLCD_BBEN
#define CONF_SLCD_BBEN 1
#endif

// <o> Bias Buffer Enable Duration <1-16>
// <i> Configure the enable duration of the bias buffer, unit is cycle of SLCD OSC clock source
// <id> slcd_arch_bbd
#ifndef CONF_SLCD_BBD
#define CONF_SLCD_BBD 2
#endif

// <o> Clock Prescaler
// <i> Setting for LCD frame frequency
// <0=>16
// <1=>32
// <2=>64
// <3=>128
// <id> slcd_arch_presc
#ifndef CONF_SLCD_PRESC
#define CONF_SLCD_PRESC 1
#endif

// <o> Clock Divider
// <i> Setting for LCD frame frequency
// <0=>1
// <1=>2
// <2=>3
// <3=>4
// <4=>5
// <5=>6
// <6=>7
// <7=>8
// <id> slcd_arch_ckdiv
#ifndef CONF_SLCD_CKDIV
#define CONF_SLCD_CKDIV 5
#endif

/* TODO add frame frequency check */

// <o> Reference Refresh Frequency
// <i> Setting for Reference Refresh Frequency
// <0=>2kHz
// <1=>1kHz
// <2=>500Hz
// <3=>250Hz
// <4=>125Hz
// <5=>62.5Hz
// <id> slcd_arch_rrf
#ifndef CONF_SLCD_RRF
#define CONF_SLCD_RRF 5
#endif

// <o> Power Refresh Frequency
// <i> Setting for Charge pump Refresh Frequency
// <0=>2kHz
// <1=>1kHz
// <2=>500Hz
// <3=>250Hz
// <id> slcd_arch_prf
#ifndef CONF_SLCD_PRF
#define CONF_SLCD_PRF 3
#endif

// <q> External VLCD
// <i> Setting for how VLCD is generated
// <id> slcd_arch_xvlcd
#ifndef CONF_SLCD_XVLCD
#define CONF_SLCD_XVLCD 0
#endif

// <o> Waveform Mode
// <i> Setting for Waveform Mode
// <0=>Low Power Waveform(frame-inversion)
// <1=>Standard Waveform Mode(bit-inversion)
// <id> slcd_arch_wmod
#ifndef CONF_SLCD_WMOD
#define CONF_SLCD_WMOD 0
#endif

// <o> Contrast Adjustment
// <i> The contrast of the LCD is determined by the value of VLCD voltage.
// <i> The higher the VLCD voltage, the higher is the contrast.
// <i> The software contrast adjustment is only possible in internal supply mode.
// <0=>2.5056V
// <1=>2.5731V
// <2=>2.6379V
// <3=>2.7054V
// <4=>2.7729V
// <5=>2.8404V
// <6=>2.9052V
// <7=>2.9727V
// <8=>3.0402V
// <9=>3.1077V
// <10=>3.1725V
// <11=>3.24V
// <12=>3.3075V
// <13=>3.375V
// <14=>3.4398V
// <15=>3.5073V
// <id> slcd_arch_contrast_adjust
#ifndef CONF_SLCD_CONTRAST_ADJUST
#define CONF_SLCD_CONTRAST_ADJUST 14
#endif

// </h>

// <e> Advanced configuration
// <id> slcd_arch_advanced_settings
#ifndef CONF_SLCD_ADVANCED_SETTINGS
#define CONF_SLCD_ADVANCED_SETTINGS 1
#endif

// <q> Run in standby
// <i> Indicates whether the SLCD will continue running in standby sleep mode or not
// <id> slcd_arch_runstdby
#ifndef CONF_SLCD_RUNSTDBY
#define CONF_SLCD_RUNSTDBY 1
#endif

// </e>

#if SLCD_FRAME_FREQUENCY < 30 || SLCD_FRAME_FREQUENCY > 100
#warning The optimal frame frequency should be in range from 30Hz up to 100Hz to avoid flickering and ghosting effect.
#endif

#define SLCD_FC_MAX_MS (((0x1F + 1) * 8) * (1000 / SLCD_FRAME_FREQUENCY))
#define SLCD_FC_MIN_MS (1000 / SLCD_FRAME_FREQUENCY)
#define SLCD_FC_BYPASS_MAX_MS ((0x1F + 1) * (1000 / SLCD_FRAME_FREQUENCY))

// <e> Character Mapping Setting
// <id> slcd_arch_cm_setting
#ifndef CONF_SLCD_CM_ENABLE
#define CONF_SLCD_CM_ENABLE 0
#endif

/**
 * character lookup table
 */
#ifndef CONF_SLCD_LPENL
#define CONF_SLCD_LPENL (\
		(uint32_t)1 <<  0 | \
		(uint32_t)1 <<  1 | \
		(uint32_t)1 <<  2 | \
		(uint32_t)1 <<  3 | \
		(uint32_t)1 <<  4 | \
		(uint32_t)1 <<  5 | \
		(uint32_t)1 <<  6 | \
		(uint32_t)1 <<  7 | \
		(uint32_t)1 << 11 | \
		(uint32_t)1 << 12 | \
		(uint32_t)1 << 13 | \
		(uint32_t)1 << 14 | \
		(uint32_t)1 << 21 | \
		(uint32_t)1 << 22 | \
		(uint32_t)1 << 23 | \
		(uint32_t)1 << 24 | \
		(uint32_t)1 << 25 | \
		(uint32_t)1 << 28 | \
		(uint32_t)1 << 29 | \
		(uint32_t)1 << 30 | \
		(uint32_t)1 << 31 | 0)
#endif // CONF_SLCD_LPENL

#ifndef CONF_SLCD_LPENH
#define CONF_SLCD_LPENH (\
		(uint32_t)1 << (32 - 32) | \
		(uint32_t)1 << (33 - 32) | \
		(uint32_t)1 << (34 - 32) | \
		(uint32_t)1 << (35 - 32) | \
		(uint32_t)1 << (42 - 32) | \
		(uint32_t)1 << (43 - 32) | 0)
#endif // CONF_SLCD_LPENH

// <<< end of configuration section >>>

#endif // HPL_SLCD_CONFIG_H
