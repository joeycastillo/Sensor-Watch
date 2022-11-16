/**
 * \file
 *
 * \brief Component description for SPI
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
#ifndef _SAMG55_SPI_COMPONENT_H_
#define _SAMG55_SPI_COMPONENT_H_
#define _SAMG55_SPI_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Serial Peripheral Interface
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR SPI */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define SPI_11279                      /**< (SPI) Module ID */
#define REV_SPI D                      /**< (SPI) Module revision */

/* -------- SPI_CR : (SPI Offset: 0x00) (/W 32) SPI Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t SPIEN:1;                   /**< bit:      0  SPI Enable                               */
    uint32_t SPIDIS:1;                  /**< bit:      1  SPI Disable                              */
    uint32_t :5;                        /**< bit:   2..6  Reserved */
    uint32_t SWRST:1;                   /**< bit:      7  SPI Software Reset                       */
    uint32_t :4;                        /**< bit:  8..11  Reserved */
    uint32_t REQCLR:1;                  /**< bit:     12  Request to Clear the Comparison Trigger  */
    uint32_t :11;                       /**< bit: 13..23  Reserved */
    uint32_t LASTXFER:1;                /**< bit:     24  Last Transfer                            */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_CR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_CR_OFFSET                       (0x00)                                        /**<  (SPI_CR) SPI Control Register  Offset */

#define SPI_CR_SPIEN_Pos                    0                                              /**< (SPI_CR) SPI Enable Position */
#define SPI_CR_SPIEN_Msk                    (_U_(0x1) << SPI_CR_SPIEN_Pos)                 /**< (SPI_CR) SPI Enable Mask */
#define SPI_CR_SPIEN                        SPI_CR_SPIEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CR_SPIEN_Msk instead */
#define SPI_CR_SPIDIS_Pos                   1                                              /**< (SPI_CR) SPI Disable Position */
#define SPI_CR_SPIDIS_Msk                   (_U_(0x1) << SPI_CR_SPIDIS_Pos)                /**< (SPI_CR) SPI Disable Mask */
#define SPI_CR_SPIDIS                       SPI_CR_SPIDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CR_SPIDIS_Msk instead */
#define SPI_CR_SWRST_Pos                    7                                              /**< (SPI_CR) SPI Software Reset Position */
#define SPI_CR_SWRST_Msk                    (_U_(0x1) << SPI_CR_SWRST_Pos)                 /**< (SPI_CR) SPI Software Reset Mask */
#define SPI_CR_SWRST                        SPI_CR_SWRST_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CR_SWRST_Msk instead */
#define SPI_CR_REQCLR_Pos                   12                                             /**< (SPI_CR) Request to Clear the Comparison Trigger Position */
#define SPI_CR_REQCLR_Msk                   (_U_(0x1) << SPI_CR_REQCLR_Pos)                /**< (SPI_CR) Request to Clear the Comparison Trigger Mask */
#define SPI_CR_REQCLR                       SPI_CR_REQCLR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CR_REQCLR_Msk instead */
#define SPI_CR_LASTXFER_Pos                 24                                             /**< (SPI_CR) Last Transfer Position */
#define SPI_CR_LASTXFER_Msk                 (_U_(0x1) << SPI_CR_LASTXFER_Pos)              /**< (SPI_CR) Last Transfer Mask */
#define SPI_CR_LASTXFER                     SPI_CR_LASTXFER_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CR_LASTXFER_Msk instead */
#define SPI_CR_MASK                         _U_(0x1001083)                                 /**< \deprecated (SPI_CR) Register MASK  (Use SPI_CR_Msk instead)  */
#define SPI_CR_Msk                          _U_(0x1001083)                                 /**< (SPI_CR) Register Mask  */


/* -------- SPI_MR : (SPI Offset: 0x04) (R/W 32) SPI Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t MSTR:1;                    /**< bit:      0  Master/Slave Mode                        */
    uint32_t PS:1;                      /**< bit:      1  Peripheral Select                        */
    uint32_t PCSDEC:1;                  /**< bit:      2  Chip Select Decode                       */
    uint32_t BRSRCCLK:1;                /**< bit:      3  Bit Rate Source Clock                    */
    uint32_t MODFDIS:1;                 /**< bit:      4  Mode Fault Detection                     */
    uint32_t WDRBT:1;                   /**< bit:      5  Wait Data Read Before Transfer           */
    uint32_t :1;                        /**< bit:      6  Reserved */
    uint32_t LLB:1;                     /**< bit:      7  Local Loopback Enable                    */
    uint32_t :4;                        /**< bit:  8..11  Reserved */
    uint32_t CMPMODE:1;                 /**< bit:     12  Comparison Mode                          */
    uint32_t :3;                        /**< bit: 13..15  Reserved */
    uint32_t PCS:2;                     /**< bit: 16..17  Peripheral Chip Select                   */
    uint32_t :6;                        /**< bit: 18..23  Reserved */
    uint32_t DLYBCS:8;                  /**< bit: 24..31  Delay Between Chip Selects               */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_MR_OFFSET                       (0x04)                                        /**<  (SPI_MR) SPI Mode Register  Offset */

#define SPI_MR_MSTR_Pos                     0                                              /**< (SPI_MR) Master/Slave Mode Position */
#define SPI_MR_MSTR_Msk                     (_U_(0x1) << SPI_MR_MSTR_Pos)                  /**< (SPI_MR) Master/Slave Mode Mask */
#define SPI_MR_MSTR                         SPI_MR_MSTR_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_MSTR_Msk instead */
#define SPI_MR_PS_Pos                       1                                              /**< (SPI_MR) Peripheral Select Position */
#define SPI_MR_PS_Msk                       (_U_(0x1) << SPI_MR_PS_Pos)                    /**< (SPI_MR) Peripheral Select Mask */
#define SPI_MR_PS                           SPI_MR_PS_Msk                                  /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_PS_Msk instead */
#define SPI_MR_PCSDEC_Pos                   2                                              /**< (SPI_MR) Chip Select Decode Position */
#define SPI_MR_PCSDEC_Msk                   (_U_(0x1) << SPI_MR_PCSDEC_Pos)                /**< (SPI_MR) Chip Select Decode Mask */
#define SPI_MR_PCSDEC                       SPI_MR_PCSDEC_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_PCSDEC_Msk instead */
#define SPI_MR_BRSRCCLK_Pos                 3                                              /**< (SPI_MR) Bit Rate Source Clock Position */
#define SPI_MR_BRSRCCLK_Msk                 (_U_(0x1) << SPI_MR_BRSRCCLK_Pos)              /**< (SPI_MR) Bit Rate Source Clock Mask */
#define SPI_MR_BRSRCCLK                     SPI_MR_BRSRCCLK_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_BRSRCCLK_Msk instead */
#define   SPI_MR_BRSRCCLK_PERIPH_CLK_Val    _U_(0x0)                                       /**< (SPI_MR) The peripheral clock is the source clock for the bit rate generation.  */
#define   SPI_MR_BRSRCCLK_PMC_PCK_Val       _U_(0x1)                                       /**< (SPI_MR) PMC PCKx is the source clock for the bit rate generation, thus the bit rate can be independent of the core/peripheral clock.  */
#define SPI_MR_BRSRCCLK_PERIPH_CLK          (SPI_MR_BRSRCCLK_PERIPH_CLK_Val << SPI_MR_BRSRCCLK_Pos)  /**< (SPI_MR) The peripheral clock is the source clock for the bit rate generation. Position  */
#define SPI_MR_BRSRCCLK_PMC_PCK             (SPI_MR_BRSRCCLK_PMC_PCK_Val << SPI_MR_BRSRCCLK_Pos)  /**< (SPI_MR) PMC PCKx is the source clock for the bit rate generation, thus the bit rate can be independent of the core/peripheral clock. Position  */
#define SPI_MR_MODFDIS_Pos                  4                                              /**< (SPI_MR) Mode Fault Detection Position */
#define SPI_MR_MODFDIS_Msk                  (_U_(0x1) << SPI_MR_MODFDIS_Pos)               /**< (SPI_MR) Mode Fault Detection Mask */
#define SPI_MR_MODFDIS                      SPI_MR_MODFDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_MODFDIS_Msk instead */
#define SPI_MR_WDRBT_Pos                    5                                              /**< (SPI_MR) Wait Data Read Before Transfer Position */
#define SPI_MR_WDRBT_Msk                    (_U_(0x1) << SPI_MR_WDRBT_Pos)                 /**< (SPI_MR) Wait Data Read Before Transfer Mask */
#define SPI_MR_WDRBT                        SPI_MR_WDRBT_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_WDRBT_Msk instead */
#define SPI_MR_LLB_Pos                      7                                              /**< (SPI_MR) Local Loopback Enable Position */
#define SPI_MR_LLB_Msk                      (_U_(0x1) << SPI_MR_LLB_Pos)                   /**< (SPI_MR) Local Loopback Enable Mask */
#define SPI_MR_LLB                          SPI_MR_LLB_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_LLB_Msk instead */
#define SPI_MR_CMPMODE_Pos                  12                                             /**< (SPI_MR) Comparison Mode Position */
#define SPI_MR_CMPMODE_Msk                  (_U_(0x1) << SPI_MR_CMPMODE_Pos)               /**< (SPI_MR) Comparison Mode Mask */
#define SPI_MR_CMPMODE                      SPI_MR_CMPMODE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_MR_CMPMODE_Msk instead */
#define   SPI_MR_CMPMODE_FLAG_ONLY_Val      _U_(0x0)                                       /**< (SPI_MR) Any character is received and comparison function drives CMP flag.  */
#define   SPI_MR_CMPMODE_START_CONDITION_Val _U_(0x1)                                       /**< (SPI_MR) Comparison condition must be met to start reception of all incoming characters until REQCLR is set.  */
#define SPI_MR_CMPMODE_FLAG_ONLY            (SPI_MR_CMPMODE_FLAG_ONLY_Val << SPI_MR_CMPMODE_Pos)  /**< (SPI_MR) Any character is received and comparison function drives CMP flag. Position  */
#define SPI_MR_CMPMODE_START_CONDITION      (SPI_MR_CMPMODE_START_CONDITION_Val << SPI_MR_CMPMODE_Pos)  /**< (SPI_MR) Comparison condition must be met to start reception of all incoming characters until REQCLR is set. Position  */
#define SPI_MR_PCS_Pos                      16                                             /**< (SPI_MR) Peripheral Chip Select Position */
#define SPI_MR_PCS_Msk                      (_U_(0x3) << SPI_MR_PCS_Pos)                   /**< (SPI_MR) Peripheral Chip Select Mask */
#define SPI_MR_PCS(value)                   (SPI_MR_PCS_Msk & ((value) << SPI_MR_PCS_Pos))
#define SPI_MR_DLYBCS_Pos                   24                                             /**< (SPI_MR) Delay Between Chip Selects Position */
#define SPI_MR_DLYBCS_Msk                   (_U_(0xFF) << SPI_MR_DLYBCS_Pos)               /**< (SPI_MR) Delay Between Chip Selects Mask */
#define SPI_MR_DLYBCS(value)                (SPI_MR_DLYBCS_Msk & ((value) << SPI_MR_DLYBCS_Pos))
#define SPI_MR_MASK                         _U_(0xFF0310BF)                                /**< \deprecated (SPI_MR) Register MASK  (Use SPI_MR_Msk instead)  */
#define SPI_MR_Msk                          _U_(0xFF0310BF)                                /**< (SPI_MR) Register Mask  */


