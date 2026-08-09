#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern void (*D_00713E70[])(void);
extern void (*D_00713E78[])(void);
extern void (*D_00713E7C[])(void);
extern void (*D_00713E80[])(void);
extern void *func_004988c0(u16 arg0, u8 *arg1);
extern void *func_0049a370(u16 arg0, u8 *arg1);
extern void (*D_00713F18[])(s32);
extern void (*D_00713F10[])(void);
extern void (*D_00713F1C[])(void);
extern void (*D_00713F20[])(void);
extern void (*D_00713D54[])(void);
extern u32 func_004bd050(u32 arg0);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_0049Color;
extern Code1_0049Color iGpffffbb64;

extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}

extern void func_004841c0(void *arg0);

extern void func_00484280();



// FUN_00490360
void func_00490360(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490360_check;
loop_00490360_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490360_check:
    if (var_7 < 3U) {
        goto loop_00490360_body;
    }
}
// FUN_004903C0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004903c0);
// FUN_00490BB0
void func_00490bb0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490bb0_check;
loop_00490bb0_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490bb0_check:
    if (var_7 < 3U) {
        goto loop_00490bb0_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
    *(f32 *)(temp_6 + 0xE8) = *(f32 *)(temp_5 + 0xE8) * fparg0;
}
// FUN_00490C40
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00490c40);
// FUN_00491660
void func_00491660(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00491660_check;
loop_00491660_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00491660_check:
    if (var_7 < 3U) {
        goto loop_00491660_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}
// FUN_004916F0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004916f0);
// FUN_00492080
void func_00492080(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492080_check;
loop_00492080_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492080_check:
    if (var_7 < 3U) {
        goto loop_00492080_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
}
// FUN_00492100
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492100);
// FUN_00492A80
void func_00492a80(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492a80_check;
loop_00492a80_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492a80_check:
    if (var_7 < 3U) {
        goto loop_00492a80_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
}
// FUN_00492B20
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492b20);
// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}



// FUN_00492D00
void func_00492d00(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

/* measured: probing opt_loop_invariants for the preheader -1 and loop branch. */
#pragma opt_loop_invariants on
// FUN_00492D10
void func_00492d10(u8 *arg0, u8 *arg1, u32 arg2) {
    extern void (*D_00713D50[])(u8 *, u8 *, u32);
    u32 count;
    u32 var_6;
    u8 *var_5;

    var_5 = arg1;
    var_6 = arg2;
    if (*(s32 *)(arg0 + 0x10) == 0) {
        count = *(u32 *)(arg0 + 8);
        var_5 = *(u8 **)(arg0 + 0x18);
        var_6 = 0;
        goto loop_00492d10_check;
loop_00492d10_body:
        *(s32 *)(var_5 + 0x10) = -1;
        var_5 += 0x20;
        var_6 += 1;
loop_00492d10_check:
        if (var_6 < count) {
            goto loop_00492d10_body;
        }
    }
    D_00713D50[*(u16 *)arg0 * 4](arg0, var_5, var_6);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) + 1;
}
/* measured: closes opt_loop_invariants at its prior file baseline. */
#pragma opt_loop_invariants off
// FUN_00492E30
void func_00492e30(u16 *arg0) {
    D_00713D54[*arg0 * 4]();
}
// FUN_004940D0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004940d0);
// FUN_004941F0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004941f0);
// FUN_00494680
void func_00494680(void *arg0)
{
    func_004841c0(*(void **)((u8 *)arg0 + 0x10));
    func_004841c0(*(void **)((u8 *)arg0 + 0x14));
    jtbl_008873EC[0](arg0);
}



// FUN_00494740
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00494740);
// FUN_00494F90
void func_00494f90(u8 *arg0) {
    func_0048a1f0();
    func_003c2290(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x10)) + 0x10)) + 0x18), 0xA);
    func_003c2290(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x14)) + 0x10)) + 0x18), 0xA);
}

// FUN_00494FF0
void func_00494ff0(u8 *arg0) {
    extern void func_003c22f0(void *);
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    u8 *temp_18;

    temp_18 = *(u8 **)(arg0 + 0x14);
    temp_17 = *(u8 **)(*(u8 **)(temp_18 + 0x10) + 0x18);
    func_003c22f0(temp_17);
    if (*(u16 *)temp_18 & 4) {
        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
    }
    temp_17_2 = *(u8 **)(arg0 + 0x10);
    temp_16 = *(u8 **)(*(u8 **)(temp_17_2 + 0x10) + 0x18);
    func_003c22f0(temp_16);
    if (*(u16 *)temp_17_2 & 4) {
        *(u16 *)(temp_16 + 0xC) = *(u16 *)(temp_16 + 0xC) | 1;
    }
}
// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(void **)(arg0 + 0x10));
    func_00484280(*(void **)(arg0 + 0x14), arg1);
}

