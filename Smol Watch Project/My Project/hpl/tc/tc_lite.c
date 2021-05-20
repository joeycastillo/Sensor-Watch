
/**
 * \file
 *
 * \brief TC related functionality implementation.
 *
 * Copyright (c) 2017 Microchip Technology Inc. and its subsidiaries.
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

#include "tc_lite.h"

/**
 * \brief Initialize TC interface
 */
int8_t PWM_0_init()
{

	if (!hri_tc_is_syncing(TC3, TC_SYNCBUSY_SWRST)) {
		if (hri_tc_get_CTRLA_reg(TC3, TC_CTRLA_ENABLE)) {
			hri_tc_clear_CTRLA_ENABLE_bit(TC3);
			hri_tc_wait_for_sync(TC3, TC_SYNCBUSY_ENABLE);
		}
		hri_tc_write_CTRLA_reg(TC3, TC_CTRLA_SWRST);
	}
	hri_tc_wait_for_sync(TC3, TC_SYNCBUSY_SWRST);

	hri_tc_write_CTRLA_reg(TC3,
	                       0 << TC_CTRLA_COPEN0_Pos          /* Capture Pin 0 Enable: disabled */
	                           | 0 << TC_CTRLA_COPEN1_Pos    /* Capture Pin 1 Enable: disabled */
	                           | 0 << TC_CTRLA_CAPTEN0_Pos   /* Capture Channel 0 Enable: disabled */
	                           | 0 << TC_CTRLA_CAPTEN1_Pos   /* Capture Channel 1 Enable: disabled */
	                           | 0 << TC_CTRLA_ALOCK_Pos     /* Auto Lock: disabled */
	                           | 0 << TC_CTRLA_PRESCSYNC_Pos /* Prescaler and Counter Synchronization: 0 */
	                           | 0 << TC_CTRLA_ONDEMAND_Pos  /* Clock On Demand: disabled */
	                           | 0 << TC_CTRLA_RUNSTDBY_Pos  /* Run in Standby: disabled */
	                           | 0 << TC_CTRLA_PRESCALER_Pos /* Setting: 0 */
	                           | 0x1 << TC_CTRLA_MODE_Pos);  /* Operating Mode: 0x1 */

	hri_tc_write_CTRLB_reg(TC3,
	                       0 << TC_CTRLBSET_CMD_Pos           /* Command: 0 */
	                           | 0 << TC_CTRLBSET_ONESHOT_Pos /* One-Shot: disabled */
	                           | 0 << TC_CTRLBCLR_LUPD_Pos    /* Setting: disabled */
	                           | 0 << TC_CTRLBSET_DIR_Pos);   /* Counter Direction: disabled */

	// hri_tc_write_WAVE_reg(TC3,0); /* Waveform Generation Mode: 0 */

	// hri_tc_write_DRVCTRL_reg(TC3,0 << TC_DRVCTRL_INVEN1_Pos /* Output Waveform 1 Invert Enable: disabled */
	//		 | 0 << TC_DRVCTRL_INVEN0_Pos); /* Output Waveform 0 Invert Enable: disabled */

	// hri_tc_write_DBGCTRL_reg(TC3,0); /* Run in debug: 0 */

	// hri_tccount8_write_CC_reg(TC3, 0 ,0x0); /* Compare/Capture Value: 0x0 */

	// hri_tccount8_write_CC_reg(TC3, 1 ,0x0); /* Compare/Capture Value: 0x0 */

	// hri_tccount8_write_COUNT_reg(TC3,0x0); /* Counter Value: 0x0 */

	// hri_tc_write_PER_reg(TC3,0x0); /*  Period Value: 0x0 */

	// hri_tc_write_EVCTRL_reg(TC3,0 << TC_EVCTRL_MCEO0_Pos /* Match or Capture Channel 0 Event Output Enable: disabled
	// */
	//		 | 0 << TC_EVCTRL_MCEO1_Pos /* Match or Capture Channel 1 Event Output Enable: disabled */
	//		 | 0 << TC_EVCTRL_OVFEO_Pos /* Overflow/Underflow Event Output Enable: disabled */
	//		 | 0 << TC_EVCTRL_TCEI_Pos /* TC Event Input: disabled */
	//		 | 0 << TC_EVCTRL_TCINV_Pos /* TC Inverted Event Input: disabled */
	//		 | 0); /* Event Action: 0 */

	// hri_tc_write_INTEN_reg(TC3,0 << TC_INTENSET_MC0_Pos /* Match or Capture Channel 0 Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_MC1_Pos /* Match or Capture Channel 1 Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_ERR_Pos /* Error Interrupt Enable: disabled */
	//		 | 0 << TC_INTENSET_OVF_Pos); /* Overflow Interrupt enable: disabled */

	hri_tc_write_CTRLA_ENABLE_bit(TC3, 1 << TC_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}
