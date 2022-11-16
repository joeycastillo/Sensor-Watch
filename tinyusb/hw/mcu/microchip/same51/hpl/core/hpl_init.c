/**
 * \file
 *
 * \brief HPL initialization related functionality implementation.
 *
 * Copyright (C) 2014-2017 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include <hpl_gpio.h>
#include <hpl_init.h>
#include <hpl_gclk_base.h>
#include <hpl_gclk_config.h>
#include <hpl_mclk_config.h>

#include <hpl_dma.h>
#include <hpl_dmac_config.h>

/* Referenced GCLKs, should be initialized firstly
*/
// CircuitPython: CIRCUITPY_GCLK_INIT_1ST is defined in asf4_conf/hpl_gclk_config.h
// to specify which clocks to initialize first.
#ifdef CIRCUITPY_GCLK_INIT_1ST
#define _GCLK_INIT_1ST CIRCUITPY_GCLK_INIT_1ST
#else
#warning No CIRCUITPY_GCLK_INIT_1ST defined!
#define _GCLK_INIT_1ST 0x0000
#endif

/* Not referenced GCLKs, initialized last */
#ifdef CIRCUITPY_GCLK_INIT_LAST
#define _GCLK_INIT_LAST CIRCUITPY_GCLK_INIT_LAST
#else
#define _GCLK_INIT_LAST (~_GCLK_INIT_1ST)
#endif

/**
 * \brief Initialize the hardware abstraction layer
 */
void _init_chip(void)
{

	hri_nvmctrl_set_CTRLA_RWS_bf(NVMCTRL, CONF_NVM_WAIT_STATE);

	_osc32kctrl_init_sources();
	_oscctrl_init_sources();
	_mclk_init();
#if _GCLK_INIT_1ST
	_gclk_init_generators_by_fref(_GCLK_INIT_1ST);
#endif
	_oscctrl_init_referenced_generators();
	_gclk_init_generators_by_fref(_GCLK_INIT_LAST);

#if CONF_DMAC_ENABLE
	hri_mclk_set_AHBMASK_DMAC_bit(MCLK);
	_dma_init();
#endif
}
