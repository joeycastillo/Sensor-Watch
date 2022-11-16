/**
 * \file
 *
 * \brief Component description for PDMIC
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
#ifndef _SAMG55_PDMIC_COMPONENT_H_
#define _SAMG55_PDMIC_COMPONENT_H_
#define _SAMG55_PDMIC_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Pulse Density Modulation Interface Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PDMIC */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define PDMIC_11237                      /**< (PDMIC) Module ID */
#define REV_PDMIC D                      /**< (PDMIC) Module revision */

/* -------- PDMIC_CR : (PDMIC Offset: 0x00) (R/W 32) Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SWRST:1;                   /**< bit:      0  Software Reset                           */
    uint32_t :3;                        /**< bit:   1..3  Reserved */
    uint32_t ENPDM:1;                   /**< bit:      4  Enable PDM                               */
    uint32_t :27;                       /**< bit:  5..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_CR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_CR_OFFSET                     (0x00)                                        /**<  (PDMIC_CR) Control Register  Offset */

#define PDMIC_CR_SWRST_Pos                  0                                              /**< (PDMIC_CR) Software Reset Position */
#define PDMIC_CR_SWRST_Msk                  (_U_(0x1) << PDMIC_CR_SWRST_Pos)               /**< (PDMIC_CR) Software Reset Mask */
#define PDMIC_CR_SWRST                      PDMIC_CR_SWRST_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_CR_SWRST_Msk instead */
#define PDMIC_CR_ENPDM_Pos                  4                                              /**< (PDMIC_CR) Enable PDM Position */
#define PDMIC_CR_ENPDM_Msk                  (_U_(0x1) << PDMIC_CR_ENPDM_Pos)               /**< (PDMIC_CR) Enable PDM Mask */
#define PDMIC_CR_ENPDM                      PDMIC_CR_ENPDM_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_CR_ENPDM_Msk instead */
#define PDMIC_CR_MASK                       _U_(0x11)                                      /**< \deprecated (PDMIC_CR) Register MASK  (Use PDMIC_CR_Msk instead)  */
#define PDMIC_CR_Msk                        _U_(0x11)                                      /**< (PDMIC_CR) Register Mask  */


/* -------- PDMIC_MR : (PDMIC Offset: 0x04) (R/W 32) Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :4;                        /**< bit:   0..3  Reserved */
    uint32_t CLKS:1;                    /**< bit:      4  Clock Source Selection                   */
    uint32_t :3;                        /**< bit:   5..7  Reserved */
    uint32_t PRESCAL:7;                 /**< bit:  8..14  Prescaler Rate Selection                 */
    uint32_t :17;                       /**< bit: 15..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_MR_OFFSET                     (0x04)                                        /**<  (PDMIC_MR) Mode Register  Offset */

#define PDMIC_MR_CLKS_Pos                   4                                              /**< (PDMIC_MR) Clock Source Selection Position */
#define PDMIC_MR_CLKS_Msk                   (_U_(0x1) << PDMIC_MR_CLKS_Pos)                /**< (PDMIC_MR) Clock Source Selection Mask */
#define PDMIC_MR_CLKS                       PDMIC_MR_CLKS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_MR_CLKS_Msk instead */
#define PDMIC_MR_PRESCAL_Pos                8                                              /**< (PDMIC_MR) Prescaler Rate Selection Position */
#define PDMIC_MR_PRESCAL_Msk                (_U_(0x7F) << PDMIC_MR_PRESCAL_Pos)            /**< (PDMIC_MR) Prescaler Rate Selection Mask */
#define PDMIC_MR_PRESCAL(value)             (PDMIC_MR_PRESCAL_Msk & ((value) << PDMIC_MR_PRESCAL_Pos))
#define PDMIC_MR_MASK                       _U_(0x7F10)                                    /**< \deprecated (PDMIC_MR) Register MASK  (Use PDMIC_MR_Msk instead)  */
#define PDMIC_MR_Msk                        _U_(0x7F10)                                    /**< (PDMIC_MR) Register Mask  */


/* -------- PDMIC_CDR : (PDMIC Offset: 0x14) (R/ 32) Converted Data Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DATA:32;                   /**< bit:  0..31  Data Converted                           */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_CDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_CDR_OFFSET                    (0x14)                                        /**<  (PDMIC_CDR) Converted Data Register  Offset */

#define PDMIC_CDR_DATA_Pos                  0                                              /**< (PDMIC_CDR) Data Converted Position */
#define PDMIC_CDR_DATA_Msk                  (_U_(0xFFFFFFFF) << PDMIC_CDR_DATA_Pos)        /**< (PDMIC_CDR) Data Converted Mask */
#define PDMIC_CDR_DATA(value)               (PDMIC_CDR_DATA_Msk & ((value) << PDMIC_CDR_DATA_Pos))
#define PDMIC_CDR_MASK                      _U_(0xFFFFFFFF)                                /**< \deprecated (PDMIC_CDR) Register MASK  (Use PDMIC_CDR_Msk instead)  */
#define PDMIC_CDR_Msk                       _U_(0xFFFFFFFF)                                /**< (PDMIC_CDR) Register Mask  */


/* -------- PDMIC_IER : (PDMIC Offset: 0x18) (/W 32) Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :24;                       /**< bit:  0..23  Reserved */
    uint32_t DRDY:1;                    /**< bit:     24  Data Ready Interrupt Enable              */
    uint32_t OVRE:1;                    /**< bit:     25  Overrun Error Interrupt Enable           */
    uint32_t :1;                        /**< bit:     26  Reserved */
    uint32_t ENDRX:1;                   /**< bit:     27  End of Receive Buffer Interrupt Enable   */
    uint32_t RXBUFF:1;                  /**< bit:     28  Receive Buffer Full Interrupt Enable     */
    uint32_t :3;                        /**< bit: 29..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_IER_OFFSET                    (0x18)                                        /**<  (PDMIC_IER) Interrupt Enable Register  Offset */