// FUN_004950E0
void func_004950e0(u8 *arg0) {
    u32 temp_16;
    u8 *var_18;
    u32 var_17;

    var_18 = *(u8 **)(*(u8 ***)(arg0 + 0x30));
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    var_17 = 0;
    goto loop_004950e0_check;
loop_004950e0_body:
    *(s32 *)(var_18 + 4) = -1 - (func_004bd050(0) & 3);
    var_17 += 1;
    var_18 += 0x10;
loop_004950e0_check:
    if (var_17 < temp_16) {
        goto loop_004950e0_body;
    }
}
// FUN_00498AC0
void func_00498ac0(u8 *arg0) {
    D_00713E78[*(s32 *)(arg0 + 0x2C) * 6]();
    jtbl_008873EC[0](arg0);
}
// FUN_00498B20
void func_00498b20(u8 *arg0) {
    func_004988c0(*(u16 *)(arg0 + 0x2C), *(u8 **)(arg0 + 0x34));
}
// FUN_00498B50
void func_00498b50(u8 *arg0) {
    D_00713E70[*(s32 *)(arg0 + 0x2C) * 6]();
    *(s32 *)(arg0 + 0x28) = 0;
}
// FUN_00498BA0
void func_00498ba0(u8 *arg0) {
    D_00713E7C[*(s32 *)(arg0 + 0x2C) * 6]();
    *(s32 *)(arg0 + 0x28) = *(s32 *)(arg0 + 0x28) + 1;
}
// FUN_00498C00
void func_00498c00(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x28) > 0) {
        D_00713E80[*(s32 *)(arg0 + 0x2C) * 6]();
    }
}
// FUN_00498CE0
u_long128 func_00498ce0(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}
// FUN_00498CF0
u_long128 func_00498cf0(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}
// FUN_00498D00
void func_00498d00(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}
// FUN_00498D10
void func_00498d10(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
}
// FUN_00498D20
void func_00498d20(u8 *arg0) {
    u8 *temp_4;
    u8 *temp_7;
    u8 *temp_7_2;

    temp_4 = *(u8 **)(*(u8 **)(arg0 + 0x3C));
    if (iGpffffbb64.c3 != 0xFF) {
        temp_7 = *(u8 **)(temp_4 + 0x14);
        *(Code1_0049Color *)(temp_7 + 4) = iGpffffbb64;
        return;
    }
    iGpffffbb64.c3 = 0xFE;
    temp_7_2 = *(u8 **)(temp_4 + 0x14);
    *(Code1_0049Color *)(temp_7_2 + 4) = iGpffffbb64;
    iGpffffbb64.c3 = 0xFF;
}
// FUN_0049A570
void func_0049a570(u8 *arg0) {
    D_00713F18[*(s32 *)(arg0 + 0x38) * 6](*(s32 *)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}
// FUN_0049A5E0
void func_0049a5e0(u8 *arg0) {
    func_0049a370(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
}
// FUN_0049A610
void func_0049a610(u8 *arg0) {
    D_00713F10[*(s32 *)(arg0 + 0x38) * 6]();
    *(s32 *)(arg0 + 0x34) = 0;
}
// FUN_0049A660
void func_0049a660(u8 *arg0) {
    D_00713F1C[*(s32 *)(arg0 + 0x38) * 6]();
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}
// FUN_0049A6C0
void func_0049a6c0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        D_00713F20[*(s32 *)(arg0 + 0x38) * 6]();
    }
}
// FUN_0049A7A0
u_long128 func_0049a7a0(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}
// FUN_0049A7B0
u_long128 func_0049a7b0(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}
// FUN_0049A7C0
void func_0049a7c0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}
// FUN_0049A7D0
void func_0049a7d0(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
    *(f32 *)(arg0 + 0x24) = fparg0;
    *(f32 *)(arg0 + 0x28) = fparg0;
}
// FUN_0049A7F0
void func_0049a7f0(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}
/* measured: the sibling 0049b470 body matches this routine's control-flow and
   call sequence; target entries are 0x18 bytes, so the fill stride is six words. */
#pragma opt_loop_invariants on
// FUN_0049A810
void func_0049a810(u8 *arg0)
{
    extern void func_003c2290(void *, s32);
    extern void func_003c22f0(void *);
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = *(u8 **)(arg0 + 0x3C);
    entry = *(s32 **)state;
    work = *(u8 **)(state + 4);
    count = *(s32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    func_003c2290(*(u8 **)(*(u8 **)(work + 0x10) + 0x18), 2);
    tex = *(s32 ***)(*(u8 **)(*(u8 **)(work + 0x10) + 0x18) + 0x5C);
    func_0043f9c8((s32)tex[5], 0, *(s16 *)(work + 8) * 0xC);
    model = *(u8 **)(*(u8 **)(work + 0x10) + 0x18);
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        *(u16 *)(model + 0xC) = *(u16 *)(model + 0xC) | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
/* measured: closes the opt_loop_invariants scope for 0049a810 at the file baseline. */
#pragma opt_loop_invariants off
