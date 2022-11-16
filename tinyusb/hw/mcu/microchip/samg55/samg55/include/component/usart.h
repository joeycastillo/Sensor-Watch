/**
 * \file
 *
 * \brief Component description for USART
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
#ifndef _SAMG55_USART_COMPONENT_H_
#define _SAMG55_USART_COMPONENT_H_
#define _SAMG55_USART_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Universal Synchronous Asynchronous Receiver Transmitter
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR USART */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define USART_11278                      /**< (USART) Module ID */
#define REV_USART C                      /**< (USART) Module revision */

/* -------- US_CR : (USART Offset: 0x00) (/W 32) Control Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t :2;                        /**< bit:   0..1  Reserved */
    uint32_t RSTRX:1;                   /**< bit:      2  Reset Receiver                           */
    uint32_t RSTTX:1;                   /**< bit:      3  Reset Transmitter                        */
    uint32_t RXEN:1;                    /**< bit:      4  Receiver Enable                          */
    uint32_t RXDIS:1;                   /**< bit:      5  Receiver Disable                         */
    uint32_t TXEN:1;                    /**< bit:      6  Transmitter Enable                       */
    uint32_t TXDIS:1;                   /**< bit:      7  Transmitter Disable                      */
    uint32_t RSTSTA:1;                  /**< bit:      8  Reset Status Bits                        */
    uint32_t STTBRK:1;                  /**< bit:      9  Start Break                              */
    uint32_t STPBRK:1;                  /**< bit:     10  Stop Break                               */
    uint32_t STTTO:1;                   /**< bit:     11  Clear TIMEOUT Flag and Start Time-out After Next Character Received */
    uint32_t SENDA:1;                   /**< bit:     12  Send Address                             */
    uint32_t RSTIT:1;                   /**< bit:     13  Reset Iterations                         */
    uint32_t RSTNACK:1;                 /**< bit:     14  Reset Non Acknowledge                    */
    uint32_t RETTO:1;                   /**< bit:     15  Start Time-out Immediately               */
    uint32_t :2;                        /**< bit: 16..17  Reserved */
    uint32_t RTSEN:1;                   /**< bit:     18  Request to Send Enable                   */
    uint32_t RTSDIS:1;                  /**< bit:     19  Request to Send Disable                  */
    uint32_t LINABT:1;                  /**< bit:     20  Abort LIN Transmission                   */
    uint32_t LINWKUP:1;                 /**< bit:     21  Send LIN Wakeup Signal                   */
    uint32_t :6;                        /**< bit: 22..27  Reserved */
    uint32_t REQCLR:1;                  /**< bit:     28  Request to Clear the Comparison Trigger  */
    uint32_t :3;                        /**< bit: 29..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_CR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_CR_OFFSET                        (0x00)                                        /**<  (US_CR) Control Register  Offset */

#define US_CR_RSTRX_Pos                     2                                              /**< (US_CR) Reset Receiver Position */
#define US_CR_RSTRX_Msk                     (_U_(0x1) << US_CR_RSTRX_Pos)                  /**< (US_CR) Reset Receiver Mask */
#define US_CR_RSTRX                         US_CR_RSTRX_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RSTRX_Msk instead */
#define US_CR_RSTTX_Pos                     3                                              /**< (US_CR) Reset Transmitter Position */
#define US_CR_RSTTX_Msk                     (_U_(0x1) << US_CR_RSTTX_Pos)                  /**< (US_CR) Reset Transmitter Mask */
#define US_CR_RSTTX                         US_CR_RSTTX_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RSTTX_Msk instead */
#define US_CR_RXEN_Pos                      4                                              /**< (US_CR) Receiver Enable Position */
#define US_CR_RXEN_Msk                      (_U_(0x1) << US_CR_RXEN_Pos)                   /**< (US_CR) Receiver Enable Mask */
#define US_CR_RXEN                          US_CR_RXEN_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RXEN_Msk instead */
#define US_CR_RXDIS_Pos                     5                                              /**< (US_CR) Receiver Disable Position */
#define US_CR_RXDIS_Msk                     (_U_(0x1) << US_CR_RXDIS_Pos)                  /**< (US_CR) Receiver Disable Mask */
#define US_CR_RXDIS                         US_CR_RXDIS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RXDIS_Msk instead */
#define US_CR_TXEN_Pos                      6                                              /**< (US_CR) Transmitter Enable Position */
#define US_CR_TXEN_Msk                      (_U_(0x1) << US_CR_TXEN_Pos)                   /**< (US_CR) Transmitter Enable Mask */
#define US_CR_TXEN                          US_CR_TXEN_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_TXEN_Msk instead */
#define US_CR_TXDIS_Pos                     7                                              /**< (US_CR) Transmitter Disable Position */
#define US_CR_TXDIS_Msk                     (_U_(0x1) << US_CR_TXDIS_Pos)                  /**< (US_CR) Transmitter Disable Mask */
#define US_CR_TXDIS                         US_CR_TXDIS_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_TXDIS_Msk instead */
#define US_CR_RSTSTA_Pos                    8                                              /**< (US_CR) Reset Status Bits Position */
#define US_CR_RSTSTA_Msk                    (_U_(0x1) << US_CR_RSTSTA_Pos)                 /**< (US_CR) Reset Status Bits Mask */
#define US_CR_RSTSTA                        US_CR_RSTSTA_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RSTSTA_Msk instead */
#define US_CR_STTBRK_Pos                    9                                              /**< (US_CR) Start Break Position */
#define US_CR_STTBRK_Msk                    (_U_(0x1) << US_CR_STTBRK_Pos)                 /**< (US_CR) Start Break Mask */
#define US_CR_STTBRK                        US_CR_STTBRK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_STTBRK_Msk instead */
#define US_CR_STPBRK_Pos                    10                                             /**< (US_CR) Stop Break Position */
#define US_CR_STPBRK_Msk                    (_U_(0x1) << US_CR_STPBRK_Pos)                 /**< (US_CR) Stop Break Mask */
#define US_CR_STPBRK                        US_CR_STPBRK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_STPBRK_Msk instead */
#define US_CR_STTTO_Pos                     11                                             /**< (US_CR) Clear TIMEOUT Flag and Start Time-out After Next Character Received Position */
#define US_CR_STTTO_Msk                     (_U_(0x1) << US_CR_STTTO_Pos)                  /**< (US_CR) Clear TIMEOUT Flag and Start Time-out After Next Character Received Mask */
#define US_CR_STTTO                         US_CR_STTTO_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_STTTO_Msk instead */
#define US_CR_SENDA_Pos                     12                                             /**< (US_CR) Send Address Position */
#define US_CR_SENDA_Msk                     (_U_(0x1) << US_CR_SENDA_Pos)                  /**< (US_CR) Send Address Mask */
#define US_CR_SENDA                         US_CR_SENDA_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_SENDA_Msk instead */
#define US_CR_RSTIT_Pos                     13                                             /**< (US_CR) Reset Iterations Position */
#define US_CR_RSTIT_Msk                     (_U_(0x1) << US_CR_RSTIT_Pos)                  /**< (US_CR) Reset Iterations Mask */
#define US_CR_RSTIT                         US_CR_RSTIT_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RSTIT_Msk instead */
#define US_CR_RSTNACK_Pos                   14                                             /**< (US_CR) Reset Non Acknowledge Position */
#define US_CR_RSTNACK_Msk                   (_U_(0x1) << US_CR_RSTNACK_Pos)                /**< (US_CR) Reset Non Acknowledge Mask */
#define US_CR_RSTNACK                       US_CR_RSTNACK_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RSTNACK_Msk instead */
#define US_CR_RETTO_Pos                     15                                             /**< (US_CR) Start Time-out Immediately Position */
#define US_CR_RETTO_Msk                     (_U_(0x1) << US_CR_RETTO_Pos)                  /**< (US_CR) Start Time-out Immediately Mask */
#define US_CR_RETTO                         US_CR_RETTO_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RETTO_Msk instead */
#define US_CR_RTSEN_Pos                     18                                             /**< (US_CR) Request to Send Enable Position */
#define US_CR_RTSEN_Msk                     (_U_(0x1) << US_CR_RTSEN_Pos)                  /**< (US_CR) Request to Send Enable Mask */
#define US_CR_RTSEN                         US_CR_RTSEN_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RTSEN_Msk instead */
#define US_CR_RTSDIS_Pos                    19                                             /**< (US_CR) Request to Send Disable Position */
#define US_CR_RTSDIS_Msk                    (_U_(0x1) << US_CR_RTSDIS_Pos)                 /**< (US_CR) Request to Send Disable Mask */
#define US_CR_RTSDIS                        US_CR_RTSDIS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_RTSDIS_Msk instead */
#define US_CR_LINABT_Pos                    20                                             /**< (US_CR) Abort LIN Transmission Position */
#define US_CR_LINABT_Msk                    (_U_(0x1) << US_CR_LINABT_Pos)                 /**< (US_CR) Abort LIN Transmission Mask */
#define US_CR_LINABT                        US_CR_LINABT_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_LINABT_Msk instead */
#define US_CR_LINWKUP_Pos                   21                                             /**< (US_CR) Send LIN Wakeup Signal Position */
#define US_CR_LINWKUP_Msk                   (_U_(0x1) << US_CR_LINWKUP_Pos)                /**< (US_CR) Send LIN Wakeup Signal Mask */
#define US_CR_LINWKUP                       US_CR_LINWKUP_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_LINWKUP_Msk instead */
#define US_CR_REQCLR_Pos                    28                                             /**< (US_CR) Request to Clear the Comparison Trigger Position */
#define US_CR_REQCLR_Msk                    (_U_(0x1) << US_CR_REQCLR_Pos)                 /**< (US_CR) Request to Clear the Comparison Trigger Mask */
#define US_CR_REQCLR                        US_CR_REQCLR_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CR_REQCLR_Msk instead */
#define US_CR_MASK                          _U_(0x103CFFFC)                                /**< \deprecated (US_CR) Register MASK  (Use US_CR_Msk instead)  */
#define US_CR_Msk                           _U_(0x103CFFFC)                                /**< (US_CR) Register Mask  */


/* -------- US_MR : (USART Offset: 0x04) (R/W 32) Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t USART_MODE:4;              /**< bit:   0..3  USART Mode of Operation                  */
    uint32_t USCLKS:2;                  /**< bit:   4..5  Clock Selection                          */
    uint32_t CHRL:2;                    /**< bit:   6..7  Character Length                         */
    uint32_t SYNC:1;                    /**< bit:      8  Synchronous Mode Select                  */
    uint32_t PAR:3;                     /**< bit:  9..11  Parity Type                              */
    uint32_t NBSTOP:2;                  /**< bit: 12..13  Number of Stop Bits                      */
    uint32_t CHMODE:2;                  /**< bit: 14..15  Channel Mode                             */
    uint32_t MSBF:1;                    /**< bit:     16  Bit Order                                */
    uint32_t MODE9:1;                   /**< bit:     17  9-bit Character Length                   */
    uint32_t CLKO:1;                    /**< bit:     18  Clock Output Select                      */
    uint32_t OVER:1;                    /**< bit:     19  Oversampling Mode                        */
    uint32_t INACK:1;                   /**< bit:     20  Inhibit Non Acknowledge                  */
    uint32_t DSNACK:1;                  /**< bit:     21  Disable Successive NACK                  */
    uint32_t :1;                        /**< bit:     22  Reserved */
    uint32_t INVDATA:1;                 /**< bit:     23  Inverted Data                            */
    uint32_t MAX_ITERATION:3;           /**< bit: 24..26  Maximum Number of Automatic Iteration    */
    uint32_t :1;                        /**< bit:     27  Reserved */
    uint32_t FILTER:1;                  /**< bit:     28  Receive Line Filter                      */
    uint32_t :3;                        /**< bit: 29..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_MR_OFFSET                        (0x04)                                        /**<  (US_MR) Mode Register  Offset */

