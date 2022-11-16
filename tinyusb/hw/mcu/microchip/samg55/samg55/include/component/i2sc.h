/**
 * \file
 *
 * \brief Component description for I2SC
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
#ifndef _SAMG55_I2SC_COMPONENT_H_
#define _SAMG55_I2SC_COMPONENT_H_
#define _SAMG55_I2SC_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Inter-IC Sound Controller
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR I2SC */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define I2SC_11241                      /**< (I2SC) Module ID */
#define REV_I2SC F                      /**< (I2SC) Module revision */

/* -------- I2SC_CR : (I2SC Offset: 0x00) (/W 32) Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXEN:1;                    /**< bit:      0  Receiver Enable                          */
    uint32_t RXDIS:1;                   /**< bit:      1  Receiver Disable                         */
    uint32_t CKEN:1;                    /**< bit:      2  Clocks Enable                            */
    uint32_t CKDIS:1;                   /**< bit:      3  Clocks Disable                           */
    uint32_t TXEN:1;                    /**< bit:      4  Transmitter Enable                       */
    uint32_t TXDIS:1;                   /**< bit:      5  Transmitter Disable                      */
    uint32_t :1;                        /**< bit:      6  Reserved */
    uint32_t SWRST:1;                   /**< bit:      7  Software Reset                           */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_CR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_CR_OFFSET                      (0x00)                                        /**<  (I2SC_CR) Control Register  Offset */

#define I2SC_CR_RXEN_Pos                    0                                              /**< (I2SC_CR) Receiver Enable Position */
#define I2SC_CR_RXEN_Msk                    (_U_(0x1) << I2SC_CR_RXEN_Pos)                 /**< (I2SC_CR) Receiver Enable Mask */
#define I2SC_CR_RXEN                        I2SC_CR_RXEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_RXEN_Msk instead */
#define I2SC_CR_RXDIS_Pos                   1                                              /**< (I2SC_CR) Receiver Disable Position */
#define I2SC_CR_RXDIS_Msk                   (_U_(0x1) << I2SC_CR_RXDIS_Pos)                /**< (I2SC_CR) Receiver Disable Mask */
#define I2SC_CR_RXDIS                       I2SC_CR_RXDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_RXDIS_Msk instead */
#define I2SC_CR_CKEN_Pos                    2                                              /**< (I2SC_CR) Clocks Enable Position */
#define I2SC_CR_CKEN_Msk                    (_U_(0x1) << I2SC_CR_CKEN_Pos)                 /**< (I2SC_CR) Clocks Enable Mask */
#define I2SC_CR_CKEN                        I2SC_CR_CKEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_CKEN_Msk instead */
#define I2SC_CR_CKDIS_Pos                   3                                              /**< (I2SC_CR) Clocks Disable Position */
#define I2SC_CR_CKDIS_Msk                   (_U_(0x1) << I2SC_CR_CKDIS_Pos)                /**< (I2SC_CR) Clocks Disable Mask */
#define I2SC_CR_CKDIS                       I2SC_CR_CKDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_CKDIS_Msk instead */
#define I2SC_CR_TXEN_Pos                    4                                              /**< (I2SC_CR) Transmitter Enable Position */
#define I2SC_CR_TXEN_Msk                    (_U_(0x1) << I2SC_CR_TXEN_Pos)                 /**< (I2SC_CR) Transmitter Enable Mask */
#define I2SC_CR_TXEN                        I2SC_CR_TXEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_TXEN_Msk instead */
#define I2SC_CR_TXDIS_Pos                   5                                              /**< (I2SC_CR) Transmitter Disable Position */
#define I2SC_CR_TXDIS_Msk                   (_U_(0x1) << I2SC_CR_TXDIS_Pos)                /**< (I2SC_CR) Transmitter Disable Mask */
#define I2SC_CR_TXDIS                       I2SC_CR_TXDIS_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_TXDIS_Msk instead */
#define I2SC_CR_SWRST_Pos                   7                                              /**< (I2SC_CR) Software Reset Position */
#define I2SC_CR_SWRST_Msk                   (_U_(0x1) << I2SC_CR_SWRST_Pos)                /**< (I2SC_CR) Software Reset Mask */
#define I2SC_CR_SWRST                       I2SC_CR_SWRST_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_CR_SWRST_Msk instead */
#define I2SC_CR_MASK                        _U_(0xBF)                                      /**< \deprecated (I2SC_CR) Register MASK  (Use I2SC_CR_Msk instead)  */
#define I2SC_CR_Msk                         _U_(0xBF)                                      /**< (I2SC_CR) Register Mask  */


/* -------- I2SC_MR : (I2SC Offset: 0x04) (R/W 32) Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t MODE:1;                    /**< bit:      0  Inter-IC Sound Controller Mode           */
    uint32_t :1;                        /**< bit:      1  Reserved */
    uint32_t DATALENGTH:3;              /**< bit:   2..4  Data Word Length                         */
    uint32_t :3;                        /**< bit:   5..7  Reserved */
    uint32_t RXMONO:1;                  /**< bit:      8  Receive Mono                             */
    uint32_t RXDMA:1;                   /**< bit:      9  Single or Multiple PDC Channels for Receiver */
    uint32_t RXLOOP:1;                  /**< bit:     10  Loop-back Test Mode                      */
    uint32_t :1;                        /**< bit:     11  Reserved */
    uint32_t TXMONO:1;                  /**< bit:     12  Transmit Mono                            */
    uint32_t TXDMA:1;                   /**< bit:     13  Single or Multiple PDC Channels for Transmitter */
    uint32_t TXSAME:1;                  /**< bit:     14  Transmit Data when Underrun              */
    uint32_t :1;                        /**< bit:     15  Reserved */
    uint32_t IMCKDIV:6;                 /**< bit: 16..21  Selected Clock to I2SC Master Clock Ratio */
    uint32_t :2;                        /**< bit: 22..23  Reserved */
    uint32_t IMCKFS:6;                  /**< bit: 24..29  Master Clock to fs Ratio                 */
    uint32_t IMCKMODE:1;                /**< bit:     30  Master Clock Mode                        */
    uint32_t IWS:1;                     /**< bit:     31  I2SWS TDM Slot Width                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_MR_OFFSET                      (0x04)                                        /**<  (I2SC_MR) Mode Register  Offset */

