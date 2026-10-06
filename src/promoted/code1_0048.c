#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct EffRandState EffRandState;
extern u32 effMiscRand(EffRandState *state);
extern f32 effMiscRandFloat(EffRandState *state);

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
extern void func_004861f0(u8 *arg0, f32 *arg1);
extern void effMiscQuatMultiplyVU(void);
extern void func_0048a2b0(u8 *arg0, u8 *arg1);
extern f32 func_0044b920(f32 arg0);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern f32 fabsf(f32 value);
extern void func_004bcf20(f32 arg0, f32 arg1, f32 arg2);
extern void func_004bceb0(void);
extern void func_00486400(u8 *arg0, f32 arg1);
extern void func_00484790(u8 *arg0);
extern void func_004847e0(u8 *arg0);
extern u8 *func_00482230(s32 *arg0);
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
s32 func_00481460(s32 arg0);
extern void func_00460ac0(s32 arg0, void *arg1);
extern void func_003c42b0(void *arg0, s32 arg1);
extern s32 func_003c2150(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 *RpGeometryLock(u8 *arg0, s32 arg1);
extern u8 *func_003c22f0(u8 *arg0);
extern u8 *func_00483a00(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00481390(s32 arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0046d730(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void func_00485630(u8 *arg0);
extern void func_00485870(u8 *arg0);
extern void func_00492d10(void *object);
extern void func_00487c30(u8 *arg0, f32 arg1);
extern void func_00487fb0(u8 *arg0, f32 arg1);
void func_00483810();
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
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


extern void (*jtbl_008873EC[])(void *);
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
    extern void memcpy(void *dst, void *src, u32 size);
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
    memcpy(temp_17_2, arg0, *arg0);
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
u8 *func_00484010(u8 *arg0)
{
    u8 *temp_23;
    u8 *temp_22;
    s32 var_20;
    u8 *temp_19;
    u8 *temp_18;
    u8 *var_17;
    u8 *temp_6;
    s32 var_16;

    temp_23 = func_00483a00(
        *(u16 *)(arg0 + 0x48),
        *(u16 *)(arg0 + 8),
        *(u16 *)(arg0 + 0xA),
        *(s32 *)(arg0 + 4));
    temp_22 = *(u8 **)(temp_23 + 0x54);
    temp_19 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 0x18);
    temp_18 = *(u8 **)(*(u8 **)(temp_23 + 0x10) + 0x18);

    var_16 = 0;
    while (var_16 < *(s16 *)(arg0 + 0x48)) {
        s32 temp_3;
        u8 *p;

        temp_3 = var_16 * 4;
        p = *(u8 **)(*(u8 **)(arg0 + 0x54) + temp_3);
        if (*(s32 *)p != 0) {
            func_003c42b0(*(void **)(temp_22 + temp_3), *(s32 *)p);
        }
        var_16 += 1;
    }

    RpGeometryLock(temp_19, 1);

    {
        u8 *src;
        u8 *dst;
        s32 var_3;

        src = *(u8 **)(temp_19 + 0x2C);
        dst = *(u8 **)(temp_18 + 0x2C);
        var_17 = dst;
        for (var_3 = 0; var_3 < *(s16 *)(arg0 + 0x4C); var_3++) {
            *(u16 *)dst = *(u16 *)src;
            *(u16 *)(dst + 2) = *(u16 *)(src + 2);
            *(u16 *)(dst + 4) = *(u16 *)(src + 4);
            src += 8;
            dst += 8;
        }
    }

    var_20 = 0;
    while (var_20 < *(s16 *)(arg0 + 0x48)) {
        var_16 = 0;
        temp_6 = (u8 *)(temp_22 + var_20 * 4);
        while (var_16 < *(s16 *)(arg0 + 0xA)) {
            func_003c2150(temp_18, var_17, *(s32 *)temp_6);
            var_17 += 8;
            var_16 += 1;
        }
        var_20 += 1;
    }

    func_003c22f0(temp_19);
    return temp_23;
}
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
void *func_00484530(void *input)
{
    return NULL;
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
    memset(temp_2, 0, 0x2C);
    *(s32 *)(temp_2 + 0) = 0xD2;
    *(u16 *)(temp_2 + 4) = temp_18;
    *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0xC);
    *(u16 *)(temp_2 + 0x1C) = *(u16 *)(arg0 + 0x1C);
    if (*(u16 *)(temp_2 + 4) >= 0x21U) {
        func_0046d730(D_00713470, 0x2DD);
    }
    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(temp_2 + 4) << 6)) == NULL) {
        func_0046d730(D_00713470, 0x2DE);
    }
    *(void **)(temp_2 + 8) =
        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(temp_2 + 4) << 6)))(
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
    memset(temp_2, 0, 0x2C);
    *(s32 *)(temp_2 + 0) = 0xD2;
    *(u16 *)(temp_2 + 4) = temp_18;
    *(u16 *)(temp_2 + 0xC) = *(u16 *)(arg0 + 0xC);
    *(u16 *)(temp_2 + 0x1C) = *(u16 *)(arg0 + 0x1C);
    if (*(EffectInstanceConstructor *)(D_00713494 + (*(u16 *)(temp_2 + 4) << 6)) == NULL) {
        func_0046d730(D_00713470, 0x321);
    }
    *(void **)(temp_2 + 8) =
        (*(EffectInstanceConstructor *)(D_00713494 + (*(u16 *)(temp_2 + 4) << 6)))(
            *(void **)(arg0 + 8));
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
void func_00484a90(u8 *arg0, f32 scale) {
    void (*fn)(s32, f32) = *(void (**)(s32, f32))(D_007134A8 + (*(u16 *)(arg0 + 4) << 6));

    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), scale);
    }
}

// FUN_00484AE0
void func_00484ae0(u8 *arg0, s32 arg1) {
    void (*fn)(s32, s32) = *(void (**)(s32, s32))(D_007134B0 + (*(u16 *)(arg0 + 4) << 6));
    if (fn != NULL) {
        fn(*(s32 *)(arg0 + 8), arg1);
    }
}

typedef struct Code48InitialState {
    f32 vector00[4];
    f32 vector10[4];
    u_long128 quad20;
    u8 unknown30[0x10];
    f32 vector40[4];
    f32 vector50[4];
    f32 scalar60;
    u32 word64;
    u32 word68;
    u32 unknown6c;
    u32 unknown70;
    f32 scalar74;
    u32 unknown78[2];
} Code48InitialState;
// FUN_00484B30
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma opt_propagation off
u_long128 func_00484b30(u8 *arg0)
{
    Code48InitialState *state = (Code48InitialState *)(void *)arg0;
    const u_long128 *quadSource;
    u_long128 quad;

    memset(state, 0, sizeof(*state));
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(state) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(state) : "memory");
    __asm__ volatile("sqc2 vf0, 64(%0)" : : "r"(state) : "memory");
    state->vector40[1] = 5.0f;
    __asm__ volatile("sqc2 vf0, 80(%0)" : : "r"(state) : "memory");
    quadSource = (const u_long128 *)(const void *)D_00713CE0;
    quad = *quadSource;
    state->quad20 = quad;
    state->scalar60 = 1.0f;
    state->scalar74 = 1.0f;
    state->word64 = 0xFFFFFFFF;
    state->word68 = 0x80;
    return quad;
}
#pragma pop
/* The input and allocated result have separate construction lifetimes.
 * Both initial vectors use the first input quad, as in retail. */
