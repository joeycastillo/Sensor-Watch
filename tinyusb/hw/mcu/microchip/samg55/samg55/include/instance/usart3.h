/**
 * \file
 *
 * \brief Instance description for USART3
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
#ifndef _SAMG55_USART3_INSTANCE_H_
#define _SAMG55_USART3_INSTANCE_H_

/* ========== Register definition for USART3 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_USART3_US_CR        (0x40018200) /**< (USART3) Control Register */
#define REG_USART3_US_MR        (0x40018204) /**< (USART3) Mode Register */
#define REG_USART3_US_IER       (0x40018208) /**< (USART3) Interrupt Enable Register */
#define REG_USART3_US_IDR       (0x4001820C) /**< (USART3) Interrupt Disable Register */
#define REG_USART3_US_IMR       (0x40018210) /**< (USART3) Interrupt Mask Register */
#define REG_USART3_US_CSR       (0x40018214) /**< (USART3) Channel Status Register */
#define REG_USART3_US_RHR       (0x40018218) /**< (USART3) Receive Holding Register */
#define REG_USART3_US_THR       (0x4001821C) /**< (USART3) Transmit Holding Register */
#define REG_USART3_US_BRGR      (0x40018220) /**< (USART3) Baud Rate Generator Register */
#define REG_USART3_US_RTOR      (0x40018224) /**< (USART3) Receiver Time-out Register */
#define REG_USART3_US_TTGR      (0x40018228) /**< (USART3) Transmitter Timeguard Register */
#define REG_USART3_US_FIDI      (0x40018240) /**< (USART3) FI DI Ratio Register */
#define REG_USART3_US_NER       (0x40018244) /**< (USART3) Number of Errors Register */
#define REG_USART3_US_IF        (0x4001824C) /**< (USART3) IrDA Filter Register */
#define REG_USART3_US_LINMR     (0x40018254) /**< (USART3) LIN Mode Register */
#define REG_USART3_US_LINIR     (0x40018258) /**< (USART3) LIN Identifier Register */
#define REG_USART3_US_LINBRR    (0x4001825C) /**< (USART3) LIN Baud Rate Register */
#define REG_USART3_US_CMPR      (0x40018290) /**< (USART3) Comparison Register */
#define REG_USART3_US_WPMR      (0x400182E4) /**< (USART3) Write Protection Mode Register */
#define REG_USART3_US_WPSR      (0x400182E8) /**< (USART3) Write Protection Status Register */
#define REG_USART3_US_RPR       (0x40018300) /**< (USART3) Receive Pointer Register */
#define REG_USART3_US_RCR       (0x40018304) /**< (USART3) Receive Counter Register */
#define REG_USART3_US_TPR       (0x40018308) /**< (USART3) Transmit Pointer Register */
#define REG_USART3_US_TCR       (0x4001830C) /**< (USART3) Transmit Counter Register */
#define REG_USART3_US_RNPR      (0x40018310) /**< (USART3) Receive Next Pointer Register */
#define REG_USART3_US_RNCR      (0x40018314) /**< (USART3) Receive Next Counter Register */
#define REG_USART3_US_TNPR      (0x40018318) /**< (USART3) Transmit Next Pointer Register */
#define REG_USART3_US_TNCR      (0x4001831C) /**< (USART3) Transmit Next Counter Register */
#define REG_USART3_US_PTCR      (0x40018320) /**< (USART3) Transfer Control Register */
#define REG_USART3_US_PTSR      (0x40018324) /**< (USART3) Transfer Status Register */

#else

