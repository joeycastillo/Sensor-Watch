/* Auto-generated config file hpl_rtc_config.h */
#ifndef HPL_RTC_CONFIG_H
#define HPL_RTC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Basic settings

#ifndef CONF_RTC_ENABLE
#define CONF_RTC_ENABLE 1
#endif

// <q> Force reset RTC on initialization
// <i> Force RTC to reset on initialization.
// <i> Note that the previous power down data in RTC is lost if it's enabled.
// <id> rtc_arch_init_reset
#ifndef CONF_RTC_INIT_RESET
#define CONF_RTC_INIT_RESET 1
#endif

// <o> Prescaler configuration
// <0x0=>OFF(Peripheral clock divided by 1)
// <0x1=>Peripheral clock divided by 1
// <0x2=>Peripheral clock divided by 2
// <0x3=>Peripheral clock divided by 4
// <0x4=>Peripheral clock divided by 8
// <0x5=>Peripheral clock divided by 16
// <0x6=>Peripheral clock divided by 32
// <0x7=>Peripheral clock divided by 64
// <0x8=>Peripheral clock divided by 128
// <0x9=>Peripheral clock divided by 256
// <0xA=>Peripheral clock divided by 512
// <0xB=>Peripheral clock divided by 1024
// <i> These bits define the RTC clock relative to the peripheral clock
// <id> rtc_arch_prescaler
#ifndef CONF_RTC_PRESCALER

#define CONF_RTC_PRESCALER 0x1

#endif

#ifndef CONF_RTC_COMP_VAL

#define CONF_RTC_COMP_VAL 0

#endif

// <e> RTC Tamper Input 0 settings
// <id> tamper_input_0_settings
#ifndef CONF_TAMPER_INPUT_0_SETTINGS
#define CONF_TAMPER_INPUT_0_SETTINGS 0
#endif

// <q> Tamper Level Settings
// <i> Indicates Tamper input 0 level
// <id> tamper_level_0
#ifndef CONF_RTC_TAMP_LVL_0
#define CONF_RTC_TAMP_LVL_0 0
#endif

// <o> RTC Tamper Input Action
// <0x0=>OFF(Disabled)
// <0x1=>Wake and Set Tamper Flag
// <0x2=>Capture Timestamp and Set Tamper Flag
// <0x3=>Active Layer Mode.IN and OUT pin is used.Timestamp is also captured.
// <i> These bits define the RTC Tamper Input Action to be performed
// <id> rtc_tamper_input_action_0
#ifndef CONF_RTC_TAMPER_INACT_0
#define CONF_RTC_TAMPER_INACT_0 0
#endif

// <q> Debounce Enable for Tamper Input
// <i> Indicates Debounce should be enabled for Tamper input 0
// <id> tamper_debounce_enable_0
#ifndef CONF_RTC_TAMP_DEBNC_0
#define CONF_RTC_TAMP_DEBNC_0 0
#endif

// </e>

// <e> RTC Tamper Input 1 settings
// <id> tamper_input_1_settings
#ifndef CONF_TAMPER_INPUT_1_SETTINGS
#define CONF_TAMPER_INPUT_1_SETTINGS 0
#endif

// <q> Tamper Level Settings
// <i> Indicates Tamper input 1 level
// <id> tamper_level_1
#ifndef CONF_RTC_TAMP_LVL_1
#define CONF_RTC_TAMP_LVL_1 0
#endif

// <o> RTC Tamper Input Action
// <0x0=>OFF(Disabled)
// <0x1=>Wake and Set Tamper Flag
// <0x2=>Capture Timestamp and Set Tamper Flag
// <0x3=>Active Layer Mode.IN and OUT pin is used.Timestamp is also captured.
// <i> These bits define the RTC Tamper Input Action to be performed
// <id> rtc_tamper_input_action_1
#ifndef CONF_RTC_TAMPER_INACT_1
#define CONF_RTC_TAMPER_INACT_1 0
#endif

// <q> Debounce Enable for Tamper Input
// <i> Indicates Debounce should be enabled for Tamper input 1
// <id> tamper_debounce_enable_1
#ifndef CONF_RTC_TAMP_DEBNC_1
#define CONF_RTC_TAMP_DEBNC_1 0
#endif

// </e>

// <e> RTC Tamper Input 2 settings
// <id> tamper_input_2_settings
#ifndef CONF_TAMPER_INPUT_2_SETTINGS
#define CONF_TAMPER_INPUT_2_SETTINGS 0
#endif

