/**
 * \file
 *
 * \brief Instance description for TWI0
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
#ifndef _SAMG55_TWI0_INSTANCE_H_
#define _SAMG55_TWI0_INSTANCE_H_

/* ========== Register definition for TWI0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI0_CR             (0x4000C600) /**< (TWI0) Control Register */
#define REG_TWI0_MMR            (0x4000C604) /**< (TWI0) Master Mode Register */
#define REG_TWI0_SMR            (0x4000C608) /**< (TWI0) Slave Mode Register */
#define REG_TWI0_IADR           (0x4000C60C) /**< (TWI0) Internal Address Register */
#define REG_TWI0_CWGR           (0x4000C610) /**< (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR             (0x4000C620) /**< (TWI0) Status Register */
#define REG_TWI0_IER            (0x4000C624) /**< (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR            (0x4000C628) /**< (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR            (0x4000C62C) /**< (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR            (0x4000C630) /**< (TWI0) Receive Holding Register */
#define REG_TWI0_THR            (0x4000C634) /**< (TWI0) Transmit Holding Register */
#define REG_TWI0_SMBTR          (0x4000C638) /**< (TWI0) SMBus Timing Register */
#define REG_TWI0_ACR            (0x4000C640) /**< (TWI0) Alternative Command Register */
#define REG_TWI0_FILTR          (0x4000C644) /**< (TWI0) Filter Register */
#define REG_TWI0_SWMR           (0x4000C64C) /**< (TWI0) SleepWalking Matching Register */
#define REG_TWI0_WPMR           (0x4000C6E4) /**< (TWI0) Write Protection Mode Register */
#define REG_TWI0_WPSR           (0x4000C6E8) /**< (TWI0) Write Protection Status Register */
#define REG_TWI0_RPR            (0x4000C700) /**< (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR            (0x4000C704) /**< (TWI0) Receive Counter Register */
#define REG_TWI0_TPR            (0x4000C708) /**< (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR            (0x4000C70C) /**< (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR           (0x4000C710) /**< (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR           (0x4000C714) /**< (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR           (0x4000C718) /**< (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR           (0x4000C71C) /**< (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR           (0x4000C720) /**< (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR           (0x4000C724) /**< (TWI0) Transfer Status Register */

#else

#define REG_TWI0_CR             (*(__O  uint32_t*)0x4000C600U) /**< (TWI0) Control Register */
#define REG_TWI0_MMR            (*(__IO uint32_t*)0x4000C604U) /**< (TWI0) Master Mode Register */
#define REG_TWI0_SMR            (*(__IO uint32_t*)0x4000C608U) /**< (TWI0) Slave Mode Register */
#define REG_TWI0_IADR           (*(__IO uint32_t*)0x4000C60CU) /**< (TWI0) Internal Address Register */
#define REG_TWI0_CWGR           (*(__IO uint32_t*)0x4000C610U) /**< (TWI0) Clock Waveform Generator Register */
#define REG_TWI0_SR             (*(__I  uint32_t*)0x4000C620U) /**< (TWI0) Status Register */
#define REG_TWI0_IER            (*(__O  uint32_t*)0x4000C624U) /**< (TWI0) Interrupt Enable Register */
#define REG_TWI0_IDR            (*(__O  uint32_t*)0x4000C628U) /**< (TWI0) Interrupt Disable Register */
#define REG_TWI0_IMR            (*(__I  uint32_t*)0x4000C62CU) /**< (TWI0) Interrupt Mask Register */
#define REG_TWI0_RHR            (*(__I  uint32_t*)0x4000C630U) /**< (TWI0) Receive Holding Register */
#define REG_TWI0_THR            (*(__O  uint32_t*)0x4000C634U) /**< (TWI0) Transmit Holding Register */
#define REG_TWI0_SMBTR          (*(__IO uint32_t*)0x4000C638U) /**< (TWI0) SMBus Timing Register */
#define REG_TWI0_ACR            (*(__IO uint32_t*)0x4000C640U) /**< (TWI0) Alternative Command Register */
#define REG_TWI0_FILTR          (*(__IO uint32_t*)0x4000C644U) /**< (TWI0) Filter Register */
#define REG_TWI0_SWMR           (*(__IO uint32_t*)0x4000C64CU) /**< (TWI0) SleepWalking Matching Register */
#define REG_TWI0_WPMR           (*(__IO uint32_t*)0x4000C6E4U) /**< (TWI0) Write Protection Mode Register */
#define REG_TWI0_WPSR           (*(__I  uint32_t*)0x4000C6E8U) /**< (TWI0) Write Protection Status Register */
#define REG_TWI0_RPR            (*(__IO uint32_t*)0x4000C700U) /**< (TWI0) Receive Pointer Register */
#define REG_TWI0_RCR            (*(__IO uint32_t*)0x4000C704U) /**< (TWI0) Receive Counter Register */
#define REG_TWI0_TPR            (*(__IO uint32_t*)0x4000C708U) /**< (TWI0) Transmit Pointer Register */
#define REG_TWI0_TCR            (*(__IO uint32_t*)0x4000C70CU) /**< (TWI0) Transmit Counter Register */
#define REG_TWI0_RNPR           (*(__IO uint32_t*)0x4000C710U) /**< (TWI0) Receive Next Pointer Register */
#define REG_TWI0_RNCR           (*(__IO uint32_t*)0x4000C714U) /**< (TWI0) Receive Next Counter Register */
#define REG_TWI0_TNPR           (*(__IO uint32_t*)0x4000C718U) /**< (TWI0) Transmit Next Pointer Register */
#define REG_TWI0_TNCR           (*(__IO uint32_t*)0x4000C71CU) /**< (TWI0) Transmit Next Counter Register */
#define REG_TWI0_PTCR           (*(__O  uint32_t*)0x4000C720U) /**< (TWI0) Transfer Control Register */
#define REG_TWI0_PTSR           (*(__I  uint32_t*)0x4000C724U) /**< (TWI0) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI0 peripheral ========== */
#define TWI0_DMAC_ID_TX                          24        
#define TWI0_DMAC_ID_RX                          10        

#endif /* _SAMG55_TWI0_INSTANCE_ */
