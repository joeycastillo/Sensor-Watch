/**
 * \file
 *
 * \brief Component description for MCLK
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

#ifndef _SAML22_MCLK_COMPONENT_
#define _SAML22_MCLK_COMPONENT_

/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR MCLK */
/* ========================================================================== */
/** \addtogroup SAML22_MCLK Main Clock */
/*@{*/

#define MCLK_U2234
#define REV_MCLK                    0x210

/* -------- MCLK_INTENCLR : (MCLK Offset: 0x01) (R/W  8) Interrupt Enable Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  CKRDY:1;          /*!< bit:      0  Clock Ready Interrupt Enable       */
    uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} MCLK_INTENCLR_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_INTENCLR_OFFSET        0x01         /**< \brief (MCLK_INTENCLR offset) Interrupt Enable Clear */
#define MCLK_INTENCLR_RESETVALUE    _U_(0x00)    /**< \brief (MCLK_INTENCLR reset_value) Interrupt Enable Clear */

#define MCLK_INTENCLR_CKRDY_Pos     0            /**< \brief (MCLK_INTENCLR) Clock Ready Interrupt Enable */
#define MCLK_INTENCLR_CKRDY         (_U_(0x1) << MCLK_INTENCLR_CKRDY_Pos)
#define MCLK_INTENCLR_MASK          _U_(0x01)    /**< \brief (MCLK_INTENCLR) MASK Register */

/* -------- MCLK_INTENSET : (MCLK Offset: 0x02) (R/W  8) Interrupt Enable Set -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  CKRDY:1;          /*!< bit:      0  Clock Ready Interrupt Enable       */
    uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} MCLK_INTENSET_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_INTENSET_OFFSET        0x02         /**< \brief (MCLK_INTENSET offset) Interrupt Enable Set */
#define MCLK_INTENSET_RESETVALUE    _U_(0x00)    /**< \brief (MCLK_INTENSET reset_value) Interrupt Enable Set */

#define MCLK_INTENSET_CKRDY_Pos     0            /**< \brief (MCLK_INTENSET) Clock Ready Interrupt Enable */
#define MCLK_INTENSET_CKRDY         (_U_(0x1) << MCLK_INTENSET_CKRDY_Pos)
#define MCLK_INTENSET_MASK          _U_(0x01)    /**< \brief (MCLK_INTENSET) MASK Register */

/* -------- MCLK_INTFLAG : (MCLK Offset: 0x03) (R/W  8) Interrupt Flag Status and Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { // __I to avoid read-modify-write on write-to-clear register
  struct {
    __I uint8_t  CKRDY:1;          /*!< bit:      0  Clock Ready                        */
    __I uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} MCLK_INTFLAG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_INTFLAG_OFFSET         0x03         /**< \brief (MCLK_INTFLAG offset) Interrupt Flag Status and Clear */
#define MCLK_INTFLAG_RESETVALUE     _U_(0x01)    /**< \brief (MCLK_INTFLAG reset_value) Interrupt Flag Status and Clear */

#define MCLK_INTFLAG_CKRDY_Pos      0            /**< \brief (MCLK_INTFLAG) Clock Ready */
#define MCLK_INTFLAG_CKRDY          (_U_(0x1) << MCLK_INTFLAG_CKRDY_Pos)
#define MCLK_INTFLAG_MASK           _U_(0x01)    /**< \brief (MCLK_INTFLAG) MASK Register */

/* -------- MCLK_CPUDIV : (MCLK Offset: 0x04) (R/W  8) CPU Clock Division -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  CPUDIV:8;         /*!< bit:  0.. 7  CPU Clock Division Factor          */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} MCLK_CPUDIV_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_CPUDIV_OFFSET          0x04         /**< \brief (MCLK_CPUDIV offset) CPU Clock Division */
#define MCLK_CPUDIV_RESETVALUE      _U_(0x01)    /**< \brief (MCLK_CPUDIV reset_value) CPU Clock Division */

