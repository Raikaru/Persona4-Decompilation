/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldUnit.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*DAT_008873EC[])(void *);
extern s32 (*DAT_008873F4[])(s32, s32, s32);

extern s32 iGpffffb2e8;
extern s32 iGpffffb260;
extern s32 iGpffffb2e4;
extern s32 iGpffffb274;
extern u8 *iGpffffb414;
extern s32 D_00764344;
extern s32 D_00724504;
extern u8 *iGpffff9db0;
extern u8 iGpffff9f28;
extern u8 iGpffff9f29;
extern u8 iGpffff9f2a;
extern u8 iGpffff9f2b;
extern u8 iGpffff9f24;
extern s32 func_0014b870(s32 arg0, s32 arg1);
extern void func_002319c0(s32 arg0);
extern s32 func_0047ae90(s32 arg0, u16 arg1);
extern s32 func_004553c0(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_0043f810(void *arg0, s32 arg1, s32 arg2);
extern s32 func_001619b0(u16 arg0, u16 arg1, u16 arg2);
extern s32 func_00161a70(u16 arg0, u16 arg1, u16 arg2);
extern void func_00182310(s32 arg0);
extern s32 func_00164570(u32 arg0, s32 arg1);
extern u8 *func_00231630(u32 arg0, s32 arg1, s32 arg2);
extern u8 *func_00163990(u32 arg0, u8 *arg1, s32 arg2);
extern void func_00442088(void *dst, const void *fmt, s32 value);
extern void func_0046d740(const void *msg, const void *file, u32 line);
extern u32 func_003b7060(void);
extern u8 *func_00145270(s32 arg0);
extern s32 func_00145540(s32 arg0, u8 arg1, u8 *arg2);
extern void func_00479940(u8 *arg0, s32 arg1, s16 arg2, s32 arg3, s32 arg4);
extern void func_0047aa30(u8 *arg0, u8 *arg1);
extern s32 func_0014c780(void);
extern void func_0017b9a0(s32 arg0, f32 arg1);
extern void func_0047a1e0(void *arg0, void *arg1, s32 arg2);
extern void func_003e05d0(u8 *arg0);
extern void func_00168de0(s32 arg0, void *arg1, f32 arg2);
extern void func_00168ae0();
extern void func_0014b0c0(s32 arg0, s32 arg1);
extern void func_00168730(s32 arg0, s32 arg1);
extern void func_00168780(s32 arg0, f32 arg1);
extern s32 func_00478750(s32 arg0);
extern f32 func_00168770(s32 arg0);
extern void func_00478e70(u8 *arg0);
extern s32 func_00182220(s32 arg0, u8 *arg1, s32 arg2);
extern s32 func_002319f0(s32 arg0);
extern s32 func_0016fd00(s32 arg0);
extern s32 func_0017e890(s32 arg0, u8 *arg1, u8 *arg2);
extern void func_0017e990(s32 arg0);
extern s32 func_0017d070(s32 arg0);
extern void func_00168c00(s32 arg0);
extern f32 func_003e4180(f32 *arg0);
extern s32 func_00161630(u16 arg0, u16 arg1, u16 arg2, s32 arg3);
extern u8 *func_00164880(s32 arg0, u32 arg1, f32 arg2);
extern u8 *func_0014cef0(s32 arg0, s32 arg1);
extern void func_0014c920(void);
extern s32 func_0014c960(s32 *arg0, s32 *arg1);
extern s32 func_00106330(s32 arg0);
extern s32 func_00145ac0(s32 arg0, s32 arg1);
extern u8 *func_00162330(void);
extern u8 *func_00231580(u16 arg0);
extern u8 *func_00162680(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00109400(s32 arg0);
extern s32 func_00104c70(s32 arg0);
extern s32 func_00105ee0(s32 arg0);
extern s32 func_00155280(void);
extern void func_0014a0f0(u16 arg0, s32 arg1);
extern u16 func_00145780(u16 arg0, s32 arg1, s32 arg2);
extern void func_0047a1a0(void *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_0047a180(void *arg0, f32 *arg1, s32 arg2);
extern s32 func_0018bb20(s32 arg0, void *arg1);

extern void memset(void *destination, s32 value, u32 size);
extern u8 D_007E8020[];
extern u8 D_007E8C00[];
extern u8 D_007EF9B0[];
extern u8 D_007E8BE0[];
extern u8 D_005F1500[];
extern u8 D_005F1510[];
extern u8 D_005F13C0[];
extern u8 D_005F1340[];
extern u8 D_005F12E0[];
extern u8 D_005F1520[];
extern u8 D_005F1528[];
extern u8 D_005DC920[];
extern u8 D_00756510[];
extern u8 D_005F1530[];
extern u8 D_005F1550[];
extern u8 D_005F1570[];
extern s32 D_007E8BE8[];
extern s32 D_00764364;
extern u8 D_007EF9F8[];
extern u8 D_007F16F0[];
extern u8 D_007EFA00[];
extern u8 D_007EFA04[];
extern u8 D_007EFB60[];
extern u8 D_007EFB64[];
extern u8 D_007F00D8[];
extern u8 D_005F1590[];
extern u8 D_005F15B0[];
extern u8 D_005F15C0[];
extern u8 D_005F15E0[];
extern u8 D_007E80A0[];

static s32 D_007643C8[2];
static s32 D_007643C0[2];
static u8 D_00763008[4];
static u8 D_00763010[4];
static u8 *D_00762EA0;
static s32 D_00764350;
static s32 D_007643E4;
static f32 D_007613EC;

typedef struct {
    u8 b[4];
} S4;

typedef struct {
    u32 h[2];
} S8;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;

s32 func_00163c90(s32 arg0);
void func_00164020(u8 *arg0);
void func_00164fa0(s32 arg0);
void func_00165670(u8 *arg0, s32 arg1);
s32 func_00478140(s32 arg0, u16 arg1, s32 arg2);
s32 func_004782b0(s32 arg0);
void func_00440b68(u8 *arg0, u8 *arg1, s32 arg2);
s32 func_00454a60(u8 *arg0, s32 arg1);
s32 func_0014a200(void);
s32 func_0014a270(void);
s32 func_001668e0(u8 *arg0);
void func_0044ea90(u8 *arg0, s32 arg1);
f32 func_0044b7b0(f32 arg0);
u8 *func_0047a250(s32 arg0);
void func_0047a220(s32 arg0, u8 *arg1);
void func_004b14f0(u8 *arg0, u8 *arg1);
void func_004b13f0(u8 *arg0, u8 *arg1);
u8 *func_0047a2f0(s32 arg0);
void func_00146630(u16 arg0);
void func_0047a870(s32 arg0);
void func_004787e0(s32 arg0);
void func_00452080(s32 arg0);
s32 func_00162510(s32 arg0, s32 arg1);
s32 func_0015a160(void);
s32 func_001679d0(u8 *arg0);
u8 *func_001452b0(s32 arg0);
void func_0046d730(u8 *arg0, s32 arg1);
void func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2);
extern s64 func_001060b0(void);
extern s32 func_001064f0(s32 arg0);
extern s32 func_00110d60(s16 arg0);
extern s32 D_007E8BF8[];
void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
s32 func_00161b10(u16 arg0, u16 arg1, u16 arg2);
s32 func_0015a320(void);
u8 *func_00161c80(u16 arg0, u16 arg1, u16 arg2, s32 arg3);
void *func_00451fc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, void (*arg5)(void *), void (*arg6)(void *), s32 arg7);





/* measured: disable common-subexpression elimination to preserve the retail
   second unit-base materialization after the allocator call. */
#pragma opt_common_subs off
// FUN_00162C30
s32 func_00162c30(void)
{
    s32 field;
    s32 i;
    s32 j;
    s32 k;
    s32 *v4;
    s32 *v7;
    s32 v9;
    s32 v18;
    s32 resource;

    for (i = 0; i < 4; i++) {
        v4 = ((s32 *)D_007EF9B0) + i * 468;
        if ((v4[18] != 0) && (v4[21] == 0)) {
            if (func_004782b0(v4[20]) == 0) {
                return 0;
            }
            for (j = 0; j < 5; j++) {
                if (func_0047ae90(v4[20], j) == 0) {
                    return 0;
                }
            }
            if ((v18 = v4[460]) != 0) {
                if (func_004553c0(v18) == 0) {
                    return 0;
                }
                func_0044ea90(D_005F1500, 0x218);
                v7 = ((s32 *)D_007EF9B0) + i * 468;
                field = (s32)(v7 + 460);
                resource = *(s32 *)(v7[460] + 0x118);
                v7[461] = (*DAT_008873F4)(1, resource, 0x40000);
                v7[462] = *(s32 *)(*(s32 *)field + 0x118);
                resource = *(s32 *)field;
                v9 = *(s32 *)(resource + 0x118);
                func_0043f810((void *)v7[461],
                              *(s32 *)(resource + 0x110), v9);
                func_00454bd0(*(s32 *)field);
                *(s32 *)field = 0;
                for (k = 0; k < 5; k++) {
                    resource = v7[20];
                    v9 = *(s32 *)((s32)resource + k * 0xC + 0x290);
                    if (v9 != 0) {
                        *((s32 *)((s32)v7 + k * 4) + 453) =
                            *(s32 *)(v9 + 0x2FC);
                    }
                }
            }
        }
    }
    return 1;
}
/* measured: restore common-subexpression elimination after func_00162c30. */
#pragma opt_common_subs on
// FUN_00162E10
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00162e10);