/* -------- SPI_RDR : (SPI Offset: 0x08) (R/ 32) SPI Receive Data Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RD:16;                     /**< bit:  0..15  Receive Data                             */
    uint32_t PCS:4;                     /**< bit: 16..19  Peripheral Chip Select                   */
    uint32_t :12;                       /**< bit: 20..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_RDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_RDR_OFFSET                      (0x08)                                        /**<  (SPI_RDR) SPI Receive Data Register  Offset */

#define SPI_RDR_RD_Pos                      0                                              /**< (SPI_RDR) Receive Data Position */
#define SPI_RDR_RD_Msk                      (_U_(0xFFFF) << SPI_RDR_RD_Pos)                /**< (SPI_RDR) Receive Data Mask */
#define SPI_RDR_RD(value)                   (SPI_RDR_RD_Msk & ((value) << SPI_RDR_RD_Pos))
#define SPI_RDR_PCS_Pos                     16                                             /**< (SPI_RDR) Peripheral Chip Select Position */
#define SPI_RDR_PCS_Msk                     (_U_(0xF) << SPI_RDR_PCS_Pos)                  /**< (SPI_RDR) Peripheral Chip Select Mask */
#define SPI_RDR_PCS(value)                  (SPI_RDR_PCS_Msk & ((value) << SPI_RDR_PCS_Pos))
#define SPI_RDR_MASK                        _U_(0xFFFFF)                                   /**< \deprecated (SPI_RDR) Register MASK  (Use SPI_RDR_Msk instead)  */
#define SPI_RDR_Msk                         _U_(0xFFFFF)                                   /**< (SPI_RDR) Register Mask  */


/* -------- SPI_TDR : (SPI Offset: 0x0c) (/W 32) SPI Transmit Data Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TD:16;                     /**< bit:  0..15  Transmit Data                            */
    uint32_t PCS:4;                     /**< bit: 16..19  Peripheral Chip Select                   */
    uint32_t :4;                        /**< bit: 20..23  Reserved */
    uint32_t LASTXFER:1;                /**< bit:     24  Last Transfer                            */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_TDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_TDR_OFFSET                      (0x0C)                                        /**<  (SPI_TDR) SPI Transmit Data Register  Offset */

#define SPI_TDR_TD_Pos                      0                                              /**< (SPI_TDR) Transmit Data Position */
#define SPI_TDR_TD_Msk                      (_U_(0xFFFF) << SPI_TDR_TD_Pos)                /**< (SPI_TDR) Transmit Data Mask */
#define SPI_TDR_TD(value)                   (SPI_TDR_TD_Msk & ((value) << SPI_TDR_TD_Pos))
#define SPI_TDR_PCS_Pos                     16                                             /**< (SPI_TDR) Peripheral Chip Select Position */
#define SPI_TDR_PCS_Msk                     (_U_(0xF) << SPI_TDR_PCS_Pos)                  /**< (SPI_TDR) Peripheral Chip Select Mask */
#define SPI_TDR_PCS(value)                  (SPI_TDR_PCS_Msk & ((value) << SPI_TDR_PCS_Pos))
#define SPI_TDR_LASTXFER_Pos                24                                             /**< (SPI_TDR) Last Transfer Position */
#define SPI_TDR_LASTXFER_Msk                (_U_(0x1) << SPI_TDR_LASTXFER_Pos)             /**< (SPI_TDR) Last Transfer Mask */
#define SPI_TDR_LASTXFER                    SPI_TDR_LASTXFER_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_TDR_LASTXFER_Msk instead */
#define SPI_TDR_MASK                        _U_(0x10FFFFF)                                 /**< \deprecated (SPI_TDR) Register MASK  (Use SPI_TDR_Msk instead)  */
#define SPI_TDR_Msk                         _U_(0x10FFFFF)                                 /**< (SPI_TDR) Register Mask  */


/* -------- SPI_SR : (SPI Offset: 0x10) (R/ 32) SPI Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RDRF:1;                    /**< bit:      0  Receive Data Register Full (cleared by reading SPI_RDR) */
    uint32_t TDRE:1;                    /**< bit:      1  Transmit Data Register Empty (cleared by writing SPI_TDR) */
    uint32_t MODF:1;                    /**< bit:      2  Mode Fault Error (cleared on read)       */
    uint32_t OVRES:1;                   /**< bit:      3  Overrun Error Status (cleared on read)   */
    uint32_t ENDRX:1;                   /**< bit:      4  End of RX buffer (cleared by writing SPI_RCR or SPI_RNCR) */
    uint32_t ENDTX:1;                   /**< bit:      5  End of TX buffer (cleared by writing SPI_TCR or SPI_TNCR) */
    uint32_t RXBUFF:1;                  /**< bit:      6  RX Buffer Full (cleared by writing SPI_RCR or SPI_RNCR) */
    uint32_t TXBUFE:1;                  /**< bit:      7  TX Buffer Empty (cleared by writing SPI_TCR or SPI_TNCR) */
    uint32_t NSSR:1;                    /**< bit:      8  NSS Rising (cleared on read)             */
    uint32_t TXEMPTY:1;                 /**< bit:      9  Transmission Registers Empty (cleared by writing SPI_TDR) */
    uint32_t UNDES:1;                   /**< bit:     10  Underrun Error Status (slave mode only) (cleared on read) */
    uint32_t CMP:1;                     /**< bit:     11  Comparison Status (cleared on read)      */
    uint32_t :4;                        /**< bit: 12..15  Reserved */
    uint32_t SPIENS:1;                  /**< bit:     16  SPI Enable Status                        */
    uint32_t :15;                       /**< bit: 17..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_SR_OFFSET                       (0x10)                                        /**<  (SPI_SR) SPI Status Register  Offset */

