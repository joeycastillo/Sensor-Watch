/**
 * \file
 *
 * \brief Component description for MEM2MEM
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
#ifndef _SAMG55_MEM2MEM_COMPONENT_H_
#define _SAMG55_MEM2MEM_COMPONENT_H_
#define _SAMG55_MEM2MEM_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Memory to Memory
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR MEM2MEM */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define MEM2MEM_11211                      /**< (MEM2MEM) Module ID */
#define REV_MEM2MEM B                      /**< (MEM2MEM) Module revision */

/* -------- MEM2MEM_THR : (MEM2MEM Offset: 0x00) (R/W 32) Memory to Memory Transfer Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t THDATA:32;                 /**< bit:  0..31  Transfer Holding Data                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_THR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_THR_OFFSET                  (0x00)                                        /**<  (MEM2MEM_THR) Memory to Memory Transfer Holding Register  Offset */

#define MEM2MEM_THR_THDATA_Pos              0                                              /**< (MEM2MEM_THR) Transfer Holding Data Position */
#define MEM2MEM_THR_THDATA_Msk              (_U_(0xFFFFFFFF) << MEM2MEM_THR_THDATA_Pos)    /**< (MEM2MEM_THR) Transfer Holding Data Mask */
#define MEM2MEM_THR_THDATA(value)           (MEM2MEM_THR_THDATA_Msk & ((value) << MEM2MEM_THR_THDATA_Pos))
#define MEM2MEM_THR_MASK                    _U_(0xFFFFFFFF)                                /**< \deprecated (MEM2MEM_THR) Register MASK  (Use MEM2MEM_THR_Msk instead)  */
#define MEM2MEM_THR_Msk                     _U_(0xFFFFFFFF)                                /**< (MEM2MEM_THR) Register Mask  */


/* -------- MEM2MEM_MR : (MEM2MEM Offset: 0x04) (R/W 32) Memory to Memory Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TSIZE:2;                   /**< bit:   0..1  Transfer Size                            */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_MR_OFFSET                   (0x04)                                        /**<  (MEM2MEM_MR) Memory to Memory Mode Register  Offset */

#define MEM2MEM_MR_TSIZE_Pos                0                                              /**< (MEM2MEM_MR) Transfer Size Position */
#define MEM2MEM_MR_TSIZE_Msk                (_U_(0x3) << MEM2MEM_MR_TSIZE_Pos)             /**< (MEM2MEM_MR) Transfer Size Mask */
#define MEM2MEM_MR_TSIZE(value)             (MEM2MEM_MR_TSIZE_Msk & ((value) << MEM2MEM_MR_TSIZE_Pos))
#define   MEM2MEM_MR_TSIZE_T_8BIT_Val       _U_(0x0)                                       /**< (MEM2MEM_MR) The buffer size is defined in byte.  */
#define   MEM2MEM_MR_TSIZE_T_16BIT_Val      _U_(0x1)                                       /**< (MEM2MEM_MR) The buffer size is defined in half-word (16-bit).  */
#define   MEM2MEM_MR_TSIZE_T_32BIT_Val      _U_(0x2)                                       /**< (MEM2MEM_MR) The buffer size is defined in word (32-bit). Default value.  */
#define MEM2MEM_MR_TSIZE_T_8BIT             (MEM2MEM_MR_TSIZE_T_8BIT_Val << MEM2MEM_MR_TSIZE_Pos)  /**< (MEM2MEM_MR) The buffer size is defined in byte. Position  */
#define MEM2MEM_MR_TSIZE_T_16BIT            (MEM2MEM_MR_TSIZE_T_16BIT_Val << MEM2MEM_MR_TSIZE_Pos)  /**< (MEM2MEM_MR) The buffer size is defined in half-word (16-bit). Position  */
#define MEM2MEM_MR_TSIZE_T_32BIT            (MEM2MEM_MR_TSIZE_T_32BIT_Val << MEM2MEM_MR_TSIZE_Pos)  /**< (MEM2MEM_MR) The buffer size is defined in word (32-bit). Default value. Position  */
#define MEM2MEM_MR_MASK                     _U_(0x03)                                      /**< \deprecated (MEM2MEM_MR) Register MASK  (Use MEM2MEM_MR_Msk instead)  */
#define MEM2MEM_MR_Msk                      _U_(0x03)                                      /**< (MEM2MEM_MR) Register Mask  */


