/**
 * \file
 *
 * \brief PWM functionality declaration.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef HAL_PWM_H_INCLUDED
#define HAL_PWM_H_INCLUDED

#include <hpl_pwm.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_pwm_async
 *
 *@{
 */

/**
 * \brief PWM descriptor
 *
 * The PWM descriptor forward declaration.
 */
struct pwm_descriptor;

/**
 * \brief PWM callback type
 */
typedef void (*pwm_cb_t)(const struct pwm_descriptor *const descr);

/**
 * \brief PWM callback types
 */
enum pwm_callback_type { PWM_PERIOD_CB, PWM_ERROR_CB };

/**
 * \brief PWM callbacks
 */
struct pwm_callbacks {
	pwm_cb_t period;
	pwm_cb_t error;
};

/** \brief PWM descriptor
 */
struct pwm_descriptor {
	/** PWM device */
	struct _pwm_device device;
	/** PWM callback structure */
	struct pwm_callbacks pwm_cb;
};

/** \brief Initialize the PWM HAL instance and hardware
 *
 *  \param[in] descr Pointer to the HAL PWM descriptor
 *  \param[in] hw The pointer to hardware instance
 *  \param[in] func The pointer to a set of functions pointers
 *
 *  \return Operation status.
 */
int32_t pwm_init(struct pwm_descriptor *const descr, void *const hw, struct _pwm_hpl_interface *const func);

/** \brief Deinitialize the PWM HAL instance and hardware
 *
 *  \param[in] descr Pointer to the HAL PWM descriptor
 *
 *  \return Operation status.
 */
int32_t pwm_deinit(struct pwm_descriptor *const descr);

/** \brief PWM output start
 *
 *  \param[in] descr Pointer to the HAL PWM descriptor
 *
 *  \return Operation status.
 */
int32_t pwm_enable(struct pwm_descriptor *const descr);

/** \brief PWM output stop
 *
 *  \param[in] descr Pointer to the HAL PWM descriptor
 *
 *  \return Operation status.
 */
int32_t pwm_disable(struct pwm_descriptor *const descr);

/** \brief Register PWM callback
 *
 *  \param[in] descr Pointer to the HAL PWM descriptor
 *  \param[in] type Callback type
 *  \param[in] cb A callback function, passing NULL de-registers callback
 *
 *  \return Operation status.
 *  \retval 0 Success
 *  \retval -1 Error
 */
int32_t pwm_register_callback(struct pwm_descriptor *const descr, enum pwm_callback_type type, pwm_cb_t cb);

/** \brief Change PWM parameter
 *
 *  \param[in] descr Pointer to the HAL PWM descriptor
 *  \param[in] period Total period of one PWM cycle
 *  \param[in] duty_cycle Period of PWM first half during one cycle
 *
 *  \return Operation status.
 */
int32_t pwm_set_parameters(struct pwm_descriptor *const descr, const pwm_period_t period,
                           const pwm_period_t duty_cycle);

/** \brief Get PWM driver version
 *
 *  \return Current driver version.
 */
uint32_t pwm_get_version(void);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* HAL_PWM;_H_INCLUDED */