// <q> Tamper Level Settings
// <i> Indicates Tamper input 2 level
// <id> tamper_level_2
#ifndef CONF_RTC_TAMP_LVL_2
#define CONF_RTC_TAMP_LVL_2 0
#endif

// <o> RTC Tamper Input Action
// <0x0=>OFF(Disabled)
// <0x1=>Wake and Set Tamper Flag
// <0x2=>Capture Timestamp and Set Tamper Flag
// <0x3=>Active Layer Mode.IN and OUT pin is used.Timestamp is also captured.
// <i> These bits define the RTC Tamper Input Action to be performed
// <id> rtc_tamper_input_action_2
#ifndef CONF_RTC_TAMPER_INACT_2
#define CONF_RTC_TAMPER_INACT_2 0
#endif

// <q> Debounce Enable for Tamper Input
// <i> Indicates Debounce should be enabled for Tamper input 2
// <id> tamper_debounce_enable_2
#ifndef CONF_RTC_TAMP_DEBNC_2
#define CONF_RTC_TAMP_DEBNC_2 0
#endif

// </e>

// <e> RTC Tamper Input 3 settings
// <id> tamper_input_3_settings
#ifndef CONF_TAMPER_INPUT_3_SETTINGS
#define CONF_TAMPER_INPUT_3_SETTINGS 0
#endif

// <q> Tamper Level Settings
// <i> Indicates Tamper input 3 level
// <id> tamper_level_3
#ifndef CONF_RTC_TAMP_LVL_3
#define CONF_RTC_TAMP_LVL_3 0
#endif

// <o> RTC Tamper Input Action
// <0x0=>OFF(Disabled)
// <0x1=>Wake and Set Tamper Flag
// <0x2=>Capture Timestamp and Set Tamper Flag
// <0x3=>Active Layer Mode.IN and OUT pin is used.Timestamp is also captured.
// <i> These bits define the RTC Tamper Input Action to be performed
// <id> rtc_tamper_input_action_3
#ifndef CONF_RTC_TAMPER_INACT_3
#define CONF_RTC_TAMPER_INACT_3 0
#endif

// <q> Debounce Enable for Tamper Input
// <i> Indicates Debounce should be enabled for Tamper input 3
// <id> tamper_debounce_enable_3
#ifndef CONF_RTC_TAMP_DEBNC_3
#define CONF_RTC_TAMP_DEBNC_3 0
#endif

// </e>

// <e> RTC Tamper Input 4 settings
// <id> tamper_input_4_settings
#ifndef CONF_TAMPER_INPUT_4_SETTINGS
#define CONF_TAMPER_INPUT_4_SETTINGS 0
#endif

// <q> Tamper Level Settings
// <i> Indicates Tamper input 4 level
// <id> tamper_level_4
#ifndef CONF_RTC_TAMP_LVL_4
#define CONF_RTC_TAMP_LVL_4 0
#endif

// <o> RTC Tamper Input Action
// <0x0=>OFF(Disabled)
// <0x1=>Wake and Set Tamper Flag
// <0x2=>Capture Timestamp and Set Tamper Flag
// <0x3=>Active Layer Mode.IN and OUT pin is used.Timestamp is also captured.
// <i> These bits define the RTC Tamper Input Action to be performed
// <id> rtc_tamper_input_action_4
#ifndef CONF_RTC_TAMPER_INACT_4
#define CONF_RTC_TAMPER_INACT_4 0
#endif

// <q> Debounce Enable for Tamper Input
// <i> Indicates Debounce should be enabled for Tamper input 4
// <id> tamper_debounce_enable_4
#ifndef CONF_RTC_TAMP_DEBNC_4
#define CONF_RTC_TAMP_DEBNC_4 0
#endif

// </e>

// <o> RTC Tamper Active Layer Frequency Prescalar
// <0x0=>DIV2 CLK_RTC_OUT is CLK_RTC /2
// <0x1=>DIV4 CLK_RTC_OUT is CLK_RTC /4
// <0x2=>DIV8 CLK_RTC_OUT is CLK_RTC /8
// <0x3=>DIV16 CLK_RTC_OUT is CLK_RTC /16
// <0x4=>DIV32 CLK_RTC_OUT is CLK_RTC /32
// <0x5=>DIV64 CLK_RTC_OUT is CLK_RTC /64
// <0x6=>DIV128 CLK_RTC_OUT is CLK_RTC /128
// <0x7=>DIV256 CLK_RTC_OUT is CLK_RTC /256
// <i> These bits define the RTC Tamper Active Layer Frequecny Prescalar
// <id> rtc_tamper_active_layer_frequency_prescalar
#ifndef CONF_RTC_TAMP_ACT_LAYER_FREQ_PRES
#define CONF_RTC_TAMP_ACT_LAYER_FREQ_PRES 0
#endif

