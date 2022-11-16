/**
 * \file
 *
 * \brief Instance description for USART6
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
#ifndef _SAMG55_USART6_INSTANCE_H_
#define _SAMG55_USART6_INSTANCE_H_

/* ========== Register definition for USART6 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART6_US_CR        (0x40040200) /**< (USART6) Control Register */
#define REG_USART6_US_MR        (0x40040204) /**< (USART6) Mode Register */
#define REG_USART6_US_IER       (0x40040208) /**< (USART6) Interrupt Enable Register */
#define REG_USART6_US_IDR       (0x4004020C) /**< (USART6) Interrupt Disable Register */
#define REG_USART6_US_IMR       (0x40040210) /**< (USART6) Interrupt Mask Register */
#define REG_USART6_US_CSR       (0x40040214) /**< (USART6) Channel Status Register */
#define REG_USART6_US_RHR       (0x40040218) /**< (USART6) Receive Holding Register */
#define REG_USART6_US_THR       (0x4004021C) /**< (USART6) Transmit Holding Register */
#define REG_USART6_US_BRGR      (0x40040220) /**< (USART6) Baud Rate Generator Register */
#define REG_USART6_US_RTOR      (0x40040224) /**< (USART6) Receiver Time-out Register */
#define REG_USART6_US_TTGR      (0x40040228) /**< (USART6) Transmitter Timeguard Register */
#define REG_USART6_US_FIDI      (0x40040240) /**< (USART6) FI DI Ratio Register */
#define REG_USART6_US_NER       (0x40040244) /**< (USART6) Number of Errors Register */
#define REG_USART6_US_IF        (0x4004024C) /**< (USART6) IrDA Filter Register */
#define REG_USART6_US_LINMR     (0x40040254) /**< (USART6) LIN Mode Register */
#define REG_USART6_US_LINIR     (0x40040258) /**< (USART6) LIN Identifier Register */
#define REG_USART6_US_LINBRR    (0x4004025C) /**< (USART6) LIN Baud Rate Register */
#define REG_USART6_US_CMPR      (0x40040290) /**< (USART6) Comparison Register */
#define REG_USART6_US_WPMR      (0x400402E4) /**< (USART6) Write Protection Mode Register */
#define REG_USART6_US_WPSR      (0x400402E8) /**< (USART6) Write Protection Status Register */
#define REG_USART6_US_RPR       (0x40040300) /**< (USART6) Receive Pointer Register */
#define REG_USART6_US_RCR       (0x40040304) /**< (USART6) Receive Counter Register */
#define REG_USART6_US_TPR       (0x40040308) /**< (USART6) Transmit Pointer Register */
#define REG_USART6_US_TCR       (0x4004030C) /**< (USART6) Transmit Counter Register */
#define REG_USART6_US_RNPR      (0x40040310) /**< (USART6) Receive Next Pointer Register */
#define REG_USART6_US_RNCR      (0x40040314) /**< (USART6) Receive Next Counter Register */
#define REG_USART6_US_TNPR      (0x40040318) /**< (USART6) Transmit Next Pointer Register */
#define REG_USART6_US_TNCR      (0x4004031C) /**< (USART6) Transmit Next Counter Register */
#define REG_USART6_US_PTCR      (0x40040320) /**< (USART6) Transfer Control Register */
#define REG_USART6_US_PTSR      (0x40040324) /**< (USART6) Transfer Status Register */

#else

#define REG_USART6_US_CR        (*(__O  uint32_t*)0x40040200U) /**< (USART6) Control Register */
#define REG_USART6_US_MR        (*(__IO uint32_t*)0x40040204U) /**< (USART6) Mode Register */
#define REG_USART6_US_IER       (*(__O  uint32_t*)0x40040208U) /**< (USART6) Interrupt Enable Register */
#define REG_USART6_US_IDR       (*(__O  uint32_t*)0x4004020CU) /**< (USART6) Interrupt Disable Register */
#define REG_USART6_US_IMR       (*(__I  uint32_t*)0x40040210U) /**< (USART6) Interrupt Mask Register */
#define REG_USART6_US_CSR       (*(__I  uint32_t*)0x40040214U) /**< (USART6) Channel Status Register */
#define REG_USART6_US_RHR       (*(__I  uint32_t*)0x40040218U) /**< (USART6) Receive Holding Register */
#define REG_USART6_US_THR       (*(__O  uint32_t*)0x4004021CU) /**< (USART6) Transmit Holding Register */
#define REG_USART6_US_BRGR      (*(__IO uint32_t*)0x40040220U) /**< (USART6) Baud Rate Generator Register */
#define REG_USART6_US_RTOR      (*(__IO uint32_t*)0x40040224U) /**< (USART6) Receiver Time-out Register */
#define REG_USART6_US_TTGR      (*(__IO uint32_t*)0x40040228U) /**< (USART6) Transmitter Timeguard Register */
#define REG_USART6_US_FIDI      (*(__IO uint32_t*)0x40040240U) /**< (USART6) FI DI Ratio Register */
#define REG_USART6_US_NER       (*(__I  uint32_t*)0x40040244U) /**< (USART6) Number of Errors Register */
#define REG_USART6_US_IF        (*(__IO uint32_t*)0x4004024CU) /**< (USART6) IrDA Filter Register */
#define REG_USART6_US_LINMR     (*(__IO uint32_t*)0x40040254U) /**< (USART6) LIN Mode Register */
#define REG_USART6_US_LINIR     (*(__IO uint32_t*)0x40040258U) /**< (USART6) LIN Identifier Register */
#define REG_USART6_US_LINBRR    (*(__I  uint32_t*)0x4004025CU) /**< (USART6) LIN Baud Rate Register */
#define REG_USART6_US_CMPR      (*(__IO uint32_t*)0x40040290U) /**< (USART6) Comparison Register */
#define REG_USART6_US_WPMR      (*(__IO uint32_t*)0x400402E4U) /**< (USART6) Write Protection Mode Register */
#define REG_USART6_US_WPSR      (*(__I  uint32_t*)0x400402E8U) /**< (USART6) Write Protection Status Register */
#define REG_USART6_US_RPR       (*(__IO uint32_t*)0x40040300U) /**< (USART6) Receive Pointer Register */
#define REG_USART6_US_RCR       (*(__IO uint32_t*)0x40040304U) /**< (USART6) Receive Counter Register */
#define REG_USART6_US_TPR       (*(__IO uint32_t*)0x40040308U) /**< (USART6) Transmit Pointer Register */
#define REG_USART6_US_TCR       (*(__IO uint32_t*)0x4004030CU) /**< (USART6) Transmit Counter Register */
#define REG_USART6_US_RNPR      (*(__IO uint32_t*)0x40040310U) /**< (USART6) Receive Next Pointer Register */
#define REG_USART6_US_RNCR      (*(__IO uint32_t*)0x40040314U) /**< (USART6) Receive Next Counter Register */
#define REG_USART6_US_TNPR      (*(__IO uint32_t*)0x40040318U) /**< (USART6) Transmit Next Pointer Register */
#define REG_USART6_US_TNCR      (*(__IO uint32_t*)0x4004031CU) /**< (USART6) Transmit Next Counter Register */
#define REG_USART6_US_PTCR      (*(__O  uint32_t*)0x40040320U) /**< (USART6) Transfer Control Register */
#define REG_USART6_US_PTSR      (*(__I  uint32_t*)0x40040324U) /**< (USART6) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART6 peripheral ========== */
#define USART6_DMAC_ID_TX                        25        
#define USART6_DMAC_ID_RX                        11        

#endif /* _SAMG55_USART6_INSTANCE_ */
