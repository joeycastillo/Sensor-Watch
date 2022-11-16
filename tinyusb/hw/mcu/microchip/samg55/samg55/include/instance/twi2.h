/**
 * \file
 *
 * \brief Instance description for TWI2
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
#ifndef _SAMG55_TWI2_INSTANCE_H_
#define _SAMG55_TWI2_INSTANCE_H_

/* ========== Register definition for TWI2 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI2_CR             (0x40024600) /**< (TWI2) Control Register */
#define REG_TWI2_MMR            (0x40024604) /**< (TWI2) Master Mode Register */
#define REG_TWI2_SMR            (0x40024608) /**< (TWI2) Slave Mode Register */
#define REG_TWI2_IADR           (0x4002460C) /**< (TWI2) Internal Address Register */
#define REG_TWI2_CWGR           (0x40024610) /**< (TWI2) Clock Waveform Generator Register */
#define REG_TWI2_SR             (0x40024620) /**< (TWI2) Status Register */
#define REG_TWI2_IER            (0x40024624) /**< (TWI2) Interrupt Enable Register */
#define REG_TWI2_IDR            (0x40024628) /**< (TWI2) Interrupt Disable Register */
#define REG_TWI2_IMR            (0x4002462C) /**< (TWI2) Interrupt Mask Register */
#define REG_TWI2_RHR            (0x40024630) /**< (TWI2) Receive Holding Register */
#define REG_TWI2_THR            (0x40024634) /**< (TWI2) Transmit Holding Register */
#define REG_TWI2_SMBTR          (0x40024638) /**< (TWI2) SMBus Timing Register */
#define REG_TWI2_ACR            (0x40024640) /**< (TWI2) Alternative Command Register */
#define REG_TWI2_FILTR          (0x40024644) /**< (TWI2) Filter Register */
#define REG_TWI2_SWMR           (0x4002464C) /**< (TWI2) SleepWalking Matching Register */
#define REG_TWI2_WPMR           (0x400246E4) /**< (TWI2) Write Protection Mode Register */
#define REG_TWI2_WPSR           (0x400246E8) /**< (TWI2) Write Protection Status Register */
#define REG_TWI2_RPR            (0x40024700) /**< (TWI2) Receive Pointer Register */
#define REG_TWI2_RCR            (0x40024704) /**< (TWI2) Receive Counter Register */
#define REG_TWI2_TPR            (0x40024708) /**< (TWI2) Transmit Pointer Register */
#define REG_TWI2_TCR            (0x4002470C) /**< (TWI2) Transmit Counter Register */
#define REG_TWI2_RNPR           (0x40024710) /**< (TWI2) Receive Next Pointer Register */
#define REG_TWI2_RNCR           (0x40024714) /**< (TWI2) Receive Next Counter Register */
#define REG_TWI2_TNPR           (0x40024718) /**< (TWI2) Transmit Next Pointer Register */
#define REG_TWI2_TNCR           (0x4002471C) /**< (TWI2) Transmit Next Counter Register */
#define REG_TWI2_PTCR           (0x40024720) /**< (TWI2) Transfer Control Register */
#define REG_TWI2_PTSR           (0x40024724) /**< (TWI2) Transfer Status Register */

#else

#define REG_TWI2_CR             (*(__O  uint32_t*)0x40024600U) /**< (TWI2) Control Register */
#define REG_TWI2_MMR            (*(__IO uint32_t*)0x40024604U) /**< (TWI2) Master Mode Register */
#define REG_TWI2_SMR            (*(__IO uint32_t*)0x40024608U) /**< (TWI2) Slave Mode Register */
#define REG_TWI2_IADR           (*(__IO uint32_t*)0x4002460CU) /**< (TWI2) Internal Address Register */
#define REG_TWI2_CWGR           (*(__IO uint32_t*)0x40024610U) /**< (TWI2) Clock Waveform Generator Register */
#define REG_TWI2_SR             (*(__I  uint32_t*)0x40024620U) /**< (TWI2) Status Register */
#define REG_TWI2_IER            (*(__O  uint32_t*)0x40024624U) /**< (TWI2) Interrupt Enable Register */
#define REG_TWI2_IDR            (*(__O  uint32_t*)0x40024628U) /**< (TWI2) Interrupt Disable Register */
#define REG_TWI2_IMR            (*(__I  uint32_t*)0x4002462CU) /**< (TWI2) Interrupt Mask Register */
#define REG_TWI2_RHR            (*(__I  uint32_t*)0x40024630U) /**< (TWI2) Receive Holding Register */
#define REG_TWI2_THR            (*(__O  uint32_t*)0x40024634U) /**< (TWI2) Transmit Holding Register */
#define REG_TWI2_SMBTR          (*(__IO uint32_t*)0x40024638U) /**< (TWI2) SMBus Timing Register */
#define REG_TWI2_ACR            (*(__IO uint32_t*)0x40024640U) /**< (TWI2) Alternative Command Register */
#define REG_TWI2_FILTR          (*(__IO uint32_t*)0x40024644U) /**< (TWI2) Filter Register */
#define REG_TWI2_SWMR           (*(__IO uint32_t*)0x4002464CU) /**< (TWI2) SleepWalking Matching Register */
#define REG_TWI2_WPMR           (*(__IO uint32_t*)0x400246E4U) /**< (TWI2) Write Protection Mode Register */
#define REG_TWI2_WPSR           (*(__I  uint32_t*)0x400246E8U) /**< (TWI2) Write Protection Status Register */
#define REG_TWI2_RPR            (*(__IO uint32_t*)0x40024700U) /**< (TWI2) Receive Pointer Register */
#define REG_TWI2_RCR            (*(__IO uint32_t*)0x40024704U) /**< (TWI2) Receive Counter Register */
#define REG_TWI2_TPR            (*(__IO uint32_t*)0x40024708U) /**< (TWI2) Transmit Pointer Register */
#define REG_TWI2_TCR            (*(__IO uint32_t*)0x4002470CU) /**< (TWI2) Transmit Counter Register */
#define REG_TWI2_RNPR           (*(__IO uint32_t*)0x40024710U) /**< (TWI2) Receive Next Pointer Register */
#define REG_TWI2_RNCR           (*(__IO uint32_t*)0x40024714U) /**< (TWI2) Receive Next Counter Register */
#define REG_TWI2_TNPR           (*(__IO uint32_t*)0x40024718U) /**< (TWI2) Transmit Next Pointer Register */
#define REG_TWI2_TNCR           (*(__IO uint32_t*)0x4002471CU) /**< (TWI2) Transmit Next Counter Register */
#define REG_TWI2_PTCR           (*(__O  uint32_t*)0x40024720U) /**< (TWI2) Transfer Control Register */
#define REG_TWI2_PTSR           (*(__I  uint32_t*)0x40024724U) /**< (TWI2) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI2 peripheral ========== */
#define TWI2_DMAC_ID_TX                          22        
#define TWI2_DMAC_ID_RX                          8         

#endif /* _SAMG55_TWI2_INSTANCE_ */
