/**
 * \file
 *
 * \brief Instance description for USART2
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
#ifndef _SAMG55_USART2_INSTANCE_H_
#define _SAMG55_USART2_INSTANCE_H_

/* ========== Register definition for USART2 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART2_US_CR        (0x40024200) /**< (USART2) Control Register */
#define REG_USART2_US_MR        (0x40024204) /**< (USART2) Mode Register */
#define REG_USART2_US_IER       (0x40024208) /**< (USART2) Interrupt Enable Register */
#define REG_USART2_US_IDR       (0x4002420C) /**< (USART2) Interrupt Disable Register */
#define REG_USART2_US_IMR       (0x40024210) /**< (USART2) Interrupt Mask Register */
#define REG_USART2_US_CSR       (0x40024214) /**< (USART2) Channel Status Register */
#define REG_USART2_US_RHR       (0x40024218) /**< (USART2) Receive Holding Register */
#define REG_USART2_US_THR       (0x4002421C) /**< (USART2) Transmit Holding Register */
#define REG_USART2_US_BRGR      (0x40024220) /**< (USART2) Baud Rate Generator Register */
#define REG_USART2_US_RTOR      (0x40024224) /**< (USART2) Receiver Time-out Register */
#define REG_USART2_US_TTGR      (0x40024228) /**< (USART2) Transmitter Timeguard Register */
#define REG_USART2_US_FIDI      (0x40024240) /**< (USART2) FI DI Ratio Register */
#define REG_USART2_US_NER       (0x40024244) /**< (USART2) Number of Errors Register */
#define REG_USART2_US_IF        (0x4002424C) /**< (USART2) IrDA Filter Register */
#define REG_USART2_US_LINMR     (0x40024254) /**< (USART2) LIN Mode Register */
#define REG_USART2_US_LINIR     (0x40024258) /**< (USART2) LIN Identifier Register */
#define REG_USART2_US_LINBRR    (0x4002425C) /**< (USART2) LIN Baud Rate Register */
#define REG_USART2_US_CMPR      (0x40024290) /**< (USART2) Comparison Register */
#define REG_USART2_US_WPMR      (0x400242E4) /**< (USART2) Write Protection Mode Register */
#define REG_USART2_US_WPSR      (0x400242E8) /**< (USART2) Write Protection Status Register */
#define REG_USART2_US_RPR       (0x40024300) /**< (USART2) Receive Pointer Register */
#define REG_USART2_US_RCR       (0x40024304) /**< (USART2) Receive Counter Register */
#define REG_USART2_US_TPR       (0x40024308) /**< (USART2) Transmit Pointer Register */
#define REG_USART2_US_TCR       (0x4002430C) /**< (USART2) Transmit Counter Register */
#define REG_USART2_US_RNPR      (0x40024310) /**< (USART2) Receive Next Pointer Register */
#define REG_USART2_US_RNCR      (0x40024314) /**< (USART2) Receive Next Counter Register */
#define REG_USART2_US_TNPR      (0x40024318) /**< (USART2) Transmit Next Pointer Register */
#define REG_USART2_US_TNCR      (0x4002431C) /**< (USART2) Transmit Next Counter Register */
#define REG_USART2_US_PTCR      (0x40024320) /**< (USART2) Transfer Control Register */
#define REG_USART2_US_PTSR      (0x40024324) /**< (USART2) Transfer Status Register */

#else

#define REG_USART2_US_CR        (*(__O  uint32_t*)0x40024200U) /**< (USART2) Control Register */
#define REG_USART2_US_MR        (*(__IO uint32_t*)0x40024204U) /**< (USART2) Mode Register */
#define REG_USART2_US_IER       (*(__O  uint32_t*)0x40024208U) /**< (USART2) Interrupt Enable Register */
#define REG_USART2_US_IDR       (*(__O  uint32_t*)0x4002420CU) /**< (USART2) Interrupt Disable Register */
#define REG_USART2_US_IMR       (*(__I  uint32_t*)0x40024210U) /**< (USART2) Interrupt Mask Register */
#define REG_USART2_US_CSR       (*(__I  uint32_t*)0x40024214U) /**< (USART2) Channel Status Register */
#define REG_USART2_US_RHR       (*(__I  uint32_t*)0x40024218U) /**< (USART2) Receive Holding Register */
#define REG_USART2_US_THR       (*(__O  uint32_t*)0x4002421CU) /**< (USART2) Transmit Holding Register */
#define REG_USART2_US_BRGR      (*(__IO uint32_t*)0x40024220U) /**< (USART2) Baud Rate Generator Register */
#define REG_USART2_US_RTOR      (*(__IO uint32_t*)0x40024224U) /**< (USART2) Receiver Time-out Register */
#define REG_USART2_US_TTGR      (*(__IO uint32_t*)0x40024228U) /**< (USART2) Transmitter Timeguard Register */
#define REG_USART2_US_FIDI      (*(__IO uint32_t*)0x40024240U) /**< (USART2) FI DI Ratio Register */
#define REG_USART2_US_NER       (*(__I  uint32_t*)0x40024244U) /**< (USART2) Number of Errors Register */
#define REG_USART2_US_IF        (*(__IO uint32_t*)0x4002424CU) /**< (USART2) IrDA Filter Register */
#define REG_USART2_US_LINMR     (*(__IO uint32_t*)0x40024254U) /**< (USART2) LIN Mode Register */
#define REG_USART2_US_LINIR     (*(__IO uint32_t*)0x40024258U) /**< (USART2) LIN Identifier Register */
#define REG_USART2_US_LINBRR    (*(__I  uint32_t*)0x4002425CU) /**< (USART2) LIN Baud Rate Register */
#define REG_USART2_US_CMPR      (*(__IO uint32_t*)0x40024290U) /**< (USART2) Comparison Register */
#define REG_USART2_US_WPMR      (*(__IO uint32_t*)0x400242E4U) /**< (USART2) Write Protection Mode Register */
#define REG_USART2_US_WPSR      (*(__I  uint32_t*)0x400242E8U) /**< (USART2) Write Protection Status Register */
#define REG_USART2_US_RPR       (*(__IO uint32_t*)0x40024300U) /**< (USART2) Receive Pointer Register */
#define REG_USART2_US_RCR       (*(__IO uint32_t*)0x40024304U) /**< (USART2) Receive Counter Register */
#define REG_USART2_US_TPR       (*(__IO uint32_t*)0x40024308U) /**< (USART2) Transmit Pointer Register */
#define REG_USART2_US_TCR       (*(__IO uint32_t*)0x4002430CU) /**< (USART2) Transmit Counter Register */
#define REG_USART2_US_RNPR      (*(__IO uint32_t*)0x40024310U) /**< (USART2) Receive Next Pointer Register */
#define REG_USART2_US_RNCR      (*(__IO uint32_t*)0x40024314U) /**< (USART2) Receive Next Counter Register */
#define REG_USART2_US_TNPR      (*(__IO uint32_t*)0x40024318U) /**< (USART2) Transmit Next Pointer Register */
#define REG_USART2_US_TNCR      (*(__IO uint32_t*)0x4002431CU) /**< (USART2) Transmit Next Counter Register */
#define REG_USART2_US_PTCR      (*(__O  uint32_t*)0x40024320U) /**< (USART2) Transfer Control Register */
#define REG_USART2_US_PTSR      (*(__I  uint32_t*)0x40024324U) /**< (USART2) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART2 peripheral ========== */
#define USART2_DMAC_ID_TX                        22        
#define USART2_DMAC_ID_RX                        8         

#endif /* _SAMG55_USART2_INSTANCE_ */