#define PDMIC_IER_DRDY_Pos                  24                                             /**< (PDMIC_IER) Data Ready Interrupt Enable Position */
#define PDMIC_IER_DRDY_Msk                  (_U_(0x1) << PDMIC_IER_DRDY_Pos)               /**< (PDMIC_IER) Data Ready Interrupt Enable Mask */
#define PDMIC_IER_DRDY                      PDMIC_IER_DRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IER_DRDY_Msk instead */
#define PDMIC_IER_OVRE_Pos                  25                                             /**< (PDMIC_IER) Overrun Error Interrupt Enable Position */
#define PDMIC_IER_OVRE_Msk                  (_U_(0x1) << PDMIC_IER_OVRE_Pos)               /**< (PDMIC_IER) Overrun Error Interrupt Enable Mask */
#define PDMIC_IER_OVRE                      PDMIC_IER_OVRE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IER_OVRE_Msk instead */
#define PDMIC_IER_ENDRX_Pos                 27                                             /**< (PDMIC_IER) End of Receive Buffer Interrupt Enable Position */
#define PDMIC_IER_ENDRX_Msk                 (_U_(0x1) << PDMIC_IER_ENDRX_Pos)              /**< (PDMIC_IER) End of Receive Buffer Interrupt Enable Mask */
#define PDMIC_IER_ENDRX                     PDMIC_IER_ENDRX_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IER_ENDRX_Msk instead */
#define PDMIC_IER_RXBUFF_Pos                28                                             /**< (PDMIC_IER) Receive Buffer Full Interrupt Enable Position */
#define PDMIC_IER_RXBUFF_Msk                (_U_(0x1) << PDMIC_IER_RXBUFF_Pos)             /**< (PDMIC_IER) Receive Buffer Full Interrupt Enable Mask */
#define PDMIC_IER_RXBUFF                    PDMIC_IER_RXBUFF_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IER_RXBUFF_Msk instead */
#define PDMIC_IER_MASK                      _U_(0x1B000000)                                /**< \deprecated (PDMIC_IER) Register MASK  (Use PDMIC_IER_Msk instead)  */
#define PDMIC_IER_Msk                       _U_(0x1B000000)                                /**< (PDMIC_IER) Register Mask  */


/* -------- PDMIC_IDR : (PDMIC Offset: 0x1c) (/W 32) Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :24;                       /**< bit:  0..23  Reserved */
    uint32_t DRDY:1;                    /**< bit:     24  Data Ready Interrupt Disable             */
    uint32_t OVRE:1;                    /**< bit:     25  General Overrun Error Interrupt Disable  */
    uint32_t :1;                        /**< bit:     26  Reserved */
    uint32_t ENDRX:1;                   /**< bit:     27  End of Receive Buffer Interrupt Disable  */
    uint32_t RXBUFF:1;                  /**< bit:     28  Receive Buffer Full Interrupt Disable    */
    uint32_t :3;                        /**< bit: 29..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_IDR_OFFSET                    (0x1C)                                        /**<  (PDMIC_IDR) Interrupt Disable Register  Offset */

#define PDMIC_IDR_DRDY_Pos                  24                                             /**< (PDMIC_IDR) Data Ready Interrupt Disable Position */
#define PDMIC_IDR_DRDY_Msk                  (_U_(0x1) << PDMIC_IDR_DRDY_Pos)               /**< (PDMIC_IDR) Data Ready Interrupt Disable Mask */
#define PDMIC_IDR_DRDY                      PDMIC_IDR_DRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IDR_DRDY_Msk instead */
#define PDMIC_IDR_OVRE_Pos                  25                                             /**< (PDMIC_IDR) General Overrun Error Interrupt Disable Position */
#define PDMIC_IDR_OVRE_Msk                  (_U_(0x1) << PDMIC_IDR_OVRE_Pos)               /**< (PDMIC_IDR) General Overrun Error Interrupt Disable Mask */
#define PDMIC_IDR_OVRE                      PDMIC_IDR_OVRE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IDR_OVRE_Msk instead */
#define PDMIC_IDR_ENDRX_Pos                 27                                             /**< (PDMIC_IDR) End of Receive Buffer Interrupt Disable Position */
#define PDMIC_IDR_ENDRX_Msk                 (_U_(0x1) << PDMIC_IDR_ENDRX_Pos)              /**< (PDMIC_IDR) End of Receive Buffer Interrupt Disable Mask */
#define PDMIC_IDR_ENDRX                     PDMIC_IDR_ENDRX_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IDR_ENDRX_Msk instead */
#define PDMIC_IDR_RXBUFF_Pos                28                                             /**< (PDMIC_IDR) Receive Buffer Full Interrupt Disable Position */
#define PDMIC_IDR_RXBUFF_Msk                (_U_(0x1) << PDMIC_IDR_RXBUFF_Pos)             /**< (PDMIC_IDR) Receive Buffer Full Interrupt Disable Mask */
#define PDMIC_IDR_RXBUFF                    PDMIC_IDR_RXBUFF_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IDR_RXBUFF_Msk instead */
#define PDMIC_IDR_MASK                      _U_(0x1B000000)                                /**< \deprecated (PDMIC_IDR) Register MASK  (Use PDMIC_IDR_Msk instead)  */
#define PDMIC_IDR_Msk                       _U_(0x1B000000)                                /**< (PDMIC_IDR) Register Mask  */


