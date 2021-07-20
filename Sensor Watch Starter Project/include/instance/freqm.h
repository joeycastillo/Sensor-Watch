/**
 * \file
 *
 * \brief Instance description for FREQM
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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

#ifndef _SAML22_FREQM_INSTANCE_
#define _SAML22_FREQM_INSTANCE_

/* ========== Register definition for FREQM peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_FREQM_CTRLA            (0x40002C00U) /**< \brief (FREQM) Control A Register */
#define REG_FREQM_CTRLB            (0x40002C01U) /**< \brief (FREQM) Control B Register */
#define REG_FREQM_CFGA             (0x40002C02U) /**< \brief (FREQM) Config A register */
#define REG_FREQM_INTENCLR         (0x40002C08U) /**< \brief (FREQM) Interrupt Enable Clear Register */
#define REG_FREQM_INTENSET         (0x40002C09U) /**< \brief (FREQM) Interrupt Enable Set Register */
#define REG_FREQM_INTFLAG          (0x40002C0AU) /**< \brief (FREQM) Interrupt Flag Register */
#define REG_FREQM_STATUS           (0x40002C0BU) /**< \brief (FREQM) Status Register */
#define REG_FREQM_SYNCBUSY         (0x40002C0CU) /**< \brief (FREQM) Synchronization Busy Register */
#define REG_FREQM_VALUE            (0x40002C10U) /**< \brief (FREQM) Count Value Register */
#else
#define REG_FREQM_CTRLA            (*(RwReg8 *)0x40002C00U) /**< \brief (FREQM) Control A Register */
#define REG_FREQM_CTRLB            (*(WoReg8 *)0x40002C01U) /**< \brief (FREQM) Control B Register */
#define REG_FREQM_CFGA             (*(RwReg16*)0x40002C02U) /**< \brief (FREQM) Config A register */
#define REG_FREQM_INTENCLR         (*(RwReg8 *)0x40002C08U) /**< \brief (FREQM) Interrupt Enable Clear Register */
#define REG_FREQM_INTENSET         (*(RwReg8 *)0x40002C09U) /**< \brief (FREQM) Interrupt Enable Set Register */
#define REG_FREQM_INTFLAG          (*(RwReg8 *)0x40002C0AU) /**< \brief (FREQM) Interrupt Flag Register */
#define REG_FREQM_STATUS           (*(RwReg8 *)0x40002C0BU) /**< \brief (FREQM) Status Register */
#define REG_FREQM_SYNCBUSY         (*(RoReg  *)0x40002C0CU) /**< \brief (FREQM) Synchronization Busy Register */
#define REG_FREQM_VALUE            (*(RoReg  *)0x40002C10U) /**< \brief (FREQM) Count Value Register */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for FREQM peripheral ========== */
#define FREQM_GCLK_ID_MSR           4        // Index of measure generic clock
#define FREQM_GCLK_ID_REF           5        // Index of reference generic clock

#endif /* _SAML22_FREQM_INSTANCE_ */
