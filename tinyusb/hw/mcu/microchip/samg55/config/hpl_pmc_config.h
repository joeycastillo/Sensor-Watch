/* Auto-generated config file hpl_pmc_config.h */
#ifndef HPL_PMC_CONFIG_H
#define HPL_PMC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

// <e> OSC32K Oscillator Configuration
//   <i> Indicates whether configuration for OSC32K is enabled or not
//   <id> enable_osc32k
#ifndef CONF_PMC_OSC32K_CONFIG
#define CONF_PMC_OSC32K_CONFIG 0
#endif

// <h> OSC32K Oscillator Control
// <q> OSC32K Oscillator Enable
//   <i> Indicates whether OSC32K Oscillator is enabled or not
//   <id> osc32k_arch_enable
#ifndef CONF_PMC_OSC32K_ENABLE
#define CONF_PMC_OSC32K_ENABLE 0
#endif

// </h>
// </e>

// <e> XOSC32K Oscillator Configuration
//   <i> Indicates whether configuration for XOSC32K is enabled or not
//   <id> enable_xosc32k
#ifndef CONF_PMC_XOSC32K_CONFIG
#define CONF_PMC_XOSC32K_CONFIG 1
#endif

// <h> XOSC32K Oscillator Control
// <q> XOSC32K Oscillator Enable
//   <i> Indicates whether XOSC32K Oscillator is enabled or not
//   <id> xosc32k_arch_enable
#ifndef CONF_PMC_XOSC32K_ENABLE
#define CONF_PMC_XOSC32K_ENABLE 1
#endif

// <q> Oscillator Bypass Enable
//   <i> Indicates whether XOSC32K is bypassed or not.
//   <id> xosc32k_bypass
#ifndef CONF_PMC_XOSC32K_BYPASS
#define CONF_PMC_XOSC32K_BYPASS 0
#endif

// </h>
// </e>

// <e> OSC24M Oscillator Configuration
//   <i> Indicates whether configuration for OSC24M is enabled or not
//   <id> enable_osc24m
#ifndef CONF_PMC_OSC24M_CONFIG
#define CONF_PMC_OSC24M_CONFIG 1
#endif

// <h> OSC24M Oscillator Control
// <q> OSC24M Oscillator Enable
//   <i> Indicates whether OSC24M Oscillator is enabled or not.
//   <id> osc24m_arch_enable
#ifndef CONF_PMC_OSC24M_ENABLE
#define CONF_PMC_OSC24M_ENABLE 1
#endif

// <o> Frequency(HZ)
//   <0=> 8000000
//   <1=> 16000000
//   <2=> 24000000
//   <i> Select the frequency of embedded fast RC oscillator.
//   <id> osc24m_selector
#ifndef CONF_PMC_OSC24M_SELECTOR
#define CONF_PMC_OSC24M_SELECTOR 0
#endif

// </h>
// </e>

// <e> XOSC20M Oscillator Configuration
//   <i> Indicates whether configuration for XOSC20M is enabled or not.
//   <id> enable_xosc20m
#ifndef CONF_PMC_XOSC20M_CONFIG
#define CONF_PMC_XOSC20M_CONFIG 0
#endif

// <h> XOSC20M Oscillator Control
// <o> Frequency(HZ) <3000000-20000000>
//   <i> Select the frequency of crystal or ceramic resonator oscillator.
//   <id> xosc20m_selector
#ifndef CONF_PMC_XOSC20M_SELECTOR
#define CONF_PMC_XOSC20M_SELECTOR 12000000
#endif

// <o> Start up time for the external oscillator (ms): <0-256>
//   <i> Select start-up time.
//   <id> xosc20m_startup_time
#ifndef CONF_PMC_XOSC20M_STARTUP_TIME
#define CONF_PMC_XOSC20M_STARTUP_TIME 62
#endif

// <q> Enable
//   <i> Indicates whether XOSC20M Oscillator is enabled or not
//   <id> xosc20m_arch_enable
#ifndef CONF_PMC_XOSC20M_ENABLE
#define CONF_PMC_XOSC20M_ENABLE 0
#endif

