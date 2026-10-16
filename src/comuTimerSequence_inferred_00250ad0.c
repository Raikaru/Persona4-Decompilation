#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern s32 D_006367C0[];
extern void sdkSndStartChannel(s32 arg0, const char *arg1);
extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 func_00250ad0(s32 *arg0, u8 *arg1);
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;




extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern f32 sinf(f32 arg0);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 00250ad0-002518d0 */

// FUN_00250AD0
s32 func_00250ad0(s32 *arg0, u8 *arg1)
{
    extern s32 func_0025f430(f32 f0, f32 f1, f32 f2, s32 a0, u8 a1, s32 a2, s32 a3, u8 * a4, s32 a5, s16 a6, s16 a7, f32 f3, f32 f4, f32 f5);
    extern u32 RpRandom(void);
    extern f32 sinf(f32 arg0);
    f32 ra;
    f32 ry;
    f32 fade;
    f32 scale;
    f32 size;
    f32 level;
    f32 fade2;
    f32 rx;
    s32 flags;

    flags = arg0[0];
    if ((flags & 2) || (flags & 4)) {
        if (flags & 4) {
            scale = 0.6f;
        } else {
            scale = 1.0f;
        }
        if (flags & 8) {
            arg0[4]++;
        }
        fade = sinf(1.5707964f + (1.5707964f * (f32)arg0[4]) / 30.0f);
        level = sinf((3.1415927f * (f32)arg0[3]) / 120.0f);
        size = 42.0f * scale;
        func_0025f430(*(f32 *)&arg0[1] - size, *(f32 *)&arg0[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.1f + 0.2f * level) * fade), 0x1B, 0, *(u8 **)(arg1 + 0x10), 1,
                      (s16)size, (s16)size, 0.0f, scale, scale);
        level = (f32)RpRandom() / 2147483648.0f;
        func_0025f430(*(f32 *)&arg0[1] - size, *(f32 *)&arg0[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.1f + 0.4f * level) * fade), 0x1B, 0, *(u8 **)(arg1 + 0x10), 1,
                      (s16)size, (s16)size, 0.0f, scale, scale);
        level = (1.0f + sinf(-1.5707964f + (6.2831855f * (f32)arg0[5]) / (f32)arg0[6])) / 2.0f;
        size = 42.0f * 0.6f;
        func_0025f430(*(f32 *)&arg0[1] - size, *(f32 *)&arg0[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.3f * level) * fade), 0x1B, 0, *(u8 **)(arg1 + 0x10), 1,
                      (s16)size, (s16)size, (360.0f * (f32)arg0[3]) / 120.0f, 0.6f, 0.6f);
        level += 0.2f * ((f32)RpRandom() / 2147483648.0f) - 0.1f;
        if (level < 0.0f) {
            level = 0.0f;
        } else if (!(level <= 1.0f)) {
            level = 1.0f;
        }
        func_0025f430(*(f32 *)&arg0[1] - size, *(f32 *)&arg0[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.3f * level) * fade), 0x1B, 0, *(u8 **)(arg1 + 0x10), 1,
                      (s16)size, (s16)size, (360.0f * (f32)arg0[3]) / 120.0f, 0.6f, 0.6f);
        if (++arg0[5] >= arg0[6]) {
            arg0[5] = 0;
            arg0[6] = (s32)(60.0f + 40.0f * ((f32)RpRandom() / 2147483648.0f));
        }
        if (++arg0[3] >= 120) {
            arg0[3] = 0;
        }
        if (arg0[4] >= 30) {
            return 1;
        }
    } else {
    fade2 = sinf(1.5707964f - (1.5707964f * (f32)arg0[3]) / 30.0f);
    scale = 1.0f + (0.6f * ((f32)RpRandom() / 2147483648.0f) - 0.3f);
    ra = (f32)RpRandom() / 2147483648.0f;
    ry = (f32)RpRandom() / 2147483648.0f;
    rx = (f32)RpRandom() / 2147483648.0f;
    func_0025f430((*(f32 *)&arg0[1] + (f32)p4_0025_span(1.0f, rx)) - 19.0f * scale,
                  (*(f32 *)&arg0[2] + (f32)p4_0025_span(1.0f, ry)) - 19.0f * scale,
                  0.0f, 0xFFFFFF, (u8)(fade2 * (f32)(p4_0025_span(127.0f, ra) + 128)),
                  0x2F, 0, *(u8 **)(arg1 + 0x10), 1, 0, 0, 0.0f, scale, scale);
    if (++arg0[3] >= 30) {
        return 1;
    }
    }
    return 0;
}

