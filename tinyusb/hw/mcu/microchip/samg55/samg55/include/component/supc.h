/**
 * \file
 *
 * \brief Component description for SUPC
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
#ifndef _SAMG55_SUPC_COMPONENT_H_
#define _SAMG55_SUPC_COMPONENT_H_
#define _SAMG55_SUPC_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Supply Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR SUPC */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define SUPC_11228                      /**< (SUPC) Module ID */
#define REV_SUPC G                      /**< (SUPC) Module revision */

/* -------- SUPC_CR : (SUPC Offset: 0x00) (/W 32) Supply Controller Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :2;                        /**< bit:   0..1  Reserved */
    uint32_t VROFF:1;                   /**< bit:      2  Voltage Regulator Off                    */
    uint32_t XTALSEL:1;                 /**< bit:      3  Crystal Oscillator Select                */
    uint32_t :20;                       /**< bit:  4..23  Reserved */
    uint32_t KEY:8;                     /**< bit: 24..31  Password                                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_CR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_CR_OFFSET                      (0x00)                                        /**<  (SUPC_CR) Supply Controller Control Register  Offset */

#define SUPC_CR_VROFF_Pos                   2                                              /**< (SUPC_CR) Voltage Regulator Off Position */
#define SUPC_CR_VROFF_Msk                   (_U_(0x1) << SUPC_CR_VROFF_Pos)                /**< (SUPC_CR) Voltage Regulator Off Mask */
#define SUPC_CR_VROFF                       SUPC_CR_VROFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_CR_VROFF_Msk instead */
#define   SUPC_CR_VROFF_NO_EFFECT_Val       _U_(0x0)                                       /**< (SUPC_CR) No effect.  */
#define   SUPC_CR_VROFF_STOP_VREG_Val       _U_(0x1)                                       /**< (SUPC_CR) If KEY is correct, asserts the system reset signal and stops the voltage regulator.  */
#define SUPC_CR_VROFF_NO_EFFECT             (SUPC_CR_VROFF_NO_EFFECT_Val << SUPC_CR_VROFF_Pos)  /**< (SUPC_CR) No effect. Position  */
#define SUPC_CR_VROFF_STOP_VREG             (SUPC_CR_VROFF_STOP_VREG_Val << SUPC_CR_VROFF_Pos)  /**< (SUPC_CR) If KEY is correct, asserts the system reset signal and stops the voltage regulator. Position  */
#define SUPC_CR_XTALSEL_Pos                 3                                              /**< (SUPC_CR) Crystal Oscillator Select Position */
#define SUPC_CR_XTALSEL_Msk                 (_U_(0x1) << SUPC_CR_XTALSEL_Pos)              /**< (SUPC_CR) Crystal Oscillator Select Mask */
#define SUPC_CR_XTALSEL                     SUPC_CR_XTALSEL_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_CR_XTALSEL_Msk instead */
#define   SUPC_CR_XTALSEL_NO_EFFECT_Val     _U_(0x0)                                       /**< (SUPC_CR) No effect.  */
#define   SUPC_CR_XTALSEL_CRYSTAL_SEL_Val   _U_(0x1)                                       /**< (SUPC_CR) If KEY is correct, switches the slow clock on the crystal oscillator output.  */
#define SUPC_CR_XTALSEL_NO_EFFECT           (SUPC_CR_XTALSEL_NO_EFFECT_Val << SUPC_CR_XTALSEL_Pos)  /**< (SUPC_CR) No effect. Position  */
#define SUPC_CR_XTALSEL_CRYSTAL_SEL         (SUPC_CR_XTALSEL_CRYSTAL_SEL_Val << SUPC_CR_XTALSEL_Pos)  /**< (SUPC_CR) If KEY is correct, switches the slow clock on the crystal oscillator output. Position  */
#define SUPC_CR_KEY_Pos                     24                                             /**< (SUPC_CR) Password Position */
#define SUPC_CR_KEY_Msk                     (_U_(0xFF) << SUPC_CR_KEY_Pos)                 /**< (SUPC_CR) Password Mask */
#define SUPC_CR_KEY(value)                  (SUPC_CR_KEY_Msk & ((value) << SUPC_CR_KEY_Pos))
#define   SUPC_CR_KEY_PASSWD_Val            _U_(0xA5)                                      /**< (SUPC_CR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define SUPC_CR_KEY_PASSWD                  (SUPC_CR_KEY_PASSWD_Val << SUPC_CR_KEY_Pos)    /**< (SUPC_CR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define SUPC_CR_MASK                        _U_(0xFF00000C)                                /**< \deprecated (SUPC_CR) Register MASK  (Use SUPC_CR_Msk instead)  */
#define SUPC_CR_Msk                         _U_(0xFF00000C)                                /**< (SUPC_CR) Register Mask  */


/* -------- SUPC_SMMR : (SUPC Offset: 0x04) (R/W 32) Supply Controller Supply Monitor Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SMTH:4;                    /**< bit:   0..3  Supply Monitor Threshold                 */
    uint32_t :4;                        /**< bit:   4..7  Reserved */
    uint32_t SMSMPL:3;                  /**< bit:  8..10  Supply Monitor Sampling Period           */
    uint32_t :1;                        /**< bit:     11  Reserved */
    uint32_t SMRSTEN:1;                 /**< bit:     12  Supply Monitor Reset Enable              */
    uint32_t SMIEN:1;                   /**< bit:     13  Supply Monitor Interrupt Enable          */
    uint32_t :18;                       /**< bit: 14..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_SMMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_SMMR_OFFSET                    (0x04)                                        /**<  (SUPC_SMMR) Supply Controller Supply Monitor Mode Register  Offset */

#define SUPC_SMMR_SMTH_Pos                  0                                              /**< (SUPC_SMMR) Supply Monitor Threshold Position */
#define SUPC_SMMR_SMTH_Msk                  (_U_(0xF) << SUPC_SMMR_SMTH_Pos)               /**< (SUPC_SMMR) Supply Monitor Threshold Mask */
#define SUPC_SMMR_SMTH(value)               (SUPC_SMMR_SMTH_Msk & ((value) << SUPC_SMMR_SMTH_Pos))
#define SUPC_SMMR_SMSMPL_Pos                8                                              /**< (SUPC_SMMR) Supply Monitor Sampling Period Position */
#define SUPC_SMMR_SMSMPL_Msk                (_U_(0x7) << SUPC_SMMR_SMSMPL_Pos)             /**< (SUPC_SMMR) Supply Monitor Sampling Period Mask */
#define SUPC_SMMR_SMSMPL(value)             (SUPC_SMMR_SMSMPL_Msk & ((value) << SUPC_SMMR_SMSMPL_Pos))
#define   SUPC_SMMR_SMSMPL_SMD_Val          _U_(0x0)                                       /**< (SUPC_SMMR) Supply Monitor disabled  */
#define   SUPC_SMMR_SMSMPL_CSM_Val          _U_(0x1)                                       /**< (SUPC_SMMR) Continuous Supply Monitor  */
#define   SUPC_SMMR_SMSMPL_32SLCK_Val       _U_(0x2)                                       /**< (SUPC_SMMR) Supply Monitor enables one SLCK period every 32 SLCK periods  */
#define   SUPC_SMMR_SMSMPL_256SLCK_Val      _U_(0x3)                                       /**< (SUPC_SMMR) Supply Monitor enables one SLCK period every 256 SLCK periods  */
#define   SUPC_SMMR_SMSMPL_2048SLCK_Val     _U_(0x4)                                       /**< (SUPC_SMMR) Supply Monitor enables one SLCK period every 2,048 SLCK periods  */
#define SUPC_SMMR_SMSMPL_SMD                (SUPC_SMMR_SMSMPL_SMD_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor disabled Position  */
#define SUPC_SMMR_SMSMPL_CSM                (SUPC_SMMR_SMSMPL_CSM_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Continuous Supply Monitor Position  */
#define SUPC_SMMR_SMSMPL_32SLCK             (SUPC_SMMR_SMSMPL_32SLCK_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor enables one SLCK period every 32 SLCK periods Position  */
#define SUPC_SMMR_SMSMPL_256SLCK            (SUPC_SMMR_SMSMPL_256SLCK_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor enables one SLCK period every 256 SLCK periods Position  */
#define SUPC_SMMR_SMSMPL_2048SLCK           (SUPC_SMMR_SMSMPL_2048SLCK_Val << SUPC_SMMR_SMSMPL_Pos)  /**< (SUPC_SMMR) Supply Monitor enables one SLCK period every 2,048 SLCK periods Position  */
#define SUPC_SMMR_SMRSTEN_Pos               12                                             /**< (SUPC_SMMR) Supply Monitor Reset Enable Position */
#define SUPC_SMMR_SMRSTEN_Msk               (_U_(0x1) << SUPC_SMMR_SMRSTEN_Pos)            /**< (SUPC_SMMR) Supply Monitor Reset Enable Mask */
#define SUPC_SMMR_SMRSTEN                   SUPC_SMMR_SMRSTEN_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SMMR_SMRSTEN_Msk instead */
#define   SUPC_SMMR_SMRSTEN_NOT_ENABLE_Val  _U_(0x0)                                       /**< (SUPC_SMMR) The core reset signal vddcore_nreset is not affected when a supply monitor detection occurs.  */
#define   SUPC_SMMR_SMRSTEN_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_SMMR) The core reset signal vddcore_nreset is asserted when a supply monitor detection occurs.  */
#define SUPC_SMMR_SMRSTEN_NOT_ENABLE        (SUPC_SMMR_SMRSTEN_NOT_ENABLE_Val << SUPC_SMMR_SMRSTEN_Pos)  /**< (SUPC_SMMR) The core reset signal vddcore_nreset is not affected when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_SMRSTEN_ENABLE            (SUPC_SMMR_SMRSTEN_ENABLE_Val << SUPC_SMMR_SMRSTEN_Pos)  /**< (SUPC_SMMR) The core reset signal vddcore_nreset is asserted when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_SMIEN_Pos                 13                                             /**< (SUPC_SMMR) Supply Monitor Interrupt Enable Position */
#define SUPC_SMMR_SMIEN_Msk                 (_U_(0x1) << SUPC_SMMR_SMIEN_Pos)              /**< (SUPC_SMMR) Supply Monitor Interrupt Enable Mask */
#define SUPC_SMMR_SMIEN                     SUPC_SMMR_SMIEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SMMR_SMIEN_Msk instead */
#define   SUPC_SMMR_SMIEN_NOT_ENABLE_Val    _U_(0x0)                                       /**< (SUPC_SMMR) The SUPC interrupt signal is not affected when a supply monitor detection occurs.  */
#define   SUPC_SMMR_SMIEN_ENABLE_Val        _U_(0x1)                                       /**< (SUPC_SMMR) The SUPC interrupt signal is asserted when a supply monitor detection occurs.  */
#define SUPC_SMMR_SMIEN_NOT_ENABLE          (SUPC_SMMR_SMIEN_NOT_ENABLE_Val << SUPC_SMMR_SMIEN_Pos)  /**< (SUPC_SMMR) The SUPC interrupt signal is not affected when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_SMIEN_ENABLE              (SUPC_SMMR_SMIEN_ENABLE_Val << SUPC_SMMR_SMIEN_Pos)  /**< (SUPC_SMMR) The SUPC interrupt signal is asserted when a supply monitor detection occurs. Position  */
#define SUPC_SMMR_MASK                      _U_(0x370F)                                    /**< \deprecated (SUPC_SMMR) Register MASK  (Use SUPC_SMMR_Msk instead)  */
#define SUPC_SMMR_Msk                       _U_(0x370F)                                    /**< (SUPC_SMMR) Register Mask  */


/* -------- SUPC_MR : (SUPC Offset: 0x08) (R/W 32) Supply Controller Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :12;                       /**< bit:  0..11  Reserved */
    uint32_t BODRSTEN:1;                /**< bit:     12  POR Core Reset Enable                    */
    uint32_t BODDIS:1;                  /**< bit:     13  POR Core Disable                         */
    uint32_t :6;                        /**< bit: 14..19  Reserved */
    uint32_t OSCBYPASS:1;               /**< bit:     20  Oscillator Bypass                        */
    uint32_t CDPSWITCH:1;               /**< bit:     21  Cache Data SRAM Power Switch             */
    uint32_t CTPSWITCH:1;               /**< bit:     22  Cache Tag SRAM Power Switch              */
    uint32_t ONE:1;                     /**< bit:     23  This bit must always be set to 1.        */
    uint32_t KEY:8;                     /**< bit: 24..31  Password Key                             */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_MR_OFFSET                      (0x08)                                        /**<  (SUPC_MR) Supply Controller Mode Register  Offset */

