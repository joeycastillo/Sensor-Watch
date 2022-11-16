/**
 * \file
 *
 * \brief Component description for FLEXCOM
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
#ifndef _SAMG55_FLEXCOM_COMPONENT_H_
#define _SAMG55_FLEXCOM_COMPONENT_H_
#define _SAMG55_FLEXCOM_COMPONENT_         /**< \deprecated  Backward compatibility for ASF */

/** \addtogroup SAMG_SAMG55 Flexible Serial Communication
 *  @{
 */
/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR FLEXCOM */
/* ========================================================================== */
#ifndef COMPONENT_TYPEDEF_STYLE
  #define COMPONENT_TYPEDEF_STYLE 'R'  /**< Defines default style of typedefs for the component header files ('R' = RFO, 'N' = NTO)*/
#endif

#define FLEXCOM_11277                      /**< (FLEXCOM) Module ID */
#define REV_FLEXCOM A                      /**< (FLEXCOM) Module revision */

/* -------- FLEXCOM_MR : (FLEXCOM Offset: 0x00) (R/W 32) FLEXCOM Mode register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t OPMODE:2;                  /**< bit:   0..1  FLEXCOM Operating Mode                   */
    uint32_t :30;                       /**< bit:  2..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} FLEXCOM_MR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define FLEXCOM_MR_OFFSET                   (0x00)                                        /**<  (FLEXCOM_MR) FLEXCOM Mode register  Offset */

#define FLEXCOM_MR_OPMODE_Pos               0                                              /**< (FLEXCOM_MR) FLEXCOM Operating Mode Position */
#define FLEXCOM_MR_OPMODE_Msk               (_U_(0x3) << FLEXCOM_MR_OPMODE_Pos)            /**< (FLEXCOM_MR) FLEXCOM Operating Mode Mask */
#define FLEXCOM_MR_OPMODE(value)            (FLEXCOM_MR_OPMODE_Msk & ((value) << FLEXCOM_MR_OPMODE_Pos))
#define   FLEXCOM_MR_OPMODE_NO_COM_Val      _U_(0x0)                                       /**< (FLEXCOM_MR) No communication  */
#define   FLEXCOM_MR_OPMODE_USART_Val       _U_(0x1)                                       /**< (FLEXCOM_MR) All related USART related protocols are selected (RS232, RS485, IrDA, ISO7816, LIN,)All SPI/TWI related registers are not accessible and have no impact on IOs.  */
#define   FLEXCOM_MR_OPMODE_SPI_Val         _U_(0x2)                                       /**< (FLEXCOM_MR) SPI operating mode is selected.All USART/TWI related registers are not accessible and have no impact on IOs.  */
#define   FLEXCOM_MR_OPMODE_TWI_Val         _U_(0x3)                                       /**< (FLEXCOM_MR) All related TWI protocols are selected (TWI, SMBUS). All USART/SPI related registers are not accessible and have no impact on IOs.  */
#define FLEXCOM_MR_OPMODE_NO_COM            (FLEXCOM_MR_OPMODE_NO_COM_Val << FLEXCOM_MR_OPMODE_Pos)  /**< (FLEXCOM_MR) No communication Position  */
#define FLEXCOM_MR_OPMODE_USART             (FLEXCOM_MR_OPMODE_USART_Val << FLEXCOM_MR_OPMODE_Pos)  /**< (FLEXCOM_MR) All related USART related protocols are selected (RS232, RS485, IrDA, ISO7816, LIN,)All SPI/TWI related registers are not accessible and have no impact on IOs. Position  */
#define FLEXCOM_MR_OPMODE_SPI               (FLEXCOM_MR_OPMODE_SPI_Val << FLEXCOM_MR_OPMODE_Pos)  /**< (FLEXCOM_MR) SPI operating mode is selected.All USART/TWI related registers are not accessible and have no impact on IOs. Position  */
#define FLEXCOM_MR_OPMODE_TWI               (FLEXCOM_MR_OPMODE_TWI_Val << FLEXCOM_MR_OPMODE_Pos)  /**< (FLEXCOM_MR) All related TWI protocols are selected (TWI, SMBUS). All USART/SPI related registers are not accessible and have no impact on IOs. Position  */
#define FLEXCOM_MR_MASK                     _U_(0x03)                                      /**< \deprecated (FLEXCOM_MR) Register MASK  (Use FLEXCOM_MR_Msk instead)  */
#define FLEXCOM_MR_Msk                      _U_(0x03)                                      /**< (FLEXCOM_MR) Register Mask  */


