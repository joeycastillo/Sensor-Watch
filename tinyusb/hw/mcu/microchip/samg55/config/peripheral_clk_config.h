/* Auto-generated config file peripheral_clk_config.h */
#ifndef PERIPHERAL_CLK_CONFIG_H
#define PERIPHERAL_CLK_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

/**
 * \def CONF_HCLK_FREQUENCY
 * \brief HCLK's Clock frequency
 */
#ifndef CONF_HCLK_FREQUENCY
#define CONF_HCLK_FREQUENCY 8000000
#endif

/**
 * \def CONF_FCLK_FREQUENCY
 * \brief FCLK's Clock frequency
 */
#ifndef CONF_FCLK_FREQUENCY
#define CONF_FCLK_FREQUENCY 8000000
#endif

/**
 * \def CONF_CPU_FREQUENCY
 * \brief CPU's Clock frequency
 */
#ifndef CONF_CPU_FREQUENCY
#define CONF_CPU_FREQUENCY 8000000
#endif

/**
 * \def CONF_SLCK_FREQUENCY
 * \brief Slow Clock frequency
 */
#define CONF_SLCK_FREQUENCY 32768

/**
 * \def CONF_MCK_FREQUENCY
 * \brief Master Clock frequency
 */
#define CONF_MCK_FREQUENCY 8000000

// <o> USB Clock Source
// <0=> USB Clock Controller (USB_48M)
// <id> usb_clock_source
// <i> Select the clock source for USB.
#ifndef CONF_UDP_SRC
#define CONF_UDP_SRC 0
#endif

/**
 * \def CONF_UDP_FREQUENCY
 * \brief UDP's Clock frequency
 */
#ifndef CONF_UDP_FREQUENCY
#define CONF_UDP_FREQUENCY 48005120
#endif

// <<< end of configuration section >>>

#endif // PERIPHERAL_CLK_CONFIG_H