#define SUPC_MR_BODRSTEN_Pos                12                                             /**< (SUPC_MR) POR Core Reset Enable Position */
#define SUPC_MR_BODRSTEN_Msk                (_U_(0x1) << SUPC_MR_BODRSTEN_Pos)             /**< (SUPC_MR) POR Core Reset Enable Mask */
#define SUPC_MR_BODRSTEN                    SUPC_MR_BODRSTEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_MR_BODRSTEN_Msk instead */
#define   SUPC_MR_BODRSTEN_NOT_ENABLE_Val   _U_(0x0)                                       /**< (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs.  */
#define   SUPC_MR_BODRSTEN_ENABLE_Val       _U_(0x1)                                       /**< (SUPC_MR) The core reset signal vddcore_nreset is asserted when a brownout detection occurs.  */
#define SUPC_MR_BODRSTEN_NOT_ENABLE         (SUPC_MR_BODRSTEN_NOT_ENABLE_Val << SUPC_MR_BODRSTEN_Pos)  /**< (SUPC_MR) The core reset signal vddcore_nreset is not affected when a brownout detection occurs. Position  */
#define SUPC_MR_BODRSTEN_ENABLE             (SUPC_MR_BODRSTEN_ENABLE_Val << SUPC_MR_BODRSTEN_Pos)  /**< (SUPC_MR) The core reset signal vddcore_nreset is asserted when a brownout detection occurs. Position  */
#define SUPC_MR_BODDIS_Pos                  13                                             /**< (SUPC_MR) POR Core Disable Position */
#define SUPC_MR_BODDIS_Msk                  (_U_(0x1) << SUPC_MR_BODDIS_Pos)               /**< (SUPC_MR) POR Core Disable Mask */
#define SUPC_MR_BODDIS                      SUPC_MR_BODDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_MR_BODDIS_Msk instead */
#define   SUPC_MR_BODDIS_ENABLE_Val         _U_(0x0)                                       /**< (SUPC_MR) The core brownout detector is enabled.  */
#define   SUPC_MR_BODDIS_DISABLE_Val        _U_(0x1)                                       /**< (SUPC_MR) The core brownout detector is disabled.  */
#define SUPC_MR_BODDIS_ENABLE               (SUPC_MR_BODDIS_ENABLE_Val << SUPC_MR_BODDIS_Pos)  /**< (SUPC_MR) The core brownout detector is enabled. Position  */
#define SUPC_MR_BODDIS_DISABLE              (SUPC_MR_BODDIS_DISABLE_Val << SUPC_MR_BODDIS_Pos)  /**< (SUPC_MR) The core brownout detector is disabled. Position  */
#define SUPC_MR_OSCBYPASS_Pos               20                                             /**< (SUPC_MR) Oscillator Bypass Position */
#define SUPC_MR_OSCBYPASS_Msk               (_U_(0x1) << SUPC_MR_OSCBYPASS_Pos)            /**< (SUPC_MR) Oscillator Bypass Mask */
#define SUPC_MR_OSCBYPASS                   SUPC_MR_OSCBYPASS_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_MR_OSCBYPASS_Msk instead */
#define   SUPC_MR_OSCBYPASS_NO_EFFECT_Val   _U_(0x0)                                       /**< (SUPC_MR) No effect. Clock selection depends on XTALSEL value.  */
#define   SUPC_MR_OSCBYPASS_BYPASS_Val      _U_(0x1)                                       /**< (SUPC_MR) The 32 kHz crystal oscillator is bypassed if XTALSEL=1. OSCBYPASS must be set prior to write XTALSEL=1.  */
#define SUPC_MR_OSCBYPASS_NO_EFFECT         (SUPC_MR_OSCBYPASS_NO_EFFECT_Val << SUPC_MR_OSCBYPASS_Pos)  /**< (SUPC_MR) No effect. Clock selection depends on XTALSEL value. Position  */
#define SUPC_MR_OSCBYPASS_BYPASS            (SUPC_MR_OSCBYPASS_BYPASS_Val << SUPC_MR_OSCBYPASS_Pos)  /**< (SUPC_MR) The 32 kHz crystal oscillator is bypassed if XTALSEL=1. OSCBYPASS must be set prior to write XTALSEL=1. Position  */
#define SUPC_MR_CDPSWITCH_Pos               21                                             /**< (SUPC_MR) Cache Data SRAM Power Switch Position */
#define SUPC_MR_CDPSWITCH_Msk               (_U_(0x1) << SUPC_MR_CDPSWITCH_Pos)            /**< (SUPC_MR) Cache Data SRAM Power Switch Mask */
#define SUPC_MR_CDPSWITCH                   SUPC_MR_CDPSWITCH_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_MR_CDPSWITCH_Msk instead */
#define   SUPC_MR_CDPSWITCH_OFF_Val         _U_(0x0)                                       /**< (SUPC_MR) The cache data SRAM is not powered.  */
#define   SUPC_MR_CDPSWITCH_ON_Val          _U_(0x1)                                       /**< (SUPC_MR) The cache data SRAM is powered.  */
#define SUPC_MR_CDPSWITCH_OFF               (SUPC_MR_CDPSWITCH_OFF_Val << SUPC_MR_CDPSWITCH_Pos)  /**< (SUPC_MR) The cache data SRAM is not powered. Position  */
#define SUPC_MR_CDPSWITCH_ON                (SUPC_MR_CDPSWITCH_ON_Val << SUPC_MR_CDPSWITCH_Pos)  /**< (SUPC_MR) The cache data SRAM is powered. Position  */
#define SUPC_MR_CTPSWITCH_Pos               22                                             /**< (SUPC_MR) Cache Tag SRAM Power Switch Position */
#define SUPC_MR_CTPSWITCH_Msk               (_U_(0x1) << SUPC_MR_CTPSWITCH_Pos)            /**< (SUPC_MR) Cache Tag SRAM Power Switch Mask */
#define SUPC_MR_CTPSWITCH                   SUPC_MR_CTPSWITCH_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_MR_CTPSWITCH_Msk instead */
#define   SUPC_MR_CTPSWITCH_OFF_Val         _U_(0x0)                                       /**< (SUPC_MR) The cache tag SRAM is not powered.  */
#define   SUPC_MR_CTPSWITCH_ON_Val          _U_(0x1)                                       /**< (SUPC_MR) The cache tag SRAM is powered.  */
#define SUPC_MR_CTPSWITCH_OFF               (SUPC_MR_CTPSWITCH_OFF_Val << SUPC_MR_CTPSWITCH_Pos)  /**< (SUPC_MR) The cache tag SRAM is not powered. Position  */
#define SUPC_MR_CTPSWITCH_ON                (SUPC_MR_CTPSWITCH_ON_Val << SUPC_MR_CTPSWITCH_Pos)  /**< (SUPC_MR) The cache tag SRAM is powered. Position  */
#define SUPC_MR_ONE_Pos                     23                                             /**< (SUPC_MR) This bit must always be set to 1. Position */
#define SUPC_MR_ONE_Msk                     (_U_(0x1) << SUPC_MR_ONE_Pos)                  /**< (SUPC_MR) This bit must always be set to 1. Mask */
#define SUPC_MR_ONE                         SUPC_MR_ONE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_MR_ONE_Msk instead */
#define SUPC_MR_KEY_Pos                     24                                             /**< (SUPC_MR) Password Key Position */
#define SUPC_MR_KEY_Msk                     (_U_(0xFF) << SUPC_MR_KEY_Pos)                 /**< (SUPC_MR) Password Key Mask */
#define SUPC_MR_KEY(value)                  (SUPC_MR_KEY_Msk & ((value) << SUPC_MR_KEY_Pos))
#define   SUPC_MR_KEY_PASSWD_Val            _U_(0xA5)                                      /**< (SUPC_MR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define SUPC_MR_KEY_PASSWD                  (SUPC_MR_KEY_PASSWD_Val << SUPC_MR_KEY_Pos)    /**< (SUPC_MR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define SUPC_MR_MASK                        _U_(0xFFF03000)                                /**< \deprecated (SUPC_MR) Register MASK  (Use SUPC_MR_Msk instead)  */
#define SUPC_MR_Msk                         _U_(0xFFF03000)                                /**< (SUPC_MR) Register Mask  */


/* -------- SUPC_WUMR : (SUPC Offset: 0x0c) (R/W 32) Supply Controller Wake-up Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t SMEN:1;                    /**< bit:      1  Supply Monitor Wake-up Enable            */
    uint32_t RTTEN:1;                   /**< bit:      2  Real-time Timer Wake-up Enable           */
    uint32_t RTCEN:1;                   /**< bit:      3  Real-time Clock Wake-up Enable           */
    uint32_t :1;                        /**< bit:      4  Reserved */
    uint32_t LPDBCEN0:1;                /**< bit:      5  Low-power Debouncer Enable WKUP0         */
    uint32_t LPDBCEN1:1;                /**< bit:      6  Low-power Debouncer Enable WKUP1         */
    uint32_t LPDBCCLR:1;                /**< bit:      7  Low-power Debouncer Clear                */
    uint32_t :4;                        /**< bit:  8..11  Reserved */
    uint32_t WKUPDBC:3;                 /**< bit: 12..14  Wake-up Inputs Debouncer Period          */
    uint32_t :1;                        /**< bit:     15  Reserved */
    uint32_t LPDBC:3;                   /**< bit: 16..18  Low-power Debouncer Period               */
    uint32_t :13;                       /**< bit: 19..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t :5;                        /**< bit:   0..4  Reserved */
    uint32_t LPDBCEN:2;                 /**< bit:   5..6  Low-power Debouncer Enable WKUPx         */
    uint32_t :25;                       /**< bit:  7..31 Reserved */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_WUMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_WUMR_OFFSET                    (0x0C)                                        /**<  (SUPC_WUMR) Supply Controller Wake-up Mode Register  Offset */