#define US_MR_USART_MODE_Pos                0                                              /**< (US_MR) USART Mode of Operation Position */
#define US_MR_USART_MODE_Msk                (_U_(0xF) << US_MR_USART_MODE_Pos)             /**< (US_MR) USART Mode of Operation Mask */
#define US_MR_USART_MODE(value)             (US_MR_USART_MODE_Msk & ((value) << US_MR_USART_MODE_Pos))
#define   US_MR_USART_MODE_NORMAL_Val       _U_(0x0)                                       /**< (US_MR) Normal mode  */
#define   US_MR_USART_MODE_RS485_Val        _U_(0x1)                                       /**< (US_MR) RS485 mode  */
#define   US_MR_USART_MODE_HW_HANDSHAKING_Val _U_(0x2)                                       /**< (US_MR) Hardware Handshaking  */
#define   US_MR_USART_MODE_IS07816_T_0_Val  _U_(0x4)                                       /**< (US_MR) IS07816 Protocol: T = 0  */
#define   US_MR_USART_MODE_IS07816_T_1_Val  _U_(0x6)                                       /**< (US_MR) IS07816 Protocol: T = 1  */
#define   US_MR_USART_MODE_IRDA_Val         _U_(0x8)                                       /**< (US_MR) IrDA mode  */
#define   US_MR_USART_MODE_LIN_MASTER_Val   _U_(0xA)                                       /**< (US_MR) LIN master mode  */
#define   US_MR_USART_MODE_LIN_SLAVE_Val    _U_(0xB)                                       /**< (US_MR) LIN Slave mode  */
#define   US_MR_USART_MODE_SPI_MASTER_Val   _U_(0xE)                                       /**< (US_MR) SPI master mode  */
#define   US_MR_USART_MODE_SPI_SLAVE_Val    _U_(0xF)                                       /**< (US_MR) SPI Slave mode  */
#define US_MR_USART_MODE_NORMAL             (US_MR_USART_MODE_NORMAL_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) Normal mode Position  */
#define US_MR_USART_MODE_RS485              (US_MR_USART_MODE_RS485_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) RS485 mode Position  */
#define US_MR_USART_MODE_HW_HANDSHAKING     (US_MR_USART_MODE_HW_HANDSHAKING_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) Hardware Handshaking Position  */
#define US_MR_USART_MODE_IS07816_T_0        (US_MR_USART_MODE_IS07816_T_0_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) IS07816 Protocol: T = 0 Position  */
#define US_MR_USART_MODE_IS07816_T_1        (US_MR_USART_MODE_IS07816_T_1_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) IS07816 Protocol: T = 1 Position  */
#define US_MR_USART_MODE_IRDA               (US_MR_USART_MODE_IRDA_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) IrDA mode Position  */
#define US_MR_USART_MODE_LIN_MASTER         (US_MR_USART_MODE_LIN_MASTER_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) LIN master mode Position  */
#define US_MR_USART_MODE_LIN_SLAVE          (US_MR_USART_MODE_LIN_SLAVE_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) LIN Slave mode Position  */
#define US_MR_USART_MODE_SPI_MASTER         (US_MR_USART_MODE_SPI_MASTER_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) SPI master mode Position  */
#define US_MR_USART_MODE_SPI_SLAVE          (US_MR_USART_MODE_SPI_SLAVE_Val << US_MR_USART_MODE_Pos)  /**< (US_MR) SPI Slave mode Position  */
#define US_MR_USCLKS_Pos                    4                                              /**< (US_MR) Clock Selection Position */
#define US_MR_USCLKS_Msk                    (_U_(0x3) << US_MR_USCLKS_Pos)                 /**< (US_MR) Clock Selection Mask */
#define US_MR_USCLKS(value)                 (US_MR_USCLKS_Msk & ((value) << US_MR_USCLKS_Pos))
#define   US_MR_USCLKS_MCK_Val              _U_(0x0)                                       /**< (US_MR) Peripheral clock is selected  */
#define   US_MR_USCLKS_DIV_Val              _U_(0x1)                                       /**< (US_MR) Peripheral clock divided (DIV=8) is selected  */
#define   US_MR_USCLKS_PMC_PCK_Val          _U_(0x2)                                       /**< (US_MR) PMC programmable clock (PCK) is selected.If the SCK pin is driven (CLKO=1), the CD field must be greater than 1.  */
#define   US_MR_USCLKS_SCK_Val              _U_(0x3)                                       /**< (US_MR) External pin (SCK) is selected  */
#define US_MR_USCLKS_MCK                    (US_MR_USCLKS_MCK_Val << US_MR_USCLKS_Pos)     /**< (US_MR) Peripheral clock is selected Position  */
#define US_MR_USCLKS_DIV                    (US_MR_USCLKS_DIV_Val << US_MR_USCLKS_Pos)     /**< (US_MR) Peripheral clock divided (DIV=8) is selected Position  */
#define US_MR_USCLKS_PMC_PCK                (US_MR_USCLKS_PMC_PCK_Val << US_MR_USCLKS_Pos)  /**< (US_MR) PMC programmable clock (PCK) is selected.If the SCK pin is driven (CLKO=1), the CD field must be greater than 1. Position  */
#define US_MR_USCLKS_SCK                    (US_MR_USCLKS_SCK_Val << US_MR_USCLKS_Pos)     /**< (US_MR) External pin (SCK) is selected Position  */
#define US_MR_CHRL_Pos                      6                                              /**< (US_MR) Character Length Position */
#define US_MR_CHRL_Msk                      (_U_(0x3) << US_MR_CHRL_Pos)                   /**< (US_MR) Character Length Mask */
#define US_MR_CHRL(value)                   (US_MR_CHRL_Msk & ((value) << US_MR_CHRL_Pos))
#define   US_MR_CHRL_5_BIT_Val              _U_(0x0)                                       /**< (US_MR) Character length is 5 bits  */
#define   US_MR_CHRL_6_BIT_Val              _U_(0x1)                                       /**< (US_MR) Character length is 6 bits  */
#define   US_MR_CHRL_7_BIT_Val              _U_(0x2)                                       /**< (US_MR) Character length is 7 bits  */
#define   US_MR_CHRL_8_BIT_Val              _U_(0x3)                                       /**< (US_MR) Character length is 8 bits  */
#define US_MR_CHRL_5_BIT                    (US_MR_CHRL_5_BIT_Val << US_MR_CHRL_Pos)       /**< (US_MR) Character length is 5 bits Position  */
#define US_MR_CHRL_6_BIT                    (US_MR_CHRL_6_BIT_Val << US_MR_CHRL_Pos)       /**< (US_MR) Character length is 6 bits Position  */
#define US_MR_CHRL_7_BIT                    (US_MR_CHRL_7_BIT_Val << US_MR_CHRL_Pos)       /**< (US_MR) Character length is 7 bits Position  */
#define US_MR_CHRL_8_BIT                    (US_MR_CHRL_8_BIT_Val << US_MR_CHRL_Pos)       /**< (US_MR) Character length is 8 bits Position  */
#define US_MR_SYNC_Pos                      8                                              /**< (US_MR) Synchronous Mode Select Position */
#define US_MR_SYNC_Msk                      (_U_(0x1) << US_MR_SYNC_Pos)                   /**< (US_MR) Synchronous Mode Select Mask */
#define US_MR_SYNC                          US_MR_SYNC_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_SYNC_Msk instead */
#define US_MR_PAR_Pos                       9                                              /**< (US_MR) Parity Type Position */
#define US_MR_PAR_Msk                       (_U_(0x7) << US_MR_PAR_Pos)                    /**< (US_MR) Parity Type Mask */
#define US_MR_PAR(value)                    (US_MR_PAR_Msk & ((value) << US_MR_PAR_Pos)) 
#define   US_MR_PAR_EVEN_Val                _U_(0x0)                                       /**< (US_MR) Even parity  */
#define   US_MR_PAR_ODD_Val                 _U_(0x1)                                       /**< (US_MR) Odd parity  */
#define   US_MR_PAR_SPACE_Val               _U_(0x2)                                       /**< (US_MR) Parity forced to 0 (Space)  */
#define   US_MR_PAR_MARK_Val                _U_(0x3)                                       /**< (US_MR) Parity forced to 1 (Mark)  */
#define   US_MR_PAR_NO_Val                  _U_(0x4)                                       /**< (US_MR) No parity  */
#define   US_MR_PAR_MULTIDROP_Val           _U_(0x6)                                       /**< (US_MR) Multidrop mode  */
#define US_MR_PAR_EVEN                      (US_MR_PAR_EVEN_Val << US_MR_PAR_Pos)          /**< (US_MR) Even parity Position  */
#define US_MR_PAR_ODD                       (US_MR_PAR_ODD_Val << US_MR_PAR_Pos)           /**< (US_MR) Odd parity Position  */
#define US_MR_PAR_SPACE                     (US_MR_PAR_SPACE_Val << US_MR_PAR_Pos)         /**< (US_MR) Parity forced to 0 (Space) Position  */
#define US_MR_PAR_MARK                      (US_MR_PAR_MARK_Val << US_MR_PAR_Pos)          /**< (US_MR) Parity forced to 1 (Mark) Position  */
#define US_MR_PAR_NO                        (US_MR_PAR_NO_Val << US_MR_PAR_Pos)            /**< (US_MR) No parity Position  */
#define US_MR_PAR_MULTIDROP                 (US_MR_PAR_MULTIDROP_Val << US_MR_PAR_Pos)     /**< (US_MR) Multidrop mode Position  */
#define US_MR_NBSTOP_Pos                    12                                             /**< (US_MR) Number of Stop Bits Position */
#define US_MR_NBSTOP_Msk                    (_U_(0x3) << US_MR_NBSTOP_Pos)                 /**< (US_MR) Number of Stop Bits Mask */
#define US_MR_NBSTOP(value)                 (US_MR_NBSTOP_Msk & ((value) << US_MR_NBSTOP_Pos))
#define   US_MR_NBSTOP_1_BIT_Val            _U_(0x0)                                       /**< (US_MR) 1 stop bit  */
#define   US_MR_NBSTOP_1_5_BIT_Val          _U_(0x1)                                       /**< (US_MR) 1.5 stop bits (SYNC = 0) or reserved (SYNC = 1)  */
#define   US_MR_NBSTOP_2_BIT_Val            _U_(0x2)                                       /**< (US_MR) 2 stop bits  */
#define US_MR_NBSTOP_1_BIT                  (US_MR_NBSTOP_1_BIT_Val << US_MR_NBSTOP_Pos)   /**< (US_MR) 1 stop bit Position  */
#define US_MR_NBSTOP_1_5_BIT                (US_MR_NBSTOP_1_5_BIT_Val << US_MR_NBSTOP_Pos)  /**< (US_MR) 1.5 stop bits (SYNC = 0) or reserved (SYNC = 1) Position  */
#define US_MR_NBSTOP_2_BIT                  (US_MR_NBSTOP_2_BIT_Val << US_MR_NBSTOP_Pos)   /**< (US_MR) 2 stop bits Position  */
#define US_MR_CHMODE_Pos                    14                                             /**< (US_MR) Channel Mode Position */
#define US_MR_CHMODE_Msk                    (_U_(0x3) << US_MR_CHMODE_Pos)                 /**< (US_MR) Channel Mode Mask */
#define US_MR_CHMODE(value)                 (US_MR_CHMODE_Msk & ((value) << US_MR_CHMODE_Pos))
#define   US_MR_CHMODE_NORMAL_Val           _U_(0x0)                                       /**< (US_MR) Normal mode  */
#define   US_MR_CHMODE_AUTOMATIC_Val        _U_(0x1)                                       /**< (US_MR) Automatic Echo. Receiver input is connected to the TXD pin.  */
#define   US_MR_CHMODE_LOCAL_LOOPBACK_Val   _U_(0x2)                                       /**< (US_MR) Local Loopback. Transmitter output is connected to the Receiver Input.  */
#define   US_MR_CHMODE_REMOTE_LOOPBACK_Val  _U_(0x3)                                       /**< (US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin.  */
#define US_MR_CHMODE_NORMAL                 (US_MR_CHMODE_NORMAL_Val << US_MR_CHMODE_Pos)  /**< (US_MR) Normal mode Position  */
#define US_MR_CHMODE_AUTOMATIC              (US_MR_CHMODE_AUTOMATIC_Val << US_MR_CHMODE_Pos)  /**< (US_MR) Automatic Echo. Receiver input is connected to the TXD pin. Position  */
#define US_MR_CHMODE_LOCAL_LOOPBACK         (US_MR_CHMODE_LOCAL_LOOPBACK_Val << US_MR_CHMODE_Pos)  /**< (US_MR) Local Loopback. Transmitter output is connected to the Receiver Input. Position  */
#define US_MR_CHMODE_REMOTE_LOOPBACK        (US_MR_CHMODE_REMOTE_LOOPBACK_Val << US_MR_CHMODE_Pos)  /**< (US_MR) Remote Loopback. RXD pin is internally connected to the TXD pin. Position  */
#define US_MR_MSBF_Pos                      16                                             /**< (US_MR) Bit Order Position */
#define US_MR_MSBF_Msk                      (_U_(0x1) << US_MR_MSBF_Pos)                   /**< (US_MR) Bit Order Mask */
#define US_MR_MSBF                          US_MR_MSBF_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_MSBF_Msk instead */
#define US_MR_MODE9_Pos                     17                                             /**< (US_MR) 9-bit Character Length Position */
#define US_MR_MODE9_Msk                     (_U_(0x1) << US_MR_MODE9_Pos)                  /**< (US_MR) 9-bit Character Length Mask */
#define US_MR_MODE9                         US_MR_MODE9_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_MODE9_Msk instead */
#define US_MR_CLKO_Pos                      18                                             /**< (US_MR) Clock Output Select Position */
#define US_MR_CLKO_Msk                      (_U_(0x1) << US_MR_CLKO_Pos)                   /**< (US_MR) Clock Output Select Mask */
#define US_MR_CLKO                          US_MR_CLKO_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_CLKO_Msk instead */
#define US_MR_OVER_Pos                      19                                             /**< (US_MR) Oversampling Mode Position */
#define US_MR_OVER_Msk                      (_U_(0x1) << US_MR_OVER_Pos)                   /**< (US_MR) Oversampling Mode Mask */
#define US_MR_OVER                          US_MR_OVER_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_OVER_Msk instead */
#define US_MR_INACK_Pos                     20                                             /**< (US_MR) Inhibit Non Acknowledge Position */
#define US_MR_INACK_Msk                     (_U_(0x1) << US_MR_INACK_Pos)                  /**< (US_MR) Inhibit Non Acknowledge Mask */
#define US_MR_INACK                         US_MR_INACK_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_INACK_Msk instead */
#define US_MR_DSNACK_Pos                    21                                             /**< (US_MR) Disable Successive NACK Position */
#define US_MR_DSNACK_Msk                    (_U_(0x1) << US_MR_DSNACK_Pos)                 /**< (US_MR) Disable Successive NACK Mask */
#define US_MR_DSNACK                        US_MR_DSNACK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_DSNACK_Msk instead */
#define US_MR_INVDATA_Pos                   23                                             /**< (US_MR) Inverted Data Position */
#define US_MR_INVDATA_Msk                   (_U_(0x1) << US_MR_INVDATA_Pos)                /**< (US_MR) Inverted Data Mask */
#define US_MR_INVDATA                       US_MR_INVDATA_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_INVDATA_Msk instead */
#define US_MR_MAX_ITERATION_Pos             24                                             /**< (US_MR) Maximum Number of Automatic Iteration Position */
#define US_MR_MAX_ITERATION_Msk             (_U_(0x7) << US_MR_MAX_ITERATION_Pos)          /**< (US_MR) Maximum Number of Automatic Iteration Mask */
#define US_MR_MAX_ITERATION(value)          (US_MR_MAX_ITERATION_Msk & ((value) << US_MR_MAX_ITERATION_Pos))
#define US_MR_FILTER_Pos                    28                                             /**< (US_MR) Receive Line Filter Position */
#define US_MR_FILTER_Msk                    (_U_(0x1) << US_MR_FILTER_Pos)                 /**< (US_MR) Receive Line Filter Mask */
#define US_MR_FILTER                        US_MR_FILTER_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_MR_FILTER_Msk instead */
#define US_MR_MASK                          _U_(0x17BFFFFF)                                /**< \deprecated (US_MR) Register MASK  (Use US_MR_Msk instead)  */
#define US_MR_Msk                           _U_(0x17BFFFFF)                                /**< (US_MR) Register Mask  */


