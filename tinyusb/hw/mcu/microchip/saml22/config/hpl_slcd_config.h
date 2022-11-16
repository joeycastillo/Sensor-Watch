/* Auto-generated config file hpl_slcd_config.h */
#ifndef HPL_SLCD_CONFIG_H
#define HPL_SLCD_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <hpl_slcd_cm.h>
#include <peripheral_clk_config.h>

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
#define CONF_SLCD_COM_NUM 5
#endif

// <o> Number of Segment Lines <1-44>
// <i> Number of Segment Lines
// <id> slcd_arch_seg_num
#ifndef CONF_SLCD_SEG_NUM
#define CONF_SLCD_SEG_NUM 8
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
#define CONF_SLCD_BIAS 3
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
#define CONF_SLCD_PRESC 0
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
#define CONF_SLCD_CKDIV 3
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
#define CONF_SLCD_RRF 0
#endif

// <o> Power Refresh Frequency
// <i> Setting for Charge pump Refresh Frequency
// <0=>2kHz
// <1=>1kHz
// <2=>500Hz
// <3=>250Hz
// <id> slcd_arch_prf
#ifndef CONF_SLCD_PRF
#define CONF_SLCD_PRF 0
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
#define CONF_SLCD_CONTRAST_ADJUST 10
#endif

// </h>

// <e> Advanced configuration
// <id> slcd_arch_advanced_settings
#ifndef CONF_SLCD_ADVANCED_SETTINGS
#define CONF_SLCD_ADVANCED_SETTINGS 0
#endif

// <q> Run in standby
// <i> Indicates whether the SLCD will continue running in standby sleep mode or not
// <id> slcd_arch_runstdby
#ifndef CONF_SLCD_RUNSTDBY
#define CONF_SLCD_RUNSTDBY 0
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

// <e> 7 Segment Character Mapping Setting
// <id> slcd_arch_cm_7segs_setting
#ifndef CONF_SLCD_CM_7SEGS_SETTING
#define CONF_SLCD_CM_7SEGS_SETTING 0
#endif

// <o> Segment 0 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_0_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_0_SETTING
#define CONF_SLCD_CM_7SEGS_0_SETTING 0
#endif
// <o> Segment 1 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_1_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_1_SETTING
#define CONF_SLCD_CM_7SEGS_1_SETTING 1
#endif
// <o> Segment 2 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_2_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_2_SETTING
#define CONF_SLCD_CM_7SEGS_2_SETTING 2
#endif
// <o> Segment 3 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_3_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_3_SETTING
#define CONF_SLCD_CM_7SEGS_3_SETTING 3
#endif
// <o> Segment 4 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_4_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_4_SETTING
#define CONF_SLCD_CM_7SEGS_4_SETTING 4
#endif
// <o> Segment 5 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_5_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_5_SETTING
#define CONF_SLCD_CM_7SEGS_5_SETTING 5
#endif
// <o> Segment 6 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_7segs_6_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_7SEGS_6_SETTING
#define CONF_SLCD_CM_7SEGS_6_SETTING 6
#endif

// </e>

// <e> 14 Segment Character Mapping Setting
// <id> slcd_arch_cm_14segs_enable
#ifndef CONF_SLCD_CM_14SEGS_ENABLE
#define CONF_SLCD_CM_14SEGS_ENABLE 0
#endif

// <o> Segments 0 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_0_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_0_SETTING
#define CONF_SLCD_CM_14SEGS_0_SETTING 0
#endif

// <o> Segments 1 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_1_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_1_SETTING
#define CONF_SLCD_CM_14SEGS_1_SETTING 1
#endif

// <o> Segments 2 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_2_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_2_SETTING
#define CONF_SLCD_CM_14SEGS_2_SETTING 2
#endif

// <o> Segments 3 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_3_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_3_SETTING
#define CONF_SLCD_CM_14SEGS_3_SETTING 3
#endif

// <o> Segments 4 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_4_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_4_SETTING
#define CONF_SLCD_CM_14SEGS_4_SETTING 4
#endif

// <o> Segments 5 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_5_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_5_SETTING
#define CONF_SLCD_CM_14SEGS_5_SETTING 5
#endif

// <o> Segments 6 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_6_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_6_SETTING
#define CONF_SLCD_CM_14SEGS_6_SETTING 6
#endif

// <o> Segments 7 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_7_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_7_SETTING
#define CONF_SLCD_CM_14SEGS_7_SETTING 7
#endif

// <o> Segments 8 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_8_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_8_SETTING
#define CONF_SLCD_CM_14SEGS_8_SETTING 8
#endif

// <o> Segments 9 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_9_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_9_SETTING
#define CONF_SLCD_CM_14SEGS_9_SETTING 9
#endif

// <o> Segments 10 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_10_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_10_SETTING
#define CONF_SLCD_CM_14SEGS_10_SETTING 10
#endif

// <o> Segments 11 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_11_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_11_SETTING
#define CONF_SLCD_CM_14SEGS_11_SETTING 11
#endif

// <o> Segments 12 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_12_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_12_SETTING
#define CONF_SLCD_CM_14SEGS_12_SETTING 12
#endif

// <o> Segments 13 Setting
//   <i> Segment index for the character mapping area
//   <i> Index 0 is the Character mapping beinging COMn/SEGn, Index 1 is COMn/SEGn + 1
// <id> slcd_arch_cm_14segs_13_mapping_setting
// <0=>0
// <1=>1
// <2=>2
// <3=>3
// <4=>4
// <5=>5
// <6=>6
// <7=>7
// <8=>8
// <9=>9
// <10=>10
// <11=>11
// <12=>12
// <13=>13
// <14=>14
// <15=>15
// <16=>16
// <17=>17
// <18=>18
// <19=>19
// <20=>20
// <21=>21
// <22=>22
// <23=>23
#ifndef CONF_SLCD_CM_14SEGS_13_SETTING
#define CONF_SLCD_CM_14SEGS_13_SETTING 13
#endif

// </e>

