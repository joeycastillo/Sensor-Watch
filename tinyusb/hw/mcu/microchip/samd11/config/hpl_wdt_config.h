/* Auto-generated config file hpl_wdt_config.h */
#ifndef HPL_WDT_CONFIG_H
#define HPL_WDT_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Basic settings

// <o> PER configuration
// <0x0=>8 clock cycles
// <0x1=>16 clock cycles
// <0x2=>32 clock cycles
// <0x3=>64 clock cycles
// <0x4=>128 clock cycles
// <0x5=>256 clock cycles
// <0x6=>512 clock cycles
// <0x7=>1024 clock cycles
// <0x8=>2048 clock cycles
// <0x9=>4096 clock cycles
// <0xA=>8192 clock cycles
// <0xB=>16384 clock cycles
// <i> These bits define the watchdog time-out period
// <id> wdt_arch_per
#ifndef CONF_WDT_PER
#define CONF_WDT_PER 0x0
#endif

// </h>

// <h> Advanced  settings

// <e> Window mode enable
// <i> Watchdog Timer window mode enable
// 0: Disabled
// 0: Enabled
// <id> wdt_arch_window_en
#ifndef CONF_WDT_WINDOW_EN
#define CONF_WDT_WINDOW_EN 0x0
#endif

// <o> Window mode timeout period configuration
// <0x0=>8 clock cycles
// <0x1=>16 clock cycles
// <0x2=>32 clock cycles
// <0x3=>64 clock cycles
// <0x4=>128 clock cycles
// <0x5=>256 clock cycles
// <0x6=>512 clock cycles
// <0x7=>1024 clock cycles
// <0x8=>2048 clock cycles
// <0x9=>4096 clock cycles
// <0xA=>8192 clock cycles
// <0xB=>16384 clock cycles
// <i> These bits define the watchdog time-out period
// <id> wdt_arch_window
#ifndef CONF_WDT_WINDOW
#define CONF_WDT_WINDOW 0x0
#endif

// </e>

// </h>

// <<< end of configuration section >>>

#endif // HPL_WDT_CONFIG_H