/* -------- PDMIC_IMR : (PDMIC Offset: 0x20) (R/ 32) Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :24;                       /**< bit:  0..23  Reserved */
    uint32_t DRDY:1;                    /**< bit:     24  Data Ready Interrupt Mask                */
    uint32_t OVRE:1;                    /**< bit:     25  General Overrun Error Interrupt Mask     */
    uint32_t :1;                        /**< bit:     26  Reserved */
    uint32_t ENDRX:1;                   /**< bit:     27  End of Receive Buffer Interrupt Mask     */
    uint32_t RXBUFF:1;                  /**< bit:     28  Receive Buffer Full Interrupt Mask       */
    uint32_t :3;                        /**< bit: 29..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_IMR_OFFSET                    (0x20)                                        /**<  (PDMIC_IMR) Interrupt Mask Register  Offset */

#define PDMIC_IMR_DRDY_Pos                  24                                             /**< (PDMIC_IMR) Data Ready Interrupt Mask Position */
#define PDMIC_IMR_DRDY_Msk                  (_U_(0x1) << PDMIC_IMR_DRDY_Pos)               /**< (PDMIC_IMR) Data Ready Interrupt Mask Mask */
#define PDMIC_IMR_DRDY                      PDMIC_IMR_DRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IMR_DRDY_Msk instead */
#define PDMIC_IMR_OVRE_Pos                  25                                             /**< (PDMIC_IMR) General Overrun Error Interrupt Mask Position */
#define PDMIC_IMR_OVRE_Msk                  (_U_(0x1) << PDMIC_IMR_OVRE_Pos)               /**< (PDMIC_IMR) General Overrun Error Interrupt Mask Mask */
#define PDMIC_IMR_OVRE                      PDMIC_IMR_OVRE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IMR_OVRE_Msk instead */
#define PDMIC_IMR_ENDRX_Pos                 27                                             /**< (PDMIC_IMR) End of Receive Buffer Interrupt Mask Position */
#define PDMIC_IMR_ENDRX_Msk                 (_U_(0x1) << PDMIC_IMR_ENDRX_Pos)              /**< (PDMIC_IMR) End of Receive Buffer Interrupt Mask Mask */
#define PDMIC_IMR_ENDRX                     PDMIC_IMR_ENDRX_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IMR_ENDRX_Msk instead */
#define PDMIC_IMR_RXBUFF_Pos                28                                             /**< (PDMIC_IMR) Receive Buffer Full Interrupt Mask Position */
#define PDMIC_IMR_RXBUFF_Msk                (_U_(0x1) << PDMIC_IMR_RXBUFF_Pos)             /**< (PDMIC_IMR) Receive Buffer Full Interrupt Mask Mask */
#define PDMIC_IMR_RXBUFF                    PDMIC_IMR_RXBUFF_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_IMR_RXBUFF_Msk instead */
#define PDMIC_IMR_MASK                      _U_(0x1B000000)                                /**< \deprecated (PDMIC_IMR) Register MASK  (Use PDMIC_IMR_Msk instead)  */
#define PDMIC_IMR_Msk                       _U_(0x1B000000)                                /**< (PDMIC_IMR) Register Mask  */


/* -------- PDMIC_ISR : (PDMIC Offset: 0x24) (R/ 32) Interrupt Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :16;                       /**< bit:  0..15  Reserved */
    uint32_t FIFOCNT:8;                 /**< bit: 16..23  FIFO Count                               */
    uint32_t DRDY:1;                    /**< bit:     24  Data Ready                               */
    uint32_t OVRE:1;                    /**< bit:     25  Overrun Error                            */
    uint32_t :1;                        /**< bit:     26  Reserved */
    uint32_t ENDRX:1;                   /**< bit:     27  End of RX Buffer                         */
    uint32_t RXBUFF:1;                  /**< bit:     28  RX Buffer Full                           */
    uint32_t :3;                        /**< bit: 29..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_ISR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_ISR_OFFSET                    (0x24)                                        /**<  (PDMIC_ISR) Interrupt Status Register  Offset */

#define PDMIC_ISR_FIFOCNT_Pos               16                                             /**< (PDMIC_ISR) FIFO Count Position */
#define PDMIC_ISR_FIFOCNT_Msk               (_U_(0xFF) << PDMIC_ISR_FIFOCNT_Pos)           /**< (PDMIC_ISR) FIFO Count Mask */
#define PDMIC_ISR_FIFOCNT(value)            (PDMIC_ISR_FIFOCNT_Msk & ((value) << PDMIC_ISR_FIFOCNT_Pos))
#define PDMIC_ISR_DRDY_Pos                  24                                             /**< (PDMIC_ISR) Data Ready Position */
#define PDMIC_ISR_DRDY_Msk                  (_U_(0x1) << PDMIC_ISR_DRDY_Pos)               /**< (PDMIC_ISR) Data Ready Mask */
#define PDMIC_ISR_DRDY                      PDMIC_ISR_DRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_ISR_DRDY_Msk instead */
#define PDMIC_ISR_OVRE_Pos                  25                                             /**< (PDMIC_ISR) Overrun Error Position */
#define PDMIC_ISR_OVRE_Msk                  (_U_(0x1) << PDMIC_ISR_OVRE_Pos)               /**< (PDMIC_ISR) Overrun Error Mask */
#define PDMIC_ISR_OVRE                      PDMIC_ISR_OVRE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_ISR_OVRE_Msk instead */
#define PDMIC_ISR_ENDRX_Pos                 27                                             /**< (PDMIC_ISR) End of RX Buffer Position */
#define PDMIC_ISR_ENDRX_Msk                 (_U_(0x1) << PDMIC_ISR_ENDRX_Pos)              /**< (PDMIC_ISR) End of RX Buffer Mask */
#define PDMIC_ISR_ENDRX                     PDMIC_ISR_ENDRX_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_ISR_ENDRX_Msk instead */
#define PDMIC_ISR_RXBUFF_Pos                28                                             /**< (PDMIC_ISR) RX Buffer Full Position */
#define PDMIC_ISR_RXBUFF_Msk                (_U_(0x1) << PDMIC_ISR_RXBUFF_Pos)             /**< (PDMIC_ISR) RX Buffer Full Mask */
#define PDMIC_ISR_RXBUFF                    PDMIC_ISR_RXBUFF_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_ISR_RXBUFF_Msk instead */
#define PDMIC_ISR_MASK                      _U_(0x1BFF0000)                                /**< \deprecated (PDMIC_ISR) Register MASK  (Use PDMIC_ISR_Msk instead)  */
#define PDMIC_ISR_Msk                       _U_(0x1BFF0000)                                /**< (PDMIC_ISR) Register Mask  */


