/**
 * \file
 *
 * \brief Generic WDT functionality declaration.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _HAL_WDT_H_INCLUDED
#define _HAL_WDT_H_INCLUDED

#include "hpl_wdt.h"
#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_wdt
 *
 * @{
 */

struct wdt_descriptor;

/** \brief WDT HAL driver struct
 *
 */
struct wdt_descriptor {
	struct wdt_dev dev;
};

/**
 * \brief Initialize the WDT HAL instance and hardware
 *
 * Initialize WDT HAL.
 *
 * \param[out] wdt The pointer to the HAL WDT instance.
 * \param[in]  hw The pointer to the hardware instance.
 * \return Operation status of init
 * \retval 0 Completed sucessfully.
 * \retval -1 Always on or enabled, don't need init again.
 */
static inline int32_t wdt_init(struct wdt_descriptor *const wdt, const void *hw)
{
	ASSERT(wdt && hw);

	wdt->dev.hw = (void *)hw;

	return _wdt_init(&wdt->dev);
}

/**
 * \brief Deinitialize the WDT HAL instance and hardware
 *
 * Deinitialize WDT HAL.
 *
 * \param[in] wdt The pointer to the HAL WDT instance.
 * \return Operation status of init
 * \retval 0 Completed sucessfully.
 * \retval -1 Always on, can't deinitialize.
 */
static inline int32_t wdt_deinit(struct wdt_descriptor *const wdt)
{
	ASSERT(wdt);

	return _wdt_deinit(&wdt->dev);
}
/**
 * \brief Config the timeout period for WDT HAL instance and hardware
 *
 * Set the timeout period to WDT instance.
 *
 * \param[in] wdt The pointer to the HAL WDT instance.
 * \param[in] clk_rate The current clock rate of generic clock(GCLK_WDT) in HZ
 * \param[in] timeout_period The desired timeout period(ms).
 * \return Operation status of init
 * \retval 0 Completed sucessfully.
 * \retval -1 Always on or enabled, can't set again.
 * \retval -2 Invalid timeout period.
 */
static inline int32_t wdt_set_timeout_period(struct wdt_descriptor *const wdt, const uint32_t clk_rate,
                                             const uint16_t timeout_period)
{
	ASSERT(wdt && wdt->dev.hw);

	return _wdt_set_timeout_period(&wdt->dev, clk_rate, timeout_period);
}

/**
 * \brief Get the timeout period for WDT HAL instance and hardware
 *
 * \param[in] wdt The pointer to the HAL WDT instance.
 * \param[in] clk_rate The current clock rate of generic clock (GCLK_WDT) in Hz
 * \return Current timeout period(ms)
 * \retval -1 Invalid timeout period
 */
static inline uint32_t wdt_get_timeout_period(struct wdt_descriptor *const wdt, const uint32_t clk_rate)
{
	ASSERT(wdt && wdt->dev.hw);

	return _wdt_get_timeout_period(&wdt->dev, clk_rate);
}

/**
 * \brief Enbale watchdog timer
 *
 * \param[in] wdt The pointer to the HAL WDT instance.
 * \return Operation status of init
 * \retval 0  Completed sucessfully.
 */
static inline int32_t wdt_enable(struct wdt_descriptor *const wdt)
{
	ASSERT(wdt && wdt->dev.hw);

	return _wdt_enable(&wdt->dev);
}

/**
 * \brief Disable watchdog timer
 *
 * \param[in] wdt The pointer to the HAL WDT instance.
 * \return Operation status of init
 * \retval 0  Completed sucessfully.
 * \retval -1 Always on, can't disable.
 */
static inline int32_t wdt_disable(struct wdt_descriptor *const wdt)
{
	ASSERT(wdt && wdt->dev.hw);

	return _wdt_disable(&wdt->dev);
}

/**
 * \brief Feed watchdog timer to make WDT kick from start
 *
 * \param[in] wdt The pointer to the HAL WDT instance.
 * \return Operation status of init
 * \retval 0 Completed sucessfully.
 */
static inline int32_t wdt_feed(struct wdt_descriptor *const wdt)
{
	ASSERT(wdt && wdt->dev.hw);

	return _wdt_feed(&wdt->dev);
}

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version.
 */
uint32_t wdt_get_version(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* _HAL_WDT_H_INCLUDED */
