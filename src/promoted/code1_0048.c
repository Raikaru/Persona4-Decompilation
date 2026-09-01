#include "include_asm.h"
#include "type.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern void func_00492dd0();
extern void func_00492e10();
extern void func_003c02e0(u8 *arg0);
extern void func_003c4220(s32 arg0);
extern void func_003e9390(s32 arg0);
void func_003e9cb0(void *frame, void *matrix, u32 flags);
extern void func_004823e0(u8 *arg0);
extern void func_00481f30(u8 *arg0, s32 arg1);
extern s32 func_004861f0(u8 *arg0, f32 *arg1);
extern void func_004bce50(void);
extern void func_0048a2b0(u8 *arg0, u8 *arg1);
extern f32 func_0044b920(f32 arg0);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern void func_004bcf20(f32 arg0, f32 arg1, f32 arg2);
extern s32 func_004bceb0(void);
extern void func_00486400(u8 *arg0, f32 arg1);
extern void func_00484790(u8 *arg0);
extern void func_004847e0(u8 *arg0);
extern u8 *func_00482230(s32 *arg0);
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
s32 func_00481460(s32 arg0);
extern void func_00460ac0(s32 arg0, void *arg1);
extern void func_003c42b0(void *arg0, s32 arg1);
extern s32 func_00481390(s32 arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0046d730(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void func_00485630(void);
extern void func_00485870(s32 arg0);
extern void func_00492d10(s32 arg0);
extern void func_00487c30(u8 *arg0, f32 arg1);
extern void func_00487fb0(u8 *arg0, f32 arg1);
void func_00483810();
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;
extern void func_00494f90(u8 *arg0);
extern s32 func_00494710(u8 *arg0, u16 arg1);
extern void func_00494740(u8 *arg0, u16 arg1, void *arg2, f32 arg3);
extern void func_004940d0(u8 *arg0, u16 arg1, void *arg2);
extern void func_004946f0(u8 *arg0, u16 arg1);
extern void func_004946d0(u8 *arg0, u16 arg1);
extern void func_00494ff0(u8 *arg0);


extern void (*jtbl_008873EC[])();
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}
// FUN_00481D80
u8 *func_00481d80(s32 arg0) {
    s32 temp_17;
    u8 *temp_2;
    u8 *var_16;

    var_16 = NULL;
    if (arg0 != 0) {
        var_16 = func_00482230((s32 *)(u32)arg0);
    }
    temp_17 = (*(s32 *)(var_16 + 8) * 0x14) + 0x18;
    func_0044ea90(D_007132F0, 0x72);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    *(u8 **)(temp_2 + 0) = var_16;
    *(u8 **)(temp_2 + 0x10) = temp_2 + 0x18;
    func_00481f30(temp_2, 0);
    *(s16 *)(temp_2 + 0x14) = 1;
    return temp_2;
}
// FUN_00481E30
u8 *func_00481e30(u8 **arg0) {
    s32 temp_17;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *arg0;
    *(s32 *)(temp_16 + 0x10) = *(s32 *)(temp_16 + 0x10) + 1;
    temp_17 = (*(s32 *)(temp_16 + 8) * 0x14) + 0x18;
    func_0044ea90(D_007132F0, 0x8E);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    *(u8 **)(temp_2 + 0) = temp_16;
    *(u8 **)(temp_2 + 0x10) = temp_2 + 0x18;
    func_00481f30(temp_2, 0);
    *(s16 *)(temp_2 + 0x14) = 1;
    return temp_2;
}
// FUN_00481EE0
void func_00481ee0(u8 **arg0)
{
    func_004823e0(*arg0);
    jtbl_008873EC[0](arg0);
}
// FUN_00481F30
void func_00481f30(u8 *arg0, s32 arg1)
{
    s16 temp_16_2;
    s32 *temp_5;
    s32 *temp_5_2;
    s32 *temp_5_3;
    s32 *temp_5_4;
    s32 temp_16;
    s32 temp_22;
    s32 temp_4_2;
    u32 temp_3;
    s32 var_20;
    u8 *temp_16_3;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_18_2;
    u8 *temp_18_3;
    u8 *temp_19;
    u8 *temp_23;
    u8 *temp_30;
    u8 *temp_4;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *temp_4_5;

    temp_19 = *(u8 **)(arg0 + 0);
    if (*(s32 *)(*(u8 **)(temp_19 + 0) + 4) <= arg1) {
        func_0046d730(D_007132F0, 0xCB);
    }
    temp_16 = arg1 * 0x14;
    temp_18 = *(u8 **)(temp_19 + 4) + temp_16;
    if (*(u32 *)(temp_18 + 0xC) != 0) {
        if (*(s32 *)(temp_18 + 0x10) & 0x10000000) {
            *(s32 *)(arg0 + 4) = 0x10000000;
            *(s32 *)(arg0 + 8) = arg1;
            *(u32 *)(arg0 + 0xC) = *(u32 *)(temp_18 + 0xC);
            temp_30 = *(u8 **)(temp_19 + 0) + *(s32 *)(temp_18 + 0);
            var_20 = 0;
            goto loop_00481f30_check;
loop_00481f30_body:
            temp_22 = var_20 * 0x14;
            temp_17 = *(u8 **)(arg0 + 0x10) + temp_22;
            temp_23 = temp_30 + var_20 * 0x18;
            temp_16_2 = *(s16 *)(temp_23 + 0);
            if (*(s32 *)(*(u8 **)(temp_19 + 0) + 4) <= temp_16_2) {
                func_0046d730(D_007132F0, 0xB0);
            }
            temp_5 = (s32 *)(*(u8 **)(temp_19 + 4) + temp_16_2 * 0x14);
            temp_4 = *(u8 **)(temp_19 + 0) + *temp_5;
            *(s32 *)(temp_17 + 4) = 0;
            *(s32 *)(temp_17 + 8) = *(s16 *)(temp_4 + 0x12);
            *(s32 **)(temp_17 + 0xC) = temp_5;
            *(u8 **)(temp_17 + 0x10) = temp_4;
            *(s32 *)(*(u8 **)(arg0 + 0x10) + temp_22 + 4) =
                -(s32)*(s16 *)(temp_23 + 2);
            var_20 += 1;
loop_00481f30_check:
            temp_3 = (u32)*(u32 *)(temp_18 + 0xC) > (u32)var_20;
            if (temp_3 == 0) {
                goto loop_00481f30_done;
            } else {
                goto loop_00481f30_body;
            }
        } else {
            temp_4_2 = *(s32 *)(temp_18 + 8);
            if (temp_4_2 & 0xC0) {
                *(s32 *)(arg0 + 4) = temp_4_2;
                *(s32 *)(arg0 + 8) = arg1;
                *(u32 *)(arg0 + 0xC) = 2U;
                temp_18_2 = *(u8 **)(arg0 + 0x10);
                if (*(s32 *)(*(u8 **)(temp_19 + 0) + 4) <= arg1) {
                    func_0046d730(D_007132F0, 0xB0);
                }
                temp_5_2 = (s32 *)(*(u8 **)(temp_19 + 4) + temp_16);
                temp_4_3 = *(u8 **)(temp_19 + 0) + *temp_5_2;
                *(s32 *)(temp_18_2 + 4) = 0;
                *(s32 *)(temp_18_2 + 8) = *(s16 *)(temp_4_3 + 0x12);
                *(s32 **)(temp_18_2 + 0xC) = temp_5_2;
                *(u8 **)(temp_18_2 + 0x10) = temp_4_3;
                temp_16_3 = *(u8 **)(arg0 + 0x10) + 0x14;
                if (*(s32 *)(*(u8 **)(temp_19 + 0) + 4) <= (arg1 + 1)) {
                    func_0046d730(D_007132F0, 0xB0);
                }
                temp_5_3 =
                    (s32 *)(*(u8 **)(temp_19 + 4) + (arg1 + 1) * 0x14);
                temp_4_4 = *(u8 **)(temp_19 + 0) + *temp_5_3;
                *(s32 *)(temp_16_3 + 4) = 0;
                *(s32 *)(temp_16_3 + 8) = *(s16 *)(temp_4_4 + 0x12);
                *(s32 **)(temp_16_3 + 0xC) = temp_5_3;
                *(u8 **)(temp_16_3 + 0x10) = temp_4_4;
            } else {
                *(s32 *)(arg0 + 4) = 0;
                *(s32 *)(arg0 + 8) = arg1;
                *(u32 *)(arg0 + 0xC) = 1U;
                temp_18_3 = *(u8 **)(arg0 + 0x10);
                if (*(s32 *)(*(u8 **)(temp_19 + 0) + 4) <= arg1) {
                    func_0046d730(D_007132F0, 0xB0);
                }
                temp_5_4 = (s32 *)(*(u8 **)(temp_19 + 4) + temp_16);
                temp_4_5 = *(u8 **)(temp_19 + 0) + *temp_5_4;
                *(s32 *)(temp_18_3 + 4) = 0;
                *(s32 *)(temp_18_3 + 8) = *(s16 *)(temp_4_5 + 0x12);
                *(s32 **)(temp_18_3 + 0xC) = temp_5_4;
                *(u8 **)(temp_18_3 + 0x10) = temp_4_5;
            }
        }
loop_00481f30_done:
        *(s16 *)(arg0 + 0x14) = 1;
    }
}
/* measured: opt_loop_invariants on hoists the second-loop preheader constants. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off preserves the target pointer evaluation order. */
#pragma opt_propagation off
// FUN_00482230
u8 *func_00482230(s32 *arg0)
{
    u8 *temp_2;
    s32 *var_18;
    s32 temp_17;
    s32 temp_16;
    s32 temp_4_2;
    s32 var_17;
    s32 var_7;
    u8 *temp_17_2;
    u8 *temp_2_3;
    u8 *temp_4;
    s32 temp_3;
    u8 *scratch;
    extern void func_0043f810(void *dst, void *src, u32 size);
    {
        s32 offset;
        s32 *temp_2_2;
        offset = *(s32 *)arg0;
        temp_2_2 = (s32 *)((u8 *)arg0 + offset);
        temp_16 = *temp_2_2;
        var_18 = temp_2_2 + 1;
        temp_17 = offset + 0x1C;
        temp_17 += temp_16 * 4;
    }
    func_0044ea90(D_007132F0, 0x114);
    temp_2 = (u8 *)jtbl_008873E8[0](temp_17, 0x40000);
    *(u8 **)(temp_2 + 0x18) = temp_2;
    temp_17_2 = temp_2 + 0x1C;
    func_0043f810(temp_17_2, arg0, *arg0);
    *(u8 **)(temp_2 + 0) = temp_17_2;
    *(u8 **)(temp_2 + 4) = temp_17_2 + 8;
    *(s32 *)(temp_2 + 0xC) = temp_16;
    temp_2_3 = *(u8 **)(temp_2 + 0);
    scratch = temp_2_3 + 8;
    temp_4_2 = *(s32 *)temp_2_3;
    *(u8 **)(temp_2 + 0x14) =
        (u8 *)((s32)scratch + temp_4_2);

    var_17 = 0;
    while (var_17 < temp_16) {
        s32 temp_3;
        temp_3 = func_00481390((s32)((u8 *)arg0 + *var_18));
        *(s32 *)(*(u8 **)(temp_2 + 0x14) + (var_17 * 4)) = temp_3;
        var_18 += 1;
        var_17 += 1;
    }
    *(s32 *)(temp_2 + 0x10) = 1;
    *(s32 *)(temp_2 + 8) = 1;
    temp_3 = *(s32 *)(*(u8 **)(temp_2 + 0) + 4);
    var_7 = 0;
    while (var_7 < temp_3) {
        temp_4 = *(u8 **)(temp_2 + 4) + (var_7 * 0x14);
        if ((*(s32 *)(temp_4 + 0x10) & 0x10000000) != 0) {
            *(s32 *)(temp_2 + 8) = *(s32 *)(temp_4 + 0xC);
        } else {
            temp_4_2 = *(s32 *)(temp_4 + 8);
            if ((temp_4_2 & 0x40) != 0) {
                *(s32 *)(temp_2 + 8) = 2;
            } else if ((temp_4_2 & 0x80) != 0) {
                *(s32 *)(temp_2 + 8) = 2;
            }
        }
        var_7 += 1;
    }
    return temp_2;
}
/* measured: restore opt_propagation after func_00482230. */
#pragma opt_propagation on
/* measured: restore opt_loop_invariants after func_00482230. */
#pragma opt_loop_invariants off
// FUN_004823E0
void func_004823e0(u8 *arg0) {
    s32 temp_3;
    s32 var_17;

    if ((arg0 == NULL) || (*(s32 *)(arg0 + 0x10) == 0)) {
        func_0046d730(D_007132F0, 0x151);
    }
    temp_3 = *(s32 *)(arg0 + 0x10) - 1;
    *(s32 *)(arg0 + 0x10) = temp_3;
    if (temp_3 == 0) {
        var_17 = 0;
        goto loop_004823e0_check;
loop_004823e0_body:
        func_003ef3a0(*(void **)(*(u8 **)(arg0 + 0x14) + (var_17 * 4)));
        var_17 += 1;
loop_004823e0_check:
        if (var_17 < *(s32 *)(arg0 + 0xC)) {
            goto loop_004823e0_body;
        }
        (*jtbl_008873EC)(*(u8 **)(arg0 + 0x18));
    }
}
// FUN_004824A0
void func_004824a0(u8 *arg0, u8 *arg1, u8 *arg2)
{
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    s32 temp_7_2;
    s32 temp_8;
    s32 var_5;
    u32 temp_9;
    u32 temp_9_2;
    u8 **temp_3_2;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_5;
    u8 *temp_7;

    temp_3 = *(u8 **)(arg0 + 0);
    temp_7 = *(u8 **)(arg1 + 0xC);
    if ((*(s32 *)(temp_7 + 0x10) & 0x10000000) == 0) {
        temp_8 = *(s32 *)(arg1 + 8);
        if (temp_8 <= 0) {
            temp_9 = *(u32 *)(arg1 + 4) + 1;
            *(u32 *)(arg1 + 4) = temp_9;
            if (temp_9 >= *(u32 *)(temp_7 + 0xC)) {
                if ((*(s32 *)(temp_7 + 0x10) & 0x10) != 0) {
                    *(s16 *)(arg0 + 0x14) = 0;
                    *(u32 *)(arg1 + 4) = *(u32 *)(temp_7 + 0xC) - 1;
                } else {
                    *(u32 *)(arg1 + 4) = 0;
                }
            }
            temp_5 = *(u8 **)(arg1 + 0x10);
            temp_9_2 = *(u32 *)(arg1 + 4);
            temp_4 = (u8 *)(temp_9_2 * 0x18);
            temp_4 = (u8 *)((u32)temp_4 + (u32)temp_5);
            *(s32 *)(arg1 + 8) = *(s16 *)(temp_4 + 0x12);
        } else {
            *(s32 *)(arg1 + 8) = temp_8 - 1;
        }
        temp_9_2 = *(u32 *)(arg1 + 4);
        temp_4 = *(u8 **)(arg1 + 0x10) + (temp_9_2 * 0x18);
        temp_7_2 = *(s32 *)(temp_7 + 0x10);
        if ((temp_7_2 & 1) != 0) {
            var_5 = *(s32 *)(*(u8 **)(temp_3 + 0) +
                             *(s32 *)(temp_7 + 4) + (temp_9_2 * 4));
        } else {
            var_5 = -1;
        }
        *(s32 *)(arg2 + 0x2C) = var_5;
        temp_3_2 = *(u8 ***)(*(u8 **)(temp_3 + 0x14) +
                             (*(s16 *)(temp_4 + 0x10) * 4));
        temp_5 = *(u8 **)(temp_3_2 + 0);
        temp_f5 = (f32)*(s32 *)(temp_5 + 0xC);
        temp_f6 = (f32)*(s32 *)(temp_5 + 0x10);
        temp_7_2 = *(s32 *)(temp_7 + 0x10);
        if ((temp_7_2 & 2) != 0) {
            *(s16 *)(arg2 + 0x28) = 2;
        } else if ((temp_7_2 & 4) != 0) {
            *(s16 *)(arg2 + 0x28) = 3;
        } else {
            *(s16 *)(arg2 + 0x28) = 1;
        }
        *(f32 *)(arg2 + 0x10) = *(f32 *)(temp_4 + 0x14);
        temp_f4 = (f32)*(s16 *)(temp_4 + 4);
        temp_f3 = (f32)*(s16 *)(temp_4 + 6);
        temp_f2 = (f32)*(s16 *)(temp_4 + 0);
        temp_f1 = (f32)*(s16 *)(temp_4 + 2);
        *(f32 *)(arg2 + 0x18) =
            (f32)((s32)*(s16 *)(temp_4 + 8) >> 4) / temp_f5;
        *(f32 *)(arg2 + 0x1C) =
            (f32)((s32)*(s16 *)(temp_4 + 0xA) >> 4) / temp_f6;
        *(f32 *)(arg2 + 0x20) =
            (f32)((s32)*(s16 *)(temp_4 + 0xC) >> 4) / temp_f5;
        *(f32 *)(arg2 + 0x24) =
            (f32)((s32)*(s16 *)(temp_4 + 0xE) >> 4) / temp_f6;
        temp_f2 = temp_f2 / 2.0f;
        temp_f1 = temp_f1 / 2.0f;
        *(f32 *)(arg2 + 0) = temp_f2 - temp_f4;
        *(f32 *)(arg2 + 4) = temp_f1 - temp_f3;
        *(f32 *)(arg2 + 8) = temp_f2;
        *(f32 *)(arg2 + 0xC) = temp_f1;
        *(f32 *)(arg2 + 0x30) = temp_f5;
        *(f32 *)(arg2 + 0x34) = temp_f6;
        *(u8 **)(arg2 + 0x14) = (u8 *)temp_3_2;
    }
}
// FUN_00482790
s32 func_00482790(u8 **arg0, u32 arg1)
{
    u8 *temp_16;

    temp_16 = *arg0;
    if (*(u32 *)(temp_16 + 0xC) <= arg1) {
        func_0046d730(D_007132F0, 0x1E9);
    }
    return *(s32 *)(*(u8 **)(temp_16 + 0x14) + arg1 * 4);
}
// FUN_00484010
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484010);
// FUN_004841C0
void func_004841c0(u8 *arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 var_16;

    temp_4 = *(s32 *)(arg0 + 0x10);
    if (temp_4 != 0) {
        func_003c02e0((u8 *)temp_4);
    }
    temp_4_2 = *(s32 *)(arg0 + 0xC);
    if (temp_4_2 != 0) {
        func_003e9390(temp_4_2);
    }
    if (*(s32 *)(arg0 + 0x54) != 0) {
        var_16 = 0;
        goto loop_004841c0_check;
loop_004841c0_body:
        func_003c4220(*(s32 *)(*(u8 **)(arg0 + 0x54) + ((u16)var_16 * 4)));
        var_16 = (var_16 + 1) & 0xFFFF;
loop_004841c0_check:
        if ((var_16 & 0xFFFF) < *(s16 *)(arg0 + 0x48)) {
            goto loop_004841c0_body;
        }
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00484280
void func_00484280(u8 *arg0, s32 arg1)
{
    s32 temp_2;

    temp_2 = func_00481460(arg1);
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    func_00460ac0(temp_2, arg0 + 0x18);
}
// FUN_004842D0
void func_004842d0(u8 *arg0, s32 arg1)
{
    s32 var_16;

    var_16 = 0;
    goto loop_004842d0_check;
loop_004842d0_body:
    func_003c42b0(*(void **)(*(u8 **)(arg0 + 0x54) + ((u16)var_16 * 4)), arg1);
    var_16 = (var_16 + 1) & 0xFFFF;
loop_004842d0_check:
    if ((var_16 & 0xFFFF) < *(s16 *)(arg0 + 0x48)) {
        goto loop_004842d0_body;
    }
}
// FUN_00484350
void func_00484350(u8 *arg0)
{
    RwMatrix matrix;

    func_00483700(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}

// FUN_004843A0
void func_004843a0(u8 *arg0)
{
    RwMatrix matrix;

    func_00483810(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}

// FUN_004843F0
void func_004843f0(u8 *arg0, s32 arg1) {
    u16 var_17;
    s32 temp_16;
    u16 index;

    temp_16 = func_00481390(arg1);
    var_17 = 0;
    goto loop_004843f0_check;
loop_004843f0_body:
    index = (u16)var_17;
    func_003c42b0(
        *(void **)(*(u8 **)(arg0 + 0x54) + (index * 4)),
        temp_16);
    var_17 += 1;
loop_004843f0_check:
    if ((u16)var_17 < *(s16 *)(arg0 + 0x48)) {
        goto loop_004843f0_body;
    }
    func_003ef3a0((void *)temp_16);
}
// FUN_00484510
void func_00484510(void)
{
}

// FUN_00484520
void func_00484520(void)
{
}

// FUN_00484530
s32 func_00484530(void)
{
    return 0;
}

// FUN_00484540
void func_00484540(void)
{
}

// FUN_00484550
void func_00484550(void)
{
}

// FUN_00484560
s32 func_00484560(void)
{
    return 1;
}
// FUN_00484570
u8 *func_00484570(u8 *arg0)
{
    u32 temp_3;
    u16 temp_18;
    u8 *temp_2;

    temp_3 = *(u32 *)(arg0 + 0);
    if (temp_3 <= 0xD2U) {
        goto code1_0048_84570_after_check;
    } else {
        func_0046d730(D_00713470, 0x2D7);
    }
code1_0048_84570_after_check:
    temp_18 = *(u16 *)(arg0 + 4);
    func_0044ea90(D_00713470, 0x21);
    temp_2 = jtbl_008873E8[0](0x2C, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00713470, 0x22);
    }
    func_0043f9c8(temp_2, 0, 0x2C);
    *(s32 *)(temp_2 + 0) = 0xD2;
    *(u16 *)(temp_2 + 4) = temp_18;
    *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0xC);
    *(u16 *)(temp_2 + 0x1C) = *(u16 *)(arg0 + 0x1C);
    if (*(u16 *)(temp_2 + 4) >= 0x21U) {
        func_0046d730(D_00713470, 0x2DD);
    }
    if (*(s32 *)(D_00713480 + (*(u16 *)(temp_2 + 4) << 6)) == 0) {
        func_0046d730(D_00713470, 0x2DE);
    }
    *(s32 *)(temp_2 + 8) =
        (*(s32 (**)(u8 *))(D_00713480 + (*(u16 *)(temp_2 + 4) << 6)))(
            arg0);
    return temp_2;
}
// FUN_004846D0
void func_004846d0(u8 *arg0) {
    s32 (*temp_2)(s32);
    u8 *base;

    base = arg0;
    if (*(s32 *)(base + 8) != 0) {
        temp_2 = *(s32 (**)(s32))(D_00713490 +
            (*(u16 *)(base + 4) << 6));
        if (temp_2 == NULL) {
            func_0046d730(D_00713470, 0x2EB);
        }
        code1_0048_call(
            *(s32 (**)(s32))(D_00713490 + (*(u16 *)(base + 4) << 6)),
            *(s32 *)(base + 8));
    }
    func_00484790(base);
    func_004847e0(base);
    (*jtbl_008873EC)(base);
}

// FUN_00484790
void func_00484790(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[6];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
        *(u8 **)(arg0 + 0x18) = NULL;
    }
}

// FUN_004847E0
void func_004847e0(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[10];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x20) = 0;
        *(s32 *)(arg0 + 0x24) = 0;
        *(u8 **)(arg0 + 0x28) = NULL;
    }
}

