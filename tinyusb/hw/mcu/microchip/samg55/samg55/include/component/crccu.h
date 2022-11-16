/**
 * \file
 *
 * \brief Component description for CRCCU
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
#ifndef _SAMG55_CRCCU_COMPONENT_H_
#define _SAMG55_CRCCU_COMPONENT_H_
#define _SAMG55_CRCCU_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Cyclic Redundancy Check Calculation Unit
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR CRCCU */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define CRCCU_11001                      /**< (CRCCU) Module ID */
#define REV_CRCCU I                      /**< (CRCCU) Module revision */

/* -------- CRCCU_DSCR : (CRCCU Offset: 0x00) (R/W 32) CRCCU Descriptor Base Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :9;                        /**< bit:   0..8  Reserved */
    uint32_t DSCR:23;                   /**< bit:  9..31  Descriptor Base Address                  */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DSCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DSCR_OFFSET                   (0x00)                                        /**<  (CRCCU_DSCR) CRCCU Descriptor Base Register  Offset */

#define CRCCU_DSCR_DSCR_Pos                 9                                              /**< (CRCCU_DSCR) Descriptor Base Address Position */
#define CRCCU_DSCR_DSCR_Msk                 (_U_(0x7FFFFF) << CRCCU_DSCR_DSCR_Pos)         /**< (CRCCU_DSCR) Descriptor Base Address Mask */
#define CRCCU_DSCR_DSCR(value)              (CRCCU_DSCR_DSCR_Msk & ((value) << CRCCU_DSCR_DSCR_Pos))
#define CRCCU_DSCR_MASK                     _U_(0xFFFFFE00)                                /**< \deprecated (CRCCU_DSCR) Register MASK  (Use CRCCU_DSCR_Msk instead)  */
#define CRCCU_DSCR_Msk                      _U_(0xFFFFFE00)                                /**< (CRCCU_DSCR) Register Mask  */


/* -------- CRCCU_DMA_EN : (CRCCU Offset: 0x08) (/W 32) CRCCU DMA Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMAEN:1;                   /**< bit:      0  DMA Enable                               */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_EN_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_EN_OFFSET                 (0x08)                                        /**<  (CRCCU_DMA_EN) CRCCU DMA Enable Register  Offset */

#define CRCCU_DMA_EN_DMAEN_Pos              0                                              /**< (CRCCU_DMA_EN) DMA Enable Position */
#define CRCCU_DMA_EN_DMAEN_Msk              (_U_(0x1) << CRCCU_DMA_EN_DMAEN_Pos)           /**< (CRCCU_DMA_EN) DMA Enable Mask */
#define CRCCU_DMA_EN_DMAEN                  CRCCU_DMA_EN_DMAEN_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_EN_DMAEN_Msk instead */
#define CRCCU_DMA_EN_MASK                   _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_EN) Register MASK  (Use CRCCU_DMA_EN_Msk instead)  */
#define CRCCU_DMA_EN_Msk                    _U_(0x01)                                      /**< (CRCCU_DMA_EN) Register Mask  */


/* -------- CRCCU_DMA_DIS : (CRCCU Offset: 0x0c) (/W 32) CRCCU DMA Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMADIS:1;                  /**< bit:      0  DMA Disable                              */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_DIS_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_DIS_OFFSET                (0x0C)                                        /**<  (CRCCU_DMA_DIS) CRCCU DMA Disable Register  Offset */

#define CRCCU_DMA_DIS_DMADIS_Pos            0                                              /**< (CRCCU_DMA_DIS) DMA Disable Position */
#define CRCCU_DMA_DIS_DMADIS_Msk            (_U_(0x1) << CRCCU_DMA_DIS_DMADIS_Pos)         /**< (CRCCU_DMA_DIS) DMA Disable Mask */
#define CRCCU_DMA_DIS_DMADIS                CRCCU_DMA_DIS_DMADIS_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_DIS_DMADIS_Msk instead */
#define CRCCU_DMA_DIS_MASK                  _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_DIS) Register MASK  (Use CRCCU_DMA_DIS_Msk instead)  */
#define CRCCU_DMA_DIS_Msk                   _U_(0x01)                                      /**< (CRCCU_DMA_DIS) Register Mask  */


