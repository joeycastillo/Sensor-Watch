/**
 * \file
 *
 * \brief Instance description for TWI1
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
#ifndef _SAMG55_TWI1_INSTANCE_H_
#define _SAMG55_TWI1_INSTANCE_H_

/* ========== Register definition for TWI1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI1_CR             (0x40020600) /**< (TWI1) Control Register */
#define REG_TWI1_MMR            (0x40020604) /**< (TWI1) Master Mode Register */
#define REG_TWI1_SMR            (0x40020608) /**< (TWI1) Slave Mode Register */
#define REG_TWI1_IADR           (0x4002060C) /**< (TWI1) Internal Address Register */
#define REG_TWI1_CWGR           (0x40020610) /**< (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR             (0x40020620) /**< (TWI1) Status Register */
#define REG_TWI1_IER            (0x40020624) /**< (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR            (0x40020628) /**< (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR            (0x4002062C) /**< (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR            (0x40020630) /**< (TWI1) Receive Holding Register */
#define REG_TWI1_THR            (0x40020634) /**< (TWI1) Transmit Holding Register */
#define REG_TWI1_SMBTR          (0x40020638) /**< (TWI1) SMBus Timing Register */
#define REG_TWI1_ACR            (0x40020640) /**< (TWI1) Alternative Command Register */
#define REG_TWI1_FILTR          (0x40020644) /**< (TWI1) Filter Register */
#define REG_TWI1_SWMR           (0x4002064C) /**< (TWI1) SleepWalking Matching Register */
#define REG_TWI1_WPMR           (0x400206E4) /**< (TWI1) Write Protection Mode Register */
#define REG_TWI1_WPSR           (0x400206E8) /**< (TWI1) Write Protection Status Register */
#define REG_TWI1_RPR            (0x40020700) /**< (TWI1) Receive Pointer Register */
#define REG_TWI1_RCR            (0x40020704) /**< (TWI1) Receive Counter Register */
#define REG_TWI1_TPR            (0x40020708) /**< (TWI1) Transmit Pointer Register */
#define REG_TWI1_TCR            (0x4002070C) /**< (TWI1) Transmit Counter Register */
#define REG_TWI1_RNPR           (0x40020710) /**< (TWI1) Receive Next Pointer Register */
#define REG_TWI1_RNCR           (0x40020714) /**< (TWI1) Receive Next Counter Register */
#define REG_TWI1_TNPR           (0x40020718) /**< (TWI1) Transmit Next Pointer Register */
#define REG_TWI1_TNCR           (0x4002071C) /**< (TWI1) Transmit Next Counter Register */
#define REG_TWI1_PTCR           (0x40020720) /**< (TWI1) Transfer Control Register */
#define REG_TWI1_PTSR           (0x40020724) /**< (TWI1) Transfer Status Register */

#else

#define REG_TWI1_CR             (*(__O  uint32_t*)0x40020600U) /**< (TWI1) Control Register */
#define REG_TWI1_MMR            (*(__IO uint32_t*)0x40020604U) /**< (TWI1) Master Mode Register */
#define REG_TWI1_SMR            (*(__IO uint32_t*)0x40020608U) /**< (TWI1) Slave Mode Register */
#define REG_TWI1_IADR           (*(__IO uint32_t*)0x4002060CU) /**< (TWI1) Internal Address Register */
#define REG_TWI1_CWGR           (*(__IO uint32_t*)0x40020610U) /**< (TWI1) Clock Waveform Generator Register */
#define REG_TWI1_SR             (*(__I  uint32_t*)0x40020620U) /**< (TWI1) Status Register */
#define REG_TWI1_IER            (*(__O  uint32_t*)0x40020624U) /**< (TWI1) Interrupt Enable Register */
#define REG_TWI1_IDR            (*(__O  uint32_t*)0x40020628U) /**< (TWI1) Interrupt Disable Register */
#define REG_TWI1_IMR            (*(__I  uint32_t*)0x4002062CU) /**< (TWI1) Interrupt Mask Register */
#define REG_TWI1_RHR            (*(__I  uint32_t*)0x40020630U) /**< (TWI1) Receive Holding Register */
#define REG_TWI1_THR            (*(__O  uint32_t*)0x40020634U) /**< (TWI1) Transmit Holding Register */
#define REG_TWI1_SMBTR          (*(__IO uint32_t*)0x40020638U) /**< (TWI1) SMBus Timing Register */
#define REG_TWI1_ACR            (*(__IO uint32_t*)0x40020640U) /**< (TWI1) Alternative Command Register */
#define REG_TWI1_FILTR          (*(__IO uint32_t*)0x40020644U) /**< (TWI1) Filter Register */
#define REG_TWI1_SWMR           (*(__IO uint32_t*)0x4002064CU) /**< (TWI1) SleepWalking Matching Register */
#define REG_TWI1_WPMR           (*(__IO uint32_t*)0x400206E4U) /**< (TWI1) Write Protection Mode Register */
#define REG_TWI1_WPSR           (*(__I  uint32_t*)0x400206E8U) /**< (TWI1) Write Protection Status Register */
#define REG_TWI1_RPR            (*(__IO uint32_t*)0x40020700U) /**< (TWI1) Receive Pointer Register */
#define REG_TWI1_RCR            (*(__IO uint32_t*)0x40020704U) /**< (TWI1) Receive Counter Register */
#define REG_TWI1_TPR            (*(__IO uint32_t*)0x40020708U) /**< (TWI1) Transmit Pointer Register */
#define REG_TWI1_TCR            (*(__IO uint32_t*)0x4002070CU) /**< (TWI1) Transmit Counter Register */
#define REG_TWI1_RNPR           (*(__IO uint32_t*)0x40020710U) /**< (TWI1) Receive Next Pointer Register */
#define REG_TWI1_RNCR           (*(__IO uint32_t*)0x40020714U) /**< (TWI1) Receive Next Counter Register */
#define REG_TWI1_TNPR           (*(__IO uint32_t*)0x40020718U) /**< (TWI1) Transmit Next Pointer Register */
#define REG_TWI1_TNCR           (*(__IO uint32_t*)0x4002071CU) /**< (TWI1) Transmit Next Counter Register */
#define REG_TWI1_PTCR           (*(__O  uint32_t*)0x40020720U) /**< (TWI1) Transfer Control Register */
#define REG_TWI1_PTSR           (*(__I  uint32_t*)0x40020724U) /**< (TWI1) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI1 peripheral ========== */
#define TWI1_DMAC_ID_TX                          23        
#define TWI1_DMAC_ID_RX                          9         

#endif /* _SAMG55_TWI1_INSTANCE_ */
