/* This is a software floating point library which can be used instead of
   the floating point routines in libgcc1.c for targets without hardware
   floating point. 
 Copyright (C) 1994, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file with other programs, and to distribute
those programs without any restriction coming from the use of this
file.  (The General Public License restrictions do apply in other
respects; for example, they cover modification of the file, and
distribution when not linked into another program.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with other files,
   some of which are compiled with GCC, to produce an executable,
   this library does not by itself cause the resulting executable
   to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License.  */

/* Adapted from GCC releases/gcc-2.95/gcc/config/fp-bit.c, GOFAST float_to_usi.
 * Retail symbol and unpacker ABI retained. ee-gcc 2.96 -O2: 156B/160B,
 * zero differing instruction bytes; the final retail word is zero padding.
 * The accompanying license is in COPYING.gcc-runtime; these notices and
 * exceptions apply to this runtime source, not unrelated project files. */

#include "type.h"
extern void func_0044ddf0(u32 *, u32 *);
typedef enum { SNAN, QNAN, ZERO, NUMBER, INFINITY } FloatClass;
typedef struct { FloatClass kind; u32 sign; s32 exponent; u64 fraction; } FloatParts;
static __inline__ int iszero(FloatParts *p) { return p->kind == 2; }
static __inline__ int isnan(FloatParts *p) { return p->kind == SNAN || p->kind == QNAN; }
static __inline__ int isinf(FloatParts *p) { return p->kind == 4; }
// FUN_0044E830
u32 func_0044e830(f64 arg0)
{
    FloatParts parts;
    func_0044ddf0((u32 *)&arg0, (u32 *)&parts);
    if (iszero(&parts)) return 0;
    if (isnan(&parts)) return 0;
    if (parts.sign) return 0;
    if (isinf(&parts))
        return -1;
    if (parts.exponent < 0)
        return 0;
    if (parts.exponent > 31)
        return -1;
    if (parts.exponent > 60)
        return parts.fraction << (parts.exponent - 60);
    else
        return parts.fraction >> (60 - parts.exponent);
}
