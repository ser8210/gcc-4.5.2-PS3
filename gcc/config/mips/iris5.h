/* Definitions of target machine for GNU compiler.  IRIX version 5.
   Copyright (C) 1993, 1995, 1996, 1998, 2000,
   2001, 2002, 2003, 2004, 2007, 2010 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifdef IRIX_USING_GNU_LD
#define IRIX_SUBTARGET_LINK_SPEC "-melf32bsmip"
#else
#define IRIX_SUBTARGET_LINK_SPEC "-_SYSTYPE_SVR4"
#endif

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "\
%{!static: \
  %{!shared:%{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s libprof1.a%s}%{!p:crt1.o%s}}}} \
%{static: \
  %{pg:gcrt1.o%s} \
  %{!pg:%{p:/usr/lib/nonshared/mcrt1.o%s libprof1.a%s} \
  %{!p:/usr/lib/nonshared/crt1.o%s}}} \
irix-crti.o%s crtbegin.o%s"

#undef LIB_SPEC
#define LIB_SPEC "%{!shared:%{p:-lprof1} %{pg:-lprof1} -lc}"

/* Avoid getting two warnings for libgcc.a everytime we link. */
#undef LIBGCC_SPEC
#define LIBGCC_SPEC \
  SUBTARGET_DONT_WARN_UNUSED_SPEC " -lgcc " SUBTARGET_WARN_UNUSED_SPEC

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s irix-crtn.o%s %{!shared:crtn.o%s}"

#undef MACHINE_TYPE
#define MACHINE_TYPE "SGI running IRIX 5.x"