/* -------- CRCCU_DMA_SR : (CRCCU Offset: 0x10) (R/ 32) CRCCU DMA Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMASR:1;                   /**< bit:      0  DMA Status                               */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_SR_OFFSET                 (0x10)                                        /**<  (CRCCU_DMA_SR) CRCCU DMA Status Register  Offset */

#define CRCCU_DMA_SR_DMASR_Pos              0                                              /**< (CRCCU_DMA_SR) DMA Status Position */
#define CRCCU_DMA_SR_DMASR_Msk              (_U_(0x1) << CRCCU_DMA_SR_DMASR_Pos)           /**< (CRCCU_DMA_SR) DMA Status Mask */
#define CRCCU_DMA_SR_DMASR                  CRCCU_DMA_SR_DMASR_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_SR_DMASR_Msk instead */
#define CRCCU_DMA_SR_MASK                   _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_SR) Register MASK  (Use CRCCU_DMA_SR_Msk instead)  */
#define CRCCU_DMA_SR_Msk                    _U_(0x01)                                      /**< (CRCCU_DMA_SR) Register Mask  */


/* -------- CRCCU_DMA_IER : (CRCCU Offset: 0x14) (/W 32) CRCCU DMA Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMAIER:1;                  /**< bit:      0  Interrupt Enable                         */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_IER_OFFSET                (0x14)                                        /**<  (CRCCU_DMA_IER) CRCCU DMA Interrupt Enable Register  Offset */

#define CRCCU_DMA_IER_DMAIER_Pos            0                                              /**< (CRCCU_DMA_IER) Interrupt Enable Position */
#define CRCCU_DMA_IER_DMAIER_Msk            (_U_(0x1) << CRCCU_DMA_IER_DMAIER_Pos)         /**< (CRCCU_DMA_IER) Interrupt Enable Mask */
#define CRCCU_DMA_IER_DMAIER                CRCCU_DMA_IER_DMAIER_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_IER_DMAIER_Msk instead */
#define CRCCU_DMA_IER_MASK                  _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_IER) Register MASK  (Use CRCCU_DMA_IER_Msk instead)  */
#define CRCCU_DMA_IER_Msk                   _U_(0x01)                                      /**< (CRCCU_DMA_IER) Register Mask  */


/* -------- CRCCU_DMA_IDR : (CRCCU Offset: 0x18) (/W 32) CRCCU DMA Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMAIDR:1;                  /**< bit:      0  Interrupt Disable                        */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_IDR_OFFSET                (0x18)                                        /**<  (CRCCU_DMA_IDR) CRCCU DMA Interrupt Disable Register  Offset */

#define CRCCU_DMA_IDR_DMAIDR_Pos            0                                              /**< (CRCCU_DMA_IDR) Interrupt Disable Position */
#define CRCCU_DMA_IDR_DMAIDR_Msk            (_U_(0x1) << CRCCU_DMA_IDR_DMAIDR_Pos)         /**< (CRCCU_DMA_IDR) Interrupt Disable Mask */
#define CRCCU_DMA_IDR_DMAIDR                CRCCU_DMA_IDR_DMAIDR_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_IDR_DMAIDR_Msk instead */
#define CRCCU_DMA_IDR_MASK                  _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_IDR) Register MASK  (Use CRCCU_DMA_IDR_Msk instead)  */
#define CRCCU_DMA_IDR_Msk                   _U_(0x01)                                      /**< (CRCCU_DMA_IDR) Register Mask  */


/* -------- CRCCU_DMA_IMR : (CRCCU Offset: 0x1c) (R/ 32) CRCCU DMA Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMAIMR:1;                  /**< bit:      0  Interrupt Mask                           */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_IMR_OFFSET                (0x1C)                                        /**<  (CRCCU_DMA_IMR) CRCCU DMA Interrupt Mask Register  Offset */

