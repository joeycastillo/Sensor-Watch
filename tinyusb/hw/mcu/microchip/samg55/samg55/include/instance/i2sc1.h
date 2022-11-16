/**
 * \file
 *
 * \brief Instance description for I2SC1
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
#ifndef _SAMG55_I2SC1_INSTANCE_H_
#define _SAMG55_I2SC1_INSTANCE_H_

/* ========== Register definition for I2SC1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_I2SC1_CR            (0x40004000) /**< (I2SC1) Control Register */
#define REG_I2SC1_MR            (0x40004004) /**< (I2SC1) Mode Register */
#define REG_I2SC1_SR            (0x40004008) /**< (I2SC1) Status Register */
#define REG_I2SC1_SCR           (0x4000400C) /**< (I2SC1) Status Clear Register */
#define REG_I2SC1_SSR           (0x40004010) /**< (I2SC1) Status Set Register */
#define REG_I2SC1_IER           (0x40004014) /**< (I2SC1) Interrupt Enable Register */
#define REG_I2SC1_IDR           (0x40004018) /**< (I2SC1) Interrupt Disable Register */
#define REG_I2SC1_IMR           (0x4000401C) /**< (I2SC1) Interrupt Mask Register */
#define REG_I2SC1_RHR           (0x40004020) /**< (I2SC1) Receiver Holding Register */
#define REG_I2SC1_THR           (0x40004024) /**< (I2SC1) Transmitter Holding Register */
#define REG_I2SC1_RPR           (0x40004100) /**< (I2SC1) Receive Pointer Register */
#define REG_I2SC1_RCR           (0x40004104) /**< (I2SC1) Receive Counter Register */
#define REG_I2SC1_TPR           (0x40004108) /**< (I2SC1) Transmit Pointer Register */
#define REG_I2SC1_TCR           (0x4000410C) /**< (I2SC1) Transmit Counter Register */
#define REG_I2SC1_RNPR          (0x40004110) /**< (I2SC1) Receive Next Pointer Register */
#define REG_I2SC1_RNCR          (0x40004114) /**< (I2SC1) Receive Next Counter Register */
#define REG_I2SC1_TNPR          (0x40004118) /**< (I2SC1) Transmit Next Pointer Register */
#define REG_I2SC1_TNCR          (0x4000411C) /**< (I2SC1) Transmit Next Counter Register */
#define REG_I2SC1_PTCR          (0x40004120) /**< (I2SC1) Transfer Control Register */
#define REG_I2SC1_PTSR          (0x40004124) /**< (I2SC1) Transfer Status Register */

#else

#define REG_I2SC1_CR            (*(__O  uint32_t*)0x40004000U) /**< (I2SC1) Control Register */
#define REG_I2SC1_MR            (*(__IO uint32_t*)0x40004004U) /**< (I2SC1) Mode Register */
#define REG_I2SC1_SR            (*(__I  uint32_t*)0x40004008U) /**< (I2SC1) Status Register */
#define REG_I2SC1_SCR           (*(__O  uint32_t*)0x4000400CU) /**< (I2SC1) Status Clear Register */
#define REG_I2SC1_SSR           (*(__O  uint32_t*)0x40004010U) /**< (I2SC1) Status Set Register */
#define REG_I2SC1_IER           (*(__O  uint32_t*)0x40004014U) /**< (I2SC1) Interrupt Enable Register */
#define REG_I2SC1_IDR           (*(__O  uint32_t*)0x40004018U) /**< (I2SC1) Interrupt Disable Register */
#define REG_I2SC1_IMR           (*(__I  uint32_t*)0x4000401CU) /**< (I2SC1) Interrupt Mask Register */
#define REG_I2SC1_RHR           (*(__I  uint32_t*)0x40004020U) /**< (I2SC1) Receiver Holding Register */
#define REG_I2SC1_THR           (*(__O  uint32_t*)0x40004024U) /**< (I2SC1) Transmitter Holding Register */
#define REG_I2SC1_RPR           (*(__IO uint32_t*)0x40004100U) /**< (I2SC1) Receive Pointer Register */
#define REG_I2SC1_RCR           (*(__IO uint32_t*)0x40004104U) /**< (I2SC1) Receive Counter Register */
#define REG_I2SC1_TPR           (*(__IO uint32_t*)0x40004108U) /**< (I2SC1) Transmit Pointer Register */
#define REG_I2SC1_TCR           (*(__IO uint32_t*)0x4000410CU) /**< (I2SC1) Transmit Counter Register */
#define REG_I2SC1_RNPR          (*(__IO uint32_t*)0x40004110U) /**< (I2SC1) Receive Next Pointer Register */
#define REG_I2SC1_RNCR          (*(__IO uint32_t*)0x40004114U) /**< (I2SC1) Receive Next Counter Register */
#define REG_I2SC1_TNPR          (*(__IO uint32_t*)0x40004118U) /**< (I2SC1) Transmit Next Pointer Register */
#define REG_I2SC1_TNCR          (*(__IO uint32_t*)0x4000411CU) /**< (I2SC1) Transmit Next Counter Register */
#define REG_I2SC1_PTCR          (*(__O  uint32_t*)0x40004120U) /**< (I2SC1) Transfer Control Register */
#define REG_I2SC1_PTSR          (*(__I  uint32_t*)0x40004124U) /**< (I2SC1) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for I2SC1 peripheral ========== */
#define I2SC1_DMAC_ID_TX1                        5         
#define I2SC1_DMAC_ID_TX0                        4         
#define I2SC1_INSTANCE_ID                        17        
#define I2SC1_DMAC_ID_RX1                        21        
#define I2SC1_DMAC_ID_RX0                        20        

#endif /* _SAMG55_I2SC1_INSTANCE_ */
