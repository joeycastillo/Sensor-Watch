The SPI Master DMA Driver
==================================

The serial peripheral interface (SPI) is a DMA serial communication
interface.

The SPI Master DMA driver uses DMA system to transfer data from
a memory buffer to SPI (Memory to Peripheral), and receive data
from SPI to a memory buffer (Peripheral to Memory).User must configure
DMA system driver accordingly. A callback is called when all the data
is transfered or all the data is received, if it is registered via 
spi_m_dma_register_callback function.

Features
--------

* Initialization/de-initialization
* Enabling/disabling
* Control of the following settings:

  * Baudrate
  * SPI mode
  * Character size
  * Data order
* Data transfer: transmission, reception and full-duplex
* Notifications about transfer completion and errors via callbacks

Applications
------------

Send/receive/exchange data with a SPI slave device. E.g., serial flash, SD card,
LCD controller, etc.

Dependencies
------------

SPI master capable hardware and DMA hardware, with data sent/received.

Concurrency
-----------

N/A

Limitations
-----------

When only uses DMA channel to receive data, the transfer channel must enable to
send dummy data to the slave.

While read/write/transfer is in progress, the data buffer used must be kept
unchanged.

Known issues and workarounds
----------------------------

N/A