// <e> Character 0 Mapping Setting
// <id> slcd_arch_char0_setting
#ifndef CONF_SLCD_CHAR0_ENABLE_SETTING
#define CONF_SLCD_CHAR0_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character0 COM begin index
// <id> slcd_arch_char0_com_idx
#ifndef CONF_SLCD_CHAR0_COM_IDX
#define CONF_SLCD_CHAR0_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character0 Segment begin index
// <id> slcd_arch_char0_seg_idx
#ifndef CONF_SLCD_CHAR0_SEG_IDX
#define CONF_SLCD_CHAR0_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character0 mapping
// <id> slcd_arch_char0_seg_num
#ifndef CONF_SLCD_CHAR0_SEG_NUM
#define CONF_SLCD_CHAR0_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character0
//   <id> slcd_arch_char0_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR0_MAPPING_TABLE
#define CONF_SLCD_CHAR0_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 1 Mapping Setting
// <id> slcd_arch_char1_setting
#ifndef CONF_SLCD_CHAR1_ENABLE_SETTING
#define CONF_SLCD_CHAR1_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character1 COM begin index
// <id> slcd_arch_char1_com_idx
#ifndef CONF_SLCD_CHAR1_COM_IDX
#define CONF_SLCD_CHAR1_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character1 Segment begin index
// <id> slcd_arch_char1_seg_idx
#ifndef CONF_SLCD_CHAR1_SEG_IDX
#define CONF_SLCD_CHAR1_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character1 mapping
// <id> slcd_arch_char1_seg_num
#ifndef CONF_SLCD_CHAR1_SEG_NUM
#define CONF_SLCD_CHAR1_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character1
//   <id> slcd_arch_char1_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR1_MAPPING_TABLE
#define CONF_SLCD_CHAR1_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 2 Mapping Setting
// <id> slcd_arch_char2_setting
#ifndef CONF_SLCD_CHAR2_ENABLE_SETTING
#define CONF_SLCD_CHAR2_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character2 COM begin index
// <id> slcd_arch_char2_com_idx
#ifndef CONF_SLCD_CHAR2_COM_IDX
#define CONF_SLCD_CHAR2_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character2 Segment begin index
// <id> slcd_arch_char2_seg_idx
#ifndef CONF_SLCD_CHAR2_SEG_IDX
#define CONF_SLCD_CHAR2_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character2 mapping
// <id> slcd_arch_char2_seg_num
#ifndef CONF_SLCD_CHAR2_SEG_NUM
#define CONF_SLCD_CHAR2_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character2
//   <id> slcd_arch_char2_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR2_MAPPING_TABLE
#define CONF_SLCD_CHAR2_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 3 Mapping Setting
// <id> slcd_arch_char3_setting
#ifndef CONF_SLCD_CHAR3_ENABLE_SETTING
#define CONF_SLCD_CHAR3_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character3 COM begin index
// <id> slcd_arch_char3_com_idx
#ifndef CONF_SLCD_CHAR3_COM_IDX
#define CONF_SLCD_CHAR3_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character3 Segment begin index
// <id> slcd_arch_char3_seg_idx
#ifndef CONF_SLCD_CHAR3_SEG_IDX
#define CONF_SLCD_CHAR3_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character3 mapping
// <id> slcd_arch_char3_seg_num
#ifndef CONF_SLCD_CHAR3_SEG_NUM
#define CONF_SLCD_CHAR3_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character3
//   <id> slcd_arch_char3_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR3_MAPPING_TABLE
#define CONF_SLCD_CHAR3_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 4 Mapping Setting
// <id> slcd_arch_char4_setting
#ifndef CONF_SLCD_CHAR4_ENABLE_SETTING
#define CONF_SLCD_CHAR4_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character4 COM begin index
// <id> slcd_arch_char4_com_idx
#ifndef CONF_SLCD_CHAR4_COM_IDX
#define CONF_SLCD_CHAR4_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character4 Segment begin index
// <id> slcd_arch_char4_seg_idx
#ifndef CONF_SLCD_CHAR4_SEG_IDX
#define CONF_SLCD_CHAR4_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character4 mapping
// <id> slcd_arch_char4_seg_num
#ifndef CONF_SLCD_CHAR4_SEG_NUM
#define CONF_SLCD_CHAR4_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character4
//   <id> slcd_arch_char4_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR4_MAPPING_TABLE
#define CONF_SLCD_CHAR4_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 5 Mapping Setting
// <id> slcd_arch_char5_setting
#ifndef CONF_SLCD_CHAR5_ENABLE_SETTING
#define CONF_SLCD_CHAR5_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character5 COM begin index
// <id> slcd_arch_char5_com_idx
#ifndef CONF_SLCD_CHAR5_COM_IDX
#define CONF_SLCD_CHAR5_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character5 Segment begin index
// <id> slcd_arch_char5_seg_idx
#ifndef CONF_SLCD_CHAR5_SEG_IDX
#define CONF_SLCD_CHAR5_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character5 mapping
// <id> slcd_arch_char5_seg_num
#ifndef CONF_SLCD_CHAR5_SEG_NUM
#define CONF_SLCD_CHAR5_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character5
//   <id> slcd_arch_char5_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR5_MAPPING_TABLE
#define CONF_SLCD_CHAR5_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 6 Mapping Setting
// <id> slcd_arch_char6_setting
#ifndef CONF_SLCD_CHAR6_ENABLE_SETTING
#define CONF_SLCD_CHAR6_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character6 COM begin index
// <id> slcd_arch_char6_com_idx
#ifndef CONF_SLCD_CHAR6_COM_IDX
#define CONF_SLCD_CHAR6_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character6 Segment begin index
// <id> slcd_arch_char6_seg_idx
#ifndef CONF_SLCD_CHAR6_SEG_IDX
#define CONF_SLCD_CHAR6_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character6 mapping
// <id> slcd_arch_char6_seg_num
#ifndef CONF_SLCD_CHAR6_SEG_NUM
#define CONF_SLCD_CHAR6_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character6
//   <id> slcd_arch_char6_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR6_MAPPING_TABLE
#define CONF_SLCD_CHAR6_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 7 Mapping Setting
// <id> slcd_arch_char7_setting
#ifndef CONF_SLCD_CHAR7_ENABLE_SETTING
#define CONF_SLCD_CHAR7_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character7 COM begin index
// <id> slcd_arch_char7_com_idx
#ifndef CONF_SLCD_CHAR7_COM_IDX
#define CONF_SLCD_CHAR7_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character7 Segment begin index
// <id> slcd_arch_char7_seg_idx
#ifndef CONF_SLCD_CHAR7_SEG_IDX
#define CONF_SLCD_CHAR7_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character7 mapping
// <id> slcd_arch_char7_seg_num
#ifndef CONF_SLCD_CHAR7_SEG_NUM
#define CONF_SLCD_CHAR7_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character7
//   <id> slcd_arch_char7_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR7_MAPPING_TABLE
#define CONF_SLCD_CHAR7_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 8 Mapping Setting
// <id> slcd_arch_char8_setting
#ifndef CONF_SLCD_CHAR8_ENABLE_SETTING
#define CONF_SLCD_CHAR8_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character8 COM begin index
// <id> slcd_arch_char8_com_idx
#ifndef CONF_SLCD_CHAR8_COM_IDX
#define CONF_SLCD_CHAR8_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character8 Segment begin index
// <id> slcd_arch_char8_seg_idx
#ifndef CONF_SLCD_CHAR8_SEG_IDX
#define CONF_SLCD_CHAR8_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character8 mapping
// <id> slcd_arch_char8_seg_num
#ifndef CONF_SLCD_CHAR8_SEG_NUM
#define CONF_SLCD_CHAR8_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character8
//   <id> slcd_arch_char8_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR8_MAPPING_TABLE
#define CONF_SLCD_CHAR8_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 9 Mapping Setting
// <id> slcd_arch_char9_setting
#ifndef CONF_SLCD_CHAR9_ENABLE_SETTING
#define CONF_SLCD_CHAR9_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character9 COM begin index
// <id> slcd_arch_char9_com_idx
#ifndef CONF_SLCD_CHAR9_COM_IDX
#define CONF_SLCD_CHAR9_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character9 Segment begin index
// <id> slcd_arch_char9_seg_idx
#ifndef CONF_SLCD_CHAR9_SEG_IDX
#define CONF_SLCD_CHAR9_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character9 mapping
// <id> slcd_arch_char9_seg_num
#ifndef CONF_SLCD_CHAR9_SEG_NUM
#define CONF_SLCD_CHAR9_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character9
//   <id> slcd_arch_char9_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR9_MAPPING_TABLE
#define CONF_SLCD_CHAR9_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 10 Mapping Setting
// <id> slcd_arch_char10_setting
#ifndef CONF_SLCD_CHAR10_ENABLE_SETTING
#define CONF_SLCD_CHAR10_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character10 COM begin index
// <id> slcd_arch_char10_com_idx
#ifndef CONF_SLCD_CHAR10_COM_IDX
#define CONF_SLCD_CHAR10_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character10 Segment begin index
// <id> slcd_arch_char10_seg_idx
#ifndef CONF_SLCD_CHAR10_SEG_IDX
#define CONF_SLCD_CHAR10_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character10 mapping
// <id> slcd_arch_char10_seg_num
#ifndef CONF_SLCD_CHAR10_SEG_NUM
#define CONF_SLCD_CHAR10_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character10
//   <id> slcd_arch_char10_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR10_MAPPING_TABLE
#define CONF_SLCD_CHAR10_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 11 Mapping Setting
// <id> slcd_arch_char11_setting
#ifndef CONF_SLCD_CHAR11_ENABLE_SETTING
#define CONF_SLCD_CHAR11_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character11 COM begin index
// <id> slcd_arch_char11_com_idx
#ifndef CONF_SLCD_CHAR11_COM_IDX
#define CONF_SLCD_CHAR11_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character11 Segment begin index
// <id> slcd_arch_char11_seg_idx
#ifndef CONF_SLCD_CHAR11_SEG_IDX
#define CONF_SLCD_CHAR11_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character11 mapping
// <id> slcd_arch_char11_seg_num
#ifndef CONF_SLCD_CHAR11_SEG_NUM
#define CONF_SLCD_CHAR11_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character11
//   <id> slcd_arch_char11_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR11_MAPPING_TABLE
#define CONF_SLCD_CHAR11_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 12 Mapping Setting
// <id> slcd_arch_char12_setting
#ifndef CONF_SLCD_CHAR12_ENABLE_SETTING
#define CONF_SLCD_CHAR12_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character12 COM begin index
// <id> slcd_arch_char12_com_idx
#ifndef CONF_SLCD_CHAR12_COM_IDX
#define CONF_SLCD_CHAR12_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character12 Segment begin index
// <id> slcd_arch_char12_seg_idx
#ifndef CONF_SLCD_CHAR12_SEG_IDX
#define CONF_SLCD_CHAR12_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character12 mapping
// <id> slcd_arch_char12_seg_num
#ifndef CONF_SLCD_CHAR12_SEG_NUM
#define CONF_SLCD_CHAR12_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character12
//   <id> slcd_arch_char12_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR12_MAPPING_TABLE
#define CONF_SLCD_CHAR12_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 13 Mapping Setting
// <id> slcd_arch_char13_setting
#ifndef CONF_SLCD_CHAR13_ENABLE_SETTING
#define CONF_SLCD_CHAR13_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character13 COM begin index
// <id> slcd_arch_char13_com_idx
#ifndef CONF_SLCD_CHAR13_COM_IDX
#define CONF_SLCD_CHAR13_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character13 Segment begin index
// <id> slcd_arch_char13_seg_idx
#ifndef CONF_SLCD_CHAR13_SEG_IDX
#define CONF_SLCD_CHAR13_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character13 mapping
// <id> slcd_arch_char13_seg_num
#ifndef CONF_SLCD_CHAR13_SEG_NUM
#define CONF_SLCD_CHAR13_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character13
//   <id> slcd_arch_char13_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR13_MAPPING_TABLE
#define CONF_SLCD_CHAR13_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 14 Mapping Setting
// <id> slcd_arch_char14_setting
#ifndef CONF_SLCD_CHAR14_ENABLE_SETTING
#define CONF_SLCD_CHAR14_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character14 COM begin index
// <id> slcd_arch_char14_com_idx
#ifndef CONF_SLCD_CHAR14_COM_IDX
#define CONF_SLCD_CHAR14_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character14 Segment begin index
// <id> slcd_arch_char14_seg_idx
#ifndef CONF_SLCD_CHAR14_SEG_IDX
#define CONF_SLCD_CHAR14_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character14 mapping
// <id> slcd_arch_char14_seg_num
#ifndef CONF_SLCD_CHAR14_SEG_NUM
#define CONF_SLCD_CHAR14_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character14
//   <id> slcd_arch_char14_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR14_MAPPING_TABLE
#define CONF_SLCD_CHAR14_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 15 Mapping Setting
// <id> slcd_arch_char15_setting
#ifndef CONF_SLCD_CHAR15_ENABLE_SETTING
#define CONF_SLCD_CHAR15_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character15 COM begin index
// <id> slcd_arch_char15_com_idx
#ifndef CONF_SLCD_CHAR15_COM_IDX
#define CONF_SLCD_CHAR15_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character15 Segment begin index
// <id> slcd_arch_char15_seg_idx
#ifndef CONF_SLCD_CHAR15_SEG_IDX
#define CONF_SLCD_CHAR15_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character15 mapping
// <id> slcd_arch_char15_seg_num
#ifndef CONF_SLCD_CHAR15_SEG_NUM
#define CONF_SLCD_CHAR15_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character15
//   <id> slcd_arch_char15_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR15_MAPPING_TABLE
#define CONF_SLCD_CHAR15_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 16 Mapping Setting
// <id> slcd_arch_char16_setting
#ifndef CONF_SLCD_CHAR16_ENABLE_SETTING
#define CONF_SLCD_CHAR16_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character16 COM begin index
// <id> slcd_arch_char16_com_idx
#ifndef CONF_SLCD_CHAR16_COM_IDX
#define CONF_SLCD_CHAR16_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character16 Segment begin index
// <id> slcd_arch_char16_seg_idx
#ifndef CONF_SLCD_CHAR16_SEG_IDX
#define CONF_SLCD_CHAR16_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character16 mapping
// <id> slcd_arch_char16_seg_num
#ifndef CONF_SLCD_CHAR16_SEG_NUM
#define CONF_SLCD_CHAR16_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character16
//   <id> slcd_arch_char16_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR16_MAPPING_TABLE
#define CONF_SLCD_CHAR16_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 17 Mapping Setting
// <id> slcd_arch_char17_setting
#ifndef CONF_SLCD_CHAR17_ENABLE_SETTING
#define CONF_SLCD_CHAR17_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character17 COM begin index
// <id> slcd_arch_char17_com_idx
#ifndef CONF_SLCD_CHAR17_COM_IDX
#define CONF_SLCD_CHAR17_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character17 Segment begin index
// <id> slcd_arch_char17_seg_idx
#ifndef CONF_SLCD_CHAR17_SEG_IDX
#define CONF_SLCD_CHAR17_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character17 mapping
// <id> slcd_arch_char17_seg_num
#ifndef CONF_SLCD_CHAR17_SEG_NUM
#define CONF_SLCD_CHAR17_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character17
//   <id> slcd_arch_char17_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR17_MAPPING_TABLE
#define CONF_SLCD_CHAR17_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 18 Mapping Setting
// <id> slcd_arch_char18_setting
#ifndef CONF_SLCD_CHAR18_ENABLE_SETTING
#define CONF_SLCD_CHAR18_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character18 COM begin index
// <id> slcd_arch_char18_com_idx
#ifndef CONF_SLCD_CHAR18_COM_IDX
#define CONF_SLCD_CHAR18_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character18 Segment begin index
// <id> slcd_arch_char18_seg_idx
#ifndef CONF_SLCD_CHAR18_SEG_IDX
#define CONF_SLCD_CHAR18_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character18 mapping
// <id> slcd_arch_char18_seg_num
#ifndef CONF_SLCD_CHAR18_SEG_NUM
#define CONF_SLCD_CHAR18_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character18
//   <id> slcd_arch_char18_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR18_MAPPING_TABLE
#define CONF_SLCD_CHAR18_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 19 Mapping Setting
// <id> slcd_arch_char19_setting
#ifndef CONF_SLCD_CHAR19_ENABLE_SETTING
#define CONF_SLCD_CHAR19_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character19 COM begin index
// <id> slcd_arch_char19_com_idx
#ifndef CONF_SLCD_CHAR19_COM_IDX
#define CONF_SLCD_CHAR19_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character19 Segment begin index
// <id> slcd_arch_char19_seg_idx
#ifndef CONF_SLCD_CHAR19_SEG_IDX
#define CONF_SLCD_CHAR19_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character19 mapping
// <id> slcd_arch_char19_seg_num
#ifndef CONF_SLCD_CHAR19_SEG_NUM
#define CONF_SLCD_CHAR19_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character19
//   <id> slcd_arch_char19_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR19_MAPPING_TABLE
#define CONF_SLCD_CHAR19_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 20 Mapping Setting
// <id> slcd_arch_char20_setting
#ifndef CONF_SLCD_CHAR20_ENABLE_SETTING
#define CONF_SLCD_CHAR20_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character20 COM begin index
// <id> slcd_arch_char20_com_idx
#ifndef CONF_SLCD_CHAR20_COM_IDX
#define CONF_SLCD_CHAR20_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character20 Segment begin index
// <id> slcd_arch_char20_seg_idx
#ifndef CONF_SLCD_CHAR20_SEG_IDX
#define CONF_SLCD_CHAR20_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character20 mapping
// <id> slcd_arch_char20_seg_num
#ifndef CONF_SLCD_CHAR20_SEG_NUM
#define CONF_SLCD_CHAR20_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character20
//   <id> slcd_arch_char20_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR20_MAPPING_TABLE
#define CONF_SLCD_CHAR20_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 21 Mapping Setting
// <id> slcd_arch_char21_setting
#ifndef CONF_SLCD_CHAR21_ENABLE_SETTING
#define CONF_SLCD_CHAR21_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character21 COM begin index
// <id> slcd_arch_char21_com_idx
#ifndef CONF_SLCD_CHAR21_COM_IDX
#define CONF_SLCD_CHAR21_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character21 Segment begin index
// <id> slcd_arch_char21_seg_idx
#ifndef CONF_SLCD_CHAR21_SEG_IDX
#define CONF_SLCD_CHAR21_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character21 mapping
// <id> slcd_arch_char21_seg_num
#ifndef CONF_SLCD_CHAR21_SEG_NUM
#define CONF_SLCD_CHAR21_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character21
//   <id> slcd_arch_char21_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR21_MAPPING_TABLE
#define CONF_SLCD_CHAR21_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 22 Mapping Setting
// <id> slcd_arch_char22_setting
#ifndef CONF_SLCD_CHAR22_ENABLE_SETTING
#define CONF_SLCD_CHAR22_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character22 COM begin index
// <id> slcd_arch_char22_com_idx
#ifndef CONF_SLCD_CHAR22_COM_IDX
#define CONF_SLCD_CHAR22_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character22 Segment begin index
// <id> slcd_arch_char22_seg_idx
#ifndef CONF_SLCD_CHAR22_SEG_IDX
#define CONF_SLCD_CHAR22_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character22 mapping
// <id> slcd_arch_char22_seg_num
#ifndef CONF_SLCD_CHAR22_SEG_NUM
#define CONF_SLCD_CHAR22_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character22
//   <id> slcd_arch_char22_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR22_MAPPING_TABLE
#define CONF_SLCD_CHAR22_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 23 Mapping Setting
// <id> slcd_arch_char23_setting
#ifndef CONF_SLCD_CHAR23_ENABLE_SETTING
#define CONF_SLCD_CHAR23_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character23 COM begin index
// <id> slcd_arch_char23_com_idx
#ifndef CONF_SLCD_CHAR23_COM_IDX
#define CONF_SLCD_CHAR23_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character23 Segment begin index
// <id> slcd_arch_char23_seg_idx
#ifndef CONF_SLCD_CHAR23_SEG_IDX
#define CONF_SLCD_CHAR23_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character23 mapping
// <id> slcd_arch_char23_seg_num
#ifndef CONF_SLCD_CHAR23_SEG_NUM
#define CONF_SLCD_CHAR23_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character23
//   <id> slcd_arch_char23_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR23_MAPPING_TABLE
#define CONF_SLCD_CHAR23_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 24 Mapping Setting
// <id> slcd_arch_char24_setting
#ifndef CONF_SLCD_CHAR24_ENABLE_SETTING
#define CONF_SLCD_CHAR24_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character24 COM begin index
// <id> slcd_arch_char24_com_idx
#ifndef CONF_SLCD_CHAR24_COM_IDX
#define CONF_SLCD_CHAR24_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character24 Segment begin index
// <id> slcd_arch_char24_seg_idx
#ifndef CONF_SLCD_CHAR24_SEG_IDX
#define CONF_SLCD_CHAR24_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character24 mapping
// <id> slcd_arch_char24_seg_num
#ifndef CONF_SLCD_CHAR24_SEG_NUM
#define CONF_SLCD_CHAR24_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character24
//   <id> slcd_arch_char24_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR24_MAPPING_TABLE
#define CONF_SLCD_CHAR24_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 25 Mapping Setting
// <id> slcd_arch_char25_setting
#ifndef CONF_SLCD_CHAR25_ENABLE_SETTING
#define CONF_SLCD_CHAR25_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character25 COM begin index
// <id> slcd_arch_char25_com_idx
#ifndef CONF_SLCD_CHAR25_COM_IDX
#define CONF_SLCD_CHAR25_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character25 Segment begin index
// <id> slcd_arch_char25_seg_idx
#ifndef CONF_SLCD_CHAR25_SEG_IDX
#define CONF_SLCD_CHAR25_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character25 mapping
// <id> slcd_arch_char25_seg_num
#ifndef CONF_SLCD_CHAR25_SEG_NUM
#define CONF_SLCD_CHAR25_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character25
//   <id> slcd_arch_char25_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR25_MAPPING_TABLE
#define CONF_SLCD_CHAR25_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 26 Mapping Setting
// <id> slcd_arch_char26_setting
#ifndef CONF_SLCD_CHAR26_ENABLE_SETTING
#define CONF_SLCD_CHAR26_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character26 COM begin index
// <id> slcd_arch_char26_com_idx
#ifndef CONF_SLCD_CHAR26_COM_IDX
#define CONF_SLCD_CHAR26_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character26 Segment begin index
// <id> slcd_arch_char26_seg_idx
#ifndef CONF_SLCD_CHAR26_SEG_IDX
#define CONF_SLCD_CHAR26_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character26 mapping
// <id> slcd_arch_char26_seg_num
#ifndef CONF_SLCD_CHAR26_SEG_NUM
#define CONF_SLCD_CHAR26_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character26
//   <id> slcd_arch_char26_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR26_MAPPING_TABLE
#define CONF_SLCD_CHAR26_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 27 Mapping Setting
// <id> slcd_arch_char27_setting
#ifndef CONF_SLCD_CHAR27_ENABLE_SETTING
#define CONF_SLCD_CHAR27_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character27 COM begin index
// <id> slcd_arch_char27_com_idx
#ifndef CONF_SLCD_CHAR27_COM_IDX
#define CONF_SLCD_CHAR27_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character27 Segment begin index
// <id> slcd_arch_char27_seg_idx
#ifndef CONF_SLCD_CHAR27_SEG_IDX
#define CONF_SLCD_CHAR27_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character27 mapping
// <id> slcd_arch_char27_seg_num
#ifndef CONF_SLCD_CHAR27_SEG_NUM
#define CONF_SLCD_CHAR27_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character27
//   <id> slcd_arch_char27_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR27_MAPPING_TABLE
#define CONF_SLCD_CHAR27_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 28 Mapping Setting
// <id> slcd_arch_char28_setting
#ifndef CONF_SLCD_CHAR28_ENABLE_SETTING
#define CONF_SLCD_CHAR28_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character28 COM begin index
// <id> slcd_arch_char28_com_idx
#ifndef CONF_SLCD_CHAR28_COM_IDX
#define CONF_SLCD_CHAR28_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character28 Segment begin index
// <id> slcd_arch_char28_seg_idx
#ifndef CONF_SLCD_CHAR28_SEG_IDX
#define CONF_SLCD_CHAR28_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character28 mapping
// <id> slcd_arch_char28_seg_num
#ifndef CONF_SLCD_CHAR28_SEG_NUM
#define CONF_SLCD_CHAR28_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character28
//   <id> slcd_arch_char28_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR28_MAPPING_TABLE
#define CONF_SLCD_CHAR28_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 29 Mapping Setting
// <id> slcd_arch_char29_setting
#ifndef CONF_SLCD_CHAR29_ENABLE_SETTING
#define CONF_SLCD_CHAR29_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character29 COM begin index
// <id> slcd_arch_char29_com_idx
#ifndef CONF_SLCD_CHAR29_COM_IDX
#define CONF_SLCD_CHAR29_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character29 Segment begin index
// <id> slcd_arch_char29_seg_idx
#ifndef CONF_SLCD_CHAR29_SEG_IDX
#define CONF_SLCD_CHAR29_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character29 mapping
// <id> slcd_arch_char29_seg_num
#ifndef CONF_SLCD_CHAR29_SEG_NUM
#define CONF_SLCD_CHAR29_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character29
//   <id> slcd_arch_char29_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR29_MAPPING_TABLE
#define CONF_SLCD_CHAR29_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 30 Mapping Setting
// <id> slcd_arch_char30_setting
#ifndef CONF_SLCD_CHAR30_ENABLE_SETTING
#define CONF_SLCD_CHAR30_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character30 COM begin index
// <id> slcd_arch_char30_com_idx
#ifndef CONF_SLCD_CHAR30_COM_IDX
#define CONF_SLCD_CHAR30_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character30 Segment begin index
// <id> slcd_arch_char30_seg_idx
#ifndef CONF_SLCD_CHAR30_SEG_IDX
#define CONF_SLCD_CHAR30_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character30 mapping
// <id> slcd_arch_char30_seg_num
#ifndef CONF_SLCD_CHAR30_SEG_NUM
#define CONF_SLCD_CHAR30_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character30
//   <id> slcd_arch_char30_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR30_MAPPING_TABLE
#define CONF_SLCD_CHAR30_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 31 Mapping Setting
// <id> slcd_arch_char31_setting
#ifndef CONF_SLCD_CHAR31_ENABLE_SETTING
#define CONF_SLCD_CHAR31_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character31 COM begin index
// <id> slcd_arch_char31_com_idx
#ifndef CONF_SLCD_CHAR31_COM_IDX
#define CONF_SLCD_CHAR31_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character31 Segment begin index
// <id> slcd_arch_char31_seg_idx
#ifndef CONF_SLCD_CHAR31_SEG_IDX
#define CONF_SLCD_CHAR31_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character31 mapping
// <id> slcd_arch_char31_seg_num
#ifndef CONF_SLCD_CHAR31_SEG_NUM
#define CONF_SLCD_CHAR31_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character31
//   <id> slcd_arch_char31_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR31_MAPPING_TABLE
#define CONF_SLCD_CHAR31_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 32 Mapping Setting
// <id> slcd_arch_char32_setting
#ifndef CONF_SLCD_CHAR32_ENABLE_SETTING
#define CONF_SLCD_CHAR32_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character32 COM begin index
// <id> slcd_arch_char32_com_idx
#ifndef CONF_SLCD_CHAR32_COM_IDX
#define CONF_SLCD_CHAR32_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character32 Segment begin index
// <id> slcd_arch_char32_seg_idx
#ifndef CONF_SLCD_CHAR32_SEG_IDX
#define CONF_SLCD_CHAR32_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character32 mapping
// <id> slcd_arch_char32_seg_num
#ifndef CONF_SLCD_CHAR32_SEG_NUM
#define CONF_SLCD_CHAR32_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character32
//   <id> slcd_arch_char32_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR32_MAPPING_TABLE
#define CONF_SLCD_CHAR32_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 33 Mapping Setting
// <id> slcd_arch_char33_setting
#ifndef CONF_SLCD_CHAR33_ENABLE_SETTING
#define CONF_SLCD_CHAR33_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character33 COM begin index
// <id> slcd_arch_char33_com_idx
#ifndef CONF_SLCD_CHAR33_COM_IDX
#define CONF_SLCD_CHAR33_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character33 Segment begin index
// <id> slcd_arch_char33_seg_idx
#ifndef CONF_SLCD_CHAR33_SEG_IDX
#define CONF_SLCD_CHAR33_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character33 mapping
// <id> slcd_arch_char33_seg_num
#ifndef CONF_SLCD_CHAR33_SEG_NUM
#define CONF_SLCD_CHAR33_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character33
//   <id> slcd_arch_char33_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR33_MAPPING_TABLE
#define CONF_SLCD_CHAR33_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 34 Mapping Setting
// <id> slcd_arch_char34_setting
#ifndef CONF_SLCD_CHAR34_ENABLE_SETTING
#define CONF_SLCD_CHAR34_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character34 COM begin index
// <id> slcd_arch_char34_com_idx
#ifndef CONF_SLCD_CHAR34_COM_IDX
#define CONF_SLCD_CHAR34_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character34 Segment begin index
// <id> slcd_arch_char34_seg_idx
#ifndef CONF_SLCD_CHAR34_SEG_IDX
#define CONF_SLCD_CHAR34_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character34 mapping
// <id> slcd_arch_char34_seg_num
#ifndef CONF_SLCD_CHAR34_SEG_NUM
#define CONF_SLCD_CHAR34_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character34
//   <id> slcd_arch_char34_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR34_MAPPING_TABLE
#define CONF_SLCD_CHAR34_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 35 Mapping Setting
// <id> slcd_arch_char35_setting
#ifndef CONF_SLCD_CHAR35_ENABLE_SETTING
#define CONF_SLCD_CHAR35_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character35 COM begin index
// <id> slcd_arch_char35_com_idx
#ifndef CONF_SLCD_CHAR35_COM_IDX
#define CONF_SLCD_CHAR35_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character35 Segment begin index
// <id> slcd_arch_char35_seg_idx
#ifndef CONF_SLCD_CHAR35_SEG_IDX
#define CONF_SLCD_CHAR35_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character35 mapping
// <id> slcd_arch_char35_seg_num
#ifndef CONF_SLCD_CHAR35_SEG_NUM
#define CONF_SLCD_CHAR35_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character35
//   <id> slcd_arch_char35_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR35_MAPPING_TABLE
#define CONF_SLCD_CHAR35_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 36 Mapping Setting
// <id> slcd_arch_char36_setting
#ifndef CONF_SLCD_CHAR36_ENABLE_SETTING
#define CONF_SLCD_CHAR36_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character36 COM begin index
// <id> slcd_arch_char36_com_idx
#ifndef CONF_SLCD_CHAR36_COM_IDX
#define CONF_SLCD_CHAR36_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character36 Segment begin index
// <id> slcd_arch_char36_seg_idx
#ifndef CONF_SLCD_CHAR36_SEG_IDX
#define CONF_SLCD_CHAR36_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character36 mapping
// <id> slcd_arch_char36_seg_num
#ifndef CONF_SLCD_CHAR36_SEG_NUM
#define CONF_SLCD_CHAR36_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character36
//   <id> slcd_arch_char36_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR36_MAPPING_TABLE
#define CONF_SLCD_CHAR36_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 37 Mapping Setting
// <id> slcd_arch_char37_setting
#ifndef CONF_SLCD_CHAR37_ENABLE_SETTING
#define CONF_SLCD_CHAR37_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character37 COM begin index
// <id> slcd_arch_char37_com_idx
#ifndef CONF_SLCD_CHAR37_COM_IDX
#define CONF_SLCD_CHAR37_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character37 Segment begin index
// <id> slcd_arch_char37_seg_idx
#ifndef CONF_SLCD_CHAR37_SEG_IDX
#define CONF_SLCD_CHAR37_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character37 mapping
// <id> slcd_arch_char37_seg_num
#ifndef CONF_SLCD_CHAR37_SEG_NUM
#define CONF_SLCD_CHAR37_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character37
//   <id> slcd_arch_char37_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR37_MAPPING_TABLE
#define CONF_SLCD_CHAR37_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 38 Mapping Setting
// <id> slcd_arch_char38_setting
#ifndef CONF_SLCD_CHAR38_ENABLE_SETTING
#define CONF_SLCD_CHAR38_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character38 COM begin index
// <id> slcd_arch_char38_com_idx
#ifndef CONF_SLCD_CHAR38_COM_IDX
#define CONF_SLCD_CHAR38_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character38 Segment begin index
// <id> slcd_arch_char38_seg_idx
#ifndef CONF_SLCD_CHAR38_SEG_IDX
#define CONF_SLCD_CHAR38_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character38 mapping
// <id> slcd_arch_char38_seg_num
#ifndef CONF_SLCD_CHAR38_SEG_NUM
#define CONF_SLCD_CHAR38_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character38
//   <id> slcd_arch_char38_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR38_MAPPING_TABLE
#define CONF_SLCD_CHAR38_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 39 Mapping Setting
// <id> slcd_arch_char39_setting
#ifndef CONF_SLCD_CHAR39_ENABLE_SETTING
#define CONF_SLCD_CHAR39_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character39 COM begin index
// <id> slcd_arch_char39_com_idx
#ifndef CONF_SLCD_CHAR39_COM_IDX
#define CONF_SLCD_CHAR39_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character39 Segment begin index
// <id> slcd_arch_char39_seg_idx
#ifndef CONF_SLCD_CHAR39_SEG_IDX
#define CONF_SLCD_CHAR39_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character39 mapping
// <id> slcd_arch_char39_seg_num
#ifndef CONF_SLCD_CHAR39_SEG_NUM
#define CONF_SLCD_CHAR39_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character39
//   <id> slcd_arch_char39_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR39_MAPPING_TABLE
#define CONF_SLCD_CHAR39_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 40 Mapping Setting
// <id> slcd_arch_char40_setting
#ifndef CONF_SLCD_CHAR40_ENABLE_SETTING
#define CONF_SLCD_CHAR40_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character40 COM begin index
// <id> slcd_arch_char40_com_idx
#ifndef CONF_SLCD_CHAR40_COM_IDX
#define CONF_SLCD_CHAR40_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character40 Segment begin index
// <id> slcd_arch_char40_seg_idx
#ifndef CONF_SLCD_CHAR40_SEG_IDX
#define CONF_SLCD_CHAR40_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character40 mapping
// <id> slcd_arch_char40_seg_num
#ifndef CONF_SLCD_CHAR40_SEG_NUM
#define CONF_SLCD_CHAR40_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character40
//   <id> slcd_arch_char40_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR40_MAPPING_TABLE
#define CONF_SLCD_CHAR40_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 41 Mapping Setting
// <id> slcd_arch_char41_setting
#ifndef CONF_SLCD_CHAR41_ENABLE_SETTING
#define CONF_SLCD_CHAR41_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character41 COM begin index
// <id> slcd_arch_char41_com_idx
#ifndef CONF_SLCD_CHAR41_COM_IDX
#define CONF_SLCD_CHAR41_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character41 Segment begin index
// <id> slcd_arch_char41_seg_idx
#ifndef CONF_SLCD_CHAR41_SEG_IDX
#define CONF_SLCD_CHAR41_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character41 mapping
// <id> slcd_arch_char41_seg_num
#ifndef CONF_SLCD_CHAR41_SEG_NUM
#define CONF_SLCD_CHAR41_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character41
//   <id> slcd_arch_char41_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR41_MAPPING_TABLE
#define CONF_SLCD_CHAR41_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 42 Mapping Setting
// <id> slcd_arch_char42_setting
#ifndef CONF_SLCD_CHAR42_ENABLE_SETTING
#define CONF_SLCD_CHAR42_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character42 COM begin index
// <id> slcd_arch_char42_com_idx
#ifndef CONF_SLCD_CHAR42_COM_IDX
#define CONF_SLCD_CHAR42_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character42 Segment begin index
// <id> slcd_arch_char42_seg_idx
#ifndef CONF_SLCD_CHAR42_SEG_IDX
#define CONF_SLCD_CHAR42_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character42 mapping
// <id> slcd_arch_char42_seg_num
#ifndef CONF_SLCD_CHAR42_SEG_NUM
#define CONF_SLCD_CHAR42_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character42
//   <id> slcd_arch_char42_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR42_MAPPING_TABLE
#define CONF_SLCD_CHAR42_MAPPING_SIZE 7
#endif