#define SUPC_WUMR_SMEN_Pos                  1                                              /**< (SUPC_WUMR) Supply Monitor Wake-up Enable Position */
#define SUPC_WUMR_SMEN_Msk                  (_U_(0x1) << SUPC_WUMR_SMEN_Pos)               /**< (SUPC_WUMR) Supply Monitor Wake-up Enable Mask */
#define SUPC_WUMR_SMEN                      SUPC_WUMR_SMEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUMR_SMEN_Msk instead */
#define   SUPC_WUMR_SMEN_NOT_ENABLE_Val     _U_(0x0)                                       /**< (SUPC_WUMR) The supply monitor detection has no wake-up effect.  */
#define   SUPC_WUMR_SMEN_ENABLE_Val         _U_(0x1)                                       /**< (SUPC_WUMR) The supply monitor detection forces the wake-up of the core power supply.  */
#define SUPC_WUMR_SMEN_NOT_ENABLE           (SUPC_WUMR_SMEN_NOT_ENABLE_Val << SUPC_WUMR_SMEN_Pos)  /**< (SUPC_WUMR) The supply monitor detection has no wake-up effect. Position  */
#define SUPC_WUMR_SMEN_ENABLE               (SUPC_WUMR_SMEN_ENABLE_Val << SUPC_WUMR_SMEN_Pos)  /**< (SUPC_WUMR) The supply monitor detection forces the wake-up of the core power supply. Position  */
#define SUPC_WUMR_RTTEN_Pos                 2                                              /**< (SUPC_WUMR) Real-time Timer Wake-up Enable Position */
#define SUPC_WUMR_RTTEN_Msk                 (_U_(0x1) << SUPC_WUMR_RTTEN_Pos)              /**< (SUPC_WUMR) Real-time Timer Wake-up Enable Mask */
#define SUPC_WUMR_RTTEN                     SUPC_WUMR_RTTEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUMR_RTTEN_Msk instead */
#define   SUPC_WUMR_RTTEN_ENABLE_Val        _U_(0x1)                                       /**< (SUPC_WUMR) The RTT alarm signal forces the wake-up of the core power supply.  */
#define SUPC_WUMR_RTTEN_ENABLE              (SUPC_WUMR_RTTEN_ENABLE_Val << SUPC_WUMR_RTTEN_Pos)  /**< (SUPC_WUMR) The RTT alarm signal forces the wake-up of the core power supply. Position  */
#define SUPC_WUMR_RTCEN_Pos                 3                                              /**< (SUPC_WUMR) Real-time Clock Wake-up Enable Position */
#define SUPC_WUMR_RTCEN_Msk                 (_U_(0x1) << SUPC_WUMR_RTCEN_Pos)              /**< (SUPC_WUMR) Real-time Clock Wake-up Enable Mask */
#define SUPC_WUMR_RTCEN                     SUPC_WUMR_RTCEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUMR_RTCEN_Msk instead */
#define   SUPC_WUMR_RTCEN_ENABLE_Val        _U_(0x1)                                       /**< (SUPC_WUMR) The RTC alarm signal forces the wake-up of the core power supply.  */
#define SUPC_WUMR_RTCEN_ENABLE              (SUPC_WUMR_RTCEN_ENABLE_Val << SUPC_WUMR_RTCEN_Pos)  /**< (SUPC_WUMR) The RTC alarm signal forces the wake-up of the core power supply. Position  */
#define SUPC_WUMR_LPDBCEN0_Pos              5                                              /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP0 Position */
#define SUPC_WUMR_LPDBCEN0_Msk              (_U_(0x1) << SUPC_WUMR_LPDBCEN0_Pos)           /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP0 Mask */
#define SUPC_WUMR_LPDBCEN0                  SUPC_WUMR_LPDBCEN0_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUMR_LPDBCEN0_Msk instead */
#define   SUPC_WUMR_LPDBCEN0_NOT_ENABLE_Val _U_(0x0)                                       /**< (SUPC_WUMR) The WKUP0 input pin is not connected to the low-power debouncer.  */
#define   SUPC_WUMR_LPDBCEN0_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUMR) The WKUP0 input pin is connected to the low-power debouncer and forces a system wake-up.  */
#define SUPC_WUMR_LPDBCEN0_NOT_ENABLE       (SUPC_WUMR_LPDBCEN0_NOT_ENABLE_Val << SUPC_WUMR_LPDBCEN0_Pos)  /**< (SUPC_WUMR) The WKUP0 input pin is not connected to the low-power debouncer. Position  */
#define SUPC_WUMR_LPDBCEN0_ENABLE           (SUPC_WUMR_LPDBCEN0_ENABLE_Val << SUPC_WUMR_LPDBCEN0_Pos)  /**< (SUPC_WUMR) The WKUP0 input pin is connected to the low-power debouncer and forces a system wake-up. Position  */
#define SUPC_WUMR_LPDBCEN1_Pos              6                                              /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP1 Position */
#define SUPC_WUMR_LPDBCEN1_Msk              (_U_(0x1) << SUPC_WUMR_LPDBCEN1_Pos)           /**< (SUPC_WUMR) Low-power Debouncer Enable WKUP1 Mask */
#define SUPC_WUMR_LPDBCEN1                  SUPC_WUMR_LPDBCEN1_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUMR_LPDBCEN1_Msk instead */
#define   SUPC_WUMR_LPDBCEN1_NOT_ENABLE_Val _U_(0x0)                                       /**< (SUPC_WUMR) The WKUP1 input pin is not connected to the low-power debouncer.  */
#define   SUPC_WUMR_LPDBCEN1_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUMR) The WKUP1 input pin is connected to the low-power debouncer and forces a system wake-up.  */
#define SUPC_WUMR_LPDBCEN1_NOT_ENABLE       (SUPC_WUMR_LPDBCEN1_NOT_ENABLE_Val << SUPC_WUMR_LPDBCEN1_Pos)  /**< (SUPC_WUMR) The WKUP1 input pin is not connected to the low-power debouncer. Position  */
#define SUPC_WUMR_LPDBCEN1_ENABLE           (SUPC_WUMR_LPDBCEN1_ENABLE_Val << SUPC_WUMR_LPDBCEN1_Pos)  /**< (SUPC_WUMR) The WKUP1 input pin is connected to the low-power debouncer and forces a system wake-up. Position  */
#define SUPC_WUMR_LPDBCCLR_Pos              7                                              /**< (SUPC_WUMR) Low-power Debouncer Clear Position */
#define SUPC_WUMR_LPDBCCLR_Msk              (_U_(0x1) << SUPC_WUMR_LPDBCCLR_Pos)           /**< (SUPC_WUMR) Low-power Debouncer Clear Mask */
#define SUPC_WUMR_LPDBCCLR                  SUPC_WUMR_LPDBCCLR_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUMR_LPDBCCLR_Msk instead */
#define   SUPC_WUMR_LPDBCCLR_NOT_ENABLE_Val _U_(0x0)                                       /**< (SUPC_WUMR) A low-power debounce event does not create an immediate clear on the first half of GPBR registers.  */
#define   SUPC_WUMR_LPDBCCLR_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUMR) A low-power debounce event on WKUP0 or WKUP1 generates an immediate clear on the first half of GPBR registers.  */
#define SUPC_WUMR_LPDBCCLR_NOT_ENABLE       (SUPC_WUMR_LPDBCCLR_NOT_ENABLE_Val << SUPC_WUMR_LPDBCCLR_Pos)  /**< (SUPC_WUMR) A low-power debounce event does not create an immediate clear on the first half of GPBR registers. Position  */
#define SUPC_WUMR_LPDBCCLR_ENABLE           (SUPC_WUMR_LPDBCCLR_ENABLE_Val << SUPC_WUMR_LPDBCCLR_Pos)  /**< (SUPC_WUMR) A low-power debounce event on WKUP0 or WKUP1 generates an immediate clear on the first half of GPBR registers. Position  */
#define SUPC_WUMR_WKUPDBC_Pos               12                                             /**< (SUPC_WUMR) Wake-up Inputs Debouncer Period Position */
#define SUPC_WUMR_WKUPDBC_Msk               (_U_(0x7) << SUPC_WUMR_WKUPDBC_Pos)            /**< (SUPC_WUMR) Wake-up Inputs Debouncer Period Mask */
#define SUPC_WUMR_WKUPDBC(value)            (SUPC_WUMR_WKUPDBC_Msk & ((value) << SUPC_WUMR_WKUPDBC_Pos))
#define   SUPC_WUMR_WKUPDBC_IMMEDIATE_Val   _U_(0x0)                                       /**< (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge.  */
#define   SUPC_WUMR_WKUPDBC_3_SCLK_Val      _U_(0x1)                                       /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_32_SCLK_Val     _U_(0x2)                                       /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_512_SCLK_Val    _U_(0x3)                                       /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_4096_SCLK_Val   _U_(0x4)                                       /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods  */
#define   SUPC_WUMR_WKUPDBC_32768_SCLK_Val  _U_(0x5)                                       /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods  */
#define SUPC_WUMR_WKUPDBC_IMMEDIATE         (SUPC_WUMR_WKUPDBC_IMMEDIATE_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) Immediate, no debouncing, detected active at least on one Slow Clock edge. Position  */
#define SUPC_WUMR_WKUPDBC_3_SCLK            (SUPC_WUMR_WKUPDBC_3_SCLK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 3 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_32_SCLK           (SUPC_WUMR_WKUPDBC_32_SCLK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_512_SCLK          (SUPC_WUMR_WKUPDBC_512_SCLK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 512 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_4096_SCLK         (SUPC_WUMR_WKUPDBC_4096_SCLK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 4,096 SLCK periods Position  */
#define SUPC_WUMR_WKUPDBC_32768_SCLK        (SUPC_WUMR_WKUPDBC_32768_SCLK_Val << SUPC_WUMR_WKUPDBC_Pos)  /**< (SUPC_WUMR) WKUPx shall be in its active state for at least 32,768 SLCK periods Position  */
#define SUPC_WUMR_LPDBC_Pos                 16                                             /**< (SUPC_WUMR) Low-power Debouncer Period Position */
#define SUPC_WUMR_LPDBC_Msk                 (_U_(0x7) << SUPC_WUMR_LPDBC_Pos)              /**< (SUPC_WUMR) Low-power Debouncer Period Mask */
#define SUPC_WUMR_LPDBC(value)              (SUPC_WUMR_LPDBC_Msk & ((value) << SUPC_WUMR_LPDBC_Pos))
#define   SUPC_WUMR_LPDBC_DISABLE_Val       _U_(0x0)                                       /**< (SUPC_WUMR) Disable the low-power debouncers.  */
#define   SUPC_WUMR_LPDBC_2_RTCOUT0_Val     _U_(0x1)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 2 RTCOUTx periods  */
#define   SUPC_WUMR_LPDBC_3_RTCOUT0_Val     _U_(0x2)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 3 RTCOUTx periods  */
#define   SUPC_WUMR_LPDBC_4_RTCOUT0_Val     _U_(0x3)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 4 RTCOUTx periods  */
#define   SUPC_WUMR_LPDBC_5_RTCOUT0_Val     _U_(0x4)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 5 RTCOUTx periods  */
#define   SUPC_WUMR_LPDBC_6_RTCOUT0_Val     _U_(0x5)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 6 RTCOUTx periods  */
#define   SUPC_WUMR_LPDBC_7_RTCOUT0_Val     _U_(0x6)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 7 RTCOUTx periods  */
#define   SUPC_WUMR_LPDBC_8_RTCOUT0_Val     _U_(0x7)                                       /**< (SUPC_WUMR) WKUP0/1 in active state for at least 8 RTCOUTx periods  */
#define SUPC_WUMR_LPDBC_DISABLE             (SUPC_WUMR_LPDBC_DISABLE_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) Disable the low-power debouncers. Position  */
#define SUPC_WUMR_LPDBC_2_RTCOUT0           (SUPC_WUMR_LPDBC_2_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 2 RTCOUTx periods Position  */
#define SUPC_WUMR_LPDBC_3_RTCOUT0           (SUPC_WUMR_LPDBC_3_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 3 RTCOUTx periods Position  */
#define SUPC_WUMR_LPDBC_4_RTCOUT0           (SUPC_WUMR_LPDBC_4_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 4 RTCOUTx periods Position  */
#define SUPC_WUMR_LPDBC_5_RTCOUT0           (SUPC_WUMR_LPDBC_5_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 5 RTCOUTx periods Position  */
#define SUPC_WUMR_LPDBC_6_RTCOUT0           (SUPC_WUMR_LPDBC_6_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 6 RTCOUTx periods Position  */
#define SUPC_WUMR_LPDBC_7_RTCOUT0           (SUPC_WUMR_LPDBC_7_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 7 RTCOUTx periods Position  */
#define SUPC_WUMR_LPDBC_8_RTCOUT0           (SUPC_WUMR_LPDBC_8_RTCOUT0_Val << SUPC_WUMR_LPDBC_Pos)  /**< (SUPC_WUMR) WKUP0/1 in active state for at least 8 RTCOUTx periods Position  */
#define SUPC_WUMR_MASK                      _U_(0x770EE)                                   /**< \deprecated (SUPC_WUMR) Register MASK  (Use SUPC_WUMR_Msk instead)  */
#define SUPC_WUMR_Msk                       _U_(0x770EE)                                   /**< (SUPC_WUMR) Register Mask  */

#define SUPC_WUMR_LPDBCEN_Pos               5                                              /**< (SUPC_WUMR Position) Low-power Debouncer Enable WKUPx */
#define SUPC_WUMR_LPDBCEN_Msk               (_U_(0x3) << SUPC_WUMR_LPDBCEN_Pos)            /**< (SUPC_WUMR Mask) LPDBCEN */
#define SUPC_WUMR_LPDBCEN(value)            (SUPC_WUMR_LPDBCEN_Msk & ((value) << SUPC_WUMR_LPDBCEN_Pos))  

/* -------- SUPC_WUIR : (SUPC Offset: 0x10) (R/W 32) Supply Controller Wake-up Inputs Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WKUPEN0:1;                 /**< bit:      0  Wake-up Input Enable 0                   */
    uint32_t WKUPEN1:1;                 /**< bit:      1  Wake-up Input Enable 1                   */
    uint32_t WKUPEN2:1;                 /**< bit:      2  Wake-up Input Enable 2                   */
    uint32_t WKUPEN3:1;                 /**< bit:      3  Wake-up Input Enable 3                   */
    uint32_t WKUPEN4:1;                 /**< bit:      4  Wake-up Input Enable 4                   */
    uint32_t WKUPEN5:1;                 /**< bit:      5  Wake-up Input Enable 5                   */
    uint32_t WKUPEN6:1;                 /**< bit:      6  Wake-up Input Enable 6                   */
    uint32_t WKUPEN7:1;                 /**< bit:      7  Wake-up Input Enable 7                   */
    uint32_t WKUPEN8:1;                 /**< bit:      8  Wake-up Input Enable 8                   */
    uint32_t WKUPEN9:1;                 /**< bit:      9  Wake-up Input Enable 9                   */
    uint32_t WKUPEN10:1;                /**< bit:     10  Wake-up Input Enable 10                  */
    uint32_t WKUPEN11:1;                /**< bit:     11  Wake-up Input Enable 11                  */
    uint32_t WKUPEN12:1;                /**< bit:     12  Wake-up Input Enable 12                  */
    uint32_t WKUPEN13:1;                /**< bit:     13  Wake-up Input Enable 13                  */
    uint32_t WKUPEN14:1;                /**< bit:     14  Wake-up Input Enable 14                  */
    uint32_t WKUPEN15:1;                /**< bit:     15  Wake-up Input Enable 15                  */
    uint32_t WKUPT0:1;                  /**< bit:     16  Wake-up Input Type 0                     */
    uint32_t WKUPT1:1;                  /**< bit:     17  Wake-up Input Type 1                     */
    uint32_t WKUPT2:1;                  /**< bit:     18  Wake-up Input Type 2                     */
    uint32_t WKUPT3:1;                  /**< bit:     19  Wake-up Input Type 3                     */
    uint32_t WKUPT4:1;                  /**< bit:     20  Wake-up Input Type 4                     */
    uint32_t WKUPT5:1;                  /**< bit:     21  Wake-up Input Type 5                     */
    uint32_t WKUPT6:1;                  /**< bit:     22  Wake-up Input Type 6                     */
    uint32_t WKUPT7:1;                  /**< bit:     23  Wake-up Input Type 7                     */
    uint32_t WKUPT8:1;                  /**< bit:     24  Wake-up Input Type 8                     */
    uint32_t WKUPT9:1;                  /**< bit:     25  Wake-up Input Type 9                     */
    uint32_t WKUPT10:1;                 /**< bit:     26  Wake-up Input Type 10                    */
    uint32_t WKUPT11:1;                 /**< bit:     27  Wake-up Input Type 11                    */
    uint32_t WKUPT12:1;                 /**< bit:     28  Wake-up Input Type 12                    */
    uint32_t WKUPT13:1;                 /**< bit:     29  Wake-up Input Type 13                    */
    uint32_t WKUPT14:1;                 /**< bit:     30  Wake-up Input Type 14                    */
    uint32_t WKUPT15:1;                 /**< bit:     31  Wake-up Input Type 15                    */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t WKUPEN:16;                 /**< bit:  0..15  Wake-up Input Enable x                   */
    uint32_t WKUPT:16;                  /**< bit: 16..31  Wake-up Input Type x5                    */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_WUIR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_WUIR_OFFSET                    (0x10)                                        /**<  (SUPC_WUIR) Supply Controller Wake-up Inputs Register  Offset */