// <q> Bypass Enable
//   <i> Indicates whether XOSC20M is bypassed or not.
//   <id> xosc20m_bypass
#ifndef CONF_PMC_XOSC20M_BYPASS
#define CONF_PMC_XOSC20M_BYPASS 0
#endif

// </h>
// </e>

// <e> Main Clock configuration
//   <i> Indicates whether Main Clock configuration is enabled or not
//   <id> enable_mainck
#ifndef CONF_CLK_MAINCK_CONFIG
#define CONF_CLK_MAINCK_CONFIG 1
#endif

// <h> Main Clock Control
// <o> Clock Source
//   <0=> Embedded 8/16/24 MHz Fast RC Oscillator (OSC24M)
//   <1=> External 3-20MHz Oscillator (XOSC20M)
//   <i> This defines the clock source for the Main Clock
//   <id> mainck_oscillator
#ifndef CONF_PMC_MAINCK_SRC
#define CONF_PMC_MAINCK_SRC 0
#endif

// <q> Enable Main Clock Failure Detection
// <i> Indicates whether Main Clock Failure Detection is enabled or disable.
// <i> The 8/16/24 MHz RC oscillator is automatically enabled when CFDEN=1.
// <id> clk_gen_cfden_enable
#ifndef CONF_PMC_CFDEN_ENABLE
#define CONF_PMC_CFDEN_ENABLE 0
#endif

// <q> Enable
//   <i> Indicates whether Main Clock is enabled or disable
//   <id> mainck_arch_enable
#ifndef CONF_PMC_MAINCK_ENABLE
#define CONF_PMC_MAINCK_ENABLE 1
#endif

// </h>
// </e>

// <e> Slow Clock Configuration
//   <i> Indicates whether Slow Clock configuration is enabled or not
//   <id> enable_slck
#ifndef CONF_PMC_SLCK_CONFIG
#define CONF_PMC_SLCK_CONFIG 1
#endif

// <h> Slow Clock Control
// <o> Clock Source
//   <0=> Embedded 32kHz RC Oscillator (OSC32K)
//   <1=> External 32768Hz Crystal Oscillator (XOSC32K)
//   <i> This defines the clock source for Slow Clock
//   <id> slck_ref_clock
#ifndef CONF_PMC_SLCK_SRC
#define CONF_PMC_SLCK_SRC 1
#endif

// <q> Enable
//   <i> Indicates whether Slow Clock is enabled or disable
//   <id> slck_arch_enable
#ifndef CONF_PMC_SLCK_ENABLE
#define CONF_PMC_SLCK_ENABLE 0
#endif

// </h>
// </e>

// <e> PLLA Clock Configuration
//   <i> Indicates whether configuration for PLLA Clock is enabled or not
//   <id> enable_pllack
#ifndef CONF_PMC_PLLACK_CONFIG
#define CONF_PMC_PLLACK_CONFIG 0
#endif

// <y> Source Source
//   <SLCK"> Slow Clock (SLCK)
//   <i> Select the clock source.
//   <id> pllack_ref_clock
#ifndef CONF_PMC_PLLACK_CLK
#define CONF_PMC_PLLACK_CLK SLCK
#endif

// <h> PLLA Clock Control
// <q> PLLA Clock Enable
//   <i> Indicates whether PLLACK Oscillator is enabled or not
//   <id> pllack_arch_enable
#ifndef CONF_PMC_PLLACK_ENABLE
#define CONF_PMC_PLLACK_ENABLE 0
#endif

// <o> Counter  <0-63>
//   <i> Specifies the number of Slow Clock cycles before the LOCKB bit is set
//   <i> in PMC_SR after CKGR_PLLBR is written
//   <id> pllack_counter
#ifndef CONF_PMC_PLLACK_COUNTER
#define CONF_PMC_PLLACK_COUNTER 50
#endif

// <o> Muliplier <8-7500>
//   <i> Indicates multiplier for input frequency
//   <id> pllack_mul
#ifndef CONF_PMC_PLLACK_MUL
#define CONF_PMC_PLLACK_MUL 1465
#endif