/* measured: nd 130 after four retries (recipe B + preheader reordering).
   (1) Retail materialises 0x750 into $a1 ONCE in the search-loop preheader
   (order: slot=NULL, i=0, step, base) and reuses it as func_00231630's arg1;
   mwcc b210 always sinks the constant to the loop-entry block in $v0 and
   rematerialises addiu $a1,0x750 at the call, shifting the whole tail by one
   word — tried shared s32 local (with/without opt_loop_invariants, for/while,
   every pre-loop placement) and inline literal; base hoists to $a0 correctly
   either way (recipe B works for D_007E8C00). (2) The average loop: retail
   re-issues lw 0x48(slot) per iteration (cnt in $a1); mwcc CSEs it out of the
   loop (cnt in $a0) — all load spellings nd >= 122. (3) D_00724504's load
   lands before the t21*0x18 scaling in mwcc, after it in retail, both operand
   orders tried. Constant-materialization + CSE-of-loop-test-load floors.
   Note this is the recipe-B retest: the base hoist itself is NOT the blocker. */
// FUN_00163990
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00163990);



/* measured: parked nd 5, object/window 808/816. The control flow, 0x50-byte frame, stack aggregate stores, and 35.0f COP1 call match. Exact fndiff residuals are offsets 0x14, 0x18, 0x1C, 0x20, and 0x24: b210 schedules the D_005F1528 lwc1 before the D_005F1520 ld and colors the ld result $v0 instead of retail $v1. Ruled out assignment/declaration-order swaps, named-local versus direct-store forms, pointer and aggregate S8/S12 forms, comma sequencing, register storage, and pragma wrappers; no prototype or symbol changes. Committed at nd 5. */
// FUN_00163C90
s32 func_00163c90(s32 arg0)
{
  u8 sp40[12];
  f32 sp30[3];
  u8 var_5;
  s64 new_var;
  f32 temp_f0;
  s32 temp_2;
  u8 *temp_16;
  s64 temp_s64;
  f32 temp_stack;
  temp_s64 = (new_var = *((s64 *) D_005F1520));
  temp_stack = *((f32 *) D_005F1528);
  *((s64 *) sp40) = temp_s64;
  *((f32 *) (sp40 + 8)) = temp_stack;
  temp_16 = D_007E8C00 + (arg0 * 0x750);
  if ((*((s32 *) (temp_16 + 0x48))) == 0)
  {
    return 1;
  }
  if ((*((s32 *) (temp_16 + 0x54))) != 0)
  {
    return 1;
  }
  if ((*((s32 *) (temp_16 + 0x50))) == 0)
  {
    return 1;
  }
  if (func_004782b0(*((s32 *) (temp_16 + 0x50))) == 0)
  {
    return 0;
  }
  var_5 = 0;
  if ((*((u8 *) (temp_16 + 0x1CA))) == 1)
  {
    var_5 = 3;
  }
  *((s32 *) (temp_16 + 0x54)) = (s32) func_00145270(func_00145540((arg0 + 0x64) & 0xFFFF, var_5, *((u8 **) (temp_16 + 0x50))) & 0xFFFF);
  func_00479940(*((u8 **) (temp_16 + 0x50)), 0, 0, 0x10, 1);
  func_0047aa30(*((u8 **) (temp_16 + 0x50)), D_005DC920);
  temp_2 = (*((s32 *) (temp_16 + 0x1C0))) - func_0014c780();
  if (temp_2 < (-3))
  {
    *((u8 *) (temp_16 + 0x1CB)) = 0;
  }
  else
    if (temp_2 < (-1))
  {
    *((u8 *) (temp_16 + 0x1CB)) = 1;
  }
  else
    if (temp_2 < 3)
  {
    *((u8 *) (temp_16 + 0x1CB)) = 2;
  }
  else
    if (temp_2 >= 3)
  {
    *((u8 *) (temp_16 + 0x1CB)) = 3;
  }
  if ((*((u8 *) (temp_16 + 0x1CA))) == 1)
  {
    func_0017b9a0(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x224)), *((f32 *) (D_005F1340 + ((*((u8 *) (temp_16 + 0x1CB))) * 4))));
  }
  func_0047a1e0(*((void **) (temp_16 + 0x50)), (D_005F12E0 + ((*((u8 *) (temp_16 + 0x1CA))) * 0x30)) + ((*((u8 *) (temp_16 + 0x1CB))) * 0xC), 2);
  func_003e05d0(func_0047a2f0(*((s32 *) (temp_16 + 0x50))));
  func_00168de0(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), sp40, *((f32 *) ((*((u8 **) (temp_16 + 0x1AC))) + 0x14C)));
  func_00168ae0(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), (*((u8 **) (temp_16 + 0x1AC))) + 0x140);
  func_0014b0c0(*((u16 *) (*((u8 **) (0x54 + temp_16)))), 1);
  func_00168730(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), 0x40000000);
  func_00168780(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)), 35.0f);
  *((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x228)) = func_00478750(iGpffffb274);
  temp_f0 = func_00168770(*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x220)));
  sp30[2] = temp_f0;
  sp30[1] = temp_f0;
  sp30[0] = temp_f0;
  func_0047a1e0((void *) (*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x228))), sp30, 2);
  func_00478e70((u8 *) (*((s32 *) ((*((u8 **) (temp_16 + 0x54))) + 0x228))));
  *((s32 *) (temp_16 + 0x1B0)) = func_00182220(0, temp_16, *((u8 *) (temp_16 + 0x1CA)));
  *((s32 *) (temp_16 + 0x1B8)) = func_00167420((u8 *) 0, temp_16);
  return 1;
}