#define I2SC_MR_MODE_Pos                    0                                              /**< (I2SC_MR) Inter-IC Sound Controller Mode Position */
#define I2SC_MR_MODE_Msk                    (_U_(0x1) << I2SC_MR_MODE_Pos)                 /**< (I2SC_MR) Inter-IC Sound Controller Mode Mask */
#define I2SC_MR_MODE                        I2SC_MR_MODE_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_MODE_Msk instead */
#define   I2SC_MR_MODE_SLAVE_Val            _U_(0x0)                                       /**< (I2SC_MR) I2SCK and i2SWS pin inputs used as bit clock and word select/frame synchronization.  */
#define   I2SC_MR_MODE_MASTER_Val           _U_(0x1)                                       /**< (I2SC_MR) Bit clock and word select/frame synchronization generated by I2SC from MCK and output to I2SCK and I2SWS pins. MCK is output as master clock on I2SMCK if I2SC_MR.IMCKMODE is set.  */
#define I2SC_MR_MODE_SLAVE                  (I2SC_MR_MODE_SLAVE_Val << I2SC_MR_MODE_Pos)   /**< (I2SC_MR) I2SCK and i2SWS pin inputs used as bit clock and word select/frame synchronization. Position  */
#define I2SC_MR_MODE_MASTER                 (I2SC_MR_MODE_MASTER_Val << I2SC_MR_MODE_Pos)  /**< (I2SC_MR) Bit clock and word select/frame synchronization generated by I2SC from MCK and output to I2SCK and I2SWS pins. MCK is output as master clock on I2SMCK if I2SC_MR.IMCKMODE is set. Position  */
#define I2SC_MR_DATALENGTH_Pos              2                                              /**< (I2SC_MR) Data Word Length Position */
#define I2SC_MR_DATALENGTH_Msk              (_U_(0x7) << I2SC_MR_DATALENGTH_Pos)           /**< (I2SC_MR) Data Word Length Mask */
#define I2SC_MR_DATALENGTH(value)           (I2SC_MR_DATALENGTH_Msk & ((value) << I2SC_MR_DATALENGTH_Pos))
#define   I2SC_MR_DATALENGTH_32_BITS_Val    _U_(0x0)                                       /**< (I2SC_MR) Data length is set to 32 bits  */
#define   I2SC_MR_DATALENGTH_24_BITS_Val    _U_(0x1)                                       /**< (I2SC_MR) Data length is set to 24 bits  */
#define   I2SC_MR_DATALENGTH_20_BITS_Val    _U_(0x2)                                       /**< (I2SC_MR) Data length is set to 20 bits  */
#define   I2SC_MR_DATALENGTH_18_BITS_Val    _U_(0x3)                                       /**< (I2SC_MR) Data length is set to 18 bits  */
#define   I2SC_MR_DATALENGTH_16_BITS_Val    _U_(0x4)                                       /**< (I2SC_MR) Data length is set to 16 bits  */
#define   I2SC_MR_DATALENGTH_16_BITS_COMPACT_Val _U_(0x5)                                       /**< (I2SC_MR) Data length is set to 16-bit compact stereo. Left sample in bits 15:0 and right sample in bits 31:16 of same word.  */
#define   I2SC_MR_DATALENGTH_8_BITS_Val     _U_(0x6)                                       /**< (I2SC_MR) Data length is set to 8 bits  */
#define   I2SC_MR_DATALENGTH_8_BITS_COMPACT_Val _U_(0x7)                                       /**< (I2SC_MR) Data length is set to 8-bit compact stereo. Left sample in bits 7:0 and right sample in bits 15:8 of the same word.  */
#define I2SC_MR_DATALENGTH_32_BITS          (I2SC_MR_DATALENGTH_32_BITS_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 32 bits Position  */
#define I2SC_MR_DATALENGTH_24_BITS          (I2SC_MR_DATALENGTH_24_BITS_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 24 bits Position  */
#define I2SC_MR_DATALENGTH_20_BITS          (I2SC_MR_DATALENGTH_20_BITS_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 20 bits Position  */
#define I2SC_MR_DATALENGTH_18_BITS          (I2SC_MR_DATALENGTH_18_BITS_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 18 bits Position  */
#define I2SC_MR_DATALENGTH_16_BITS          (I2SC_MR_DATALENGTH_16_BITS_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 16 bits Position  */
#define I2SC_MR_DATALENGTH_16_BITS_COMPACT  (I2SC_MR_DATALENGTH_16_BITS_COMPACT_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 16-bit compact stereo. Left sample in bits 15:0 and right sample in bits 31:16 of same word. Position  */
#define I2SC_MR_DATALENGTH_8_BITS           (I2SC_MR_DATALENGTH_8_BITS_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 8 bits Position  */
#define I2SC_MR_DATALENGTH_8_BITS_COMPACT   (I2SC_MR_DATALENGTH_8_BITS_COMPACT_Val << I2SC_MR_DATALENGTH_Pos)  /**< (I2SC_MR) Data length is set to 8-bit compact stereo. Left sample in bits 7:0 and right sample in bits 15:8 of the same word. Position  */
#define I2SC_MR_RXMONO_Pos                  8                                              /**< (I2SC_MR) Receive Mono Position */
#define I2SC_MR_RXMONO_Msk                  (_U_(0x1) << I2SC_MR_RXMONO_Pos)               /**< (I2SC_MR) Receive Mono Mask */
#define I2SC_MR_RXMONO                      I2SC_MR_RXMONO_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_RXMONO_Msk instead */
#define I2SC_MR_RXDMA_Pos                   9                                              /**< (I2SC_MR) Single or Multiple PDC Channels for Receiver Position */
#define I2SC_MR_RXDMA_Msk                   (_U_(0x1) << I2SC_MR_RXDMA_Pos)                /**< (I2SC_MR) Single or Multiple PDC Channels for Receiver Mask */
#define I2SC_MR_RXDMA                       I2SC_MR_RXDMA_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_RXDMA_Msk instead */
#define I2SC_MR_RXLOOP_Pos                  10                                             /**< (I2SC_MR) Loop-back Test Mode Position */
#define I2SC_MR_RXLOOP_Msk                  (_U_(0x1) << I2SC_MR_RXLOOP_Pos)               /**< (I2SC_MR) Loop-back Test Mode Mask */
#define I2SC_MR_RXLOOP                      I2SC_MR_RXLOOP_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_RXLOOP_Msk instead */
#define I2SC_MR_TXMONO_Pos                  12                                             /**< (I2SC_MR) Transmit Mono Position */
#define I2SC_MR_TXMONO_Msk                  (_U_(0x1) << I2SC_MR_TXMONO_Pos)               /**< (I2SC_MR) Transmit Mono Mask */
#define I2SC_MR_TXMONO                      I2SC_MR_TXMONO_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_TXMONO_Msk instead */
#define I2SC_MR_TXDMA_Pos                   13                                             /**< (I2SC_MR) Single or Multiple PDC Channels for Transmitter Position */
#define I2SC_MR_TXDMA_Msk                   (_U_(0x1) << I2SC_MR_TXDMA_Pos)                /**< (I2SC_MR) Single or Multiple PDC Channels for Transmitter Mask */
#define I2SC_MR_TXDMA                       I2SC_MR_TXDMA_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_TXDMA_Msk instead */
#define I2SC_MR_TXSAME_Pos                  14                                             /**< (I2SC_MR) Transmit Data when Underrun Position */
#define I2SC_MR_TXSAME_Msk                  (_U_(0x1) << I2SC_MR_TXSAME_Pos)               /**< (I2SC_MR) Transmit Data when Underrun Mask */
#define I2SC_MR_TXSAME                      I2SC_MR_TXSAME_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_TXSAME_Msk instead */
#define I2SC_MR_IMCKDIV_Pos                 16                                             /**< (I2SC_MR) Selected Clock to I2SC Master Clock Ratio Position */
#define I2SC_MR_IMCKDIV_Msk                 (_U_(0x3F) << I2SC_MR_IMCKDIV_Pos)             /**< (I2SC_MR) Selected Clock to I2SC Master Clock Ratio Mask */
#define I2SC_MR_IMCKDIV(value)              (I2SC_MR_IMCKDIV_Msk & ((value) << I2SC_MR_IMCKDIV_Pos))
#define I2SC_MR_IMCKFS_Pos                  24                                             /**< (I2SC_MR) Master Clock to fs Ratio Position */
#define I2SC_MR_IMCKFS_Msk                  (_U_(0x3F) << I2SC_MR_IMCKFS_Pos)              /**< (I2SC_MR) Master Clock to fs Ratio Mask */
#define I2SC_MR_IMCKFS(value)               (I2SC_MR_IMCKFS_Msk & ((value) << I2SC_MR_IMCKFS_Pos))
#define   I2SC_MR_IMCKFS_M2SF32_Val         _U_(0x0)                                       /**< (I2SC_MR) Sample frequency ratio set to 32  */
#define   I2SC_MR_IMCKFS_M2SF64_Val         _U_(0x1)                                       /**< (I2SC_MR) Sample frequency ratio set to 64  */
#define   I2SC_MR_IMCKFS_M2SF96_Val         _U_(0x2)                                       /**< (I2SC_MR) Sample frequency ratio set to 96  */
#define   I2SC_MR_IMCKFS_M2SF128_Val        _U_(0x3)                                       /**< (I2SC_MR) Sample frequency ratio set to 128  */
#define   I2SC_MR_IMCKFS_M2SF192_Val        _U_(0x5)                                       /**< (I2SC_MR) Sample frequency ratio set to 192  */
#define   I2SC_MR_IMCKFS_M2SF256_Val        _U_(0x7)                                       /**< (I2SC_MR) Sample frequency ratio set to 256  */
#define   I2SC_MR_IMCKFS_M2SF384_Val        _U_(0xB)                                       /**< (I2SC_MR) Sample frequency ratio set to 384  */
#define   I2SC_MR_IMCKFS_M2SF512_Val        _U_(0xF)                                       /**< (I2SC_MR) Sample frequency ratio set to 512  */
#define   I2SC_MR_IMCKFS_M2SF768_Val        _U_(0x17)                                      /**< (I2SC_MR) Sample frequency ratio set to 768  */
#define   I2SC_MR_IMCKFS_M2SF1024_Val       _U_(0x1F)                                      /**< (I2SC_MR) Sample frequency ratio set to 1024  */
#define   I2SC_MR_IMCKFS_M2SF1536_Val       _U_(0x2F)                                      /**< (I2SC_MR) Sample frequency ratio set to 1536  */
#define   I2SC_MR_IMCKFS_M2SF2048_Val       _U_(0x3F)                                      /**< (I2SC_MR) Sample frequency ratio set to 2048  */
#define I2SC_MR_IMCKFS_M2SF32               (I2SC_MR_IMCKFS_M2SF32_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 32 Position  */
#define I2SC_MR_IMCKFS_M2SF64               (I2SC_MR_IMCKFS_M2SF64_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 64 Position  */
#define I2SC_MR_IMCKFS_M2SF96               (I2SC_MR_IMCKFS_M2SF96_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 96 Position  */
#define I2SC_MR_IMCKFS_M2SF128              (I2SC_MR_IMCKFS_M2SF128_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 128 Position  */
#define I2SC_MR_IMCKFS_M2SF192              (I2SC_MR_IMCKFS_M2SF192_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 192 Position  */
#define I2SC_MR_IMCKFS_M2SF256              (I2SC_MR_IMCKFS_M2SF256_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 256 Position  */
#define I2SC_MR_IMCKFS_M2SF384              (I2SC_MR_IMCKFS_M2SF384_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 384 Position  */
#define I2SC_MR_IMCKFS_M2SF512              (I2SC_MR_IMCKFS_M2SF512_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 512 Position  */
#define I2SC_MR_IMCKFS_M2SF768              (I2SC_MR_IMCKFS_M2SF768_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 768 Position  */
#define I2SC_MR_IMCKFS_M2SF1024             (I2SC_MR_IMCKFS_M2SF1024_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 1024 Position  */
#define I2SC_MR_IMCKFS_M2SF1536             (I2SC_MR_IMCKFS_M2SF1536_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 1536 Position  */
#define I2SC_MR_IMCKFS_M2SF2048             (I2SC_MR_IMCKFS_M2SF2048_Val << I2SC_MR_IMCKFS_Pos)  /**< (I2SC_MR) Sample frequency ratio set to 2048 Position  */
#define I2SC_MR_IMCKMODE_Pos                30                                             /**< (I2SC_MR) Master Clock Mode Position */
#define I2SC_MR_IMCKMODE_Msk                (_U_(0x1) << I2SC_MR_IMCKMODE_Pos)             /**< (I2SC_MR) Master Clock Mode Mask */
#define I2SC_MR_IMCKMODE                    I2SC_MR_IMCKMODE_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_IMCKMODE_Msk instead */
#define I2SC_MR_IWS_Pos                     31                                             /**< (I2SC_MR) I2SWS TDM Slot Width Position */
#define I2SC_MR_IWS_Msk                     (_U_(0x1) << I2SC_MR_IWS_Pos)                  /**< (I2SC_MR) I2SWS TDM Slot Width Mask */
#define I2SC_MR_IWS                         I2SC_MR_IWS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_MR_IWS_Msk instead */
#define I2SC_MR_MASK                        _U_(0xFF3F771D)                                /**< \deprecated (I2SC_MR) Register MASK  (Use I2SC_MR_Msk instead)  */
#define I2SC_MR_Msk                         _U_(0xFF3F771D)                                /**< (I2SC_MR) Register Mask  */


