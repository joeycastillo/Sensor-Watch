/* Auto-generated config file hpl_mem2mem_config.h */
#ifndef HPL_MEM2MEM_CONFIG_H
#define HPL_MEM2MEM_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <e> MEM2MEM enable
// <i> Indicates whether mem2mem is enabled or not
// <id> mem2mem_enable
#ifndef CONF_MEM2MEM_ENABLE
#define CONF_MEM2MEM_ENABLE 0
#endif

// <h> Basic configuration

// <o> Transfer Size
// <0=> The buffer size is defined in byte
// <1=> The buffer size is defined in half-word (16-bit)
// <2=> The buffer size is defined in word (32-bit)
// <i> Transfer Size
// <id> mem2mem_mr_tsize
#ifndef CONF_MEM2MEM_MR_TSIZE
#define CONF_MEM2MEM_MR_TSIZE 0
#endif

// </h>
// </e>

// <<< end of configuration section >>>

#endif // HPL_MEM2MEM_CONFIG_H