// FUN_00484BB0
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
u8 *func_00484bb0(u8 *arg0)
{
    extern void func_004861f0(u8 *arg0, f32 *arg1);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    extern void func_00486400(u8 *arg0, f32 arg1);
    extern void func_004865c0(u8 *arg0, s32 arg1);
    extern char *strcpy(char *destination, const char *source);
    s32 func_004867e0(u8 *arg0, u8 *arg1);
    u8 *func_00486780(u8 *arg0, s32 arg1);
    u_long128 vf0quad;
    void *(**alloc)(u32, u32);
    u8 *node;
    u8 *nodeClone;
    u8 *prim;
    u16 kind;
    u8 *found;
    s32 idx;
    u8 *csrc;
    s32 count;
    u8 *base;
    u8 *cur;
    s32 i;
    u8 *slot;
    u8 *target;
    u8 *addr20;
    u8 *addr24;
    s32 idx94;
    u8 *var2;
    s32 tmp;
    u8 *const input = arg0;

    func_0044ea90(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    {
        u8 *const clone = (u8 *)alloc[0](0x90, 0x40000);
        if (clone == NULL) {
            func_0046d730(D_00713470, 0x547);
        }
        memset(clone, 0, 0x90);
        *(s32 *)(clone + 0x80) = 0;
        *(s32 *)(clone + 0x84) = 0;
        func_00484b30(clone);
        /* Retail initializes both vectors from the first input quad. */
        *(u_long128 *)clone = *(u_long128 *)input;
        *(u_long128 *)(clone + 0x10) = *(u_long128 *)input;
        *(f32 *)(clone + 0x74) = *(f32 *)(input + 0x74);
        *(s32 *)(clone + 0x68) = *(s32 *)(input + 0x68);
        if (*(u8 **)(input + 0x8C) != NULL) {
            u8 *linkedSource;
            for (node = *(u8 **)(input + 0x8C); node != NULL; node = *(u8 **)(node + 0xAC)) {
                func_0044ea90(D_00713470, 0x559);
                nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
                if (nodeClone == NULL) {
                    func_0046d730(D_00713470, 0x55A);
                }
                memset(nodeClone, 0, 0xC0);
                memset(nodeClone, 0, 0x90);
                *(s32 *)(nodeClone + 0x84) = 1;
                *(u8 *)(nodeClone + 0x88) = 8;
                *(u8 *)(nodeClone + 0x89) = 0;
                *(u8 *)(nodeClone + 0x8A) = 0;
                func_00484b30(nodeClone);
                if ((*(s32 *)(node + 0x98) & 1) == 0) {
                    linkedSource = *(u8 **)(node + 0x90);
                    if (*(u32 *)linkedSource > 0xD2) {
                        func_0046d730(D_00713470, 0x2D7);
                    }
                    kind = *(u16 *)(linkedSource + 4);
                    func_0044ea90(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        func_0046d730(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(linkedSource + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(linkedSource + 0x1C);
                    if (*(u16 *)(prim + 4) >= 0x21U) {
                        func_0046d730(D_00713470, 0x2DD);
                    }
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == NULL) {
                        func_0046d730(D_00713470, 0x2DE);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)))(linkedSource);
                    *(u8 **)(nodeClone + 0x90) = prim;
                } else {
                    found = func_00486740(input, *(s32 *)(node + 0x90));
                    idx = func_004867e0(input, found);
                    csrc = *(u8 **)(func_00486780(clone, idx) + 0x90);
                    if (*(u32 *)csrc > 0xD2) {
                        func_0046d730(D_00713470, 0x318);
                    }
                    kind = *(u16 *)(csrc + 4);
                    func_0044ea90(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        func_0046d730(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(csrc + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(csrc + 0x1C);
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == NULL) {
                        func_0046d730(D_00713470, 0x321);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(void **)(csrc + 8));
                    *(u8 **)(nodeClone + 0x90) = prim;
                }
                func_00486710(nodeClone, node);
                strcpy((char *)nodeClone + 0x9C, (const char *)node + 0x9C);
                *(s32 *)(nodeClone + 0xAC) = 0;
                if (*(u8 **)(clone + 0x88) != NULL) {
                    *(u8 **)(*(u8 **)(clone + 0x88) + 0xAC) = nodeClone;
                    *(u8 **)(nodeClone + 0xB0) = *(u8 **)(clone + 0x88);
                } else {
                    *(u8 **)(clone + 0x8C) = nodeClone;
                    *(u8 **)(nodeClone + 0xB0) = NULL;
                }
                *(u8 **)(clone + 0x88) = nodeClone;
                *(s32 *)(clone + 0x80) += 1;
            }
        } else {
            u8 *indexedSource;
            count = *(s32 *)(input + 0x80);
            base = input + *(s32 *)(input + 0x88);
            cur = base;
            i = 0;
            goto indexed_check;
    indexed_body:
            func_0044ea90(D_00713470, 0x559);
            nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
            if (nodeClone == NULL) {
                func_0046d730(D_00713470, 0x55A);
            }
            memset(nodeClone, 0, 0xC0);
            memset(nodeClone, 0, 0x90);
            *(s32 *)(nodeClone + 0x84) = 1;
            *(u8 *)(nodeClone + 0x88) = 8;
            *(u8 *)(nodeClone + 0x89) = 0;
            *(u8 *)(nodeClone + 0x8A) = 0;
            func_00484b30(nodeClone);
            tmp = *(s32 *)(cur + 0x98);
            if ((tmp & 1) == 0) {
                indexedSource = input + *(s32 *)(cur + 0x90);
                if ((tmp & 2) != 0) {
                    addr24 = indexedSource + 0x24;
                    if (*(s32 *)addr24 != 0) {
                        func_0046d730(D_00713470, 0x5BB);
                    }
                    addr20 = indexedSource + 0x20;
                    if (*(s32 *)addr20 != 0) {
                        func_0046d730(D_00713470, 0x5BC);
                    }
                    idx94 = *(s32 *)(cur + 0x94);
                    slot = base + idx94 * 0xC0;
                    target = input + *(s32 *)(slot + 0x90);
                    if (*(s32 *)(target + 0x24) == 0) {
                        func_0046d730(D_00713470, 0x5BE);
                    }
                    *(s32 *)addr24 = *(s32 *)(target + 0x24);
                    if (*(s32 *)(target + 0x28) != 0) {
                        var2 = *(u8 **)(target + 0x20);
                    } else if (*(s32 *)(target + 0x20) != 0) {
                        var2 = target + *(s32 *)(target + 0x20);
                    } else {
                        var2 = NULL;
                    }
                    *(u32 *)addr20 = (u32)var2 - (u32)indexedSource;
                    if (*(u32 *)indexedSource > 0xD2) {
                        func_0046d730(D_00713470, 0x2D7);
                    }
                    kind = *(u16 *)(indexedSource + 4);
                    func_0044ea90(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        func_0046d730(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(indexedSource + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(indexedSource + 0x1C);
                    if (*(u16 *)(prim + 4) >= 0x21U) {
                        func_0046d730(D_00713470, 0x2DD);
                    }
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == NULL) {
                        func_0046d730(D_00713470, 0x2DE);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)))(indexedSource);
                    *(u8 **)(nodeClone + 0x90) = prim;
                    *(s32 *)addr24 = 0;
                    *(s32 *)addr20 = 0;
                } else {
                    if (*(u32 *)indexedSource > 0xD2) {
                        func_0046d730(D_00713470, 0x2D7);
                    }
                    kind = *(u16 *)(indexedSource + 4);
                    func_0044ea90(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        func_0046d730(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(indexedSource + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(indexedSource + 0x1C);
                    if (*(u16 *)(prim + 4) >= 0x21U) {
                        func_0046d730(D_00713470, 0x2DD);
                    }
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == NULL) {
                        func_0046d730(D_00713470, 0x2DE);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)))(indexedSource);
                    *(u8 **)(nodeClone + 0x90) = prim;
                }
            } else {
                csrc = *(u8 **)(func_00486780(clone, *(s32 *)(cur + 0x90)) + 0x90);
                if (*(u32 *)csrc > 0xD2) {
                    func_0046d730(D_00713470, 0x318);
                }
                kind = *(u16 *)(csrc + 4);
                func_0044ea90(D_00713470, 0x21);
                prim = (u8 *)alloc[0](0x2C, 0x40000);
                if (prim == NULL) {
                    func_0046d730(D_00713470, 0x22);
                }
                memset(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                *(u16 *)(prim + 4) = kind;
                *(u16 *)(prim + 0xC) = *(u16 *)(csrc + 0xC);
                *(u16 *)(prim + 0x1C) = *(u16 *)(csrc + 0x1C);
                if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == NULL) {
                    func_0046d730(D_00713470, 0x321);
                }
                *(void **)(prim + 8) =
                    (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(void **)(csrc + 8));
                *(u8 **)(nodeClone + 0x90) = prim;
            }
            func_00486710(nodeClone, cur);
            strcpy((char *)nodeClone + 0x9C, (const char *)cur + 0x9C);
            *(s32 *)(nodeClone + 0xAC) = 0;
            if (*(u8 **)(clone + 0x88) != NULL) {
                *(u8 **)(*(u8 **)(clone + 0x88) + 0xAC) = nodeClone;
                *(u8 **)(nodeClone + 0xB0) = *(u8 **)(clone + 0x88);
            } else {
                *(u8 **)(clone + 0x8C) = nodeClone;
                *(u8 **)(nodeClone + 0xB0) = NULL;
            }
            *(u8 **)(clone + 0x88) = nodeClone;
            *(s32 *)(clone + 0x80) += 1;
            cur += 0xC0;
            i += 1;
    indexed_check:
            if (i < count) {
                goto indexed_body;
            }
        }
        /* VU0's fixed vector is (0, 0, 0, 1). */
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(&vf0quad) : "memory");
        func_004861f0(clone, (f32 *)&vf0quad);
        func_00486330(clone, (u8 *)&vf0quad);
        func_00486400(clone, 1.0f);
        func_004865c0(clone, -1);
        return clone;
    }
}
#pragma pop
/* Guarded native proof, 2026-09-29: 564/576 bytes; three restore-register
 * words differ. The restored quadword uses v1 where retail uses v0.
 * Separate save/restore pointers and opt_propagation off preserve the
 * retail 0x90 frame and address materialization. No computation asm is
 * used to force the remaining register choice. Production retains ASM. */
// FUN_00485630 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
void func_00485630(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    /* 00484b30 initializes the 0x80-byte state; 00484bb0 allocates a
     * 0x90-byte root. The union keeps field and quadword transfers in the
     * same object, including all four components of the saved rotation. */
    typedef union SceneStateStorage {
        Code48InitialState fields;
        u_long128 quad[8];
    } SceneStateStorage;
    typedef struct SceneRoot {
        SceneStateStorage state;
        s32 childCount;
        u32 frame; /* Wrapping storage, read as signed for selection. */
        u8 *lastChild;
        u8 *firstChild;
    } SceneRoot;
    typedef char SceneRootExtent[sizeof(SceneRoot) == 0x90 ? 1 : -1];
    SceneRoot *root;
    /* The saved parent rotation survives both propagation calls. */
    struct {
        u_long128 savedRotation;
        u_long128 rotation;
        u_long128 position;
        u_long128 origin;
    } work;
    f32 scale;
    f32 five;
    u8 *child;
    s32 count;
    u8 *primitive;
    void (*positionCallback)(s32, void *);
    void (*rotationCallback)(s32, void *);
    s32 childFlags;

    root = (SceneRoot *)(void *)arg0;
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0), "m"(root->state.quad[4]) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0), "m"(root->state.quad[0]) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.origin) : "r"(&work.origin) : "memory");
    if ((root->state.fields.word68 & 0x60) != 0) {
        u_long128 *save_slot;
        u_long128 *restore_slot;
        save_slot = &work.savedRotation;
        *save_slot = root->state.quad[5];
        func_00486970(arg0, (u8 *)&work.origin, &work.rotation);
        func_00486330(arg0, (u8 *)&work.rotation);
        restore_slot = &work.savedRotation;
        root->state.quad[5] = *restore_slot;
    }
    count = (s32)root->frame;
    scale = root->state.fields.scalar60 * root->state.fields.scalar74;
    child = root->firstChild;
    five = 5.0f;
    for (; child != NULL; child = *(u8 **)(child + 0xAC)) {
        if (count < *(s32 *)(child + 0x80)) {
            continue;
        }
        if ((*(s32 *)(child + 0x84) & 2) != 0) {
            continue;
        }
        if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
            func_00486840(child, (u8 *)&work.origin, &work.position);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&work.origin), "m"(work.origin) : "$vf10", "memory");
            childFlags = *(s32 *)(child + 0x68);
            if ((childFlags & 4) != 0) {
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vaddx.y $vf10, $vf0, $vf2x \n"
                    :
                    : "r"(five)
                    : "$vf2", "$vf10", "memory");
            }
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&work.position), "m"(work.position) : "$vf11", "memory");
            if ((childFlags & 0x80) != 0) {
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                    :
                    : "r"(scale)
                    : "$vf2", "$vf11", "memory");
            }
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.position) : "r"(&work.position) : "memory");
            primitive = *(u8 **)(child + 0x90);
            positionCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x20);
            if (positionCallback != NULL) {
                positionCallback(*(s32 *)(primitive + 8), &work.position);
            }
        }
        if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
            func_00486970(child, (u8 *)&work.origin, &work.rotation);
            primitive = *(u8 **)(child + 0x90);
            rotationCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x24);
            if (rotationCallback != NULL) {
                rotationCallback(*(s32 *)(primitive + 8), &work.rotation);
            }
        }
        primitive = *(u8 **)(child + 0x90);
        (*(void (**)(s32))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x08))(*(s32 *)(primitive + 8));
    }
    root->state.fields.word68 |= 0x80000000;
    /* Retail ADDIU wraps the word even when its signed view reaches INT_MAX. */
    root->frame += 1U;
}

#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485630);
#endif
/* Guarded native proof, 2026-09-29: 616/624 bytes; three restore-register
 * words differ, as in func_00485630. The pointer parameter, named mask,
 * and separate save/restore pointers preserve the retail 0xb0 frame.
 * The residual is not an exact match; production retains ASM. */
// FUN_00485870 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
void func_00485870(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    /* 00484b30 initializes the 0x80-byte state; 00484bb0 allocates a
     * 0x90-byte root. The union keeps field and quadword transfers in the
     * same object, including all four components of the saved rotation. */
    typedef union SceneStateStorage {
        Code48InitialState fields;
        u_long128 quad[8];
    } SceneStateStorage;
    typedef struct SceneRoot {
        SceneStateStorage state;
        s32 childCount;
        u32 frame; /* Wrapping storage, read as signed for selection. */
        u8 *lastChild;
        u8 *firstChild;
    } SceneRoot;
    typedef char SceneRootExtent[sizeof(SceneRoot) == 0x90 ? 1 : -1];
    SceneRoot *root;
    /* The saved parent rotation survives both propagation calls. */
    struct {
        u_long128 savedRotation;
        u_long128 rotation;
        u_long128 position;
        u_long128 origin;
    } work;
    f32 scale;
    f32 five;
    u8 *child;
    s32 flags;
    s32 count_minus_1;
    u8 *primitive;
    void (*positionCallback)(s32, void *);
    void (*rotationCallback)(s32, void *);
    s32 childFlags;
    u32 mask;

    root = (SceneRoot *)(void *)arg0;
    if ((s32)root->frame <= 0) {
        return;
    }
    flags = root->state.fields.word68;
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0), "m"(root->state.quad[4]) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0), "m"(root->state.quad[0]) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.origin) : "r"(&work.origin) : "memory");
    if ((flags & 0x60) != 0) {
        if ((flags & 0x80000000) == 0) {
            u_long128 *save_slot;
            u_long128 *restore_slot;
            save_slot = &work.savedRotation;
            *save_slot = root->state.quad[5];
            func_00486970(arg0, (u8 *)&work.origin, &work.rotation);
            func_00486330(arg0, (u8 *)&work.rotation);
            restore_slot = &work.savedRotation;
            root->state.quad[5] = *restore_slot;
        }
    }
    /* Reload after propagation, then subtract in the word's wrapping domain. */
    count_minus_1 = (s32)(root->frame - 1U);
    scale = root->state.fields.scalar60 * root->state.fields.scalar74;
    child = root->firstChild;
    mask = 0x80000000;
    five = 5.0f;
    for (; child != NULL; child = *(u8 **)(child + 0xAC)) {
        if (count_minus_1 < *(s32 *)(child + 0x80)) {
            continue;
        }
        if ((*(s32 *)(child + 0x84) & 2) != 0) {
            continue;
        }
        if ((flags & mask) == 0) {
            if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
                func_00486840(child, (u8 *)&work.origin, &work.position);
                __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&work.origin), "m"(work.origin) : "$vf10", "memory");
                childFlags = *(s32 *)(child + 0x68);
                if ((childFlags & 4) != 0) {
                    __asm__ volatile(
                        "qmtc2.ni %0, $vf2 \n"
                        "vaddx.y $vf10, $vf0, $vf2x \n"
                        :
                        : "r"(five)
                        : "$vf2", "$vf10", "memory");
                }
                __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&work.position), "m"(work.position) : "$vf11", "memory");
                if ((childFlags & 0x80) != 0) {
                    __asm__ volatile(
                        "qmtc2.ni %0, $vf2 \n"
                        "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                        :
                        : "r"(scale)
                        : "$vf2", "$vf11", "memory");
                }
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.position) : "r"(&work.position) : "memory");
                primitive = *(u8 **)(child + 0x90);
                positionCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x20);
                if (positionCallback != NULL) {
                    positionCallback(*(s32 *)(primitive + 8), &work.position);
                }
            }
            if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
                func_00486970(child, (u8 *)&work.origin, &work.rotation);
                primitive = *(u8 **)(child + 0x90);
                rotationCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x24);
                if (rotationCallback != NULL) {
                    rotationCallback(*(s32 *)(primitive + 8), &work.rotation);
                }
            }
        }
        primitive = *(u8 **)(child + 0x90);
        (*(void (**)(s32))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x0C))(*(s32 *)(primitive + 8));
    }
    root->state.fields.word68 &= 0x7fffffffU;
}

