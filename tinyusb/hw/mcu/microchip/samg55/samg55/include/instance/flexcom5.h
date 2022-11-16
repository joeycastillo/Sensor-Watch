/**
 * \file
 *
 * \brief Instance description for FLEXCOM5
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
#ifndef _SAMG55_FLEXCOM5_INSTANCE_H_
#define _SAMG55_FLEXCOM5_INSTANCE_H_

/* ========== Register definition for FLEXCOM5 peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_FLEXCOM5_MR         (0x40008000) /**< (FLEXCOM5) FLEXCOM Mode register */
#define REG_FLEXCOM5_RHR        (0x40008010) /**< (FLEXCOM5) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM5_THR        (0x40008020) /**< (FLEXCOM5) FLEXCOM Transmit Holding Register */

#else

#define REG_FLEXCOM5_MR         (*(__IO uint32_t*)0x40008000U) /**< (FLEXCOM5) FLEXCOM Mode register */
#define REG_FLEXCOM5_RHR        (*(__I  uint32_t*)0x40008010U) /**< (FLEXCOM5) FLEXCOM Receive Holding Register */
#define REG_FLEXCOM5_THR        (*(__IO uint32_t*)0x40008020U) /**< (FLEXCOM5) FLEXCOM Transmit Holding Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for FLEXCOM5 peripheral ========== */
#define FLEXCOM5_INSTANCE_ID                     21        
#define FLEXCOM5_DMAC_ID_TX                      27        
#define FLEXCOM5_DMAC_ID_RX                      13        

#endif /* _SAMG55_FLEXCOM5_INSTANCE_ */
