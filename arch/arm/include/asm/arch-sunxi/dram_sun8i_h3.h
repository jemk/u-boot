/*
 * sun8i H3 platform dram controller register and constant defines
 *
 * (C) Copyright 2007-2015 Allwinner Technology Co.
 *                         Jerry Wang <wangflord@allwinnertech.com>
 * (C) Copyright 2015      Vishnu Patekar <vishnupatekar0510@gmail.com>
 * (C) Copyright 2014-2015 Hans de Goede <hdegoede@redhat.com>
 * (C) Copyright 2015      Jens Kuske <jenskuske@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _SUNXI_DRAM_SUN8I_H3_H
#define _SUNXI_DRAM_SUN8I_H3_H

struct sunxi_mctl_com_reg {
	u32 cr;			/* 0x00 control register */
	u8 res0[0xc];		/* 0x04 */
	u32 mcr[16][2];		/* 0x10 */
	u32 bwcr;		/* 0x90 bandwidth control register */
	u32 maer;		/* 0x94 master enable register */
	u32 mapr;		/* 0x98 master priority register */
	u32 mcgcr;		/* 0x9c */
	u32 cpu_bwcr;		/* 0xa0 */
	u32 gpu_bwcr;		/* 0xa4 */
	u32 ve_bwcr;		/* 0xa8 */
	u32 disp_bwcr;		/* 0xac */
	u32 other_bwcr;		/* 0xb0 */
	u32 total_bwcr;		/* 0xb4 */
	u8 res1[0x8];		/* 0xb8 */
	u32 swonr;		/* 0xc0 */
	u32 swoffr;		/* 0xc4 */
	u8 res2[0x8];		/* 0xc8 */
	u32 cccr;		/* 0xd0 */
	u8 res3[0x72c];		/* 0xd4 */
	u32 protect;		/* 0x800 */
};

#define MCTL_CR_BL8		(0x4 << 20)

#define MCTL_CR_1T		(0x1 << 19)
#define MCTL_CR_2T		(0x0 << 19)

#define MCTL_CR_LPDDR3		(0x7 << 16)
#define MCTL_CR_LPDDR2		(0x6 << 16)
#define MCTL_CR_DDR3		(0x3 << 16)
#define MCTL_CR_DDR2		(0x2 << 16)

#define MCTL_CR_SEQUENTIAL	(0x1 << 15)
#define MCTL_CR_INTERLEAVED	(0x0 << 15)

#define MCTL_CR_32BIT		(0x1 << 12)
#define MCTL_CR_16BIT		(0x0 << 12)
#define MCTL_CR_BUS_WIDTH(x)	((x) == 32 ? MCTL_CR_32BIT : MCTL_CR_16BIT)

#define MCTL_CR_PAGE_SIZE(x)	((fls(x) - 4) << 8)
#define MCTL_CR_ROW_BITS(x)	(((x) - 1) << 4)
#define MCTL_CR_EIGHT_BANKS	(0x1 << 2)
#define MCTL_CR_FOUR_BANKS	(0x0 << 2)
#define MCTL_CR_DUAL_RANK	(0x1 << 0)
#define MCTL_CR_SINGLE_RANK	(0x0 << 0)

#define PROTECT_MAGIC		(0x94be6fa3)

