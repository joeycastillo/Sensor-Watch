/**
 * \file
 *
 * \brief Component description for SLCD
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

#ifndef _SAML22_SLCD_COMPONENT_
#define _SAML22_SLCD_COMPONENT_

/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR SLCD */
/* ========================================================================== */
/** \addtogroup SAML22_SLCD Segment Liquid Crystal Display Controller */
/*@{*/

#define SLCD_U2264
#define REV_SLCD                    0x100

/* -------- SLCD_CTRLA : (SLCD Offset: 0x00) (R/W 32) Control A -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SWRST:1;          /*!< bit:      0  Software Reset                     */
    uint32_t ENABLE:1;         /*!< bit:      1  Enable                             */
    uint32_t DUTY:3;           /*!< bit:  2.. 4  Duty Ratio                         */
    uint32_t WMOD:1;           /*!< bit:      5  Waveform Mode                      */
    uint32_t RUNSTDBY:1;       /*!< bit:      6  Run in Standby                     */
    uint32_t :1;               /*!< bit:      7  Reserved                           */
    uint32_t PRESC:2;          /*!< bit:  8.. 9  Clock Prescaler                    */
    uint32_t :2;               /*!< bit: 10..11  Reserved                           */
    uint32_t CKDIV:3;          /*!< bit: 12..14  Clock Divider                      */
    uint32_t :1;               /*!< bit:     15  Reserved                           */
    uint32_t BIAS:2;           /*!< bit: 16..17  Bias Setting                       */
    uint32_t :1;               /*!< bit:     18  Reserved                           */
    uint32_t XVLCD:1;          /*!< bit:     19  External VLCD                      */
    uint32_t PRF:2;            /*!< bit: 20..21  Power Refresh Frequency            */
    uint32_t DMFCS:2;          /*!< bit: 22..23  Display Memory Update Frame Counter Selection */
    uint32_t RRF:3;            /*!< bit: 24..26  Reference Refresh Frequency        */
    uint32_t :5;               /*!< bit: 27..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_CTRLA_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CTRLA_OFFSET           0x00         /**< \brief (SLCD_CTRLA offset) Control A */
#define SLCD_CTRLA_RESETVALUE       _U_(0x03D80000) /**< \brief (SLCD_CTRLA reset_value) Control A */

#define SLCD_CTRLA_SWRST_Pos        0            /**< \brief (SLCD_CTRLA) Software Reset */
#define SLCD_CTRLA_SWRST            (_U_(0x1) << SLCD_CTRLA_SWRST_Pos)
#define SLCD_CTRLA_ENABLE_Pos       1            /**< \brief (SLCD_CTRLA) Enable */
#define SLCD_CTRLA_ENABLE           (_U_(0x1) << SLCD_CTRLA_ENABLE_Pos)
#define SLCD_CTRLA_DUTY_Pos         2            /**< \brief (SLCD_CTRLA) Duty Ratio */
#define SLCD_CTRLA_DUTY_Msk         (_U_(0x7) << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_DUTY(value)      (SLCD_CTRLA_DUTY_Msk & ((value) << SLCD_CTRLA_DUTY_Pos))
#define   SLCD_CTRLA_DUTY_STATIC_Val      _U_(0x0)   /**< \brief (SLCD_CTRLA) Static duty */
#define   SLCD_CTRLA_DUTY_HALF_Val        _U_(0x1)   /**< \brief (SLCD_CTRLA) 1/2 duty */
#define   SLCD_CTRLA_DUTY_THIRD_Val       _U_(0x2)   /**< \brief (SLCD_CTRLA) 1/3 duty */
#define   SLCD_CTRLA_DUTY_FOURTH_Val      _U_(0x3)   /**< \brief (SLCD_CTRLA) 1/4 duty */
#define   SLCD_CTRLA_DUTY_SIXTH_Val       _U_(0x4)   /**< \brief (SLCD_CTRLA) 1/6 duty */
#define   SLCD_CTRLA_DUTY_EIGHT_Val       _U_(0x5)   /**< \brief (SLCD_CTRLA) 1/8 duty */
#define SLCD_CTRLA_DUTY_STATIC      (SLCD_CTRLA_DUTY_STATIC_Val    << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_DUTY_HALF        (SLCD_CTRLA_DUTY_HALF_Val      << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_DUTY_THIRD       (SLCD_CTRLA_DUTY_THIRD_Val     << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_DUTY_FOURTH      (SLCD_CTRLA_DUTY_FOURTH_Val    << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_DUTY_SIXTH       (SLCD_CTRLA_DUTY_SIXTH_Val     << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_DUTY_EIGHT       (SLCD_CTRLA_DUTY_EIGHT_Val     << SLCD_CTRLA_DUTY_Pos)
#define SLCD_CTRLA_WMOD_Pos         5            /**< \brief (SLCD_CTRLA) Waveform Mode */
#define SLCD_CTRLA_WMOD             (_U_(0x1) << SLCD_CTRLA_WMOD_Pos)
#define   SLCD_CTRLA_WMOD_LP_Val          _U_(0x0)   /**< \brief (SLCD_CTRLA) Low Power Waveform Mode */
#define   SLCD_CTRLA_WMOD_STD_Val         _U_(0x1)   /**< \brief (SLCD_CTRLA) Standard Waveform Mode */
#define SLCD_CTRLA_WMOD_LP          (SLCD_CTRLA_WMOD_LP_Val        << SLCD_CTRLA_WMOD_Pos)
#define SLCD_CTRLA_WMOD_STD         (SLCD_CTRLA_WMOD_STD_Val       << SLCD_CTRLA_WMOD_Pos)
#define SLCD_CTRLA_RUNSTDBY_Pos     6            /**< \brief (SLCD_CTRLA) Run in Standby */
#define SLCD_CTRLA_RUNSTDBY         (_U_(0x1) << SLCD_CTRLA_RUNSTDBY_Pos)
#define SLCD_CTRLA_PRESC_Pos        8            /**< \brief (SLCD_CTRLA) Clock Prescaler */
#define SLCD_CTRLA_PRESC_Msk        (_U_(0x3) << SLCD_CTRLA_PRESC_Pos)
#define SLCD_CTRLA_PRESC(value)     (SLCD_CTRLA_PRESC_Msk & ((value) << SLCD_CTRLA_PRESC_Pos))
#define   SLCD_CTRLA_PRESC_PRESC16_Val    _U_(0x0)   /**< \brief (SLCD_CTRLA) 16 */
#define   SLCD_CTRLA_PRESC_PRESC32_Val    _U_(0x1)   /**< \brief (SLCD_CTRLA) 32 */
#define   SLCD_CTRLA_PRESC_PRESC64_Val    _U_(0x2)   /**< \brief (SLCD_CTRLA) 64 */
#define   SLCD_CTRLA_PRESC_PRESC128_Val   _U_(0x3)   /**< \brief (SLCD_CTRLA) 128 */
#define SLCD_CTRLA_PRESC_PRESC16    (SLCD_CTRLA_PRESC_PRESC16_Val  << SLCD_CTRLA_PRESC_Pos)
#define SLCD_CTRLA_PRESC_PRESC32    (SLCD_CTRLA_PRESC_PRESC32_Val  << SLCD_CTRLA_PRESC_Pos)
#define SLCD_CTRLA_PRESC_PRESC64    (SLCD_CTRLA_PRESC_PRESC64_Val  << SLCD_CTRLA_PRESC_Pos)
#define SLCD_CTRLA_PRESC_PRESC128   (SLCD_CTRLA_PRESC_PRESC128_Val << SLCD_CTRLA_PRESC_Pos)
#define SLCD_CTRLA_CKDIV_Pos        12           /**< \brief (SLCD_CTRLA) Clock Divider */
#define SLCD_CTRLA_CKDIV_Msk        (_U_(0x7) << SLCD_CTRLA_CKDIV_Pos)
#define SLCD_CTRLA_CKDIV(value)     (SLCD_CTRLA_CKDIV_Msk & ((value) << SLCD_CTRLA_CKDIV_Pos))
#define SLCD_CTRLA_BIAS_Pos         16           /**< \brief (SLCD_CTRLA) Bias Setting */
#define SLCD_CTRLA_BIAS_Msk         (_U_(0x3) << SLCD_CTRLA_BIAS_Pos)
#define SLCD_CTRLA_BIAS(value)      (SLCD_CTRLA_BIAS_Msk & ((value) << SLCD_CTRLA_BIAS_Pos))
#define   SLCD_CTRLA_BIAS_STATIC_Val      _U_(0x0)   /**< \brief (SLCD_CTRLA) Static */
#define   SLCD_CTRLA_BIAS_HALF_Val        _U_(0x1)   /**< \brief (SLCD_CTRLA) 1/2 bias */
#define   SLCD_CTRLA_BIAS_THIRD_Val       _U_(0x2)   /**< \brief (SLCD_CTRLA) 1/3 bias */
#define   SLCD_CTRLA_BIAS_FOURTH_Val      _U_(0x3)   /**< \brief (SLCD_CTRLA) 1/4 bias */
#define SLCD_CTRLA_BIAS_STATIC      (SLCD_CTRLA_BIAS_STATIC_Val    << SLCD_CTRLA_BIAS_Pos)
#define SLCD_CTRLA_BIAS_HALF        (SLCD_CTRLA_BIAS_HALF_Val      << SLCD_CTRLA_BIAS_Pos)
#define SLCD_CTRLA_BIAS_THIRD       (SLCD_CTRLA_BIAS_THIRD_Val     << SLCD_CTRLA_BIAS_Pos)
#define SLCD_CTRLA_BIAS_FOURTH      (SLCD_CTRLA_BIAS_FOURTH_Val    << SLCD_CTRLA_BIAS_Pos)
#define SLCD_CTRLA_XVLCD_Pos        19           /**< \brief (SLCD_CTRLA) External VLCD */
#define SLCD_CTRLA_XVLCD            (_U_(0x1) << SLCD_CTRLA_XVLCD_Pos)
#define SLCD_CTRLA_PRF_Pos          20           /**< \brief (SLCD_CTRLA) Power Refresh Frequency */
#define SLCD_CTRLA_PRF_Msk          (_U_(0x3) << SLCD_CTRLA_PRF_Pos)
#define SLCD_CTRLA_PRF(value)       (SLCD_CTRLA_PRF_Msk & ((value) << SLCD_CTRLA_PRF_Pos))
#define   SLCD_CTRLA_PRF_PR2000_Val       _U_(0x0)   /**< \brief (SLCD_CTRLA) 2kHz */
#define   SLCD_CTRLA_PRF_PR1000_Val       _U_(0x1)   /**< \brief (SLCD_CTRLA) 1kHz */
#define   SLCD_CTRLA_PRF_PR500_Val        _U_(0x2)   /**< \brief (SLCD_CTRLA) 500Hz */
#define   SLCD_CTRLA_PRF_PR250_Val        _U_(0x3)   /**< \brief (SLCD_CTRLA) 250Hz */
#define SLCD_CTRLA_PRF_PR2000       (SLCD_CTRLA_PRF_PR2000_Val     << SLCD_CTRLA_PRF_Pos)
#define SLCD_CTRLA_PRF_PR1000       (SLCD_CTRLA_PRF_PR1000_Val     << SLCD_CTRLA_PRF_Pos)
#define SLCD_CTRLA_PRF_PR500        (SLCD_CTRLA_PRF_PR500_Val      << SLCD_CTRLA_PRF_Pos)
#define SLCD_CTRLA_PRF_PR250        (SLCD_CTRLA_PRF_PR250_Val      << SLCD_CTRLA_PRF_Pos)
#define SLCD_CTRLA_DMFCS_Pos        22           /**< \brief (SLCD_CTRLA) Display Memory Update Frame Counter Selection */
#define SLCD_CTRLA_DMFCS_Msk        (_U_(0x3) << SLCD_CTRLA_DMFCS_Pos)
#define SLCD_CTRLA_DMFCS(value)     (SLCD_CTRLA_DMFCS_Msk & ((value) << SLCD_CTRLA_DMFCS_Pos))
#define   SLCD_CTRLA_DMFCS_FC0_Val        _U_(0x0)   /**< \brief (SLCD_CTRLA) Frame Counter 0 */
#define   SLCD_CTRLA_DMFCS_FC1_Val        _U_(0x1)   /**< \brief (SLCD_CTRLA) Frame Counter 1 */
#define   SLCD_CTRLA_DMFCS_FC2_Val        _U_(0x2)   /**< \brief (SLCD_CTRLA) Frame Counter 2 */
#define   SLCD_CTRLA_DMFCS_NFC_Val        _U_(0x3)   /**< \brief (SLCD_CTRLA) Frame Counter event to DMU is forced to 0 */
#define SLCD_CTRLA_DMFCS_FC0        (SLCD_CTRLA_DMFCS_FC0_Val      << SLCD_CTRLA_DMFCS_Pos)
#define SLCD_CTRLA_DMFCS_FC1        (SLCD_CTRLA_DMFCS_FC1_Val      << SLCD_CTRLA_DMFCS_Pos)
#define SLCD_CTRLA_DMFCS_FC2        (SLCD_CTRLA_DMFCS_FC2_Val      << SLCD_CTRLA_DMFCS_Pos)
#define SLCD_CTRLA_DMFCS_NFC        (SLCD_CTRLA_DMFCS_NFC_Val      << SLCD_CTRLA_DMFCS_Pos)
#define SLCD_CTRLA_RRF_Pos          24           /**< \brief (SLCD_CTRLA) Reference Refresh Frequency */
#define SLCD_CTRLA_RRF_Msk          (_U_(0x7) << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_RRF(value)       (SLCD_CTRLA_RRF_Msk & ((value) << SLCD_CTRLA_RRF_Pos))
#define   SLCD_CTRLA_RRF_RR2000_Val       _U_(0x0)   /**< \brief (SLCD_CTRLA) 2kHz */
#define   SLCD_CTRLA_RRF_RR1000_Val       _U_(0x1)   /**< \brief (SLCD_CTRLA) 1kHz */
#define   SLCD_CTRLA_RRF_RR500_Val        _U_(0x2)   /**< \brief (SLCD_CTRLA) 500Hz */
#define   SLCD_CTRLA_RRF_RR250_Val        _U_(0x3)   /**< \brief (SLCD_CTRLA) 250Hz */
#define   SLCD_CTRLA_RRF_RR125_Val        _U_(0x4)   /**< \brief (SLCD_CTRLA) 125Hz */
#define   SLCD_CTRLA_RRF_RR62_Val         _U_(0x5)   /**< \brief (SLCD_CTRLA) 62.5Hz */
#define SLCD_CTRLA_RRF_RR2000       (SLCD_CTRLA_RRF_RR2000_Val     << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_RRF_RR1000       (SLCD_CTRLA_RRF_RR1000_Val     << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_RRF_RR500        (SLCD_CTRLA_RRF_RR500_Val      << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_RRF_RR250        (SLCD_CTRLA_RRF_RR250_Val      << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_RRF_RR125        (SLCD_CTRLA_RRF_RR125_Val      << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_RRF_RR62         (SLCD_CTRLA_RRF_RR62_Val       << SLCD_CTRLA_RRF_Pos)
#define SLCD_CTRLA_MASK             _U_(0x07FB737F) /**< \brief (SLCD_CTRLA) MASK Register */

