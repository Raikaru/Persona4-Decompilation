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

typedef int (*code)(...);

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
    BtlPacketFunc destroyFunc;
    u8 padding_74[4];
    void* workData;
} BtlPacket;

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern void func_001d7700(void);
extern u32 func_001d7760(void);
extern u32 func_001d79e0(u16 *param_1);
extern u32 func_001d7a60(u8 *param_1);

typedef u8 bool;

extern u32 func_001ef4d0();

extern u32 func_001ef720();

extern u16 func_001d7f10(u32 param_1, u32 param_2, u16 param_3, u32 param_4);
extern u32 func_00201f60(int param_1);



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



// FUN_001D7880
void func_001d7880(void)

{
  int iVar1 = 0;

  iVar1 = (int)func_00194470(0x306,0);
  *(u8 *)(iVar1 + 0x47) = *(u8 *)(iVar1 + 0x47) & 0xfe;
  *(code *)(iVar1 + 0x68) = (code)func_001d7700;
  *(code *)(iVar1 + 0x6c) = (code)func_001d7760;
  return;
}



// FUN_001D7A10
void func_001d7a10(u16 param_1)

{
  int iVar1 = 0;

  iVar1 = (int)func_00194470(0x308,2);
  *(code *)(iVar1 + 0x6c) = (code)func_001d79e0;
  **(u16 **)(iVar1 + 0x78) = param_1;
  return;
}



// FUN_001D7AB0
void func_001d7ab0(u8 *param_1,u16 param_2)

{
  typedef struct BtlMessageArgs {
    u8 values[4];
  } BtlMessageArgs;
  u8 *work;
  int packet = 0;

  packet = (int)func_00194470(0x30a,6);
  *(code *)(packet + 0x6c) = (code)func_001d7a60;
  work = *(u8 **)(packet + 0x78);
  *(BtlMessageArgs *)work = *(BtlMessageArgs *)param_1;
  *(u16 *)(work + 4) = param_2;
  return;
}


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



// FUN_001D99E0
bool btlCond_FRLV_O(int param_1, u32 param_2)
{
  u32 uVar1 = 0;

  uVar1 = func_001ef4d0(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000);
  return param_2 <= (uVar1 & 0xffff);
}


#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001D9A30 (MATCH nd0 -> MISMATCH nd49) - measured W161. */

// FUN_001D9A30
bool btlCond_ENLV_O(int param_1, u32 param_2)
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



// FUN_001D9AA0
bool btlCond_FRCNT(int param_1, u32 param_2)
{
  u32 uVar1 = 0;

  uVar1 = func_001ef720(1 << *(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) & 0xffff, 0x80000);
  return (uVar1 & 0xffff) <= param_2;
}


#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001D9AF0 (MATCH nd0 -> MISMATCH nd49) - measured W161. */

// FUN_001D9AF0
bool btlCond_ENCNT(int param_1, u32 param_2)
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



// FUN_001DA6F0
bool btlCond_MYUSESKIL(int param_1, int param_2)
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



// FUN_001DA7E0
u32 btlCond_MYGROUP(int param_1)
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



// FUN_001DA8F0
bool btlCond_TURN(int param_1, u32 param_2)
{
    return param_2 >= *(u32*)(param_1 + 0x20);
}



// FUN_001DA910
bool btlCond_TURN_O(int param_1, u32 param_2)
{
    return param_2 <= *(u32*)(param_1 + 0x20);
}



// FUN_001DACC0
bool btlCond_MYID(int param_1, int param_2)
{
    return *(u16*)(*(s32*)(param_1 + 0x30) + 0xa4) == param_2;
}



// FUN_00202010
void func_00202010(u32 param_1, u16 param_2)
{
  u32 *puVar1;
  int iVar2 = 0;

  iVar2 = (int)func_00194470(0x504, 0xc);
  *(code *)(iVar2 + 0x6c) = (code)func_00201f60;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  *(u16 *)(puVar1 + 1) = param_2;
  puVar1[2] = 0;
  return;
}