// FUN_00163FC0
s32 func_00163fc0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        if (func_00163c90(i) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00164020
void func_00164020(u8 *arg0)
{
    s32 i;
    s32 t48;
    u16 *t54;

    t48 = *(s32 *)(arg0 + 0x48);
    if (t48 != 0) {
        func_002319c0(t48);
        t54 = *(u16 **)(arg0 + 0x54);
        if (t54 != NULL) {
            func_00146630(*t54);
        }
        if ((*(s32 *)(arg0 + 0x50) != 0) &&
            ((*(u16 *)(arg0 + 0x728) == 0) || (*(s32 *)(arg0 + 0x44) == 1))) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(s32 *)(arg0 + 0x50) + i * 0xC + 0x28C) |= 1;
            }
            func_0014b870(*(s32 *)(arg0 + 0x50), 0);
        }
        if (*(s32 *)(arg0 + 0x1B0) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B0));
        }
        if (*(s32 *)(arg0 + 0x734) != 0) {
            DAT_008873EC[0](*(void **)(arg0 + 0x734));
        }
        if (*(s32 *)(arg0 + 0x1B4) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B4));
        }
        if (*(s32 *)(arg0 + 0x1B8) != 0) {
            func_00452080(*(s32 *)(arg0 + 0x1B8));
        }
        *(s32 *)(arg0 + 0x48) = 0;
        *(s32 *)(arg0 + 0x50) = 0;
        *(s32 *)(arg0 + 0x54) = 0;
        *(s32 *)(arg0 + 0x1B0) = 0;
        *(s32 *)(arg0 + 0x734) = 0;
        *(s32 *)(arg0 + 0x1B4) = 0;
        *(s32 *)(arg0 + 0x1B8) = 0;
        if (*(u16 *)(arg0 + 0x1C8) != 0) {
            iGpffffb2e8 -= 1;
        }
    }
}



// FUN_00164170
void func_00164170(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        func_00164020(D_007EF9B0 + i * 0x750);
    }
}



// FUN_001641D0
void func_001641d0(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00164020(D_007E8C00 + i * 0x750);
    }
}



/* measured: nd ~128 after many attempts. (1) Loop A register rotation:
   retail keeps var_16 in $s0 (coalesced with temp_2's freed $16) and the
   D_007F16F0 slot pointer in $a0; mwcc b210 gives temp_4 the freed $16 and
   pushes var_16 to $s1, var_5 to $a0 vs retail's $a1 — every declaration
   order tried. Saved-register-rotation floor. (2) temp_21 is s64 for the
   clean andi ($18,& 0xffff) but the D_005F13C0 index wants s32 (retail
   daddu+sll); the (s64)(s16) cast pairs, s64 temp_18_3/andis, func_004787e0
   1-arg call, and the first block all match. */
// FUN_00164230
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164230);



// FUN_00164570
s32 func_00164570(u32 arg0, s32 arg1)
{
    s32 sp6C;
    s32 sp68;
    f32 var_f20;
    s32 temp_3;
    s32 var_17;
    u32 var_2;
    u8 *temp_16;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_4;

    var_17 = 0;
    if (D_00764344 == 1) {
        return 0;
    }
    temp_4 = iGpffff9db0;
    temp_3 = *(s32 *)temp_4;
    if ((temp_3 >= 0x28) && (temp_3 < 0x3C) && (*(s32 *)(temp_4 + 4) != 0)) {
        return 0;
    }
    if (arg1 != 0) {
        while ((temp_2 = func_00164880(var_17, arg0, (f32)0xBB8)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 2);
            var_17 += 1;
        }
    } else {
        while ((temp_2 = func_00164880(var_17, arg0, (f32)0x1770)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 1);
            var_17 += 1;
        }
        var_f20 = (f32)0xBB8;
        if (func_0014a270() == 1) {
            var_f20 = 100.0f;
        }
        while ((temp_2 = func_00164880(var_17, arg0, var_f20)) != NULL) {
            temp_19 = iGpffff9db0;
            var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
            if ((var_2 & 0xFFFF) == 0xFFFF) {
                var_2 = 1;
            }
            func_00163990(var_2, temp_2, 0);
            var_17 += 1;
        }
        if ((func_00106330(0x1410) == 0) && (func_00106330(0x1411) == 0)) {
            func_0014c920();
            while (func_0014c960(&sp6C, &sp68) == 1) {
                temp_16 = func_0014cef0(sp6C, sp68);
                if (temp_16 != NULL) {
                    temp_19 = iGpffff9db0;
                    var_2 = func_00161630(*(u16 *)temp_19, *(u16 *)(temp_19 + 4), (u16)(func_0015a160() & 0xFFFF), 2);
                    if ((var_2 & 0xFFFF) == 0xFFFF) {
                        var_2 = 1;
                    }
                    func_00163990(var_2, temp_16, 0);
                }
            }
        }
    }
    return var_17;
}



// FUN_00164880
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164880);



// FUN_00164F40
s32 func_00164f40(void)
{
    return iGpffffb2e8;
}



// FUN_00164F50
void func_00164f50(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00164fa0(i);
    }
}



/* measured: nd ~26 after four attempts; everything matches except retail's
   three re-issued `mult` recomputations of arg0*0x750 (temp_20_2, D_007F00D8,
   D_007EFB60 sites). mwcc b210 CSEs arg0*0x750 against the temp_17 local
   (kept in $s1 across the calls) and emits addu instead of a fresh mult, in
   every spelling tried: arg0*0x750, 0x750*arg0, (s32)&D_..+arg0*0x750
   int-cast form, (u32)arg0*0x750 (that one also grows the frame to 0x90).
   CSE-of-recomputed-multiply floor (cf. cmmMisc func_00247cb0). sp70[3]
   array, w0/w1 copy loop, and D_007EFA04-between-calls placement all match. */
// FUN_00164FA0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00164fa0);



// FUN_00165270
void func_00165270(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0) {
            *(s32 *)(p + 0x50) = func_00478140(8, (u16)(*(u8 *)(p + 0x1CA) + 1), 0);
        }
    }
}



// FUN_00165300
s32 func_00165300(void)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        u8 *p = D_007E8C00 + i * 0x750;
        if (*(s32 *)(p + 0x48) != 0 && func_004782b0(*(s32 *)(p + 0x50)) == 0) {
            return 0;
        }
    }
    return 1;
}



// FUN_00165380
/* nd 148 -> 0 (the old "GVN merges the slot address" floor). Each section-local
   `slot = D_007E8C00 + i * 0x750` reassignment (A, B, C, the 0x1CB read, the
   func_00167420 argument) must rematerialise; `slot += 0x54` must stay an addiu
   between the two calls (`t2 = t1 & 0xFFFF` first so the andi precedes it); the
   0x1CB read goes through `p = ...` so its recompute precedes the arg-0 load. */
/* measured: opt_common_subs off rematerialises the slot address per assignment;
   opt_propagation off keeps the pointer bump out of the store offset. */
