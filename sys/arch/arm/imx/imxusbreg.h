/*	$NetBSD: imxusbreg.h,v 1.1 2010/11/30 13:05:27 bsh Exp $	*/
/*
 * Copyright (c) 2009, 2010  Genetec Corporation.  All rights reserved.
 * Written by Hashimoto Kenichi for Genetec Corporation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GENETEC CORPORATION ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORPORATION
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ARM_IMX_IMXUSBREG_H
#define _ARM_IMX_IMXUSBREG_H

#define	IMXUSB_ID		0x0000
#define	 IMXUSB_ID_ID_MASK		__BITS(5,0)
#define	 IMXUSB_ID_REVISION_SHIFT	16
#define	 IMXUSB_ID_REVISION_MASK	__BITS(IMXUSB_ID_REVISION_SHIFT,23)
#define	IMXUSB_HWGENERAL	0x0004
#define	IMXUSB_HWHOST		0x0008
#define	 HWHOST_HC			__BIT(0)
#define	 HWHOST_NPORT_SHIFT		1
#define	 HWHOST_NPORT_MASK		__BITS(HWHOST_NPORT_SHIFT,3)
#define	IMXUSB_HWDEVICE		0x000c
#define	 HWDEVICE_DC			__BIT(0)
#define	 HWDEVICE_DEVEP_SHIFT		1
#define	 HWDEVICE_DEVEP_MASK		__BITS(HWDEVICE_DEVEP_SHIFT,5)
#define	IMXUSB_HWTXBUF		0x0010
#define	IMXUSB_HWRXBUF		0x0014

#define	IMXUSB_EHCIREGS	0x0100

#define	IMXUSB_ULPIVIEW	0x0170
#define	 ULPI_WU	__BIT(31)
#define	 ULPI_RUN	__BIT(30)
#define	 ULPI_RW	__BIT(29)
#define	 ULPI_SS	__BIT(27)
#define	 ULPI_PORT_SHIFT	24
#define	 ULPI_PORT_MASK		(0x7 << ULPI_PORT_SHIFT)
#define	 ULPI_ADDR_SHIFT	16
#define	 ULPI_ADDR_MASK		(0xff << ULPI_ADDR_SHIFT)
#define	 ULPI_DATRD_SHIFT	8
#define	 ULPI_DATRD_MASK	(0xff << ULPI_DATRD_SHIFT)
#define	 ULPI_DATWR_SHIFT	0
#define	 ULPI_DATWR_MASK	(0xff << ULPI_DATWR_SHIFT)

#define	IMXUSB_OTGSC	0x01A4
#define	 OTGSC_DPIE	__BIT(30)
#define	 OTGSC_1MSE	__BIT(29)
#define	 OTGSC_BSEIE	__BIT(28)
#define	 OTGSC_BSVIE	__BIT(27)
#define	 OTGSC_ASVIE	__BIT(26)
#define	 OTGSC_AVVIE	__BIT(25)
#define	 OTGSC_IDIE	__BIT(24)
#define	 OTGSC_DPIS	__BIT(22)
#define	 OTGSC_1MSS	__BIT(21)
#define	 OTGSC_BSEIS	__BIT(20)
#define	 OTGSC_BSVIS	__BIT(19)
#define	 OTGSC_ASVIS	__BIT(18)
#define	 OTGSC_AVVIS	__BIT(17)
#define	 OTGSC_IDIS	__BIT(16)
#define	 OTGSC_DPS	__BIT(14)
#define	 OTGSC_1MST	__BIT(13)
#define	 OTGSC_BSE	__BIT(12)
#define	 OTGSC_BSV	__BIT(11)
#define	 OTGSC_ASV	__BIT(10)
#define	 OTGSC_AVV	__BIT( 9)
#define	 OTGSC_ID	__BIT( 8)
#define	 OTGSC_IDPU	__BIT( 5)
#define	 OTGSC_DP	__BIT( 4)
#define	 OTGSC_OT	__BIT( 3)
#define	 OTGSC_VC	__BIT( 1)
#define	 OTGSC_VD	__BIT( 0)
#define	IMXUSB_OTGMODE	0x01A8
#define	 USBMODE_DEVICE	(0x2 << 0)
#define	 USBMODE_HOST	(0x3 << 0)

#define	IMXUSB_EHCI_SIZE	0x200


/* extension to PORTSCx register of EHCI. */
#define	PORTSC_PTS_SHIFT	30
#define	PORTSC_PTS_MASK 	__BITS(PORTSC_PTS_SHIFT,31)
#define	PORTSC_PTS_UTMI		(0 << PORTSC_PTS_SHIFT)
#define	PORTSC_PTS_PHILIPS	(1 << PORTSC_PTS_SHIFT) /* not in i.MX51*/
#define	PORTSC_PTS_ULPI		(2 << PORTSC_PTS_SHIFT)
#define	PORTSC_PTS_SERIAL	(3 << PORTSC_PTS_SHIFT)

#define	PORTSC_STS	__BIT(29)	/* serial transeiver select */
#define	PORTSC_PTW	__BIT(28)	/* parallel transceiver width */
#define	PORTSC_PTW_8	0
#define	PORTSC_PTW_16	PORT_SC_PTW
#define	PORTSC_PSPD	__BITS(26,27)	/* port speed (RO) */
#define	PORTSC_PFSC	__BIT(24)	/* port force full speed */
#define	PORTSC_PHCD	__BIT(23)	/* PHY low power suspend */

#endif	/* _ARM_IMX_IMXUSBREG_H */
