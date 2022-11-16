/**
 * \file
 *
 * \brief Instance description for SPI6
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
#ifndef _SAMG55_SPI6_INSTANCE_H_
#define _SAMG55_SPI6_INSTANCE_H_

/* ========== Register definition for SPI6 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_SPI6_CR             (0x40040400) /**< (SPI6) SPI Control Register */
#define REG_SPI6_MR             (0x40040404) /**< (SPI6) SPI Mode Register */
#define REG_SPI6_RDR            (0x40040408) /**< (SPI6) SPI Receive Data Register */
#define REG_SPI6_TDR            (0x4004040C) /**< (SPI6) SPI Transmit Data Register */
#define REG_SPI6_SR             (0x40040410) /**< (SPI6) SPI Status Register */
#define REG_SPI6_IER            (0x40040414) /**< (SPI6) SPI Interrupt Enable Register */
#define REG_SPI6_IDR            (0x40040418) /**< (SPI6) SPI Interrupt Disable Register */
#define REG_SPI6_IMR            (0x4004041C) /**< (SPI6) SPI Interrupt Mask Register */
#define REG_SPI6_CSR            (0x40040430) /**< (SPI6) SPI Chip Select Register 0 */
#define REG_SPI6_CSR0           (0x40040430) /**< (SPI6) SPI Chip Select Register 0 */
#define REG_SPI6_CSR1           (0x40040434) /**< (SPI6) SPI Chip Select Register 1 */
#define REG_SPI6_CMPR           (0x40040448) /**< (SPI6) SPI Comparison Register */
#define REG_SPI6_WPMR           (0x400404E4) /**< (SPI6) SPI Write Protection Mode Register */
#define REG_SPI6_WPSR           (0x400404E8) /**< (SPI6) SPI Write Protection Status Register */
#define REG_SPI6_RPR            (0x40040500) /**< (SPI6) Receive Pointer Register */
#define REG_SPI6_RCR            (0x40040504) /**< (SPI6) Receive Counter Register */
#define REG_SPI6_TPR            (0x40040508) /**< (SPI6) Transmit Pointer Register */
#define REG_SPI6_TCR            (0x4004050C) /**< (SPI6) Transmit Counter Register */
#define REG_SPI6_RNPR           (0x40040510) /**< (SPI6) Receive Next Pointer Register */
#define REG_SPI6_RNCR           (0x40040514) /**< (SPI6) Receive Next Counter Register */
#define REG_SPI6_TNPR           (0x40040518) /**< (SPI6) Transmit Next Pointer Register */
#define REG_SPI6_TNCR           (0x4004051C) /**< (SPI6) Transmit Next Counter Register */
#define REG_SPI6_PTCR           (0x40040520) /**< (SPI6) Transfer Control Register */
#define REG_SPI6_PTSR           (0x40040524) /**< (SPI6) Transfer Status Register */

#else

#define REG_SPI6_CR             (*(__O  uint32_t*)0x40040400U) /**< (SPI6) SPI Control Register */
#define REG_SPI6_MR             (*(__IO uint32_t*)0x40040404U) /**< (SPI6) SPI Mode Register */
#define REG_SPI6_RDR            (*(__I  uint32_t*)0x40040408U) /**< (SPI6) SPI Receive Data Register */
#define REG_SPI6_TDR            (*(__O  uint32_t*)0x4004040CU) /**< (SPI6) SPI Transmit Data Register */
#define REG_SPI6_SR             (*(__I  uint32_t*)0x40040410U) /**< (SPI6) SPI Status Register */
#define REG_SPI6_IER            (*(__O  uint32_t*)0x40040414U) /**< (SPI6) SPI Interrupt Enable Register */
#define REG_SPI6_IDR            (*(__O  uint32_t*)0x40040418U) /**< (SPI6) SPI Interrupt Disable Register */
#define REG_SPI6_IMR            (*(__I  uint32_t*)0x4004041CU) /**< (SPI6) SPI Interrupt Mask Register */
#define REG_SPI6_CSR            (*(__IO uint32_t*)0x40040430U) /**< (SPI6) SPI Chip Select Register 0 */
#define REG_SPI6_CSR0           (*(__IO uint32_t*)0x40040430U) /**< (SPI6) SPI Chip Select Register 0 */
#define REG_SPI6_CSR1           (*(__IO uint32_t*)0x40040434U) /**< (SPI6) SPI Chip Select Register 1 */
#define REG_SPI6_CMPR           (*(__IO uint32_t*)0x40040448U) /**< (SPI6) SPI Comparison Register */
#define REG_SPI6_WPMR           (*(__IO uint32_t*)0x400404E4U) /**< (SPI6) SPI Write Protection Mode Register */
#define REG_SPI6_WPSR           (*(__I  uint32_t*)0x400404E8U) /**< (SPI6) SPI Write Protection Status Register */
#define REG_SPI6_RPR            (*(__IO uint32_t*)0x40040500U) /**< (SPI6) Receive Pointer Register */
#define REG_SPI6_RCR            (*(__IO uint32_t*)0x40040504U) /**< (SPI6) Receive Counter Register */
#define REG_SPI6_TPR            (*(__IO uint32_t*)0x40040508U) /**< (SPI6) Transmit Pointer Register */
#define REG_SPI6_TCR            (*(__IO uint32_t*)0x4004050CU) /**< (SPI6) Transmit Counter Register */
#define REG_SPI6_RNPR           (*(__IO uint32_t*)0x40040510U) /**< (SPI6) Receive Next Pointer Register */
#define REG_SPI6_RNCR           (*(__IO uint32_t*)0x40040514U) /**< (SPI6) Receive Next Counter Register */
#define REG_SPI6_TNPR           (*(__IO uint32_t*)0x40040518U) /**< (SPI6) Transmit Next Pointer Register */
#define REG_SPI6_TNCR           (*(__IO uint32_t*)0x4004051CU) /**< (SPI6) Transmit Next Counter Register */
#define REG_SPI6_PTCR           (*(__O  uint32_t*)0x40040520U) /**< (SPI6) Transfer Control Register */
#define REG_SPI6_PTSR           (*(__I  uint32_t*)0x40040524U) /**< (SPI6) Transfer Status Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for SPI6 peripheral ========== */
#define SPI6_DMAC_ID_TX                          25        
#define SPI6_DMAC_ID_RX                          11        

#endif /* _SAMG55_SPI6_INSTANCE_ */