#define MCLK_CPUDIV_CPUDIV_Pos      0            /**< \brief (MCLK_CPUDIV) CPU Clock Division Factor */
#define MCLK_CPUDIV_CPUDIV_Msk      (_U_(0xFF) << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV(value)   (MCLK_CPUDIV_CPUDIV_Msk & ((value) << MCLK_CPUDIV_CPUDIV_Pos))
#define   MCLK_CPUDIV_CPUDIV_DIV1_Val     _U_(0x1)   /**< \brief (MCLK_CPUDIV) Divide by 1 */
#define   MCLK_CPUDIV_CPUDIV_DIV2_Val     _U_(0x2)   /**< \brief (MCLK_CPUDIV) Divide by 2 */
#define   MCLK_CPUDIV_CPUDIV_DIV4_Val     _U_(0x4)   /**< \brief (MCLK_CPUDIV) Divide by 4 */
#define   MCLK_CPUDIV_CPUDIV_DIV8_Val     _U_(0x8)   /**< \brief (MCLK_CPUDIV) Divide by 8 */
#define   MCLK_CPUDIV_CPUDIV_DIV16_Val    _U_(0x10)   /**< \brief (MCLK_CPUDIV) Divide by 16 */
#define   MCLK_CPUDIV_CPUDIV_DIV32_Val    _U_(0x20)   /**< \brief (MCLK_CPUDIV) Divide by 32 */
#define   MCLK_CPUDIV_CPUDIV_DIV64_Val    _U_(0x40)   /**< \brief (MCLK_CPUDIV) Divide by 64 */
#define   MCLK_CPUDIV_CPUDIV_DIV128_Val   _U_(0x80)   /**< \brief (MCLK_CPUDIV) Divide by 128 */
#define MCLK_CPUDIV_CPUDIV_DIV1     (MCLK_CPUDIV_CPUDIV_DIV1_Val   << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV2     (MCLK_CPUDIV_CPUDIV_DIV2_Val   << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV4     (MCLK_CPUDIV_CPUDIV_DIV4_Val   << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV8     (MCLK_CPUDIV_CPUDIV_DIV8_Val   << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV16    (MCLK_CPUDIV_CPUDIV_DIV16_Val  << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV32    (MCLK_CPUDIV_CPUDIV_DIV32_Val  << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV64    (MCLK_CPUDIV_CPUDIV_DIV64_Val  << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_CPUDIV_DIV128   (MCLK_CPUDIV_CPUDIV_DIV128_Val << MCLK_CPUDIV_CPUDIV_Pos)
#define MCLK_CPUDIV_MASK            _U_(0xFF)    /**< \brief (MCLK_CPUDIV) MASK Register */

/* -------- MCLK_BUPDIV : (MCLK Offset: 0x06) (R/W  8) Backup Clock Division -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint8_t  BUPDIV:8;         /*!< bit:  0.. 7  Backup Clock Division Factor       */
  } bit;                       /*!< Structure used for bit  access                  */
  uint8_t reg;                 /*!< Type      used for register access              */
} MCLK_BUPDIV_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_BUPDIV_OFFSET          0x06         /**< \brief (MCLK_BUPDIV offset) Backup Clock Division */
#define MCLK_BUPDIV_RESETVALUE      _U_(0x01)    /**< \brief (MCLK_BUPDIV reset_value) Backup Clock Division */

