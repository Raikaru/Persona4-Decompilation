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
extern s32 func_003c2150(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 *func_003c2290(u8 *arg0, s32 arg1);
extern u8 *func_003c22f0(u8 *arg0);
extern u8 *func_00483a00(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00481390(s32 arg0);
extern void func_003ef3a0(void *arg0);
extern void func_0046d730(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void func_00485630(u8 *arg0);
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

    func_003c2290(temp_19, 1);

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

    func_0043f9c8(state, 0, sizeof(*state));
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
/* Decode 00484bb0 (window 2688B=672w, gate 2607-2769B/651-692w; frame 0xF0=240B; s32(u32) single-arg, returns s32 resource (alloc pointer as int; callers in btlCutin/btlFormation/effHelper store as s32/u32)). Retail calls in order: 44ea90, jtbl alloc 144/192/44, 43f9c8, 84b30, lq/sq GPR quad copies, 86740/867e0/86780/86710, 442830, then 861f0/86330/86400/865c0 sequence. Single VU op: sqc2 vf0,0(sp+0xE0) to init the 861f0/86330 quad param as (0,0,0,1.0), never zero quad (W=1). No GP floats via $28, no (f32)(u32) sites, no normalize. Integer list build with 0xC0=192 stride per child, 0x80/0x84 counters, 0x88/0x8C/0xB0 links. Template: Code48InitialState-style typed state + one u_long128 (aligned16) for the vf0 quad only (extra slot costs 0x10 frame), single asm block `sqc2 vf0,0(%0)` with compiler address + =m + memory (vf0 needs no clobber, follow 84b30 idiom), all allocation/traversal/callbacks/reloads/scalar arithmetic in C. Expect obj ~672w; outside 3% stays INCLUDE_ASM with factual note. Production stays ASM. Do NOT touch 85870/8a980 per assignment. */
/* measured: GUARDED_SCORE 187 via probe_variants (v1 408, v5 187 best; prop off 187 vs on 594 load-bearing; loopinv/sched tie 187 kept simpler; common off 581 worse; decl swaps tie kept original; >0x20 190 worse kept >=0x21; frame 0xF0 exact; fnalign 670/670 exact, 197 edits +76 reloc-only; biggest remaining saved-reg rotation + branch/scheduling; no daddu 28 (no $28 floats per decode) and no VU colours (single vf0 op); callees/globals reused from tree: 44ea90/46d730/43f9c8/jtbl_008873E8/D_00713470/D_00713480 via top decls, 84b30/861f0/86330/86400/865c0/86710 via same TU, 86740/867e0/86780 via mdlEffect/same TU, 442830 strcpy; template Code48InitialState quads + single vf0 u_long128 as decode). Retail 672w/obj 670w (-2 -0.3% inside gate 651-692). Production stays ASM. */
// FUN_00484BB0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
u8 *func_00484bb0(u8 *arg0)
{
    extern s32 func_004861f0(u8 *arg0, f32 *arg1);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    extern void func_00486400(u8 *arg0, f32 arg1);
    extern void func_004865c0(u8 *arg0, s32 arg1);
    extern void func_00486710(u8 *arg0, u8 *arg1);
    extern void func_00442830(u8 *arg0, u8 *arg1);
    u8 *func_00486740(u8 *arg0, s32 arg1);
    s32 func_004867e0(u8 *arg0, u8 *arg1);
    u8 *func_00486780(u8 *arg0, s32 arg1);
    u_long128 vf0quad;
    void *(**alloc)(u32, u32);
    u8 *clone;
    u8 *node;
    u8 *nodeClone;
    u8 *src;
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
    func_0044ea90(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    clone = (u8 *)alloc[0](0x90, 0x40000);
    if (clone == NULL) {
        func_0046d730(D_00713470, 0x547);
    }
    func_0043f9c8(clone, 0, 0x90);
    *(s32 *)(clone + 0x80) = 0;
    *(s32 *)(clone + 0x84) = 0;
    func_00484b30(clone);
    *(u_long128 *)clone = *(u_long128 *)arg0;
    *(u_long128 *)(clone + 0x10) = *(u_long128 *)(arg0 + 0x10);
    *(f32 *)(clone + 0x74) = *(f32 *)(arg0 + 0x74);
    *(s32 *)(clone + 0x68) = *(s32 *)(arg0 + 0x68);
    if (*(u8 **)(arg0 + 0x8C) != NULL) {
        for (node = *(u8 **)(arg0 + 0x8C); node != NULL; node = *(u8 **)(node + 0xAC)) {
            func_0044ea90(D_00713470, 0x559);
            nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
            if (nodeClone == NULL) {
                func_0046d730(D_00713470, 0x55A);
            }
            func_0043f9c8(nodeClone, 0, 0xC0);
            func_0043f9c8(nodeClone, 0, 0x90);
            *(s32 *)(nodeClone + 0x84) = 1;
            *(u8 *)(nodeClone + 0x88) = 8;
            *(u8 *)(nodeClone + 0x89) = 0;
            *(u8 *)(nodeClone + 0x8A) = 0;
            func_00484b30(nodeClone);
            if ((*(s32 *)(node + 0x98) & 1) == 0) {
                src = *(u8 **)(node + 0x90);
                if (*(u32 *)src > 0xD2) {
                    func_0046d730(D_00713470, 0x2D7);
                }
                kind = *(u16 *)(src + 4);
                func_0044ea90(D_00713470, 0x21);
                prim = (u8 *)alloc[0](0x2C, 0x40000);
                if (prim == NULL) {
                    func_0046d730(D_00713470, 0x22);
                }
                func_0043f9c8(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                *(u16 *)(prim + 4) = kind;
                *(u16 *)(prim + 0xC) = *(u16 *)(src + 0xC);
                *(u16 *)(prim + 0x1C) = *(u16 *)(src + 0x1C);
                if (*(u16 *)(prim + 4) >= 0x21) {
                    func_0046d730(D_00713470, 0x2DD);
                }
                if (*(s32 *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == 0) {
                    func_0046d730(D_00713470, 0x2DE);
                }
                *(s32 *)(prim + 8) =
                    (*(s32 (**)(u8 *))(D_00713480 + (*(u16 *)(prim + 4) << 6)))(src);
                *(u8 **)(nodeClone + 0x90) = prim;
            } else {
                found = func_00486740(arg0, *(s32 *)(node + 0x90));
                idx = func_004867e0(arg0, found);
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
                func_0043f9c8(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                *(u16 *)(prim + 4) = kind;
                *(u16 *)(prim + 0xC) = *(u16 *)(csrc + 0xC);
                *(u16 *)(prim + 0x1C) = *(u16 *)(csrc + 0x1C);
                if (*(s32 *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == 0) {
                    func_0046d730(D_00713470, 0x321);
                }
                *(s32 *)(prim + 8) =
                    (*(s32 (**)(s32))(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(s32 *)(csrc + 8));
                *(u8 **)(nodeClone + 0x90) = prim;
            }
            func_00486710(nodeClone, node);
            func_00442830(nodeClone + 0x9C, node + 0x9C);
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
        count = *(s32 *)(arg0 + 0x80);
        base = arg0 + *(s32 *)(arg0 + 0x88);
        cur = base;
        i = 0;
        goto indexed_check;
indexed_body:
        func_0044ea90(D_00713470, 0x559);
        nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
        if (nodeClone == NULL) {
            func_0046d730(D_00713470, 0x55A);
        }
        func_0043f9c8(nodeClone, 0, 0xC0);
        func_0043f9c8(nodeClone, 0, 0x90);
        *(s32 *)(nodeClone + 0x84) = 1;
        *(u8 *)(nodeClone + 0x88) = 8;
        *(u8 *)(nodeClone + 0x89) = 0;
        *(u8 *)(nodeClone + 0x8A) = 0;
        func_00484b30(nodeClone);
        tmp = *(s32 *)(cur + 0x98);
        if ((tmp & 1) == 0) {
            src = arg0 + *(s32 *)(cur + 0x90);
            if ((tmp & 2) != 0) {
                addr24 = src + 0x24;
                if (*(s32 *)addr24 != 0) {
                    func_0046d730(D_00713470, 0x5BB);
                }
                addr20 = src + 0x20;
                if (*(s32 *)addr20 != 0) {
                    func_0046d730(D_00713470, 0x5BC);
                }
                idx94 = *(s32 *)(cur + 0x94);
                slot = base + idx94 * 0xC0;
                target = arg0 + *(s32 *)(slot + 0x90);
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
                *(s32 *)addr20 = (s32)(var2 - src);
                if (*(u32 *)src > 0xD2) {
                    func_0046d730(D_00713470, 0x2D7);
                }
                kind = *(u16 *)(src + 4);
                func_0044ea90(D_00713470, 0x21);
                prim = (u8 *)alloc[0](0x2C, 0x40000);
                if (prim == NULL) {
                    func_0046d730(D_00713470, 0x22);
                }
                func_0043f9c8(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                *(u16 *)(prim + 4) = kind;
                *(u16 *)(prim + 0xC) = *(u16 *)(src + 0xC);
                *(u16 *)(prim + 0x1C) = *(u16 *)(src + 0x1C);
                if (*(u16 *)(prim + 4) >= 0x21) {
                    func_0046d730(D_00713470, 0x2DD);
                }
                if (*(s32 *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == 0) {
                    func_0046d730(D_00713470, 0x2DE);
                }
                *(s32 *)(prim + 8) =
                    (*(s32 (**)(u8 *))(D_00713480 + (*(u16 *)(prim + 4) << 6)))(src);
                *(u8 **)(nodeClone + 0x90) = prim;
                *(s32 *)addr24 = 0;
                *(s32 *)addr20 = 0;
            } else {
                if (*(u32 *)src > 0xD2) {
                    func_0046d730(D_00713470, 0x2D7);
                }
                kind = *(u16 *)(src + 4);
                func_0044ea90(D_00713470, 0x21);
                prim = (u8 *)alloc[0](0x2C, 0x40000);
                if (prim == NULL) {
                    func_0046d730(D_00713470, 0x22);
                }
                func_0043f9c8(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                *(u16 *)(prim + 4) = kind;
                *(u16 *)(prim + 0xC) = *(u16 *)(src + 0xC);
                *(u16 *)(prim + 0x1C) = *(u16 *)(src + 0x1C);
                if (*(u16 *)(prim + 4) >= 0x21) {
                    func_0046d730(D_00713470, 0x2DD);
                }
                if (*(s32 *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == 0) {
                    func_0046d730(D_00713470, 0x2DE);
                }
                *(s32 *)(prim + 8) =
                    (*(s32 (**)(u8 *))(D_00713480 + (*(u16 *)(prim + 4) << 6)))(src);
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
            func_0043f9c8(prim, 0, 0x2C);
            *(s32 *)prim = 0xD2;
            *(u16 *)(prim + 4) = kind;
            *(u16 *)(prim + 0xC) = *(u16 *)(csrc + 0xC);
            *(u16 *)(prim + 0x1C) = *(u16 *)(csrc + 0x1C);
            if (*(s32 *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == 0) {
                func_0046d730(D_00713470, 0x321);
            }
            *(s32 *)(prim + 8) =
                (*(s32 (**)(s32))(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(s32 *)(csrc + 8));
            *(u8 **)(nodeClone + 0x90) = prim;
        }
        func_00486710(nodeClone, cur);
        func_00442830(nodeClone + 0x9C, cur + 0x9C);
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
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(&vf0quad) : "memory");
    func_004861f0(clone, (f32 *)&vf0quad);
    func_00486330(clone, (u8 *)&vf0quad);
    func_00486400(clone, 1.0f);
    func_004865c0(clone, -1);
    return clone;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00484bb0);
#endif
/* Floor: 140 emitted against retail's 140, with three real deltas and one
   consequent nop; everything else is byte-identical once the relocations are
   masked.  The reconstruction follows its sibling func_00485870 below, with
   the differences retail shows: no `count <= 0` early-out, the child test
   uses the raw `*(s32 *)(arg0 + 0x84)` rather than count - 1, there is no
   `flags & 0x80000000` arm in the loop, the final per-child callback is at
   table offset 0x08 rather than 0x0C, and the tail sets the 0x80000000 bit
   and bumps the 0x84 counter.  The four quadword slots are separate locals,
   which is what puts the frame at retail's 0x90: merging the func_00486840
   output with the save slot costs a slot and 0x10 of frame.
   WALL: retail rematerialises `addiu $vN, $sp, 0x50` on both sides of the
   func_00486970/func_00486330 pair (`$v1` for the save, `$v0` for the
   restore); b210 hoists that address into `$s0` and keeps it live across
   both calls, which is one instruction shorter and shifts everything after
   it.  Measured and rejected: a single `u_long128 *` local (this body, the
   shortest), two pointer locals in disjoint scopes, a `u8 *` pair, direct
   `*(u_long128 *)sp50` on both sides (folds to `sq 0x50($sp)`, two
   instructions short), a `u_long128` value local, a `struct { u_long128 }`
   and a `struct { s32[4] }` wrapper, and opt_common_subs / opt_propagation /
   opt_lifetimes / opt_dead_assignments / schedule off both function-wide and
   scoped to the block.  The declaration of func_00485630 above carries the
   real `u8 *` parameter that retail passes in $a0; func_00485ae0's call site
   was updated to pass it and still matches. */
/* 2026-09-18 probe; floor stands at 13.  Retail recomputes `addiu $v1, $sp,
   0x50` at each use where this body keeps the save-slot address in $s0, so
   the obvious fix is the one that works on the sibling func_00485870 three
   hundred lines up - assign `save_slot` twice, once before the calls and
   once before the restore.  It does not transfer: the double assignment
   costs 13 -> 112 here, the trailing-assignment-only form 112, and dropping
   the pointer entirely for `*(u_long128 *)sp50` 118.
   The two functions are near-identical in shape and want opposite spellings,
   so do not copy this idiom between them without measuring.  The remaining
   rows are `bbit032`/`bbit132` branch-target lines, which are capstone
   mis-decodes of relocated words rather than real differences. */
// FUN_00485630 NONMATCHING
#ifdef NON_MATCHING
void func_00485630(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    u_long128 spA0;
    u_long128 sp70;
    u_long128 sp60;
    u8 sp50[16] __attribute__((aligned(16)));
    f32 scale;
    f32 five;
    u8 *child;
    s32 count;
    u8 *temp_4;
    void (*temp_2)(s32, void *);
    void (*temp_3)(s32, void *);
    void (*temp_4fn)(s32);
    s32 child_flags;

    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
    if ((*(s32 *)(arg0 + 0x68) & 0x60) != 0) {
        u_long128 *save_slot = (u_long128 *)sp50;
        *save_slot = *(u_long128 *)(arg0 + 0x50);
        func_00486970(arg0, (u8 *)&spA0, &sp60);
        func_00486330(arg0, (u8 *)&sp60);
        *(u_long128 *)(arg0 + 0x50) = *save_slot;
    }
    count = *(s32 *)(arg0 + 0x84);
    scale = *(f32 *)(arg0 + 0x60) * *(f32 *)(arg0 + 0x74);
    child = *(u8 **)(arg0 + 0x8C);
    five = 5.0f;
    goto loop_00485630_check;
loop_00485630_body:
    if (count < *(s32 *)(child + 0x80)) {
        goto loop_00485630_next;
    }
    if ((*(s32 *)(child + 0x84) & 2) != 0) {
        goto loop_00485630_next;
    }
    if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
        func_00486840(child, (u8 *)&spA0, &sp70);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
        child_flags = *(s32 *)(child + 0x68);
        if ((child_flags & 4) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vaddx.y $vf10, $vf0, $vf2x \n"
                :
                : "f"(five)
                : "$2", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&sp70) : "$vf11", "memory");
        if ((child_flags & 0x80) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                :
                : "f"(scale)
                : "$2", "$vf2", "$vf11", "memory");
        }
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp70) : "$vf10", "memory");
        temp_4 = *(u8 **)(child + 0x90);
        temp_2 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
        if (temp_2 != NULL) {
            temp_2(*(s32 *)(temp_4 + 8), &sp70);
        }
    }
    if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
        func_00486970(child, (u8 *)&spA0, &sp60);
        temp_4 = *(u8 **)(child + 0x90);
        temp_3 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x24);
        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_4 + 8), &sp60);
        }
    }
    temp_4 = *(u8 **)(child + 0x90);
    temp_4fn = *(void (**)(s32))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x08);
    temp_4fn(*(s32 *)(temp_4 + 8));
loop_00485630_next:
    child = *(u8 **)(child + 0xAC);
loop_00485630_check:
    if (child != NULL) {
        goto loop_00485630_body;
    }
    *(s32 *)(arg0 + 0x68) |= 0x80000000;
    *(s32 *)(arg0 + 0x84) += 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485630);
#endif
/* 2026-09-18 re-probe; floor stands at 10.  Six of the alignment rows are
   `bbit032`/`bbit132` branch-target lines, which are capstone mis-decodes of
   relocated words rather than real differences.  The one real row is an
   extra `addiu $s0, $s4, 0x50`: this body materialises the save-slot address
   where retail addresses the quadword directly.  Every way of removing the
   pointer is far worse - storing through `*(u_long128 *)sp70` inline 120, a
   plain `u_long128 saved` local 125, and assigning `save_slot` once instead
   of twice 120.  The redundant-looking second `save_slot = (u_long128 *)sp70`
   is load bearing: it is what keeps the address out of a saved register
   across the two calls. */
// FUN_00485870 NONMATCHING
#ifdef SKIP_ASM
/* measured: 616B obj vs 624B window, 11 differing words reloc-masked (probe cand4).
 * Baseline PoB archive nd388; cleaned honest-C cand1 125; u8[16] save slot for
 * stack (frame 0xA0->0xB0 fixed) cand2 120; scoped dst/src temps cand3 120;
 * shared save_slot live across (u_long128 *save_slot = (u_long128 *)sp70) cand4 11.
 * Parent loop_invariants lever measured 11->11 neutral (genuinely OFF at -O2, omitted
 * to avoid H003 warn); struct-field restore 120 (worse); u_long128[1] save slot 120
 * (worse); u8* signature COMPILE ERROR against extern s32 (confirms s32 correct, keeps
 * caller 85ae0 MATCH with no change). Trailing out-params already bare (&sp80/&sp90 as
 * u_long128*, no casts) so second parent lever (delete trailing cast) already optimal.
 * Conventions copied from MATCHed neighbours: u_long128 quads + lqc2/sqc2/vadd/vmulx/
 * qmtc2/mfc1+nop VU idioms verbatim from 861f0/86400; goto loop_check + D_00713480 +
 * (kind<<6)+off table + !=NULL guards from 86060/860f0; s32 arg0 with (u8*) casts per
 * 81d80 s32-as-pointer file convention.
 * Residual wall (save/restore quad copy, off 104-152): retail materialises stack slot
 * sp+0x70 twice with volatiles (addiu $v1,sp,0x70 + lq/sq 0($v1) for save, addiu
 * $v0,sp,0x70 + lq 0($v0) for restore, arg accesses direct 80($s4)), while honest C
 * with shared save_slot gives saved $s1 shared (1 addiu, not 2) plus extra arg pointer
 * addiu $s0,$s4,0x50 for restore store via sq 0($s0) vs direct 80($s4). Single-use
 * short-lived GPR quad pointer form (addiu+0-disp with volatile) folds to sp+OFF direct
 * in every honest spelling tried (array, struct-field, pointer-temp, volatile array,
 * opt_propagation/common_subs/loop_invariants); double DATA use in one block forces it
 * (micro12: p[0],p[1] -> addiu $a1,sp + 0/16-disp with volatile) but save/restore each
 * single-use; "" : "+r"(p) barrier gives retail form (micro10) but H002-banned.
 * Pointer-temp vs direct-index wall per handoff 7a (both forms same function).
 * Re-measured 2026-09-17: banked 11 holds (obj 616B/window 624B, fnalign 154/154/12+6reloc,
 * earliest hunk off 104-152 save/restore wall). Eight-pragma sweep: loop_invariants on 11,
 * strength_reduction off 11, unroll off 11, dead_assignments off 19, propagation off 19,
 * peephole off 80, common_subs off 129, schedule on 138. Earliest-hunk variants re-probed:
 * direct-indexed 120, value-local 125. Each stack slot stays its own u_long128 local
 * (spA0/sp90/sp80 + sp70 save, one asm block per lqc2/sqc2/vadd/vmulx/qmtc2 transfer per
 * 861f0/86400 idiom); opclass no surplus for this floor. Banked as guarded floor. */
void func_00485870(s32 arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void func_00486330(u8 *arg0, u8 *arg1);
    u_long128 spA0;
    u_long128 sp90;
    u_long128 sp80;
    u8 sp70[16] __attribute__((aligned(16)));
    f32 scale;
    f32 five;
    u8 *child;
    s32 flags;
    s32 count_minus_1;
    u32 mask;
    u8 *temp_4;
    void (*temp_2)(s32, void *);
    void (*temp_3)(s32, void *);
    void (*temp_4fn)(s32);
    s32 child_flags;

    if (*(s32 *)((u8 *)arg0 + 0x84) <= 0) {
        return;
    }
    flags = *(s32 *)((u8 *)arg0 + 0x68);
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"((u8 *)arg0) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"((u8 *)arg0) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
    if ((flags & 0x60) != 0) {
        if ((flags & 0x80000000) == 0) {
            u_long128 *save_slot = (u_long128 *)0;

            save_slot = (u_long128 *)sp70;
            *save_slot = *(u_long128 *)((u8 *)arg0 + 0x50);
            func_00486970((u8 *)arg0, (u8 *)&spA0, &sp80);
            func_00486330((u8 *)arg0, (u8 *)&sp80);
            save_slot = (u_long128 *)sp70;
            *(u_long128 *)((u8 *)arg0 + 0x50) = *save_slot;
        }
    }
    count_minus_1 = *(s32 *)((u8 *)arg0 + 0x84) - 1;
    scale = *(f32 *)((u8 *)arg0 + 0x60) * *(f32 *)((u8 *)arg0 + 0x74);
    child = *(u8 **)((u8 *)arg0 + 0x8C);
    mask = 0x80000000;
    five = 5.0f;
    goto loop_00485870_check;
loop_00485870_body:
    if (count_minus_1 < *(s32 *)(child + 0x80)) {
        goto loop_00485870_next;
    }
    if ((*(s32 *)(child + 0x84) & 2) != 0) {
        goto loop_00485870_next;
    }
    if ((flags & mask) != 0) {
        goto callback_0c;
    }
    if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
        func_00486840(child, (u8 *)&spA0, &sp90);
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&spA0) : "$vf10", "memory");
        child_flags = *(s32 *)(child + 0x68);
        if ((child_flags & 4) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vaddx.y $vf10, $vf0, $vf2x \n"
                :
                : "f"(five)
                : "$2", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&sp90) : "$vf11", "memory");
        if ((child_flags & 0x80) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                :
                : "f"(scale)
                : "$2", "$vf2", "$vf11", "memory");
        }
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&sp90) : "$vf10", "memory");
        temp_4 = *(u8 **)(child + 0x90);
        temp_2 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x20);
        if (temp_2 != NULL) {
            temp_2(*(s32 *)(temp_4 + 8), &sp90);
        }
    }
    if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
        func_00486970(child, (u8 *)&spA0, &sp80);
        temp_4 = *(u8 **)(child + 0x90);
        temp_3 = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x24);
        if (temp_3 != NULL) {
            temp_3(*(s32 *)(temp_4 + 8), &sp80);
        }
    }
