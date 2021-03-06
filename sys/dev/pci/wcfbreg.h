/*	$NetBSD: wcfbreg.h,v 1.1 2010/03/10 05:16:17 macallan Exp $ */

/*-
 * Copyright (c) 2010 Michael Lorenz
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * register definitions for 3Dlabs Wildcat
 * mostly from OpenBSD's ifb driver
 */
 
#ifndef WCFBREG_H
#define WCFBREG_H

#define WC_RESOLUTION	0x8070	
#define WC_CONFIG	0x8074	/* contains log2(stride) in 0x00ff0000 */
#define WC_FB8_ADDR0	0x8080
#define WC_FB8_ADDR1	0x8084

#define WC_CMAP_INDEX	0x80bc
#define WC_CMAP_DATA	0x80c0

/*
 * 80e4 DPMS state register
 * States ``off'' and ``suspend'' need chip reprogramming before video can
 * be enabled again.
 */
#define	WC_DPMS_STATE		0x80e4
	#define	WC_DPMS_OFF			0x00000000
	#define	WC_DPMS_SUSPEND			0x00000001
	#define	WC_DPMS_STANDBY			0x00000002
	#define	WC_DPMS_ON			0x00000003

#endif
