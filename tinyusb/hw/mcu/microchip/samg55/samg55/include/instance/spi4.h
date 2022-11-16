/**
 * \file
 *
 * \brief Instance description for SPI4
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
#ifndef _SAMG55_SPI4_INSTANCE_H_
#define _SAMG55_SPI4_INSTANCE_H_

/* ========== Register definition for SPI4 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI4_CR             (0x4001C400) /**< (SPI4) SPI Control Register */
#define REG_SPI4_MR             (0x4001C404) /**< (SPI4) SPI Mode Register */
#define REG_SPI4_RDR            (0x4001C408) /**< (SPI4) SPI Receive Data Register */
#define REG_SPI4_TDR            (0x4001C40C) /**< (SPI4) SPI Transmit Data Register */
#define REG_SPI4_SR             (0x4001C410) /**< (SPI4) SPI Status Register */
#define REG_SPI4_IER            (0x4001C414) /**< (SPI4) SPI Interrupt Enable Register */
#define REG_SPI4_IDR            (0x4001C418) /**< (SPI4) SPI Interrupt Disable Register */
#define REG_SPI4_IMR            (0x4001C41C) /**< (SPI4) SPI Interrupt Mask Register */
#define REG_SPI4_CSR            (0x4001C430) /**< (SPI4) SPI Chip Select Register 0 */
#define REG_SPI4_CSR0           (0x4001C430) /**< (SPI4) SPI Chip Select Register 0 */
#define REG_SPI4_CSR1           (0x4001C434) /**< (SPI4) SPI Chip Select Register 1 */
#define REG_SPI4_CMPR           (0x4001C448) /**< (SPI4) SPI Comparison Register */
#define REG_SPI4_WPMR           (0x4001C4E4) /**< (SPI4) SPI Write Protection Mode Register */
#define REG_SPI4_WPSR           (0x4001C4E8) /**< (SPI4) SPI Write Protection Status Register */
#define REG_SPI4_RPR            (0x4001C500) /**< (SPI4) Receive Pointer Register */
#define REG_SPI4_RCR            (0x4001C504) /**< (SPI4) Receive Counter Register */
#define REG_SPI4_TPR            (0x4001C508) /**< (SPI4) Transmit Pointer Register */
#define REG_SPI4_TCR            (0x4001C50C) /**< (SPI4) Transmit Counter Register */
#define REG_SPI4_RNPR           (0x4001C510) /**< (SPI4) Receive Next Pointer Register */
#define REG_SPI4_RNCR           (0x4001C514) /**< (SPI4) Receive Next Counter Register */
#define REG_SPI4_TNPR           (0x4001C518) /**< (SPI4) Transmit Next Pointer Register */
#define REG_SPI4_TNCR           (0x4001C51C) /**< (SPI4) Transmit Next Counter Register */
#define REG_SPI4_PTCR           (0x4001C520) /**< (SPI4) Transfer Control Register */
#define REG_SPI4_PTSR           (0x4001C524) /**< (SPI4) Transfer Status Register */

#else

#define REG_SPI4_CR             (*(__O  uint32_t*)0x4001C400U) /**< (SPI4) SPI Control Register */
#define REG_SPI4_MR             (*(__IO uint32_t*)0x4001C404U) /**< (SPI4) SPI Mode Register */
#define REG_SPI4_RDR            (*(__I  uint32_t*)0x4001C408U) /**< (SPI4) SPI Receive Data Register */
#define REG_SPI4_TDR            (*(__O  uint32_t*)0x4001C40CU) /**< (SPI4) SPI Transmit Data Register */
#define REG_SPI4_SR             (*(__I  uint32_t*)0x4001C410U) /**< (SPI4) SPI Status Register */
#define REG_SPI4_IER            (*(__O  uint32_t*)0x4001C414U) /**< (SPI4) SPI Interrupt Enable Register */
#define REG_SPI4_IDR            (*(__O  uint32_t*)0x4001C418U) /**< (SPI4) SPI Interrupt Disable Register */
#define REG_SPI4_IMR            (*(__I  uint32_t*)0x4001C41CU) /**< (SPI4) SPI Interrupt Mask Register */
#define REG_SPI4_CSR            (*(__IO uint32_t*)0x4001C430U) /**< (SPI4) SPI Chip Select Register 0 */
#define REG_SPI4_CSR0           (*(__IO uint32_t*)0x4001C430U) /**< (SPI4) SPI Chip Select Register 0 */
#define REG_SPI4_CSR1           (*(__IO uint32_t*)0x4001C434U) /**< (SPI4) SPI Chip Select Register 1 */
#define REG_SPI4_CMPR           (*(__IO uint32_t*)0x4001C448U) /**< (SPI4) SPI Comparison Register */
#define REG_SPI4_WPMR           (*(__IO uint32_t*)0x4001C4E4U) /**< (SPI4) SPI Write Protection Mode Register */
#define REG_SPI4_WPSR           (*(__I  uint32_t*)0x4001C4E8U) /**< (SPI4) SPI Write Protection Status Register */
#define REG_SPI4_RPR            (*(__IO uint32_t*)0x4001C500U) /**< (SPI4) Receive Pointer Register */
#define REG_SPI4_RCR            (*(__IO uint32_t*)0x4001C504U) /**< (SPI4) Receive Counter Register */
#define REG_SPI4_TPR            (*(__IO uint32_t*)0x4001C508U) /**< (SPI4) Transmit Pointer Register */
#define REG_SPI4_TCR            (*(__IO uint32_t*)0x4001C50CU) /**< (SPI4) Transmit Counter Register */
#define REG_SPI4_RNPR           (*(__IO uint32_t*)0x4001C510U) /**< (SPI4) Receive Next Pointer Register */
#define REG_SPI4_RNCR           (*(__IO uint32_t*)0x4001C514U) /**< (SPI4) Receive Next Counter Register */
#define REG_SPI4_TNPR           (*(__IO uint32_t*)0x4001C518U) /**< (SPI4) Transmit Next Pointer Register */
#define REG_SPI4_TNCR           (*(__IO uint32_t*)0x4001C51CU) /**< (SPI4) Transmit Next Counter Register */
#define REG_SPI4_PTCR           (*(__O  uint32_t*)0x4001C520U) /**< (SPI4) Transfer Control Register */
#define REG_SPI4_PTSR           (*(__I  uint32_t*)0x4001C524U) /**< (SPI4) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI4 peripheral ========== */
#define SPI4_DMAC_ID_TX                          26        
#define SPI4_DMAC_ID_RX                          12        

#endif /* _SAMG55_SPI4_INSTANCE_ */