#define SPI_SR_RDRF_Pos                     0                                              /**< (SPI_SR) Receive Data Register Full (cleared by reading SPI_RDR) Position */
#define SPI_SR_RDRF_Msk                     (_U_(0x1) << SPI_SR_RDRF_Pos)                  /**< (SPI_SR) Receive Data Register Full (cleared by reading SPI_RDR) Mask */
#define SPI_SR_RDRF                         SPI_SR_RDRF_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_RDRF_Msk instead */
#define SPI_SR_TDRE_Pos                     1                                              /**< (SPI_SR) Transmit Data Register Empty (cleared by writing SPI_TDR) Position */
#define SPI_SR_TDRE_Msk                     (_U_(0x1) << SPI_SR_TDRE_Pos)                  /**< (SPI_SR) Transmit Data Register Empty (cleared by writing SPI_TDR) Mask */
#define SPI_SR_TDRE                         SPI_SR_TDRE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_TDRE_Msk instead */
#define SPI_SR_MODF_Pos                     2                                              /**< (SPI_SR) Mode Fault Error (cleared on read) Position */
#define SPI_SR_MODF_Msk                     (_U_(0x1) << SPI_SR_MODF_Pos)                  /**< (SPI_SR) Mode Fault Error (cleared on read) Mask */
#define SPI_SR_MODF                         SPI_SR_MODF_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_MODF_Msk instead */
#define SPI_SR_OVRES_Pos                    3                                              /**< (SPI_SR) Overrun Error Status (cleared on read) Position */
#define SPI_SR_OVRES_Msk                    (_U_(0x1) << SPI_SR_OVRES_Pos)                 /**< (SPI_SR) Overrun Error Status (cleared on read) Mask */
#define SPI_SR_OVRES                        SPI_SR_OVRES_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_OVRES_Msk instead */
#define SPI_SR_ENDRX_Pos                    4                                              /**< (SPI_SR) End of RX buffer (cleared by writing SPI_RCR or SPI_RNCR) Position */
#define SPI_SR_ENDRX_Msk                    (_U_(0x1) << SPI_SR_ENDRX_Pos)                 /**< (SPI_SR) End of RX buffer (cleared by writing SPI_RCR or SPI_RNCR) Mask */
#define SPI_SR_ENDRX                        SPI_SR_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_ENDRX_Msk instead */
#define SPI_SR_ENDTX_Pos                    5                                              /**< (SPI_SR) End of TX buffer (cleared by writing SPI_TCR or SPI_TNCR) Position */
#define SPI_SR_ENDTX_Msk                    (_U_(0x1) << SPI_SR_ENDTX_Pos)                 /**< (SPI_SR) End of TX buffer (cleared by writing SPI_TCR or SPI_TNCR) Mask */
#define SPI_SR_ENDTX                        SPI_SR_ENDTX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_ENDTX_Msk instead */
#define SPI_SR_RXBUFF_Pos                   6                                              /**< (SPI_SR) RX Buffer Full (cleared by writing SPI_RCR or SPI_RNCR) Position */
#define SPI_SR_RXBUFF_Msk                   (_U_(0x1) << SPI_SR_RXBUFF_Pos)                /**< (SPI_SR) RX Buffer Full (cleared by writing SPI_RCR or SPI_RNCR) Mask */
#define SPI_SR_RXBUFF                       SPI_SR_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_RXBUFF_Msk instead */
#define SPI_SR_TXBUFE_Pos                   7                                              /**< (SPI_SR) TX Buffer Empty (cleared by writing SPI_TCR or SPI_TNCR) Position */
#define SPI_SR_TXBUFE_Msk                   (_U_(0x1) << SPI_SR_TXBUFE_Pos)                /**< (SPI_SR) TX Buffer Empty (cleared by writing SPI_TCR or SPI_TNCR) Mask */
#define SPI_SR_TXBUFE                       SPI_SR_TXBUFE_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_TXBUFE_Msk instead */
#define SPI_SR_NSSR_Pos                     8                                              /**< (SPI_SR) NSS Rising (cleared on read) Position */
#define SPI_SR_NSSR_Msk                     (_U_(0x1) << SPI_SR_NSSR_Pos)                  /**< (SPI_SR) NSS Rising (cleared on read) Mask */
#define SPI_SR_NSSR                         SPI_SR_NSSR_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_NSSR_Msk instead */
#define SPI_SR_TXEMPTY_Pos                  9                                              /**< (SPI_SR) Transmission Registers Empty (cleared by writing SPI_TDR) Position */
#define SPI_SR_TXEMPTY_Msk                  (_U_(0x1) << SPI_SR_TXEMPTY_Pos)               /**< (SPI_SR) Transmission Registers Empty (cleared by writing SPI_TDR) Mask */
#define SPI_SR_TXEMPTY                      SPI_SR_TXEMPTY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_TXEMPTY_Msk instead */
#define SPI_SR_UNDES_Pos                    10                                             /**< (SPI_SR) Underrun Error Status (slave mode only) (cleared on read) Position */
#define SPI_SR_UNDES_Msk                    (_U_(0x1) << SPI_SR_UNDES_Pos)                 /**< (SPI_SR) Underrun Error Status (slave mode only) (cleared on read) Mask */
#define SPI_SR_UNDES                        SPI_SR_UNDES_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_UNDES_Msk instead */
#define SPI_SR_CMP_Pos                      11                                             /**< (SPI_SR) Comparison Status (cleared on read) Position */
#define SPI_SR_CMP_Msk                      (_U_(0x1) << SPI_SR_CMP_Pos)                   /**< (SPI_SR) Comparison Status (cleared on read) Mask */
#define SPI_SR_CMP                          SPI_SR_CMP_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_CMP_Msk instead */
#define SPI_SR_SPIENS_Pos                   16                                             /**< (SPI_SR) SPI Enable Status Position */
#define SPI_SR_SPIENS_Msk                   (_U_(0x1) << SPI_SR_SPIENS_Pos)                /**< (SPI_SR) SPI Enable Status Mask */
#define SPI_SR_SPIENS                       SPI_SR_SPIENS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_SR_SPIENS_Msk instead */
#define SPI_SR_MASK                         _U_(0x10FFF)                                   /**< \deprecated (SPI_SR) Register MASK  (Use SPI_SR_Msk instead)  */
#define SPI_SR_Msk                          _U_(0x10FFF)                                   /**< (SPI_SR) Register Mask  */


/* -------- SPI_IER : (SPI Offset: 0x14) (/W 32) SPI Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RDRF:1;                    /**< bit:      0  Receive Data Register Full Interrupt Enable */
    uint32_t TDRE:1;                    /**< bit:      1  SPI Transmit Data Register Empty Interrupt Enable */
    uint32_t MODF:1;                    /**< bit:      2  Mode Fault Error Interrupt Enable        */
    uint32_t OVRES:1;                   /**< bit:      3  Overrun Error Interrupt Enable           */
    uint32_t ENDRX:1;                   /**< bit:      4  End of Receive Buffer Interrupt Enable   */
    uint32_t ENDTX:1;                   /**< bit:      5  End of Transmit Buffer Interrupt Enable  */
    uint32_t RXBUFF:1;                  /**< bit:      6  Receive Buffer Full Interrupt Enable     */
    uint32_t TXBUFE:1;                  /**< bit:      7  Transmit Buffer Empty Interrupt Enable   */
    uint32_t NSSR:1;                    /**< bit:      8  NSS Rising Interrupt Enable              */
    uint32_t TXEMPTY:1;                 /**< bit:      9  Transmission Registers Empty Enable      */
    uint32_t UNDES:1;                   /**< bit:     10  Underrun Error Interrupt Enable          */
    uint32_t CMP:1;                     /**< bit:     11  Comparison Interrupt Enable              */
    uint32_t :20;                       /**< bit: 12..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_IER_OFFSET                      (0x14)                                        /**<  (SPI_IER) SPI Interrupt Enable Register  Offset */

#define SPI_IER_RDRF_Pos                    0                                              /**< (SPI_IER) Receive Data Register Full Interrupt Enable Position */
#define SPI_IER_RDRF_Msk                    (_U_(0x1) << SPI_IER_RDRF_Pos)                 /**< (SPI_IER) Receive Data Register Full Interrupt Enable Mask */
#define SPI_IER_RDRF                        SPI_IER_RDRF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_RDRF_Msk instead */
#define SPI_IER_TDRE_Pos                    1                                              /**< (SPI_IER) SPI Transmit Data Register Empty Interrupt Enable Position */
#define SPI_IER_TDRE_Msk                    (_U_(0x1) << SPI_IER_TDRE_Pos)                 /**< (SPI_IER) SPI Transmit Data Register Empty Interrupt Enable Mask */
#define SPI_IER_TDRE                        SPI_IER_TDRE_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_TDRE_Msk instead */
#define SPI_IER_MODF_Pos                    2                                              /**< (SPI_IER) Mode Fault Error Interrupt Enable Position */
#define SPI_IER_MODF_Msk                    (_U_(0x1) << SPI_IER_MODF_Pos)                 /**< (SPI_IER) Mode Fault Error Interrupt Enable Mask */
#define SPI_IER_MODF                        SPI_IER_MODF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_MODF_Msk instead */
#define SPI_IER_OVRES_Pos                   3                                              /**< (SPI_IER) Overrun Error Interrupt Enable Position */
#define SPI_IER_OVRES_Msk                   (_U_(0x1) << SPI_IER_OVRES_Pos)                /**< (SPI_IER) Overrun Error Interrupt Enable Mask */
#define SPI_IER_OVRES                       SPI_IER_OVRES_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_OVRES_Msk instead */
#define SPI_IER_ENDRX_Pos                   4                                              /**< (SPI_IER) End of Receive Buffer Interrupt Enable Position */
#define SPI_IER_ENDRX_Msk                   (_U_(0x1) << SPI_IER_ENDRX_Pos)                /**< (SPI_IER) End of Receive Buffer Interrupt Enable Mask */
#define SPI_IER_ENDRX                       SPI_IER_ENDRX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_ENDRX_Msk instead */
#define SPI_IER_ENDTX_Pos                   5                                              /**< (SPI_IER) End of Transmit Buffer Interrupt Enable Position */
#define SPI_IER_ENDTX_Msk                   (_U_(0x1) << SPI_IER_ENDTX_Pos)                /**< (SPI_IER) End of Transmit Buffer Interrupt Enable Mask */
#define SPI_IER_ENDTX                       SPI_IER_ENDTX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_ENDTX_Msk instead */
#define SPI_IER_RXBUFF_Pos                  6                                              /**< (SPI_IER) Receive Buffer Full Interrupt Enable Position */
#define SPI_IER_RXBUFF_Msk                  (_U_(0x1) << SPI_IER_RXBUFF_Pos)               /**< (SPI_IER) Receive Buffer Full Interrupt Enable Mask */
#define SPI_IER_RXBUFF                      SPI_IER_RXBUFF_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_RXBUFF_Msk instead */
#define SPI_IER_TXBUFE_Pos                  7                                              /**< (SPI_IER) Transmit Buffer Empty Interrupt Enable Position */
#define SPI_IER_TXBUFE_Msk                  (_U_(0x1) << SPI_IER_TXBUFE_Pos)               /**< (SPI_IER) Transmit Buffer Empty Interrupt Enable Mask */
#define SPI_IER_TXBUFE                      SPI_IER_TXBUFE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_TXBUFE_Msk instead */
#define SPI_IER_NSSR_Pos                    8                                              /**< (SPI_IER) NSS Rising Interrupt Enable Position */
#define SPI_IER_NSSR_Msk                    (_U_(0x1) << SPI_IER_NSSR_Pos)                 /**< (SPI_IER) NSS Rising Interrupt Enable Mask */
#define SPI_IER_NSSR                        SPI_IER_NSSR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_NSSR_Msk instead */
#define SPI_IER_TXEMPTY_Pos                 9                                              /**< (SPI_IER) Transmission Registers Empty Enable Position */
#define SPI_IER_TXEMPTY_Msk                 (_U_(0x1) << SPI_IER_TXEMPTY_Pos)              /**< (SPI_IER) Transmission Registers Empty Enable Mask */
#define SPI_IER_TXEMPTY                     SPI_IER_TXEMPTY_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_TXEMPTY_Msk instead */
#define SPI_IER_UNDES_Pos                   10                                             /**< (SPI_IER) Underrun Error Interrupt Enable Position */
#define SPI_IER_UNDES_Msk                   (_U_(0x1) << SPI_IER_UNDES_Pos)                /**< (SPI_IER) Underrun Error Interrupt Enable Mask */
#define SPI_IER_UNDES                       SPI_IER_UNDES_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_UNDES_Msk instead */
#define SPI_IER_CMP_Pos                     11                                             /**< (SPI_IER) Comparison Interrupt Enable Position */
#define SPI_IER_CMP_Msk                     (_U_(0x1) << SPI_IER_CMP_Pos)                  /**< (SPI_IER) Comparison Interrupt Enable Mask */
#define SPI_IER_CMP                         SPI_IER_CMP_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IER_CMP_Msk instead */
#define SPI_IER_MASK                        _U_(0xFFF)                                     /**< \deprecated (SPI_IER) Register MASK  (Use SPI_IER_Msk instead)  */
#define SPI_IER_Msk                         _U_(0xFFF)                                     /**< (SPI_IER) Register Mask  */