/* -------- PDMIC_DSPR0 : (PDMIC Offset: 0x58) (R/W 32) DSP Configuration Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t HPFBYP:1;                  /**< bit:      1  High-Pass Filter Bypass                  */
    uint32_t SINBYP:1;                  /**< bit:      2  SINCC Filter Bypass                      */
    uint32_t SIZE:1;                    /**< bit:      3  Data Size                                */
    uint32_t OSR:3;                     /**< bit:   4..6  Oversampling Ratio                       */
    uint32_t :1;                        /**< bit:      7  Reserved */
    uint32_t SCALE:4;                   /**< bit:  8..11  Data Scale                               */
    uint32_t SHIFT:4;                   /**< bit: 12..15  Data Shift                               */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_DSPR0_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_DSPR0_OFFSET                  (0x58)                                        /**<  (PDMIC_DSPR0) DSP Configuration Register 0  Offset */

#define PDMIC_DSPR0_HPFBYP_Pos              1                                              /**< (PDMIC_DSPR0) High-Pass Filter Bypass Position */
#define PDMIC_DSPR0_HPFBYP_Msk              (_U_(0x1) << PDMIC_DSPR0_HPFBYP_Pos)           /**< (PDMIC_DSPR0) High-Pass Filter Bypass Mask */
#define PDMIC_DSPR0_HPFBYP                  PDMIC_DSPR0_HPFBYP_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_DSPR0_HPFBYP_Msk instead */
#define PDMIC_DSPR0_SINBYP_Pos              2                                              /**< (PDMIC_DSPR0) SINCC Filter Bypass Position */
#define PDMIC_DSPR0_SINBYP_Msk              (_U_(0x1) << PDMIC_DSPR0_SINBYP_Pos)           /**< (PDMIC_DSPR0) SINCC Filter Bypass Mask */
#define PDMIC_DSPR0_SINBYP                  PDMIC_DSPR0_SINBYP_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_DSPR0_SINBYP_Msk instead */
#define PDMIC_DSPR0_SIZE_Pos                3                                              /**< (PDMIC_DSPR0) Data Size Position */
#define PDMIC_DSPR0_SIZE_Msk                (_U_(0x1) << PDMIC_DSPR0_SIZE_Pos)             /**< (PDMIC_DSPR0) Data Size Mask */
#define PDMIC_DSPR0_SIZE                    PDMIC_DSPR0_SIZE_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_DSPR0_SIZE_Msk instead */
#define PDMIC_DSPR0_OSR_Pos                 4                                              /**< (PDMIC_DSPR0) Oversampling Ratio Position */
#define PDMIC_DSPR0_OSR_Msk                 (_U_(0x7) << PDMIC_DSPR0_OSR_Pos)              /**< (PDMIC_DSPR0) Oversampling Ratio Mask */
#define PDMIC_DSPR0_OSR(value)              (PDMIC_DSPR0_OSR_Msk & ((value) << PDMIC_DSPR0_OSR_Pos))
#define   PDMIC_DSPR0_OSR_128_Val           _U_(0x0)                                       /**< (PDMIC_DSPR0) Oversampling ratio is 128  */
#define   PDMIC_DSPR0_OSR_64_Val            _U_(0x1)                                       /**< (PDMIC_DSPR0) Oversampling ratio is 64  */
#define PDMIC_DSPR0_OSR_128                 (PDMIC_DSPR0_OSR_128_Val << PDMIC_DSPR0_OSR_Pos)  /**< (PDMIC_DSPR0) Oversampling ratio is 128 Position  */
#define PDMIC_DSPR0_OSR_64                  (PDMIC_DSPR0_OSR_64_Val << PDMIC_DSPR0_OSR_Pos)  /**< (PDMIC_DSPR0) Oversampling ratio is 64 Position  */
#define PDMIC_DSPR0_SCALE_Pos               8                                              /**< (PDMIC_DSPR0) Data Scale Position */
#define PDMIC_DSPR0_SCALE_Msk               (_U_(0xF) << PDMIC_DSPR0_SCALE_Pos)            /**< (PDMIC_DSPR0) Data Scale Mask */
#define PDMIC_DSPR0_SCALE(value)            (PDMIC_DSPR0_SCALE_Msk & ((value) << PDMIC_DSPR0_SCALE_Pos))
#define PDMIC_DSPR0_SHIFT_Pos               12                                             /**< (PDMIC_DSPR0) Data Shift Position */
#define PDMIC_DSPR0_SHIFT_Msk               (_U_(0xF) << PDMIC_DSPR0_SHIFT_Pos)            /**< (PDMIC_DSPR0) Data Shift Mask */
#define PDMIC_DSPR0_SHIFT(value)            (PDMIC_DSPR0_SHIFT_Msk & ((value) << PDMIC_DSPR0_SHIFT_Pos))
#define PDMIC_DSPR0_MASK                    _U_(0xFF7E)                                    /**< \deprecated (PDMIC_DSPR0) Register MASK  (Use PDMIC_DSPR0_Msk instead)  */
#define PDMIC_DSPR0_Msk                     _U_(0xFF7E)                                    /**< (PDMIC_DSPR0) Register Mask  */


