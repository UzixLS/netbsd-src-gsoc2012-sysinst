# fixautomake.m4 serial 3 (gettext-0.13)
dnl Copyright (C) 2002-2003 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

dnl From Bruno Haible

dnl Fix unesthetic build commands generated by automake.
AC_DEFUN([FIX_MAKEFILE_COMPILE], [
  sed -e "s,\`test -f \\\$< || echo '\\\$(srcdir)/'\`\\\$<,\\\$<," -e "s,\`test -f '\\\$<' || echo '\\\$(srcdir)/'\`\\\$<,\\\$<," < $ac_file > $ac_file.tmp
  mv $ac_file.tmp $ac_file
])

dnl Fix an automake-1.5-1.7.2 bug: the distrib rule is omitted.
AC_DEFUN([FIX_MAKEFILE_DISTRIB], [
  sed -e 's,^#distdir:,distdir:,' < $ac_file > $ac_file.tmp
  mv $ac_file.tmp $ac_file
])

dnl Fix an automake-1.5-1.7.2 bug: all info files are erased by "make".
AC_DEFUN([FIX_MAKEFILE_INFO], [
  sed -e '/@rm -f \$''@/d' < $ac_file > $ac_file.tmp
  mv $ac_file.tmp $ac_file
])
