/**
 * \file
 *
 * \brief Instance description for USART4
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
#ifndef _SAMG55_USART4_INSTANCE_H_
#define _SAMG55_USART4_INSTANCE_H_

/* ========== Register definition for USART4 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART4_US_CR        (0x4001C200) /**< (USART4) Control Register */
#define REG_USART4_US_MR        (0x4001C204) /**< (USART4) Mode Register */
#define REG_USART4_US_IER       (0x4001C208) /**< (USART4) Interrupt Enable Register */
#define REG_USART4_US_IDR       (0x4001C20C) /**< (USART4) Interrupt Disable Register */
#define REG_USART4_US_IMR       (0x4001C210) /**< (USART4) Interrupt Mask Register */
#define REG_USART4_US_CSR       (0x4001C214) /**< (USART4) Channel Status Register */
#define REG_USART4_US_RHR       (0x4001C218) /**< (USART4) Receive Holding Register */
#define REG_USART4_US_THR       (0x4001C21C) /**< (USART4) Transmit Holding Register */
#define REG_USART4_US_BRGR      (0x4001C220) /**< (USART4) Baud Rate Generator Register */
#define REG_USART4_US_RTOR      (0x4001C224) /**< (USART4) Receiver Time-out Register */
#define REG_USART4_US_TTGR      (0x4001C228) /**< (USART4) Transmitter Timeguard Register */
#define REG_USART4_US_FIDI      (0x4001C240) /**< (USART4) FI DI Ratio Register */
#define REG_USART4_US_NER       (0x4001C244) /**< (USART4) Number of Errors Register */
#define REG_USART4_US_IF        (0x4001C24C) /**< (USART4) IrDA Filter Register */
#define REG_USART4_US_LINMR     (0x4001C254) /**< (USART4) LIN Mode Register */
#define REG_USART4_US_LINIR     (0x4001C258) /**< (USART4) LIN Identifier Register */
#define REG_USART4_US_LINBRR    (0x4001C25C) /**< (USART4) LIN Baud Rate Register */
#define REG_USART4_US_CMPR      (0x4001C290) /**< (USART4) Comparison Register */
#define REG_USART4_US_WPMR      (0x4001C2E4) /**< (USART4) Write Protection Mode Register */
#define REG_USART4_US_WPSR      (0x4001C2E8) /**< (USART4) Write Protection Status Register */
#define REG_USART4_US_RPR       (0x4001C300) /**< (USART4) Receive Pointer Register */
#define REG_USART4_US_RCR       (0x4001C304) /**< (USART4) Receive Counter Register */
#define REG_USART4_US_TPR       (0x4001C308) /**< (USART4) Transmit Pointer Register */
#define REG_USART4_US_TCR       (0x4001C30C) /**< (USART4) Transmit Counter Register */
#define REG_USART4_US_RNPR      (0x4001C310) /**< (USART4) Receive Next Pointer Register */
#define REG_USART4_US_RNCR      (0x4001C314) /**< (USART4) Receive Next Counter Register */
#define REG_USART4_US_TNPR      (0x4001C318) /**< (USART4) Transmit Next Pointer Register */
#define REG_USART4_US_TNCR      (0x4001C31C) /**< (USART4) Transmit Next Counter Register */
#define REG_USART4_US_PTCR      (0x4001C320) /**< (USART4) Transfer Control Register */
#define REG_USART4_US_PTSR      (0x4001C324) /**< (USART4) Transfer Status Register */

#else

