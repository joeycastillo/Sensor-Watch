/**
 * \file
 *
 * \brief Component description for OSC32KCTRL
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

#ifndef _SAML22_OSC32KCTRL_COMPONENT_
#define _SAML22_OSC32KCTRL_COMPONENT_

/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR OSC32KCTRL */
/* ========================================================================== */
/** \addtogroup SAML22_OSC32KCTRL 32k Oscillators Control */
/*@{*/

#define OSC32KCTRL_U2246
#define REV_OSC32KCTRL              0x300

/* -------- OSC32KCTRL_INTENCLR : (OSC32KCTRL Offset: 0x00) (R/W 32) Interrupt Enable Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t XOSC32KRDY:1;     /*!< bit:      0  XOSC32K Ready Interrupt Enable     */
    uint32_t :1;               /*!< bit:      1  Reserved                           */
    uint32_t CLKFAIL:1;        /*!< bit:      2  XOSC32K Clock Failure Detector Interrupt Enable */
    uint32_t :29;              /*!< bit:  3..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} OSC32KCTRL_INTENCLR_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_INTENCLR_OFFSET  0x00         /**< \brief (OSC32KCTRL_INTENCLR offset) Interrupt Enable Clear */
#define OSC32KCTRL_INTENCLR_RESETVALUE 0x00000000ul /**< \brief (OSC32KCTRL_INTENCLR reset_value) Interrupt Enable Clear */

#define OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos 0            /**< \brief (OSC32KCTRL_INTENCLR) XOSC32K Ready Interrupt Enable */
#define OSC32KCTRL_INTENCLR_XOSC32KRDY (0x1ul << OSC32KCTRL_INTENCLR_XOSC32KRDY_Pos)
#define OSC32KCTRL_INTENCLR_CLKFAIL_Pos 2            /**< \brief (OSC32KCTRL_INTENCLR) XOSC32K Clock Failure Detector Interrupt Enable */
#define OSC32KCTRL_INTENCLR_CLKFAIL (0x1ul << OSC32KCTRL_INTENCLR_CLKFAIL_Pos)
#define OSC32KCTRL_INTENCLR_MASK    0x00000005ul /**< \brief (OSC32KCTRL_INTENCLR) MASK Register */

/* -------- OSC32KCTRL_INTENSET : (OSC32KCTRL Offset: 0x04) (R/W 32) Interrupt Enable Set -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t XOSC32KRDY:1;     /*!< bit:      0  XOSC32K Ready Interrupt Enable     */
    uint32_t :1;               /*!< bit:      1  Reserved                           */
    uint32_t CLKFAIL:1;        /*!< bit:      2  XOSC32K Clock Failure Detector Interrupt Enable */
    uint32_t :29;              /*!< bit:  3..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} OSC32KCTRL_INTENSET_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_INTENSET_OFFSET  0x04         /**< \brief (OSC32KCTRL_INTENSET offset) Interrupt Enable Set */
#define OSC32KCTRL_INTENSET_RESETVALUE 0x00000000ul /**< \brief (OSC32KCTRL_INTENSET reset_value) Interrupt Enable Set */

#define OSC32KCTRL_INTENSET_XOSC32KRDY_Pos 0            /**< \brief (OSC32KCTRL_INTENSET) XOSC32K Ready Interrupt Enable */
#define OSC32KCTRL_INTENSET_XOSC32KRDY (0x1ul << OSC32KCTRL_INTENSET_XOSC32KRDY_Pos)
#define OSC32KCTRL_INTENSET_CLKFAIL_Pos 2            /**< \brief (OSC32KCTRL_INTENSET) XOSC32K Clock Failure Detector Interrupt Enable */
#define OSC32KCTRL_INTENSET_CLKFAIL (0x1ul << OSC32KCTRL_INTENSET_CLKFAIL_Pos)
#define OSC32KCTRL_INTENSET_MASK    0x00000005ul /**< \brief (OSC32KCTRL_INTENSET) MASK Register */