/* -------- SPI_IDR : (SPI Offset: 0x18) (/W 32) SPI Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RDRF:1;                    /**< bit:      0  Receive Data Register Full Interrupt Disable */
    uint32_t TDRE:1;                    /**< bit:      1  SPI Transmit Data Register Empty Interrupt Disable */
    uint32_t MODF:1;                    /**< bit:      2  Mode Fault Error Interrupt Disable       */
    uint32_t OVRES:1;                   /**< bit:      3  Overrun Error Interrupt Disable          */
    uint32_t ENDRX:1;                   /**< bit:      4  End of Receive Buffer Interrupt Disable  */
    uint32_t ENDTX:1;                   /**< bit:      5  End of Transmit Buffer Interrupt Disable */
    uint32_t RXBUFF:1;                  /**< bit:      6  Receive Buffer Full Interrupt Disable    */
    uint32_t TXBUFE:1;                  /**< bit:      7  Transmit Buffer Empty Interrupt Disable  */
    uint32_t NSSR:1;                    /**< bit:      8  NSS Rising Interrupt Disable             */
    uint32_t TXEMPTY:1;                 /**< bit:      9  Transmission Registers Empty Disable     */
    uint32_t UNDES:1;                   /**< bit:     10  Underrun Error Interrupt Disable         */
    uint32_t CMP:1;                     /**< bit:     11  Comparison Interrupt Disable             */
    uint32_t :20;                       /**< bit: 12..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_IDR_OFFSET                      (0x18)                                        /**<  (SPI_IDR) SPI Interrupt Disable Register  Offset */

#define SPI_IDR_RDRF_Pos                    0                                              /**< (SPI_IDR) Receive Data Register Full Interrupt Disable Position */
#define SPI_IDR_RDRF_Msk                    (_U_(0x1) << SPI_IDR_RDRF_Pos)                 /**< (SPI_IDR) Receive Data Register Full Interrupt Disable Mask */
#define SPI_IDR_RDRF                        SPI_IDR_RDRF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_RDRF_Msk instead */
#define SPI_IDR_TDRE_Pos                    1                                              /**< (SPI_IDR) SPI Transmit Data Register Empty Interrupt Disable Position */
#define SPI_IDR_TDRE_Msk                    (_U_(0x1) << SPI_IDR_TDRE_Pos)                 /**< (SPI_IDR) SPI Transmit Data Register Empty Interrupt Disable Mask */
#define SPI_IDR_TDRE                        SPI_IDR_TDRE_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_TDRE_Msk instead */
#define SPI_IDR_MODF_Pos                    2                                              /**< (SPI_IDR) Mode Fault Error Interrupt Disable Position */
#define SPI_IDR_MODF_Msk                    (_U_(0x1) << SPI_IDR_MODF_Pos)                 /**< (SPI_IDR) Mode Fault Error Interrupt Disable Mask */
#define SPI_IDR_MODF                        SPI_IDR_MODF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_MODF_Msk instead */
#define SPI_IDR_OVRES_Pos                   3                                              /**< (SPI_IDR) Overrun Error Interrupt Disable Position */
#define SPI_IDR_OVRES_Msk                   (_U_(0x1) << SPI_IDR_OVRES_Pos)                /**< (SPI_IDR) Overrun Error Interrupt Disable Mask */
#define SPI_IDR_OVRES                       SPI_IDR_OVRES_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_OVRES_Msk instead */
#define SPI_IDR_ENDRX_Pos                   4                                              /**< (SPI_IDR) End of Receive Buffer Interrupt Disable Position */
#define SPI_IDR_ENDRX_Msk                   (_U_(0x1) << SPI_IDR_ENDRX_Pos)                /**< (SPI_IDR) End of Receive Buffer Interrupt Disable Mask */
#define SPI_IDR_ENDRX                       SPI_IDR_ENDRX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_ENDRX_Msk instead */
#define SPI_IDR_ENDTX_Pos                   5                                              /**< (SPI_IDR) End of Transmit Buffer Interrupt Disable Position */
#define SPI_IDR_ENDTX_Msk                   (_U_(0x1) << SPI_IDR_ENDTX_Pos)                /**< (SPI_IDR) End of Transmit Buffer Interrupt Disable Mask */
#define SPI_IDR_ENDTX                       SPI_IDR_ENDTX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_ENDTX_Msk instead */
#define SPI_IDR_RXBUFF_Pos                  6                                              /**< (SPI_IDR) Receive Buffer Full Interrupt Disable Position */
#define SPI_IDR_RXBUFF_Msk                  (_U_(0x1) << SPI_IDR_RXBUFF_Pos)               /**< (SPI_IDR) Receive Buffer Full Interrupt Disable Mask */
#define SPI_IDR_RXBUFF                      SPI_IDR_RXBUFF_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_RXBUFF_Msk instead */
#define SPI_IDR_TXBUFE_Pos                  7                                              /**< (SPI_IDR) Transmit Buffer Empty Interrupt Disable Position */
#define SPI_IDR_TXBUFE_Msk                  (_U_(0x1) << SPI_IDR_TXBUFE_Pos)               /**< (SPI_IDR) Transmit Buffer Empty Interrupt Disable Mask */
#define SPI_IDR_TXBUFE                      SPI_IDR_TXBUFE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_TXBUFE_Msk instead */
#define SPI_IDR_NSSR_Pos                    8                                              /**< (SPI_IDR) NSS Rising Interrupt Disable Position */
#define SPI_IDR_NSSR_Msk                    (_U_(0x1) << SPI_IDR_NSSR_Pos)                 /**< (SPI_IDR) NSS Rising Interrupt Disable Mask */
#define SPI_IDR_NSSR                        SPI_IDR_NSSR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_NSSR_Msk instead */
#define SPI_IDR_TXEMPTY_Pos                 9                                              /**< (SPI_IDR) Transmission Registers Empty Disable Position */
#define SPI_IDR_TXEMPTY_Msk                 (_U_(0x1) << SPI_IDR_TXEMPTY_Pos)              /**< (SPI_IDR) Transmission Registers Empty Disable Mask */
#define SPI_IDR_TXEMPTY                     SPI_IDR_TXEMPTY_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_TXEMPTY_Msk instead */
#define SPI_IDR_UNDES_Pos                   10                                             /**< (SPI_IDR) Underrun Error Interrupt Disable Position */
#define SPI_IDR_UNDES_Msk                   (_U_(0x1) << SPI_IDR_UNDES_Pos)                /**< (SPI_IDR) Underrun Error Interrupt Disable Mask */
#define SPI_IDR_UNDES                       SPI_IDR_UNDES_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_UNDES_Msk instead */
#define SPI_IDR_CMP_Pos                     11                                             /**< (SPI_IDR) Comparison Interrupt Disable Position */
#define SPI_IDR_CMP_Msk                     (_U_(0x1) << SPI_IDR_CMP_Pos)                  /**< (SPI_IDR) Comparison Interrupt Disable Mask */
#define SPI_IDR_CMP                         SPI_IDR_CMP_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IDR_CMP_Msk instead */
#define SPI_IDR_MASK                        _U_(0xFFF)                                     /**< \deprecated (SPI_IDR) Register MASK  (Use SPI_IDR_Msk instead)  */
#define SPI_IDR_Msk                         _U_(0xFFF)                                     /**< (SPI_IDR) Register Mask  */


/* -------- SPI_IMR : (SPI Offset: 0x1c) (R/ 32) SPI Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RDRF:1;                    /**< bit:      0  Receive Data Register Full Interrupt Mask */
    uint32_t TDRE:1;                    /**< bit:      1  SPI Transmit Data Register Empty Interrupt Mask */
    uint32_t MODF:1;                    /**< bit:      2  Mode Fault Error Interrupt Mask          */
    uint32_t OVRES:1;                   /**< bit:      3  Overrun Error Interrupt Mask             */
    uint32_t ENDRX:1;                   /**< bit:      4  End of Receive Buffer Interrupt Mask     */
    uint32_t ENDTX:1;                   /**< bit:      5  End of Transmit Buffer Interrupt Mask    */
    uint32_t RXBUFF:1;                  /**< bit:      6  Receive Buffer Full Interrupt Mask       */
    uint32_t TXBUFE:1;                  /**< bit:      7  Transmit Buffer Empty Interrupt Mask     */
    uint32_t NSSR:1;                    /**< bit:      8  NSS Rising Interrupt Mask                */
    uint32_t TXEMPTY:1;                 /**< bit:      9  Transmission Registers Empty Mask        */
    uint32_t UNDES:1;                   /**< bit:     10  Underrun Error Interrupt Mask            */
    uint32_t CMP:1;                     /**< bit:     11  Comparison Interrupt Mask                */
    uint32_t :20;                       /**< bit: 12..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_IMR_OFFSET                      (0x1C)                                        /**<  (SPI_IMR) SPI Interrupt Mask Register  Offset */

