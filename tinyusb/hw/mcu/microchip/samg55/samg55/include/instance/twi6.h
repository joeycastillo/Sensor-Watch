/**
 * \file
 *
 * \brief Instance description for TWI6
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
#ifndef _SAMG55_TWI6_INSTANCE_H_
#define _SAMG55_TWI6_INSTANCE_H_

/* ========== Register definition for TWI6 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI6_CR             (0x40040600) /**< (TWI6) Control Register */
#define REG_TWI6_MMR            (0x40040604) /**< (TWI6) Master Mode Register */
#define REG_TWI6_SMR            (0x40040608) /**< (TWI6) Slave Mode Register */
#define REG_TWI6_IADR           (0x4004060C) /**< (TWI6) Internal Address Register */
#define REG_TWI6_CWGR           (0x40040610) /**< (TWI6) Clock Waveform Generator Register */
#define REG_TWI6_SR             (0x40040620) /**< (TWI6) Status Register */
#define REG_TWI6_IER            (0x40040624) /**< (TWI6) Interrupt Enable Register */
#define REG_TWI6_IDR            (0x40040628) /**< (TWI6) Interrupt Disable Register */
#define REG_TWI6_IMR            (0x4004062C) /**< (TWI6) Interrupt Mask Register */
#define REG_TWI6_RHR            (0x40040630) /**< (TWI6) Receive Holding Register */
#define REG_TWI6_THR            (0x40040634) /**< (TWI6) Transmit Holding Register */
#define REG_TWI6_SMBTR          (0x40040638) /**< (TWI6) SMBus Timing Register */
#define REG_TWI6_ACR            (0x40040640) /**< (TWI6) Alternative Command Register */
#define REG_TWI6_FILTR          (0x40040644) /**< (TWI6) Filter Register */
#define REG_TWI6_SWMR           (0x4004064C) /**< (TWI6) SleepWalking Matching Register */
#define REG_TWI6_WPMR           (0x400406E4) /**< (TWI6) Write Protection Mode Register */
#define REG_TWI6_WPSR           (0x400406E8) /**< (TWI6) Write Protection Status Register */
#define REG_TWI6_RPR            (0x40040700) /**< (TWI6) Receive Pointer Register */
#define REG_TWI6_RCR            (0x40040704) /**< (TWI6) Receive Counter Register */
#define REG_TWI6_TPR            (0x40040708) /**< (TWI6) Transmit Pointer Register */
#define REG_TWI6_TCR            (0x4004070C) /**< (TWI6) Transmit Counter Register */
#define REG_TWI6_RNPR           (0x40040710) /**< (TWI6) Receive Next Pointer Register */
#define REG_TWI6_RNCR           (0x40040714) /**< (TWI6) Receive Next Counter Register */
#define REG_TWI6_TNPR           (0x40040718) /**< (TWI6) Transmit Next Pointer Register */
#define REG_TWI6_TNCR           (0x4004071C) /**< (TWI6) Transmit Next Counter Register */
#define REG_TWI6_PTCR           (0x40040720) /**< (TWI6) Transfer Control Register */
#define REG_TWI6_PTSR           (0x40040724) /**< (TWI6) Transfer Status Register */

#else

#define REG_TWI6_CR             (*(__O  uint32_t*)0x40040600U) /**< (TWI6) Control Register */
#define REG_TWI6_MMR            (*(__IO uint32_t*)0x40040604U) /**< (TWI6) Master Mode Register */
#define REG_TWI6_SMR            (*(__IO uint32_t*)0x40040608U) /**< (TWI6) Slave Mode Register */
#define REG_TWI6_IADR           (*(__IO uint32_t*)0x4004060CU) /**< (TWI6) Internal Address Register */
#define REG_TWI6_CWGR           (*(__IO uint32_t*)0x40040610U) /**< (TWI6) Clock Waveform Generator Register */
#define REG_TWI6_SR             (*(__I  uint32_t*)0x40040620U) /**< (TWI6) Status Register */
#define REG_TWI6_IER            (*(__O  uint32_t*)0x40040624U) /**< (TWI6) Interrupt Enable Register */
#define REG_TWI6_IDR            (*(__O  uint32_t*)0x40040628U) /**< (TWI6) Interrupt Disable Register */
#define REG_TWI6_IMR            (*(__I  uint32_t*)0x4004062CU) /**< (TWI6) Interrupt Mask Register */
#define REG_TWI6_RHR            (*(__I  uint32_t*)0x40040630U) /**< (TWI6) Receive Holding Register */
#define REG_TWI6_THR            (*(__O  uint32_t*)0x40040634U) /**< (TWI6) Transmit Holding Register */
#define REG_TWI6_SMBTR          (*(__IO uint32_t*)0x40040638U) /**< (TWI6) SMBus Timing Register */
#define REG_TWI6_ACR            (*(__IO uint32_t*)0x40040640U) /**< (TWI6) Alternative Command Register */
#define REG_TWI6_FILTR          (*(__IO uint32_t*)0x40040644U) /**< (TWI6) Filter Register */
#define REG_TWI6_SWMR           (*(__IO uint32_t*)0x4004064CU) /**< (TWI6) SleepWalking Matching Register */
#define REG_TWI6_WPMR           (*(__IO uint32_t*)0x400406E4U) /**< (TWI6) Write Protection Mode Register */
#define REG_TWI6_WPSR           (*(__I  uint32_t*)0x400406E8U) /**< (TWI6) Write Protection Status Register */
#define REG_TWI6_RPR            (*(__IO uint32_t*)0x40040700U) /**< (TWI6) Receive Pointer Register */
#define REG_TWI6_RCR            (*(__IO uint32_t*)0x40040704U) /**< (TWI6) Receive Counter Register */
#define REG_TWI6_TPR            (*(__IO uint32_t*)0x40040708U) /**< (TWI6) Transmit Pointer Register */
#define REG_TWI6_TCR            (*(__IO uint32_t*)0x4004070CU) /**< (TWI6) Transmit Counter Register */
#define REG_TWI6_RNPR           (*(__IO uint32_t*)0x40040710U) /**< (TWI6) Receive Next Pointer Register */
#define REG_TWI6_RNCR           (*(__IO uint32_t*)0x40040714U) /**< (TWI6) Receive Next Counter Register */
#define REG_TWI6_TNPR           (*(__IO uint32_t*)0x40040718U) /**< (TWI6) Transmit Next Pointer Register */
#define REG_TWI6_TNCR           (*(__IO uint32_t*)0x4004071CU) /**< (TWI6) Transmit Next Counter Register */
#define REG_TWI6_PTCR           (*(__O  uint32_t*)0x40040720U) /**< (TWI6) Transfer Control Register */
#define REG_TWI6_PTSR           (*(__I  uint32_t*)0x40040724U) /**< (TWI6) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI6 peripheral ========== */
#define TWI6_DMAC_ID_TX                          25        
#define TWI6_DMAC_ID_RX                          11        

#endif /* _SAMG55_TWI6_INSTANCE_ */