/* -------- PDMIC_DSPR1 : (PDMIC Offset: 0x5c) (R/W 32) DSP Configuration Register 1 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t DGAIN:15;                  /**< bit:  0..14  Gain Correction                          */
    uint32_t :1;                        /**< bit:     15  Reserved */
    uint32_t OFST:16;                   /**< bit: 16..31  Offset Correction                        */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_DSPR1_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_DSPR1_OFFSET                  (0x5C)                                        /**<  (PDMIC_DSPR1) DSP Configuration Register 1  Offset */

#define PDMIC_DSPR1_DGAIN_Pos               0                                              /**< (PDMIC_DSPR1) Gain Correction Position */
#define PDMIC_DSPR1_DGAIN_Msk               (_U_(0x7FFF) << PDMIC_DSPR1_DGAIN_Pos)         /**< (PDMIC_DSPR1) Gain Correction Mask */
#define PDMIC_DSPR1_DGAIN(value)            (PDMIC_DSPR1_DGAIN_Msk & ((value) << PDMIC_DSPR1_DGAIN_Pos))
#define PDMIC_DSPR1_OFST_Pos                16                                             /**< (PDMIC_DSPR1) Offset Correction Position */
#define PDMIC_DSPR1_OFST_Msk                (_U_(0xFFFF) << PDMIC_DSPR1_OFST_Pos)          /**< (PDMIC_DSPR1) Offset Correction Mask */
#define PDMIC_DSPR1_OFST(value)             (PDMIC_DSPR1_OFST_Msk & ((value) << PDMIC_DSPR1_OFST_Pos))
#define PDMIC_DSPR1_MASK                    _U_(0xFFFF7FFF)                                /**< \deprecated (PDMIC_DSPR1) Register MASK  (Use PDMIC_DSPR1_Msk instead)  */
#define PDMIC_DSPR1_Msk                     _U_(0xFFFF7FFF)                                /**< (PDMIC_DSPR1) Register Mask  */


/* -------- PDMIC_WPMR : (PDMIC Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                  */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protect Key                        */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_WPMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_WPMR_OFFSET                   (0xE4)                                        /**<  (PDMIC_WPMR) Write Protection Mode Register  Offset */

#define PDMIC_WPMR_WPEN_Pos                 0                                              /**< (PDMIC_WPMR) Write Protection Enable Position */
#define PDMIC_WPMR_WPEN_Msk                 (_U_(0x1) << PDMIC_WPMR_WPEN_Pos)              /**< (PDMIC_WPMR) Write Protection Enable Mask */
#define PDMIC_WPMR_WPEN                     PDMIC_WPMR_WPEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_WPMR_WPEN_Msk instead */
#define PDMIC_WPMR_WPKEY_Pos                8                                              /**< (PDMIC_WPMR) Write Protect Key Position */
#define PDMIC_WPMR_WPKEY_Msk                (_U_(0xFFFFFF) << PDMIC_WPMR_WPKEY_Pos)        /**< (PDMIC_WPMR) Write Protect Key Mask */
#define PDMIC_WPMR_WPKEY(value)             (PDMIC_WPMR_WPKEY_Msk & ((value) << PDMIC_WPMR_WPKEY_Pos))
#define   PDMIC_WPMR_WPKEY_PASSWD_Val       _U_(0x414443)                                  /**< (PDMIC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define PDMIC_WPMR_WPKEY_PASSWD             (PDMIC_WPMR_WPKEY_PASSWD_Val << PDMIC_WPMR_WPKEY_Pos)  /**< (PDMIC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define PDMIC_WPMR_MASK                     _U_(0xFFFFFF01)                                /**< \deprecated (PDMIC_WPMR) Register MASK  (Use PDMIC_WPMR_Msk instead)  */
#define PDMIC_WPMR_Msk                      _U_(0xFFFFFF01)                                /**< (PDMIC_WPMR) Register Mask  */


/* -------- PDMIC_WPSR : (PDMIC Offset: 0xe8) (R/ 32) Write Protection Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status        */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPVSRC:16;                 /**< bit:  8..23  Write Protection Violation Source        */
    uint32_t :8;                        /**< bit: 24..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_WPSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_WPSR_OFFSET                   (0xE8)                                        /**<  (PDMIC_WPSR) Write Protection Status Register  Offset */

#define PDMIC_WPSR_WPVS_Pos                 0                                              /**< (PDMIC_WPSR) Write Protection Violation Status Position */
#define PDMIC_WPSR_WPVS_Msk                 (_U_(0x1) << PDMIC_WPSR_WPVS_Pos)              /**< (PDMIC_WPSR) Write Protection Violation Status Mask */
#define PDMIC_WPSR_WPVS                     PDMIC_WPSR_WPVS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_WPSR_WPVS_Msk instead */
#define PDMIC_WPSR_WPVSRC_Pos               8                                              /**< (PDMIC_WPSR) Write Protection Violation Source Position */
#define PDMIC_WPSR_WPVSRC_Msk               (_U_(0xFFFF) << PDMIC_WPSR_WPVSRC_Pos)         /**< (PDMIC_WPSR) Write Protection Violation Source Mask */
#define PDMIC_WPSR_WPVSRC(value)            (PDMIC_WPSR_WPVSRC_Msk & ((value) << PDMIC_WPSR_WPVSRC_Pos))
#define PDMIC_WPSR_MASK                     _U_(0xFFFF01)                                  /**< \deprecated (PDMIC_WPSR) Register MASK  (Use PDMIC_WPSR_Msk instead)  */
#define PDMIC_WPSR_Msk                      _U_(0xFFFF01)                                  /**< (PDMIC_WPSR) Register Mask  */


/* -------- PDMIC_RPR : (PDMIC Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_RPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_RPR_OFFSET                    (0x100)                                       /**<  (PDMIC_RPR) Receive Pointer Register  Offset */

