/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */
#include "atmel_start.h"
#include "sleep_manager_main.h"

static struct sleepmgr_ready_to_sleep_cb sleepmgr_cb;

static void sleep_cb(struct sleepmgr_ready_to_sleep *const ready)
{
	ready->ready = false;
}

void sleep_manager_init(void)
{
	sleepmgr_init();

	sleepmgr_cb.cb = sleep_cb;
	sleepmgr_register_ready_to_sleep_callback(&sleepmgr_cb);
}