#define SUPC_WUIR_WKUPEN0_Pos               0                                              /**< (SUPC_WUIR) Wake-up Input Enable 0 Position */
#define SUPC_WUIR_WKUPEN0_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN0_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 0 Mask */
#define SUPC_WUIR_WKUPEN0                   SUPC_WUIR_WKUPEN0_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN0_Msk instead */
#define   SUPC_WUIR_WKUPEN0_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN0_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN0_DISABLE           (SUPC_WUIR_WKUPEN0_DISABLE_Val << SUPC_WUIR_WKUPEN0_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN0_ENABLE            (SUPC_WUIR_WKUPEN0_ENABLE_Val << SUPC_WUIR_WKUPEN0_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN1_Pos               1                                              /**< (SUPC_WUIR) Wake-up Input Enable 1 Position */
#define SUPC_WUIR_WKUPEN1_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN1_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 1 Mask */
#define SUPC_WUIR_WKUPEN1                   SUPC_WUIR_WKUPEN1_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN1_Msk instead */
#define   SUPC_WUIR_WKUPEN1_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN1_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN1_DISABLE           (SUPC_WUIR_WKUPEN1_DISABLE_Val << SUPC_WUIR_WKUPEN1_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN1_ENABLE            (SUPC_WUIR_WKUPEN1_ENABLE_Val << SUPC_WUIR_WKUPEN1_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN2_Pos               2                                              /**< (SUPC_WUIR) Wake-up Input Enable 2 Position */
#define SUPC_WUIR_WKUPEN2_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN2_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 2 Mask */
#define SUPC_WUIR_WKUPEN2                   SUPC_WUIR_WKUPEN2_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN2_Msk instead */
#define   SUPC_WUIR_WKUPEN2_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN2_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN2_DISABLE           (SUPC_WUIR_WKUPEN2_DISABLE_Val << SUPC_WUIR_WKUPEN2_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN2_ENABLE            (SUPC_WUIR_WKUPEN2_ENABLE_Val << SUPC_WUIR_WKUPEN2_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN3_Pos               3                                              /**< (SUPC_WUIR) Wake-up Input Enable 3 Position */
#define SUPC_WUIR_WKUPEN3_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN3_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 3 Mask */
#define SUPC_WUIR_WKUPEN3                   SUPC_WUIR_WKUPEN3_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN3_Msk instead */
#define   SUPC_WUIR_WKUPEN3_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN3_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN3_DISABLE           (SUPC_WUIR_WKUPEN3_DISABLE_Val << SUPC_WUIR_WKUPEN3_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN3_ENABLE            (SUPC_WUIR_WKUPEN3_ENABLE_Val << SUPC_WUIR_WKUPEN3_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN4_Pos               4                                              /**< (SUPC_WUIR) Wake-up Input Enable 4 Position */
#define SUPC_WUIR_WKUPEN4_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN4_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 4 Mask */
#define SUPC_WUIR_WKUPEN4                   SUPC_WUIR_WKUPEN4_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN4_Msk instead */
#define   SUPC_WUIR_WKUPEN4_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN4_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN4_DISABLE           (SUPC_WUIR_WKUPEN4_DISABLE_Val << SUPC_WUIR_WKUPEN4_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN4_ENABLE            (SUPC_WUIR_WKUPEN4_ENABLE_Val << SUPC_WUIR_WKUPEN4_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN5_Pos               5                                              /**< (SUPC_WUIR) Wake-up Input Enable 5 Position */
#define SUPC_WUIR_WKUPEN5_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN5_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 5 Mask */
#define SUPC_WUIR_WKUPEN5                   SUPC_WUIR_WKUPEN5_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN5_Msk instead */
#define   SUPC_WUIR_WKUPEN5_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN5_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN5_DISABLE           (SUPC_WUIR_WKUPEN5_DISABLE_Val << SUPC_WUIR_WKUPEN5_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN5_ENABLE            (SUPC_WUIR_WKUPEN5_ENABLE_Val << SUPC_WUIR_WKUPEN5_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN6_Pos               6                                              /**< (SUPC_WUIR) Wake-up Input Enable 6 Position */
#define SUPC_WUIR_WKUPEN6_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN6_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 6 Mask */
#define SUPC_WUIR_WKUPEN6                   SUPC_WUIR_WKUPEN6_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN6_Msk instead */
#define   SUPC_WUIR_WKUPEN6_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN6_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN6_DISABLE           (SUPC_WUIR_WKUPEN6_DISABLE_Val << SUPC_WUIR_WKUPEN6_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN6_ENABLE            (SUPC_WUIR_WKUPEN6_ENABLE_Val << SUPC_WUIR_WKUPEN6_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN7_Pos               7                                              /**< (SUPC_WUIR) Wake-up Input Enable 7 Position */
#define SUPC_WUIR_WKUPEN7_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN7_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 7 Mask */
#define SUPC_WUIR_WKUPEN7                   SUPC_WUIR_WKUPEN7_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN7_Msk instead */
#define   SUPC_WUIR_WKUPEN7_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN7_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN7_DISABLE           (SUPC_WUIR_WKUPEN7_DISABLE_Val << SUPC_WUIR_WKUPEN7_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN7_ENABLE            (SUPC_WUIR_WKUPEN7_ENABLE_Val << SUPC_WUIR_WKUPEN7_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN8_Pos               8                                              /**< (SUPC_WUIR) Wake-up Input Enable 8 Position */
#define SUPC_WUIR_WKUPEN8_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN8_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 8 Mask */
#define SUPC_WUIR_WKUPEN8                   SUPC_WUIR_WKUPEN8_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN8_Msk instead */
#define   SUPC_WUIR_WKUPEN8_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN8_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN8_DISABLE           (SUPC_WUIR_WKUPEN8_DISABLE_Val << SUPC_WUIR_WKUPEN8_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN8_ENABLE            (SUPC_WUIR_WKUPEN8_ENABLE_Val << SUPC_WUIR_WKUPEN8_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN9_Pos               9                                              /**< (SUPC_WUIR) Wake-up Input Enable 9 Position */
#define SUPC_WUIR_WKUPEN9_Msk               (_U_(0x1) << SUPC_WUIR_WKUPEN9_Pos)            /**< (SUPC_WUIR) Wake-up Input Enable 9 Mask */
#define SUPC_WUIR_WKUPEN9                   SUPC_WUIR_WKUPEN9_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN9_Msk instead */
#define   SUPC_WUIR_WKUPEN9_DISABLE_Val     _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN9_ENABLE_Val      _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN9_DISABLE           (SUPC_WUIR_WKUPEN9_DISABLE_Val << SUPC_WUIR_WKUPEN9_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN9_ENABLE            (SUPC_WUIR_WKUPEN9_ENABLE_Val << SUPC_WUIR_WKUPEN9_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN10_Pos              10                                             /**< (SUPC_WUIR) Wake-up Input Enable 10 Position */
#define SUPC_WUIR_WKUPEN10_Msk              (_U_(0x1) << SUPC_WUIR_WKUPEN10_Pos)           /**< (SUPC_WUIR) Wake-up Input Enable 10 Mask */
#define SUPC_WUIR_WKUPEN10                  SUPC_WUIR_WKUPEN10_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN10_Msk instead */
#define   SUPC_WUIR_WKUPEN10_DISABLE_Val    _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN10_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN10_DISABLE          (SUPC_WUIR_WKUPEN10_DISABLE_Val << SUPC_WUIR_WKUPEN10_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN10_ENABLE           (SUPC_WUIR_WKUPEN10_ENABLE_Val << SUPC_WUIR_WKUPEN10_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN11_Pos              11                                             /**< (SUPC_WUIR) Wake-up Input Enable 11 Position */
#define SUPC_WUIR_WKUPEN11_Msk              (_U_(0x1) << SUPC_WUIR_WKUPEN11_Pos)           /**< (SUPC_WUIR) Wake-up Input Enable 11 Mask */
#define SUPC_WUIR_WKUPEN11                  SUPC_WUIR_WKUPEN11_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN11_Msk instead */
#define   SUPC_WUIR_WKUPEN11_DISABLE_Val    _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN11_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN11_DISABLE          (SUPC_WUIR_WKUPEN11_DISABLE_Val << SUPC_WUIR_WKUPEN11_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN11_ENABLE           (SUPC_WUIR_WKUPEN11_ENABLE_Val << SUPC_WUIR_WKUPEN11_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN12_Pos              12                                             /**< (SUPC_WUIR) Wake-up Input Enable 12 Position */
#define SUPC_WUIR_WKUPEN12_Msk              (_U_(0x1) << SUPC_WUIR_WKUPEN12_Pos)           /**< (SUPC_WUIR) Wake-up Input Enable 12 Mask */
#define SUPC_WUIR_WKUPEN12                  SUPC_WUIR_WKUPEN12_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN12_Msk instead */
#define   SUPC_WUIR_WKUPEN12_DISABLE_Val    _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN12_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN12_DISABLE          (SUPC_WUIR_WKUPEN12_DISABLE_Val << SUPC_WUIR_WKUPEN12_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN12_ENABLE           (SUPC_WUIR_WKUPEN12_ENABLE_Val << SUPC_WUIR_WKUPEN12_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN13_Pos              13                                             /**< (SUPC_WUIR) Wake-up Input Enable 13 Position */
#define SUPC_WUIR_WKUPEN13_Msk              (_U_(0x1) << SUPC_WUIR_WKUPEN13_Pos)           /**< (SUPC_WUIR) Wake-up Input Enable 13 Mask */
#define SUPC_WUIR_WKUPEN13                  SUPC_WUIR_WKUPEN13_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN13_Msk instead */
#define   SUPC_WUIR_WKUPEN13_DISABLE_Val    _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN13_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN13_DISABLE          (SUPC_WUIR_WKUPEN13_DISABLE_Val << SUPC_WUIR_WKUPEN13_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN13_ENABLE           (SUPC_WUIR_WKUPEN13_ENABLE_Val << SUPC_WUIR_WKUPEN13_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN14_Pos              14                                             /**< (SUPC_WUIR) Wake-up Input Enable 14 Position */
#define SUPC_WUIR_WKUPEN14_Msk              (_U_(0x1) << SUPC_WUIR_WKUPEN14_Pos)           /**< (SUPC_WUIR) Wake-up Input Enable 14 Mask */
#define SUPC_WUIR_WKUPEN14                  SUPC_WUIR_WKUPEN14_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN14_Msk instead */
#define   SUPC_WUIR_WKUPEN14_DISABLE_Val    _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN14_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN14_DISABLE          (SUPC_WUIR_WKUPEN14_DISABLE_Val << SUPC_WUIR_WKUPEN14_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN14_ENABLE           (SUPC_WUIR_WKUPEN14_ENABLE_Val << SUPC_WUIR_WKUPEN14_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPEN15_Pos              15                                             /**< (SUPC_WUIR) Wake-up Input Enable 15 Position */
#define SUPC_WUIR_WKUPEN15_Msk              (_U_(0x1) << SUPC_WUIR_WKUPEN15_Pos)           /**< (SUPC_WUIR) Wake-up Input Enable 15 Mask */
#define SUPC_WUIR_WKUPEN15                  SUPC_WUIR_WKUPEN15_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPEN15_Msk instead */
#define   SUPC_WUIR_WKUPEN15_DISABLE_Val    _U_(0x0)                                       /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect.  */
#define   SUPC_WUIR_WKUPEN15_ENABLE_Val     _U_(0x1)                                       /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPEN15_DISABLE          (SUPC_WUIR_WKUPEN15_DISABLE_Val << SUPC_WUIR_WKUPEN15_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input has no wake-up effect. Position  */
#define SUPC_WUIR_WKUPEN15_ENABLE           (SUPC_WUIR_WKUPEN15_ENABLE_Val << SUPC_WUIR_WKUPEN15_Pos)  /**< (SUPC_WUIR) The corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT0_Pos                16                                             /**< (SUPC_WUIR) Wake-up Input Type 0 Position */
#define SUPC_WUIR_WKUPT0_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT0_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 0 Mask */
#define SUPC_WUIR_WKUPT0                    SUPC_WUIR_WKUPT0_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT0_Msk instead */
#define   SUPC_WUIR_WKUPT0_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT0_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT0_LOW                (SUPC_WUIR_WKUPT0_LOW_Val << SUPC_WUIR_WKUPT0_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT0_HIGH               (SUPC_WUIR_WKUPT0_HIGH_Val << SUPC_WUIR_WKUPT0_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT1_Pos                17                                             /**< (SUPC_WUIR) Wake-up Input Type 1 Position */
#define SUPC_WUIR_WKUPT1_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT1_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 1 Mask */
#define SUPC_WUIR_WKUPT1                    SUPC_WUIR_WKUPT1_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT1_Msk instead */
#define   SUPC_WUIR_WKUPT1_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT1_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT1_LOW                (SUPC_WUIR_WKUPT1_LOW_Val << SUPC_WUIR_WKUPT1_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT1_HIGH               (SUPC_WUIR_WKUPT1_HIGH_Val << SUPC_WUIR_WKUPT1_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT2_Pos                18                                             /**< (SUPC_WUIR) Wake-up Input Type 2 Position */
#define SUPC_WUIR_WKUPT2_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT2_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 2 Mask */
#define SUPC_WUIR_WKUPT2                    SUPC_WUIR_WKUPT2_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT2_Msk instead */
#define   SUPC_WUIR_WKUPT2_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT2_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT2_LOW                (SUPC_WUIR_WKUPT2_LOW_Val << SUPC_WUIR_WKUPT2_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT2_HIGH               (SUPC_WUIR_WKUPT2_HIGH_Val << SUPC_WUIR_WKUPT2_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT3_Pos                19                                             /**< (SUPC_WUIR) Wake-up Input Type 3 Position */
#define SUPC_WUIR_WKUPT3_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT3_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 3 Mask */
#define SUPC_WUIR_WKUPT3                    SUPC_WUIR_WKUPT3_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT3_Msk instead */
#define   SUPC_WUIR_WKUPT3_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT3_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT3_LOW                (SUPC_WUIR_WKUPT3_LOW_Val << SUPC_WUIR_WKUPT3_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT3_HIGH               (SUPC_WUIR_WKUPT3_HIGH_Val << SUPC_WUIR_WKUPT3_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT4_Pos                20                                             /**< (SUPC_WUIR) Wake-up Input Type 4 Position */
#define SUPC_WUIR_WKUPT4_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT4_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 4 Mask */
#define SUPC_WUIR_WKUPT4                    SUPC_WUIR_WKUPT4_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT4_Msk instead */
#define   SUPC_WUIR_WKUPT4_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT4_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT4_LOW                (SUPC_WUIR_WKUPT4_LOW_Val << SUPC_WUIR_WKUPT4_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT4_HIGH               (SUPC_WUIR_WKUPT4_HIGH_Val << SUPC_WUIR_WKUPT4_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT5_Pos                21                                             /**< (SUPC_WUIR) Wake-up Input Type 5 Position */
#define SUPC_WUIR_WKUPT5_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT5_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 5 Mask */
#define SUPC_WUIR_WKUPT5                    SUPC_WUIR_WKUPT5_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT5_Msk instead */
#define   SUPC_WUIR_WKUPT5_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT5_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT5_LOW                (SUPC_WUIR_WKUPT5_LOW_Val << SUPC_WUIR_WKUPT5_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT5_HIGH               (SUPC_WUIR_WKUPT5_HIGH_Val << SUPC_WUIR_WKUPT5_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT6_Pos                22                                             /**< (SUPC_WUIR) Wake-up Input Type 6 Position */
#define SUPC_WUIR_WKUPT6_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT6_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 6 Mask */
#define SUPC_WUIR_WKUPT6                    SUPC_WUIR_WKUPT6_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT6_Msk instead */
#define   SUPC_WUIR_WKUPT6_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT6_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT6_LOW                (SUPC_WUIR_WKUPT6_LOW_Val << SUPC_WUIR_WKUPT6_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT6_HIGH               (SUPC_WUIR_WKUPT6_HIGH_Val << SUPC_WUIR_WKUPT6_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT7_Pos                23                                             /**< (SUPC_WUIR) Wake-up Input Type 7 Position */
#define SUPC_WUIR_WKUPT7_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT7_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 7 Mask */
#define SUPC_WUIR_WKUPT7                    SUPC_WUIR_WKUPT7_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT7_Msk instead */
#define   SUPC_WUIR_WKUPT7_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT7_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT7_LOW                (SUPC_WUIR_WKUPT7_LOW_Val << SUPC_WUIR_WKUPT7_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT7_HIGH               (SUPC_WUIR_WKUPT7_HIGH_Val << SUPC_WUIR_WKUPT7_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT8_Pos                24                                             /**< (SUPC_WUIR) Wake-up Input Type 8 Position */
#define SUPC_WUIR_WKUPT8_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT8_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 8 Mask */
#define SUPC_WUIR_WKUPT8                    SUPC_WUIR_WKUPT8_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT8_Msk instead */
#define   SUPC_WUIR_WKUPT8_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT8_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT8_LOW                (SUPC_WUIR_WKUPT8_LOW_Val << SUPC_WUIR_WKUPT8_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT8_HIGH               (SUPC_WUIR_WKUPT8_HIGH_Val << SUPC_WUIR_WKUPT8_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT9_Pos                25                                             /**< (SUPC_WUIR) Wake-up Input Type 9 Position */
#define SUPC_WUIR_WKUPT9_Msk                (_U_(0x1) << SUPC_WUIR_WKUPT9_Pos)             /**< (SUPC_WUIR) Wake-up Input Type 9 Mask */
#define SUPC_WUIR_WKUPT9                    SUPC_WUIR_WKUPT9_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT9_Msk instead */
#define   SUPC_WUIR_WKUPT9_LOW_Val          _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT9_HIGH_Val         _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT9_LOW                (SUPC_WUIR_WKUPT9_LOW_Val << SUPC_WUIR_WKUPT9_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT9_HIGH               (SUPC_WUIR_WKUPT9_HIGH_Val << SUPC_WUIR_WKUPT9_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT10_Pos               26                                             /**< (SUPC_WUIR) Wake-up Input Type 10 Position */
#define SUPC_WUIR_WKUPT10_Msk               (_U_(0x1) << SUPC_WUIR_WKUPT10_Pos)            /**< (SUPC_WUIR) Wake-up Input Type 10 Mask */
#define SUPC_WUIR_WKUPT10                   SUPC_WUIR_WKUPT10_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT10_Msk instead */
#define   SUPC_WUIR_WKUPT10_LOW_Val         _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT10_HIGH_Val        _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT10_LOW               (SUPC_WUIR_WKUPT10_LOW_Val << SUPC_WUIR_WKUPT10_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT10_HIGH              (SUPC_WUIR_WKUPT10_HIGH_Val << SUPC_WUIR_WKUPT10_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT11_Pos               27                                             /**< (SUPC_WUIR) Wake-up Input Type 11 Position */
#define SUPC_WUIR_WKUPT11_Msk               (_U_(0x1) << SUPC_WUIR_WKUPT11_Pos)            /**< (SUPC_WUIR) Wake-up Input Type 11 Mask */
#define SUPC_WUIR_WKUPT11                   SUPC_WUIR_WKUPT11_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT11_Msk instead */
#define   SUPC_WUIR_WKUPT11_LOW_Val         _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT11_HIGH_Val        _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT11_LOW               (SUPC_WUIR_WKUPT11_LOW_Val << SUPC_WUIR_WKUPT11_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT11_HIGH              (SUPC_WUIR_WKUPT11_HIGH_Val << SUPC_WUIR_WKUPT11_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT12_Pos               28                                             /**< (SUPC_WUIR) Wake-up Input Type 12 Position */
#define SUPC_WUIR_WKUPT12_Msk               (_U_(0x1) << SUPC_WUIR_WKUPT12_Pos)            /**< (SUPC_WUIR) Wake-up Input Type 12 Mask */
#define SUPC_WUIR_WKUPT12                   SUPC_WUIR_WKUPT12_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT12_Msk instead */
#define   SUPC_WUIR_WKUPT12_LOW_Val         _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT12_HIGH_Val        _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT12_LOW               (SUPC_WUIR_WKUPT12_LOW_Val << SUPC_WUIR_WKUPT12_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT12_HIGH              (SUPC_WUIR_WKUPT12_HIGH_Val << SUPC_WUIR_WKUPT12_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT13_Pos               29                                             /**< (SUPC_WUIR) Wake-up Input Type 13 Position */
#define SUPC_WUIR_WKUPT13_Msk               (_U_(0x1) << SUPC_WUIR_WKUPT13_Pos)            /**< (SUPC_WUIR) Wake-up Input Type 13 Mask */
#define SUPC_WUIR_WKUPT13                   SUPC_WUIR_WKUPT13_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT13_Msk instead */
#define   SUPC_WUIR_WKUPT13_LOW_Val         _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT13_HIGH_Val        _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT13_LOW               (SUPC_WUIR_WKUPT13_LOW_Val << SUPC_WUIR_WKUPT13_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT13_HIGH              (SUPC_WUIR_WKUPT13_HIGH_Val << SUPC_WUIR_WKUPT13_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT14_Pos               30                                             /**< (SUPC_WUIR) Wake-up Input Type 14 Position */
#define SUPC_WUIR_WKUPT14_Msk               (_U_(0x1) << SUPC_WUIR_WKUPT14_Pos)            /**< (SUPC_WUIR) Wake-up Input Type 14 Mask */
#define SUPC_WUIR_WKUPT14                   SUPC_WUIR_WKUPT14_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT14_Msk instead */
#define   SUPC_WUIR_WKUPT14_LOW_Val         _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT14_HIGH_Val        _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT14_LOW               (SUPC_WUIR_WKUPT14_LOW_Val << SUPC_WUIR_WKUPT14_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT14_HIGH              (SUPC_WUIR_WKUPT14_HIGH_Val << SUPC_WUIR_WKUPT14_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT15_Pos               31                                             /**< (SUPC_WUIR) Wake-up Input Type 15 Position */
#define SUPC_WUIR_WKUPT15_Msk               (_U_(0x1) << SUPC_WUIR_WKUPT15_Pos)            /**< (SUPC_WUIR) Wake-up Input Type 15 Mask */
#define SUPC_WUIR_WKUPT15                   SUPC_WUIR_WKUPT15_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_WUIR_WKUPT15_Msk instead */
#define   SUPC_WUIR_WKUPT15_LOW_Val         _U_(0x0)                                       /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define   SUPC_WUIR_WKUPT15_HIGH_Val        _U_(0x1)                                       /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply.  */
#define SUPC_WUIR_WKUPT15_LOW               (SUPC_WUIR_WKUPT15_LOW_Val << SUPC_WUIR_WKUPT15_Pos)  /**< (SUPC_WUIR) A falling edge followed by a low level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_WKUPT15_HIGH              (SUPC_WUIR_WKUPT15_HIGH_Val << SUPC_WUIR_WKUPT15_Pos)  /**< (SUPC_WUIR) A rising edge followed by a high level for a period defined by WKUPDBC on the corresponding wake-up input forces the wake-up of the core power supply. Position  */
#define SUPC_WUIR_MASK                      _U_(0xFFFFFFFF)                                /**< \deprecated (SUPC_WUIR) Register MASK  (Use SUPC_WUIR_Msk instead)  */
#define SUPC_WUIR_Msk                       _U_(0xFFFFFFFF)                                /**< (SUPC_WUIR) Register Mask  */

