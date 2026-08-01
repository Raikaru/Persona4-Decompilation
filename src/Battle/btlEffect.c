/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001D8DF0)
/* Source unit: src/Battle/btlEffect_001d8df0.c */
#include "type.h"

/* Ported from P3FES FUN_002c09f0 (verified MATCH there), which is compiled
 * inside the donor's opt_loop_invariants on region. Removing it here measured
 * MATCH nd0 -> MISMATCH nd50 (object 100/96), matching the donor's own
 * recorded W161 annotation of nd0 -> nd50. */
#pragma opt_loop_invariants on
// FUN_001D8DF0
u32 func_001d8df0(int param_1)
{
  u32 result;
  u16 count;
  s32 index;
  u32 bit;

  result = 0;
  index = 0;
  count = *(u16 *)(param_1 + 0x38);
  bit = 1;
  for (; (index & 0xffff) < count; index = (u16)(index + 1)) {
    u8 genus = *(u8 *)(*(int *)(*(int *)(param_1 + (u16)index * 4) + 0x30) + 0xa2);
    result = (result | ((bit << genus) & 0xffff)) & 0xffff;
  }
  return result;
}
#pragma opt_loop_invariants off
#endif /* P4_UNIT_001D8DF0 */

#if defined(P4_UNIT_001DA6F0)
/* Source unit: src/Battle/btlEffect_001da6f0.c */
#include "type.h"

typedef u8 bool;

// FUN_001DA6F0
bool func_001da6f0(int param_1, int param_2)
{
    bool result;

    switch (*(u16*)(param_1 + 0x7c))
    {
    default:
        result = 0;
        break;
    case 1:
    case 2:
        result = *(u16*)(param_1 + 0x7e) == param_2;
        break;
    }
    return result;
}
#endif /* P4_UNIT_001DA6F0 */

#if defined(P4_UNIT_001DA8F0)
/* Source unit: src/Battle/btlEffect_001da8f0.c */
#include "type.h"

typedef u8 bool;

// FUN_001DA8F0
bool func_001da8f0(int param_1, u32 param_2)
{
    return param_2 >= *(u32*)(param_1 + 0x20);
}
#endif /* P4_UNIT_001DA8F0 */

#if defined(P4_UNIT_001DA910)
/* Source unit: src/Battle/btlEffect_001da910.c */
#include "type.h"

typedef u8 bool;

// FUN_001DA910
bool func_001da910(int param_1, u32 param_2)
{
    return param_2 <= *(u32*)(param_1 + 0x20);
}
#endif /* P4_UNIT_001DA910 */

#if defined(P4_UNIT_001DACC0)
/* Source unit: src/Battle/btlEffect_001dacc0.c */
#include "type.h"

typedef u8 bool;

// FUN_001DACC0
bool func_001dacc0(int param_1, int param_2)
{
    return *(u16*)(*(s32*)(param_1 + 0x30) + 0xa4) == param_2;
}
#endif /* P4_UNIT_001DACC0 */

#if defined(P4_UNIT_00108D80)
/* Source unit: src/Battle/btlEffect_00108d80.c */
#include "type.h"

extern char D_005e4308[];
extern long func_00452380(void* path);
extern void func_00452080(long handle);

// FUN_00108D80
void func_00108d80(void)
{
  long handle;

  if ((handle = func_00452380(D_005e4308)) == 0) {
    return;
  }
  func_00452080(handle);
  return;
}
#endif /* P4_UNIT_00108D80 */

#if defined(P4_UNIT_001D6880)
/* Source unit: src/Battle/btlEffect_001d6880.c */
#include "type.h"

typedef struct BtlFormationWork {
  u32 state;
  u32 list;
  u32 argument5;
  u8 padding0c[4];
  s32 sentinel;
  u8 random;
  u8 padding15[3];
  u32 argument3;
  u32 argument4;
  u8 padding20[0x34];
  u16 count;
  u16 padding56;
  u32 items;
} BtlFormationWork;

extern void func_001d42e0(BtlFormationWork* param_1);
extern void func_00485b20(u32 param_1);
extern void func_004787e0(u32 param_1);

// FUN_001D6880
void func_001d6880(u16 *param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    func_001d42e0((BtlFormationWork *)*(int *)(param_1 + 8));
    *(u32 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 10) != 0) {
    func_00485b20(*(int *)(param_1 + 10));
    *(u32 *)(param_1 + 10) = 0;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    func_004787e0(*(int *)(param_1 + 0xc));
    *(u32 *)(param_1 + 0xc) = 0;
  }
  *(u32 *)(param_1 + 2) = 0xffffffff;
  *(u8 *)(param_1 + 4) = 0x14;
  *(u32 *)(param_1 + 6) = 0;
  *param_1 = 0x200;
  return;
}
#endif /* P4_UNIT_001D6880 */

