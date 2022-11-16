/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using ADC_0 to generate waveform.
 */
void ADC_0_example(void)
{
	uint8_t buffer[2];

	adc_sync_enable_channel(&ADC_0, 0);

	while (1) {
		adc_sync_read_channel(&ADC_0, 0, buffer, 2);
	}
}

/**
 * Example of using DAC_0 to generate waveform.
 */
void DAC_0_example(void)
{
	uint16_t i = 0;

	dac_sync_enable_channel(&DAC_0, 0);

	for (;;) {
		dac_sync_write(&DAC_0, 0, &i, 1);
		i = (i + 1) % 1024;
	}
}

static uint8_t src_data[512];
static uint8_t chk_data[512];
/**
 * Example of using FLASH_0 to read and write buffer.
 */
void FLASH_0_example(void)
{
	uint32_t page_size;
	uint16_t i;

	/* Init source data */
	page_size = flash_get_page_size(&FLASH_0);

	for (i = 0; i < page_size; i++) {
		src_data[i] = i;
	}

	/* Write data to flash */
	flash_write(&FLASH_0, 0x3200, src_data, page_size);

	/* Read data from flash */
	flash_read(&FLASH_0, 0x3200, chk_data, page_size);
}

static struct timer_task TIMER_0_task1, TIMER_0_task2;
/**
 * Example of using TIMER_0.
 */
static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
}

static void TIMER_0_task2_cb(const struct timer_task *const timer_task)
{
}

void TIMER_0_example(void)
{
	TIMER_0_task1.interval = 100;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
	TIMER_0_task2.interval = 200;
	TIMER_0_task2.cb       = TIMER_0_task2_cb;
	TIMER_0_task2.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_add_task(&TIMER_0, &TIMER_0_task2);
	timer_start(&TIMER_0);
}

/**
 * Example of using SPI_M_SYNC_SERCOM0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_M_SYNC_SERCOM0[12] = "Hello World!";

void SPI_M_SYNC_SERCOM0_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_M_SYNC_SERCOM0, &io);

	spi_m_sync_enable(&SPI_M_SYNC_SERCOM0);
	io_write(io, example_SPI_M_SYNC_SERCOM0, 12);
}

void I2C_M_SERCOM1_example(void)
{
	struct io_descriptor *I2C_M_SERCOM1_io;

	i2c_m_sync_get_io_descriptor(&I2C_M_SERCOM1, &I2C_M_SERCOM1_io);
	i2c_m_sync_enable(&I2C_M_SERCOM1);
	i2c_m_sync_set_slaveaddr(&I2C_M_SERCOM1, 0x12, I2C_M_SEVEN);
	io_write(I2C_M_SERCOM1_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using USART_ASYNC_SERCOM2 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_USART_ASYNC_SERCOM2[12] = "Hello World!";

static void tx_cb_USART_ASYNC_SERCOM2(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_ASYNC_SERCOM2_example(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_ASYNC_SERCOM2, USART_ASYNC_TXC_CB, tx_cb_USART_ASYNC_SERCOM2);
	/*usart_async_register_callback(&USART_ASYNC_SERCOM2, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_ASYNC_SERCOM2, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_ASYNC_SERCOM2, &io);
	usart_async_enable(&USART_ASYNC_SERCOM2);

	io_write(io, example_USART_ASYNC_SERCOM2, 12);
}

/**
 * Example of using SPI_M_DMA_SERCOM3 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_SPI_M_DMA_SERCOM3[12] = "Hello World!";

static void tx_complete_cb_SPI_M_DMA_SERCOM3(struct _dma_resource *resource)
{
	/* Transfer completed */
}

void SPI_M_DMA_SERCOM3_example(void)
{
	struct io_descriptor *io;
	spi_m_dma_get_io_descriptor(&SPI_M_DMA_SERCOM3, &io);

	spi_m_dma_register_callback(&SPI_M_DMA_SERCOM3, SPI_M_DMA_CB_TX_DONE, tx_complete_cb_SPI_M_DMA_SERCOM3);
	spi_m_dma_enable(&SPI_M_DMA_SERCOM3);
	io_write(io, example_SPI_M_DMA_SERCOM3, 12);
}

void delay_example(void)
{
	delay_ms(5000);
}

/**
 * Example of using PWM_0.
 */
void PWM_0_example(void)
{
	pwm_set_parameters(&PWM_0, 10000, 5000);
	pwm_enable(&PWM_0);
}

/**
 * Example of using RAND_0 to generate waveform.
 */
void RAND_0_example(void)
{
	uint32_t random_n[4];
	rand_sync_enable(&RAND_0);
	random_n[0] = rand_sync_read32(&RAND_0);
	random_n[1] = rand_sync_read32(&RAND_0);
	rand_sync_read_buf32(&RAND_0, &random_n[2], 2);
	if (random_n[0] == random_n[1]) {
		/* halt */
		while (1)
			;
	}
	if (random_n[2] == random_n[3]) {
		/* halt */
		while (1)
			;
	}
}