/* -------- SLCD_CTRLB : (SLCD Offset: 0x04) (R/W 16) Control B -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint16_t BBD:4;            /*!< bit:  0.. 3  Bias Buffer Enable Duration        */
    uint16_t :3;               /*!< bit:  4.. 6  Reserved                           */
    uint16_t BBEN:1;           /*!< bit:      7  Bias Buffer Enable                 */
    uint16_t LRD:4;            /*!< bit:  8..11  Low Resistance Enable Duration     */
    uint16_t :3;               /*!< bit: 12..14  Reserved                           */
    uint16_t LREN:1;           /*!< bit:     15  Low Resistance Enable              */
  } bit;                       /*!< Structure used for bit  access                  */
  uint16_t reg;                /*!< Type      used for register access              */
} SLCD_CTRLB_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CTRLB_OFFSET           0x04         /**< \brief (SLCD_CTRLB offset) Control B */
#define SLCD_CTRLB_RESETVALUE       _U_(0x0000)  /**< \brief (SLCD_CTRLB reset_value) Control B */

#define SLCD_CTRLB_BBD_Pos          0            /**< \brief (SLCD_CTRLB) Bias Buffer Enable Duration */
#define SLCD_CTRLB_BBD_Msk          (_U_(0xF) << SLCD_CTRLB_BBD_Pos)
#define SLCD_CTRLB_BBD(value)       (SLCD_CTRLB_BBD_Msk & ((value) << SLCD_CTRLB_BBD_Pos))
#define SLCD_CTRLB_BBEN_Pos         7            /**< \brief (SLCD_CTRLB) Bias Buffer Enable */
#define SLCD_CTRLB_BBEN             (_U_(0x1) << SLCD_CTRLB_BBEN_Pos)
#define SLCD_CTRLB_LRD_Pos          8            /**< \brief (SLCD_CTRLB) Low Resistance Enable Duration */
#define SLCD_CTRLB_LRD_Msk          (_U_(0xF) << SLCD_CTRLB_LRD_Pos)
#define SLCD_CTRLB_LRD(value)       (SLCD_CTRLB_LRD_Msk & ((value) << SLCD_CTRLB_LRD_Pos))
#define SLCD_CTRLB_LREN_Pos         15           /**< \brief (SLCD_CTRLB) Low Resistance Enable */
#define SLCD_CTRLB_LREN             (_U_(0x1) << SLCD_CTRLB_LREN_Pos)
#define SLCD_CTRLB_MASK             _U_(0x8F8F)  /**< \brief (SLCD_CTRLB) MASK Register */

/* -------- SLCD_CTRLC : (SLCD Offset: 0x06) (R/W 16) Control C -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint16_t CLEAR:1;          /*!< bit:      0  Clear Display Memory               */
    uint16_t LOCK:1;           /*!< bit:      1  Lock Shadow Memory                 */
    uint16_t ABMEN:1;          /*!< bit:      2  Automated Bit Mapping Enable       */
    uint16_t ACMEN:1;          /*!< bit:      3  Automated Character Mapping Enable */
    uint16_t CTST:4;           /*!< bit:  4.. 7  Contrast Adjustment                */
    uint16_t LPPM:2;           /*!< bit:  8.. 9  LCD Power Macro Power mode         */
    uint16_t :6;               /*!< bit: 10..15  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint16_t reg;                /*!< Type      used for register access              */
} SLCD_CTRLC_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CTRLC_OFFSET           0x06         /**< \brief (SLCD_CTRLC offset) Control C */
#define SLCD_CTRLC_RESETVALUE       _U_(0x0000)  /**< \brief (SLCD_CTRLC reset_value) Control C */

#define SLCD_CTRLC_CLEAR_Pos        0            /**< \brief (SLCD_CTRLC) Clear Display Memory */
#define SLCD_CTRLC_CLEAR            (_U_(0x1) << SLCD_CTRLC_CLEAR_Pos)
#define SLCD_CTRLC_LOCK_Pos         1            /**< \brief (SLCD_CTRLC) Lock Shadow Memory */
#define SLCD_CTRLC_LOCK             (_U_(0x1) << SLCD_CTRLC_LOCK_Pos)
#define SLCD_CTRLC_ABMEN_Pos        2            /**< \brief (SLCD_CTRLC) Automated Bit Mapping Enable */
#define SLCD_CTRLC_ABMEN            (_U_(0x1) << SLCD_CTRLC_ABMEN_Pos)
#define SLCD_CTRLC_ACMEN_Pos        3            /**< \brief (SLCD_CTRLC) Automated Character Mapping Enable */
#define SLCD_CTRLC_ACMEN            (_U_(0x1) << SLCD_CTRLC_ACMEN_Pos)
#define SLCD_CTRLC_CTST_Pos         4            /**< \brief (SLCD_CTRLC) Contrast Adjustment */
#define SLCD_CTRLC_CTST_Msk         (_U_(0xF) << SLCD_CTRLC_CTST_Pos)
#define SLCD_CTRLC_CTST(value)      (SLCD_CTRLC_CTST_Msk & ((value) << SLCD_CTRLC_CTST_Pos))
#define SLCD_CTRLC_LPPM_Pos         8            /**< \brief (SLCD_CTRLC) LCD Power Macro Power mode */
#define SLCD_CTRLC_LPPM_Msk         (_U_(0x3) << SLCD_CTRLC_LPPM_Pos)
#define SLCD_CTRLC_LPPM(value)      (SLCD_CTRLC_LPPM_Msk & ((value) << SLCD_CTRLC_LPPM_Pos))
#define   SLCD_CTRLC_LPPM_AUTO_Val        _U_(0x0)   /**< \brief (SLCD_CTRLC) LCD power automatically select regualation mode or pump mode */
#define   SLCD_CTRLC_LPPM_STEPUP_Val      _U_(0x1)   /**< \brief (SLCD_CTRLC) LCD power use step-up pump loop only */
#define   SLCD_CTRLC_LPPM_STEPDOWN_Val    _U_(0x2)   /**< \brief (SLCD_CTRLC) LCD power use step-down drop-out regulation loop only */
#define SLCD_CTRLC_LPPM_AUTO        (SLCD_CTRLC_LPPM_AUTO_Val      << SLCD_CTRLC_LPPM_Pos)
#define SLCD_CTRLC_LPPM_STEPUP      (SLCD_CTRLC_LPPM_STEPUP_Val    << SLCD_CTRLC_LPPM_Pos)
#define SLCD_CTRLC_LPPM_STEPDOWN    (SLCD_CTRLC_LPPM_STEPDOWN_Val  << SLCD_CTRLC_LPPM_Pos)
#define SLCD_CTRLC_MASK             _U_(0x03FF)  /**< \brief (SLCD_CTRLC) MASK Register */

/* -------- SLCD_CTRLD : (SLCD Offset: 0x08) (R/W  8) Control D -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  BLANK:1;          /*!< bit:      0  Blank LCD                          */
    uint8_t  BLINK:1;          /*!< bit:      1  Blinking Enable                    */
    uint8_t  CSREN:1;          /*!< bit:      2  Circular Shift Register Enable     */
    uint8_t  :1;               /*!< bit:      3  Reserved                           */
    uint8_t  FC0EN:1;          /*!< bit:      4  Frame Counter 0 Enable             */
    uint8_t  FC1EN:1;          /*!< bit:      5  Frame Counter 1 Enable             */
    uint8_t  FC2EN:1;          /*!< bit:      6  Frame Counter 2 Enable             */
    uint8_t  DISPEN:1;         /*!< bit:      7  Display enable                     */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_CTRLD_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CTRLD_OFFSET           0x08         /**< \brief (SLCD_CTRLD offset) Control D */
