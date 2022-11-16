/**
 * \file
 *
 * \brief WDT related functionality declaration.
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

#ifndef _HPL_WDT_H_INCLUDED
#define _HPL_WDT_H_INCLUDED

/**
 * \addtogroup HPL WDT
 *
 * \section hpl_wdt_rev Revision History
 * - v1.0.0 Initial Release
 *
 *@{
 */

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief WDT device structure
 *
 * The WDT device structure
 */
struct wdt_dev {
	void *hw;
};

/**
 * \name HPL functions
 */

/**
 * \brief WDT initialization function
 *
 * \param[in] dev The pointer to hardware instance
 * \return Initialization status.
 * \retval 0  The initialization is completed successfully
 * \retval -1 Always on or enabled
 */
int32_t _wdt_init(struct wdt_dev *const dev);

/**
 * \brief Deinitialize WDT
 *
 * \param[in] dev The pointer to hardware instance
 * \return Operation status.
 * \retval 0  Operation is completed successfully
 * \retval -1 Always on
 */
int32_t _wdt_deinit(struct wdt_dev *const dev);

/**
 * \brief Set timeout period for WDT instance
 *
 * \param[in] dev The pointer to hardware instance
 * \param[in] clk_rate The current clock rate of generic clock(GCLK_WDT) in HZ
 * \param[in] timeout_period The desired timeout period(ms)
 * \return Operation status.
 * \retval 0 Operation is completed successfully
 * \retval -1 Always on or enabled
 * \retval -2 Invalid timeout period
 */
int32_t _wdt_set_timeout_period(struct wdt_dev *const dev, const uint32_t clk_rate, const uint16_t timeout_period);

/**
 * \brief Get timeout period for WDT instance
 *
 * \param[in] dev The pointer to hardware instance
 * \param[in] clk_rate The current clock rate of generic clock (GCLK_WDT) in Hz
 * \return Current timeout period (ms)
 * \retval -1 Invalid timeout period
 */
uint32_t _wdt_get_timeout_period(const struct wdt_dev *const dev, const uint32_t clk_rate);

/**
 * \brief Enbale watchdog timer
 *
 * \param[in] dev The pointer to hardware instance
 * \return Operation status.
 * \retval 0 Operation is completed successfully
 * \retval -1 Always on
 */
int32_t _wdt_enable(struct wdt_dev *const dev);

/**
 * \brief Disable watchdog timer
 *
 * \param[in] dev The pointer to hardware instance
 * \return Operation status.
 * \retval 0  Operation is completed successfully
 * \retval -1 Always on
 */
int32_t _wdt_disable(struct wdt_dev *const dev);

/**
 * \brief reset watchdog timer to make wdt work from start
 *
 * \param[in] dev The pointer to hardware instance
 * \return Operation status.
 * \retval 0  Operation is completed successfully
 */
int32_t _wdt_feed(struct wdt_dev *const dev);

#ifdef __cplusplus
}
#endif
/**@}*/
#endif /* _HPL_WDT_H_INCLUDED */