// FUN_00251570
u8 *func_00251570(s32 arg0, s32 arg1) {
    u8 *ptr;
    s32 i;

    if (arg1 != 0) {
        goto select_second;
    }
    ptr = (u8 *)(arg0 + 0x780);
    i = 0;
    goto first_test;
first_body:
    if ((*(u32 *)ptr & 1) == 0) {
        memset(ptr, 0, 0x20);
        *(u32 *)ptr |= 1;
        return ptr;
    }
    ptr += 0x20;
    i += 1;
first_test:
    if (i >= 0xC) {
        goto done;
    }
    goto first_body;
select_second:
    if ((u32)(arg1 - 1) >= 2U) {
        goto select_third;
    }
    ptr = (u8 *)(arg0 + 0x900);
    i = 0;
    goto second_test;
second_body:
    if ((*(u32 *)ptr & 1) == 0) {
        memset(ptr, 0, 0x20);
        *(u32 *)ptr |= 1;
        return ptr;
    }
    ptr += 0x20;
    i += 1;
second_test:
    if (i >= 4) {
        goto done;
    }
    goto second_body;
select_third:
    if (arg1 != 3) {
        goto done;
    }
    ptr = (u8 *)(arg0 + 0x980);
    i = 0;
    goto third_test;
third_body:
    if ((*(u32 *)ptr & 1) == 0) {
        memset(ptr, 0, 0x20);
        *(u32 *)ptr |= 1;
        return ptr;
    }
    ptr += 0x20;
    i += 1;
third_test:
    if (i < 3) {
        goto third_body;
    }
done:
    return NULL;
}

// FUN_002516F0
void func_002516f0(u8 *arg0, u8 *arg1) {
    s32 var_17;
    s32 *var_18_2;
    s32 *var_18_3;
    s32 var_17_2;
    s32 var_17_3;
    s32 *var_18;

    var_18 = (s32 *)(arg0 + 0x780);
    var_17 = 0;
    goto loop_5_test;
loop_5_body:
    if ((*var_18 & 1) && (func_00250ad0(var_18, arg1) != 0)) {
        *var_18 &= ~1;
    }
    var_18 = (s32 *)((u8 *)var_18 + 0x20);
    var_17 += 1;
loop_5_test:
    if (var_17 < 0xC) {
        goto loop_5_body;
    }
    var_18_2 = (s32 *)(arg0 + 0x900);
    var_17_2 = 0;
    goto loop_11_test;
loop_11_body:
    if ((*var_18_2 & 1) && (func_00250ad0(var_18_2, arg1) != 0)) {
        *var_18_2 &= ~1;
    }
    var_18_2 = (s32 *)((u8 *)var_18_2 + 0x20);
    var_17_2 += 1;
loop_11_test:
    if (var_17_2 < 4) {
        goto loop_11_body;
    }
    var_18_3 = (s32 *)(arg0 + 0x980);
    var_17_3 = 0;
    goto loop_17_test;
loop_17_body:
    if ((*var_18_3 & 1) && (func_00250ad0(var_18_3, arg1) != 0)) {
        *var_18_3 &= ~1;
    }
    var_18_3 = (s32 *)((u8 *)var_18_3 + 0x20);
    var_17_3 += 1;
loop_17_test:
    if (var_17_3 < 3) {
        goto loop_17_body;
    }
}

// FUN_00251850
void func_00251850(u8 *arg0) {
    s32 var_7;
    u8 *var_6;
    u8 *var_6_2;
    s32 temp_4;
    s32 temp_5;
    s32 var_5;

    var_6 = arg0 + 0x780;
    var_7 = 0;
    goto loop_test;
loop_4:
    temp_5 = *(s32 *)var_6;
    if (temp_5 & 1) {
        *(s32 *)var_6 = temp_5 | 8;
    }
    var_6 += 0x20;
    var_7 += 1;
loop_test:
    if (var_7 < 0xC) {
        goto loop_4;
    }
    var_6_2 = arg0 + 0x900;
    var_5 = 0;
    goto loop_9_test;
loop_9:
    temp_4 = *(s32 *)var_6_2;
    if (temp_4 & 1) {
        *(s32 *)var_6_2 = temp_4 | 8;
    }
    var_6_2 += 0x20;
    var_5 += 1;
loop_9_test:
    if (var_5 < 4) {
        goto loop_9;
    }
}

// FUN_002518D0
void func_002518d0(s32 arg0) {
    if ((arg0 > 0) && (arg0 < 10)) {
        sdkSndStartChannel(2, D_00635C00);
        return;
    }
    if (arg0 == 10) {
        sdkSndStartChannel(2, D_00635C00);
        return;
    }
    if (arg0 == 0) {
        sdkSndStartChannel(2, D_00635C20);
        return;
    }
    if (arg0 == 11) {
        sdkSndStartChannel(2, D_00635C40);
        return;
    }
    if (arg0 == 12) {
        sdkSndStartChannel(2, D_00635C60);
    }
}