#define MCLK_BUPDIV_BUPDIV_Pos      0            /**< \brief (MCLK_BUPDIV) Backup Clock Division Factor */
#define MCLK_BUPDIV_BUPDIV_Msk      (_U_(0xFF) << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV(value)   (MCLK_BUPDIV_BUPDIV_Msk & ((value) << MCLK_BUPDIV_BUPDIV_Pos))
#define   MCLK_BUPDIV_BUPDIV_DIV1_Val     _U_(0x1)   /**< \brief (MCLK_BUPDIV) Divide by 1 */
#define   MCLK_BUPDIV_BUPDIV_DIV2_Val     _U_(0x2)   /**< \brief (MCLK_BUPDIV) Divide by 2 */
#define   MCLK_BUPDIV_BUPDIV_DIV4_Val     _U_(0x4)   /**< \brief (MCLK_BUPDIV) Divide by 4 */
#define   MCLK_BUPDIV_BUPDIV_DIV8_Val     _U_(0x8)   /**< \brief (MCLK_BUPDIV) Divide by 8 */
#define   MCLK_BUPDIV_BUPDIV_DIV16_Val    _U_(0x10)   /**< \brief (MCLK_BUPDIV) Divide by 16 */
#define   MCLK_BUPDIV_BUPDIV_DIV32_Val    _U_(0x20)   /**< \brief (MCLK_BUPDIV) Divide by 32 */
#define   MCLK_BUPDIV_BUPDIV_DIV64_Val    _U_(0x40)   /**< \brief (MCLK_BUPDIV) Divide by 64 */
#define   MCLK_BUPDIV_BUPDIV_DIV128_Val   _U_(0x80)   /**< \brief (MCLK_BUPDIV) Divide by 128 */
#define MCLK_BUPDIV_BUPDIV_DIV1     (MCLK_BUPDIV_BUPDIV_DIV1_Val   << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV2     (MCLK_BUPDIV_BUPDIV_DIV2_Val   << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV4     (MCLK_BUPDIV_BUPDIV_DIV4_Val   << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV8     (MCLK_BUPDIV_BUPDIV_DIV8_Val   << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV16    (MCLK_BUPDIV_BUPDIV_DIV16_Val  << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV32    (MCLK_BUPDIV_BUPDIV_DIV32_Val  << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV64    (MCLK_BUPDIV_BUPDIV_DIV64_Val  << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_BUPDIV_DIV128   (MCLK_BUPDIV_BUPDIV_DIV128_Val << MCLK_BUPDIV_BUPDIV_Pos)
#define MCLK_BUPDIV_MASK            _U_(0xFF)    /**< \brief (MCLK_BUPDIV) MASK Register */

/* -------- MCLK_AHBMASK : (MCLK Offset: 0x10) (R/W 32) AHB Mask -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t HPB0_:1;          /*!< bit:      0  HPB0 AHB Clock Mask                */
    uint32_t HPB1_:1;          /*!< bit:      1  HPB1 AHB Clock Mask                */
    uint32_t HPB2_:1;          /*!< bit:      2  HPB2 AHB Clock Mask                */
    uint32_t DMAC_:1;          /*!< bit:      3  DMAC AHB Clock Mask                */
    uint32_t USB_:1;           /*!< bit:      4  USB AHB Clock Mask                 */
    uint32_t DSU_:1;           /*!< bit:      5  DSU AHB Clock Mask                 */
    uint32_t :1;               /*!< bit:      6  Reserved                           */
    uint32_t PAC_:1;           /*!< bit:      7  PAC AHB Clock Mask                 */
    uint32_t NVMCTRL_:1;       /*!< bit:      8  NVMCTRL AHB Clock Mask             */
    uint32_t HSRAM_:1;         /*!< bit:      9  HSRAM AHB Clock Mask               */
    uint32_t NVMCTRL_PICACHU_:1; /*!< bit:     10  NVMCTRL_PICACHU AHB Clock Mask     */
    uint32_t :21;              /*!< bit: 11..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} MCLK_AHBMASK_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_AHBMASK_OFFSET         0x10         /**< \brief (MCLK_AHBMASK offset) AHB Mask */
#define MCLK_AHBMASK_RESETVALUE     _U_(0x000007FF) /**< \brief (MCLK_AHBMASK reset_value) AHB Mask */