#pragma opt_common_subs off
#pragma opt_propagation off
void func_00165380(void)
{
    s32 i;
    u8 *slot;
    u8 *f1ca;
    u8 *f50;
    u8 *f54;
    u8 *f1b8;
    u8 *p;
    u8 var_5;
    u8 *src;
    s32 n;
    u8 *dst;
    s32 t1;
    s32 t2;
    f32 sp50[3];
    f32 temp_f0;

    for (i = 0; i < 0xF; i++) {
        slot = D_007E8C00 + i * 0x750;
        if (*(s32 *)(slot + 0x48) != 0) {
            var_5 = 0;
            *(s32 *)(slot + 0x40) &= ~2;
            f1ca = slot + 0x1CA;
            if (*f1ca == 1) {
                var_5 = 3;
            }
            slot = D_007E8C00 + i * 0x750;
            f50 = slot + 0x50;
            t1 = func_00145540((i + 0x64) & 0xFFFF, var_5, *(u8 **)(slot + 0x50));
            t2 = t1 & 0xFFFF;
            slot += 0x54;
            *(s32 *)slot = (s32)func_00145270(t2);
            func_0047aa30(*(u8 **)f50, D_005DC920);
            if (*f1ca == 1) {
                p = D_007E8C00 + i * 0x750;
                func_0017b9a0(*(s32 *)(*(u8 **)slot + 0x224), *(f32 *)(D_005F1340 + *(u8 *)(p + 0x1CB) * 4));
            }
            slot = D_007E8C00 + i * 0x750;
            f1ca = slot + 0x1CA;
            f50 = slot + 0x50;
            func_0047a1e0(*(void **)f50, D_005F12E0 + *f1ca * 0x30 + *(u8 *)(slot + 0x1CB) * 0xC, 2);
            dst = func_0047a2f0(*(s32 *)f50);
            n = 8;
            src = slot;
            do {
                t1 = *(s32 *)src;
                t2 = *(s32 *)(src + 4);
                src += 8;
                n -= 1;
                *(s32 *)dst = t1;
                *(s32 *)(dst + 4) = t2;
                dst += 8;
            } while (n > 0);
            func_003e05d0(func_0047a2f0(*(s32 *)f50));
            f54 = slot + 0x54;
            func_0014b0c0(*(u16 *)(*(u8 **)f54), 1);
            func_00168730(*(s32 *)(*(u8 **)f54 + 0x220), 0x40000000);
            func_00168c00(*(s32 *)(*(u8 **)f54 + 0x220));
            func_00168780(*(s32 *)(*(u8 **)f54 + 0x220), 35.0f);
            *(s32 *)(*(u8 **)f54 + 0x228) = func_00478750(iGpffffb274);
            temp_f0 = func_00168770(*(s32 *)(*(u8 **)f54 + 0x220));
            sp50[2] = temp_f0;
            sp50[1] = temp_f0;
            sp50[0] = temp_f0;
            func_0047a1e0((void *)*(s32 *)(*(u8 **)f54 + 0x228), sp50, 2);
            func_00478e70((u8 *)*(s32 *)(*(u8 **)f54 + 0x228));
            *(s32 *)(slot + 0x1B0) = func_00182220(0, slot, *f1ca);
            f1b8 = slot + 0x1B8;
            if (*(s32 *)f1b8 == 0) {
                *(s32 *)f1b8 = func_00167420((u8 *)0, D_007E8C00 + i * 0x750);
            }
        }
    }
}
/* measured: closes the two brackets above; the file default is on. */
#pragma opt_common_subs on
#pragma opt_propagation on



// FUN_00165670
void func_00165670(u8 *arg0, s32 arg1)
{
    u8 *p = arg0;
    u8 *q;
    u8 *s;
    u8 *d;
    s32 n;
    s32 v;
    s32 i;
    v = *(u32 *)(p + 0x48) != 0 && *(u32 *)(p + 0x54) != 0;
    if (v != 0) {
        q = func_0047a2f0(*(u32 *)(p + 0x50));
        s = q;
        n = 8;
        d = p;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            n--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (n > 0);
        func_00146630(*(u16 *)(*(u32 *)(p + 0x54)));
        *(u32 *)(p + 0x54) = 0;
        if (*(u32 *)(p + 0x50) != 0) {
            func_0047a870(*(u32 *)(p + 0x50));
            func_0047a220(*(u32 *)(p + 0x50), D_00763010);
        }
        if (*(u32 *)(p + 0x50) != 0 && arg1 == 1) {
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u32 *)(p + 0x50) + i * 12 + 0x28C) |= 1;
            }
            func_004787e0(*(u32 *)(p + 0x50));
            *(u32 *)(p + 0x50) = 0;
        }
        if (*(u32 *)(p + 0x1B0) != 0) {
            func_00452080(*(u32 *)(p + 0x1B0));
            *(u32 *)(p + 0x1B0) = 0;
        }
        if (*(u32 *)(p + 0x1B8) != 0) {
            func_00452080(*(u32 *)(p + 0x1B8));
            *(u32 *)(p + 0x1B8) = 0;
        }
        if (*(u32 *)(p + 0x1B4) != 0) {
            func_00452080(*(u32 *)(p + 0x1B4));
            *(u32 *)(p + 0x1B4) = 0;
        }
    }
}



// FUN_001657E0
void func_001657e0(s32 arg0)
{
    s32 i = !arg0;
    for (; i < 4; i++) {
        func_00165670(D_007EF9B0 + i * 0x750, 0);
    }
}



// FUN_00165840
void func_00165840(s32 arg0)
{
    s32 i;
    for (i = 0; i < 0xF; i++) {
        func_00165670(D_007E8C00 + i * 0x750, arg0);
    }
}



/* SUPERSEDED measured: nd 63 after four attempts; only registers differ from here on.
   (1) var_16 lands in $s2 and var_18 in $s0 where retail has $s0/$s2 — the
   allocator's internal order is fixed ($s4=var_20, $s3=var_19, $s2=var_16,
   $s1=var_17, $s0=var_18) under every declaration permutation tried, so the
   whole body shows the 2-way swap (saved-register-rotation floor). (2) The
   var_16*4 scale is GVN'd into ONE saved register ($s5) feeding both the
   D_007643C8 slot pointer and the D_007643C0 store; retail computes it twice
   (temp sll for the slot pointer + hoisted sll $s6 for the C0 store) — 1
   word; explicit temp_22 = var_16*4 local still GVN's with the pointer
   scale. Everything else matches byte-for-byte: absolute lui addressing via
   array declarations for D_007E8BE8/D_007E8BF8, daddiu 0x80A/0x120A via the
   u16 var_18_2, dsll32/dsra32 via (s16) of the s64 func_001060b0 result,
   andi-then-bgez ordering, temp_21 in $s5/$s6 slot pair. */
