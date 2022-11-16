
/**
 * \file
 *
 * \brief RTC Driver
 *
 * Copyright (C) 2014 - 2018 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include <hpl_calendar.h>
#include <utils_assert.h>
#include <hpl_rtc_config.h>

/*!< Pointer to hpl device */
static struct calendar_dev *_rtc_dev = NULL;

/**
 * \brief Initializes the RTC module with given configurations.
 */
int32_t _calendar_init(struct calendar_dev *const dev)
{
	ASSERT(dev && dev->hw);

	_rtc_dev = dev;

	hri_rtcmode0_wait_for_sync(dev->hw, RTC_MODE0_SYNCBUSY_SWRST);
	if (hri_rtcmode0_get_CTRLA_ENABLE_bit(dev->hw)) {
#if !CONF_RTC_INIT_RESET
		return ERR_DENIED;
#else
		hri_rtcmode0_clear_CTRLA_ENABLE_bit(dev->hw);
		hri_rtcmode0_wait_for_sync(dev->hw, RTC_MODE0_SYNCBUSY_ENABLE);
#endif
	}
	hri_rtcmode0_set_CTRLA_SWRST_bit(dev->hw);
	hri_rtcmode0_wait_for_sync(dev->hw, RTC_MODE0_SYNCBUSY_SWRST);

#if CONF_RTC_EVENT_CONTROL_ENABLE == 1
	hri_rtcmode0_write_EVCTRL_reg(dev->hw,
	                              (CONF_RTC_PEREO0 << RTC_MODE0_EVCTRL_PEREO0_Pos)
	                                  | (CONF_RTC_PEREO1 << RTC_MODE0_EVCTRL_PEREO1_Pos)
	                                  | (CONF_RTC_PEREO2 << RTC_MODE0_EVCTRL_PEREO2_Pos)
	                                  | (CONF_RTC_PEREO3 << RTC_MODE0_EVCTRL_PEREO3_Pos)
	                                  | (CONF_RTC_PEREO4 << RTC_MODE0_EVCTRL_PEREO4_Pos)
	                                  | (CONF_RTC_PEREO5 << RTC_MODE0_EVCTRL_PEREO5_Pos)
	                                  | (CONF_RTC_PEREO6 << RTC_MODE0_EVCTRL_PEREO6_Pos)
	                                  | (CONF_RTC_PEREO7 << RTC_MODE0_EVCTRL_PEREO7_Pos)
	                                  | (CONF_RTC_COMPE0 << RTC_MODE0_EVCTRL_CMPEO_Pos)
	                                  | (CONF_RTC_COMPE1 << RTC_MODE0_EVCTRL_CMPEO1_Pos)
	                                  | (CONF_RTC_TAMPEREO << RTC_MODE0_EVCTRL_TAMPEREO_Pos)
	                                  | (CONF_RTC_TAMPEVEI << RTC_MODE0_EVCTRL_TAMPEVEI_Pos)
	                                  | (CONF_RTC_OVFEO << RTC_MODE0_EVCTRL_OVFEO_Pos));
#endif

	hri_rtcmode0_write_CTRLA_reg(dev->hw, RTC_MODE0_CTRLA_PRESCALER(CONF_RTC_PRESCALER) | RTC_MODE0_CTRLA_COUNTSYNC);

	return ERR_NONE;
}

/**
 * \brief Deinit the RTC module
 */
int32_t _calendar_deinit(struct calendar_dev *const dev)
{
	ASSERT(dev && dev->hw);

	NVIC_DisableIRQ(RTC_IRQn);
	dev->callback = NULL;

	hri_rtcmode0_clear_CTRLA_ENABLE_bit(dev->hw);
	hri_rtcmode0_set_CTRLA_SWRST_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief Enable the RTC module
 */
int32_t _calendar_enable(struct calendar_dev *const dev)
{
	ASSERT(dev && dev->hw);

	hri_rtcmode0_set_CTRLA_ENABLE_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief Disable the RTC module
 */
int32_t _calendar_disable(struct calendar_dev *const dev)
{
	ASSERT(dev && dev->hw);

	hri_rtcmode0_clear_CTRLA_ENABLE_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief Set the current calendar time to desired time.
 */
int32_t _calendar_set_counter(struct calendar_dev *const dev, const uint32_t counter)
{
	ASSERT(dev && dev->hw);

	hri_rtcmode0_write_COUNT_COUNT_bf(dev->hw, counter);

	return ERR_NONE;
}

/**
 * \brief Get current counter
 */
uint32_t _calendar_get_counter(struct calendar_dev *const dev)
{
	ASSERT(dev && dev->hw);

	return hri_rtcmode0_read_COUNT_COUNT_bf(dev->hw);
}

/**
 * \brief Set the compare for the specified value.
 */
int32_t _calendar_set_comp(struct calendar_dev *const dev, const uint32_t comp)
{
	ASSERT(dev && dev->hw);

	hri_rtcmode0_write_COMP_reg(dev->hw, 0, comp);

	return ERR_NONE;
}

/**
 * \brief Get the compare value
 */
uint32_t _calendar_get_comp(struct calendar_dev *const dev)
{
	ASSERT(dev && dev->hw);

	return hri_rtcmode0_read_COMP_reg(dev->hw, 0);
}

/**
 * \brief Registers callback for the specified callback type
 */
int32_t _calendar_register_callback(struct calendar_dev *const dev, calendar_drv_cb_alarm_t callback)
{
	ASSERT(dev && dev->hw);

	/* Check callback */
	if (callback != NULL) {
		/* register the callback */
		dev->callback = callback;

		/* enable RTC_IRQn */
		NVIC_ClearPendingIRQ(RTC_IRQn);
		NVIC_EnableIRQ(RTC_IRQn);

		/* enable cmp */
		hri_rtcmode0_set_INTEN_CMP0_bit(dev->hw);
	} else {
		/* disable cmp */
		hri_rtcmode0_clear_INTEN_CMP0_bit(dev->hw);

		/* disable RTC_IRQn */
		NVIC_DisableIRQ(RTC_IRQn);
	}

	return ERR_NONE;
}

/**
 * \brief RTC interrupt handler
 *
 * \param[in] dev The pointer to calendar device struct
 */
static void _rtc_interrupt_handler(struct calendar_dev *dev)
{
	/* Read and mask interrupt flag register */
	uint16_t interrupt_status = hri_rtcmode0_read_INTFLAG_reg(dev->hw);

	if (interrupt_status & RTC_MODE0_INTFLAG_CMP0) {
		dev->callback(dev);

		/* Clear interrupt flag */
		hri_rtcmode0_clear_interrupt_CMP0_bit(dev->hw);
	}
}

/**
 * \brief Set calendar IRQ
 */
void _calendar_set_irq(struct calendar_dev *const dev)
{
	(void)dev;
	NVIC_SetPendingIRQ(RTC_IRQn);
}

/**
* \brief Rtc interrupt handler
*/
void RTC_Handler(void)
{
	_rtc_interrupt_handler(_rtc_dev);
}