#define SLCD_CTRLD_RESETVALUE       _U_(0x80)    /**< \brief (SLCD_CTRLD reset_value) Control D */

#define SLCD_CTRLD_BLANK_Pos        0            /**< \brief (SLCD_CTRLD) Blank LCD */
#define SLCD_CTRLD_BLANK            (_U_(0x1) << SLCD_CTRLD_BLANK_Pos)
#define SLCD_CTRLD_BLINK_Pos        1            /**< \brief (SLCD_CTRLD) Blinking Enable */
#define SLCD_CTRLD_BLINK            (_U_(0x1) << SLCD_CTRLD_BLINK_Pos)
#define SLCD_CTRLD_CSREN_Pos        2            /**< \brief (SLCD_CTRLD) Circular Shift Register Enable */
#define SLCD_CTRLD_CSREN            (_U_(0x1) << SLCD_CTRLD_CSREN_Pos)
#define SLCD_CTRLD_FC0EN_Pos        4            /**< \brief (SLCD_CTRLD) Frame Counter 0 Enable */
#define SLCD_CTRLD_FC0EN            (_U_(0x1) << SLCD_CTRLD_FC0EN_Pos)
#define SLCD_CTRLD_FC1EN_Pos        5            /**< \brief (SLCD_CTRLD) Frame Counter 1 Enable */
#define SLCD_CTRLD_FC1EN            (_U_(0x1) << SLCD_CTRLD_FC1EN_Pos)
#define SLCD_CTRLD_FC2EN_Pos        6            /**< \brief (SLCD_CTRLD) Frame Counter 2 Enable */
#define SLCD_CTRLD_FC2EN            (_U_(0x1) << SLCD_CTRLD_FC2EN_Pos)
#define SLCD_CTRLD_DISPEN_Pos       7            /**< \brief (SLCD_CTRLD) Display enable */
#define SLCD_CTRLD_DISPEN           (_U_(0x1) << SLCD_CTRLD_DISPEN_Pos)
#define SLCD_CTRLD_MASK             _U_(0xF7)    /**< \brief (SLCD_CTRLD) MASK Register */

/* -------- SLCD_EVCTRL : (SLCD Offset: 0x0C) (R/W  8) Event Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  FC0OEO:1;         /*!< bit:      0  Frame Counter 0 Overflow Event Output Enable */
    uint8_t  FC1OEO:1;         /*!< bit:      1  Frame Counter 1 Overflow Event Output Enable */
    uint8_t  FC2OEO:1;         /*!< bit:      2  Frame Counter 2 Overflow Event Output Enable */
    uint8_t  :5;               /*!< bit:  3.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_EVCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_EVCTRL_OFFSET          0x0C         /**< \brief (SLCD_EVCTRL offset) Event Control */
#define SLCD_EVCTRL_RESETVALUE      _U_(0x00)    /**< \brief (SLCD_EVCTRL reset_value) Event Control */

#define SLCD_EVCTRL_FC0OEO_Pos      0            /**< \brief (SLCD_EVCTRL) Frame Counter 0 Overflow Event Output Enable */
#define SLCD_EVCTRL_FC0OEO          (_U_(0x1) << SLCD_EVCTRL_FC0OEO_Pos)
#define SLCD_EVCTRL_FC1OEO_Pos      1            /**< \brief (SLCD_EVCTRL) Frame Counter 1 Overflow Event Output Enable */
#define SLCD_EVCTRL_FC1OEO          (_U_(0x1) << SLCD_EVCTRL_FC1OEO_Pos)
#define SLCD_EVCTRL_FC2OEO_Pos      2            /**< \brief (SLCD_EVCTRL) Frame Counter 2 Overflow Event Output Enable */
#define SLCD_EVCTRL_FC2OEO          (_U_(0x1) << SLCD_EVCTRL_FC2OEO_Pos)
#define SLCD_EVCTRL_MASK            _U_(0x07)    /**< \brief (SLCD_EVCTRL) MASK Register */

/* -------- SLCD_INTENCLR : (SLCD Offset: 0x0D) (R/W  8) Interrupt Enable Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  FC0O:1;           /*!< bit:      0  Frame Counter 0 Overflow Interrupt Disable */
    uint8_t  FC1O:1;           /*!< bit:      1  Frame Counter 1 Overflow Interrupt Disable */
    uint8_t  FC2O:1;           /*!< bit:      2  Frame Counter 2 Overflow Interrupt Disable */
    uint8_t  VLCDRT:1;         /*!< bit:      3  VLCD Ready Toggle Interrupt Disable */
    uint8_t  VLCDST:1;         /*!< bit:      4  VLCD Status Toggle Interrupt Disable */
    uint8_t  PRST:1;           /*!< bit:      5  Pump Run Status Toggle Interrupt Disable */
    uint8_t  :2;               /*!< bit:  6.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_INTENCLR_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_INTENCLR_OFFSET        0x0D         /**< \brief (SLCD_INTENCLR offset) Interrupt Enable Clear */
#define SLCD_INTENCLR_RESETVALUE    _U_(0x00)    /**< \brief (SLCD_INTENCLR reset_value) Interrupt Enable Clear */

#define SLCD_INTENCLR_FC0O_Pos      0            /**< \brief (SLCD_INTENCLR) Frame Counter 0 Overflow Interrupt Disable */
#define SLCD_INTENCLR_FC0O          (_U_(0x1) << SLCD_INTENCLR_FC0O_Pos)
#define SLCD_INTENCLR_FC1O_Pos      1            /**< \brief (SLCD_INTENCLR) Frame Counter 1 Overflow Interrupt Disable */
#define SLCD_INTENCLR_FC1O          (_U_(0x1) << SLCD_INTENCLR_FC1O_Pos)
#define SLCD_INTENCLR_FC2O_Pos      2            /**< \brief (SLCD_INTENCLR) Frame Counter 2 Overflow Interrupt Disable */
#define SLCD_INTENCLR_FC2O          (_U_(0x1) << SLCD_INTENCLR_FC2O_Pos)
#define SLCD_INTENCLR_VLCDRT_Pos    3            /**< \brief (SLCD_INTENCLR) VLCD Ready Toggle Interrupt Disable */
#define SLCD_INTENCLR_VLCDRT        (_U_(0x1) << SLCD_INTENCLR_VLCDRT_Pos)
#define SLCD_INTENCLR_VLCDST_Pos    4            /**< \brief (SLCD_INTENCLR) VLCD Status Toggle Interrupt Disable */
#define SLCD_INTENCLR_VLCDST        (_U_(0x1) << SLCD_INTENCLR_VLCDST_Pos)
#define SLCD_INTENCLR_PRST_Pos      5            /**< \brief (SLCD_INTENCLR) Pump Run Status Toggle Interrupt Disable */
#define SLCD_INTENCLR_PRST          (_U_(0x1) << SLCD_INTENCLR_PRST_Pos)
#define SLCD_INTENCLR_MASK          _U_(0x3F)    /**< \brief (SLCD_INTENCLR) MASK Register */

/* -------- SLCD_INTENSET : (SLCD Offset: 0x0E) (R/W  8) Interrupt Enable Set -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  FC0O:1;           /*!< bit:      0  Frame Counter 0 Overflow Interrupt Enable */
    uint8_t  FC1O:1;           /*!< bit:      1  Frame Counter 1 Overflow Interrupt Enable */
    uint8_t  FC2O:1;           /*!< bit:      2  Frame Counter 2 Overflow Interrupt Enable */
    uint8_t  VLCDRT:1;         /*!< bit:      3  VLCD Ready Toggle Interrupt Enable */
    uint8_t  VLCDST:1;         /*!< bit:      4  VLCD Status Toggle Interrupt Enable */
    uint8_t  PRST:1;           /*!< bit:      5  Pump Run Status Toggle Interrupt Enable */
    uint8_t  :2;               /*!< bit:  6.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_INTENSET_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_INTENSET_OFFSET        0x0E         /**< \brief (SLCD_INTENSET offset) Interrupt Enable Set */
#define SLCD_INTENSET_RESETVALUE    _U_(0x00)    /**< \brief (SLCD_INTENSET reset_value) Interrupt Enable Set */

#define SLCD_INTENSET_FC0O_Pos      0            /**< \brief (SLCD_INTENSET) Frame Counter 0 Overflow Interrupt Enable */
#define SLCD_INTENSET_FC0O          (_U_(0x1) << SLCD_INTENSET_FC0O_Pos)
#define SLCD_INTENSET_FC1O_Pos      1            /**< \brief (SLCD_INTENSET) Frame Counter 1 Overflow Interrupt Enable */
#define SLCD_INTENSET_FC1O          (_U_(0x1) << SLCD_INTENSET_FC1O_Pos)
#define SLCD_INTENSET_FC2O_Pos      2            /**< \brief (SLCD_INTENSET) Frame Counter 2 Overflow Interrupt Enable */
#define SLCD_INTENSET_FC2O          (_U_(0x1) << SLCD_INTENSET_FC2O_Pos)
#define SLCD_INTENSET_VLCDRT_Pos    3            /**< \brief (SLCD_INTENSET) VLCD Ready Toggle Interrupt Enable */
#define SLCD_INTENSET_VLCDRT        (_U_(0x1) << SLCD_INTENSET_VLCDRT_Pos)
#define SLCD_INTENSET_VLCDST_Pos    4            /**< \brief (SLCD_INTENSET) VLCD Status Toggle Interrupt Enable */
#define SLCD_INTENSET_VLCDST        (_U_(0x1) << SLCD_INTENSET_VLCDST_Pos)
#define SLCD_INTENSET_PRST_Pos      5            /**< \brief (SLCD_INTENSET) Pump Run Status Toggle Interrupt Enable */
#define SLCD_INTENSET_PRST          (_U_(0x1) << SLCD_INTENSET_PRST_Pos)
#define SLCD_INTENSET_MASK          _U_(0x3F)    /**< \brief (SLCD_INTENSET) MASK Register */

/* -------- SLCD_INTFLAG : (SLCD Offset: 0x0F) (R/W  8) Interrupt Flag Status and Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { // __I to avoid read-modify-write on write-to-clear register
  struct {
    __I uint8_t  FC0O:1;           /*!< bit:      0  Frame Counter 0 Overflow           */
    __I uint8_t  FC1O:1;           /*!< bit:      1  Frame Counter 1 Overflow           */
    __I uint8_t  FC2O:1;           /*!< bit:      2  Frame Counter 2 Overflow           */
    __I uint8_t  VLCDRT:1;         /*!< bit:      3  VLCD Ready Toggle                  */
    __I uint8_t  VLCDST:1;         /*!< bit:      4  VLCD Status Toggle                 */
    __I uint8_t  PRST:1;           /*!< bit:      5  Pump Run Status Toggle             */
    __I uint8_t  :2;               /*!< bit:  6.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_INTFLAG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_INTFLAG_OFFSET         0x0F         /**< \brief (SLCD_INTFLAG offset) Interrupt Flag Status and Clear */
#define SLCD_INTFLAG_RESETVALUE     _U_(0x00)    /**< \brief (SLCD_INTFLAG reset_value) Interrupt Flag Status and Clear */