#define PDMIC_RPR_RXPTR_Pos                 0                                              /**< (PDMIC_RPR) Receive Pointer Register Position */
#define PDMIC_RPR_RXPTR_Msk                 (_U_(0xFFFFFFFF) << PDMIC_RPR_RXPTR_Pos)       /**< (PDMIC_RPR) Receive Pointer Register Mask */
#define PDMIC_RPR_RXPTR(value)              (PDMIC_RPR_RXPTR_Msk & ((value) << PDMIC_RPR_RXPTR_Pos))
#define PDMIC_RPR_MASK                      _U_(0xFFFFFFFF)                                /**< \deprecated (PDMIC_RPR) Register MASK  (Use PDMIC_RPR_Msk instead)  */
#define PDMIC_RPR_Msk                       _U_(0xFFFFFFFF)                                /**< (PDMIC_RPR) Register Mask  */


/* -------- PDMIC_RCR : (PDMIC Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCTR:16;                  /**< bit:  0..15  Receive Counter Register                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_RCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_RCR_OFFSET                    (0x104)                                       /**<  (PDMIC_RCR) Receive Counter Register  Offset */

#define PDMIC_RCR_RXCTR_Pos                 0                                              /**< (PDMIC_RCR) Receive Counter Register Position */
#define PDMIC_RCR_RXCTR_Msk                 (_U_(0xFFFF) << PDMIC_RCR_RXCTR_Pos)           /**< (PDMIC_RCR) Receive Counter Register Mask */
#define PDMIC_RCR_RXCTR(value)              (PDMIC_RCR_RXCTR_Msk & ((value) << PDMIC_RCR_RXCTR_Pos))
#define PDMIC_RCR_MASK                      _U_(0xFFFF)                                    /**< \deprecated (PDMIC_RCR) Register MASK  (Use PDMIC_RCR_Msk instead)  */
#define PDMIC_RCR_Msk                       _U_(0xFFFF)                                    /**< (PDMIC_RCR) Register Mask  */


/* -------- PDMIC_RNPR : (PDMIC Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_RNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_RNPR_OFFSET                   (0x110)                                       /**<  (PDMIC_RNPR) Receive Next Pointer Register  Offset */

#define PDMIC_RNPR_RXNPTR_Pos               0                                              /**< (PDMIC_RNPR) Receive Next Pointer Position */
#define PDMIC_RNPR_RXNPTR_Msk               (_U_(0xFFFFFFFF) << PDMIC_RNPR_RXNPTR_Pos)     /**< (PDMIC_RNPR) Receive Next Pointer Mask */
#define PDMIC_RNPR_RXNPTR(value)            (PDMIC_RNPR_RXNPTR_Msk & ((value) << PDMIC_RNPR_RXNPTR_Pos))
#define PDMIC_RNPR_MASK                     _U_(0xFFFFFFFF)                                /**< \deprecated (PDMIC_RNPR) Register MASK  (Use PDMIC_RNPR_Msk instead)  */
#define PDMIC_RNPR_Msk                      _U_(0xFFFFFFFF)                                /**< (PDMIC_RNPR) Register Mask  */


/* -------- PDMIC_RNCR : (PDMIC Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} PDMIC_RNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_RNCR_OFFSET                   (0x114)                                       /**<  (PDMIC_RNCR) Receive Next Counter Register  Offset */

#define PDMIC_RNCR_RXNCTR_Pos               0                                              /**< (PDMIC_RNCR) Receive Next Counter Position */
#define PDMIC_RNCR_RXNCTR_Msk               (_U_(0xFFFF) << PDMIC_RNCR_RXNCTR_Pos)         /**< (PDMIC_RNCR) Receive Next Counter Mask */
#define PDMIC_RNCR_RXNCTR(value)            (PDMIC_RNCR_RXNCTR_Msk & ((value) << PDMIC_RNCR_RXNCTR_Pos))
#define PDMIC_RNCR_MASK                     _U_(0xFFFF)                                    /**< \deprecated (PDMIC_RNCR) Register MASK  (Use PDMIC_RNCR_Msk instead)  */
#define PDMIC_RNCR_Msk                      _U_(0xFFFF)                                    /**< (PDMIC_RNCR) Register Mask  */


/* -------- PDMIC_PTCR : (PDMIC Offset: 0x120) (/W 32) Transfer Control Register -------- */
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
} PDMIC_PTCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_PTCR_OFFSET                   (0x120)                                       /**<  (PDMIC_PTCR) Transfer Control Register  Offset */

