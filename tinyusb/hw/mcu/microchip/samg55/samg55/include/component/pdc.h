/**
 * \file
 *
 * \brief Component description for PDC
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
#ifndef _SAMG55_PDC_COMPONENT_H_
#define _SAMG55_PDC_COMPONENT_H_
#define _SAMG55_PDC_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Peripheral DMA Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PDC */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define PDC_6031                       /**< (PDC) Module ID */
#define REV_PDC I                      /**< (PDC) Module revision */

/* -------- PDC_PERIPH_RPR : (PDC Offset: 0x00) (R/W 32) Receive Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_RPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_RPR_OFFSET               (0x00)                                        /**<  (PDC_PERIPH_RPR) Receive Pointer Register  Offset */

#define PDC_PERIPH_RPR_RXPTR_Pos            0                                              /**< (PDC_PERIPH_RPR) Receive Pointer Register Position */
#define PDC_PERIPH_RPR_RXPTR_Msk            (_U_(0xFFFFFFFF) << PDC_PERIPH_RPR_RXPTR_Pos)  /**< (PDC_PERIPH_RPR) Receive Pointer Register Mask */
#define PDC_PERIPH_RPR_RXPTR(value)         (PDC_PERIPH_RPR_RXPTR_Msk & ((value) << PDC_PERIPH_RPR_RXPTR_Pos))
#define PDC_PERIPH_RPR_MASK                 _U_(0xFFFFFFFF)                                /**< \deprecated (PDC_PERIPH_RPR) Register MASK  (Use PDC_PERIPH_RPR_Msk instead)  */
#define PDC_PERIPH_RPR_Msk                  _U_(0xFFFFFFFF)                                /**< (PDC_PERIPH_RPR) Register Mask  */


/* -------- PDC_PERIPH_RCR : (PDC Offset: 0x04) (R/W 32) Receive Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCTR:16;                  /**< bit:  0..15  Receive Counter Register                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_RCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_RCR_OFFSET               (0x04)                                        /**<  (PDC_PERIPH_RCR) Receive Counter Register  Offset */

#define PDC_PERIPH_RCR_RXCTR_Pos            0                                              /**< (PDC_PERIPH_RCR) Receive Counter Register Position */
#define PDC_PERIPH_RCR_RXCTR_Msk            (_U_(0xFFFF) << PDC_PERIPH_RCR_RXCTR_Pos)      /**< (PDC_PERIPH_RCR) Receive Counter Register Mask */
#define PDC_PERIPH_RCR_RXCTR(value)         (PDC_PERIPH_RCR_RXCTR_Msk & ((value) << PDC_PERIPH_RCR_RXCTR_Pos))
#define PDC_PERIPH_RCR_MASK                 _U_(0xFFFF)                                    /**< \deprecated (PDC_PERIPH_RCR) Register MASK  (Use PDC_PERIPH_RCR_Msk instead)  */
#define PDC_PERIPH_RCR_Msk                  _U_(0xFFFF)                                    /**< (PDC_PERIPH_RCR) Register Mask  */


/* -------- PDC_PERIPH_TPR : (PDC Offset: 0x08) (R/W 32) Transmit Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXPTR:32;                  /**< bit:  0..31  Transmit Counter Register                */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_TPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_TPR_OFFSET               (0x08)                                        /**<  (PDC_PERIPH_TPR) Transmit Pointer Register  Offset */

#define PDC_PERIPH_TPR_TXPTR_Pos            0                                              /**< (PDC_PERIPH_TPR) Transmit Counter Register Position */
#define PDC_PERIPH_TPR_TXPTR_Msk            (_U_(0xFFFFFFFF) << PDC_PERIPH_TPR_TXPTR_Pos)  /**< (PDC_PERIPH_TPR) Transmit Counter Register Mask */
#define PDC_PERIPH_TPR_TXPTR(value)         (PDC_PERIPH_TPR_TXPTR_Msk & ((value) << PDC_PERIPH_TPR_TXPTR_Pos))
#define PDC_PERIPH_TPR_MASK                 _U_(0xFFFFFFFF)                                /**< \deprecated (PDC_PERIPH_TPR) Register MASK  (Use PDC_PERIPH_TPR_Msk instead)  */
#define PDC_PERIPH_TPR_Msk                  _U_(0xFFFFFFFF)                                /**< (PDC_PERIPH_TPR) Register Mask  */