/* -------- MEM2MEM_IER : (MEM2MEM Offset: 0x08) (/W 32) Memory to Memory Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXEND:1;                   /**< bit:      0  End of Transfer Interrupt Enable         */
    uint32_t RXBUFF:1;                  /**< bit:      1  Buffer Full Interrupt Enable             */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_IER_OFFSET                  (0x08)                                        /**<  (MEM2MEM_IER) Memory to Memory Interrupt Enable Register  Offset */

#define MEM2MEM_IER_RXEND_Pos               0                                              /**< (MEM2MEM_IER) End of Transfer Interrupt Enable Position */
#define MEM2MEM_IER_RXEND_Msk               (_U_(0x1) << MEM2MEM_IER_RXEND_Pos)            /**< (MEM2MEM_IER) End of Transfer Interrupt Enable Mask */
#define MEM2MEM_IER_RXEND                   MEM2MEM_IER_RXEND_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_IER_RXEND_Msk instead */
#define MEM2MEM_IER_RXBUFF_Pos              1                                              /**< (MEM2MEM_IER) Buffer Full Interrupt Enable Position */
#define MEM2MEM_IER_RXBUFF_Msk              (_U_(0x1) << MEM2MEM_IER_RXBUFF_Pos)           /**< (MEM2MEM_IER) Buffer Full Interrupt Enable Mask */
#define MEM2MEM_IER_RXBUFF                  MEM2MEM_IER_RXBUFF_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_IER_RXBUFF_Msk instead */
#define MEM2MEM_IER_MASK                    _U_(0x03)                                      /**< \deprecated (MEM2MEM_IER) Register MASK  (Use MEM2MEM_IER_Msk instead)  */
#define MEM2MEM_IER_Msk                     _U_(0x03)                                      /**< (MEM2MEM_IER) Register Mask  */


/* -------- MEM2MEM_IDR : (MEM2MEM Offset: 0x0c) (/W 32) Memory to Memory Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXEND:1;                   /**< bit:      0  End of Transfer Interrupt Disable        */
    uint32_t RXBUFF:1;                  /**< bit:      1  Buffer Full Interrupt Disable            */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_IDR_OFFSET                  (0x0C)                                        /**<  (MEM2MEM_IDR) Memory to Memory Interrupt Disable Register  Offset */

#define MEM2MEM_IDR_RXEND_Pos               0                                              /**< (MEM2MEM_IDR) End of Transfer Interrupt Disable Position */
#define MEM2MEM_IDR_RXEND_Msk               (_U_(0x1) << MEM2MEM_IDR_RXEND_Pos)            /**< (MEM2MEM_IDR) End of Transfer Interrupt Disable Mask */
#define MEM2MEM_IDR_RXEND                   MEM2MEM_IDR_RXEND_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_IDR_RXEND_Msk instead */
#define MEM2MEM_IDR_RXBUFF_Pos              1                                              /**< (MEM2MEM_IDR) Buffer Full Interrupt Disable Position */
#define MEM2MEM_IDR_RXBUFF_Msk              (_U_(0x1) << MEM2MEM_IDR_RXBUFF_Pos)           /**< (MEM2MEM_IDR) Buffer Full Interrupt Disable Mask */
#define MEM2MEM_IDR_RXBUFF                  MEM2MEM_IDR_RXBUFF_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_IDR_RXBUFF_Msk instead */
#define MEM2MEM_IDR_MASK                    _U_(0x03)                                      /**< \deprecated (MEM2MEM_IDR) Register MASK  (Use MEM2MEM_IDR_Msk instead)  */
#define MEM2MEM_IDR_Msk                     _U_(0x03)                                      /**< (MEM2MEM_IDR) Register Mask  */


/* -------- MEM2MEM_IMR : (MEM2MEM Offset: 0x10) (R/ 32) Memory to Memory Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXEND:1;                   /**< bit:      0  End of Transfer Interrupt Mask           */
    uint32_t RXBUFF:1;                  /**< bit:      1  Buffer Full Interrupt Mask               */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_IMR_OFFSET                  (0x10)                                        /**<  (MEM2MEM_IMR) Memory to Memory Interrupt Mask Register  Offset */

