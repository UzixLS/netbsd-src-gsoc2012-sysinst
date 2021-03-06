/* Native-dependent code for Alpha BSD's.

   Copyright (C) 2000, 2001, 2002, 2004, 2005 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#include "defs.h"
#include "inferior.h"
#include "regcache.h"

#include "alpha-tdep.h"
#include "alphabsd-tdep.h"
#include "inf-ptrace.h"

#include <sys/types.h>
#include <sys/ptrace.h>
#include <machine/reg.h>

#ifdef HAVE_SYS_PROCFS_H
#include <sys/procfs.h>
#endif

#ifndef HAVE_GREGSET_T
typedef struct reg gregset_t;
#endif

#ifndef HAVE_FPREGSET_T 
typedef struct fpreg fpregset_t; 
#endif 

#include "gregset.h"

/* Provide *regset() wrappers around the generic Alpha BSD register
   supply/fill routines.  */

void
supply_gregset (gregset_t *gregsetp)
{
  alphabsd_supply_reg (current_regcache, (char *) gregsetp, -1);
}

void
fill_gregset (gregset_t *gregsetp, int regno)
{
  alphabsd_fill_reg (current_regcache, (char *) gregsetp, regno);
}

void
supply_fpregset (fpregset_t *fpregsetp)
{
  alphabsd_supply_fpreg (current_regcache, (char *) fpregsetp, -1);
}

void
fill_fpregset (fpregset_t *fpregsetp, int regno)
{
  alphabsd_fill_fpreg (current_regcache, (char *) fpregsetp, regno);
}

/* Determine if PT_GETREGS fetches this register.  */

static int
getregs_supplies (int regno)
{
  return ((regno >= ALPHA_V0_REGNUM && regno <= ALPHA_ZERO_REGNUM)
	  || regno >= ALPHA_PC_REGNUM);
}

/* Fetch register REGNO from the inferior.  If REGNO is -1, do this
   for all registers (including the floating point registers).  */

static void
alphabsd_fetch_inferior_registers (int regno)
{
  if (regno == -1 || getregs_supplies (regno))
    {
      struct reg gregs;

      if (ptrace (PT_GETREGS, PIDGET (inferior_ptid),
		  (PTRACE_TYPE_ARG3) &gregs, TIDGET (inferior_ptid)) == -1)
	perror_with_name (_("Couldn't get registers"));

      alphabsd_supply_reg (current_regcache, (char *) &gregs, regno);
      if (regno != -1)
	return;
    }

  if (regno == -1 || regno >= FP0_REGNUM)
    {
      struct fpreg fpregs;

      if (ptrace (PT_GETFPREGS, PIDGET (inferior_ptid),
		  (PTRACE_TYPE_ARG3) &fpregs, TIDGET (inferior_ptid)) == -1)
	perror_with_name (_("Couldn't get floating point status"));

      alphabsd_supply_fpreg (current_regcache, (char *) &fpregs, regno);
    }
}

/* Store register REGNO back into the inferior.  If REGNO is -1, do
   this for all registers (including the floating point registers).  */

static void
alphabsd_store_inferior_registers (int regno)
{
  if (regno == -1 || getregs_supplies (regno))
    {
      struct reg gregs;
      if (ptrace (PT_GETREGS, PIDGET (inferior_ptid),
                  (PTRACE_TYPE_ARG3) &gregs, TIDGET (inferior_ptid)) == -1)
        perror_with_name (_("Couldn't get registers"));

      alphabsd_fill_reg (current_regcache, (char *) &gregs, regno);

      if (ptrace (PT_SETREGS, PIDGET (inferior_ptid),
                  (PTRACE_TYPE_ARG3) &gregs, TIDGET (inferior_ptid)) == -1)
        perror_with_name (_("Couldn't write registers"));

      if (regno != -1)
	return;
    }

  if (regno == -1 || regno >= FP0_REGNUM)
    {
      struct fpreg fpregs;

      if (ptrace (PT_GETFPREGS, PIDGET (inferior_ptid),
		  (PTRACE_TYPE_ARG3) &fpregs, TIDGET (inferior_ptid)) == -1)
	perror_with_name (_("Couldn't get floating point status"));

      alphabsd_fill_fpreg (current_regcache, (char *) &fpregs, regno);

      if (ptrace (PT_SETFPREGS, PIDGET (inferior_ptid),
		  (PTRACE_TYPE_ARG3) &fpregs, TIDGET (inferior_ptid)) == -1)
	perror_with_name (_("Couldn't write floating point status"));
    }
}

/* Provide a prototype to silence -Wmissing-prototypes.  */
void _initialize_alphabsd_nat (void);

void
_initialize_alphabsd_nat (void)
{
  struct target_ops *t;

  t = inf_ptrace_target ();
  t->to_fetch_registers = alphabsd_fetch_inferior_registers;
  t->to_store_registers = alphabsd_store_inferior_registers;
  add_target (t);
}