/* -------- PDC_PERIPH_TCR : (PDC Offset: 0x0c) (R/W 32) Transmit Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCTR:16;                  /**< bit:  0..15  Transmit Counter Register                */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_TCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_TCR_OFFSET               (0x0C)                                        /**<  (PDC_PERIPH_TCR) Transmit Counter Register  Offset */

#define PDC_PERIPH_TCR_TXCTR_Pos            0                                              /**< (PDC_PERIPH_TCR) Transmit Counter Register Position */
#define PDC_PERIPH_TCR_TXCTR_Msk            (_U_(0xFFFF) << PDC_PERIPH_TCR_TXCTR_Pos)      /**< (PDC_PERIPH_TCR) Transmit Counter Register Mask */
#define PDC_PERIPH_TCR_TXCTR(value)         (PDC_PERIPH_TCR_TXCTR_Msk & ((value) << PDC_PERIPH_TCR_TXCTR_Pos))
#define PDC_PERIPH_TCR_MASK                 _U_(0xFFFF)                                    /**< \deprecated (PDC_PERIPH_TCR) Register MASK  (Use PDC_PERIPH_TCR_Msk instead)  */
#define PDC_PERIPH_TCR_Msk                  _U_(0xFFFF)                                    /**< (PDC_PERIPH_TCR) Register Mask  */


/* -------- PDC_PERIPH_RNPR : (PDC Offset: 0x10) (R/W 32) Receive Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_RNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_RNPR_OFFSET              (0x10)                                        /**<  (PDC_PERIPH_RNPR) Receive Next Pointer Register  Offset */

#define PDC_PERIPH_RNPR_RXNPTR_Pos          0                                              /**< (PDC_PERIPH_RNPR) Receive Next Pointer Position */
#define PDC_PERIPH_RNPR_RXNPTR_Msk          (_U_(0xFFFFFFFF) << PDC_PERIPH_RNPR_RXNPTR_Pos)  /**< (PDC_PERIPH_RNPR) Receive Next Pointer Mask */
#define PDC_PERIPH_RNPR_RXNPTR(value)       (PDC_PERIPH_RNPR_RXNPTR_Msk & ((value) << PDC_PERIPH_RNPR_RXNPTR_Pos))
#define PDC_PERIPH_RNPR_MASK                _U_(0xFFFFFFFF)                                /**< \deprecated (PDC_PERIPH_RNPR) Register MASK  (Use PDC_PERIPH_RNPR_Msk instead)  */
#define PDC_PERIPH_RNPR_Msk                 _U_(0xFFFFFFFF)                                /**< (PDC_PERIPH_RNPR) Register Mask  */


/* -------- PDC_PERIPH_RNCR : (PDC Offset: 0x14) (R/W 32) Receive Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_RNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_RNCR_OFFSET              (0x14)                                        /**<  (PDC_PERIPH_RNCR) Receive Next Counter Register  Offset */

#define PDC_PERIPH_RNCR_RXNCTR_Pos          0                                              /**< (PDC_PERIPH_RNCR) Receive Next Counter Position */
#define PDC_PERIPH_RNCR_RXNCTR_Msk          (_U_(0xFFFF) << PDC_PERIPH_RNCR_RXNCTR_Pos)    /**< (PDC_PERIPH_RNCR) Receive Next Counter Mask */
#define PDC_PERIPH_RNCR_RXNCTR(value)       (PDC_PERIPH_RNCR_RXNCTR_Msk & ((value) << PDC_PERIPH_RNCR_RXNCTR_Pos))
#define PDC_PERIPH_RNCR_MASK                _U_(0xFFFF)                                    /**< \deprecated (PDC_PERIPH_RNCR) Register MASK  (Use PDC_PERIPH_RNCR_Msk instead)  */
#define PDC_PERIPH_RNCR_Msk                 _U_(0xFFFF)                                    /**< (PDC_PERIPH_RNCR) Register Mask  */


/* -------- PDC_PERIPH_TNPR : (PDC Offset: 0x18) (R/W 32) Transmit Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNPTR:32;                 /**< bit:  0..31  Transmit Next Pointer                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_TNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_TNPR_OFFSET              (0x18)                                        /**<  (PDC_PERIPH_TNPR) Transmit Next Pointer Register  Offset */