#define MEM2MEM_IMR_RXEND_Pos               0                                              /**< (MEM2MEM_IMR) End of Transfer Interrupt Mask Position */
#define MEM2MEM_IMR_RXEND_Msk               (_U_(0x1) << MEM2MEM_IMR_RXEND_Pos)            /**< (MEM2MEM_IMR) End of Transfer Interrupt Mask Mask */
#define MEM2MEM_IMR_RXEND                   MEM2MEM_IMR_RXEND_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_IMR_RXEND_Msk instead */
#define MEM2MEM_IMR_RXBUFF_Pos              1                                              /**< (MEM2MEM_IMR) Buffer Full Interrupt Mask Position */
#define MEM2MEM_IMR_RXBUFF_Msk              (_U_(0x1) << MEM2MEM_IMR_RXBUFF_Pos)           /**< (MEM2MEM_IMR) Buffer Full Interrupt Mask Mask */
#define MEM2MEM_IMR_RXBUFF                  MEM2MEM_IMR_RXBUFF_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_IMR_RXBUFF_Msk instead */
#define MEM2MEM_IMR_MASK                    _U_(0x03)                                      /**< \deprecated (MEM2MEM_IMR) Register MASK  (Use MEM2MEM_IMR_Msk instead)  */
#define MEM2MEM_IMR_Msk                     _U_(0x03)                                      /**< (MEM2MEM_IMR) Register Mask  */


/* -------- MEM2MEM_ISR : (MEM2MEM Offset: 0x14) (R/ 32) Memory to Memory Interrupt Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXEND:1;                   /**< bit:      0  End of Transfer                          */
    uint32_t RXBUFF:1;                  /**< bit:      1  Buffer Full                              */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_ISR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_ISR_OFFSET                  (0x14)                                        /**<  (MEM2MEM_ISR) Memory to Memory Interrupt Status Register  Offset */

#define MEM2MEM_ISR_RXEND_Pos               0                                              /**< (MEM2MEM_ISR) End of Transfer Position */
#define MEM2MEM_ISR_RXEND_Msk               (_U_(0x1) << MEM2MEM_ISR_RXEND_Pos)            /**< (MEM2MEM_ISR) End of Transfer Mask */
#define MEM2MEM_ISR_RXEND                   MEM2MEM_ISR_RXEND_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_ISR_RXEND_Msk instead */
#define MEM2MEM_ISR_RXBUFF_Pos              1                                              /**< (MEM2MEM_ISR) Buffer Full Position */
#define MEM2MEM_ISR_RXBUFF_Msk              (_U_(0x1) << MEM2MEM_ISR_RXBUFF_Pos)           /**< (MEM2MEM_ISR) Buffer Full Mask */
#define MEM2MEM_ISR_RXBUFF                  MEM2MEM_ISR_RXBUFF_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_ISR_RXBUFF_Msk instead */
#define MEM2MEM_ISR_MASK                    _U_(0x03)                                      /**< \deprecated (MEM2MEM_ISR) Register MASK  (Use MEM2MEM_ISR_Msk instead)  */
#define MEM2MEM_ISR_Msk                     _U_(0x03)                                      /**< (MEM2MEM_ISR) Register Mask  */


/* -------- MEM2MEM_RPR : (MEM2MEM Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_RPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_RPR_OFFSET                  (0x100)                                       /**<  (MEM2MEM_RPR) Receive Pointer Register  Offset */

#define MEM2MEM_RPR_RXPTR_Pos               0                                              /**< (MEM2MEM_RPR) Receive Pointer Register Position */
#define MEM2MEM_RPR_RXPTR_Msk               (_U_(0xFFFFFFFF) << MEM2MEM_RPR_RXPTR_Pos)     /**< (MEM2MEM_RPR) Receive Pointer Register Mask */
#define MEM2MEM_RPR_RXPTR(value)            (MEM2MEM_RPR_RXPTR_Msk & ((value) << MEM2MEM_RPR_RXPTR_Pos))
#define MEM2MEM_RPR_MASK                    _U_(0xFFFFFFFF)                                /**< \deprecated (MEM2MEM_RPR) Register MASK  (Use MEM2MEM_RPR_Msk instead)  */
#define MEM2MEM_RPR_Msk                     _U_(0xFFFFFFFF)                                /**< (MEM2MEM_RPR) Register Mask  */


/* -------- MEM2MEM_RCR : (MEM2MEM Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCTR:16;                  /**< bit:  0..15  Receive Counter Register                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_RCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_RCR_OFFSET                  (0x104)                                       /**<  (MEM2MEM_RCR) Receive Counter Register  Offset */

