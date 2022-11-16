/**
 * \file
 *
 * \brief Instance description for USART5
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
#ifndef _SAMG55_USART5_INSTANCE_H_
#define _SAMG55_USART5_INSTANCE_H_

/* ========== Register definition for USART5 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART5_US_CR        (0x40008200) /**< (USART5) Control Register */
#define REG_USART5_US_MR        (0x40008204) /**< (USART5) Mode Register */
#define REG_USART5_US_IER       (0x40008208) /**< (USART5) Interrupt Enable Register */
#define REG_USART5_US_IDR       (0x4000820C) /**< (USART5) Interrupt Disable Register */
#define REG_USART5_US_IMR       (0x40008210) /**< (USART5) Interrupt Mask Register */
#define REG_USART5_US_CSR       (0x40008214) /**< (USART5) Channel Status Register */
#define REG_USART5_US_RHR       (0x40008218) /**< (USART5) Receive Holding Register */
#define REG_USART5_US_THR       (0x4000821C) /**< (USART5) Transmit Holding Register */
#define REG_USART5_US_BRGR      (0x40008220) /**< (USART5) Baud Rate Generator Register */
#define REG_USART5_US_RTOR      (0x40008224) /**< (USART5) Receiver Time-out Register */
#define REG_USART5_US_TTGR      (0x40008228) /**< (USART5) Transmitter Timeguard Register */
#define REG_USART5_US_FIDI      (0x40008240) /**< (USART5) FI DI Ratio Register */
#define REG_USART5_US_NER       (0x40008244) /**< (USART5) Number of Errors Register */
#define REG_USART5_US_IF        (0x4000824C) /**< (USART5) IrDA Filter Register */
#define REG_USART5_US_LINMR     (0x40008254) /**< (USART5) LIN Mode Register */
#define REG_USART5_US_LINIR     (0x40008258) /**< (USART5) LIN Identifier Register */
#define REG_USART5_US_LINBRR    (0x4000825C) /**< (USART5) LIN Baud Rate Register */
#define REG_USART5_US_CMPR      (0x40008290) /**< (USART5) Comparison Register */
#define REG_USART5_US_WPMR      (0x400082E4) /**< (USART5) Write Protection Mode Register */
#define REG_USART5_US_WPSR      (0x400082E8) /**< (USART5) Write Protection Status Register */
#define REG_USART5_US_RPR       (0x40008300) /**< (USART5) Receive Pointer Register */
#define REG_USART5_US_RCR       (0x40008304) /**< (USART5) Receive Counter Register */
#define REG_USART5_US_TPR       (0x40008308) /**< (USART5) Transmit Pointer Register */
#define REG_USART5_US_TCR       (0x4000830C) /**< (USART5) Transmit Counter Register */
#define REG_USART5_US_RNPR      (0x40008310) /**< (USART5) Receive Next Pointer Register */
#define REG_USART5_US_RNCR      (0x40008314) /**< (USART5) Receive Next Counter Register */
#define REG_USART5_US_TNPR      (0x40008318) /**< (USART5) Transmit Next Pointer Register */
#define REG_USART5_US_TNCR      (0x4000831C) /**< (USART5) Transmit Next Counter Register */
#define REG_USART5_US_PTCR      (0x40008320) /**< (USART5) Transfer Control Register */
#define REG_USART5_US_PTSR      (0x40008324) /**< (USART5) Transfer Status Register */

#else

#define REG_USART5_US_CR        (*(__O  uint32_t*)0x40008200U) /**< (USART5) Control Register */
#define REG_USART5_US_MR        (*(__IO uint32_t*)0x40008204U) /**< (USART5) Mode Register */
#define REG_USART5_US_IER       (*(__O  uint32_t*)0x40008208U) /**< (USART5) Interrupt Enable Register */
#define REG_USART5_US_IDR       (*(__O  uint32_t*)0x4000820CU) /**< (USART5) Interrupt Disable Register */
#define REG_USART5_US_IMR       (*(__I  uint32_t*)0x40008210U) /**< (USART5) Interrupt Mask Register */
#define REG_USART5_US_CSR       (*(__I  uint32_t*)0x40008214U) /**< (USART5) Channel Status Register */
#define REG_USART5_US_RHR       (*(__I  uint32_t*)0x40008218U) /**< (USART5) Receive Holding Register */
#define REG_USART5_US_THR       (*(__O  uint32_t*)0x4000821CU) /**< (USART5) Transmit Holding Register */
#define REG_USART5_US_BRGR      (*(__IO uint32_t*)0x40008220U) /**< (USART5) Baud Rate Generator Register */
#define REG_USART5_US_RTOR      (*(__IO uint32_t*)0x40008224U) /**< (USART5) Receiver Time-out Register */
#define REG_USART5_US_TTGR      (*(__IO uint32_t*)0x40008228U) /**< (USART5) Transmitter Timeguard Register */
#define REG_USART5_US_FIDI      (*(__IO uint32_t*)0x40008240U) /**< (USART5) FI DI Ratio Register */
#define REG_USART5_US_NER       (*(__I  uint32_t*)0x40008244U) /**< (USART5) Number of Errors Register */
#define REG_USART5_US_IF        (*(__IO uint32_t*)0x4000824CU) /**< (USART5) IrDA Filter Register */
#define REG_USART5_US_LINMR     (*(__IO uint32_t*)0x40008254U) /**< (USART5) LIN Mode Register */
#define REG_USART5_US_LINIR     (*(__IO uint32_t*)0x40008258U) /**< (USART5) LIN Identifier Register */
#define REG_USART5_US_LINBRR    (*(__I  uint32_t*)0x4000825CU) /**< (USART5) LIN Baud Rate Register */
#define REG_USART5_US_CMPR      (*(__IO uint32_t*)0x40008290U) /**< (USART5) Comparison Register */
#define REG_USART5_US_WPMR      (*(__IO uint32_t*)0x400082E4U) /**< (USART5) Write Protection Mode Register */
#define REG_USART5_US_WPSR      (*(__I  uint32_t*)0x400082E8U) /**< (USART5) Write Protection Status Register */
#define REG_USART5_US_RPR       (*(__IO uint32_t*)0x40008300U) /**< (USART5) Receive Pointer Register */
#define REG_USART5_US_RCR       (*(__IO uint32_t*)0x40008304U) /**< (USART5) Receive Counter Register */
#define REG_USART5_US_TPR       (*(__IO uint32_t*)0x40008308U) /**< (USART5) Transmit Pointer Register */
#define REG_USART5_US_TCR       (*(__IO uint32_t*)0x4000830CU) /**< (USART5) Transmit Counter Register */
#define REG_USART5_US_RNPR      (*(__IO uint32_t*)0x40008310U) /**< (USART5) Receive Next Pointer Register */
#define REG_USART5_US_RNCR      (*(__IO uint32_t*)0x40008314U) /**< (USART5) Receive Next Counter Register */
#define REG_USART5_US_TNPR      (*(__IO uint32_t*)0x40008318U) /**< (USART5) Transmit Next Pointer Register */
#define REG_USART5_US_TNCR      (*(__IO uint32_t*)0x4000831CU) /**< (USART5) Transmit Next Counter Register */
#define REG_USART5_US_PTCR      (*(__O  uint32_t*)0x40008320U) /**< (USART5) Transfer Control Register */
#define REG_USART5_US_PTSR      (*(__I  uint32_t*)0x40008324U) /**< (USART5) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART5 peripheral ========== */
#define USART5_DMAC_ID_TX                        27        
#define USART5_DMAC_ID_RX                        13        

#endif /* _SAMG55_USART5_INSTANCE_ */
