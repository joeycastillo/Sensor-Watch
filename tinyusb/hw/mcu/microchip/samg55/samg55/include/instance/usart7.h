/**
 * \file
 *
 * \brief Instance description for USART7
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
#ifndef _SAMG55_USART7_INSTANCE_H_
#define _SAMG55_USART7_INSTANCE_H_

/* ========== Register definition for USART7 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART7_US_CR        (0x40034200) /**< (USART7) Control Register */
#define REG_USART7_US_MR        (0x40034204) /**< (USART7) Mode Register */
#define REG_USART7_US_IER       (0x40034208) /**< (USART7) Interrupt Enable Register */
#define REG_USART7_US_IDR       (0x4003420C) /**< (USART7) Interrupt Disable Register */
#define REG_USART7_US_IMR       (0x40034210) /**< (USART7) Interrupt Mask Register */
#define REG_USART7_US_CSR       (0x40034214) /**< (USART7) Channel Status Register */
#define REG_USART7_US_RHR       (0x40034218) /**< (USART7) Receive Holding Register */
#define REG_USART7_US_THR       (0x4003421C) /**< (USART7) Transmit Holding Register */
#define REG_USART7_US_BRGR      (0x40034220) /**< (USART7) Baud Rate Generator Register */
#define REG_USART7_US_RTOR      (0x40034224) /**< (USART7) Receiver Time-out Register */
#define REG_USART7_US_TTGR      (0x40034228) /**< (USART7) Transmitter Timeguard Register */
#define REG_USART7_US_FIDI      (0x40034240) /**< (USART7) FI DI Ratio Register */
#define REG_USART7_US_NER       (0x40034244) /**< (USART7) Number of Errors Register */
#define REG_USART7_US_IF        (0x4003424C) /**< (USART7) IrDA Filter Register */
#define REG_USART7_US_LINMR     (0x40034254) /**< (USART7) LIN Mode Register */
#define REG_USART7_US_LINIR     (0x40034258) /**< (USART7) LIN Identifier Register */
#define REG_USART7_US_LINBRR    (0x4003425C) /**< (USART7) LIN Baud Rate Register */
#define REG_USART7_US_CMPR      (0x40034290) /**< (USART7) Comparison Register */
#define REG_USART7_US_WPMR      (0x400342E4) /**< (USART7) Write Protection Mode Register */
#define REG_USART7_US_WPSR      (0x400342E8) /**< (USART7) Write Protection Status Register */
#define REG_USART7_US_RPR       (0x40034300) /**< (USART7) Receive Pointer Register */
#define REG_USART7_US_RCR       (0x40034304) /**< (USART7) Receive Counter Register */
#define REG_USART7_US_TPR       (0x40034308) /**< (USART7) Transmit Pointer Register */
#define REG_USART7_US_TCR       (0x4003430C) /**< (USART7) Transmit Counter Register */
#define REG_USART7_US_RNPR      (0x40034310) /**< (USART7) Receive Next Pointer Register */
#define REG_USART7_US_RNCR      (0x40034314) /**< (USART7) Receive Next Counter Register */
#define REG_USART7_US_TNPR      (0x40034318) /**< (USART7) Transmit Next Pointer Register */
#define REG_USART7_US_TNCR      (0x4003431C) /**< (USART7) Transmit Next Counter Register */
#define REG_USART7_US_PTCR      (0x40034320) /**< (USART7) Transfer Control Register */
#define REG_USART7_US_PTSR      (0x40034324) /**< (USART7) Transfer Status Register */

#else

