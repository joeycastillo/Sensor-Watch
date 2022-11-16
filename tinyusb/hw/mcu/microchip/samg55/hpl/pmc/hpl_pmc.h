/**
 * \file
 *
 * \brief Power Management Controller register vG related functionality.
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef _HPL_PMC_G_H_INCLUDED
#define _HPL_PMC_G_H_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initializes cortex M4 core clock
 *
 */
void _pmc_init(void);

/**
 * \brief Enable the specified peripheral clock.
 *
 * \note The ID must not be shifted (i.e., 1 << ID_xxx).
 *
 * \param periph_id Peripheral ID
 *
 */
static inline void _pmc_enable_periph_clock(uint32_t periph_id)
{
	if (periph_id < 32) {
		if (!hri_pmc_get_PCSR0_reg(PMC, (1 << periph_id))) {
			hri_pmc_set_PCSR0_reg(PMC, (1 << periph_id));
		}
	} else {
		periph_id -= 32;
		if (!hri_pmc_get_PCSR1_reg(PMC, (1 << periph_id))) {
			hri_pmc_set_PCSR1_reg(PMC, (1 << periph_id));
		}
	}
}

/**
 * \brief Disable the specified peripheral clock.
 *
 * \note The ID must not be shifted (i.e., 1 << ID_xxx).
 *
 * \param periph_id Peripheral ID
 *
 */
static inline void _pmc_disable_periph_clock(uint32_t periph_id)
{
	if (periph_id < 32) {
		if (hri_pmc_get_PCSR0_reg(PMC, (1 << periph_id))) {
			hri_pmc_clear_PCSR0_reg(PMC, (1 << periph_id));
		}
	} else {
		periph_id -= 32;
		if (hri_pmc_get_PCSR1_reg(PMC, (1 << periph_id))) {
			hri_pmc_clear_PCSR1_reg(PMC, (1 << periph_id));
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif /* _HPL_PMC_G_H_INCLUDED */
