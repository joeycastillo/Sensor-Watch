/* Auto-generated config file hpl_sercom_config.h */
#ifndef HPL_SERCOM_CONFIG_H
#define HPL_SERCOM_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

#ifndef SERCOM_I2CM_CTRLA_MODE_I2C_MASTER
#define SERCOM_I2CM_CTRLA_MODE_I2C_MASTER (5 << 2)
#endif

#ifndef CONF_SERCOM_1_I2CM_ENABLE
#define CONF_SERCOM_1_I2CM_ENABLE 1
#endif

// <h> Basic

// <o> I2C Bus clock speed (Hz) <1-400000>
// <i> I2C Bus clock (SCL) speed measured in Hz
// <id> i2c_master_baud_rate
#ifndef CONF_SERCOM_1_I2CM_BAUD
#define CONF_SERCOM_1_I2CM_BAUD 100000
#endif

// </h>

// <e> Advanced
// <id> i2c_master_advanced
#ifndef CONF_SERCOM_1_I2CM_ADVANCED_CONFIG
#define CONF_SERCOM_1_I2CM_ADVANCED_CONFIG 0
#endif

// <o> TRise (ns) <0-300>
// <i> Determined by the bus impedance, check electric characteristics in the datasheet
// <i> Standard Fast Mode: typical 215ns, max 300ns
// <i> Fast Mode +: typical 60ns, max 100ns
// <i> High Speed Mode: typical 20ns, max 40ns
// <id> i2c_master_arch_trise

#ifndef CONF_SERCOM_1_I2CM_TRISE
#define CONF_SERCOM_1_I2CM_TRISE 215
#endif

// <q> Master SCL Low Extended Time-Out (MEXTTOEN)
// <i> This enables the master SCL low extend time-out
// <id> i2c_master_arch_mexttoen
#ifndef CONF_SERCOM_1_I2CM_MEXTTOEN
#define CONF_SERCOM_1_I2CM_MEXTTOEN 0
#endif

// <q> Slave SCL Low Extend Time-Out (SEXTTOEN)
// <i> Enables the slave SCL low extend time-out. If SCL is cumulatively held low for greater than 25ms from the initial START to a STOP, the slave will release its clock hold if enabled and reset the internal state machine
// <id> i2c_master_arch_sexttoen
#ifndef CONF_SERCOM_1_I2CM_SEXTTOEN
#define CONF_SERCOM_1_I2CM_SEXTTOEN 0
#endif

// <q> SCL Low Time-Out (LOWTOUT)
// <i> Enables SCL low time-out. If SCL is held low for 25ms-35ms, the master will release it's clock hold
// <id> i2c_master_arch_lowtout
#ifndef CONF_SERCOM_1_I2CM_LOWTOUT
#define CONF_SERCOM_1_I2CM_LOWTOUT 0
#endif

// <o> Inactive Time-Out (INACTOUT)
// <0x0=>Disabled
// <0x1=>5-6 SCL cycle time-out(50-60us)
// <0x2=>10-11 SCL cycle time-out(100-110us)
// <0x3=>20-21 SCL cycle time-out(200-210us)
// <i> Defines if inactivity time-out should be enabled, and how long the time-out should be
// <id> i2c_master_arch_inactout
#ifndef CONF_SERCOM_1_I2CM_INACTOUT
#define CONF_SERCOM_1_I2CM_INACTOUT 0x0
#endif

// <o> SDA Hold Time (SDAHOLD)
// <0=>Disabled
// <1=>50-100ns hold time
// <2=>300-600ns hold time
// <3=>400-800ns hold time
// <i> Defines the SDA hold time with respect to the negative edge of SCL
// <id> i2c_master_arch_sdahold
#ifndef CONF_SERCOM_1_I2CM_SDAHOLD
#define CONF_SERCOM_1_I2CM_SDAHOLD 0x2
#endif

// <q> Run in stand-by
// <i> Determine if the module shall run in standby sleep mode
// <id> i2c_master_arch_runstdby
#ifndef CONF_SERCOM_1_I2CM_RUNSTDBY
#define CONF_SERCOM_1_I2CM_RUNSTDBY 0
#endif

// <o> Debug Stop Mode
// <i> Behavior of the baud-rate generator when CPU is halted by external debugger.
// <0=>Keep running
// <1=>Halt
// <id> i2c_master_arch_dbgstop
#ifndef CONF_SERCOM_1_I2CM_DEBUG_STOP_MODE
#define CONF_SERCOM_1_I2CM_DEBUG_STOP_MODE 0
#endif