/* -------- US_IER : (USART Offset: 0x08) (/W 32) Interrupt Enable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXRDY:1;                   /**< bit:      0  RXRDY Interrupt Enable                   */
    uint32_t TXRDY:1;                   /**< bit:      1  TXRDY Interrupt Enable                   */
    uint32_t RXBRK:1;                   /**< bit:      2  Receiver Break Interrupt Enable          */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Receive Buffer Interrupt Enable (available in all USART modes of operation) */
    uint32_t ENDTX:1;                   /**< bit:      4  End of Transmit Buffer Interrupt Enable (available in all USART modes of operation) */
    uint32_t OVRE:1;                    /**< bit:      5  Overrun Error Interrupt Enable           */
    uint32_t FRAME:1;                   /**< bit:      6  Framing Error Interrupt Enable           */
    uint32_t PARE:1;                    /**< bit:      7  Parity Error Interrupt Enable            */
    uint32_t TIMEOUT:1;                 /**< bit:      8  Time-out Interrupt Enable                */
    uint32_t TXEMPTY:1;                 /**< bit:      9  TXEMPTY Interrupt Enable                 */
    uint32_t ITER:1;                    /**< bit:     10  Max number of Repetitions Reached Interrupt Enable */
    uint32_t TXBUFE:1;                  /**< bit:     11  Transmit Buffer Empty Interrupt Enable (available in all USART modes of operation) */
    uint32_t RXBUFF:1;                  /**< bit:     12  Receive Buffer Full Interrupt Enable (available in all USART modes of operation) */
    uint32_t NACK:1;                    /**< bit:     13  Non Acknowledge Interrupt Enable         */
    uint32_t :5;                        /**< bit: 14..18  Reserved */
    uint32_t CTSIC:1;                   /**< bit:     19  Clear to Send Input Change Interrupt Enable */
    uint32_t :2;                        /**< bit: 20..21  Reserved */
    uint32_t CMP:1;                     /**< bit:     22  Comparison Interrupt Enable              */
    uint32_t :9;                        /**< bit: 23..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_IER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_IER_OFFSET                       (0x08)                                        /**<  (US_IER) Interrupt Enable Register  Offset */

#define US_IER_RXRDY_Pos                    0                                              /**< (US_IER) RXRDY Interrupt Enable Position */
#define US_IER_RXRDY_Msk                    (_U_(0x1) << US_IER_RXRDY_Pos)                 /**< (US_IER) RXRDY Interrupt Enable Mask */
#define US_IER_RXRDY                        US_IER_RXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_RXRDY_Msk instead */
#define US_IER_TXRDY_Pos                    1                                              /**< (US_IER) TXRDY Interrupt Enable Position */
#define US_IER_TXRDY_Msk                    (_U_(0x1) << US_IER_TXRDY_Pos)                 /**< (US_IER) TXRDY Interrupt Enable Mask */
#define US_IER_TXRDY                        US_IER_TXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_TXRDY_Msk instead */
#define US_IER_RXBRK_Pos                    2                                              /**< (US_IER) Receiver Break Interrupt Enable Position */
#define US_IER_RXBRK_Msk                    (_U_(0x1) << US_IER_RXBRK_Pos)                 /**< (US_IER) Receiver Break Interrupt Enable Mask */
#define US_IER_RXBRK                        US_IER_RXBRK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_RXBRK_Msk instead */
#define US_IER_ENDRX_Pos                    3                                              /**< (US_IER) End of Receive Buffer Interrupt Enable (available in all USART modes of operation) Position */
#define US_IER_ENDRX_Msk                    (_U_(0x1) << US_IER_ENDRX_Pos)                 /**< (US_IER) End of Receive Buffer Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IER_ENDRX                        US_IER_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_ENDRX_Msk instead */
#define US_IER_ENDTX_Pos                    4                                              /**< (US_IER) End of Transmit Buffer Interrupt Enable (available in all USART modes of operation) Position */
#define US_IER_ENDTX_Msk                    (_U_(0x1) << US_IER_ENDTX_Pos)                 /**< (US_IER) End of Transmit Buffer Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IER_ENDTX                        US_IER_ENDTX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_ENDTX_Msk instead */
#define US_IER_OVRE_Pos                     5                                              /**< (US_IER) Overrun Error Interrupt Enable Position */
#define US_IER_OVRE_Msk                     (_U_(0x1) << US_IER_OVRE_Pos)                  /**< (US_IER) Overrun Error Interrupt Enable Mask */
#define US_IER_OVRE                         US_IER_OVRE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_OVRE_Msk instead */
#define US_IER_FRAME_Pos                    6                                              /**< (US_IER) Framing Error Interrupt Enable Position */
#define US_IER_FRAME_Msk                    (_U_(0x1) << US_IER_FRAME_Pos)                 /**< (US_IER) Framing Error Interrupt Enable Mask */
#define US_IER_FRAME                        US_IER_FRAME_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_FRAME_Msk instead */
#define US_IER_PARE_Pos                     7                                              /**< (US_IER) Parity Error Interrupt Enable Position */
#define US_IER_PARE_Msk                     (_U_(0x1) << US_IER_PARE_Pos)                  /**< (US_IER) Parity Error Interrupt Enable Mask */
#define US_IER_PARE                         US_IER_PARE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_PARE_Msk instead */
#define US_IER_TIMEOUT_Pos                  8                                              /**< (US_IER) Time-out Interrupt Enable Position */
#define US_IER_TIMEOUT_Msk                  (_U_(0x1) << US_IER_TIMEOUT_Pos)               /**< (US_IER) Time-out Interrupt Enable Mask */
#define US_IER_TIMEOUT                      US_IER_TIMEOUT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_TIMEOUT_Msk instead */
#define US_IER_TXEMPTY_Pos                  9                                              /**< (US_IER) TXEMPTY Interrupt Enable Position */
#define US_IER_TXEMPTY_Msk                  (_U_(0x1) << US_IER_TXEMPTY_Pos)               /**< (US_IER) TXEMPTY Interrupt Enable Mask */
#define US_IER_TXEMPTY                      US_IER_TXEMPTY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_TXEMPTY_Msk instead */
#define US_IER_ITER_Pos                     10                                             /**< (US_IER) Max number of Repetitions Reached Interrupt Enable Position */
#define US_IER_ITER_Msk                     (_U_(0x1) << US_IER_ITER_Pos)                  /**< (US_IER) Max number of Repetitions Reached Interrupt Enable Mask */
#define US_IER_ITER                         US_IER_ITER_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_ITER_Msk instead */
#define US_IER_TXBUFE_Pos                   11                                             /**< (US_IER) Transmit Buffer Empty Interrupt Enable (available in all USART modes of operation) Position */
#define US_IER_TXBUFE_Msk                   (_U_(0x1) << US_IER_TXBUFE_Pos)                /**< (US_IER) Transmit Buffer Empty Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IER_TXBUFE                       US_IER_TXBUFE_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_TXBUFE_Msk instead */
#define US_IER_RXBUFF_Pos                   12                                             /**< (US_IER) Receive Buffer Full Interrupt Enable (available in all USART modes of operation) Position */
#define US_IER_RXBUFF_Msk                   (_U_(0x1) << US_IER_RXBUFF_Pos)                /**< (US_IER) Receive Buffer Full Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IER_RXBUFF                       US_IER_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_RXBUFF_Msk instead */
#define US_IER_NACK_Pos                     13                                             /**< (US_IER) Non Acknowledge Interrupt Enable Position */
#define US_IER_NACK_Msk                     (_U_(0x1) << US_IER_NACK_Pos)                  /**< (US_IER) Non Acknowledge Interrupt Enable Mask */
#define US_IER_NACK                         US_IER_NACK_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_NACK_Msk instead */
#define US_IER_CTSIC_Pos                    19                                             /**< (US_IER) Clear to Send Input Change Interrupt Enable Position */
#define US_IER_CTSIC_Msk                    (_U_(0x1) << US_IER_CTSIC_Pos)                 /**< (US_IER) Clear to Send Input Change Interrupt Enable Mask */
#define US_IER_CTSIC                        US_IER_CTSIC_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_CTSIC_Msk instead */
#define US_IER_CMP_Pos                      22                                             /**< (US_IER) Comparison Interrupt Enable Position */
#define US_IER_CMP_Msk                      (_U_(0x1) << US_IER_CMP_Pos)                   /**< (US_IER) Comparison Interrupt Enable Mask */
#define US_IER_CMP                          US_IER_CMP_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IER_CMP_Msk instead */
#define US_IER_MASK                         _U_(0x483FFF)                                  /**< \deprecated (US_IER) Register MASK  (Use US_IER_Msk instead)  */
#define US_IER_Msk                          _U_(0x483FFF)                                  /**< (US_IER) Register Mask  */


/* -------- US_IDR : (USART Offset: 0x0c) (/W 32) Interrupt Disable Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXRDY:1;                   /**< bit:      0  RXRDY Interrupt Disable                  */
    uint32_t TXRDY:1;                   /**< bit:      1  TXRDY Interrupt Disable                  */
    uint32_t RXBRK:1;                   /**< bit:      2  Receiver Break Interrupt Disable         */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Receive Buffer Interrupt Enable (available in all USART modes of operation) */
    uint32_t ENDTX:1;                   /**< bit:      4  End of Transmit Buffer Interrupt Disable (available in all USART modes of operation) */
    uint32_t OVRE:1;                    /**< bit:      5  Overrun Error Interrupt Enable           */
    uint32_t FRAME:1;                   /**< bit:      6  Framing Error Interrupt Disable          */
    uint32_t PARE:1;                    /**< bit:      7  Parity Error Interrupt Disable           */
    uint32_t TIMEOUT:1;                 /**< bit:      8  Time-out Interrupt Disable               */
    uint32_t TXEMPTY:1;                 /**< bit:      9  TXEMPTY Interrupt Disable                */
    uint32_t ITER:1;                    /**< bit:     10  Max Number of Repetitions Reached Interrupt Disable */
    uint32_t TXBUFE:1;                  /**< bit:     11  Transmit Buffer Empty Interrupt Enable (available in all USART modes of operation) */
    uint32_t RXBUFF:1;                  /**< bit:     12  Receive Buffer Full Interrupt Enable (available in all USART modes of operation) */
    uint32_t NACK:1;                    /**< bit:     13  Non Acknowledge Interrupt Disable        */
    uint32_t :5;                        /**< bit: 14..18  Reserved */
    uint32_t CTSIC:1;                   /**< bit:     19  Clear to Send Input Change Interrupt Disable */
    uint32_t :2;                        /**< bit: 20..21  Reserved */
    uint32_t CMP:1;                     /**< bit:     22  Comparison Interrupt Disable             */
    uint32_t :9;                        /**< bit: 23..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_IDR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_IDR_OFFSET                       (0x0C)                                        /**<  (US_IDR) Interrupt Disable Register  Offset */

#define US_IDR_RXRDY_Pos                    0                                              /**< (US_IDR) RXRDY Interrupt Disable Position */
#define US_IDR_RXRDY_Msk                    (_U_(0x1) << US_IDR_RXRDY_Pos)                 /**< (US_IDR) RXRDY Interrupt Disable Mask */
#define US_IDR_RXRDY                        US_IDR_RXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_RXRDY_Msk instead */
#define US_IDR_TXRDY_Pos                    1                                              /**< (US_IDR) TXRDY Interrupt Disable Position */
#define US_IDR_TXRDY_Msk                    (_U_(0x1) << US_IDR_TXRDY_Pos)                 /**< (US_IDR) TXRDY Interrupt Disable Mask */
#define US_IDR_TXRDY                        US_IDR_TXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_TXRDY_Msk instead */
#define US_IDR_RXBRK_Pos                    2                                              /**< (US_IDR) Receiver Break Interrupt Disable Position */
#define US_IDR_RXBRK_Msk                    (_U_(0x1) << US_IDR_RXBRK_Pos)                 /**< (US_IDR) Receiver Break Interrupt Disable Mask */
#define US_IDR_RXBRK                        US_IDR_RXBRK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_RXBRK_Msk instead */
#define US_IDR_ENDRX_Pos                    3                                              /**< (US_IDR) End of Receive Buffer Interrupt Enable (available in all USART modes of operation) Position */
#define US_IDR_ENDRX_Msk                    (_U_(0x1) << US_IDR_ENDRX_Pos)                 /**< (US_IDR) End of Receive Buffer Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IDR_ENDRX                        US_IDR_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_ENDRX_Msk instead */
#define US_IDR_ENDTX_Pos                    4                                              /**< (US_IDR) End of Transmit Buffer Interrupt Disable (available in all USART modes of operation) Position */
#define US_IDR_ENDTX_Msk                    (_U_(0x1) << US_IDR_ENDTX_Pos)                 /**< (US_IDR) End of Transmit Buffer Interrupt Disable (available in all USART modes of operation) Mask */
#define US_IDR_ENDTX                        US_IDR_ENDTX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_ENDTX_Msk instead */
#define US_IDR_OVRE_Pos                     5                                              /**< (US_IDR) Overrun Error Interrupt Enable Position */
#define US_IDR_OVRE_Msk                     (_U_(0x1) << US_IDR_OVRE_Pos)                  /**< (US_IDR) Overrun Error Interrupt Enable Mask */
#define US_IDR_OVRE                         US_IDR_OVRE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_OVRE_Msk instead */
#define US_IDR_FRAME_Pos                    6                                              /**< (US_IDR) Framing Error Interrupt Disable Position */
#define US_IDR_FRAME_Msk                    (_U_(0x1) << US_IDR_FRAME_Pos)                 /**< (US_IDR) Framing Error Interrupt Disable Mask */
#define US_IDR_FRAME                        US_IDR_FRAME_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_FRAME_Msk instead */
#define US_IDR_PARE_Pos                     7                                              /**< (US_IDR) Parity Error Interrupt Disable Position */
#define US_IDR_PARE_Msk                     (_U_(0x1) << US_IDR_PARE_Pos)                  /**< (US_IDR) Parity Error Interrupt Disable Mask */
#define US_IDR_PARE                         US_IDR_PARE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_PARE_Msk instead */
#define US_IDR_TIMEOUT_Pos                  8                                              /**< (US_IDR) Time-out Interrupt Disable Position */
#define US_IDR_TIMEOUT_Msk                  (_U_(0x1) << US_IDR_TIMEOUT_Pos)               /**< (US_IDR) Time-out Interrupt Disable Mask */
#define US_IDR_TIMEOUT                      US_IDR_TIMEOUT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_TIMEOUT_Msk instead */
#define US_IDR_TXEMPTY_Pos                  9                                              /**< (US_IDR) TXEMPTY Interrupt Disable Position */
#define US_IDR_TXEMPTY_Msk                  (_U_(0x1) << US_IDR_TXEMPTY_Pos)               /**< (US_IDR) TXEMPTY Interrupt Disable Mask */
#define US_IDR_TXEMPTY                      US_IDR_TXEMPTY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_TXEMPTY_Msk instead */
#define US_IDR_ITER_Pos                     10                                             /**< (US_IDR) Max Number of Repetitions Reached Interrupt Disable Position */
#define US_IDR_ITER_Msk                     (_U_(0x1) << US_IDR_ITER_Pos)                  /**< (US_IDR) Max Number of Repetitions Reached Interrupt Disable Mask */
#define US_IDR_ITER                         US_IDR_ITER_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_ITER_Msk instead */
#define US_IDR_TXBUFE_Pos                   11                                             /**< (US_IDR) Transmit Buffer Empty Interrupt Enable (available in all USART modes of operation) Position */
#define US_IDR_TXBUFE_Msk                   (_U_(0x1) << US_IDR_TXBUFE_Pos)                /**< (US_IDR) Transmit Buffer Empty Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IDR_TXBUFE                       US_IDR_TXBUFE_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_TXBUFE_Msk instead */
#define US_IDR_RXBUFF_Pos                   12                                             /**< (US_IDR) Receive Buffer Full Interrupt Enable (available in all USART modes of operation) Position */
#define US_IDR_RXBUFF_Msk                   (_U_(0x1) << US_IDR_RXBUFF_Pos)                /**< (US_IDR) Receive Buffer Full Interrupt Enable (available in all USART modes of operation) Mask */
#define US_IDR_RXBUFF                       US_IDR_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_RXBUFF_Msk instead */
#define US_IDR_NACK_Pos                     13                                             /**< (US_IDR) Non Acknowledge Interrupt Disable Position */
#define US_IDR_NACK_Msk                     (_U_(0x1) << US_IDR_NACK_Pos)                  /**< (US_IDR) Non Acknowledge Interrupt Disable Mask */
#define US_IDR_NACK                         US_IDR_NACK_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_NACK_Msk instead */
#define US_IDR_CTSIC_Pos                    19                                             /**< (US_IDR) Clear to Send Input Change Interrupt Disable Position */
#define US_IDR_CTSIC_Msk                    (_U_(0x1) << US_IDR_CTSIC_Pos)                 /**< (US_IDR) Clear to Send Input Change Interrupt Disable Mask */
#define US_IDR_CTSIC                        US_IDR_CTSIC_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_CTSIC_Msk instead */
#define US_IDR_CMP_Pos                      22                                             /**< (US_IDR) Comparison Interrupt Disable Position */
#define US_IDR_CMP_Msk                      (_U_(0x1) << US_IDR_CMP_Pos)                   /**< (US_IDR) Comparison Interrupt Disable Mask */
#define US_IDR_CMP                          US_IDR_CMP_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IDR_CMP_Msk instead */
#define US_IDR_MASK                         _U_(0x483FFF)                                  /**< \deprecated (US_IDR) Register MASK  (Use US_IDR_Msk instead)  */
#define US_IDR_Msk                          _U_(0x483FFF)                                  /**< (US_IDR) Register Mask  */