/* -------- OSC32KCTRL_INTFLAG : (OSC32KCTRL Offset: 0x08) (R/W 32) Interrupt Flag Status and Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { // __I to avoid read-modify-write on write-to-clear register
  struct {
    __I uint32_t XOSC32KRDY:1;     /*!< bit:      0  XOSC32K Ready                      */
    __I uint32_t :1;               /*!< bit:      1  Reserved                           */
    __I uint32_t CLKFAIL:1;        /*!< bit:      2  XOSC32K Clock Failure Detector     */
    __I uint32_t :29;              /*!< bit:  3..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} OSC32KCTRL_INTFLAG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_INTFLAG_OFFSET   0x08         /**< \brief (OSC32KCTRL_INTFLAG offset) Interrupt Flag Status and Clear */
#define OSC32KCTRL_INTFLAG_RESETVALUE 0x00000000ul /**< \brief (OSC32KCTRL_INTFLAG reset_value) Interrupt Flag Status and Clear */

#define OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos 0            /**< \brief (OSC32KCTRL_INTFLAG) XOSC32K Ready */
#define OSC32KCTRL_INTFLAG_XOSC32KRDY (0x1ul << OSC32KCTRL_INTFLAG_XOSC32KRDY_Pos)
#define OSC32KCTRL_INTFLAG_CLKFAIL_Pos 2            /**< \brief (OSC32KCTRL_INTFLAG) XOSC32K Clock Failure Detector */
#define OSC32KCTRL_INTFLAG_CLKFAIL  (0x1ul << OSC32KCTRL_INTFLAG_CLKFAIL_Pos)
#define OSC32KCTRL_INTFLAG_MASK     0x00000005ul /**< \brief (OSC32KCTRL_INTFLAG) MASK Register */

/* -------- OSC32KCTRL_STATUS : (OSC32KCTRL Offset: 0x0C) (R/  32) Power and Clocks Status -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t XOSC32KRDY:1;     /*!< bit:      0  XOSC32K Ready                      */
    uint32_t :1;               /*!< bit:      1  Reserved                           */
    uint32_t CLKFAIL:1;        /*!< bit:      2  XOSC32K Clock Failure Detector     */
    uint32_t CLKSW:1;          /*!< bit:      3  XOSC32K Clock switch               */
    uint32_t :28;              /*!< bit:  4..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} OSC32KCTRL_STATUS_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_STATUS_OFFSET    0x0C         /**< \brief (OSC32KCTRL_STATUS offset) Power and Clocks Status */
#define OSC32KCTRL_STATUS_RESETVALUE 0x00000000ul /**< \brief (OSC32KCTRL_STATUS reset_value) Power and Clocks Status */

#define OSC32KCTRL_STATUS_XOSC32KRDY_Pos 0            /**< \brief (OSC32KCTRL_STATUS) XOSC32K Ready */
#define OSC32KCTRL_STATUS_XOSC32KRDY (0x1ul << OSC32KCTRL_STATUS_XOSC32KRDY_Pos)
#define OSC32KCTRL_STATUS_CLKFAIL_Pos 2            /**< \brief (OSC32KCTRL_STATUS) XOSC32K Clock Failure Detector */
#define OSC32KCTRL_STATUS_CLKFAIL   (0x1ul << OSC32KCTRL_STATUS_CLKFAIL_Pos)
#define OSC32KCTRL_STATUS_CLKSW_Pos 3            /**< \brief (OSC32KCTRL_STATUS) XOSC32K Clock switch */
#define OSC32KCTRL_STATUS_CLKSW     (0x1ul << OSC32KCTRL_STATUS_CLKSW_Pos)
#define OSC32KCTRL_STATUS_MASK      0x0000000Dul /**< \brief (OSC32KCTRL_STATUS) MASK Register */

/* -------- OSC32KCTRL_RTCCTRL : (OSC32KCTRL Offset: 0x10) (R/W  8) RTC Clock Selection -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  RTCSEL:3;         /*!< bit:  0.. 2  RTC Clock Selection                */
    uint8_t  :5;               /*!< bit:  3.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} OSC32KCTRL_RTCCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_RTCCTRL_OFFSET   0x10         /**< \brief (OSC32KCTRL_RTCCTRL offset) RTC Clock Selection */
