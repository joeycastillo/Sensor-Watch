/**
 * \file
 *
 * \brief Instance description for PDMIC1
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
#ifndef _SAMG55_PDMIC1_INSTANCE_H_
#define _SAMG55_PDMIC1_INSTANCE_H_

/* ========== Register definition for PDMIC1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_PDMIC1_CR           (0x40030000) /**< (PDMIC1) Control Register */
#define REG_PDMIC1_MR           (0x40030004) /**< (PDMIC1) Mode Register */
#define REG_PDMIC1_CDR          (0x40030014) /**< (PDMIC1) Converted Data Register */
#define REG_PDMIC1_IER          (0x40030018) /**< (PDMIC1) Interrupt Enable Register */
#define REG_PDMIC1_IDR          (0x4003001C) /**< (PDMIC1) Interrupt Disable Register */
#define REG_PDMIC1_IMR          (0x40030020) /**< (PDMIC1) Interrupt Mask Register */
#define REG_PDMIC1_ISR          (0x40030024) /**< (PDMIC1) Interrupt Status Register */
#define REG_PDMIC1_DSPR0        (0x40030058) /**< (PDMIC1) DSP Configuration Register 0 */
#define REG_PDMIC1_DSPR1        (0x4003005C) /**< (PDMIC1) DSP Configuration Register 1 */
#define REG_PDMIC1_WPMR         (0x400300E4) /**< (PDMIC1) Write Protection Mode Register */
#define REG_PDMIC1_WPSR         (0x400300E8) /**< (PDMIC1) Write Protection Status Register */
#define REG_PDMIC1_RPR          (0x40030100) /**< (PDMIC1) Receive Pointer Register */
#define REG_PDMIC1_RCR          (0x40030104) /**< (PDMIC1) Receive Counter Register */
#define REG_PDMIC1_RNPR         (0x40030110) /**< (PDMIC1) Receive Next Pointer Register */
#define REG_PDMIC1_RNCR         (0x40030114) /**< (PDMIC1) Receive Next Counter Register */
#define REG_PDMIC1_PTCR         (0x40030120) /**< (PDMIC1) Transfer Control Register */
#define REG_PDMIC1_PTSR         (0x40030124) /**< (PDMIC1) Transfer Status Register */

#else

#define REG_PDMIC1_CR           (*(__IO uint32_t*)0x40030000U) /**< (PDMIC1) Control Register */
#define REG_PDMIC1_MR           (*(__IO uint32_t*)0x40030004U) /**< (PDMIC1) Mode Register */
#define REG_PDMIC1_CDR          (*(__I  uint32_t*)0x40030014U) /**< (PDMIC1) Converted Data Register */
#define REG_PDMIC1_IER          (*(__O  uint32_t*)0x40030018U) /**< (PDMIC1) Interrupt Enable Register */
#define REG_PDMIC1_IDR          (*(__O  uint32_t*)0x4003001CU) /**< (PDMIC1) Interrupt Disable Register */
#define REG_PDMIC1_IMR          (*(__I  uint32_t*)0x40030020U) /**< (PDMIC1) Interrupt Mask Register */
#define REG_PDMIC1_ISR          (*(__I  uint32_t*)0x40030024U) /**< (PDMIC1) Interrupt Status Register */
#define REG_PDMIC1_DSPR0        (*(__IO uint32_t*)0x40030058U) /**< (PDMIC1) DSP Configuration Register 0 */
#define REG_PDMIC1_DSPR1        (*(__IO uint32_t*)0x4003005CU) /**< (PDMIC1) DSP Configuration Register 1 */
#define REG_PDMIC1_WPMR         (*(__IO uint32_t*)0x400300E4U) /**< (PDMIC1) Write Protection Mode Register */
#define REG_PDMIC1_WPSR         (*(__I  uint32_t*)0x400300E8U) /**< (PDMIC1) Write Protection Status Register */
#define REG_PDMIC1_RPR          (*(__IO uint32_t*)0x40030100U) /**< (PDMIC1) Receive Pointer Register */
#define REG_PDMIC1_RCR          (*(__IO uint32_t*)0x40030104U) /**< (PDMIC1) Receive Counter Register */
#define REG_PDMIC1_RNPR         (*(__IO uint32_t*)0x40030110U) /**< (PDMIC1) Receive Next Pointer Register */
#define REG_PDMIC1_RNCR         (*(__IO uint32_t*)0x40030114U) /**< (PDMIC1) Receive Next Counter Register */
#define REG_PDMIC1_PTCR         (*(__O  uint32_t*)0x40030120U) /**< (PDMIC1) Transfer Control Register */
#define REG_PDMIC1_PTSR         (*(__I  uint32_t*)0x40030124U) /**< (PDMIC1) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for PDMIC1 peripheral ========== */
#define PDMIC1_INSTANCE_ID                       18        

#endif /* _SAMG55_PDMIC1_INSTANCE_ */