#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485870);
#endif
// FUN_00485AE0
void func_00485ae0(s32 arg0)
{
    func_00485630((u8 *)arg0);
    func_00485870((u8 *)arg0);
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
extern void func_00486330(u8 *arg0, u8 *arg1);
extern void func_004865c0(u8 *arg0, s32 arg1);
/* measured: object 852B/window 864B, nd 0. The allocator table address lives in
   a saved register (`alloc = jtbl_008873E8` after the first assert-log call),
   which needs opt_propagation off so the first call does not fold the constant
   back in; `> 0xD2` gives retail's `sltiu $at` form where `>= 0xD3` colours
   into $v0; the 16-byte stack quadword is zeroed with the tree's `sqc2 vf0`
   idiom before the two calls that read it. */
// FUN_00485C80
/* measured: opt_propagation off keeps `alloc` live in $s1 across all three
   allocations instead of re-materialising the table address at the first use. */
#pragma opt_propagation off
u8 *func_00485c80(u8 *arg0)
{
    u_long128 sp80;
    u8 *clone;
    u8 *node;
    u8 *nodeClone;
    u8 *src;
    u8 *prim;
    u16 kind;
    void *(**alloc)(u32, u32);

    if (*(u8 **)(arg0 + 0x8C) == NULL) {
        func_0046d730(D_00713470, 0x6B7);
    }
    func_0044ea90(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    clone = (u8 *)alloc[0](0x90, 0x40000);
    if (clone == NULL) {
        func_0046d730(D_00713470, 0x547);
    }
    memset(clone, 0, 0x90);
    *(s32 *)(clone + 0x80) = 0;
    *(s32 *)(clone + 0x84) = 0;
    func_00484b30(clone);
    *(u_long128 *)clone = *(u_long128 *)arg0;
    *(u_long128 *)(clone + 0x10) = *(u_long128 *)(arg0 + 0x10);
    *(f32 *)(clone + 0x74) = *(f32 *)(arg0 + 0x74);
    *(s32 *)(clone + 0x68) = *(s32 *)(arg0 + 0x68);
    for (node = *(u8 **)(arg0 + 0x8C); node != NULL; node = *(u8 **)(node + 0xAC)) {
        func_0044ea90(D_00713470, 0x559);
        nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
        if (nodeClone == NULL) {
            func_0046d730(D_00713470, 0x55A);
        }
        memset(nodeClone, 0, 0xC0);
        memset(nodeClone, 0, 0x90);
        *(s32 *)(nodeClone + 0x84) = 1;
        *(u8 *)(nodeClone + 0x88) = 8;
        *(u8 *)(nodeClone + 0x89) = 0;
        *(u8 *)(nodeClone + 0x8A) = 0;
        func_00484b30(nodeClone);
        src = *(u8 **)(node + 0x90);
        if (*(u32 *)src > 0xD2) {
            func_0046d730(D_00713470, 0x318);
        }
        kind = *(u16 *)(src + 4);
        func_0044ea90(D_00713470, 0x21);
        prim = (u8 *)alloc[0](0x2C, 0x40000);
        if (prim == NULL) {
            func_0046d730(D_00713470, 0x22);
        }
        memset(prim, 0, 0x2C);
        *(s32 *)prim = 0xD2;
        *(u16 *)(prim + 4) = kind;
        *(u16 *)(prim + 0xC) = *(u16 *)(src + 0xC);
        *(u16 *)(prim + 0x1C) = *(u16 *)(src + 0x1C);
        if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == NULL) {
            func_0046d730(D_00713470, 0x321);
        }
        *(void **)(prim + 8) =
            (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(void **)(src + 8));
        *(u8 **)(nodeClone + 0x90) = prim;
        func_00486710(nodeClone, node);
        *(s32 *)(nodeClone + 0xAC) = 0;
        if (*(u8 **)(clone + 0x88) != NULL) {
            *(u8 **)(*(u8 **)(clone + 0x88) + 0xAC) = nodeClone;
            *(u8 **)(nodeClone + 0xB0) = *(u8 **)(clone + 0x88);
        } else {
            *(u8 **)(clone + 0x8C) = nodeClone;
            *(u8 **)(nodeClone + 0xB0) = NULL;
        }
        *(u8 **)(clone + 0x88) = nodeClone;
        *(s32 *)(clone + 0x80) += 1;
    }
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(&sp80) : "memory");
    func_004861f0(clone, (f32 *)&sp80);
    func_00486330(clone, (u8 *)&sp80);
    func_00486400(clone, 1.0f);
    func_004865c0(clone, -1);
    return clone;
}
/* measured: closes the propagation bracket; the file default is on. */
#pragma opt_propagation on
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
void func_004861f0(u8 *arg0, f32 *arg1)
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
    effMiscQuatMultiplyVU();
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

/* Packed-word to VU bridge. $2 is quadword scratch; C owns addresses and storage. */
static inline void model_normalize_packed_color(const u32 *source, f32 scale)
{
    u32 scaleBits;
    __asm__ volatile(
        "lw $2, 0(%1)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 %0, %2\n"
        "nop\n"
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : "=&r"(scaleBits)
        : "r"(source), "f"(scale), "m"(*source)
        : "$2", "$vf2", "$vf10", "memory");
}

// FUN_004865C0
/* measured: 276B/288B, instruction-exact after relocation normalization; 12B zero tail.
 * Only the packed-word/VU bridges are assembly; locals and traversal remain C. */
void func_004865c0(u8 *arg0, s32 arg1)
{
    u32 baseColor;
    u32 childColor;
    u32 packedColor;
    f32 parent[4] __attribute__((aligned(16)));
    f32 scale;
    const u32 *source;
    u8 *node;
    u8 *data;
    void (*callback)(s32, u32);
    u32 color;
    u32 work;

    *(s32 *)(arg0 + 0x64) = arg1;
    baseColor = (u32)arg1;
    source = &baseColor;
    scale = fGpffff8044;
    model_normalize_packed_color(source, scale);
    __asm__ volatile("sqc2 $vf10, 0(%1)\n"
        : "=m"(parent) : "r"(parent) : "memory");

    node = *(u8 **)(arg0 + 0x8C);
    if (node != NULL) {
        while (node != NULL) {
            childColor = *(u32 *)(node + 0x64);
            source = &childColor;
            model_normalize_packed_color(source, scale);
            __asm__ volatile(
                "lqc2 $vf11, 0(%0)\n"
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                : : "r"(parent), "m"(parent)
                : "$vf10", "$vf11", "memory");
            work = 0x437F0000U; /* Binary32 255.0f, transferred to VF2.x. */
            __asm__ volatile(
                "qmtc2 %0, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2 %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, packedColor\n"
                : "+r"(work), "=m"(packedColor)
                : : "$vf2", "$vf10", "memory");
            color = packedColor;
            data = *(u8 **)(node + 0x90);
            callback = *(void (**)(s32, u32))(
                D_00713480 + *(u16 *)(data + 4) * 0x40 + 0x30);
            if (callback != NULL) {
                callback(*(s32 *)(data + 8), color);
            }
            node = *(u8 **)(node + 0xAC);
        }
    }
}
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
        effMiscQuatMultiplyVU();
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(arg2) : "$vf10", "memory");
}
/* measured: closes optimization_level 1 for the parked 00486970 body. */
#pragma optimization_level 2
// FUN_00489E00
void func_00489e00(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x4C);
    if (temp_4 != 0) {
        func_00492d10(temp_4);
        func_00487c30(arg0, 1.0f);
    }
}
// FUN_00489E80
void func_00489e80(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x4C);
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
/* Measured with b210 -O2: keeping the trace/diagonal stages and the scaled
   root as distinct lifetimes reproduces the scalar calculation. Propagation
   and common-subexpression elimination otherwise merge the identity
   constants and discard the root copy before register coalescing. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_0048A980
void func_0048a980(f32 *arg0)
{
    extern f32 sqrtf(f32);
    f32 q[4] __attribute__((aligned(16)));
    f32 zz, yy, xx;
    f32 one;
    f32 traceXY, traceXYZ, trace;

    yy = arg0[5];
    xx = arg0[0];
    zz = arg0[10];
    one = 1.0f;
    traceXY = xx + yy;
    traceXYZ = zz + traceXY;
    trace = one + traceXYZ;
    if (!(trace < one)) {
        f32 s = 2.0f * sqrtf(trace);
        q[3] = -(s / 4.0f);
        q[0] = (arg0[6] - arg0[9]) / s;
        q[1] = (arg0[8] - arg0[2]) / s;
        q[2] = (arg0[1] - arg0[4]) / s;
    } else {
        u32 selected = (((xx > yy) ? 1 : 0) ^ 1) & 0xFF;
        s32 i;
        s32 j, k;
        s32 axisCount;
        s32 next;
        s32 oi, oj, ok;
        u8 *ri, *rj, *rk;
        f32 dj, delta, radicand, sum;
        f32 root;
        f32 identity;
        f32 zero;

        if (!(zz <= *(f32 *)((u8 *)arg0 + selected * 16 + selected * 4))) {
            u8 third = 2;
            selected = third;
        }
        i = (u8)selected;
        next = i + 1;
        axisCount = 3;
        j = (u8)(next % axisCount);
        k = (u8)((j + 1) % axisCount);
        oj = j * 4;
        rj = (u8 *)arg0 + j * 16;
        dj = *(f32 *)(rj + oj);
        oi = i * 4;
        ri = (u8 *)arg0 + i * 16;
        delta = *(f32 *)(ri + oi) - dj;
        ok = k * 4;
        rk = (u8 *)arg0 + k * 16;
        radicand = delta - *(f32 *)(rk + ok);
        identity = 1.0f;
        sum = identity + radicand;
        root = sqrtf(sum);
        {
            f32 scaled = 2.0f * root;
            root = scaled;
        }
        zero = 0.0f;
        if (zero != root) {
            *(f32 *)((u8 *)q + oi) = root / 4.0f;
            *(f32 *)((u8 *)q + oj) = (*(f32 *)(ri + oj) + *(f32 *)(rj + oi)) / root;
            *(f32 *)((u8 *)q + ok) = (*(f32 *)(ri + ok) + *(f32 *)(rk + oi)) / root;
            q[3] = -((*(f32 *)(rj + ok) - *(f32 *)(rk + oj)) / root);
        } else {
            *(f32 *)((u8 *)q + oi) = identity;
            *(f32 *)((u8 *)q + oj) = zero;
            *(f32 *)((u8 *)q + ok) = zero;
            q[3] = zero;
        }
    }
    /* The quaternion is returned through the established VU0 vf10 ABI. */
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(q), "m"(q) : "$vf10");
}
#pragma pop
/* The fields consumed by the packed-color interpolator. */
typedef struct EffectPackedColorKeys {
    u8 mode;
    u8 pad01[3];
    u32 startColor;
    u32 endColor;
    u32 firstMiddleColor;
    f32 firstFraction;
    u32 secondMiddleColor;
    f32 secondFraction;
} EffectPackedColorKeys;

typedef struct EffectPackedOpacityKeys {
    u32 alpha;
    u32 field04;
    f32 fadeInFraction;
    f32 fadeOutFraction;
} EffectPackedOpacityKeys;

/* Fade against integer frame boundaries, retaining full opacity between ramps.
 * measured: the returning helper preserves native division-wait boundaries. */
static inline f32 effect_color_opacity(s32 frame, s32 duration, s32 fadeIn, s32 fadeOut, f32 fullOpacity)
{
    if (frame < fadeIn) {
        return (f32)frame / (f32)fadeIn;
    }
    if (fadeOut < frame) {
        return (f32)(duration - frame) / (f32)(duration - fadeOut);
    }
    return fullOpacity;
}

/* Interpolate the configured RGB keys in VU0 and apply the independent alpha
 * envelope. Packed RGBA returns as a sign-extended 32-bit word.
 * measured: native b210 -O2, 1044/1056 bytes, one exact resolved relocation. */