/* -------- I2SC_SR : (I2SC Offset: 0x08) (R/ 32) Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXEN:1;                    /**< bit:      0  Receiver Enabled                         */
    uint32_t RXRDY:1;                   /**< bit:      1  Receive Ready                            */
    uint32_t RXOR:1;                    /**< bit:      2  Receive Overrun                          */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Receiver Transfer                 */
    uint32_t TXEN:1;                    /**< bit:      4  Transmitter Enabled                      */
    uint32_t TXRDY:1;                   /**< bit:      5  Transmit Ready                           */
    uint32_t TXUR:1;                    /**< bit:      6  Transmit Underrun                        */
    uint32_t ENDTX:1;                   /**< bit:      7  End of Transmitter Transfer              */
    uint32_t RXORCH:2;                  /**< bit:   8..9  Receive Overrun Channel                  */
    uint32_t :9;                        /**< bit: 10..18  Reserved */
    uint32_t RXBUFF:1;                  /**< bit:     19  Receive Buffer Full                      */
    uint32_t TXURCH:2;                  /**< bit: 20..21  Transmit Underrun Channel                */
    uint32_t :9;                        /**< bit: 22..30  Reserved */
    uint32_t TXBUFE:1;                  /**< bit:     31  Transmit Buffer Empty                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_SR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_SR_OFFSET                      (0x08)                                        /**<  (I2SC_SR) Status Register  Offset */

#define I2SC_SR_RXEN_Pos                    0                                              /**< (I2SC_SR) Receiver Enabled Position */
#define I2SC_SR_RXEN_Msk                    (_U_(0x1) << I2SC_SR_RXEN_Pos)                 /**< (I2SC_SR) Receiver Enabled Mask */
#define I2SC_SR_RXEN                        I2SC_SR_RXEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_RXEN_Msk instead */
#define I2SC_SR_RXRDY_Pos                   1                                              /**< (I2SC_SR) Receive Ready Position */
#define I2SC_SR_RXRDY_Msk                   (_U_(0x1) << I2SC_SR_RXRDY_Pos)                /**< (I2SC_SR) Receive Ready Mask */
#define I2SC_SR_RXRDY                       I2SC_SR_RXRDY_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_RXRDY_Msk instead */
#define I2SC_SR_RXOR_Pos                    2                                              /**< (I2SC_SR) Receive Overrun Position */
#define I2SC_SR_RXOR_Msk                    (_U_(0x1) << I2SC_SR_RXOR_Pos)                 /**< (I2SC_SR) Receive Overrun Mask */
#define I2SC_SR_RXOR                        I2SC_SR_RXOR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_RXOR_Msk instead */
#define I2SC_SR_ENDRX_Pos                   3                                              /**< (I2SC_SR) End of Receiver Transfer Position */
#define I2SC_SR_ENDRX_Msk                   (_U_(0x1) << I2SC_SR_ENDRX_Pos)                /**< (I2SC_SR) End of Receiver Transfer Mask */
#define I2SC_SR_ENDRX                       I2SC_SR_ENDRX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_ENDRX_Msk instead */
#define I2SC_SR_TXEN_Pos                    4                                              /**< (I2SC_SR) Transmitter Enabled Position */
#define I2SC_SR_TXEN_Msk                    (_U_(0x1) << I2SC_SR_TXEN_Pos)                 /**< (I2SC_SR) Transmitter Enabled Mask */
#define I2SC_SR_TXEN                        I2SC_SR_TXEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_TXEN_Msk instead */
#define I2SC_SR_TXRDY_Pos                   5                                              /**< (I2SC_SR) Transmit Ready Position */
#define I2SC_SR_TXRDY_Msk                   (_U_(0x1) << I2SC_SR_TXRDY_Pos)                /**< (I2SC_SR) Transmit Ready Mask */
#define I2SC_SR_TXRDY                       I2SC_SR_TXRDY_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_TXRDY_Msk instead */
#define I2SC_SR_TXUR_Pos                    6                                              /**< (I2SC_SR) Transmit Underrun Position */
#define I2SC_SR_TXUR_Msk                    (_U_(0x1) << I2SC_SR_TXUR_Pos)                 /**< (I2SC_SR) Transmit Underrun Mask */
#define I2SC_SR_TXUR                        I2SC_SR_TXUR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_TXUR_Msk instead */
#define I2SC_SR_ENDTX_Pos                   7                                              /**< (I2SC_SR) End of Transmitter Transfer Position */
#define I2SC_SR_ENDTX_Msk                   (_U_(0x1) << I2SC_SR_ENDTX_Pos)                /**< (I2SC_SR) End of Transmitter Transfer Mask */
#define I2SC_SR_ENDTX                       I2SC_SR_ENDTX_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_ENDTX_Msk instead */
#define I2SC_SR_RXORCH_Pos                  8                                              /**< (I2SC_SR) Receive Overrun Channel Position */
#define I2SC_SR_RXORCH_Msk                  (_U_(0x3) << I2SC_SR_RXORCH_Pos)               /**< (I2SC_SR) Receive Overrun Channel Mask */
#define I2SC_SR_RXORCH(value)               (I2SC_SR_RXORCH_Msk & ((value) << I2SC_SR_RXORCH_Pos))
#define I2SC_SR_RXBUFF_Pos                  19                                             /**< (I2SC_SR) Receive Buffer Full Position */
#define I2SC_SR_RXBUFF_Msk                  (_U_(0x1) << I2SC_SR_RXBUFF_Pos)               /**< (I2SC_SR) Receive Buffer Full Mask */
#define I2SC_SR_RXBUFF                      I2SC_SR_RXBUFF_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_RXBUFF_Msk instead */
#define I2SC_SR_TXURCH_Pos                  20                                             /**< (I2SC_SR) Transmit Underrun Channel Position */
#define I2SC_SR_TXURCH_Msk                  (_U_(0x3) << I2SC_SR_TXURCH_Pos)               /**< (I2SC_SR) Transmit Underrun Channel Mask */
#define I2SC_SR_TXURCH(value)               (I2SC_SR_TXURCH_Msk & ((value) << I2SC_SR_TXURCH_Pos))
#define I2SC_SR_TXBUFE_Pos                  31                                             /**< (I2SC_SR) Transmit Buffer Empty Position */
#define I2SC_SR_TXBUFE_Msk                  (_U_(0x1) << I2SC_SR_TXBUFE_Pos)               /**< (I2SC_SR) Transmit Buffer Empty Mask */
#define I2SC_SR_TXBUFE                      I2SC_SR_TXBUFE_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SR_TXBUFE_Msk instead */
#define I2SC_SR_MASK                        _U_(0x803803FF)                                /**< \deprecated (I2SC_SR) Register MASK  (Use I2SC_SR_Msk instead)  */
#define I2SC_SR_Msk                         _U_(0x803803FF)                                /**< (I2SC_SR) Register Mask  */


/* -------- I2SC_SCR : (I2SC Offset: 0x0c) (/W 32) Status Clear Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :2;                        /**< bit:   0..1  Reserved */
    uint32_t RXOR:1;                    /**< bit:      2  Receive Overrun Status Clear             */
    uint32_t :3;                        /**< bit:   3..5  Reserved */
    uint32_t TXUR:1;                    /**< bit:      6  Transmit Underrun Status Clear           */
    uint32_t :1;                        /**< bit:      7  Reserved */
    uint32_t RXORCH:2;                  /**< bit:   8..9  Receive Overrun Per Channel Status Clear */
    uint32_t :10;                       /**< bit: 10..19  Reserved */
    uint32_t TXURCH:2;                  /**< bit: 20..21  Transmit Underrun Per Channel Status Clear */
    uint32_t :10;                       /**< bit: 22..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_SCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_SCR_OFFSET                     (0x0C)                                        /**<  (I2SC_SCR) Status Clear Register  Offset */

