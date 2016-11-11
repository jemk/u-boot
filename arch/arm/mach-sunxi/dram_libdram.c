/*
 * Allwinner platform libdram blob DRAM controller init
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/dram.h>
#include <linux/kconfig.h>

/* Some callback functions, needed for the libdram blob */

void __usdelay(unsigned long us)
{
	udelay(us);
}

int set_ddr_voltage(int set_vol)
{
	return 0;
}

/* A piece of data, extracted from the H5 Android image */
u32 dram_para[] = {
    0x000002A0,
    0x00000003,
    0x003B3BF9,
    0x00000001,
    0x10F410F4,
    0x00000000,
    0x00001840,
    0x00000040,
    0x00000018,
    0x00000002,
    0x0048a192,
    0x01b1a94b,
    0x00061043,
    0xb4787896,
    0x00000000,
    0x00000000,
    0x00000064,
    0x1e08a1e0,
    0x00000000,
    0x00000000,
    0x00002535,
    0x23330000,
    0x00008897,
    0x04002910,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000
};

/* Entry point to the libdram blob */
unsigned long init_DRAM(u32, void *);

unsigned long sunxi_dram_init(void)
{
	init_DRAM(0, &dram_para[0]);
	return get_ram_size((long *)PHYS_SDRAM_0, PHYS_SDRAM_0_SIZE);
}