#define MCLK_AHBMASK_HPB0_Pos       0            /**< \brief (MCLK_AHBMASK) HPB0 AHB Clock Mask */
#define MCLK_AHBMASK_HPB0           (_U_(0x1) << MCLK_AHBMASK_HPB0_Pos)
#define MCLK_AHBMASK_HPB1_Pos       1            /**< \brief (MCLK_AHBMASK) HPB1 AHB Clock Mask */
#define MCLK_AHBMASK_HPB1           (_U_(0x1) << MCLK_AHBMASK_HPB1_Pos)
#define MCLK_AHBMASK_HPB2_Pos       2            /**< \brief (MCLK_AHBMASK) HPB2 AHB Clock Mask */
#define MCLK_AHBMASK_HPB2           (_U_(0x1) << MCLK_AHBMASK_HPB2_Pos)
#define MCLK_AHBMASK_DMAC_Pos       3            /**< \brief (MCLK_AHBMASK) DMAC AHB Clock Mask */
#define MCLK_AHBMASK_DMAC           (_U_(0x1) << MCLK_AHBMASK_DMAC_Pos)
#define MCLK_AHBMASK_USB_Pos        4            /**< \brief (MCLK_AHBMASK) USB AHB Clock Mask */
#define MCLK_AHBMASK_USB            (_U_(0x1) << MCLK_AHBMASK_USB_Pos)
#define MCLK_AHBMASK_DSU_Pos        5            /**< \brief (MCLK_AHBMASK) DSU AHB Clock Mask */
#define MCLK_AHBMASK_DSU            (_U_(0x1) << MCLK_AHBMASK_DSU_Pos)
#define MCLK_AHBMASK_PAC_Pos        7            /**< \brief (MCLK_AHBMASK) PAC AHB Clock Mask */
#define MCLK_AHBMASK_PAC            (_U_(0x1) << MCLK_AHBMASK_PAC_Pos)
#define MCLK_AHBMASK_NVMCTRL_Pos    8            /**< \brief (MCLK_AHBMASK) NVMCTRL AHB Clock Mask */
#define MCLK_AHBMASK_NVMCTRL        (_U_(0x1) << MCLK_AHBMASK_NVMCTRL_Pos)
#define MCLK_AHBMASK_HSRAM_Pos      9            /**< \brief (MCLK_AHBMASK) HSRAM AHB Clock Mask */
#define MCLK_AHBMASK_HSRAM          (_U_(0x1) << MCLK_AHBMASK_HSRAM_Pos)
#define MCLK_AHBMASK_NVMCTRL_PICACHU_Pos 10           /**< \brief (MCLK_AHBMASK) NVMCTRL_PICACHU AHB Clock Mask */
#define MCLK_AHBMASK_NVMCTRL_PICACHU (_U_(0x1) << MCLK_AHBMASK_NVMCTRL_PICACHU_Pos)
#define MCLK_AHBMASK_MASK           _U_(0x000007BF) /**< \brief (MCLK_AHBMASK) MASK Register */

/* -------- MCLK_APBAMASK : (MCLK Offset: 0x14) (R/W 32) APBA Mask -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t PAC_:1;           /*!< bit:      0  PAC APB Clock Enable               */
    uint32_t PM_:1;            /*!< bit:      1  PM APB Clock Enable                */
    uint32_t MCLK_:1;          /*!< bit:      2  MCLK APB Clock Enable              */
    uint32_t RSTC_:1;          /*!< bit:      3  RSTC APB Clock Enable              */
    uint32_t OSCCTRL_:1;       /*!< bit:      4  OSCCTRL APB Clock Enable           */
    uint32_t OSC32KCTRL_:1;    /*!< bit:      5  OSC32KCTRL APB Clock Enable        */
    uint32_t SUPC_:1;          /*!< bit:      6  SUPC APB Clock Enable              */
    uint32_t GCLK_:1;          /*!< bit:      7  GCLK APB Clock Enable              */
    uint32_t WDT_:1;           /*!< bit:      8  WDT APB Clock Enable               */
    uint32_t RTC_:1;           /*!< bit:      9  RTC APB Clock Enable               */
    uint32_t EIC_:1;           /*!< bit:     10  EIC APB Clock Enable               */
    uint32_t FREQM_:1;         /*!< bit:     11  FREQM APB Clock Enable             */
    uint32_t :20;              /*!< bit: 12..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} MCLK_APBAMASK_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_APBAMASK_OFFSET        0x14         /**< \brief (MCLK_APBAMASK offset) APBA Mask */