// FUN_0048ABD0
s32 func_0048abd0(u8 *colorData, u8 *opacityData, s32 frame, s32 duration) {
    const EffectPackedColorKeys *colors = (const EffectPackedColorKeys *)colorData;
    const EffectPackedOpacityKeys *opacityKeys = (const EffectPackedOpacityKeys *)opacityData;
    s32 secondColor;
    s32 firstColor;
    s32 packedRgb;
    s32 mixedColor;
    const s32 *colorSource;
    f32 normalization;
    f32 blend;
    f32 durationFloat;
    f32 scaledAlpha;
    f32 alphaFloat;
    f32 opacity;
    s32 baseAlpha;
    s32 alpha;
    s32 endColor;
    s32 startColor;
    u8 mode;
    f32 inverseBlend;
    f32 segmentSpan;
    s32 endFrame;
    s32 startFrame;

    if (duration == 0) {
        return (s32)((colors->startColor & 0xFFFFFFU) |
                     (opacityKeys->alpha << 24));
    }
    durationFloat = (f32)duration;
    mode = colors->mode;
    switch (mode) {
    case 0:
        startColor = (s32)colors->startColor;
        endColor = (s32)colors->endColor;
        blend = (f32)frame / durationFloat;
        break;
    case 1:
        endFrame = (s32)(colors->firstFraction * durationFloat);
        if (frame < endFrame) {
            startColor = (s32)colors->startColor;
            endColor = (s32)colors->firstMiddleColor;
            blend = (f32)frame / (f32)endFrame;
        } else {
            startColor = (s32)colors->firstMiddleColor;
            endColor = (s32)colors->endColor;
            blend = (segmentSpan = (f32)(duration - endFrame), (f32)(frame - endFrame) / segmentSpan);
        }
        break;
    case 2:
        startFrame = (s32)(colors->firstFraction * durationFloat);
        if (frame < startFrame) {
            startColor = (s32)colors->startColor;
            endColor = (s32)colors->firstMiddleColor;
            blend = (f32)frame / (f32)startFrame;
        } else {
            endFrame = (s32)(colors->secondFraction * durationFloat);
            if (frame < endFrame) {
                startColor = (s32)colors->firstMiddleColor;
                endColor = (s32)colors->secondMiddleColor;
                blend = (segmentSpan = (f32)(endFrame - startFrame), (f32)(frame - startFrame) / segmentSpan);
            } else {
                startColor = (s32)colors->secondMiddleColor;
                endColor = (s32)colors->endColor;
                blend = (segmentSpan = (f32)(duration - endFrame), (f32)(frame - endFrame) / segmentSpan);
            }
        }
        break;
    default:
        startColor = (s32)colors->startColor;
        endColor = (s32)colors->endColor;
        blend = 0.0f;
        break;
    }
    secondColor = endColor;
    colorSource = &secondColor;
    normalization = fGpffff8044;
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vmove.xyzw $vf11, $vf10\n"
        : : "r"(colorSource), "f"(normalization), "m"(secondColor)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    firstColor = startColor;
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : : "r"(&firstColor), "f"(normalization), "m"(firstColor)
        : "$2", "$vf2", "$vf10", "memory");
    opacity = 1.0f; /* Full alpha between the two independently configured ramps. */
    inverseBlend = opacity - blend;
    __asm__ volatile(
        "mfc1 $2, %0\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf11, $vf11, $vf2x\n"
        "vadd.xyzw $vf10, $vf10, $vf11\n"
        : : "f"(inverseBlend), "f"(blend)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    {
        u32 colorWork = 0x437F0000U; /* Binary32 255.0f for the VU color scale. */
        __asm__ volatile(
            "qmtc2.ni %0, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $zero, %0\n"
            "ppacb %0, $zero, %0\n"
            "sw %0, packedRgb\n"
            : "+r"(colorWork), "=m"(packedRgb)
            : : "$vf2", "$vf10", "memory");
    }
    mixedColor = packedRgb;
    {
        s32 fadeIn = (s32)(opacityKeys->fadeInFraction * durationFloat);
        s32 fadeOut = (s32)(opacityKeys->fadeOutFraction * durationFloat);
        opacity = effect_color_opacity(frame, duration, fadeIn, fadeOut, opacity);
    }
    baseAlpha = (s32)opacityKeys->alpha;
    alphaFloat = (f32)(u32)baseAlpha;
    scaledAlpha = alphaFloat * opacity;
    alpha = (s32)(u32)scaledAlpha;
    return (s32)(((u32)mixedColor & 0xFFFFFFU) | ((u32)alpha << 24));
}
/* measured: opt_propagation off tested for target subtraction scheduling. */
#pragma opt_propagation off
// FUN_0048AFF0
f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 mode;
    f32 from;
    f32 to;
    f32 t;
    f32 fArg2;

    if (arg2 == 0) {
        return *(f32 *)(arg0 + 4);
    }

    fArg2 = (f32)arg2;
    mode = *(u8 *)arg0;
    switch (mode) {
    case 0:
        from = *(f32 *)(arg0 + 4);
        to = *(f32 *)(arg0 + 8);
        t = (f32)arg1 / fArg2;
        break;
    case 1: {
        s32 v1 = (s32)(*(f32 *)(arg0 + 0x18) * fArg2);
        if (arg1 < v1) {
            from = *(f32 *)(arg0 + 4);
            to = *(f32 *)(arg0 + 0x14);
            t = (f32)arg1 / (f32)v1;
        } else {
            f32 denom;
            from = *(f32 *)(arg0 + 0x14);
            to = *(f32 *)(arg0 + 8);
            denom = (f32)(arg2 - v1);
            t = (f32)(arg1 - v1) / denom;
        }
        break;
    }
    case 2: {
        s32 t1 = (s32)(*(f32 *)(arg0 + 0x18) * fArg2);
        if (arg1 < t1) {
            from = *(f32 *)(arg0 + 4);
            to = *(f32 *)(arg0 + 0x14);
            t = (f32)arg1 / (f32)t1;
        } else {
            s32 t2 = (s32)(*(f32 *)(arg0 + 0x20) * fArg2);
            if (arg1 < t2) {
                from = *(f32 *)(arg0 + 0x14);
                to = *(f32 *)(arg0 + 0x1c);
                {
                    f32 denom = (f32)(t2 - t1);
                    t = (f32)(arg1 - t1) / denom;
                }
            } else {
                f32 denom;
                from = *(f32 *)(arg0 + 0x1c);
                to = *(f32 *)(arg0 + 8);
                denom = (f32)(arg2 - t2);
                t = (f32)(arg1 - t2) / denom;
            }
        }
        break;
    }
    default:
        from = *(f32 *)(arg0 + 4);
        to = *(f32 *)(arg0 + 8);
        t = 0.0f;
        break;
    }

    return from + t * (to - from);
}
/* measured: restore opt_propagation after func_0048aff0. */
#pragma opt_propagation on
// FUN_0048B220
void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3)
{
    s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
    f32 func_0048a460(void);
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
/* Guarded native proof, 2026-09-29: 1668/1696 bytes, 373 differing words.
 * Branch-local packed-color outputs recover the retail 0x150 frame.
 * Approved VU helpers own complete C objects and allocated transfer registers.
 * Count is read at its address use; interpolation increments before attributes.
 * Instruction differences remain; production retains ASM. */
// FUN_0048B340 NONMATCHING
#ifdef NON_MATCHING
void func_0048b340(u8 *arg0, u8 *arg1)
{
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048a810(f32 t, void *quads);
    extern f32 fGpffff8044;
    u_long128 quadF0[4];
    u_long128 tmpE0;
    u_long128 tmpD0;
    u8 *config;
    s32 c4;
    u32 c0;
    u32 boundC0;
    u32 nmult;
    s32 node10;
    u8 *nodesBase;
    f32 one;
    f32 invN;
    f32 acc;
    f32 scaleTop;
    f32 acc2;
    f32 inv2;
    f32 baseX;
    f32 diffX;
    f32 baseY;
    f32 diffY;
    f32 packScale;
    u8 *dst1;
    u8 *clear;
    u8 *src1;
    u8 *dst2;
    u8 *dst3;
    u32 i;
    u32 j;
    u32 k;
    s32 tmp;
    f32 ftmp;
    u32 alpha;
    u8 *second;
    u8 *iter;

    config = *(u8 **)(arg0 + 0x20);
    c4 = *(s32 *)(config + 0xC4);
    c0 = *(u32 *)(config + 0xC0);
    nmult = c0 * (u32)c4;
    if (nmult == 0) {
        return;
    }
    node10 = *(s32 *)(arg1 + 0x10);
    nodesBase = *(u8 **)(arg0 + 0x18);
    clear = nodesBase + 32 * (*(u32 *)(arg0 + 4) + ((u32)(arg1 - nodesBase) >> 5) * nmult);
    if (node10 == 0) {
        memcpy(clear, arg1, 0x20);
        dst1 = clear;
        i = 0;
        goto loop0_check;
loop0_body:
        *(s32 *)(dst1 + 0x10) = -1;
        dst1 += 0x20;
        i += 1;
loop0_check:
        if (i < nmult) {
            goto loop0_body;
        }
        return;
    }
    *(s32 *)(clear + 0x10) = node10 - 1;
    one = 1.0f;
    invN = one / (f32)(u32)nmult;
    acc = 0.0f;
    scaleTop = (f32)(u32)((*(u32 *)(arg1 + 0x14)) >> 24);
    boundC0 = nmult - (u32)c4;
    dst1 = clear + nmult * 32 - 0x20;
    src1 = dst1 - (u32)(c4 * 32);
    j = 0;
    goto loop1_check;
loop1_body:
    memcpy(dst1, src1, 0x20);
    ftmp = scaleTop * acc;
    alpha = (u32)ftmp;
    *(u32 *)(dst1 + 0x14) = (*(u32 *)(src1 + 0x14) & 0xFFFFFF) | (alpha << 24);
    acc = acc + invN;
    dst1 -= 0x20;
    src1 -= 0x20;
    j += 1;
loop1_check:
    if (j < boundC0) {
        goto loop1_body;
    }
    memcpy(clear, arg1, 0x20);
    *(s32 *)(clear + 0x10) = -1;
    if ((c4 == 1) || (c0 < 2)) {
        return;
    }
    if ((node10 >= 2) && (c0 >= 3)) {
        s32 colTmpA;
        s32 colTmpB;
        u32 packedTmp;
        u32 colorTransfer;
        second = clear + (u32)(c4 * 32);
        if (*(s32 *)(clear + (u32)(c4 * 64) + 0x10) < 0) {
            return;
        }
        quadF0[0] = *(u_long128 *)(clear + (u32)(c4 * 64));
        quadF0[1] = *(u_long128 *)second;
        quadF0[2] = *(u_long128 *)clear;
        quadF0[3] = *(u_long128 *)clear;
        iter = second - 0x20;
        acc2 = 0.0f;
        inv2 = one / (f32)(u32)((u32)c4 + 1);
        baseX = *(f32 *)(second + 0x18);
        diffX = *(f32 *)(clear + 0x18) - baseX;
        baseY = *(f32 *)(second + 0x1C);
        diffY = *(f32 *)(clear + 0x1C) - baseY;
        colTmpA = *(s32 *)(clear + 0x14);
        colTmpB = *(s32 *)(second + 0x14);
        packScale = 255.0f;
        {
            f32 sc = fGpffff8044;
            effectVuUnpackColor10((u32 *)&colTmpA, sc);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11");
            effectVuUnpackColor10((u32 *)&colTmpB, sc);
            effectVuStore10((EffectVuVector *)&tmpE0);
            __asm__ volatile(
                "vsub.xyzw $vf11, $vf11, $vf10\n"
                "vaddw.xyz $vf10, $vf0, $vf0w\n"
                "vmulx.w $vf10, $vf0, $vf0x\n"
                : : : "$vf10", "$vf11");
            effectVuScale10(inv2);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11");
            effectVuStore10((EffectVuVector *)&tmpD0);
        }
        k = 0;
        goto loop2_check;
loop2_body:
        acc2 = acc2 + inv2;
        func_0048a810(acc2, quadF0);
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(iter) : "$vf10", "memory");
        *(f32 *)(iter + 0x18) = baseX + diffX * acc2;
        *(f32 *)(iter + 0x1C) = baseY + diffY * acc2;
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&tmpE0) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&tmpD0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&tmpE0) : "$vf10", "memory");
        {
            __asm__ volatile(
                "mfc1 %0, %2\n"
                "nop\n"
                "qmtc2.ni %0, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, packedTmp\n"
                : "=r"(colorTransfer), "=m"(packedTmp)
                : "f"(packScale)
                : "$vf2", "$vf10", "memory");
        }
        *(u32 *)(iter + 0x14) = packedTmp;
        *(s32 *)(iter + 0x10) = node10;
        iter -= 0x20;
        k += 1;
loop2_check:
        if (k < (u32)(c4 - 1)) {
            goto loop2_body;
        }
        return;
    } else {
        s32 colTmpA;
        s32 colTmpB;
        u32 packedTmp;
        u32 colorTransfer;
        if (node10 <= 0) {
            return;
        }
        second = clear + (u32)(c4 * 32);
        if (*(s32 *)(second + 0x10) < 0) {
            return;
        }
        iter = second - 0x20;
        acc2 = 0.0f;
        inv2 = one / (f32)(u32)((u32)c4 + 1);
        baseX = *(f32 *)(second + 0x18);
        {
            f32 bx = *(f32 *)(clear + 0x18);
            diffX = bx - baseX;
        }
        baseY = *(f32 *)(second + 0x1C);
        {
            f32 by = *(f32 *)(clear + 0x1C);
            diffY = by - baseY;
        }
        colTmpA = *(s32 *)(clear + 0x14);
        colTmpB = *(s32 *)(second + 0x14);
        packScale = 255.0f;
        {
            f32 sc = fGpffff8044;
            effectVuUnpackColor10((u32 *)&colTmpA, sc);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11");
            effectVuUnpackColor10((u32 *)&colTmpB, sc);
            effectVuStore10((EffectVuVector *)&tmpE0);
            __asm__ volatile(
                "vsub.xyzw $vf11, $vf11, $vf10\n"
                "vaddw.xyz $vf10, $vf0, $vf0w\n"
                "vmulx.w $vf10, $vf0, $vf0x\n"
                : : : "$vf10", "$vf11");
            effectVuScale10(inv2);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11");
            effectVuStore10((EffectVuVector *)&tmpD0);
        }
        tmp = c4 - 1;
        k = 0;
        goto loop3_check;
loop3_body:
        acc2 = acc2 + inv2;
        {
            f32 t = acc2;
            effectVuLoad10((EffectVuVector *)second);
            effectVuLoad11((EffectVuVector *)clear);
            __asm__ volatile(
                "qmtc2.ni %0, $vf2\n"
                "vsubx.w $vf3, $vf0, $vf2x\n"
                "vmulax.xyzw $ACC, $vf11, $vf2x\n"
                "vmaddw.xyzw $vf10, $vf10, $vf3w\n"
                : : "r"(t) : "$vf2", "$vf3", "$vf10", "$vf11", "ACC");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(iter) : "$vf10", "memory");
        }
        *(f32 *)(iter + 0x18) = baseX + diffX * acc2;
        *(f32 *)(iter + 0x1C) = baseY + diffY * acc2;
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&tmpE0) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&tmpD0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&tmpE0) : "$vf10", "memory");
        {
            __asm__ volatile(
                "mfc1 %0, %2\n"
                "nop\n"
                "qmtc2.ni %0, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2.ni %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, packedTmp\n"
                : "=r"(colorTransfer), "=m"(packedTmp)
                : "f"(packScale)
                : "$vf2", "$vf10", "memory");
        }
        *(u32 *)(iter + 0x14) = packedTmp;
        *(s32 *)(iter + 0x10) = node10;
        iter -= 0x20;
        k += 1;