#define I2SC_SCR_RXOR_Pos                   2                                              /**< (I2SC_SCR) Receive Overrun Status Clear Position */
#define I2SC_SCR_RXOR_Msk                   (_U_(0x1) << I2SC_SCR_RXOR_Pos)                /**< (I2SC_SCR) Receive Overrun Status Clear Mask */
#define I2SC_SCR_RXOR                       I2SC_SCR_RXOR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SCR_RXOR_Msk instead */
#define I2SC_SCR_TXUR_Pos                   6                                              /**< (I2SC_SCR) Transmit Underrun Status Clear Position */
#define I2SC_SCR_TXUR_Msk                   (_U_(0x1) << I2SC_SCR_TXUR_Pos)                /**< (I2SC_SCR) Transmit Underrun Status Clear Mask */
#define I2SC_SCR_TXUR                       I2SC_SCR_TXUR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SCR_TXUR_Msk instead */
#define I2SC_SCR_RXORCH_Pos                 8                                              /**< (I2SC_SCR) Receive Overrun Per Channel Status Clear Position */
#define I2SC_SCR_RXORCH_Msk                 (_U_(0x3) << I2SC_SCR_RXORCH_Pos)              /**< (I2SC_SCR) Receive Overrun Per Channel Status Clear Mask */
#define I2SC_SCR_RXORCH(value)              (I2SC_SCR_RXORCH_Msk & ((value) << I2SC_SCR_RXORCH_Pos))
#define I2SC_SCR_TXURCH_Pos                 20                                             /**< (I2SC_SCR) Transmit Underrun Per Channel Status Clear Position */
#define I2SC_SCR_TXURCH_Msk                 (_U_(0x3) << I2SC_SCR_TXURCH_Pos)              /**< (I2SC_SCR) Transmit Underrun Per Channel Status Clear Mask */
#define I2SC_SCR_TXURCH(value)              (I2SC_SCR_TXURCH_Msk & ((value) << I2SC_SCR_TXURCH_Pos))
#define I2SC_SCR_MASK                       _U_(0x300344)                                  /**< \deprecated (I2SC_SCR) Register MASK  (Use I2SC_SCR_Msk instead)  */
#define I2SC_SCR_Msk                        _U_(0x300344)                                  /**< (I2SC_SCR) Register Mask  */


/* -------- I2SC_SSR : (I2SC Offset: 0x10) (/W 32) Status Set Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :2;                        /**< bit:   0..1  Reserved */
    uint32_t RXOR:1;                    /**< bit:      2  Receive Overrun Status Set               */
    uint32_t :3;                        /**< bit:   3..5  Reserved */
    uint32_t TXUR:1;                    /**< bit:      6  Transmit Underrun Status Set             */
    uint32_t :1;                        /**< bit:      7  Reserved */
    uint32_t RXORCH:2;                  /**< bit:   8..9  Receive Overrun Per Channel Status Set   */
    uint32_t :10;                       /**< bit: 10..19  Reserved */
    uint32_t TXURCH:2;                  /**< bit: 20..21  Transmit Underrun Per Channel Status Set */
    uint32_t :10;                       /**< bit: 22..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_SSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_SSR_OFFSET                     (0x10)                                        /**<  (I2SC_SSR) Status Set Register  Offset */

#define I2SC_SSR_RXOR_Pos                   2                                              /**< (I2SC_SSR) Receive Overrun Status Set Position */
#define I2SC_SSR_RXOR_Msk                   (_U_(0x1) << I2SC_SSR_RXOR_Pos)                /**< (I2SC_SSR) Receive Overrun Status Set Mask */
#define I2SC_SSR_RXOR                       I2SC_SSR_RXOR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SSR_RXOR_Msk instead */
#define I2SC_SSR_TXUR_Pos                   6                                              /**< (I2SC_SSR) Transmit Underrun Status Set Position */
#define I2SC_SSR_TXUR_Msk                   (_U_(0x1) << I2SC_SSR_TXUR_Pos)                /**< (I2SC_SSR) Transmit Underrun Status Set Mask */
#define I2SC_SSR_TXUR                       I2SC_SSR_TXUR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_SSR_TXUR_Msk instead */
#define I2SC_SSR_RXORCH_Pos                 8                                              /**< (I2SC_SSR) Receive Overrun Per Channel Status Set Position */
#define I2SC_SSR_RXORCH_Msk                 (_U_(0x3) << I2SC_SSR_RXORCH_Pos)              /**< (I2SC_SSR) Receive Overrun Per Channel Status Set Mask */
#define I2SC_SSR_RXORCH(value)              (I2SC_SSR_RXORCH_Msk & ((value) << I2SC_SSR_RXORCH_Pos))
#define I2SC_SSR_TXURCH_Pos                 20                                             /**< (I2SC_SSR) Transmit Underrun Per Channel Status Set Position */
#define I2SC_SSR_TXURCH_Msk                 (_U_(0x3) << I2SC_SSR_TXURCH_Pos)              /**< (I2SC_SSR) Transmit Underrun Per Channel Status Set Mask */
#define I2SC_SSR_TXURCH(value)              (I2SC_SSR_TXURCH_Msk & ((value) << I2SC_SSR_TXURCH_Pos))
#define I2SC_SSR_MASK                       _U_(0x300344)                                  /**< \deprecated (I2SC_SSR) Register MASK  (Use I2SC_SSR_Msk instead)  */
#define I2SC_SSR_Msk                        _U_(0x300344)                                  /**< (I2SC_SSR) Register Mask  */


/* -------- I2SC_IER : (I2SC Offset: 0x14) (/W 32) Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t RXRDY:1;                   /**< bit:      1  Receiver Ready Interrupt Enable          */
    uint32_t RXOR:1;                    /**< bit:      2  Receiver Overrun Interrupt Enable        */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Reception Interrupt Enable        */
    uint32_t :1;                        /**< bit:      4  Reserved */
    uint32_t TXRDY:1;                   /**< bit:      5  Transmit Ready Interrupt Enable          */
    uint32_t TXUR:1;                    /**< bit:      6  Transmit Underflow Interrupt Enable      */
    uint32_t ENDTX:1;                   /**< bit:      7  End of Transmission Interrupt Enable     */
    uint32_t :11;                       /**< bit:  8..18  Reserved */
    uint32_t RXFULL:1;                  /**< bit:     19  Receive Buffer Full Interrupt Enable     */
    uint32_t :11;                       /**< bit: 20..30  Reserved */
    uint32_t TXEMPTY:1;                 /**< bit:     31  Transmit Buffer Empty Interrupt Enable   */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_IER_OFFSET                     (0x14)                                        /**<  (I2SC_IER) Interrupt Enable Register  Offset */

#define I2SC_IER_RXRDY_Pos                  1                                              /**< (I2SC_IER) Receiver Ready Interrupt Enable Position */
#define I2SC_IER_RXRDY_Msk                  (_U_(0x1) << I2SC_IER_RXRDY_Pos)               /**< (I2SC_IER) Receiver Ready Interrupt Enable Mask */
#define I2SC_IER_RXRDY                      I2SC_IER_RXRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_RXRDY_Msk instead */
#define I2SC_IER_RXOR_Pos                   2                                              /**< (I2SC_IER) Receiver Overrun Interrupt Enable Position */
#define I2SC_IER_RXOR_Msk                   (_U_(0x1) << I2SC_IER_RXOR_Pos)                /**< (I2SC_IER) Receiver Overrun Interrupt Enable Mask */
#define I2SC_IER_RXOR                       I2SC_IER_RXOR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_RXOR_Msk instead */
#define I2SC_IER_ENDRX_Pos                  3                                              /**< (I2SC_IER) End of Reception Interrupt Enable Position */
#define I2SC_IER_ENDRX_Msk                  (_U_(0x1) << I2SC_IER_ENDRX_Pos)               /**< (I2SC_IER) End of Reception Interrupt Enable Mask */
#define I2SC_IER_ENDRX                      I2SC_IER_ENDRX_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_ENDRX_Msk instead */
#define I2SC_IER_TXRDY_Pos                  5                                              /**< (I2SC_IER) Transmit Ready Interrupt Enable Position */
#define I2SC_IER_TXRDY_Msk                  (_U_(0x1) << I2SC_IER_TXRDY_Pos)               /**< (I2SC_IER) Transmit Ready Interrupt Enable Mask */
#define I2SC_IER_TXRDY                      I2SC_IER_TXRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_TXRDY_Msk instead */
#define I2SC_IER_TXUR_Pos                   6                                              /**< (I2SC_IER) Transmit Underflow Interrupt Enable Position */
#define I2SC_IER_TXUR_Msk                   (_U_(0x1) << I2SC_IER_TXUR_Pos)                /**< (I2SC_IER) Transmit Underflow Interrupt Enable Mask */
#define I2SC_IER_TXUR                       I2SC_IER_TXUR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_TXUR_Msk instead */
#define I2SC_IER_ENDTX_Pos                  7                                              /**< (I2SC_IER) End of Transmission Interrupt Enable Position */
#define I2SC_IER_ENDTX_Msk                  (_U_(0x1) << I2SC_IER_ENDTX_Pos)               /**< (I2SC_IER) End of Transmission Interrupt Enable Mask */
#define I2SC_IER_ENDTX                      I2SC_IER_ENDTX_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_ENDTX_Msk instead */
#define I2SC_IER_RXFULL_Pos                 19                                             /**< (I2SC_IER) Receive Buffer Full Interrupt Enable Position */
#define I2SC_IER_RXFULL_Msk                 (_U_(0x1) << I2SC_IER_RXFULL_Pos)              /**< (I2SC_IER) Receive Buffer Full Interrupt Enable Mask */
#define I2SC_IER_RXFULL                     I2SC_IER_RXFULL_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_RXFULL_Msk instead */
#define I2SC_IER_TXEMPTY_Pos                31                                             /**< (I2SC_IER) Transmit Buffer Empty Interrupt Enable Position */
#define I2SC_IER_TXEMPTY_Msk                (_U_(0x1) << I2SC_IER_TXEMPTY_Pos)             /**< (I2SC_IER) Transmit Buffer Empty Interrupt Enable Mask */
#define I2SC_IER_TXEMPTY                    I2SC_IER_TXEMPTY_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IER_TXEMPTY_Msk instead */
#define I2SC_IER_MASK                       _U_(0x800800EE)                                /**< \deprecated (I2SC_IER) Register MASK  (Use I2SC_IER_Msk instead)  */
#define I2SC_IER_Msk                        _U_(0x800800EE)                                /**< (I2SC_IER) Register Mask  */