#define SLCD_INTFLAG_FC0O_Pos       0            /**< \brief (SLCD_INTFLAG) Frame Counter 0 Overflow */
#define SLCD_INTFLAG_FC0O           (_U_(0x1) << SLCD_INTFLAG_FC0O_Pos)
#define SLCD_INTFLAG_FC1O_Pos       1            /**< \brief (SLCD_INTFLAG) Frame Counter 1 Overflow */
#define SLCD_INTFLAG_FC1O           (_U_(0x1) << SLCD_INTFLAG_FC1O_Pos)
#define SLCD_INTFLAG_FC2O_Pos       2            /**< \brief (SLCD_INTFLAG) Frame Counter 2 Overflow */
#define SLCD_INTFLAG_FC2O           (_U_(0x1) << SLCD_INTFLAG_FC2O_Pos)
#define SLCD_INTFLAG_VLCDRT_Pos     3            /**< \brief (SLCD_INTFLAG) VLCD Ready Toggle */
#define SLCD_INTFLAG_VLCDRT         (_U_(0x1) << SLCD_INTFLAG_VLCDRT_Pos)
#define SLCD_INTFLAG_VLCDST_Pos     4            /**< \brief (SLCD_INTFLAG) VLCD Status Toggle */
#define SLCD_INTFLAG_VLCDST         (_U_(0x1) << SLCD_INTFLAG_VLCDST_Pos)
#define SLCD_INTFLAG_PRST_Pos       5            /**< \brief (SLCD_INTFLAG) Pump Run Status Toggle */
#define SLCD_INTFLAG_PRST           (_U_(0x1) << SLCD_INTFLAG_PRST_Pos)
#define SLCD_INTFLAG_MASK           _U_(0x3F)    /**< \brief (SLCD_INTFLAG) MASK Register */

/* -------- SLCD_STATUS : (SLCD Offset: 0x10) (R/   8) Status -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  VLCDR:1;          /*!< bit:      0  VLCD Ready                         */
    uint8_t  PRUN:1;           /*!< bit:      1  LCD Charge Pump is Running         */
    uint8_t  VLCDS:1;          /*!< bit:      2  VLCD Status                        */
    uint8_t  CMWRBUSY:1;       /*!< bit:      3  Character mapping write busy       */
    uint8_t  ACMBUSY:1;        /*!< bit:      4  ACM state machine busy             */
    uint8_t  ABMBUSY:1;        /*!< bit:      5  ABM state machine busy             */
    uint8_t  :2;               /*!< bit:  6.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_STATUS_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_STATUS_OFFSET          0x10         /**< \brief (SLCD_STATUS offset) Status */
#define SLCD_STATUS_RESETVALUE      _U_(0x00)    /**< \brief (SLCD_STATUS reset_value) Status */

#define SLCD_STATUS_VLCDR_Pos       0            /**< \brief (SLCD_STATUS) VLCD Ready */
#define SLCD_STATUS_VLCDR           (_U_(0x1) << SLCD_STATUS_VLCDR_Pos)
#define SLCD_STATUS_PRUN_Pos        1            /**< \brief (SLCD_STATUS) LCD Charge Pump is Running */
#define SLCD_STATUS_PRUN            (_U_(0x1) << SLCD_STATUS_PRUN_Pos)
#define SLCD_STATUS_VLCDS_Pos       2            /**< \brief (SLCD_STATUS) VLCD Status */
#define SLCD_STATUS_VLCDS           (_U_(0x1) << SLCD_STATUS_VLCDS_Pos)
#define SLCD_STATUS_CMWRBUSY_Pos    3            /**< \brief (SLCD_STATUS) Character mapping write busy */
#define SLCD_STATUS_CMWRBUSY        (_U_(0x1) << SLCD_STATUS_CMWRBUSY_Pos)
#define SLCD_STATUS_ACMBUSY_Pos     4            /**< \brief (SLCD_STATUS) ACM state machine busy */
#define SLCD_STATUS_ACMBUSY         (_U_(0x1) << SLCD_STATUS_ACMBUSY_Pos)
#define SLCD_STATUS_ABMBUSY_Pos     5            /**< \brief (SLCD_STATUS) ABM state machine busy */
#define SLCD_STATUS_ABMBUSY         (_U_(0x1) << SLCD_STATUS_ABMBUSY_Pos)
#define SLCD_STATUS_MASK            _U_(0x3F)    /**< \brief (SLCD_STATUS) MASK Register */

/* -------- SLCD_SYNCBUSY : (SLCD Offset: 0x14) (R/  32) Synchronization Busy -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SWRST:1;          /*!< bit:      0  Software Reset                     */
    uint32_t ENABLE:1;         /*!< bit:      1  Enable                             */
    uint32_t CTRLD:1;          /*!< bit:      2  Control D                          */
    uint32_t :29;              /*!< bit:  3..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SYNCBUSY_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SYNCBUSY_OFFSET        0x14         /**< \brief (SLCD_SYNCBUSY offset) Synchronization Busy */
#define SLCD_SYNCBUSY_RESETVALUE    _U_(0x00000000) /**< \brief (SLCD_SYNCBUSY reset_value) Synchronization Busy */

#define SLCD_SYNCBUSY_SWRST_Pos     0            /**< \brief (SLCD_SYNCBUSY) Software Reset */
#define SLCD_SYNCBUSY_SWRST         (_U_(0x1) << SLCD_SYNCBUSY_SWRST_Pos)
#define SLCD_SYNCBUSY_ENABLE_Pos    1            /**< \brief (SLCD_SYNCBUSY) Enable */
#define SLCD_SYNCBUSY_ENABLE        (_U_(0x1) << SLCD_SYNCBUSY_ENABLE_Pos)
#define SLCD_SYNCBUSY_CTRLD_Pos     2            /**< \brief (SLCD_SYNCBUSY) Control D */
#define SLCD_SYNCBUSY_CTRLD         (_U_(0x1) << SLCD_SYNCBUSY_CTRLD_Pos)
#define SLCD_SYNCBUSY_MASK          _U_(0x00000007) /**< \brief (SLCD_SYNCBUSY) MASK Register */

/* -------- SLCD_FC0 : (SLCD Offset: 0x18) (R/W  8) Frame Counter 0 Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  OVF:5;            /*!< bit:  0.. 4  Frame Counter Overflow Value       */
    uint8_t  :2;               /*!< bit:  5.. 6  Reserved                           */
    uint8_t  PB:1;             /*!< bit:      7  Prescaler Bypass                   */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_FC0_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_FC0_OFFSET             0x18         /**< \brief (SLCD_FC0 offset) Frame Counter 0 Configuration */
#define SLCD_FC0_RESETVALUE         _U_(0x00)    /**< \brief (SLCD_FC0 reset_value) Frame Counter 0 Configuration */

#define SLCD_FC0_OVF_Pos            0            /**< \brief (SLCD_FC0) Frame Counter Overflow Value */
#define SLCD_FC0_OVF_Msk            (_U_(0x1F) << SLCD_FC0_OVF_Pos)
#define SLCD_FC0_OVF(value)         (SLCD_FC0_OVF_Msk & ((value) << SLCD_FC0_OVF_Pos))
#define SLCD_FC0_PB_Pos             7            /**< \brief (SLCD_FC0) Prescaler Bypass */
#define SLCD_FC0_PB                 (_U_(0x1) << SLCD_FC0_PB_Pos)
#define SLCD_FC0_MASK               _U_(0x9F)    /**< \brief (SLCD_FC0) MASK Register */

/* -------- SLCD_FC1 : (SLCD Offset: 0x19) (R/W  8) Frame Counter 1 Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  OVF:5;            /*!< bit:  0.. 4  Frame Counter Overflow Value       */
    uint8_t  :2;               /*!< bit:  5.. 6  Reserved                           */
    uint8_t  PB:1;             /*!< bit:      7  Prescaler Bypass                   */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_FC1_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_FC1_OFFSET             0x19         /**< \brief (SLCD_FC1 offset) Frame Counter 1 Configuration */
#define SLCD_FC1_RESETVALUE         _U_(0x00)    /**< \brief (SLCD_FC1 reset_value) Frame Counter 1 Configuration */

#define SLCD_FC1_OVF_Pos            0            /**< \brief (SLCD_FC1) Frame Counter Overflow Value */
#define SLCD_FC1_OVF_Msk            (_U_(0x1F) << SLCD_FC1_OVF_Pos)
#define SLCD_FC1_OVF(value)         (SLCD_FC1_OVF_Msk & ((value) << SLCD_FC1_OVF_Pos))
#define SLCD_FC1_PB_Pos             7            /**< \brief (SLCD_FC1) Prescaler Bypass */
#define SLCD_FC1_PB                 (_U_(0x1) << SLCD_FC1_PB_Pos)
#define SLCD_FC1_MASK               _U_(0x9F)    /**< \brief (SLCD_FC1) MASK Register */

/* -------- SLCD_FC2 : (SLCD Offset: 0x1A) (R/W  8) Frame Counter 2 Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  OVF:5;            /*!< bit:  0.. 4  Frame Counter Overflow Value       */
    uint8_t  :2;               /*!< bit:  5.. 6  Reserved                           */
    uint8_t  PB:1;             /*!< bit:      7  Prescaler Bypass                   */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_FC2_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_FC2_OFFSET             0x1A         /**< \brief (SLCD_FC2 offset) Frame Counter 2 Configuration */
#define SLCD_FC2_RESETVALUE         _U_(0x00)    /**< \brief (SLCD_FC2 reset_value) Frame Counter 2 Configuration */

#define SLCD_FC2_OVF_Pos            0            /**< \brief (SLCD_FC2) Frame Counter Overflow Value */
#define SLCD_FC2_OVF_Msk            (_U_(0x1F) << SLCD_FC2_OVF_Pos)
#define SLCD_FC2_OVF(value)         (SLCD_FC2_OVF_Msk & ((value) << SLCD_FC2_OVF_Pos))
#define SLCD_FC2_PB_Pos             7            /**< \brief (SLCD_FC2) Prescaler Bypass */
#define SLCD_FC2_PB                 (_U_(0x1) << SLCD_FC2_PB_Pos)
#define SLCD_FC2_MASK               _U_(0x9F)    /**< \brief (SLCD_FC2) MASK Register */

/* -------- SLCD_LPENL : (SLCD Offset: 0x1C) (R/W 32) LCD Pin Enable Low -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t LPEN:32;          /*!< bit:  0..31  LCD Pin Enable                     */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_LPENL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_LPENL_OFFSET           0x1C         /**< \brief (SLCD_LPENL offset) LCD Pin Enable Low */
#define SLCD_LPENL_RESETVALUE       _U_(0x00000000) /**< \brief (SLCD_LPENL reset_value) LCD Pin Enable Low */

#define SLCD_LPENL_LPEN_Pos         0            /**< \brief (SLCD_LPENL) LCD Pin Enable */
#define SLCD_LPENL_LPEN_Msk         (_U_(0xFFFFFFFF) << SLCD_LPENL_LPEN_Pos)
#define SLCD_LPENL_LPEN(value)      (SLCD_LPENL_LPEN_Msk & ((value) << SLCD_LPENL_LPEN_Pos))
#define SLCD_LPENL_MASK             _U_(0xFFFFFFFF) /**< \brief (SLCD_LPENL) MASK Register */

/* -------- SLCD_LPENH : (SLCD Offset: 0x20) (R/W 32) LCD Pin Enable High -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t LPEN:20;          /*!< bit:  0..19  LCD Pin Enable                     */
    uint32_t :12;              /*!< bit: 20..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_LPENH_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_LPENH_OFFSET           0x20         /**< \brief (SLCD_LPENH offset) LCD Pin Enable High */
#define SLCD_LPENH_RESETVALUE       _U_(0x00000000) /**< \brief (SLCD_LPENH reset_value) LCD Pin Enable High */