#define CRCCU_DMA_IMR_DMAIMR_Pos            0                                              /**< (CRCCU_DMA_IMR) Interrupt Mask Position */
#define CRCCU_DMA_IMR_DMAIMR_Msk            (_U_(0x1) << CRCCU_DMA_IMR_DMAIMR_Pos)         /**< (CRCCU_DMA_IMR) Interrupt Mask Mask */
#define CRCCU_DMA_IMR_DMAIMR                CRCCU_DMA_IMR_DMAIMR_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_IMR_DMAIMR_Msk instead */
#define CRCCU_DMA_IMR_MASK                  _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_IMR) Register MASK  (Use CRCCU_DMA_IMR_Msk instead)  */
#define CRCCU_DMA_IMR_Msk                   _U_(0x01)                                      /**< (CRCCU_DMA_IMR) Register Mask  */


/* -------- CRCCU_DMA_ISR : (CRCCU Offset: 0x20) (R/ 32) CRCCU DMA Interrupt Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DMAISR:1;                  /**< bit:      0  Interrupt Status                         */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_DMA_ISR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_DMA_ISR_OFFSET                (0x20)                                        /**<  (CRCCU_DMA_ISR) CRCCU DMA Interrupt Status Register  Offset */

#define CRCCU_DMA_ISR_DMAISR_Pos            0                                              /**< (CRCCU_DMA_ISR) Interrupt Status Position */
#define CRCCU_DMA_ISR_DMAISR_Msk            (_U_(0x1) << CRCCU_DMA_ISR_DMAISR_Pos)         /**< (CRCCU_DMA_ISR) Interrupt Status Mask */
#define CRCCU_DMA_ISR_DMAISR                CRCCU_DMA_ISR_DMAISR_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_DMA_ISR_DMAISR_Msk instead */
#define CRCCU_DMA_ISR_MASK                  _U_(0x01)                                      /**< \deprecated (CRCCU_DMA_ISR) Register MASK  (Use CRCCU_DMA_ISR_Msk instead)  */
#define CRCCU_DMA_ISR_Msk                   _U_(0x01)                                      /**< (CRCCU_DMA_ISR) Register Mask  */


/* -------- CRCCU_CR : (CRCCU Offset: 0x34) (/W 32) CRCCU Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RESET:1;                   /**< bit:      0  CRC Computation Reset                    */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_CR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_CR_OFFSET                     (0x34)                                        /**<  (CRCCU_CR) CRCCU Control Register  Offset */

#define CRCCU_CR_RESET_Pos                  0                                              /**< (CRCCU_CR) CRC Computation Reset Position */
#define CRCCU_CR_RESET_Msk                  (_U_(0x1) << CRCCU_CR_RESET_Pos)               /**< (CRCCU_CR) CRC Computation Reset Mask */
#define CRCCU_CR_RESET                      CRCCU_CR_RESET_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_CR_RESET_Msk instead */
#define CRCCU_CR_MASK                       _U_(0x01)                                      /**< \deprecated (CRCCU_CR) Register MASK  (Use CRCCU_CR_Msk instead)  */
#define CRCCU_CR_Msk                        _U_(0x01)                                      /**< (CRCCU_CR) Register Mask  */


/* -------- CRCCU_MR : (CRCCU Offset: 0x38) (R/W 32) CRCCU Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ENABLE:1;                  /**< bit:      0  CRC Enable                               */
    uint32_t COMPARE:1;                 /**< bit:      1  CRC Compare                              */
    uint32_t PTYPE:2;                   /**< bit:   2..3  Primitive Polynomial                     */
    uint32_t DIVIDER:4;                 /**< bit:   4..7  Request Divider                          */
    uint32_t :9;                        /**< bit:  8..16  Reserved */
    uint32_t BITORDER:1;                /**< bit:     17  Precomputation Bit Swap Operation of the CRC */
    uint32_t :14;                       /**< bit: 18..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_MR_OFFSET                     (0x38)                                        /**<  (CRCCU_MR) CRCCU Mode Register  Offset */