// FUN_001658B0
void func_001658b0(void)
{
    s32 i;
    s32 j;
    u16 code;
    s32 value;
    s32 count;

    count = 0;
    j = 0;
    func_0043f9c8(D_007E8BE0, 0, 0x20);
    D_007E8BE8[0] = -1;
    D_007E8BF8[0] = -1;
    if (func_0014a200() == 0) {
        goto done;
    }
    if (func_0014a200() != 0) {
        goto loop;
    }
done:
    return;
loop:
    for (i = 0; i < 8; i++) {
        value = func_0015a160();
        if (value == func_001064f0(i + 1)) {
            s32 state;
            s32 parity;
            s32 base;
            base = 10;
            state = func_00110d60((s16)func_001060b0());
            parity = state & 1;
            if (state < 0 && parity != 0) {
                parity -= 2;
            }
            if (parity != 0) {
                base = 20;
            }
            if (i < 6) {
                value = i + 2;
                code = (u16)((value << 8) | base);
            } else if (i == 6) {
                code = 0x80A;
                value = i + 2;
            } else {
                code = 0x120A;
                value = 9;
            }
            if (count >= 2) {
                func_0046d730(D_005F1500, 0x916);
            }
            if (D_007643C8[count] != 0) {
                func_0046d730(D_005F1500, 0x917);
            }
            D_007643C8[count] = func_00478140(9, code, 0);
            func_00440b68(D_00763008, D_005F1500, 0x91C);
            D_007643C0[count] =
                func_00454a60(D_005F13C0 + value * 0x20, 0);
            *(s32 *)(D_007E8BE0 + j * 16) = 1;
            *(u16 *)(D_007E8BE0 + j * 16 + 4) = 9;
            *(u16 *)(D_007E8BE0 + j * 16 + 6) = code;
            *(s32 *)(D_007E8BE0 + j * 16 + 0xC) = value;
            j++;
            count++;
        }
    }
}



// FUN_00165B00
void func_00165b00(void)
{
    s32 i;
    s32 j = 0;
    for (i = 0; i < 2; i++) {
        u8 *p = D_007E8BE0 + i * 16;
        if (*(s32 *)p != 0) {
            D_007643C8[j] = func_00478140(*(u16 *)(p + 4), *(u16 *)(p + 6), 0);
            func_00440b68(D_00763008, D_005F1500, 0x939);
            D_007643C0[j] = func_00454a60(D_005F13C0 + (*(s32 *)(p + 0xC) << 5), 0);
            j++;
        }
    }
}



/* measured: nd 133 after four retries (recipe B retest). The D_007E8BE0
   scan loop is now byte-identical in shape (base hoist + addiu $v1,$a1,8 +
   sw 0($v1) reproduced via `*((s32 *)p + 2)` element addressing — the +8
   materializes instead of folding); the ONLY scan-loop residual is retail
   hoisting the ==1 compare constant into the preheader (register cascade:
   retail a3/a2/a1/a0, mwcc b210 a2/a1/a0/$v0-with-const-in-body) — every
   spelling (named local, literal, pragma on/off) sinks the constant to its
   use inside the body; constant-materialization floor. (2) The big loop
   keeps var_17_2 in $s2 / temp_18+temp_2 in $s1 where retail has them
   swapped — declaration orders, limit local, merged variable, all nd >= 130.
   (3) temp_19_2's address is materialized after the NULL check in retail,
   before it in mwcc. Saved-register + constant-materialization floors;
   recipe B itself (typed base pointer) works for the base hoist. */
// FUN_00165BE0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00165be0);



/* measured: func_00165fb0 is an exact C match (object 796B, window 800B, normalized_diff 0). Retail computes the +4 byte first and keeps it live in $a1 while computing +7 into $v0; reusing the existing temp_4 loop temporary for the +4 assignment reproduces that liveness order and both endpoint stores. */
/* The archived nd2 body had the endpoint temporaries reversed; naming/order probes did not move them. This liveness change preserves the 796B object and closes both prior residual words. */
// FUN_00165FB0
void func_00165fb0(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_17;
    s32 temp_21;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_4_2;
    u8 *temp_6;
    u8 *var_18;
    u8 color3;
    u8 color1;
    u8 color2;
    u8 color0;

    if (arg0 != NULL) {
        temp_17 = (s32)(((*(u8 **)(arg0 + 0x160) + 7)[0] & 1) != 0);
        *(u16 *)(arg0 + 0xC) = (u16)func_00145ac0(arg2 & 0xFFFF, func_00478750(*(s32 *)(func_0015a320())));
        temp_2 = func_00145270(*(u16 *)(arg0 + 0xC));
        func_0047aa30(*(u8 **)(temp_2 + 0x144), D_005DC920);
        temp_21 = temp_17 * 0xC;
        func_0047a1e0(*(u8 **)(temp_2 + 0x144), D_005F1530 + temp_21, 2);
        func_0047a1a0(*(u8 **)(temp_2 + 0x144), D_00756510, *(f32 *)(arg1 + 0x14C), 2);
        func_0047a180(*(u8 **)(temp_2 + 0x144), (f32 *)(arg1 + 0x140), 2);
        if (*(s32 *)(arg0 + 8) != 0) {
            func_00479940(*(u8 **)(temp_2 + 0x144), 0, 2, 0, 0);
        } else if (temp_17 == 1) {
            func_00479940(*(u8 **)(temp_2 + 0x144), 0, 3, 0, 0);
        }
        temp_3 = *(u8 **)(temp_2 + 0x144);
        *(s32 *)(temp_3 + 0xD8) |= 0x80;
        temp_3_2 = *(u8 **)(temp_2 + 0x144);
        var_18 = *(u8 **)(*(u8 **)(temp_3_2 + 0x2CC));
        temp_6 = *(u8 **)(temp_3_2 + 0x124);
        temp_4 = iGpffff9f28;
        color1 = iGpffff9f29;
        color2 = iGpffff9f2a;
        color0 = iGpffff9f2b;
        temp_6[4] = temp_4;
        temp_6[5] = color1;
        temp_6[6] = color2;
        temp_6[7] = color0;
        while (var_18 != NULL) {
            temp_4 = *(s32 *)(var_18 + 8);
            if (temp_4 != 0) {
                func_004b13f0((u8 *)temp_4, (u8 *)&iGpffff9f28);
            }
            var_18 = *(u8 **)(var_18 + 0x10);
        }
        if (temp_17 == 1) {
            func_0047a220((s32)*(u8 **)(temp_2 + 0x144), (u8 *)&iGpffff9f24);
        } else {
            func_0047a220((s32)*(u8 **)(temp_2 + 0x144), D_005F1570 + ((func_0015a160() / 20U) * 4));
        }
        temp_2_2 = (u8 *)func_00478750(D_00764364);
        *(u8 **)(temp_2 + 0x16C) = temp_2_2;
        func_0047a1a0(temp_2_2, D_00756510, *(f32 *)(arg1 + 0x14C), 2);
        func_0047a1e0(*(u8 **)(temp_2 + 0x16C), D_005F1550 + temp_21, 2);
        func_0047a180(*(u8 **)(temp_2 + 0x16C), (f32 *)(arg1 + 0x140), 2);
        temp_4_2 = *(u8 **)(temp_2 + 0x16C);
        *(u8 **)(arg0 + 0x164) = temp_4_2;
        func_00478e70(temp_4_2);
        temp_17_2 = (s32)((600.0f + *(f32 *)(arg1 + 0x140)) / 1200.0f);
        temp_18 = (s32)((600.0f + *(f32 *)(arg1 + 0x148)) / 1200.0f);
        *(u8 **)(temp_2 + 0x140) = func_00145270(*(u16 *)((u8 *)func_00155280() + (temp_18 << 8) + (temp_17_2 * 0x10) + 0x56));
        func_0014a0f0(*(u16 *)(arg0 + 0xC), 1);
        iGpffffb2e4 += 1;
    }
}