/* -------- I2SC_IDR : (I2SC Offset: 0x18) (/W 32) Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t RXRDY:1;                   /**< bit:      1  Receiver Ready Interrupt Disable         */
    uint32_t RXOR:1;                    /**< bit:      2  Receiver Overrun Interrupt Disable       */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Reception Interrupt Disable       */
    uint32_t :1;                        /**< bit:      4  Reserved */
    uint32_t TXRDY:1;                   /**< bit:      5  Transmit Ready Interrupt Disable         */
    uint32_t TXUR:1;                    /**< bit:      6  Transmit Underflow Interrupt Disable     */
    uint32_t ENDTX:1;                   /**< bit:      7  End of Transmission Interrupt Disable    */
    uint32_t :11;                       /**< bit:  8..18  Reserved */
    uint32_t RXFULL:1;                  /**< bit:     19  Receive Buffer Full Interrupt Disable    */
    uint32_t :11;                       /**< bit: 20..30  Reserved */
    uint32_t TXEMPTY:1;                 /**< bit:     31  Transmit Buffer Empty Interrupt Disable  */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_IDR_OFFSET                     (0x18)                                        /**<  (I2SC_IDR) Interrupt Disable Register  Offset */

#define I2SC_IDR_RXRDY_Pos                  1                                              /**< (I2SC_IDR) Receiver Ready Interrupt Disable Position */
#define I2SC_IDR_RXRDY_Msk                  (_U_(0x1) << I2SC_IDR_RXRDY_Pos)               /**< (I2SC_IDR) Receiver Ready Interrupt Disable Mask */
#define I2SC_IDR_RXRDY                      I2SC_IDR_RXRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_RXRDY_Msk instead */
#define I2SC_IDR_RXOR_Pos                   2                                              /**< (I2SC_IDR) Receiver Overrun Interrupt Disable Position */
#define I2SC_IDR_RXOR_Msk                   (_U_(0x1) << I2SC_IDR_RXOR_Pos)                /**< (I2SC_IDR) Receiver Overrun Interrupt Disable Mask */
#define I2SC_IDR_RXOR                       I2SC_IDR_RXOR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_RXOR_Msk instead */
#define I2SC_IDR_ENDRX_Pos                  3                                              /**< (I2SC_IDR) End of Reception Interrupt Disable Position */
#define I2SC_IDR_ENDRX_Msk                  (_U_(0x1) << I2SC_IDR_ENDRX_Pos)               /**< (I2SC_IDR) End of Reception Interrupt Disable Mask */
#define I2SC_IDR_ENDRX                      I2SC_IDR_ENDRX_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_ENDRX_Msk instead */
#define I2SC_IDR_TXRDY_Pos                  5                                              /**< (I2SC_IDR) Transmit Ready Interrupt Disable Position */
#define I2SC_IDR_TXRDY_Msk                  (_U_(0x1) << I2SC_IDR_TXRDY_Pos)               /**< (I2SC_IDR) Transmit Ready Interrupt Disable Mask */
#define I2SC_IDR_TXRDY                      I2SC_IDR_TXRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_TXRDY_Msk instead */
#define I2SC_IDR_TXUR_Pos                   6                                              /**< (I2SC_IDR) Transmit Underflow Interrupt Disable Position */
#define I2SC_IDR_TXUR_Msk                   (_U_(0x1) << I2SC_IDR_TXUR_Pos)                /**< (I2SC_IDR) Transmit Underflow Interrupt Disable Mask */
#define I2SC_IDR_TXUR                       I2SC_IDR_TXUR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_TXUR_Msk instead */
#define I2SC_IDR_ENDTX_Pos                  7                                              /**< (I2SC_IDR) End of Transmission Interrupt Disable Position */
#define I2SC_IDR_ENDTX_Msk                  (_U_(0x1) << I2SC_IDR_ENDTX_Pos)               /**< (I2SC_IDR) End of Transmission Interrupt Disable Mask */
#define I2SC_IDR_ENDTX                      I2SC_IDR_ENDTX_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_ENDTX_Msk instead */
#define I2SC_IDR_RXFULL_Pos                 19                                             /**< (I2SC_IDR) Receive Buffer Full Interrupt Disable Position */
#define I2SC_IDR_RXFULL_Msk                 (_U_(0x1) << I2SC_IDR_RXFULL_Pos)              /**< (I2SC_IDR) Receive Buffer Full Interrupt Disable Mask */
#define I2SC_IDR_RXFULL                     I2SC_IDR_RXFULL_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_RXFULL_Msk instead */
#define I2SC_IDR_TXEMPTY_Pos                31                                             /**< (I2SC_IDR) Transmit Buffer Empty Interrupt Disable Position */
#define I2SC_IDR_TXEMPTY_Msk                (_U_(0x1) << I2SC_IDR_TXEMPTY_Pos)             /**< (I2SC_IDR) Transmit Buffer Empty Interrupt Disable Mask */
#define I2SC_IDR_TXEMPTY                    I2SC_IDR_TXEMPTY_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IDR_TXEMPTY_Msk instead */
#define I2SC_IDR_MASK                       _U_(0x800800EE)                                /**< \deprecated (I2SC_IDR) Register MASK  (Use I2SC_IDR_Msk instead)  */
#define I2SC_IDR_Msk                        _U_(0x800800EE)                                /**< (I2SC_IDR) Register Mask  */


/* -------- I2SC_IMR : (I2SC Offset: 0x1c) (R/ 32) Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :1;                        /**< bit:      0  Reserved */
    uint32_t RXRDY:1;                   /**< bit:      1  Receiver Ready Interrupt Disable         */
    uint32_t RXOR:1;                    /**< bit:      2  Receiver Overrun Interrupt Disable       */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Reception Interrupt Disable       */
    uint32_t :1;                        /**< bit:      4  Reserved */
    uint32_t TXRDY:1;                   /**< bit:      5  Transmit Ready Interrupt Disable         */
    uint32_t TXUR:1;                    /**< bit:      6  Transmit Underflow Interrupt Disable     */
    uint32_t ENDTX:1;                   /**< bit:      7  End of Transmission Interrupt Disable    */
    uint32_t :11;                       /**< bit:  8..18  Reserved */
    uint32_t RXFULL:1;                  /**< bit:     19  Receive Buffer Full Interrupt Disable    */
    uint32_t :11;                       /**< bit: 20..30  Reserved */
    uint32_t TXEMPTY:1;                 /**< bit:     31  Transmit Buffer Empty Interrupt Disable  */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_IMR_OFFSET                     (0x1C)                                        /**<  (I2SC_IMR) Interrupt Mask Register  Offset */