// </e>

// <e> Character 43 Mapping Setting
// <id> slcd_arch_char43_setting
#ifndef CONF_SLCD_CHAR43_ENABLE_SETTING
#define CONF_SLCD_CHAR43_ENABLE_SETTING 0
#endif

// <o> COM index <0-7>
// <i> Character43 COM begin index
// <id> slcd_arch_char43_com_idx
#ifndef CONF_SLCD_CHAR43_COM_IDX
#define CONF_SLCD_CHAR43_COM_IDX 0
#endif

// <o> Segment index <0-44>
// <i> Character43 Segment begin index
// <id> slcd_arch_char43_seg_idx
#ifndef CONF_SLCD_CHAR43_SEG_IDX
#define CONF_SLCD_CHAR43_SEG_IDX 1
#endif

// <o> Number of Segment <1-24>
// <i> Number of Segment used for Character43 mapping
// <id> slcd_arch_char43_seg_num
#ifndef CONF_SLCD_CHAR43_SEG_NUM
#define CONF_SLCD_CHAR43_SEG_NUM 1
#endif

// <o> Mapping Table
//   <i> Select the char mapping table for Character43
//   <id> slcd_arch_char43_mapping_table
//   <7=>7 Segments Mapping Table
//   <14=>14 Segments Mapping Table
#ifndef CONF_SLCD_CHAR43_MAPPING_TABLE
#define CONF_SLCD_CHAR43_MAPPING_SIZE 7
#endif