loop3_check:
        if (k < (u32)tmp) {
            goto loop3_body;
        }
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b340);
#endif
/* Recovered Wave controller: complete position snapshots and actual live trail
 * indexing. Domain and source/compiler evidence are recorded in
 * docs/probe_archive/wave-spawn-20261005/. The existing trail provider retains
 * its separately documented initialization limitation; this caller does not
 * read its trail payload. */
// FUN_0048B9E0
#include "particle_spawn_internal.h"
/* Measured: these scoped settings preserve the recovered wave update
 * evaluation order and the complete retail 2652-byte executable body. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_0048b9e0(u8 *arg0)
{
    extern f32 sinf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern u8 D_00713D30[];
    EffectVuVector direction;
    EffectVuVector spreadVector;
    u_long128 b220buf;
    u32 count;
    u32 flags;
    SpawnParticle *particle;
    WaveSpawnState *state;
    WaveSpawnParameters *parameters;
    WaveSpawnEmitter *const emitter = (WaveSpawnEmitter *)arg0;
    s32 lifetime;
    s32 emissionDuration;
    u8 angleMode;
    f32 gravity;
    f32 zero;
    f32 one, half, two;
    f32 angleScale;
    s32 spawnBudget;
    s32 preroll;
    u32 index;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 age;
    s32 trailCount;
    s32 trailWidth;
    s32 trailLength;
    SpawnParticle *trail;
    s32 trailIndex;
    u32 particleIndex;
    f32 a;
    f32 finalAmplitudeVariation;
    f32 b;
    f32 c;
    count = emitter->primaryCount;
    flags = emitter->flags;
    particle = emitter->particles;
    state = emitter->state;
    parameters = emitter->parameters;
    lifetime = parameters->lifetime;
    if (lifetime == 0) {
        return;
    }
    emissionDuration = parameters->emissionDuration;
    angleMode = parameters->angleMode;
    gravity = parameters->gravity;
    /* VU multiplication consumes W as well as the three spatial lanes. */
    spreadVector.lane[3] = 0.0f;
    effectVuLoad10(&parameters->rotation);
    func_004bceb0();
    if ((emissionDuration != 0) && (emitter->ticks >= emissionDuration)) {
        preroll = 0;
        spawnBudget = 0;
        goto post_init;
    }
    if ((emitter->ticks == 0) && (parameters->preroll != 0)) {
        /* Keep the byte-valued enable phase distinct from its loop flag.
         * The same narrow-to-word source form occurs in func_0048a980. */
        u8 initialPreroll = 1;
        preroll = initialPreroll;
        if (!(parameters->emissionVariation <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - parameters->emissionVariation) * effMiscRandFloat(0);
            ftmp2 = (f32)emitter->primaryCount;
            spawnBudget = (s32)(ftmp2 * prerollScale);
        } else {
            spawnBudget = emitter->primaryCount;
        }
        goto post_init;
    } else {
        preroll = 0;
        if (!(parameters->emissionVariation <= 0.0f)) {
            ftmp1 = (fGpffff807c - parameters->emissionVariation) * effMiscRandFloat(0);
            tmp = parameters->emissionRate;
            ftmp2 = (f32)(u32)tmp;
            emitter->emissionAccumulator = emitter->emissionAccumulator + ftmp2 * ftmp1;
        } else {
            tmp = parameters->emissionRate;
            ftmp1 = (f32)(u32)tmp;
            emitter->emissionAccumulator = emitter->emissionAccumulator + ftmp1;
        }
        ftmp1 = emitter->emissionAccumulator;
        ftmp1 = fabsf(ftmp1);
        spawnBudget = (s32)ftmp1;
        emitter->emissionAccumulator = emitter->emissionAccumulator - (f32)spawnBudget;
        goto post_init;
    }
post_init:
    index = 0;
    zero = 0.0f;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    angleScale = fGpffff8080;
    goto main_check;
main_body:
    if (particle->age < lifetime) {
        goto skip_clear;
    }
    if (emissionDuration != 0) {
        tmp = -2;
    } else {
        tmp = -1;
    }
    particle->age = tmp;
    trailCount = emitter->parameters->trailCount;
    trailWidth = emitter->parameters->trailWidth;
    trailLength = trailCount * trailWidth;
    if (trailLength != 0) {
        /* The live emitter base/count may differ from the loop capture. */
        particleIndex = ((u32)particle - (u32)emitter->particles) >> 5;
        trail = emitter->particles + (emitter->primaryCount + particleIndex * (u32)trailLength);
        trailIndex = 0;
        goto clear_check;
clear_body:
        trail->age = -1;
        trail += 1;
        trailIndex += 1;
clear_check:
        if (trailIndex < trailLength) {
            goto clear_body;
        }
    }
skip_clear:
    age = particle->age;
    if (age == -2) {
        goto next_iter;
    }
    if (age != -1) {
        goto else_branch;
    }
    if (spawnBudget == 0) {
        goto next_iter;
    }
    if (!((flags & 1) == 0)) {
        state->direction[0] = zero;
        state->direction[1] = one;
        state->direction[2] = zero;
    } else {
        effectVuLoad10((const EffectVuVector *)D_00713D30);
        spawnVuTransform10();
        effectVuStore10(&direction);
        state->direction[0] = direction.lane[0];
        state->direction[1] = direction.lane[1];
        state->direction[2] = direction.lane[2];
    }
    b = effMiscRandFloat(0);
    direction.lane[0] = two * (b - half);
    direction.lane[1] = zero;
    b = effMiscRandFloat(0);
    direction.lane[2] = two * (b - half);
    direction.lane[3] = zero;
    effectVuLoad10(&direction);
    spawnVuNormalize10();
    if ((flags & 1) == 0) {
        spawnVuTransform10();
    }
    effectVuStore10(&direction);
    state->waveDirection[0] = direction.lane[0];
    state->waveDirection[1] = direction.lane[1];
    state->waveDirection[2] = direction.lane[2];
    a = parameters->speedVariation;
    b = effMiscRandFloat(0);
    state->speed = parameters->speed * ((one - a) + a * b);
    a = parameters->initialAmplitudeVariation;
    b = effMiscRandFloat(0);
    c = parameters->initialAmplitude * ((one - a) + a * b);
    finalAmplitudeVariation = parameters->finalAmplitudeVariation;
    b = effMiscRandFloat(0);
    ftmp1 = parameters->finalAmplitude * ((one - finalAmplitudeVariation) + finalAmplitudeVariation * b);
    state->amplitude = c;
    state->amplitudeStep = (ftmp1 - c) / (f32)lifetime;
    a = parameters->phaseStepVariation;
    b = effMiscRandFloat(0);
    state->phaseStep = parameters->phaseStep * ((one - a) + a * b);
    b = effMiscRandFloat(0);
    state->phase = angleScale * b;
    state->previousSine = sinf(state->phase);
    b = effMiscRandFloat(0);
    c = parameters->spread * (two * (b - half));
    spreadVector.lane[0] = c;
    spreadVector.lane[1] = c;
    spreadVector.lane[2] = c;
    if ((flags & 1) != 0) {
        effectVuLoad10(&direction);
        effectVuLoad11(&spreadVector);
        spawnVuMultiply10();
    } else {
        effectVuLoad10(&direction);
        effectVuLoad11(&spreadVector);
        spawnVuMultiply10();
        effectVuLoad11(&parameters->position);
        spawnVuAdd10();
    }
    effectVuStore10(&particle->position);
    a = parameters->sizeVariation;
    b = effMiscRandFloat(0);
    state->sizeScale = (one - a) + a * b;
    if (angleMode != 2) {
        a = parameters->angleVariation;
        b = effMiscRandFloat(0);
        state->angleScale = (one - a) + a * b;
        if (angleMode == 1) {
            b = effMiscRandFloat(0);
            state->angleOffset = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                state->angleScale = state->angleScale * -1.0f;
            }
        } else {
            state->angleOffset = zero;
        }
    } else {
        state->angleOffset = zero;
        state->angleScale = one;
    }
    particle->age = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)&particle->position;
    }
    if (preroll != 0) {
        f32 prerollElapsed;
        f32 travelled;
        f32 gravityDistance;
        f32 gravitySquaredDistance;
        tmp = (u32)effMiscRand(0) % (u32)lifetime;
        prerollElapsed = (f32)(u32)tmp;
        travelled = state->speed * prerollElapsed;
        gravityDistance = gravity * prerollElapsed;
        gravitySquaredDistance = prerollElapsed * gravityDistance;
        ftmp2 = travelled - half * gravitySquaredDistance;
        particle->position.lane[0] = particle->position.lane[0] + state->direction[0] * ftmp2;
        particle->position.lane[1] = particle->position.lane[1] + state->direction[1] * ftmp2;
        particle->position.lane[2] = particle->position.lane[2] + state->direction[2] * ftmp2;
        state->phase = state->phase + state->phaseStep * prerollElapsed;
        state->amplitude = state->amplitude + state->amplitudeStep * prerollElapsed;
        a = sinf(state->phase);
        c = state->amplitude * a;
        particle->position.lane[0] = particle->position.lane[0] + state->waveDirection[0] * c;
        particle->position.lane[1] = particle->position.lane[1] + state->waveDirection[1] * c;
        particle->position.lane[2] = particle->position.lane[2] + state->waveDirection[2] * c;
        state->phase = state->phase + state->phaseStep;
        state->amplitude = state->amplitude + state->amplitudeStep;
        state->previousSine = a;
        particle->age = (s32)prerollElapsed;
    }
    func_0048b220((u8 *)particle, (u8 *)parameters, particle->age, &b220buf);
    particle->size = particle->size * state->sizeScale;
    particle->angle = particle->angle * state->angleScale;
    particle->angle = particle->angle + state->angleOffset;
    if (preroll != 0) {
        trailLength = emitter->parameters->trailCount * emitter->parameters->trailWidth;
        if (trailLength != 0) {
            particleIndex = ((u32)particle - (u32)emitter->particles) >> 5;
            trail = emitter->particles + (emitter->primaryCount + particleIndex * (u32)trailLength);
            memcpy(trail, particle, sizeof(*particle));
            trail->age = -1;
        }
        particle->age = particle->age + 1;
    }
    spawnBudget -= 1;
    goto next_iter2;
else_branch:
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)&particle->position;
    }
    ftmp1 = sinf(state->phase);
    ftmp2 = state->amplitude * (ftmp1 - state->previousSine);
    particle->position.lane[0] = particle->position.lane[0] + state->waveDirection[0] * ftmp2;
    particle->position.lane[1] = particle->position.lane[1] + state->waveDirection[1] * ftmp2;
    particle->position.lane[2] = particle->position.lane[2] + state->waveDirection[2] * ftmp2;
    ftmp2 = state->speed - gravity * (f32)age;
    particle->position.lane[0] = particle->position.lane[0] + state->direction[0] * ftmp2;
    particle->position.lane[1] = particle->position.lane[1] + state->direction[1] * ftmp2;
    particle->position.lane[2] = particle->position.lane[2] + state->direction[2] * ftmp2;
    state->phase = state->phase + state->phaseStep;
    state->amplitude = state->amplitude + state->amplitudeStep;
    state->previousSine = ftmp1;
    func_0048b220((u8 *)particle, (u8 *)parameters, age, &b220buf);
    particle->size = particle->size * state->sizeScale;
    particle->angle = particle->angle * state->angleScale;
    particle->angle = particle->angle + state->angleOffset;
    func_0048b340((u8 *)emitter, (u8 *)particle);
    particle->age = age + 1;
next_iter2:
next_iter:
    index += 1;
    state += 1;
    particle += 1;
