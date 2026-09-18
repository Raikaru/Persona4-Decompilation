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
extern void func_003dc740(void *arg0, void *arg1, f32 fparg0, s32 arg2);
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
void func_00370290(u8 *arg0, f32 *arg1, f32 fparg0) {
    f32 first[3];
    f32 second[3];
    s8 buf[0xC];
    s8 *p;
    s32 count;
    f32 cross[3];
    f32 result[3];

    p = buf;
    count = 0xC;
    if (p != NULL) {
        do {
            *p = 0;
            p += 1;
            count -= 1;
        } while (count != 0);
    }
    *(f32 *)(arg0 + 0x0C) = *(f32 *)(arg0 + 0x00) + arg1[0];
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0x04) + arg1[1];
    *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x08) + arg1[2];

    first[0] = ((f32 *)buf)[0] - *(f32 *)(arg0 + 0x24);
    first[1] = ((f32 *)buf)[1] - ((f32 *)(arg0 + 0x24))[1];
    first[2] = ((f32 *)buf)[2] - ((f32 *)(arg0 + 0x24))[2];
    second[0] = *(f32 *)(arg0 + 0x24) - *(f32 *)(arg0 + 0x00);
    second[1] = *(f32 *)(arg0 + 0x28) - *(f32 *)(arg0 + 0x04);
    second[2] = *(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x08);
    func_003e40b0(&first[0], &first[0]);
    func_003e40b0(&second[0], &second[0]);

    cross[0] = second[1] * first[2] - second[2] * first[1];
    cross[1] = second[2] * first[0] - second[0] * first[2];
    cross[2] = second[0] * first[1] - second[1] * first[0];
    result[0] = cross[1] * first[2] - cross[2] * first[1];
    result[1] = cross[2] * first[0] - cross[0] * first[2];
    result[2] = cross[0] * first[1] - cross[1] * first[0];

    result[0] *= fparg0;
    result[1] *= fparg0;
    result[2] *= fparg0;

    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg0 + 0x24) + result[0];
    *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg0 + 0x28) + result[1];
    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x2C) + result[2];
}
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
void func_00370640(u8 *arg0) {
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
    f32 t;
    f32 one_minus_t;

    t = (f32)(*(u16 *)(arg0 + 0) += 1) /
        *(f32 *)(arg0 + 4);
    if ((f32)*(u16 *)(arg0 + 0) >= *(f32 *)(arg0 + 4)) {
        work.random[0] = *(f32 *)(arg0 + 0x3C) - *(f32 *)(arg0 + 0x48);
        work.random[1] = *(f32 *)(arg0 + 0x40) - *(f32 *)(arg0 + 0x4C);
        work.random[2] = *(f32 *)(arg0 + 0x44) - *(f32 *)(arg0 + 0x50);
        work.params[0] = -work.random[0];
        work.params[1] = -work.random[1];
        work.params[2] = -work.random[2];
        *(struct Vec3 *)(arg0 + 0x24) = *(struct Vec3 *)(arg0 + 0x48);

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
        work.random[2] = (scale / 2.0f + 0.0f) -
                         scale * (random_value / 4096.0f);

        *(struct Vec3 *)(arg0 + 0x48) = *(struct Vec3 *)work.random;
        func_00370290(arg0 + 0x24, work.params, *(f32 *)(arg0 + 0x58));
        *(u16 *)(arg0 + 0) = 0;
        t = 0.0f;
    }
    one_minus_t = 1.0f - t;
    *(f32 *)(arg0 + 0x0C) =
        one_minus_t * (one_minus_t *
                       (*(f32 *)(arg0 + 0x24) * one_minus_t)) +
        one_minus_t * (one_minus_t *
                       (3.0f * *(f32 *)(arg0 + 0x30) * t)) +
        one_minus_t * (t * (3.0f * *(f32 *)(arg0 + 0x3C) * t)) +
        t * (t * (*(f32 *)(arg0 + 0x48) * t));
    *(f32 *)(arg0 + 0x10) =
        one_minus_t * (one_minus_t *
                       (*(f32 *)(arg0 + 0x28) * one_minus_t)) +
        one_minus_t * (one_minus_t *
                       (3.0f * *(f32 *)(arg0 + 0x34) * t)) +
        one_minus_t * (t * (3.0f * *(f32 *)(arg0 + 0x40) * t)) +
        t * (t * (*(f32 *)(arg0 + 0x4C) * t));
    *(f32 *)(arg0 + 0x14) =
        one_minus_t * (one_minus_t *
                       (*(f32 *)(arg0 + 0x2C) * one_minus_t)) +
        one_minus_t * (one_minus_t *
                       (3.0f * *(f32 *)(arg0 + 0x38) * t)) +
        one_minus_t * (t * (3.0f * *(f32 *)(arg0 + 0x44) * t)) +
        t * (t * (*(f32 *)(arg0 + 0x50) * t));
    *(f32 *)(arg0 + 0x0C) *= *(f32 *)(arg0 + 0x5C);
    *(f32 *)(arg0 + 0x10) *= *(f32 *)(arg0 + 0x5C);
    *(f32 *)(arg0 + 0x14) *= *(f32 *)(arg0 + 0x5C);
    *(f32 *)(arg0 + 0x0C) += *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 0x10) += *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0x14) += *(f32 *)(arg0 + 0x20);
}
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
void func_00370cd0(u8 *arg0) {
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
        f32 rotation[4];
        s32 axis[3];
        u32 axis_pad;
        struct {
            f32 params[3];
            u32 pad;
            f32 random[3];
        } work;
    } locals;
    f32 *rotation_ptr;
    f32 duration;
    f32 t;
    f32 one_minus_t;
    f32 x;
    f32 y;
    f32 z;

    duration = (f32)*(u16 *)(arg0 + 2);
    t = (f32)(*(u16 *)(arg0 + 0) += 1) / duration;
    if (*(u16 *)(arg0 + 0) >= *(u16 *)(arg0 + 2)) {
        f32 scale;
        u32 value;
        f32 random_value;
        locals.work.random[0] = *(f32 *)(arg0 + 0x40) - *(f32 *)(arg0 + 0x4C);
        locals.work.random[1] = *(f32 *)(arg0 + 0x44) - *(f32 *)(arg0 + 0x50);
        locals.work.random[2] = *(f32 *)(arg0 + 0x48) - *(f32 *)(arg0 + 0x54);
        locals.work.params[0] = -locals.work.random[0];
        locals.work.params[1] = -locals.work.random[1];
        locals.work.params[2] = -locals.work.random[2];
        *(struct Vec3 *)(arg0 + 0x28) = *(struct Vec3 *)(arg0 + 0x4C);

        scale = *(f32 *)(arg0 + 0x58);
        value = func_003b7060() & 0xFFF;
        if (value >= 0) {
            random_value = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            random_value = (f32)(s32)value;
            random_value += random_value;
        }
        locals.work.random[0] = (scale / 2.0f + 0.0f) -
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
        locals.work.random[1] = (scale / 2.0f + 0.0f) -
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
        locals.work.random[2] = (scale / 2.0f + 0.0f) -
                         scale * (random_value / 4096.0f);

        *(struct Vec3 *)(arg0 + 0x4C) = *(struct Vec3 *)locals.work.random;
        func_00370290(arg0 + 0x28, locals.work.params, *(f32 *)(arg0 + 0x64));
        *(u16 *)(arg0 + 0) = 0;
        t = 0.0f;
    }

    one_minus_t = 1.0f - t;
    x = one_minus_t * (one_minus_t *
                       (*(f32 *)(arg0 + 0x28) * one_minus_t)) +
        one_minus_t * (one_minus_t *
                       (3.0f * *(f32 *)(arg0 + 0x34) * t)) +
        one_minus_t * (t * (3.0f * *(f32 *)(arg0 + 0x40) * t)) +
        t * (t * (*(f32 *)(arg0 + 0x4C) * t));
    y = one_minus_t * (one_minus_t *
                       (*(f32 *)(arg0 + 0x2C) * one_minus_t)) +
        one_minus_t * (one_minus_t *
                       (3.0f * *(f32 *)(arg0 + 0x38) * t)) +
        one_minus_t * (t * (3.0f * *(f32 *)(arg0 + 0x44) * t)) +
        t * (t * (*(f32 *)(arg0 + 0x50) * t));
    z = one_minus_t * (one_minus_t *
                       (*(f32 *)(arg0 + 0x30) * one_minus_t)) +
        one_minus_t * (one_minus_t *
                       (3.0f * *(f32 *)(arg0 + 0x3C) * t)) +
        one_minus_t * (t * (3.0f * *(f32 *)(arg0 + 0x48) * t)) +
        t * (t * (*(f32 *)(arg0 + 0x54) * t));

    x *= *(f32 *)(arg0 + 0x68);
    y *= *(f32 *)(arg0 + 0x68);
    z *= *(f32 *)(arg0 + 0x68);
    rotation_ptr = locals.rotation;
    *(struct Vec4 *)rotation_ptr = *(struct Vec4 *)(arg0 + 0x18);
    locals.axis[0] = 0x3F800000;
    locals.axis[1] = 0;
    locals.axis[2] = 0;
    func_003dc740(rotation_ptr, locals.axis, x, 2);
    locals.axis[0] = 0;
    locals.axis[1] = 0x3F800000;
    locals.axis[2] = 0;
    func_003dc740(rotation_ptr, locals.axis, y, 2);
    locals.axis[0] = 0;
    locals.axis[1] = 0;
    locals.axis[2] = 0x3F800000;
    func_003dc740(rotation_ptr, locals.axis, z, 2);
    *(struct Vec4 *)(arg0 + 8) = *(struct Vec4 *)locals.rotation;
}
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
/* measured 00379f90: probe 680 words, retail 750 vs object 742 instrs (8 short, 1.1% inside gate; fnalign 230 edits +8 reloc-only). Frame 0xE0 vs retail 0xF0 (arg0 $s4 vs $s1, systematic $s1/$s4 + $s3/$s1 + $s0/$s3 coloring). Switch 16-state on *(u32*)(arg0+0x1F2F8) via jtbl_00752A20 (case 6 shares default 0x37aaac, omitted like 0037bc80; 1->2, 4->5, 5->7, 7->8, 8->9, 10->11, 12->13 fallthroughs). Case0 gate on *(+0x1F30C) with ++1F2F0, inner 0x1A/0.6f + 0x14/0.7f + 0x10/0.8f (gp -0x7E90/-0x7F64/-0x7C74), (f32)(u32)dur, D_0064EAC0 0x38; case3 79e90+150.0f/3.0f/2.0f via base/first/second/output + 75e50 (mod*i, +0x14); case4 sel-based m=(mod*(count-sel))&FFFF, 79e90, v2/v1/v0 + 75fa0 0.0f+(360/count)*(count-sel) adda/madd, D_0064EAC0 0x5F; default D_0064EAC0 0x1B6. Free pragmas: dead +5, prop +11, sched +4, common +55, loop/peephole/unroll/strength tie (bare kept, unlike bc80 dead-off). m2c jr/jtbl fails without rodata; romwright+Ghidra+IDA+generated used. */
// FUN_00379F90 NONMATCHING
#ifdef NON_MATCHING
s32 func_00379f90(u8 *arg0) {
    extern s32 func_00378a70(u8 *arg0, s32 arg1);
    extern s32 func_00379240(u8 *arg0);
    extern s32 func_00379420(u8 *arg0);
    extern void func_0038d060(u8 *arg0);
    extern void func_0038d0d0(u8 *arg0, s32 arg1);
    extern void func_0038d0a0(u8 *arg0);
    extern s32 func_00375970(u8 *arg0);
    extern s32 func_00375910(u8 *arg0);
    extern void func_00375b40(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00375890(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_00376590(u8 *arg0, u8 *arg1);
    extern void func_00388f40(u8 *arg0);
    extern void func_00389110(u8 *arg0);
    extern s32 func_00389160(u8 *arg0);
    extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_0046d730(const void *file, u32 line);
    extern char D_0064EAC0[];
    extern u16 D_008C024E;
    extern s32 func_00106330(s32 arg0);
    extern void func_00106390(s32 arg0, s32 arg1);
    extern u16 func_00378bf0(void);
    extern s32 func_00378c80(u8 *arg0, s32 arg1, s32 arg2);
    extern void func_00378df0(u8 *arg0, s32 arg1);
    extern void func_003798d0(u8 *arg0, s32 arg1);
    extern s32 func_00379920(u8 *arg0);
    extern void func_003799d0(u8 *arg0);
    extern s32 func_00379a70(u8 *arg0);
    extern s32 func_00379c70(u8 *arg0, s32 arg1);
    extern s32 func_00379d70(u8 *arg0);
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
        struct Vec3 v0;
        struct Vec3 v1;
        struct Vec3 v2;
    } work;
    f32 factor;
    f32 f0;
    f32 f1;
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    s32 mod;
    s32 i;
    s32 sel;
    s32 m;
    u16 dur;
    sbase = arg0 + 0x1F1D0;
    mod = ((s32)*(u16 *)(sbase + 2) / *(s32 *)(arg0 + 0x1F304)) & 0xFFFF;
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (*(s32 *)(arg0 + 0x1F30C) != 0) {
            *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
            if (func_00378a70(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
                break;
            }
        }
        sbase2 = sbase;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)(sbase2 + 2) = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            *(u16 *)(sbase2 + 2) = 0x14;
            factor = 0.7f;
            break;
        case 2:
            *(u16 *)(sbase2 + 2) = 0x10;
            factor = 0.8f;
            break;
        default:
            func_0046d730(D_0064EAC0, 0x38);
            break;
        }
        dur = *(u16 *)(sbase2 + 2);
        f0 = (f32)(u32)dur;
        f1 = factor * (f32)(*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f;
        f1 = 1.0f + f1;
        f1 = f0 * f1;
        *(u16 *)(sbase2 + 2) = (u16)f1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(s32 *)(sbase + 0xC) = -1;
        if (func_00379240(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (func_00379420(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2: {
        u16 tmp = *(u16 *)(arg0 + 0x1F2F0) + 1;
        *(u16 *)(arg0 + 0x1F2F0) = tmp;
        if (((s32)(tmp & 0xFFFF) < 0)) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    }
    case 3:
        if ((D_008C024E & 0x40) != 0) {
            deck = *(u8 **)(arg0 + 0x1F298);
            func_0038d0a0(deck);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(s32 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                work.base = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6B8);
                func_00379e90(arg0, 0, &work.output.x);
                work.first.x = work.base.x + (work.output.x - work.base.x) / 3.0f + 150.0f;
                work.first.y = work.base.y + (work.output.y - work.base.y) / 3.0f;
                work.first.z = work.base.z - (work.output.z - work.base.z);
                work.second.x = work.base.x + (2.0f * (work.output.x - work.base.x)) / 3.0f + 150.0f;
                work.second.y = work.base.y + (2.0f * (work.output.y - work.base.y)) / 3.0f;
                work.second.z = work.base.z + (work.output.z - work.base.z);
                m = (mod * i) & 0xFFFF;
                func_00375e50(arg0, i, m & 0xFFFF, (m + 0x14) & 0xFFFF, &work.base.x);
            }
            func_0045af60(0, 4, 0, 1);
        } else if ((D_008C024E & 0x20) != 0) {
            func_003799d0(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 4:
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) != 0) {
                func_00375b40(arg0, i, 0, 0xA);
                sel = *(s32 *)(sbase + 8);
                m = (mod * (*(s32 *)(arg0 + 0x1F304) - sel)) & 0xFFFF;
                if (sel >= *(s32 *)(arg0 + 0x1F304)) {
                    func_0046d730(D_0064EAC0, 0x5F);
                }
                func_00379e90(arg0, i, (f32 *)0);
                work.v2 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6CC);
                work.v1 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6D8);
                work.v0 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6E4);
                func_00375fa0(arg0, i, m, &work.v2.x, &work.v1.x, &work.v0.x, 0.0f, 0.0f + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)) * (f32)(*(s32 *)(arg0 + 0x1F304) - sel));
                (*(s32 *)(sbase + 8))++;
            }
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if (*(s32 *)(sbase + 8) != *(s32 *)(arg0 + 0x1F304)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) | 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u16 *)(sbase + 4) = func_00378bf0();
    case 5: {
        u16 tmp = *(u16 *)(arg0 + 0x1F2F0) + 1;
        *(u16 *)(arg0 + 0x1F2F0) = tmp;
        if ((tmp & 0xFFFF) < *(u16 *)(sbase + 4)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    }
    case 7:
        if (func_00106330(0x1431) == 0) {
            func_003798d0(arg0, 1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) | 2;
            break;
        }
        func_00389110(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if (func_00389160(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 2);
        *(u32 *)(arg0 + 0x1F2F8) = 9;
    case 9:
        if ((D_008C024E & 0x40) == 0) {
            break;
        }
        *(s32 *)(sbase + 0xC) = func_00376590(arg0, (u8 *)0);
        func_00388f40(*(u8 **)(arg0 + 0x1F294));
        func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
        func_0045af60(1, 2, 2, 0xD);
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        break;
    case 10:
        if (func_00375970(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        func_00378df0(arg0, *(s32 *)(sbase + 0xC));
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00376290(arg0, i, 0xF, 0xFF, 0);
            }
        }
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (func_00375910(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00375890(arg0, i, 0);
            }
        }
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) & 0xFFFE;
        func_00379c70(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
        break;
    case 12:
        if (func_00379d70(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        return 1;
    case 14:
        if (func_00379a70(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 15:
        if (func_00379920(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if ((*(u16 *)(arg0 + 0x1F2F0) & 0xFFFF) < 0x1E) {
            break;
        }
        func_00106390(0x1431, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 7;
        break;
    default:
        func_0046d730(D_0064EAC0, 0x1B6);
        break;
    }
    if (*(u16 *)(sbase + 0) & 1) {
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00378c80(arg0, i, mod);
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00379f90);
#endif
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
extern s32 func_00378a70(u8 *arg0, s32 arg1);
extern s32 func_00379240(u8 *arg0);
extern s32 func_00379420(u8 *arg0);
extern void func_0038d060(u8 *arg0);
extern void func_0038d0d0(u8 *arg0, s32 arg1);
extern void func_0038d0a0(u8 *arg0);
extern s32 func_00375970(u8 *arg0);
extern s32 func_00375910(u8 *arg0);
extern void func_00375b40(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00375890(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_00376590(u8 *arg0, u8 *arg1);
extern void func_00388f40(u8 *arg0);
extern void func_00389110(u8 *arg0);
extern s32 func_00389160(u8 *arg0);
extern void func_0045af60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_0046d730(const void *file, u32 line);
extern char D_0064EAE0[];
extern char D_0064EB00[];
extern u16 D_008C024E;
extern s32 func_00106330(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern u16 func_00378bf0(void);
extern s32 func_00378c80(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00378df0(u8 *arg0, s32 arg1);
extern void func_003798d0(u8 *arg0, s32 arg1);
extern s32 func_00379920(u8 *arg0);
extern void func_003799d0(u8 *arg0);
extern s32 func_00379a70(u8 *arg0);
extern s32 func_00379c70(u8 *arg0, s32 arg1);
extern s32 func_00379d70(u8 *arg0);
// measured: shuffle-draw state machine fully recovered (16-state switch on *(u32*)(arg0+0x1F2F8) with 1->2 and 4->5->7->8->9 plus 10->11 and 12->13 fallthroughs, 0.6f/0.7f/0.8f pool at gp-0x7E90/-0x7F64/-0x7C74 confirmed at orig 0x761260/0x76118c/0x76147c, (f32)(u32) u16 at +2, 0.0f+(360/count)*(count-sel) adda/madd for func_00375fa0); floor object 2956B/window 2992B (36B short, 1.2%), normalized_diff 2343, frame 0xE0 vs retail 0xF0 (6 vs 7 saved, arg0 in $s4 vs $s1); remaining walls are saved-reg coloring and scheduling residuals. Keep ASM until coloring closes.
/* measured 0037ad10: `schedule on` inside the guard is worth 2 words (683 -> 681). */
/* measured 0037ad10: `opt_propagation off` inside the guard is worth 1 words (681 -> 680). */
// FUN_0037AD10 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_propagation off
#pragma schedule on
s32 func_0037ad10(u8 *arg0) {
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
        struct Vec3 v0;
        struct Vec3 v1;
        struct Vec3 v2;
    } work;
    f32 factor;
    f32 f0;
    f32 f1;
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    s32 mod;
    s32 i;
    s32 sel;
    s32 m;
    s32 parity;
    u16 dur;
    sbase = arg0 + 0x1F1D0;
    mod = ((s32)*(u16 *)(sbase + 2) / *(s32 *)(arg0 + 0x1F304)) & 0xFFFF;
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (func_00378a70(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        sbase2 = sbase;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)(sbase2 + 2) = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            *(u16 *)(sbase2 + 2) = 0x14;
            factor = 0.7f;
            break;
        case 2:
            *(u16 *)(sbase2 + 2) = 0x10;
            factor = 0.8f;
            break;
        default:
            func_0046d730(D_0064EAE0, 0x3A);
            break;
        }
        dur = *(u16 *)(sbase2 + 2);
        f0 = (f32)(u32)dur;
        f1 = factor * (f32)(*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f;
        f1 = 1.0f + f1;
        f1 = f0 * f1;
        *(u16 *)(sbase2 + 2) = (u16)f1;
        *(s32 *)(sbase + 0xC) = -1;
        if (func_00379240(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (func_00379420(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2: {
        u16 tmp = *(u16 *)(arg0 + 0x1F2F0) + 1;
        *(u16 *)(arg0 + 0x1F2F0) = tmp;
        if (((s32)(tmp & 0xFFFF) < 0)) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    }
    case 3:
        if ((D_008C024E & 0x40) != 0) {
            deck = *(u8 **)(arg0 + 0x1F298);
            func_0038d0a0(deck);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(s32 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                f32 x_off = 150.0f;
                parity = i & 1;
                if ((i < 0) && (parity != 0)) {
                    parity -= 2;
                }
                if (parity == 0) {
                    x_off = x_off * -1.0f;
                }
                work.base = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6B8);
                func_0037ab50(arg0, 0, &work.output.x);
                work.first.x = x_off + (work.base.x + (work.output.x - work.base.x) / 3.0f);
                work.first.y = 100.0f + (work.base.y + (work.output.y - work.base.y) / 3.0f);
                work.first.z = work.base.z + (work.output.z - work.base.z);
                work.second.x = x_off + (work.base.x + (2.0f * (work.output.x - work.base.x)) / 3.0f);
                work.second.y = 100.0f + (work.base.y + (2.0f * (work.output.y - work.base.y)) / 3.0f);
                work.second.z = work.first.z;
                m = (mod * i) & 0xFFFF;
                func_00375e50(arg0, i, m & 0xFFFF, (m + 0x14) & 0xFFFF, &work.base.x);
            }
            func_0045af60(0, 4, 0, 1);
        } else if ((D_008C024E & 0x20) != 0) {
            func_003799d0(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 4:
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) != 0) {
                func_00375b40(arg0, i, 0, 0xA);
                sel = *(s32 *)(sbase + 8);
                m = (mod * (*(s32 *)(arg0 + 0x1F304) - sel)) & 0xFFFF;
                if (sel >= *(s32 *)(arg0 + 0x1F304)) {
                    func_0046d730(D_0064EAE0, 0x6B);
                }
                func_0037ab50(arg0, i, (f32 *)0);
                work.v2 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6CC);
                work.v1 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6D8);
                work.v0 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6E4);
                func_00375fa0(arg0, i, m, &work.v2.x, &work.v1.x, &work.v0.x, 0.0f, 0.0f + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)) * (f32)(*(s32 *)(arg0 + 0x1F304) - sel));
                (*(s32 *)(sbase + 8))++;
            }
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if (*(s32 *)(sbase + 8) != *(s32 *)(arg0 + 0x1F304)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) | 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u16 *)(sbase + 4) = func_00378bf0();
    case 5: {
        u16 tmp = *(u16 *)(arg0 + 0x1F2F0) + 1;
        *(u16 *)(arg0 + 0x1F2F0) = tmp;
        if ((tmp & 0xFFFF) < *(u16 *)(sbase + 4)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    }
    case 7:
        if (func_00106330(0x1431) == 0) {
            func_003798d0(arg0, 1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) | 2;
            break;
        }
        func_00389110(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if (func_00389160(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 2);
        *(u32 *)(arg0 + 0x1F2F8) = 9;
    case 9:
        if ((D_008C024E & 0x40) == 0) {
            break;
        }
        *(s32 *)(sbase + 0xC) = func_00376590(arg0, (u8 *)0);
        func_00388f40(*(u8 **)(arg0 + 0x1F294));
        func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
        func_0045af60(1, 2, 2, 0xD);
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        break;
    case 10:
        if (func_00375970(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        func_00378df0(arg0, *(s32 *)(sbase + 0xC));
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00376290(arg0, i, 0xF, 0xFF, 0);
            }
        }
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (func_00375910(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00375890(arg0, i, 0);
            }
        }
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) & 0xFFFE;
        func_00379c70(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
        break;
    case 12:
        if (func_00379d70(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        return 1;
    case 14:
        if (func_00379a70(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 15:
        if (func_00379920(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if ((*(u16 *)(arg0 + 0x1F2F0) & 0xFFFF) < 0x1E) {
            break;
        }
        func_00106390(0x1431, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 7;
        break;
    default:
        func_0046d730(D_0064EAE0, 0x19E);
        break;
    }
    if (*(u16 *)(sbase + 0) & 1) {
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00378c80(arg0, i, mod);
            }
        }
    }
    return 0;
}
#pragma schedule off
#pragma opt_propagation on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037ad10);
#endif
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
// FUN_0037BC80 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_dead_assignments off
s32 func_0037bc80(u8 *arg0) {
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct {
        struct Vec3 v0;
        struct Vec3 v1;
        struct Vec3 v2;
    } work;
    f32 factor;
    f32 f0;
    f32 f1;
    u8 *sbase;
    u8 *sbase2;
    u8 *deck;
    s32 mod;
    s32 i;
    s32 sel;
    s32 m;
    u16 dur;
    sbase = arg0 + 0x1F1D0;
    mod = ((s32)*(u16 *)(sbase + 2) / *(s32 *)(arg0 + 0x1F304)) & 0xFFFF;
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (func_00378a70(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        sbase2 = sbase;
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            *(u16 *)(sbase2 + 2) = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            *(u16 *)(sbase2 + 2) = 0x14;
            factor = 0.7f;
            break;
        case 2:
            *(u16 *)(sbase2 + 2) = 0x10;
            factor = 0.8f;
            break;
        default:
            func_0046d730(D_0064EB00, 0x3A);
            break;
        }
        dur = *(u16 *)(sbase2 + 2);
        f0 = (f32)(u32)dur;
        f1 = factor * (f32)(*(s32 *)(arg0 + 0x1F304) - 3) / 5.0f;
        f1 = 1.0f + f1;
        f1 = f0 * f1;
        *(u16 *)(sbase2 + 2) = (u16)f1;
        *(s32 *)(sbase + 0xC) = -1;
        if (func_00379240(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (func_00379420(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2: {
        u16 tmp = *(u16 *)(arg0 + 0x1F2F0) + 1;
        *(u16 *)(arg0 + 0x1F2F0) = tmp;
        if (((s32)(tmp & 0xFFFF) < 0)) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    }
    case 3:
        if ((D_008C024E & 0x40) != 0) {
            deck = *(u8 **)(arg0 + 0x1F298);
            func_0038d0a0(deck);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(s32 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                m = (mod * i) & 0xFFFF;
                func_0037bac0(arg0, i, m & 0xFFFF, (m + 0x14) & 0xFFFF);
            }
            func_0045af60(0, 4, 0, 1);
        } else if ((D_008C024E & 0x20) != 0) {
            func_003799d0(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
        }
        break;
    case 4:
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (func_00375970(arg0 + i * 0xE8 + 0x1D6A0) != 0) {
                func_00375b40(arg0, i, 0, 0xA);
                m = (mod * (*(s32 *)(arg0 + 0x1F304) - i)) & 0xFFFF;
                sel = *(s32 *)(sbase + 8);
                if (sel >= *(s32 *)(arg0 + 0x1F304)) {
                    func_0046d730(D_0064EB00, 0x72);
                }
                func_0037b8c0(arg0, i, (f32 *)0);
                func_00378c80(arg0, i, m);
                work.v2 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6CC);
                work.v1 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6D8);
                work.v0 = *(struct Vec3 *)(arg0 + i * 0xE8 + 0x1D6E4);
                func_00375fa0(arg0, i, m, &work.v2.x, &work.v1.x, &work.v0.x, 0.0f, 0.0f + (360.0f / (f32)*(s32 *)(arg0 + 0x1F304)) * (f32)(*(s32 *)(arg0 + 0x1F304) - sel));
                (*(s32 *)(sbase + 8))++;
            }
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if (*(s32 *)(sbase + 8) != *(s32 *)(arg0 + 0x1F304)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) | 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u16 *)(sbase + 4) = func_00378bf0();
    case 5: {
        u16 tmp = *(u16 *)(arg0 + 0x1F2F0) + 1;
        *(u16 *)(arg0 + 0x1F2F0) = tmp;
        if ((tmp & 0xFFFF) < *(u16 *)(sbase + 4)) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 7;
    }
    case 7:
        if (func_00106330(0x1431) == 0) {
            func_003798d0(arg0, 1);
            *(u32 *)(arg0 + 0x1F2F8) = 0xF;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) | 2;
            break;
        }
        func_00389110(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 8;
    case 8:
        if (func_00389160(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 2);
        *(u32 *)(arg0 + 0x1F2F8) = 9;
    case 9:
        if ((D_008C024E & 0x40) == 0) {
            break;
        }
        *(s32 *)(sbase + 0xC) = func_00376590(arg0, (u8 *)0);
        func_00388f40(*(u8 **)(arg0 + 0x1F294));
        func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
        func_0045af60(1, 2, 2, 0xD);
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
        break;
    case 10:
        if (func_00375970(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        func_00378df0(arg0, *(s32 *)(sbase + 0xC));
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00376290(arg0, i, 0xF, 0xFF, 0);
            }
        }
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if (func_00375910(arg0 + (*(s32 *)(sbase + 0xC) * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00375890(arg0, i, 0);
            }
        }
        *(u16 *)(sbase + 0) = *(u16 *)(sbase + 0) & 0xFFFE;
        func_00379c70(arg0, *(s32 *)(sbase + 0xC));
        *(u32 *)(arg0 + 0x1F2F8) = 0xC;
        break;
    case 12:
        if (func_00379d70(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xD;
    case 13:
        return 1;
    case 14:
        if (func_00379a70(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 15:
        if (func_00379920(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        *(u16 *)(arg0 + 0x1F2F0) = *(u16 *)(arg0 + 0x1F2F0) + 1;
        if ((*(u16 *)(arg0 + 0x1F2F0) & 0xFFFF) < 0x1E) {
            break;
        }
        func_00106390(0x1431, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 7;
        break;
    default:
        func_0046d730(D_0064EB00, 0x1AF);
        break;
    }
    if (*(u16 *)(sbase + 0) & 1) {
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            if (i != *(s32 *)(sbase + 0xC)) {
                func_00378c80(arg0, i, mod);
            }
        }
    }
    return 0;
}
#pragma opt_dead_assignments on
#else
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037bc80);
#endif
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