#define CRCCU_MR_ENABLE_Pos                 0                                              /**< (CRCCU_MR) CRC Enable Position */
#define CRCCU_MR_ENABLE_Msk                 (_U_(0x1) << CRCCU_MR_ENABLE_Pos)              /**< (CRCCU_MR) CRC Enable Mask */
#define CRCCU_MR_ENABLE                     CRCCU_MR_ENABLE_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_MR_ENABLE_Msk instead */
#define CRCCU_MR_COMPARE_Pos                1                                              /**< (CRCCU_MR) CRC Compare Position */
#define CRCCU_MR_COMPARE_Msk                (_U_(0x1) << CRCCU_MR_COMPARE_Pos)             /**< (CRCCU_MR) CRC Compare Mask */
#define CRCCU_MR_COMPARE                    CRCCU_MR_COMPARE_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_MR_COMPARE_Msk instead */
#define CRCCU_MR_PTYPE_Pos                  2                                              /**< (CRCCU_MR) Primitive Polynomial Position */
#define CRCCU_MR_PTYPE_Msk                  (_U_(0x3) << CRCCU_MR_PTYPE_Pos)               /**< (CRCCU_MR) Primitive Polynomial Mask */
#define CRCCU_MR_PTYPE(value)               (CRCCU_MR_PTYPE_Msk & ((value) << CRCCU_MR_PTYPE_Pos))
#define   CRCCU_MR_PTYPE_CCITT8023_Val      _U_(0x0)                                       /**< (CRCCU_MR) Polynom 0x04C11DB7  */
#define   CRCCU_MR_PTYPE_CASTAGNOLI_Val     _U_(0x1)                                       /**< (CRCCU_MR) Polynom 0x1EDC6F41  */
#define   CRCCU_MR_PTYPE_CCITT16_Val        _U_(0x2)                                       /**< (CRCCU_MR) Polynom 0x1021  */
#define CRCCU_MR_PTYPE_CCITT8023            (CRCCU_MR_PTYPE_CCITT8023_Val << CRCCU_MR_PTYPE_Pos)  /**< (CRCCU_MR) Polynom 0x04C11DB7 Position  */
#define CRCCU_MR_PTYPE_CASTAGNOLI           (CRCCU_MR_PTYPE_CASTAGNOLI_Val << CRCCU_MR_PTYPE_Pos)  /**< (CRCCU_MR) Polynom 0x1EDC6F41 Position  */
#define CRCCU_MR_PTYPE_CCITT16              (CRCCU_MR_PTYPE_CCITT16_Val << CRCCU_MR_PTYPE_Pos)  /**< (CRCCU_MR) Polynom 0x1021 Position  */
#define CRCCU_MR_DIVIDER_Pos                4                                              /**< (CRCCU_MR) Request Divider Position */
#define CRCCU_MR_DIVIDER_Msk                (_U_(0xF) << CRCCU_MR_DIVIDER_Pos)             /**< (CRCCU_MR) Request Divider Mask */
#define CRCCU_MR_DIVIDER(value)             (CRCCU_MR_DIVIDER_Msk & ((value) << CRCCU_MR_DIVIDER_Pos))
#define CRCCU_MR_BITORDER_Pos               17                                             /**< (CRCCU_MR) Precomputation Bit Swap Operation of the CRC Position */
#define CRCCU_MR_BITORDER_Msk               (_U_(0x1) << CRCCU_MR_BITORDER_Pos)            /**< (CRCCU_MR) Precomputation Bit Swap Operation of the CRC Mask */
#define CRCCU_MR_BITORDER                   CRCCU_MR_BITORDER_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_MR_BITORDER_Msk instead */
#define   CRCCU_MR_BITORDER_MSBFIRST_Val    _U_(0x0)                                       /**< (CRCCU_MR) CRC computation is performed from the most significant bit to the least significant bit  */
#define   CRCCU_MR_BITORDER_LSBFIRST_Val    _U_(0x1)                                       /**< (CRCCU_MR) CRC computation is performed from the least significant bit to the most significant bit  */
#define CRCCU_MR_BITORDER_MSBFIRST          (CRCCU_MR_BITORDER_MSBFIRST_Val << CRCCU_MR_BITORDER_Pos)  /**< (CRCCU_MR) CRC computation is performed from the most significant bit to the least significant bit Position  */
#define CRCCU_MR_BITORDER_LSBFIRST          (CRCCU_MR_BITORDER_LSBFIRST_Val << CRCCU_MR_BITORDER_Pos)  /**< (CRCCU_MR) CRC computation is performed from the least significant bit to the most significant bit Position  */
#define CRCCU_MR_MASK                       _U_(0x200FF)                                   /**< \deprecated (CRCCU_MR) Register MASK  (Use CRCCU_MR_Msk instead)  */
#define CRCCU_MR_Msk                        _U_(0x200FF)                                   /**< (CRCCU_MR) Register Mask  */