callback_0c:
    temp_4 = *(u8 **)(child + 0x90);
    temp_4fn = *(void (**)(s32))(D_00713480 + (*(u16 *)(temp_4 + 4) << 6) + 0x0C);
    temp_4fn(*(s32 *)(temp_4 + 8));
loop_00485870_next:
    child = *(u8 **)(child + 0xAC);
loop_00485870_check:
    if (child != NULL) {
        goto loop_00485870_body;
    }
    {
        u32 v = *(u32 *)((u8 *)arg0 + 0x68);
        *(u32 *)((u8 *)arg0 + 0x68) = v & 0x7fffffffU;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_00485870);
#endif
// FUN_00485AE0
void func_00485ae0(s32 arg0)
{
    func_00485630((u8 *)arg0);
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
extern void func_00486330(u8 *arg0, u8 *arg1);
extern void func_00486710(u8 *arg0, u8 *arg1);
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
    func_0043f9c8(clone, 0, 0x90);
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
        func_0043f9c8(nodeClone, 0, 0xC0);
        func_0043f9c8(nodeClone, 0, 0x90);
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
        func_0043f9c8(prim, 0, 0x2C);
        *(s32 *)prim = 0xD2;
        *(u16 *)(prim + 4) = kind;
        *(u16 *)(prim + 0xC) = *(u16 *)(src + 0xC);
        *(u16 *)(prim + 0x1C) = *(u16 *)(src + 0x1C);
        if (*(s32 *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == 0) {
            func_0046d730(D_00713470, 0x321);
        }
        *(s32 *)(prim + 8) =
            (*(s32 (**)(s32))(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(s32 *)(src + 8));
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
/* Floor (measured 2026-09-17, source-repo only): probe_variants base 5 words (v2_retail 7, v1_ghidra 110, v4/v5 7, v6 50, v7 s8 99, v8 struct3 142, v9 doubledef neutral), fnalign 146/146/6, emitted 584B/window 592B (98.6%). Four-pragma sweep on best: base wins (loop/sched neutral, prop/common worse). wscan 0, opclass N/A (no guard). Residual is FPR destination selection (cvt.w.s/mfc1 colors + branch); recorded cvt wall re-derived and rejected as shared-wall claim (same shape as 00311930/0034ddf0 but per-function levers differ). Banked as guarded floor; production stays ASM.
 * Re-measured 2026-09-17: still 5 words (obj 584B/window 592B, fnalign 146/146/6); residual is mtc1 f1-vs-f3, add f1-vs-f3, sqrt f2-vs-f1, mul f2-vs-f1, swc1 f1-vs-f3 plus one branch-cascade bbit; 36-config pragma sweep skipped per parent (00311930 proven byte-identical across all configs, so cvt.w.s destinations banked, not re-proven). */
/* measured 0048a980 (pragma exhaustion): all eight cheap pragmas and all
   twenty-eight pairs via `tools/pragma_sweep.py --pairs`; ten configurations
   tie the banked 5 and every other is 96 or worse, so nothing moves it.
   WALL, 4 real words at an exact 146/146 (the fifth fnalign row is a
   bbit032 branch-target artefact, not a code difference): retail keeps the
   1.0f addend in $f1 and puts the sqrt result in $f2, while b210 uses $f3
   for the constant and $f1 for the root - the long-lived value gets the
   higher register here and the lower one in retail.  Measured and rejected:
   inlining the 1.0f at both its uses, giving it a dedicated local declared
   first, the same declared last, and a dedicated local for the sqrt result;
   all four tie at 5. */
/* 2026-09-18 lead pass, 5 more measured variants on top of the permuter's
   9731 compiles; floor confirmed at 5 words.  146/146 instructions, and the
   residual is an FP temporary rotation around the second `sqrtf`: retail
   holds the 1.0f in $f1 and the square root in $f2, this body uses $f3 and
   $f1.  (The sixth fnalign row is a capstone mis-decode of the relocated
   `bbit032` branch word, not a real difference.)
   Reusing `temp_f1` for that 1.0f is load-bearing: giving the constant its
   own local costs 5 -> 7, and inlining it into the add costs the same.
   Inlining the 2.0f, swapping the `temp_f2_2`/`temp_f2_3` declarations and
   padding the float declaration list all tie at 5 with a byte-identical
   stream.  FP temp numbering here follows the count of live float values,
   which no source shape tried changes without changing the stream. */
/* 2026-09-18, handoff 7o re-probe; floor stands at 5.  146/146 instructions
   and the residual is an FPR pair, not a GPR one: retail holds the 1.0f in
   $f1 and the sqrt result in $f2, this body has them $f3 and $f1.  The 7o
   lever does not reach floating-point colouring here - declaring the sqrt
   temporary first among the float locals ties at 5, declaring it before
   `temp_f0` ties at 5, reusing `temp_f2_2` for the sqrt result instead of a
   fresh temporary ties at 5, and giving the difference chain its own
   temporary so the 1.0f stays live across it ties at 5.  One of the six
   fnalign rows is a `bbit032` branch-target line, which is a capstone
   mis-decode of a relocated word, not a real difference. */
// FUN_0048A980 NONMATCHING
#ifdef NON_MATCHING
/* Best re-derived body for func_0048a980: 5 differing words (reloc-masked),
   146/146 instrs, 6 fnalign edits. Plain C + terminal lqc2 per VU handoff.
   Terminal transfer is C-shaping target; no interior VU pipeline.
   Owner TU supplies code1_0048_mul; add helper retained for standalone replay. */
static inline f32 code1_0048_add(f32 left, f32 right) {
    return left + right;
}

void func_0048a980(f32 *arg0)
{
    extern f32 sqrtf(f32 arg0);
    f32 sp[4];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f5;
    f32 temp_f2_3;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_3;
    s32 temp_5;
    s32 temp_6;
    s32 temp_7;
    s32 temp_8;
    u8 var_6;
    s32 var_3;
    u8 *temp_5_2;
    u8 *temp_7_2;
    u8 *temp_9;
    u8 next2;
    s32 temp_10;

    temp_f3 = arg0[5];
    temp_f2 = arg0[0];
    temp_f4 = arg0[10];
    temp_f1 = 1.0f;
    temp_f0 = temp_f2 + temp_f3;
    temp_f0 = code1_0048_add(temp_f4, temp_f0);
    temp_f0 = code1_0048_add(temp_f1, temp_f0);
    if (!(temp_f0 < temp_f1)) {
        temp_f2_2 = 2.0f * sqrtf(temp_f0);
        sp[3] = -(temp_f2_2 / 4.0f);
        sp[0] = (arg0[6] - arg0[9]) / temp_f2_2;
        sp[1] = (arg0[8] - arg0[2]) / temp_f2_2;
        sp[2] = (arg0[1] - arg0[4]) / temp_f2_2;
    } else {
        var_3 = (temp_f2 > temp_f3) ? 1 : 0;
        var_6 = (var_3 ^ 1) & 0xFF;
        if (!(temp_f4 <= *(f32 *)((u8 *)arg0 + (var_6 * 0x10) +
                                  (var_6 * 4)))) {
            var_6 = 2;
        }
        temp_7 = var_6 & 0xFF;
        temp_5 = ((s32)(temp_7 + 1) % 3) & 0xFF;
        temp_10 = (s32)(temp_5 + 1) % 3;
        next2 = temp_10 & 0xFF;
        temp_3 = temp_5 * 4;
        temp_9 = (u8 *)arg0 + (temp_5 * 0x10);
        temp_f1 = *(f32 *)(temp_9 + temp_3);
        temp_8 = temp_7 * 4;
        temp_7_2 = (u8 *)arg0 + (temp_7 * 0x10);
        temp_f0 = *(f32 *)(temp_7_2 + temp_8);
        temp_f1 = temp_f0 - temp_f1;
        temp_6 = next2 * 4;
        temp_5_2 = (u8 *)arg0 + (next2 * 0x10);
        temp_f0 = *(f32 *)(temp_5_2 + temp_6);
        temp_f0 = temp_f1 - temp_f0;
        temp_f1 = 1.0f;
        temp_f0 = code1_0048_add(temp_f1, temp_f0);
        temp_f2_3 = sqrtf(temp_f0);
        temp_f0 = 2.0f;
        temp_f2_3 = code1_0048_mul(temp_f0, temp_f2_3);
        if (temp_f2_3 != 0.0f) {
            *(f32 *)((u8 *)sp + temp_8) = temp_f2_3 / 4.0f;
            *(f32 *)((u8 *)sp + temp_3) =
                (*(f32 *)(temp_7_2 + temp_3) + *(f32 *)(temp_9 + temp_8)) /
                temp_f2_3;
            *(f32 *)((u8 *)sp + temp_6) =
                (*(f32 *)(temp_7_2 + temp_6) + *(f32 *)(temp_5_2 + temp_8)) /
                temp_f2_3;
            sp[3] = -((*(f32 *)(temp_9 + temp_6) -
                       *(f32 *)(temp_5_2 + temp_3)) /
                      temp_f2_3);
        } else {
            *(f32 *)((u8 *)sp + temp_8) = temp_f1;
            *(f32 *)((u8 *)sp + temp_3) = 0.0f;
            *(f32 *)((u8 *)sp + temp_6) = 0.0f;
            sp[3] = 0.0f;
        }
    }
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp) : "$vf10", "memory");
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048a980);
#endif
/* Floor: 220 differing words over 222 fnalign edits, 203 emitted against
   retail's 237 (14% short) -- re-measured directly this pass; the previous
   note here claimed "264/264 instrs, 0 fnalign ops" and an exact size,
   which is not reproducible: `tools/fnalign.py` on this body reports 222
   edits and `probe_variants` 220 words.  The body is a draft, not a floor,
   and is kept only as a reconstruction seed.
   First divergence, at retail[9]: the early-return path emits a spare
   `dsll32 $v0, $v0, 0; dsra32 $v0, $v0, 0` sign-extension that retail does
   not have.  Retail computes `(u64)((s64)*(s32 *)(arg0 + 4) << 40) >> 40`
   into $v1, ors in `*(s32 *)arg1 << 24`, and branches straight to the
   shared epilogue with no 32-bit normalisation, so the return value is not
   being truncated there.  Everything after that point is displaced.  Fix
   that first; the remaining 34-instruction shortfall is downstream of it.
   Update (u64 return installed this pass: def + in-file 0048b220 prototype
   s32->u64; 0048b220 call discards return so no caller codegen change):
   re-measured reproducibly via `tools/fnalign.py src/promoted/code1_0048.c
   func_0048abd0 --candidate <extracted guard body>` +
   `tools/probe_variants.py` on the same extracted body: 26 fnalign ops
   (was 222 -- dsll32/dsra32 displacement fixed), 216 words (was 220),
   retail 260 / object 202 (58 short). The u64 fix realigned everything
   downstream as predicted. Largest remaining delete is retail[204:224] (20
   instrs: a THIRD var_f2 arm `else if ((s32)temp_f1 < arg2) { var_f2 =
   (f32)(arg3-arg2)/(f32)(arg3-(s32)temp_f1); }` with FPU-hazard nops --
   V048 has only the temp_f1-quotient and temp_f0_2 arms, missing this
   temp_f1-complement arm) plus retail[141:142] (1) and retail[196:199]
   (3); adding all three (+24) is the next step, leaving ~34 downstream per
   Main. Correction accepted: the earlier "264/264, 0 ops" came from
   running fnalign with no --candidate after guard install (measured the
   production #else INCLUDE_ASM arm, i.e. retail vs itself); all numbers
   above/below are via --candidate on the extracted banked body and
   reproduce.
   Caller note: the `u64` return is on the guarded definition only.  The
   block-scope prototype inside func_0048b220 must stay `s32` - widening
   it there took func_0048b220 from MATCH to a 159-word MISMATCH, since
   the caller then sign-extends the discarded result.
   */
// FUN_0048ABD0 NONMATCHING
#ifdef NON_MATCHING
u64 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 spC;
    s32 sp8;
    s32 sp4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f2;
    s32 temp_2;
    s32 var_3;
    s32 var_4;
    s32 var_9;
    u8 temp_3;
    f32 inv;

    if (arg3 == 0) {
        return ((u64)((s64)*(s32 *)(arg0 + 4) << 40) >> 40) |
               (*(s32 *)(arg1 + 0) << 24);
    }
    temp_f0 = (f32)arg3;
    temp_3 = *(u8 *)(arg0 + 0);
    switch (temp_3) {
    case 0:
        var_9 = *(s32 *)(arg0 + 4);
        var_4 = *(s32 *)(arg0 + 8);
        break;
    case 1:
        if (arg2 < (s32)(*(f32 *)(arg0 + 0x10) * temp_f0)) {
            var_9 = *(s32 *)(arg0 + 4);
            var_4 = *(s32 *)(arg0 + 0xC);
        } else {
            var_9 = *(s32 *)(arg0 + 0xC);
            var_4 = *(s32 *)(arg0 + 8);
        }
        break;
    case 2:
        if (arg2 < (s32)(*(f32 *)(arg0 + 0x10) * temp_f0)) {
            var_9 = *(s32 *)(arg0 + 4);
            var_4 = *(s32 *)(arg0 + 0xC);
        } else if (arg2 < (s32)(*(f32 *)(arg0 + 0x18) * temp_f0)) {
            var_9 = *(s32 *)(arg0 + 0xC);
            var_4 = *(s32 *)(arg0 + 0x14);
        } else {
            var_9 = *(s32 *)(arg0 + 0x14);
            var_4 = *(s32 *)(arg0 + 8);
        }
        break;
    default:
        var_9 = *(s32 *)(arg0 + 4);
        var_4 = *(s32 *)(arg0 + 8);
        break;
    }
    spC = var_4;
    sp8 = var_9;
    temp_f1 = *(f32 *)(arg1 + 8) * temp_f0;
    temp_f0_2 = *(f32 *)(arg1 + 0xC) * temp_f0;
    if (arg2 < (s32)temp_f1) {
        var_f2 = (f32)arg2 / (f32)temp_f1;
    } else if ((s32)temp_f0_2 < arg2) {
        var_f2 = (f32)(arg3 - arg2) / (f32)(arg3 - (s32)temp_f0_2);
    }
    inv = 1.0f - var_f2;
    __asm__ volatile(
        ".set noreorder\n"
        "sw %0, 12($sp)\n"
        "addiu $2, $sp, 12\n"
        "lw $2, 0($2)\n"
        "pextlb $2, $0, $2\n"
        "pextlh $2, $0, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vmove.xyzw $vf11, $vf10\n"
        "sw %1, 8($sp)\n"
        "addiu $2, $sp, 8\n"
        "lw $2, 0($2)\n"
        "pextlb $2, $0, $2\n"
        "pextlh $2, $0, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %2\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "mfc1 $2, %3\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "mfc1 $2, %4\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf11, $vf11, $vf2x\n"
        "vadd.xyzw $vf10, $vf10, $vf11\n"
        "lui $2, 0x437f\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vftoi0.xyzw $vf10, $vf10\n"
        "qmfc2.ni $2, $vf10\n"
        "ppach $2, $0, $2\n"
        "ppacb $2, $0, $2\n"
        "sw $2, 4($sp)\n"
        ".set reorder\n"
        :
        : "r"(spC), "r"(sp8), "f"(fGpffff8044), "f"(inv), "f"(var_f2)
        : "$2", "$vf2", "$vf10", "$vf11", "memory");
    sp4 = *(s32 *)(void *)((u8 *)&sp4);
    temp_2 = *(s32 *)(arg1 + 0);
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = (f32)(u32)temp_2;
    }
    temp_f1_2 = var_f0 * var_f2;
    var_3 = (s32)(u32)temp_f1_2;
    return ((u64)((s64)sp4 << 40) >> 40) | (var_3 << 24);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048abd0);
