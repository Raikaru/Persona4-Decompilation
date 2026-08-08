#include "include_asm.h"
/* Persona 4 USA decompilation - y_symbol.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void (*jtbl_008873EC[])(...);
extern void *(*D_008873F4[])(s32, s32, s32);

typedef struct
{
    f32 x;
    f32 y;
} Vec2;

typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern u8 D_0063F120[];
extern u8 D_0063F130[];
extern u8 D_0063F140[];
extern u8 D_0063F150[];
extern u8 D_0063F160[];
extern u8 D_00794CF0[];
extern u8 D_00794D20[];
extern u8 D_00794DB0[];
extern u8 D_00794DE0[];
extern u8 D_007E80A0[];
extern u8 D_007E80A8[];
extern u8 D_007E8C50[];
extern u8 D_007E8C54[];

extern u32 D_007EFA00[];
extern u8 *D_007EFA04;

extern void func_0044ea90(void *msg, s32 id);
extern s32 func_00451fc0(s32 window, u8 *data, s32 a, s32 b, s32 c,
                         s32 (*init)(u8 *), void (*close)(u8 *), void *buf);
extern u8 *func_00145270(s32 arg0);
extern s32 func_00106330(s32 arg0);
extern s32 func_0014c4c0(u8 *arg0, u8 *arg1, f32 arg2);
extern f32 func_0014b5d0(u8 *arg0);
extern u8 *func_0047a2f0(u32 arg0);
extern s32 func_002ac740(void);
extern s8 func_002ac3c0(u8 arg0, u8 arg1);
extern s8 func_002b11c0(u8 *arg0);
extern s8 func_002b1210(u8 *arg0);
extern f32 func_002b1260(s32 arg0, f32 arg1);
extern f32 func_002b1320(s32 arg0, f32 arg1);
extern f32 func_002b13e0(u8 *arg0, f32 arg1);
extern f32 func_002b1480(u8 *arg0, f32 arg1);
extern s32 func_002b2960(void);
extern s32 func_002b2a30(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_002b2bd0(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4,
                          f32 arg5);
extern void func_0025ecd0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6, void *arg7,
                          f32 arg8, f32 arg9, f32 arg10, f32 arg11,
                          f32 arg12, f32 arg13);
extern f32 func_0046b260(u8 *arg0);
extern f32 func_0046b2f0(u8 *arg0);
extern u8 *func_0046d200(s32 arg0, s32 arg1);
extern void func_0046d280(u8 *arg0);

extern s32 func_002b3720(u8 *arg0);
extern void func_002b3960(u8 *arg0);
extern s32 func_002b3c70(u8 *arg0);
extern s32 func_002b4250(u8 *arg0);
extern s32 func_002b4ad0(u8 *arg0);

// FUN_002B3990
s32 func_002b3990(s32 arg0)
{
    s32 ret;
    u8 *work;
    u8 *t;

    func_0044ea90(D_0063F120, 0x98);
    work = D_008873F4[0](1, 0x24, 0x40000);
    ret = func_00451fc0(arg0, D_0063F130, 0xF, 0, 0, func_002b3720,
                        func_002b3960, work);
    *(u32 *)(work + 4) = (u32)func_00145270(0x400);
    *(u32 *)(work + 0) = (u32)work;
    *(u32 *)(work + 8) = 0x3F400000;
    *(u32 *)(work + 0xC) = 0x3F400000;
    *(u32 *)(work + 0x10) = 0;
    work[0x20] = 0;
    t = func_0046d200(func_002ac740(), 0x10);
    *(s16 *)(work + 0x14) = (s16)(s32)(func_0046b260(t) / 2.0f);
    *(s16 *)(work + 0x16) = (s16)(s32)(func_0046b2f0(t) / 2.0f);
    func_0046d280(t);
    return ret;
}
/* discarded C candidate measured nd 118 (object 368 / window 368); retail
   retains a different argument-materialisation order and saved-FPU register. */
/* Measured nd 118 (object 368 / window 368), well above the ~25 parking
   threshold; this full-size candidate preserves the recovered symbol math and
   argument ABI for future reduction. Committed at nd 118. */