#define PDMIC_PTCR_RXTEN_Pos                0                                              /**< (PDMIC_PTCR) Receiver Transfer Enable Position */
#define PDMIC_PTCR_RXTEN_Msk                (_U_(0x1) << PDMIC_PTCR_RXTEN_Pos)             /**< (PDMIC_PTCR) Receiver Transfer Enable Mask */
#define PDMIC_PTCR_RXTEN                    PDMIC_PTCR_RXTEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_RXTEN_Msk instead */
#define PDMIC_PTCR_RXTDIS_Pos               1                                              /**< (PDMIC_PTCR) Receiver Transfer Disable Position */
#define PDMIC_PTCR_RXTDIS_Msk               (_U_(0x1) << PDMIC_PTCR_RXTDIS_Pos)            /**< (PDMIC_PTCR) Receiver Transfer Disable Mask */
#define PDMIC_PTCR_RXTDIS                   PDMIC_PTCR_RXTDIS_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_RXTDIS_Msk instead */
#define PDMIC_PTCR_TXTEN_Pos                8                                              /**< (PDMIC_PTCR) Transmitter Transfer Enable Position */
#define PDMIC_PTCR_TXTEN_Msk                (_U_(0x1) << PDMIC_PTCR_TXTEN_Pos)             /**< (PDMIC_PTCR) Transmitter Transfer Enable Mask */
#define PDMIC_PTCR_TXTEN                    PDMIC_PTCR_TXTEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_TXTEN_Msk instead */
#define PDMIC_PTCR_TXTDIS_Pos               9                                              /**< (PDMIC_PTCR) Transmitter Transfer Disable Position */
#define PDMIC_PTCR_TXTDIS_Msk               (_U_(0x1) << PDMIC_PTCR_TXTDIS_Pos)            /**< (PDMIC_PTCR) Transmitter Transfer Disable Mask */
#define PDMIC_PTCR_TXTDIS                   PDMIC_PTCR_TXTDIS_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_TXTDIS_Msk instead */
#define PDMIC_PTCR_RXCBEN_Pos               16                                             /**< (PDMIC_PTCR) Receiver Circular Buffer Enable Position */
#define PDMIC_PTCR_RXCBEN_Msk               (_U_(0x1) << PDMIC_PTCR_RXCBEN_Pos)            /**< (PDMIC_PTCR) Receiver Circular Buffer Enable Mask */
#define PDMIC_PTCR_RXCBEN                   PDMIC_PTCR_RXCBEN_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_RXCBEN_Msk instead */
#define PDMIC_PTCR_RXCBDIS_Pos              17                                             /**< (PDMIC_PTCR) Receiver Circular Buffer Disable Position */
#define PDMIC_PTCR_RXCBDIS_Msk              (_U_(0x1) << PDMIC_PTCR_RXCBDIS_Pos)           /**< (PDMIC_PTCR) Receiver Circular Buffer Disable Mask */
#define PDMIC_PTCR_RXCBDIS                  PDMIC_PTCR_RXCBDIS_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_RXCBDIS_Msk instead */
#define PDMIC_PTCR_TXCBEN_Pos               18                                             /**< (PDMIC_PTCR) Transmitter Circular Buffer Enable Position */
#define PDMIC_PTCR_TXCBEN_Msk               (_U_(0x1) << PDMIC_PTCR_TXCBEN_Pos)            /**< (PDMIC_PTCR) Transmitter Circular Buffer Enable Mask */
#define PDMIC_PTCR_TXCBEN                   PDMIC_PTCR_TXCBEN_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_TXCBEN_Msk instead */
#define PDMIC_PTCR_TXCBDIS_Pos              19                                             /**< (PDMIC_PTCR) Transmitter Circular Buffer Disable Position */
#define PDMIC_PTCR_TXCBDIS_Msk              (_U_(0x1) << PDMIC_PTCR_TXCBDIS_Pos)           /**< (PDMIC_PTCR) Transmitter Circular Buffer Disable Mask */
#define PDMIC_PTCR_TXCBDIS                  PDMIC_PTCR_TXCBDIS_Msk                         /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_TXCBDIS_Msk instead */
#define PDMIC_PTCR_ERRCLR_Pos               24                                             /**< (PDMIC_PTCR) Transfer Bus Error Clear Position */
#define PDMIC_PTCR_ERRCLR_Msk               (_U_(0x1) << PDMIC_PTCR_ERRCLR_Pos)            /**< (PDMIC_PTCR) Transfer Bus Error Clear Mask */
#define PDMIC_PTCR_ERRCLR                   PDMIC_PTCR_ERRCLR_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTCR_ERRCLR_Msk instead */
#define PDMIC_PTCR_MASK                     _U_(0x10F0303)                                 /**< \deprecated (PDMIC_PTCR) Register MASK  (Use PDMIC_PTCR_Msk instead)  */
#define PDMIC_PTCR_Msk                      _U_(0x10F0303)                                 /**< (PDMIC_PTCR) Register Mask  */


/* -------- PDMIC_PTSR : (PDMIC Offset: 0x124) (R/ 32) Transfer Status Register -------- */
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
} PDMIC_PTSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PDMIC_PTSR_OFFSET                   (0x124)                                       /**<  (PDMIC_PTSR) Transfer Status Register  Offset */

