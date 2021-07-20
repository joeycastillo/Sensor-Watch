/**
 * \file
 *
 * \brief Instance description for GCLK
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAML22_GCLK_INSTANCE_
#define _SAML22_GCLK_INSTANCE_

/* ========== Register definition for GCLK peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_GCLK_CTRLA             (0x40001C00U) /**< \brief (GCLK) Control */
#define REG_GCLK_SYNCBUSY          (0x40001C04U) /**< \brief (GCLK) Synchronization Busy */
#define REG_GCLK_GENCTRL0          (0x40001C20U) /**< \brief (GCLK) Generic Clock Generator Control 0 */
#define REG_GCLK_GENCTRL1          (0x40001C24U) /**< \brief (GCLK) Generic Clock Generator Control 1 */
#define REG_GCLK_GENCTRL2          (0x40001C28U) /**< \brief (GCLK) Generic Clock Generator Control 2 */
#define REG_GCLK_GENCTRL3          (0x40001C2CU) /**< \brief (GCLK) Generic Clock Generator Control 3 */
#define REG_GCLK_GENCTRL4          (0x40001C30U) /**< \brief (GCLK) Generic Clock Generator Control 4 */
#define REG_GCLK_PCHCTRL0          (0x40001C80U) /**< \brief (GCLK) Peripheral Clock Control 0 */
#define REG_GCLK_PCHCTRL1          (0x40001C84U) /**< \brief (GCLK) Peripheral Clock Control 1 */
#define REG_GCLK_PCHCTRL2          (0x40001C88U) /**< \brief (GCLK) Peripheral Clock Control 2 */
#define REG_GCLK_PCHCTRL3          (0x40001C8CU) /**< \brief (GCLK) Peripheral Clock Control 3 */
#define REG_GCLK_PCHCTRL4          (0x40001C90U) /**< \brief (GCLK) Peripheral Clock Control 4 */
#define REG_GCLK_PCHCTRL5          (0x40001C94U) /**< \brief (GCLK) Peripheral Clock Control 5 */
#define REG_GCLK_PCHCTRL6          (0x40001C98U) /**< \brief (GCLK) Peripheral Clock Control 6 */
#define REG_GCLK_PCHCTRL7          (0x40001C9CU) /**< \brief (GCLK) Peripheral Clock Control 7 */
#define REG_GCLK_PCHCTRL8          (0x40001CA0U) /**< \brief (GCLK) Peripheral Clock Control 8 */
#define REG_GCLK_PCHCTRL9          (0x40001CA4U) /**< \brief (GCLK) Peripheral Clock Control 9 */
#define REG_GCLK_PCHCTRL10         (0x40001CA8U) /**< \brief (GCLK) Peripheral Clock Control 10 */
#define REG_GCLK_PCHCTRL11         (0x40001CACU) /**< \brief (GCLK) Peripheral Clock Control 11 */
#define REG_GCLK_PCHCTRL12         (0x40001CB0U) /**< \brief (GCLK) Peripheral Clock Control 12 */
#define REG_GCLK_PCHCTRL13         (0x40001CB4U) /**< \brief (GCLK) Peripheral Clock Control 13 */
#define REG_GCLK_PCHCTRL14         (0x40001CB8U) /**< \brief (GCLK) Peripheral Clock Control 14 */
#define REG_GCLK_PCHCTRL15         (0x40001CBCU) /**< \brief (GCLK) Peripheral Clock Control 15 */
#define REG_GCLK_PCHCTRL16         (0x40001CC0U) /**< \brief (GCLK) Peripheral Clock Control 16 */
#define REG_GCLK_PCHCTRL17         (0x40001CC4U) /**< \brief (GCLK) Peripheral Clock Control 17 */
#define REG_GCLK_PCHCTRL18         (0x40001CC8U) /**< \brief (GCLK) Peripheral Clock Control 18 */
#define REG_GCLK_PCHCTRL19         (0x40001CCCU) /**< \brief (GCLK) Peripheral Clock Control 19 */
#define REG_GCLK_PCHCTRL20         (0x40001CD0U) /**< \brief (GCLK) Peripheral Clock Control 20 */
#define REG_GCLK_PCHCTRL21         (0x40001CD4U) /**< \brief (GCLK) Peripheral Clock Control 21 */
#define REG_GCLK_PCHCTRL22         (0x40001CD8U) /**< \brief (GCLK) Peripheral Clock Control 22 */
#define REG_GCLK_PCHCTRL23         (0x40001CDCU) /**< \brief (GCLK) Peripheral Clock Control 23 */
#define REG_GCLK_PCHCTRL24         (0x40001CE0U) /**< \brief (GCLK) Peripheral Clock Control 24 */
#define REG_GCLK_PCHCTRL25         (0x40001CE4U) /**< \brief (GCLK) Peripheral Clock Control 25 */
#define REG_GCLK_PCHCTRL26         (0x40001CE8U) /**< \brief (GCLK) Peripheral Clock Control 26 */
#define REG_GCLK_PCHCTRL27         (0x40001CECU) /**< \brief (GCLK) Peripheral Clock Control 27 */
#define REG_GCLK_PCHCTRL28         (0x40001CF0U) /**< \brief (GCLK) Peripheral Clock Control 28 */
#define REG_GCLK_PCHCTRL29         (0x40001CF4U) /**< \brief (GCLK) Peripheral Clock Control 29 */
#else
#define REG_GCLK_CTRLA             (*(RwReg8 *)0x40001C00U) /**< \brief (GCLK) Control */
#define REG_GCLK_SYNCBUSY          (*(RoReg  *)0x40001C04U) /**< \brief (GCLK) Synchronization Busy */
#define REG_GCLK_GENCTRL0          (*(RwReg  *)0x40001C20U) /**< \brief (GCLK) Generic Clock Generator Control 0 */
#define REG_GCLK_GENCTRL1          (*(RwReg  *)0x40001C24U) /**< \brief (GCLK) Generic Clock Generator Control 1 */
#define REG_GCLK_GENCTRL2          (*(RwReg  *)0x40001C28U) /**< \brief (GCLK) Generic Clock Generator Control 2 */
#define REG_GCLK_GENCTRL3          (*(RwReg  *)0x40001C2CU) /**< \brief (GCLK) Generic Clock Generator Control 3 */
#define REG_GCLK_GENCTRL4          (*(RwReg  *)0x40001C30U) /**< \brief (GCLK) Generic Clock Generator Control 4 */
#define REG_GCLK_PCHCTRL0          (*(RwReg  *)0x40001C80U) /**< \brief (GCLK) Peripheral Clock Control 0 */
#define REG_GCLK_PCHCTRL1          (*(RwReg  *)0x40001C84U) /**< \brief (GCLK) Peripheral Clock Control 1 */
#define REG_GCLK_PCHCTRL2          (*(RwReg  *)0x40001C88U) /**< \brief (GCLK) Peripheral Clock Control 2 */
#define REG_GCLK_PCHCTRL3          (*(RwReg  *)0x40001C8CU) /**< \brief (GCLK) Peripheral Clock Control 3 */
#define REG_GCLK_PCHCTRL4          (*(RwReg  *)0x40001C90U) /**< \brief (GCLK) Peripheral Clock Control 4 */
#define REG_GCLK_PCHCTRL5          (*(RwReg  *)0x40001C94U) /**< \brief (GCLK) Peripheral Clock Control 5 */
#define REG_GCLK_PCHCTRL6          (*(RwReg  *)0x40001C98U) /**< \brief (GCLK) Peripheral Clock Control 6 */
#define REG_GCLK_PCHCTRL7          (*(RwReg  *)0x40001C9CU) /**< \brief (GCLK) Peripheral Clock Control 7 */
#define REG_GCLK_PCHCTRL8          (*(RwReg  *)0x40001CA0U) /**< \brief (GCLK) Peripheral Clock Control 8 */
#define REG_GCLK_PCHCTRL9          (*(RwReg  *)0x40001CA4U) /**< \brief (GCLK) Peripheral Clock Control 9 */
#define REG_GCLK_PCHCTRL10         (*(RwReg  *)0x40001CA8U) /**< \brief (GCLK) Peripheral Clock Control 10 */
#define REG_GCLK_PCHCTRL11         (*(RwReg  *)0x40001CACU) /**< \brief (GCLK) Peripheral Clock Control 11 */
#define REG_GCLK_PCHCTRL12         (*(RwReg  *)0x40001CB0U) /**< \brief (GCLK) Peripheral Clock Control 12 */
#define REG_GCLK_PCHCTRL13         (*(RwReg  *)0x40001CB4U) /**< \brief (GCLK) Peripheral Clock Control 13 */
#define REG_GCLK_PCHCTRL14         (*(RwReg  *)0x40001CB8U) /**< \brief (GCLK) Peripheral Clock Control 14 */
#define REG_GCLK_PCHCTRL15         (*(RwReg  *)0x40001CBCU) /**< \brief (GCLK) Peripheral Clock Control 15 */
#define REG_GCLK_PCHCTRL16         (*(RwReg  *)0x40001CC0U) /**< \brief (GCLK) Peripheral Clock Control 16 */
#define REG_GCLK_PCHCTRL17         (*(RwReg  *)0x40001CC4U) /**< \brief (GCLK) Peripheral Clock Control 17 */
#define REG_GCLK_PCHCTRL18         (*(RwReg  *)0x40001CC8U) /**< \brief (GCLK) Peripheral Clock Control 18 */
#define REG_GCLK_PCHCTRL19         (*(RwReg  *)0x40001CCCU) /**< \brief (GCLK) Peripheral Clock Control 19 */
#define REG_GCLK_PCHCTRL20         (*(RwReg  *)0x40001CD0U) /**< \brief (GCLK) Peripheral Clock Control 20 */
#define REG_GCLK_PCHCTRL21         (*(RwReg  *)0x40001CD4U) /**< \brief (GCLK) Peripheral Clock Control 21 */
#define REG_GCLK_PCHCTRL22         (*(RwReg  *)0x40001CD8U) /**< \brief (GCLK) Peripheral Clock Control 22 */
#define REG_GCLK_PCHCTRL23         (*(RwReg  *)0x40001CDCU) /**< \brief (GCLK) Peripheral Clock Control 23 */
#define REG_GCLK_PCHCTRL24         (*(RwReg  *)0x40001CE0U) /**< \brief (GCLK) Peripheral Clock Control 24 */
#define REG_GCLK_PCHCTRL25         (*(RwReg  *)0x40001CE4U) /**< \brief (GCLK) Peripheral Clock Control 25 */
#define REG_GCLK_PCHCTRL26         (*(RwReg  *)0x40001CE8U) /**< \brief (GCLK) Peripheral Clock Control 26 */
#define REG_GCLK_PCHCTRL27         (*(RwReg  *)0x40001CECU) /**< \brief (GCLK) Peripheral Clock Control 27 */
#define REG_GCLK_PCHCTRL28         (*(RwReg  *)0x40001CF0U) /**< \brief (GCLK) Peripheral Clock Control 28 */
#define REG_GCLK_PCHCTRL29         (*(RwReg  *)0x40001CF4U) /**< \brief (GCLK) Peripheral Clock Control 29 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for GCLK peripheral ========== */
#define GCLK_GENDIV_BITS            16      
#define GCLK_GEN_BITS               3       
#define GCLK_GEN_NUM                5        // Number of Generic Clock Generators
#define GCLK_GEN_NUM_MSB            4        // Number of Generic Clock Generators - 1
#define GCLK_GEN_SOURCE_NUM_MSB     7        // Number of Generic Clock Sources - 1
#define GCLK_NUM                    30       // Number of Generic Clock Users
#define GCLK_SOURCE_BITS            3       
#define GCLK_SOURCE_DFLL48M         6       
#define GCLK_SOURCE_FDPLL           7       
#define GCLK_SOURCE_GCLKGEN1        2       
#define GCLK_SOURCE_GCLKIN          1       
#define GCLK_SOURCE_NUM             8        // Number of Generic Clock Sources
#define GCLK_SOURCE_OSCULP32K       3       
#define GCLK_SOURCE_OSC16M          5       
#define GCLK_SOURCE_XOSC            0       
#define GCLK_SOURCE_XOSC32K         4       

#endif /* _SAML22_GCLK_INSTANCE_ */
