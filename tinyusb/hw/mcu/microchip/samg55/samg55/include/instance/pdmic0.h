/**
 * \file
 *
 * \brief Instance description for PDMIC0
 *
 * Copyright (c) 2017 Atmel Corporation, a wholly owned subsidiary of Microchip Technology Inc.
 *
 * \license_start
 *
 * \page License
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \license_stop
 *
 */

/* file generated from device description version 2017-07-05T18:00:00Z */
#ifndef _SAMG55_PDMIC0_INSTANCE_H_
#define _SAMG55_PDMIC0_INSTANCE_H_

/* ========== Register definition for PDMIC0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_PDMIC0_CR           (0x4002C000) /**< (PDMIC0) Control Register */
#define REG_PDMIC0_MR           (0x4002C004) /**< (PDMIC0) Mode Register */
#define REG_PDMIC0_CDR          (0x4002C014) /**< (PDMIC0) Converted Data Register */
#define REG_PDMIC0_IER          (0x4002C018) /**< (PDMIC0) Interrupt Enable Register */
#define REG_PDMIC0_IDR          (0x4002C01C) /**< (PDMIC0) Interrupt Disable Register */
#define REG_PDMIC0_IMR          (0x4002C020) /**< (PDMIC0) Interrupt Mask Register */
#define REG_PDMIC0_ISR          (0x4002C024) /**< (PDMIC0) Interrupt Status Register */
#define REG_PDMIC0_DSPR0        (0x4002C058) /**< (PDMIC0) DSP Configuration Register 0 */
#define REG_PDMIC0_DSPR1        (0x4002C05C) /**< (PDMIC0) DSP Configuration Register 1 */
#define REG_PDMIC0_WPMR         (0x4002C0E4) /**< (PDMIC0) Write Protection Mode Register */
#define REG_PDMIC0_WPSR         (0x4002C0E8) /**< (PDMIC0) Write Protection Status Register */
#define REG_PDMIC0_RPR          (0x4002C100) /**< (PDMIC0) Receive Pointer Register */
#define REG_PDMIC0_RCR          (0x4002C104) /**< (PDMIC0) Receive Counter Register */
#define REG_PDMIC0_RNPR         (0x4002C110) /**< (PDMIC0) Receive Next Pointer Register */
#define REG_PDMIC0_RNCR         (0x4002C114) /**< (PDMIC0) Receive Next Counter Register */
#define REG_PDMIC0_PTCR         (0x4002C120) /**< (PDMIC0) Transfer Control Register */
#define REG_PDMIC0_PTSR         (0x4002C124) /**< (PDMIC0) Transfer Status Register */

#else

#define REG_PDMIC0_CR           (*(__IO uint32_t*)0x4002C000U) /**< (PDMIC0) Control Register */
#define REG_PDMIC0_MR           (*(__IO uint32_t*)0x4002C004U) /**< (PDMIC0) Mode Register */
#define REG_PDMIC0_CDR          (*(__I  uint32_t*)0x4002C014U) /**< (PDMIC0) Converted Data Register */
#define REG_PDMIC0_IER          (*(__O  uint32_t*)0x4002C018U) /**< (PDMIC0) Interrupt Enable Register */
#define REG_PDMIC0_IDR          (*(__O  uint32_t*)0x4002C01CU) /**< (PDMIC0) Interrupt Disable Register */
#define REG_PDMIC0_IMR          (*(__I  uint32_t*)0x4002C020U) /**< (PDMIC0) Interrupt Mask Register */
#define REG_PDMIC0_ISR          (*(__I  uint32_t*)0x4002C024U) /**< (PDMIC0) Interrupt Status Register */
#define REG_PDMIC0_DSPR0        (*(__IO uint32_t*)0x4002C058U) /**< (PDMIC0) DSP Configuration Register 0 */
#define REG_PDMIC0_DSPR1        (*(__IO uint32_t*)0x4002C05CU) /**< (PDMIC0) DSP Configuration Register 1 */
#define REG_PDMIC0_WPMR         (*(__IO uint32_t*)0x4002C0E4U) /**< (PDMIC0) Write Protection Mode Register */
#define REG_PDMIC0_WPSR         (*(__I  uint32_t*)0x4002C0E8U) /**< (PDMIC0) Write Protection Status Register */
#define REG_PDMIC0_RPR          (*(__IO uint32_t*)0x4002C100U) /**< (PDMIC0) Receive Pointer Register */
#define REG_PDMIC0_RCR          (*(__IO uint32_t*)0x4002C104U) /**< (PDMIC0) Receive Counter Register */
#define REG_PDMIC0_RNPR         (*(__IO uint32_t*)0x4002C110U) /**< (PDMIC0) Receive Next Pointer Register */
#define REG_PDMIC0_RNCR         (*(__IO uint32_t*)0x4002C114U) /**< (PDMIC0) Receive Next Counter Register */
#define REG_PDMIC0_PTCR         (*(__O  uint32_t*)0x4002C120U) /**< (PDMIC0) Transfer Control Register */
#define REG_PDMIC0_PTSR         (*(__I  uint32_t*)0x4002C124U) /**< (PDMIC0) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for PDMIC0 peripheral ========== */
#define PDMIC0_INSTANCE_ID                       13        
#define PDMIC0_DMAC_ID_RX                        6         

#endif /* _SAMG55_PDMIC0_INSTANCE_ */