main_check:
    if (index < count) {
        goto main_body;
    }
}
#pragma pop

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
/* Motion emitter: ordinary C emission, random and integration calculations;
 * VU instructions preserve the full hardware vector operations. The aligned
 * XYZ scale's complete object representation is described at its declaration.
 * Proof: docs/probe_archive/Motion_scale_0048c4e0_20261005/README.md.
 * Measured scopes preserve scalar operand lifetimes across RNG calls. */
// FUN_0048C4E0
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
void func_0048c4e0(u8 *arg0)
{
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    EffectVuVector vec130;
    /* LQC2 reads the complete representation of this aligned XYZ vector.
     * The fourth word is the struct's unspecified tail padding, not a float
     * member. Preserve the hardware load and all four VU result lanes. */
    typedef struct MotionScale3 {
        f32 lane[3];
    } __attribute__((aligned(16))) MotionScale3;
    typedef char MotionScale3Size[(sizeof(MotionScale3) == 16) ? 1 : -1];
    MotionScale3 vec120;
    u_long128 b220buf;
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
    f32 e0val;
    f32 half;
    f32 two;
    f32 one;
    f32 zero;
    f32 g80;
    f32 negone;
    s32 v15;
    s32 v14;
    u8 initialPreroll;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    u32 particleIndex;
    f32 speedVariation;
    f32 spreadVariation;
    f32 sizeVariation;
    f32 angleVariation;
    f32 b;

    count = *(u32 *)(parent + 4);
    flags = *(u32 *)(parent + 12);
    nodes = *(u8 **)(parent + 24);
    out = *(f32 **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 220);
    e0val = *(f32 *)(config + 216);
    vec130.lane[3] = 0.0f;
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        initialPreroll = 1;
        v14 = initialPreroll;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            f32 prerollScale = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * prerollScale);
        } else {
            v15 = *(s32 *)(parent + 4);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        } else {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    half = 0.5f;
    two = 2.0f;
    one = 1.0f;
    zero = 0.0f;
    g80 = fGpffff8080;
    negone = -1.0f;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 != 0) {
        tmp = -2;
    } else {
        tmp = -1;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        particleIndex = ((u32)nodes - (u32)*(u8 **)(parent + 24)) >> 5;
        clear = *(u8 **)(parent + 24) + ((*(u32 *)(parent + 4) + particleIndex * (u32)nmult) << 5);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    vec130.lane[0] = (effMiscRandFloat(0) - half) * two;
    vec130.lane[1] = (effMiscRandFloat(0) - half) * two;
    vec130.lane[2] = (effMiscRandFloat(0) - half) * two;
    effectVuLoad10(&vec130);
    spawnVuNormalize10();
    effectVuStore10(&vec130);
    out[0] = vec130.lane[0];
    out[1] = vec130.lane[1];
    out[2] = vec130.lane[2];
    speedVariation = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    out[3] = fabsf(*(f32 *)(config + 208) * ((one - speedVariation) + speedVariation * b));
    spreadVariation = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    vec120.lane[0] = *(f32 *)(config + 200) * ((one - spreadVariation) + spreadVariation * b);
    vec120.lane[1] = vec120.lane[0];
    vec120.lane[2] = vec120.lane[0];
    effectVuLoad10(&vec130);
    if (*(f32 *)(config + 208) < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)"
            : : "r"(&vec120), "m"(*(const u8 (*)[sizeof(vec120)])&vec120)
            : "$vf11");
        spawnVuMultiply10();
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)"
            : : "r"(&vec120), "m"(*(const u8 (*)[sizeof(vec120)])&vec120)
            : "$vf11");
        spawnVuMultiply10();
        effectVuLoad11((const EffectVuVector *)config);
        spawnVuAdd10();
    }
    effectVuStore10((EffectVuVector *)nodes);
    sizeVariation = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[4] = (one - sizeVariation) + sizeVariation * b;
    if (mode9C != 2) {
        angleVariation = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[6] = (one - angleVariation) + angleVariation * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[5] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[6] = out[6] * negone;
            }
        } else {
            out[5] = zero;
        }
    } else {
        out[5] = zero;
        out[6] = one;
    }
    *(s32 *)(nodes + 16) = 0;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    if (v14 != 0) {
        f32 prerollElapsed;
        f32 prerollDistance;
        f32 travelled;
        f32 accelerationDistance;
        f32 accelerationSquaredDistance;
        f32 gravityDistance;
        f32 gravitySquaredDistance;
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        prerollElapsed = (f32)(u32)tmp;
        effectVuLoad11((const EffectVuVector *)nodes);
        travelled = out[3] * prerollElapsed;
        accelerationDistance = e0val * prerollElapsed;
        accelerationSquaredDistance = prerollElapsed * accelerationDistance;
        prerollDistance = travelled + half * accelerationSquaredDistance;
        if (prerollDistance < zero) {
            prerollDistance = zero;
        }
        vec130.lane[0] = prerollDistance * out[0];
        vec130.lane[1] = prerollDistance * out[1];
        vec130.lane[2] = prerollDistance * out[2];
        gravityDistance = e4val * prerollElapsed;
        gravitySquaredDistance = prerollElapsed * gravityDistance;
        vec130.lane[1] = vec130.lane[1] - half * gravitySquaredDistance;
        effectVuLoad10(&vec130);
        spawnVuAdd10();
        effectVuStore10((EffectVuVector *)nodes);
        *(s32 *)(nodes + 16) = (s32)prerollElapsed;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            particleIndex = ((u32)nodes - (u32)*(u8 **)(parent + 24)) >> 5;
            clear = *(u8 **)(parent + 24) + ((*(u32 *)(parent + 4) + particleIndex * (u32)nmult) << 5);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    {
    f32 liveDistance;
    {
        u_long128 *snapshot = &b220buf;
        *snapshot = *(u_long128 *)nodes;
    }
    effectVuLoad11((const EffectVuVector *)nodes);
    liveDistance = out[3] + e0val * (f32)node10;
    if (liveDistance < zero) {
        liveDistance = zero;
    }
    vec130.lane[0] = liveDistance * out[0];
    vec130.lane[1] = liveDistance * out[1];
    vec130.lane[2] = liveDistance * out[2];
    vec130.lane[1] = vec130.lane[1] - e4val * (f32)node10;
    effectVuLoad10(&vec130);
    spawnVuAdd10();
    effectVuStore10((EffectVuVector *)nodes);
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
    }
next_iter2:
next_iter:
    idx += 1;
    out += 7;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}

#pragma pop
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
/* Guarded native proof, 2026-09-29: 2572/2608 bytes, 579 differing words.
 * Keeping the angle global live across the loop recovers the retail
 * 0x180 frame and nine saved FPRs. Both preroll and live transforms are
 * conditional on the clear flag; Y translation is applied only once.
 * Instruction differences remain; production retains ASM. */
// FUN_0048CDF0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_0048cdf0(u8 *arg0)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    u_long128 b220buf;
    u_long128 cfg0;
    u_long128 cfg10;
    f32 tmp130[4] __attribute__((aligned(16)));
    f32 tmp150[4] __attribute__((aligned(16)));
    f32 tmp160[4] __attribute__((aligned(16)));
    f32 tmp170[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 eF0val;
    f32 eECval;
    f32 angleScale;
    s32 v15;
    s32 v14;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;
    count = *(u32 *)(parent + 4);
    flags = *(u32 *)(parent + 12);
    nodes = *(u8 **)(parent + 24);
    out = *(f32 **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    eF0val = *(f32 *)(config + 240);
    eECval = *(f32 *)(config + 236);
    tmp170[3] = 0.0f;
    tmp130[3] = 0.0f;
    tmp160[3] = 0.0f;
    cfg0 = *(u_long128 *)(config + 0);
    cfg10 = *(u_long128 *)(config + 16);
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = *(s32 *)(parent + 4);
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    angleScale = fGpffff8080;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    a = *(f32 *)(config + 208);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 204) * ((1.0f - a) + a * b);
    out[8] = c;
    a = *(f32 *)(config + 216);
    b = effMiscRandFloat(0);
    out[9] = (*(f32 *)(config + 212) * ((1.0f - a) + a * b) - c) / (f32)limitB8;
    b = effMiscRandFloat(0);
    out[10] = angleScale * b;
    a = *(f32 *)(config + 224);
    b = effMiscRandFloat(0);
    out[11] = *(f32 *)(config + 220) * ((1.0f - a) + a * b);
    a = *(f32 *)(config + 232);
    b = effMiscRandFloat(0);
    out[12] = *(f32 *)(config + 228) * ((1.0f - a) + a * b);
    tmp170[0] = cosf(out[10]);
    tmp170[1] = 0.0f;
    tmp170[2] = sinf(out[10]);
    b = effMiscRandFloat(0);
    out[7] = *(f32 *)(config + 200) * b;
    tmp160[0] = c;
    tmp160[1] = c;
    tmp160[2] = c;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp160), "m"(*(u_long128 *)tmp160) : "$vf11", "memory");
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile(
        "lw $2, 28(%0) \n"
        "nop \n"
        "qmtc2.ni $2, $vf2 \n"
        "vaddx.y $vf10, $vf0, $vf2x \n"
        : : "r"(out) : "$2", "$vf2", "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        out[0] = ((f32 *)&cfg0)[0];
        out[1] = ((f32 *)&cfg0)[1];
        out[2] = ((f32 *)&cfg0)[2];
        out[3] = ((f32 *)&cfg10)[0];
        out[4] = ((f32 *)&cfg10)[1];
        out[5] = ((f32 *)&cfg10)[2];
        out[6] = ((f32 *)&cfg10)[3];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&cfg10), "m"(cfg10) : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&cfg0), "m"(cfg0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[13] = (1.0f - a) + a * b;
    if (mode9C == 2) {
        out[14] = 0.0f;
        out[15] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[15] = (1.0f - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[14] = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[15] = out[15] * -1.0f;
            }
        } else {
            out[14] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        out[7] = out[7] + out[12] * ftmp1;
        out[7] = out[7] - ftmp1 * eF0val * ftmp1 * 0.5f;
        out[8] = out[8] + out[9] * ftmp1;
        tmp130[0] = out[8] * cosf(out[10]);
        tmp130[1] = out[7];
        tmp130[2] = out[8] * sinf(out[10]);
        if ((flags & 1) == 0) {
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&cfg10), "m"(cfg10) : "$vf10", "memory");
            func_004bceb0();
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&cfg0), "m"(cfg0) : "$vf11", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        } else {
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    ftmp1 = (f32)node10;
    ftmp2 = ftmp1 * (eECval * ftmp1 * 0.5f + out[11]) + out[10];
    out[7] = out[7] + out[12];
    out[7] = out[7] - eF0val * ftmp1;
    out[8] = out[8] + out[9];
    c = out[8];
    tmp130[0] = c * cosf(ftmp2);
    tmp130[1] = out[7];
    tmp130[2] = c * sinf(ftmp2);
    if ((flags & 1) == 0) {
        tmp150[0] = out[3];
        tmp150[1] = out[4];
        tmp150[2] = out[5];
        tmp150[3] = out[6];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp150), "m"(*(u_long128 *)tmp150) : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
        tmp130[0] = tmp130[0] + out[0];
        tmp130[1] = tmp130[1] + out[1];
        tmp130[2] = tmp130[2] + out[2];
    }
    *(f32 *)(nodes + 0) = tmp130[0];
    *(f32 *)(nodes + 4) = tmp130[1];
    *(f32 *)(nodes + 8) = tmp130[2];
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 16;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048cdf0);
#endif
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
/* Guarded native proof, 2026-09-29: 2476/2480 bytes, 413 differing words.
 * Immutable owner identity restores the owner/config/work/node register order;
 * the real config capture and three live quadword homes follow retail.
 * Preroll rereads current count rather than the cached loop bound.
 * Frame 0x150 still differs from retail 0x160; no unused storage is added.
 * Instruction differences remain; production is ASM. */