#define SUPC_WUIR_WKUPEN_Pos                0                                              /**< (SUPC_WUIR Position) Wake-up Input Enable x */
#define SUPC_WUIR_WKUPEN_Msk                (_U_(0xFFFF) << SUPC_WUIR_WKUPEN_Pos)          /**< (SUPC_WUIR Mask) WKUPEN */
#define SUPC_WUIR_WKUPEN(value)             (SUPC_WUIR_WKUPEN_Msk & ((value) << SUPC_WUIR_WKUPEN_Pos))  
#define SUPC_WUIR_WKUPT_Pos                 16                                             /**< (SUPC_WUIR Position) Wake-up Input Type x5 */
#define SUPC_WUIR_WKUPT_Msk                 (_U_(0xFFFF) << SUPC_WUIR_WKUPT_Pos)           /**< (SUPC_WUIR Mask) WKUPT */
#define SUPC_WUIR_WKUPT(value)              (SUPC_WUIR_WKUPT_Msk & ((value) << SUPC_WUIR_WKUPT_Pos))  

/* -------- SUPC_SR : (SUPC Offset: 0x14) (R/ 32) Supply Controller Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t WKUPS:1;                   /**< bit:      1  WKUP Wake-up Status (cleared on read)    */
    uint32_t :1;                        /**< bit:      2  Reserved */
    uint32_t BODRSTS:1;                 /**< bit:      3  Brownout Detector Reset Status (cleared on read) */
    uint32_t SMRSTS:1;                  /**< bit:      4  Supply Monitor Reset Status (cleared on read) */
    uint32_t SMS:1;                     /**< bit:      5  Supply Monitor Status (cleared on read)  */
    uint32_t SMOS:1;                    /**< bit:      6  Supply Monitor Output Status             */
    uint32_t OSCSEL:1;                  /**< bit:      7  32-kHz Oscillator Selection Status       */
    uint32_t :5;                        /**< bit:  8..12  Reserved */
    uint32_t LPDBCS0:1;                 /**< bit:     13  Low-power Debouncer Wake-up Status on WKUP0 (cleared on read) */
    uint32_t LPDBCS1:1;                 /**< bit:     14  Low-power Debouncer Wake-up Status on WKUP1 (cleared on read) */
    uint32_t :1;                        /**< bit:     15  Reserved */
    uint32_t WKUPIS0:1;                 /**< bit:     16  WKUP Input Status 0 (cleared on read)    */
    uint32_t WKUPIS1:1;                 /**< bit:     17  WKUP Input Status 1 (cleared on read)    */
    uint32_t WKUPIS2:1;                 /**< bit:     18  WKUP Input Status 2 (cleared on read)    */
    uint32_t WKUPIS3:1;                 /**< bit:     19  WKUP Input Status 3 (cleared on read)    */
    uint32_t WKUPIS4:1;                 /**< bit:     20  WKUP Input Status 4 (cleared on read)    */
    uint32_t WKUPIS5:1;                 /**< bit:     21  WKUP Input Status 5 (cleared on read)    */
    uint32_t WKUPIS6:1;                 /**< bit:     22  WKUP Input Status 6 (cleared on read)    */
    uint32_t WKUPIS7:1;                 /**< bit:     23  WKUP Input Status 7 (cleared on read)    */
    uint32_t WKUPIS8:1;                 /**< bit:     24  WKUP Input Status 8 (cleared on read)    */
    uint32_t WKUPIS9:1;                 /**< bit:     25  WKUP Input Status 9 (cleared on read)    */
    uint32_t WKUPIS10:1;                /**< bit:     26  WKUP Input Status 10 (cleared on read)   */
    uint32_t WKUPIS11:1;                /**< bit:     27  WKUP Input Status 11 (cleared on read)   */
    uint32_t WKUPIS12:1;                /**< bit:     28  WKUP Input Status 12 (cleared on read)   */
    uint32_t WKUPIS13:1;                /**< bit:     29  WKUP Input Status 13 (cleared on read)   */
    uint32_t WKUPIS14:1;                /**< bit:     30  WKUP Input Status 14 (cleared on read)   */
    uint32_t WKUPIS15:1;                /**< bit:     31  WKUP Input Status 15 (cleared on read)   */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t :13;                       /**< bit:  0..12  Reserved */
    uint32_t LPDBCS:2;                  /**< bit: 13..14  Low-power Debouncer Wake-up Status on WKUPx (cleared on read) */
    uint32_t :1;                        /**< bit:     15  Reserved */
    uint32_t WKUPIS:16;                 /**< bit: 16..31  WKUP Input Status x5 (cleared on read)   */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_SR_OFFSET                      (0x14)                                        /**<  (SUPC_SR) Supply Controller Status Register  Offset */

