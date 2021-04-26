/**
 * \file
 *
 * \brief SLCD Character Mapping declaration.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef HPL_SLCD_CM_H_INCLUDED
#define HPL_SLCD_CM_H_INCLUDED

#include <stdint.h>

/* Character Mapping Struct */
struct slcd_char_mapping {
	uint32_t character : 8; /*!< ASCII character */
	uint32_t mapping : 24;  /*!< Mapping value */
};

/* SLCD Character settting Struct */
struct slcd_char_setting {
	uint8_t com_index; /*!< Common terminal index, start from 0 */
	uint8_t seg_index; /*!< Segment terminal index, start from 0 */
	uint8_t nseg;      /*!< Number of Segment, this field is used to
	                        indentify which segments line will be
	                        used. For example, if char mapping from
	                        COM1/SEG2 and nseg=2,size=7, then
	                        COM1/SEG2, COM1/SEG3, COM2/SEG2,
	                        COM2/SEG3, COM3/SEG2, COM3/SEG3,
	                        COM4/SEG2 will be used for mapping
	                        */
	uint8_t size;      /*!< char size, typical is 7/14/16 */
};
#endif /* HPL_SLCD_CM_H_INCLUDED */
