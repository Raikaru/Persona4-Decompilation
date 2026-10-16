/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Battle/btlShuffleDraw.c); members 00370290-00371160 */

#include "include_asm.h"
#include "type.h"
extern void *func_003e0f80(void);
extern void RwMatrixRotate(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_003e42a0(void *arg0, void *arg1, void *arg2);
extern void func_003e0f40(void *arg0);
extern void RwV3dNormalize(f32 *arg0, f32 *arg1);
extern u32 RpRandom(void);
extern void func_00370290(u8 *arg0, f32 *arg1, f32 fparg0);
extern void func_003dc740(void *arg0, void *arg1, f32 fparg0, s32 arg2);
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
    RwV3dNormalize(&first[0], &first[0]);
    RwV3dNormalize(&second[0], &second[0]);

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
void btlShuffleCalcInitMotion(u8 *arg0) {
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
    value = RpRandom() & 0xFFF;
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
    value = RpRandom() & 0xFFF;
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
    value = RpRandom() & 0xFFF;
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
        value = RpRandom() & 0xFFF;
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
        value = RpRandom() & 0xFFF;
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
        value = RpRandom() & 0xFFF;
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
void btlShuffleCalcInitRotation(u8 *arg0) {
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
    value = RpRandom() & 0xFFF;
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
    value = RpRandom() & 0xFFF;
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
    value = RpRandom() & 0xFFF;
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
        value = RpRandom() & 0xFFF;
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
        value = RpRandom() & 0xFFF;
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
        value = RpRandom() & 0xFFF;
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
    void *matrix;

    matrix = func_003e0f80();
    sp70[0] = *(f32 *)(arg2 + 0) - *(f32 *)(arg0 + 0);
    sp70[1] = *(f32 *)(arg2 + 4) - *(f32 *)(arg0 + 4);
    sp70[2] = *(f32 *)(arg2 + 8) - *(f32 *)(arg0 + 8);
    RwMatrixRotate(matrix, arg1, fparg0, 0);
    func_003e42a0(arg3, sp70, matrix);
    *(f32 *)(arg3 + 0) += *(f32 *)(arg0 + 0);
    *(f32 *)(arg3 + 4) += *(f32 *)(arg0 + 4);
    *(f32 *)(arg3 + 8) += *(f32 *)(arg0 + 8);
    func_003e0f40(matrix);
}
