/**
 * \file
 *
 * \brief Instance description for TWI4
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
#ifndef _SAMG55_TWI4_INSTANCE_H_
#define _SAMG55_TWI4_INSTANCE_H_

/* ========== Register definition for TWI4 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_TWI4_CR             (0x4001C600) /**< (TWI4) Control Register */
#define REG_TWI4_MMR            (0x4001C604) /**< (TWI4) Master Mode Register */
#define REG_TWI4_SMR            (0x4001C608) /**< (TWI4) Slave Mode Register */
#define REG_TWI4_IADR           (0x4001C60C) /**< (TWI4) Internal Address Register */
#define REG_TWI4_CWGR           (0x4001C610) /**< (TWI4) Clock Waveform Generator Register */
#define REG_TWI4_SR             (0x4001C620) /**< (TWI4) Status Register */
#define REG_TWI4_IER            (0x4001C624) /**< (TWI4) Interrupt Enable Register */
#define REG_TWI4_IDR            (0x4001C628) /**< (TWI4) Interrupt Disable Register */
#define REG_TWI4_IMR            (0x4001C62C) /**< (TWI4) Interrupt Mask Register */
#define REG_TWI4_RHR            (0x4001C630) /**< (TWI4) Receive Holding Register */
#define REG_TWI4_THR            (0x4001C634) /**< (TWI4) Transmit Holding Register */
#define REG_TWI4_SMBTR          (0x4001C638) /**< (TWI4) SMBus Timing Register */
#define REG_TWI4_ACR            (0x4001C640) /**< (TWI4) Alternative Command Register */
#define REG_TWI4_FILTR          (0x4001C644) /**< (TWI4) Filter Register */
#define REG_TWI4_SWMR           (0x4001C64C) /**< (TWI4) SleepWalking Matching Register */
#define REG_TWI4_WPMR           (0x4001C6E4) /**< (TWI4) Write Protection Mode Register */
#define REG_TWI4_WPSR           (0x4001C6E8) /**< (TWI4) Write Protection Status Register */
#define REG_TWI4_RPR            (0x4001C700) /**< (TWI4) Receive Pointer Register */
#define REG_TWI4_RCR            (0x4001C704) /**< (TWI4) Receive Counter Register */
#define REG_TWI4_TPR            (0x4001C708) /**< (TWI4) Transmit Pointer Register */
#define REG_TWI4_TCR            (0x4001C70C) /**< (TWI4) Transmit Counter Register */
#define REG_TWI4_RNPR           (0x4001C710) /**< (TWI4) Receive Next Pointer Register */
#define REG_TWI4_RNCR           (0x4001C714) /**< (TWI4) Receive Next Counter Register */
#define REG_TWI4_TNPR           (0x4001C718) /**< (TWI4) Transmit Next Pointer Register */
#define REG_TWI4_TNCR           (0x4001C71C) /**< (TWI4) Transmit Next Counter Register */
#define REG_TWI4_PTCR           (0x4001C720) /**< (TWI4) Transfer Control Register */
#define REG_TWI4_PTSR           (0x4001C724) /**< (TWI4) Transfer Status Register */

#else

#define REG_TWI4_CR             (*(__O  uint32_t*)0x4001C600U) /**< (TWI4) Control Register */
#define REG_TWI4_MMR            (*(__IO uint32_t*)0x4001C604U) /**< (TWI4) Master Mode Register */
#define REG_TWI4_SMR            (*(__IO uint32_t*)0x4001C608U) /**< (TWI4) Slave Mode Register */
#define REG_TWI4_IADR           (*(__IO uint32_t*)0x4001C60CU) /**< (TWI4) Internal Address Register */
#define REG_TWI4_CWGR           (*(__IO uint32_t*)0x4001C610U) /**< (TWI4) Clock Waveform Generator Register */
#define REG_TWI4_SR             (*(__I  uint32_t*)0x4001C620U) /**< (TWI4) Status Register */
#define REG_TWI4_IER            (*(__O  uint32_t*)0x4001C624U) /**< (TWI4) Interrupt Enable Register */
#define REG_TWI4_IDR            (*(__O  uint32_t*)0x4001C628U) /**< (TWI4) Interrupt Disable Register */
#define REG_TWI4_IMR            (*(__I  uint32_t*)0x4001C62CU) /**< (TWI4) Interrupt Mask Register */
#define REG_TWI4_RHR            (*(__I  uint32_t*)0x4001C630U) /**< (TWI4) Receive Holding Register */
#define REG_TWI4_THR            (*(__O  uint32_t*)0x4001C634U) /**< (TWI4) Transmit Holding Register */
#define REG_TWI4_SMBTR          (*(__IO uint32_t*)0x4001C638U) /**< (TWI4) SMBus Timing Register */
#define REG_TWI4_ACR            (*(__IO uint32_t*)0x4001C640U) /**< (TWI4) Alternative Command Register */
#define REG_TWI4_FILTR          (*(__IO uint32_t*)0x4001C644U) /**< (TWI4) Filter Register */
#define REG_TWI4_SWMR           (*(__IO uint32_t*)0x4001C64CU) /**< (TWI4) SleepWalking Matching Register */
#define REG_TWI4_WPMR           (*(__IO uint32_t*)0x4001C6E4U) /**< (TWI4) Write Protection Mode Register */
#define REG_TWI4_WPSR           (*(__I  uint32_t*)0x4001C6E8U) /**< (TWI4) Write Protection Status Register */
#define REG_TWI4_RPR            (*(__IO uint32_t*)0x4001C700U) /**< (TWI4) Receive Pointer Register */
#define REG_TWI4_RCR            (*(__IO uint32_t*)0x4001C704U) /**< (TWI4) Receive Counter Register */
#define REG_TWI4_TPR            (*(__IO uint32_t*)0x4001C708U) /**< (TWI4) Transmit Pointer Register */
#define REG_TWI4_TCR            (*(__IO uint32_t*)0x4001C70CU) /**< (TWI4) Transmit Counter Register */
#define REG_TWI4_RNPR           (*(__IO uint32_t*)0x4001C710U) /**< (TWI4) Receive Next Pointer Register */
#define REG_TWI4_RNCR           (*(__IO uint32_t*)0x4001C714U) /**< (TWI4) Receive Next Counter Register */
#define REG_TWI4_TNPR           (*(__IO uint32_t*)0x4001C718U) /**< (TWI4) Transmit Next Pointer Register */
#define REG_TWI4_TNCR           (*(__IO uint32_t*)0x4001C71CU) /**< (TWI4) Transmit Next Counter Register */
#define REG_TWI4_PTCR           (*(__O  uint32_t*)0x4001C720U) /**< (TWI4) Transfer Control Register */
#define REG_TWI4_PTSR           (*(__I  uint32_t*)0x4001C724U) /**< (TWI4) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for TWI4 peripheral ========== */
#define TWI4_DMAC_ID_TX                          26        
#define TWI4_DMAC_ID_RX                          12        

#endif /* _SAMG55_TWI4_INSTANCE_ */
