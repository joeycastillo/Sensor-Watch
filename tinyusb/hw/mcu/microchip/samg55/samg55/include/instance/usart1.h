/**
 * \file
 *
 * \brief Instance description for USART1
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
#ifndef _SAMG55_USART1_INSTANCE_H_
#define _SAMG55_USART1_INSTANCE_H_

/* ========== Register definition for USART1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART1_US_CR        (0x40020200) /**< (USART1) Control Register */
#define REG_USART1_US_MR        (0x40020204) /**< (USART1) Mode Register */
#define REG_USART1_US_IER       (0x40020208) /**< (USART1) Interrupt Enable Register */
#define REG_USART1_US_IDR       (0x4002020C) /**< (USART1) Interrupt Disable Register */
#define REG_USART1_US_IMR       (0x40020210) /**< (USART1) Interrupt Mask Register */
#define REG_USART1_US_CSR       (0x40020214) /**< (USART1) Channel Status Register */
#define REG_USART1_US_RHR       (0x40020218) /**< (USART1) Receive Holding Register */
#define REG_USART1_US_THR       (0x4002021C) /**< (USART1) Transmit Holding Register */
#define REG_USART1_US_BRGR      (0x40020220) /**< (USART1) Baud Rate Generator Register */
#define REG_USART1_US_RTOR      (0x40020224) /**< (USART1) Receiver Time-out Register */
#define REG_USART1_US_TTGR      (0x40020228) /**< (USART1) Transmitter Timeguard Register */
#define REG_USART1_US_FIDI      (0x40020240) /**< (USART1) FI DI Ratio Register */
#define REG_USART1_US_NER       (0x40020244) /**< (USART1) Number of Errors Register */
#define REG_USART1_US_IF        (0x4002024C) /**< (USART1) IrDA Filter Register */
#define REG_USART1_US_LINMR     (0x40020254) /**< (USART1) LIN Mode Register */
#define REG_USART1_US_LINIR     (0x40020258) /**< (USART1) LIN Identifier Register */
#define REG_USART1_US_LINBRR    (0x4002025C) /**< (USART1) LIN Baud Rate Register */
#define REG_USART1_US_CMPR      (0x40020290) /**< (USART1) Comparison Register */
#define REG_USART1_US_WPMR      (0x400202E4) /**< (USART1) Write Protection Mode Register */
#define REG_USART1_US_WPSR      (0x400202E8) /**< (USART1) Write Protection Status Register */
#define REG_USART1_US_RPR       (0x40020300) /**< (USART1) Receive Pointer Register */
#define REG_USART1_US_RCR       (0x40020304) /**< (USART1) Receive Counter Register */
#define REG_USART1_US_TPR       (0x40020308) /**< (USART1) Transmit Pointer Register */
#define REG_USART1_US_TCR       (0x4002030C) /**< (USART1) Transmit Counter Register */
#define REG_USART1_US_RNPR      (0x40020310) /**< (USART1) Receive Next Pointer Register */
#define REG_USART1_US_RNCR      (0x40020314) /**< (USART1) Receive Next Counter Register */
#define REG_USART1_US_TNPR      (0x40020318) /**< (USART1) Transmit Next Pointer Register */
#define REG_USART1_US_TNCR      (0x4002031C) /**< (USART1) Transmit Next Counter Register */
#define REG_USART1_US_PTCR      (0x40020320) /**< (USART1) Transfer Control Register */
#define REG_USART1_US_PTSR      (0x40020324) /**< (USART1) Transfer Status Register */

#else

