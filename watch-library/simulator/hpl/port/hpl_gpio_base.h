
/**
 * \file
 *
 * \brief SAM PORT.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
#include <compiler.h>
#include <hpl_gpio.h>
#include <utils_assert.h>
#include <hpl_port_config.h>

/**
 * \brief Set direction on port with mask
 */
static inline void _gpio_set_direction(const enum gpio_port port, const uint32_t mask,
                                       const enum gpio_direction direction)
{
}

/**
 * \brief Set output level on port with mask
 */
static inline void _gpio_set_level(const enum gpio_port port, const uint32_t mask, const bool level)
{
}

/**
 * \brief Change output level to the opposite with mask
 */
static inline void _gpio_toggle_level(const enum gpio_port port, const uint32_t mask)
{
}

/**
 * \brief Get input levels on all port pins
 */
static inline uint32_t _gpio_get_level(const enum gpio_port port)
{
	uint32_t tmp = 0;
	return tmp;
}

/**
 * \brief Set pin pull mode
 */
static inline void _gpio_set_pin_pull_mode(const enum gpio_port port, const uint8_t pin,
                                           const enum gpio_pull_mode pull_mode)
{
}

/**
 * \brief Set gpio pin function
 */
static inline void _gpio_set_pin_function(const uint32_t gpio, const uint32_t function)
{
}

static inline void _port_event_init()
{
}
