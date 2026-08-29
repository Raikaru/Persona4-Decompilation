#include "include_asm.h"
#include "type.h"

extern void *func_003e0f80(void);
extern void func_003e0870(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_003e42a0(void *arg0, void *arg1, void *arg2);
extern void func_003e0f40(void *arg0);
extern void func_00371260(u8 *arg0);
extern void func_00375fa0(u8 *arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5,
                           f32 fparg0, f32 fparg1);
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern f32 fGpffff80d8;
extern f32 fGpffff83e4;
extern f32 fGpffff837c;
extern void func_003e40b0(f32 *arg0, f32 *arg1);
extern s32 func_00378530(s32 arg0, s32 arg1);
extern void func_00376330(u8 *arg0, s32 arg1, f32 *arg2);
extern s32 func_003717e0(u8 *arg0, u8 *arg1);
extern f32 func_003e41b0(f32 *arg0);
extern u32 func_003b7060(void);
extern void func_00370290(u8 *arg0, f32 *arg1, f32 fparg0);
extern void func_00375e50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4);
static inline f32 add_retail_order(f32 a, f32 b) {
    return a + b;
}
static inline u8 *code1_0037_add_offset(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

// FUN_00370290
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370290);
// FUN_00370410
void func_00370410(u8 *arg0) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        f32 params[3];
        u32 pad;
        f32 random[3];
    } work;
    u32 value;
    f32 random_value;
    f32 scale;

    *(s32 *)(arg0 + 4) = 0x43340000;
    *(struct Vec3 *)(arg0 + 0x18) = *(struct Vec3 *)(arg0 + 0xC);
    *(f32 *)(arg0 + 0x54) = 10.0f;
    *(f32 *)(arg0 + 0x58) = 10.0f;
    *(s32 *)(arg0 + 0x5C) = 0x3F800000;
    work.random[0] = 0.0f;
    work.random[1] = 0.0f;
    work.random[2] = 0.0f;
    *(struct Vec3 *)(arg0 + 0x24) = *(struct Vec3 *)work.random;

    scale = *(f32 *)(arg0 + 0x54);
    value = func_003b7060() & 0xFFF;
    if (value >= 0) {
        random_value = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        random_value = (f32)(s32)value;
        random_value += random_value;
    }
    work.random[0] = (scale / 2.0f + 0.0f) -
                     scale * (random_value / 4096.0f);

    scale = *(f32 *)(arg0 + 0x54);
    value = func_003b7060() & 0xFFF;
    if (value >= 0) {
        random_value = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        random_value = (f32)(s32)value;
        random_value += random_value;
    }
    work.random[1] = (scale / 2.0f + 0.0f) -
                     (scale * (random_value / 4096.0f)) / 4096.0f;

    scale = *(f32 *)(arg0 + 0x54);
    value = func_003b7060() & 0xFFF;
    if (value >= 0) {
        random_value = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        random_value = (f32)(s32)value;
        random_value += random_value;
    }
    work.random[2] = (scale / 2.0f + 0.0f) -
                     (scale * (random_value / 4096.0f)) / 4096.0f;

    *(struct Vec3 *)(arg0 + 0x48) = *(struct Vec3 *)work.random;
    work.params[0] = 0.0f;
    work.params[1] = 0.0f;
    work.params[2] = *(f32 *)(arg0 + 0x58);
    func_00370290(arg0 + 0x24, work.params, work.params[2]);
}
// FUN_00370640
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370640);
// FUN_00370A80
void func_00370a80(u8 *arg0) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec4 {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct {
        f32 params[3];
        u32 pad;
        f32 random[3];
    } work;
    u32 value;
    f32 random_value;
    f32 scale;

    *(u16 *)(arg0 + 2) = 0xB4;
    *(struct Vec4 *)(arg0 + 0x18) = *(struct Vec4 *)(arg0 + 8);
    *(f32 *)(arg0 + 0x58) = 5.0f;
    *(f32 *)(arg0 + 0x5C) = 15.0f;
    *(f32 *)(arg0 + 0x60) = 15.0f;
    *(s32 *)(arg0 + 0x64) = 0x3F800000;
    *(s32 *)(arg0 + 0x68) = 0x3F800000;
    work.random[0] = 0.0f;
    work.random[1] = 0.0f;
    work.random[2] = 0.0f;
    *(struct Vec3 *)(arg0 + 0x28) = *(struct Vec3 *)work.random;

    scale = *(f32 *)(arg0 + 0x58);
    value = func_003b7060() & 0xFFF;
    if (value >= 0) {
        random_value = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        random_value = (f32)(s32)value;
        random_value += random_value;
    }
    work.random[0] = (scale / 2.0f + 0.0f) -
                     scale * (random_value / 4096.0f);

    scale = *(f32 *)(arg0 + 0x5C);
    value = func_003b7060() & 0xFFF;
    if (value >= 0) {
        random_value = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        random_value = (f32)(s32)value;
        random_value += random_value;
    }
    work.random[1] = (scale / 2.0f + 0.0f) -
                     scale * (random_value / 4096.0f);

    scale = *(f32 *)(arg0 + 0x60);
    value = func_003b7060() & 0xFFF;
    if (value >= 0) {
        random_value = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        random_value = (f32)(s32)value;
        random_value += random_value;
    }
    work.random[2] = (scale / 2.0f + 0.0f) -
                     scale * (random_value / 4096.0f);

    *(struct Vec3 *)(arg0 + 0x4C) = *(struct Vec3 *)work.random;
    work.params[0] = 0.0f;
    work.params[1] = 0.0f;
    work.params[2] = *(f32 *)(arg0 + 0x64);
    func_00370290(arg0 + 0x28, work.params, work.params[2]);
}
// FUN_00370CD0
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370cd0);
// FUN_00371160
void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, u8 *arg3) {
    f32 sp70[3];
    void *temp_16;

    temp_16 = func_003e0f80();
    sp70[0] = *(f32 *)(arg2 + 0) - *(f32 *)(arg0 + 0);
    sp70[1] = *(f32 *)(arg2 + 4) - *(f32 *)(arg0 + 4);
    sp70[2] = *(f32 *)(arg2 + 8) - *(f32 *)(arg0 + 8);
    func_003e0870(temp_16, arg1, fparg0, 0);
    func_003e42a0(arg3, sp70, temp_16);
    *(f32 *)(arg3 + 0) += *(f32 *)(arg0 + 0);
    *(f32 *)(arg3 + 4) += *(f32 *)(arg0 + 4);
    *(f32 *)(arg3 + 8) += *(f32 *)(arg0 + 8);
    func_003e0f40(temp_16);
}
// measured: opt_propagation off probe for 00379e90 load order
#pragma opt_propagation off
// FUN_00379E90
void func_00379e90(u8 *arg0, s32 arg1, f32 *arg2) {
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 pad4c;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 pad5c;
        f32 sp60;
        f32 sp64;
        f32 sp68;
    } work;
    f32 temp_f2;

    func_00371260((u8 *)&work.sp60);
    work.sp64 = work.sp64 - 25.0f;
    work.sp50 = work.sp60;
    work.sp54 = work.sp64;
    temp_f2 = work.sp68;
    work.sp58 = add_retail_order(temp_f2, 200.0f);
    work.sp40 = 0.0f;
    work.sp44 = func_0044b610(fGpffff80d8);
    work.sp48 = -func_0044b7b0(fGpffff80d8);
    if (arg2 != NULL) {
        func_00371160((u8 *)&work.sp50, (u8 *)&work.sp40, (u8 *)&work.sp60, 0.0f, (u8 *)arg2);
        return;
    }
    func_00375fa0(arg0, arg1, 0, &work.sp40, &work.sp50, &work.sp60, 0.0f, 0.0f);
}
// measured: close opt_propagation off probe for 00379e90
#pragma opt_propagation on
// FUN_00379F90
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00379f90);
// FUN_0037AB50
void func_0037ab50(u8 *arg0, s32 arg1, f32 *arg2) {
    struct {
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 pad5c;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 pad6c;
        f32 sp70;
        f32 sp74;
        f32 sp78;
    } work;
    f32 temp_f20;
    f32 temp_f2;
    f32 zero;
    s32 parity;

    func_00371260((u8 *)&work.sp70);
    work.sp74 = work.sp74 - 25.0f;
    work.sp60 = work.sp70;
    work.sp64 = work.sp74;
    temp_f2 = work.sp78;
    work.sp68 = add_retail_order(temp_f2, 200.0f);
    parity = arg1 & 1;
    if ((arg1 < 0) && (parity != 0)) {
        parity -= 2;
    }
    if (parity == 0) {
        temp_f20 = -func_0044b610(fGpffff83e4);
        work.sp50 = temp_f20 * func_0044b7b0(fGpffff837c);
        temp_f20 = -func_0044b610(fGpffff83e4);
        work.sp54 = temp_f20 * func_0044b610(fGpffff837c);
        work.sp58 = func_0044b7b0(fGpffff83e4);
        zero = 0.0f;
    } else {
        temp_f20 = -func_0044b610(fGpffff83e4);
        work.sp50 = temp_f20 * func_0044b7b0(fGpffff837c);
        temp_f20 = func_0044b610(fGpffff83e4);
        work.sp54 = temp_f20 * func_0044b610(fGpffff837c);
        work.sp58 = -func_0044b7b0(fGpffff83e4);
        zero = 0.0f;
    }
    if (arg2 != NULL) {
        func_00371160((u8 *)&work.sp60, (u8 *)&work.sp50,
                      (u8 *)&work.sp70, zero, (u8 *)arg2);
        return;
    }
    func_00375fa0(arg0, arg1, 0, &work.sp50, &work.sp60,
                  &work.sp70, zero, zero);
}
// FUN_0037AD10
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037ad10);
// FUN_0037B8C0
void func_0037b8c0(u8 *arg0, s32 arg1, f32 *arg2) {
    struct {
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 pad5c;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 pad6c;
        f32 sp70;
        f32 sp74;
        f32 sp78;
    } work;
    f32 temp_f20;
    s32 temp_hi;

    func_00371260((u8 *)&work.sp70);
    work.sp74 = work.sp74 - 25.0f;
    work.sp60 = work.sp70;
    work.sp64 = work.sp74;
    work.sp68 = add_retail_order(work.sp78, 200.0f);
    temp_hi = arg1 % 3;
    switch (temp_hi) {
    case 0:
        work.sp50 = 0.0f;
        work.sp54 = func_0044b610(fGpffff80d8);
        work.sp58 = -func_0044b7b0(fGpffff80d8);
        break;
    case 1:
        temp_f20 = -func_0044b610(fGpffff80d8);
        work.sp50 = temp_f20 * func_0044b7b0(fGpffff837c);
        temp_f20 = -func_0044b610(fGpffff80d8);
        work.sp54 = temp_f20 * func_0044b610(fGpffff837c);
        work.sp58 = func_0044b7b0(fGpffff80d8);
        break;
    case 2:
        temp_f20 = -func_0044b610(fGpffff80d8);
        work.sp50 = temp_f20 * func_0044b7b0(fGpffff837c);
        temp_f20 = func_0044b610(fGpffff80d8);
        work.sp54 = temp_f20 * func_0044b610(fGpffff837c);
        work.sp58 = -func_0044b7b0(fGpffff80d8);
        break;
    }
    if (arg2 != NULL) {
        func_00371160((u8 *)&work.sp60, (u8 *)&work.sp50,
                      (u8 *)&work.sp70, 0.0f, (u8 *)arg2);
        return;
    }
    func_00375fa0(arg0, arg1, 0, &work.sp50, &work.sp60,
                  &work.sp70, 0.0f, 0.0f);
}
// FUN_0037BAC0
void func_0037bac0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        struct Vec3 base;
        struct Vec3 first;
        struct Vec3 second;
        struct Vec3 output;
    } points;
    f32 x_offset;
    f32 y_offset;
    s32 remainder;

    x_offset = 150.0f;
    y_offset = 100.0f;
    points.base = *(struct Vec3 *)(code1_0037_add_offset(arg1 * 0xE8, arg0) +
                                   0x1D6B8);
    func_0037b8c0(arg0, 0, &points.output.x);
    remainder = arg1 % 3;
    switch (remainder) {
    case 0:
        y_offset = y_offset * (f32)(remainder - remainder);
        break;
    case 1:
        x_offset = x_offset * -1.0f;
        break;
    case 2:
        break;
    }
    points.first.x = x_offset +
                     (points.base.x +
                      (points.output.x - points.base.x) / 3.0f);
    points.first.y = y_offset +
                     (points.base.y +
                      (points.output.y - points.base.y) / 3.0f);
    points.first.z = points.base.z +
                     (points.output.z - points.base.z);
    points.second.x = x_offset +
                      (points.base.x +
                       (2.0f * (points.output.x - points.base.x)) / 3.0f);
    points.second.y = y_offset +
                      (points.base.y +
                       (2.0f * (points.output.y - points.base.y)) / 3.0f);
    points.second.z = points.first.z;
    func_00375e50(arg0, arg1, arg2, arg3, &points.base.x);
}
// FUN_0037BC80
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037bc80);
// FUN_0037ED90
s32 func_0037ed90(u8 *arg0, s32 arg1) {
    f32 work[4];
    f32 screen[2];
    f32 delta[2];
    f32 target_x;
    f32 best_dist;
    f32 target_y;
    f32 dist;
    s32 count;
    s32 i;
    s32 best;

    target_x = (f32)((arg1 / 3 - 1) * 0x6B) + 314.0f;
    target_y = (f32)(arg1 % 3 - 1) * 120.0f + 236.0f;
    count = func_00378530(*(s32 *)(arg0 + 0x1F304),
                          *(s32 *)(arg0 + 0x1F2FC));
    func_00376330(arg0, 0, work);
    func_003717e0((u8 *)work, (u8 *)screen);
    delta[0] = screen[0] - target_x;
    delta[1] = screen[1] - target_y;
    best_dist = func_003e41b0(delta);
    i = 1;
    best = 0;
    while (i < count) {
        func_00376330(arg0, i, work);
        func_003717e0((u8 *)work, (u8 *)screen);
        delta[0] = screen[0] - target_x;
        delta[1] = screen[1] - target_y;
        dist = func_003e41b0(delta);
        if (dist < best_dist) {
            best = i;
            best_dist = dist;
        }
        i++;
    }
    return best;
}