// </e>

#ifndef CONF_SERCOM_1_I2CM_SPEED
#define CONF_SERCOM_1_I2CM_SPEED 0x00 // Speed: Standard/Fast mode
#endif
#if CONF_SERCOM_1_I2CM_TRISE < 215 || CONF_SERCOM_1_I2CM_TRISE > 300
#warning Bad I2C Rise time for Standard/Fast mode, reset to 215ns
#undef CONF_SERCOM_1_I2CM_TRISE
#define CONF_SERCOM_1_I2CM_TRISE 215U
#endif

//                  gclk_freq - (i2c_scl_freq * 10) - (gclk_freq * i2c_scl_freq * Trise)
// BAUD + BAUDLOW = --------------------------------------------------------------------
//                  i2c_scl_freq
// BAUD:    register value low  [7:0]
// BAUDLOW: register value high [15:8], only used for odd BAUD + BAUDLOW
#define CONF_SERCOM_1_I2CM_BAUD_BAUDLOW                                                                                \
	(((CONF_GCLK_SERCOM1_CORE_FREQUENCY - (CONF_SERCOM_1_I2CM_BAUD * 10U)                                              \
	   - (CONF_SERCOM_1_I2CM_TRISE * (CONF_SERCOM_1_I2CM_BAUD / 100U) * (CONF_GCLK_SERCOM1_CORE_FREQUENCY / 10000U)    \
	      / 1000U))                                                                                                    \
	      * 10U                                                                                                        \
	  + 5U)                                                                                                            \
	 / (CONF_SERCOM_1_I2CM_BAUD * 10U))
#ifndef CONF_SERCOM_1_I2CM_BAUD_RATE
#if CONF_SERCOM_1_I2CM_BAUD_BAUDLOW > (0xFF * 2)
#warning Requested I2C baudrate too low, please check
#define CONF_SERCOM_1_I2CM_BAUD_RATE 0xFF
#elif CONF_SERCOM_1_I2CM_BAUD_BAUDLOW <= 1
#warning Requested I2C baudrate too high, please check
#define CONF_SERCOM_1_I2CM_BAUD_RATE 1
#else
#define CONF_SERCOM_1_I2CM_BAUD_RATE                                                                                   \
	((CONF_SERCOM_1_I2CM_BAUD_BAUDLOW & 0x1)                                                                           \
	     ? (CONF_SERCOM_1_I2CM_BAUD_BAUDLOW / 2) + ((CONF_SERCOM_1_I2CM_BAUD_BAUDLOW / 2 + 1) << 8)                    \
	     : (CONF_SERCOM_1_I2CM_BAUD_BAUDLOW / 2))
#endif
#endif

#include <peripheral_clk_config.h>

// Enable configuration of module
#ifndef CONF_SERCOM_3_SPI_ENABLE
#define CONF_SERCOM_3_SPI_ENABLE 1
#endif

// Set module in SPI Master mode
#ifndef CONF_SERCOM_3_SPI_MODE
#define CONF_SERCOM_3_SPI_MODE 0x03
#endif

// <h> Basic Configuration

// <q> Receive buffer enable
// <i> Enable receive buffer to receive data from slave (RXEN)
// <id> spi_master_rx_enable
#ifndef CONF_SERCOM_3_SPI_RXEN
#define CONF_SERCOM_3_SPI_RXEN 0x1
#endif

// <o> Character Size
// <i> Bit size for all characters sent over the SPI bus (CHSIZE)
// <0x0=>8 bits
// <0x1=>9 bits
// <id> spi_master_character_size
#ifndef CONF_SERCOM_3_SPI_CHSIZE
#define CONF_SERCOM_3_SPI_CHSIZE 0x0
#endif
// <o> Baud rate <1-12000000>
// <i> The SPI data transfer rate
// <id> spi_master_baud_rate
#ifndef CONF_SERCOM_3_SPI_BAUD
#define CONF_SERCOM_3_SPI_BAUD 1000000
#endif

// </h>

// <e> Advanced Configuration
// <id> spi_master_advanced
#ifndef CONF_SERCOM_3_SPI_ADVANCED
#define CONF_SERCOM_3_SPI_ADVANCED 1
#endif

// <o> Dummy byte <0x00-0x1ff>
// <id> spi_master_dummybyte
// <i> Dummy byte used when reading data from the slave without sending any data
#ifndef CONF_SERCOM_3_SPI_DUMMYBYTE
#define CONF_SERCOM_3_SPI_DUMMYBYTE 0x1ff
#endif

