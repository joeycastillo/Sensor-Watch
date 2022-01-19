/**
 * \file
 *
 * \brief Instance description for EVSYS
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

#ifndef _SAML22_EVSYS_INSTANCE_
#define _SAML22_EVSYS_INSTANCE_

/* ========== Register definition for EVSYS peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_EVSYS_CTRLA            (0x42000000) /**< \brief (EVSYS) Control */
#define REG_EVSYS_CHSTATUS         (0x4200000C) /**< \brief (EVSYS) Channel Status */
#define REG_EVSYS_INTENCLR         (0x42000010) /**< \brief (EVSYS) Interrupt Enable Clear */
#define REG_EVSYS_INTENSET         (0x42000014) /**< \brief (EVSYS) Interrupt Enable Set */
#define REG_EVSYS_INTFLAG          (0x42000018) /**< \brief (EVSYS) Interrupt Flag Status and Clear */
#define REG_EVSYS_SWEVT            (0x4200001C) /**< \brief (EVSYS) Software Event */
#define REG_EVSYS_CHANNEL0         (0x42000020) /**< \brief (EVSYS) Channel 0 */
#define REG_EVSYS_CHANNEL1         (0x42000024) /**< \brief (EVSYS) Channel 1 */
#define REG_EVSYS_CHANNEL2         (0x42000028) /**< \brief (EVSYS) Channel 2 */
#define REG_EVSYS_CHANNEL3         (0x4200002C) /**< \brief (EVSYS) Channel 3 */
#define REG_EVSYS_CHANNEL4         (0x42000030) /**< \brief (EVSYS) Channel 4 */
#define REG_EVSYS_CHANNEL5         (0x42000034) /**< \brief (EVSYS) Channel 5 */
#define REG_EVSYS_CHANNEL6         (0x42000038) /**< \brief (EVSYS) Channel 6 */
#define REG_EVSYS_CHANNEL7         (0x4200003C) /**< \brief (EVSYS) Channel 7 */
#define REG_EVSYS_USER0            (0x42000080) /**< \brief (EVSYS) User Multiplexer 0 */
#define REG_EVSYS_USER1            (0x42000084) /**< \brief (EVSYS) User Multiplexer 1 */
#define REG_EVSYS_USER2            (0x42000088) /**< \brief (EVSYS) User Multiplexer 2 */
#define REG_EVSYS_USER3            (0x4200008C) /**< \brief (EVSYS) User Multiplexer 3 */
#define REG_EVSYS_USER4            (0x42000090) /**< \brief (EVSYS) User Multiplexer 4 */
#define REG_EVSYS_USER5            (0x42000094) /**< \brief (EVSYS) User Multiplexer 5 */
#define REG_EVSYS_USER6            (0x42000098) /**< \brief (EVSYS) User Multiplexer 6 */
#define REG_EVSYS_USER7            (0x4200009C) /**< \brief (EVSYS) User Multiplexer 7 */
#define REG_EVSYS_USER8            (0x420000A0) /**< \brief (EVSYS) User Multiplexer 8 */
#define REG_EVSYS_USER9            (0x420000A4) /**< \brief (EVSYS) User Multiplexer 9 */
#define REG_EVSYS_USER10           (0x420000A8) /**< \brief (EVSYS) User Multiplexer 10 */
#define REG_EVSYS_USER11           (0x420000AC) /**< \brief (EVSYS) User Multiplexer 11 */
#define REG_EVSYS_USER12           (0x420000B0) /**< \brief (EVSYS) User Multiplexer 12 */
#define REG_EVSYS_USER13           (0x420000B4) /**< \brief (EVSYS) User Multiplexer 13 */
#define REG_EVSYS_USER14           (0x420000B8) /**< \brief (EVSYS) User Multiplexer 14 */
#define REG_EVSYS_USER15           (0x420000BC) /**< \brief (EVSYS) User Multiplexer 15 */
#define REG_EVSYS_USER16           (0x420000C0) /**< \brief (EVSYS) User Multiplexer 16 */
#define REG_EVSYS_USER17           (0x420000C4) /**< \brief (EVSYS) User Multiplexer 17 */
#define REG_EVSYS_USER18           (0x420000C8) /**< \brief (EVSYS) User Multiplexer 18 */
#define REG_EVSYS_USER19           (0x420000CC) /**< \brief (EVSYS) User Multiplexer 19 */
#define REG_EVSYS_USER20           (0x420000D0) /**< \brief (EVSYS) User Multiplexer 20 */
#define REG_EVSYS_USER21           (0x420000D4) /**< \brief (EVSYS) User Multiplexer 21 */
#define REG_EVSYS_USER22           (0x420000D8) /**< \brief (EVSYS) User Multiplexer 22 */
#define REG_EVSYS_USER23           (0x420000DC) /**< \brief (EVSYS) User Multiplexer 23 */
#define REG_EVSYS_USER24           (0x420000E0) /**< \brief (EVSYS) User Multiplexer 24 */
#define REG_EVSYS_USER25           (0x420000E4) /**< \brief (EVSYS) User Multiplexer 25 */
#define REG_EVSYS_USER26           (0x420000E8) /**< \brief (EVSYS) User Multiplexer 26 */
#define REG_EVSYS_USER27           (0x420000EC) /**< \brief (EVSYS) User Multiplexer 27 */
#define REG_EVSYS_USER28           (0x420000F0) /**< \brief (EVSYS) User Multiplexer 28 */
#define REG_EVSYS_USER29           (0x420000F4) /**< \brief (EVSYS) User Multiplexer 29 */
#define REG_EVSYS_USER30           (0x420000F8) /**< \brief (EVSYS) User Multiplexer 30 */
#else
#define REG_EVSYS_CTRLA            (*(RwReg8 *)0x42000000UL) /**< \brief (EVSYS) Control */
#define REG_EVSYS_CHSTATUS         (*(RoReg  *)0x4200000CUL) /**< \brief (EVSYS) Channel Status */
#define REG_EVSYS_INTENCLR         (*(RwReg  *)0x42000010UL) /**< \brief (EVSYS) Interrupt Enable Clear */
#define REG_EVSYS_INTENSET         (*(RwReg  *)0x42000014UL) /**< \brief (EVSYS) Interrupt Enable Set */
#define REG_EVSYS_INTFLAG          (*(RwReg  *)0x42000018UL) /**< \brief (EVSYS) Interrupt Flag Status and Clear */
#define REG_EVSYS_SWEVT            (*(WoReg  *)0x4200001CUL) /**< \brief (EVSYS) Software Event */
#define REG_EVSYS_CHANNEL0         (*(RwReg  *)0x42000020UL) /**< \brief (EVSYS) Channel 0 */
#define REG_EVSYS_CHANNEL1         (*(RwReg  *)0x42000024UL) /**< \brief (EVSYS) Channel 1 */
#define REG_EVSYS_CHANNEL2         (*(RwReg  *)0x42000028UL) /**< \brief (EVSYS) Channel 2 */
#define REG_EVSYS_CHANNEL3         (*(RwReg  *)0x4200002CUL) /**< \brief (EVSYS) Channel 3 */
#define REG_EVSYS_CHANNEL4         (*(RwReg  *)0x42000030UL) /**< \brief (EVSYS) Channel 4 */
#define REG_EVSYS_CHANNEL5         (*(RwReg  *)0x42000034UL) /**< \brief (EVSYS) Channel 5 */
#define REG_EVSYS_CHANNEL6         (*(RwReg  *)0x42000038UL) /**< \brief (EVSYS) Channel 6 */
#define REG_EVSYS_CHANNEL7         (*(RwReg  *)0x4200003CUL) /**< \brief (EVSYS) Channel 7 */
#define REG_EVSYS_USER0            (*(RwReg  *)0x42000080UL) /**< \brief (EVSYS) User Multiplexer 0 */
#define REG_EVSYS_USER1            (*(RwReg  *)0x42000084UL) /**< \brief (EVSYS) User Multiplexer 1 */
#define REG_EVSYS_USER2            (*(RwReg  *)0x42000088UL) /**< \brief (EVSYS) User Multiplexer 2 */
#define REG_EVSYS_USER3            (*(RwReg  *)0x4200008CUL) /**< \brief (EVSYS) User Multiplexer 3 */
#define REG_EVSYS_USER4            (*(RwReg  *)0x42000090UL) /**< \brief (EVSYS) User Multiplexer 4 */
#define REG_EVSYS_USER5            (*(RwReg  *)0x42000094UL) /**< \brief (EVSYS) User Multiplexer 5 */
#define REG_EVSYS_USER6            (*(RwReg  *)0x42000098UL) /**< \brief (EVSYS) User Multiplexer 6 */
#define REG_EVSYS_USER7            (*(RwReg  *)0x4200009CUL) /**< \brief (EVSYS) User Multiplexer 7 */
#define REG_EVSYS_USER8            (*(RwReg  *)0x420000A0UL) /**< \brief (EVSYS) User Multiplexer 8 */
#define REG_EVSYS_USER9            (*(RwReg  *)0x420000A4UL) /**< \brief (EVSYS) User Multiplexer 9 */
#define REG_EVSYS_USER10           (*(RwReg  *)0x420000A8UL) /**< \brief (EVSYS) User Multiplexer 10 */
#define REG_EVSYS_USER11           (*(RwReg  *)0x420000ACUL) /**< \brief (EVSYS) User Multiplexer 11 */
#define REG_EVSYS_USER12           (*(RwReg  *)0x420000B0UL) /**< \brief (EVSYS) User Multiplexer 12 */
#define REG_EVSYS_USER13           (*(RwReg  *)0x420000B4UL) /**< \brief (EVSYS) User Multiplexer 13 */
#define REG_EVSYS_USER14           (*(RwReg  *)0x420000B8UL) /**< \brief (EVSYS) User Multiplexer 14 */
#define REG_EVSYS_USER15           (*(RwReg  *)0x420000BCUL) /**< \brief (EVSYS) User Multiplexer 15 */
#define REG_EVSYS_USER16           (*(RwReg  *)0x420000C0UL) /**< \brief (EVSYS) User Multiplexer 16 */
#define REG_EVSYS_USER17           (*(RwReg  *)0x420000C4UL) /**< \brief (EVSYS) User Multiplexer 17 */
#define REG_EVSYS_USER18           (*(RwReg  *)0x420000C8UL) /**< \brief (EVSYS) User Multiplexer 18 */
#define REG_EVSYS_USER19           (*(RwReg  *)0x420000CCUL) /**< \brief (EVSYS) User Multiplexer 19 */
#define REG_EVSYS_USER20           (*(RwReg  *)0x420000D0UL) /**< \brief (EVSYS) User Multiplexer 20 */
#define REG_EVSYS_USER21           (*(RwReg  *)0x420000D4UL) /**< \brief (EVSYS) User Multiplexer 21 */
#define REG_EVSYS_USER22           (*(RwReg  *)0x420000D8UL) /**< \brief (EVSYS) User Multiplexer 22 */
#define REG_EVSYS_USER23           (*(RwReg  *)0x420000DCUL) /**< \brief (EVSYS) User Multiplexer 23 */
#define REG_EVSYS_USER24           (*(RwReg  *)0x420000E0UL) /**< \brief (EVSYS) User Multiplexer 24 */
#define REG_EVSYS_USER25           (*(RwReg  *)0x420000E4UL) /**< \brief (EVSYS) User Multiplexer 25 */
#define REG_EVSYS_USER26           (*(RwReg  *)0x420000E8UL) /**< \brief (EVSYS) User Multiplexer 26 */
#define REG_EVSYS_USER27           (*(RwReg  *)0x420000ECUL) /**< \brief (EVSYS) User Multiplexer 27 */
#define REG_EVSYS_USER28           (*(RwReg  *)0x420000F0UL) /**< \brief (EVSYS) User Multiplexer 28 */
#define REG_EVSYS_USER29           (*(RwReg  *)0x420000F4UL) /**< \brief (EVSYS) User Multiplexer 29 */
#define REG_EVSYS_USER30           (*(RwReg  *)0x420000F8UL) /**< \brief (EVSYS) User Multiplexer 30 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for EVSYS peripheral ========== */
#define EVSYS_CHANNELS              8        // Number of Channels
#define EVSYS_CHANNELS_BITS         3        // Number of bits to select Channel
#define EVSYS_CHANNELS_MSB          7        // Number of Channels - 1
#define EVSYS_EXTEVT_NUM            0        // Number of External Event Generators
#define EVSYS_GCLK_ID_0             7
#define EVSYS_GCLK_ID_1             8
#define EVSYS_GCLK_ID_2             9
#define EVSYS_GCLK_ID_3             10
#define EVSYS_GCLK_ID_4             11
#define EVSYS_GCLK_ID_5             12
#define EVSYS_GCLK_ID_6             13
#define EVSYS_GCLK_ID_7             14
#define EVSYS_GCLK_ID_LSB           7
#define EVSYS_GCLK_ID_MSB           14
#define EVSYS_GCLK_ID_SIZE          8
#define EVSYS_GENERATORS            71       // Total Number of Event Generators
#define EVSYS_GENERATORS_BITS       7        // Number of bits to select Event Generator
#define EVSYS_USERS                 31       // Total Number of Event Users
#define EVSYS_USERS_BITS            5        // Number of bits to select Event User

