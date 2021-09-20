/* Auto-generated config file nv_storage_config.h */
#ifndef NV_STORAGE_CONFIG_H
#define NV_STORAGE_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

//<o> Storage start address <0x00000000-0xFFFFFFFF>
//<i> This defines the start address of device flash for storage.
//<i> The start address should be in device flash area.
//<i> The start address and (start address + Item Number * Sector size) cannot beyond device flash area.
//<id> conf_storage_memory_start
#ifndef CONF_STORAGE_MEMORY_START
#define CONF_STORAGE_MEMORY_START 0x10000
#endif

//<o> Item number <0-65535>
//<i> This defines the maximum number of elements stored in persistent storage
//<id> conf_max_item_number
#ifndef CONF_MAX_ITEM_NUMBER
#define CONF_MAX_ITEM_NUMBER 10
#endif

//<o> Sector size <0-65535>
//<i> This defines the size of one storage sector in bytes
//<id> conf_sector_size
#ifndef CONF_SECTOR_SIZE
#define CONF_SECTOR_SIZE 4096
#endif

/**
 * Check If the Storage configuration out of the flash area.
 */
#ifdef FLASH_SIZE
#if (CONF_STORAGE_MEMORY_START + (SECTOR_AMOUNT * CONF_SECTOR_SIZE)) > FLASH_SIZE
#error Invalidate storage configuration, make sure the configuration with \
the sector start address (CONF_STORAGE_MEMORY_START) and sector size (CONF_SECTOR_SIZE) \
are located within the device flash size.
#endif
#endif

#ifdef IFLASH_SIZE
#if (CONF_STORAGE_MEMORY_START + (SECTOR_AMOUNT * CONF_SECTOR_SIZE)) > IFLASH_SIZE
#error Invalidate storage configuration, make sure the configuration with \
the sector start address (CONF_STORAGE_MEMORY_START) and sector size (CONF_SECTOR_SIZE) \
are located within the device flash size.
#endif
#endif

// <<< end of configuration section >>>

#endif // NV_STORAGE_CONFIG_H