/* -------- FLEXCOM_RHR : (FLEXCOM Offset: 0x10) (R/ 32) FLEXCOM Receive Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t RXDATA:16;                 /**< bit:  0..15  Receive Data                             */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} FLEXCOM_RHR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define FLEXCOM_RHR_OFFSET                  (0x10)                                        /**<  (FLEXCOM_RHR) FLEXCOM Receive Holding Register  Offset */

#define FLEXCOM_RHR_RXDATA_Pos              0                                              /**< (FLEXCOM_RHR) Receive Data Position */
#define FLEXCOM_RHR_RXDATA_Msk              (_U_(0xFFFF) << FLEXCOM_RHR_RXDATA_Pos)        /**< (FLEXCOM_RHR) Receive Data Mask */
#define FLEXCOM_RHR_RXDATA(value)           (FLEXCOM_RHR_RXDATA_Msk & ((value) << FLEXCOM_RHR_RXDATA_Pos))
#define FLEXCOM_RHR_MASK                    _U_(0xFFFF)                                    /**< \deprecated (FLEXCOM_RHR) Register MASK  (Use FLEXCOM_RHR_Msk instead)  */
#define FLEXCOM_RHR_Msk                     _U_(0xFFFF)                                    /**< (FLEXCOM_RHR) Register Mask  */


/* -------- FLEXCOM_THR : (FLEXCOM Offset: 0x20) (R/W 32) FLEXCOM Transmit Holding Register -------- */
#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
typedef union { 
  struct {
    uint32_t TXDATA:16;                 /**< bit:  0..15  Transmit Data                            */
    uint32_t :16;                       /**< bit: 16..31  Reserved */
  } bit;                                /**< Structure used for bit  access */
  uint32_t reg;                         /**< Type used for register access */
} FLEXCOM_THR_Type;
#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */

#define FLEXCOM_THR_OFFSET                  (0x20)                                        /**<  (FLEXCOM_THR) FLEXCOM Transmit Holding Register  Offset */

#define FLEXCOM_THR_TXDATA_Pos              0                                              /**< (FLEXCOM_THR) Transmit Data Position */
#define FLEXCOM_THR_TXDATA_Msk              (_U_(0xFFFF) << FLEXCOM_THR_TXDATA_Pos)        /**< (FLEXCOM_THR) Transmit Data Mask */
#define FLEXCOM_THR_TXDATA(value)           (FLEXCOM_THR_TXDATA_Msk & ((value) << FLEXCOM_THR_TXDATA_Pos))
#define FLEXCOM_THR_MASK                    _U_(0xFFFF)                                    /**< \deprecated (FLEXCOM_THR) Register MASK  (Use FLEXCOM_THR_Msk instead)  */
#define FLEXCOM_THR_Msk                     _U_(0xFFFF)                                    /**< (FLEXCOM_THR) Register Mask  */


#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#if COMPONENT_TYPEDEF_STYLE == 'R'
/** \brief FLEXCOM hardware registers */
typedef struct {  
  __IO uint32_t FLEXCOM_MR;     /**< (FLEXCOM Offset: 0x00) FLEXCOM Mode register */
  RoReg8  Reserved1[0xC];
  __I  uint32_t FLEXCOM_RHR;    /**< (FLEXCOM Offset: 0x10) FLEXCOM Receive Holding Register */
  RoReg8  Reserved2[0xC];
  __IO uint32_t FLEXCOM_THR;    /**< (FLEXCOM Offset: 0x20) FLEXCOM Transmit Holding Register */
} Flexcom;

#elif COMPONENT_TYPEDEF_STYLE == 'N'
/** \brief FLEXCOM hardware registers */
typedef struct {  
  __IO FLEXCOM_MR_Type                FLEXCOM_MR;     /**< Offset: 0x00 (R/W  32) FLEXCOM Mode register */
  __I  uint32_t                       Reserved1[3];
  __I  FLEXCOM_RHR_Type               FLEXCOM_RHR;    /**< Offset: 0x10 (R/   32) FLEXCOM Receive Holding Register */
  __I  uint32_t                       Reserved2[3];
  __IO FLEXCOM_THR_Type               FLEXCOM_THR;    /**< Offset: 0x20 (R/W  32) FLEXCOM Transmit Holding Register */
} Flexcom;

#else /* COMPONENT_TYPEDEF_STYLE */
#error Unknown component typedef style
#endif /* COMPONENT_TYPEDEF_STYLE */

#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
/** @}  end of Flexible Serial Communication */

#endif /* _SAMG55_FLEXCOM_COMPONENT_H_ */