/* -------- US_IMR : (USART Offset: 0x10) (R/ 32) Interrupt Mask Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXRDY:1;                   /**< bit:      0  RXRDY Interrupt Mask                     */
    uint32_t TXRDY:1;                   /**< bit:      1  TXRDY Interrupt Mask                     */
    uint32_t RXBRK:1;                   /**< bit:      2  Receiver Break Interrupt Mask            */
    uint32_t ENDRX:1;                   /**< bit:      3  End of Receive Buffer Interrupt Mask (available in all USART modes of operation) */
    uint32_t ENDTX:1;                   /**< bit:      4  End of Transmit Buffer Interrupt Mask (available in all USART modes of operation) */
    uint32_t OVRE:1;                    /**< bit:      5  Overrun Error Interrupt Mask             */
    uint32_t FRAME:1;                   /**< bit:      6  Framing Error Interrupt Mask             */
    uint32_t PARE:1;                    /**< bit:      7  Parity Error Interrupt Mask              */
    uint32_t TIMEOUT:1;                 /**< bit:      8  Time-out Interrupt Mask                  */
    uint32_t TXEMPTY:1;                 /**< bit:      9  TXEMPTY Interrupt Mask                   */
    uint32_t ITER:1;                    /**< bit:     10  Max Number of Repetitions Reached Interrupt Mask */
    uint32_t TXBUFE:1;                  /**< bit:     11  Transmit Buffer Empty Interrupt Mask (available in all USART modes of operation) */
    uint32_t RXBUFF:1;                  /**< bit:     12  Receive Buffer Full Interrupt Mask (available in all USART modes of operation) */
    uint32_t NACK:1;                    /**< bit:     13  Non Acknowledge Interrupt Mask           */
    uint32_t :5;                        /**< bit: 14..18  Reserved */
    uint32_t CTSIC:1;                   /**< bit:     19  Clear to Send Input Change Interrupt Mask */
    uint32_t :2;                        /**< bit: 20..21  Reserved */
    uint32_t CMP:1;                     /**< bit:     22  Comparison Interrupt Mask                */
    uint32_t :9;                        /**< bit: 23..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_IMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_IMR_OFFSET                       (0x10)                                        /**<  (US_IMR) Interrupt Mask Register  Offset */

#define US_IMR_RXRDY_Pos                    0                                              /**< (US_IMR) RXRDY Interrupt Mask Position */
#define US_IMR_RXRDY_Msk                    (_U_(0x1) << US_IMR_RXRDY_Pos)                 /**< (US_IMR) RXRDY Interrupt Mask Mask */
#define US_IMR_RXRDY                        US_IMR_RXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_RXRDY_Msk instead */
#define US_IMR_TXRDY_Pos                    1                                              /**< (US_IMR) TXRDY Interrupt Mask Position */
#define US_IMR_TXRDY_Msk                    (_U_(0x1) << US_IMR_TXRDY_Pos)                 /**< (US_IMR) TXRDY Interrupt Mask Mask */
#define US_IMR_TXRDY                        US_IMR_TXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_TXRDY_Msk instead */
#define US_IMR_RXBRK_Pos                    2                                              /**< (US_IMR) Receiver Break Interrupt Mask Position */
#define US_IMR_RXBRK_Msk                    (_U_(0x1) << US_IMR_RXBRK_Pos)                 /**< (US_IMR) Receiver Break Interrupt Mask Mask */
#define US_IMR_RXBRK                        US_IMR_RXBRK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_RXBRK_Msk instead */
#define US_IMR_ENDRX_Pos                    3                                              /**< (US_IMR) End of Receive Buffer Interrupt Mask (available in all USART modes of operation) Position */
#define US_IMR_ENDRX_Msk                    (_U_(0x1) << US_IMR_ENDRX_Pos)                 /**< (US_IMR) End of Receive Buffer Interrupt Mask (available in all USART modes of operation) Mask */
#define US_IMR_ENDRX                        US_IMR_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_ENDRX_Msk instead */
#define US_IMR_ENDTX_Pos                    4                                              /**< (US_IMR) End of Transmit Buffer Interrupt Mask (available in all USART modes of operation) Position */
#define US_IMR_ENDTX_Msk                    (_U_(0x1) << US_IMR_ENDTX_Pos)                 /**< (US_IMR) End of Transmit Buffer Interrupt Mask (available in all USART modes of operation) Mask */
#define US_IMR_ENDTX                        US_IMR_ENDTX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_ENDTX_Msk instead */
#define US_IMR_OVRE_Pos                     5                                              /**< (US_IMR) Overrun Error Interrupt Mask Position */
#define US_IMR_OVRE_Msk                     (_U_(0x1) << US_IMR_OVRE_Pos)                  /**< (US_IMR) Overrun Error Interrupt Mask Mask */
#define US_IMR_OVRE                         US_IMR_OVRE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_OVRE_Msk instead */
#define US_IMR_FRAME_Pos                    6                                              /**< (US_IMR) Framing Error Interrupt Mask Position */
#define US_IMR_FRAME_Msk                    (_U_(0x1) << US_IMR_FRAME_Pos)                 /**< (US_IMR) Framing Error Interrupt Mask Mask */
#define US_IMR_FRAME                        US_IMR_FRAME_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_FRAME_Msk instead */
#define US_IMR_PARE_Pos                     7                                              /**< (US_IMR) Parity Error Interrupt Mask Position */
#define US_IMR_PARE_Msk                     (_U_(0x1) << US_IMR_PARE_Pos)                  /**< (US_IMR) Parity Error Interrupt Mask Mask */
#define US_IMR_PARE                         US_IMR_PARE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_PARE_Msk instead */
#define US_IMR_TIMEOUT_Pos                  8                                              /**< (US_IMR) Time-out Interrupt Mask Position */
#define US_IMR_TIMEOUT_Msk                  (_U_(0x1) << US_IMR_TIMEOUT_Pos)               /**< (US_IMR) Time-out Interrupt Mask Mask */
#define US_IMR_TIMEOUT                      US_IMR_TIMEOUT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_TIMEOUT_Msk instead */
#define US_IMR_TXEMPTY_Pos                  9                                              /**< (US_IMR) TXEMPTY Interrupt Mask Position */
#define US_IMR_TXEMPTY_Msk                  (_U_(0x1) << US_IMR_TXEMPTY_Pos)               /**< (US_IMR) TXEMPTY Interrupt Mask Mask */
#define US_IMR_TXEMPTY                      US_IMR_TXEMPTY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_TXEMPTY_Msk instead */
#define US_IMR_ITER_Pos                     10                                             /**< (US_IMR) Max Number of Repetitions Reached Interrupt Mask Position */
#define US_IMR_ITER_Msk                     (_U_(0x1) << US_IMR_ITER_Pos)                  /**< (US_IMR) Max Number of Repetitions Reached Interrupt Mask Mask */
#define US_IMR_ITER                         US_IMR_ITER_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_ITER_Msk instead */
#define US_IMR_TXBUFE_Pos                   11                                             /**< (US_IMR) Transmit Buffer Empty Interrupt Mask (available in all USART modes of operation) Position */
#define US_IMR_TXBUFE_Msk                   (_U_(0x1) << US_IMR_TXBUFE_Pos)                /**< (US_IMR) Transmit Buffer Empty Interrupt Mask (available in all USART modes of operation) Mask */
#define US_IMR_TXBUFE                       US_IMR_TXBUFE_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_TXBUFE_Msk instead */
#define US_IMR_RXBUFF_Pos                   12                                             /**< (US_IMR) Receive Buffer Full Interrupt Mask (available in all USART modes of operation) Position */
#define US_IMR_RXBUFF_Msk                   (_U_(0x1) << US_IMR_RXBUFF_Pos)                /**< (US_IMR) Receive Buffer Full Interrupt Mask (available in all USART modes of operation) Mask */
#define US_IMR_RXBUFF                       US_IMR_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_RXBUFF_Msk instead */
#define US_IMR_NACK_Pos                     13                                             /**< (US_IMR) Non Acknowledge Interrupt Mask Position */
#define US_IMR_NACK_Msk                     (_U_(0x1) << US_IMR_NACK_Pos)                  /**< (US_IMR) Non Acknowledge Interrupt Mask Mask */
#define US_IMR_NACK                         US_IMR_NACK_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_NACK_Msk instead */
#define US_IMR_CTSIC_Pos                    19                                             /**< (US_IMR) Clear to Send Input Change Interrupt Mask Position */
#define US_IMR_CTSIC_Msk                    (_U_(0x1) << US_IMR_CTSIC_Pos)                 /**< (US_IMR) Clear to Send Input Change Interrupt Mask Mask */
#define US_IMR_CTSIC                        US_IMR_CTSIC_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_CTSIC_Msk instead */
#define US_IMR_CMP_Pos                      22                                             /**< (US_IMR) Comparison Interrupt Mask Position */
#define US_IMR_CMP_Msk                      (_U_(0x1) << US_IMR_CMP_Pos)                   /**< (US_IMR) Comparison Interrupt Mask Mask */
#define US_IMR_CMP                          US_IMR_CMP_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_IMR_CMP_Msk instead */
#define US_IMR_MASK                         _U_(0x483FFF)                                  /**< \deprecated (US_IMR) Register MASK  (Use US_IMR_Msk instead)  */
#define US_IMR_Msk                          _U_(0x483FFF)                                  /**< (US_IMR) Register Mask  */


/* -------- US_CSR : (USART Offset: 0x14) (R/ 32) Channel Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXRDY:1;                   /**< bit:      0  Receiver Ready (cleared by reading US_RHR) */
    uint32_t TXRDY:1;                   /**< bit:      1  Transmitter Ready (cleared by writing US_THR) */
    uint32_t RXBRK:1;                   /**< bit:      2  Break Received/End of Break (cleared by writing a one to the bit US_CR.RSTSTA) */
    uint32_t ENDRX:1;                   /**< bit:      3  End of RX Buffer (cleared by writing US_RCR or US_RNCR) */
    uint32_t ENDTX:1;                   /**< bit:      4  End of TX Buffer (cleared by writing US_TCR or US_TNCR) */
    uint32_t OVRE:1;                    /**< bit:      5  Overrun Error (cleared by writing a one to the bit US_CR.RSTSTA) */
    uint32_t FRAME:1;                   /**< bit:      6  Framing Error (cleared by writing a one to the bit US_CR.RSTSTA) */
    uint32_t PARE:1;                    /**< bit:      7  Parity Error (cleared by writing a one to the US_CR.RSTSTA) */
    uint32_t TIMEOUT:1;                 /**< bit:      8  Receiver Time-out (cleared by writing a one to the bit US_CR.STTTO) */
    uint32_t TXEMPTY:1;                 /**< bit:      9  Transmitter Empty (cleared by writing US_THR) */
    uint32_t ITER:1;                    /**< bit:     10  Max Number of Repetitions Reached (cleared by writing a one to the bit US_CR.RSTIT) */
    uint32_t TXBUFE:1;                  /**< bit:     11  TX Buffer Empty (cleared by writing US_TCR or US_TNCR) */
    uint32_t RXBUFF:1;                  /**< bit:     12  RX Buffer Full (cleared by writing US_RCR or US_RNCR) */
    uint32_t NACK:1;                    /**< bit:     13  Non Acknowledge Interrupt (cleared by writing a one to the bit US_CR.RSTNACK) */
    uint32_t :5;                        /**< bit: 14..18  Reserved */
    uint32_t CTSIC:1;                   /**< bit:     19  Clear to Send Input Change Flag (cleared on read) */
    uint32_t :2;                        /**< bit: 20..21  Reserved */
    uint32_t CMP:1;                     /**< bit:     22  Comparison Status (cleared by writing a one to the bit US_CR.RSTSTA command) */
    uint32_t CTS:1;                     /**< bit:     23  Image of CTS Input                       */
    uint32_t :8;                        /**< bit: 24..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_CSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_CSR_OFFSET                       (0x14)                                        /**<  (US_CSR) Channel Status Register  Offset */