#define OSC32KCTRL_RTCCTRL_RESETVALUE 0x00ul       /**< \brief (OSC32KCTRL_RTCCTRL reset_value) RTC Clock Selection */

#define OSC32KCTRL_RTCCTRL_RTCSEL_Pos 0            /**< \brief (OSC32KCTRL_RTCCTRL) RTC Clock Selection */
#define OSC32KCTRL_RTCCTRL_RTCSEL_Msk (0x7ul << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_RTCSEL(value) (OSC32KCTRL_RTCCTRL_RTCSEL_Msk & ((value) << OSC32KCTRL_RTCCTRL_RTCSEL_Pos))
#define   OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K_Val 0x0ul  /**< \brief (OSC32KCTRL_RTCCTRL) 1.024kHz from 32kHz internal ULP oscillator */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K_Val 0x1ul  /**< \brief (OSC32KCTRL_RTCCTRL) 32.768kHz from 32kHz internal ULP oscillator */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_OSC1K_Val 0x2ul  /**< \brief (OSC32KCTRL_RTCCTRL) 1.024kHz from 32.768kHz internal oscillator */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_OSC32K_Val 0x3ul  /**< \brief (OSC32KCTRL_RTCCTRL) 32.768kHz from 32.768kHz internal oscillator */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K_Val 0x4ul  /**< \brief (OSC32KCTRL_RTCCTRL) 1.024kHz from 32.768kHz internal oscillator */
#define   OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K_Val 0x5ul  /**< \brief (OSC32KCTRL_RTCCTRL) 32.768kHz from 32.768kHz external crystal oscillator */
#define OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K (OSC32KCTRL_RTCCTRL_RTCSEL_ULP1K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K (OSC32KCTRL_RTCCTRL_RTCSEL_ULP32K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_RTCSEL_OSC1K (OSC32KCTRL_RTCCTRL_RTCSEL_OSC1K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_RTCSEL_OSC32K (OSC32KCTRL_RTCCTRL_RTCSEL_OSC32K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K (OSC32KCTRL_RTCCTRL_RTCSEL_XOSC1K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K (OSC32KCTRL_RTCCTRL_RTCSEL_XOSC32K_Val << OSC32KCTRL_RTCCTRL_RTCSEL_Pos)
#define OSC32KCTRL_RTCCTRL_MASK     0x07ul       /**< \brief (OSC32KCTRL_RTCCTRL) MASK Register */

/* -------- OSC32KCTRL_SLCDCTRL : (OSC32KCTRL Offset: 0x11) (R/W  8) SLCD Clock Selection -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  SLCDSEL:1;        /*!< bit:      0  SLCD Clock Selection               */
    uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} OSC32KCTRL_SLCDCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_SLCDCTRL_OFFSET  0x11         /**< \brief (OSC32KCTRL_SLCDCTRL offset) SLCD Clock Selection */
#define OSC32KCTRL_SLCDCTRL_RESETVALUE 0x00ul       /**< \brief (OSC32KCTRL_SLCDCTRL reset_value) SLCD Clock Selection */

#define OSC32KCTRL_SLCDCTRL_SLCDSEL_Pos 0            /**< \brief (OSC32KCTRL_SLCDCTRL) SLCD Clock Selection */
#define OSC32KCTRL_SLCDCTRL_SLCDSEL (0x1ul << OSC32KCTRL_SLCDCTRL_SLCDSEL_Pos)
#define OSC32KCTRL_SLCDCTRL_MASK    0x01ul       /**< \brief (OSC32KCTRL_SLCDCTRL) MASK Register */

