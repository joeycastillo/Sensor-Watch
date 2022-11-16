/**
 * \file
 *
 * \brief Instance description for FLEXCOM1
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
#ifndef _SAMG55_FLEXCOM1_INSTANCE_H_
#define _SAMG55_FLEXCOM1_INSTANCE_H_

/* ========== Register definition for FLEXCOM1 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_FLEXCOM1_MR         (0x40020000) /**< (FLEXCOM1) FLEXCOM Mode register */
#define REG_FLEXCOM1_RHR        (0x40020010) /**< (FLEXCOM1) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM1_THR        (0x40020020) /**< (FLEXCOM1) FLEXCOM Transmit Holding Register */

#else

#define REG_FLEXCOM1_MR         (*(__IO uint32_t*)0x40020000U) /**< (FLEXCOM1) FLEXCOM Mode register */
#define REG_FLEXCOM1_RHR        (*(__I  uint32_t*)0x40020010U) /**< (FLEXCOM1) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM1_THR        (*(__IO uint32_t*)0x40020020U) /**< (FLEXCOM1) FLEXCOM Transmit Holding Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for FLEXCOM1 peripheral ========== */
#define FLEXCOM1_INSTANCE_ID                     9         
#define FLEXCOM1_DMAC_ID_TX                      23        
#define FLEXCOM1_DMAC_ID_RX                      9         

#endif /* _SAMG55_FLEXCOM1_INSTANCE_ */