/* -------- CRCCU_SR : (CRCCU Offset: 0x3c) (R/ 32) CRCCU Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CRC:32;                    /**< bit:  0..31  Cyclic Redundancy Check Value            */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_SR_OFFSET                     (0x3C)                                        /**<  (CRCCU_SR) CRCCU Status Register  Offset */

#define CRCCU_SR_CRC_Pos                    0                                              /**< (CRCCU_SR) Cyclic Redundancy Check Value Position */
#define CRCCU_SR_CRC_Msk                    (_U_(0xFFFFFFFF) << CRCCU_SR_CRC_Pos)          /**< (CRCCU_SR) Cyclic Redundancy Check Value Mask */
#define CRCCU_SR_CRC(value)                 (CRCCU_SR_CRC_Msk & ((value) << CRCCU_SR_CRC_Pos))
#define CRCCU_SR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (CRCCU_SR) Register MASK  (Use CRCCU_SR_Msk instead)  */
#define CRCCU_SR_Msk                        _U_(0xFFFFFFFF)                                /**< (CRCCU_SR) Register Mask  */


/* -------- CRCCU_IER : (CRCCU Offset: 0x40) (/W 32) CRCCU Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ERRIER:1;                  /**< bit:      0  CRC Error Interrupt Enable               */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_IER_OFFSET                    (0x40)                                        /**<  (CRCCU_IER) CRCCU Interrupt Enable Register  Offset */

#define CRCCU_IER_ERRIER_Pos                0                                              /**< (CRCCU_IER) CRC Error Interrupt Enable Position */
#define CRCCU_IER_ERRIER_Msk                (_U_(0x1) << CRCCU_IER_ERRIER_Pos)             /**< (CRCCU_IER) CRC Error Interrupt Enable Mask */
#define CRCCU_IER_ERRIER                    CRCCU_IER_ERRIER_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_IER_ERRIER_Msk instead */
#define CRCCU_IER_MASK                      _U_(0x01)                                      /**< \deprecated (CRCCU_IER) Register MASK  (Use CRCCU_IER_Msk instead)  */
#define CRCCU_IER_Msk                       _U_(0x01)                                      /**< (CRCCU_IER) Register Mask  */


/* -------- CRCCU_IDR : (CRCCU Offset: 0x44) (/W 32) CRCCU Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ERRIDR:1;                  /**< bit:      0  CRC Error Interrupt Disable              */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_IDR_OFFSET                    (0x44)                                        /**<  (CRCCU_IDR) CRCCU Interrupt Disable Register  Offset */