#define SPI_IMR_RDRF_Pos                    0                                              /**< (SPI_IMR) Receive Data Register Full Interrupt Mask Position */
#define SPI_IMR_RDRF_Msk                    (_U_(0x1) << SPI_IMR_RDRF_Pos)                 /**< (SPI_IMR) Receive Data Register Full Interrupt Mask Mask */
#define SPI_IMR_RDRF                        SPI_IMR_RDRF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_RDRF_Msk instead */
#define SPI_IMR_TDRE_Pos                    1                                              /**< (SPI_IMR) SPI Transmit Data Register Empty Interrupt Mask Position */
#define SPI_IMR_TDRE_Msk                    (_U_(0x1) << SPI_IMR_TDRE_Pos)                 /**< (SPI_IMR) SPI Transmit Data Register Empty Interrupt Mask Mask */
#define SPI_IMR_TDRE                        SPI_IMR_TDRE_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_TDRE_Msk instead */
#define SPI_IMR_MODF_Pos                    2                                              /**< (SPI_IMR) Mode Fault Error Interrupt Mask Position */
#define SPI_IMR_MODF_Msk                    (_U_(0x1) << SPI_IMR_MODF_Pos)                 /**< (SPI_IMR) Mode Fault Error Interrupt Mask Mask */
#define SPI_IMR_MODF                        SPI_IMR_MODF_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_MODF_Msk instead */
#define SPI_IMR_OVRES_Pos                   3                                              /**< (SPI_IMR) Overrun Error Interrupt Mask Position */
#define SPI_IMR_OVRES_Msk                   (_U_(0x1) << SPI_IMR_OVRES_Pos)                /**< (SPI_IMR) Overrun Error Interrupt Mask Mask */
#define SPI_IMR_OVRES                       SPI_IMR_OVRES_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_OVRES_Msk instead */
#define SPI_IMR_ENDRX_Pos                   4                                              /**< (SPI_IMR) End of Receive Buffer Interrupt Mask Position */
#define SPI_IMR_ENDRX_Msk                   (_U_(0x1) << SPI_IMR_ENDRX_Pos)                /**< (SPI_IMR) End of Receive Buffer Interrupt Mask Mask */
#define SPI_IMR_ENDRX                       SPI_IMR_ENDRX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_ENDRX_Msk instead */
#define SPI_IMR_ENDTX_Pos                   5                                              /**< (SPI_IMR) End of Transmit Buffer Interrupt Mask Position */
#define SPI_IMR_ENDTX_Msk                   (_U_(0x1) << SPI_IMR_ENDTX_Pos)                /**< (SPI_IMR) End of Transmit Buffer Interrupt Mask Mask */
#define SPI_IMR_ENDTX                       SPI_IMR_ENDTX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_ENDTX_Msk instead */
#define SPI_IMR_RXBUFF_Pos                  6                                              /**< (SPI_IMR) Receive Buffer Full Interrupt Mask Position */
#define SPI_IMR_RXBUFF_Msk                  (_U_(0x1) << SPI_IMR_RXBUFF_Pos)               /**< (SPI_IMR) Receive Buffer Full Interrupt Mask Mask */
#define SPI_IMR_RXBUFF                      SPI_IMR_RXBUFF_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_RXBUFF_Msk instead */
#define SPI_IMR_TXBUFE_Pos                  7                                              /**< (SPI_IMR) Transmit Buffer Empty Interrupt Mask Position */
#define SPI_IMR_TXBUFE_Msk                  (_U_(0x1) << SPI_IMR_TXBUFE_Pos)               /**< (SPI_IMR) Transmit Buffer Empty Interrupt Mask Mask */
#define SPI_IMR_TXBUFE                      SPI_IMR_TXBUFE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_TXBUFE_Msk instead */
#define SPI_IMR_NSSR_Pos                    8                                              /**< (SPI_IMR) NSS Rising Interrupt Mask Position */
#define SPI_IMR_NSSR_Msk                    (_U_(0x1) << SPI_IMR_NSSR_Pos)                 /**< (SPI_IMR) NSS Rising Interrupt Mask Mask */
#define SPI_IMR_NSSR                        SPI_IMR_NSSR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_NSSR_Msk instead */
#define SPI_IMR_TXEMPTY_Pos                 9                                              /**< (SPI_IMR) Transmission Registers Empty Mask Position */
#define SPI_IMR_TXEMPTY_Msk                 (_U_(0x1) << SPI_IMR_TXEMPTY_Pos)              /**< (SPI_IMR) Transmission Registers Empty Mask Mask */
#define SPI_IMR_TXEMPTY                     SPI_IMR_TXEMPTY_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_TXEMPTY_Msk instead */
#define SPI_IMR_UNDES_Pos                   10                                             /**< (SPI_IMR) Underrun Error Interrupt Mask Position */
#define SPI_IMR_UNDES_Msk                   (_U_(0x1) << SPI_IMR_UNDES_Pos)                /**< (SPI_IMR) Underrun Error Interrupt Mask Mask */
#define SPI_IMR_UNDES                       SPI_IMR_UNDES_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_UNDES_Msk instead */
#define SPI_IMR_CMP_Pos                     11                                             /**< (SPI_IMR) Comparison Interrupt Mask Position */
#define SPI_IMR_CMP_Msk                     (_U_(0x1) << SPI_IMR_CMP_Pos)                  /**< (SPI_IMR) Comparison Interrupt Mask Mask */
#define SPI_IMR_CMP                         SPI_IMR_CMP_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_IMR_CMP_Msk instead */
#define SPI_IMR_MASK                        _U_(0xFFF)                                     /**< \deprecated (SPI_IMR) Register MASK  (Use SPI_IMR_Msk instead)  */
#define SPI_IMR_Msk                         _U_(0xFFF)                                     /**< (SPI_IMR) Register Mask  */


/* -------- SPI_CSR : (SPI Offset: 0x30) (R/W 32) SPI Chip Select Register 0 -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CPOL:1;                    /**< bit:      0  Clock Polarity                           */
    uint32_t NCPHA:1;                   /**< bit:      1  Clock Phase                              */
    uint32_t CSNAAT:1;                  /**< bit:      2  Chip Select Not Active After Transfer (Ignored if CSAAT = 1) */
    uint32_t CSAAT:1;                   /**< bit:      3  Chip Select Active After Transfer        */
    uint32_t BITS:4;                    /**< bit:   4..7  Bits Per Transfer                        */
    uint32_t SCBR:8;                    /**< bit:  8..15  Serial Clock Bit Rate                    */
    uint32_t DLYBS:8;                   /**< bit: 16..23  Delay Before SPCK                        */
    uint32_t DLYBCT:8;                  /**< bit: 24..31  Delay Between Consecutive Transfers      */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_CSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_CSR_OFFSET                      (0x30)                                        /**<  (SPI_CSR) SPI Chip Select Register 0  Offset */

#define SPI_CSR_CPOL_Pos                    0                                              /**< (SPI_CSR) Clock Polarity Position */
#define SPI_CSR_CPOL_Msk                    (_U_(0x1) << SPI_CSR_CPOL_Pos)                 /**< (SPI_CSR) Clock Polarity Mask */
#define SPI_CSR_CPOL                        SPI_CSR_CPOL_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CSR_CPOL_Msk instead */
#define SPI_CSR_NCPHA_Pos                   1                                              /**< (SPI_CSR) Clock Phase Position */
#define SPI_CSR_NCPHA_Msk                   (_U_(0x1) << SPI_CSR_NCPHA_Pos)                /**< (SPI_CSR) Clock Phase Mask */
#define SPI_CSR_NCPHA                       SPI_CSR_NCPHA_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CSR_NCPHA_Msk instead */
#define SPI_CSR_CSNAAT_Pos                  2                                              /**< (SPI_CSR) Chip Select Not Active After Transfer (Ignored if CSAAT = 1) Position */
#define SPI_CSR_CSNAAT_Msk                  (_U_(0x1) << SPI_CSR_CSNAAT_Pos)               /**< (SPI_CSR) Chip Select Not Active After Transfer (Ignored if CSAAT = 1) Mask */
#define SPI_CSR_CSNAAT                      SPI_CSR_CSNAAT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CSR_CSNAAT_Msk instead */
#define SPI_CSR_CSAAT_Pos                   3                                              /**< (SPI_CSR) Chip Select Active After Transfer Position */
#define SPI_CSR_CSAAT_Msk                   (_U_(0x1) << SPI_CSR_CSAAT_Pos)                /**< (SPI_CSR) Chip Select Active After Transfer Mask */
#define SPI_CSR_CSAAT                       SPI_CSR_CSAAT_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_CSR_CSAAT_Msk instead */
#define SPI_CSR_BITS_Pos                    4                                              /**< (SPI_CSR) Bits Per Transfer Position */
#define SPI_CSR_BITS_Msk                    (_U_(0xF) << SPI_CSR_BITS_Pos)                 /**< (SPI_CSR) Bits Per Transfer Mask */
#define SPI_CSR_BITS(value)                 (SPI_CSR_BITS_Msk & ((value) << SPI_CSR_BITS_Pos))
#define   SPI_CSR_BITS_8_BIT_Val            _U_(0x0)                                       /**< (SPI_CSR) 8 bits for transfer  */
#define   SPI_CSR_BITS_9_BIT_Val            _U_(0x1)                                       /**< (SPI_CSR) 9 bits for transfer  */
#define   SPI_CSR_BITS_10_BIT_Val           _U_(0x2)                                       /**< (SPI_CSR) 10 bits for transfer  */
#define   SPI_CSR_BITS_11_BIT_Val           _U_(0x3)                                       /**< (SPI_CSR) 11 bits for transfer  */
#define   SPI_CSR_BITS_12_BIT_Val           _U_(0x4)                                       /**< (SPI_CSR) 12 bits for transfer  */
#define   SPI_CSR_BITS_13_BIT_Val           _U_(0x5)                                       /**< (SPI_CSR) 13 bits for transfer  */
#define   SPI_CSR_BITS_14_BIT_Val           _U_(0x6)                                       /**< (SPI_CSR) 14 bits for transfer  */
#define   SPI_CSR_BITS_15_BIT_Val           _U_(0x7)                                       /**< (SPI_CSR) 15 bits for transfer  */
#define   SPI_CSR_BITS_16_BIT_Val           _U_(0x8)                                       /**< (SPI_CSR) 16 bits for transfer  */
#define SPI_CSR_BITS_8_BIT                  (SPI_CSR_BITS_8_BIT_Val << SPI_CSR_BITS_Pos)   /**< (SPI_CSR) 8 bits for transfer Position  */
#define SPI_CSR_BITS_9_BIT                  (SPI_CSR_BITS_9_BIT_Val << SPI_CSR_BITS_Pos)   /**< (SPI_CSR) 9 bits for transfer Position  */
#define SPI_CSR_BITS_10_BIT                 (SPI_CSR_BITS_10_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 10 bits for transfer Position  */
#define SPI_CSR_BITS_11_BIT                 (SPI_CSR_BITS_11_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 11 bits for transfer Position  */
#define SPI_CSR_BITS_12_BIT                 (SPI_CSR_BITS_12_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 12 bits for transfer Position  */
#define SPI_CSR_BITS_13_BIT                 (SPI_CSR_BITS_13_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 13 bits for transfer Position  */
#define SPI_CSR_BITS_14_BIT                 (SPI_CSR_BITS_14_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 14 bits for transfer Position  */
#define SPI_CSR_BITS_15_BIT                 (SPI_CSR_BITS_15_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 15 bits for transfer Position  */
#define SPI_CSR_BITS_16_BIT                 (SPI_CSR_BITS_16_BIT_Val << SPI_CSR_BITS_Pos)  /**< (SPI_CSR) 16 bits for transfer Position  */
#define SPI_CSR_SCBR_Pos                    8                                              /**< (SPI_CSR) Serial Clock Bit Rate Position */
#define SPI_CSR_SCBR_Msk                    (_U_(0xFF) << SPI_CSR_SCBR_Pos)                /**< (SPI_CSR) Serial Clock Bit Rate Mask */
#define SPI_CSR_SCBR(value)                 (SPI_CSR_SCBR_Msk & ((value) << SPI_CSR_SCBR_Pos))
#define SPI_CSR_DLYBS_Pos                   16                                             /**< (SPI_CSR) Delay Before SPCK Position */
#define SPI_CSR_DLYBS_Msk                   (_U_(0xFF) << SPI_CSR_DLYBS_Pos)               /**< (SPI_CSR) Delay Before SPCK Mask */
#define SPI_CSR_DLYBS(value)                (SPI_CSR_DLYBS_Msk & ((value) << SPI_CSR_DLYBS_Pos))
#define SPI_CSR_DLYBCT_Pos                  24                                             /**< (SPI_CSR) Delay Between Consecutive Transfers Position */
#define SPI_CSR_DLYBCT_Msk                  (_U_(0xFF) << SPI_CSR_DLYBCT_Pos)              /**< (SPI_CSR) Delay Between Consecutive Transfers Mask */
#define SPI_CSR_DLYBCT(value)               (SPI_CSR_DLYBCT_Msk & ((value) << SPI_CSR_DLYBCT_Pos))
#define SPI_CSR_MASK                        _U_(0xFFFFFFFF)                                /**< \deprecated (SPI_CSR) Register MASK  (Use SPI_CSR_Msk instead)  */
#define SPI_CSR_Msk                         _U_(0xFFFFFFFF)                                /**< (SPI_CSR) Register Mask  */


