/**
 * \file
 *
 * \brief Timer task functionality declaration.
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

#ifndef _HAL_TIMER_H_INCLUDED
#define _HAL_TIMER_H_INCLUDED

#include <utils_list.h>
#include <hpl_timer.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_timer
 *
 * @{
 */

/**
 * \brief Timer mode type
 */
enum timer_task_mode { TIMER_TASK_ONE_SHOT, TIMER_TASK_REPEAT };

/**
 * \brief Timer task descriptor
 *
 * The timer task descriptor forward declaration.
 */
struct timer_task;

/**
 * \brief Timer task callback function type
 */
typedef void (*timer_cb_t)(const struct timer_task *const timer_task);

/**
 * \brief Timer task structure
 */
struct timer_task {
	struct list_element elem;       /*! List element. */
	uint32_t            time_label; /*! Absolute timer start time. */

	uint32_t             interval; /*! Number of timer ticks before calling the task. */
	timer_cb_t           cb;       /*! Function pointer to the task. */
	enum timer_task_mode mode;     /*! Task mode: one shot or repeat. */
};

/**
 * \brief Timer structure
 */
struct timer_descriptor {
	struct _timer_device   device;
	uint32_t               time;
	struct list_descriptor tasks; /*! Timer tasks list. */
	volatile uint8_t       flags;
};

/**
 * \brief Initialize timer
 *
 * This function initializes the given timer.
 * It checks if the given hardware is not initialized and if the given hardware
 * is permitted to be initialized.
 *
 * \param[out] descr A timer descriptor to initialize
 * \param[in] hw The pointer to the hardware instance
 * \param[in] func The pointer to a set of function pointers
 *
 * \return Initialization status.
 */
int32_t timer_init(struct timer_descriptor *const descr, void *const hw, struct _timer_hpl_interface *const func);

/**
 * \brief Deinitialize timer
 *
 * This function deinitializes the given timer.
 * It checks if the given hardware is initialized and if the given hardware is
 * permitted to be deinitialized.
 *
 * \param[in] descr A timer descriptor to deinitialize
 *
 * \return De-initialization status.
 */
int32_t timer_deinit(struct timer_descriptor *const descr);

/**
 * \brief Start timer
 *
 * This function starts the given timer.
 * It checks if the given hardware is initialized.
 *
 * \param[in] descr The timer descriptor of a timer to start
 *
 * \return Timer starting status.
 */
int32_t timer_start(struct timer_descriptor *const descr);

/**
 * \brief Stop timer
 *
 * This function stops the given timer.
 * It checks if the given hardware is initialized.
 *
 * \param[in] descr The timer descriptor of a timer to stop
 *
 * \return Timer stopping status.
 */
int32_t timer_stop(struct timer_descriptor *const descr);

/**
 * \brief Set amount of clock cycles per timer tick
 *
 * This function sets the amount of clock cycles per timer tick for the given timer.
 * It checks if the given hardware is initialized.
 *
 * \param[in] descr The timer descriptor of a timer to stop
 * \param[in] clock_cycles The amount of clock cycles per tick to set
 *
 * \return Setting clock cycles amount status.
 */
int32_t timer_set_clock_cycles_per_tick(struct timer_descriptor *const descr, const uint32_t clock_cycles);

/**
 * \brief Retrieve the amount of clock cycles in a tick
 *
 * This function retrieves how many clock cycles there are in a single timer tick.
 * It checks if the given hardware is initialized.
 *
 * \param[in]  descr The timer descriptor of a timer to convert ticks to
 * clock cycles
 * \param[out] cycles The amount of clock cycles
 *
 * \return The status of clock cycles retrieving.
 */
int32_t timer_get_clock_cycles_in_tick(const struct timer_descriptor *const descr, uint32_t *const cycles);

/**
 * \brief Add timer task
 *
 * This function adds the given timer task to the given timer.
 * It checks if the given hardware is initialized.
 *
 * \param[in] descr The timer descriptor of a timer to add task to
 * \param[in] task A task to add
 *
 * \return Timer's task adding status.
 */
int32_t timer_add_task(struct timer_descriptor *const descr, struct timer_task *const task);

/**
 * \brief Remove timer task
 *
 * This function removes the given timer task from the given timer.
 * It checks if the given hardware is initialized.
 *
 * \param[in] descr The timer descriptor of a timer to remove task from
 * \param[in] task A task to remove
 *
 * \return Timer's task removing status.
 */
int32_t timer_remove_task(struct timer_descriptor *const descr, const struct timer_task *const task);

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version.
 */
uint32_t timer_get_version(void);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* _HAL_TIMER_H_INCLUDED */
