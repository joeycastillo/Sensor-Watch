/**
 * \file
 *
 * \brief Instance description for I2SC0
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
#ifndef _SAMG55_I2SC0_INSTANCE_H_
#define _SAMG55_I2SC0_INSTANCE_H_

/* ========== Register definition for I2SC0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_I2SC0_CR            (0x40000000) /**< (I2SC0) Control Register */
#define REG_I2SC0_MR            (0x40000004) /**< (I2SC0) Mode Register */
#define REG_I2SC0_SR            (0x40000008) /**< (I2SC0) Status Register */
#define REG_I2SC0_SCR           (0x4000000C) /**< (I2SC0) Status Clear Register */
#define REG_I2SC0_SSR           (0x40000010) /**< (I2SC0) Status Set Register */
#define REG_I2SC0_IER           (0x40000014) /**< (I2SC0) Interrupt Enable Register */
#define REG_I2SC0_IDR           (0x40000018) /**< (I2SC0) Interrupt Disable Register */
#define REG_I2SC0_IMR           (0x4000001C) /**< (I2SC0) Interrupt Mask Register */
#define REG_I2SC0_RHR           (0x40000020) /**< (I2SC0) Receiver Holding Register */
#define REG_I2SC0_THR           (0x40000024) /**< (I2SC0) Transmitter Holding Register */
#define REG_I2SC0_RPR           (0x40000100) /**< (I2SC0) Receive Pointer Register */
#define REG_I2SC0_RCR           (0x40000104) /**< (I2SC0) Receive Counter Register */
#define REG_I2SC0_TPR           (0x40000108) /**< (I2SC0) Transmit Pointer Register */
#define REG_I2SC0_TCR           (0x4000010C) /**< (I2SC0) Transmit Counter Register */
#define REG_I2SC0_RNPR          (0x40000110) /**< (I2SC0) Receive Next Pointer Register */
#define REG_I2SC0_RNCR          (0x40000114) /**< (I2SC0) Receive Next Counter Register */
#define REG_I2SC0_TNPR          (0x40000118) /**< (I2SC0) Transmit Next Pointer Register */
#define REG_I2SC0_TNCR          (0x4000011C) /**< (I2SC0) Transmit Next Counter Register */
#define REG_I2SC0_PTCR          (0x40000120) /**< (I2SC0) Transfer Control Register */
#define REG_I2SC0_PTSR          (0x40000124) /**< (I2SC0) Transfer Status Register */

#else

#define REG_I2SC0_CR            (*(__O  uint32_t*)0x40000000U) /**< (I2SC0) Control Register */
#define REG_I2SC0_MR            (*(__IO uint32_t*)0x40000004U) /**< (I2SC0) Mode Register */
#define REG_I2SC0_SR            (*(__I  uint32_t*)0x40000008U) /**< (I2SC0) Status Register */
#define REG_I2SC0_SCR           (*(__O  uint32_t*)0x4000000CU) /**< (I2SC0) Status Clear Register */
#define REG_I2SC0_SSR           (*(__O  uint32_t*)0x40000010U) /**< (I2SC0) Status Set Register */
#define REG_I2SC0_IER           (*(__O  uint32_t*)0x40000014U) /**< (I2SC0) Interrupt Enable Register */
#define REG_I2SC0_IDR           (*(__O  uint32_t*)0x40000018U) /**< (I2SC0) Interrupt Disable Register */
#define REG_I2SC0_IMR           (*(__I  uint32_t*)0x4000001CU) /**< (I2SC0) Interrupt Mask Register */
#define REG_I2SC0_RHR           (*(__I  uint32_t*)0x40000020U) /**< (I2SC0) Receiver Holding Register */
#define REG_I2SC0_THR           (*(__O  uint32_t*)0x40000024U) /**< (I2SC0) Transmitter Holding Register */
#define REG_I2SC0_RPR           (*(__IO uint32_t*)0x40000100U) /**< (I2SC0) Receive Pointer Register */
#define REG_I2SC0_RCR           (*(__IO uint32_t*)0x40000104U) /**< (I2SC0) Receive Counter Register */
#define REG_I2SC0_TPR           (*(__IO uint32_t*)0x40000108U) /**< (I2SC0) Transmit Pointer Register */
#define REG_I2SC0_TCR           (*(__IO uint32_t*)0x4000010CU) /**< (I2SC0) Transmit Counter Register */
#define REG_I2SC0_RNPR          (*(__IO uint32_t*)0x40000110U) /**< (I2SC0) Receive Next Pointer Register */
#define REG_I2SC0_RNCR          (*(__IO uint32_t*)0x40000114U) /**< (I2SC0) Receive Next Counter Register */
#define REG_I2SC0_TNPR          (*(__IO uint32_t*)0x40000118U) /**< (I2SC0) Transmit Next Pointer Register */
#define REG_I2SC0_TNCR          (*(__IO uint32_t*)0x4000011CU) /**< (I2SC0) Transmit Next Counter Register */
#define REG_I2SC0_PTCR          (*(__O  uint32_t*)0x40000120U) /**< (I2SC0) Transfer Control Register */
#define REG_I2SC0_PTSR          (*(__I  uint32_t*)0x40000124U) /**< (I2SC0) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for I2SC0 peripheral ========== */
#define I2SC0_DMAC_ID_TX1                        3         
#define I2SC0_DMAC_ID_TX0                        2         
#define I2SC0_INSTANCE_ID                        16        
#define I2SC0_DMAC_ID_RX1                        19        
#define I2SC0_DMAC_ID_RX0                        18        

#endif /* _SAMG55_I2SC0_INSTANCE_ */