#define MEM2MEM_RCR_RXCTR_Pos               0                                              /**< (MEM2MEM_RCR) Receive Counter Register Position */
#define MEM2MEM_RCR_RXCTR_Msk               (_U_(0xFFFF) << MEM2MEM_RCR_RXCTR_Pos)         /**< (MEM2MEM_RCR) Receive Counter Register Mask */
#define MEM2MEM_RCR_RXCTR(value)            (MEM2MEM_RCR_RXCTR_Msk & ((value) << MEM2MEM_RCR_RXCTR_Pos))
#define MEM2MEM_RCR_MASK                    _U_(0xFFFF)                                    /**< \deprecated (MEM2MEM_RCR) Register MASK  (Use MEM2MEM_RCR_Msk instead)  */
#define MEM2MEM_RCR_Msk                     _U_(0xFFFF)                                    /**< (MEM2MEM_RCR) Register Mask  */


/* -------- MEM2MEM_TPR : (MEM2MEM Offset: 0x108) (R/W 32) Transmit Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXPTR:32;                  /**< bit:  0..31  Transmit Counter Register                */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_TPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_TPR_OFFSET                  (0x108)                                       /**<  (MEM2MEM_TPR) Transmit Pointer Register  Offset */

#define MEM2MEM_TPR_TXPTR_Pos               0                                              /**< (MEM2MEM_TPR) Transmit Counter Register Position */
#define MEM2MEM_TPR_TXPTR_Msk               (_U_(0xFFFFFFFF) << MEM2MEM_TPR_TXPTR_Pos)     /**< (MEM2MEM_TPR) Transmit Counter Register Mask */
#define MEM2MEM_TPR_TXPTR(value)            (MEM2MEM_TPR_TXPTR_Msk & ((value) << MEM2MEM_TPR_TXPTR_Pos))
#define MEM2MEM_TPR_MASK                    _U_(0xFFFFFFFF)                                /**< \deprecated (MEM2MEM_TPR) Register MASK  (Use MEM2MEM_TPR_Msk instead)  */
#define MEM2MEM_TPR_Msk                     _U_(0xFFFFFFFF)                                /**< (MEM2MEM_TPR) Register Mask  */


/* -------- MEM2MEM_TCR : (MEM2MEM Offset: 0x10c) (R/W 32) Transmit Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCTR:16;                  /**< bit:  0..15  Transmit Counter Register                */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_TCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_TCR_OFFSET                  (0x10C)                                       /**<  (MEM2MEM_TCR) Transmit Counter Register  Offset */

#define MEM2MEM_TCR_TXCTR_Pos               0                                              /**< (MEM2MEM_TCR) Transmit Counter Register Position */
#define MEM2MEM_TCR_TXCTR_Msk               (_U_(0xFFFF) << MEM2MEM_TCR_TXCTR_Pos)         /**< (MEM2MEM_TCR) Transmit Counter Register Mask */
#define MEM2MEM_TCR_TXCTR(value)            (MEM2MEM_TCR_TXCTR_Msk & ((value) << MEM2MEM_TCR_TXCTR_Pos))
#define MEM2MEM_TCR_MASK                    _U_(0xFFFF)                                    /**< \deprecated (MEM2MEM_TCR) Register MASK  (Use MEM2MEM_TCR_Msk instead)  */
#define MEM2MEM_TCR_Msk                     _U_(0xFFFF)                                    /**< (MEM2MEM_TCR) Register Mask  */


/* -------- MEM2MEM_RNPR : (MEM2MEM Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_RNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_RNPR_OFFSET                 (0x110)                                       /**<  (MEM2MEM_RNPR) Receive Next Pointer Register  Offset */

#define MEM2MEM_RNPR_RXNPTR_Pos             0                                              /**< (MEM2MEM_RNPR) Receive Next Pointer Position */
#define MEM2MEM_RNPR_RXNPTR_Msk             (_U_(0xFFFFFFFF) << MEM2MEM_RNPR_RXNPTR_Pos)   /**< (MEM2MEM_RNPR) Receive Next Pointer Mask */
#define MEM2MEM_RNPR_RXNPTR(value)          (MEM2MEM_RNPR_RXNPTR_Msk & ((value) << MEM2MEM_RNPR_RXNPTR_Pos))
#define MEM2MEM_RNPR_MASK                   _U_(0xFFFFFFFF)                                /**< \deprecated (MEM2MEM_RNPR) Register MASK  (Use MEM2MEM_RNPR_Msk instead)  */
#define MEM2MEM_RNPR_Msk                    _U_(0xFFFFFFFF)                                /**< (MEM2MEM_RNPR) Register Mask  */