#define CRCCU_IDR_ERRIDR_Pos                0                                              /**< (CRCCU_IDR) CRC Error Interrupt Disable Position */
#define CRCCU_IDR_ERRIDR_Msk                (_U_(0x1) << CRCCU_IDR_ERRIDR_Pos)             /**< (CRCCU_IDR) CRC Error Interrupt Disable Mask */
#define CRCCU_IDR_ERRIDR                    CRCCU_IDR_ERRIDR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_IDR_ERRIDR_Msk instead */
#define CRCCU_IDR_MASK                      _U_(0x01)                                      /**< \deprecated (CRCCU_IDR) Register MASK  (Use CRCCU_IDR_Msk instead)  */
#define CRCCU_IDR_Msk                       _U_(0x01)                                      /**< (CRCCU_IDR) Register Mask  */


/* -------- CRCCU_IMR : (CRCCU Offset: 0x48) (R/ 32) CRCCU Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ERRIMR:1;                  /**< bit:      0  CRC Error Interrupt Mask                 */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_IMR_OFFSET                    (0x48)                                        /**<  (CRCCU_IMR) CRCCU Interrupt Mask Register  Offset */

#define CRCCU_IMR_ERRIMR_Pos                0                                              /**< (CRCCU_IMR) CRC Error Interrupt Mask Position */
#define CRCCU_IMR_ERRIMR_Msk                (_U_(0x1) << CRCCU_IMR_ERRIMR_Pos)             /**< (CRCCU_IMR) CRC Error Interrupt Mask Mask */
#define CRCCU_IMR_ERRIMR                    CRCCU_IMR_ERRIMR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_IMR_ERRIMR_Msk instead */
#define CRCCU_IMR_MASK                      _U_(0x01)                                      /**< \deprecated (CRCCU_IMR) Register MASK  (Use CRCCU_IMR_Msk instead)  */
#define CRCCU_IMR_Msk                       _U_(0x01)                                      /**< (CRCCU_IMR) Register Mask  */


/* -------- CRCCU_ISR : (CRCCU Offset: 0x4c) (R/ 32) CRCCU Interrupt Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t ERRISR:1;                  /**< bit:      0  CRC Error Interrupt Status               */
    uint32_t :31;                       /**< bit:  1..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} CRCCU_ISR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define CRCCU_ISR_OFFSET                    (0x4C)                                        /**<  (CRCCU_ISR) CRCCU Interrupt Status Register  Offset */