#define PDC_PERIPH_TNPR_TXNPTR_Pos          0                                              /**< (PDC_PERIPH_TNPR) Transmit Next Pointer Position */
#define PDC_PERIPH_TNPR_TXNPTR_Msk          (_U_(0xFFFFFFFF) << PDC_PERIPH_TNPR_TXNPTR_Pos)  /**< (PDC_PERIPH_TNPR) Transmit Next Pointer Mask */
#define PDC_PERIPH_TNPR_TXNPTR(value)       (PDC_PERIPH_TNPR_TXNPTR_Msk & ((value) << PDC_PERIPH_TNPR_TXNPTR_Pos))
#define PDC_PERIPH_TNPR_MASK                _U_(0xFFFFFFFF)                                /**< \deprecated (PDC_PERIPH_TNPR) Register MASK  (Use PDC_PERIPH_TNPR_Msk instead)  */
#define PDC_PERIPH_TNPR_Msk                 _U_(0xFFFFFFFF)                                /**< (PDC_PERIPH_TNPR) Register Mask  */


/* -------- PDC_PERIPH_TNCR : (PDC Offset: 0x1c) (R/W 32) Transmit Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNCTR:16;                 /**< bit:  0..15  Transmit Counter Next                    */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_TNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_TNCR_OFFSET              (0x1C)                                        /**<  (PDC_PERIPH_TNCR) Transmit Next Counter Register  Offset */

#define PDC_PERIPH_TNCR_TXNCTR_Pos          0                                              /**< (PDC_PERIPH_TNCR) Transmit Counter Next Position */
#define PDC_PERIPH_TNCR_TXNCTR_Msk          (_U_(0xFFFF) << PDC_PERIPH_TNCR_TXNCTR_Pos)    /**< (PDC_PERIPH_TNCR) Transmit Counter Next Mask */
#define PDC_PERIPH_TNCR_TXNCTR(value)       (PDC_PERIPH_TNCR_TXNCTR_Msk & ((value) << PDC_PERIPH_TNCR_TXNCTR_Pos))
#define PDC_PERIPH_TNCR_MASK                _U_(0xFFFF)                                    /**< \deprecated (PDC_PERIPH_TNCR) Register MASK  (Use PDC_PERIPH_TNCR_Msk instead)  */
#define PDC_PERIPH_TNCR_Msk                 _U_(0xFFFF)                                    /**< (PDC_PERIPH_TNCR) Register Mask  */


/* -------- PDC_PERIPH_PTCR : (PDC Offset: 0x20) (/W 32) Transfer Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXTEN:1;                   /**< bit:      0  Receiver Transfer Enable                 */
    uint32_t RXTDIS:1;                  /**< bit:      1  Receiver Transfer Disable                */
    uint32_t :6;                        /**< bit:   2..7  Reserved */
    uint32_t TXTEN:1;                   /**< bit:      8  Transmitter Transfer Enable              */
    uint32_t TXTDIS:1;                  /**< bit:      9  Transmitter Transfer Disable             */
    uint32_t :6;                        /**< bit: 10..15  Reserved */
    uint32_t RXCBEN:1;                  /**< bit:     16  Receiver Circular Buffer Enable          */
    uint32_t RXCBDIS:1;                 /**< bit:     17  Receiver Circular Buffer Disable         */
    uint32_t TXCBEN:1;                  /**< bit:     18  Transmitter Circular Buffer Enable       */
    uint32_t TXCBDIS:1;                 /**< bit:     19  Transmitter Circular Buffer Disable      */
    uint32_t :4;                        /**< bit: 20..23  Reserved */
    uint32_t ERRCLR:1;                  /**< bit:     24  Transfer Bus Error Clear                 */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_PTCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_PTCR_OFFSET              (0x20)                                        /**<  (PDC_PERIPH_PTCR) Transfer Control Register  Offset */