#define PDMIC_PTSR_RXTEN_Pos                0                                              /**< (PDMIC_PTSR) Receiver Transfer Enable Position */
#define PDMIC_PTSR_RXTEN_Msk                (_U_(0x1) << PDMIC_PTSR_RXTEN_Pos)             /**< (PDMIC_PTSR) Receiver Transfer Enable Mask */
#define PDMIC_PTSR_RXTEN                    PDMIC_PTSR_RXTEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTSR_RXTEN_Msk instead */
#define PDMIC_PTSR_TXTEN_Pos                8                                              /**< (PDMIC_PTSR) Transmitter Transfer Enable Position */
#define PDMIC_PTSR_TXTEN_Msk                (_U_(0x1) << PDMIC_PTSR_TXTEN_Pos)             /**< (PDMIC_PTSR) Transmitter Transfer Enable Mask */
#define PDMIC_PTSR_TXTEN                    PDMIC_PTSR_TXTEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTSR_TXTEN_Msk instead */
#define PDMIC_PTSR_RXCBEN_Pos               16                                             /**< (PDMIC_PTSR) Receiver Circular Buffer Enable Position */
#define PDMIC_PTSR_RXCBEN_Msk               (_U_(0x1) << PDMIC_PTSR_RXCBEN_Pos)            /**< (PDMIC_PTSR) Receiver Circular Buffer Enable Mask */
#define PDMIC_PTSR_RXCBEN                   PDMIC_PTSR_RXCBEN_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTSR_RXCBEN_Msk instead */
#define PDMIC_PTSR_TXCBEN_Pos               18                                             /**< (PDMIC_PTSR) Transmitter Circular Buffer Enable Position */
#define PDMIC_PTSR_TXCBEN_Msk               (_U_(0x1) << PDMIC_PTSR_TXCBEN_Pos)            /**< (PDMIC_PTSR) Transmitter Circular Buffer Enable Mask */
#define PDMIC_PTSR_TXCBEN                   PDMIC_PTSR_TXCBEN_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTSR_TXCBEN_Msk instead */
#define PDMIC_PTSR_ERR_Pos                  24                                             /**< (PDMIC_PTSR) Transfer Bus Error Position */
#define PDMIC_PTSR_ERR_Msk                  (_U_(0x1) << PDMIC_PTSR_ERR_Pos)               /**< (PDMIC_PTSR) Transfer Bus Error Mask */
#define PDMIC_PTSR_ERR                      PDMIC_PTSR_ERR_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use PDMIC_PTSR_ERR_Msk instead */
#define PDMIC_PTSR_MASK                     _U_(0x1050101)                                 /**< \deprecated (PDMIC_PTSR) Register MASK  (Use PDMIC_PTSR_Msk instead)  */
#define PDMIC_PTSR_Msk                      _U_(0x1050101)                                 /**< (PDMIC_PTSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief PDMIC hardware registers */
typedef struct {  
  __IO uint32_t PDMIC_CR;       /**< (PDMIC Offset: 0x00) Control Register */
  __IO uint32_t PDMIC_MR;       /**< (PDMIC Offset: 0x04) Mode Register */
  RoReg8  Reserved1[0xC];
  __I  uint32_t PDMIC_CDR;      /**< (PDMIC Offset: 0x14) Converted Data Register */
  __O  uint32_t PDMIC_IER;      /**< (PDMIC Offset: 0x18) Interrupt Enable Register */
  __O  uint32_t PDMIC_IDR;      /**< (PDMIC Offset: 0x1C) Interrupt Disable Register */
  __I  uint32_t PDMIC_IMR;      /**< (PDMIC Offset: 0x20) Interrupt Mask Register */
  __I  uint32_t PDMIC_ISR;      /**< (PDMIC Offset: 0x24) Interrupt Status Register */
  RoReg8  Reserved2[0x30];
  __IO uint32_t PDMIC_DSPR0;    /**< (PDMIC Offset: 0x58) DSP Configuration Register 0 */
  __IO uint32_t PDMIC_DSPR1;    /**< (PDMIC Offset: 0x5C) DSP Configuration Register 1 */
  RoReg8  Reserved3[0x84];
  __IO uint32_t PDMIC_WPMR;     /**< (PDMIC Offset: 0xE4) Write Protection Mode Register */
  __I  uint32_t PDMIC_WPSR;     /**< (PDMIC Offset: 0xE8) Write Protection Status Register */
  RoReg8  Reserved4[0x14];
  __IO uint32_t PDMIC_RPR;      /**< (PDMIC Offset: 0x100) Receive Pointer Register */
  __IO uint32_t PDMIC_RCR;      /**< (PDMIC Offset: 0x104) Receive Counter Register */
  RoReg8  Reserved5[0x8];
  __IO uint32_t PDMIC_RNPR;     /**< (PDMIC Offset: 0x110) Receive Next Pointer Register */
  __IO uint32_t PDMIC_RNCR;     /**< (PDMIC Offset: 0x114) Receive Next Counter Register */
  RoReg8  Reserved6[0x8];
  __O  uint32_t PDMIC_PTCR;     /**< (PDMIC Offset: 0x120) Transfer Control Register */
  __I  uint32_t PDMIC_PTSR;     /**< (PDMIC Offset: 0x124) Transfer Status Register */
} Pdmic;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief PDMIC hardware registers */
typedef struct {  
  __IO PDMIC_CR_Type                  PDMIC_CR;       /**< Offset: 0x00 (R/W  32) Control Register */
  __IO PDMIC_MR_Type                  PDMIC_MR;       /**< Offset: 0x04 (R/W  32) Mode Register */
  __I  uint32_t                       Reserved1[3];
  __I  PDMIC_CDR_Type                 PDMIC_CDR;      /**< Offset: 0x14 (R/   32) Converted Data Register */
  __O  PDMIC_IER_Type                 PDMIC_IER;      /**< Offset: 0x18 ( /W  32) Interrupt Enable Register */
  __O  PDMIC_IDR_Type                 PDMIC_IDR;      /**< Offset: 0x1C ( /W  32) Interrupt Disable Register */
  __I  PDMIC_IMR_Type                 PDMIC_IMR;      /**< Offset: 0x20 (R/   32) Interrupt Mask Register */
  __I  PDMIC_ISR_Type                 PDMIC_ISR;      /**< Offset: 0x24 (R/   32) Interrupt Status Register */
  __I  uint32_t                       Reserved2[12];
  __IO PDMIC_DSPR0_Type               PDMIC_DSPR0;    /**< Offset: 0x58 (R/W  32) DSP Configuration Register 0 */
  __IO PDMIC_DSPR1_Type               PDMIC_DSPR1;    /**< Offset: 0x5C (R/W  32) DSP Configuration Register 1 */
  __I  uint32_t                       Reserved3[33];
  __IO PDMIC_WPMR_Type                PDMIC_WPMR;     /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I  PDMIC_WPSR_Type                PDMIC_WPSR;     /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I  uint32_t                       Reserved4[5];
  __IO PDMIC_RPR_Type                 PDMIC_RPR;      /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO PDMIC_RCR_Type                 PDMIC_RCR;      /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __I  uint32_t                       Reserved5[2];
  __IO PDMIC_RNPR_Type                PDMIC_RNPR;     /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO PDMIC_RNCR_Type                PDMIC_RNCR;     /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __I  uint32_t                       Reserved6[2];
  __O  PDMIC_PTCR_Type                PDMIC_PTCR;     /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I  PDMIC_PTSR_Type                PDMIC_PTSR;     /**< Offset: 0x124 (R/   32) Transfer Status Register */
} Pdmic;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Pulse Density Modulation Interface Controller */

#endif /* _SAMG55_PDMIC_COMPONENT_H_ */