// <o> Divider
//   <0=> clock frequency is divided by 1
//   <1=> clock frequency is divided by 2
//   <i> Select the clock divider
//   <id> pllack_div
#ifndef CONF_PMC_PLLACK_DIV
#define CONF_PMC_PLLACK_DIV 0
#endif

// </h>
// </e>

// <e> PLLB Clock Oscillator Configuration
//   <i> Indicates whether configuration for PLLB Clock is enabled or not
//   <id> enable_pllbck
#ifndef CONF_PMC_PLLBCK_CONFIG
#define CONF_PMC_PLLBCK_CONFIG 1
#endif

// <y> Clock Source
//   <SLCK"> Slow Clock (SLCK)
//   <i> Select the clock source.
//   <id> pllbck_ref_clock
#ifndef CONF_PMC_PLLBCK_CLK
#define CONF_PMC_PLLBCK_CLK SLCK
#endif

// <h> PLLB Clock Control
//   <q> Enable
//   <i> Indicates whether PLLB Clock Oscillator is enabled or not
//   <id> pllbck_arch_enable
#ifndef CONF_PMC_PLLBCK_ENABLE
#define CONF_PMC_PLLBCK_ENABLE 1
#endif

// <o> Counter  <0-63>
//   <i> Specifies the number of Slow Clock cycles before the LOCKB bit is set
//   <i> in PMC_SR after CKGR_PLLBR is written
//   <id> pllbck_counter
#ifndef CONF_PMC_PLLBCK_COUNTER
#define CONF_PMC_PLLBCK_COUNTER 50
#endif

// <o> Muliplier <8-2400>
//   <i> Indicates multiplier for input frequency
//   <id> pllbck_mul
#ifndef CONF_PMC_PLLBCK_MUL
#define CONF_PMC_PLLBCK_MUL 1465
#endif

// <o> Divider
//   <0=> clock frequency is divided by 1
//   <1=> clock frequency is divided by 2
//   <i> Select the clock divider
//   <id> pllbck_div
#ifndef CONF_PMC_PLLBCK_DIV
#define CONF_PMC_PLLBCK_DIV 0
#endif

// </h>
// </e>

// <e> Master Clock(MCK) configuration
//   <i> Indicates whether Master Clock(MCK) configuration is enabled or not
//   <id> enable_mck
#ifndef CONF_PMC_MCK_CONFIG
#define CONF_PMC_MCK_CONFIG 1
#endif

// <h> MCK Clock Control
// <o> clock generator MCK source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <i> This defines the clock source for MCK
//   <id> mck_oscillator
#ifndef CONF_PMC_MCK_SRC
#define CONF_PMC_MCK_SRC 1
#endif

// <q> Enable Clock_MCK
//   <i> Indicates whether MCK is enabled or disable
//   <id> mck_arch_enable
#ifndef CONF_PMC_MCK_ENABLE
#define CONF_PMC_MCK_ENABLE 1
#endif

// <y> Master Clock Prescaler
//   <PMC_MCKR_PRES_CLK_1_Val"> 1
//   <PMC_MCKR_PRES_CLK_2_Val"> 2
//   <PMC_MCKR_PRES_CLK_4_Val"> 4
//   <PMC_MCKR_PRES_CLK_8_Val"> 8
//   <PMC_MCKR_PRES_CLK_16_Val"> 16
//   <PMC_MCKR_PRES_CLK_32_Val"> 32
//   <PMC_MCKR_PRES_CLK_64_Val"> 64
//   <PMC_MCKR_PRES_CLK_3_Val"> 3
//   <i> Select the clock prescaler.
//   <id> mck_presc
#ifndef CONF_PMC_MCK_PRESC
#define CONF_PMC_MCK_PRESC PMC_MCKR_PRES_CLK_1_Val
#endif

// </h>
// </e>

// <e> SLCK2 Clock configuration
// <i> Indicates whether SLCK2 is enabled or disable
// <id> slck2_arch_enable
#ifndef CONF_PMC_SLCK2_ENABLE
#define CONF_PMC_SLCK2_ENABLE 1
#endif