#define SLCD_LPENH_LPEN_Pos         0            /**< \brief (SLCD_LPENH) LCD Pin Enable */
#define SLCD_LPENH_LPEN_Msk         (_U_(0xFFFFF) << SLCD_LPENH_LPEN_Pos)
#define SLCD_LPENH_LPEN(value)      (SLCD_LPENH_LPEN_Msk & ((value) << SLCD_LPENH_LPEN_Pos))
#define SLCD_LPENH_MASK             _U_(0x000FFFFF) /**< \brief (SLCD_LPENH) MASK Register */

/* -------- SLCD_SDATAL0 : (SLCD Offset: 0x24) (R/W 32) Segments Data Low for COM0 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL0_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL0_OFFSET         0x24         /**< \brief (SLCD_SDATAL0 offset) Segments Data Low for COM0 Line */
#define SLCD_SDATAL0_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL0 reset_value) Segments Data Low for COM0 Line */

#define SLCD_SDATAL0_SDATA_Pos      0            /**< \brief (SLCD_SDATAL0) Segments Data */
#define SLCD_SDATAL0_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL0_SDATA_Pos)
#define SLCD_SDATAL0_SDATA(value)   (SLCD_SDATAL0_SDATA_Msk & ((value) << SLCD_SDATAL0_SDATA_Pos))
#define SLCD_SDATAL0_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL0) MASK Register */

/* -------- SLCD_SDATAH0 : (SLCD Offset: 0x28) (R/W 32) Segments Data High for COM0 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:12;         /*!< bit:  0..11  Segments Data                      */
    uint32_t :20;              /*!< bit: 12..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH0_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH0_OFFSET         0x28         /**< \brief (SLCD_SDATAH0 offset) Segments Data High for COM0 Line */
#define SLCD_SDATAH0_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH0 reset_value) Segments Data High for COM0 Line */

#define SLCD_SDATAH0_SDATA_Pos      0            /**< \brief (SLCD_SDATAH0) Segments Data */
#define SLCD_SDATAH0_SDATA_Msk      (_U_(0xFFF) << SLCD_SDATAH0_SDATA_Pos)
#define SLCD_SDATAH0_SDATA(value)   (SLCD_SDATAH0_SDATA_Msk & ((value) << SLCD_SDATAH0_SDATA_Pos))
#define SLCD_SDATAH0_MASK           _U_(0x00000FFF) /**< \brief (SLCD_SDATAH0) MASK Register */

/* -------- SLCD_SDATAL1 : (SLCD Offset: 0x2C) (R/W 32) Segments Data Low for COM1 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL1_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL1_OFFSET         0x2C         /**< \brief (SLCD_SDATAL1 offset) Segments Data Low for COM1 Line */
#define SLCD_SDATAL1_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL1 reset_value) Segments Data Low for COM1 Line */

#define SLCD_SDATAL1_SDATA_Pos      0            /**< \brief (SLCD_SDATAL1) Segments Data */
#define SLCD_SDATAL1_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL1_SDATA_Pos)
#define SLCD_SDATAL1_SDATA(value)   (SLCD_SDATAL1_SDATA_Msk & ((value) << SLCD_SDATAL1_SDATA_Pos))
#define SLCD_SDATAL1_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL1) MASK Register */

/* -------- SLCD_SDATAH1 : (SLCD Offset: 0x30) (R/W 32) Segments Data High for COM1 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:12;         /*!< bit:  0..11  Segments Data                      */
    uint32_t :20;              /*!< bit: 12..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH1_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH1_OFFSET         0x30         /**< \brief (SLCD_SDATAH1 offset) Segments Data High for COM1 Line */
#define SLCD_SDATAH1_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH1 reset_value) Segments Data High for COM1 Line */

#define SLCD_SDATAH1_SDATA_Pos      0            /**< \brief (SLCD_SDATAH1) Segments Data */
#define SLCD_SDATAH1_SDATA_Msk      (_U_(0xFFF) << SLCD_SDATAH1_SDATA_Pos)
#define SLCD_SDATAH1_SDATA(value)   (SLCD_SDATAH1_SDATA_Msk & ((value) << SLCD_SDATAH1_SDATA_Pos))
#define SLCD_SDATAH1_MASK           _U_(0x00000FFF) /**< \brief (SLCD_SDATAH1) MASK Register */

/* -------- SLCD_SDATAL2 : (SLCD Offset: 0x34) (R/W 32) Segments Data Low for COM2 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL2_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL2_OFFSET         0x34         /**< \brief (SLCD_SDATAL2 offset) Segments Data Low for COM2 Line */
#define SLCD_SDATAL2_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL2 reset_value) Segments Data Low for COM2 Line */

#define SLCD_SDATAL2_SDATA_Pos      0            /**< \brief (SLCD_SDATAL2) Segments Data */
#define SLCD_SDATAL2_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL2_SDATA_Pos)
#define SLCD_SDATAL2_SDATA(value)   (SLCD_SDATAL2_SDATA_Msk & ((value) << SLCD_SDATAL2_SDATA_Pos))
#define SLCD_SDATAL2_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL2) MASK Register */

/* -------- SLCD_SDATAH2 : (SLCD Offset: 0x38) (R/W 32) Segments Data High for COM2 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:12;         /*!< bit:  0..11  Segments Data                      */
    uint32_t :20;              /*!< bit: 12..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH2_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH2_OFFSET         0x38         /**< \brief (SLCD_SDATAH2 offset) Segments Data High for COM2 Line */
#define SLCD_SDATAH2_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH2 reset_value) Segments Data High for COM2 Line */

#define SLCD_SDATAH2_SDATA_Pos      0            /**< \brief (SLCD_SDATAH2) Segments Data */
#define SLCD_SDATAH2_SDATA_Msk      (_U_(0xFFF) << SLCD_SDATAH2_SDATA_Pos)
#define SLCD_SDATAH2_SDATA(value)   (SLCD_SDATAH2_SDATA_Msk & ((value) << SLCD_SDATAH2_SDATA_Pos))
#define SLCD_SDATAH2_MASK           _U_(0x00000FFF) /**< \brief (SLCD_SDATAH2) MASK Register */

/* -------- SLCD_SDATAL3 : (SLCD Offset: 0x3C) (R/W 32) Segments Data Low for COM3 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL3_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL3_OFFSET         0x3C         /**< \brief (SLCD_SDATAL3 offset) Segments Data Low for COM3 Line */
#define SLCD_SDATAL3_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL3 reset_value) Segments Data Low for COM3 Line */

#define SLCD_SDATAL3_SDATA_Pos      0            /**< \brief (SLCD_SDATAL3) Segments Data */
#define SLCD_SDATAL3_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL3_SDATA_Pos)
#define SLCD_SDATAL3_SDATA(value)   (SLCD_SDATAL3_SDATA_Msk & ((value) << SLCD_SDATAL3_SDATA_Pos))
#define SLCD_SDATAL3_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL3) MASK Register */

/* -------- SLCD_SDATAH3 : (SLCD Offset: 0x40) (R/W 32) Segments Data High for COM3 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:12;         /*!< bit:  0..11  Segments Data                      */
    uint32_t :20;              /*!< bit: 12..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH3_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH3_OFFSET         0x40         /**< \brief (SLCD_SDATAH3 offset) Segments Data High for COM3 Line */
#define SLCD_SDATAH3_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH3 reset_value) Segments Data High for COM3 Line */

#define SLCD_SDATAH3_SDATA_Pos      0            /**< \brief (SLCD_SDATAH3) Segments Data */
#define SLCD_SDATAH3_SDATA_Msk      (_U_(0xFFF) << SLCD_SDATAH3_SDATA_Pos)
#define SLCD_SDATAH3_SDATA(value)   (SLCD_SDATAH3_SDATA_Msk & ((value) << SLCD_SDATAH3_SDATA_Pos))
#define SLCD_SDATAH3_MASK           _U_(0x00000FFF) /**< \brief (SLCD_SDATAH3) MASK Register */

/* -------- SLCD_SDATAL4 : (SLCD Offset: 0x44) (R/W 32) Segments Data Low for COM4 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL4_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL4_OFFSET         0x44         /**< \brief (SLCD_SDATAL4 offset) Segments Data Low for COM4 Line */
#define SLCD_SDATAL4_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL4 reset_value) Segments Data Low for COM4 Line */

#define SLCD_SDATAL4_SDATA_Pos      0            /**< \brief (SLCD_SDATAL4) Segments Data */
#define SLCD_SDATAL4_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL4_SDATA_Pos)
#define SLCD_SDATAL4_SDATA(value)   (SLCD_SDATAL4_SDATA_Msk & ((value) << SLCD_SDATAL4_SDATA_Pos))
#define SLCD_SDATAL4_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL4) MASK Register */

/* -------- SLCD_SDATAH4 : (SLCD Offset: 0x48) (R/W 32) Segments Data High for COM4 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:10;         /*!< bit:  0.. 9  Segments Data                      */
    uint32_t :22;              /*!< bit: 10..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH4_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH4_OFFSET         0x48         /**< \brief (SLCD_SDATAH4 offset) Segments Data High for COM4 Line */
#define SLCD_SDATAH4_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH4 reset_value) Segments Data High for COM4 Line */

#define SLCD_SDATAH4_SDATA_Pos      0            /**< \brief (SLCD_SDATAH4) Segments Data */
#define SLCD_SDATAH4_SDATA_Msk      (_U_(0x3FF) << SLCD_SDATAH4_SDATA_Pos)
#define SLCD_SDATAH4_SDATA(value)   (SLCD_SDATAH4_SDATA_Msk & ((value) << SLCD_SDATAH4_SDATA_Pos))
#define SLCD_SDATAH4_MASK           _U_(0x000003FF) /**< \brief (SLCD_SDATAH4) MASK Register */

/* -------- SLCD_SDATAL5 : (SLCD Offset: 0x4C) (R/W 32) Segments Data Low for COM5 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL5_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL5_OFFSET         0x4C         /**< \brief (SLCD_SDATAL5 offset) Segments Data Low for COM5 Line */
#define SLCD_SDATAL5_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL5 reset_value) Segments Data Low for COM5 Line */

#define SLCD_SDATAL5_SDATA_Pos      0            /**< \brief (SLCD_SDATAL5) Segments Data */
#define SLCD_SDATAL5_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL5_SDATA_Pos)
#define SLCD_SDATAL5_SDATA(value)   (SLCD_SDATAL5_SDATA_Msk & ((value) << SLCD_SDATAL5_SDATA_Pos))
#define SLCD_SDATAL5_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL5) MASK Register */

/* -------- SLCD_SDATAH5 : (SLCD Offset: 0x50) (R/W 32) Segments Data High for COM5 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:10;         /*!< bit:  0.. 9  Segments Data                      */
    uint32_t :22;              /*!< bit: 10..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH5_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH5_OFFSET         0x50         /**< \brief (SLCD_SDATAH5 offset) Segments Data High for COM5 Line */
#define SLCD_SDATAH5_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH5 reset_value) Segments Data High for COM5 Line */

#define SLCD_SDATAH5_SDATA_Pos      0            /**< \brief (SLCD_SDATAH5) Segments Data */
#define SLCD_SDATAH5_SDATA_Msk      (_U_(0x3FF) << SLCD_SDATAH5_SDATA_Pos)
#define SLCD_SDATAH5_SDATA(value)   (SLCD_SDATAH5_SDATA_Msk & ((value) << SLCD_SDATAH5_SDATA_Pos))
#define SLCD_SDATAH5_MASK           _U_(0x000003FF) /**< \brief (SLCD_SDATAH5) MASK Register */