// GENERATORS
#define EVSYS_ID_GEN_OSCCTRL_XOSC_FAIL 1
#define EVSYS_ID_GEN_OSC32KCTRL_XOSC32K_FAIL 2
#define EVSYS_ID_GEN_RTC_CMP_0      3
#define EVSYS_ID_GEN_RTC_CMP_1      4
#define EVSYS_ID_GEN_RTC_TAMPER     5
#define EVSYS_ID_GEN_RTC_OVF        6
#define EVSYS_ID_GEN_RTC_PER_0      7
#define EVSYS_ID_GEN_RTC_PER_1      8
#define EVSYS_ID_GEN_RTC_PER_2      9
#define EVSYS_ID_GEN_RTC_PER_3      10
#define EVSYS_ID_GEN_RTC_PER_4      11
#define EVSYS_ID_GEN_RTC_PER_5      12
#define EVSYS_ID_GEN_RTC_PER_6      13
#define EVSYS_ID_GEN_RTC_PER_7      14
#define EVSYS_ID_GEN_EIC_EXTINT_0   15
#define EVSYS_ID_GEN_EIC_EXTINT_1   16
#define EVSYS_ID_GEN_EIC_EXTINT_2   17
#define EVSYS_ID_GEN_EIC_EXTINT_3   18
#define EVSYS_ID_GEN_EIC_EXTINT_4   19
#define EVSYS_ID_GEN_EIC_EXTINT_5   20
#define EVSYS_ID_GEN_EIC_EXTINT_6   21
#define EVSYS_ID_GEN_EIC_EXTINT_7   22
#define EVSYS_ID_GEN_EIC_EXTINT_8   23
#define EVSYS_ID_GEN_EIC_EXTINT_9   24
#define EVSYS_ID_GEN_EIC_EXTINT_10  25
#define EVSYS_ID_GEN_EIC_EXTINT_11  26
#define EVSYS_ID_GEN_EIC_EXTINT_12  27
#define EVSYS_ID_GEN_EIC_EXTINT_13  28
#define EVSYS_ID_GEN_EIC_EXTINT_14  29
#define EVSYS_ID_GEN_EIC_EXTINT_15  30
#define EVSYS_ID_GEN_DMAC_CH_0      31
#define EVSYS_ID_GEN_DMAC_CH_1      32
#define EVSYS_ID_GEN_DMAC_CH_2      33
#define EVSYS_ID_GEN_DMAC_CH_3      34
#define EVSYS_ID_GEN_TCC0_OVF       35
#define EVSYS_ID_GEN_TCC0_TRG       36
#define EVSYS_ID_GEN_TCC0_CNT       37
#define EVSYS_ID_GEN_TCC0_MCX_0     38
#define EVSYS_ID_GEN_TCC0_MCX_1     39
#define EVSYS_ID_GEN_TCC0_MCX_2     40
#define EVSYS_ID_GEN_TCC0_MCX_3     41
#define EVSYS_ID_GEN_TC0_OVF        42
#define EVSYS_ID_GEN_TC0_MCX_0      43
#define EVSYS_ID_GEN_TC0_MCX_1      44
#define EVSYS_ID_GEN_TC1_OVF        45
#define EVSYS_ID_GEN_TC1_MCX_0      46
#define EVSYS_ID_GEN_TC1_MCX_1      47
#define EVSYS_ID_GEN_TC2_OVF        48
#define EVSYS_ID_GEN_TC2_MCX_0      49
#define EVSYS_ID_GEN_TC2_MCX_1      50
#define EVSYS_ID_GEN_TC3_OVF        51
#define EVSYS_ID_GEN_TC3_MCX_0      52
#define EVSYS_ID_GEN_TC3_MCX_1      53
#define EVSYS_ID_GEN_ADC_RESRDY     54
#define EVSYS_ID_GEN_ADC_WINMON     55
#define EVSYS_ID_GEN_AC_COMP_0      56
#define EVSYS_ID_GEN_AC_COMP_1      57
#define EVSYS_ID_GEN_AC_WIN_0       58
#define EVSYS_ID_GEN_SLCD_FC0OVERFLOW 61
#define EVSYS_ID_GEN_SLCD_FC1OVERFLOW 62
#define EVSYS_ID_GEN_SLCD_FC2OVERFLOW 63
#define EVSYS_ID_GEN_SLCD_DT        64
#define EVSYS_ID_GEN_TRNG_READY     65
#define EVSYS_ID_GEN_CCL_LUTOUT_0   66
#define EVSYS_ID_GEN_CCL_LUTOUT_1   67
#define EVSYS_ID_GEN_CCL_LUTOUT_2   68
#define EVSYS_ID_GEN_CCL_LUTOUT_3   69
#define EVSYS_ID_GEN_PAC_ACCERR     70