// <h> SLCK2 Clock Control
// <o> clock generator SLCK2 source
//   <0=> Slow Clock (SLCK)
//   <i> This defines the clock source for SLCK2
//   <id> clk_gen_slck2_oscillator
#ifndef CONF_PMC_SLCK2_SRC
#define CONF_PMC_SLCK2_SRC 0
#endif

// </h>
// </e>

// <e> USB Clock Controller (USB_48M)
//   <id> enable_usb_48m
#ifndef CONF_PMC_USB_CONFIG
#define CONF_PMC_USB_CONFIG 1
#endif

// <h> USB Clock Control
// <o> clock generator USB source
//   <0=> PLLA Clock (PLLACK)
//   <1=> PLLB Clock (PLLBCK)
//   <i> This defines the clock source for USB
//   <id> usb_48m_oscillator
#ifndef CONF_PMC_USB_SRC
#define CONF_PMC_USB_SRC 1
#endif

// <o> USB Clock Divider (USBDIV + 1) <1-16>
//   <i> Set the clock divider.
//   <id> usb_48m_div
#ifndef CONF_PMC_USB_USBDIV
#define CONF_PMC_USB_USBDIV 1
#endif

// </h>
// </e>

// <e> Clock_PCK0 configuration
//   <i> Indicates whether PCK0 configuration is enabled or not
//   <id> enable_pck0
#ifndef CONF_PMC_PCK0_CONFIG
#define CONF_PMC_PCK0_CONFIG 1
#endif

// <h> PCK0 Clock Control
// <o> clock generator PCK0 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK0
//   <id> pck0_oscillator
#ifndef CONF_PMC_PCK0_SRC
#define CONF_PMC_PCK0_SRC 1
#endif

// <q> Enable
//   <i> Indicates whether PCK0 is enabled or disable
//   <id> pck0_arch_enable
#ifndef CONF_PMC_PCK0_ENABLE
#define CONF_PMC_PCK0_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck0_presc
#ifndef CONF_PMC_PCK0_PRESC
#define CONF_PMC_PCK0_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK1 configuration
//   <i> Indicates whether PCK1 configuration is enabled or not
//   <id> enable_pck1
#ifndef CONF_PMC_PCK1_CONFIG
#define CONF_PMC_PCK1_CONFIG 1
#endif

// <h> PCK1 Clock Control
// <o> clock generator PCK1 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK1
//   <id> pck1_oscillator
#ifndef CONF_PMC_PCK1_SRC
#define CONF_PMC_PCK1_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK1 is enabled or disable
//   <id> pck1_arch_enable
#ifndef CONF_PMC_PCK1_ENABLE
#define CONF_PMC_PCK1_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck1_presc
#ifndef CONF_PMC_PCK1_PRESC
#define CONF_PMC_PCK1_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK2 configuration
//   <i> Indicates whether PCK2 configuration is enabled or not
//   <id> enable_pck2
#ifndef CONF_PMC_PCK2_CONFIG
#define CONF_PMC_PCK2_CONFIG 1
#endif

// <h> PCK2 Clock Control
// <o> clock generator PCK2 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK2
//   <id> pck2_oscillator
#ifndef CONF_PMC_PCK2_SRC
#define CONF_PMC_PCK2_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK2 is enabled or disable
//   <id> pck2_arch_enable
#ifndef CONF_PMC_PCK2_ENABLE
#define CONF_PMC_PCK2_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck2_presc
#ifndef CONF_PMC_PCK2_PRESC
#define CONF_PMC_PCK2_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK3 configuration
//   <i> Indicates whether PCK3 configuration is enabled or not
//   <id> enable_pck3
#ifndef CONF_PMC_PCK3_CONFIG
#define CONF_PMC_PCK3_CONFIG 1
#endif