#define SUPC_SR_WKUPS_Pos                   1                                              /**< (SUPC_SR) WKUP Wake-up Status (cleared on read) Position */
#define SUPC_SR_WKUPS_Msk                   (_U_(0x1) << SUPC_SR_WKUPS_Pos)                /**< (SUPC_SR) WKUP Wake-up Status (cleared on read) Mask */
#define SUPC_SR_WKUPS                       SUPC_SR_WKUPS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPS_Msk instead */
#define   SUPC_SR_WKUPS_NO_Val              _U_(0x0)                                       /**< (SUPC_SR) No wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_WKUPS_PRESENT_Val         _U_(0x1)                                       /**< (SUPC_SR) At least one wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPS_NO                    (SUPC_SR_WKUPS_NO_Val << SUPC_SR_WKUPS_Pos)    /**< (SUPC_SR) No wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPS_PRESENT               (SUPC_SR_WKUPS_PRESENT_Val << SUPC_SR_WKUPS_Pos)  /**< (SUPC_SR) At least one wake-up due to the assertion of the WKUP pins has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_BODRSTS_Pos                 3                                              /**< (SUPC_SR) Brownout Detector Reset Status (cleared on read) Position */
#define SUPC_SR_BODRSTS_Msk                 (_U_(0x1) << SUPC_SR_BODRSTS_Pos)              /**< (SUPC_SR) Brownout Detector Reset Status (cleared on read) Mask */
#define SUPC_SR_BODRSTS                     SUPC_SR_BODRSTS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_BODRSTS_Msk instead */
#define   SUPC_SR_BODRSTS_NO_Val            _U_(0x0)                                       /**< (SUPC_SR) No core brownout rising edge event has been detected since the last read of SUPC_SR.  */
#define   SUPC_SR_BODRSTS_PRESENT_Val       _U_(0x1)                                       /**< (SUPC_SR) At least one brownout output rising edge event has been detected since the last read of SUPC_SR.  */
#define SUPC_SR_BODRSTS_NO                  (SUPC_SR_BODRSTS_NO_Val << SUPC_SR_BODRSTS_Pos)  /**< (SUPC_SR) No core brownout rising edge event has been detected since the last read of SUPC_SR. Position  */
#define SUPC_SR_BODRSTS_PRESENT             (SUPC_SR_BODRSTS_PRESENT_Val << SUPC_SR_BODRSTS_Pos)  /**< (SUPC_SR) At least one brownout output rising edge event has been detected since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMRSTS_Pos                  4                                              /**< (SUPC_SR) Supply Monitor Reset Status (cleared on read) Position */
#define SUPC_SR_SMRSTS_Msk                  (_U_(0x1) << SUPC_SR_SMRSTS_Pos)               /**< (SUPC_SR) Supply Monitor Reset Status (cleared on read) Mask */
#define SUPC_SR_SMRSTS                      SUPC_SR_SMRSTS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_SMRSTS_Msk instead */
#define   SUPC_SR_SMRSTS_NO_Val             _U_(0x0)                                       /**< (SUPC_SR) No supply monitor detection has generated a core reset since the last read of SUPC_SR.  */
#define   SUPC_SR_SMRSTS_PRESENT_Val        _U_(0x1)                                       /**< (SUPC_SR) At least one supply monitor detection has generated a core reset since the last read of SUPC_SR.  */
#define SUPC_SR_SMRSTS_NO                   (SUPC_SR_SMRSTS_NO_Val << SUPC_SR_SMRSTS_Pos)  /**< (SUPC_SR) No supply monitor detection has generated a core reset since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMRSTS_PRESENT              (SUPC_SR_SMRSTS_PRESENT_Val << SUPC_SR_SMRSTS_Pos)  /**< (SUPC_SR) At least one supply monitor detection has generated a core reset since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMS_Pos                     5                                              /**< (SUPC_SR) Supply Monitor Status (cleared on read) Position */
#define SUPC_SR_SMS_Msk                     (_U_(0x1) << SUPC_SR_SMS_Pos)                  /**< (SUPC_SR) Supply Monitor Status (cleared on read) Mask */
#define SUPC_SR_SMS                         SUPC_SR_SMS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_SMS_Msk instead */
#define   SUPC_SR_SMS_NO_Val                _U_(0x0)                                       /**< (SUPC_SR) No supply monitor detection since the last read of SUPC_SR.  */
#define   SUPC_SR_SMS_PRESENT_Val           _U_(0x1)                                       /**< (SUPC_SR) At least one supply monitor detection since the last read of SUPC_SR.  */
#define SUPC_SR_SMS_NO                      (SUPC_SR_SMS_NO_Val << SUPC_SR_SMS_Pos)        /**< (SUPC_SR) No supply monitor detection since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMS_PRESENT                 (SUPC_SR_SMS_PRESENT_Val << SUPC_SR_SMS_Pos)   /**< (SUPC_SR) At least one supply monitor detection since the last read of SUPC_SR. Position  */
#define SUPC_SR_SMOS_Pos                    6                                              /**< (SUPC_SR) Supply Monitor Output Status Position */
#define SUPC_SR_SMOS_Msk                    (_U_(0x1) << SUPC_SR_SMOS_Pos)                 /**< (SUPC_SR) Supply Monitor Output Status Mask */
#define SUPC_SR_SMOS                        SUPC_SR_SMOS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_SMOS_Msk instead */
#define   SUPC_SR_SMOS_HIGH_Val             _U_(0x0)                                       /**< (SUPC_SR) The supply monitor detected VDDIO higher than its threshold at its last measurement.  */
#define   SUPC_SR_SMOS_LOW_Val              _U_(0x1)                                       /**< (SUPC_SR) The supply monitor detected VDDIO lower than its threshold at its last measurement.  */
#define SUPC_SR_SMOS_HIGH                   (SUPC_SR_SMOS_HIGH_Val << SUPC_SR_SMOS_Pos)    /**< (SUPC_SR) The supply monitor detected VDDIO higher than its threshold at its last measurement. Position  */
#define SUPC_SR_SMOS_LOW                    (SUPC_SR_SMOS_LOW_Val << SUPC_SR_SMOS_Pos)     /**< (SUPC_SR) The supply monitor detected VDDIO lower than its threshold at its last measurement. Position  */
#define SUPC_SR_OSCSEL_Pos                  7                                              /**< (SUPC_SR) 32-kHz Oscillator Selection Status Position */
#define SUPC_SR_OSCSEL_Msk                  (_U_(0x1) << SUPC_SR_OSCSEL_Pos)               /**< (SUPC_SR) 32-kHz Oscillator Selection Status Mask */
#define SUPC_SR_OSCSEL                      SUPC_SR_OSCSEL_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_OSCSEL_Msk instead */
#define   SUPC_SR_OSCSEL_RC_Val             _U_(0x0)                                       /**< (SUPC_SR) The slow clock SLCK is generated by the embedded 32 kHz RC oscillator.  */
#define   SUPC_SR_OSCSEL_CRYST_Val          _U_(0x1)                                       /**< (SUPC_SR) The slow clock SLCK is generated by the 32 kHz crystal oscillator.  */
#define SUPC_SR_OSCSEL_RC                   (SUPC_SR_OSCSEL_RC_Val << SUPC_SR_OSCSEL_Pos)  /**< (SUPC_SR) The slow clock SLCK is generated by the embedded 32 kHz RC oscillator. Position  */
#define SUPC_SR_OSCSEL_CRYST                (SUPC_SR_OSCSEL_CRYST_Val << SUPC_SR_OSCSEL_Pos)  /**< (SUPC_SR) The slow clock SLCK is generated by the 32 kHz crystal oscillator. Position  */
#define SUPC_SR_LPDBCS0_Pos                 13                                             /**< (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP0 (cleared on read) Position */
#define SUPC_SR_LPDBCS0_Msk                 (_U_(0x1) << SUPC_SR_LPDBCS0_Pos)              /**< (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP0 (cleared on read) Mask */
#define SUPC_SR_LPDBCS0                     SUPC_SR_LPDBCS0_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_LPDBCS0_Msk instead */
#define   SUPC_SR_LPDBCS0_NO_Val            _U_(0x0)                                       /**< (SUPC_SR) No wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_LPDBCS0_PRESENT_Val       _U_(0x1)                                       /**< (SUPC_SR) At least one wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_LPDBCS0_NO                  (SUPC_SR_LPDBCS0_NO_Val << SUPC_SR_LPDBCS0_Pos)  /**< (SUPC_SR) No wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_LPDBCS0_PRESENT             (SUPC_SR_LPDBCS0_PRESENT_Val << SUPC_SR_LPDBCS0_Pos)  /**< (SUPC_SR) At least one wake-up due to the assertion of the WKUP0 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_LPDBCS1_Pos                 14                                             /**< (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP1 (cleared on read) Position */
#define SUPC_SR_LPDBCS1_Msk                 (_U_(0x1) << SUPC_SR_LPDBCS1_Pos)              /**< (SUPC_SR) Low-power Debouncer Wake-up Status on WKUP1 (cleared on read) Mask */
#define SUPC_SR_LPDBCS1                     SUPC_SR_LPDBCS1_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_LPDBCS1_Msk instead */
#define   SUPC_SR_LPDBCS1_NO_Val            _U_(0x0)                                       /**< (SUPC_SR) No wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR.  */
#define   SUPC_SR_LPDBCS1_PRESENT_Val       _U_(0x1)                                       /**< (SUPC_SR) At least one wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR.  */
#define SUPC_SR_LPDBCS1_NO                  (SUPC_SR_LPDBCS1_NO_Val << SUPC_SR_LPDBCS1_Pos)  /**< (SUPC_SR) No wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_LPDBCS1_PRESENT             (SUPC_SR_LPDBCS1_PRESENT_Val << SUPC_SR_LPDBCS1_Pos)  /**< (SUPC_SR) At least one wake-up due to the assertion of the WKUP1 pin has occurred since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS0_Pos                 16                                             /**< (SUPC_SR) WKUP Input Status 0 (cleared on read) Position */
#define SUPC_SR_WKUPIS0_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS0_Pos)              /**< (SUPC_SR) WKUP Input Status 0 (cleared on read) Mask */
#define SUPC_SR_WKUPIS0                     SUPC_SR_WKUPIS0_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS0_Msk instead */
#define   SUPC_SR_WKUPIS0_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS0_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS0_DISABLED            (SUPC_SR_WKUPIS0_DISABLED_Val << SUPC_SR_WKUPIS0_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS0_ENABLED             (SUPC_SR_WKUPIS0_ENABLED_Val << SUPC_SR_WKUPIS0_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS1_Pos                 17                                             /**< (SUPC_SR) WKUP Input Status 1 (cleared on read) Position */
#define SUPC_SR_WKUPIS1_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS1_Pos)              /**< (SUPC_SR) WKUP Input Status 1 (cleared on read) Mask */
#define SUPC_SR_WKUPIS1                     SUPC_SR_WKUPIS1_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS1_Msk instead */
#define   SUPC_SR_WKUPIS1_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS1_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS1_DISABLED            (SUPC_SR_WKUPIS1_DISABLED_Val << SUPC_SR_WKUPIS1_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS1_ENABLED             (SUPC_SR_WKUPIS1_ENABLED_Val << SUPC_SR_WKUPIS1_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS2_Pos                 18                                             /**< (SUPC_SR) WKUP Input Status 2 (cleared on read) Position */
#define SUPC_SR_WKUPIS2_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS2_Pos)              /**< (SUPC_SR) WKUP Input Status 2 (cleared on read) Mask */
#define SUPC_SR_WKUPIS2                     SUPC_SR_WKUPIS2_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS2_Msk instead */
#define   SUPC_SR_WKUPIS2_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS2_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS2_DISABLED            (SUPC_SR_WKUPIS2_DISABLED_Val << SUPC_SR_WKUPIS2_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS2_ENABLED             (SUPC_SR_WKUPIS2_ENABLED_Val << SUPC_SR_WKUPIS2_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS3_Pos                 19                                             /**< (SUPC_SR) WKUP Input Status 3 (cleared on read) Position */
#define SUPC_SR_WKUPIS3_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS3_Pos)              /**< (SUPC_SR) WKUP Input Status 3 (cleared on read) Mask */
#define SUPC_SR_WKUPIS3                     SUPC_SR_WKUPIS3_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS3_Msk instead */
#define   SUPC_SR_WKUPIS3_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS3_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS3_DISABLED            (SUPC_SR_WKUPIS3_DISABLED_Val << SUPC_SR_WKUPIS3_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS3_ENABLED             (SUPC_SR_WKUPIS3_ENABLED_Val << SUPC_SR_WKUPIS3_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS4_Pos                 20                                             /**< (SUPC_SR) WKUP Input Status 4 (cleared on read) Position */
#define SUPC_SR_WKUPIS4_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS4_Pos)              /**< (SUPC_SR) WKUP Input Status 4 (cleared on read) Mask */
#define SUPC_SR_WKUPIS4                     SUPC_SR_WKUPIS4_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS4_Msk instead */
#define   SUPC_SR_WKUPIS4_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS4_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS4_DISABLED            (SUPC_SR_WKUPIS4_DISABLED_Val << SUPC_SR_WKUPIS4_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS4_ENABLED             (SUPC_SR_WKUPIS4_ENABLED_Val << SUPC_SR_WKUPIS4_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS5_Pos                 21                                             /**< (SUPC_SR) WKUP Input Status 5 (cleared on read) Position */
#define SUPC_SR_WKUPIS5_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS5_Pos)              /**< (SUPC_SR) WKUP Input Status 5 (cleared on read) Mask */
#define SUPC_SR_WKUPIS5                     SUPC_SR_WKUPIS5_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS5_Msk instead */
#define   SUPC_SR_WKUPIS5_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS5_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS5_DISABLED            (SUPC_SR_WKUPIS5_DISABLED_Val << SUPC_SR_WKUPIS5_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS5_ENABLED             (SUPC_SR_WKUPIS5_ENABLED_Val << SUPC_SR_WKUPIS5_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS6_Pos                 22                                             /**< (SUPC_SR) WKUP Input Status 6 (cleared on read) Position */
#define SUPC_SR_WKUPIS6_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS6_Pos)              /**< (SUPC_SR) WKUP Input Status 6 (cleared on read) Mask */
#define SUPC_SR_WKUPIS6                     SUPC_SR_WKUPIS6_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS6_Msk instead */
#define   SUPC_SR_WKUPIS6_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS6_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS6_DISABLED            (SUPC_SR_WKUPIS6_DISABLED_Val << SUPC_SR_WKUPIS6_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS6_ENABLED             (SUPC_SR_WKUPIS6_ENABLED_Val << SUPC_SR_WKUPIS6_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS7_Pos                 23                                             /**< (SUPC_SR) WKUP Input Status 7 (cleared on read) Position */
#define SUPC_SR_WKUPIS7_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS7_Pos)              /**< (SUPC_SR) WKUP Input Status 7 (cleared on read) Mask */
#define SUPC_SR_WKUPIS7                     SUPC_SR_WKUPIS7_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS7_Msk instead */
#define   SUPC_SR_WKUPIS7_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS7_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS7_DISABLED            (SUPC_SR_WKUPIS7_DISABLED_Val << SUPC_SR_WKUPIS7_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS7_ENABLED             (SUPC_SR_WKUPIS7_ENABLED_Val << SUPC_SR_WKUPIS7_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS8_Pos                 24                                             /**< (SUPC_SR) WKUP Input Status 8 (cleared on read) Position */
#define SUPC_SR_WKUPIS8_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS8_Pos)              /**< (SUPC_SR) WKUP Input Status 8 (cleared on read) Mask */
#define SUPC_SR_WKUPIS8                     SUPC_SR_WKUPIS8_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS8_Msk instead */
#define   SUPC_SR_WKUPIS8_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS8_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS8_DISABLED            (SUPC_SR_WKUPIS8_DISABLED_Val << SUPC_SR_WKUPIS8_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS8_ENABLED             (SUPC_SR_WKUPIS8_ENABLED_Val << SUPC_SR_WKUPIS8_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS9_Pos                 25                                             /**< (SUPC_SR) WKUP Input Status 9 (cleared on read) Position */
#define SUPC_SR_WKUPIS9_Msk                 (_U_(0x1) << SUPC_SR_WKUPIS9_Pos)              /**< (SUPC_SR) WKUP Input Status 9 (cleared on read) Mask */
#define SUPC_SR_WKUPIS9                     SUPC_SR_WKUPIS9_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS9_Msk instead */
#define   SUPC_SR_WKUPIS9_DISABLED_Val      _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS9_ENABLED_Val       _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS9_DISABLED            (SUPC_SR_WKUPIS9_DISABLED_Val << SUPC_SR_WKUPIS9_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS9_ENABLED             (SUPC_SR_WKUPIS9_ENABLED_Val << SUPC_SR_WKUPIS9_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS10_Pos                26                                             /**< (SUPC_SR) WKUP Input Status 10 (cleared on read) Position */
#define SUPC_SR_WKUPIS10_Msk                (_U_(0x1) << SUPC_SR_WKUPIS10_Pos)             /**< (SUPC_SR) WKUP Input Status 10 (cleared on read) Mask */
#define SUPC_SR_WKUPIS10                    SUPC_SR_WKUPIS10_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS10_Msk instead */
#define   SUPC_SR_WKUPIS10_DISABLED_Val     _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS10_ENABLED_Val      _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS10_DISABLED           (SUPC_SR_WKUPIS10_DISABLED_Val << SUPC_SR_WKUPIS10_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS10_ENABLED            (SUPC_SR_WKUPIS10_ENABLED_Val << SUPC_SR_WKUPIS10_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS11_Pos                27                                             /**< (SUPC_SR) WKUP Input Status 11 (cleared on read) Position */
#define SUPC_SR_WKUPIS11_Msk                (_U_(0x1) << SUPC_SR_WKUPIS11_Pos)             /**< (SUPC_SR) WKUP Input Status 11 (cleared on read) Mask */
#define SUPC_SR_WKUPIS11                    SUPC_SR_WKUPIS11_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS11_Msk instead */
#define   SUPC_SR_WKUPIS11_DISABLED_Val     _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS11_ENABLED_Val      _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS11_DISABLED           (SUPC_SR_WKUPIS11_DISABLED_Val << SUPC_SR_WKUPIS11_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS11_ENABLED            (SUPC_SR_WKUPIS11_ENABLED_Val << SUPC_SR_WKUPIS11_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS12_Pos                28                                             /**< (SUPC_SR) WKUP Input Status 12 (cleared on read) Position */
#define SUPC_SR_WKUPIS12_Msk                (_U_(0x1) << SUPC_SR_WKUPIS12_Pos)             /**< (SUPC_SR) WKUP Input Status 12 (cleared on read) Mask */
#define SUPC_SR_WKUPIS12                    SUPC_SR_WKUPIS12_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS12_Msk instead */
#define   SUPC_SR_WKUPIS12_DISABLED_Val     _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS12_ENABLED_Val      _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS12_DISABLED           (SUPC_SR_WKUPIS12_DISABLED_Val << SUPC_SR_WKUPIS12_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS12_ENABLED            (SUPC_SR_WKUPIS12_ENABLED_Val << SUPC_SR_WKUPIS12_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS13_Pos                29                                             /**< (SUPC_SR) WKUP Input Status 13 (cleared on read) Position */
#define SUPC_SR_WKUPIS13_Msk                (_U_(0x1) << SUPC_SR_WKUPIS13_Pos)             /**< (SUPC_SR) WKUP Input Status 13 (cleared on read) Mask */
#define SUPC_SR_WKUPIS13                    SUPC_SR_WKUPIS13_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS13_Msk instead */
#define   SUPC_SR_WKUPIS13_DISABLED_Val     _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS13_ENABLED_Val      _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS13_DISABLED           (SUPC_SR_WKUPIS13_DISABLED_Val << SUPC_SR_WKUPIS13_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS13_ENABLED            (SUPC_SR_WKUPIS13_ENABLED_Val << SUPC_SR_WKUPIS13_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS14_Pos                30                                             /**< (SUPC_SR) WKUP Input Status 14 (cleared on read) Position */
#define SUPC_SR_WKUPIS14_Msk                (_U_(0x1) << SUPC_SR_WKUPIS14_Pos)             /**< (SUPC_SR) WKUP Input Status 14 (cleared on read) Mask */
#define SUPC_SR_WKUPIS14                    SUPC_SR_WKUPIS14_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS14_Msk instead */
#define   SUPC_SR_WKUPIS14_DISABLED_Val     _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS14_ENABLED_Val      _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS14_DISABLED           (SUPC_SR_WKUPIS14_DISABLED_Val << SUPC_SR_WKUPIS14_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS14_ENABLED            (SUPC_SR_WKUPIS14_ENABLED_Val << SUPC_SR_WKUPIS14_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_WKUPIS15_Pos                31                                             /**< (SUPC_SR) WKUP Input Status 15 (cleared on read) Position */
#define SUPC_SR_WKUPIS15_Msk                (_U_(0x1) << SUPC_SR_WKUPIS15_Pos)             /**< (SUPC_SR) WKUP Input Status 15 (cleared on read) Mask */
#define SUPC_SR_WKUPIS15                    SUPC_SR_WKUPIS15_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_SR_WKUPIS15_Msk instead */
#define   SUPC_SR_WKUPIS15_DISABLED_Val     _U_(0x0)                                       /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event.  */
#define   SUPC_SR_WKUPIS15_ENABLED_Val      _U_(0x1)                                       /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR.  */
#define SUPC_SR_WKUPIS15_DISABLED           (SUPC_SR_WKUPIS15_DISABLED_Val << SUPC_SR_WKUPIS15_Pos)  /**< (SUPC_SR) The corresponding wake-up input is disabled, or was inactive at the time the debouncer triggered a wake-up event. Position  */
#define SUPC_SR_WKUPIS15_ENABLED            (SUPC_SR_WKUPIS15_ENABLED_Val << SUPC_SR_WKUPIS15_Pos)  /**< (SUPC_SR) The corresponding wake-up input was active at the time the debouncer triggered a wake-up event since the last read of SUPC_SR. Position  */
#define SUPC_SR_MASK                        _U_(0xFFFF60FA)                                /**< \deprecated (SUPC_SR) Register MASK  (Use SUPC_SR_Msk instead)  */
#define SUPC_SR_Msk                         _U_(0xFFFF60FA)                                /**< (SUPC_SR) Register Mask  */