/* -------- SPI_CMPR : (SPI Offset: 0x48) (R/W 32) SPI Comparison Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t VAL1:16;                   /**< bit:  0..15  First Comparison Value for Received Character */
    uint32_t VAL2:16;                   /**< bit: 16..31  Second Comparison Value for Received Character */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_CMPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_CMPR_OFFSET                     (0x48)                                        /**<  (SPI_CMPR) SPI Comparison Register  Offset */

#define SPI_CMPR_VAL1_Pos                   0                                              /**< (SPI_CMPR) First Comparison Value for Received Character Position */
#define SPI_CMPR_VAL1_Msk                   (_U_(0xFFFF) << SPI_CMPR_VAL1_Pos)             /**< (SPI_CMPR) First Comparison Value for Received Character Mask */
#define SPI_CMPR_VAL1(value)                (SPI_CMPR_VAL1_Msk & ((value) << SPI_CMPR_VAL1_Pos))
#define SPI_CMPR_VAL2_Pos                   16                                             /**< (SPI_CMPR) Second Comparison Value for Received Character Position */
#define SPI_CMPR_VAL2_Msk                   (_U_(0xFFFF) << SPI_CMPR_VAL2_Pos)             /**< (SPI_CMPR) Second Comparison Value for Received Character Mask */
#define SPI_CMPR_VAL2(value)                (SPI_CMPR_VAL2_Msk & ((value) << SPI_CMPR_VAL2_Pos))
#define SPI_CMPR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (SPI_CMPR) Register MASK  (Use SPI_CMPR_Msk instead)  */
#define SPI_CMPR_Msk                        _U_(0xFFFFFFFF)                                /**< (SPI_CMPR) Register Mask  */


/* -------- SPI_WPMR : (SPI Offset: 0xe4) (R/W 32) SPI Write Protection Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                  */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protect Key                        */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_WPMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_WPMR_OFFSET                     (0xE4)                                        /**<  (SPI_WPMR) SPI Write Protection Mode Register  Offset */

#define SPI_WPMR_WPEN_Pos                   0                                              /**< (SPI_WPMR) Write Protection Enable Position */
#define SPI_WPMR_WPEN_Msk                   (_U_(0x1) << SPI_WPMR_WPEN_Pos)                /**< (SPI_WPMR) Write Protection Enable Mask */
#define SPI_WPMR_WPEN                       SPI_WPMR_WPEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_WPMR_WPEN_Msk instead */
#define SPI_WPMR_WPKEY_Pos                  8                                              /**< (SPI_WPMR) Write Protect Key Position */
#define SPI_WPMR_WPKEY_Msk                  (_U_(0xFFFFFF) << SPI_WPMR_WPKEY_Pos)          /**< (SPI_WPMR) Write Protect Key Mask */
#define SPI_WPMR_WPKEY(value)               (SPI_WPMR_WPKEY_Msk & ((value) << SPI_WPMR_WPKEY_Pos))
#define   SPI_WPMR_WPKEY_PASSWD_Val         _U_(0x535049)                                  /**< (SPI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0  */
#define SPI_WPMR_WPKEY_PASSWD               (SPI_WPMR_WPKEY_PASSWD_Val << SPI_WPMR_WPKEY_Pos)  /**< (SPI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0 Position  */
#define SPI_WPMR_MASK                       _U_(0xFFFFFF01)                                /**< \deprecated (SPI_WPMR) Register MASK  (Use SPI_WPMR_Msk instead)  */
#define SPI_WPMR_Msk                        _U_(0xFFFFFF01)                                /**< (SPI_WPMR) Register Mask  */


/* -------- SPI_WPSR : (SPI Offset: 0xe8) (R/ 32) SPI Write Protection Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status        */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPVSRC:8;                  /**< bit:  8..15  Write Protection Violation Source        */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_WPSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_WPSR_OFFSET                     (0xE8)                                        /**<  (SPI_WPSR) SPI Write Protection Status Register  Offset */

#define SPI_WPSR_WPVS_Pos                   0                                              /**< (SPI_WPSR) Write Protection Violation Status Position */
#define SPI_WPSR_WPVS_Msk                   (_U_(0x1) << SPI_WPSR_WPVS_Pos)                /**< (SPI_WPSR) Write Protection Violation Status Mask */
#define SPI_WPSR_WPVS                       SPI_WPSR_WPVS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_WPSR_WPVS_Msk instead */
#define SPI_WPSR_WPVSRC_Pos                 8                                              /**< (SPI_WPSR) Write Protection Violation Source Position */
#define SPI_WPSR_WPVSRC_Msk                 (_U_(0xFF) << SPI_WPSR_WPVSRC_Pos)             /**< (SPI_WPSR) Write Protection Violation Source Mask */
#define SPI_WPSR_WPVSRC(value)              (SPI_WPSR_WPVSRC_Msk & ((value) << SPI_WPSR_WPVSRC_Pos))
#define SPI_WPSR_MASK                       _U_(0xFF01)                                    /**< \deprecated (SPI_WPSR) Register MASK  (Use SPI_WPSR_Msk instead)  */
#define SPI_WPSR_Msk                        _U_(0xFF01)                                    /**< (SPI_WPSR) Register Mask  */


/* -------- SPI_RPR : (SPI Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_RPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_RPR_OFFSET                      (0x100)                                       /**<  (SPI_RPR) Receive Pointer Register  Offset */

#define SPI_RPR_RXPTR_Pos                   0                                              /**< (SPI_RPR) Receive Pointer Register Position */
#define SPI_RPR_RXPTR_Msk                   (_U_(0xFFFFFFFF) << SPI_RPR_RXPTR_Pos)         /**< (SPI_RPR) Receive Pointer Register Mask */
#define SPI_RPR_RXPTR(value)                (SPI_RPR_RXPTR_Msk & ((value) << SPI_RPR_RXPTR_Pos))
#define SPI_RPR_MASK                        _U_(0xFFFFFFFF)                                /**< \deprecated (SPI_RPR) Register MASK  (Use SPI_RPR_Msk instead)  */
#define SPI_RPR_Msk                         _U_(0xFFFFFFFF)                                /**< (SPI_RPR) Register Mask  */


/* -------- SPI_RCR : (SPI Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCTR:16;                  /**< bit:  0..15  Receive Counter Register                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_RCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_RCR_OFFSET                      (0x104)                                       /**<  (SPI_RCR) Receive Counter Register  Offset */

#define SPI_RCR_RXCTR_Pos                   0                                              /**< (SPI_RCR) Receive Counter Register Position */
#define SPI_RCR_RXCTR_Msk                   (_U_(0xFFFF) << SPI_RCR_RXCTR_Pos)             /**< (SPI_RCR) Receive Counter Register Mask */
#define SPI_RCR_RXCTR(value)                (SPI_RCR_RXCTR_Msk & ((value) << SPI_RCR_RXCTR_Pos))
#define SPI_RCR_MASK                        _U_(0xFFFF)                                    /**< \deprecated (SPI_RCR) Register MASK  (Use SPI_RCR_Msk instead)  */
#define SPI_RCR_Msk                         _U_(0xFFFF)                                    /**< (SPI_RCR) Register Mask  */


