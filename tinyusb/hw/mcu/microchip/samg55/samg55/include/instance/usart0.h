/**
 * \file
 *
 * \brief Instance description for USART0
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
#ifndef _SAMG55_USART0_INSTANCE_H_
#define _SAMG55_USART0_INSTANCE_H_

/* ========== Register definition for USART0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART0_US_CR        (0x4000C200) /**< (USART0) Control Register */
#define REG_USART0_US_MR        (0x4000C204) /**< (USART0) Mode Register */
#define REG_USART0_US_IER       (0x4000C208) /**< (USART0) Interrupt Enable Register */
#define REG_USART0_US_IDR       (0x4000C20C) /**< (USART0) Interrupt Disable Register */
#define REG_USART0_US_IMR       (0x4000C210) /**< (USART0) Interrupt Mask Register */
#define REG_USART0_US_CSR       (0x4000C214) /**< (USART0) Channel Status Register */
#define REG_USART0_US_RHR       (0x4000C218) /**< (USART0) Receive Holding Register */
#define REG_USART0_US_THR       (0x4000C21C) /**< (USART0) Transmit Holding Register */
#define REG_USART0_US_BRGR      (0x4000C220) /**< (USART0) Baud Rate Generator Register */
#define REG_USART0_US_RTOR      (0x4000C224) /**< (USART0) Receiver Time-out Register */
#define REG_USART0_US_TTGR      (0x4000C228) /**< (USART0) Transmitter Timeguard Register */
#define REG_USART0_US_FIDI      (0x4000C240) /**< (USART0) FI DI Ratio Register */
#define REG_USART0_US_NER       (0x4000C244) /**< (USART0) Number of Errors Register */
#define REG_USART0_US_IF        (0x4000C24C) /**< (USART0) IrDA Filter Register */
#define REG_USART0_US_LINMR     (0x4000C254) /**< (USART0) LIN Mode Register */
#define REG_USART0_US_LINIR     (0x4000C258) /**< (USART0) LIN Identifier Register */
#define REG_USART0_US_LINBRR    (0x4000C25C) /**< (USART0) LIN Baud Rate Register */
#define REG_USART0_US_CMPR      (0x4000C290) /**< (USART0) Comparison Register */
#define REG_USART0_US_WPMR      (0x4000C2E4) /**< (USART0) Write Protection Mode Register */
#define REG_USART0_US_WPSR      (0x4000C2E8) /**< (USART0) Write Protection Status Register */
#define REG_USART0_US_RPR       (0x4000C300) /**< (USART0) Receive Pointer Register */
#define REG_USART0_US_RCR       (0x4000C304) /**< (USART0) Receive Counter Register */
#define REG_USART0_US_TPR       (0x4000C308) /**< (USART0) Transmit Pointer Register */
#define REG_USART0_US_TCR       (0x4000C30C) /**< (USART0) Transmit Counter Register */
#define REG_USART0_US_RNPR      (0x4000C310) /**< (USART0) Receive Next Pointer Register */
#define REG_USART0_US_RNCR      (0x4000C314) /**< (USART0) Receive Next Counter Register */
#define REG_USART0_US_TNPR      (0x4000C318) /**< (USART0) Transmit Next Pointer Register */
#define REG_USART0_US_TNCR      (0x4000C31C) /**< (USART0) Transmit Next Counter Register */
#define REG_USART0_US_PTCR      (0x4000C320) /**< (USART0) Transfer Control Register */
#define REG_USART0_US_PTSR      (0x4000C324) /**< (USART0) Transfer Status Register */

#else