#define REG_USART7_US_CR        (*(__O  uint32_t*)0x40034200U) /**< (USART7) Control Register */
#define REG_USART7_US_MR        (*(__IO uint32_t*)0x40034204U) /**< (USART7) Mode Register */
#define REG_USART7_US_IER       (*(__O  uint32_t*)0x40034208U) /**< (USART7) Interrupt Enable Register */
#define REG_USART7_US_IDR       (*(__O  uint32_t*)0x4003420CU) /**< (USART7) Interrupt Disable Register */
#define REG_USART7_US_IMR       (*(__I  uint32_t*)0x40034210U) /**< (USART7) Interrupt Mask Register */
#define REG_USART7_US_CSR       (*(__I  uint32_t*)0x40034214U) /**< (USART7) Channel Status Register */
#define REG_USART7_US_RHR       (*(__I  uint32_t*)0x40034218U) /**< (USART7) Receive Holding Register */
#define REG_USART7_US_THR       (*(__O  uint32_t*)0x4003421CU) /**< (USART7) Transmit Holding Register */
#define REG_USART7_US_BRGR      (*(__IO uint32_t*)0x40034220U) /**< (USART7) Baud Rate Generator Register */
#define REG_USART7_US_RTOR      (*(__IO uint32_t*)0x40034224U) /**< (USART7) Receiver Time-out Register */
#define REG_USART7_US_TTGR      (*(__IO uint32_t*)0x40034228U) /**< (USART7) Transmitter Timeguard Register */
#define REG_USART7_US_FIDI      (*(__IO uint32_t*)0x40034240U) /**< (USART7) FI DI Ratio Register */
#define REG_USART7_US_NER       (*(__I  uint32_t*)0x40034244U) /**< (USART7) Number of Errors Register */
#define REG_USART7_US_IF        (*(__IO uint32_t*)0x4003424CU) /**< (USART7) IrDA Filter Register */
#define REG_USART7_US_LINMR     (*(__IO uint32_t*)0x40034254U) /**< (USART7) LIN Mode Register */
#define REG_USART7_US_LINIR     (*(__IO uint32_t*)0x40034258U) /**< (USART7) LIN Identifier Register */
#define REG_USART7_US_LINBRR    (*(__I  uint32_t*)0x4003425CU) /**< (USART7) LIN Baud Rate Register */
#define REG_USART7_US_CMPR      (*(__IO uint32_t*)0x40034290U) /**< (USART7) Comparison Register */
#define REG_USART7_US_WPMR      (*(__IO uint32_t*)0x400342E4U) /**< (USART7) Write Protection Mode Register */
#define REG_USART7_US_WPSR      (*(__I  uint32_t*)0x400342E8U) /**< (USART7) Write Protection Status Register */
#define REG_USART7_US_RPR       (*(__IO uint32_t*)0x40034300U) /**< (USART7) Receive Pointer Register */
#define REG_USART7_US_RCR       (*(__IO uint32_t*)0x40034304U) /**< (USART7) Receive Counter Register */
#define REG_USART7_US_TPR       (*(__IO uint32_t*)0x40034308U) /**< (USART7) Transmit Pointer Register */
#define REG_USART7_US_TCR       (*(__IO uint32_t*)0x4003430CU) /**< (USART7) Transmit Counter Register */
#define REG_USART7_US_RNPR      (*(__IO uint32_t*)0x40034310U) /**< (USART7) Receive Next Pointer Register */
#define REG_USART7_US_RNCR      (*(__IO uint32_t*)0x40034314U) /**< (USART7) Receive Next Counter Register */
#define REG_USART7_US_TNPR      (*(__IO uint32_t*)0x40034318U) /**< (USART7) Transmit Next Pointer Register */
#define REG_USART7_US_TNCR      (*(__IO uint32_t*)0x4003431CU) /**< (USART7) Transmit Next Counter Register */
#define REG_USART7_US_PTCR      (*(__O  uint32_t*)0x40034320U) /**< (USART7) Transfer Control Register */
#define REG_USART7_US_PTSR      (*(__I  uint32_t*)0x40034324U) /**< (USART7) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART7 peripheral ========== */
#define USART7_DMAC_ID_TX                        29        
#define USART7_DMAC_ID_RX                        16        

#endif /* _SAMG55_USART7_INSTANCE_ */