/* -------- SPI_TPR : (SPI Offset: 0x108) (R/W 32) Transmit Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXPTR:32;                  /**< bit:  0..31  Transmit Counter Register                */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_TPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_TPR_OFFSET                      (0x108)                                       /**<  (SPI_TPR) Transmit Pointer Register  Offset */

#define SPI_TPR_TXPTR_Pos                   0                                              /**< (SPI_TPR) Transmit Counter Register Position */
#define SPI_TPR_TXPTR_Msk                   (_U_(0xFFFFFFFF) << SPI_TPR_TXPTR_Pos)         /**< (SPI_TPR) Transmit Counter Register Mask */
#define SPI_TPR_TXPTR(value)                (SPI_TPR_TXPTR_Msk & ((value) << SPI_TPR_TXPTR_Pos))
#define SPI_TPR_MASK                        _U_(0xFFFFFFFF)                                /**< \deprecated (SPI_TPR) Register MASK  (Use SPI_TPR_Msk instead)  */
#define SPI_TPR_Msk                         _U_(0xFFFFFFFF)                                /**< (SPI_TPR) Register Mask  */


/* -------- SPI_TCR : (SPI Offset: 0x10c) (R/W 32) Transmit Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCTR:16;                  /**< bit:  0..15  Transmit Counter Register                */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_TCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_TCR_OFFSET                      (0x10C)                                       /**<  (SPI_TCR) Transmit Counter Register  Offset */

#define SPI_TCR_TXCTR_Pos                   0                                              /**< (SPI_TCR) Transmit Counter Register Position */
#define SPI_TCR_TXCTR_Msk                   (_U_(0xFFFF) << SPI_TCR_TXCTR_Pos)             /**< (SPI_TCR) Transmit Counter Register Mask */
#define SPI_TCR_TXCTR(value)                (SPI_TCR_TXCTR_Msk & ((value) << SPI_TCR_TXCTR_Pos))
#define SPI_TCR_MASK                        _U_(0xFFFF)                                    /**< \deprecated (SPI_TCR) Register MASK  (Use SPI_TCR_Msk instead)  */
#define SPI_TCR_Msk                         _U_(0xFFFF)                                    /**< (SPI_TCR) Register Mask  */


/* -------- SPI_RNPR : (SPI Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_RNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_RNPR_OFFSET                     (0x110)                                       /**<  (SPI_RNPR) Receive Next Pointer Register  Offset */

#define SPI_RNPR_RXNPTR_Pos                 0                                              /**< (SPI_RNPR) Receive Next Pointer Position */
#define SPI_RNPR_RXNPTR_Msk                 (_U_(0xFFFFFFFF) << SPI_RNPR_RXNPTR_Pos)       /**< (SPI_RNPR) Receive Next Pointer Mask */
#define SPI_RNPR_RXNPTR(value)              (SPI_RNPR_RXNPTR_Msk & ((value) << SPI_RNPR_RXNPTR_Pos))
#define SPI_RNPR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (SPI_RNPR) Register MASK  (Use SPI_RNPR_Msk instead)  */
#define SPI_RNPR_Msk                        _U_(0xFFFFFFFF)                                /**< (SPI_RNPR) Register Mask  */


/* -------- SPI_RNCR : (SPI Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_RNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_RNCR_OFFSET                     (0x114)                                       /**<  (SPI_RNCR) Receive Next Counter Register  Offset */

#define SPI_RNCR_RXNCTR_Pos                 0                                              /**< (SPI_RNCR) Receive Next Counter Position */
#define SPI_RNCR_RXNCTR_Msk                 (_U_(0xFFFF) << SPI_RNCR_RXNCTR_Pos)           /**< (SPI_RNCR) Receive Next Counter Mask */
#define SPI_RNCR_RXNCTR(value)              (SPI_RNCR_RXNCTR_Msk & ((value) << SPI_RNCR_RXNCTR_Pos))
#define SPI_RNCR_MASK                       _U_(0xFFFF)                                    /**< \deprecated (SPI_RNCR) Register MASK  (Use SPI_RNCR_Msk instead)  */
#define SPI_RNCR_Msk                        _U_(0xFFFF)                                    /**< (SPI_RNCR) Register Mask  */


/* -------- SPI_TNPR : (SPI Offset: 0x118) (R/W 32) Transmit Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNPTR:32;                 /**< bit:  0..31  Transmit Next Pointer                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_TNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_TNPR_OFFSET                     (0x118)                                       /**<  (SPI_TNPR) Transmit Next Pointer Register  Offset */

#define SPI_TNPR_TXNPTR_Pos                 0                                              /**< (SPI_TNPR) Transmit Next Pointer Position */
#define SPI_TNPR_TXNPTR_Msk                 (_U_(0xFFFFFFFF) << SPI_TNPR_TXNPTR_Pos)       /**< (SPI_TNPR) Transmit Next Pointer Mask */
#define SPI_TNPR_TXNPTR(value)              (SPI_TNPR_TXNPTR_Msk & ((value) << SPI_TNPR_TXNPTR_Pos))
#define SPI_TNPR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (SPI_TNPR) Register MASK  (Use SPI_TNPR_Msk instead)  */
#define SPI_TNPR_Msk                        _U_(0xFFFFFFFF)                                /**< (SPI_TNPR) Register Mask  */


/* -------- SPI_TNCR : (SPI Offset: 0x11c) (R/W 32) Transmit Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNCTR:16;                 /**< bit:  0..15  Transmit Counter Next                    */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} SPI_TNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_TNCR_OFFSET                     (0x11C)                                       /**<  (SPI_TNCR) Transmit Next Counter Register  Offset */

#define SPI_TNCR_TXNCTR_Pos                 0                                              /**< (SPI_TNCR) Transmit Counter Next Position */
#define SPI_TNCR_TXNCTR_Msk                 (_U_(0xFFFF) << SPI_TNCR_TXNCTR_Pos)           /**< (SPI_TNCR) Transmit Counter Next Mask */
#define SPI_TNCR_TXNCTR(value)              (SPI_TNCR_TXNCTR_Msk & ((value) << SPI_TNCR_TXNCTR_Pos))
#define SPI_TNCR_MASK                       _U_(0xFFFF)                                    /**< \deprecated (SPI_TNCR) Register MASK  (Use SPI_TNCR_Msk instead)  */
#define SPI_TNCR_Msk                        _U_(0xFFFF)                                    /**< (SPI_TNCR) Register Mask  */


/* -------- SPI_PTCR : (SPI Offset: 0x120) (/W 32) Transfer Control Register -------- */
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
} SPI_PTCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_PTCR_OFFSET                     (0x120)                                       /**<  (SPI_PTCR) Transfer Control Register  Offset */

#define SPI_PTCR_RXTEN_Pos                  0                                              /**< (SPI_PTCR) Receiver Transfer Enable Position */
#define SPI_PTCR_RXTEN_Msk                  (_U_(0x1) << SPI_PTCR_RXTEN_Pos)               /**< (SPI_PTCR) Receiver Transfer Enable Mask */
#define SPI_PTCR_RXTEN                      SPI_PTCR_RXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_RXTEN_Msk instead */
#define SPI_PTCR_RXTDIS_Pos                 1                                              /**< (SPI_PTCR) Receiver Transfer Disable Position */
#define SPI_PTCR_RXTDIS_Msk                 (_U_(0x1) << SPI_PTCR_RXTDIS_Pos)              /**< (SPI_PTCR) Receiver Transfer Disable Mask */
#define SPI_PTCR_RXTDIS                     SPI_PTCR_RXTDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_RXTDIS_Msk instead */
#define SPI_PTCR_TXTEN_Pos                  8                                              /**< (SPI_PTCR) Transmitter Transfer Enable Position */
#define SPI_PTCR_TXTEN_Msk                  (_U_(0x1) << SPI_PTCR_TXTEN_Pos)               /**< (SPI_PTCR) Transmitter Transfer Enable Mask */
#define SPI_PTCR_TXTEN                      SPI_PTCR_TXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_TXTEN_Msk instead */
#define SPI_PTCR_TXTDIS_Pos                 9                                              /**< (SPI_PTCR) Transmitter Transfer Disable Position */
#define SPI_PTCR_TXTDIS_Msk                 (_U_(0x1) << SPI_PTCR_TXTDIS_Pos)              /**< (SPI_PTCR) Transmitter Transfer Disable Mask */
#define SPI_PTCR_TXTDIS                     SPI_PTCR_TXTDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_TXTDIS_Msk instead */
#define SPI_PTCR_RXCBEN_Pos                 16                                             /**< (SPI_PTCR) Receiver Circular Buffer Enable Position */
#define SPI_PTCR_RXCBEN_Msk                 (_U_(0x1) << SPI_PTCR_RXCBEN_Pos)              /**< (SPI_PTCR) Receiver Circular Buffer Enable Mask */
#define SPI_PTCR_RXCBEN                     SPI_PTCR_RXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_RXCBEN_Msk instead */
#define SPI_PTCR_RXCBDIS_Pos                17                                             /**< (SPI_PTCR) Receiver Circular Buffer Disable Position */
#define SPI_PTCR_RXCBDIS_Msk                (_U_(0x1) << SPI_PTCR_RXCBDIS_Pos)             /**< (SPI_PTCR) Receiver Circular Buffer Disable Mask */
#define SPI_PTCR_RXCBDIS                    SPI_PTCR_RXCBDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_RXCBDIS_Msk instead */
#define SPI_PTCR_TXCBEN_Pos                 18                                             /**< (SPI_PTCR) Transmitter Circular Buffer Enable Position */
#define SPI_PTCR_TXCBEN_Msk                 (_U_(0x1) << SPI_PTCR_TXCBEN_Pos)              /**< (SPI_PTCR) Transmitter Circular Buffer Enable Mask */
#define SPI_PTCR_TXCBEN                     SPI_PTCR_TXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_TXCBEN_Msk instead */
#define SPI_PTCR_TXCBDIS_Pos                19                                             /**< (SPI_PTCR) Transmitter Circular Buffer Disable Position */
#define SPI_PTCR_TXCBDIS_Msk                (_U_(0x1) << SPI_PTCR_TXCBDIS_Pos)             /**< (SPI_PTCR) Transmitter Circular Buffer Disable Mask */
#define SPI_PTCR_TXCBDIS                    SPI_PTCR_TXCBDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_TXCBDIS_Msk instead */
#define SPI_PTCR_ERRCLR_Pos                 24                                             /**< (SPI_PTCR) Transfer Bus Error Clear Position */
#define SPI_PTCR_ERRCLR_Msk                 (_U_(0x1) << SPI_PTCR_ERRCLR_Pos)              /**< (SPI_PTCR) Transfer Bus Error Clear Mask */
#define SPI_PTCR_ERRCLR                     SPI_PTCR_ERRCLR_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTCR_ERRCLR_Msk instead */
#define SPI_PTCR_MASK                       _U_(0x10F0303)                                 /**< \deprecated (SPI_PTCR) Register MASK  (Use SPI_PTCR_Msk instead)  */
#define SPI_PTCR_Msk                        _U_(0x10F0303)                                 /**< (SPI_PTCR) Register Mask  */