#define I2SC_IMR_RXRDY_Pos                  1                                              /**< (I2SC_IMR) Receiver Ready Interrupt Disable Position */
#define I2SC_IMR_RXRDY_Msk                  (_U_(0x1) << I2SC_IMR_RXRDY_Pos)               /**< (I2SC_IMR) Receiver Ready Interrupt Disable Mask */
#define I2SC_IMR_RXRDY                      I2SC_IMR_RXRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_RXRDY_Msk instead */
#define I2SC_IMR_RXOR_Pos                   2                                              /**< (I2SC_IMR) Receiver Overrun Interrupt Disable Position */
#define I2SC_IMR_RXOR_Msk                   (_U_(0x1) << I2SC_IMR_RXOR_Pos)                /**< (I2SC_IMR) Receiver Overrun Interrupt Disable Mask */
#define I2SC_IMR_RXOR                       I2SC_IMR_RXOR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_RXOR_Msk instead */
#define I2SC_IMR_ENDRX_Pos                  3                                              /**< (I2SC_IMR) End of Reception Interrupt Disable Position */
#define I2SC_IMR_ENDRX_Msk                  (_U_(0x1) << I2SC_IMR_ENDRX_Pos)               /**< (I2SC_IMR) End of Reception Interrupt Disable Mask */
#define I2SC_IMR_ENDRX                      I2SC_IMR_ENDRX_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_ENDRX_Msk instead */
#define I2SC_IMR_TXRDY_Pos                  5                                              /**< (I2SC_IMR) Transmit Ready Interrupt Disable Position */
#define I2SC_IMR_TXRDY_Msk                  (_U_(0x1) << I2SC_IMR_TXRDY_Pos)               /**< (I2SC_IMR) Transmit Ready Interrupt Disable Mask */
#define I2SC_IMR_TXRDY                      I2SC_IMR_TXRDY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_TXRDY_Msk instead */
#define I2SC_IMR_TXUR_Pos                   6                                              /**< (I2SC_IMR) Transmit Underflow Interrupt Disable Position */
#define I2SC_IMR_TXUR_Msk                   (_U_(0x1) << I2SC_IMR_TXUR_Pos)                /**< (I2SC_IMR) Transmit Underflow Interrupt Disable Mask */
#define I2SC_IMR_TXUR                       I2SC_IMR_TXUR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_TXUR_Msk instead */
#define I2SC_IMR_ENDTX_Pos                  7                                              /**< (I2SC_IMR) End of Transmission Interrupt Disable Position */
#define I2SC_IMR_ENDTX_Msk                  (_U_(0x1) << I2SC_IMR_ENDTX_Pos)               /**< (I2SC_IMR) End of Transmission Interrupt Disable Mask */
#define I2SC_IMR_ENDTX                      I2SC_IMR_ENDTX_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_ENDTX_Msk instead */
#define I2SC_IMR_RXFULL_Pos                 19                                             /**< (I2SC_IMR) Receive Buffer Full Interrupt Disable Position */
#define I2SC_IMR_RXFULL_Msk                 (_U_(0x1) << I2SC_IMR_RXFULL_Pos)              /**< (I2SC_IMR) Receive Buffer Full Interrupt Disable Mask */
#define I2SC_IMR_RXFULL                     I2SC_IMR_RXFULL_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_RXFULL_Msk instead */
#define I2SC_IMR_TXEMPTY_Pos                31                                             /**< (I2SC_IMR) Transmit Buffer Empty Interrupt Disable Position */
#define I2SC_IMR_TXEMPTY_Msk                (_U_(0x1) << I2SC_IMR_TXEMPTY_Pos)             /**< (I2SC_IMR) Transmit Buffer Empty Interrupt Disable Mask */
#define I2SC_IMR_TXEMPTY                    I2SC_IMR_TXEMPTY_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_IMR_TXEMPTY_Msk instead */
#define I2SC_IMR_MASK                       _U_(0x800800EE)                                /**< \deprecated (I2SC_IMR) Register MASK  (Use I2SC_IMR_Msk instead)  */
#define I2SC_IMR_Msk                        _U_(0x800800EE)                                /**< (I2SC_IMR) Register Mask  */


/* -------- I2SC_RHR : (I2SC Offset: 0x20) (R/ 32) Receiver Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RHR:32;                    /**< bit:  0..31  Receiver Holding Register                */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_RHR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_RHR_OFFSET                     (0x20)                                        /**<  (I2SC_RHR) Receiver Holding Register  Offset */

#define I2SC_RHR_RHR_Pos                    0                                              /**< (I2SC_RHR) Receiver Holding Register Position */
#define I2SC_RHR_RHR_Msk                    (_U_(0xFFFFFFFF) << I2SC_RHR_RHR_Pos)          /**< (I2SC_RHR) Receiver Holding Register Mask */
#define I2SC_RHR_RHR(value)                 (I2SC_RHR_RHR_Msk & ((value) << I2SC_RHR_RHR_Pos))
#define I2SC_RHR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (I2SC_RHR) Register MASK  (Use I2SC_RHR_Msk instead)  */
#define I2SC_RHR_Msk                        _U_(0xFFFFFFFF)                                /**< (I2SC_RHR) Register Mask  */


/* -------- I2SC_THR : (I2SC Offset: 0x24) (/W 32) Transmitter Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t THR:32;                    /**< bit:  0..31  Transmitter Holding Register             */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_THR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_THR_OFFSET                     (0x24)                                        /**<  (I2SC_THR) Transmitter Holding Register  Offset */

#define I2SC_THR_THR_Pos                    0                                              /**< (I2SC_THR) Transmitter Holding Register Position */
#define I2SC_THR_THR_Msk                    (_U_(0xFFFFFFFF) << I2SC_THR_THR_Pos)          /**< (I2SC_THR) Transmitter Holding Register Mask */
#define I2SC_THR_THR(value)                 (I2SC_THR_THR_Msk & ((value) << I2SC_THR_THR_Pos))
#define I2SC_THR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (I2SC_THR) Register MASK  (Use I2SC_THR_Msk instead)  */
#define I2SC_THR_Msk                        _U_(0xFFFFFFFF)                                /**< (I2SC_THR) Register Mask  */


/* -------- I2SC_RPR : (I2SC Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_RPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_RPR_OFFSET                     (0x100)                                       /**<  (I2SC_RPR) Receive Pointer Register  Offset */

#define I2SC_RPR_RXPTR_Pos                  0                                              /**< (I2SC_RPR) Receive Pointer Register Position */
#define I2SC_RPR_RXPTR_Msk                  (_U_(0xFFFFFFFF) << I2SC_RPR_RXPTR_Pos)        /**< (I2SC_RPR) Receive Pointer Register Mask */
#define I2SC_RPR_RXPTR(value)               (I2SC_RPR_RXPTR_Msk & ((value) << I2SC_RPR_RXPTR_Pos))
#define I2SC_RPR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (I2SC_RPR) Register MASK  (Use I2SC_RPR_Msk instead)  */
#define I2SC_RPR_Msk                        _U_(0xFFFFFFFF)                                /**< (I2SC_RPR) Register Mask  */


/* -------- I2SC_RCR : (I2SC Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCTR:16;                  /**< bit:  0..15  Receive Counter Register                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_RCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_RCR_OFFSET                     (0x104)                                       /**<  (I2SC_RCR) Receive Counter Register  Offset */

#define I2SC_RCR_RXCTR_Pos                  0                                              /**< (I2SC_RCR) Receive Counter Register Position */
#define I2SC_RCR_RXCTR_Msk                  (_U_(0xFFFF) << I2SC_RCR_RXCTR_Pos)            /**< (I2SC_RCR) Receive Counter Register Mask */
#define I2SC_RCR_RXCTR(value)               (I2SC_RCR_RXCTR_Msk & ((value) << I2SC_RCR_RXCTR_Pos))
#define I2SC_RCR_MASK                       _U_(0xFFFF)                                    /**< \deprecated (I2SC_RCR) Register MASK  (Use I2SC_RCR_Msk instead)  */
#define I2SC_RCR_Msk                        _U_(0xFFFF)                                    /**< (I2SC_RCR) Register Mask  */


/* -------- I2SC_TPR : (I2SC Offset: 0x108) (R/W 32) Transmit Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXPTR:32;                  /**< bit:  0..31  Transmit Counter Register                */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_TPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_TPR_OFFSET                     (0x108)                                       /**<  (I2SC_TPR) Transmit Pointer Register  Offset */

#define I2SC_TPR_TXPTR_Pos                  0                                              /**< (I2SC_TPR) Transmit Counter Register Position */
#define I2SC_TPR_TXPTR_Msk                  (_U_(0xFFFFFFFF) << I2SC_TPR_TXPTR_Pos)        /**< (I2SC_TPR) Transmit Counter Register Mask */
#define I2SC_TPR_TXPTR(value)               (I2SC_TPR_TXPTR_Msk & ((value) << I2SC_TPR_TXPTR_Pos))
#define I2SC_TPR_MASK                       _U_(0xFFFFFFFF)                                /**< \deprecated (I2SC_TPR) Register MASK  (Use I2SC_TPR_Msk instead)  */
#define I2SC_TPR_Msk                        _U_(0xFFFFFFFF)                                /**< (I2SC_TPR) Register Mask  */


/* -------- I2SC_TCR : (I2SC Offset: 0x10c) (R/W 32) Transmit Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCTR:16;                  /**< bit:  0..15  Transmit Counter Register                */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_TCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_TCR_OFFSET                     (0x10C)                                       /**<  (I2SC_TCR) Transmit Counter Register  Offset */