struct sunxi_mctl_ctl_reg {
	u32 pir;		/* 0x00 PHY initialization register */
	u32 pwrctl;		/* 0x04 */
	u32 mrctrl;		/* 0x08 */
	u32 clken;		/* 0x0c */
	u32 pgsr[2];		/* 0x10 PHY general status registers */
	u32 stat;		/* 0x18 operating mode status register */
	u8 res1[0x14];		/* 0x1c */
	u32 mr[4];		/* 0x30 DRAM mode registers */
	u32 pllgcr;		/* 0x40 */
	u32 ptr[5];		/* 0x44 PHY timing registers */
	u32 dramtmg[9];		/* 0x58 DRAM timing registers */
	u32 odtcfg;		/* 0x7c ODT configuration register */
	u32 dfitmg[2];		/* 0x80 DFI timing registers */
	u8 res2[0x4];		/* 0x88 */
	u32 rfshctl0;		/* 0x8c refresh control register 0 */
	u32 rfshtmg;		/* 0x90 refresh timing register */
	u32 rfshctl1;		/* 0x94 refresh control register 1 */
	u32 pwrtmg;		/* 0x98 */
	u8 res3[0x20];		/* 0x9c */
	u32 dqsgmr;		/* 0xbc */
	u32 dtcr;		/* 0xc0 data training configuration register */
	u32 dtar[4];		/* 0xc4 data training address registers */
	u32 dtdr[2];		/* 0xd4 data training data register */
	u32 dtmr[2];		/* 0xdc */
	u32 dtbmr;		/* 0xe4 */
	u32 catr[2];		/* 0xe8 */
	u32 dtedr[2];		/* 0xf0 data training eye data regisers */
	u8 res4[0x8];		/* 0xf8 */
	u32 pgcr[4];		/* 0x100 PHY general configuration registers */
	u32 iovcr[2];		/* 0x110 */
	u32 dqsdr;		/* 0x118 */
	u32 dxccr;		/* 0x11c */
	u32 odtmap;		/* 0x120 ODT/rank map register */
	u32 zqctl[2];		/* 0x124 ZQ control registers */
	u8 res6[0x14];		/* 0x12c */
	u32 zqcr;		/* 0x140 ZQ control register */
	u32 zqsr;		/* 0x144 ZQ status register */
	u32 zqdr[3];		/* 0x148 ZQ data registers */
	u8 res7[0x6c];		/* 0x154 */
	u32 sched;		/* 0x1c0 scheduler control register */
	u32 perfhpr[2];		/* 0x1c4 high priority read CAM registers */
	u32 perflpr[2];		/* 0x1cc low priority read CAM registers */
	u32 perfwr[2];		/* 0x1d4 write CAM registers */
	u8 res8[0x24];		/* 0x1dc */
	u32 acmdlr;		/* 0x200 AC master delay line register */
	u32 aclcdlr;		/* 0x204 AC local calibrated delay line register */
	u32 aciocr;		/* 0x208 AC I/O configuration register */
	u8 res9[0x4];		/* 0x20c */
	u32 acbdlr[31];		/* 0x210 AC bit delay line registers */
	u8 res10[0x74];		/* 0x28c */
	struct {		/* 0x300 DATX8 modules*/
		u32 mdlr;		/* 0x00 master delay line register */
		u32 lcdlr[3];		/* 0x04 local calibrated delay line registers */
		u32 bdlr[12];		/* 0x10 bit delay line registers */
		u32 gtr;		/* 0x40 general timing register */
		u32 gcr;		/* 0x44 general configuration register */
		u32 gsr[3];		/* 0x48 general status registers */
		u8 res0[0x2c];		/* 0x54 */
	} dx[4];
	u8 res11[0x300];	/* 0x500 */
	u32 bistrr;		/* 0x800 BIST run register */
	u32 bistwcr;		/* 0x804 BIST word count register */
	u32 bistmskr[3];	/* 0x808 BIST mask registers */
	u32 bistlsr;		/* 0x814 BIST LFSR seed register */
	u32 bistar[3];		/* 0x818 BIST address registers */
	u32 bistudpr;		/* 0x824 BIST user data pattern register */
	u32 bistgsr;		/* 0x828 BIST general status register */
	u32 bistwer;		/* 0x82c BIST word error register */
	u32 bistber[4];		/* 0x830 BIST bit error registers */
	u32 bistwcsr;		/* 0x840 BIST word count status register */
	u32 bistfwr[3];		/* 0x844 BIST fail word registers */
	u8 res12[0x30];		/* 0x850 */
	u32 dfiupd[3];		/* 0x880 */
};