// FUN_001662D0
void func_001662d0(void)
{
    u32 sp6C;
    u32 t17;
    u8 *src;
    u8 *s19;
    u8 *p;
    u8 *slotp;
    s32 i;
    s32 j;
    u16 h0;
    u16 h4;
    u8 *dp;
    u8 *s;
    u8 *d;
    s32 k;

    t17 = func_0015a160();
    if (iGpffffb260 == 1) {
        return;
    }
    func_0043f9c8(D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    h0 = *(u16 *)iGpffff9db0;
    h4 = *(u16 *)(iGpffff9db0 + 4);
    s19 = (u8 *)func_00161b10(h0, h4, t17);
    if (s19 == 0) {
        return;
    }
    if (func_0015a320() == 0) {
        return;
    }
    i = 0;
    while ((src = func_00166600(s19, &sp6C, i)) != NULL) {
        h0 = *(u16 *)iGpffff9db0;
        h4 = *(u16 *)(iGpffff9db0 + 4);
        p = func_00161c80(h0, h4, t17, 2);
        if (p == NULL) {
            func_0046d730(D_005F1500, 0xA63);
        }
        slotp = NULL;
        j = 0;
        dp = D_007E80A0;
        for (; j < 8; j++) {
            if (*(s32 *)(dp + j * 0x168) == 0) {
                slotp = dp + j * 0x168;
                break;
            }
        }
        *(s32 *)slotp = 1;
        *(s32 *)(slotp + 0x160) = (s32)p;
        *(s16 *)(slotp + 0xE) = (s16)sp6C;
        d = slotp + 0x10;
        k = 0x2A;
        s = src;
        do {
            u32 w0 = *(u32 *)s;
            u32 w1 = *(u32 *)(s + 4);
            s += 8;
            k--;
            *(u32 *)d = w0;
            *(u32 *)(d + 4) = w1;
            d += 8;
        } while (k > 0);
        func_00165fb0(slotp, src, 0x3FE - i);
        i++;
    }
}

// FUN_001664A0
void func_001664a0(void)
{
    s32 i;
    s32 k;
    s32 j = 0;
    u8 *node;
    u8 *p;
    if (D_00764350 != 1) {
        for (i = 0; i < 8; i++) {
            p = D_007E80A0 + i * 360;
            if (*(s32 *)p != 0) {
                node = func_001452b0(0x10);
                if (node == 0) {
                    return;
                }
                for (k = 0; k < *(u16 *)(p + 0xE); k++) {
                    node = *(u8 **)(node + 0x138);
                    if (node == 0) {
                        func_0046d730(D_005F1500, 0xA87);
                    }
                }
                {
                    u8 *s;
                    u8 *d;
                    s32 n;
                    d = D_007E80A0 + (u32)i * 360 + 0x10;
                    n = 0x2A;
                    s = node;
                    do {
                        u32 w0 = *(u32 *)s;
                        u32 w1 = *(u32 *)(s + 4);
                        s += 8;
                        n--;
                        *(u32 *)d = w0;
                        *(u32 *)(d + 4) = w1;
                        d += 8;
                    } while (n > 0);
                }
                func_00165fb0(D_007E80A0 + (u32)i * 360, node, 0x3FE - j);
                j++;
            }
        }
    }
}
// FUN_00166600
u8 *func_00166600(u8 *arg0, u32 *arg1, s32 arg2)
{
    V3 pos;
    V3 vec;
    f32 temp_f0;
    f32 var_f22;
    f32 var_f23;
    u8 *var_19;
    u8 *var_18;
    u8 *temp_3;
    s32 var_2;
    s32 var_21;
    s32 var_17;
    s32 var_16;

    var_19 = func_001452b0(0x10);
    var_18 = NULL;
    func_0015a160();
    *arg1 = 0;
    var_16 = 0;
    if (func_0014a200() == 1) {
        if (iGpffffb2e4 < (s32)arg0) {
            var_f22 = 1.1754944e-38f;
            while (var_19 != NULL) {
                pos = *(V3 *)(var_19 + 0x140);
                vec.x = pos.x - *(f32 *)(func_0047a2f0((s32)*(u8 **)D_007EFA00) + 0x30);
                vec.y = pos.y - *(f32 *)(func_0047a2f0((s32)*(u8 **)D_007EFA00) + 0x34);
                vec.z = pos.z - *(f32 *)(func_0047a2f0((s32)*(u8 **)D_007EFA00) + 0x38);
                if (func_003e4180(&vec.x) < 500.0f) {
                    var_19 = *(u8 **)(var_19 + 0x138);
                    var_16 += 1;
                } else {
                    if (iGpffffb2e4 == 0) {
                        return var_19;
                    }
                    var_f23 = 1.1754944e-38f;
                    var_21 = 0;
                    var_17 = 0;
                    while (var_17 < 8) {
                        temp_3 = D_007E80A0 + var_17 * 0x168;
                        if (*(s32 *)temp_3 != 0) {
                            vec.x = pos.x - *(f32 *)(temp_3 + 0x150);
                            vec.y = pos.y - *(f32 *)(temp_3 + 0x154);
                            vec.z = pos.z - *(f32 *)(temp_3 + 0x158);
                            temp_f0 = func_003e4180(&vec.x);
                            if (temp_f0 < 100.0f) {
                                var_21 = 1;
                                break;
                            }
                            var_f23 += temp_f0;
                        }
                        var_17 += 1;
                    }
                    if (var_21 == 1) {
                        var_19 = *(u8 **)(var_19 + 0x138);
                        var_16 += 1;
                    } else {
                        if (!(var_f23 <= var_f22)) {
                            var_f22 = var_f23;
                            *arg1 = var_16;
                            var_18 = var_19;
                        }
                        var_19 = *(u8 **)(var_19 + 0x138);
                        var_16 += 1;
                    }
                }
            }
        }
    } else if (func_0014a270() == 1) {
        var_2 = 0;
        while (var_19 != NULL) {
            if (var_2 == arg2) {
                *arg1 = arg2;
                var_18 = var_19;
                break;
            }
            var_19 = *(u8 **)(var_19 + 0x138);
            var_2 += 1;
        }
    }
    return var_18;
}






// FUN_001668E0
s32 func_001668e0(u8 *arg0)
{
    s32 temp_3;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_2;
    s32 var_2_2;
    u32 temp_2;
    u32 var_17;
    u8 *temp_16;
    u8 *temp_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 1) {
        return 0;
    }
    if (*(s32 *)(temp_16 + 8) == 1) {
        return 0;
    }
    switch (*(s32 *)temp_16) {
    case 0:
        iGpffffb2e8 = 0;
        var_17 = *(u32 *)(temp_16 + 0xC);
        if (var_17 == -1U) {
            temp_17 = iGpffff9db0;
            var_17 = func_001619b0(*(u16 *)temp_17, *(u16 *)(temp_17 + 4), (u16)(func_0015a160() & 0xFFFF));
        }
        if (func_0014a270() == 1) {
            var_17 = *(u32 *)(temp_16 + 0xC);
            if (var_17 == -1U) {
                var_17 = 0xF;
            }
        }
        func_00164570(var_17, 0);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        var_17_2 = 0;
        while (var_17_2 < 0xF) {
            if (func_00163c90(var_17_2) == 0) {
                var_2 = 0;
                goto out1;
            }
            var_17_2 += 1;
        }
        var_2 = 1;
    out1:
        if (var_2 != 0) {
            *(s32 *)temp_16 = 3;
        }
        break;
    case 2:
        var_17_3 = 0;
        while (var_17_3 < 0xF) {
            if (func_00163c90(var_17_3) == 0) {
                var_2_2 = 0;
                goto out2;
            }
            var_17_3 += 1;
        }
        var_2_2 = 1;
    out2:
        if (var_2_2 != 0) {
            func_00182310(0);
            *(s32 *)temp_16 += 1;
        }
        break;
    case 3:
        temp_17 = iGpffff9db0;
        temp_2 = func_00161a70(*(u16 *)temp_17, *(u16 *)(temp_17 + 4), (u16)(func_0015a160() & 0xFFFF));
        if ((u32)iGpffffb2e8 < temp_2 && func_00164570(temp_2, 1) > 0) {
            *(s32 *)temp_16 = 2;
        }
        break;
    }
    return 0;
}