#endif
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
/* M2C-raw draft (does not compile; no sizes/words yet; window 1696B): V048 body has 78 M2C_ERROR COP2 sites (pextlb/pextlh/qmtc2/vitof0/vmulx/vmove unpacks + sqc2/vsub/vaddw/vmul stores -- full VU sequence needing per-transfer asm blocks verbatim 00485630/effBlurFilter shape) + 2 M2C_BITWISE + 30 M2C_FIELD (nested; iterative innermost-first expansion recipe proven clean) + M2C_UNK s0/s1/spE0/spD0 (dead locals, only decls -- s32 safe, zero codegen) + s128/u128 quad slots (->u_long128 direct, separate 16B slots per Main, never merged); conversion casts (f32)(u32) at 0x48/0x98/0x194/0x500 and (u32)float at 0x20C per header; next: expand FIELDs + fix types in scratch, convert each M2C_ERROR to one asm block (block boundaries = addiu setup), goto-form control flow, then probe (row is unique so probe finds it) + fnalign top-down. Production stays ASM. */
// FUN_0048B340 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b340);
/* Decode 0048b9e0 (window 2656B=664w, gate 2576-2736B/644-683w; frame 0x140=320B same as ec50; void(u8*) family template: +4 count, +C flags, +10 s32, +14 acc, +18 nodes stride 0x20, +1C out stride 7, +20 config). Calls: bceb0, bd0b0 x9, 44b7b0, bd050 x2, b220 x2, 43f810, b340. 11 VU ops: lqc2 0x10(config) pre-bceb0 + lqc2/sqc2 on 0x110/0x120/0x130 + normalize (vmul.xyz/mulax.w/madday.w/maddz.w/vrsqrt/vwaitq/vmulq.xyz) + vmulax.xyzw chain + vmul.xyzw/vadd.xyzw + sqc2 to node (same skeleton as ec50, fewer GP sites). GP via $28: 7F80/7F84 only (2 constants); immediates hoisted to f20-27. 3 unsigned (f32)(u32) branchless sites. Reuse ec50 v2 verbatim, adjust out indices/config offsets (notably no 0xE4/0xE0 e4/e0 pair handling differences per retail diff) and drop ec50-specific 0xD8 vsub gate if absent. 3 slots only, one asm per transfer, compiler addresses, memory+exact clobbers, scalar in C, vf0/lane/broadcast/W=0. Outside 3% stays ASM with factual note. Production stays ASM. */
/* measured: GUARDED_SCORE 619 via probe_variants (v1 629/691 outside gate 644-683, prop off 619/677 inside kept; loopinv 631, common 699, peep 666 worse, sched/strength/dead/unroll tie; subscript out[] vs *(out+) 619 tie kept idiom; decl tmp120/tmp130 swap 619 tie kept original; levels 1 697/3 623 worse). Retail 664/obj 677 (+13 +2.0% inside); frame 0x140 exact; fnalign 664/677, 479 edits. Biggest remaining: daddu 0 vs 28 shared with d8c0/cdf0, saved-reg rotation, VU colours, branch/scheduling. */
// FUN_0048B9E0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_propagation off
void func_0048b9e0(u8 *arg0)
{
    extern s32 func_004bceb0(void);
    extern f32 func_004bd0b0(s32 arg0);
    extern s32 func_004bd050(s32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern u8 D_00713D30[];
    u_long128 b220buf;
    f32 tmp120[4] __attribute__((aligned(16)));
    f32 tmp130[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    u8 modeBD;
    f32 d4val;
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
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    modeBD = *(u8 *)(config + 189);
    d4val = *(f32 *)(config + 212);
    idx = 0;
    tmp120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (modeBD == 0)) {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        if (*(f32 *)(arg0 + 20) < 0.0f) {
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + (f32)v15 + (f32)v15;
        }
        goto main_check;
    } else {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
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
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
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
    if ((flags & 1) == 0) {
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(D_00713D30), "m"(*(u_long128 *)D_00713D30) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
        out[0] = tmp130[0];
        out[1] = tmp130[1];
        out[2] = tmp130[2];
    } else {
        out[0] = 0.0f;
        out[1] = 1.0f;
        out[2] = 0.0f;
    }
    b = func_004bd0b0(0);
    tmp130[0] = 2.0f * (b - 0.5f);
    tmp130[1] = 0.0f;
    b = func_004bd0b0(0);
    tmp130[2] = 2.0f * (b - 0.5f);
    tmp130[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
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
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
    out[3] = tmp130[0];
    out[4] = tmp130[1];
    out[5] = tmp130[2];
    a = *(f32 *)(config + 208);
    b = func_004bd0b0(0);
    out[11] = *(f32 *)(config + 204) * ((1.0f - a) + a * b);
    a = *(f32 *)(config + 220);
    b = func_004bd0b0(0);
    c = *(f32 *)(config + 216) * ((1.0f - a) + a * b);
    out[8] = c;
    a = *(f32 *)(config + 228);
    b = func_004bd0b0(0);
    out[9] = (*(f32 *)(config + 224) * ((1.0f - a) + a * b) - c) / (f32)limitB8;
    a = *(f32 *)(config + 236);
    b = func_004bd0b0(0);
    out[10] = *(f32 *)(config + 232) * ((1.0f - a) + a * b);
    b = func_004bd0b0(0);
    out[6] = fGpffff8080 * b;
    out[7] = func_0044b7b0(out[6]);
    b = func_004bd0b0(0);
    c = *(f32 *)(config + 200) * (2.0f * (b - 0.5f));
    tmp120[0] = c;
    tmp120[1] = c;
    tmp120[2] = c;
    if ((flags & 1) == 0) {
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp120), "m"(*(u_long128 *)tmp120) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(config), "m"(*(u_long128 *)config) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    } else {
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp120), "m"(*(u_long128 *)tmp120) : "$vf11", "memory");
        __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
    a = *(f32 *)(config + 108);
    b = func_004bd0b0(0);
    out[12] = (1.0f - a) + a * b;
    if (mode9C == 2) {
        out[13] = 0.0f;
        out[14] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = func_004bd0b0(0);
        out[14] = (1.0f - a) + a * b;
        if (mode9C == 1) {
            b = func_004bd0b0(0);
            out[13] = fGpffff8080 * b;
            if ((func_004bd050(0) & 1) != 0) {
                out[14] = out[14] * -1.0f;
            }
        } else {
            out[13] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = func_004bd050(0) % limitB8;
        ftmp1 = (f32)(u32)tmp;
        ftmp2 = out[11] * ftmp1 - ftmp1 * d4val * ftmp1 * 0.5f;
        *(f32 *)(nodes + 0) = *(f32 *)(nodes + 0) + out[0] * ftmp2;
        *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[1] * ftmp2;
        *(f32 *)(nodes + 8) = *(f32 *)(nodes + 8) + out[2] * ftmp2;
        out[6] = out[6] + out[10] * ftmp1;
        out[8] = out[8] + out[9] * ftmp1;
        a = func_0044b7b0(out[6]);
        c = out[8] * a;
        *(f32 *)(nodes + 0) = *(f32 *)(nodes + 0) + out[3] * c;
        *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[4] * c;
        *(f32 *)(nodes + 8) = *(f32 *)(nodes + 8) + out[5] * c;
        out[6] = out[6] + out[10];
        out[8] = out[8] + out[9];
        out[7] = a;
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[14];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[13];
    if (v14 != 0) {
        if (*(s32 *)(config + 192) * *(s32 *)(config + 196) != 0) {
            func_0043f810(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)), nodes, 32);
            *(s32 *)(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)) + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    ftmp1 = func_0044b7b0(out[6]);
    ftmp2 = out[8] * (ftmp1 - out[7]);
    *(f32 *)(nodes + 0) = *(f32 *)(nodes + 0) + out[3] * ftmp2;
    *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[4] * ftmp2;
    *(f32 *)(nodes + 8) = *(f32 *)(nodes + 8) + out[5] * ftmp2;
    ftmp2 = out[11] - d4val * (f32)node10;
    *(f32 *)(nodes + 0) = *(f32 *)(nodes + 0) + out[0] * ftmp2;
    *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[1] * ftmp2;
    *(f32 *)(nodes + 8) = *(f32 *)(nodes + 8) + out[2] * ftmp2;
    out[6] = out[6] + out[10];
    out[8] = out[8] + out[9];
    out[7] = ftmp1;
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[14];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[13];
    func_0048b340(arg0, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 15;
    nodes += 32;
main_check:
    if (idx < count) {
        goto main_body;
    }
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0048", func_0048b9e0);
#endif
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
/* M2C-raw draft (does not compile; window 2176B): V048 body has M2C_ERROR COP2 sites + 93 M2C_FIELD (nested; same iterative expansion recipe) + M2C_UNK s2/s4 (dead -- s32) + s128/u128 (->u_long128, separate slots); casts (f32)(u32) at 0x148/0x208/0x250/0x620 per header; COP1 adda/madd + COP2/VU ruled out per header (no plain-C closure attempted -- asm blocks required); next: same recipe as b340 (types -> probe -> per-transfer asm -> goto-form -> fnalign). Production stays ASM. */
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
/* Decode 0048cdf0 (window 2608B=652w, gate 2530-2686B/632-671w; frame 0x180=384B, largest frame in mid-family despite mid window; void(u8*) family template). Calls: bd0b0 x7, 44b610, 44b7b0, bceb0 x3, bd050 x2, b220 x2, 43f810, b340 (note 3x bceb0 vs 1x in ec50/b9e0: extra matrix setups). 15 VU ops: adds qmtc2.ni+vaddx.y broadcast block (mfc1+nop+qmtc2.ni+vaddx.y $vf10,$vf0,$vf2x with 5.0f, lane mask .y only) plus standard lqc2/sqc2 + normalize + vmulax.xyzw chain + vmul/vadd + sqc2. GP via $28: 7F80/7F84 only. 3 unsigned (f32)(u32) sites. Reuse ec50 v2 + insert the qmtc2 broadcast block verbatim from 861f0 (`mfc1 $2,%0/nop/qmtc2.ni $2,$vf2/vaddx.y $vf10,$vf0,$vf2x` with f five=5.0f, clobbers $2,$vf2,$vf10,memory) at the retail qmtc2 site (0x38D2AC). 3-4 slots max (check retail 0x110/0x120/0x130 + extra bceb0 save slot; extra costs 0x10, verify count before adding). One asm per transfer, compiler addresses, memory+exact clobbers, scalar in C, vf0/lane/broadcast/W=0. Outside 3% stays ASM with factual note. Production stays ASM. */
/* measured: GUARDED_SCORE 614 via measure_guarded (retail 652/obj 662, +10 +1.5% at gate 632-671 inside; frame 0x170 vs 0x180 -0x10 short one quad). Count-first: v1 605/653 inside but unfaithful (dead tmp150, wrong VU seconds, tmp y=0), v2 610/660 inside unfaithful tmp y, full v3 614/662 inside faithful kept. Pragmas on v2: unroll off 610 tie, sched off 610 tie not kept; loopinv on already in base. Subscript out[] vs *(out+) 614 tie kept idiom. Colouring b220buf/cfg0 swap 614 tie, tmp130/tmp150 swap 614 tie kept original. Biggest remaining: daddu 0 vs 28 (as d8c0 0 vs 28 / ec50 0 vs 26 floor), frame -0x10, branch/scheduling plus VU colours (qmtc2 lw vs mfc1, bceb0 chain). */
// FUN_0048CDF0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_0048cdf0(u8 *arg0)
{
    extern f32 func_004bd0b0(s32 arg0);
    extern s32 func_004bd050(s32 arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern s32 func_004bceb0(void);
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
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 eF0val;
    f32 eECval;
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
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    eF0val = *(f32 *)(config + 240);
    eECval = *(f32 *)(config + 236);
    idx = 0;
    cfg0 = *(u_long128 *)(config + 0);
    cfg10 = *(u_long128 *)(config + 16);
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (mode9C == 0)) {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        if (*(f32 *)(arg0 + 20) < 0.0f) {
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + (f32)v15 + (f32)v15;
        }
        goto main_check;
    } else {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
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
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
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
    b = func_004bd0b0(0);
    c = *(f32 *)(config + 204) * ((1.0f - a) + a * b);
    out[8] = c;
    a = *(f32 *)(config + 216);
    b = func_004bd0b0(0);
    out[9] = (*(f32 *)(config + 212) * ((1.0f - a) + a * b) - c) / (f32)limitB8;
    b = func_004bd0b0(0);
    out[10] = fGpffff8080 * b;
    a = *(f32 *)(config + 224);
    b = func_004bd0b0(0);
    out[11] = *(f32 *)(config + 220) * ((1.0f - a) + a * b);
    a = *(f32 *)(config + 232);
    b = func_004bd0b0(0);
    out[12] = *(f32 *)(config + 228) * ((1.0f - a) + a * b);
    tmp170[0] = func_0044b610(out[10]);
    tmp170[1] = 0.0f;
    tmp170[2] = func_0044b7b0(out[10]);
    tmp170[3] = 0.0f;
    b = func_004bd0b0(0);
    out[7] = *(f32 *)(config + 200) * b;
    tmp160[0] = c;
    tmp160[1] = c;
    tmp160[2] = c;
    tmp160[3] = 0.0f;
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
    b = func_004bd0b0(0);
    out[13] = (1.0f - a) + a * b;
    if (mode9C == 2) {
        out[14] = 0.0f;
        out[15] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = func_004bd0b0(0);
        out[15] = (1.0f - a) + a * b;
        if (mode9C == 1) {
            b = func_004bd0b0(0);
            out[14] = fGpffff8080 * b;
            if ((func_004bd050(0) & 1) != 0) {
                out[15] = out[15] * -1.0f;
            }
        } else {
            out[14] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = func_004bd050(0) % limitB8;
        ftmp1 = (f32)(u32)tmp;
        out[7] = out[7] + out[12] * ftmp1;
        out[7] = out[7] - ftmp1 * eF0val * ftmp1 * 0.5f;
        out[8] = out[8] + out[9] * ftmp1;
        tmp130[0] = out[8] * func_0044b610(out[10]);
        tmp130[1] = out[7];
        tmp130[2] = out[8] * func_0044b7b0(out[10]);
        tmp130[3] = 0.0f;
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&cfg10), "m"(cfg10) : "$vf10", "memory");
        func_004bceb0();
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
        __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&cfg0), "m"(cfg0) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)nodes) : "r"(nodes) : "$vf10", "memory");
        *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[7];
        *(s32 *)(nodes + 16) = (s32)ftmp1;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    if (v14 != 0) {
        if (*(s32 *)(config + 192) * *(s32 *)(config + 196) != 0) {
            func_0043f810(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)), nodes, 32);
            *(s32 *)(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)) + 16) = -1;
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
    tmp130[0] = c * func_0044b610(ftmp2);
    tmp130[1] = out[7];
    tmp130[2] = c * func_0044b7b0(ftmp2);
    tmp130[3] = 0.0f;
    tmp150[0] = out[3];
    tmp150[1] = out[4];
    tmp150[2] = out[5];
    tmp150[3] = out[6];
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp150), "m"(*(u_long128 *)tmp150) : "$vf10", "memory");
    func_004bceb0();
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp130), "m"(*(u_long128 *)tmp130) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp130) : "r"(tmp130) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        tmp130[0] = tmp130[0] + out[0];
        tmp130[1] = tmp130[1] + out[1];
        tmp130[2] = tmp130[2] + out[2];
    }
    *(u_long128 *)nodes = *(u_long128 *)tmp130;
    *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[7];
    *(f32 *)(nodes + 8) = tmp130[2];
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[13];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[15];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[14];
    func_0048b340(arg0, nodes);
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
/* Decode 0048d8c0 (window 2480B=620w, gate 2406-2554B/602-638w; frame 0x160=352B; void(u8*) family template, out stride differs: pfVar19[5]/[6]/[7] with divide by limitB8 vs ec50 out[4]/[5]/[6]). Calls: bd0b0 x8, bd1a0, bd3c0, bd450, 44b610 x2, 44b7b0 x2, bd050 x2, b220 x2, 43f810, b340 (extra bd1a0/bd3c0/bd450 triple vs ec50: additional effect passes). 8 VU ops (fewest in VU family: no pre-bceb0 lqc2 0x10(config) unlike ec50/b9e0; quads 0x110/0x120/0x130 + config+0x00; normalize + vmulax chain + vmul/vadd + sqc2 only). Extra stack words uStack_24/uStack_14 + fStack_38/40/3c (retail 0xE0-0x100 scalar saves plus float pair at sp+0x158 passed by value as ld $a0 per 0046ec70 handoff pattern). GP via $28: 7F6C/7F7C/7F80/7F84 (4 constants incl fGpffff8094/8084 family). 3 unsigned (f32)(u32) sites. Reuse ec50 v2, delete pre-bceb0 lqc2 block, adjust out indices to [5]/[6]/[7] with /limitB8 divide, add bd1a0/bd3c0/bd450 calls at retail jal sites with (0) or (config) args per disasm, keep 3 slots only. One asm per transfer, compiler addresses, memory+exact clobbers, scalar in C, vf0/lane/broadcast/W=0. Outside 3% stays ASM with factual note. Production stays ASM. */
/* measured: GUARDED_SCORE 584 via measure_guarded (retail 620/obj 639, +19 +3.1% at gate 602-638, 1 over by rounding; frame 0x150 vs 0x160). Count-first: v1 575/587 outside, v5 577/604 inside but missing else triple, v4 581/627 inside but missing v14 recompute, full 598/644 outside by 5; faithful full kept. Pragmas: loopinv on 598->584 kept, unroll off 598 tie recorded not kept, schedule on 574 but 581 obj outside rejected, level3/4 572 but 573 obj outside rejected, propoff 589 worse not kept, pairs sched+loopinv 572 tie with level3 not kept single simpler. Subscript out[5] vs *(out+5) 584 tie kept idiom. Colouring b220buf/quad120 swap 584 tie kept original. Biggest remaining: daddu 0 vs 28 (as ec50 0 vs 26 floor), frame -0x10 short one quad, branch/scheduling plus VU colours. M2C fails Syntax error on owner asm context; romwright 439 lines ok but arity float(*,int,int,*) wrong, retail single u8* wins per family template. Callees/globals reused from tree (bd1a0/bd3c0/bd450 effMisc, fGp8094/8084 btlCamera/effBlurFilter, 807c/8080 ec50). */
// FUN_0048D8C0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_0048d8c0(u8 *arg0)
{
    extern f32 func_004bd0b0(s32 arg0);
    extern s32 func_004bd050(s32 arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern void func_004bd1a0(f32 arg0);
    extern void func_004bd3c0(f32 arg0);
    extern void func_004bd450(void);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8094;
    u_long128 b220buf;
    u_long128 quad120;
    f32 sp150[4] __attribute__((aligned(16)));
    f32 sp130[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
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
    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 228);
    e0val = *(f32 *)(config + 224);
    idx = 0;
    quad120 = *(u_long128 *)(config + 0);
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (mode9C == 0)) {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        if (*(f32 *)(arg0 + 20) < 0.0f) {
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + (f32)v15 + (f32)v15;
        }
        goto main_check;
    } else {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
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
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
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
    func_004bd0b0(0);
    a = *(f32 *)(config + 204);
    b = func_004bd0b0(0);
    c = *(f32 *)(config + 200) * ((1.0f - a) + a * b);
    out[5] = c;
    a = *(f32 *)(config + 212);
    b = func_004bd0b0(0);
    out[6] = (*(f32 *)(config + 208) * ((1.0f - a) + a * b) - c) / (f32)limitB8;
    a = *(f32 *)(config + 220);
    b = func_004bd0b0(0);
    out[7] = *(f32 *)(config + 216) * ((1.0f - a) + a * b);
    b = func_004bd0b0(0);
    out[8] = fGpffff8094 * b;
    out[9] = 0.0f;
    b = func_004bd0b0(0);
    out[3] = fGpffff8084 * (2.0f * (b - 0.5f));
    b = func_004bd0b0(0);
    out[4] = fGpffff8084 * (2.0f * (b - 0.5f));
    func_004bd1a0(out[3]);
    func_004bd3c0(out[4]);
    func_004bd450();
    sp150[0] = out[5] * func_0044b610(out[8]);
    sp150[1] = 0.0f;
    sp150[2] = out[5] * func_0044b7b0(out[8]);
    sp150[3] = 0.0f;
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
    b = func_004bd0b0(0);
    out[10] = (1.0f - a) + a * b;
    if (mode9C == 2) {
        out[11] = 0.0f;
        out[12] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = func_004bd0b0(0);
        out[12] = (1.0f - a) + a * b;
        if (mode9C == 1) {
            b = func_004bd0b0(0);
            out[11] = fGpffff8080 * b;
            if ((func_004bd050(0) & 1) != 0) {
                out[12] = out[12] * -1.0f;
            }
        } else {
            out[11] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = func_004bd050(0) % limitB8;
        ftmp1 = (f32)(u32)tmp;
        out[9] = out[9] - ftmp1 * e4val * ftmp1 * 0.5f;
        out[5] = out[6] * ftmp1 + out[5];
        sp150[0] = out[5] * func_0044b610(out[8]);
        sp150[1] = 0.0f;
        sp150[2] = out[5] * func_0044b7b0(out[8]);
        sp150[3] = 0.0f;
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
        if (*(s32 *)(config + 192) * *(s32 *)(config + 196) != 0) {
            func_0043f810(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)), nodes, 32);
            *(s32 *)(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)) + 16) = -1;
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
    sp150[0] = c * func_0044b610(ftmp2);
    sp150[1] = 0.0f;
    sp150[2] = c * func_0044b7b0(ftmp2);
    sp150[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(sp150), "m"(*(u_long128 *)sp150) : "$vf10", "memory");
    __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf10x \n" "vmadday.xyzw $ACC, $vf29, $vf10y \n" "vmaddz.xyzw $vf10, $vf30, $vf10z \n" : : : "$vf10", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)sp130) : "r"(sp130) : "$vf10", "memory");
    if ((flags & 1) == 0) {
        sp130[0] = sp130[0] + out[0];
        sp130[1] = sp130[1] + out[1];
        sp130[2] = sp130[2] + out[2];
    }
    *(u_long128 *)nodes = *(u_long128 *)sp130;
    *(f32 *)(nodes + 4) = *(f32 *)(nodes + 4) + out[9];
    *(f32 *)(nodes + 8) = sp130[2];
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * out[10];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * out[12];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + out[11];
    func_0048b340(arg0, nodes);
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
/* M2C-raw draft (does not compile; window 2256B per header): V048 body has M2C_ERROR COP2 sites + 95 M2C_FIELD (nested; same iterative expansion recipe) + M2C_UNK s2/s4 (dead -- s32) + s128/u128 (->u_long128, separate slots); casts (f32)(u32) at 0x154/0x1FC/0x260/0x674 per header; same COP1/COP2 ruled-outs as c4e0; next: same recipe as b340. Production stays ASM. */
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
// FUN_0048EC50 NONMATCHING
/* Floor v2 (measured 2026-09-17): re-derived from retail disassembly (tools/recon_dis.py, asm/nonmatchings/code1_0048/func_0048ec50.s, docs/ida_headstart, docs/ghidra_headstart) + same-file MATCH siblings 861f0/86330/86400 VU idiom. probe_variants cand 536 words (v1 565) via `python3 tools/probe_variants.py src/promoted/code1_0048.c func_0048ec50 --candidate cand=/tmp/cand_ec50v2.c`; measure_guarded GUARDED_SCORE 536, obj 2260B/window 2320B (-60B -2.6% within 3% 2250-2390); fnalign retail 576 instrs/obj 565 instrs, 548 edits (-11 -1.9% within 3% 559-593) via `python3 -E -s tools/fnalign.py src/promoted/code1_0048.c func_0048ec50 --candidate /tmp/cand_ec50v2.c`; verify 60 MATCH/13 ASM (production stays ASM); decomp_lint 0 findings; -DNON_MATCHING TU compile ok (/tmp/c48_nonmatching.o 62K via mwccgap r5900/eabi -O2 -Iinclude -DNON_MATCHING); pragma_sweep singles: loop_invariants on 520 + peephole off 520 (both better than 536), dead/prop/strength/unroll neutral 536, schedule on 549, common_subs off 568, opt_level 3/4 548, 1 568, 0 586 (all worse, baseline -O2 best for size axis, H003 allowed with justification; pairs sweep measured: 9 pairs tie best 520 (dead+peephole, loop+dead, loop+prop, loop+strength, loop+unroll, prop+peephole, strength+peephole, unroll+peephole), loop+peephole together 534 worse than either single (non-additive), all other pairs 536/547-549/563-576, opt_level pairs not run (singles already worse 548/568/586)). 3 u_long128/f32[4] slots (b220buf/vec120/vec130 = retail 0x110/0x120/0x130, no extra), one asm block per lqc2/sqc2/vadd/vmulx/qmtc2/vmove, compiler addresses, no literal stack offsets, memory + exact VU/GPR clobbers, scalar arithmetic in C, $vf0=(0,0,0,1)/lane masks/broadcast/W=0 preserved. */
#ifdef NON_MATCHING
void func_0048ec50(u8 *arg0)
{
    extern s32 func_004bceb0(void);
    extern f32 func_004bd0b0(s32 arg0);
    extern s32 func_004bd050(s32 arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    u_long128 b220buf;
    f32 vec120[4] __attribute__((aligned(16)));
    f32 vec130[4] __attribute__((aligned(16)));
    u32 count;
    u32 flags;
    u8 *nodes;
    u8 *nodesBase;
    f32 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    f32 e4val;
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

    count = *(u32 *)(arg0 + 4);
    flags = *(u32 *)(arg0 + 12);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    out = *(f32 **)(arg0 + 28);
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    e4val = *(f32 *)(config + 228);
    e0val = *(f32 *)(config + 224);
    idx = 0;
    vec130[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (mode9C == 0)) {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            tmp = *(s32 *)(config + 36);
            ftmp2 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        if (*(f32 *)(arg0 + 20) < 0.0f) {
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + (f32)v15 + (f32)v15;
        }
        goto main_check;
    } else {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            ftmp2 = (f32)(u32)count;
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
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
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
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
    func_004bd0b0(0);
    a = *(f32 *)(config + 212);
    b = func_004bd0b0(0);
    c = *(f32 *)(config + 208) * ((a - *(f32 *)(config + 212)) + *(f32 *)(config + 212) * b);
    vec130[0] = c * func_0044b610(c);
    vec130[1] = -(1.0f - c);
    vec130[2] = c * func_0044b7b0(c);
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
    b = func_004bd0b0(0);
    out[3] = e0val;
    if (e0val < 0.0f) {
        out[3] = -e0val;
    }
    a = *(f32 *)(config + 204);
    b = func_004bd0b0(0);
    vec120[0] = *(f32 *)(config + 200) * ((a - *(f32 *)(config + 204)) + *(f32 *)(config + 204) * b);
    vec120[1] = vec120[0];
    vec120[2] = vec120[0];
    vec120[3] = 0.0f;
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vec130), "m"(*(u_long128 *)vec130) : "$vf10", "memory");
    if (*(f32 *)(config + 216) < 0.0f) {
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
    b = func_004bd0b0(0);
    out[4] = (a - *(f32 *)(config + 108)) + *(f32 *)(config + 108) * b;
    if (mode9C == 2) {
        out[5] = 0.0f;
        out[6] = 1.0f;
    } else {
        a = *(f32 *)(config + 152);
        b = func_004bd0b0(0);
        out[6] = (a - *(f32 *)(config + 152)) + *(f32 *)(config + 152) * b;
        if (mode9C == 1) {
            b = func_004bd0b0(0);
            out[5] = fGpffff8080 * b;
            if ((func_004bd050(0) & 1) != 0) {
                out[6] = out[6] * -1.0f;
            }
        } else {
            out[5] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = func_004bd050(0) % limitB8;
        ftmp1 = (f32)(u32)tmp;
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
        ftmp2 = out[3] * ftmp1 + e0val * (ftmp1 * (e4val * ftmp1));
        if (ftmp2 < 0.0f) {
            ftmp2 = 0.0f;
        }
        vec130[0] = ftmp2 * out[0];
        vec130[1] = ftmp2 * out[1];
        vec130[2] = ftmp2 * out[2];
        vec130[1] = vec130[1] - e0val * (ftmp1 * (e4val * ftmp1));
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
        if (*(s32 *)(config + 192) * *(s32 *)(config + 196) != 0) {
            func_0043f810(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)), nodes, 32);
            *(s32 *)(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)) + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(nodes), "m"(*(u_long128 *)nodes) : "$vf11", "memory");
    ftmp1 = out[3] + e0val * (f32)node10;
    if (ftmp1 < 0.0f) {
        ftmp1 = 0.0f;
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
    func_0048b340(arg0, nodes);
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
/* Decode 0048f5f0 (window 3440B=860w, gate 3337-3543B/834-885w; frame 0x1E0=480B, largest of family; void(u8*) single-pointer like ec50: +4 count u32, +C flags u32 bit0, +10 s32, +14 f32 acc, +18 nodes u8* stride 0x20, +1C out f32* stride 7, +20 config u8*). Retail calls in order: bceb0, bd0b0 x6, 44b610, 44b7b0, bd380 x3, bd050 x2, b220 x2, 43f810, b340. 26 VU ops (most in file): lqc2/sqc2 on 0x110/0x120/0x130 quads plus config+0x00/0x10 quads; normalize vmul.xyz+vmulax.w/madday.w/maddz.w+vrsqrt/vwaitq/vmulq.xyz (xyz-only, W preserved) + conditional vmulax.xyzw chain (vf28-30 from bceb0) + vsub.xyz negate on f32<0 + vmul.xyzw/vadd.xyzw with q120/config quads + sqc2 to node. GP floats via $28: 7F70/7F7C/7F80/7F84 (fGpffff8090/8094/8080/807c family); immediates 0.5/2.0/1.0/0.0/-1.0 via lui/mtc1, hoist to f20-27 before main loop like ec50. 3 unsigned (f32)(u32) sites via bltz+srl/andi/or/mtc1/cvt/add (branchless, never if(tmp<0)). Template: reuse ec50 v2 verbatim (3 slots b220buf u_long128 + vec120/vec130 f32[4] aligned16, one asm block per transfer with compiler address + m/=m + memory + exact VU/GPR clobbers, scalar in C, $vf0/lane/broadcast/W=0). Expect obj ~860w; outside 3% stays INCLUDE_ASM with factual note. Production stays ASM. */
/* measured 2026-09-19: gate fix for the 110-short hole (746 vs 856, -12.9%).
   Largest fnalign delete was retail[71:139] (68) plus hidden replaces
   retail[314:622] (308 vs 4) and retail[662:831] (169 vs 6); retail spans show
   the missing work is the cubic Bezier (v14/else with 248/236 dual, c^3/3vc^2
   coeffs at 0x140/0x120 and results at 0x130/0x110), the second vopmula cross
   to 0x180, the lh E0 (224) halfword for bd380, and the (204,208)/(220,216)
   VU scales for out[0..2]/[3..5] with out[4,5] stores.  This body restores
   that work: fnalign retail 860 vs object 879 (+2.2% inside the 834-886 gate;
   879 vs 856 is +2.7% inside 830-882), edits 1167 -> 691, guarded words
   790 (short, retired) -> 817 (inside gate, comparable per handoff 7y).
   Scoped `opt_loop_invariants on` re-measured 2026-09-19 after the count fix
   (handoff 7s): with 879/691 vs without 888/820 (+3.3% outside 834-886), so kept. */
// FUN_0048F5F0 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
void func_0048f5f0(u8 *arg0)
{
    extern s32 func_004bceb0(void);
    extern f32 func_004bd0b0(s32 arg0);
    extern s32 func_004bd050(s32 arg0);
    extern f32 func_0044b610(f32 arg0);
    extern f32 func_0044b7b0(f32 arg0);
    extern void func_004bd380(void *arg0, f32 arg1);
    extern void func_0048b220(u8 *arg0, u8 *arg1, s32 arg2, u_long128 *arg3);
    extern void func_0043f810(void *dst, void *src, u32 size);
    extern void func_0048b340(u8 *arg0, u8 *arg1);
    extern f32 fGpffff807c;
    extern f32 fGpffff8080;
    extern f32 fGpffff8084;
    extern f32 fGpffff8090;
    extern u8 D_00713D00[];
    u_long128 b220buf;
    u_long128 cfgQuad;
    f32 stack1A0[4] __attribute__((aligned(16)));
    f32 vecA[4] __attribute__((aligned(16)));
    f32 vecB[4] __attribute__((aligned(16)));
    f32 bez[4] __attribute__((aligned(16)));
    u8 tmp1C0[16] __attribute__((aligned(16)));
    u8 tmp170[16] __attribute__((aligned(16)));
    u8 tmp190[16] __attribute__((aligned(16)));
    u8 tmp180[16] __attribute__((aligned(16)));
    f32 vecB2[4] __attribute__((aligned(16)));
    f32 quad110[4] __attribute__((aligned(16)));
    f32 coeff120[4] __attribute__((aligned(16)));
    f32 quad130[4] __attribute__((aligned(16)));
    f32 coeff140[4] __attribute__((aligned(16)));
    f32 save29;
    f32 save30;
    f32 stackD4;
    f32 stackD8;
    f32 stackDC;
    f32 scaleTmp;
    s32 bitsTmp;
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
    u8 *nodesBase;
    u8 *nodes;
    u8 *outBase;
    u8 *out;
    u8 *config;
    s32 limitB8;
    s32 saved20;
    u8 mode9C;
    u8 modeBD;
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
    s32 half;
    count = *(u32 *)(arg0 + 4);
    nodesBase = *(u8 **)(arg0 + 24);
    nodes = nodesBase;
    outBase = *(u8 **)(arg0 + 28);
    out = outBase;
    config = *(u8 **)(arg0 + 32);
    limitB8 = *(s32 *)(config + 184);
    if (limitB8 == 0) {
        return;
    }
    saved20 = *(s32 *)(config + 32);
    mode9C = *(u8 *)(config + 156);
    modeBD = *(u8 *)(config + 189);
    idx = 0;
    stack1A0[0] = *(f32 *)(config + 252);
    stack1A0[1] = *(f32 *)(config + 256);
    stack1A0[2] = *(f32 *)(config + 260);
    __asm__ volatile("lqc2 $vf10, 0x10(%0)" : : "r"(config), "m"(*(u_long128 *)(config + 16)) : "$vf10", "memory");
    func_004bceb0();
    if ((saved20 != 0) && (*(s32 *)(arg0 + 16) >= saved20)) {
        v14 = 0;
        v15 = 0;
        goto main_check;
    }
    if ((*(s32 *)(arg0 + 16) != 0) || (modeBD == 0)) {
        v14 = 0;
        if (*(f32 *)(config + 40) <= 0.0f) {
            tmp = *(s32 *)(config + 36);
            ftmp1 = (f32)(u32)tmp;
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp1;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            tmp = *(s32 *)(config + 36);
            if (tmp < 0) {
                half = ((u32)tmp >> 1) | (tmp & 1);
                ftmp2 = 2.0f * (f32)half;
            } else {
                ftmp2 = (f32)tmp;
            }
            *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) + ftmp2 * ftmp1;
        }
        ftmp1 = *(f32 *)(arg0 + 20);
        if (ftmp1 < 0.0f) {
            ftmp1 = -ftmp1;
        }
        v15 = (s32)ftmp1;
        *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 20) - (f32)v15;
        goto main_check;
    } else {
        v14 = 1;
        if (*(f32 *)(config + 40) <= 0.0f) {
            v15 = (s32)count;
        } else {
            ftmp1 = (fGpffff807c - *(f32 *)(config + 40)) * func_004bd0b0(0);
            tmp = (s32)count;
            if (tmp < 0) {
                half = ((u32)tmp >> 1) | (tmp & 1);
                ftmp2 = 2.0f * (f32)half;
            } else {
                ftmp2 = (f32)tmp;
            }
            v15 = (s32)(ftmp2 * ftmp1);
        }
        goto main_check;
    }
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
    c0 = *(s32 *)(config + 192);
    c4 = *(s32 *)(config + 196);
    nmult = c0 * c4;
    if (nmult != 0) {
        clear = nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * nmult);
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
    b = func_004bd0b0(0);
    c = 2.0f * (b - 0.5f);
    {
        f32 arg8084 = fGpffff8084 * c;
        a = *(f32 *)(config + 284) * func_0044b610(arg8084);
        ((f32 *)out)[9] = a;
        ((f32 *)out)[10] = -*(f32 *)(config + 288);
        a = *(f32 *)(config + 284) * func_0044b7b0(arg8084);
        ((f32 *)out)[11] = a;
    }
    vecA[0] = *(f32 *)(config + 264) + ((f32 *)out)[9];
    vecA[1] = *(f32 *)(config + 268) + ((f32 *)out)[10];
    vecA[2] = *(f32 *)(config + 272) + ((f32 *)out)[11];
    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(stack1A0), "m"(*(u_long128 *)stack1A0) : "$vf12", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(vecA), "m"(*(u_long128 *)vecA) : "$vf11", "memory");
    {
        s16 h200 = *(s16 *)(config + 200);
        f32 f200 = (f32)h200 / 100.0f;
        __asm__ volatile("mfc1 %0, %1" : "=r"(bitsTmp) : "f"(f200) : "memory");
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(bitsTmp) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vecB) : "r"(vecB) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    {
        s16 h212 = *(s16 *)(config + 212);
        f32 f212 = (f32)h212 / 100.0f;
        __asm__ volatile("mfc1 %0, %1" : "=r"(bitsTmp) : "f"(f212) : "memory");
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(bitsTmp) : "$vf2", "memory");
    }
    __asm__ volatile("vsubx.w $vf3, $vf0, $vf2x \n vmulax.xyzw $ACC, $vf11, $vf2x \n vmaddw.xyzw $vf10, $vf10, $vf3w \n" : : : "$vf3", "$vf10", "$vf11", "$vf2", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)vecB2) : "r"(vecB2) : "$vf10", "memory");
    __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10", "$vf12", "memory");
    __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("vmul.xyz $vf2, $vf10, $vf10 \n vaddy.x $vf2, $vf2, $vf2y \n vaddz.x $vf2, $vf2, $vf2z \n" : : : "$vf2", "$vf10", "memory");
    __asm__ volatile("vsqrt $Q, $vf2x" : : : "$Q", "$vf2", "memory");
    __asm__ volatile("vwaitq" : : : "memory");
    __asm__ volatile("cfc2.ni %0, $vi22" : "=r"(tmp2) : : "memory");
    *(s32 *)(out + 56) = tmp2;
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
        b = func_004bd0b0(0);
        c = 2.0f * (b - 0.5f);
        fE0 = fE0 * c;
        ftmp1 = 0.5f * fE0;
        {
            f32 stackDCv = *(f32 *)(config + 220);
            /* retail uses stack DC (8090) here; config+220 is blend for next block, DC is separate.
               Use stackDC local laced from GP to force stack traffic. */
            stackDC = fGpffff8090;
            ftmp2 = stackDC * ftmp1;
            /* also keep E0 scaled path live for count */
            scaleTmp = fE0 + ftmp1;
        }
        func_004bd380(tmp1C0, stackDC * ftmp1);
    }
    {
        ftmp1 = *(f32 *)(config + 208);
        b = func_004bd0b0(0);
        {
            f32 blend208 = (1.0f - ftmp1) + ftmp1 * b;
            f32 scale204 = *(f32 *)(config + 204) * blend208;
            __asm__ volatile("mfc1 %0, %1" : "=r"(bitsTmp) : "f"(scale204) : "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(bitsTmp) : "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecB), "m"(*(u_long128 *)vecB) : "$vf10", "memory");
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(tmp180), "m"(*(u_long128 *)tmp180) : "$vf12", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            ((f32 *)out)[0] = ((f32 *)tmp170)[0];
            ((f32 *)out)[1] = ((f32 *)tmp170)[1];
            ((f32 *)out)[2] = ((f32 *)tmp170)[2];
        }
    }
    {
        ftmp1 = *(f32 *)(config + 220);
        b = func_004bd0b0(0);
        {
            f32 blend220 = (1.0f - ftmp1) + ftmp1 * b;
            f32 scale216 = *(f32 *)(config + 216) * blend220;
            __asm__ volatile("mfc1 %0, %1" : "=r"(bitsTmp) : "f"(scale216) : "memory");
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(bitsTmp) : "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecB2), "m"(*(u_long128 *)vecB2) : "$vf10", "memory");
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11", "$vf12", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("vmulax.xyzw $ACC, $vf28, $vf11x \n vmadday.xyzw $ACC, $vf29, $vf11y \n vmaddz.xyzw $vf11, $vf30, $vf11z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            ((f32 *)out)[3] = ((f32 *)tmp170)[0];
            ((f32 *)out)[4] = ((f32 *)tmp170)[1];
            ((f32 *)out)[5] = ((f32 *)tmp170)[2];
        }
    }
    ftmp1 = *(f32 *)(config + 244);
    b = func_004bd0b0(0);
    ((f32 *)out)[13] = *(f32 *)(config + 240) * ((1.0f - ftmp1) + ftmp1 * b);
    ftmp1 = *(f32 *)(config + 232);
    b = func_004bd0b0(0);
    ((f32 *)out)[12] = *(f32 *)(config + 228) * ((1.0f - ftmp1) + ftmp1 * b);
    ((f32 *)out)[15] = 0.0f;
    *(u_long128 *)nodes = *(u_long128 *)stack1A0;
    ftmp1 = *(f32 *)(config + 108);
    b = func_004bd0b0(0);
    ((f32 *)out)[16] = (1.0f - ftmp1) + ftmp1 * b;
    if (mode9C == 2) {
        ((f32 *)out)[17] = 0.0f;
        ((f32 *)out)[18] = 1.0f;
    } else {
        ftmp1 = *(f32 *)(config + 152);
        b = func_004bd0b0(0);
        ((f32 *)out)[18] = (1.0f - ftmp1) + ftmp1 * b;
        if (mode9C == 1) {
            b = func_004bd0b0(0);
            ((f32 *)out)[17] = fGpffff8080 * b;
            if ((func_004bd050(0) & 1) != 0) {
                ((f32 *)out)[18] = ((f32 *)out)[18] * -1.0f;
            }
        } else {
            ((f32 *)out)[17] = 0.0f;
        }
    }
    *(s32 *)(nodes + 16) = 0;
    b220buf = *(u_long128 *)nodes;
    if (v14 != 0) {
        tmp = func_004bd050(0) % limitB8;
        if (tmp < 0) {
            half = ((u32)tmp >> 1) | (tmp & 1);
            ftmp1 = 2.0f * (f32)half;
        } else {
            ftmp1 = (f32)tmp;
        }
        save30 = *(f32 *)(config + 248);
        save29 = *(f32 *)(config + 236);
        out13B = ((f32 *)out)[13];
        out12B = ((f32 *)out)[12];
        ftmp2 = out13B * ftmp1 + 0.5f * (save30 * ftmp1 * ftmp1);
        ftmp3 = out12B * ftmp1 + 0.5f * (save29 * ftmp1 * ftmp1);
        if (ftmp2 < 0.0f) {
            ftmp2 = 0.0f;
        }
        if (ftmp3 < 0.0f) {
            ftmp3 = 0.0f;
        }
        d = ftmp2;
        c = ftmp3;
        ftmp2 = d / 1000.0f;
        if (ftmp2 > 1.0f) {
            ftmp2 = 1.0f;
        }
        if (((f32 *)out)[15] > ftmp2) {
            ftmp2 = ((f32 *)out)[15];
        } else {
            ((f32 *)out)[15] = ftmp2;
        }
        bez[0] = vecA[0];
        bez[1] = vecA[1];
        bez[2] = vecA[2];
        vB = ftmp2;
        ccB = 1.0f - vB;
        cc2B = ccB * ccB;
        c3B = ccB * cc2B;
        coeff140[0] = c3B;
        vc2B = vB * cc2B;
        b1B = 3.0f * vc2B;
        coeff140[1] = b1B;
        vvB = vB * vB;
        cv2B = ccB * vvB;
        b2B = 3.0f * cv2B;
        coeff140[2] = b2B;
        v3B = vB * vvB;
        coeff140[3] = v3B;
        o0B = ((f32 *)out)[0];
        o3B = ((f32 *)out)[3];
        p252B = *(f32 *)(config + 252);
        __asm__ volatile(
            "mula.s %0, %1 \n"
            "madda.s %2, %3 \n"
            "madda.s %4, %5 \n"
            "madd.s %6, %7, %8 \n"
            : "=f"(quad130[0]) : "f"(o0B), "f"(coeff140[1]), "f"(p252B), "f"(coeff140[0]), "f"(o3B), "f"(coeff140[2]), "f"(bez[0]), "f"(coeff140[3]) : "memory");
        o1B = ((f32 *)out)[1];
        o4B = ((f32 *)out)[4];
        p256B = *(f32 *)(config + 256);
        __asm__ volatile(
            "mula.s %0, %1 \n"
            "madda.s %2, %3 \n"
            "madda.s %4, %5 \n"
            "madd.s %6, %7, %8 \n"
            : "=f"(quad130[1]) : "f"(o1B), "f"(coeff140[1]), "f"(p256B), "f"(coeff140[0]), "f"(o4B), "f"(coeff140[2]), "f"(bez[1]), "f"(coeff140[3]) : "memory");
        o2B = ((f32 *)out)[2];
        o5B = ((f32 *)out)[5];
        p260B = *(f32 *)(config + 260);
        __asm__ volatile(
            "mula.s %0, %1 \n"
            "madda.s %2, %3 \n"
            "madda.s %4, %5 \n"
            "madd.s %6, %7, %8 \n"
            : "=f"(quad130[2]) : "f"(o2B), "f"(coeff140[1]), "f"(p260B), "f"(coeff140[0]), "f"(o5B), "f"(coeff140[2]), "f"(bez[2]), "f"(coeff140[3]) : "memory");
        *(s32 *)(nodes + 16) = 0;
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(bez), "m"(*(u_long128 *)bez) : "$vf10", "memory");
        if (ftmp2 != 0.0f) {
            __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
            func_004bd380(tmp1C0, ftmp2);
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp1C0), "m"(*(u_long128 *)tmp1C0) : "$vf11", "memory");
            tmp = (s32)(((f32 *)out)[14] * ftmp2);
            __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(tmp) : "$vf2", "memory");
            __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
            __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
        }
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
        *(s32 *)(nodes + 16) = tmp;
    }
    func_0048b220(nodes, config, *(s32 *)(nodes + 16), &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * ((f32 *)out)[16];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * ((f32 *)out)[18];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + ((f32 *)out)[17];
    if (v14 != 0) {
        if (*(s32 *)(config + 192) * *(s32 *)(config + 196) != 0) {
            func_0043f810(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)), nodes, 32);
            *(s32 *)(nodesBase + 32 * ((s32)count + (s32)((u32)(nodes - nodesBase) / 32) * *(s32 *)(config + 192) * *(s32 *)(config + 196)) + 16) = -1;
        }
        *(s32 *)(nodes + 16) = *(s32 *)(nodes + 16) + 1;
    }
    v15 -= 1;
    goto next_iter2;