#define SUPC_SR_LPDBCS_Pos                  13                                             /**< (SUPC_SR Position) Low-power Debouncer Wake-up Status on WKUPx (cleared on read) */
#define SUPC_SR_LPDBCS_Msk                  (_U_(0x3) << SUPC_SR_LPDBCS_Pos)               /**< (SUPC_SR Mask) LPDBCS */
#define SUPC_SR_LPDBCS(value)               (SUPC_SR_LPDBCS_Msk & ((value) << SUPC_SR_LPDBCS_Pos))  
#define SUPC_SR_WKUPIS_Pos                  16                                             /**< (SUPC_SR Position) WKUP Input Status x5 (cleared on read) */
#define SUPC_SR_WKUPIS_Msk                  (_U_(0xFFFF) << SUPC_SR_WKUPIS_Pos)            /**< (SUPC_SR Mask) WKUPIS */
#define SUPC_SR_WKUPIS(value)               (SUPC_SR_WKUPIS_Msk & ((value) << SUPC_SR_WKUPIS_Pos))  

/* -------- SUPC_PWMR : (SUPC Offset: 0x1c) (R/W 32) Supply Controller Power Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t LPOWERS:1;                 /**< bit:      0  Low Power Value Selection                */
    uint32_t LPOWER0:1;                 /**< bit:      1  Low Power Value                          */
    uint32_t LPOWER1:1;                 /**< bit:      2  Low Power Value                          */
    uint32_t LPOWER2:1;                 /**< bit:      3  Low Power Value                          */
    uint32_t LPOWER3:1;                 /**< bit:      4  Low Power Value                          */
    uint32_t :2;                        /**< bit:   5..6  Reserved */
    uint32_t STUPTIME:1;                /**< bit:      7  Start-up Time when Resuming from Wait Mode */
    uint32_t ECPWRS:1;                  /**< bit:      8  Enhanced Custom Power Value Selection    */
    uint32_t ECPWR0:1;                  /**< bit:      9  Enhanced Custom Power Value              */
    uint32_t ECPWR1:1;                  /**< bit:     10  Enhanced Custom Power Value              */
    uint32_t ECPWR2:1;                  /**< bit:     11  Enhanced Custom Power Value              */
    uint32_t ECPWR3:1;                  /**< bit:     12  Enhanced Custom Power Value              */
    uint32_t :3;                        /**< bit: 13..15  Reserved */
    uint32_t SRAM0ON:1;                 /**< bit:     16  SRAM Power Control                       */
    uint32_t SRAM1ON:1;                 /**< bit:     17  SRAM Power Control                       */
    uint32_t SRAM2ON:1;                 /**< bit:     18  SRAM Power Control                       */
    uint32_t SRAM3ON:1;                 /**< bit:     19  SRAM Power Control                       */
    uint32_t SRAM4ON:1;                 /**< bit:     20  SRAM Power Control                       */
    uint32_t SRAM5ON:1;                 /**< bit:     21  SRAM Power Control                       */
    uint32_t SRAM6ON:1;                 /**< bit:     22  SRAM Power Control                       */
    uint32_t DPRAMON:1;                 /**< bit:     23  Dual-port RAM Power Control              */
    uint32_t KEY:8;                     /**< bit: 24..31  Password Key                             */
  } bit;                                /**< Structure used for bit  access */
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t LPOWER:4;                  /**< bit:   1..4  Low Power Value                          */
    uint32_t :4;                        /**< bit:   5..8  Reserved */
    uint32_t ECPWR:4;                   /**< bit:  9..12  Enhanced Custom Power Value              */
    uint32_t :19;                       /**< bit: 13..31 Reserved */
  } vec;                                /**< Structure used for vec  access  */
  uint32_t reg;                         /**< Type used for register access */
} SUPC_PWMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SUPC_PWMR_OFFSET                    (0x1C)                                        /**<  (SUPC_PWMR) Supply Controller Power Mode Register  Offset */

