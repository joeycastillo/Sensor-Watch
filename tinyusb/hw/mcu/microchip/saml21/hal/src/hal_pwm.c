/**
 * \file
 *
 * \brief PWM functionality implementation.
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

#include "hal_pwm.h"
#include <utils_assert.h>
#include <utils.h>

/**
 * \brief Driver version
 */
#define DRIVER_VERSION 0x00000001u

static void pwm_period_expired(struct _pwm_device *device);
static void pwm_detect_fault(struct _pwm_device *device);

/**
 * \brief Initialize pwm
 */
int32_t pwm_init(struct pwm_descriptor *const descr, void *const hw, struct _pwm_hpl_interface *const func)
{
	ASSERT(descr && hw);
	_pwm_init(&descr->device, hw);
	descr->device.callback.pwm_period_cb = pwm_period_expired;
	descr->device.callback.pwm_error_cb  = pwm_detect_fault;
	return ERR_NONE;
}

/**
 * \brief Deinitialize pwm
 */
int32_t pwm_deinit(struct pwm_descriptor *const descr)
{
	ASSERT(descr);
	_pwm_deinit(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Start pwm
 */
int32_t pwm_enable(struct pwm_descriptor *const descr)
{
	ASSERT(descr);
	if (_pwm_is_enabled(&descr->device)) {
		return ERR_DENIED;
	}
	_pwm_enable(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Stop pwm
 */
int32_t pwm_disable(struct pwm_descriptor *const descr)
{
	ASSERT(descr);
	if (!_pwm_is_enabled(&descr->device)) {
		return ERR_DENIED;
	}
	_pwm_disable(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Register PWM callback
 */
int32_t pwm_register_callback(struct pwm_descriptor *const descr, enum pwm_callback_type type, pwm_cb_t cb)
{
	switch (type) {
	case PWM_PERIOD_CB:
		descr->pwm_cb.period = cb;
		break;

	case PWM_ERROR_CB:
		descr->pwm_cb.error = cb;
		break;

	default:
		return ERR_INVALID_ARG;
	}
	ASSERT(descr);
	_pwm_set_irq_state(&descr->device, (enum _pwm_callback_type)type, NULL != cb);
	return ERR_NONE;
}

/**
 * \brief Change PWM parameter
 */
int32_t pwm_set_parameters(struct pwm_descriptor *const descr, const pwm_period_t period, const pwm_period_t duty_cycle)
{
	ASSERT(descr);
	_pwm_set_param(&descr->device, period, duty_cycle);
	return ERR_NONE;
}

/**
 * \brief Retrieve the current driver version
 */
uint32_t pwm_get_version(void)
{
	return DRIVER_VERSION;
}

/**
 * \internal Process interrupts caused by period experied
 */
static void pwm_period_expired(struct _pwm_device *device)
{
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wcast-align"
	struct pwm_descriptor *const descr = CONTAINER_OF(device, struct pwm_descriptor, device);
	#pragma GCC diagnostic pop

	if (descr->pwm_cb.period) {
		descr->pwm_cb.period(descr);
	}
}

/**
 * \internal Process interrupts caused by pwm fault
 */
static void pwm_detect_fault(struct _pwm_device *device)
{
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wcast-align"
	struct pwm_descriptor *const descr = CONTAINER_OF(device, struct pwm_descriptor, device);
	#pragma GCC diagnostic pop

	if (descr->pwm_cb.error) {
		descr->pwm_cb.error(descr);
	}
}