// FUN_0048D8C0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
void func_0048d8c0(u8 *arg0)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern void func_004bd1a0(f32 arg0);
    extern void func_004bd3c0(f32 arg0);
    extern void func_004bd450(void);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8094;
    f32 sp150[4] __attribute__((aligned(16)));
    f32 sp130[4] __attribute__((aligned(16)));
    u_long128 quad120;
    u_long128 b220buf;
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
    f32 e0val;
    f32 orbitScale;
    f32 tiltScale;
    f32 angleScale;
    s32 v15;
    s32 v14;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;
    count = *(u32 *)(parent + 4);
    flags = *(u32 *)(parent + 12);
    nodes = *(u8 **)(parent + 24);
    out = *(f32 **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 228);
    e0val = *(f32 *)(config + 224);
    sp150[3] = 0.0f;
    {
        u_long128 *const capture = &quad120;
        *capture = *(u_long128 *)(config + 0);
    }
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        v14 = 1;
        if (!(*(f32 *)(config + 40) <= 0.0f)) {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * ftmp1);
        } else {
            v15 = *(s32 *)(parent + 4);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    orbitScale = fGpffff8094;
    tiltScale = fGpffff8084;
    angleScale = fGpffff8080;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    a = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 200) * ((1.0f - a) + a * b);
    out[5] = c;
    a = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    out[6] = (*(f32 *)(config + 208) * ((1.0f - a) + a * b) - c) / (f32)limitB8;
    a = *(f32 *)(config + 220);
    b = effMiscRandFloat(0);
    out[7] = *(f32 *)(config + 216) * ((1.0f - a) + a * b);
    b = effMiscRandFloat(0);
    out[8] = orbitScale * b;
    out[9] = 0.0f;
    b = effMiscRandFloat(0);
    out[3] = tiltScale * (2.0f * (b - 0.5f));
    b = effMiscRandFloat(0);
    out[4] = tiltScale * (2.0f * (b - 0.5f));
    func_004bd1a0(out[3]);
    func_004bd3c0(out[4]);
    func_004bd450();
    sp150[0] = out[5] * cosf(out[8]);
    sp150[1] = 0.0f;
    sp150[2] = out[5] * sinf(out[8]);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    if ((flags & 1) == 0) {
        out[0] = ((f32 *)&quad120)[0];
        out[1] = ((f32 *)&quad120)[1];
        out[2] = ((f32 *)&quad120)[2];
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&quad120), "m"(quad120) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[10] = (1.0f - a) + a * b;
    if (mode9C == 2) {
        out[11] = 0.0f;
        out[12] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[12] = (1.0f - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[11] = angleScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[12] = out[12] * -1.0f;
            }
        } else {
            out[11] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        out[9] = out[9] - ftmp1 * e4val * ftmp1 * 0.5f;
        out[5] = out[6] * ftmp1 + out[5];
        sp150[0] = out[5] * cosf(out[8]);
        sp150[1] = 0.0f;
        sp150[2] = out[5] * sinf(out[8]);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        if ((flags & 1) == 0) {
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf10", "$vf11", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&quad120), "m"(quad120) : "$vf10", "memory");
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[9];
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[10];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[11];
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    ftmp1 = (f32)node10;
    ftmp2 = ftmp1 * (e0val * ftmp1 * 0.5f + out[7]) + out[8];
    out[9] = out[9] - e4val * ftmp1;
    out[5] = out[5] + out[6];
    func_004bd1a0(out[3]);
    func_004bd3c0(out[4]);
    func_004bd450();
    c = out[5];
    sp150[0] = c * cosf(ftmp2);
    sp150[1] = 0.0f;
    sp150[2] = c * sinf(ftmp2);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)sp130) : "r"(sp130) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        sp130[0] = sp130[0] + out[0];
        sp130[1] = sp130[1] + out[1];
        sp130[2] = sp130[2] + out[2];
    }
    *(f32 *)(nodes + 0) = sp130[0];
    *(f32 *)(nodes + 4) = sp130[1] + out[9];
    *(f32 *)(nodes + 8) = sp130[2];
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[10];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[11];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 13;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048d8c0);
#endif
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
/* Guarded native proof, 2026-09-29: 2236/2256 bytes, 393 differing words;
 * frame 0x140 matches retail. Initial direction uses independent random
 * X/Z components and positive Y, not trigonometry. E0 motion and E4 Y
 * acceleration are separate ordinary C expressions.
 * Instruction differences remain; production retains ASM. */