#define MCLK_APBAMASK_RESETVALUE    _U_(0x00001FFF) /**< \brief (MCLK_APBAMASK reset_value) APBA Mask */

#define MCLK_APBAMASK_PAC_Pos       0            /**< \brief (MCLK_APBAMASK) PAC APB Clock Enable */
#define MCLK_APBAMASK_PAC           (_U_(0x1) << MCLK_APBAMASK_PAC_Pos)
#define MCLK_APBAMASK_PM_Pos        1            /**< \brief (MCLK_APBAMASK) PM APB Clock Enable */
#define MCLK_APBAMASK_PM            (_U_(0x1) << MCLK_APBAMASK_PM_Pos)
#define MCLK_APBAMASK_MCLK_Pos      2            /**< \brief (MCLK_APBAMASK) MCLK APB Clock Enable */
#define MCLK_APBAMASK_MCLK          (_U_(0x1) << MCLK_APBAMASK_MCLK_Pos)
#define MCLK_APBAMASK_RSTC_Pos      3            /**< \brief (MCLK_APBAMASK) RSTC APB Clock Enable */
#define MCLK_APBAMASK_RSTC          (_U_(0x1) << MCLK_APBAMASK_RSTC_Pos)
#define MCLK_APBAMASK_OSCCTRL_Pos   4            /**< \brief (MCLK_APBAMASK) OSCCTRL APB Clock Enable */
#define MCLK_APBAMASK_OSCCTRL       (_U_(0x1) << MCLK_APBAMASK_OSCCTRL_Pos)
#define MCLK_APBAMASK_OSC32KCTRL_Pos 5            /**< \brief (MCLK_APBAMASK) OSC32KCTRL APB Clock Enable */
#define MCLK_APBAMASK_OSC32KCTRL    (_U_(0x1) << MCLK_APBAMASK_OSC32KCTRL_Pos)
#define MCLK_APBAMASK_SUPC_Pos      6            /**< \brief (MCLK_APBAMASK) SUPC APB Clock Enable */
#define MCLK_APBAMASK_SUPC          (_U_(0x1) << MCLK_APBAMASK_SUPC_Pos)
#define MCLK_APBAMASK_GCLK_Pos      7            /**< \brief (MCLK_APBAMASK) GCLK APB Clock Enable */
#define MCLK_APBAMASK_GCLK          (_U_(0x1) << MCLK_APBAMASK_GCLK_Pos)
#define MCLK_APBAMASK_WDT_Pos       8            /**< \brief (MCLK_APBAMASK) WDT APB Clock Enable */
#define MCLK_APBAMASK_WDT           (_U_(0x1) << MCLK_APBAMASK_WDT_Pos)
#define MCLK_APBAMASK_RTC_Pos       9            /**< \brief (MCLK_APBAMASK) RTC APB Clock Enable */
#define MCLK_APBAMASK_RTC           (_U_(0x1) << MCLK_APBAMASK_RTC_Pos)
#define MCLK_APBAMASK_EIC_Pos       10           /**< \brief (MCLK_APBAMASK) EIC APB Clock Enable */
#define MCLK_APBAMASK_EIC           (_U_(0x1) << MCLK_APBAMASK_EIC_Pos)
#define MCLK_APBAMASK_FREQM_Pos     11           /**< \brief (MCLK_APBAMASK) FREQM APB Clock Enable */
#define MCLK_APBAMASK_FREQM         (_U_(0x1) << MCLK_APBAMASK_FREQM_Pos)
#define MCLK_APBAMASK_MASK          _U_(0x00000FFF) /**< \brief (MCLK_APBAMASK) MASK Register */