#define PIR_CLRSR		BIT(27)		/* clear status registers */
#define PIR_WREYE		BIT(15)		/* write data eye training */
#define PIR_RDEYE		BIT(14)		/* read data eye training */
#define PIR_WRDSKW		BIT(13)		/* write data bit deskew */
#define PIR_RDDSKW		BIT(12)		/* read data bit deskew */
#define PIR_WLADJ		BIT(11)		/* write leveling adjust */
#define PIR_QSGATE		BIT(10)		/* read DQS gate training */
#define PIR_WL			BIT(9)		/* write leveling */
#define PIR_DRAMINIT		BIT(8)		/* DRAM initialization */
#define PIR_DRAMRST		BIT(7)		/* DRAM reset */
#define PIR_PHYRST		BIT(6)		/* PHY reset */
#define PIR_DCAL		BIT(5)		/* DDL calibration */
#define PIR_PLLINIT		BIT(4)		/* PLL initialization */
#define PIR_ZCAL		BIT(1)		/* ZQ calibration */
#define PIR_INIT		BIT(0)		/* PHY initialization trigger */

#define PGSR0_INIT_DONE		BIT(0)		/* PHY initialization done */

#define PTR3_TDINIT1(x)		(((x) & 0x1f) << 20)	/* DRAM init time 1 */
#define PTR3_TDINIT0(x)		(((x) & 0xfffff) << 0)	/* DRAM init time 0 */

#define PTR4_TDINIT3(x)		(((x) & 0x7ff) << 20)	/* DRAM init time 3 */
#define PTR4_TDINIT2(x)		(((x) & 0x3ffff) << 0)	/* DRAM init time 2 */

#define DRAMTMG0_WR2PRE(x)	(((x) & 0x3f) << 24)	/* write to precharge */
#define DRAMTMG0_TFAW(x)	(((x) & 0x3f) << 16)	/* tFAW */
#define DRAMTMG0_TRAS_MAX(x)	(((x) & 0x3f) << 8)	/* tRAS(max) */
#define DRAMTMG0_TRAS(x)	(((x) & 0x3f) << 0)	/* tRAS */

#define DRAMTMG1_TXP(x)		(((x) & 0x1f) << 16)	/* tXP */
#define DRAMTMG1_RD2PRE(x)	(((x) & 0x1f) << 8)	/* read to precharge */
#define DRAMTMG1_TRC(x)		(((x) & 0x3f) << 0)	/* tRC */

#define DRAMTMG2_WR_LATENCY(x)	(((x) & 0x3f) << 24)	/* write latency */
#define DRAMTMG2_RD_LATENCY(x)	(((x) & 0x1f) << 16)	/* read latency */
#define DRAMTMG2_RD2WR(x)	(((x) & 0x1f) << 8)	/* read to write */
#define DRAMTMG2_WR2RD(x)	(((x) & 0x3f) << 0)	/* write to read */

#define DRAMTMG3_TMRW(x)	(((x) & 0x3ff) << 16)	/* tMRW */
#define DRAMTMG3_TMRD(x)	(((x) & 0x7) << 12)	/* tMRD */
#define DRAMTMG3_TMOD(x)	(((x) & 0x3ff) << 0)	/* tMOD */

#define DRAMTMG4_TRCD(x)	(((x) & 0x1f) << 24)	/* tRCD */
#define DRAMTMG4_TCCD(x)	(((x) & 0x7) << 16)	/* tCCD */
#define DRAMTMG4_TRRD(x)	(((x) & 0xf) << 8)	/* tRRD */
#define DRAMTMG4_TRP(x)		(((x) & 0x1f) << 0)	/* tRP */

#define DRAMTMG5_TCKSRX(x)	(((x) & 0xf) << 24)	/* tCKSRX */
#define DRAMTMG5_TCKSRE(x)	(((x) & 0xf) << 16)	/* tCKSRE */
#define DRAMTMG5_TCKESR(x)	(((x) & 0x3f) << 8)	/* tCKESR */
#define DRAMTMG5_TCKE(x)	(((x) & 0xf) << 0)	/* tCKE */

