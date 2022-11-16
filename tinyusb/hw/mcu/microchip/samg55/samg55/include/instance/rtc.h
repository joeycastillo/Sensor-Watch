/**
 * \file
 *
 * \brief Instance description for RTC
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
#ifndef _SAMG55_RTC_INSTANCE_H_
#define _SAMG55_RTC_INSTANCE_H_

/* ========== Register definition for RTC peripheral ========== */
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))

#define REG_RTC_CR              (0x400E1460) /**< (RTC) Control Register */
#define REG_RTC_MR              (0x400E1464) /**< (RTC) Mode Register */
#define REG_RTC_TIMR            (0x400E1468) /**< (RTC) Time Register */
#define REG_RTC_CALR            (0x400E146C) /**< (RTC) Calendar Register */
#define REG_RTC_TIMALR          (0x400E1470) /**< (RTC) Time Alarm Register */
#define REG_RTC_CALALR          (0x400E1474) /**< (RTC) Calendar Alarm Register */
#define REG_RTC_SR              (0x400E1478) /**< (RTC) Status Register */
#define REG_RTC_SCCR            (0x400E147C) /**< (RTC) Status Clear Command Register */
#define REG_RTC_IER             (0x400E1480) /**< (RTC) Interrupt Enable Register */
#define REG_RTC_IDR             (0x400E1484) /**< (RTC) Interrupt Disable Register */
#define REG_RTC_IMR             (0x400E1488) /**< (RTC) Interrupt Mask Register */
#define REG_RTC_VER             (0x400E148C) /**< (RTC) Valid Entry Register */
#define REG_RTC_MSR             (0x400E1530) /**< (RTC) Milliseconds Register */
#define REG_RTC_WPMR            (0x400E1544) /**< (RTC) Write Protection Mode Register */

#else

#define REG_RTC_CR              (*(__IO uint32_t*)0x400E1460U) /**< (RTC) Control Register */
#define REG_RTC_MR              (*(__IO uint32_t*)0x400E1464U) /**< (RTC) Mode Register */
#define REG_RTC_TIMR            (*(__IO uint32_t*)0x400E1468U) /**< (RTC) Time Register */
#define REG_RTC_CALR            (*(__IO uint32_t*)0x400E146CU) /**< (RTC) Calendar Register */
#define REG_RTC_TIMALR          (*(__IO uint32_t*)0x400E1470U) /**< (RTC) Time Alarm Register */
#define REG_RTC_CALALR          (*(__IO uint32_t*)0x400E1474U) /**< (RTC) Calendar Alarm Register */
#define REG_RTC_SR              (*(__I  uint32_t*)0x400E1478U) /**< (RTC) Status Register */
#define REG_RTC_SCCR            (*(__O  uint32_t*)0x400E147CU) /**< (RTC) Status Clear Command Register */
#define REG_RTC_IER             (*(__O  uint32_t*)0x400E1480U) /**< (RTC) Interrupt Enable Register */
#define REG_RTC_IDR             (*(__O  uint32_t*)0x400E1484U) /**< (RTC) Interrupt Disable Register */
#define REG_RTC_IMR             (*(__I  uint32_t*)0x400E1488U) /**< (RTC) Interrupt Mask Register */
#define REG_RTC_VER             (*(__I  uint32_t*)0x400E148CU) /**< (RTC) Valid Entry Register */
#define REG_RTC_MSR             (*(__I  uint32_t*)0x400E1530U) /**< (RTC) Milliseconds Register */
#define REG_RTC_WPMR            (*(__IO uint32_t*)0x400E1544U) /**< (RTC) Write Protection Mode Register */

#endif /* (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance Parameter definitions for RTC peripheral ========== */
#define RTC_INSTANCE_ID                          2         

#endif /* _SAMG55_RTC_INSTANCE_ */