#define US_CSR_RXRDY_Pos                    0                                              /**< (US_CSR) Receiver Ready (cleared by reading US_RHR) Position */
#define US_CSR_RXRDY_Msk                    (_U_(0x1) << US_CSR_RXRDY_Pos)                 /**< (US_CSR) Receiver Ready (cleared by reading US_RHR) Mask */
#define US_CSR_RXRDY                        US_CSR_RXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_RXRDY_Msk instead */
#define US_CSR_TXRDY_Pos                    1                                              /**< (US_CSR) Transmitter Ready (cleared by writing US_THR) Position */
#define US_CSR_TXRDY_Msk                    (_U_(0x1) << US_CSR_TXRDY_Pos)                 /**< (US_CSR) Transmitter Ready (cleared by writing US_THR) Mask */
#define US_CSR_TXRDY                        US_CSR_TXRDY_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_TXRDY_Msk instead */
#define US_CSR_RXBRK_Pos                    2                                              /**< (US_CSR) Break Received/End of Break (cleared by writing a one to the bit US_CR.RSTSTA) Position */
#define US_CSR_RXBRK_Msk                    (_U_(0x1) << US_CSR_RXBRK_Pos)                 /**< (US_CSR) Break Received/End of Break (cleared by writing a one to the bit US_CR.RSTSTA) Mask */
#define US_CSR_RXBRK                        US_CSR_RXBRK_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_RXBRK_Msk instead */
#define US_CSR_ENDRX_Pos                    3                                              /**< (US_CSR) End of RX Buffer (cleared by writing US_RCR or US_RNCR) Position */
#define US_CSR_ENDRX_Msk                    (_U_(0x1) << US_CSR_ENDRX_Pos)                 /**< (US_CSR) End of RX Buffer (cleared by writing US_RCR or US_RNCR) Mask */
#define US_CSR_ENDRX                        US_CSR_ENDRX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_ENDRX_Msk instead */
#define US_CSR_ENDTX_Pos                    4                                              /**< (US_CSR) End of TX Buffer (cleared by writing US_TCR or US_TNCR) Position */
#define US_CSR_ENDTX_Msk                    (_U_(0x1) << US_CSR_ENDTX_Pos)                 /**< (US_CSR) End of TX Buffer (cleared by writing US_TCR or US_TNCR) Mask */
#define US_CSR_ENDTX                        US_CSR_ENDTX_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_ENDTX_Msk instead */
#define US_CSR_OVRE_Pos                     5                                              /**< (US_CSR) Overrun Error (cleared by writing a one to the bit US_CR.RSTSTA) Position */
#define US_CSR_OVRE_Msk                     (_U_(0x1) << US_CSR_OVRE_Pos)                  /**< (US_CSR) Overrun Error (cleared by writing a one to the bit US_CR.RSTSTA) Mask */
#define US_CSR_OVRE                         US_CSR_OVRE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_OVRE_Msk instead */
#define US_CSR_FRAME_Pos                    6                                              /**< (US_CSR) Framing Error (cleared by writing a one to the bit US_CR.RSTSTA) Position */
#define US_CSR_FRAME_Msk                    (_U_(0x1) << US_CSR_FRAME_Pos)                 /**< (US_CSR) Framing Error (cleared by writing a one to the bit US_CR.RSTSTA) Mask */
#define US_CSR_FRAME                        US_CSR_FRAME_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_FRAME_Msk instead */
#define US_CSR_PARE_Pos                     7                                              /**< (US_CSR) Parity Error (cleared by writing a one to the US_CR.RSTSTA) Position */
#define US_CSR_PARE_Msk                     (_U_(0x1) << US_CSR_PARE_Pos)                  /**< (US_CSR) Parity Error (cleared by writing a one to the US_CR.RSTSTA) Mask */
#define US_CSR_PARE                         US_CSR_PARE_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_PARE_Msk instead */
#define US_CSR_TIMEOUT_Pos                  8                                              /**< (US_CSR) Receiver Time-out (cleared by writing a one to the bit US_CR.STTTO) Position */
#define US_CSR_TIMEOUT_Msk                  (_U_(0x1) << US_CSR_TIMEOUT_Pos)               /**< (US_CSR) Receiver Time-out (cleared by writing a one to the bit US_CR.STTTO) Mask */
#define US_CSR_TIMEOUT                      US_CSR_TIMEOUT_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_TIMEOUT_Msk instead */
#define US_CSR_TXEMPTY_Pos                  9                                              /**< (US_CSR) Transmitter Empty (cleared by writing US_THR) Position */
#define US_CSR_TXEMPTY_Msk                  (_U_(0x1) << US_CSR_TXEMPTY_Pos)               /**< (US_CSR) Transmitter Empty (cleared by writing US_THR) Mask */
#define US_CSR_TXEMPTY                      US_CSR_TXEMPTY_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_TXEMPTY_Msk instead */
#define US_CSR_ITER_Pos                     10                                             /**< (US_CSR) Max Number of Repetitions Reached (cleared by writing a one to the bit US_CR.RSTIT) Position */
#define US_CSR_ITER_Msk                     (_U_(0x1) << US_CSR_ITER_Pos)                  /**< (US_CSR) Max Number of Repetitions Reached (cleared by writing a one to the bit US_CR.RSTIT) Mask */
#define US_CSR_ITER                         US_CSR_ITER_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_ITER_Msk instead */
#define US_CSR_TXBUFE_Pos                   11                                             /**< (US_CSR) TX Buffer Empty (cleared by writing US_TCR or US_TNCR) Position */
#define US_CSR_TXBUFE_Msk                   (_U_(0x1) << US_CSR_TXBUFE_Pos)                /**< (US_CSR) TX Buffer Empty (cleared by writing US_TCR or US_TNCR) Mask */
#define US_CSR_TXBUFE                       US_CSR_TXBUFE_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_TXBUFE_Msk instead */
#define US_CSR_RXBUFF_Pos                   12                                             /**< (US_CSR) RX Buffer Full (cleared by writing US_RCR or US_RNCR) Position */
#define US_CSR_RXBUFF_Msk                   (_U_(0x1) << US_CSR_RXBUFF_Pos)                /**< (US_CSR) RX Buffer Full (cleared by writing US_RCR or US_RNCR) Mask */
#define US_CSR_RXBUFF                       US_CSR_RXBUFF_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_RXBUFF_Msk instead */
#define US_CSR_NACK_Pos                     13                                             /**< (US_CSR) Non Acknowledge Interrupt (cleared by writing a one to the bit US_CR.RSTNACK) Position */
#define US_CSR_NACK_Msk                     (_U_(0x1) << US_CSR_NACK_Pos)                  /**< (US_CSR) Non Acknowledge Interrupt (cleared by writing a one to the bit US_CR.RSTNACK) Mask */
#define US_CSR_NACK                         US_CSR_NACK_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_NACK_Msk instead */
#define US_CSR_CTSIC_Pos                    19                                             /**< (US_CSR) Clear to Send Input Change Flag (cleared on read) Position */
#define US_CSR_CTSIC_Msk                    (_U_(0x1) << US_CSR_CTSIC_Pos)                 /**< (US_CSR) Clear to Send Input Change Flag (cleared on read) Mask */
#define US_CSR_CTSIC                        US_CSR_CTSIC_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_CTSIC_Msk instead */
#define US_CSR_CMP_Pos                      22                                             /**< (US_CSR) Comparison Status (cleared by writing a one to the bit US_CR.RSTSTA command) Position */
#define US_CSR_CMP_Msk                      (_U_(0x1) << US_CSR_CMP_Pos)                   /**< (US_CSR) Comparison Status (cleared by writing a one to the bit US_CR.RSTSTA command) Mask */
#define US_CSR_CMP                          US_CSR_CMP_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_CMP_Msk instead */
#define US_CSR_CTS_Pos                      23                                             /**< (US_CSR) Image of CTS Input Position */
#define US_CSR_CTS_Msk                      (_U_(0x1) << US_CSR_CTS_Pos)                   /**< (US_CSR) Image of CTS Input Mask */
#define US_CSR_CTS                          US_CSR_CTS_Msk                                 /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CSR_CTS_Msk instead */
#define US_CSR_MASK                         _U_(0xC83FFF)                                  /**< \deprecated (US_CSR) Register MASK  (Use US_CSR_Msk instead)  */
#define US_CSR_Msk                          _U_(0xC83FFF)                                  /**< (US_CSR) Register Mask  */


/* -------- US_RHR : (USART Offset: 0x18) (R/ 32) Receive Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCHR:9;                   /**< bit:   0..8  Received Character                       */
    uint32_t :6;                        /**< bit:  9..14  Reserved */
    uint32_t RXSYNH:1;                  /**< bit:     15  Received Sync                            */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_RHR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_RHR_OFFSET                       (0x18)                                        /**<  (US_RHR) Receive Holding Register  Offset */

#define US_RHR_RXCHR_Pos                    0                                              /**< (US_RHR) Received Character Position */
#define US_RHR_RXCHR_Msk                    (_U_(0x1FF) << US_RHR_RXCHR_Pos)               /**< (US_RHR) Received Character Mask */
#define US_RHR_RXCHR(value)                 (US_RHR_RXCHR_Msk & ((value) << US_RHR_RXCHR_Pos))
#define US_RHR_RXSYNH_Pos                   15                                             /**< (US_RHR) Received Sync Position */
#define US_RHR_RXSYNH_Msk                   (_U_(0x1) << US_RHR_RXSYNH_Pos)                /**< (US_RHR) Received Sync Mask */
#define US_RHR_RXSYNH                       US_RHR_RXSYNH_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_RHR_RXSYNH_Msk instead */
#define US_RHR_MASK                         _U_(0x81FF)                                    /**< \deprecated (US_RHR) Register MASK  (Use US_RHR_Msk instead)  */
#define US_RHR_Msk                          _U_(0x81FF)                                    /**< (US_RHR) Register Mask  */


/* -------- US_THR : (USART Offset: 0x1c) (/W 32) Transmit Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCHR:9;                   /**< bit:   0..8  Character to be Transmitted              */
    uint32_t :6;                        /**< bit:  9..14  Reserved */
    uint32_t TXSYNH:1;                  /**< bit:     15  Sync Field to be Transmitted             */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_THR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_THR_OFFSET                       (0x1C)                                        /**<  (US_THR) Transmit Holding Register  Offset */

#define US_THR_TXCHR_Pos                    0                                              /**< (US_THR) Character to be Transmitted Position */
#define US_THR_TXCHR_Msk                    (_U_(0x1FF) << US_THR_TXCHR_Pos)               /**< (US_THR) Character to be Transmitted Mask */
#define US_THR_TXCHR(value)                 (US_THR_TXCHR_Msk & ((value) << US_THR_TXCHR_Pos))
#define US_THR_TXSYNH_Pos                   15                                             /**< (US_THR) Sync Field to be Transmitted Position */
#define US_THR_TXSYNH_Msk                   (_U_(0x1) << US_THR_TXSYNH_Pos)                /**< (US_THR) Sync Field to be Transmitted Mask */
#define US_THR_TXSYNH                       US_THR_TXSYNH_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_THR_TXSYNH_Msk instead */
#define US_THR_MASK                         _U_(0x81FF)                                    /**< \deprecated (US_THR) Register MASK  (Use US_THR_Msk instead)  */
#define US_THR_Msk                          _U_(0x81FF)                                    /**< (US_THR) Register Mask  */


/* -------- US_BRGR : (USART Offset: 0x20) (R/W 32) Baud Rate Generator Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t CD:16;                     /**< bit:  0..15  Clock Divider                            */
    uint32_t FP:3;                      /**< bit: 16..18  Fractional Part                          */
    uint32_t :13;                       /**< bit: 19..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_BRGR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_BRGR_OFFSET                      (0x20)                                        /**<  (US_BRGR) Baud Rate Generator Register  Offset */

#define US_BRGR_CD_Pos                      0                                              /**< (US_BRGR) Clock Divider Position */
#define US_BRGR_CD_Msk                      (_U_(0xFFFF) << US_BRGR_CD_Pos)                /**< (US_BRGR) Clock Divider Mask */
#define US_BRGR_CD(value)                   (US_BRGR_CD_Msk & ((value) << US_BRGR_CD_Pos))
#define US_BRGR_FP_Pos                      16                                             /**< (US_BRGR) Fractional Part Position */
#define US_BRGR_FP_Msk                      (_U_(0x7) << US_BRGR_FP_Pos)                   /**< (US_BRGR) Fractional Part Mask */
#define US_BRGR_FP(value)                   (US_BRGR_FP_Msk & ((value) << US_BRGR_FP_Pos))
#define US_BRGR_MASK                        _U_(0x7FFFF)                                   /**< \deprecated (US_BRGR) Register MASK  (Use US_BRGR_Msk instead)  */
#define US_BRGR_Msk                         _U_(0x7FFFF)                                   /**< (US_BRGR) Register Mask  */


/* -------- US_RTOR : (USART Offset: 0x24) (R/W 32) Receiver Time-out Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TO:17;                     /**< bit:  0..16  Time-out Value                           */
    uint32_t :15;                       /**< bit: 17..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_RTOR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_RTOR_OFFSET                      (0x24)                                        /**<  (US_RTOR) Receiver Time-out Register  Offset */

#define US_RTOR_TO_Pos                      0                                              /**< (US_RTOR) Time-out Value Position */
#define US_RTOR_TO_Msk                      (_U_(0x1FFFF) << US_RTOR_TO_Pos)               /**< (US_RTOR) Time-out Value Mask */
#define US_RTOR_TO(value)                   (US_RTOR_TO_Msk & ((value) << US_RTOR_TO_Pos))
#define US_RTOR_MASK                        _U_(0x1FFFF)                                   /**< \deprecated (US_RTOR) Register MASK  (Use US_RTOR_Msk instead)  */
#define US_RTOR_Msk                         _U_(0x1FFFF)                                   /**< (US_RTOR) Register Mask  */


/* -------- US_TTGR : (USART Offset: 0x28) (R/W 32) Transmitter Timeguard Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TG:8;                      /**< bit:   0..7  Timeguard Value                          */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_TTGR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_TTGR_OFFSET                      (0x28)                                        /**<  (US_TTGR) Transmitter Timeguard Register  Offset */

