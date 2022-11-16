/**
 * \file
 *
 * \brief Instance description for FLEXCOM6
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
#ifndef _SAMG55_FLEXCOM6_INSTANCE_H_
#define _SAMG55_FLEXCOM6_INSTANCE_H_

/* ========== Register definition for FLEXCOM6 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_FLEXCOM6_MR         (0x40040000) /**< (FLEXCOM6) FLEXCOM Mode register */
#define REG_FLEXCOM6_RHR        (0x40040010) /**< (FLEXCOM6) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM6_THR        (0x40040020) /**< (FLEXCOM6) FLEXCOM Transmit Holding Register */

#else

#define REG_FLEXCOM6_MR         (*(__IO uint32_t*)0x40040000U) /**< (FLEXCOM6) FLEXCOM Mode register */
#define REG_FLEXCOM6_RHR        (*(__I  uint32_t*)0x40040010U) /**< (FLEXCOM6) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM6_THR        (*(__IO uint32_t*)0x40040020U) /**< (FLEXCOM6) FLEXCOM Transmit Holding Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for FLEXCOM6 peripheral ========== */
#define FLEXCOM6_INSTANCE_ID                     22        
#define FLEXCOM6_DMAC_ID_TX                      25        
#define FLEXCOM6_DMAC_ID_RX                      11        

#endif /* _SAMG55_FLEXCOM6_INSTANCE_ */