// <o> RTC Tamper Debounce Frequency Prescalar
// <0x0=>DIV2 CLK_RTC_DEB is CLK_RTC /2
// <0x1=>DIV4 CLK_RTC_DEB is CLK_RTC /4
// <0x2=>DIV8 CLK_RTC_DEB is CLK_RTC /8
// <0x3=>DIV16 CLK_RTC_DEB is CLK_RTC /16
// <0x4=>DIV32 CLK_RTC_DEB is CLK_RTC /32
// <0x5=>DIV64 CLK_RTC_DEB is CLK_RTC /64
// <0x6=>DIV128 CLK_RTC_DEB is CLK_RTC /128
// <0x7=>DIV256 CLK_RTC_DEB is CLK_RTC /256
// <i> These bits define the RTC Debounce Frequency Prescalar
// <id> rtc_tamper_debounce_frequency_prescalar
#ifndef CONF_RTC_TAMP_DEBF_PRES
#define CONF_RTC_TAMP_DEBF_PRES 0
#endif

// <e> Event control
// <id> rtc_event_control
#ifndef CONF_RTC_EVENT_CONTROL_ENABLE
#define CONF_RTC_EVENT_CONTROL_ENABLE 0
#endif

// <q> Periodic Interval 0 Event Output
// <i> This bit indicates whether Periodic interval 0 event is enabled and will be generated
// <id> rtc_pereo0
#ifndef CONF_RTC_PEREO0
#define CONF_RTC_PEREO0 0
#endif
// <q> Periodic Interval 1 Event Output
// <i> This bit indicates whether Periodic interval 1 event is enabled and will be generated
// <id> rtc_pereo1
#ifndef CONF_RTC_PEREO1
#define CONF_RTC_PEREO1 0
#endif
// <q> Periodic Interval 2 Event Output
// <i> This bit indicates whether Periodic interval 2 event is enabled and will be generated
// <id> rtc_pereo2
#ifndef CONF_RTC_PEREO2
#define CONF_RTC_PEREO2 0
#endif
// <q> Periodic Interval 3 Event Output
// <i> This bit indicates whether Periodic interval 3 event is enabled and will be generated
// <id> rtc_pereo3
#ifndef CONF_RTC_PEREO3
#define CONF_RTC_PEREO3 0
#endif
// <q> Periodic Interval 4 Event Output
// <i> This bit indicates whether Periodic interval 4 event is enabled and will be generated
// <id> rtc_pereo4
#ifndef CONF_RTC_PEREO4
#define CONF_RTC_PEREO4 0
#endif
// <q> Periodic Interval 5 Event Output
// <i> This bit indicates whether Periodic interval 5 event is enabled and will be generated
// <id> rtc_pereo5
#ifndef CONF_RTC_PEREO5
#define CONF_RTC_PEREO5 0
#endif
// <q> Periodic Interval 6 Event Output
// <i> This bit indicates whether Periodic interval 6 event is enabled and will be generated
// <id> rtc_pereo6
#ifndef CONF_RTC_PEREO6
#define CONF_RTC_PEREO6 0
#endif
// <q> Periodic Interval 7 Event Output
// <i> This bit indicates whether Periodic interval 7 event is enabled and will be generated
// <id> rtc_pereo7
#ifndef CONF_RTC_PEREO7
#define CONF_RTC_PEREO7 0
#endif

// <q> Compare 0 Event Output
// <i> This bit indicates whether Compare O event is enabled and will be generated
// <id> rtc_cmpeo0
#ifndef CONF_RTC_COMPE0
#define CONF_RTC_COMPE0 0
#endif

// <q> Overflow Event Output
// <i> This bit indicates whether Overflow event is enabled and will be generated
// <id> rtc_ovfeo
#ifndef CONF_RTC_OVFEO
#define CONF_RTC_OVFEO 0
#endif

// </e>

// </h>

// <<< end of configuration section >>>

#endif // HPL_RTC_CONFIG_H
