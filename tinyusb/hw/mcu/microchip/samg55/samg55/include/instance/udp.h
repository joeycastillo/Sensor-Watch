/**
 * \file
 *
 * \brief Instance description for UDP
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
#ifndef _SAMG55_UDP_INSTANCE_H_
#define _SAMG55_UDP_INSTANCE_H_

/* ========== Register definition for UDP peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_UDP_FRM_NUM         (0x40044000) /**< (UDP) Frame Number Register */
#define REG_UDP_GLB_STAT        (0x40044004) /**< (UDP) Global State Register */
#define REG_UDP_FADDR           (0x40044008) /**< (UDP) Function Address Register */
#define REG_UDP_IER             (0x40044010) /**< (UDP) Interrupt Enable Register */
#define REG_UDP_IDR             (0x40044014) /**< (UDP) Interrupt Disable Register */
#define REG_UDP_IMR             (0x40044018) /**< (UDP) Interrupt Mask Register */
#define REG_UDP_ISR             (0x4004401C) /**< (UDP) Interrupt Status Register */
#define REG_UDP_ICR             (0x40044020) /**< (UDP) Interrupt Clear Register */
#define REG_UDP_RST_EP          (0x40044028) /**< (UDP) Reset Endpoint Register */
#define REG_UDP_CSR             (0x40044030) /**< (UDP) Endpoint Control and Status Register 0 */
#define REG_UDP_CSR0            (0x40044030) /**< (UDP) Endpoint Control and Status Register 0 */
#define REG_UDP_CSR1            (0x40044034) /**< (UDP) Endpoint Control and Status Register 1 */
#define REG_UDP_CSR2            (0x40044038) /**< (UDP) Endpoint Control and Status Register 2 */
#define REG_UDP_CSR3            (0x4004403C) /**< (UDP) Endpoint Control and Status Register 3 */
#define REG_UDP_CSR4            (0x40044040) /**< (UDP) Endpoint Control and Status Register 4 */
#define REG_UDP_CSR5            (0x40044044) /**< (UDP) Endpoint Control and Status Register 5 */
#define REG_UDP_FDR             (0x40044050) /**< (UDP) Endpoint FIFO Data Register 0 */
#define REG_UDP_FDR0            (0x40044050) /**< (UDP) Endpoint FIFO Data Register 0 */
#define REG_UDP_FDR1            (0x40044054) /**< (UDP) Endpoint FIFO Data Register 1 */
#define REG_UDP_FDR2            (0x40044058) /**< (UDP) Endpoint FIFO Data Register 2 */
#define REG_UDP_FDR3            (0x4004405C) /**< (UDP) Endpoint FIFO Data Register 3 */
#define REG_UDP_FDR4            (0x40044060) /**< (UDP) Endpoint FIFO Data Register 4 */
#define REG_UDP_FDR5            (0x40044064) /**< (UDP) Endpoint FIFO Data Register 5 */
#define REG_UDP_TXVC            (0x40044074) /**< (UDP) Transceiver Control Register */

#else

#define REG_UDP_FRM_NUM         (*(__I  uint32_t*)0x40044000U) /**< (UDP) Frame Number Register */
#define REG_UDP_GLB_STAT        (*(__IO uint32_t*)0x40044004U) /**< (UDP) Global State Register */
#define REG_UDP_FADDR           (*(__IO uint32_t*)0x40044008U) /**< (UDP) Function Address Register */
#define REG_UDP_IER             (*(__O  uint32_t*)0x40044010U) /**< (UDP) Interrupt Enable Register */
#define REG_UDP_IDR             (*(__O  uint32_t*)0x40044014U) /**< (UDP) Interrupt Disable Register */
#define REG_UDP_IMR             (*(__I  uint32_t*)0x40044018U) /**< (UDP) Interrupt Mask Register */
#define REG_UDP_ISR             (*(__I  uint32_t*)0x4004401CU) /**< (UDP) Interrupt Status Register */
#define REG_UDP_ICR             (*(__O  uint32_t*)0x40044020U) /**< (UDP) Interrupt Clear Register */
#define REG_UDP_RST_EP          (*(__IO uint32_t*)0x40044028U) /**< (UDP) Reset Endpoint Register */
#define REG_UDP_CSR             (*(__IO uint32_t*)0x40044030U) /**< (UDP) Endpoint Control and Status Register 0 */
#define REG_UDP_CSR0            (*(__IO uint32_t*)0x40044030U) /**< (UDP) Endpoint Control and Status Register 0 */
#define REG_UDP_CSR1            (*(__IO uint32_t*)0x40044034U) /**< (UDP) Endpoint Control and Status Register 1 */
#define REG_UDP_CSR2            (*(__IO uint32_t*)0x40044038U) /**< (UDP) Endpoint Control and Status Register 2 */
#define REG_UDP_CSR3            (*(__IO uint32_t*)0x4004403CU) /**< (UDP) Endpoint Control and Status Register 3 */
#define REG_UDP_CSR4            (*(__IO uint32_t*)0x40044040U) /**< (UDP) Endpoint Control and Status Register 4 */
#define REG_UDP_CSR5            (*(__IO uint32_t*)0x40044044U) /**< (UDP) Endpoint Control and Status Register 5 */
#define REG_UDP_FDR             (*(__IO uint32_t*)0x40044050U) /**< (UDP) Endpoint FIFO Data Register 0 */
#define REG_UDP_FDR0            (*(__IO uint32_t*)0x40044050U) /**< (UDP) Endpoint FIFO Data Register 0 */
#define REG_UDP_FDR1            (*(__IO uint32_t*)0x40044054U) /**< (UDP) Endpoint FIFO Data Register 1 */
#define REG_UDP_FDR2            (*(__IO uint32_t*)0x40044058U) /**< (UDP) Endpoint FIFO Data Register 2 */
#define REG_UDP_FDR3            (*(__IO uint32_t*)0x4004405CU) /**< (UDP) Endpoint FIFO Data Register 3 */
#define REG_UDP_FDR4            (*(__IO uint32_t*)0x40044060U) /**< (UDP) Endpoint FIFO Data Register 4 */
#define REG_UDP_FDR5            (*(__IO uint32_t*)0x40044064U) /**< (UDP) Endpoint FIFO Data Register 5 */
#define REG_UDP_TXVC            (*(__IO uint32_t*)0x40044074U) /**< (UDP) Transceiver Control Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for UDP peripheral ========== */
#define UDP_INSTANCE_ID                          48        

#endif /* _SAMG55_UDP_INSTANCE_ */