// <o> Data Order
// <0=>MSB first
// <1=>LSB first
// <i> I least significant or most significant bit is shifted out first (DORD)
// <id> spi_master_arch_dord
#ifndef CONF_SERCOM_3_SPI_DORD
#define CONF_SERCOM_3_SPI_DORD 0x0
#endif

// <o> Clock Polarity
// <0=>SCK is low when idle
// <1=>SCK is high when idle
// <i> Determines if the leading edge is rising or falling with a corresponding opposite edge at the trailing edge. (CPOL)
// <id> spi_master_arch_cpol
#ifndef CONF_SERCOM_3_SPI_CPOL
#define CONF_SERCOM_3_SPI_CPOL 0x0
#endif

// <o> Clock Phase
// <0x0=>Sample input on leading edge
// <0x1=>Sample input on trailing edge
// <i> Determines if input data is sampled on leading or trailing SCK edge. (CPHA)
// <id> spi_master_arch_cpha
#ifndef CONF_SERCOM_3_SPI_CPHA
#define CONF_SERCOM_3_SPI_CPHA 0x0
#endif

// <o> Immediate Buffer Overflow Notification
// <i> Controls when OVF is asserted (IBON)
// <0x0=>In data stream
// <0x1=>On buffer overflow
// <id> spi_master_arch_ibon
#ifndef CONF_SERCOM_3_SPI_IBON
#define CONF_SERCOM_3_SPI_IBON 0x0
#endif

// <q> Run in stand-by
// <i> Module stays active in stand-by sleep mode. (RUNSTDBY)
// <id> spi_master_arch_runstdby
#ifndef CONF_SERCOM_3_SPI_RUNSTDBY
#define CONF_SERCOM_3_SPI_RUNSTDBY 0x0
#endif

// <o> Debug Stop Mode
// <i> Behavior of the baud-rate generator when CPU is halted by external debugger. (DBGSTOP)
// <0=>Keep running
// <1=>Halt
// <id> spi_master_arch_dbgstop
#ifndef CONF_SERCOM_3_SPI_DBGSTOP
#define CONF_SERCOM_3_SPI_DBGSTOP 0
#endif

// </e>

// Address mode disabled in master mode
#ifndef CONF_SERCOM_3_SPI_AMODE_EN
#define CONF_SERCOM_3_SPI_AMODE_EN 0
#endif

#ifndef CONF_SERCOM_3_SPI_AMODE
#define CONF_SERCOM_3_SPI_AMODE 0
#endif

#ifndef CONF_SERCOM_3_SPI_ADDR
#define CONF_SERCOM_3_SPI_ADDR 0
#endif

#ifndef CONF_SERCOM_3_SPI_ADDRMASK
#define CONF_SERCOM_3_SPI_ADDRMASK 0
#endif

#ifndef CONF_SERCOM_3_SPI_SSDE
#define CONF_SERCOM_3_SPI_SSDE 0
#endif

#ifndef CONF_SERCOM_3_SPI_MSSEN
#define CONF_SERCOM_3_SPI_MSSEN 0x0
#endif

#ifndef CONF_SERCOM_3_SPI_PLOADEN
#define CONF_SERCOM_3_SPI_PLOADEN 0
#endif

// <o> Receive Data Pinout
// <0x0=>PAD[0]
// <0x1=>PAD[1]
// <0x2=>PAD[2]
// <0x3=>PAD[3]
// <id> spi_master_rxpo
#ifndef CONF_SERCOM_3_SPI_RXPO
#define CONF_SERCOM_3_SPI_RXPO 2
#endif

// <o> Transmit Data Pinout
// <0x0=>PAD[0,1]_DO_SCK
// <0x1=>PAD[2,3]_DO_SCK
// <0x2=>PAD[3,1]_DO_SCK
// <0x3=>PAD[0,3]_DO_SCK
// <id> spi_master_txpo
#ifndef CONF_SERCOM_3_SPI_TXPO
#define CONF_SERCOM_3_SPI_TXPO 3
#endif

// Calculate baud register value from requested baudrate value
#ifndef CONF_SERCOM_3_SPI_BAUD_RATE
#define CONF_SERCOM_3_SPI_BAUD_RATE ((float)CONF_GCLK_SERCOM3_CORE_FREQUENCY / (float)(2 * CONF_SERCOM_3_SPI_BAUD)) - 1
#endif

// <<< end of configuration section >>>

#endif // HPL_SERCOM_CONFIG_H