// USERS
#define EVSYS_ID_USER_RTC_TAMPER    0
#define EVSYS_ID_USER_PORT_EV_0     1
#define EVSYS_ID_USER_PORT_EV_1     2
#define EVSYS_ID_USER_PORT_EV_2     3
#define EVSYS_ID_USER_PORT_EV_3     4
#define EVSYS_ID_USER_DMAC_CH_0     5
#define EVSYS_ID_USER_DMAC_CH_1     6
#define EVSYS_ID_USER_DMAC_CH_2     7
#define EVSYS_ID_USER_DMAC_CH_3     8
#define EVSYS_ID_USER_TCC0_EV_0     9
#define EVSYS_ID_USER_TCC0_EV_1     10
#define EVSYS_ID_USER_TCC0_MC_0     11
#define EVSYS_ID_USER_TCC0_MC_1     12
#define EVSYS_ID_USER_TCC0_MC_2     13
#define EVSYS_ID_USER_TCC0_MC_3     14
#define EVSYS_ID_USER_TC0_EVU       15
#define EVSYS_ID_USER_TC1_EVU       16
#define EVSYS_ID_USER_TC2_EVU       17
#define EVSYS_ID_USER_TC3_EVU       18
#define EVSYS_ID_USER_ADC_START     19
#define EVSYS_ID_USER_ADC_SYNC      20
#define EVSYS_ID_USER_AC_SOC_0      21
#define EVSYS_ID_USER_AC_SOC_1      22
#define EVSYS_ID_USER_CCL_LUTIN_0   24
#define EVSYS_ID_USER_CCL_LUTIN_1   25
#define EVSYS_ID_USER_CCL_LUTIN_2   26
#define EVSYS_ID_USER_CCL_LUTIN_3   27
#define EVSYS_ID_USER_MTB_START     29
#define EVSYS_ID_USER_MTB_STOP      30

#endif /* _SAML22_EVSYS_INSTANCE_ */