// FUN_00484830
u8 *func_00484830(u8 *arg0)
{
    u32 temp_3;
    u16 temp_18;
    u8 *temp_2;
    temp_3 = *(u32 *)(arg0 + 0);
    if (temp_3 <= 0xD2U) {
        goto code1_0048_after_check;
    } else {
        func_0046d730(D_00713470, 0x318);
    }
code1_0048_after_check:
    temp_18 = *(u16 *)(arg0 + 4);
    func_0044ea90(D_00713470, 0x21);
    temp_2 = jtbl_008873E8[0](0x2C, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_00713470, 0x22);
    }
    func_0043f9c8(temp_2, 0, 0x2C);
    *(s32 *)(temp_2 + 0) = 0xD2;
    *(u16 *)(temp_2 + 4) = temp_18;
    *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0xC);
    *(u16 *)(temp_2 + 0x1C) = *(u16 *)(arg0 + 0x1C);
    if (*(s32 *)(D_00713494 + (*(u16 *)(temp_2 + 4) << 6)) == 0) {
        func_0046d730(D_00713470, 0x321);
    }
    *(s32 *)(temp_2 + 8) =
        (*(s32 (**)(s32))(D_00713494 + (*(u16 *)(temp_2 + 4) << 6)))(
            *(s32 *)(arg0 + 8));
    return temp_2;
}
// FUN_00484970
void func_00484970(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_0071349C + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_004849C0
void func_004849c0(u8 *arg0)
{
    void (*fn)(s32) = *(void (**)(s32))(D_00713488 + (*(u16 *)(arg0 + 4) << 6));
    fn(*(s32 *)(arg0 + 8));
}
// FUN_00484A00
void func_00484a00(u8 *arg0)
{
    void (*fn)(s32) = *(void (**)(s32))(D_0071348C + (*(u16 *)(arg0 + 4) << 6));
    fn(*(s32 *)(arg0 + 8));
}
// FUN_00484A40
void func_00484a40(u8 *arg0, void *arg1) {
    void (*fn)(s32, void *) = *(void (**)(s32, void *))(D_007134A0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

// FUN_00484A90
void func_00484a90(u8 *arg0) {
    void (*fn)(s32) = *(void (**)(s32))(D_007134A8 + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8));
    }
}

// FUN_00484AE0
void func_00484ae0(u8 *arg0, s32 arg1) {
    void (*fn)(s32, s32) = *(void (**)(s32, s32))(D_007134B0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

/* Measured compiled-C park: typed 16-byte aggregate copy reproduces retail
   D_00713CE0 lq/sq transfer widths; object 120B / window 128B,
   normalized_diff 6. Exact residual rows are archived in
   build/WBSmallFiles_code1_0048_00484b30_park.txt. Committed at nd 6. */
// FUN_00484B30 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484b30);

// FUN_00484BB0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484bb0);
// FUN_00485630
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485630);
// FUN_00485870
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485870);
// FUN_00485AE0
void func_00485ae0(s32 arg0)
{
    func_00485630();
    func_00485870(arg0);
}
// FUN_00485B20
void func_00485b20(u8 *arg0)
{
    u8 *var_18;
    u8 *temp_17;
    u8 *temp_16;
    u8 *temp_4;
    u8 *temp_4_2;

    var_18 = *(u8 **)(arg0 + 0x8C);
    goto loop_00485b20_check;
loop_00485b20_body:
    temp_17 = *(u8 **)(var_18 + 0xAC);
    if ((*(s32 *)(var_18 + 0x98) & 1) == 0) {
        temp_16 = *(u8 **)(var_18 + 0x90);
        if (*(s32 *)(temp_16 + 8) != 0) {
            if (*(s32 *)(D_00713480 + (*(u16 *)(temp_16 + 4) << 6) + 0x10) == 0) {
                func_0046d730(D_00713470, 0x2EB);
            }
            (*(void (**)(s32))(D_00713480 + (*(u16 *)(temp_16 + 4) << 6) + 0x10))(
                *(s32 *)(temp_16 + 8));
        }
        temp_4 = *(u8 **)(temp_16 + 0x18);
        if (temp_4 != NULL) {
            jtbl_008873EC[0](temp_4);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 0x14) = 0;
            *(u8 **)(temp_16 + 0x18) = NULL;
        }
        temp_4_2 = *(u8 **)(temp_16 + 0x28);
        if (temp_4_2 != NULL) {
            jtbl_008873EC[0](temp_4_2);
            *(s32 *)(temp_16 + 0x20) = 0;
            *(s32 *)(temp_16 + 0x24) = 0;
            *(u8 **)(temp_16 + 0x28) = NULL;
        }
        jtbl_008873EC[0](temp_16);
    }
    jtbl_008873EC[0](var_18);
    var_18 = temp_17;
loop_00485b20_check:
    if (var_18 != NULL) {
        goto loop_00485b20_body;
    }
    jtbl_008873EC[0](arg0);
}
// FUN_00485C80
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485c80);
// FUN_00485FE0
void func_00485fe0(u8 *arg0) {
    u8 *n = *(u8 **)(arg0 + 0x8C);
    u8 *o;
    void (*fn)(s32);

    while (n != NULL) {
        o = *(u8 **)(n + 0x90);
        fn = *(void (**)(s32))(D_00713480 + (*(u16 *)(o + 4) << 6) + 0x1C);
        if (fn != NULL) {
            fn(*(s32 *)(o + 8));
        }
        n = *(u8 **)(n + 0xAC);
    }
    *(s32 *)(arg0 + 0x84) = 0;
}