/* -------- OSC32KCTRL_XOSC32K : (OSC32KCTRL Offset: 0x14) (R/W 16) 32kHz External Crystal Oscillator (XOSC32K) Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint16_t :1;               /*!< bit:      0  Reserved                           */
    uint16_t ENABLE:1;         /*!< bit:      1  Oscillator Enable                  */
    uint16_t XTALEN:1;         /*!< bit:      2  Crystal Oscillator Enable          */
    uint16_t EN32K:1;          /*!< bit:      3  32kHz Output Enable                */
    uint16_t EN1K:1;           /*!< bit:      4  1kHz Output Enable                 */
    uint16_t :1;               /*!< bit:      5  Reserved                           */
    uint16_t RUNSTDBY:1;       /*!< bit:      6  Run in Standby                     */
    uint16_t ONDEMAND:1;       /*!< bit:      7  On Demand Control                  */
    uint16_t STARTUP:3;        /*!< bit:  8..10  Oscillator Start-Up Time           */
    uint16_t :1;               /*!< bit:     11  Reserved                           */
    uint16_t WRTLOCK:1;        /*!< bit:     12  Write Lock                         */
    uint16_t :3;               /*!< bit: 13..15  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint16_t reg;                /*!< Type      used for register access              */
} OSC32KCTRL_XOSC32K_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_XOSC32K_OFFSET   0x14         /**< \brief (OSC32KCTRL_XOSC32K offset) 32kHz External Crystal Oscillator (XOSC32K) Control */
#define OSC32KCTRL_XOSC32K_RESETVALUE 0x0080ul     /**< \brief (OSC32KCTRL_XOSC32K reset_value) 32kHz External Crystal Oscillator (XOSC32K) Control */

#define OSC32KCTRL_XOSC32K_ENABLE_Pos 1            /**< \brief (OSC32KCTRL_XOSC32K) Oscillator Enable */
#define OSC32KCTRL_XOSC32K_ENABLE   (0x1ul << OSC32KCTRL_XOSC32K_ENABLE_Pos)
#define OSC32KCTRL_XOSC32K_XTALEN_Pos 2            /**< \brief (OSC32KCTRL_XOSC32K) Crystal Oscillator Enable */
#define OSC32KCTRL_XOSC32K_XTALEN   (0x1ul << OSC32KCTRL_XOSC32K_XTALEN_Pos)
#define OSC32KCTRL_XOSC32K_EN32K_Pos 3            /**< \brief (OSC32KCTRL_XOSC32K) 32kHz Output Enable */
#define OSC32KCTRL_XOSC32K_EN32K    (0x1ul << OSC32KCTRL_XOSC32K_EN32K_Pos)
#define OSC32KCTRL_XOSC32K_EN1K_Pos 4            /**< \brief (OSC32KCTRL_XOSC32K) 1kHz Output Enable */
#define OSC32KCTRL_XOSC32K_EN1K     (0x1ul << OSC32KCTRL_XOSC32K_EN1K_Pos)
#define OSC32KCTRL_XOSC32K_RUNSTDBY_Pos 6            /**< \brief (OSC32KCTRL_XOSC32K) Run in Standby */
#define OSC32KCTRL_XOSC32K_RUNSTDBY (0x1ul << OSC32KCTRL_XOSC32K_RUNSTDBY_Pos)
#define OSC32KCTRL_XOSC32K_ONDEMAND_Pos 7            /**< \brief (OSC32KCTRL_XOSC32K) On Demand Control */
#define OSC32KCTRL_XOSC32K_ONDEMAND (0x1ul << OSC32KCTRL_XOSC32K_ONDEMAND_Pos)
#define OSC32KCTRL_XOSC32K_STARTUP_Pos 8            /**< \brief (OSC32KCTRL_XOSC32K) Oscillator Start-Up Time */
#define OSC32KCTRL_XOSC32K_STARTUP_Msk (0x7ul << OSC32KCTRL_XOSC32K_STARTUP_Pos)
#define OSC32KCTRL_XOSC32K_STARTUP(value) (OSC32KCTRL_XOSC32K_STARTUP_Msk & ((value) << OSC32KCTRL_XOSC32K_STARTUP_Pos))
#define OSC32KCTRL_XOSC32K_WRTLOCK_Pos 12           /**< \brief (OSC32KCTRL_XOSC32K) Write Lock */
#define OSC32KCTRL_XOSC32K_WRTLOCK  (0x1ul << OSC32KCTRL_XOSC32K_WRTLOCK_Pos)
#define OSC32KCTRL_XOSC32K_MASK     0x17DEul     /**< \brief (OSC32KCTRL_XOSC32K) MASK Register */