/* -------- MCLK_APBBMASK : (MCLK Offset: 0x18) (R/W 32) APBB Mask -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t USB_:1;           /*!< bit:      0  USB APB Clock Enable               */
    uint32_t DSU_:1;           /*!< bit:      1  DSU APB Clock Enable               */
    uint32_t NVMCTRL_:1;       /*!< bit:      2  NVMCTRL APB Clock Enable           */
    uint32_t PORT_:1;          /*!< bit:      3  PORT APB Clock Enable              */
    uint32_t :28;              /*!< bit:  4..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} MCLK_APBBMASK_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_APBBMASK_OFFSET        0x18         /**< \brief (MCLK_APBBMASK offset) APBB Mask */
#define MCLK_APBBMASK_RESETVALUE    _U_(0x0000004F) /**< \brief (MCLK_APBBMASK reset_value) APBB Mask */

#define MCLK_APBBMASK_USB_Pos       0            /**< \brief (MCLK_APBBMASK) USB APB Clock Enable */
#define MCLK_APBBMASK_USB           (_U_(0x1) << MCLK_APBBMASK_USB_Pos)
#define MCLK_APBBMASK_DSU_Pos       1            /**< \brief (MCLK_APBBMASK) DSU APB Clock Enable */
#define MCLK_APBBMASK_DSU           (_U_(0x1) << MCLK_APBBMASK_DSU_Pos)
#define MCLK_APBBMASK_NVMCTRL_Pos   2            /**< \brief (MCLK_APBBMASK) NVMCTRL APB Clock Enable */
#define MCLK_APBBMASK_NVMCTRL       (_U_(0x1) << MCLK_APBBMASK_NVMCTRL_Pos)
#define MCLK_APBBMASK_PORT_Pos      3            /**< \brief (MCLK_APBBMASK) PORT APB Clock Enable */
#define MCLK_APBBMASK_PORT          (_U_(0x1) << MCLK_APBBMASK_PORT_Pos)
#define MCLK_APBBMASK_MASK          _U_(0x0000000F) /**< \brief (MCLK_APBBMASK) MASK Register */

/* -------- MCLK_APBCMASK : (MCLK Offset: 0x1C) (R/W 32) APBC Mask -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t EVSYS_:1;         /*!< bit:      0  EVSYS APB Clock Enable             */
    uint32_t SERCOM0_:1;       /*!< bit:      1  SERCOM0 APB Clock Enable           */
    uint32_t SERCOM1_:1;       /*!< bit:      2  SERCOM1 APB Clock Enable           */
    uint32_t SERCOM2_:1;       /*!< bit:      3  SERCOM2 APB Clock Enable           */
    uint32_t SERCOM3_:1;       /*!< bit:      4  SERCOM3 APB Clock Enable           */
    uint32_t SERCOM4_:1;       /*!< bit:      5  SERCOM4 APB Clock Enable           */
    uint32_t SERCOM5_:1;       /*!< bit:      6  SERCOM5 APB Clock Enable           */
    uint32_t TCC0_:1;          /*!< bit:      7  TCC0 APB Clock Enable              */
    uint32_t TC0_:1;           /*!< bit:      8  TC0 APB Clock Enable               */
    uint32_t TC1_:1;           /*!< bit:      9  TC1 APB Clock Enable               */
    uint32_t TC2_:1;           /*!< bit:     10  TC2 APB Clock Enable               */
    uint32_t TC3_:1;           /*!< bit:     11  TC3 APB Clock Enable               */
    uint32_t ADC_:1;           /*!< bit:     12  ADC APB Clock Enable               */
    uint32_t AC_:1;            /*!< bit:     13  AC APB Clock Enable                */
    uint32_t PTC_:1;           /*!< bit:     14  PTC APB Clock Enable               */
    uint32_t SLCD_:1;          /*!< bit:     15  SLCD APB Clock Enable              */
    uint32_t AES_:1;           /*!< bit:     16  AES APB Clock Enable               */
    uint32_t TRNG_:1;          /*!< bit:     17  TRNG APB Clock Enable              */
    uint32_t CCL_:1;           /*!< bit:     18  CCL APB Clock Enable               */
    uint32_t :13;              /*!< bit: 19..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} MCLK_APBCMASK_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MCLK_APBCMASK_OFFSET        0x1C         /**< \brief (MCLK_APBCMASK offset) APBC Mask */