#define REG_USART0_US_CR        (*(__O  uint32_t*)0x4000C200U) /**< (USART0) Control Register */
#define REG_USART0_US_MR        (*(__IO uint32_t*)0x4000C204U) /**< (USART0) Mode Register */
#define REG_USART0_US_IER       (*(__O  uint32_t*)0x4000C208U) /**< (USART0) Interrupt Enable Register */
#define REG_USART0_US_IDR       (*(__O  uint32_t*)0x4000C20CU) /**< (USART0) Interrupt Disable Register */
#define REG_USART0_US_IMR       (*(__I  uint32_t*)0x4000C210U) /**< (USART0) Interrupt Mask Register */
#define REG_USART0_US_CSR       (*(__I  uint32_t*)0x4000C214U) /**< (USART0) Channel Status Register */
#define REG_USART0_US_RHR       (*(__I  uint32_t*)0x4000C218U) /**< (USART0) Receive Holding Register */
#define REG_USART0_US_THR       (*(__O  uint32_t*)0x4000C21CU) /**< (USART0) Transmit Holding Register */
#define REG_USART0_US_BRGR      (*(__IO uint32_t*)0x4000C220U) /**< (USART0) Baud Rate Generator Register */
#define REG_USART0_US_RTOR      (*(__IO uint32_t*)0x4000C224U) /**< (USART0) Receiver Time-out Register */
#define REG_USART0_US_TTGR      (*(__IO uint32_t*)0x4000C228U) /**< (USART0) Transmitter Timeguard Register */
#define REG_USART0_US_FIDI      (*(__IO uint32_t*)0x4000C240U) /**< (USART0) FI DI Ratio Register */
#define REG_USART0_US_NER       (*(__I  uint32_t*)0x4000C244U) /**< (USART0) Number of Errors Register */
#define REG_USART0_US_IF        (*(__IO uint32_t*)0x4000C24CU) /**< (USART0) IrDA Filter Register */
#define REG_USART0_US_LINMR     (*(__IO uint32_t*)0x4000C254U) /**< (USART0) LIN Mode Register */
#define REG_USART0_US_LINIR     (*(__IO uint32_t*)0x4000C258U) /**< (USART0) LIN Identifier Register */
#define REG_USART0_US_LINBRR    (*(__I  uint32_t*)0x4000C25CU) /**< (USART0) LIN Baud Rate Register */
#define REG_USART0_US_CMPR      (*(__IO uint32_t*)0x4000C290U) /**< (USART0) Comparison Register */
#define REG_USART0_US_WPMR      (*(__IO uint32_t*)0x4000C2E4U) /**< (USART0) Write Protection Mode Register */
#define REG_USART0_US_WPSR      (*(__I  uint32_t*)0x4000C2E8U) /**< (USART0) Write Protection Status Register */
#define REG_USART0_US_RPR       (*(__IO uint32_t*)0x4000C300U) /**< (USART0) Receive Pointer Register */
#define REG_USART0_US_RCR       (*(__IO uint32_t*)0x4000C304U) /**< (USART0) Receive Counter Register */
#define REG_USART0_US_TPR       (*(__IO uint32_t*)0x4000C308U) /**< (USART0) Transmit Pointer Register */
#define REG_USART0_US_TCR       (*(__IO uint32_t*)0x4000C30CU) /**< (USART0) Transmit Counter Register */
#define REG_USART0_US_RNPR      (*(__IO uint32_t*)0x4000C310U) /**< (USART0) Receive Next Pointer Register */
#define REG_USART0_US_RNCR      (*(__IO uint32_t*)0x4000C314U) /**< (USART0) Receive Next Counter Register */
#define REG_USART0_US_TNPR      (*(__IO uint32_t*)0x4000C318U) /**< (USART0) Transmit Next Pointer Register */
#define REG_USART0_US_TNCR      (*(__IO uint32_t*)0x4000C31CU) /**< (USART0) Transmit Next Counter Register */
#define REG_USART0_US_PTCR      (*(__O  uint32_t*)0x4000C320U) /**< (USART0) Transfer Control Register */
#define REG_USART0_US_PTSR      (*(__I  uint32_t*)0x4000C324U) /**< (USART0) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART0 peripheral ========== */
#define USART0_DMAC_ID_TX                        24        
#define USART0_DMAC_ID_RX                        10        

#endif /* _SAMG55_USART0_INSTANCE_ */