#define I2SC_TCR_TXCTR_Pos                  0                                              /**< (I2SC_TCR) Transmit Counter Register Position */
#define I2SC_TCR_TXCTR_Msk                  (_U_(0xFFFF) << I2SC_TCR_TXCTR_Pos)            /**< (I2SC_TCR) Transmit Counter Register Mask */
#define I2SC_TCR_TXCTR(value)               (I2SC_TCR_TXCTR_Msk & ((value) << I2SC_TCR_TXCTR_Pos))
#define I2SC_TCR_MASK                       _U_(0xFFFF)                                    /**< \deprecated (I2SC_TCR) Register MASK  (Use I2SC_TCR_Msk instead)  */
#define I2SC_TCR_Msk                        _U_(0xFFFF)                                    /**< (I2SC_TCR) Register Mask  */


/* -------- I2SC_RNPR : (I2SC Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_RNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_RNPR_OFFSET                    (0x110)                                       /**<  (I2SC_RNPR) Receive Next Pointer Register  Offset */

#define I2SC_RNPR_RXNPTR_Pos                0                                              /**< (I2SC_RNPR) Receive Next Pointer Position */
#define I2SC_RNPR_RXNPTR_Msk                (_U_(0xFFFFFFFF) << I2SC_RNPR_RXNPTR_Pos)      /**< (I2SC_RNPR) Receive Next Pointer Mask */
#define I2SC_RNPR_RXNPTR(value)             (I2SC_RNPR_RXNPTR_Msk & ((value) << I2SC_RNPR_RXNPTR_Pos))
#define I2SC_RNPR_MASK                      _U_(0xFFFFFFFF)                                /**< \deprecated (I2SC_RNPR) Register MASK  (Use I2SC_RNPR_Msk instead)  */
#define I2SC_RNPR_Msk                       _U_(0xFFFFFFFF)                                /**< (I2SC_RNPR) Register Mask  */


/* -------- I2SC_RNCR : (I2SC Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_RNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_RNCR_OFFSET                    (0x114)                                       /**<  (I2SC_RNCR) Receive Next Counter Register  Offset */

#define I2SC_RNCR_RXNCTR_Pos                0                                              /**< (I2SC_RNCR) Receive Next Counter Position */
#define I2SC_RNCR_RXNCTR_Msk                (_U_(0xFFFF) << I2SC_RNCR_RXNCTR_Pos)          /**< (I2SC_RNCR) Receive Next Counter Mask */
#define I2SC_RNCR_RXNCTR(value)             (I2SC_RNCR_RXNCTR_Msk & ((value) << I2SC_RNCR_RXNCTR_Pos))
#define I2SC_RNCR_MASK                      _U_(0xFFFF)                                    /**< \deprecated (I2SC_RNCR) Register MASK  (Use I2SC_RNCR_Msk instead)  */
#define I2SC_RNCR_Msk                       _U_(0xFFFF)                                    /**< (I2SC_RNCR) Register Mask  */


/* -------- I2SC_TNPR : (I2SC Offset: 0x118) (R/W 32) Transmit Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNPTR:32;                 /**< bit:  0..31  Transmit Next Pointer                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_TNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_TNPR_OFFSET                    (0x118)                                       /**<  (I2SC_TNPR) Transmit Next Pointer Register  Offset */

#define I2SC_TNPR_TXNPTR_Pos                0                                              /**< (I2SC_TNPR) Transmit Next Pointer Position */
#define I2SC_TNPR_TXNPTR_Msk                (_U_(0xFFFFFFFF) << I2SC_TNPR_TXNPTR_Pos)      /**< (I2SC_TNPR) Transmit Next Pointer Mask */
#define I2SC_TNPR_TXNPTR(value)             (I2SC_TNPR_TXNPTR_Msk & ((value) << I2SC_TNPR_TXNPTR_Pos))
#define I2SC_TNPR_MASK                      _U_(0xFFFFFFFF)                                /**< \deprecated (I2SC_TNPR) Register MASK  (Use I2SC_TNPR_Msk instead)  */
#define I2SC_TNPR_Msk                       _U_(0xFFFFFFFF)                                /**< (I2SC_TNPR) Register Mask  */


/* -------- I2SC_TNCR : (I2SC Offset: 0x11c) (R/W 32) Transmit Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNCTR:16;                 /**< bit:  0..15  Transmit Counter Next                    */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} I2SC_TNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_TNCR_OFFSET                    (0x11C)                                       /**<  (I2SC_TNCR) Transmit Next Counter Register  Offset */

#define I2SC_TNCR_TXNCTR_Pos                0                                              /**< (I2SC_TNCR) Transmit Counter Next Position */
#define I2SC_TNCR_TXNCTR_Msk                (_U_(0xFFFF) << I2SC_TNCR_TXNCTR_Pos)          /**< (I2SC_TNCR) Transmit Counter Next Mask */
#define I2SC_TNCR_TXNCTR(value)             (I2SC_TNCR_TXNCTR_Msk & ((value) << I2SC_TNCR_TXNCTR_Pos))
#define I2SC_TNCR_MASK                      _U_(0xFFFF)                                    /**< \deprecated (I2SC_TNCR) Register MASK  (Use I2SC_TNCR_Msk instead)  */
#define I2SC_TNCR_Msk                       _U_(0xFFFF)                                    /**< (I2SC_TNCR) Register Mask  */


/* -------- I2SC_PTCR : (I2SC Offset: 0x120) (/W 32) Transfer Control Register -------- */
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
} I2SC_PTCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_PTCR_OFFSET                    (0x120)                                       /**<  (I2SC_PTCR) Transfer Control Register  Offset */

#define I2SC_PTCR_RXTEN_Pos                 0                                              /**< (I2SC_PTCR) Receiver Transfer Enable Position */
#define I2SC_PTCR_RXTEN_Msk                 (_U_(0x1) << I2SC_PTCR_RXTEN_Pos)              /**< (I2SC_PTCR) Receiver Transfer Enable Mask */
#define I2SC_PTCR_RXTEN                     I2SC_PTCR_RXTEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_RXTEN_Msk instead */
#define I2SC_PTCR_RXTDIS_Pos                1                                              /**< (I2SC_PTCR) Receiver Transfer Disable Position */
#define I2SC_PTCR_RXTDIS_Msk                (_U_(0x1) << I2SC_PTCR_RXTDIS_Pos)             /**< (I2SC_PTCR) Receiver Transfer Disable Mask */
#define I2SC_PTCR_RXTDIS                    I2SC_PTCR_RXTDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_RXTDIS_Msk instead */
#define I2SC_PTCR_TXTEN_Pos                 8                                              /**< (I2SC_PTCR) Transmitter Transfer Enable Position */
#define I2SC_PTCR_TXTEN_Msk                 (_U_(0x1) << I2SC_PTCR_TXTEN_Pos)              /**< (I2SC_PTCR) Transmitter Transfer Enable Mask */
#define I2SC_PTCR_TXTEN                     I2SC_PTCR_TXTEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_TXTEN_Msk instead */
#define I2SC_PTCR_TXTDIS_Pos                9                                              /**< (I2SC_PTCR) Transmitter Transfer Disable Position */
#define I2SC_PTCR_TXTDIS_Msk                (_U_(0x1) << I2SC_PTCR_TXTDIS_Pos)             /**< (I2SC_PTCR) Transmitter Transfer Disable Mask */
#define I2SC_PTCR_TXTDIS                    I2SC_PTCR_TXTDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_TXTDIS_Msk instead */
#define I2SC_PTCR_RXCBEN_Pos                16                                             /**< (I2SC_PTCR) Receiver Circular Buffer Enable Position */
#define I2SC_PTCR_RXCBEN_Msk                (_U_(0x1) << I2SC_PTCR_RXCBEN_Pos)             /**< (I2SC_PTCR) Receiver Circular Buffer Enable Mask */
#define I2SC_PTCR_RXCBEN                    I2SC_PTCR_RXCBEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_RXCBEN_Msk instead */
#define I2SC_PTCR_RXCBDIS_Pos               17                                             /**< (I2SC_PTCR) Receiver Circular Buffer Disable Position */
#define I2SC_PTCR_RXCBDIS_Msk               (_U_(0x1) << I2SC_PTCR_RXCBDIS_Pos)            /**< (I2SC_PTCR) Receiver Circular Buffer Disable Mask */
#define I2SC_PTCR_RXCBDIS                   I2SC_PTCR_RXCBDIS_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_RXCBDIS_Msk instead */
#define I2SC_PTCR_TXCBEN_Pos                18                                             /**< (I2SC_PTCR) Transmitter Circular Buffer Enable Position */
#define I2SC_PTCR_TXCBEN_Msk                (_U_(0x1) << I2SC_PTCR_TXCBEN_Pos)             /**< (I2SC_PTCR) Transmitter Circular Buffer Enable Mask */
#define I2SC_PTCR_TXCBEN                    I2SC_PTCR_TXCBEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_TXCBEN_Msk instead */
#define I2SC_PTCR_TXCBDIS_Pos               19                                             /**< (I2SC_PTCR) Transmitter Circular Buffer Disable Position */
#define I2SC_PTCR_TXCBDIS_Msk               (_U_(0x1) << I2SC_PTCR_TXCBDIS_Pos)            /**< (I2SC_PTCR) Transmitter Circular Buffer Disable Mask */
#define I2SC_PTCR_TXCBDIS                   I2SC_PTCR_TXCBDIS_Msk                          /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_TXCBDIS_Msk instead */
#define I2SC_PTCR_ERRCLR_Pos                24                                             /**< (I2SC_PTCR) Transfer Bus Error Clear Position */
#define I2SC_PTCR_ERRCLR_Msk                (_U_(0x1) << I2SC_PTCR_ERRCLR_Pos)             /**< (I2SC_PTCR) Transfer Bus Error Clear Mask */
#define I2SC_PTCR_ERRCLR                    I2SC_PTCR_ERRCLR_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTCR_ERRCLR_Msk instead */
#define I2SC_PTCR_MASK                      _U_(0x10F0303)                                 /**< \deprecated (I2SC_PTCR) Register MASK  (Use I2SC_PTCR_Msk instead)  */
#define I2SC_PTCR_Msk                       _U_(0x10F0303)                                 /**< (I2SC_PTCR) Register Mask  */