#define MCLK_APBCMASK_RESETVALUE    _U_(0x0007FFFF) /**< \brief (MCLK_APBCMASK reset_value) APBC Mask */

#define MCLK_APBCMASK_EVSYS_Pos     0            /**< \brief (MCLK_APBCMASK) EVSYS APB Clock Enable */
#define MCLK_APBCMASK_EVSYS         (_U_(0x1) << MCLK_APBCMASK_EVSYS_Pos)
#define MCLK_APBCMASK_SERCOM0_Pos   1            /**< \brief (MCLK_APBCMASK) SERCOM0 APB Clock Enable */
#define MCLK_APBCMASK_SERCOM0       (_U_(0x1) << MCLK_APBCMASK_SERCOM0_Pos)
#define MCLK_APBCMASK_SERCOM1_Pos   2            /**< \brief (MCLK_APBCMASK) SERCOM1 APB Clock Enable */
#define MCLK_APBCMASK_SERCOM1       (_U_(0x1) << MCLK_APBCMASK_SERCOM1_Pos)
#define MCLK_APBCMASK_SERCOM2_Pos   3            /**< \brief (MCLK_APBCMASK) SERCOM2 APB Clock Enable */
#define MCLK_APBCMASK_SERCOM2       (_U_(0x1) << MCLK_APBCMASK_SERCOM2_Pos)
#define MCLK_APBCMASK_SERCOM3_Pos   4            /**< \brief (MCLK_APBCMASK) SERCOM3 APB Clock Enable */
#define MCLK_APBCMASK_SERCOM3       (_U_(0x1) << MCLK_APBCMASK_SERCOM3_Pos)
#define MCLK_APBCMASK_SERCOM4_Pos   5            /**< \brief (MCLK_APBCMASK) SERCOM4 APB Clock Enable */
#define MCLK_APBCMASK_SERCOM4       (_U_(0x1) << MCLK_APBCMASK_SERCOM4_Pos)
#define MCLK_APBCMASK_SERCOM5_Pos   6            /**< \brief (MCLK_APBCMASK) SERCOM5 APB Clock Enable */
#define MCLK_APBCMASK_SERCOM5       (_U_(0x1) << MCLK_APBCMASK_SERCOM5_Pos)
#define MCLK_APBCMASK_TCC0_Pos      7            /**< \brief (MCLK_APBCMASK) TCC0 APB Clock Enable */
#define MCLK_APBCMASK_TCC0          (_U_(0x1) << MCLK_APBCMASK_TCC0_Pos)
#define MCLK_APBCMASK_TC0_Pos       8            /**< \brief (MCLK_APBCMASK) TC0 APB Clock Enable */
#define MCLK_APBCMASK_TC0           (_U_(0x1) << MCLK_APBCMASK_TC0_Pos)
#define MCLK_APBCMASK_TC1_Pos       9            /**< \brief (MCLK_APBCMASK) TC1 APB Clock Enable */
#define MCLK_APBCMASK_TC1           (_U_(0x1) << MCLK_APBCMASK_TC1_Pos)
#define MCLK_APBCMASK_TC2_Pos       10           /**< \brief (MCLK_APBCMASK) TC2 APB Clock Enable */
#define MCLK_APBCMASK_TC2           (_U_(0x1) << MCLK_APBCMASK_TC2_Pos)
#define MCLK_APBCMASK_TC3_Pos       11           /**< \brief (MCLK_APBCMASK) TC3 APB Clock Enable */
#define MCLK_APBCMASK_TC3           (_U_(0x1) << MCLK_APBCMASK_TC3_Pos)
#define MCLK_APBCMASK_ADC_Pos       12           /**< \brief (MCLK_APBCMASK) ADC APB Clock Enable */
#define MCLK_APBCMASK_ADC           (_U_(0x1) << MCLK_APBCMASK_ADC_Pos)
#define MCLK_APBCMASK_AC_Pos        13           /**< \brief (MCLK_APBCMASK) AC APB Clock Enable */
#define MCLK_APBCMASK_AC            (_U_(0x1) << MCLK_APBCMASK_AC_Pos)
#define MCLK_APBCMASK_PTC_Pos       14           /**< \brief (MCLK_APBCMASK) PTC APB Clock Enable */
#define MCLK_APBCMASK_PTC           (_U_(0x1) << MCLK_APBCMASK_PTC_Pos)
#define MCLK_APBCMASK_SLCD_Pos      15           /**< \brief (MCLK_APBCMASK) SLCD APB Clock Enable */
#define MCLK_APBCMASK_SLCD          (_U_(0x1) << MCLK_APBCMASK_SLCD_Pos)
#define MCLK_APBCMASK_AES_Pos       16           /**< \brief (MCLK_APBCMASK) AES APB Clock Enable */
#define MCLK_APBCMASK_AES           (_U_(0x1) << MCLK_APBCMASK_AES_Pos)
#define MCLK_APBCMASK_TRNG_Pos      17           /**< \brief (MCLK_APBCMASK) TRNG APB Clock Enable */
#define MCLK_APBCMASK_TRNG          (_U_(0x1) << MCLK_APBCMASK_TRNG_Pos)
#define MCLK_APBCMASK_CCL_Pos       18           /**< \brief (MCLK_APBCMASK) CCL APB Clock Enable */
#define MCLK_APBCMASK_CCL           (_U_(0x1) << MCLK_APBCMASK_CCL_Pos)
#define MCLK_APBCMASK_MASK          _U_(0x0007FFFF) /**< \brief (MCLK_APBCMASK) MASK Register */