#define US_TTGR_TG_Pos                      0                                              /**< (US_TTGR) Timeguard Value Position */
#define US_TTGR_TG_Msk                      (_U_(0xFF) << US_TTGR_TG_Pos)                  /**< (US_TTGR) Timeguard Value Mask */
#define US_TTGR_TG(value)                   (US_TTGR_TG_Msk & ((value) << US_TTGR_TG_Pos))
#define US_TTGR_MASK                        _U_(0xFF)                                      /**< \deprecated (US_TTGR) Register MASK  (Use US_TTGR_Msk instead)  */
#define US_TTGR_Msk                         _U_(0xFF)                                      /**< (US_TTGR) Register Mask  */


/* -------- US_FIDI : (USART Offset: 0x40) (R/W 32) FI DI Ratio Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t FI_DI_RATIO:16;            /**< bit:  0..15  FI Over DI Ratio Value                   */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_FIDI_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_FIDI_OFFSET                      (0x40)                                        /**<  (US_FIDI) FI DI Ratio Register  Offset */

#define US_FIDI_FI_DI_RATIO_Pos             0                                              /**< (US_FIDI) FI Over DI Ratio Value Position */
#define US_FIDI_FI_DI_RATIO_Msk             (_U_(0xFFFF) << US_FIDI_FI_DI_RATIO_Pos)       /**< (US_FIDI) FI Over DI Ratio Value Mask */
#define US_FIDI_FI_DI_RATIO(value)          (US_FIDI_FI_DI_RATIO_Msk & ((value) << US_FIDI_FI_DI_RATIO_Pos))
#define US_FIDI_MASK                        _U_(0xFFFF)                                    /**< \deprecated (US_FIDI) Register MASK  (Use US_FIDI_Msk instead)  */
#define US_FIDI_Msk                         _U_(0xFFFF)                                    /**< (US_FIDI) Register Mask  */


/* -------- US_NER : (USART Offset: 0x44) (R/ 32) Number of Errors Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t NB_ERRORS:8;               /**< bit:   0..7  Number of Errors                         */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_NER_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_NER_OFFSET                       (0x44)                                        /**<  (US_NER) Number of Errors Register  Offset */

#define US_NER_NB_ERRORS_Pos                0                                              /**< (US_NER) Number of Errors Position */
#define US_NER_NB_ERRORS_Msk                (_U_(0xFF) << US_NER_NB_ERRORS_Pos)            /**< (US_NER) Number of Errors Mask */
#define US_NER_NB_ERRORS(value)             (US_NER_NB_ERRORS_Msk & ((value) << US_NER_NB_ERRORS_Pos))
#define US_NER_MASK                         _U_(0xFF)                                      /**< \deprecated (US_NER) Register MASK  (Use US_NER_Msk instead)  */
#define US_NER_Msk                          _U_(0xFF)                                      /**< (US_NER) Register Mask  */


/* -------- US_IF : (USART Offset: 0x4c) (R/W 32) IrDA Filter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t IRDA_FILTER:8;             /**< bit:   0..7  IrDA Filter                              */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_IF_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_IF_OFFSET                        (0x4C)                                        /**<  (US_IF) IrDA Filter Register  Offset */

#define US_IF_IRDA_FILTER_Pos               0                                              /**< (US_IF) IrDA Filter Position */
#define US_IF_IRDA_FILTER_Msk               (_U_(0xFF) << US_IF_IRDA_FILTER_Pos)           /**< (US_IF) IrDA Filter Mask */
#define US_IF_IRDA_FILTER(value)            (US_IF_IRDA_FILTER_Msk & ((value) << US_IF_IRDA_FILTER_Pos))
#define US_IF_MASK                          _U_(0xFF)                                      /**< \deprecated (US_IF) Register MASK  (Use US_IF_Msk instead)  */
#define US_IF_Msk                           _U_(0xFF)                                      /**< (US_IF) Register Mask  */


/* -------- US_LINMR : (USART Offset: 0x54) (R/W 32) LIN Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t NACT:2;                    /**< bit:   0..1  LIN Node Action                          */
    uint32_t PARDIS:1;                  /**< bit:      2  Parity Disable                           */
    uint32_t CHKDIS:1;                  /**< bit:      3  Checksum Disable                         */
    uint32_t CHKTYP:1;                  /**< bit:      4  Checksum Type                            */
    uint32_t DLM:1;                     /**< bit:      5  Data Length Mode                         */
    uint32_t FSDIS:1;                   /**< bit:      6  Frame Slot Mode Disable                  */
    uint32_t WKUPTYP:1;                 /**< bit:      7  Wakeup Signal Type                       */
    uint32_t DLC:8;                     /**< bit:  8..15  Data Length Control                      */
    uint32_t PDCM:1;                    /**< bit:     16  PDC Mode                                 */
    uint32_t SYNCDIS:1;                 /**< bit:     17  Synchronization Disable                  */
    uint32_t :14;                       /**< bit: 18..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_LINMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_LINMR_OFFSET                     (0x54)                                        /**<  (US_LINMR) LIN Mode Register  Offset */

#define US_LINMR_NACT_Pos                   0                                              /**< (US_LINMR) LIN Node Action Position */
#define US_LINMR_NACT_Msk                   (_U_(0x3) << US_LINMR_NACT_Pos)                /**< (US_LINMR) LIN Node Action Mask */
#define US_LINMR_NACT(value)                (US_LINMR_NACT_Msk & ((value) << US_LINMR_NACT_Pos))
#define   US_LINMR_NACT_PUBLISH_Val         _U_(0x0)                                       /**< (US_LINMR) The USART transmits the response.  */
#define   US_LINMR_NACT_SUBSCRIBE_Val       _U_(0x1)                                       /**< (US_LINMR) The USART receives the response.  */
#define   US_LINMR_NACT_IGNORE_Val          _U_(0x2)                                       /**< (US_LINMR) The USART does not transmit and does not receive the response.  */
#define US_LINMR_NACT_PUBLISH               (US_LINMR_NACT_PUBLISH_Val << US_LINMR_NACT_Pos)  /**< (US_LINMR) The USART transmits the response. Position  */
#define US_LINMR_NACT_SUBSCRIBE             (US_LINMR_NACT_SUBSCRIBE_Val << US_LINMR_NACT_Pos)  /**< (US_LINMR) The USART receives the response. Position  */
#define US_LINMR_NACT_IGNORE                (US_LINMR_NACT_IGNORE_Val << US_LINMR_NACT_Pos)  /**< (US_LINMR) The USART does not transmit and does not receive the response. Position  */
#define US_LINMR_PARDIS_Pos                 2                                              /**< (US_LINMR) Parity Disable Position */
#define US_LINMR_PARDIS_Msk                 (_U_(0x1) << US_LINMR_PARDIS_Pos)              /**< (US_LINMR) Parity Disable Mask */
#define US_LINMR_PARDIS                     US_LINMR_PARDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_PARDIS_Msk instead */
#define US_LINMR_CHKDIS_Pos                 3                                              /**< (US_LINMR) Checksum Disable Position */
#define US_LINMR_CHKDIS_Msk                 (_U_(0x1) << US_LINMR_CHKDIS_Pos)              /**< (US_LINMR) Checksum Disable Mask */
#define US_LINMR_CHKDIS                     US_LINMR_CHKDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_CHKDIS_Msk instead */
#define US_LINMR_CHKTYP_Pos                 4                                              /**< (US_LINMR) Checksum Type Position */
#define US_LINMR_CHKTYP_Msk                 (_U_(0x1) << US_LINMR_CHKTYP_Pos)              /**< (US_LINMR) Checksum Type Mask */
#define US_LINMR_CHKTYP                     US_LINMR_CHKTYP_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_CHKTYP_Msk instead */
#define US_LINMR_DLM_Pos                    5                                              /**< (US_LINMR) Data Length Mode Position */
#define US_LINMR_DLM_Msk                    (_U_(0x1) << US_LINMR_DLM_Pos)                 /**< (US_LINMR) Data Length Mode Mask */
#define US_LINMR_DLM                        US_LINMR_DLM_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_DLM_Msk instead */
#define US_LINMR_FSDIS_Pos                  6                                              /**< (US_LINMR) Frame Slot Mode Disable Position */
#define US_LINMR_FSDIS_Msk                  (_U_(0x1) << US_LINMR_FSDIS_Pos)               /**< (US_LINMR) Frame Slot Mode Disable Mask */
#define US_LINMR_FSDIS                      US_LINMR_FSDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_FSDIS_Msk instead */
#define US_LINMR_WKUPTYP_Pos                7                                              /**< (US_LINMR) Wakeup Signal Type Position */
#define US_LINMR_WKUPTYP_Msk                (_U_(0x1) << US_LINMR_WKUPTYP_Pos)             /**< (US_LINMR) Wakeup Signal Type Mask */
#define US_LINMR_WKUPTYP                    US_LINMR_WKUPTYP_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_WKUPTYP_Msk instead */
#define US_LINMR_DLC_Pos                    8                                              /**< (US_LINMR) Data Length Control Position */
#define US_LINMR_DLC_Msk                    (_U_(0xFF) << US_LINMR_DLC_Pos)                /**< (US_LINMR) Data Length Control Mask */
#define US_LINMR_DLC(value)                 (US_LINMR_DLC_Msk & ((value) << US_LINMR_DLC_Pos))
#define US_LINMR_PDCM_Pos                   16                                             /**< (US_LINMR) PDC Mode Position */
#define US_LINMR_PDCM_Msk                   (_U_(0x1) << US_LINMR_PDCM_Pos)                /**< (US_LINMR) PDC Mode Mask */
#define US_LINMR_PDCM                       US_LINMR_PDCM_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_PDCM_Msk instead */
#define US_LINMR_SYNCDIS_Pos                17                                             /**< (US_LINMR) Synchronization Disable Position */
#define US_LINMR_SYNCDIS_Msk                (_U_(0x1) << US_LINMR_SYNCDIS_Pos)             /**< (US_LINMR) Synchronization Disable Mask */
#define US_LINMR_SYNCDIS                    US_LINMR_SYNCDIS_Msk                           /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_LINMR_SYNCDIS_Msk instead */
#define US_LINMR_MASK                       _U_(0x3FFFF)                                   /**< \deprecated (US_LINMR) Register MASK  (Use US_LINMR_Msk instead)  */
#define US_LINMR_Msk                        _U_(0x3FFFF)                                   /**< (US_LINMR) Register Mask  */


/* -------- US_LINIR : (USART Offset: 0x58) (R/W 32) LIN Identifier Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t IDCHR:8;                   /**< bit:   0..7  Identifier Character                     */
    uint32_t :24;                       /**< bit:  8..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_LINIR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_LINIR_OFFSET                     (0x58)                                        /**<  (US_LINIR) LIN Identifier Register  Offset */

#define US_LINIR_IDCHR_Pos                  0                                              /**< (US_LINIR) Identifier Character Position */
#define US_LINIR_IDCHR_Msk                  (_U_(0xFF) << US_LINIR_IDCHR_Pos)              /**< (US_LINIR) Identifier Character Mask */
#define US_LINIR_IDCHR(value)               (US_LINIR_IDCHR_Msk & ((value) << US_LINIR_IDCHR_Pos))
#define US_LINIR_MASK                       _U_(0xFF)                                      /**< \deprecated (US_LINIR) Register MASK  (Use US_LINIR_Msk instead)  */
#define US_LINIR_Msk                        _U_(0xFF)                                      /**< (US_LINIR) Register Mask  */


/* -------- US_LINBRR : (USART Offset: 0x5c) (R/ 32) LIN Baud Rate Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t LINCD:16;                  /**< bit:  0..15  Clock Divider after Synchronization      */
    uint32_t LINFP:3;                   /**< bit: 16..18  Fractional Part after Synchronization    */
    uint32_t :13;                       /**< bit: 19..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_LINBRR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_LINBRR_OFFSET                    (0x5C)                                        /**<  (US_LINBRR) LIN Baud Rate Register  Offset */

#define US_LINBRR_LINCD_Pos                 0                                              /**< (US_LINBRR) Clock Divider after Synchronization Position */
#define US_LINBRR_LINCD_Msk                 (_U_(0xFFFF) << US_LINBRR_LINCD_Pos)           /**< (US_LINBRR) Clock Divider after Synchronization Mask */
#define US_LINBRR_LINCD(value)              (US_LINBRR_LINCD_Msk & ((value) << US_LINBRR_LINCD_Pos))
#define US_LINBRR_LINFP_Pos                 16                                             /**< (US_LINBRR) Fractional Part after Synchronization Position */
#define US_LINBRR_LINFP_Msk                 (_U_(0x7) << US_LINBRR_LINFP_Pos)              /**< (US_LINBRR) Fractional Part after Synchronization Mask */
#define US_LINBRR_LINFP(value)              (US_LINBRR_LINFP_Msk & ((value) << US_LINBRR_LINFP_Pos))
#define US_LINBRR_MASK                      _U_(0x7FFFF)                                   /**< \deprecated (US_LINBRR) Register MASK  (Use US_LINBRR_Msk instead)  */
#define US_LINBRR_Msk                       _U_(0x7FFFF)                                   /**< (US_LINBRR) Register Mask  */


/* -------- US_CMPR : (USART Offset: 0x90) (R/W 32) Comparison Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t VAL1:9;                    /**< bit:   0..8  First Comparison Value for Received Character */
    uint32_t :3;                        /**< bit:  9..11  Reserved */
    uint32_t CMPMODE:1;                 /**< bit:     12  Comparison Mode                          */
    uint32_t :1;                        /**< bit:     13  Reserved */
    uint32_t CMPPAR:1;                  /**< bit:     14  Compare Parity                           */
    uint32_t :1;                        /**< bit:     15  Reserved */
    uint32_t VAL2:9;                    /**< bit: 16..24  Second Comparison Value for Received Character */
    uint32_t :7;                        /**< bit: 25..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_CMPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_CMPR_OFFSET                      (0x90)                                        /**<  (US_CMPR) Comparison Register  Offset */