// <h> PCK3 Clock Control
// <o> clock generator PCK3 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK3
//   <id> pck3_oscillator
#ifndef CONF_PMC_PCK3_SRC
#define CONF_PMC_PCK3_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK3 is enabled or disable
//   <id> pck3_arch_enable
#ifndef CONF_PMC_PCK3_ENABLE
#define CONF_PMC_PCK3_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck3_presc
#ifndef CONF_PMC_PCK3_PRESC
#define CONF_PMC_PCK3_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK4 configuration
//   <i> Indicates whether PCK4 configuration is enabled or not
//   <id> enable_pck4
#ifndef CONF_PMC_PCK4_CONFIG
#define CONF_PMC_PCK4_CONFIG 1
#endif

// <h> PCK4 Clock Control
// <o> clock generator PCK4 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK4
//   <id> pck4_oscillator
#ifndef CONF_PMC_PCK4_SRC
#define CONF_PMC_PCK4_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK4 is enabled or disable
//   <id> pck4_arch_enable
#ifndef CONF_PMC_PCK4_ENABLE
#define CONF_PMC_PCK4_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck4_presc
#ifndef CONF_PMC_PCK4_PRESC
#define CONF_PMC_PCK4_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK5 configuration
//   <i> Indicates whether PCK5 configuration is enabled or not
//   <id> enable_pck5
#ifndef CONF_PMC_PCK5_CONFIG
#define CONF_PMC_PCK5_CONFIG 1
#endif

// <h> PCK5 Clock Control
// <o> clock generator PCK5 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK5
//   <id> pck5_oscillator
#ifndef CONF_PMC_PCK5_SRC
#define CONF_PMC_PCK5_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK5 is enabled or disable
//   <id> pck5_arch_enable
#ifndef CONF_PMC_PCK5_ENABLE
#define CONF_PMC_PCK5_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck5_presc
#ifndef CONF_PMC_PCK5_PRESC
#define CONF_PMC_PCK5_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK6 configuration
//   <i> Indicates whether PCK6 configuration is enabled or not
//   <id> enable_pck6
#ifndef CONF_PMC_PCK6_CONFIG
#define CONF_PMC_PCK6_CONFIG 1
#endif

// <h> PCK6 Clock Control
// <o> clock generator PCK6 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK6
//   <id> pck6_oscillator
#ifndef CONF_PMC_PCK6_SRC
#define CONF_PMC_PCK6_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK6 is enabled or disable
//   <id> pck6_arch_enable
#ifndef CONF_PMC_PCK6_ENABLE
#define CONF_PMC_PCK6_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck6_presc
#ifndef CONF_PMC_PCK6_PRESC
#define CONF_PMC_PCK6_PRESC 1
#endif
// </h>
// </e>

// <e> Clock_PCK7 configuration
//   <i> Indicates whether PCK7 configuration is enabled or not
//   <id> enable_pck7
#ifndef CONF_PMC_PCK7_CONFIG
#define CONF_PMC_PCK7_CONFIG 1
#endif

// <h> PCK7 Clock Control
// <o> clock generator PCK7 source
//   <0=> Slow Clock (SLCK)
//   <1=> Main Clock (MAINCK)
//   <2=> PLLA Clock (PLLACK)
//   <3=> PLLB Clock (PLLBCK)
//   <4=> Master Clock (MCK)
//   <i> This defines the clock source for PCK7
//   <id> pck7_oscillator
#ifndef CONF_PMC_PCK7_SRC
#define CONF_PMC_PCK7_SRC 0
#endif

// <q> Enable
//   <i> Indicates whether PCK7 is enabled or disable
//   <id> pck7_arch_enable
#ifndef CONF_PMC_PCK7_ENABLE
#define CONF_PMC_PCK7_ENABLE 0
#endif

// <o> Programmable Clock Controller Prescaler <1-256>
//   <i> Select the clock prescaler
//   <id> pck7_presc
#ifndef CONF_PMC_PCK7_PRESC
#define CONF_PMC_PCK7_PRESC 1
#endif
// </h>
// </e>

// <e> MCK/8
// <id> enable_mck_div_8
#ifndef CONF_MCK_DIV_8_CONFIG
#define CONF_MCK_DIV_8_CONFIG 0
#endif