#define CRCCU_ISR_ERRISR_Pos                0                                              /**< (CRCCU_ISR) CRC Error Interrupt Status Position */
#define CRCCU_ISR_ERRISR_Msk                (_U_(0x1) << CRCCU_ISR_ERRISR_Pos)             /**< (CRCCU_ISR) CRC Error Interrupt Status Mask */
#define CRCCU_ISR_ERRISR                    CRCCU_ISR_ERRISR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use CRCCU_ISR_ERRISR_Msk instead */
#define CRCCU_ISR_MASK                      _U_(0x01)                                      /**< \deprecated (CRCCU_ISR) Register MASK  (Use CRCCU_ISR_Msk instead)  */
#define CRCCU_ISR_Msk                       _U_(0x01)                                      /**< (CRCCU_ISR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief CRCCU hardware registers */
typedef struct {  
  __IO uint32_t CRCCU_DSCR;     /**< (CRCCU Offset: 0x00) CRCCU Descriptor Base Register */
  RoReg8  Reserved1[0x4];
  __O  uint32_t CRCCU_DMA_EN;   /**< (CRCCU Offset: 0x08) CRCCU DMA Enable Register */
  __O  uint32_t CRCCU_DMA_DIS;  /**< (CRCCU Offset: 0x0C) CRCCU DMA Disable Register */
  __I  uint32_t CRCCU_DMA_SR;   /**< (CRCCU Offset: 0x10) CRCCU DMA Status Register */
  __O  uint32_t CRCCU_DMA_IER;  /**< (CRCCU Offset: 0x14) CRCCU DMA Interrupt Enable Register */
  __O  uint32_t CRCCU_DMA_IDR;  /**< (CRCCU Offset: 0x18) CRCCU DMA Interrupt Disable Register */
  __I  uint32_t CRCCU_DMA_IMR;  /**< (CRCCU Offset: 0x1C) CRCCU DMA Interrupt Mask Register */
  __I  uint32_t CRCCU_DMA_ISR;  /**< (CRCCU Offset: 0x20) CRCCU DMA Interrupt Status Register */
  RoReg8  Reserved2[0x10];
  __O  uint32_t CRCCU_CR;       /**< (CRCCU Offset: 0x34) CRCCU Control Register */
  __IO uint32_t CRCCU_MR;       /**< (CRCCU Offset: 0x38) CRCCU Mode Register */
  __I  uint32_t CRCCU_SR;       /**< (CRCCU Offset: 0x3C) CRCCU Status Register */
  __O  uint32_t CRCCU_IER;      /**< (CRCCU Offset: 0x40) CRCCU Interrupt Enable Register */
  __O  uint32_t CRCCU_IDR;      /**< (CRCCU Offset: 0x44) CRCCU Interrupt Disable Register */
  __I  uint32_t CRCCU_IMR;      /**< (CRCCU Offset: 0x48) CRCCU Interrupt Mask Register */
  __I  uint32_t CRCCU_ISR;      /**< (CRCCU Offset: 0x4C) CRCCU Interrupt Status Register */
} Crccu;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief CRCCU hardware registers */
typedef struct {  
  __IO CRCCU_DSCR_Type                CRCCU_DSCR;     /**< Offset: 0x00 (R/W  32) CRCCU Descriptor Base Register */
  __I  uint32_t                       Reserved1[1];
  __O  CRCCU_DMA_EN_Type              CRCCU_DMA_EN;   /**< Offset: 0x08 ( /W  32) CRCCU DMA Enable Register */
  __O  CRCCU_DMA_DIS_Type             CRCCU_DMA_DIS;  /**< Offset: 0x0C ( /W  32) CRCCU DMA Disable Register */
  __I  CRCCU_DMA_SR_Type              CRCCU_DMA_SR;   /**< Offset: 0x10 (R/   32) CRCCU DMA Status Register */
  __O  CRCCU_DMA_IER_Type             CRCCU_DMA_IER;  /**< Offset: 0x14 ( /W  32) CRCCU DMA Interrupt Enable Register */
  __O  CRCCU_DMA_IDR_Type             CRCCU_DMA_IDR;  /**< Offset: 0x18 ( /W  32) CRCCU DMA Interrupt Disable Register */
  __I  CRCCU_DMA_IMR_Type             CRCCU_DMA_IMR;  /**< Offset: 0x1C (R/   32) CRCCU DMA Interrupt Mask Register */
  __I  CRCCU_DMA_ISR_Type             CRCCU_DMA_ISR;  /**< Offset: 0x20 (R/   32) CRCCU DMA Interrupt Status Register */
  __I  uint32_t                       Reserved2[4];
  __O  CRCCU_CR_Type                  CRCCU_CR;       /**< Offset: 0x34 ( /W  32) CRCCU Control Register */
  __IO CRCCU_MR_Type                  CRCCU_MR;       /**< Offset: 0x38 (R/W  32) CRCCU Mode Register */
  __I  CRCCU_SR_Type                  CRCCU_SR;       /**< Offset: 0x3C (R/   32) CRCCU Status Register */
  __O  CRCCU_IER_Type                 CRCCU_IER;      /**< Offset: 0x40 ( /W  32) CRCCU Interrupt Enable Register */
  __O  CRCCU_IDR_Type                 CRCCU_IDR;      /**< Offset: 0x44 ( /W  32) CRCCU Interrupt Disable Register */
  __I  CRCCU_IMR_Type                 CRCCU_IMR;      /**< Offset: 0x48 (R/   32) CRCCU Interrupt Mask Register */
  __I  CRCCU_ISR_Type                 CRCCU_ISR;      /**< Offset: 0x4C (R/   32) CRCCU Interrupt Status Register */
} Crccu;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Cyclic Redundancy Check Calculation Unit */

#endif /* _SAMG55_CRCCU_COMPONENT_H_ */