#define REG_USART4_US_CR        (*(__O  uint32_t*)0x4001C200U) /**< (USART4) Control Register */
#define REG_USART4_US_MR        (*(__IO uint32_t*)0x4001C204U) /**< (USART4) Mode Register */
#define REG_USART4_US_IER       (*(__O  uint32_t*)0x4001C208U) /**< (USART4) Interrupt Enable Register */
#define REG_USART4_US_IDR       (*(__O  uint32_t*)0x4001C20CU) /**< (USART4) Interrupt Disable Register */
#define REG_USART4_US_IMR       (*(__I  uint32_t*)0x4001C210U) /**< (USART4) Interrupt Mask Register */
#define REG_USART4_US_CSR       (*(__I  uint32_t*)0x4001C214U) /**< (USART4) Channel Status Register */
#define REG_USART4_US_RHR       (*(__I  uint32_t*)0x4001C218U) /**< (USART4) Receive Holding Register */
#define REG_USART4_US_THR       (*(__O  uint32_t*)0x4001C21CU) /**< (USART4) Transmit Holding Register */
#define REG_USART4_US_BRGR      (*(__IO uint32_t*)0x4001C220U) /**< (USART4) Baud Rate Generator Register */
#define REG_USART4_US_RTOR      (*(__IO uint32_t*)0x4001C224U) /**< (USART4) Receiver Time-out Register */
#define REG_USART4_US_TTGR      (*(__IO uint32_t*)0x4001C228U) /**< (USART4) Transmitter Timeguard Register */
#define REG_USART4_US_FIDI      (*(__IO uint32_t*)0x4001C240U) /**< (USART4) FI DI Ratio Register */
#define REG_USART4_US_NER       (*(__I  uint32_t*)0x4001C244U) /**< (USART4) Number of Errors Register */
#define REG_USART4_US_IF        (*(__IO uint32_t*)0x4001C24CU) /**< (USART4) IrDA Filter Register */
#define REG_USART4_US_LINMR     (*(__IO uint32_t*)0x4001C254U) /**< (USART4) LIN Mode Register */
#define REG_USART4_US_LINIR     (*(__IO uint32_t*)0x4001C258U) /**< (USART4) LIN Identifier Register */
#define REG_USART4_US_LINBRR    (*(__I  uint32_t*)0x4001C25CU) /**< (USART4) LIN Baud Rate Register */
#define REG_USART4_US_CMPR      (*(__IO uint32_t*)0x4001C290U) /**< (USART4) Comparison Register */
#define REG_USART4_US_WPMR      (*(__IO uint32_t*)0x4001C2E4U) /**< (USART4) Write Protection Mode Register */
#define REG_USART4_US_WPSR      (*(__I  uint32_t*)0x4001C2E8U) /**< (USART4) Write Protection Status Register */
#define REG_USART4_US_RPR       (*(__IO uint32_t*)0x4001C300U) /**< (USART4) Receive Pointer Register */
#define REG_USART4_US_RCR       (*(__IO uint32_t*)0x4001C304U) /**< (USART4) Receive Counter Register */
#define REG_USART4_US_TPR       (*(__IO uint32_t*)0x4001C308U) /**< (USART4) Transmit Pointer Register */
#define REG_USART4_US_TCR       (*(__IO uint32_t*)0x4001C30CU) /**< (USART4) Transmit Counter Register */
#define REG_USART4_US_RNPR      (*(__IO uint32_t*)0x4001C310U) /**< (USART4) Receive Next Pointer Register */
#define REG_USART4_US_RNCR      (*(__IO uint32_t*)0x4001C314U) /**< (USART4) Receive Next Counter Register */
#define REG_USART4_US_TNPR      (*(__IO uint32_t*)0x4001C318U) /**< (USART4) Transmit Next Pointer Register */
#define REG_USART4_US_TNCR      (*(__IO uint32_t*)0x4001C31CU) /**< (USART4) Transmit Next Counter Register */
#define REG_USART4_US_PTCR      (*(__O  uint32_t*)0x4001C320U) /**< (USART4) Transfer Control Register */
#define REG_USART4_US_PTSR      (*(__I  uint32_t*)0x4001C324U) /**< (USART4) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART4 peripheral ========== */
#define USART4_DMAC_ID_TX                        26        
#define USART4_DMAC_ID_RX                        12        

#endif /* _SAMG55_USART4_INSTANCE_ */