/* -------- SLCD_SDATAL6 : (SLCD Offset: 0x54) (R/W 32) Segments Data Low for COM6 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL6_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL6_OFFSET         0x54         /**< \brief (SLCD_SDATAL6 offset) Segments Data Low for COM6 Line */
#define SLCD_SDATAL6_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL6 reset_value) Segments Data Low for COM6 Line */

#define SLCD_SDATAL6_SDATA_Pos      0            /**< \brief (SLCD_SDATAL6) Segments Data */
#define SLCD_SDATAL6_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL6_SDATA_Pos)
#define SLCD_SDATAL6_SDATA(value)   (SLCD_SDATAL6_SDATA_Msk & ((value) << SLCD_SDATAL6_SDATA_Pos))
#define SLCD_SDATAL6_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL6) MASK Register */

/* -------- SLCD_SDATAH6 : (SLCD Offset: 0x58) (R/W 32) Segments Data High for COM6 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:8;          /*!< bit:  0.. 7  Segments Data                      */
    uint32_t :24;              /*!< bit:  8..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH6_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH6_OFFSET         0x58         /**< \brief (SLCD_SDATAH6 offset) Segments Data High for COM6 Line */
#define SLCD_SDATAH6_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH6 reset_value) Segments Data High for COM6 Line */

#define SLCD_SDATAH6_SDATA_Pos      0            /**< \brief (SLCD_SDATAH6) Segments Data */
#define SLCD_SDATAH6_SDATA_Msk      (_U_(0xFF) << SLCD_SDATAH6_SDATA_Pos)
#define SLCD_SDATAH6_SDATA(value)   (SLCD_SDATAH6_SDATA_Msk & ((value) << SLCD_SDATAH6_SDATA_Pos))
#define SLCD_SDATAH6_MASK           _U_(0x000000FF) /**< \brief (SLCD_SDATAH6) MASK Register */

/* -------- SLCD_SDATAL7 : (SLCD Offset: 0x5C) (R/W 32) Segments Data Low for COM7 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:32;         /*!< bit:  0..31  Segments Data                      */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAL7_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAL7_OFFSET         0x5C         /**< \brief (SLCD_SDATAL7 offset) Segments Data Low for COM7 Line */
#define SLCD_SDATAL7_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAL7 reset_value) Segments Data Low for COM7 Line */

#define SLCD_SDATAL7_SDATA_Pos      0            /**< \brief (SLCD_SDATAL7) Segments Data */
#define SLCD_SDATAL7_SDATA_Msk      (_U_(0xFFFFFFFF) << SLCD_SDATAL7_SDATA_Pos)
#define SLCD_SDATAL7_SDATA(value)   (SLCD_SDATAL7_SDATA_Msk & ((value) << SLCD_SDATAL7_SDATA_Pos))
#define SLCD_SDATAL7_MASK           _U_(0xFFFFFFFF) /**< \brief (SLCD_SDATAL7) MASK Register */

/* -------- SLCD_SDATAH7 : (SLCD Offset: 0x60) (R/W 32) Segments Data High for COM7 Line -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:8;          /*!< bit:  0.. 7  Segments Data                      */
    uint32_t :24;              /*!< bit:  8..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_SDATAH7_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_SDATAH7_OFFSET         0x60         /**< \brief (SLCD_SDATAH7 offset) Segments Data High for COM7 Line */
#define SLCD_SDATAH7_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_SDATAH7 reset_value) Segments Data High for COM7 Line */

#define SLCD_SDATAH7_SDATA_Pos      0            /**< \brief (SLCD_SDATAH7) Segments Data */
#define SLCD_SDATAH7_SDATA_Msk      (_U_(0xFF) << SLCD_SDATAH7_SDATA_Pos)
#define SLCD_SDATAH7_SDATA(value)   (SLCD_SDATAH7_SDATA_Msk & ((value) << SLCD_SDATAH7_SDATA_Pos))
#define SLCD_SDATAH7_MASK           _U_(0x000000FF) /**< \brief (SLCD_SDATAH7) MASK Register */

/* -------- SLCD_ISDATA : (SLCD Offset: 0x64) ( /W 32) Indirect Segments Data Access -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:8;          /*!< bit:  0.. 7  Segments Data                      */
    uint32_t SDMASK:8;         /*!< bit:  8..15  Segments Data Mask                 */
    uint32_t OFF:6;            /*!< bit: 16..21  Byte Offset                        */
    uint32_t :10;              /*!< bit: 22..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_ISDATA_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_ISDATA_OFFSET          0x64         /**< \brief (SLCD_ISDATA offset) Indirect Segments Data Access */
#define SLCD_ISDATA_RESETVALUE      _U_(0x00000000) /**< \brief (SLCD_ISDATA reset_value) Indirect Segments Data Access */

#define SLCD_ISDATA_SDATA_Pos       0            /**< \brief (SLCD_ISDATA) Segments Data */
#define SLCD_ISDATA_SDATA_Msk       (_U_(0xFF) << SLCD_ISDATA_SDATA_Pos)
#define SLCD_ISDATA_SDATA(value)    (SLCD_ISDATA_SDATA_Msk & ((value) << SLCD_ISDATA_SDATA_Pos))
#define SLCD_ISDATA_SDMASK_Pos      8            /**< \brief (SLCD_ISDATA) Segments Data Mask */
#define SLCD_ISDATA_SDMASK_Msk      (_U_(0xFF) << SLCD_ISDATA_SDMASK_Pos)
#define SLCD_ISDATA_SDMASK(value)   (SLCD_ISDATA_SDMASK_Msk & ((value) << SLCD_ISDATA_SDMASK_Pos))
#define SLCD_ISDATA_OFF_Pos         16           /**< \brief (SLCD_ISDATA) Byte Offset */
#define SLCD_ISDATA_OFF_Msk         (_U_(0x3F) << SLCD_ISDATA_OFF_Pos)
#define SLCD_ISDATA_OFF(value)      (SLCD_ISDATA_OFF_Msk & ((value) << SLCD_ISDATA_OFF_Pos))
#define SLCD_ISDATA_MASK            _U_(0x003FFFFF) /**< \brief (SLCD_ISDATA) MASK Register */

/* -------- SLCD_BCFG : (SLCD Offset: 0x68) (R/W 32) Blink Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t MODE:1;           /*!< bit:      0  Blinking Mode                      */
    uint32_t FCS:2;            /*!< bit:  1.. 2  Frame Counter Selection            */
    uint32_t :5;               /*!< bit:  3.. 7  Reserved                           */
    uint32_t BSS0:8;           /*!< bit:  8..15  Blink Segment Selection 0          */
    uint32_t BSS1:8;           /*!< bit: 16..23  Blink Segment Selection 1          */
    uint32_t :8;               /*!< bit: 24..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_BCFG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_BCFG_OFFSET            0x68         /**< \brief (SLCD_BCFG offset) Blink Configuration */
#define SLCD_BCFG_RESETVALUE        _U_(0x00000000) /**< \brief (SLCD_BCFG reset_value) Blink Configuration */

#define SLCD_BCFG_MODE_Pos          0            /**< \brief (SLCD_BCFG) Blinking Mode */
#define SLCD_BCFG_MODE              (_U_(0x1) << SLCD_BCFG_MODE_Pos)
#define   SLCD_BCFG_MODE_BLINKALL_Val     _U_(0x0)   /**< \brief (SLCD_BCFG) Blink all segments */
#define   SLCD_BCFG_MODE_BLINKSEL_Val     _U_(0x1)   /**< \brief (SLCD_BCFG) Blink selected segments */
#define SLCD_BCFG_MODE_BLINKALL     (SLCD_BCFG_MODE_BLINKALL_Val   << SLCD_BCFG_MODE_Pos)
#define SLCD_BCFG_MODE_BLINKSEL     (SLCD_BCFG_MODE_BLINKSEL_Val   << SLCD_BCFG_MODE_Pos)
#define SLCD_BCFG_FCS_Pos           1            /**< \brief (SLCD_BCFG) Frame Counter Selection */
#define SLCD_BCFG_FCS_Msk           (_U_(0x3) << SLCD_BCFG_FCS_Pos)
#define SLCD_BCFG_FCS(value)        (SLCD_BCFG_FCS_Msk & ((value) << SLCD_BCFG_FCS_Pos))
#define   SLCD_BCFG_FCS_FC0_Val           _U_(0x0)   /**< \brief (SLCD_BCFG) Frame Counter 0 */
#define   SLCD_BCFG_FCS_FC1_Val           _U_(0x1)   /**< \brief (SLCD_BCFG) Frame Counter 1 */
#define   SLCD_BCFG_FCS_FC2_Val           _U_(0x2)   /**< \brief (SLCD_BCFG) Frame Counter 2 */
#define SLCD_BCFG_FCS_FC0           (SLCD_BCFG_FCS_FC0_Val         << SLCD_BCFG_FCS_Pos)
#define SLCD_BCFG_FCS_FC1           (SLCD_BCFG_FCS_FC1_Val         << SLCD_BCFG_FCS_Pos)
#define SLCD_BCFG_FCS_FC2           (SLCD_BCFG_FCS_FC2_Val         << SLCD_BCFG_FCS_Pos)
#define SLCD_BCFG_BSS0_Pos          8            /**< \brief (SLCD_BCFG) Blink Segment Selection 0 */
#define SLCD_BCFG_BSS0_Msk          (_U_(0xFF) << SLCD_BCFG_BSS0_Pos)
#define SLCD_BCFG_BSS0(value)       (SLCD_BCFG_BSS0_Msk & ((value) << SLCD_BCFG_BSS0_Pos))
#define SLCD_BCFG_BSS1_Pos          16           /**< \brief (SLCD_BCFG) Blink Segment Selection 1 */
#define SLCD_BCFG_BSS1_Msk          (_U_(0xFF) << SLCD_BCFG_BSS1_Pos)
#define SLCD_BCFG_BSS1(value)       (SLCD_BCFG_BSS1_Msk & ((value) << SLCD_BCFG_BSS1_Pos))
#define SLCD_BCFG_MASK              _U_(0x00FFFF07) /**< \brief (SLCD_BCFG) MASK Register */

/* -------- SLCD_CSRCFG : (SLCD Offset: 0x6C) (R/W 32) Circular Shift Register Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t DIR:1;            /*!< bit:      0  Direction                          */
    uint32_t FCS:2;            /*!< bit:  1.. 2  Frame Counter Selection            */
    uint32_t :1;               /*!< bit:      3  Reserved                           */
    uint32_t SIZE:4;           /*!< bit:  4.. 7  Circular Shift Register Size       */
    uint32_t DATA:16;          /*!< bit:  8..23  Circular Shift Register Value      */
    uint32_t :8;               /*!< bit: 24..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_CSRCFG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CSRCFG_OFFSET          0x6C         /**< \brief (SLCD_CSRCFG offset) Circular Shift Register Configuration */
#define SLCD_CSRCFG_RESETVALUE      _U_(0x00000000) /**< \brief (SLCD_CSRCFG reset_value) Circular Shift Register Configuration */