#define US_CMPR_VAL1_Pos                    0                                              /**< (US_CMPR) First Comparison Value for Received Character Position */
#define US_CMPR_VAL1_Msk                    (_U_(0x1FF) << US_CMPR_VAL1_Pos)               /**< (US_CMPR) First Comparison Value for Received Character Mask */
#define US_CMPR_VAL1(value)                 (US_CMPR_VAL1_Msk & ((value) << US_CMPR_VAL1_Pos))
#define US_CMPR_CMPMODE_Pos                 12                                             /**< (US_CMPR) Comparison Mode Position */
#define US_CMPR_CMPMODE_Msk                 (_U_(0x1) << US_CMPR_CMPMODE_Pos)              /**< (US_CMPR) Comparison Mode Mask */
#define US_CMPR_CMPMODE                     US_CMPR_CMPMODE_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CMPR_CMPMODE_Msk instead */
#define   US_CMPR_CMPMODE_FLAG_ONLY_Val     _U_(0x0)                                       /**< (US_CMPR) Any character is received and comparison function drives CMP flag.  */
#define   US_CMPR_CMPMODE_START_CONDITION_Val _U_(0x1)                                       /**< (US_CMPR) Comparison condition must be met to start reception of all incoming charactersuntil REQCLR is set.  */
#define US_CMPR_CMPMODE_FLAG_ONLY           (US_CMPR_CMPMODE_FLAG_ONLY_Val << US_CMPR_CMPMODE_Pos)  /**< (US_CMPR) Any character is received and comparison function drives CMP flag. Position  */
#define US_CMPR_CMPMODE_START_CONDITION     (US_CMPR_CMPMODE_START_CONDITION_Val << US_CMPR_CMPMODE_Pos)  /**< (US_CMPR) Comparison condition must be met to start reception of all incoming charactersuntil REQCLR is set. Position  */
#define US_CMPR_CMPPAR_Pos                  14                                             /**< (US_CMPR) Compare Parity Position */
#define US_CMPR_CMPPAR_Msk                  (_U_(0x1) << US_CMPR_CMPPAR_Pos)               /**< (US_CMPR) Compare Parity Mask */
#define US_CMPR_CMPPAR                      US_CMPR_CMPPAR_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_CMPR_CMPPAR_Msk instead */
#define US_CMPR_VAL2_Pos                    16                                             /**< (US_CMPR) Second Comparison Value for Received Character Position */
#define US_CMPR_VAL2_Msk                    (_U_(0x1FF) << US_CMPR_VAL2_Pos)               /**< (US_CMPR) Second Comparison Value for Received Character Mask */
#define US_CMPR_VAL2(value)                 (US_CMPR_VAL2_Msk & ((value) << US_CMPR_VAL2_Pos))
#define US_CMPR_MASK                        _U_(0x1FF51FF)                                 /**< \deprecated (US_CMPR) Register MASK  (Use US_CMPR_Msk instead)  */
#define US_CMPR_Msk                         _U_(0x1FF51FF)                                 /**< (US_CMPR) Register Mask  */


/* -------- US_WPMR : (USART Offset: 0xe4) (R/W 32) Write Protection Mode Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPEN:1;                    /**< bit:      0  Write Protection Enable                  */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPKEY:24;                  /**< bit:  8..31  Write Protection Key                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_WPMR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_WPMR_OFFSET                      (0xE4)                                        /**<  (US_WPMR) Write Protection Mode Register  Offset */

#define US_WPMR_WPEN_Pos                    0                                              /**< (US_WPMR) Write Protection Enable Position */
#define US_WPMR_WPEN_Msk                    (_U_(0x1) << US_WPMR_WPEN_Pos)                 /**< (US_WPMR) Write Protection Enable Mask */
#define US_WPMR_WPEN                        US_WPMR_WPEN_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_WPMR_WPEN_Msk instead */
#define US_WPMR_WPKEY_Pos                   8                                              /**< (US_WPMR) Write Protection Key Position */
#define US_WPMR_WPKEY_Msk                   (_U_(0xFFFFFF) << US_WPMR_WPKEY_Pos)           /**< (US_WPMR) Write Protection Key Mask */
#define US_WPMR_WPKEY(value)                (US_WPMR_WPKEY_Msk & ((value) << US_WPMR_WPKEY_Pos))
#define   US_WPMR_WPKEY_PASSWD_Val          _U_(0x555341)                                  /**< (US_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define US_WPMR_WPKEY_PASSWD                (US_WPMR_WPKEY_PASSWD_Val << US_WPMR_WPKEY_Pos)  /**< (US_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define US_WPMR_MASK                        _U_(0xFFFFFF01)                                /**< \deprecated (US_WPMR) Register MASK  (Use US_WPMR_Msk instead)  */
#define US_WPMR_Msk                         _U_(0xFFFFFF01)                                /**< (US_WPMR) Register Mask  */


/* -------- US_WPSR : (USART Offset: 0xe8) (R/ 32) Write Protection Status Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t WPVS:1;                    /**< bit:      0  Write Protection Violation Status        */
    uint32_t :7;                        /**< bit:   1..7  Reserved */
    uint32_t WPVSRC:16;                 /**< bit:  8..23  Write Protection Violation Source        */
    uint32_t :8;                        /**< bit: 24..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_WPSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_WPSR_OFFSET                      (0xE8)                                        /**<  (US_WPSR) Write Protection Status Register  Offset */

#define US_WPSR_WPVS_Pos                    0                                              /**< (US_WPSR) Write Protection Violation Status Position */
#define US_WPSR_WPVS_Msk                    (_U_(0x1) << US_WPSR_WPVS_Pos)                 /**< (US_WPSR) Write Protection Violation Status Mask */
#define US_WPSR_WPVS                        US_WPSR_WPVS_Msk                               /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_WPSR_WPVS_Msk instead */
#define US_WPSR_WPVSRC_Pos                  8                                              /**< (US_WPSR) Write Protection Violation Source Position */
#define US_WPSR_WPVSRC_Msk                  (_U_(0xFFFF) << US_WPSR_WPVSRC_Pos)            /**< (US_WPSR) Write Protection Violation Source Mask */
#define US_WPSR_WPVSRC(value)               (US_WPSR_WPVSRC_Msk & ((value) << US_WPSR_WPVSRC_Pos))
#define US_WPSR_MASK                        _U_(0xFFFF01)                                  /**< \deprecated (US_WPSR) Register MASK  (Use US_WPSR_Msk instead)  */
#define US_WPSR_Msk                         _U_(0xFFFF01)                                  /**< (US_WPSR) Register Mask  */


/* -------- US_RPR : (USART Offset: 0x100) (R/W 32) Receive Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXPTR:32;                  /**< bit:  0..31  Receive Pointer Register                 */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_RPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_RPR_OFFSET                       (0x100)                                       /**<  (US_RPR) Receive Pointer Register  Offset */

#define US_RPR_RXPTR_Pos                    0                                              /**< (US_RPR) Receive Pointer Register Position */
#define US_RPR_RXPTR_Msk                    (_U_(0xFFFFFFFF) << US_RPR_RXPTR_Pos)          /**< (US_RPR) Receive Pointer Register Mask */
#define US_RPR_RXPTR(value)                 (US_RPR_RXPTR_Msk & ((value) << US_RPR_RXPTR_Pos))
#define US_RPR_MASK                         _U_(0xFFFFFFFF)                                /**< \deprecated (US_RPR) Register MASK  (Use US_RPR_Msk instead)  */
#define US_RPR_Msk                          _U_(0xFFFFFFFF)                                /**< (US_RPR) Register Mask  */


/* -------- US_RCR : (USART Offset: 0x104) (R/W 32) Receive Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXCTR:16;                  /**< bit:  0..15  Receive Counter Register                 */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_RCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_RCR_OFFSET                       (0x104)                                       /**<  (US_RCR) Receive Counter Register  Offset */

#define US_RCR_RXCTR_Pos                    0                                              /**< (US_RCR) Receive Counter Register Position */
#define US_RCR_RXCTR_Msk                    (_U_(0xFFFF) << US_RCR_RXCTR_Pos)              /**< (US_RCR) Receive Counter Register Mask */
#define US_RCR_RXCTR(value)                 (US_RCR_RXCTR_Msk & ((value) << US_RCR_RXCTR_Pos))
#define US_RCR_MASK                         _U_(0xFFFF)                                    /**< \deprecated (US_RCR) Register MASK  (Use US_RCR_Msk instead)  */
#define US_RCR_Msk                          _U_(0xFFFF)                                    /**< (US_RCR) Register Mask  */


/* -------- US_TPR : (USART Offset: 0x108) (R/W 32) Transmit Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXPTR:32;                  /**< bit:  0..31  Transmit Counter Register                */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_TPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_TPR_OFFSET                       (0x108)                                       /**<  (US_TPR) Transmit Pointer Register  Offset */

#define US_TPR_TXPTR_Pos                    0                                              /**< (US_TPR) Transmit Counter Register Position */
#define US_TPR_TXPTR_Msk                    (_U_(0xFFFFFFFF) << US_TPR_TXPTR_Pos)          /**< (US_TPR) Transmit Counter Register Mask */
#define US_TPR_TXPTR(value)                 (US_TPR_TXPTR_Msk & ((value) << US_TPR_TXPTR_Pos))
#define US_TPR_MASK                         _U_(0xFFFFFFFF)                                /**< \deprecated (US_TPR) Register MASK  (Use US_TPR_Msk instead)  */
#define US_TPR_Msk                          _U_(0xFFFFFFFF)                                /**< (US_TPR) Register Mask  */


/* -------- US_TCR : (USART Offset: 0x10c) (R/W 32) Transmit Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXCTR:16;                  /**< bit:  0..15  Transmit Counter Register                */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_TCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_TCR_OFFSET                       (0x10C)                                       /**<  (US_TCR) Transmit Counter Register  Offset */

#define US_TCR_TXCTR_Pos                    0                                              /**< (US_TCR) Transmit Counter Register Position */
#define US_TCR_TXCTR_Msk                    (_U_(0xFFFF) << US_TCR_TXCTR_Pos)              /**< (US_TCR) Transmit Counter Register Mask */
#define US_TCR_TXCTR(value)                 (US_TCR_TXCTR_Msk & ((value) << US_TCR_TXCTR_Pos))
#define US_TCR_MASK                         _U_(0xFFFF)                                    /**< \deprecated (US_TCR) Register MASK  (Use US_TCR_Msk instead)  */
#define US_TCR_Msk                          _U_(0xFFFF)                                    /**< (US_TCR) Register Mask  */


/* -------- US_RNPR : (USART Offset: 0x110) (R/W 32) Receive Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNPTR:32;                 /**< bit:  0..31  Receive Next Pointer                     */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_RNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_RNPR_OFFSET                      (0x110)                                       /**<  (US_RNPR) Receive Next Pointer Register  Offset */

#define US_RNPR_RXNPTR_Pos                  0                                              /**< (US_RNPR) Receive Next Pointer Position */
#define US_RNPR_RXNPTR_Msk                  (_U_(0xFFFFFFFF) << US_RNPR_RXNPTR_Pos)        /**< (US_RNPR) Receive Next Pointer Mask */
#define US_RNPR_RXNPTR(value)               (US_RNPR_RXNPTR_Msk & ((value) << US_RNPR_RXNPTR_Pos))
#define US_RNPR_MASK                        _U_(0xFFFFFFFF)                                /**< \deprecated (US_RNPR) Register MASK  (Use US_RNPR_Msk instead)  */
#define US_RNPR_Msk                         _U_(0xFFFFFFFF)                                /**< (US_RNPR) Register Mask  */


/* -------- US_RNCR : (USART Offset: 0x114) (R/W 32) Receive Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXNCTR:16;                 /**< bit:  0..15  Receive Next Counter                     */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_RNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_RNCR_OFFSET                      (0x114)                                       /**<  (US_RNCR) Receive Next Counter Register  Offset */

#define US_RNCR_RXNCTR_Pos                  0                                              /**< (US_RNCR) Receive Next Counter Position */
#define US_RNCR_RXNCTR_Msk                  (_U_(0xFFFF) << US_RNCR_RXNCTR_Pos)            /**< (US_RNCR) Receive Next Counter Mask */
#define US_RNCR_RXNCTR(value)               (US_RNCR_RXNCTR_Msk & ((value) << US_RNCR_RXNCTR_Pos))
#define US_RNCR_MASK                        _U_(0xFFFF)                                    /**< \deprecated (US_RNCR) Register MASK  (Use US_RNCR_Msk instead)  */
#define US_RNCR_Msk                         _U_(0xFFFF)                                    /**< (US_RNCR) Register Mask  */


/* -------- US_TNPR : (USART Offset: 0x118) (R/W 32) Transmit Next Pointer Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNPTR:32;                 /**< bit:  0..31  Transmit Next Pointer                    */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_TNPR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_TNPR_OFFSET                      (0x118)                                       /**<  (US_TNPR) Transmit Next Pointer Register  Offset */

#define US_TNPR_TXNPTR_Pos                  0                                              /**< (US_TNPR) Transmit Next Pointer Position */
#define US_TNPR_TXNPTR_Msk                  (_U_(0xFFFFFFFF) << US_TNPR_TXNPTR_Pos)        /**< (US_TNPR) Transmit Next Pointer Mask */
#define US_TNPR_TXNPTR(value)               (US_TNPR_TXNPTR_Msk & ((value) << US_TNPR_TXNPTR_Pos))
#define US_TNPR_MASK                        _U_(0xFFFFFFFF)                                /**< \deprecated (US_TNPR) Register MASK  (Use US_TNPR_Msk instead)  */
#define US_TNPR_Msk                         _U_(0xFFFFFFFF)                                /**< (US_TNPR) Register Mask  */


/* -------- US_TNCR : (USART Offset: 0x11c) (R/W 32) Transmit Next Counter Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXNCTR:16;                 /**< bit:  0..15  Transmit Counter Next                    */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} US_TNCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_TNCR_OFFSET                      (0x11C)                                       /**<  (US_TNCR) Transmit Next Counter Register  Offset */

#define US_TNCR_TXNCTR_Pos                  0                                              /**< (US_TNCR) Transmit Counter Next Position */
#define US_TNCR_TXNCTR_Msk                  (_U_(0xFFFF) << US_TNCR_TXNCTR_Pos)            /**< (US_TNCR) Transmit Counter Next Mask */
#define US_TNCR_TXNCTR(value)               (US_TNCR_TXNCTR_Msk & ((value) << US_TNCR_TXNCTR_Pos))
#define US_TNCR_MASK                        _U_(0xFFFF)                                    /**< \deprecated (US_TNCR) Register MASK  (Use US_TNCR_Msk instead)  */
#define US_TNCR_Msk                         _U_(0xFFFF)                                    /**< (US_TNCR) Register Mask  */


/* -------- US_PTCR : (USART Offset: 0x120) (/W 32) Transfer Control Register -------- */
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
} US_PTCR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_PTCR_OFFSET                      (0x120)                                       /**<  (US_PTCR) Transfer Control Register  Offset */