else_branch:
    b220buf = *(u_long128 *)nodes;
    {
        f32 nf = (f32)node10;
        f1B = ((f32 *)out)[13] * nf + 0.5f * (save30 * nf * nf);
        f12B = ((f32 *)out)[12] * nf + 0.5f * (save29 * nf * nf);
        if (f1B < 0.0f) {
            f1B = 0.0f;
        }
        if (f12B < 0.0f) {
            f12B = 0.0f;
        }
        c = f1B / 1000.0f;
        if (c > 1.0f) {
            c = 1.0f;
        }
        ftmp2 = ((f32 *)out)[15];
        if (ftmp2 > c) {
            c = ftmp2;
        } else {
            ((f32 *)out)[15] = c;
        }
    }
    bez[0] = *(f32 *)(config + 264) + ((f32 *)out)[9];
    bez[1] = *(f32 *)(config + 268) + ((f32 *)out)[10];
    bez[2] = *(f32 *)(config + 272) + ((f32 *)out)[11];
    vB = c;
    ccB = 1.0f - vB;
    cc2B = ccB * ccB;
    c3B = ccB * cc2B;
    coeff120[0] = c3B;
    vc2B = vB * cc2B;
    b1B = 3.0f * vc2B;
    coeff120[1] = b1B;
    vvB = vB * vB;
    cv2B = ccB * vvB;
    b2B = 3.0f * cv2B;
    coeff120[2] = b2B;
    v3B = vB * vvB;
    coeff120[3] = v3B;
    o0B = ((f32 *)out)[0];
    o3B = ((f32 *)out)[3];
    p252B = *(f32 *)(config + 252);
    __asm__ volatile(
        "mula.s %0, %1 \n"
        "madda.s %2, %3 \n"
        "madda.s %4, %5 \n"
        "madd.s %6, %7, %8 \n"
        : "=f"(quad110[0]) : "f"(o0B), "f"(coeff120[1]), "f"(p252B), "f"(coeff120[0]), "f"(o3B), "f"(coeff120[2]), "f"(bez[0]), "f"(coeff120[3]) : "memory");
    o1B = ((f32 *)out)[1];
    o4B = ((f32 *)out)[4];
    p256B = *(f32 *)(config + 256);
    __asm__ volatile(
        "mula.s %0, %1 \n"
        "madda.s %2, %3 \n"
        "madda.s %4, %5 \n"
        "madd.s %6, %7, %8 \n"
        : "=f"(quad110[1]) : "f"(o1B), "f"(coeff120[1]), "f"(p256B), "f"(coeff120[0]), "f"(o4B), "f"(coeff120[2]), "f"(bez[1]), "f"(coeff120[3]) : "memory");
    o2B = ((f32 *)out)[2];
    o5B = ((f32 *)out)[5];
    p260B = *(f32 *)(config + 260);
    __asm__ volatile(
        "mula.s %0, %1 \n"
        "madda.s %2, %3 \n"
        "madda.s %4, %5 \n"
        "madd.s %6, %7, %8 \n"
        : "=f"(quad110[2]) : "f"(o2B), "f"(coeff120[1]), "f"(p260B), "f"(coeff120[0]), "f"(o5B), "f"(coeff120[2]), "f"(bez[2]), "f"(coeff120[3]) : "memory");
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(quad110), "m"(*(u_long128 *)quad110) : "$vf10", "memory");
    if (f12B != 0.0f) {
        __asm__ volatile("sqc2 $vf10, 0(%0)" : "=m"(*(u_long128 *)tmp170) : "r"(tmp170) : "$vf10", "memory");
        vecA[0] = ((f32 *)out)[6];
        vecA[1] = ((f32 *)out)[7];
        vecA[2] = ((f32 *)out)[8];
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(vecA), "m"(*(u_long128 *)vecA) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf11", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmul.xyz $vf2, $vf10, $vf10 \n vmulax.w $ACC, $vf0, $vf2x \n vmadday.w $ACC, $vf0, $vf2y \n vmaddz.w $vf2, $vf0, $vf2z \n vrsqrt $Q, $vf0w, $vf2w \n vwaitq \n vmulq.xyz $vf10, $vf10, $Q \n sqc2 $vf10, 0(%0) \n" : : "r"(tmp1C0) : "$vf2", "$vf10", "$vf11", "ACC", "Q", "memory");
        func_004bd380(tmp1C0, c);
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(tmp1C0), "m"(*(u_long128 *)tmp1C0) : "$vf11", "memory");
        tmp = (s32)(((f32 *)out)[14] * c);
        __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(tmp) : "$vf2", "memory");
        __asm__ volatile("vmulx.xyzw $vf11, $vf11, $vf2x \n" : : : "$vf11", "$vf2", "memory");
        __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(tmp170), "m"(*(u_long128 *)tmp170) : "$vf10", "memory");
        __asm__ volatile("vsub.xyzw $vf10, $vf10, $vf11 \n vmulax.xyzw $ACC, $vf28, $vf10x \n vmadday.xyzw $ACC, $vf29, $vf10y \n vmaddz.xyzw $vf10, $vf30, $vf10z \n vadd.xyzw $vf10, $vf10, $vf11 \n" : : : "$vf10", "$vf11", "ACC", "memory");
    }
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(nodes) : "$vf10", "memory");
    func_0048b220(nodes, config, node10, &b220buf);
    *(f32 *)(nodes + 24) = *(f32 *)(nodes + 24) * ((f32 *)out)[16];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) * ((f32 *)out)[18];
    *(f32 *)(nodes + 28) = *(f32 *)(nodes + 28) + ((f32 *)out)[17];
    func_0048b340(arg0, nodes);
    *(s32 *)(nodes + 16) = node10 + 1;
next_iter2:
next_iter:
    idx += 1;
    out += 76;
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