/* -------- MEM2MEM_RNCR : (MEM2MEM Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_RNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_RNCR_OFFSET                 (0x114)                                       /**<  (MEM2MEM_RNCR) Receive Next Counter Register  Offset */

#define MEM2MEM_RNCR_RXNCTR_Pos             0                                              /**< (MEM2MEM_RNCR) Receive Next Counter Position */
#define MEM2MEM_RNCR_RXNCTR_Msk             (_U_(0xFFFF) << MEM2MEM_RNCR_RXNCTR_Pos)       /**< (MEM2MEM_RNCR) Receive Next Counter Mask */
#define MEM2MEM_RNCR_RXNCTR(value)          (MEM2MEM_RNCR_RXNCTR_Msk & ((value) << MEM2MEM_RNCR_RXNCTR_Pos))
#define MEM2MEM_RNCR_MASK                   _U_(0xFFFF)                                    /**< \deprecated (MEM2MEM_RNCR) Register MASK  (Use MEM2MEM_RNCR_Msk instead)  */
#define MEM2MEM_RNCR_Msk                    _U_(0xFFFF)                                    /**< (MEM2MEM_RNCR) Register Mask  */


/* -------- MEM2MEM_TNPR : (MEM2MEM Offset: 0x118) (R/W 32) Transmit Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNPTR:32;                 /**< bit:  0..31  Transmit Next Pointer                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_TNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_TNPR_OFFSET                 (0x118)                                       /**<  (MEM2MEM_TNPR) Transmit Next Pointer Register  Offset */

#define MEM2MEM_TNPR_TXNPTR_Pos             0                                              /**< (MEM2MEM_TNPR) Transmit Next Pointer Position */
#define MEM2MEM_TNPR_TXNPTR_Msk             (_U_(0xFFFFFFFF) << MEM2MEM_TNPR_TXNPTR_Pos)   /**< (MEM2MEM_TNPR) Transmit Next Pointer Mask */
#define MEM2MEM_TNPR_TXNPTR(value)          (MEM2MEM_TNPR_TXNPTR_Msk & ((value) << MEM2MEM_TNPR_TXNPTR_Pos))
#define MEM2MEM_TNPR_MASK                   _U_(0xFFFFFFFF)                                /**< \deprecated (MEM2MEM_TNPR) Register MASK  (Use MEM2MEM_TNPR_Msk instead)  */
#define MEM2MEM_TNPR_Msk                    _U_(0xFFFFFFFF)                                /**< (MEM2MEM_TNPR) Register Mask  */


/* -------- MEM2MEM_TNCR : (MEM2MEM Offset: 0x11c) (R/W 32) Transmit Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNCTR:16;                 /**< bit:  0..15  Transmit Counter Next                    */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} MEM2MEM_TNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_TNCR_OFFSET                 (0x11C)                                       /**<  (MEM2MEM_TNCR) Transmit Next Counter Register  Offset */

#define MEM2MEM_TNCR_TXNCTR_Pos             0                                              /**< (MEM2MEM_TNCR) Transmit Counter Next Position */
#define MEM2MEM_TNCR_TXNCTR_Msk             (_U_(0xFFFF) << MEM2MEM_TNCR_TXNCTR_Pos)       /**< (MEM2MEM_TNCR) Transmit Counter Next Mask */
#define MEM2MEM_TNCR_TXNCTR(value)          (MEM2MEM_TNCR_TXNCTR_Msk & ((value) << MEM2MEM_TNCR_TXNCTR_Pos))
#define MEM2MEM_TNCR_MASK                   _U_(0xFFFF)                                    /**< \deprecated (MEM2MEM_TNCR) Register MASK  (Use MEM2MEM_TNCR_Msk instead)  */
#define MEM2MEM_TNCR_Msk                    _U_(0xFFFF)                                    /**< (MEM2MEM_TNCR) Register Mask  */


/* -------- MEM2MEM_PTCR : (MEM2MEM Offset: 0x120) (/W 32) Transfer Control Register -------- */
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
} MEM2MEM_PTCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_PTCR_OFFSET                 (0x120)                                       /**<  (MEM2MEM_PTCR) Transfer Control Register  Offset */