// FUN_0048E2F0 NONMATCHING
#ifdef NON_MATCHING
void func_0048e2f0(u8 *arg0)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    u_long128 b220buf;
    f32 vec120[4] __attribute__((aligned(16)));
    f32 vec130[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
    f32 one;
    f32 half;
    f32 two;
    f32 zero;
    f32 negone;
    f32 g80;
    f32 e0val;
    s32 v15;
    s32 v14;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;

    count = *(u32 *)(parent + 4);
    flags = *(u32 *)(parent + 12);
    nodes = *(u8 **)(parent + 24);
    out = *(f32 **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 228);
    e0val = *(f32 *)(config + 224);
    vec130[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = *(s32 *)(parent + 4);
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    one = 1.0f;
    half = 0.5f;
    two = 2.0f;
    zero = 0.0f;
    g80 = fGpffff8080;
    negone = -1.0f;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    a = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 208) * ((one - a) + a * b);
    vec130[0] = c * ((effMiscRandFloat(0) - half) * two);
    vec130[1] = one - c;
    vec130[2] = c * ((effMiscRandFloat(0) - half) * two);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vec130) : "r"(vec130) : "$vf10", "memory");
    out[0] = vec130[0];
    out[1] = vec130[1];
    out[2] = vec130[2];
    a = *(f32 *)(config + 220);
    b = effMiscRandFloat(0);
    out[3] = *(f32 *)(config + 216) * ((one - a) + a * b);
    out[3] = fabsf(out[3]);
    a = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    vec120[0] = *(f32 *)(config + 200) * ((one - a) + a * b);
    vec120[1] = vec120[0];
    vec120[2] = vec120[0];
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    if (*(f32 *)(config + 216) < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[4] = (one - a) + a * b;
    if (mode9C == 2) {
        out[5] = zero;
        out[6] = one;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[6] = (one - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[5] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[6] = out[6] * negone;
            }
        } else {
            out[5] = zero;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
        ftmp2 = half * (e0val * ftmp1 * ftmp1) + out[3] * ftmp1;
        if (ftmp2 < zero) {
            ftmp2 = zero;
        }
        vec130[0] = ftmp2 * out[0];
        vec130[1] = ftmp2 * out[1];
        vec130[2] = ftmp2 * out[2];
        vec130[1] = vec130[1] - half * (e4val * ftmp1 * ftmp1);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
    ftmp1 = out[3] + e0val * (f32)node10;
    if (ftmp1 < zero) {
        ftmp1 = zero;
    }
    vec130[0] = ftmp1 * out[0];
    vec130[1] = ftmp1 * out[1];
    vec130[2] = ftmp1 * out[2];
    vec130[1] = vec130[1] - e4val * (f32)node10;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 7;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048e2f0);
#endif
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
/* Guarded native proof, 2026-09-29: 2300/2320 bytes, 405 differing words;
 * frame 0x140 and twelve saved FPRs match retail. Cone angle consumes
 * the first RNG result and the signed integer at config+0xe8; distinct
 * angle scale/offset globals stay live across the loop. The cone's Y
 * component is negative, unlike func_0048e2f0.
 * Instruction differences remain; production retains ASM. */
// FUN_0048EC50 NONMATCHING
#ifdef NON_MATCHING
void func_0048ec50(u8 *arg0)
{
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8090;
    extern f32 fGpffff8094;
    u_long128 b220buf;
    f32 vec120[4] __attribute__((aligned(16)));
    f32 vec130[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    f32 *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
    f32 half;
    f32 two;
    f32 one;
    f32 zero;
    f32 negone;
    f32 angleScale;
    f32 angleOffset;
    f32 angle;
    f32 g80;
    f32 e0val;
    s32 v15;
    s32 v14;
    u32 idx;
    s32 tmp;
    f32 ftmp1;
    f32 ftmp2;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;

    count = *(u32 *)(parent + 4);
    flags = *(u32 *)(parent + 12);
    nodes = *(u8 **)(parent + 24);
    out = *(f32 **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 228);
    e0val = *(f32 *)(config + 224);
    vec130[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = *(s32 *)(parent + 4);
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            ftmp2 = (f32)*(u32 *)(parent + 4);
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    half = 0.5f;
    two = 2.0f;
    angleScale = fGpffff8090;
    angleOffset = fGpffff8094;
    one = 1.0f;
    zero = 0.0f;
    g80 = fGpffff8080;
    negone = -1.0f;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    b = effMiscRandFloat(0);
    angle = angleScale * (half * ((f32)*(s32 *)(config + 232) * (two * (b - half)))) - angleOffset;
    a = *(f32 *)(config + 212);
    b = effMiscRandFloat(0);
    c = *(f32 *)(config + 208) * ((one - a) + a * b);
    vec130[0] = c * cosf(angle);
    vec130[1] = -(one - c);
    vec130[2] = c * sinf(angle);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    if ((flags & 1) == 0) {
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x \n"
            "vmadday.xyzw $ACC, $vf29, $vf10y \n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
            : : : "$vf10", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vec130) : "r"(vec130) : "$vf10", "memory");
    out[0] = vec130[0];
    out[1] = vec130[1];
    out[2] = vec130[2];
    a = *(f32 *)(config + 220);
    b = effMiscRandFloat(0);
    out[3] = *(f32 *)(config + 216) * ((one - a) + a * b);
    out[3] = fabsf(out[3]);
    a = *(f32 *)(config + 204);
    b = effMiscRandFloat(0);
    vec120[0] = *(f32 *)(config + 200) * ((one - a) + a * b);
    vec120[1] = vec120[0];
    vec120[2] = vec120[0];
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    if (*(f32 *)(config + 216) < zero) {
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10", "memory");
    }
    if ((flags & 1) != 0) {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    } else {
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vec120), "m"(*(u_long128 *)vec120) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out[4] = (one - a) + a * b;
    if (mode9C == 2) {
        out[5] = zero;
        out[6] = one;
    } else {
        a = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out[6] = (one - a) + a * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out[5] = g80 * b;
            if ((effMiscRand(0) & 1) != 0) {
                out[6] = out[6] * negone;
            }
        } else {
            out[5] = zero;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
        ftmp2 = half * (e0val * ftmp1 * ftmp1) + out[3] * ftmp1;
        if (ftmp2 < zero) {
            ftmp2 = zero;
        }
        vec130[0] = ftmp2 * out[0];
        vec130[1] = ftmp2 * out[1];
        vec130[2] = ftmp2 * out[2];
        vec130[1] = vec130[1] - half * (e4val * ftmp1 * ftmp1);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
    ftmp1 = out[3] + e0val * (f32)node10;
    if (ftmp1 < zero) {
        ftmp1 = zero;
    }
    vec130[0] = ftmp1 * out[0];
    vec130[1] = ftmp1 * out[1];
    vec130[2] = ftmp1 * out[2];
    vec130[1] = vec130[1] - e4val * (f32)node10;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[4];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[6];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[5];
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 7;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048ec50);
#endif
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
/* Guarded native proof, 2026-09-29: 3408/3440 bytes;
 * 658 differing relocation-masked words. The 76-byte work record separates
 * control points, offsets, and scalar state; its length union preserves
 * hardware-Q bits without numeric conversion. Ordinary C cubic polynomials
 * generate native COP1 MACs. Genuine literal/global lifetimes recover the
 * retail 0x1e0 frame; input/control lanes are not given guessed initial values.
 * Instruction differences remain; production retains ASM. */
// FUN_0048F5F0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_0048f5f0(u8 *arg0)
{
    typedef struct BezierParticleWork {
        f32 control0[3];
        f32 control1[3];
        f32 control2[3];
        f32 offset[3];
        f32 rotationSpeed;
        f32 travelSpeed;
        union { s32 bits; f32 value; } length;
        f32 progress;
        f32 opacity;
        f32 spin;
        f32 scale;
    } BezierParticleWork;
    extern f32 cosf(f32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_004bd380(void *arg0, f32 arg1);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void memcpy(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8090;
    extern u8 D_00713D00[];
    u_long128 b220buf;
    f32 stack1A0[4] __attribute__((aligned(16)));
    f32 vecA[4] __attribute__((aligned(16)));
    f32 vecB[4] __attribute__((aligned(16)));
    f32 bez[4] __attribute__((aligned(16)));
    u8 tmp1C0[16] __attribute__((aligned(16)));
    u8 tmp170[16] __attribute__((aligned(16)));
    u8 tmp180[16] __attribute__((aligned(16)));
    f32 vecB2[4] __attribute__((aligned(16)));
    f32 quad110[4] __attribute__((aligned(16)));
    f32 coeff120[4] __attribute__((aligned(16)));
    f32 quad130[4] __attribute__((aligned(16)));
    f32 coeff140[4] __attribute__((aligned(16)));
    f32 save29;
    f32 save30;
    f32 stackDC;
    f32 half, two, orbitScale, hundred, one, zero, spinScale, negone, thousand, three;
    f32 vB;
    f32 ccB;
    f32 cc2B;
    f32 c3B;
    f32 vc2B;
    f32 b1B;
    f32 vvB;
    f32 cv2B;
    f32 b2B;
    f32 v3B;
    f32 o0B;
    f32 o1B;
    f32 o2B;
    f32 o3B;
    f32 o4B;
    f32 o5B;
    f32 p252B;
    f32 p256B;
    f32 p260B;
    f32 out13B;
    f32 out12B;
    f32 f1B;
    f32 f12B;
    u32 count;
    u8 *nodes;
    BezierParticleWork *out;
    u8 *config;
    u8 *const parent = arg0;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    s32 v15;
    s32 v14;
    u32 idx;
    s32 tmp;
    s32 tmp2;
    f32 ftmp1;
    f32 ftmp2;
    f32 ftmp3;
    s32 node10;
    s32 c0;
    s32 c4;
    s32 nmult;
    u8 *clear;
    s32 ci;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    count = *(u32 *)(parent + 4);
    nodes = *(u8 **)(parent + 24);
    out = *(BezierParticleWork **)(parent + 28);
    config = *(u8 **)(parent + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    save29 = *(f32 *)(config + 236);
    save30 = *(f32 *)(config + 248);
    stack1A0[0] = *(f32 *)(config + 252);
    stack1A0[1] = *(f32 *)(config + 256);
    stack1A0[2] = *(f32 *)(config + 260);
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(parent + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto post_init;
    }
    if ((*(s32 *)(parent + 16) == 0) && (*(u8 *)(config + 189) != 0)) {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = *(s32 *)(parent + 4);
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(parent + 4);
            ftmp2 = (f32)(u32)tmp;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto post_init;
    } else {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * effMiscRandFloat(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(parent + 20) = *(f32 *)(parent + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(parent + 20);
        ftmp1 = fabsf(ftmp1);
        v15 = (s32)ftmp1;
        *(f32 *)(parent + 20) = *(f32 *)(parent + 20) - (f32)v15;
        goto post_init;
    }
post_init:
    idx = 0;
    half = 0.5f;
    two = 2.0f;
    orbitScale = fGpffff8084;
    hundred = 100.0f;
    stackDC = fGpffff8090;
    one = 1.0f;
    zero = 0.0f;
    spinScale = fGpffff8080;
    negone = -1.0f;
    thousand = 1000.0f;
    three = 3.0f;
    goto main_check;
main_body:
    if (*(s32 *)(nodes + 16) < limitB8) {
        goto skip_clear;
    }
    if (saved20 == 0) {
        tmp = -1;
    } else {
        tmp = -2;
    }
    *(s32 *)(nodes + 16) = tmp;
    c0 = *(s32 *)(*(u8 **)(parent + 32) + 192);
    c4 = *(s32 *)(*(u8 **)(parent + 32) + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
        ci = 0;
        goto clear_check;
clear_body:
        *(s32 *)(clear + 16) = -1;
        clear += 32;
        ci += 1;
clear_check:
        if (ci < nmult) {
            goto clear_body;
        }
    }
skip_clear:
    node10 = *(s32 *)(nodes + 16);
    if (node10 == -2) {
        goto next_iter;
    }
    if (node10 != -1) {
        goto else_branch;
    }
    if (v15 == 0) {
        goto next_iter;
    }
    b = effMiscRandFloat(0);
    c = two * (b - half);
    {
        f32 arg8084 = orbitScale * c;
        a = *(f32 *)(config + 284) * cosf(arg8084);
        out->offset[0] = a;
        out->offset[1] = -*(f32 *)(config + 288);
        a = *(f32 *)(config + 284) * sinf(arg8084);
        out->offset[2] = a;
    }
    vecA[0] = *(f32 *)(config + 264) + out->offset[0];
    vecA[1] = *(f32 *)(config + 268) + out->offset[1];
    vecA[2] = *(f32 *)(config + 272) + out->offset[2];
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(stack1A0), "m"(*(u_long128 *)stack1A0) : "$vf12", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vecA), "m"(*(u_long128 *)vecA) : "$vf11", "memory");
    {
        s16 h200 = *(s16 *)(config + 200);
        f32 f200 = (f32)h200 / hundred;
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(f200) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vecB) : "r"(vecB) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    {
        s16 h212 = *(s16 *)(config + 212);
        f32 f212 = (f32)h212 / hundred;
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(f212) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vecB2) : "r"(vecB2) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vaddy.x $vf2, $vf2, $vf2y \n vaddz.x $vf2, $vf2, $vf2z \n" : : : "$vf2", "$vf10", "memory");
    __asm__ volatile("vsqrt $Q, $vf2x" : : : "$Q", "$vf2", "memory");
    __asm__ volatile("vwaitq" : : : "memory");
    __asm__ volatile("cfc2.ni %0, $vi22" : "=r"(tmp2) : : "memory");
    out->length.bits = tmp2;
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n" : : : "$vf2", "$vf10", "ACC", "Q", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp1C0) : "r"(tmp1C0) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12", "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(D_00713D00), "m"(*(u_long128 *)D_00713D00) : "$vf11", "memory");
    __asm__ volatile("vopmula.xyz $ACC, $vf10, $vf11 \n vopmsub.xyz $vf10, $vf11, $vf10 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
    __asm__ volatile("vopmula.xyz $ACC, $vf10, $vf11 \n vopmsub.xyz $vf10, $vf11, $vf10 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp180) : "r"(tmp180) : "$vf10", "memory");
    {
        s16 hE0 = *(s16 *)(config + 224);
        f32 fE0 = (f32)hE0;
        b = effMiscRandFloat(0);
        c = two * (b - half);
        fE0 = fE0 * c;
        ftmp1 = half * fE0;
        func_004bd380(tmp1C0, stackDC * ftmp1);
    }
    {
        ftmp1 = *(f32 *)(config + 208);
        b = effMiscRandFloat(0);
        {
            f32 blend208 = (one - ftmp1) + ftmp1 * b;
            f32 scale204 = *(f32 *)(config + 204) * blend208;
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(scale204) : "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecB), "m"(*(u_long128 *)vecB) : "$vf10", "memory");
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(tmp180), "m"(*(u_long128 *)tmp180) : "$vf12", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            out->control0[0] = ((f32 *)tmp170)[0];
            out->control0[1] = ((f32 *)tmp170)[1];
            out->control0[2] = ((f32 *)tmp170)[2];
        }
    }
    {
        ftmp1 = *(f32 *)(config + 220);
        b = effMiscRandFloat(0);
        {
            f32 blend220 = (one - ftmp1) + ftmp1 * b;
            f32 scale216 = *(f32 *)(config + 216) * blend220;
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(scale216) : "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecB2), "m"(*(u_long128 *)vecB2) : "$vf10", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            out->control1[0] = ((f32 *)tmp170)[0];
            out->control1[1] = ((f32 *)tmp170)[1];
            out->control1[2] = ((f32 *)tmp170)[2];
        }
    }
    ftmp1 = *(f32 *)(config + 244);
    b = effMiscRandFloat(0);
    out->travelSpeed = *(f32 *)(config + 240) * ((one - ftmp1) + ftmp1 * b);
    ftmp1 = *(f32 *)(config + 232);
    b = effMiscRandFloat(0);
    out->rotationSpeed = *(f32 *)(config + 228) * ((one - ftmp1) + ftmp1 * b);
    out->progress = zero;
    *(u_long128 *)nodes = *(u_long128 *)stack1A0;
    ftmp1 = *(f32 *)(config + 108);
    b = effMiscRandFloat(0);
    out->opacity = (one - ftmp1) + ftmp1 * b;
    if (mode9C == 2) {
        out->spin = zero;
        out->scale = one;
    } else {
        ftmp1 = *(f32 *)(config + 152);
        b = effMiscRandFloat(0);
        out->scale = (one - ftmp1) + ftmp1 * b;
        if (mode9C == 1) {
            b = effMiscRandFloat(0);
            out->spin = spinScale * b;
            if ((effMiscRand(0) & 1) != 0) {
                out->scale = out->scale * negone;
            }
        } else {
            out->spin = zero;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = (u32)effMiscRand(0) % (u32)limitB8;
        ftmp1 = (f32)(u32)tmp;
        out13B = out->travelSpeed;
        out12B = out->rotationSpeed;
        ftmp2 = half * (save30 * ftmp1 * ftmp1) + out13B * ftmp1;
        ftmp3 = half * (save29 * ftmp1 * ftmp1) + out12B * ftmp1;
        if (ftmp2 < zero) {
            ftmp2 = zero;
        }
        if (ftmp3 < zero) {
            ftmp3 = zero;
        }
        d = ftmp2;
        c = ftmp3;
        ftmp2 = d / thousand;
        if (ftmp2 > one) {
            ftmp2 = one;
        }
        if (out->progress > ftmp2) {
            ftmp2 = out->progress;
        } else {
            out->progress = ftmp2;
        }
        bez[0] = vecA[0];
        bez[1] = vecA[1];
        bez[2] = vecA[2];
        vB = ftmp2;
        ccB = one - vB;
        cc2B = ccB * ccB;
        c3B = ccB * cc2B;
        coeff140[0] = c3B;
        vc2B = vB * cc2B;
        b1B = three * vc2B;
        coeff140[1] = b1B;
        vvB = vB * vB;
        cv2B = ccB * vvB;
        b2B = three * cv2B;
        coeff140[2] = b2B;
        v3B = vB * vvB;
        coeff140[3] = v3B;
        o0B = out->control0[0];
        o3B = out->control1[0];
        p252B = *(f32 *)(config + 252);
        quad130[0] = bez[0] * coeff140[3] +
            (p252B * coeff140[0] + o0B * coeff140[1] +
             o3B * coeff140[2]);
        o1B = out->control0[1];
        o4B = out->control1[1];
        p256B = *(f32 *)(config + 256);
        quad130[1] = bez[1] * coeff140[3] +
            (p256B * coeff140[0] + o1B * coeff140[1] +
             o4B * coeff140[2]);
        o2B = out->control0[2];
        o5B = out->control1[2];
        p260B = *(f32 *)(config + 260);
        quad130[2] = bez[2] * coeff140[3] +
            (p260B * coeff140[0] + o2B * coeff140[1] +
             o5B * coeff140[2]);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(quad130), "m"(*(u_long128 *)quad130) : "$vf10", "memory");
        if (ftmp3 != zero) {
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            func_004bd380(tmp1C0, ftmp3);
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp1C0), "m"(*(u_long128 *)tmp1C0) : "$vf11", "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(out->length.value * ftmp2) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out->opacity;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out->scale;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out->spin;
    if (v14 != 0) {
        nmult = *(s32 *)(*(u8 **)(parent + 32) + 192) * *(s32 *)(*(u8 **)(parent + 32) + 196);
        if (nmult != 0) {
            clear = *(u8 **)(parent + 24) + 32 * (*(s32 *)(parent + 4) + (s32)((u32)(nodes - *(u8 **)(parent + 24)) / 32) * nmult);
            memcpy(clear, nodes, 32);
            *(s32 *)(clear + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    {
        f32 nf = (f32)node10;
        f1B = half * (save30 * nf * nf) + out->travelSpeed * nf;
        f12B = half * (save29 * nf * nf) + out->rotationSpeed * nf;
        if (f1B < zero) {
            f1B = zero;
        }
        if (f12B < zero) {
            f12B = zero;
        }
        c = f1B / thousand;
        if (c > one) {
            c = one;
        }
        ftmp2 = out->progress;
        if (ftmp2 > c) {
            c = ftmp2;
        } else {
            out->progress = c;
        }
    }
    bez[0] = *(f32 *)(config + 264) + out->offset[0];
    bez[1] = *(f32 *)(config + 268) + out->offset[1];
    bez[2] = *(f32 *)(config + 272) + out->offset[2];
    vB = c;
    ccB = one - vB;
    cc2B = ccB * ccB;
    c3B = ccB * cc2B;
    coeff120[0] = c3B;
    vc2B = vB * cc2B;
    b1B = three * vc2B;
    coeff120[1] = b1B;
    vvB = vB * vB;
    cv2B = ccB * vvB;
    b2B = three * cv2B;
    coeff120[2] = b2B;
    v3B = vB * vvB;
    coeff120[3] = v3B;
    o0B = out->control0[0];
    o3B = out->control1[0];
    p252B = *(f32 *)(config + 252);
    quad110[0] = bez[0] * coeff120[3] +
        (p252B * coeff120[0] + o0B * coeff120[1] +
         o3B * coeff120[2]);
    o1B = out->control0[1];
    o4B = out->control1[1];
    p256B = *(f32 *)(config + 256);
    quad110[1] = bez[1] * coeff120[3] +
        (p256B * coeff120[0] + o1B * coeff120[1] +
         o4B * coeff120[2]);
    o2B = out->control0[2];
    o5B = out->control1[2];
    p260B = *(f32 *)(config + 260);
    quad110[2] = bez[2] * coeff120[3] +
        (p260B * coeff120[0] + o2B * coeff120[1] +
         o5B * coeff120[2]);
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(quad110), "m"(*(u_long128 *)quad110) : "$vf10", "memory");
    if (f12B != zero) {
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
        vecA[0] = out->control2[0];
        vecA[1] = out->control2[1];
        vecA[2] = out->control2[2];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(stack1A0), "m"(*(u_long128 *)stack1A0) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vecA), "m"(*(u_long128 *)vecA) : "$vf11", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n sqc2 $vf10, 0(%0) \n" : : "r"(tmp1C0) : "$vf2", "$vf10", "$vf11", "ACC", "Q", "memory");
        func_004bd380(tmp1C0, f12B);
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp1C0), "m"(*(u_long128 *)tmp1C0) : "$vf11", "memory");
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(out->length.value * c) : "$vf2", "memory");
        __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out->opacity;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out->scale;
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out->spin;
    func_0048b340(parent, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 1;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}

#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048f5f0);
#endif