/** \brief MCLK hardware registers */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct {
       RoReg8                    Reserved1[0x1];
  __IO MCLK_INTENCLR_Type        INTENCLR;    /**< \brief Offset: 0x01 (R/W  8) Interrupt Enable Clear */
  __IO MCLK_INTENSET_Type        INTENSET;    /**< \brief Offset: 0x02 (R/W  8) Interrupt Enable Set */
  __IO MCLK_INTFLAG_Type         INTFLAG;     /**< \brief Offset: 0x03 (R/W  8) Interrupt Flag Status and Clear */
  __IO MCLK_CPUDIV_Type          CPUDIV;      /**< \brief Offset: 0x04 (R/W  8) CPU Clock Division */
       RoReg8                    Reserved2[0x1];
  __IO MCLK_BUPDIV_Type          BUPDIV;      /**< \brief Offset: 0x06 (R/W  8) Backup Clock Division */
       RoReg8                    Reserved3[0x9];
  __IO MCLK_AHBMASK_Type         AHBMASK;     /**< \brief Offset: 0x10 (R/W 32) AHB Mask */
  __IO MCLK_APBAMASK_Type        APBAMASK;    /**< \brief Offset: 0x14 (R/W 32) APBA Mask */
  __IO MCLK_APBBMASK_Type        APBBMASK;    /**< \brief Offset: 0x18 (R/W 32) APBB Mask */
  __IO MCLK_APBCMASK_Type        APBCMASK;    /**< \brief Offset: 0x1C (R/W 32) APBC Mask */
} Mclk;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/*@}*/

#endif /* _SAML22_MCLK_COMPONENT_ */