#define DFITMG0_CTRL_DELAY(x)	(((x) & 0x1f) << 24)	/* tCTRL_delay */
#define DFITMG0_RDDATA_EN(x)	(((x) & 0x1f) << 16)	/* tRDDATA_en */
#define DFITMG0_PHY_WRDATA(x)	(((x) & 0x1f) << 8)	/* tPHY_wrdata */
#define DFITMG0_PHY_WRLAT(x)	(((x) & 0x1f) << 0)	/* tPHY_wrlat */

#define RFSHTMG_TREFI(x)	(((x) & 0xfff) << 16)	/* tREFI */
#define RFSHTMG_TRFC(x)		(((x) & 0x1ff) <<  0)	/* tRFC */

#define PGCR0_PHYFRST		BIT(26)			/* PHY FIFO reset */

#define ZQCR_PWRDOWN		BIT(31)			/* ZQ power down */

#define ACBDLR_BD(x)		(((x) & 0x3f) << 8)	/* AC bit delay */

#define DXBDLR_DQ_IDX(x)	(x)			/* DQ0-7 BDLR index */
#define DXBDLR_DM_IDX		(8)			/* DM BDLR index */
#define DXBDLR_DQS_IDX		(9)			/* DQS BDLR index */
#define DXBDLR_DQSN_IDX		(10)			/* DQSN BDLR index */

#define DXBDLR_WBD(x)		(((x) & 0x3f) << 8)	/* DX write bit delay */
#define DXBDLR_RBD(x)		(((x) & 0x3f) << 0)	/* DX read bit delay */

#define BISTRR_BDXSEL(x)	(((x) & 0xf) << 19)	/* DATX8 select */
#define BISTRR_BDPAT_WALKING_0	(0x0 << 17)		/* data pattern */
#define BISTRR_BDPAT_WALKING_1	(0x1 << 17)
#define BISTRR_BDPAT_LFSR	(0x2 << 17)
#define BISTRR_BDPAT_USER	(0x3 << 17)
#define BISTRR_BACEN		BIT(15)			/* AC enable */
#define BISTRR_BDXEN		BIT(14)			/* DATX8 enable */
#define BISTRR_BSONF		BIT(13)			/* stop on n-th fail */
#define BISTRR_NFAIL(x)		(((x) & 0xff) << 5)	/* number of failures */
#define BISTRR_BINF		BIT(4)			/* infinite run */
#define BISTRR_BMODE_LOOPBACK	(0x0 << 3)		/* BIST mode */
#define BISTRR_BMODE_DRAM	(0x1 << 3)
#define BISTRR_BINST_NOP	(0x0 << 0)		/* BIST instruction */
#define BISTRR_BINST_RUN	(0x1 << 0)
#define BISTRR_BINST_STOP	(0x2 << 0)
#define BISTRR_BINST_RESET	(0x3 << 0)

#define BISTAR0_BBANK(x)	(((x) & 0x7) << 28)	/* bank address */
#define BISTAR0_BROW(x)		(((x) & 0xffff) << 12)	/* row address */
#define BISTAR0_BCOL(x)		(((x) & 0xfff) << 0)	/* column address */

#define BISTAR1_BRANK(x)	(((x) & 0x3) << 0)	/* rank */
#define BISTAR1_BMRANK(x)	(((x) & 0x3) << 2)	/* max rank */
#define BISTAR1_BAINC(x)	(((x) & 0xfff) << 4)	/* address increment */

#define BISTAR2_BMBANK(x)	(((x) & 0x7) << 28)	/* max bank address */
#define BISTAR2_BMROW(x)	(((x) & 0xffff) << 12)	/* max row address */
#define BISTAR2_BMCOL(x)	(((x) & 0xfff) << 0)	/* max column address */

#define BISTGSR_BDXERR		BIT(2)			/* data error */
#define BISTGSR_BACERR		BIT(1)			/* AC error */
#define BISTGSR_BDONE		BIT(0)			/* BIST done */

#define BISTWER_DXWER_SHIFT	(16)		/* DX word error shift */
#define BISTWER_ACWER_SHIFT	(0)		/* AC word error shift */

#endif /* _SUNXI_DRAM_SUN8I_H3_H */