// FUN_00166B10
void func_00166b10(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00166B40
s32 func_00166b40(u8 *arg0, s32 arg1)
{
    s32 r;
    s32 task;
    if (func_0014a200() == 0 && func_0014a270() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xB93);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    task = (s32)func_00451fc0(arg0, D_005F1590, 0xF, 0, 0, (void (*)(void *))func_001668e0, (void (*)(void *))func_00166b10, r);
    *(s32 *)(r + 0xC) = arg1;
    return task;
}



// FUN_00166C30
u32 func_00166c30(u8 *arg0)
{
    if (arg0 == 0) {
        return 1;
    } else {
        return (*(u32 *)(*(u32 *)(arg0 + 0x38)) ^ 3) < 1;
    }
}



// FUN_00166C60
void func_00166c60(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        *(s32 *)(*(u32 *)(arg0 + 0x38) + 4) = arg1;
    }
}



// FUN_00166C80
s32 func_00166c80(u8 *arg0)
{
    u8 *p;
    u8 *node;
    u8 *q;
    u8 buf1[4];
    u8 buf2[3];
    u8 buf3[3];
    s32 f;
    s32 i;
    p = *(u8 **)(arg0 + 0x38);
    func_0044b7b0(D_007613EC * (f32)(*(s32 *)(p + 8)) / 10.0f);
    q = func_0047a250(*(u32 *)(*(u32 *)(p + 4) + 0x50));
    *(S4 *)buf1 = *(S4 *)q;
    buf1[0] = 0x34;
    buf1[1] = 0x2E;
    buf1[2] = 0x61;
    *(s32 *)(p + 8) = *(s32 *)(p + 8) + 1;
    if (*(s32 *)(p + 8) > 10) {
        *(s32 *)(p + 8) = 0;
    }
    f = *(u8 *)(*(u32 *)(p + 4) + 0x1CA);
    if (f == 0) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        node = *(u8 **)b;
        while (node != NULL) {
            if (*(u8 **)(node + 8) != NULL) {
                func_004b14f0(*(u8 **)(node + 8), buf2);
                buf2[0] = 0xFF;
                buf2[1] = 0xFF;
                buf2[2] = 0xFF;
                func_004b13f0(*(u8 **)(node + 8), buf2);
            }
            node = *(u8 **)(node + 0x10);
        }
    } else if (f == 1) {
        u8 *x = *(u8 **)(p + 4);
        u8 *y = *(u8 **)(x + 0x50);
        u8 *b = *(u8 **)(y + 0x2CC);
        u8 *c = *(u8 **)b;
        u8 *d = *(u8 **)(c + 0x10);
        node = *(u8 **)(d + 0x10);
        if (*(u8 **)(node + 8) != NULL) {
            func_004b14f0(*(u8 **)(node + 8), buf3);
            buf3[0] = buf1[0];
            buf3[1] = buf1[1];
            buf3[2] = buf1[2];
            func_004b13f0(*(u8 **)(node + 8), buf3);
        }
    }
    func_0047a220(*(u32 *)(*(u32 *)(p + 4) + 0x50), buf1);
    return 0;
}



/* measured: same three defects as sibling func_00167120 (see its note): (1)
   (u8) conversions emit c.ole.s 0x46010036 vs retail 0x46000036 — 3 words,
   nLine func_0034c500 floor; (2) temp_f20 (func_0044b7b0 result) spilled to
   the stack instead of $f20 — frame 0x40 vs 0x50; (3) the four sp4C-4F byte
   copies interleave lbu/sb. The madd.s (175+70x) and msub.s (37-10x,
   255-200x) fused expressions and the 0x28 store match. */
// FUN_00166E30
s32 func_00166e30(u8 *arg0)
{
    u8 sp4C[4];
    u8 sp48[4];
    u8 sp44[4];
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    s32 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_4;
    u8 *var_17;
    u8 temp_byte0;
    u8 temp_byte1;
    u8 temp_byte2;
    u8 temp_byte3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f20 = func_0044b7b0(D_007613EC *
                             (f32)(*(s32 *)(temp_16 + 8)) /
                             (f32)(*(s32 *)(temp_16 + 0xC)));
    temp_2 = func_0047a250(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50));
    temp_byte0 = *temp_2++;
    temp_byte1 = *temp_2++;
    temp_byte2 = *temp_2++;
    temp_byte3 = *temp_2++;
    sp4C[0] = temp_byte0;
    sp4C[1] = temp_byte1;
    sp4C[2] = temp_byte2;
    sp4C[3] = temp_byte3;
    *(s32 *)(temp_16 + 0xC) = 0x28;
    temp_f1 = (175.0f + 0.0f) + (70.0f * temp_f20);
    sp4C[0] = (u8)temp_f1;
    temp_f1_2 = (37.0f + 0.0f) - (10.0f * temp_f20);
    sp4C[1] = (u8)temp_f1_2;
    temp_f1_3 = (255.0f + 0.0f) - (208.0f * temp_f20);
    sp4C[2] = (u8)temp_f1_3;
    temp_3 = *(s32 *)(temp_16 + 8) + 1;
    *(s32 *)(temp_16 + 8) = temp_3;
    if (*(s32 *)(temp_16 + 0xC) < temp_3) {
        *(s32 *)(temp_16 + 8) = 0;
    }
    temp_4 = *(u8 **)(temp_16 + 4);
    temp_3_2 = *(u8 *)(temp_4 + 0x1CA);
    if (temp_3_2 == 0) {
        var_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        var_17 = *(u8 **)var_17;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)(var_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(var_17 + 8), sp48);
            sp48[0] = 0xFF;
            sp48[1] = 0xFF;
            sp48[2] = 0xFF;
            func_004b13f0(*(u8 **)(var_17 + 8), sp48);
        }
        var_17 = *(u8 **)(var_17 + 0x10);
loop_16_check:
        if (var_17 == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (temp_3_2 == 1) {
        temp_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        temp_17 = *(u8 **)temp_17;
        temp_17 = *(u8 **)(temp_17 + 0x10);
        temp_17 = *(u8 **)(temp_17 + 0x10);
        if (*(s32 *)(temp_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(temp_17 + 8), sp44);
            sp44[0] = sp4C[0];
            sp44[1] = sp4C[1];
            sp44[2] = sp4C[2];
            func_004b13f0(*(u8 **)(temp_17 + 8), sp44);
        }
    }
mode_done:
    func_0047a220(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50), sp4C);
    return 0;
}



