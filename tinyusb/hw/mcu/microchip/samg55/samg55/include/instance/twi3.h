/**
 * \file
 *
 * \brief Instance description for TWI3
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
#ifndef _SAMG55_TWI3_INSTANCE_H_
#define _SAMG55_TWI3_INSTANCE_H_

/* ========== Register definition for TWI3 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI3_CR             (0x40018600) /**< (TWI3) Control Register */
#define REG_TWI3_MMR            (0x40018604) /**< (TWI3) Master Mode Register */
#define REG_TWI3_SMR            (0x40018608) /**< (TWI3) Slave Mode Register */
#define REG_TWI3_IADR           (0x4001860C) /**< (TWI3) Internal Address Register */
#define REG_TWI3_CWGR           (0x40018610) /**< (TWI3) Clock Waveform Generator Register */
#define REG_TWI3_SR             (0x40018620) /**< (TWI3) Status Register */
#define REG_TWI3_IER            (0x40018624) /**< (TWI3) Interrupt Enable Register */
#define REG_TWI3_IDR            (0x40018628) /**< (TWI3) Interrupt Disable Register */
#define REG_TWI3_IMR            (0x4001862C) /**< (TWI3) Interrupt Mask Register */
#define REG_TWI3_RHR            (0x40018630) /**< (TWI3) Receive Holding Register */
#define REG_TWI3_THR            (0x40018634) /**< (TWI3) Transmit Holding Register */
#define REG_TWI3_SMBTR          (0x40018638) /**< (TWI3) SMBus Timing Register */
#define REG_TWI3_ACR            (0x40018640) /**< (TWI3) Alternative Command Register */
#define REG_TWI3_FILTR          (0x40018644) /**< (TWI3) Filter Register */
#define REG_TWI3_SWMR           (0x4001864C) /**< (TWI3) SleepWalking Matching Register */
#define REG_TWI3_WPMR           (0x400186E4) /**< (TWI3) Write Protection Mode Register */
#define REG_TWI3_WPSR           (0x400186E8) /**< (TWI3) Write Protection Status Register */
#define REG_TWI3_RPR            (0x40018700) /**< (TWI3) Receive Pointer Register */
#define REG_TWI3_RCR            (0x40018704) /**< (TWI3) Receive Counter Register */
#define REG_TWI3_TPR            (0x40018708) /**< (TWI3) Transmit Pointer Register */
#define REG_TWI3_TCR            (0x4001870C) /**< (TWI3) Transmit Counter Register */
#define REG_TWI3_RNPR           (0x40018710) /**< (TWI3) Receive Next Pointer Register */
#define REG_TWI3_RNCR           (0x40018714) /**< (TWI3) Receive Next Counter Register */
#define REG_TWI3_TNPR           (0x40018718) /**< (TWI3) Transmit Next Pointer Register */
#define REG_TWI3_TNCR           (0x4001871C) /**< (TWI3) Transmit Next Counter Register */
#define REG_TWI3_PTCR           (0x40018720) /**< (TWI3) Transfer Control Register */
#define REG_TWI3_PTSR           (0x40018724) /**< (TWI3) Transfer Status Register */

#else

#define REG_TWI3_CR             (*(__O  uint32_t*)0x40018600U) /**< (TWI3) Control Register */
#define REG_TWI3_MMR            (*(__IO uint32_t*)0x40018604U) /**< (TWI3) Master Mode Register */
#define REG_TWI3_SMR            (*(__IO uint32_t*)0x40018608U) /**< (TWI3) Slave Mode Register */
#define REG_TWI3_IADR           (*(__IO uint32_t*)0x4001860CU) /**< (TWI3) Internal Address Register */
#define REG_TWI3_CWGR           (*(__IO uint32_t*)0x40018610U) /**< (TWI3) Clock Waveform Generator Register */
#define REG_TWI3_SR             (*(__I  uint32_t*)0x40018620U) /**< (TWI3) Status Register */
#define REG_TWI3_IER            (*(__O  uint32_t*)0x40018624U) /**< (TWI3) Interrupt Enable Register */
#define REG_TWI3_IDR            (*(__O  uint32_t*)0x40018628U) /**< (TWI3) Interrupt Disable Register */
#define REG_TWI3_IMR            (*(__I  uint32_t*)0x4001862CU) /**< (TWI3) Interrupt Mask Register */
#define REG_TWI3_RHR            (*(__I  uint32_t*)0x40018630U) /**< (TWI3) Receive Holding Register */
#define REG_TWI3_THR            (*(__O  uint32_t*)0x40018634U) /**< (TWI3) Transmit Holding Register */
#define REG_TWI3_SMBTR          (*(__IO uint32_t*)0x40018638U) /**< (TWI3) SMBus Timing Register */
#define REG_TWI3_ACR            (*(__IO uint32_t*)0x40018640U) /**< (TWI3) Alternative Command Register */
#define REG_TWI3_FILTR          (*(__IO uint32_t*)0x40018644U) /**< (TWI3) Filter Register */
#define REG_TWI3_SWMR           (*(__IO uint32_t*)0x4001864CU) /**< (TWI3) SleepWalking Matching Register */
#define REG_TWI3_WPMR           (*(__IO uint32_t*)0x400186E4U) /**< (TWI3) Write Protection Mode Register */
#define REG_TWI3_WPSR           (*(__I  uint32_t*)0x400186E8U) /**< (TWI3) Write Protection Status Register */
#define REG_TWI3_RPR            (*(__IO uint32_t*)0x40018700U) /**< (TWI3) Receive Pointer Register */
#define REG_TWI3_RCR            (*(__IO uint32_t*)0x40018704U) /**< (TWI3) Receive Counter Register */
#define REG_TWI3_TPR            (*(__IO uint32_t*)0x40018708U) /**< (TWI3) Transmit Pointer Register */
#define REG_TWI3_TCR            (*(__IO uint32_t*)0x4001870CU) /**< (TWI3) Transmit Counter Register */
#define REG_TWI3_RNPR           (*(__IO uint32_t*)0x40018710U) /**< (TWI3) Receive Next Pointer Register */
#define REG_TWI3_RNCR           (*(__IO uint32_t*)0x40018714U) /**< (TWI3) Receive Next Counter Register */
#define REG_TWI3_TNPR           (*(__IO uint32_t*)0x40018718U) /**< (TWI3) Transmit Next Pointer Register */
#define REG_TWI3_TNCR           (*(__IO uint32_t*)0x4001871CU) /**< (TWI3) Transmit Next Counter Register */
#define REG_TWI3_PTCR           (*(__O  uint32_t*)0x40018720U) /**< (TWI3) Transfer Control Register */
#define REG_TWI3_PTSR           (*(__I  uint32_t*)0x40018724U) /**< (TWI3) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI3 peripheral ========== */
#define TWI3_DMAC_ID_TX                          17        
#define TWI3_DMAC_ID_RX                          0         

#endif /* _SAMG55_TWI3_INSTANCE_ */
