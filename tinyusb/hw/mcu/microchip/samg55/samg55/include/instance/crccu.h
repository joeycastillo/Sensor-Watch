/**
 * \file
 *
 * \brief Instance description for CRCCU
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
#ifndef _SAMG55_CRCCU_INSTANCE_H_
#define _SAMG55_CRCCU_INSTANCE_H_

/* ========== Register definition for CRCCU peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_CRCCU_DSCR          (0x40048000) /**< (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN        (0x40048008) /**< (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS       (0x4004800C) /**< (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR        (0x40048010) /**< (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER       (0x40048014) /**< (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR       (0x40048018) /**< (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR       (0x4004801C) /**< (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR       (0x40048020) /**< (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR            (0x40048034) /**< (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR            (0x40048038) /**< (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR            (0x4004803C) /**< (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER           (0x40048040) /**< (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR           (0x40048044) /**< (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR           (0x40048048) /**< (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR           (0x4004804C) /**< (CRCCU) CRCCU Interrupt Status Register */

#else

#define REG_CRCCU_DSCR          (*(__IO uint32_t*)0x40048000U) /**< (CRCCU) CRCCU Descriptor Base Register */
#define REG_CRCCU_DMA_EN        (*(__O  uint32_t*)0x40048008U) /**< (CRCCU) CRCCU DMA Enable Register */
#define REG_CRCCU_DMA_DIS       (*(__O  uint32_t*)0x4004800CU) /**< (CRCCU) CRCCU DMA Disable Register */
#define REG_CRCCU_DMA_SR        (*(__I  uint32_t*)0x40048010U) /**< (CRCCU) CRCCU DMA Status Register */
#define REG_CRCCU_DMA_IER       (*(__O  uint32_t*)0x40048014U) /**< (CRCCU) CRCCU DMA Interrupt Enable Register */
#define REG_CRCCU_DMA_IDR       (*(__O  uint32_t*)0x40048018U) /**< (CRCCU) CRCCU DMA Interrupt Disable Register */
#define REG_CRCCU_DMA_IMR       (*(__I  uint32_t*)0x4004801CU) /**< (CRCCU) CRCCU DMA Interrupt Mask Register */
#define REG_CRCCU_DMA_ISR       (*(__I  uint32_t*)0x40048020U) /**< (CRCCU) CRCCU DMA Interrupt Status Register */
#define REG_CRCCU_CR            (*(__O  uint32_t*)0x40048034U) /**< (CRCCU) CRCCU Control Register */
#define REG_CRCCU_MR            (*(__IO uint32_t*)0x40048038U) /**< (CRCCU) CRCCU Mode Register */
#define REG_CRCCU_SR            (*(__I  uint32_t*)0x4004803CU) /**< (CRCCU) CRCCU Status Register */
#define REG_CRCCU_IER           (*(__O  uint32_t*)0x40048040U) /**< (CRCCU) CRCCU Interrupt Enable Register */
#define REG_CRCCU_IDR           (*(__O  uint32_t*)0x40048044U) /**< (CRCCU) CRCCU Interrupt Disable Register */
#define REG_CRCCU_IMR           (*(__I  uint32_t*)0x40048048U) /**< (CRCCU) CRCCU Interrupt Mask Register */
#define REG_CRCCU_ISR           (*(__I  uint32_t*)0x4004804CU) /**< (CRCCU) CRCCU Interrupt Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for CRCCU peripheral ========== */
#define CRCCU_INSTANCE_ID                        49        

#endif /* _SAMG55_CRCCU_INSTANCE_ */
