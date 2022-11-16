/**
 * \file
 *
 * \brief Instance description for TWI7
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
#ifndef _SAMG55_TWI7_INSTANCE_H_
#define _SAMG55_TWI7_INSTANCE_H_

/* ========== Register definition for TWI7 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI7_CR             (0x40034600) /**< (TWI7) Control Register */
#define REG_TWI7_MMR            (0x40034604) /**< (TWI7) Master Mode Register */
#define REG_TWI7_SMR            (0x40034608) /**< (TWI7) Slave Mode Register */
#define REG_TWI7_IADR           (0x4003460C) /**< (TWI7) Internal Address Register */
#define REG_TWI7_CWGR           (0x40034610) /**< (TWI7) Clock Waveform Generator Register */
#define REG_TWI7_SR             (0x40034620) /**< (TWI7) Status Register */
#define REG_TWI7_IER            (0x40034624) /**< (TWI7) Interrupt Enable Register */
#define REG_TWI7_IDR            (0x40034628) /**< (TWI7) Interrupt Disable Register */
#define REG_TWI7_IMR            (0x4003462C) /**< (TWI7) Interrupt Mask Register */
#define REG_TWI7_RHR            (0x40034630) /**< (TWI7) Receive Holding Register */
#define REG_TWI7_THR            (0x40034634) /**< (TWI7) Transmit Holding Register */
#define REG_TWI7_SMBTR          (0x40034638) /**< (TWI7) SMBus Timing Register */
#define REG_TWI7_ACR            (0x40034640) /**< (TWI7) Alternative Command Register */
#define REG_TWI7_FILTR          (0x40034644) /**< (TWI7) Filter Register */
#define REG_TWI7_SWMR           (0x4003464C) /**< (TWI7) SleepWalking Matching Register */
#define REG_TWI7_WPMR           (0x400346E4) /**< (TWI7) Write Protection Mode Register */
#define REG_TWI7_WPSR           (0x400346E8) /**< (TWI7) Write Protection Status Register */
#define REG_TWI7_RPR            (0x40034700) /**< (TWI7) Receive Pointer Register */
#define REG_TWI7_RCR            (0x40034704) /**< (TWI7) Receive Counter Register */
#define REG_TWI7_TPR            (0x40034708) /**< (TWI7) Transmit Pointer Register */
#define REG_TWI7_TCR            (0x4003470C) /**< (TWI7) Transmit Counter Register */
#define REG_TWI7_RNPR           (0x40034710) /**< (TWI7) Receive Next Pointer Register */
#define REG_TWI7_RNCR           (0x40034714) /**< (TWI7) Receive Next Counter Register */
#define REG_TWI7_TNPR           (0x40034718) /**< (TWI7) Transmit Next Pointer Register */
#define REG_TWI7_TNCR           (0x4003471C) /**< (TWI7) Transmit Next Counter Register */
#define REG_TWI7_PTCR           (0x40034720) /**< (TWI7) Transfer Control Register */
#define REG_TWI7_PTSR           (0x40034724) /**< (TWI7) Transfer Status Register */

#else

#define REG_TWI7_CR             (*(__O  uint32_t*)0x40034600U) /**< (TWI7) Control Register */
#define REG_TWI7_MMR            (*(__IO uint32_t*)0x40034604U) /**< (TWI7) Master Mode Register */
#define REG_TWI7_SMR            (*(__IO uint32_t*)0x40034608U) /**< (TWI7) Slave Mode Register */
#define REG_TWI7_IADR           (*(__IO uint32_t*)0x4003460CU) /**< (TWI7) Internal Address Register */
#define REG_TWI7_CWGR           (*(__IO uint32_t*)0x40034610U) /**< (TWI7) Clock Waveform Generator Register */
#define REG_TWI7_SR             (*(__I  uint32_t*)0x40034620U) /**< (TWI7) Status Register */
#define REG_TWI7_IER            (*(__O  uint32_t*)0x40034624U) /**< (TWI7) Interrupt Enable Register */
#define REG_TWI7_IDR            (*(__O  uint32_t*)0x40034628U) /**< (TWI7) Interrupt Disable Register */
#define REG_TWI7_IMR            (*(__I  uint32_t*)0x4003462CU) /**< (TWI7) Interrupt Mask Register */
#define REG_TWI7_RHR            (*(__I  uint32_t*)0x40034630U) /**< (TWI7) Receive Holding Register */
#define REG_TWI7_THR            (*(__O  uint32_t*)0x40034634U) /**< (TWI7) Transmit Holding Register */
#define REG_TWI7_SMBTR          (*(__IO uint32_t*)0x40034638U) /**< (TWI7) SMBus Timing Register */
#define REG_TWI7_ACR            (*(__IO uint32_t*)0x40034640U) /**< (TWI7) Alternative Command Register */
#define REG_TWI7_FILTR          (*(__IO uint32_t*)0x40034644U) /**< (TWI7) Filter Register */
#define REG_TWI7_SWMR           (*(__IO uint32_t*)0x4003464CU) /**< (TWI7) SleepWalking Matching Register */
#define REG_TWI7_WPMR           (*(__IO uint32_t*)0x400346E4U) /**< (TWI7) Write Protection Mode Register */
#define REG_TWI7_WPSR           (*(__I  uint32_t*)0x400346E8U) /**< (TWI7) Write Protection Status Register */
#define REG_TWI7_RPR            (*(__IO uint32_t*)0x40034700U) /**< (TWI7) Receive Pointer Register */
#define REG_TWI7_RCR            (*(__IO uint32_t*)0x40034704U) /**< (TWI7) Receive Counter Register */
#define REG_TWI7_TPR            (*(__IO uint32_t*)0x40034708U) /**< (TWI7) Transmit Pointer Register */
#define REG_TWI7_TCR            (*(__IO uint32_t*)0x4003470CU) /**< (TWI7) Transmit Counter Register */
#define REG_TWI7_RNPR           (*(__IO uint32_t*)0x40034710U) /**< (TWI7) Receive Next Pointer Register */
#define REG_TWI7_RNCR           (*(__IO uint32_t*)0x40034714U) /**< (TWI7) Receive Next Counter Register */
#define REG_TWI7_TNPR           (*(__IO uint32_t*)0x40034718U) /**< (TWI7) Transmit Next Pointer Register */
#define REG_TWI7_TNCR           (*(__IO uint32_t*)0x4003471CU) /**< (TWI7) Transmit Next Counter Register */
#define REG_TWI7_PTCR           (*(__O  uint32_t*)0x40034720U) /**< (TWI7) Transfer Control Register */
#define REG_TWI7_PTSR           (*(__I  uint32_t*)0x40034724U) /**< (TWI7) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI7 peripheral ========== */
#define TWI7_DMAC_ID_TX                          29        
#define TWI7_DMAC_ID_RX                          16        

#endif /* _SAMG55_TWI7_INSTANCE_ */