#define SLCD_CSRCFG_DIR_Pos         0            /**< \brief (SLCD_CSRCFG) Direction */
#define SLCD_CSRCFG_DIR             (_U_(0x1) << SLCD_CSRCFG_DIR_Pos)
#define SLCD_CSRCFG_FCS_Pos         1            /**< \brief (SLCD_CSRCFG) Frame Counter Selection */
#define SLCD_CSRCFG_FCS_Msk         (_U_(0x3) << SLCD_CSRCFG_FCS_Pos)
#define SLCD_CSRCFG_FCS(value)      (SLCD_CSRCFG_FCS_Msk & ((value) << SLCD_CSRCFG_FCS_Pos))
#define   SLCD_CSRCFG_FCS_FC0_Val         _U_(0x0)   /**< \brief (SLCD_CSRCFG) Frame Counter 0 */
#define   SLCD_CSRCFG_FCS_FC1_Val         _U_(0x1)   /**< \brief (SLCD_CSRCFG) Frame Counter 1 */
#define   SLCD_CSRCFG_FCS_FC2_Val         _U_(0x2)   /**< \brief (SLCD_CSRCFG) Frame Counter 2 */
#define SLCD_CSRCFG_FCS_FC0         (SLCD_CSRCFG_FCS_FC0_Val       << SLCD_CSRCFG_FCS_Pos)
#define SLCD_CSRCFG_FCS_FC1         (SLCD_CSRCFG_FCS_FC1_Val       << SLCD_CSRCFG_FCS_Pos)
#define SLCD_CSRCFG_FCS_FC2         (SLCD_CSRCFG_FCS_FC2_Val       << SLCD_CSRCFG_FCS_Pos)
#define SLCD_CSRCFG_SIZE_Pos        4            /**< \brief (SLCD_CSRCFG) Circular Shift Register Size */
#define SLCD_CSRCFG_SIZE_Msk        (_U_(0xF) << SLCD_CSRCFG_SIZE_Pos)
#define SLCD_CSRCFG_SIZE(value)     (SLCD_CSRCFG_SIZE_Msk & ((value) << SLCD_CSRCFG_SIZE_Pos))
#define SLCD_CSRCFG_DATA_Pos        8            /**< \brief (SLCD_CSRCFG) Circular Shift Register Value */
#define SLCD_CSRCFG_DATA_Msk        (_U_(0xFFFF) << SLCD_CSRCFG_DATA_Pos)
#define SLCD_CSRCFG_DATA(value)     (SLCD_CSRCFG_DATA_Msk & ((value) << SLCD_CSRCFG_DATA_Pos))
#define SLCD_CSRCFG_MASK            _U_(0x00FFFFF7) /**< \brief (SLCD_CSRCFG) MASK Register */

/* -------- SLCD_CMCFG : (SLCD Offset: 0x70) (R/W  8) Character Mapping Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  NSEG:3;           /*!< bit:  0.. 2  Number of SEG lines                */
    uint8_t  DEC:1;            /*!< bit:      3  Decrement SEG Line Index           */
    uint8_t  :4;               /*!< bit:  4.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_CMCFG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CMCFG_OFFSET           0x70         /**< \brief (SLCD_CMCFG offset) Character Mapping Configuration */
#define SLCD_CMCFG_RESETVALUE       _U_(0x00)    /**< \brief (SLCD_CMCFG reset_value) Character Mapping Configuration */

#define SLCD_CMCFG_NSEG_Pos         0            /**< \brief (SLCD_CMCFG) Number of SEG lines */
#define SLCD_CMCFG_NSEG_Msk         (_U_(0x7) << SLCD_CMCFG_NSEG_Pos)
#define SLCD_CMCFG_NSEG(value)      (SLCD_CMCFG_NSEG_Msk & ((value) << SLCD_CMCFG_NSEG_Pos))
#define SLCD_CMCFG_DEC_Pos          3            /**< \brief (SLCD_CMCFG) Decrement SEG Line Index */
#define SLCD_CMCFG_DEC              (_U_(0x1) << SLCD_CMCFG_DEC_Pos)
#define SLCD_CMCFG_MASK             _U_(0x0F)    /**< \brief (SLCD_CMCFG) MASK Register */

/* -------- SLCD_ACMCFG : (SLCD Offset: 0x74) (R/W 32) Automated Character Mapping Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t NCOM:3;           /*!< bit:  0.. 2  COM Lines per Row                  */
    uint32_t :1;               /*!< bit:      3  Reserved                           */
    uint32_t NDIG:4;           /*!< bit:  4.. 7  Number of Digit                    */
    uint32_t STEPS:8;          /*!< bit:  8..15  Scrolling Steps                    */
    uint32_t NDROW:6;          /*!< bit: 16..21  Number of Digit per Row            */
    uint32_t :1;               /*!< bit:     22  Reserved                           */
    uint32_t MODE:1;           /*!< bit:     23  Mode                               */
    uint32_t STSEG:6;          /*!< bit: 24..29  Start SEG Line                     */
    uint32_t FCS:2;            /*!< bit: 30..31  Frame Counter Selection            */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_ACMCFG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_ACMCFG_OFFSET          0x74         /**< \brief (SLCD_ACMCFG offset) Automated Character Mapping Configuration */
#define SLCD_ACMCFG_RESETVALUE      _U_(0x00000000) /**< \brief (SLCD_ACMCFG reset_value) Automated Character Mapping Configuration */

#define SLCD_ACMCFG_NCOM_Pos        0            /**< \brief (SLCD_ACMCFG) COM Lines per Row */
#define SLCD_ACMCFG_NCOM_Msk        (_U_(0x7) << SLCD_ACMCFG_NCOM_Pos)
#define SLCD_ACMCFG_NCOM(value)     (SLCD_ACMCFG_NCOM_Msk & ((value) << SLCD_ACMCFG_NCOM_Pos))
#define SLCD_ACMCFG_NDIG_Pos        4            /**< \brief (SLCD_ACMCFG) Number of Digit */
#define SLCD_ACMCFG_NDIG_Msk        (_U_(0xF) << SLCD_ACMCFG_NDIG_Pos)
#define SLCD_ACMCFG_NDIG(value)     (SLCD_ACMCFG_NDIG_Msk & ((value) << SLCD_ACMCFG_NDIG_Pos))
#define SLCD_ACMCFG_STEPS_Pos       8            /**< \brief (SLCD_ACMCFG) Scrolling Steps */
#define SLCD_ACMCFG_STEPS_Msk       (_U_(0xFF) << SLCD_ACMCFG_STEPS_Pos)
#define SLCD_ACMCFG_STEPS(value)    (SLCD_ACMCFG_STEPS_Msk & ((value) << SLCD_ACMCFG_STEPS_Pos))
#define SLCD_ACMCFG_NDROW_Pos       16           /**< \brief (SLCD_ACMCFG) Number of Digit per Row */
#define SLCD_ACMCFG_NDROW_Msk       (_U_(0x3F) << SLCD_ACMCFG_NDROW_Pos)
#define SLCD_ACMCFG_NDROW(value)    (SLCD_ACMCFG_NDROW_Msk & ((value) << SLCD_ACMCFG_NDROW_Pos))
#define SLCD_ACMCFG_MODE_Pos        23           /**< \brief (SLCD_ACMCFG) Mode */
#define SLCD_ACMCFG_MODE            (_U_(0x1) << SLCD_ACMCFG_MODE_Pos)
#define   SLCD_ACMCFG_MODE_SEQ_Val        _U_(0x0)   /**< \brief (SLCD_ACMCFG) Sequential Display Mode */
#define   SLCD_ACMCFG_MODE_SCROLL_Val     _U_(0x1)   /**< \brief (SLCD_ACMCFG) Scrolling Display Mode */
#define SLCD_ACMCFG_MODE_SEQ        (SLCD_ACMCFG_MODE_SEQ_Val      << SLCD_ACMCFG_MODE_Pos)
#define SLCD_ACMCFG_MODE_SCROLL     (SLCD_ACMCFG_MODE_SCROLL_Val   << SLCD_ACMCFG_MODE_Pos)
#define SLCD_ACMCFG_STSEG_Pos       24           /**< \brief (SLCD_ACMCFG) Start SEG Line */
#define SLCD_ACMCFG_STSEG_Msk       (_U_(0x3F) << SLCD_ACMCFG_STSEG_Pos)
#define SLCD_ACMCFG_STSEG(value)    (SLCD_ACMCFG_STSEG_Msk & ((value) << SLCD_ACMCFG_STSEG_Pos))
#define SLCD_ACMCFG_FCS_Pos         30           /**< \brief (SLCD_ACMCFG) Frame Counter Selection */
#define SLCD_ACMCFG_FCS_Msk         (_U_(0x3) << SLCD_ACMCFG_FCS_Pos)
#define SLCD_ACMCFG_FCS(value)      (SLCD_ACMCFG_FCS_Msk & ((value) << SLCD_ACMCFG_FCS_Pos))
#define   SLCD_ACMCFG_FCS_FC0_Val         _U_(0x0)   /**< \brief (SLCD_ACMCFG) Frame Counter 0 */
#define   SLCD_ACMCFG_FCS_FC1_Val         _U_(0x1)   /**< \brief (SLCD_ACMCFG) Frame Counter 1 */
#define   SLCD_ACMCFG_FCS_FC2_Val         _U_(0x2)   /**< \brief (SLCD_ACMCFG) Frame Counter 2 */
#define SLCD_ACMCFG_FCS_FC0         (SLCD_ACMCFG_FCS_FC0_Val       << SLCD_ACMCFG_FCS_Pos)
#define SLCD_ACMCFG_FCS_FC1         (SLCD_ACMCFG_FCS_FC1_Val       << SLCD_ACMCFG_FCS_Pos)
#define SLCD_ACMCFG_FCS_FC2         (SLCD_ACMCFG_FCS_FC2_Val       << SLCD_ACMCFG_FCS_Pos)
#define SLCD_ACMCFG_MASK            _U_(0xFFBFFFF7) /**< \brief (SLCD_ACMCFG) MASK Register */

/* -------- SLCD_ABMCFG : (SLCD Offset: 0x78) (R/W  8) Automated Bit Mapping Configuration -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  FCS:2;            /*!< bit:  0.. 1  Frame Counter Selection            */
    uint8_t  SIZE:6;           /*!< bit:  2.. 7  Size                               */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} SLCD_ABMCFG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_ABMCFG_OFFSET          0x78         /**< \brief (SLCD_ABMCFG offset) Automated Bit Mapping Configuration */
#define SLCD_ABMCFG_RESETVALUE      _U_(0x00)    /**< \brief (SLCD_ABMCFG reset_value) Automated Bit Mapping Configuration */

#define SLCD_ABMCFG_FCS_Pos         0            /**< \brief (SLCD_ABMCFG) Frame Counter Selection */
#define SLCD_ABMCFG_FCS_Msk         (_U_(0x3) << SLCD_ABMCFG_FCS_Pos)
#define SLCD_ABMCFG_FCS(value)      (SLCD_ABMCFG_FCS_Msk & ((value) << SLCD_ABMCFG_FCS_Pos))
#define   SLCD_ABMCFG_FCS_FC0_Val         _U_(0x0)   /**< \brief (SLCD_ABMCFG) Frame Counter 0 */
#define   SLCD_ABMCFG_FCS_FC1_Val         _U_(0x1)   /**< \brief (SLCD_ABMCFG) Frame Counter 1 */
#define   SLCD_ABMCFG_FCS_FC2_Val         _U_(0x2)   /**< \brief (SLCD_ABMCFG) Frame Counter 2 */
#define SLCD_ABMCFG_FCS_FC0         (SLCD_ABMCFG_FCS_FC0_Val       << SLCD_ABMCFG_FCS_Pos)
#define SLCD_ABMCFG_FCS_FC1         (SLCD_ABMCFG_FCS_FC1_Val       << SLCD_ABMCFG_FCS_Pos)
#define SLCD_ABMCFG_FCS_FC2         (SLCD_ABMCFG_FCS_FC2_Val       << SLCD_ABMCFG_FCS_Pos)
#define SLCD_ABMCFG_SIZE_Pos        2            /**< \brief (SLCD_ABMCFG) Size */
#define SLCD_ABMCFG_SIZE_Msk        (_U_(0x3F) << SLCD_ABMCFG_SIZE_Pos)
#define SLCD_ABMCFG_SIZE(value)     (SLCD_ABMCFG_SIZE_Msk & ((value) << SLCD_ABMCFG_SIZE_Pos))
#define SLCD_ABMCFG_MASK            _U_(0xFF)    /**< \brief (SLCD_ABMCFG) MASK Register */

