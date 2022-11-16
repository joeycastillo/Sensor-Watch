/**
 * \file
 *
 * \brief Instance description for SPI0
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
#ifndef _SAMG55_SPI0_INSTANCE_H_
#define _SAMG55_SPI0_INSTANCE_H_

/* ========== Register definition for SPI0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI0_CR             (0x4000C400) /**< (SPI0) SPI Control Register */
#define REG_SPI0_MR             (0x4000C404) /**< (SPI0) SPI Mode Register */
#define REG_SPI0_RDR            (0x4000C408) /**< (SPI0) SPI Receive Data Register */
#define REG_SPI0_TDR            (0x4000C40C) /**< (SPI0) SPI Transmit Data Register */
#define REG_SPI0_SR             (0x4000C410) /**< (SPI0) SPI Status Register */
#define REG_SPI0_IER            (0x4000C414) /**< (SPI0) SPI Interrupt Enable Register */
#define REG_SPI0_IDR            (0x4000C418) /**< (SPI0) SPI Interrupt Disable Register */
#define REG_SPI0_IMR            (0x4000C41C) /**< (SPI0) SPI Interrupt Mask Register */
#define REG_SPI0_CSR            (0x4000C430) /**< (SPI0) SPI Chip Select Register 0 */
#define REG_SPI0_CSR0           (0x4000C430) /**< (SPI0) SPI Chip Select Register 0 */
#define REG_SPI0_CSR1           (0x4000C434) /**< (SPI0) SPI Chip Select Register 1 */
#define REG_SPI0_CMPR           (0x4000C448) /**< (SPI0) SPI Comparison Register */
#define REG_SPI0_WPMR           (0x4000C4E4) /**< (SPI0) SPI Write Protection Mode Register */
#define REG_SPI0_WPSR           (0x4000C4E8) /**< (SPI0) SPI Write Protection Status Register */
#define REG_SPI0_RPR            (0x4000C500) /**< (SPI0) Receive Pointer Register */
#define REG_SPI0_RCR            (0x4000C504) /**< (SPI0) Receive Counter Register */
#define REG_SPI0_TPR            (0x4000C508) /**< (SPI0) Transmit Pointer Register */
#define REG_SPI0_TCR            (0x4000C50C) /**< (SPI0) Transmit Counter Register */
#define REG_SPI0_RNPR           (0x4000C510) /**< (SPI0) Receive Next Pointer Register */
#define REG_SPI0_RNCR           (0x4000C514) /**< (SPI0) Receive Next Counter Register */
#define REG_SPI0_TNPR           (0x4000C518) /**< (SPI0) Transmit Next Pointer Register */
#define REG_SPI0_TNCR           (0x4000C51C) /**< (SPI0) Transmit Next Counter Register */
#define REG_SPI0_PTCR           (0x4000C520) /**< (SPI0) Transfer Control Register */
#define REG_SPI0_PTSR           (0x4000C524) /**< (SPI0) Transfer Status Register */

#else

#define REG_SPI0_CR             (*(__O  uint32_t*)0x4000C400U) /**< (SPI0) SPI Control Register */
#define REG_SPI0_MR             (*(__IO uint32_t*)0x4000C404U) /**< (SPI0) SPI Mode Register */
#define REG_SPI0_RDR            (*(__I  uint32_t*)0x4000C408U) /**< (SPI0) SPI Receive Data Register */
#define REG_SPI0_TDR            (*(__O  uint32_t*)0x4000C40CU) /**< (SPI0) SPI Transmit Data Register */
#define REG_SPI0_SR             (*(__I  uint32_t*)0x4000C410U) /**< (SPI0) SPI Status Register */
#define REG_SPI0_IER            (*(__O  uint32_t*)0x4000C414U) /**< (SPI0) SPI Interrupt Enable Register */
#define REG_SPI0_IDR            (*(__O  uint32_t*)0x4000C418U) /**< (SPI0) SPI Interrupt Disable Register */
#define REG_SPI0_IMR            (*(__I  uint32_t*)0x4000C41CU) /**< (SPI0) SPI Interrupt Mask Register */
#define REG_SPI0_CSR            (*(__IO uint32_t*)0x4000C430U) /**< (SPI0) SPI Chip Select Register 0 */
#define REG_SPI0_CSR0           (*(__IO uint32_t*)0x4000C430U) /**< (SPI0) SPI Chip Select Register 0 */
#define REG_SPI0_CSR1           (*(__IO uint32_t*)0x4000C434U) /**< (SPI0) SPI Chip Select Register 1 */
#define REG_SPI0_CMPR           (*(__IO uint32_t*)0x4000C448U) /**< (SPI0) SPI Comparison Register */
#define REG_SPI0_WPMR           (*(__IO uint32_t*)0x4000C4E4U) /**< (SPI0) SPI Write Protection Mode Register */
#define REG_SPI0_WPSR           (*(__I  uint32_t*)0x4000C4E8U) /**< (SPI0) SPI Write Protection Status Register */
#define REG_SPI0_RPR            (*(__IO uint32_t*)0x4000C500U) /**< (SPI0) Receive Pointer Register */
#define REG_SPI0_RCR            (*(__IO uint32_t*)0x4000C504U) /**< (SPI0) Receive Counter Register */
#define REG_SPI0_TPR            (*(__IO uint32_t*)0x4000C508U) /**< (SPI0) Transmit Pointer Register */
#define REG_SPI0_TCR            (*(__IO uint32_t*)0x4000C50CU) /**< (SPI0) Transmit Counter Register */
#define REG_SPI0_RNPR           (*(__IO uint32_t*)0x4000C510U) /**< (SPI0) Receive Next Pointer Register */
#define REG_SPI0_RNCR           (*(__IO uint32_t*)0x4000C514U) /**< (SPI0) Receive Next Counter Register */
#define REG_SPI0_TNPR           (*(__IO uint32_t*)0x4000C518U) /**< (SPI0) Transmit Next Pointer Register */
#define REG_SPI0_TNCR           (*(__IO uint32_t*)0x4000C51CU) /**< (SPI0) Transmit Next Counter Register */
#define REG_SPI0_PTCR           (*(__O  uint32_t*)0x4000C520U) /**< (SPI0) Transfer Control Register */
#define REG_SPI0_PTSR           (*(__I  uint32_t*)0x4000C524U) /**< (SPI0) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI0 peripheral ========== */
#define SPI0_DMAC_ID_TX                          24        
#define SPI0_DMAC_ID_RX                          10        

#endif /* _SAMG55_SPI0_INSTANCE_ */