#define US_PTCR_RXTEN_Pos                   0                                              /**< (US_PTCR) Receiver Transfer Enable Position */
#define US_PTCR_RXTEN_Msk                   (_U_(0x1) << US_PTCR_RXTEN_Pos)                /**< (US_PTCR) Receiver Transfer Enable Mask */
#define US_PTCR_RXTEN                       US_PTCR_RXTEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_RXTEN_Msk instead */
#define US_PTCR_RXTDIS_Pos                  1                                              /**< (US_PTCR) Receiver Transfer Disable Position */
#define US_PTCR_RXTDIS_Msk                  (_U_(0x1) << US_PTCR_RXTDIS_Pos)               /**< (US_PTCR) Receiver Transfer Disable Mask */
#define US_PTCR_RXTDIS                      US_PTCR_RXTDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_RXTDIS_Msk instead */
#define US_PTCR_TXTEN_Pos                   8                                              /**< (US_PTCR) Transmitter Transfer Enable Position */
#define US_PTCR_TXTEN_Msk                   (_U_(0x1) << US_PTCR_TXTEN_Pos)                /**< (US_PTCR) Transmitter Transfer Enable Mask */
#define US_PTCR_TXTEN                       US_PTCR_TXTEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_TXTEN_Msk instead */
#define US_PTCR_TXTDIS_Pos                  9                                              /**< (US_PTCR) Transmitter Transfer Disable Position */
#define US_PTCR_TXTDIS_Msk                  (_U_(0x1) << US_PTCR_TXTDIS_Pos)               /**< (US_PTCR) Transmitter Transfer Disable Mask */
#define US_PTCR_TXTDIS                      US_PTCR_TXTDIS_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_TXTDIS_Msk instead */
#define US_PTCR_RXCBEN_Pos                  16                                             /**< (US_PTCR) Receiver Circular Buffer Enable Position */
#define US_PTCR_RXCBEN_Msk                  (_U_(0x1) << US_PTCR_RXCBEN_Pos)               /**< (US_PTCR) Receiver Circular Buffer Enable Mask */
#define US_PTCR_RXCBEN                      US_PTCR_RXCBEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_RXCBEN_Msk instead */
#define US_PTCR_RXCBDIS_Pos                 17                                             /**< (US_PTCR) Receiver Circular Buffer Disable Position */
#define US_PTCR_RXCBDIS_Msk                 (_U_(0x1) << US_PTCR_RXCBDIS_Pos)              /**< (US_PTCR) Receiver Circular Buffer Disable Mask */
#define US_PTCR_RXCBDIS                     US_PTCR_RXCBDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_RXCBDIS_Msk instead */
#define US_PTCR_TXCBEN_Pos                  18                                             /**< (US_PTCR) Transmitter Circular Buffer Enable Position */
#define US_PTCR_TXCBEN_Msk                  (_U_(0x1) << US_PTCR_TXCBEN_Pos)               /**< (US_PTCR) Transmitter Circular Buffer Enable Mask */
#define US_PTCR_TXCBEN                      US_PTCR_TXCBEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_TXCBEN_Msk instead */
#define US_PTCR_TXCBDIS_Pos                 19                                             /**< (US_PTCR) Transmitter Circular Buffer Disable Position */
#define US_PTCR_TXCBDIS_Msk                 (_U_(0x1) << US_PTCR_TXCBDIS_Pos)              /**< (US_PTCR) Transmitter Circular Buffer Disable Mask */
#define US_PTCR_TXCBDIS                     US_PTCR_TXCBDIS_Msk                            /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_TXCBDIS_Msk instead */
#define US_PTCR_ERRCLR_Pos                  24                                             /**< (US_PTCR) Transfer Bus Error Clear Position */
#define US_PTCR_ERRCLR_Msk                  (_U_(0x1) << US_PTCR_ERRCLR_Pos)               /**< (US_PTCR) Transfer Bus Error Clear Mask */
#define US_PTCR_ERRCLR                      US_PTCR_ERRCLR_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTCR_ERRCLR_Msk instead */
#define US_PTCR_MASK                        _U_(0x10F0303)                                 /**< \deprecated (US_PTCR) Register MASK  (Use US_PTCR_Msk instead)  */
#define US_PTCR_Msk                         _U_(0x10F0303)                                 /**< (US_PTCR) Register Mask  */


/* -------- US_PTSR : (USART Offset: 0x124) (R/ 32) Transfer Status Register -------- */
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
} US_PTSR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define US_PTSR_OFFSET                      (0x124)                                       /**<  (US_PTSR) Transfer Status Register  Offset */

#define US_PTSR_RXTEN_Pos                   0                                              /**< (US_PTSR) Receiver Transfer Enable Position */
#define US_PTSR_RXTEN_Msk                   (_U_(0x1) << US_PTSR_RXTEN_Pos)                /**< (US_PTSR) Receiver Transfer Enable Mask */
#define US_PTSR_RXTEN                       US_PTSR_RXTEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTSR_RXTEN_Msk instead */
#define US_PTSR_TXTEN_Pos                   8                                              /**< (US_PTSR) Transmitter Transfer Enable Position */
#define US_PTSR_TXTEN_Msk                   (_U_(0x1) << US_PTSR_TXTEN_Pos)                /**< (US_PTSR) Transmitter Transfer Enable Mask */
#define US_PTSR_TXTEN                       US_PTSR_TXTEN_Msk                              /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTSR_TXTEN_Msk instead */
#define US_PTSR_RXCBEN_Pos                  16                                             /**< (US_PTSR) Receiver Circular Buffer Enable Position */
#define US_PTSR_RXCBEN_Msk                  (_U_(0x1) << US_PTSR_RXCBEN_Pos)               /**< (US_PTSR) Receiver Circular Buffer Enable Mask */
#define US_PTSR_RXCBEN                      US_PTSR_RXCBEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTSR_RXCBEN_Msk instead */
#define US_PTSR_TXCBEN_Pos                  18                                             /**< (US_PTSR) Transmitter Circular Buffer Enable Position */
#define US_PTSR_TXCBEN_Msk                  (_U_(0x1) << US_PTSR_TXCBEN_Pos)               /**< (US_PTSR) Transmitter Circular Buffer Enable Mask */
#define US_PTSR_TXCBEN                      US_PTSR_TXCBEN_Msk                             /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTSR_TXCBEN_Msk instead */
#define US_PTSR_ERR_Pos                     24                                             /**< (US_PTSR) Transfer Bus Error Position */
#define US_PTSR_ERR_Msk                     (_U_(0x1) << US_PTSR_ERR_Pos)                  /**< (US_PTSR) Transfer Bus Error Mask */
#define US_PTSR_ERR                         US_PTSR_ERR_Msk                                /**< \deprecated Old style mask definition for 1 bit bitfield. Use US_PTSR_ERR_Msk instead */
#define US_PTSR_MASK                        _U_(0x1050101)                                 /**< \deprecated (US_PTSR) Register MASK  (Use US_PTSR_Msk instead)  */
#define US_PTSR_Msk                         _U_(0x1050101)                                 /**< (US_PTSR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief USART hardware registers */
typedef struct {  
  __O  uint32_t US_CR;          /**< (USART Offset: 0x00) Control Register */
  __IO uint32_t US_MR;          /**< (USART Offset: 0x04) Mode Register */
  __O  uint32_t US_IER;         /**< (USART Offset: 0x08) Interrupt Enable Register */
  __O  uint32_t US_IDR;         /**< (USART Offset: 0x0C) Interrupt Disable Register */
  __I  uint32_t US_IMR;         /**< (USART Offset: 0x10) Interrupt Mask Register */
  __I  uint32_t US_CSR;         /**< (USART Offset: 0x14) Channel Status Register */
  __I  uint32_t US_RHR;         /**< (USART Offset: 0x18) Receive Holding Register */
  __O  uint32_t US_THR;         /**< (USART Offset: 0x1C) Transmit Holding Register */
  __IO uint32_t US_BRGR;        /**< (USART Offset: 0x20) Baud Rate Generator Register */
  __IO uint32_t US_RTOR;        /**< (USART Offset: 0x24) Receiver Time-out Register */
  __IO uint32_t US_TTGR;        /**< (USART Offset: 0x28) Transmitter Timeguard Register */
  RoReg8  Reserved1[0x14];
  __IO uint32_t US_FIDI;        /**< (USART Offset: 0x40) FI DI Ratio Register */
  __I  uint32_t US_NER;         /**< (USART Offset: 0x44) Number of Errors Register */
  RoReg8  Reserved2[0x4];
  __IO uint32_t US_IF;          /**< (USART Offset: 0x4C) IrDA Filter Register */
  RoReg8  Reserved3[0x4];
  __IO uint32_t US_LINMR;       /**< (USART Offset: 0x54) LIN Mode Register */
  __IO uint32_t US_LINIR;       /**< (USART Offset: 0x58) LIN Identifier Register */
  __I  uint32_t US_LINBRR;      /**< (USART Offset: 0x5C) LIN Baud Rate Register */
  RoReg8  Reserved4[0x30];
  __IO uint32_t US_CMPR;        /**< (USART Offset: 0x90) Comparison Register */
  RoReg8  Reserved5[0x50];
  __IO uint32_t US_WPMR;        /**< (USART Offset: 0xE4) Write Protection Mode Register */
  __I  uint32_t US_WPSR;        /**< (USART Offset: 0xE8) Write Protection Status Register */
  RoReg8  Reserved6[0x14];
  __IO uint32_t US_RPR;         /**< (USART Offset: 0x100) Receive Pointer Register */
  __IO uint32_t US_RCR;         /**< (USART Offset: 0x104) Receive Counter Register */
  __IO uint32_t US_TPR;         /**< (USART Offset: 0x108) Transmit Pointer Register */
  __IO uint32_t US_TCR;         /**< (USART Offset: 0x10C) Transmit Counter Register */
  __IO uint32_t US_RNPR;        /**< (USART Offset: 0x110) Receive Next Pointer Register */
  __IO uint32_t US_RNCR;        /**< (USART Offset: 0x114) Receive Next Counter Register */
  __IO uint32_t US_TNPR;        /**< (USART Offset: 0x118) Transmit Next Pointer Register */
  __IO uint32_t US_TNCR;        /**< (USART Offset: 0x11C) Transmit Next Counter Register */
  __O  uint32_t US_PTCR;        /**< (USART Offset: 0x120) Transfer Control Register */
  __I  uint32_t US_PTSR;        /**< (USART Offset: 0x124) Transfer Status Register */
} Usart;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief USART hardware registers */
typedef struct {  
  __O  US_CR_Type                     US_CR;          /**< Offset: 0x00 ( /W  32) Control Register */
  __IO US_MR_Type                     US_MR;          /**< Offset: 0x04 (R/W  32) Mode Register */
  __O  US_IER_Type                    US_IER;         /**< Offset: 0x08 ( /W  32) Interrupt Enable Register */
  __O  US_IDR_Type                    US_IDR;         /**< Offset: 0x0C ( /W  32) Interrupt Disable Register */
  __I  US_IMR_Type                    US_IMR;         /**< Offset: 0x10 (R/   32) Interrupt Mask Register */
  __I  US_CSR_Type                    US_CSR;         /**< Offset: 0x14 (R/   32) Channel Status Register */
  __I  US_RHR_Type                    US_RHR;         /**< Offset: 0x18 (R/   32) Receive Holding Register */
  __O  US_THR_Type                    US_THR;         /**< Offset: 0x1C ( /W  32) Transmit Holding Register */
  __IO US_BRGR_Type                   US_BRGR;        /**< Offset: 0x20 (R/W  32) Baud Rate Generator Register */
  __IO US_RTOR_Type                   US_RTOR;        /**< Offset: 0x24 (R/W  32) Receiver Time-out Register */
  __IO US_TTGR_Type                   US_TTGR;        /**< Offset: 0x28 (R/W  32) Transmitter Timeguard Register */
  __I  uint32_t                       Reserved1[5];
  __IO US_FIDI_Type                   US_FIDI;        /**< Offset: 0x40 (R/W  32) FI DI Ratio Register */
  __I  US_NER_Type                    US_NER;         /**< Offset: 0x44 (R/   32) Number of Errors Register */
  __I  uint32_t                       Reserved2[1];
  __IO US_IF_Type                     US_IF;          /**< Offset: 0x4C (R/W  32) IrDA Filter Register */
  __I  uint32_t                       Reserved3[1];
  __IO US_LINMR_Type                  US_LINMR;       /**< Offset: 0x54 (R/W  32) LIN Mode Register */
  __IO US_LINIR_Type                  US_LINIR;       /**< Offset: 0x58 (R/W  32) LIN Identifier Register */
  __I  US_LINBRR_Type                 US_LINBRR;      /**< Offset: 0x5C (R/   32) LIN Baud Rate Register */
  __I  uint32_t                       Reserved4[12];
  __IO US_CMPR_Type                   US_CMPR;        /**< Offset: 0x90 (R/W  32) Comparison Register */
  __I  uint32_t                       Reserved5[20];
  __IO US_WPMR_Type                   US_WPMR;        /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I  US_WPSR_Type                   US_WPSR;        /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
  __I  uint32_t                       Reserved6[5];
  __IO US_RPR_Type                    US_RPR;         /**< Offset: 0x100 (R/W  32) Receive Pointer Register */
  __IO US_RCR_Type                    US_RCR;         /**< Offset: 0x104 (R/W  32) Receive Counter Register */
  __IO US_TPR_Type                    US_TPR;         /**< Offset: 0x108 (R/W  32) Transmit Pointer Register */
  __IO US_TCR_Type                    US_TCR;         /**< Offset: 0x10C (R/W  32) Transmit Counter Register */
  __IO US_RNPR_Type                   US_RNPR;        /**< Offset: 0x110 (R/W  32) Receive Next Pointer Register */
  __IO US_RNCR_Type                   US_RNCR;        /**< Offset: 0x114 (R/W  32) Receive Next Counter Register */
  __IO US_TNPR_Type                   US_TNPR;        /**< Offset: 0x118 (R/W  32) Transmit Next Pointer Register */
  __IO US_TNCR_Type                   US_TNCR;        /**< Offset: 0x11C (R/W  32) Transmit Next Counter Register */
  __O  US_PTCR_Type                   US_PTCR;        /**< Offset: 0x120 ( /W  32) Transfer Control Register */
  __I  US_PTSR_Type                   US_PTSR;        /**< Offset: 0x124 (R/   32) Transfer Status Register */
} Usart;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Universal Synchronous Asynchronous Receiver Transmitter */

#endif /* _SAMG55_USART_COMPONENT_H_ */