/* -------- OSC32KCTRL_CFDCTRL : (OSC32KCTRL Offset: 0x16) (R/W  8) Clock Failure Detector Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  CFDEN:1;          /*!< bit:      0  Clock Failure Detector Enable      */
    uint8_t  SWBACK:1;         /*!< bit:      1  Clock Switch Back                  */
    uint8_t  CFDPRESC:1;       /*!< bit:      2  Clock Failure Detector Prescaler   */
    uint8_t  :5;               /*!< bit:  3.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} OSC32KCTRL_CFDCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_CFDCTRL_OFFSET   0x16         /**< \brief (OSC32KCTRL_CFDCTRL offset) Clock Failure Detector Control */
#define OSC32KCTRL_CFDCTRL_RESETVALUE 0x00ul       /**< \brief (OSC32KCTRL_CFDCTRL reset_value) Clock Failure Detector Control */

#define OSC32KCTRL_CFDCTRL_CFDEN_Pos 0            /**< \brief (OSC32KCTRL_CFDCTRL) Clock Failure Detector Enable */
#define OSC32KCTRL_CFDCTRL_CFDEN    (0x1ul << OSC32KCTRL_CFDCTRL_CFDEN_Pos)
#define OSC32KCTRL_CFDCTRL_SWBACK_Pos 1            /**< \brief (OSC32KCTRL_CFDCTRL) Clock Switch Back */
#define OSC32KCTRL_CFDCTRL_SWBACK   (0x1ul << OSC32KCTRL_CFDCTRL_SWBACK_Pos)
#define OSC32KCTRL_CFDCTRL_CFDPRESC_Pos 2            /**< \brief (OSC32KCTRL_CFDCTRL) Clock Failure Detector Prescaler */
#define OSC32KCTRL_CFDCTRL_CFDPRESC (0x1ul << OSC32KCTRL_CFDCTRL_CFDPRESC_Pos)
#define OSC32KCTRL_CFDCTRL_MASK     0x07ul       /**< \brief (OSC32KCTRL_CFDCTRL) MASK Register */

/* -------- OSC32KCTRL_EVCTRL : (OSC32KCTRL Offset: 0x17) (R/W  8) Event Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  CFDEO:1;          /*!< bit:      0  Clock Failure Detector Event Output Enable */
    uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} OSC32KCTRL_EVCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_EVCTRL_OFFSET    0x17         /**< \brief (OSC32KCTRL_EVCTRL offset) Event Control */
#define OSC32KCTRL_EVCTRL_RESETVALUE 0x00ul       /**< \brief (OSC32KCTRL_EVCTRL reset_value) Event Control */

#define OSC32KCTRL_EVCTRL_CFDEO_Pos 0            /**< \brief (OSC32KCTRL_EVCTRL) Clock Failure Detector Event Output Enable */
#define OSC32KCTRL_EVCTRL_CFDEO     (0x1ul << OSC32KCTRL_EVCTRL_CFDEO_Pos)
#define OSC32KCTRL_EVCTRL_MASK      0x01ul       /**< \brief (OSC32KCTRL_EVCTRL) MASK Register */

/* -------- OSC32KCTRL_OSCULP32K : (OSC32KCTRL Offset: 0x1C) (R/W 32) 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t :1;               /*!< bit:      0  Reserved                           */
    uint32_t EN32K:1;          /*!< bit:      1  Enable Out 32k                     */
    uint32_t EN1K:1;           /*!< bit:      2  Enable Out 1k                      */
    uint32_t :5;               /*!< bit:  3.. 7  Reserved                           */
    uint32_t CALIB:5;          /*!< bit:  8..12  Oscillator Calibration             */
    uint32_t :2;               /*!< bit: 13..14  Reserved                           */
    uint32_t WRTLOCK:1;        /*!< bit:     15  Write Lock                         */
    uint32_t :16;              /*!< bit: 16..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} OSC32KCTRL_OSCULP32K_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define OSC32KCTRL_OSCULP32K_OFFSET 0x1C         /**< \brief (OSC32KCTRL_OSCULP32K offset) 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control */