/* -------- I2SC_PTSR : (I2SC Offset: 0x124) (R/ 32) Transfer Status Register -------- */
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
} I2SC_PTSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define I2SC_PTSR_OFFSET                    (0x124)                                       /**<  (I2SC_PTSR) Transfer Status Register  Offset */

#define I2SC_PTSR_RXTEN_Pos                 0                                              /**< (I2SC_PTSR) Receiver Transfer Enable Position */
#define I2SC_PTSR_RXTEN_Msk                 (_U_(0x1) << I2SC_PTSR_RXTEN_Pos)              /**< (I2SC_PTSR) Receiver Transfer Enable Mask */
#define I2SC_PTSR_RXTEN                     I2SC_PTSR_RXTEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTSR_RXTEN_Msk instead */
#define I2SC_PTSR_TXTEN_Pos                 8                                              /**< (I2SC_PTSR) Transmitter Transfer Enable Position */
#define I2SC_PTSR_TXTEN_Msk                 (_U_(0x1) << I2SC_PTSR_TXTEN_Pos)              /**< (I2SC_PTSR) Transmitter Transfer Enable Mask */
#define I2SC_PTSR_TXTEN                     I2SC_PTSR_TXTEN_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTSR_TXTEN_Msk instead */
#define I2SC_PTSR_RXCBEN_Pos                16                                             /**< (I2SC_PTSR) Receiver Circular Buffer Enable Position */
#define I2SC_PTSR_RXCBEN_Msk                (_U_(0x1) << I2SC_PTSR_RXCBEN_Pos)             /**< (I2SC_PTSR) Receiver Circular Buffer Enable Mask */
#define I2SC_PTSR_RXCBEN                    I2SC_PTSR_RXCBEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTSR_RXCBEN_Msk instead */
#define I2SC_PTSR_TXCBEN_Pos                18                                             /**< (I2SC_PTSR) Transmitter Circular Buffer Enable Position */
#define I2SC_PTSR_TXCBEN_Msk                (_U_(0x1) << I2SC_PTSR_TXCBEN_Pos)             /**< (I2SC_PTSR) Transmitter Circular Buffer Enable Mask */
#define I2SC_PTSR_TXCBEN                    I2SC_PTSR_TXCBEN_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTSR_TXCBEN_Msk instead */
#define I2SC_PTSR_ERR_Pos                   24                                             /**< (I2SC_PTSR) Transfer Bus Error Position */
#define I2SC_PTSR_ERR_Msk                   (_U_(0x1) << I2SC_PTSR_ERR_Pos)                /**< (I2SC_PTSR) Transfer Bus Error Mask */
#define I2SC_PTSR_ERR                       I2SC_PTSR_ERR_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use I2SC_PTSR_ERR_Msk instead */
#define I2SC_PTSR_MASK                      _U_(0x1050101)                                 /**< \deprecated (I2SC_PTSR) Register MASK  (Use I2SC_PTSR_Msk instead)  */
#define I2SC_PTSR_Msk                       _U_(0x1050101)                                 /**< (I2SC_PTSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief I2SC hardware registers */
typedef struct {  
  __O  uint32_t I2SC_CR;        /**< (I2SC Offset: 0x00) Control Register */
  __IO uint32_t I2SC_MR;        /**< (I2SC Offset: 0x04) Mode Register */
  __I  uint32_t I2SC_SR;        /**< (I2SC Offset: 0x08) Status Register */
  __O  uint32_t I2SC_SCR;       /**< (I2SC Offset: 0x0C) Status Clear Register */
  __O  uint32_t I2SC_SSR;       /**< (I2SC Offset: 0x10) Status Set Register */
  __O  uint32_t I2SC_IER;       /**< (I2SC Offset: 0x14) Interrupt Enable Register */
  __O  uint32_t I2SC_IDR;       /**< (I2SC Offset: 0x18) Interrupt Disable Register */
  __I  uint32_t I2SC_IMR;       /**< (I2SC Offset: 0x1C) Interrupt Mask Register */
  __I  uint32_t I2SC_RHR;       /**< (I2SC Offset: 0x20) Receiver Holding Register */
  __O  uint32_t I2SC_THR;       /**< (I2SC Offset: 0x24) Transmitter Holding Register */
  RoReg8  Reserved1[0xD8];
  __IO uint32_t I2SC_RPR;       /**< (I2SC Offset: 0x100) Receive Pointer Register */
  __IO uint32_t I2SC_RCR;       /**< (I2SC Offset: 0x104) Receive Counter Register */
  __IO uint32_t I2SC_TPR;       /**< (I2SC Offset: 0x108) Transmit Pointer Register */
  __IO uint32_t I2SC_TCR;       /**< (I2SC Offset: 0x10C) Transmit Counter Register */
  __IO uint32_t I2SC_RNPR;      /**< (I2SC Offset: 0x110) Receive Next Pointer Register */
  __IO uint32_t I2SC_RNCR;      /**< (I2SC Offset: 0x114) Receive Next Counter Register */
  __IO uint32_t I2SC_TNPR;      /**< (I2SC Offset: 0x118) Transmit Next Pointer Register */
  __IO uint32_t I2SC_TNCR;      /**< (I2SC Offset: 0x11C) Transmit Next Counter Register */
  __O  uint32_t I2SC_PTCR;      /**< (I2SC Offset: 0x120) Transfer Control Register */
  __I  uint32_t I2SC_PTSR;      /**< (I2SC Offset: 0x124) Transfer Status Register */
} I2sc;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief I2SC hardware registers */
typedef struct {  
  __O  I2SC_CR_Type                   I2SC_CR;        /**< Offset: 0x00 ( /W  32) Control Register */
  __IO I2SC_MR_Type                   I2SC_MR;        /**< Offset: 0x04 (R/W  32) Mode Register */
  __I  I2SC_SR_Type                   I2SC_SR;        /**< Offset: 0x08 (R/   32) Status Register */
  __O  I2SC_SCR_Type                  I2SC_SCR;       /**< Offset: 0x0C ( /W  32) Status Clear Register */
  __O  I2SC_SSR_Type                  I2SC_SSR;       /**< Offset: 0x10 ( /W  32) Status Set Register */
  __O  I2SC_IER_Type                  I2SC_IER;       /**< Offset: 0x14 ( /W  32) Interrupt Enable Register */
  __O  I2SC_IDR_Type                  I2SC_IDR;       /**< Offset: 0x18 ( /W  32) Interrupt Disable Register */
  __I  I2SC_IMR_Type                  I2SC_IMR;       /**< Offset: 0x1C (R/   32) Interrupt Mask Register */
  __I  I2SC_RHR_Type                  I2SC_RHR;       /**< Offset: 0x20 (R/   32) Receiver Holding Register */
  __O  I2SC_THR_Type                  I2SC_THR;       /**< Offset: 0x24 ( /W  32) Transmitter Holding Register */
  __I  uint32_t                       Reserved1[54];
  __IO I2SC_RPR_Type                  I2SC_RPR;       /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO I2SC_RCR_Type                  I2SC_RCR;       /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __IO I2SC_TPR_Type                  I2SC_TPR;       /**< Offset: 0x108 (R/W  32) Transmit Pointer Register */
  __IO I2SC_TCR_Type                  I2SC_TCR;       /**< Offset: 0x10C (R/W  32) Transmit Counter Register */
  __IO I2SC_RNPR_Type                 I2SC_RNPR;      /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO I2SC_RNCR_Type                 I2SC_RNCR;      /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __IO I2SC_TNPR_Type                 I2SC_TNPR;      /**< Offset: 0x118 (R/W  32) Transmit Next Pointer Register */
  __IO I2SC_TNCR_Type                 I2SC_TNCR;      /**< Offset: 0x11C (R/W  32) Transmit Next Counter Register */
  __O  I2SC_PTCR_Type                 I2SC_PTCR;      /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I  I2SC_PTSR_Type                 I2SC_PTSR;      /**< Offset: 0x124 (R/   32) Transfer Status Register */
} I2sc;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Inter-IC Sound Controller */

#endif /* _SAMG55_I2SC_COMPONENT_H_ */
