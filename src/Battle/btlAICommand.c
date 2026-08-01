/* Source unit: src/Battle/btlEffect_001db100.c */
#include "type.h"

typedef u8 bool;
typedef int (*code)(...);

extern u32 func_001d94d0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, code *param_6);
extern bool btlCond_MYWEAK(int param_1, short param_2);

s32 func_001db360(u64 formation, u16 index, s32 enabled);
/* definition (FUN_001DB580) is byte-verified; the extern's `int` first
   parameter was a guessed prototype and clashed with the merged definition */
extern void btlCond_MYNOMAL(u64 formation, u16 index);

extern u64 func_0010f460();

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

typedef void (*FormationCallback)(void);

void func_001dbba0(u64 formation, u32 flags, s32 arg2, s32 arg3, s32 variant, FormationCallback callback);
void btlCond_MYBAD(void);

extern u64 func_00452490();

extern u8 *func_001b0cc0();
extern s32 func_001de000();
extern s64 func_0029cc00();
extern void func_0029cf50();
extern u8 *func_0029d050();


#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB100 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB100
void btlCond_ENWEAK_DW_PAI(int param_1, u32 param_2)
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
                 (code *)&btlCond_MYWEAK);
  return;
}
#pragma opt_rebuildconditionals on



// FUN_001DB580
void btlCond_MYNOMAL(u64 formation, u16 index)
{
    func_001db360(formation, index, 1);
}



// FUN_001DB5B0
void func_001db5b0(u64 formation, u16 index)
{
    func_001db360(formation, index, 0);
}


#pragma opt_rebuildconditionals off
/* Removing this loses FUN_001DB6E0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */

// FUN_001DB6E0
void btlCond_ENNOMAL_DW(int param_1, u32 param_2)
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
                 (code *)&btlCond_MYNOMAL);
  return;
}
#pragma opt_rebuildconditionals on



// FUN_001DB740
bool btlCond_ANALYZE(int param_1)
{
  long lVar2 = 0;
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 1) {
    return 0;
  }
  lVar2 = func_0010f460(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4));
  return lVar2 != 0;
}



// FUN_001DB790
s32 btlCond_DOWN(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 8) ? 0 : 1;
}



// FUN_001DB7B0
s32 btlCond_SLIP(u8 *arg0) {
    return (**(u16 **)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64) & 0x10) ? 0 : 1;
}



// FUN_001DB900
s32 btlCond_MYTAISEI(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x10000000) != 0);
}



// FUN_001DCB50
void func_001dcb50(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 0, btlCond_MYBAD);
}



// FUN_001DCB90
void func_001dcb90(u64 formation)
{
    func_001dbba0(formation, 0x100000, 0, 0, 1, btlCond_MYBAD);
}



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



// FUN_001DEF60
u32 func_001def60(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = (char *)func_0029d050();

  func_001de640(pVar1, pVar1 + 0x38, 0x8000);
  return 1;
}



// FUN_001DF0C0
u32 func_001df0c0(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8001);
  return 1;
}



// FUN_001DF100
u32 func_001df100(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8002);
  return 1;
}



// FUN_001DF2D0
u32 func_001df2d0(void)
{
  extern u8 *func_0029d050(void);
  extern void func_001de640(void *, void *, u16);
  char *pVar1 = 0;

  pVar1 = (char *)func_0029d050();
  func_001de640(pVar1, pVar1 + 0x38, 0x8007);
  return 1;
}



// FUN_001E6820
s32 func_001e6820(void) {
    s64 temp_16;
    s64 temp_17;
    u8 *temp_18;

    temp_18 = (u8 *)(func_0029d050());
    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_0029cf50(~func_001de000(temp_18, func_001b0cc0((u64) temp_17 & 0xFFFFFFF), (s16) temp_16, 0) != 0);
    return 1;
}



// FUN_001E68C0
s32 func_001e68c0(void) {
    s64 temp_16;

    func_0029d050();
    temp_16 = func_0029cc00(0);
    func_0029cc00(1);
    func_001b0cc0((u64) temp_16 & 0xFFFFFFF);
    func_0029cf50(0U);
    return 1;
}



// FUN_001E6A00
s32 func_001e6a00(void) {
    func_0029cf50(*(u8 *)(*(u8 **)(func_001b0cc0((u64) func_0029cc00(0) & 0xFFFFFFF) + 0x30) + 0xA2) == 0);
    return 1;
}
