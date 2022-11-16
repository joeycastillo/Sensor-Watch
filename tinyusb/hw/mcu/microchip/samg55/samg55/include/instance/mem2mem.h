/**
 * \file
 *
 * \brief Instance description for MEM2MEM
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
#ifndef _SAMG55_MEM2MEM_INSTANCE_H_
#define _SAMG55_MEM2MEM_INSTANCE_H_

/* ========== Register definition for MEM2MEM peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_MEM2MEM_THR         (0x40028000) /**< (MEM2MEM) Memory to Memory Transfer Holding Register */
#define REG_MEM2MEM_MR          (0x40028004) /**< (MEM2MEM) Memory to Memory Mode Register */
#define REG_MEM2MEM_IER         (0x40028008) /**< (MEM2MEM) Memory to Memory Interrupt Enable Register */
#define REG_MEM2MEM_IDR         (0x4002800C) /**< (MEM2MEM) Memory to Memory Interrupt Disable Register */
#define REG_MEM2MEM_IMR         (0x40028010) /**< (MEM2MEM) Memory to Memory Interrupt Mask Register */
#define REG_MEM2MEM_ISR         (0x40028014) /**< (MEM2MEM) Memory to Memory Interrupt Status Register */
#define REG_MEM2MEM_RPR         (0x40028100) /**< (MEM2MEM) Receive Pointer Register */
#define REG_MEM2MEM_RCR         (0x40028104) /**< (MEM2MEM) Receive Counter Register */
#define REG_MEM2MEM_TPR         (0x40028108) /**< (MEM2MEM) Transmit Pointer Register */
#define REG_MEM2MEM_TCR         (0x4002810C) /**< (MEM2MEM) Transmit Counter Register */
#define REG_MEM2MEM_RNPR        (0x40028110) /**< (MEM2MEM) Receive Next Pointer Register */
#define REG_MEM2MEM_RNCR        (0x40028114) /**< (MEM2MEM) Receive Next Counter Register */
#define REG_MEM2MEM_TNPR        (0x40028118) /**< (MEM2MEM) Transmit Next Pointer Register */
#define REG_MEM2MEM_TNCR        (0x4002811C) /**< (MEM2MEM) Transmit Next Counter Register */
#define REG_MEM2MEM_PTCR        (0x40028120) /**< (MEM2MEM) Transfer Control Register */
#define REG_MEM2MEM_PTSR        (0x40028124) /**< (MEM2MEM) Transfer Status Register */

#else

#define REG_MEM2MEM_THR         (*(__IO uint32_t*)0x40028000U) /**< (MEM2MEM) Memory to Memory Transfer Holding Register */
#define REG_MEM2MEM_MR          (*(__IO uint32_t*)0x40028004U) /**< (MEM2MEM) Memory to Memory Mode Register */
#define REG_MEM2MEM_IER         (*(__O  uint32_t*)0x40028008U) /**< (MEM2MEM) Memory to Memory Interrupt Enable Register */
#define REG_MEM2MEM_IDR         (*(__O  uint32_t*)0x4002800CU) /**< (MEM2MEM) Memory to Memory Interrupt Disable Register */
#define REG_MEM2MEM_IMR         (*(__I  uint32_t*)0x40028010U) /**< (MEM2MEM) Memory to Memory Interrupt Mask Register */
#define REG_MEM2MEM_ISR         (*(__I  uint32_t*)0x40028014U) /**< (MEM2MEM) Memory to Memory Interrupt Status Register */
#define REG_MEM2MEM_RPR         (*(__IO uint32_t*)0x40028100U) /**< (MEM2MEM) Receive Pointer Register */
#define REG_MEM2MEM_RCR         (*(__IO uint32_t*)0x40028104U) /**< (MEM2MEM) Receive Counter Register */
#define REG_MEM2MEM_TPR         (*(__IO uint32_t*)0x40028108U) /**< (MEM2MEM) Transmit Pointer Register */
#define REG_MEM2MEM_TCR         (*(__IO uint32_t*)0x4002810CU) /**< (MEM2MEM) Transmit Counter Register */
#define REG_MEM2MEM_RNPR        (*(__IO uint32_t*)0x40028110U) /**< (MEM2MEM) Receive Next Pointer Register */
#define REG_MEM2MEM_RNCR        (*(__IO uint32_t*)0x40028114U) /**< (MEM2MEM) Receive Next Counter Register */
#define REG_MEM2MEM_TNPR        (*(__IO uint32_t*)0x40028118U) /**< (MEM2MEM) Transmit Next Pointer Register */
#define REG_MEM2MEM_TNCR        (*(__IO uint32_t*)0x4002811CU) /**< (MEM2MEM) Transmit Next Counter Register */
#define REG_MEM2MEM_PTCR        (*(__O  uint32_t*)0x40028120U) /**< (MEM2MEM) Transfer Control Register */
#define REG_MEM2MEM_PTSR        (*(__I  uint32_t*)0x40028124U) /**< (MEM2MEM) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for MEM2MEM peripheral ========== */
#define MEM2MEM_INSTANCE_ID                      15        

#endif /* _SAMG55_MEM2MEM_INSTANCE_ */
