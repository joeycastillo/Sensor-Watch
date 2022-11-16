/**
 * \file
 *
 * \brief Instance description for SPI3
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
#ifndef _SAMG55_SPI3_INSTANCE_H_
#define _SAMG55_SPI3_INSTANCE_H_

/* ========== Register definition for SPI3 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI3_CR             (0x40018400) /**< (SPI3) SPI Control Register */
#define REG_SPI3_MR             (0x40018404) /**< (SPI3) SPI Mode Register */
#define REG_SPI3_RDR            (0x40018408) /**< (SPI3) SPI Receive Data Register */
#define REG_SPI3_TDR            (0x4001840C) /**< (SPI3) SPI Transmit Data Register */
#define REG_SPI3_SR             (0x40018410) /**< (SPI3) SPI Status Register */
#define REG_SPI3_IER            (0x40018414) /**< (SPI3) SPI Interrupt Enable Register */
#define REG_SPI3_IDR            (0x40018418) /**< (SPI3) SPI Interrupt Disable Register */
#define REG_SPI3_IMR            (0x4001841C) /**< (SPI3) SPI Interrupt Mask Register */
#define REG_SPI3_CSR            (0x40018430) /**< (SPI3) SPI Chip Select Register 0 */
#define REG_SPI3_CSR0           (0x40018430) /**< (SPI3) SPI Chip Select Register 0 */
#define REG_SPI3_CSR1           (0x40018434) /**< (SPI3) SPI Chip Select Register 1 */
#define REG_SPI3_CMPR           (0x40018448) /**< (SPI3) SPI Comparison Register */
#define REG_SPI3_WPMR           (0x400184E4) /**< (SPI3) SPI Write Protection Mode Register */
#define REG_SPI3_WPSR           (0x400184E8) /**< (SPI3) SPI Write Protection Status Register */
#define REG_SPI3_RPR            (0x40018500) /**< (SPI3) Receive Pointer Register */
#define REG_SPI3_RCR            (0x40018504) /**< (SPI3) Receive Counter Register */
#define REG_SPI3_TPR            (0x40018508) /**< (SPI3) Transmit Pointer Register */
#define REG_SPI3_TCR            (0x4001850C) /**< (SPI3) Transmit Counter Register */
#define REG_SPI3_RNPR           (0x40018510) /**< (SPI3) Receive Next Pointer Register */
#define REG_SPI3_RNCR           (0x40018514) /**< (SPI3) Receive Next Counter Register */
#define REG_SPI3_TNPR           (0x40018518) /**< (SPI3) Transmit Next Pointer Register */
#define REG_SPI3_TNCR           (0x4001851C) /**< (SPI3) Transmit Next Counter Register */
#define REG_SPI3_PTCR           (0x40018520) /**< (SPI3) Transfer Control Register */
#define REG_SPI3_PTSR           (0x40018524) /**< (SPI3) Transfer Status Register */

#else

#define REG_SPI3_CR             (*(__O  uint32_t*)0x40018400U) /**< (SPI3) SPI Control Register */
#define REG_SPI3_MR             (*(__IO uint32_t*)0x40018404U) /**< (SPI3) SPI Mode Register */
#define REG_SPI3_RDR            (*(__I  uint32_t*)0x40018408U) /**< (SPI3) SPI Receive Data Register */
#define REG_SPI3_TDR            (*(__O  uint32_t*)0x4001840CU) /**< (SPI3) SPI Transmit Data Register */
#define REG_SPI3_SR             (*(__I  uint32_t*)0x40018410U) /**< (SPI3) SPI Status Register */
#define REG_SPI3_IER            (*(__O  uint32_t*)0x40018414U) /**< (SPI3) SPI Interrupt Enable Register */
#define REG_SPI3_IDR            (*(__O  uint32_t*)0x40018418U) /**< (SPI3) SPI Interrupt Disable Register */
#define REG_SPI3_IMR            (*(__I  uint32_t*)0x4001841CU) /**< (SPI3) SPI Interrupt Mask Register */
#define REG_SPI3_CSR            (*(__IO uint32_t*)0x40018430U) /**< (SPI3) SPI Chip Select Register 0 */
#define REG_SPI3_CSR0           (*(__IO uint32_t*)0x40018430U) /**< (SPI3) SPI Chip Select Register 0 */
#define REG_SPI3_CSR1           (*(__IO uint32_t*)0x40018434U) /**< (SPI3) SPI Chip Select Register 1 */
#define REG_SPI3_CMPR           (*(__IO uint32_t*)0x40018448U) /**< (SPI3) SPI Comparison Register */
#define REG_SPI3_WPMR           (*(__IO uint32_t*)0x400184E4U) /**< (SPI3) SPI Write Protection Mode Register */
#define REG_SPI3_WPSR           (*(__I  uint32_t*)0x400184E8U) /**< (SPI3) SPI Write Protection Status Register */
#define REG_SPI3_RPR            (*(__IO uint32_t*)0x40018500U) /**< (SPI3) Receive Pointer Register */
#define REG_SPI3_RCR            (*(__IO uint32_t*)0x40018504U) /**< (SPI3) Receive Counter Register */
#define REG_SPI3_TPR            (*(__IO uint32_t*)0x40018508U) /**< (SPI3) Transmit Pointer Register */
#define REG_SPI3_TCR            (*(__IO uint32_t*)0x4001850CU) /**< (SPI3) Transmit Counter Register */
#define REG_SPI3_RNPR           (*(__IO uint32_t*)0x40018510U) /**< (SPI3) Receive Next Pointer Register */
#define REG_SPI3_RNCR           (*(__IO uint32_t*)0x40018514U) /**< (SPI3) Receive Next Counter Register */
#define REG_SPI3_TNPR           (*(__IO uint32_t*)0x40018518U) /**< (SPI3) Transmit Next Pointer Register */
#define REG_SPI3_TNCR           (*(__IO uint32_t*)0x4001851CU) /**< (SPI3) Transmit Next Counter Register */
#define REG_SPI3_PTCR           (*(__O  uint32_t*)0x40018520U) /**< (SPI3) Transfer Control Register */
#define REG_SPI3_PTSR           (*(__I  uint32_t*)0x40018524U) /**< (SPI3) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI3 peripheral ========== */
#define SPI3_DMAC_ID_TX                          17        
#define SPI3_DMAC_ID_RX                          0         

#endif /* _SAMG55_SPI3_INSTANCE_ */
