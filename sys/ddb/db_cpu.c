/*	$NetBSD: db_cpu.c,v 1.4 2011/02/20 10:24:45 hannken Exp $	*/

/*-
 * Copyright (c) 2009 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Andrew Doran.
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

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: db_cpu.c,v 1.4 2011/02/20 10:24:45 hannken Exp $");

#ifndef _KERNEL
#include <stdbool.h>
#endif

#include <sys/param.h>
#include <sys/cpu.h>
#include <sys/proc.h>

#include <ddb/ddb.h>

static struct cpu_info	*head;
static void *head_addr;

struct cpu_info *
db_cpu_first(void)
{

	head = db_read_ptr("cpu_queue");
	(void) db_value_of_name("cpu_queue", (db_expr_t *)&head_addr);
	return head;
}

struct cpu_info *
db_cpu_next(struct cpu_info *ci)
{

	db_read_bytes((db_addr_t)&ci->ci_data.cpu_qchain.cqe_next,
	    sizeof(ci), (char *)&ci);
	if (ci == head_addr) {
		ci = NULL;
	}
	return ci;
}