/* -------- SLCD_CMDATA : (SLCD Offset: 0x7C) ( /W 32) Character Mapping Segments Data -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDATA:24;         /*!< bit:  0..23  Segments Data                      */
    uint32_t :8;               /*!< bit: 24..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_CMDATA_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CMDATA_OFFSET          0x7C         /**< \brief (SLCD_CMDATA offset) Character Mapping Segments Data */
#define SLCD_CMDATA_RESETVALUE      _U_(0x00000000) /**< \brief (SLCD_CMDATA reset_value) Character Mapping Segments Data */

#define SLCD_CMDATA_SDATA_Pos       0            /**< \brief (SLCD_CMDATA) Segments Data */
#define SLCD_CMDATA_SDATA_Msk       (_U_(0xFFFFFF) << SLCD_CMDATA_SDATA_Pos)
#define SLCD_CMDATA_SDATA(value)    (SLCD_CMDATA_SDATA_Msk & ((value) << SLCD_CMDATA_SDATA_Pos))
#define SLCD_CMDATA_MASK            _U_(0x00FFFFFF) /**< \brief (SLCD_CMDATA) MASK Register */

/* -------- SLCD_CMDMASK : (SLCD Offset: 0x80) (R/W 32) Character Mapping Segments Data Mask -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t SDMASK:24;        /*!< bit:  0..23  Segments Data Mask                 */
    uint32_t :8;               /*!< bit: 24..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} SLCD_CMDMASK_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CMDMASK_OFFSET         0x80         /**< \brief (SLCD_CMDMASK offset) Character Mapping Segments Data Mask */
#define SLCD_CMDMASK_RESETVALUE     _U_(0x00000000) /**< \brief (SLCD_CMDMASK reset_value) Character Mapping Segments Data Mask */

#define SLCD_CMDMASK_SDMASK_Pos     0            /**< \brief (SLCD_CMDMASK) Segments Data Mask */
#define SLCD_CMDMASK_SDMASK_Msk     (_U_(0xFFFFFF) << SLCD_CMDMASK_SDMASK_Pos)
#define SLCD_CMDMASK_SDMASK(value)  (SLCD_CMDMASK_SDMASK_Msk & ((value) << SLCD_CMDMASK_SDMASK_Pos))
#define SLCD_CMDMASK_MASK           _U_(0x00FFFFFF) /**< \brief (SLCD_CMDMASK) MASK Register */

/* -------- SLCD_CMINDEX : (SLCD Offset: 0x84) (R/W 16) Character Mapping SEG/COM Index -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint16_t SINDEX:6;         /*!< bit:  0.. 5  SEG Line Index                     */
    uint16_t :2;               /*!< bit:  6.. 7  Reserved                           */
    uint16_t CINDEX:3;         /*!< bit:  8..10  COM Line Index                     */
    uint16_t :5;               /*!< bit: 11..15  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint16_t reg;                /*!< Type      used for register access              */
} SLCD_CMINDEX_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SLCD_CMINDEX_OFFSET         0x84         /**< \brief (SLCD_CMINDEX offset) Character Mapping SEG/COM Index */
#define SLCD_CMINDEX_RESETVALUE     _U_(0x0000)  /**< \brief (SLCD_CMINDEX reset_value) Character Mapping SEG/COM Index */

#define SLCD_CMINDEX_SINDEX_Pos     0            /**< \brief (SLCD_CMINDEX) SEG Line Index */
#define SLCD_CMINDEX_SINDEX_Msk     (_U_(0x3F) << SLCD_CMINDEX_SINDEX_Pos)
#define SLCD_CMINDEX_SINDEX(value)  (SLCD_CMINDEX_SINDEX_Msk & ((value) << SLCD_CMINDEX_SINDEX_Pos))
#define SLCD_CMINDEX_CINDEX_Pos     8            /**< \brief (SLCD_CMINDEX) COM Line Index */
#define SLCD_CMINDEX_CINDEX_Msk     (_U_(0x7) << SLCD_CMINDEX_CINDEX_Pos)
#define SLCD_CMINDEX_CINDEX(value)  (SLCD_CMINDEX_CINDEX_Msk & ((value) << SLCD_CMINDEX_CINDEX_Pos))
#define SLCD_CMINDEX_MASK           _U_(0x073F)  /**< \brief (SLCD_CMINDEX) MASK Register */

/** \brief SLCD hardware registers */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct {
  __IO SLCD_CTRLA_Type           CTRLA;       /**< \brief Offset: 0x00 (R/W 32) Control A */
  __IO SLCD_CTRLB_Type           CTRLB;       /**< \brief Offset: 0x04 (R/W 16) Control B */
  __IO SLCD_CTRLC_Type           CTRLC;       /**< \brief Offset: 0x06 (R/W 16) Control C */
  __IO SLCD_CTRLD_Type           CTRLD;       /**< \brief Offset: 0x08 (R/W  8) Control D */
       RoReg8                    Reserved1[0x3];
  __IO SLCD_EVCTRL_Type          EVCTRL;      /**< \brief Offset: 0x0C (R/W  8) Event Control */
  __IO SLCD_INTENCLR_Type        INTENCLR;    /**< \brief Offset: 0x0D (R/W  8) Interrupt Enable Clear */
  __IO SLCD_INTENSET_Type        INTENSET;    /**< \brief Offset: 0x0E (R/W  8) Interrupt Enable Set */
  __IO SLCD_INTFLAG_Type         INTFLAG;     /**< \brief Offset: 0x0F (R/W  8) Interrupt Flag Status and Clear */
  __I  SLCD_STATUS_Type          STATUS;      /**< \brief Offset: 0x10 (R/   8) Status */
       RoReg8                    Reserved2[0x3];
  __I  SLCD_SYNCBUSY_Type        SYNCBUSY;    /**< \brief Offset: 0x14 (R/  32) Synchronization Busy */
  __IO SLCD_FC0_Type             FC0;         /**< \brief Offset: 0x18 (R/W  8) Frame Counter 0 Configuration */
  __IO SLCD_FC1_Type             FC1;         /**< \brief Offset: 0x19 (R/W  8) Frame Counter 1 Configuration */
  __IO SLCD_FC2_Type             FC2;         /**< \brief Offset: 0x1A (R/W  8) Frame Counter 2 Configuration */
       RoReg8                    Reserved3[0x1];
  __IO SLCD_LPENL_Type           LPENL;       /**< \brief Offset: 0x1C (R/W 32) LCD Pin Enable Low */
  __IO SLCD_LPENH_Type           LPENH;       /**< \brief Offset: 0x20 (R/W 32) LCD Pin Enable High */
  __IO SLCD_SDATAL0_Type         SDATAL0;     /**< \brief Offset: 0x24 (R/W 32) Segments Data Low for COM0 Line */
  __IO SLCD_SDATAH0_Type         SDATAH0;     /**< \brief Offset: 0x28 (R/W 32) Segments Data High for COM0 Line */
  __IO SLCD_SDATAL1_Type         SDATAL1;     /**< \brief Offset: 0x2C (R/W 32) Segments Data Low for COM1 Line */
  __IO SLCD_SDATAH1_Type         SDATAH1;     /**< \brief Offset: 0x30 (R/W 32) Segments Data High for COM1 Line */
  __IO SLCD_SDATAL2_Type         SDATAL2;     /**< \brief Offset: 0x34 (R/W 32) Segments Data Low for COM2 Line */
  __IO SLCD_SDATAH2_Type         SDATAH2;     /**< \brief Offset: 0x38 (R/W 32) Segments Data High for COM2 Line */
  __IO SLCD_SDATAL3_Type         SDATAL3;     /**< \brief Offset: 0x3C (R/W 32) Segments Data Low for COM3 Line */
  __IO SLCD_SDATAH3_Type         SDATAH3;     /**< \brief Offset: 0x40 (R/W 32) Segments Data High for COM3 Line */
  __IO SLCD_SDATAL4_Type         SDATAL4;     /**< \brief Offset: 0x44 (R/W 32) Segments Data Low for COM4 Line */
  __IO SLCD_SDATAH4_Type         SDATAH4;     /**< \brief Offset: 0x48 (R/W 32) Segments Data High for COM4 Line */
  __IO SLCD_SDATAL5_Type         SDATAL5;     /**< \brief Offset: 0x4C (R/W 32) Segments Data Low for COM5 Line */
  __IO SLCD_SDATAH5_Type         SDATAH5;     /**< \brief Offset: 0x50 (R/W 32) Segments Data High for COM5 Line */
  __IO SLCD_SDATAL6_Type         SDATAL6;     /**< \brief Offset: 0x54 (R/W 32) Segments Data Low for COM6 Line */
  __IO SLCD_SDATAH6_Type         SDATAH6;     /**< \brief Offset: 0x58 (R/W 32) Segments Data High for COM6 Line */
  __IO SLCD_SDATAL7_Type         SDATAL7;     /**< \brief Offset: 0x5C (R/W 32) Segments Data Low for COM7 Line */
  __IO SLCD_SDATAH7_Type         SDATAH7;     /**< \brief Offset: 0x60 (R/W 32) Segments Data High for COM7 Line */
  __O  SLCD_ISDATA_Type          ISDATA;      /**< \brief Offset: 0x64 ( /W 32) Indirect Segments Data Access */
  __IO SLCD_BCFG_Type            BCFG;        /**< \brief Offset: 0x68 (R/W 32) Blink Configuration */
  __IO SLCD_CSRCFG_Type          CSRCFG;      /**< \brief Offset: 0x6C (R/W 32) Circular Shift Register Configuration */
  __IO SLCD_CMCFG_Type           CMCFG;       /**< \brief Offset: 0x70 (R/W  8) Character Mapping Configuration */
       RoReg8                    Reserved4[0x3];
  __IO SLCD_ACMCFG_Type          ACMCFG;      /**< \brief Offset: 0x74 (R/W 32) Automated Character Mapping Configuration */
  __IO SLCD_ABMCFG_Type          ABMCFG;      /**< \brief Offset: 0x78 (R/W  8) Automated Bit Mapping Configuration */
       RoReg8                    Reserved5[0x3];
  __O  SLCD_CMDATA_Type          CMDATA;      /**< \brief Offset: 0x7C ( /W 32) Character Mapping Segments Data */
  __IO SLCD_CMDMASK_Type         CMDMASK;     /**< \brief Offset: 0x80 (R/W 32) Character Mapping Segments Data Mask */
  __IO SLCD_CMINDEX_Type         CMINDEX;     /**< \brief Offset: 0x84 (R/W 16) Character Mapping SEG/COM Index */
} Slcd;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/*@}*/

#endif /* _SAML22_SLCD_COMPONENT_ */