#define MEM2MEM_PTCR_RXTEN_Pos              0                                              /**< (MEM2MEM_PTCR) Receiver Transfer Enable Position */
#define MEM2MEM_PTCR_RXTEN_Msk              (_U_(0x1) << MEM2MEM_PTCR_RXTEN_Pos)           /**< (MEM2MEM_PTCR) Receiver Transfer Enable Mask */
#define MEM2MEM_PTCR_RXTEN                  MEM2MEM_PTCR_RXTEN_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_RXTEN_Msk instead */
#define MEM2MEM_PTCR_RXTDIS_Pos             1                                              /**< (MEM2MEM_PTCR) Receiver Transfer Disable Position */
#define MEM2MEM_PTCR_RXTDIS_Msk             (_U_(0x1) << MEM2MEM_PTCR_RXTDIS_Pos)          /**< (MEM2MEM_PTCR) Receiver Transfer Disable Mask */
#define MEM2MEM_PTCR_RXTDIS                 MEM2MEM_PTCR_RXTDIS_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_RXTDIS_Msk instead */
#define MEM2MEM_PTCR_TXTEN_Pos              8                                              /**< (MEM2MEM_PTCR) Transmitter Transfer Enable Position */
#define MEM2MEM_PTCR_TXTEN_Msk              (_U_(0x1) << MEM2MEM_PTCR_TXTEN_Pos)           /**< (MEM2MEM_PTCR) Transmitter Transfer Enable Mask */
#define MEM2MEM_PTCR_TXTEN                  MEM2MEM_PTCR_TXTEN_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_TXTEN_Msk instead */
#define MEM2MEM_PTCR_TXTDIS_Pos             9                                              /**< (MEM2MEM_PTCR) Transmitter Transfer Disable Position */
#define MEM2MEM_PTCR_TXTDIS_Msk             (_U_(0x1) << MEM2MEM_PTCR_TXTDIS_Pos)          /**< (MEM2MEM_PTCR) Transmitter Transfer Disable Mask */
#define MEM2MEM_PTCR_TXTDIS                 MEM2MEM_PTCR_TXTDIS_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_TXTDIS_Msk instead */
#define MEM2MEM_PTCR_RXCBEN_Pos             16                                             /**< (MEM2MEM_PTCR) Receiver Circular Buffer Enable Position */
#define MEM2MEM_PTCR_RXCBEN_Msk             (_U_(0x1) << MEM2MEM_PTCR_RXCBEN_Pos)          /**< (MEM2MEM_PTCR) Receiver Circular Buffer Enable Mask */
#define MEM2MEM_PTCR_RXCBEN                 MEM2MEM_PTCR_RXCBEN_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_RXCBEN_Msk instead */
#define MEM2MEM_PTCR_RXCBDIS_Pos            17                                             /**< (MEM2MEM_PTCR) Receiver Circular Buffer Disable Position */
#define MEM2MEM_PTCR_RXCBDIS_Msk            (_U_(0x1) << MEM2MEM_PTCR_RXCBDIS_Pos)         /**< (MEM2MEM_PTCR) Receiver Circular Buffer Disable Mask */
#define MEM2MEM_PTCR_RXCBDIS                MEM2MEM_PTCR_RXCBDIS_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_RXCBDIS_Msk instead */
#define MEM2MEM_PTCR_TXCBEN_Pos             18                                             /**< (MEM2MEM_PTCR) Transmitter Circular Buffer Enable Position */
#define MEM2MEM_PTCR_TXCBEN_Msk             (_U_(0x1) << MEM2MEM_PTCR_TXCBEN_Pos)          /**< (MEM2MEM_PTCR) Transmitter Circular Buffer Enable Mask */
#define MEM2MEM_PTCR_TXCBEN                 MEM2MEM_PTCR_TXCBEN_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_TXCBEN_Msk instead */
#define MEM2MEM_PTCR_TXCBDIS_Pos            19                                             /**< (MEM2MEM_PTCR) Transmitter Circular Buffer Disable Position */
#define MEM2MEM_PTCR_TXCBDIS_Msk            (_U_(0x1) << MEM2MEM_PTCR_TXCBDIS_Pos)         /**< (MEM2MEM_PTCR) Transmitter Circular Buffer Disable Mask */
#define MEM2MEM_PTCR_TXCBDIS                MEM2MEM_PTCR_TXCBDIS_Msk                       /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_TXCBDIS_Msk instead */
#define MEM2MEM_PTCR_ERRCLR_Pos             24                                             /**< (MEM2MEM_PTCR) Transfer Bus Error Clear Position */
#define MEM2MEM_PTCR_ERRCLR_Msk             (_U_(0x1) << MEM2MEM_PTCR_ERRCLR_Pos)          /**< (MEM2MEM_PTCR) Transfer Bus Error Clear Mask */
#define MEM2MEM_PTCR_ERRCLR                 MEM2MEM_PTCR_ERRCLR_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTCR_ERRCLR_Msk instead */
#define MEM2MEM_PTCR_MASK                   _U_(0x10F0303)                                 /**< \deprecated (MEM2MEM_PTCR) Register MASK  (Use MEM2MEM_PTCR_Msk instead)  */
#define MEM2MEM_PTCR_Msk                    _U_(0x10F0303)                                 /**< (MEM2MEM_PTCR) Register Mask  */