// FUN_00486060
s32 func_00486060(u8 *arg0) {
    s32 (*temp_2)(s32);
    s32 var_2;
    u8 *temp_4;
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 0x8C);
    goto loop_00486060_check;
loop_00486060_body:
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_2 = *(s32 (**)(s32))(D_00713480 +
        (*(u16 *)(temp_4 + 4) << 6) + 0x34);
    if (temp_2 != NULL) {
        var_2 = temp_2(*(s32 *)(temp_4 + 8));
    } else {
        var_2 = 1;
    }
    if (var_2 == 0) {
        return 0;
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_00486060_check:
    if (var_16 != NULL) {
        goto loop_00486060_body;
    }
    return 1;
}
// FUN_004860F0
s32 func_004860f0(u8 *arg0) {
    s32 (*temp_2)(s32);
    s32 var_2;
    u8 *temp_4;
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 0x8C);
    goto loop_004860f0_check;
loop_004860f0_body:
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_2 = *(s32 (**)(s32))(D_00713480 +
        (*(u16 *)(temp_4 + 4) << 6) + 0x38);
    if (temp_2 != NULL) {
        var_2 = temp_2(*(s32 *)(temp_4 + 8));
    } else {
        var_2 = 0;
    }
    if (var_2 != 0) {
        return 1;
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_004860f0_check:
    if (var_16 != NULL) {
        goto loop_004860f0_body;
    }
    return 0;
}
// FUN_00486180
void func_00486180(u8 *arg0)
{
    u8 *var_16 = *(u8 **)(arg0 + 0x8C);

    while (var_16 != NULL) {
        u8 *temp_5 = *(u8 **)(var_16 + 0x90);
        void (*temp_3)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (*(u16 *)(temp_5 + 4) << 6) + 0x3C);

        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_5 + 8), temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0xAC);
    }
}