// FUN_002B3AE0 NONMATCHING
#ifdef NON_MATCHING
void func_002b3ae0(u8 *arg0, s64 arg1, f32 fparg0, s32 arg2)
{
    f32 fparg0_saved;
    u8 *p;
    f32 angle;
    f32 centered;
    f32 temp;

    fparg0_saved = fparg0;
    p = *(u8 **)(arg0 + 0x38);
    angle = func_0014b5d0(func_0047a2f0(D_007EFA00[0]));
    if (angle >= 0.0f) {
        centered = angle - 180.0f;
    } else {
        centered = angle + 180.0f;
    }
    temp = (centered + *(f32 *)(p + 0x10)) * -1.0f;
    if (*(s8 *)(p + 0x20) == 1) {
        func_0025ecd0(arg2, 0xFF, 0x10, func_002ac740(), 1,
                      *(s16 *)(p + 0x14), *(s16 *)(p + 0x16), D_00794D20,
                      *(f32 *)&arg1, *((f32 *)&arg1 + 1), fparg0_saved, temp,
                      1.0f, 1.0f);
        return;
    }
    func_0025ecd0(arg2, 0xFF, 0x10, func_002ac740(), 1,
                  *(s16 *)(p + 0x14), *(s16 *)(p + 0x16), D_00794DE0,
                  *(f32 *)&arg1, *((f32 *)&arg1 + 1), fparg0_saved, temp,
                  1.0f, 1.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_symbol", func_002b3ae0);
#endif
// FUN_002B3C50
void func_002b3c50(u8 *arg0, u8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0x20] = arg1;
}

// FUN_002B3C60
void func_002b3c60(u8 *arg0, u8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0x21] = arg1;
}

/* No real C body was produced for this 1184-byte window. The nd 10 result came
   from a 12-byte empty stub and is a size-deficit artifact, not a near miss. */
// FUN_002B3C70
INCLUDE_ASM("asm/nonmatchings/y_symbol", func_002b3c70);
// FUN_002B4110
void func_002b4110(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B4140
s32 func_002b4140(s32 arg0, s32 arg1, Vec3 *arg2)
{
    s32 ret;
    u8 *work;
    Vec3 v;

    v = *arg2;
    func_0044ea90(D_0063F120, 0x18D);
    work = D_008873F4[0](1, 0x1C, 0x40000);
    ret = func_00451fc0(arg0, D_0063F140, 0xF, 0, 0, func_002b3c70,
                        func_002b4110, work);
    *(Vec3 *)(work + 0xC) = v;
    work[1] = arg1;
    work[0x18] = func_002b11c0((u8 *)&v);
    work[0x19] = func_002b1210((u8 *)&v);
    return ret;
}

// FUN_002B4240
void func_002b4240(u8 *arg0, u8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0] = arg1;
}

/* No real C body was produced for this 1936-byte window. The nd 10 result came
   from a 12-byte empty stub and is a size-deficit artifact, not a near miss. */
// FUN_002B4250
INCLUDE_ASM("asm/nonmatchings/y_symbol", func_002b4250);
// FUN_002B49E0
void func_002b49e0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B4A10
s32 func_002b4a10(s32 arg0, s32 arg1)
{
    u8 *work;
    s32 ret;

    func_0044ea90(D_0063F120, 0x215);
    work = D_008873F4[0](1, 0xC, 0x40000);
    ret = func_00451fc0(arg0, D_0063F150, 0xF, 0, 0, func_002b4250,
                        func_002b49e0, work);
    work[1] = arg1;
    return ret;
}

// FUN_002B4AC0
void func_002b4ac0(u8 *arg0, u8 arg1)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    p[0] = arg1;
}

/* No real C body was produced for this 1248-byte window. The nd 10 result came
   from a 12-byte empty stub and is a size-deficit artifact, not a near miss. */
// FUN_002B4AD0
INCLUDE_ASM("asm/nonmatchings/y_symbol", func_002b4ad0);
// FUN_002B4FB0
void func_002b4fb0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_002B4FE0
s32 func_002b4fe0(s32 arg0, Vec2 arg1, s32 arg2)
{
    s32 ret;
    u8 *work;
    u8 *e;

    func_0044ea90(D_0063F120, 0x28A);
    work = D_008873F4[0](1, 0xC, 0x40000);
    ret = func_00451fc0(arg0, D_0063F160, 0xF, 0, 0, func_002b4ad0,
                        func_002b4fb0, work);
    *(Vec2 *)work = arg1;
    work[8] = 0;
    e = (u8 *)&D_007E80A0 + (arg2 & 0xFF) * 0x168 + 0x150;
    work[9] = func_002b11c0(e);
    work[0xA] = func_002b1210(e);
    work[0xB] = arg2;
    return ret;
}
