/**
 * \file
 *
 * \brief Instance description for TWI5
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
#ifndef _SAMG55_TWI5_INSTANCE_H_
#define _SAMG55_TWI5_INSTANCE_H_

/* ========== Register definition for TWI5 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI5_CR             (0x40008600) /**< (TWI5) Control Register */
#define REG_TWI5_MMR            (0x40008604) /**< (TWI5) Master Mode Register */
#define REG_TWI5_SMR            (0x40008608) /**< (TWI5) Slave Mode Register */
#define REG_TWI5_IADR           (0x4000860C) /**< (TWI5) Internal Address Register */
#define REG_TWI5_CWGR           (0x40008610) /**< (TWI5) Clock Waveform Generator Register */
#define REG_TWI5_SR             (0x40008620) /**< (TWI5) Status Register */
#define REG_TWI5_IER            (0x40008624) /**< (TWI5) Interrupt Enable Register */
#define REG_TWI5_IDR            (0x40008628) /**< (TWI5) Interrupt Disable Register */
#define REG_TWI5_IMR            (0x4000862C) /**< (TWI5) Interrupt Mask Register */
#define REG_TWI5_RHR            (0x40008630) /**< (TWI5) Receive Holding Register */
#define REG_TWI5_THR            (0x40008634) /**< (TWI5) Transmit Holding Register */
#define REG_TWI5_SMBTR          (0x40008638) /**< (TWI5) SMBus Timing Register */
#define REG_TWI5_ACR            (0x40008640) /**< (TWI5) Alternative Command Register */
#define REG_TWI5_FILTR          (0x40008644) /**< (TWI5) Filter Register */
#define REG_TWI5_SWMR           (0x4000864C) /**< (TWI5) SleepWalking Matching Register */
#define REG_TWI5_WPMR           (0x400086E4) /**< (TWI5) Write Protection Mode Register */
#define REG_TWI5_WPSR           (0x400086E8) /**< (TWI5) Write Protection Status Register */
#define REG_TWI5_RPR            (0x40008700) /**< (TWI5) Receive Pointer Register */
#define REG_TWI5_RCR            (0x40008704) /**< (TWI5) Receive Counter Register */
#define REG_TWI5_TPR            (0x40008708) /**< (TWI5) Transmit Pointer Register */
#define REG_TWI5_TCR            (0x4000870C) /**< (TWI5) Transmit Counter Register */
#define REG_TWI5_RNPR           (0x40008710) /**< (TWI5) Receive Next Pointer Register */
#define REG_TWI5_RNCR           (0x40008714) /**< (TWI5) Receive Next Counter Register */
#define REG_TWI5_TNPR           (0x40008718) /**< (TWI5) Transmit Next Pointer Register */
#define REG_TWI5_TNCR           (0x4000871C) /**< (TWI5) Transmit Next Counter Register */
#define REG_TWI5_PTCR           (0x40008720) /**< (TWI5) Transfer Control Register */
#define REG_TWI5_PTSR           (0x40008724) /**< (TWI5) Transfer Status Register */

#else

#define REG_TWI5_CR             (*(__O  uint32_t*)0x40008600U) /**< (TWI5) Control Register */
#define REG_TWI5_MMR            (*(__IO uint32_t*)0x40008604U) /**< (TWI5) Master Mode Register */
#define REG_TWI5_SMR            (*(__IO uint32_t*)0x40008608U) /**< (TWI5) Slave Mode Register */
#define REG_TWI5_IADR           (*(__IO uint32_t*)0x4000860CU) /**< (TWI5) Internal Address Register */
#define REG_TWI5_CWGR           (*(__IO uint32_t*)0x40008610U) /**< (TWI5) Clock Waveform Generator Register */
#define REG_TWI5_SR             (*(__I  uint32_t*)0x40008620U) /**< (TWI5) Status Register */
#define REG_TWI5_IER            (*(__O  uint32_t*)0x40008624U) /**< (TWI5) Interrupt Enable Register */
#define REG_TWI5_IDR            (*(__O  uint32_t*)0x40008628U) /**< (TWI5) Interrupt Disable Register */
#define REG_TWI5_IMR            (*(__I  uint32_t*)0x4000862CU) /**< (TWI5) Interrupt Mask Register */
#define REG_TWI5_RHR            (*(__I  uint32_t*)0x40008630U) /**< (TWI5) Receive Holding Register */
#define REG_TWI5_THR            (*(__O  uint32_t*)0x40008634U) /**< (TWI5) Transmit Holding Register */
#define REG_TWI5_SMBTR          (*(__IO uint32_t*)0x40008638U) /**< (TWI5) SMBus Timing Register */
#define REG_TWI5_ACR            (*(__IO uint32_t*)0x40008640U) /**< (TWI5) Alternative Command Register */
#define REG_TWI5_FILTR          (*(__IO uint32_t*)0x40008644U) /**< (TWI5) Filter Register */
#define REG_TWI5_SWMR           (*(__IO uint32_t*)0x4000864CU) /**< (TWI5) SleepWalking Matching Register */
#define REG_TWI5_WPMR           (*(__IO uint32_t*)0x400086E4U) /**< (TWI5) Write Protection Mode Register */
#define REG_TWI5_WPSR           (*(__I  uint32_t*)0x400086E8U) /**< (TWI5) Write Protection Status Register */
#define REG_TWI5_RPR            (*(__IO uint32_t*)0x40008700U) /**< (TWI5) Receive Pointer Register */
#define REG_TWI5_RCR            (*(__IO uint32_t*)0x40008704U) /**< (TWI5) Receive Counter Register */
#define REG_TWI5_TPR            (*(__IO uint32_t*)0x40008708U) /**< (TWI5) Transmit Pointer Register */
#define REG_TWI5_TCR            (*(__IO uint32_t*)0x4000870CU) /**< (TWI5) Transmit Counter Register */
#define REG_TWI5_RNPR           (*(__IO uint32_t*)0x40008710U) /**< (TWI5) Receive Next Pointer Register */
#define REG_TWI5_RNCR           (*(__IO uint32_t*)0x40008714U) /**< (TWI5) Receive Next Counter Register */
#define REG_TWI5_TNPR           (*(__IO uint32_t*)0x40008718U) /**< (TWI5) Transmit Next Pointer Register */
#define REG_TWI5_TNCR           (*(__IO uint32_t*)0x4000871CU) /**< (TWI5) Transmit Next Counter Register */
#define REG_TWI5_PTCR           (*(__O  uint32_t*)0x40008720U) /**< (TWI5) Transfer Control Register */
#define REG_TWI5_PTSR           (*(__I  uint32_t*)0x40008724U) /**< (TWI5) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI5 peripheral ========== */
#define TWI5_DMAC_ID_TX                          27        
#define TWI5_DMAC_ID_RX                          13        

#endif /* _SAMG55_TWI5_INSTANCE_ */