#if defined(P4_UNIT_001D6CE0)
/* Source unit: src/Battle/btlEffect_001d6ce0.c */
#include "type.h"

typedef struct BtlFormationWork {
  u32 state;
  u32 list;
  u32 argument5;
  u8 padding0c[4];
  s32 sentinel;
  u8 random;
  u8 padding15[3];
  u32 argument3;
  u32 argument4;
  u8 padding20[0x34];
  u16 count;
  u16 padding56;
  u32 items;
} BtlFormationWork;

extern void func_001d42e0(BtlFormationWork* param_1);
extern void func_00485b20(u32 param_1);
extern void func_004787e0(u32 param_1);

// FUN_001D6CE0
u16 *func_001d6ce0(int param_1)
{
  u16 *entry;
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if ((*(u32 *)(param_1 + 0xc0) & mask) == 0) {
      entry = *(u16 **)(param_1 + index * 4);
      if (*(int *)(entry + 8) != 0) {
        func_001d42e0((BtlFormationWork *)*(int *)(entry + 8));
        *(u32 *)(entry + 8) = 0;
      }
      if (*(int *)(entry + 10) != 0) {
        func_00485b20(*(int *)(entry + 10));
        *(u32 *)(entry + 10) = 0;
      }
      if (*(int *)(entry + 0xc) != 0) {
        func_004787e0(*(int *)(entry + 0xc));
        *(u32 *)(entry + 0xc) = 0;
      }
      *(u32 *)(entry + 2) = 0xffffffff;
      *(u8 *)(entry + 4) = 0x14;
      *(u32 *)(entry + 6) = 0;
      *entry = 0x200;
      *(u32 *)(param_1 + 0xc0) |= mask;
      return entry;
    }
    mask <<= 1;
    index++;
  }
  return NULL;
}
#endif /* P4_UNIT_001D6CE0 */

#if defined(P4_UNIT_001D6DE0)
/* Source unit: src/Battle/btlEffect_001d6de0.c */
#include "type.h"

typedef struct BtlFormationWork {
  u32 state;
  u32 list;
  u32 argument5;
  u8 padding0c[4];
  s32 sentinel;
  u8 random;
  u8 padding15[3];
  u32 argument3;
  u32 argument4;
  u8 padding20[0x34];
  u16 count;
  u16 padding56;
  u32 items;
} BtlFormationWork;

extern void func_001d42e0(BtlFormationWork* param_1);
extern void func_00485b20(u32 param_1);
extern void func_004787e0(u32 param_1);

// FUN_001D6DE0
u32 func_001d6de0(int param_1, u16 *entry)
{
  u32 index;
  u32 mask;

  mask = 1;
  index = 0;
  while (index < 0x30) {
    if (*(u16 **)(param_1 + index * 4) == entry) {
      if (*(int *)(entry + 8) != 0) {
        func_001d42e0((BtlFormationWork *)*(int *)(entry + 8));
        *(u32 *)(entry + 8) = 0;
      }
      if (*(int *)(entry + 10) != 0) {
        func_00485b20(*(int *)(entry + 10));
        *(u32 *)(entry + 10) = 0;
      }
      if (*(int *)(entry + 0xc) != 0) {
        func_004787e0(*(int *)(entry + 0xc));
        *(u32 *)(entry + 0xc) = 0;
      }
      *(u32 *)(entry + 2) = 0xffffffff;
      *(u8 *)(entry + 4) = 0x14;
      *(u32 *)(entry + 6) = 0;
      *entry = 0x200;
      *(u32 *)(param_1 + 0xc0) &= ~mask;
      return 1;
    }
    mask <<= 1;
    index++;
  }
  return 0;
}
#endif /* P4_UNIT_001D6DE0 */

#if defined(P4_UNIT_001D7880)
/* Source unit: src/Battle/btlEffect_001d7880.c */
#include "type.h"

typedef int (*code)(...);

extern int func_00194470(u32 type, u32 workSize);
extern void func_001d7700(void);
extern u32 func_001d7760(void);

// FUN_001D7880
void func_001d7880(void)

{
  int iVar1 = 0;

  iVar1 = func_00194470(0x306,0);
  *(u8 *)(iVar1 + 0x47) = *(u8 *)(iVar1 + 0x47) & 0xfe;
  *(code *)(iVar1 + 0x68) = (code)func_001d7700;
  *(code *)(iVar1 + 0x6c) = (code)func_001d7760;
  return;
}
#endif /* P4_UNIT_001D7880 */

