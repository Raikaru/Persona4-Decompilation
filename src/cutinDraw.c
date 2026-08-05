#include "include_asm.h"
/* Source unit: src/cutinDraw_00120bc0.c */
#include "type.h"

extern char D_005E4FA0[];
extern char D_005E4FB8[];
extern char iGpffff9c28;
extern u32 D_005DC974[];

void func_00440b68();
void func_00442088();
s32 func_00454a60();
s32 func_004553c0();
s32 func_00455f70();
void func_0045af60();
s32 func_004b1130();
void func_004b1190();
void func_004b11d0();
void func_004b1250();
s32 func_004b1520();
s32 func_004b1540();
void func_004b1560();

extern void (*jtbl_008873EC[])(void *ptr);

void func_004b1150();
void func_00454bd0();
extern char D_005E4FC8[];
extern u8 *(*D_008873F4[])(s32, s32, s32);

void func_0044ea90();
s32 func_00451de0();
s32 func_00120bc0(u8 *arg0);
void func_00120db0();



// FUN_00120BC0
s32 func_00120bc0(u8 *arg0)
{
    struct {
        f32 x;
        f32 y;
        s32 z;
    } sp220;
    u8 sp120[0x100];
    u8 sp20[0x100];
    s32 temp_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        func_00442088(sp120, D_005E4FA0, *(s16 *)(temp_16 + 4),
                      *(s16 *)(temp_16 + 6));
        func_00440b68(&iGpffff9c28, D_005E4FB8, 0x28);
        *(s32 *)(temp_16 + 0x28) = func_00454a60(sp120, 0);
        *(s32 *)temp_16 = 1;
        break;
    case 1:
        if (func_004553c0(*(s32 *)(temp_16 + 0x28)) != 0) {
            func_00442088(sp20, D_005E4FA0, *(s16 *)(temp_16 + 4),
                          *(s16 *)(temp_16 + 6));
            *(s32 *)(temp_16 + 0x24) = func_004b1130(func_00455f70(sp20, 0));
            *(s32 *)temp_16 = 2;
        }
        break;
    case 2:
        sp220.x = *(f32 *)(temp_16 + 0x1C);
        sp220.y = *(f32 *)(temp_16 + 0x20);
        sp220.z = 0;
        if (*(s32 *)(temp_16 + 0x14) != 0) {
            if (*(s32 *)(temp_16 + 0xC) != 0 && *(s32 *)(temp_16 + 0x10) != 0) {
                func_004b1560(*(s32 *)(temp_16 + 0x24));
                *(s32 *)(temp_16 + 0x10) = 0;
                *(s32 *)(temp_16 + 0xC) = 0;
            }
            if (*(s32 *)(temp_16 + 0x18) == 0) {
                func_0045af60(0, 0, 5, 0);
                *(s32 *)(temp_16 + 0x18) = 1;
            }
            func_004b1250(*(s32 *)(temp_16 + 0x24), &sp220);
            func_004b1190(*(s32 *)(temp_16 + 0x24));
            func_004b11d0(D_005DC974, *(s32 *)(temp_16 + 0x24));
            if (func_004b1540(*(s32 *)(temp_16 + 0x24)) != 0) {
                *(s32 *)(temp_16 + 0xC) = 1;
            }
            if (func_004b1520(*(s32 *)(temp_16 + 0x24)) != 0) {
                return -1;
            }
        }
        break;
    }
    return 0;
}



// FUN_00120DB0
void func_00120db0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 0x24) != 0) {
        func_004b1150(*(s32 *)(temp_16 + 0x24));
    }
    if (*(s32 *)(temp_16 + 0x28) != 0) {
        func_00454bd0(*(s32 *)(temp_16 + 0x28));
        *(s32 *)(temp_16 + 0x28) = 0;
    }
    (*jtbl_008873EC)(temp_16);
}



// REACHABLE BUT NOT WITH HONEST SOURCE. tools/permute_ast.py cracks this in 28
// compiles (~15s), reproducibly:
//
//   python tools/permute_ast.py src/cutinDraw.c func_00120e20 --time 900 --seed 5
//
// after activating the body below. Verified MATCH at 180B. The winning form needs
// an empty `if (arg1) { }`, `hi` typed `unsigned int` rather than s16, and the lo
// load taken through a named `s16 *` temp. Four reductions toward clean C were
// measured and all fall back to MISMATCH: dropping the s16* temp, dropping the u8*
// store temp, dropping the empty if, and a hand-written clean version carrying the
// u32 type plus both pointer temps. Only the s16* temp is defensible source; the
// empty if is dead code, so the raw winner is not committable under the
// source-honesty policy. The nd-4 body below stays -- its residual is the two
// halfword loads assigned to swapped registers ($a0/$v1 against 0x1c/0x1e).
// Anyone reducing this further should start from the permuter output, not by hand.
/* Retail splits arg1 into halves through the STACK, not with a shift: the value is
   copied to a local before the first call and the two s16 halves are then read back
   through its address. Two things here look redundant and are load-bearing - the
   `result` scratch that feeds `lo`, and the `if (result == 0) return 0;` ahead of the
   final `return result;`. Removing either scores nd 17, measured. Recovered with
   permute_ast + permute_min; the reduction needed no dead code, so it cleaned up to
   ordinary C (renames and cast tidying verified byte-identical). */
// FUN_00120E20
s32 func_00120e20(s32 arg0, s32 arg1)
{
  u8 *work;
  s32 packed;
  s32 result;
  s16 lo;
  s16 hi;
  packed = arg1;
  func_0044ea90(D_005E4FB8, 0x68);
  work = D_008873F4[0](1, 0x2C, 0x40000);
  if (work == NULL)
  {
    return 0;
  }
  result = *(s16 *)&packed;
  lo = result;
  hi = *(s16 *)((u8 *)&packed + 2);
  *(s16 *)(work + 4) = lo;
  *(s16 *)(work + 6) = hi;
  result = func_00451de0(D_005E4FC8, 0xF, 0, 0, func_00120bc0, func_00120db0, work);
  if (result == 0)
  {
    return 0;
  }
  return result;
}