#define REG_USART1_US_CR        (*(__O  uint32_t*)0x40020200U) /**< (USART1) Control Register */
#define REG_USART1_US_MR        (*(__IO uint32_t*)0x40020204U) /**< (USART1) Mode Register */
#define REG_USART1_US_IER       (*(__O  uint32_t*)0x40020208U) /**< (USART1) Interrupt Enable Register */
#define REG_USART1_US_IDR       (*(__O  uint32_t*)0x4002020CU) /**< (USART1) Interrupt Disable Register */
#define REG_USART1_US_IMR       (*(__I  uint32_t*)0x40020210U) /**< (USART1) Interrupt Mask Register */
#define REG_USART1_US_CSR       (*(__I  uint32_t*)0x40020214U) /**< (USART1) Channel Status Register */
#define REG_USART1_US_RHR       (*(__I  uint32_t*)0x40020218U) /**< (USART1) Receive Holding Register */
#define REG_USART1_US_THR       (*(__O  uint32_t*)0x4002021CU) /**< (USART1) Transmit Holding Register */
#define REG_USART1_US_BRGR      (*(__IO uint32_t*)0x40020220U) /**< (USART1) Baud Rate Generator Register */
#define REG_USART1_US_RTOR      (*(__IO uint32_t*)0x40020224U) /**< (USART1) Receiver Time-out Register */
#define REG_USART1_US_TTGR      (*(__IO uint32_t*)0x40020228U) /**< (USART1) Transmitter Timeguard Register */
#define REG_USART1_US_FIDI      (*(__IO uint32_t*)0x40020240U) /**< (USART1) FI DI Ratio Register */
#define REG_USART1_US_NER       (*(__I  uint32_t*)0x40020244U) /**< (USART1) Number of Errors Register */
#define REG_USART1_US_IF        (*(__IO uint32_t*)0x4002024CU) /**< (USART1) IrDA Filter Register */
#define REG_USART1_US_LINMR     (*(__IO uint32_t*)0x40020254U) /**< (USART1) LIN Mode Register */
#define REG_USART1_US_LINIR     (*(__IO uint32_t*)0x40020258U) /**< (USART1) LIN Identifier Register */
#define REG_USART1_US_LINBRR    (*(__I  uint32_t*)0x4002025CU) /**< (USART1) LIN Baud Rate Register */
#define REG_USART1_US_CMPR      (*(__IO uint32_t*)0x40020290U) /**< (USART1) Comparison Register */
#define REG_USART1_US_WPMR      (*(__IO uint32_t*)0x400202E4U) /**< (USART1) Write Protection Mode Register */
#define REG_USART1_US_WPSR      (*(__I  uint32_t*)0x400202E8U) /**< (USART1) Write Protection Status Register */
#define REG_USART1_US_RPR       (*(__IO uint32_t*)0x40020300U) /**< (USART1) Receive Pointer Register */
#define REG_USART1_US_RCR       (*(__IO uint32_t*)0x40020304U) /**< (USART1) Receive Counter Register */
#define REG_USART1_US_TPR       (*(__IO uint32_t*)0x40020308U) /**< (USART1) Transmit Pointer Register */
#define REG_USART1_US_TCR       (*(__IO uint32_t*)0x4002030CU) /**< (USART1) Transmit Counter Register */
#define REG_USART1_US_RNPR      (*(__IO uint32_t*)0x40020310U) /**< (USART1) Receive Next Pointer Register */
#define REG_USART1_US_RNCR      (*(__IO uint32_t*)0x40020314U) /**< (USART1) Receive Next Counter Register */
#define REG_USART1_US_TNPR      (*(__IO uint32_t*)0x40020318U) /**< (USART1) Transmit Next Pointer Register */
#define REG_USART1_US_TNCR      (*(__IO uint32_t*)0x4002031CU) /**< (USART1) Transmit Next Counter Register */
#define REG_USART1_US_PTCR      (*(__O  uint32_t*)0x40020320U) /**< (USART1) Transfer Control Register */
#define REG_USART1_US_PTSR      (*(__I  uint32_t*)0x40020324U) /**< (USART1) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART1 peripheral ========== */
#define USART1_DMAC_ID_TX                        23        
#define USART1_DMAC_ID_RX                        9         

#endif /* _SAMG55_USART1_INSTANCE_ */
