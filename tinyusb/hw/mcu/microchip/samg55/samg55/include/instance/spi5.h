/**
 * \file
 *
 * \brief Instance description for SPI5
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
#ifndef _SAMG55_SPI5_INSTANCE_H_
#define _SAMG55_SPI5_INSTANCE_H_

/* ========== Register definition for SPI5 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI5_CR             (0x40008400) /**< (SPI5) SPI Control Register */
#define REG_SPI5_MR             (0x40008404) /**< (SPI5) SPI Mode Register */
#define REG_SPI5_RDR            (0x40008408) /**< (SPI5) SPI Receive Data Register */
#define REG_SPI5_TDR            (0x4000840C) /**< (SPI5) SPI Transmit Data Register */
#define REG_SPI5_SR             (0x40008410) /**< (SPI5) SPI Status Register */
#define REG_SPI5_IER            (0x40008414) /**< (SPI5) SPI Interrupt Enable Register */
#define REG_SPI5_IDR            (0x40008418) /**< (SPI5) SPI Interrupt Disable Register */
#define REG_SPI5_IMR            (0x4000841C) /**< (SPI5) SPI Interrupt Mask Register */
#define REG_SPI5_CSR            (0x40008430) /**< (SPI5) SPI Chip Select Register 0 */
#define REG_SPI5_CSR0           (0x40008430) /**< (SPI5) SPI Chip Select Register 0 */
#define REG_SPI5_CSR1           (0x40008434) /**< (SPI5) SPI Chip Select Register 1 */
#define REG_SPI5_CMPR           (0x40008448) /**< (SPI5) SPI Comparison Register */
#define REG_SPI5_WPMR           (0x400084E4) /**< (SPI5) SPI Write Protection Mode Register */
#define REG_SPI5_WPSR           (0x400084E8) /**< (SPI5) SPI Write Protection Status Register */
#define REG_SPI5_RPR            (0x40008500) /**< (SPI5) Receive Pointer Register */
#define REG_SPI5_RCR            (0x40008504) /**< (SPI5) Receive Counter Register */
#define REG_SPI5_TPR            (0x40008508) /**< (SPI5) Transmit Pointer Register */
#define REG_SPI5_TCR            (0x4000850C) /**< (SPI5) Transmit Counter Register */
#define REG_SPI5_RNPR           (0x40008510) /**< (SPI5) Receive Next Pointer Register */
#define REG_SPI5_RNCR           (0x40008514) /**< (SPI5) Receive Next Counter Register */
#define REG_SPI5_TNPR           (0x40008518) /**< (SPI5) Transmit Next Pointer Register */
#define REG_SPI5_TNCR           (0x4000851C) /**< (SPI5) Transmit Next Counter Register */
#define REG_SPI5_PTCR           (0x40008520) /**< (SPI5) Transfer Control Register */
#define REG_SPI5_PTSR           (0x40008524) /**< (SPI5) Transfer Status Register */

#else

#define REG_SPI5_CR             (*(__O  uint32_t*)0x40008400U) /**< (SPI5) SPI Control Register */
#define REG_SPI5_MR             (*(__IO uint32_t*)0x40008404U) /**< (SPI5) SPI Mode Register */
#define REG_SPI5_RDR            (*(__I  uint32_t*)0x40008408U) /**< (SPI5) SPI Receive Data Register */
#define REG_SPI5_TDR            (*(__O  uint32_t*)0x4000840CU) /**< (SPI5) SPI Transmit Data Register */
#define REG_SPI5_SR             (*(__I  uint32_t*)0x40008410U) /**< (SPI5) SPI Status Register */
#define REG_SPI5_IER            (*(__O  uint32_t*)0x40008414U) /**< (SPI5) SPI Interrupt Enable Register */
#define REG_SPI5_IDR            (*(__O  uint32_t*)0x40008418U) /**< (SPI5) SPI Interrupt Disable Register */
#define REG_SPI5_IMR            (*(__I  uint32_t*)0x4000841CU) /**< (SPI5) SPI Interrupt Mask Register */
#define REG_SPI5_CSR            (*(__IO uint32_t*)0x40008430U) /**< (SPI5) SPI Chip Select Register 0 */
#define REG_SPI5_CSR0           (*(__IO uint32_t*)0x40008430U) /**< (SPI5) SPI Chip Select Register 0 */
#define REG_SPI5_CSR1           (*(__IO uint32_t*)0x40008434U) /**< (SPI5) SPI Chip Select Register 1 */
#define REG_SPI5_CMPR           (*(__IO uint32_t*)0x40008448U) /**< (SPI5) SPI Comparison Register */
#define REG_SPI5_WPMR           (*(__IO uint32_t*)0x400084E4U) /**< (SPI5) SPI Write Protection Mode Register */
#define REG_SPI5_WPSR           (*(__I  uint32_t*)0x400084E8U) /**< (SPI5) SPI Write Protection Status Register */
#define REG_SPI5_RPR            (*(__IO uint32_t*)0x40008500U) /**< (SPI5) Receive Pointer Register */
#define REG_SPI5_RCR            (*(__IO uint32_t*)0x40008504U) /**< (SPI5) Receive Counter Register */
#define REG_SPI5_TPR            (*(__IO uint32_t*)0x40008508U) /**< (SPI5) Transmit Pointer Register */
#define REG_SPI5_TCR            (*(__IO uint32_t*)0x4000850CU) /**< (SPI5) Transmit Counter Register */
#define REG_SPI5_RNPR           (*(__IO uint32_t*)0x40008510U) /**< (SPI5) Receive Next Pointer Register */
#define REG_SPI5_RNCR           (*(__IO uint32_t*)0x40008514U) /**< (SPI5) Receive Next Counter Register */
#define REG_SPI5_TNPR           (*(__IO uint32_t*)0x40008518U) /**< (SPI5) Transmit Next Pointer Register */
#define REG_SPI5_TNCR           (*(__IO uint32_t*)0x4000851CU) /**< (SPI5) Transmit Next Counter Register */
#define REG_SPI5_PTCR           (*(__O  uint32_t*)0x40008520U) /**< (SPI5) Transfer Control Register */
#define REG_SPI5_PTSR           (*(__I  uint32_t*)0x40008524U) /**< (SPI5) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI5 peripheral ========== */
#define SPI5_DMAC_ID_TX                          27        
#define SPI5_DMAC_ID_RX                          13        

#endif /* _SAMG55_SPI5_INSTANCE_ */