// FUN_004861F0
s32 func_004861f0(u8 *arg0, f32 *arg1)
{
    u_long128 sp50[4];
    u_long128 sp40;
    u_long128 sp30;
    f32 var_21;
    f32 var_20;
    s32 flags;
    u8 *temp_4;
    s32 (*temp_2)(s32, void *, u8 *);

    __asm__ volatile("lqc2 $vf10, 0($5)" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0x40(%0)" : : "r"(arg0) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp40) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf10, 0x50(%0)" : : "r"(arg0) : "$vf10", "memory");
    func_004bceb0();
    __asm__ volatile(
        "sqc2 $vf28, 0(%0)     \n"
        "sqc2 $vf29, 16(%0)    \n"
        "sqc2 $vf30, 32(%0)    \n"
        "sqc2 $vf31, 48(%0)    \n"
        :
        : "r"(&sp50)
        : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
    var_21 = *(f32 *)(arg0 + 0x60) * *(f32 *)(arg0 + 0x74);
    arg0 = *(u8 **)(arg0 + 0x8C);
    var_20 = 5.0f;
    goto loop_004861f0_check;
loop_004861f0_body:
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&sp40) : "$vf10", "memory");
    flags = *(s32 *)(arg0 + 0x68);
    if ((flags & 4) != 0) {
        __asm__ volatile(
            "mfc1 $2, %0       \n"
            "nop               \n"
            "qmtc2.ni $2, $vf2 \n"
            "vaddx.y $vf10, $vf0, $vf2x \n"
            :
            : "f"(var_20)
            : "$2", "$vf2", "$vf10", "memory");
    }
    __asm__ volatile("lqc2 $vf11, 0x40(%0)" : : "r"(arg0) : "$vf11", "memory");
    if ((flags & 0x80) != 0) {
        __asm__ volatile(
            "mfc1 $3, %0       \n"
            "nop               \n"
            "qmtc2.ni $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(var_21)
            : "$3", "$vf2", "$vf11", "memory");
    }
    __asm__ volatile(
        "lqc2 $vf28, 0(%0)     \n"
        "lqc2 $vf29, 16(%0)    \n"
        "lqc2 $vf30, 32(%0)    \n"
        "lqc2 $vf31, 48(%0)    \n"
        :
        : "r"(&sp50)
        : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf11x \n"
        "vmadday.xyzw $ACC, $vf29, $vf11y \n"
        "vmaddz.xyzw $vf11, $vf30, $vf11z \n"
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        :
        :
        : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp30) : "$vf10", "memory");
    temp_4 = *(u8 **)(arg0 + 0x90);
    temp_2 = *(s32 (**)(s32, void *, u8 *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
    if (temp_2 != NULL) {
        temp_2(*(s32 *)(temp_4 + 8), &sp30, temp_4);
    }
    arg0 = *(u8 **)(arg0 + 0xAC);
loop_004861f0_check:
    if (arg0 != NULL) {
        goto loop_004861f0_body;
    }
}
// FUN_00486330
void func_00486330(u8 *arg0, u8 *arg1)
{
    u_long128 scratch[2];
    u8 *temp_4;
    u8 *var_16;
    s32 (*temp_2)(s32, void *);

    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg1) : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0x50(%0)" : : "r"(arg0) : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(scratch + 1) : "$vf10", "memory");
    func_004bceb0();
    __asm__ volatile(
        "lqc2 $vf10, 0x10(%0)       \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        "sqc2 $vf10, 0(%0)          \n"
        :
        : "r"(arg0)
        : "$vf10", "ACC", "memory");
    var_16 = *(u8 **)(arg0 + 0x8C);
    goto loop_00486330_check;
loop_00486330_body:
    __asm__ volatile("lqc2 $vf10, 0x50(%0)" : : "r"(var_16) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(scratch + 1) : "$vf11", "memory");
    func_004bce50();
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(scratch) : "$vf10", "memory");
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_2 = *(s32 (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x24);
    if (temp_2 != NULL) {
        temp_2(*(s32 *)(temp_4 + 8), scratch);
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_00486330_check:
    if (var_16 != NULL) {
        goto loop_00486330_body;
    }
    func_004861f0(arg0, (f32 *)(arg0 + 0x40));
}
// FUN_00486400
void func_00486400(u8 *arg0, f32 arg1)
{
    u_long128 sp50;
    u_long128 sp40;
    f32 var_21;
    f32 var_20;
    f32 temp_f12;
    f32 temp_f0;
    s32 flags;
    u8 *temp_4;
    u8 *var_16;
    void (*temp_3)(s32, u8 *, f32);
    void (*temp_3_2)(s32, void *, u8 *);
    void (*temp_3_3)(s32, void *, u8 *);

    *(f32 *)(arg0 + 0x60) = arg1;
    var_21 = arg1 * *(f32 *)(arg0 + 0x74);
    var_16 = *(u8 **)(arg0 + 0x8C);
    var_20 = 5.0f;
    goto loop_00486400_check;
loop_00486400_body:
    flags = *(s32 *)(var_16 + 0x68);
    if ((flags & 0x100) == 0) {
        temp_f12 = *(f32 *)(var_16 + 0x60);
        if ((*(s32 *)(var_16 + 0x84) & 1) != 0) {
            temp_f12 *= var_21;
        }
        temp_4 = *(u8 **)(var_16 + 0x90);
        temp_3 = *(void (**)(s32, u8 *, f32))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x28);
        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_4 + 8), temp_4, temp_f12);
        }
        goto loop_00486400_tail;
    }
    __asm__ volatile("lqc2 $vf10, 0x20(%0)" : : "r"(var_16) : "$vf10", "memory");
    temp_f0 = *(f32 *)(var_16 + 0x60);
    if ((*(s32 *)(var_16 + 0x84) & 1) != 0) {
        temp_f0 *= var_21;
    }
    __asm__ volatile(
        "mfc1 $3, %0       \n"
        "nop               \n"
        "qmtc2.ni $3, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        :
        : "f"(temp_f0)
        : "$3", "$vf2", "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp40) : "$vf10", "memory");
    temp_4 = *(u8 **)(var_16 + 0x90);
    temp_3_2 = *(void (**)(s32, void *, u8 *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x2C);
    if (temp_3_2 != NULL) {
        temp_3_2(*(s32 *)(temp_4 + 8), &sp40, temp_4);
    }
loop_00486400_tail:
    flags = *(s32 *)(var_16 + 0x68);
    if ((flags & 0x80) != 0) {
        __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        if ((flags & 4) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vaddx.y $vf10, $vf0, $vf2x \n"
                :
                : "f"(var_20)
                : "$2", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile("lqc2 $vf11, 0x40(%0)" : : "r"(var_16) : "$vf11", "memory");
        __asm__ volatile(
            "mfc1 $3, %0       \n"
            "nop               \n"
            "qmtc2.ni $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(var_21)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp50) : "$vf10", "memory");
        temp_4 = *(u8 **)(var_16 + 0x90);
        temp_3_3 = *(void (**)(s32, void *, u8 *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
        if (temp_3_3 != NULL) {
            temp_3_3(*(s32 *)(temp_4 + 8), &sp50, temp_4);
        }
    }
    var_16 = *(u8 **)(var_16 + 0xAC);
loop_00486400_check:
    if (var_16 != NULL) {
        goto loop_00486400_body;
    }
}
// FUN_004865C0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_004865c0);
// FUN_00486780
u8 *func_00486780(u8 *arg0, s32 arg1)
{
    s32 temp_3;
    s32 var_5;
    u8 *var_2;

    var_5 = arg1;
    var_2 = *(u8 **)(arg0 + 0x8C);
    goto loop_00486780_check;
loop_00486780_body:
    temp_3 = var_5;
    var_5 -= 1;
    if (temp_3 == 0) {
        return var_2;
    }
    var_2 = *(u8 **)(var_2 + 0xAC);
loop_00486780_check:
    if (var_2 != NULL) {
        goto loop_00486780_body;
    }
    func_0046d730(D_00713470, 0xA87);
    return NULL;
}
// FUN_004867E0
s32 func_004867e0(u8 *arg0, u8 *arg1)
{
    s32 index = 0;
    u8 *node = *(u8 **)(arg0 + 0x8C);

    while (node != NULL) {
        if (node == arg1) {
            return index;
        }
        index++;
        node = *(u8 **)(node + 0xAC);
    }
    func_0046d730(D_00713470, 0xA9E);
    return 0;
}
// FUN_00486840
u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2)
{
    /* measured: O1 probe for initial flag and aggregate register colours. */
    #pragma optimization_level 1
    u32 values[3];
    u8 work[0x10];
    s32 flags;
    u_long128 value;
    s32 mask;

    {

        flags = *(s32 *)(arg0 + 0x68);
        mask = flags & 0x18;
        if (mask == 0) {
            value = *(u_long128 *)(arg0 + 0x40);
            *(u_long128 *)arg2 = value;
            return value;
        }
        __asm__ volatile(
            "lqc2 $vf10, 64(%0) \n"
            :
            : "r"(arg0)
            : "$vf10", "memory");
        mask = flags & 0x10;
        if (mask != 0) {
            u32 zero_value;

            __asm__ volatile(
                "mtc1 $zero, $f0 \n"
                "nop \n"
                "mfc1 %0, $f0 \n"
                "nop \n"
                "qmtc2 %0, $vf2 \n"
                "vaddx.y $vf10y, $vf0y, $vf2x \n"
                : "=r"(zero_value)
                :
                : "$f0", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2xyz, $vf10xyz, $vf10xyz \n"
            "vaddy.x $vf2x, $vf2x, $vf2y \n"
            "vaddz.x $vf2x, $vf2x, $vf2z \n"
            ".word 0x4a0203bd \n"
            "vwaitq \n"
            "cfc2 $2, $vi22 \n"
            "mtc1 $2, $f0 \n"
            "sw $2, 64($sp) \n"
            "sw $2, 68($sp) \n"
            "sw $2, 72($sp) \n"
            :
            :
            : "$2", "$f0", "$vf2", "$vf10", "Q", "memory");
    }
    func_0048a2b0(arg1, work);
    {
        u32 mask;

        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vsub.xyz $vf10xyz, $vf0xyz, $vf10xyz \n"
            :
            : "r"(work)
            : "$vf10", "memory");
        flags = *(u32 *)(arg0 + 0x68);
        mask = flags & 0x10;
        if (mask != 0) {
            __asm__ volatile(
                "mtc1 $zero, $f0 \n"
                "nop \n"
                "mfc1 $2, $f0 \n"
                "nop \n"
                "qmtc2 $2, $vf2 \n"
                "vaddx.y $vf10y, $vf0y, $vf2x \n"
                :
                :
                : "$2", "$f0", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile(
            "vmul.xyz $vf2xyz, $vf10xyz, $vf10xyz \n"
            "vmulax.w $ACCw, $vf0w, $vf2x \n"
            "vmadday.w $ACCw, $vf0w, $vf2y \n"
            "vmaddz.w $vf2w, $vf0w, $vf2z \n"
            "vrsqrt $Q, $vf0w, $vf2w \n"
            "vwaitq \n"
            "vmulq.xyz $vf10xyz, $vf10xyz, $Q \n"
            :
            :
            : "$vf10", "$vf2", "ACC", "Q", "memory");
        __asm__ volatile(
            "lqc2 $vf11, 0(%0) \n"
            "vmul.xyzw $vf10xyzw, $vf10xyzw, $vf11xyzw \n"
            :
            : "r"(values)
            : "$vf10", "$vf11", "memory");
        if (mask != 0) {
            __asm__ volatile(
                "lw $2, 68(%0) \n"
                "nop \n"
                "qmtc2 $2, $vf2 \n"
                "vaddx.y $vf10y, $vf0y, $vf2x \n"
                :
                : "r"(arg0)
                : "$2", "$vf2", "$vf10", "memory");
        }
    }
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(arg2)
        : "$vf10", "memory");
    /* measured: closes O1 probe for initial flag and aggregate register colours. */
    #pragma optimization_level 2
}
/* measured: opening optimization_level 1 for the parked 00486970 body. */
#pragma optimization_level 1
// FUN_00486970
u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2)
{
    u32 flags;
    u_long128 sp40;
    u_long128 value;
    f32 var_f20;

    if (((flags = *(s32 *)(arg0 + 0x68)) & 0x60) == 0) {
        value = *(u_long128 *)(arg0 + 0x50);
        *arg2 = value;
        return value;
    }
    func_0048a2b0(arg1, (u8 *)&sp40);
    if (*(s32 *)(arg0 + 0x68) & 0x40) {
        var_f20 = 0.0f;
    } else {
        var_f20 = -func_0044b920(-*(f32 *)((u8 *)&sp40 + 4));
    }
    func_004bcf20(var_f20,
                  func_0044b950(*(f32 *)((u8 *)&sp40 + 0),
                                *(f32 *)((u8 *)&sp40 + 8)),
                  0.0f);
    if (*(s32 *)(arg0 + 0x68) & 0x40) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf11, $vf10\n"
            "lqc2 $vf10, 0x50(%0)\n"
            ".set reorder\n"
            :
            : "r"(arg0)
            : "$vf10", "$vf11", "memory");
        func_004bce50();
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(arg2) : "$vf10", "memory");
}
/* measured: closes optimization_level 1 for the parked 00486970 body. */
#pragma optimization_level 2
// FUN_00489E00
void func_00489e00(u8 *arg0)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg0 + 0x4C);
    if (temp_4 != 0) {
        func_00492d10(temp_4);
        func_00487c30(arg0, 1.0f);
    }
}
// FUN_00489E80
void func_00489e80(u8 *arg0)
{
    s32 temp_4;

    temp_4 = *(s32 *)(arg0 + 0x4C);
    if (temp_4 != 0) {
        func_00492d10(temp_4);
        func_00487c30(arg0, 1.0f);
    }
    func_00487fb0(arg0, 1.0f);
}
// FUN_00489EE0
void func_00489ee0(u8 *arg0)
{
    func_00492dd0(*(u8 **)(arg0 + 0x4C));
}
// FUN_00489F10
void func_00489f10(u8 *arg0)
{
    func_00492e10(*(u8 **)(arg0 + 0x4C));
}
// FUN_0048A980
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048a980);
// FUN_0048ABD0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048abd0);
// FUN_0048AFF0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048aff0);
// FUN_0048B220
void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3)
{
    s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
    void func_0048a460(void);
    u_long128 sp50;
    s32 size;

    size = *(s32 *)(arg1 + 0xB8);
    *(s32 *)(arg0 + 0x14) =
        func_0048abd0(arg1 + 0x2C, arg1 + 0x50, arg2, size);
    size = *(s32 *)(arg1 + 0xB8);
    *(f32 *)(arg0 + 0x18) =
        func_0048aff0(arg1 + 0x60, arg2, size);
    if (*(u8 *)(arg1 + 0x9C) != 2) {
        size = *(s32 *)(arg1 + 0xB8);
        *(f32 *)(arg0 + 0x1C) =
            func_0048aff0(arg1 + 0x8C, arg2, size);
        return;
    }
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
    func_0048a460();
    __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg3) : "$vf10", "memory");
    func_0048a460();
    __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp50) : "$vf10", "memory");
    if ((*(f32 *)((u8 *)&sp50 + 0) != 0.0f) ||
        (*(f32 *)((u8 *)&sp50 + 4) != 0.0f)) {
        *(f32 *)(arg0 + 0x1C) =
            func_0044b950(*(f32 *)((u8 *)&sp50 + 4),
                          *(f32 *)((u8 *)&sp50 + 0));
        return;
    }
    *(f32 *)(arg0 + 0x1C) = 0.0f;
}
// FUN_0048B340 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b340);
// FUN_0048B9E0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b9e0);
// FUN_0048C440
void func_0048c440(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048c440_check;
loop_0048c440_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048c440_check:
    if (var_7 < 3U) {
        goto loop_0048c440_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
}
// FUN_0048C4E0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048c4e0);
// FUN_0048CD60
void func_0048cd60(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048cd60_check;
loop_0048cd60_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048cd60_check:
    if (var_7 < 3U) {
        goto loop_0048cd60_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
}
// FUN_0048CDF0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048cdf0);
// FUN_0048D820
void func_0048d820(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048d820_check;
loop_0048d820_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048d820_check:
    if (var_7 < 3U) {
        goto loop_0048d820_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
    *(f32 *)(temp_6 + 0xF0) = *(f32 *)(temp_5 + 0xF0) * fparg0;
}
// FUN_0048D8C0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048d8c0);
// FUN_0048E270
void func_0048e270(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048e270_check;
loop_0048e270_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048e270_check:
    if (var_7 < 3U) {
        goto loop_0048e270_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}
// FUN_0048E2F0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048e2f0);
// FUN_0048EBC0
void func_0048ebc0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048ebc0_check;
loop_0048ebc0_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048ebc0_check:
    if (var_7 < 3U) {
        goto loop_0048ebc0_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}
// FUN_0048EC50
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048ec50);
// FUN_0048F560
void func_0048f560(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048f560_check;
loop_0048f560_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048f560_check:
    if (var_7 < 3U) {
        goto loop_0048f560_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}
// FUN_0048F5F0
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048f5f0);