#define PDC_PERIPH_PTCR_RXTEN_Pos           0                                              /**< (PDC_PERIPH_PTCR) Receiver Transfer Enable Position */
#define PDC_PERIPH_PTCR_RXTEN_Msk           (_U_(0x1) << PDC_PERIPH_PTCR_RXTEN_Pos)        /**< (PDC_PERIPH_PTCR) Receiver Transfer Enable Mask */
#define PDC_PERIPH_PTCR_RXTEN               PDC_PERIPH_PTCR_RXTEN_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_RXTEN_Msk instead */
#define PDC_PERIPH_PTCR_RXTDIS_Pos          1                                              /**< (PDC_PERIPH_PTCR) Receiver Transfer Disable Position */
#define PDC_PERIPH_PTCR_RXTDIS_Msk          (_U_(0x1) << PDC_PERIPH_PTCR_RXTDIS_Pos)       /**< (PDC_PERIPH_PTCR) Receiver Transfer Disable Mask */
#define PDC_PERIPH_PTCR_RXTDIS              PDC_PERIPH_PTCR_RXTDIS_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_RXTDIS_Msk instead */
#define PDC_PERIPH_PTCR_TXTEN_Pos           8                                              /**< (PDC_PERIPH_PTCR) Transmitter Transfer Enable Position */
#define PDC_PERIPH_PTCR_TXTEN_Msk           (_U_(0x1) << PDC_PERIPH_PTCR_TXTEN_Pos)        /**< (PDC_PERIPH_PTCR) Transmitter Transfer Enable Mask */
#define PDC_PERIPH_PTCR_TXTEN               PDC_PERIPH_PTCR_TXTEN_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_TXTEN_Msk instead */
#define PDC_PERIPH_PTCR_TXTDIS_Pos          9                                              /**< (PDC_PERIPH_PTCR) Transmitter Transfer Disable Position */
#define PDC_PERIPH_PTCR_TXTDIS_Msk          (_U_(0x1) << PDC_PERIPH_PTCR_TXTDIS_Pos)       /**< (PDC_PERIPH_PTCR) Transmitter Transfer Disable Mask */
#define PDC_PERIPH_PTCR_TXTDIS              PDC_PERIPH_PTCR_TXTDIS_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_TXTDIS_Msk instead */
#define PDC_PERIPH_PTCR_RXCBEN_Pos          16                                             /**< (PDC_PERIPH_PTCR) Receiver Circular Buffer Enable Position */
#define PDC_PERIPH_PTCR_RXCBEN_Msk          (_U_(0x1) << PDC_PERIPH_PTCR_RXCBEN_Pos)       /**< (PDC_PERIPH_PTCR) Receiver Circular Buffer Enable Mask */
#define PDC_PERIPH_PTCR_RXCBEN              PDC_PERIPH_PTCR_RXCBEN_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_RXCBEN_Msk instead */
#define PDC_PERIPH_PTCR_RXCBDIS_Pos         17                                             /**< (PDC_PERIPH_PTCR) Receiver Circular Buffer Disable Position */
#define PDC_PERIPH_PTCR_RXCBDIS_Msk         (_U_(0x1) << PDC_PERIPH_PTCR_RXCBDIS_Pos)      /**< (PDC_PERIPH_PTCR) Receiver Circular Buffer Disable Mask */
#define PDC_PERIPH_PTCR_RXCBDIS             PDC_PERIPH_PTCR_RXCBDIS_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_RXCBDIS_Msk instead */
#define PDC_PERIPH_PTCR_TXCBEN_Pos          18                                             /**< (PDC_PERIPH_PTCR) Transmitter Circular Buffer Enable Position */
#define PDC_PERIPH_PTCR_TXCBEN_Msk          (_U_(0x1) << PDC_PERIPH_PTCR_TXCBEN_Pos)       /**< (PDC_PERIPH_PTCR) Transmitter Circular Buffer Enable Mask */
#define PDC_PERIPH_PTCR_TXCBEN              PDC_PERIPH_PTCR_TXCBEN_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_TXCBEN_Msk instead */
#define PDC_PERIPH_PTCR_TXCBDIS_Pos         19                                             /**< (PDC_PERIPH_PTCR) Transmitter Circular Buffer Disable Position */
#define PDC_PERIPH_PTCR_TXCBDIS_Msk         (_U_(0x1) << PDC_PERIPH_PTCR_TXCBDIS_Pos)      /**< (PDC_PERIPH_PTCR) Transmitter Circular Buffer Disable Mask */
#define PDC_PERIPH_PTCR_TXCBDIS             PDC_PERIPH_PTCR_TXCBDIS_Msk                    /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_TXCBDIS_Msk instead */
#define PDC_PERIPH_PTCR_ERRCLR_Pos          24                                             /**< (PDC_PERIPH_PTCR) Transfer Bus Error Clear Position */
#define PDC_PERIPH_PTCR_ERRCLR_Msk          (_U_(0x1) << PDC_PERIPH_PTCR_ERRCLR_Pos)       /**< (PDC_PERIPH_PTCR) Transfer Bus Error Clear Mask */
#define PDC_PERIPH_PTCR_ERRCLR              PDC_PERIPH_PTCR_ERRCLR_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTCR_ERRCLR_Msk instead */
#define PDC_PERIPH_PTCR_MASK                _U_(0x10F0303)                                 /**< \deprecated (PDC_PERIPH_PTCR) Register MASK  (Use PDC_PERIPH_PTCR_Msk instead)  */
#define PDC_PERIPH_PTCR_Msk                 _U_(0x10F0303)                                 /**< (PDC_PERIPH_PTCR) Register Mask  */