/* -------- SPI_PTSR : (SPI Offset: 0x124) (R/ 32) Transfer Status Register -------- */
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
} SPI_PTSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define SPI_PTSR_OFFSET                     (0x124)                                       /**<  (SPI_PTSR) Transfer Status Register  Offset */

#define SPI_PTSR_RXTEN_Pos                  0                                              /**< (SPI_PTSR) Receiver Transfer Enable Position */
#define SPI_PTSR_RXTEN_Msk                  (_U_(0x1) << SPI_PTSR_RXTEN_Pos)               /**< (SPI_PTSR) Receiver Transfer Enable Mask */
#define SPI_PTSR_RXTEN                      SPI_PTSR_RXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTSR_RXTEN_Msk instead */
#define SPI_PTSR_TXTEN_Pos                  8                                              /**< (SPI_PTSR) Transmitter Transfer Enable Position */
#define SPI_PTSR_TXTEN_Msk                  (_U_(0x1) << SPI_PTSR_TXTEN_Pos)               /**< (SPI_PTSR) Transmitter Transfer Enable Mask */
#define SPI_PTSR_TXTEN                      SPI_PTSR_TXTEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTSR_TXTEN_Msk instead */
#define SPI_PTSR_RXCBEN_Pos                 16                                             /**< (SPI_PTSR) Receiver Circular Buffer Enable Position */
#define SPI_PTSR_RXCBEN_Msk                 (_U_(0x1) << SPI_PTSR_RXCBEN_Pos)              /**< (SPI_PTSR) Receiver Circular Buffer Enable Mask */
#define SPI_PTSR_RXCBEN                     SPI_PTSR_RXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTSR_RXCBEN_Msk instead */
#define SPI_PTSR_TXCBEN_Pos                 18                                             /**< (SPI_PTSR) Transmitter Circular Buffer Enable Position */
#define SPI_PTSR_TXCBEN_Msk                 (_U_(0x1) << SPI_PTSR_TXCBEN_Pos)              /**< (SPI_PTSR) Transmitter Circular Buffer Enable Mask */
#define SPI_PTSR_TXCBEN                     SPI_PTSR_TXCBEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTSR_TXCBEN_Msk instead */
#define SPI_PTSR_ERR_Pos                    24                                             /**< (SPI_PTSR) Transfer Bus Error Position */
#define SPI_PTSR_ERR_Msk                    (_U_(0x1) << SPI_PTSR_ERR_Pos)                 /**< (SPI_PTSR) Transfer Bus Error Mask */
#define SPI_PTSR_ERR                        SPI_PTSR_ERR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use SPI_PTSR_ERR_Msk instead */
#define SPI_PTSR_MASK                       _U_(0x1050101)                                 /**< \deprecated (SPI_PTSR) Register MASK  (Use SPI_PTSR_Msk instead)  */
#define SPI_PTSR_Msk                        _U_(0x1050101)                                 /**< (SPI_PTSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief SPI hardware registers */
typedef struct {  
  __O  uint32_t SPI_CR;         /**< (SPI Offset: 0x00) SPI Control Register */
  __IO uint32_t SPI_MR;         /**< (SPI Offset: 0x04) SPI Mode Register */
  __I  uint32_t SPI_RDR;        /**< (SPI Offset: 0x08) SPI Receive Data Register */
  __O  uint32_t SPI_TDR;        /**< (SPI Offset: 0x0C) SPI Transmit Data Register */
  __I  uint32_t SPI_SR;         /**< (SPI Offset: 0x10) SPI Status Register */
  __O  uint32_t SPI_IER;        /**< (SPI Offset: 0x14) SPI Interrupt Enable Register */
  __O  uint32_t SPI_IDR;        /**< (SPI Offset: 0x18) SPI Interrupt Disable Register */
  __I  uint32_t SPI_IMR;        /**< (SPI Offset: 0x1C) SPI Interrupt Mask Register */
  RoReg8  Reserved1[0x10];
  __IO uint32_t SPI_CSR[2];     /**< (SPI Offset: 0x30) SPI Chip Select Register 0 */
  RoReg8  Reserved2[0x10];
  __IO uint32_t SPI_CMPR;       /**< (SPI Offset: 0x48) SPI Comparison Register */
  RoReg8  Reserved3[0x98];
  __IO uint32_t SPI_WPMR;       /**< (SPI Offset: 0xE4) SPI Write Protection Mode Register */
  __I  uint32_t SPI_WPSR;       /**< (SPI Offset: 0xE8) SPI Write Protection Status Register */
  RoReg8  Reserved4[0x14];
  __IO uint32_t SPI_RPR;        /**< (SPI Offset: 0x100) Receive Pointer Register */
  __IO uint32_t SPI_RCR;        /**< (SPI Offset: 0x104) Receive Counter Register */
  __IO uint32_t SPI_TPR;        /**< (SPI Offset: 0x108) Transmit Pointer Register */
  __IO uint32_t SPI_TCR;        /**< (SPI Offset: 0x10C) Transmit Counter Register */
  __IO uint32_t SPI_RNPR;       /**< (SPI Offset: 0x110) Receive Next Pointer Register */
  __IO uint32_t SPI_RNCR;       /**< (SPI Offset: 0x114) Receive Next Counter Register */
  __IO uint32_t SPI_TNPR;       /**< (SPI Offset: 0x118) Transmit Next Pointer Register */
  __IO uint32_t SPI_TNCR;       /**< (SPI Offset: 0x11C) Transmit Next Counter Register */
  __O  uint32_t SPI_PTCR;       /**< (SPI Offset: 0x120) Transfer Control Register */
  __I  uint32_t SPI_PTSR;       /**< (SPI Offset: 0x124) Transfer Status Register */
} Spi;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief SPI hardware registers */
typedef struct {  
  __O  SPI_CR_Type                    SPI_CR;         /**< Offset: 0x00 ( /W  32) SPI Control Register */
  __IO SPI_MR_Type                    SPI_MR;         /**< Offset: 0x04 (R/W  32) SPI Mode Register */
  __I  SPI_RDR_Type                   SPI_RDR;        /**< Offset: 0x08 (R/   32) SPI Receive Data Register */
  __O  SPI_TDR_Type                   SPI_TDR;        /**< Offset: 0x0C ( /W  32) SPI Transmit Data Register */
  __I  SPI_SR_Type                    SPI_SR;         /**< Offset: 0x10 (R/   32) SPI Status Register */
  __O  SPI_IER_Type                   SPI_IER;        /**< Offset: 0x14 ( /W  32) SPI Interrupt Enable Register */
  __O  SPI_IDR_Type                   SPI_IDR;        /**< Offset: 0x18 ( /W  32) SPI Interrupt Disable Register */
  __I  SPI_IMR_Type                   SPI_IMR;        /**< Offset: 0x1C (R/   32) SPI Interrupt Mask Register */
  __I  uint32_t                       Reserved1[4];
  __IO SPI_CSR_Type                   SPI_CSR[2];     /**< Offset: 0x30 (R/W  32) SPI Chip Select Register 0 */
  __I  uint32_t                       Reserved2[4];
  __IO SPI_CMPR_Type                  SPI_CMPR;       /**< Offset: 0x48 (R/W  32) SPI Comparison Register */
  __I  uint32_t                       Reserved3[38];
  __IO SPI_WPMR_Type                  SPI_WPMR;       /**< Offset: 0xE4 (R/W  32) SPI Write Protection Mode Register */
  __I  SPI_WPSR_Type                  SPI_WPSR;       /**< Offset: 0xE8 (R/   32) SPI Write Protection Status Register */
  __I  uint32_t                       Reserved4[5];
  __IO SPI_RPR_Type                   SPI_RPR;        /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO SPI_RCR_Type                   SPI_RCR;        /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __IO SPI_TPR_Type                   SPI_TPR;        /**< Offset: 0x108 (R/W  32) Transmit Pointer Register */
  __IO SPI_TCR_Type                   SPI_TCR;        /**< Offset: 0x10C (R/W  32) Transmit Counter Register */
  __IO SPI_RNPR_Type                  SPI_RNPR;       /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO SPI_RNCR_Type                  SPI_RNCR;       /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __IO SPI_TNPR_Type                  SPI_TNPR;       /**< Offset: 0x118 (R/W  32) Transmit Next Pointer Register */
  __IO SPI_TNCR_Type                  SPI_TNCR;       /**< Offset: 0x11C (R/W  32) Transmit Next Counter Register */
  __O  SPI_PTCR_Type                  SPI_PTCR;       /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I  SPI_PTSR_Type                  SPI_PTSR;       /**< Offset: 0x124 (R/   32) Transfer Status Register */
} Spi;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Serial Peripheral Interface */

#endif /* _SAMG55_SPI_COMPONENT_H_ */
