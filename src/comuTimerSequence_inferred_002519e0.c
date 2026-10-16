#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern u32 kwlnTaskGetWork(void *task);
extern void func_0025f230(s32 arg0);
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;




extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern s64 cmmCommunityArcana(s32 arg0);
extern s32 func_0025ef20(u8 *arg0);
extern s32 func_0025f110(s32 arg0);
extern s32 func_0035adc0(s32 arg0, s64 arg1, s32 arg2);
extern s32 func_0035af60(s32 arg0);
extern s32 func_00251f00(s32 arg0, s32 *arg1);
extern void func_00251fc0(s32 arg0, s32 arg1);
extern void func_00252050(s32 arg0, s32 arg1, s32 arg2);
extern void func_002519b0(s32 *arg0);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Source unit: src/promoted/code1_0025.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 002519e0-00251d30 */

// FUN_002519E0
/* Candidate reconstructed from retail dispatch and generated source. */
s32 func_002519e0(u8 *sdkTaskBytes) {
    s32 arg0 = (s32)sdkTaskBytes;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 *temp_2;
    u8 *temp_2_3;

    temp_2 = (s32 *)kwlnTaskGetWork(sdkTaskBytes);
    switch (*temp_2) {
    case 0:
        temp_2[4] = func_0025ef20(D_00635BF0);
        temp_2[0] = 2;
        temp_2[5] = func_0035adc0(arg0, cmmCommunityArcana((u16)temp_2[1]), 0);
        temp_2[6] = func_0035adc0(arg0, -1, 0);
        temp_2[7] = func_00251f00(arg0, temp_2);
        goto block_15;
    case 1:
        return -1;
    case 2:
        if (func_0025f110(temp_2[4]) == 0) {
            goto block_15;
        }
        if (func_0035af60(temp_2[5]) == 0) {
            goto block_15;
        }
        if (func_0035af60(temp_2[6]) == 0) {
            goto block_15;
        }
        temp_2[0] = 3;
        func_00252050(temp_2[7], 0, 4);
        func_00252050(temp_2[7], 0, 5);
        func_00252050(temp_2[7], 0, 6);
        func_00252050(temp_2[7], 0, 7);
        func_00252050(temp_2[7], 0, 8);
        func_00252050(temp_2[7], 0, 9);
        func_00252050(temp_2[7], 0, 0);
        func_00252050(temp_2[7], 0, 1);
        func_00252050(temp_2[7], 0, 2);
        func_00252050(temp_2[7], 0, 3);
        func_00252050(temp_2[7], 2, 0);
        func_00252050(temp_2[7], 1, 0);
        goto block_15;
    case 3:
        temp_2_4 = temp_2[3] + 1;
        temp_2[3] = temp_2_4;
        if (temp_2_4 < 0x1E) {
            goto block_15;
        }
        temp_2[3] = 0;
        temp_2[0] = 4;
        func_00251fc0(temp_2[7], 1);
        goto block_15;
    case 4:
        temp_2_5 = temp_2[3] + 1;
        temp_2[3] = temp_2_5;
        if (temp_2_5 <= 0x1E) {
            goto block_15;
        }
        if ((D_008C024E[0] & 0x40) == 0) {
            goto block_15;
        }
        func_00251fc0(temp_2[7], 0);
        temp_2[3] = 0;
        temp_2[0] = 5;
        goto block_15;
    case 5:
        temp_2_6 = temp_2[3] + 1;
        temp_2[3] = temp_2_6;
        if (temp_2_6 < 0x28) {
            goto block_15;
        }
        temp_2[0] = 1;
        goto block_15;
    default:
        goto block_15;
    }
block_15:
    temp_2_3 = func_00460990();
    *(void **)(temp_2_3 + 8) = (void *)func_002519b0;
    *(s32 *)(temp_2_3 + 0x10) = arg0;
    func_00460ac0(D_007963D0, temp_2_3);
    return 0;
}

// FUN_00251CE0
void func_00251ce0(u8 *task)
{
    void *t;

    t = (s32 *)kwlnTaskGetWork(task);
    func_0025f230(*(s32 *)((u8 *)t + 0x10));
    (*jtbl_008873EC)(t);
}

// FUN_00251D30
u8 *func_00251d30(u8 *arg0) {
    s32 var_3;
    u8 *var_4;

    var_3 = 0;
    var_4 = arg0;
    goto loop_test;
loop_body:
    if ((*(s32 *)var_4 & 1) == 0) {
        return var_4;
    }
    var_4 += 0x78;
    var_3 += 1;
loop_test:
    if (var_3 < 0x10) {
        goto loop_body;
    }
    return NULL;
}