#if defined(P4_UNIT_001D7A10)
/* Source unit: src/Battle/btlEffect_001d7a10.c */
#include "type.h"

typedef int (*code)(...);

extern int func_00194470(u32 type, u32 workSize);
extern u32 func_001d79e0(u16 *param_1);

// FUN_001D7A10
void func_001d7a10(u16 param_1)

{
  int iVar1 = 0;

  iVar1 = func_00194470(0x308,2);
  *(code *)(iVar1 + 0x6c) = (code)func_001d79e0;
  **(u16 **)(iVar1 + 0x78) = param_1;
  return;
}
#endif /* P4_UNIT_001D7A10 */

#if defined(P4_UNIT_001D7AB0)
/* Source unit: src/Battle/btlEffect_001d7ab0.c */
#include "type.h"

typedef int (*code)(...);

extern int func_00194470(u32 type, u32 workSize);
extern u32 func_001d7a60(u8 *param_1);

// FUN_001D7AB0
void func_001d7ab0(u8 *param_1,u16 param_2)

{
  typedef struct BtlMessageArgs {
    u8 values[4];
  } BtlMessageArgs;
  u8 *work;
  int packet = 0;

  packet = func_00194470(0x30a,6);
  *(code *)(packet + 0x6c) = (code)func_001d7a60;
  work = *(u8 **)(packet + 0x78);
  *(BtlMessageArgs *)work = *(BtlMessageArgs *)param_1;
  *(u16 *)(work + 4) = param_2;
  return;
}
#endif /* P4_UNIT_001D7AB0 */

#if defined(P4_UNIT_001D99E0)
/* Source unit: src/Battle/btlEffect_001d99e0.c */
#include "type.h"

typedef u8 bool;

extern u32 func_001ef4d0();

// FUN_001D99E0
bool func_001d99e0(int param_1, u32 param_2)
{
  u32 uVar1 = 0;

  uVar1 = func_001ef4d0(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000);
  return param_2 <= (uVar1 & 0xffff);
}
#endif /* P4_UNIT_001D99E0 */

#if defined(P4_UNIT_001D9A30)
/* Source unit: src/Battle/btlEffect_001d9a30.c */
#include "type.h"

typedef u8 bool;

extern u32 func_001ef4d0();

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001D9A30 (MATCH nd0 -> MISMATCH nd49) - measured W161. */
// FUN_001D9A30
bool func_001d9a30(int param_1, u32 param_2)
{
  u32 uVar1 = 0;
  u16 genus;
  u32 shift;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
    goto nonzero;
  shift = 1;
  goto done;
nonzero:
  shift = 0;
done:
  genus = shift;
  uVar1 = func_001ef4d0(1 << genus & 0xffff, 0x80000);
  return param_2 <= (uVar1 & 0xffff);
}
#pragma opt_rebuildconditionals on
#endif /* P4_UNIT_001D9A30 */

#if defined(P4_UNIT_001D9AA0)
/* Source unit: src/Battle/btlEffect_001d9aa0.c */
#include "type.h"

typedef u8 bool;

extern u32 func_001ef720();

// FUN_001D9AA0
bool func_001d9aa0(int param_1, u32 param_2)
{
  u32 uVar1 = 0;

  uVar1 = func_001ef720(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000);
  return (uVar1 & 0xffff) <= param_2;
}
#endif /* P4_UNIT_001D9AA0 */

#if defined(P4_UNIT_001D9AF0)
/* Source unit: src/Battle/btlEffect_001d9af0.c */
#include "type.h"

typedef u8 bool;

extern u32 func_001ef720();

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001D9AF0 (MATCH nd0 -> MISMATCH nd49) - measured W161. */
// FUN_001D9AF0
bool func_001d9af0(int param_1, u32 param_2)
{
  u32 uVar1 = 0;
  u16 genus;
  {
    u32 shift;
    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
      goto nonzero;
    shift = 1;
    goto done;
nonzero:
    shift = 0;
done:
    genus = shift;
  }
  uVar1 = func_001ef720(1 << genus & 0xffff, 0x80000);
  return (uVar1 & 0xffff) <= param_2;
}
#pragma opt_rebuildconditionals on
#endif /* P4_UNIT_001D9AF0 */

#if defined(P4_UNIT_001DA7E0)
/* Source unit: src/Battle/btlEffect_001da7e0.c */
#include "type.h"

typedef u8 bool;

extern u16 func_001d7f10(u32 param_1, u32 param_2, u16 param_3, u32 param_4);