/* measured: nd 164 after four attempts. The u8 sp buffer must be ONE array
   (separate u8 locals get dead-store-eliminated — only the address-taken
   byte aliases; cascades into the sp[9]/sp[10] conversions). The saturation
   idiom from gc_model.c (if (x < 2.1474836e9f) {(u8)(s32)x} else {(u8)(s32)
   (x - 2.1474836e9f)}) reproduces the cvt.w.s guard for VARIABLE values
   (blocks 2/3), but: (1) block 1's 255.0f constant still folds the whole
   compare+guard away under mwccgap (real b210 emitted c.ole.s/bc1t for it;
   tried literal, single- and multi-assigned f32 locals — all fold); (2) the
   guard comes out c.olt.s+bc1f with the normal arm inline where retail has
   c.ole.s $f0,$f1 + bc1t with the saturate arm out of line — 2 words per
   block; (3) temp_4_2 lands in $s2 (frame 0x60) where retail keeps it in a
   caller-saved temp (frame 0x50). Everything else (FMA adda.s/madd.s
   198+57*f20, mul.s 100*f20, the f20 spill at 0x0, byte copies, node loops,
   func_0047a220 tail) matches. */
// FUN_00167120
s32 func_00167120(u8 *arg0)
{
    u8 sp4C[4];
    u8 sp48[4];
    u8 sp44[4];
    f32 byte0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    s32 temp_3;
    u8 temp_3_2;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2;
    u8 *temp_4;
    u8 *var_17;
    u8 temp_byte0;
    u8 temp_byte1;
    u8 temp_byte2;
    u8 temp_byte3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_f20 = func_0044b7b0(D_007613EC *
                             (f32)(*(s32 *)(temp_16 + 8)) /
                             (f32)(*(s32 *)(temp_16 + 0xC)));
    temp_2 = func_0047a250(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50));
    temp_byte0 = *temp_2++;
    temp_byte1 = *temp_2++;
    temp_byte2 = *temp_2++;
    temp_byte3 = *temp_2++;
    sp4C[0] = temp_byte0;
    sp4C[1] = temp_byte1;
    sp4C[2] = temp_byte2;
    sp4C[3] = temp_byte3;
    *(s32 *)(temp_16 + 0xC) = 0x14;
    byte0 = 255.0f;
    sp4C[0] = (u8)byte0;
    temp_f1 = (198.0f + 0.0f) + (57.0f * temp_f20);
    sp4C[1] = (u8)temp_f1;
    temp_f1_2 = 100.0f * temp_f20;
    sp4C[2] = (u8)temp_f1_2;
    temp_3 = *(s32 *)(temp_16 + 8) + 1;
    *(s32 *)(temp_16 + 8) = temp_3;
    if (*(s32 *)(temp_16 + 0xC) < temp_3) {
        *(s32 *)(temp_16 + 8) = 0;
    }
    temp_4 = *(u8 **)(temp_16 + 4);
    temp_3_2 = *(u8 *)(temp_4 + 0x1CA);
    if (temp_3_2 == 0) {
        var_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        var_17 = *(u8 **)var_17;
        goto loop_16_check;
loop_16_body:
        if (*(s32 *)(var_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(var_17 + 8), sp48);
            sp48[0] = 0xFF;
            sp48[1] = 0xFF;
            sp48[2] = 0xFF;
            func_004b13f0(*(u8 **)(var_17 + 8), sp48);
        }
        var_17 = *(u8 **)(var_17 + 0x10);
loop_16_check:
        if (var_17 == NULL) {
            goto mode_done;
        }
        goto loop_16_body;
    } else if (temp_3_2 == 1) {
        temp_17 = *(u8 **)(*(u8 **)(temp_4 + 0x50) + 0x2CC);
        temp_17 = *(u8 **)temp_17;
        temp_17 = *(u8 **)(temp_17 + 0x10);
        temp_17 = *(u8 **)(temp_17 + 0x10);
        if (*(s32 *)(temp_17 + 8) != 0) {
            func_004b14f0(*(u8 **)(temp_17 + 8), sp44);
            sp44[0] = sp4C[0];
            sp44[1] = sp4C[1];
            sp44[2] = sp4C[2];
            func_004b13f0(*(u8 **)(temp_17 + 8), sp44);
        }
    }
mode_done:
    func_0047a220(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x50), sp4C);
    return 0;
}



// FUN_001673F0
void func_001673f0(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}





// FUN_00167420
s32 func_00167420(u8 *arg0, u8 *arg1)
{
    s32 r;
    s32 task;
    func_0044ea90(D_005F1500, 0xD36);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x10, 0x40000);
    if (r == 0) {
        return 0;
    }
    task = (s32)func_00451fc0(arg0, D_005F15C0, 0xF, 0, 0, (void (*)(void *))*(void **)(D_005F15B0 + (*(u16 *)(arg1 + 0x1C8) << 2)), (void (*)(void *))func_001673f0, r);
    *(u8 **)(r + 4) = arg1;
    *(s32 *)(r + 0xC) = 0x28;
    *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) |= 0x80;
    if (*(u8 *)(arg1 + 0x1CA) == 1) {
        *(s32 *)(*(u32 *)(arg1 + 0x50) + 0xD8) &= ~0x100;
    }
    return task;
}

// FUN_00167530
void func_00167530(void)
{
    memset(D_007E8020, 0, 0x40);
}





/* measured: nd ~200 after four attempts. Retail recomputes the slot pointer
   inside the if-branch (temp_2 = D_007E8C00 + var_21*0x750, fresh mult) even
   though the loop head computed the identical value into temp_17; mwcc b210
   CSEs the recomputation and reuses $17, losing 6 words (same
   CSE-of-recomputation floor as func_00164fa0; tried pointer arithmetic,
   (s32)&-int-cast spellings, temp_5/temp_5_2 fresh forms — the int-cast also
   grows the frame to 0x90). Everything else (the (s32) cvt conversions, the
   ±3/±2 comparison chains, the 0xE1F/0xE3C guards, D_007E8020 sw stores)
   matches; only var_21/var_20 and the sltu-on-var_5 check registers remain
   after the CSE issue. */
// FUN_00167560
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_00167560);



/* measured: func_001679d0's best honest C is 772B at normalized_diff 184;
   switch layout, local lifetimes, pointer splitting, and ready-test widths
   did not close the register/control-flow scheduling residual. Archived in
   docs/probe_archive/W47FldUnit_001679d0_body.c; restored assembly fallback. */
// FUN_001679D0
INCLUDE_ASM("asm/nonmatchings/k_fldUnit", func_001679d0);

// FUN_00167D60
void func_00167d60(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}



// FUN_00167D90
s32 func_00167d90(u8 *arg0)
{
    s32 r;
    s32 task;
    u32 acc = 0;
    s32 i = 0;
    s32 j = 0;
    while (i < 4) {
        u32 v = *(u32 *)arg0;
        if (v != 0) {
            acc |= (v & 0xFF) << (j * 8);
            j++;
        }
        i++;
        arg0 += 8;
    }
    if (acc == 0) {
        return 0;
    }
    if (func_00162510(*(u16 *)D_00762EA0, *(u16 *)(D_00762EA0 + 4)) == 1 || func_0015a160() == 0) {
        return 0;
    }
    func_0044ea90(D_005F1500, 0xED8);
    r = ((s32 (*)(s32, s32, s32))DAT_008873F4[0])(1, 0x28, 0x40000);
    if (r == 0) {
        return 0;
    }
    task = (s32)func_00451fc0(NULL, D_005F15E0, 0xF, 0, 0, (void (*)(void *))func_001679d0, (void (*)(void *))func_00167d60, r);
    *(s32 *)(r + 4) = acc & 0xFF;
    *(s32 *)(r + 8) = (acc >> 8) & 0xFF;
    *(s32 *)(r + 0xC) = (acc >> 16) & 0xFF;
    *(s32 *)(r + 0x10) = (acc >> 24) & 0xFF;
    return task;
}