// </e>

/**
 * character lookup table
 */
#define SLCD_CHAR_SETTING_TABLE                                                                                        \
	{                                                                                                                  \
		{CONF_SLCD_CHAR0_COM_IDX, CONF_SLCD_CHAR0_SEG_IDX, CONF_SLCD_CHAR0_SEG_NUM - 1, CONF_SLCD_CHAR0_MAPPING_SIZE}, \
		    {CONF_SLCD_CHAR1_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR1_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR1_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR1_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR2_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR2_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR2_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR2_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR3_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR3_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR3_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR3_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR4_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR4_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR4_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR4_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR5_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR5_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR5_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR5_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR6_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR6_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR6_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR6_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR7_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR7_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR7_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR7_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR8_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR8_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR8_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR8_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR9_COM_IDX,                                                                                  \
		     CONF_SLCD_CHAR9_SEG_IDX,                                                                                  \
		     CONF_SLCD_CHAR9_SEG_NUM - 1,                                                                              \
		     CONF_SLCD_CHAR9_MAPPING_SIZE},                                                                            \
		    {CONF_SLCD_CHAR10_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR10_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR10_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR10_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR11_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR11_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR11_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR11_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR12_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR12_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR12_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR12_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR13_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR13_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR13_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR13_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR14_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR14_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR14_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR14_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR15_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR15_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR15_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR15_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR16_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR16_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR16_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR16_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR17_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR17_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR17_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR17_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR18_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR18_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR18_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR18_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR19_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR19_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR19_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR19_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR20_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR20_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR20_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR20_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR21_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR21_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR21_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR21_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR22_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR22_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR22_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR22_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR23_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR23_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR23_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR23_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR24_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR24_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR24_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR24_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR25_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR25_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR25_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR25_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR26_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR26_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR26_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR26_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR27_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR27_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR27_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR27_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR28_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR28_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR28_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR28_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR29_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR29_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR29_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR29_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR30_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR30_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR30_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR30_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR31_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR31_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR31_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR31_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR32_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR32_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR32_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR32_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR33_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR33_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR33_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR33_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR34_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR34_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR34_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR34_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR35_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR35_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR35_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR35_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR36_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR36_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR36_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR36_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR37_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR37_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR37_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR37_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR38_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR38_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR38_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR38_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR39_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR39_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR39_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR39_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR40_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR40_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR40_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR40_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR41_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR41_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR41_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR41_MAPPING_SIZE},                                                                           \
		    {CONF_SLCD_CHAR42_COM_IDX,                                                                                 \
		     CONF_SLCD_CHAR42_SEG_IDX,                                                                                 \
		     CONF_SLCD_CHAR42_SEG_NUM - 1,                                                                             \
		     CONF_SLCD_CHAR42_MAPPING_SIZE},                                                                           \
		{                                                                                                              \
			CONF_SLCD_CHAR43_COM_IDX, CONF_SLCD_CHAR43_SEG_IDX, CONF_SLCD_CHAR43_SEG_NUM - 1,                          \
			    CONF_SLCD_CHAR43_MAPPING_SIZE                                                                          \
		}                                                                                                              \
	}

#define CONF_SLCD_LPENL (0)

#define CONF_SLCD_LPENH (0) // </e>

// <<< end of configuration section >>>

#endif // HPL_SLCD_CONFIG_H
