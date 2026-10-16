#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
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

extern void func_004823e0(u8 *arg0);
extern void func_00481f30(u8 *arg0, s32 arg1);
extern u8 *func_00482230(s32 *arg0);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 TnUploadStreamTagged(s32 arg0);
extern void func_003ef3a0(void *arg0);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Source unit: src/promoted/code1_0048.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0048.c; members 00481f30-004824a0 */

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
        kAssertFail(D_007132F0, 0xCB);
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
                kAssertFail(D_007132F0, 0xB0);
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
                    kAssertFail(D_007132F0, 0xB0);
                }
                temp_5_2 = (s32 *)(*(u8 **)(temp_19 + 4) + temp_16);
                temp_4_3 = *(u8 **)(temp_19 + 0) + *temp_5_2;
                *(s32 *)(temp_18_2 + 4) = 0;
                *(s32 *)(temp_18_2 + 8) = *(s16 *)(temp_4_3 + 0x12);
                *(s32 **)(temp_18_2 + 0xC) = temp_5_2;
                *(u8 **)(temp_18_2 + 0x10) = temp_4_3;
                temp_16_3 = *(u8 **)(arg0 + 0x10) + 0x14;
                if (*(s32 *)(*(u8 **)(temp_19 + 0) + 4) <= (arg1 + 1)) {
                    kAssertFail(D_007132F0, 0xB0);
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
                    kAssertFail(D_007132F0, 0xB0);
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
/* measured: func_00482230 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off preserves the target pointer evaluation order. */
/* measured: func_00482230 MATCH -> MISMATCH without this pragma. */
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
    chkmemAllocSiteTag(D_007132F0, 0x114);
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
        temp_3 = TnUploadStreamTagged((s32)((u8 *)arg0 + *var_18));
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
/* measured: restore opt_loop_invariants after func_00482230. */
// FUN_004823E0
void func_004823e0(u8 *arg0) {
    s32 temp_3;
    s32 var_17;

    if ((arg0 == NULL) || (*(s32 *)(arg0 + 0x10) == 0)) {
        kAssertFail(D_007132F0, 0x151);
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

