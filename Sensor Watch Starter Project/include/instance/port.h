/**
 * \file
 *
 * \brief Instance description for PORT
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

#ifndef _SAML22_PORT_INSTANCE_
#define _SAML22_PORT_INSTANCE_

/* ========== Register definition for PORT peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PORT_DIR0              (0x41006000U) /**< \brief (PORT) Data Direction 0 */
#define REG_PORT_DIRCLR0           (0x41006004U) /**< \brief (PORT) Data Direction Clear 0 */
#define REG_PORT_DIRSET0           (0x41006008U) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_DIRTGL0           (0x4100600CU) /**< \brief (PORT) Data Direction Toggle 0 */
#define REG_PORT_OUT0              (0x41006010U) /**< \brief (PORT) Data Output Value 0 */
#define REG_PORT_OUTCLR0           (0x41006014U) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0           (0x41006018U) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0           (0x4100601CU) /**< \brief (PORT) Data Output Value Toggle 0 */
#define REG_PORT_IN0               (0x41006020U) /**< \brief (PORT) Data Input Value 0 */
#define REG_PORT_CTRL0             (0x41006024U) /**< \brief (PORT) Control 0 */
#define REG_PORT_WRCONFIG0         (0x41006028U) /**< \brief (PORT) Write Configuration 0 */
#define REG_PORT_EVCTRL0           (0x4100602CU) /**< \brief (PORT) Event Input Control 0 */
#define REG_PORT_PMUX0             (0x41006030U) /**< \brief (PORT) Peripheral Multiplexing 0 */
#define REG_PORT_PINCFG0           (0x41006040U) /**< \brief (PORT) Pin Configuration 0 */
#define REG_PORT_DIR1              (0x41006080U) /**< \brief (PORT) Data Direction 1 */
#define REG_PORT_DIRCLR1           (0x41006084U) /**< \brief (PORT) Data Direction Clear 1 */
#define REG_PORT_DIRSET1           (0x41006088U) /**< \brief (PORT) Data Direction Set 1 */
#define REG_PORT_DIRTGL1           (0x4100608CU) /**< \brief (PORT) Data Direction Toggle 1 */
#define REG_PORT_OUT1              (0x41006090U) /**< \brief (PORT) Data Output Value 1 */
#define REG_PORT_OUTCLR1           (0x41006094U) /**< \brief (PORT) Data Output Value Clear 1 */
#define REG_PORT_OUTSET1           (0x41006098U) /**< \brief (PORT) Data Output Value Set 1 */
#define REG_PORT_OUTTGL1           (0x4100609CU) /**< \brief (PORT) Data Output Value Toggle 1 */
#define REG_PORT_IN1               (0x410060A0U) /**< \brief (PORT) Data Input Value 1 */
#define REG_PORT_CTRL1             (0x410060A4U) /**< \brief (PORT) Control 1 */
#define REG_PORT_WRCONFIG1         (0x410060A8U) /**< \brief (PORT) Write Configuration 1 */
#define REG_PORT_EVCTRL1           (0x410060ACU) /**< \brief (PORT) Event Input Control 1 */
#define REG_PORT_PMUX1             (0x410060B0U) /**< \brief (PORT) Peripheral Multiplexing 1 */
#define REG_PORT_PINCFG1           (0x410060C0U) /**< \brief (PORT) Pin Configuration 1 */
#define REG_PORT_DIR2              (0x41006100U) /**< \brief (PORT) Data Direction 2 */
#define REG_PORT_DIRCLR2           (0x41006104U) /**< \brief (PORT) Data Direction Clear 2 */
#define REG_PORT_DIRSET2           (0x41006108U) /**< \brief (PORT) Data Direction Set 2 */
#define REG_PORT_DIRTGL2           (0x4100610CU) /**< \brief (PORT) Data Direction Toggle 2 */
#define REG_PORT_OUT2              (0x41006110U) /**< \brief (PORT) Data Output Value 2 */
#define REG_PORT_OUTCLR2           (0x41006114U) /**< \brief (PORT) Data Output Value Clear 2 */
#define REG_PORT_OUTSET2           (0x41006118U) /**< \brief (PORT) Data Output Value Set 2 */
#define REG_PORT_OUTTGL2           (0x4100611CU) /**< \brief (PORT) Data Output Value Toggle 2 */
#define REG_PORT_IN2               (0x41006120U) /**< \brief (PORT) Data Input Value 2 */
#define REG_PORT_CTRL2             (0x41006124U) /**< \brief (PORT) Control 2 */
#define REG_PORT_WRCONFIG2         (0x41006128U) /**< \brief (PORT) Write Configuration 2 */
#define REG_PORT_EVCTRL2           (0x4100612CU) /**< \brief (PORT) Event Input Control 2 */
#define REG_PORT_PMUX2             (0x41006130U) /**< \brief (PORT) Peripheral Multiplexing 2 */
#define REG_PORT_PINCFG2           (0x41006140U) /**< \brief (PORT) Pin Configuration 2 */
#else
#define REG_PORT_DIR0              (*(RwReg  *)0x41006000U) /**< \brief (PORT) Data Direction 0 */
#define REG_PORT_DIRCLR0           (*(RwReg  *)0x41006004U) /**< \brief (PORT) Data Direction Clear 0 */
#define REG_PORT_DIRSET0           (*(RwReg  *)0x41006008U) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_DIRTGL0           (*(RwReg  *)0x4100600CU) /**< \brief (PORT) Data Direction Toggle 0 */
#define REG_PORT_OUT0              (*(RwReg  *)0x41006010U) /**< \brief (PORT) Data Output Value 0 */
#define REG_PORT_OUTCLR0           (*(RwReg  *)0x41006014U) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0           (*(RwReg  *)0x41006018U) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0           (*(RwReg  *)0x4100601CU) /**< \brief (PORT) Data Output Value Toggle 0 */
#define REG_PORT_IN0               (*(RoReg  *)0x41006020U) /**< \brief (PORT) Data Input Value 0 */
#define REG_PORT_CTRL0             (*(RwReg  *)0x41006024U) /**< \brief (PORT) Control 0 */
#define REG_PORT_WRCONFIG0         (*(WoReg  *)0x41006028U) /**< \brief (PORT) Write Configuration 0 */
#define REG_PORT_EVCTRL0           (*(RwReg  *)0x4100602CU) /**< \brief (PORT) Event Input Control 0 */
#define REG_PORT_PMUX0             (*(RwReg  *)0x41006030U) /**< \brief (PORT) Peripheral Multiplexing 0 */
#define REG_PORT_PINCFG0           (*(RwReg  *)0x41006040U) /**< \brief (PORT) Pin Configuration 0 */
#define REG_PORT_DIR1              (*(RwReg  *)0x41006080U) /**< \brief (PORT) Data Direction 1 */
#define REG_PORT_DIRCLR1           (*(RwReg  *)0x41006084U) /**< \brief (PORT) Data Direction Clear 1 */
#define REG_PORT_DIRSET1           (*(RwReg  *)0x41006088U) /**< \brief (PORT) Data Direction Set 1 */
#define REG_PORT_DIRTGL1           (*(RwReg  *)0x4100608CU) /**< \brief (PORT) Data Direction Toggle 1 */
#define REG_PORT_OUT1              (*(RwReg  *)0x41006090U) /**< \brief (PORT) Data Output Value 1 */
#define REG_PORT_OUTCLR1           (*(RwReg  *)0x41006094U) /**< \brief (PORT) Data Output Value Clear 1 */
#define REG_PORT_OUTSET1           (*(RwReg  *)0x41006098U) /**< \brief (PORT) Data Output Value Set 1 */
#define REG_PORT_OUTTGL1           (*(RwReg  *)0x4100609CU) /**< \brief (PORT) Data Output Value Toggle 1 */
#define REG_PORT_IN1               (*(RoReg  *)0x410060A0U) /**< \brief (PORT) Data Input Value 1 */
#define REG_PORT_CTRL1             (*(RwReg  *)0x410060A4U) /**< \brief (PORT) Control 1 */
#define REG_PORT_WRCONFIG1         (*(WoReg  *)0x410060A8U) /**< \brief (PORT) Write Configuration 1 */
#define REG_PORT_EVCTRL1           (*(RwReg  *)0x410060ACU) /**< \brief (PORT) Event Input Control 1 */
#define REG_PORT_PMUX1             (*(RwReg  *)0x410060B0U) /**< \brief (PORT) Peripheral Multiplexing 1 */
#define REG_PORT_PINCFG1           (*(RwReg  *)0x410060C0U) /**< \brief (PORT) Pin Configuration 1 */
#define REG_PORT_DIR2              (*(RwReg  *)0x41006100U) /**< \brief (PORT) Data Direction 2 */
#define REG_PORT_DIRCLR2           (*(RwReg  *)0x41006104U) /**< \brief (PORT) Data Direction Clear 2 */
#define REG_PORT_DIRSET2           (*(RwReg  *)0x41006108U) /**< \brief (PORT) Data Direction Set 2 */
#define REG_PORT_DIRTGL2           (*(RwReg  *)0x4100610CU) /**< \brief (PORT) Data Direction Toggle 2 */
#define REG_PORT_OUT2              (*(RwReg  *)0x41006110U) /**< \brief (PORT) Data Output Value 2 */
#define REG_PORT_OUTCLR2           (*(RwReg  *)0x41006114U) /**< \brief (PORT) Data Output Value Clear 2 */
#define REG_PORT_OUTSET2           (*(RwReg  *)0x41006118U) /**< \brief (PORT) Data Output Value Set 2 */
#define REG_PORT_OUTTGL2           (*(RwReg  *)0x4100611CU) /**< \brief (PORT) Data Output Value Toggle 2 */
#define REG_PORT_IN2               (*(RoReg  *)0x41006120U) /**< \brief (PORT) Data Input Value 2 */
#define REG_PORT_CTRL2             (*(RwReg  *)0x41006124U) /**< \brief (PORT) Control 2 */
#define REG_PORT_WRCONFIG2         (*(WoReg  *)0x41006128U) /**< \brief (PORT) Write Configuration 2 */
#define REG_PORT_EVCTRL2           (*(RwReg  *)0x4100612CU) /**< \brief (PORT) Event Input Control 2 */
#define REG_PORT_PMUX2             (*(RwReg  *)0x41006130U) /**< \brief (PORT) Peripheral Multiplexing 2 */
#define REG_PORT_PINCFG2           (*(RwReg  *)0x41006140U) /**< \brief (PORT) Pin Configuration 2 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for PORT peripheral ========== */
#define PORT_BITS                   93      
#define PORT_DIR_DEFAULT_VAL        { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_DIR_IMPLEMENTED        { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_DRVSTR                 1        // DRVSTR supported
#define PORT_DRVSTR_DEFAULT_VAL     { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_DRVSTR_IMPLEMENTED     { 0xC8FFFFFF, 0xC3FFFBFF, 0x1F3FF0EF }
#define PORT_EVENT_IMPLEMENTED      { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F03F0EF }
#define PORT_EV_NUM                 4       
#define PORT_INEN_DEFAULT_VAL       { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_INEN_IMPLEMENTED       { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_ODRAIN                 0        // ODRAIN supported
#define PORT_ODRAIN_DEFAULT_VAL     { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_ODRAIN_IMPLEMENTED     { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_OUT_DEFAULT_VAL        { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_OUT_IMPLEMENTED        { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_PIN_IMPLEMENTED        { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_PMUXBIT0_DEFAULT_VAL   { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_PMUXBIT0_IMPLEMENTED   { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_PMUXBIT1_DEFAULT_VAL   { 0x40000000, 0x00000000, 0x00000000 }
#define PORT_PMUXBIT1_IMPLEMENTED   { 0xCBFFFFF7, 0xC3FFFB0F, 0x1B003C03 }
#define PORT_PMUXBIT2_DEFAULT_VAL   { 0x40000000, 0x00000000, 0x00000000 }
#define PORT_PMUXBIT2_IMPLEMENTED   { 0x4BFFFF34, 0xC3FFFB0F, 0x1F000003 }
#define PORT_PMUXBIT3_DEFAULT_VAL   { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_PMUXBIT3_IMPLEMENTED   { 0xC3CF0FF0, 0x00C3CBC7, 0x18300000 }
#define PORT_PMUXEN_DEFAULT_VAL     { 0x40000000, 0x00000000, 0x00000000 }
#define PORT_PMUXEN_IMPLEMENTED     { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_PULLEN_DEFAULT_VAL     { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_PULLEN_IMPLEMENTED     { 0xCBFFFFFF, 0xC3FFFBFF, 0x1F3FFFEF }
#define PORT_SLEWLIM                0        // SLEWLIM supported
#define PORT_SLEWLIM_DEFAULT_VAL    { 0x00000000, 0x00000000, 0x00000000 }
#define PORT_SLEWLIM_IMPLEMENTED    { 0x00000000, 0x00000000, 0x00000000 }

#endif /* _SAML22_PORT_INSTANCE_ */