// FUN_001DA7E0
u32 func_001da7e0(int param_1)
{
  u16 result;

  result = func_001d7f10(param_1, 0, *(u16 *)(param_1 + 0x7e), 0);
  switch (result) {
  case 1:
  case 2:
    return 1;
  default:
    return 0;
  }
}
#endif /* P4_UNIT_001DA7E0 */

#if defined(P4_UNIT_001DB100)
/* Source unit: src/Battle/btlEffect_001db100.c */
#include "type.h"

typedef u8 bool;
typedef int (*code)(...);

extern u32 func_001d94d0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
extern bool func_001da2f0(int param_1, short param_2);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB100 (MATCH nd0 -> MISMATCH nd43) - measured W161. */
// FUN_001DB100
void func_001db100(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  func_001d94d0(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 7,
                 (code *)&func_001da2f0);
  return;
}
#pragma opt_rebuildconditionals on
#endif /* P4_UNIT_001DB100 */

#if defined(P4_UNIT_001DB6E0)
/* Source unit: src/Battle/btlEffect_001db6e0.c */
#include "type.h"

typedef int (*code)(...);

extern u32 func_001d94d0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
extern void func_001db580(int param_1, u16 param_2);

#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB6E0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */
// FUN_001DB6E0
void func_001db6e0(int param_1, u32 param_2)
{
  u32 shift;

  {
      if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0)
          goto nonzero;
      shift = 1;
      goto done;
  nonzero:
      shift = 0;
  done:
      ;
  }
  func_001d94d0(param_1, param_2, 1 << (shift & 0xffff) & 0xffff, 0x80000, 0xb,
                 (code *)&func_001db580);
  return;
}
#pragma opt_rebuildconditionals on
#endif /* P4_UNIT_001DB6E0 */

#if defined(P4_UNIT_001DB740)
/* Source unit: src/Battle/btlEffect_001db740.c */
#include "type.h"

typedef u8 bool;

extern u64 func_0010f460();

// FUN_001DB740
bool func_001db740(int param_1)
{
  long lVar2 = 0;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 1) {
    return 0;
  }
  lVar2 = func_0010f460(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
  return lVar2 != 0;
}
#endif /* P4_UNIT_001DB740 */

#if defined(P4_UNIT_001DEEE0)
/* Source unit: src/Battle/btlEffect_001deee0.c */
#include "type.h"

extern u64 func_00452490();

// FUN_001DEEE0
u32 func_001deee0(int param_1)
{
  u32 uVar1 = 0;
  long lVar2 = 0;

  if (*(u8 *)(param_1 + 0x30) == 0) {
    uVar1 = 1;
  }
  else if (*(int *)(param_1 + 0x4c) == 0) {
    uVar1 = 1;
  }
  else {
    lVar2 = func_00452490(*(int *)(param_1 + 0x4c));
    if (lVar2 == 0) {
      *(u8 *)(param_1 + 0x30) = 0;
      *(u32 *)(param_1 + 0x4c) = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}
#endif /* P4_UNIT_001DEEE0 */

#if defined(P4_UNIT_001DEF60)
/* Source unit: src/Battle/btlEffect_001def60.c */
#include "type.h"

// FUN_001DEF60
u32 func_001def60(void)
{
  extern u32 func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = (char *)func_0029d050();

  func_001de640(pVar1, pVar1 + 0x38, 0x8000);
  return 1;
}
#endif /* P4_UNIT_001DEF60 */

#if defined(P4_UNIT_001DF0C0)
/* Source unit: src/Battle/btlEffect_001df0c0.c */
#include "type.h"

// FUN_001DF0C0
u32 func_001df0c0(void)
{
  extern u32 func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8001);
  return 1;
}
#endif /* P4_UNIT_001DF0C0 */

#if defined(P4_UNIT_001DF100)
/* Source unit: src/Battle/btlEffect_001df100.c */
#include "type.h"

// FUN_001DF100
u32 func_001df100(void)
{
  extern u32 func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8002);
  return 1;
}
#endif /* P4_UNIT_001DF100 */

#if defined(P4_UNIT_001DF2D0)
/* Source unit: src/Battle/btlEffect_001df2d0.c */
#include "type.h"

// FUN_001DF2D0
u32 func_001df2d0(void)
{
  extern u32 func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8007);
  return 1;
}
#endif /* P4_UNIT_001DF2D0 */

#if defined(P4_UNIT_00202010)
/* Source unit: src/Battle/btlEffect_00202010.c */
#include "type.h"

typedef int (*code)(...);

extern u32 func_00194470();
extern u32 func_00201f60(int param_1);

// FUN_00202010
void func_00202010(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = func_00194470(0x504, 0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_00201f60;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}
#endif /* P4_UNIT_00202010 */