/* -------- PDC_PERIPH_PTSR : (PDC Offset: 0x24) (R/ 32) Transfer Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXTEN:1;                   /**< bit:      0  Receiver Transfer Enable                 */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t TXTEN:1;                   /**< bit:      8  Transmitter Transfer Enable              */
    uint32_t :7;                        /**< bit:  9..15  Reserved */
    uint32_t RXCBEN:1;                  /**< bit:     16  Receiver Circular Buffer Enable          */
    uint32_t :1;                        /**< bit:     17  Reserved */
    uint32_t TXCBEN:1;                  /**< bit:     18  Transmitter Circular Buffer Enable       */
    uint32_t :5;                        /**< bit: 19..23  Reserved */
    uint32_t ERR:1;                     /**< bit:     24  Transfer Bus Error                       */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDC_PERIPH_PTSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDC_PERIPH_PTSR_OFFSET              (0x24)                                        /**<  (PDC_PERIPH_PTSR) Transfer Status Register  Offset */

#define PDC_PERIPH_PTSR_RXTEN_Pos           0                                              /**< (PDC_PERIPH_PTSR) Receiver Transfer Enable Position */
#define PDC_PERIPH_PTSR_RXTEN_Msk           (_U_(0x1) << PDC_PERIPH_PTSR_RXTEN_Pos)        /**< (PDC_PERIPH_PTSR) Receiver Transfer Enable Mask */
#define PDC_PERIPH_PTSR_RXTEN               PDC_PERIPH_PTSR_RXTEN_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTSR_RXTEN_Msk instead */
#define PDC_PERIPH_PTSR_TXTEN_Pos           8                                              /**< (PDC_PERIPH_PTSR) Transmitter Transfer Enable Position */
#define PDC_PERIPH_PTSR_TXTEN_Msk           (_U_(0x1) << PDC_PERIPH_PTSR_TXTEN_Pos)        /**< (PDC_PERIPH_PTSR) Transmitter Transfer Enable Mask */
#define PDC_PERIPH_PTSR_TXTEN               PDC_PERIPH_PTSR_TXTEN_Msk                      /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTSR_TXTEN_Msk instead */
#define PDC_PERIPH_PTSR_RXCBEN_Pos          16                                             /**< (PDC_PERIPH_PTSR) Receiver Circular Buffer Enable Position */
#define PDC_PERIPH_PTSR_RXCBEN_Msk          (_U_(0x1) << PDC_PERIPH_PTSR_RXCBEN_Pos)       /**< (PDC_PERIPH_PTSR) Receiver Circular Buffer Enable Mask */
#define PDC_PERIPH_PTSR_RXCBEN              PDC_PERIPH_PTSR_RXCBEN_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTSR_RXCBEN_Msk instead */
#define PDC_PERIPH_PTSR_TXCBEN_Pos          18                                             /**< (PDC_PERIPH_PTSR) Transmitter Circular Buffer Enable Position */
#define PDC_PERIPH_PTSR_TXCBEN_Msk          (_U_(0x1) << PDC_PERIPH_PTSR_TXCBEN_Pos)       /**< (PDC_PERIPH_PTSR) Transmitter Circular Buffer Enable Mask */
#define PDC_PERIPH_PTSR_TXCBEN              PDC_PERIPH_PTSR_TXCBEN_Msk                     /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTSR_TXCBEN_Msk instead */
#define PDC_PERIPH_PTSR_ERR_Pos             24                                             /**< (PDC_PERIPH_PTSR) Transfer Bus Error Position */
#define PDC_PERIPH_PTSR_ERR_Msk             (_U_(0x1) << PDC_PERIPH_PTSR_ERR_Pos)          /**< (PDC_PERIPH_PTSR) Transfer Bus Error Mask */
#define PDC_PERIPH_PTSR_ERR                 PDC_PERIPH_PTSR_ERR_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDC_PERIPH_PTSR_ERR_Msk instead */
#define PDC_PERIPH_PTSR_MASK                _U_(0x1050101)                                 /**< \deprecated (PDC_PERIPH_PTSR) Register MASK  (Use PDC_PERIPH_PTSR_Msk instead)  */
#define PDC_PERIPH_PTSR_Msk                 _U_(0x1050101)                                 /**< (PDC_PERIPH_PTSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief PDC hardware registers */
typedef struct {  
  __IO uint32_t PERIPH_RPR;     /**< (PDC Offset: 0x00) Receive Pointer Register */
  __IO uint32_t PERIPH_RCR;     /**< (PDC Offset: 0x04) Receive Counter Register */
  __IO uint32_t PERIPH_TPR;     /**< (PDC Offset: 0x08) Transmit Pointer Register */
  __IO uint32_t PERIPH_TCR;     /**< (PDC Offset: 0x0C) Transmit Counter Register */
  __IO uint32_t PERIPH_RNPR;    /**< (PDC Offset: 0x10) Receive Next Pointer Register */
  __IO uint32_t PERIPH_RNCR;    /**< (PDC Offset: 0x14) Receive Next Counter Register */
  __IO uint32_t PERIPH_TNPR;    /**< (PDC Offset: 0x18) Transmit Next Pointer Register */
  __IO uint32_t PERIPH_TNCR;    /**< (PDC Offset: 0x1C) Transmit Next Counter Register */
  __O  uint32_t PERIPH_PTCR;    /**< (PDC Offset: 0x20) Transfer Control Register */
  __I  uint32_t PERIPH_PTSR;    /**< (PDC Offset: 0x24) Transfer Status Register */
} Pdc;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief PDC hardware registers */
typedef struct {  
  __IO PDC_PERIPH_RPR_Type            PERIPH_RPR;     /**< Offset: 0x00 (R/W  32) Receive Pointer Register */
  __IO PDC_PERIPH_RCR_Type            PERIPH_RCR;     /**< Offset: 0x04 (R/W  32) Receive Counter Register */
  __IO PDC_PERIPH_TPR_Type            PERIPH_TPR;     /**< Offset: 0x08 (R/W  32) Transmit Pointer Register */
  __IO PDC_PERIPH_TCR_Type            PERIPH_TCR;     /**< Offset: 0x0C (R/W  32) Transmit Counter Register */
  __IO PDC_PERIPH_RNPR_Type           PERIPH_RNPR;    /**< Offset: 0x10 (R/W  32) Receive Next Pointer Register */
  __IO PDC_PERIPH_RNCR_Type           PERIPH_RNCR;    /**< Offset: 0x14 (R/W  32) Receive Next Counter Register */
  __IO PDC_PERIPH_TNPR_Type           PERIPH_TNPR;    /**< Offset: 0x18 (R/W  32) Transmit Next Pointer Register */
  __IO PDC_PERIPH_TNCR_Type           PERIPH_TNCR;    /**< Offset: 0x1C (R/W  32) Transmit Next Counter Register */
  __O  PDC_PERIPH_PTCR_Type           PERIPH_PTCR;    /**< Offset: 0x20 ( /W  32) Transfer Control Register */
  __I  PDC_PERIPH_PTSR_Type           PERIPH_PTSR;    /**< Offset: 0x24 (R/   32) Transfer Status Register */
} Pdc;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Peripheral DMA Controller */

#endif /* _SAMG55_PDC_COMPONENT_H_ */
