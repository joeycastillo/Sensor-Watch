/**
 * \file
 *
 * \brief Instance description for FLEXCOM0
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
#ifndef _SAMG55_FLEXCOM0_INSTANCE_H_
#define _SAMG55_FLEXCOM0_INSTANCE_H_

/* ========== Register definition for FLEXCOM0 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_FLEXCOM0_MR         (0x4000C000) /**< (FLEXCOM0) FLEXCOM Mode register */
#define REG_FLEXCOM0_RHR        (0x4000C010) /**< (FLEXCOM0) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM0_THR        (0x4000C020) /**< (FLEXCOM0) FLEXCOM Transmit Holding Register */

#else

#define REG_FLEXCOM0_MR         (*(__IO uint32_t*)0x4000C000U) /**< (FLEXCOM0) FLEXCOM Mode register */
#define REG_FLEXCOM0_RHR        (*(__I  uint32_t*)0x4000C010U) /**< (FLEXCOM0) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM0_THR        (*(__IO uint32_t*)0x4000C020U) /**< (FLEXCOM0) FLEXCOM Transmit Holding Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for FLEXCOM0 peripheral ========== */
#define FLEXCOM0_INSTANCE_ID                     8         
#define FLEXCOM0_DMAC_ID_TX                      24        
#define FLEXCOM0_DMAC_ID_RX                      10        

#endif /* _SAMG55_FLEXCOM0_INSTANCE_ */