#define OSC32KCTRL_OSCULP32K_EN32K_Pos 1            /**< \brief (OSC32KCTRL_OSCULP32K) Enable Out 32k */
#define OSC32KCTRL_OSCULP32K_EN32K  (0x1ul << OSC32KCTRL_OSCULP32K_EN32K_Pos)
#define OSC32KCTRL_OSCULP32K_EN1K_Pos 2            /**< \brief (OSC32KCTRL_OSCULP32K) Enable Out 1k */
#define OSC32KCTRL_OSCULP32K_EN1K   (0x1ul << OSC32KCTRL_OSCULP32K_EN1K_Pos)
#define OSC32KCTRL_OSCULP32K_CALIB_Pos 8            /**< \brief (OSC32KCTRL_OSCULP32K) Oscillator Calibration */
#define OSC32KCTRL_OSCULP32K_CALIB_Msk (0x1Ful << OSC32KCTRL_OSCULP32K_CALIB_Pos)
#define OSC32KCTRL_OSCULP32K_CALIB(value) (OSC32KCTRL_OSCULP32K_CALIB_Msk & ((value) << OSC32KCTRL_OSCULP32K_CALIB_Pos))
#define OSC32KCTRL_OSCULP32K_WRTLOCK_Pos 15           /**< \brief (OSC32KCTRL_OSCULP32K) Write Lock */
#define OSC32KCTRL_OSCULP32K_WRTLOCK (0x1ul << OSC32KCTRL_OSCULP32K_WRTLOCK_Pos)
#define OSC32KCTRL_OSCULP32K_MASK   0x00009F06ul /**< \brief (OSC32KCTRL_OSCULP32K) MASK Register */

/** \brief OSC32KCTRL hardware registers */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct {
  __IO OSC32KCTRL_INTENCLR_Type  INTENCLR;    /**< \brief Offset: 0x00 (R/W 32) Interrupt Enable Clear */
  __IO OSC32KCTRL_INTENSET_Type  INTENSET;    /**< \brief Offset: 0x04 (R/W 32) Interrupt Enable Set */
  __IO OSC32KCTRL_INTFLAG_Type   INTFLAG;     /**< \brief Offset: 0x08 (R/W 32) Interrupt Flag Status and Clear */
  __I  OSC32KCTRL_STATUS_Type    STATUS;      /**< \brief Offset: 0x0C (R/  32) Power and Clocks Status */
  __IO OSC32KCTRL_RTCCTRL_Type   RTCCTRL;     /**< \brief Offset: 0x10 (R/W  8) RTC Clock Selection */
  __IO OSC32KCTRL_SLCDCTRL_Type  SLCDCTRL;    /**< \brief Offset: 0x11 (R/W  8) SLCD Clock Selection */
       RoReg8                    Reserved1[0x2];
  __IO OSC32KCTRL_XOSC32K_Type   XOSC32K;     /**< \brief Offset: 0x14 (R/W 16) 32kHz External Crystal Oscillator (XOSC32K) Control */
  __IO OSC32KCTRL_CFDCTRL_Type   CFDCTRL;     /**< \brief Offset: 0x16 (R/W  8) Clock Failure Detector Control */
  __IO OSC32KCTRL_EVCTRL_Type    EVCTRL;      /**< \brief Offset: 0x17 (R/W  8) Event Control */
       RoReg8                    Reserved2[0x4];
  __IO OSC32KCTRL_OSCULP32K_Type OSCULP32K;   /**< \brief Offset: 0x1C (R/W 32) 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control */
} Osc32kctrl;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/*@}*/

#endif /* _SAML22_OSC32KCTRL_COMPONENT_ */