#define SUPC_PWMR_LPOWERS_Pos               0                                              /**< (SUPC_PWMR) Low Power Value Selection Position */
#define SUPC_PWMR_LPOWERS_Msk               (_U_(0x1) << SUPC_PWMR_LPOWERS_Pos)            /**< (SUPC_PWMR) Low Power Value Selection Mask */
#define SUPC_PWMR_LPOWERS                   SUPC_PWMR_LPOWERS_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_LPOWERS_Msk instead */
#define   SUPC_PWMR_LPOWERS_FACTORY_Val     _U_(0x0)                                       /**< (SUPC_PWMR) The trimming value applied to the regulator when the device is in Wait mode. This value is factory-defined.  */
#define   SUPC_PWMR_LPOWERS_USER_Val        _U_(0x1)                                       /**< (SUPC_PWMR) The trimming value applied to the regulator is defined by the value programmed in the LPOWERx bits.  */
#define SUPC_PWMR_LPOWERS_FACTORY           (SUPC_PWMR_LPOWERS_FACTORY_Val << SUPC_PWMR_LPOWERS_Pos)  /**< (SUPC_PWMR) The trimming value applied to the regulator when the device is in Wait mode. This value is factory-defined. Position  */
#define SUPC_PWMR_LPOWERS_USER              (SUPC_PWMR_LPOWERS_USER_Val << SUPC_PWMR_LPOWERS_Pos)  /**< (SUPC_PWMR) The trimming value applied to the regulator is defined by the value programmed in the LPOWERx bits. Position  */
#define SUPC_PWMR_LPOWER0_Pos               1                                              /**< (SUPC_PWMR) Low Power Value Position */
#define SUPC_PWMR_LPOWER0_Msk               (_U_(0x1) << SUPC_PWMR_LPOWER0_Pos)            /**< (SUPC_PWMR) Low Power Value Mask */
#define SUPC_PWMR_LPOWER0                   SUPC_PWMR_LPOWER0_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_LPOWER0_Msk instead */
#define SUPC_PWMR_LPOWER1_Pos               2                                              /**< (SUPC_PWMR) Low Power Value Position */
#define SUPC_PWMR_LPOWER1_Msk               (_U_(0x1) << SUPC_PWMR_LPOWER1_Pos)            /**< (SUPC_PWMR) Low Power Value Mask */
#define SUPC_PWMR_LPOWER1                   SUPC_PWMR_LPOWER1_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_LPOWER1_Msk instead */
#define SUPC_PWMR_LPOWER2_Pos               3                                              /**< (SUPC_PWMR) Low Power Value Position */
#define SUPC_PWMR_LPOWER2_Msk               (_U_(0x1) << SUPC_PWMR_LPOWER2_Pos)            /**< (SUPC_PWMR) Low Power Value Mask */
#define SUPC_PWMR_LPOWER2                   SUPC_PWMR_LPOWER2_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_LPOWER2_Msk instead */
#define SUPC_PWMR_LPOWER3_Pos               4                                              /**< (SUPC_PWMR) Low Power Value Position */
#define SUPC_PWMR_LPOWER3_Msk               (_U_(0x1) << SUPC_PWMR_LPOWER3_Pos)            /**< (SUPC_PWMR) Low Power Value Mask */
#define SUPC_PWMR_LPOWER3                   SUPC_PWMR_LPOWER3_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_LPOWER3_Msk instead */
#define SUPC_PWMR_STUPTIME_Pos              7                                              /**< (SUPC_PWMR) Start-up Time when Resuming from Wait Mode Position */
#define SUPC_PWMR_STUPTIME_Msk              (_U_(0x1) << SUPC_PWMR_STUPTIME_Pos)           /**< (SUPC_PWMR) Start-up Time when Resuming from Wait Mode Mask */
#define SUPC_PWMR_STUPTIME                  SUPC_PWMR_STUPTIME_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_STUPTIME_Msk instead */
#define   SUPC_PWMR_STUPTIME_FAST_Val       _U_(0x0)                                       /**< (SUPC_PWMR) Fast start-up.  */
#define   SUPC_PWMR_STUPTIME_SLOW_Val       _U_(0x1)                                       /**< (SUPC_PWMR) Slow start-up.  */
#define SUPC_PWMR_STUPTIME_FAST             (SUPC_PWMR_STUPTIME_FAST_Val << SUPC_PWMR_STUPTIME_Pos)  /**< (SUPC_PWMR) Fast start-up. Position  */
#define SUPC_PWMR_STUPTIME_SLOW             (SUPC_PWMR_STUPTIME_SLOW_Val << SUPC_PWMR_STUPTIME_Pos)  /**< (SUPC_PWMR) Slow start-up. Position  */
#define SUPC_PWMR_ECPWRS_Pos                8                                              /**< (SUPC_PWMR) Enhanced Custom Power Value Selection Position */
#define SUPC_PWMR_ECPWRS_Msk                (_U_(0x1) << SUPC_PWMR_ECPWRS_Pos)             /**< (SUPC_PWMR) Enhanced Custom Power Value Selection Mask */
#define SUPC_PWMR_ECPWRS                    SUPC_PWMR_ECPWRS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_ECPWRS_Msk instead */
#define   SUPC_PWMR_ECPWRS_FACTORY_Val      _U_(0x0)                                       /**< (SUPC_PWMR) The trimming value applied to the regulator when the device is in Active mode. This value is factory-defined.  */
#define   SUPC_PWMR_ECPWRS_USER_Val         _U_(0x1)                                       /**< (SUPC_PWMR) The trimming value applied to the regulator is defined by the value programmed in ECPWRx bits.  */
#define SUPC_PWMR_ECPWRS_FACTORY            (SUPC_PWMR_ECPWRS_FACTORY_Val << SUPC_PWMR_ECPWRS_Pos)  /**< (SUPC_PWMR) The trimming value applied to the regulator when the device is in Active mode. This value is factory-defined. Position  */
#define SUPC_PWMR_ECPWRS_USER               (SUPC_PWMR_ECPWRS_USER_Val << SUPC_PWMR_ECPWRS_Pos)  /**< (SUPC_PWMR) The trimming value applied to the regulator is defined by the value programmed in ECPWRx bits. Position  */
#define SUPC_PWMR_ECPWR0_Pos                9                                              /**< (SUPC_PWMR) Enhanced Custom Power Value Position */
#define SUPC_PWMR_ECPWR0_Msk                (_U_(0x1) << SUPC_PWMR_ECPWR0_Pos)             /**< (SUPC_PWMR) Enhanced Custom Power Value Mask */
#define SUPC_PWMR_ECPWR0                    SUPC_PWMR_ECPWR0_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_ECPWR0_Msk instead */
#define SUPC_PWMR_ECPWR1_Pos                10                                             /**< (SUPC_PWMR) Enhanced Custom Power Value Position */
#define SUPC_PWMR_ECPWR1_Msk                (_U_(0x1) << SUPC_PWMR_ECPWR1_Pos)             /**< (SUPC_PWMR) Enhanced Custom Power Value Mask */
#define SUPC_PWMR_ECPWR1                    SUPC_PWMR_ECPWR1_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_ECPWR1_Msk instead */
#define SUPC_PWMR_ECPWR2_Pos                11                                             /**< (SUPC_PWMR) Enhanced Custom Power Value Position */
#define SUPC_PWMR_ECPWR2_Msk                (_U_(0x1) << SUPC_PWMR_ECPWR2_Pos)             /**< (SUPC_PWMR) Enhanced Custom Power Value Mask */
#define SUPC_PWMR_ECPWR2                    SUPC_PWMR_ECPWR2_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_ECPWR2_Msk instead */
#define SUPC_PWMR_ECPWR3_Pos                12                                             /**< (SUPC_PWMR) Enhanced Custom Power Value Position */
#define SUPC_PWMR_ECPWR3_Msk                (_U_(0x1) << SUPC_PWMR_ECPWR3_Pos)             /**< (SUPC_PWMR) Enhanced Custom Power Value Mask */
#define SUPC_PWMR_ECPWR3                    SUPC_PWMR_ECPWR3_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_ECPWR3_Msk instead */
#define SUPC_PWMR_SRAM0ON_Pos               16                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM0ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM0ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM0ON                   SUPC_PWMR_SRAM0ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM0ON_Msk instead */
#define   SUPC_PWMR_SRAM0ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM0ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM0ON_OFF               (SUPC_PWMR_SRAM0ON_OFF_Val << SUPC_PWMR_SRAM0ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM0ON_ON                (SUPC_PWMR_SRAM0ON_ON_Val << SUPC_PWMR_SRAM0ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_SRAM1ON_Pos               17                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM1ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM1ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM1ON                   SUPC_PWMR_SRAM1ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM1ON_Msk instead */
#define   SUPC_PWMR_SRAM1ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM1ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM1ON_OFF               (SUPC_PWMR_SRAM1ON_OFF_Val << SUPC_PWMR_SRAM1ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM1ON_ON                (SUPC_PWMR_SRAM1ON_ON_Val << SUPC_PWMR_SRAM1ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_SRAM2ON_Pos               18                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM2ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM2ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM2ON                   SUPC_PWMR_SRAM2ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM2ON_Msk instead */
#define   SUPC_PWMR_SRAM2ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM2ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM2ON_OFF               (SUPC_PWMR_SRAM2ON_OFF_Val << SUPC_PWMR_SRAM2ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM2ON_ON                (SUPC_PWMR_SRAM2ON_ON_Val << SUPC_PWMR_SRAM2ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_SRAM3ON_Pos               19                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM3ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM3ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM3ON                   SUPC_PWMR_SRAM3ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM3ON_Msk instead */
#define   SUPC_PWMR_SRAM3ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM3ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM3ON_OFF               (SUPC_PWMR_SRAM3ON_OFF_Val << SUPC_PWMR_SRAM3ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM3ON_ON                (SUPC_PWMR_SRAM3ON_ON_Val << SUPC_PWMR_SRAM3ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_SRAM4ON_Pos               20                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM4ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM4ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM4ON                   SUPC_PWMR_SRAM4ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM4ON_Msk instead */
#define   SUPC_PWMR_SRAM4ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM4ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM4ON_OFF               (SUPC_PWMR_SRAM4ON_OFF_Val << SUPC_PWMR_SRAM4ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM4ON_ON                (SUPC_PWMR_SRAM4ON_ON_Val << SUPC_PWMR_SRAM4ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_SRAM5ON_Pos               21                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM5ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM5ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM5ON                   SUPC_PWMR_SRAM5ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM5ON_Msk instead */
#define   SUPC_PWMR_SRAM5ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM5ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM5ON_OFF               (SUPC_PWMR_SRAM5ON_OFF_Val << SUPC_PWMR_SRAM5ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM5ON_ON                (SUPC_PWMR_SRAM5ON_ON_Val << SUPC_PWMR_SRAM5ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_SRAM6ON_Pos               22                                             /**< (SUPC_PWMR) SRAM Power Control Position */
#define SUPC_PWMR_SRAM6ON_Msk               (_U_(0x1) << SUPC_PWMR_SRAM6ON_Pos)            /**< (SUPC_PWMR) SRAM Power Control Mask */
#define SUPC_PWMR_SRAM6ON                   SUPC_PWMR_SRAM6ON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_SRAM6ON_Msk instead */
#define   SUPC_PWMR_SRAM6ON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) SRAMx is not powered.  */
#define   SUPC_PWMR_SRAM6ON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) SRAMx is powered.  */
#define SUPC_PWMR_SRAM6ON_OFF               (SUPC_PWMR_SRAM6ON_OFF_Val << SUPC_PWMR_SRAM6ON_Pos)  /**< (SUPC_PWMR) SRAMx is not powered. Position  */
#define SUPC_PWMR_SRAM6ON_ON                (SUPC_PWMR_SRAM6ON_ON_Val << SUPC_PWMR_SRAM6ON_Pos)  /**< (SUPC_PWMR) SRAMx is powered. Position  */
#define SUPC_PWMR_DPRAMON_Pos               23                                             /**< (SUPC_PWMR) Dual-port RAM Power Control Position */
#define SUPC_PWMR_DPRAMON_Msk               (_U_(0x1) << SUPC_PWMR_DPRAMON_Pos)            /**< (SUPC_PWMR) Dual-port RAM Power Control Mask */
#define SUPC_PWMR_DPRAMON                   SUPC_PWMR_DPRAMON_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use SUPC_PWMR_DPRAMON_Msk instead */
#define   SUPC_PWMR_DPRAMON_OFF_Val         _U_(0x0)                                       /**< (SUPC_PWMR) USB dual-port RAM is not powered.  */
#define   SUPC_PWMR_DPRAMON_ON_Val          _U_(0x1)                                       /**< (SUPC_PWMR) USB dual-port RAM is powered.  */
#define SUPC_PWMR_DPRAMON_OFF               (SUPC_PWMR_DPRAMON_OFF_Val << SUPC_PWMR_DPRAMON_Pos)  /**< (SUPC_PWMR) USB dual-port RAM is not powered. Position  */
#define SUPC_PWMR_DPRAMON_ON                (SUPC_PWMR_DPRAMON_ON_Val << SUPC_PWMR_DPRAMON_Pos)  /**< (SUPC_PWMR) USB dual-port RAM is powered. Position  */
#define SUPC_PWMR_KEY_Pos                   24                                             /**< (SUPC_PWMR) Password Key Position */
#define SUPC_PWMR_KEY_Msk                   (_U_(0xFF) << SUPC_PWMR_KEY_Pos)               /**< (SUPC_PWMR) Password Key Mask */
#define SUPC_PWMR_KEY(value)                (SUPC_PWMR_KEY_Msk & ((value) << SUPC_PWMR_KEY_Pos))
#define   SUPC_PWMR_KEY_PASSWD_Val          _U_(0x5A)                                      /**< (SUPC_PWMR) Writing any other value in this field aborts the write operation.Always reads as 0.  */
#define SUPC_PWMR_KEY_PASSWD                (SUPC_PWMR_KEY_PASSWD_Val << SUPC_PWMR_KEY_Pos)  /**< (SUPC_PWMR) Writing any other value in this field aborts the write operation.Always reads as 0. Position  */
#define SUPC_PWMR_MASK                      _U_(0xFFFF1F9F)                                /**< \deprecated (SUPC_PWMR) Register MASK  (Use SUPC_PWMR_Msk instead)  */
#define SUPC_PWMR_Msk                       _U_(0xFFFF1F9F)                                /**< (SUPC_PWMR) Register Mask  */

#define SUPC_PWMR_LPOWER_Pos                1                                              /**< (SUPC_PWMR Position) Low Power Value */
#define SUPC_PWMR_LPOWER_Msk                (_U_(0xF) << SUPC_PWMR_LPOWER_Pos)             /**< (SUPC_PWMR Mask) LPOWER */
#define SUPC_PWMR_LPOWER(value)             (SUPC_PWMR_LPOWER_Msk & ((value) << SUPC_PWMR_LPOWER_Pos))  
#define SUPC_PWMR_ECPWR_Pos                 9                                              /**< (SUPC_PWMR Position) Enhanced Custom Power Value */
#define SUPC_PWMR_ECPWR_Msk                 (_U_(0xF) << SUPC_PWMR_ECPWR_Pos)              /**< (SUPC_PWMR Mask) ECPWR */
#define SUPC_PWMR_ECPWR(value)              (SUPC_PWMR_ECPWR_Msk & ((value) << SUPC_PWMR_ECPWR_Pos))  

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief SUPC hardware registers */
typedef struct {  
  __O  uint32_t SUPC_CR;        /**< (SUPC Offset: 0x00) Supply Controller Control Register */
  __IO uint32_t SUPC_SMMR;      /**< (SUPC Offset: 0x04) Supply Controller Supply Monitor Mode Register */
  __IO uint32_t SUPC_MR;        /**< (SUPC Offset: 0x08) Supply Controller Mode Register */
  __IO uint32_t SUPC_WUMR;      /**< (SUPC Offset: 0x0C) Supply Controller Wake-up Mode Register */
  __IO uint32_t SUPC_WUIR;      /**< (SUPC Offset: 0x10) Supply Controller Wake-up Inputs Register */
  __I  uint32_t SUPC_SR;        /**< (SUPC Offset: 0x14) Supply Controller Status Register */
  RoReg8  Reserved1[0x4];
  __IO uint32_t SUPC_PWMR;      /**< (SUPC Offset: 0x1C) Supply Controller Power Mode Register */
} Supc;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief SUPC hardware registers */
typedef struct {  
  __O  SUPC_CR_Type                   SUPC_CR;        /**< Offset: 0x00 ( /W  32) Supply Controller Control Register */
  __IO SUPC_SMMR_Type                 SUPC_SMMR;      /**< Offset: 0x04 (R/W  32) Supply Controller Supply Monitor Mode Register */
  __IO SUPC_MR_Type                   SUPC_MR;        /**< Offset: 0x08 (R/W  32) Supply Controller Mode Register */
  __IO SUPC_WUMR_Type                 SUPC_WUMR;      /**< Offset: 0x0C (R/W  32) Supply Controller Wake-up Mode Register */
  __IO SUPC_WUIR_Type                 SUPC_WUIR;      /**< Offset: 0x10 (R/W  32) Supply Controller Wake-up Inputs Register */
  __I  SUPC_SR_Type                   SUPC_SR;        /**< Offset: 0x14 (R/   32) Supply Controller Status Register */
  __I  uint32_t                       Reserved1[1];
  __IO SUPC_PWMR_Type                 SUPC_PWMR;      /**< Offset: 0x1C (R/W  32) Supply Controller Power Mode Register */
} Supc;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Supply Controller */

#endif /* _SAMG55_SUPC_COMPONENT_H_ */
