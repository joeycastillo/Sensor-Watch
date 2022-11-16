/**
 * \file
 *
 * \brief Instance description for PORT
 *
 * Copyright (c) 2018 Microchip Technology Inc.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

#ifndef _SAML22_PORT_INSTANCE_
#define _SAML22_PORT_INSTANCE_

/* ========== Register definition for PORT peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PORT_DIR0              (0x41006000) /**< \brief (PORT) Data Direction 0 */
#define REG_PORT_DIRCLR0           (0x41006004) /**< \brief (PORT) Data Direction Clear 0 */
#define REG_PORT_DIRSET0           (0x41006008) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_DIRTGL0           (0x4100600C) /**< \brief (PORT) Data Direction Toggle 0 */
#define REG_PORT_OUT0              (0x41006010) /**< \brief (PORT) Data Output Value 0 */
#define REG_PORT_OUTCLR0           (0x41006014) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0           (0x41006018) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0           (0x4100601C) /**< \brief (PORT) Data Output Value Toggle 0 */
#define REG_PORT_IN0               (0x41006020) /**< \brief (PORT) Data Input Value 0 */
#define REG_PORT_CTRL0             (0x41006024) /**< \brief (PORT) Control 0 */
#define REG_PORT_WRCONFIG0         (0x41006028) /**< \brief (PORT) Write Configuration 0 */
#define REG_PORT_EVCTRL0           (0x4100602C) /**< \brief (PORT) Event Input Control 0 */
#define REG_PORT_PMUX0             (0x41006030) /**< \brief (PORT) Peripheral Multiplexing 0 */
#define REG_PORT_PINCFG0           (0x41006040) /**< \brief (PORT) Pin Configuration 0 */
#define REG_PORT_DIR1              (0x41006080) /**< \brief (PORT) Data Direction 1 */
#define REG_PORT_DIRCLR1           (0x41006084) /**< \brief (PORT) Data Direction Clear 1 */
#define REG_PORT_DIRSET1           (0x41006088) /**< \brief (PORT) Data Direction Set 1 */
#define REG_PORT_DIRTGL1           (0x4100608C) /**< \brief (PORT) Data Direction Toggle 1 */
#define REG_PORT_OUT1              (0x41006090) /**< \brief (PORT) Data Output Value 1 */
#define REG_PORT_OUTCLR1           (0x41006094) /**< \brief (PORT) Data Output Value Clear 1 */
#define REG_PORT_OUTSET1           (0x41006098) /**< \brief (PORT) Data Output Value Set 1 */
#define REG_PORT_OUTTGL1           (0x4100609C) /**< \brief (PORT) Data Output Value Toggle 1 */
#define REG_PORT_IN1               (0x410060A0) /**< \brief (PORT) Data Input Value 1 */
#define REG_PORT_CTRL1             (0x410060A4) /**< \brief (PORT) Control 1 */
#define REG_PORT_WRCONFIG1         (0x410060A8) /**< \brief (PORT) Write Configuration 1 */
#define REG_PORT_EVCTRL1           (0x410060AC) /**< \brief (PORT) Event Input Control 1 */
#define REG_PORT_PMUX1             (0x410060B0) /**< \brief (PORT) Peripheral Multiplexing 1 */
#define REG_PORT_PINCFG1           (0x410060C0) /**< \brief (PORT) Pin Configuration 1 */
#define REG_PORT_DIR2              (0x41006100) /**< \brief (PORT) Data Direction 2 */
#define REG_PORT_DIRCLR2           (0x41006104) /**< \brief (PORT) Data Direction Clear 2 */
#define REG_PORT_DIRSET2           (0x41006108) /**< \brief (PORT) Data Direction Set 2 */
#define REG_PORT_DIRTGL2           (0x4100610C) /**< \brief (PORT) Data Direction Toggle 2 */
#define REG_PORT_OUT2              (0x41006110) /**< \brief (PORT) Data Output Value 2 */
#define REG_PORT_OUTCLR2           (0x41006114) /**< \brief (PORT) Data Output Value Clear 2 */
#define REG_PORT_OUTSET2           (0x41006118) /**< \brief (PORT) Data Output Value Set 2 */
#define REG_PORT_OUTTGL2           (0x4100611C) /**< \brief (PORT) Data Output Value Toggle 2 */
#define REG_PORT_IN2               (0x41006120) /**< \brief (PORT) Data Input Value 2 */
#define REG_PORT_CTRL2             (0x41006124) /**< \brief (PORT) Control 2 */
#define REG_PORT_WRCONFIG2         (0x41006128) /**< \brief (PORT) Write Configuration 2 */
#define REG_PORT_EVCTRL2           (0x4100612C) /**< \brief (PORT) Event Input Control 2 */
#define REG_PORT_PMUX2             (0x41006130) /**< \brief (PORT) Peripheral Multiplexing 2 */
#define REG_PORT_PINCFG2           (0x41006140) /**< \brief (PORT) Pin Configuration 2 */
#else
#define REG_PORT_DIR0              (*(RwReg  *)0x41006000UL) /**< \brief (PORT) Data Direction 0 */
#define REG_PORT_DIRCLR0           (*(RwReg  *)0x41006004UL) /**< \brief (PORT) Data Direction Clear 0 */
#define REG_PORT_DIRSET0           (*(RwReg  *)0x41006008UL) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_DIRTGL0           (*(RwReg  *)0x4100600CUL) /**< \brief (PORT) Data Direction Toggle 0 */
#define REG_PORT_OUT0              (*(RwReg  *)0x41006010UL) /**< \brief (PORT) Data Output Value 0 */
#define REG_PORT_OUTCLR0           (*(RwReg  *)0x41006014UL) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0           (*(RwReg  *)0x41006018UL) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0           (*(RwReg  *)0x4100601CUL) /**< \brief (PORT) Data Output Value Toggle 0 */
#define REG_PORT_IN0               (*(RoReg  *)0x41006020UL) /**< \brief (PORT) Data Input Value 0 */
#define REG_PORT_CTRL0             (*(RwReg  *)0x41006024UL) /**< \brief (PORT) Control 0 */
#define REG_PORT_WRCONFIG0         (*(WoReg  *)0x41006028UL) /**< \brief (PORT) Write Configuration 0 */
#define REG_PORT_EVCTRL0           (*(RwReg  *)0x4100602CUL) /**< \brief (PORT) Event Input Control 0 */
#define REG_PORT_PMUX0             (*(RwReg8 *)0x41006030UL) /**< \brief (PORT) Peripheral Multiplexing 0 */
#define REG_PORT_PINCFG0           (*(RwReg8 *)0x41006040UL) /**< \brief (PORT) Pin Configuration 0 */
#define REG_PORT_DIR1              (*(RwReg  *)0x41006080UL) /**< \brief (PORT) Data Direction 1 */
#define REG_PORT_DIRCLR1           (*(RwReg  *)0x41006084UL) /**< \brief (PORT) Data Direction Clear 1 */
#define REG_PORT_DIRSET1           (*(RwReg  *)0x41006088UL) /**< \brief (PORT) Data Direction Set 1 */
#define REG_PORT_DIRTGL1           (*(RwReg  *)0x4100608CUL) /**< \brief (PORT) Data Direction Toggle 1 */
#define REG_PORT_OUT1              (*(RwReg  *)0x41006090UL) /**< \brief (PORT) Data Output Value 1 */
#define REG_PORT_OUTCLR1           (*(RwReg  *)0x41006094UL) /**< \brief (PORT) Data Output Value Clear 1 */
#define REG_PORT_OUTSET1           (*(RwReg  *)0x41006098UL) /**< \brief (PORT) Data Output Value Set 1 */
#define REG_PORT_OUTTGL1           (*(RwReg  *)0x4100609CUL) /**< \brief (PORT) Data Output Value Toggle 1 */
#define REG_PORT_IN1               (*(RoReg  *)0x410060A0UL) /**< \brief (PORT) Data Input Value 1 */
#define REG_PORT_CTRL1             (*(RwReg  *)0x410060A4UL) /**< \brief (PORT) Control 1 */
#define REG_PORT_WRCONFIG1         (*(WoReg  *)0x410060A8UL) /**< \brief (PORT) Write Configuration 1 */
#define REG_PORT_EVCTRL1           (*(RwReg  *)0x410060ACUL) /**< \brief (PORT) Event Input Control 1 */
#define REG_PORT_PMUX1             (*(RwReg8 *)0x410060B0UL) /**< \brief (PORT) Peripheral Multiplexing 1 */
#define REG_PORT_PINCFG1           (*(RwReg8 *)0x410060C0UL) /**< \brief (PORT) Pin Configuration 1 */
#define REG_PORT_DIR2              (*(RwReg  *)0x41006100UL) /**< \brief (PORT) Data Direction 2 */
#define REG_PORT_DIRCLR2           (*(RwReg  *)0x41006104UL) /**< \brief (PORT) Data Direction Clear 2 */
#define REG_PORT_DIRSET2           (*(RwReg  *)0x41006108UL) /**< \brief (PORT) Data Direction Set 2 */
#define REG_PORT_DIRTGL2           (*(RwReg  *)0x4100610CUL) /**< \brief (PORT) Data Direction Toggle 2 */
#define REG_PORT_OUT2              (*(RwReg  *)0x41006110UL) /**< \brief (PORT) Data Output Value 2 */
#define REG_PORT_OUTCLR2           (*(RwReg  *)0x41006114UL) /**< \brief (PORT) Data Output Value Clear 2 */
#define REG_PORT_OUTSET2           (*(RwReg  *)0x41006118UL) /**< \brief (PORT) Data Output Value Set 2 */
#define REG_PORT_OUTTGL2           (*(RwReg  *)0x4100611CUL) /**< \brief (PORT) Data Output Value Toggle 2 */
#define REG_PORT_IN2               (*(RoReg  *)0x41006120UL) /**< \brief (PORT) Data Input Value 2 */
#define REG_PORT_CTRL2             (*(RwReg  *)0x41006124UL) /**< \brief (PORT) Control 2 */
#define REG_PORT_WRCONFIG2         (*(WoReg  *)0x41006128UL) /**< \brief (PORT) Write Configuration 2 */
#define REG_PORT_EVCTRL2           (*(RwReg  *)0x4100612CUL) /**< \brief (PORT) Event Input Control 2 */
#define REG_PORT_PMUX2             (*(RwReg8 *)0x41006130UL) /**< \brief (PORT) Peripheral Multiplexing 2 */
#define REG_PORT_PINCFG2           (*(RwReg8 *)0x41006140UL) /**< \brief (PORT) Pin Configuration 2 */
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