// <o> MCK/8 Source
// <0=> Master Clock (MCK)
// <id> mck_div_8_src
#ifndef CONF_MCK_DIV_8_SRC
#define CONF_MCK_DIV_8_SRC 0
#endif
// </e>

// <e> External Clock Input Configuration
// <id> enable_dummy_ext
#ifndef CONF_DUMMY_EXT_CONFIG
#define CONF_DUMMY_EXT_CONFIG 1
#endif

// <o> External Clock Input Source
// <i> All here are dummy values
// <i> Refer to the peripherals settings for actual input information
// <0=> Specific clock input from specific pin
// <id> dummy_ext_src
#ifndef CONF_DUMMY_EXT_SRC
#define CONF_DUMMY_EXT_SRC 0
#endif

// <h> External Clock Control
// <o> Frequency(HZ) <1-20000000>
//   <i> Select the frequency of External Clock Control
//   <id> usart_ext_frequency
#ifndef CONF_USART_EXT_FREQUENCY
#define CONF_USART_EXT_FREQUENCY 9600
#endif
// </h>
// </e>

// <e> External Clock Configuration
// <id> enable_dummy_ext_clk
#ifndef CONF_DUMMY_EXT_CLK_CONFIG
#define CONF_DUMMY_EXT_CLK_CONFIG 1
#endif

// <o> External Clock Source
// <i> All here are dummy values
// <i> Refer to the peripherals settings for actual input information
// <0=> External Clock Input
// <id> dummy_ext_clk_src
#ifndef CONF_DUMMY_EXT_CLK_SRC
#define CONF_DUMMY_EXT_CLK_SRC 0
#endif
// </e>

// <e> System Configuration
//   <i> Indicates whether configuration for system is enabled or not
//   <id> enable_hclk_clock
#ifndef CONF_SYSTEM_CONFIG
#define CONF_SYSTEM_CONFIG 1
#endif

// <h> Processor Clock Settings
// <o> Processor Clock source
//   <0=> Master Clock (MCK)
//   <i> This defines the clock source for the HCLK
//   <id> hclk_clock_source
#ifndef CONF_HCLK_SRC
#define CONF_HCLK_SRC 0
#endif

// <o> Flash Wait State
//   <0=> 1 cycle
//   <1=> 2 cycles
//   <2=> 3 cycles
//   <3=> 4 cycles
//   <4=> 5 cycles
//   <5=> 6 cycles
//   <i> This field defines the number of wait states for read and write operations.
//   <id> eefc_fws
#ifndef CONF_EEFC_FWS
#define CONF_EEFC_FWS 0
#endif

// </h>
// </e>

// <e> SysTick Configuration
//   <i> Indicates systick configuration.
//   <id> enable_systick_clock
#ifndef CONF_SYSTICK_CONFIG
#define CONF_SYSTICK_CONFIG 1
#endif

// <h> SysTick Clock Settings
// <o> systick Clock source
//   <0=> Master Clock (MCK)
//   <i> This defines the clock source for the SYSTICK
//   <id> systick_clock_source
#ifndef CONF_SYSTICK_SRC
#define CONF_SYSTICK_SRC 0
#endif

// <o> Systick clock divider
//   <8=> 8
//   <i> Select systick clock divider
//   <id> systick_clock_div
#ifndef CONF_SYSTICK_DIV
#define CONF_SYSTICK_DIV 8
#endif

// </h>
// </e>

// <e> Free Run Clock Configuration
//   <i> Indicates ...
//   <id> enable_fclk_clock
#ifndef CONF_FCLK_CONFIG
#define CONF_FCLK_CONFIG 1
#endif

// <h> Free Run Clock Settings
// <o> Free Run Clock source
//   <0=> Master Clock (MCK)
//   <i> This defines the clock source for the Free Running Clock
//   <id> fclk_clock_source
#ifndef CONF_FCLK_SRC
#define CONF_FCLK_SRC 0
#endif

// </h>
// </e>

// <<< end of configuration section >>>

#endif // HPL_PMC_CONFIG_H
