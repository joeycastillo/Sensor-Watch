/**
 * \file
 *
 * \brief SAM WDT
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
 */

#ifndef _HPL_WDT_BASE_H_INCLUDED
#define _HPL_WDT_BASE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief The register value of PER which SAMD21/SAMR21 supports
 */
enum wdt_period_reg {
	/** Corresponding to 8 clock cycles */
	WDT_PERIOD_8CYCLE,
	/** Corresponding to 16 clock cycles */
	WDT_PERIOD_16CYCLE,
	/** Corresponding to 32 clock cycles */
	WDT_PERIOD_32CYCLE,
	/** Corresponding to 64 clock cycles */
	WDT_PERIOD_64CYCLE,
	/** Corresponding to 128 clock cycles */
	WDT_PERIOD_128CYCLE,
	/** Corresponding to 256 clock cycles */
	WDT_PERIOD_256CYCLE,
	/** Corresponding to 512 clock cycles */
	WDT_PERIOD_512CYCLE,
	/** Corresponding to 1024 clock cycles */
	WDT_PERIOD_1024CYCLE,
	/** Corresponding to 2048 clock cycles */
	WDT_PERIOD_2048CYCLE,
	/** Corresponding to 4096 clock cycles */
	WDT_PERIOD_4096CYCLE,
	/** Corresponding to 8192 clock cycles */
	WDT_PERIOD_8192CYCLE,
	/** Corresponding to 16384 clock cycles */
	WDT_PERIOD_16384CYCLE
};
#ifdef __cplusplus
}
#endif
#endif /* _HPL_WDT_BASE_H_INCLUDED */