#define REG_USART3_US_CR        (*(__O  uint32_t*)0x40018200U) /**< (USART3) Control Register */
#define REG_USART3_US_MR        (*(__IO uint32_t*)0x40018204U) /**< (USART3) Mode Register */
#define REG_USART3_US_IER       (*(__O  uint32_t*)0x40018208U) /**< (USART3) Interrupt Enable Register */
#define REG_USART3_US_IDR       (*(__O  uint32_t*)0x4001820CU) /**< (USART3) Interrupt Disable Register */
#define REG_USART3_US_IMR       (*(__I  uint32_t*)0x40018210U) /**< (USART3) Interrupt Mask Register */
#define REG_USART3_US_CSR       (*(__I  uint32_t*)0x40018214U) /**< (USART3) Channel Status Register */
#define REG_USART3_US_RHR       (*(__I  uint32_t*)0x40018218U) /**< (USART3) Receive Holding Register */
#define REG_USART3_US_THR       (*(__O  uint32_t*)0x4001821CU) /**< (USART3) Transmit Holding Register */
#define REG_USART3_US_BRGR      (*(__IO uint32_t*)0x40018220U) /**< (USART3) Baud Rate Generator Register */
#define REG_USART3_US_RTOR      (*(__IO uint32_t*)0x40018224U) /**< (USART3) Receiver Time-out Register */
#define REG_USART3_US_TTGR      (*(__IO uint32_t*)0x40018228U) /**< (USART3) Transmitter Timeguard Register */
#define REG_USART3_US_FIDI      (*(__IO uint32_t*)0x40018240U) /**< (USART3) FI DI Ratio Register */
#define REG_USART3_US_NER       (*(__I  uint32_t*)0x40018244U) /**< (USART3) Number of Errors Register */
#define REG_USART3_US_IF        (*(__IO uint32_t*)0x4001824CU) /**< (USART3) IrDA Filter Register */
#define REG_USART3_US_LINMR     (*(__IO uint32_t*)0x40018254U) /**< (USART3) LIN Mode Register */
#define REG_USART3_US_LINIR     (*(__IO uint32_t*)0x40018258U) /**< (USART3) LIN Identifier Register */
#define REG_USART3_US_LINBRR    (*(__I  uint32_t*)0x4001825CU) /**< (USART3) LIN Baud Rate Register */
#define REG_USART3_US_CMPR      (*(__IO uint32_t*)0x40018290U) /**< (USART3) Comparison Register */
#define REG_USART3_US_WPMR      (*(__IO uint32_t*)0x400182E4U) /**< (USART3) Write Protection Mode Register */
#define REG_USART3_US_WPSR      (*(__I  uint32_t*)0x400182E8U) /**< (USART3) Write Protection Status Register */
#define REG_USART3_US_RPR       (*(__IO uint32_t*)0x40018300U) /**< (USART3) Receive Pointer Register */
#define REG_USART3_US_RCR       (*(__IO uint32_t*)0x40018304U) /**< (USART3) Receive Counter Register */
#define REG_USART3_US_TPR       (*(__IO uint32_t*)0x40018308U) /**< (USART3) Transmit Pointer Register */
#define REG_USART3_US_TCR       (*(__IO uint32_t*)0x4001830CU) /**< (USART3) Transmit Counter Register */
#define REG_USART3_US_RNPR      (*(__IO uint32_t*)0x40018310U) /**< (USART3) Receive Next Pointer Register */
#define REG_USART3_US_RNCR      (*(__IO uint32_t*)0x40018314U) /**< (USART3) Receive Next Counter Register */
#define REG_USART3_US_TNPR      (*(__IO uint32_t*)0x40018318U) /**< (USART3) Transmit Next Pointer Register */
#define REG_USART3_US_TNCR      (*(__IO uint32_t*)0x4001831CU) /**< (USART3) Transmit Next Counter Register */
#define REG_USART3_US_PTCR      (*(__O  uint32_t*)0x40018320U) /**< (USART3) Transfer Control Register */
#define REG_USART3_US_PTSR      (*(__I  uint32_t*)0x40018324U) /**< (USART3) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for USART3 peripheral ========== */
#define USART3_DMAC_ID_TX                        17        
#define USART3_DMAC_ID_RX                        0         

#endif /* _SAMG55_USART3_INSTANCE_ */