/* -------- MEM2MEM_PTSR : (MEM2MEM Offset: 0x124) (R/ 32) Transfer Status Register -------- */
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
} MEM2MEM_PTSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define MEM2MEM_PTSR_OFFSET                 (0x124)                                       /**<  (MEM2MEM_PTSR) Transfer Status Register  Offset */

#define MEM2MEM_PTSR_RXTEN_Pos              0                                              /**< (MEM2MEM_PTSR) Receiver Transfer Enable Position */
#define MEM2MEM_PTSR_RXTEN_Msk              (_U_(0x1) << MEM2MEM_PTSR_RXTEN_Pos)           /**< (MEM2MEM_PTSR) Receiver Transfer Enable Mask */
#define MEM2MEM_PTSR_RXTEN                  MEM2MEM_PTSR_RXTEN_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTSR_RXTEN_Msk instead */
#define MEM2MEM_PTSR_TXTEN_Pos              8                                              /**< (MEM2MEM_PTSR) Transmitter Transfer Enable Position */
#define MEM2MEM_PTSR_TXTEN_Msk              (_U_(0x1) << MEM2MEM_PTSR_TXTEN_Pos)           /**< (MEM2MEM_PTSR) Transmitter Transfer Enable Mask */
#define MEM2MEM_PTSR_TXTEN                  MEM2MEM_PTSR_TXTEN_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTSR_TXTEN_Msk instead */
#define MEM2MEM_PTSR_RXCBEN_Pos             16                                             /**< (MEM2MEM_PTSR) Receiver Circular Buffer Enable Position */
#define MEM2MEM_PTSR_RXCBEN_Msk             (_U_(0x1) << MEM2MEM_PTSR_RXCBEN_Pos)          /**< (MEM2MEM_PTSR) Receiver Circular Buffer Enable Mask */
#define MEM2MEM_PTSR_RXCBEN                 MEM2MEM_PTSR_RXCBEN_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTSR_RXCBEN_Msk instead */
#define MEM2MEM_PTSR_TXCBEN_Pos             18                                             /**< (MEM2MEM_PTSR) Transmitter Circular Buffer Enable Position */
#define MEM2MEM_PTSR_TXCBEN_Msk             (_U_(0x1) << MEM2MEM_PTSR_TXCBEN_Pos)          /**< (MEM2MEM_PTSR) Transmitter Circular Buffer Enable Mask */
#define MEM2MEM_PTSR_TXCBEN                 MEM2MEM_PTSR_TXCBEN_Msk                        /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTSR_TXCBEN_Msk instead */
#define MEM2MEM_PTSR_ERR_Pos                24                                             /**< (MEM2MEM_PTSR) Transfer Bus Error Position */
#define MEM2MEM_PTSR_ERR_Msk                (_U_(0x1) << MEM2MEM_PTSR_ERR_Pos)             /**< (MEM2MEM_PTSR) Transfer Bus Error Mask */
#define MEM2MEM_PTSR_ERR                    MEM2MEM_PTSR_ERR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use MEM2MEM_PTSR_ERR_Msk instead */
#define MEM2MEM_PTSR_MASK                   _U_(0x1050101)                                 /**< \deprecated (MEM2MEM_PTSR) Register MASK  (Use MEM2MEM_PTSR_Msk instead)  */
#define MEM2MEM_PTSR_Msk                    _U_(0x1050101)                                 /**< (MEM2MEM_PTSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief MEM2MEM hardware registers */
typedef struct {  
  __IO uint32_t MEM2MEM_THR;    /**< (MEM2MEM Offset: 0x00) Memory to Memory Transfer Holding Register */
  __IO uint32_t MEM2MEM_MR;     /**< (MEM2MEM Offset: 0x04) Memory to Memory Mode Register */
  __O  uint32_t MEM2MEM_IER;    /**< (MEM2MEM Offset: 0x08) Memory to Memory Interrupt Enable Register */
  __O  uint32_t MEM2MEM_IDR;    /**< (MEM2MEM Offset: 0x0C) Memory to Memory Interrupt Disable Register */
  __I  uint32_t MEM2MEM_IMR;    /**< (MEM2MEM Offset: 0x10) Memory to Memory Interrupt Mask Register */
  __I  uint32_t MEM2MEM_ISR;    /**< (MEM2MEM Offset: 0x14) Memory to Memory Interrupt Status Register */
  RoReg8  Reserved1[0xE8];
  __IO uint32_t MEM2MEM_RPR;    /**< (MEM2MEM Offset: 0x100) Receive Pointer Register */
  __IO uint32_t MEM2MEM_RCR;    /**< (MEM2MEM Offset: 0x104) Receive Counter Register */
  __IO uint32_t MEM2MEM_TPR;    /**< (MEM2MEM Offset: 0x108) Transmit Pointer Register */
  __IO uint32_t MEM2MEM_TCR;    /**< (MEM2MEM Offset: 0x10C) Transmit Counter Register */
  __IO uint32_t MEM2MEM_RNPR;   /**< (MEM2MEM Offset: 0x110) Receive Next Pointer Register */
  __IO uint32_t MEM2MEM_RNCR;   /**< (MEM2MEM Offset: 0x114) Receive Next Counter Register */
  __IO uint32_t MEM2MEM_TNPR;   /**< (MEM2MEM Offset: 0x118) Transmit Next Pointer Register */
  __IO uint32_t MEM2MEM_TNCR;   /**< (MEM2MEM Offset: 0x11C) Transmit Next Counter Register */
  __O  uint32_t MEM2MEM_PTCR;   /**< (MEM2MEM Offset: 0x120) Transfer Control Register */
  __I  uint32_t MEM2MEM_PTSR;   /**< (MEM2MEM Offset: 0x124) Transfer Status Register */
} Mem2mem;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief MEM2MEM hardware registers */
typedef struct {  
  __IO MEM2MEM_THR_Type               MEM2MEM_THR;    /**< Offset: 0x00 (R/W  32) Memory to Memory Transfer Holding Register */
  __IO MEM2MEM_MR_Type                MEM2MEM_MR;     /**< Offset: 0x04 (R/W  32) Memory to Memory Mode Register */
  __O  MEM2MEM_IER_Type               MEM2MEM_IER;    /**< Offset: 0x08 ( /W  32) Memory to Memory Interrupt Enable Register */
  __O  MEM2MEM_IDR_Type               MEM2MEM_IDR;    /**< Offset: 0x0C ( /W  32) Memory to Memory Interrupt Disable Register */
  __I  MEM2MEM_IMR_Type               MEM2MEM_IMR;    /**< Offset: 0x10 (R/   32) Memory to Memory Interrupt Mask Register */
  __I  MEM2MEM_ISR_Type               MEM2MEM_ISR;    /**< Offset: 0x14 (R/   32) Memory to Memory Interrupt Status Register */
  __I  uint32_t                       Reserved1[58];
  __IO MEM2MEM_RPR_Type               MEM2MEM_RPR;    /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO MEM2MEM_RCR_Type               MEM2MEM_RCR;    /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __IO MEM2MEM_TPR_Type               MEM2MEM_TPR;    /**< Offset: 0x108 (R/W  32) Transmit Pointer Register */
  __IO MEM2MEM_TCR_Type               MEM2MEM_TCR;    /**< Offset: 0x10C (R/W  32) Transmit Counter Register */
  __IO MEM2MEM_RNPR_Type              MEM2MEM_RNPR;   /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO MEM2MEM_RNCR_Type              MEM2MEM_RNCR;   /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __IO MEM2MEM_TNPR_Type              MEM2MEM_TNPR;   /**< Offset: 0x118 (R/W  32) Transmit Next Pointer Register */
  __IO MEM2MEM_TNCR_Type              MEM2MEM_TNCR;   /**< Offset: 0x11C (R/W  32) Transmit Next Counter Register */
  __O  MEM2MEM_PTCR_Type              MEM2MEM_PTCR;   /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I  MEM2MEM_PTSR_Type              MEM2MEM_PTSR;   /**< Offset: 0x124 (R/   32) Transfer Status Register */
} Mem2mem;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Memory to Memory */

#endif /* _SAMG55_MEM2MEM_COMPONENT_H_ */
