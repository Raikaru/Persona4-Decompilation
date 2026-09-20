#include "include_asm.h"
#include "sdk_task_registration.h"
/* Persona 4 USA decompilation - y_symbol.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);

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
extern u8 D_007EFA04[];

extern void func_0044ea90(void *msg, s32 id);

extern u8 *func_00145270(s32 arg0);
extern s32 func_00106330(s32 arg0);
extern s32 func_0014c4c0(u8 *arg0, u8 *arg1, f32 arg2);
extern f32 func_0014b5d0(u8 *arg0);
extern u8 *func_0047a2f0(u32 arg0);
extern s32 func_002ac740(void);
extern s8 func_002ac3c0(u8 arg0, u8 arg1);
extern s32 func_002b11c0(u8 *arg0);
extern s32 func_002b1210(u8 *arg0);
extern f32 func_002b1260(s32 arg0, f32 arg1);
extern f32 func_002b1320(s32 arg0, f32 arg1);
extern f32 func_002b13e0(u8 *arg0, f32 arg1);
extern f32 func_002b1480(u8 *arg0, f32 arg1);
extern s32 func_002b2960(void);
extern s32 func_002b2a30(u8, u8, u8, u8);
extern void func_002b2bd0(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4,
                          f32 arg5);
extern s32 func_0025ecd0(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 func_0046b260(u8 *arg0);
extern f32 func_0046b2f0(u8 *arg0);
extern u8 *func_0046d200(s32 arg0, s32 arg1);
extern void func_0046d280(void *node);

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
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063F130), 0xF, 0, 0, func_002b3720, func_002b3960, (u8 *)(work));
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
/* Re-derived body: the prior nd118 candidate is retained in
   build/WBHygiene_func_002b3ae0_archive.txt for provenance; this body is
   verified MATCH after correcting the callee ABI and arithmetic statement
   order. */
// FUN_002B3AE0
void func_002b3ae0(u8 *arg0, s64 arg1, f32 fparg0, s32 arg2)
{
    f32 fparg0_saved;
    u8 *p;
    f32 angle;
    f32 temp;

    fparg0_saved = fparg0;
    p = *(u8 **)(arg0 + 0x38);
    angle = func_0014b5d0(func_0047a2f0(D_007EFA00[0]));
    if (angle >= 0.0f) {
        temp = angle - 180.0f;
    } else {
        temp = angle;
        temp += 180.0f;
    }
    temp += *(f32 *)(p + 0x10);
    temp *= -1.0f;
    if (*(s8 *)(p + 0x20) == 1) {
        func_0025ecd0(*(f32 *)&arg1, *((f32 *)&arg1 + 1), fparg0_saved, arg2, 0xFF, 0x10, (void *)(u32)func_002ac740(), 1, *(s16 *)(p + 0x14), *(s16 *)(p + 0x16), temp, 1.0f, 1.0f, D_00794D20);
        return;
    }
    func_0025ecd0(*(f32 *)&arg1, *((f32 *)&arg1 + 1), fparg0_saved, arg2, 0xFF, 0x10, (void *)(u32)func_002ac740(), 1, *(s16 *)(p + 0x14), *(s16 *)(p + 0x16), temp, 1.0f, 1.0f, D_00794DE0);
}
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

// FUN_002B3C70
s32 func_002b3c70(u8 *arg0)
{
    u8 *p;
    u8 base[8];
    s64 out;
    Vec2 temp;
    s64 coord0;
    s64 coord1;
    f32 keep;
    f32 ty;
    f32 tx;
    s32 dx;
    s32 dy;

    p = *(u8 **)(arg0 + 0x38);
    func_002b2bd0(&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s8 *)p == 0) {
        if (func_0014c4c0(p + 0xC,
                          func_0047a2f0(D_007EFA00[0]) + 0x30,
                          4800.0f) == 1 &&
            func_002ac3c0(p[0x18], p[0x19]) == 1) {
            dx = (s8)(p[0x18] -
                      func_002b11c0(func_0047a2f0(D_007EFA00[0]) + 0x30));
            dy = (s8)(p[0x19] -
                      func_002b1210(func_0047a2f0(D_007EFA00[0]) + 0x30));
            *(f32 *)(base + 0) += 17.0f;
            *(f32 *)(base + 4) += 264.0f;
            keep = *(f32 *)(base + 0) + 18.0f * (f32)dx -
                   func_002b13e0(p + 0xC, 18.0f);
            keep +=
                func_002b1260(
                    *(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 10.0f;
            *(f32 *)&out = keep;
            keep = *(f32 *)(base + 4) + 18.0f * (f32)dy -
                   func_002b1480(p + 0xC, 18.0f);
            keep +=
                func_002b1320(
                    *(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 10.0f;
            *((f32 *)&out + 1) = keep;
            coord0 = out;
            func_0025ecd0(*(f32 *)&coord0, *((f32 *)&coord0 + 1), (f32)0xEA63, func_002b2a30(255, 255, 255, 255), 0xFF, 0xF, (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
        }
    } else if (*(s8 *)p == 1 &&
               func_002ac3c0(p[0x18], p[0x19]) == 1) {
        keep = 172.0f + 18.0f * (f32)p[0x18] -
               func_002b13e0(p + 0xC, 18.0f);
        keep -= 2.0f;
        *(f32 *)&out = keep;
        keep = 9.0f + 18.0f * (f32)p[0x19] -
               func_002b1480(p + 0xC, 18.0f);
        keep -= 2.0f;
        *((f32 *)&out + 1) = keep;
        coord1 = out;
        func_0025ecd0(*(f32 *)&coord1, *((f32 *)&coord1 + 1), (f32)0xEA63, func_002b2a30(255, 255, 255, 255), 0xFF, 0xF, (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
    }
    return 0;
}
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
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063F140), 0xF, 0, 0, func_002b3c70, func_002b4110, (u8 *)(work));
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

// FUN_002B4250
s32 func_002b4250(u8 *arg0)
{
    s8 *p;
    u8 base[8];
    s64 out;
    Vec2 temp;
    s64 coord0;
    s64 coord1;
    f32 keep;
    f32 tx;
    f32 ty;
    s32 dx;
    s32 dy;
    u8 a;
    u8 b;
    u8 f;
    u8 e;
    s32 var_3;
    u8 *o;
    u8 *h;

    p = *(s8 **)(arg0 + 0x38);
    func_002b2bd0(&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*p == 0) {
        h = func_0047a2f0(D_007EFA00[0]) + 0x30;
        o = func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30;
        if (func_00106330(0x1012) == 0) {
            if (func_0014c4c0(o, h, 2400.0f) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        } else {
            if (func_0014c4c0(o, h, (f32)0x1770) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        }
        var_3 = 0;
vtest1:
        if (var_3 == 1) {
            a = func_002b11c0(func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30);
            b = func_002b1210(func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30);
            if (func_00106330(0x1012) == 0) {
                if ((s8)func_002ac3c0(a, b) == 1) {
                    var_3 = 1;
                    goto vtest2;
                }
            } else {
                var_3 = 1;
                goto vtest2;
            }
            var_3 = 0;
vtest2:
            if (var_3 == 1) {
                dx = (s8)(a - func_002b11c0(func_0047a2f0(D_007EFA00[0]) + 0x30));
                dy = (s8)(b - func_002b1210(func_0047a2f0(D_007EFA00[0]) + 0x30));
                *(f32 *)(base + 0) += 17.0f;
                *(f32 *)(base + 4) += 264.0f;
                keep = *(f32 *)(base + 0) + 18.0f * (f32)dx -
                       func_002b1260(*(s32 *)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep += func_002b1260(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
                keep -= 10.0f;
                *(f32 *)&out = keep;
                keep = *(f32 *)(base + 4) + 18.0f * (f32)dy -
                       func_002b1320(*(s32 *)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep += func_002b1320(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
                keep -= 10.0f;
                *((f32 *)&out + 1) = keep;
                coord0 = out;
                func_0025ecd0(*(f32 *)&coord0, *((f32 *)&coord0 + 1), (f32)0xEA64, func_002b2a30(255, 255, 255, 255), 0xFF, 0x11, (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794DB0);
            }
        }
    } else if (*p == 1) {
        h = func_0047a2f0(D_007EFA00[0]) + 0x30;
        o = func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30;
        if (func_00106330(0x1012) == 0) {
            if (func_0014c4c0(o, h, 2400.0f) == 1) {
                var_3 = 1;
                goto vtest3;
            }
        } else {
            if (func_0014c4c0(o, h, (f32)0x1770) == 1) {
                var_3 = 1;
                goto vtest3;
            }
        }
        var_3 = 0;
vtest3:
        if (var_3 == 1) {
            f = func_002b11c0(func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30);
            e = func_002b1210(func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30);
            if (func_00106330(0x1012) == 0) {
                if ((s8)func_002ac3c0(f, e) == 1) {
                    var_3 = 1;
                    goto vtest4;
                }
            } else {
                var_3 = 1;
                goto vtest4;
            }
            var_3 = 0;
vtest4:
            if (var_3 == 1) {
                keep = 172.0f + 18.0f * (f32)func_002b11c0(func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30) -
                       func_002b1260(*(s32 *)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep -= 2.0f;
                *(f32 *)&out = keep;
                keep = 9.0f + 18.0f * (f32)func_002b1210(func_0047a2f0(*(u32 *)((u8 *)&D_007E8C50 + p[1] * 0x750)) + 0x30) -
                       func_002b1320(*(s32 *)(*(u8 **)((u8 *)&D_007E8C54 + p[1] * 0x750) + 0x220), 18.0f);
                keep -= 2.0f;
                *((f32 *)&out + 1) = keep;
                coord1 = out;
                func_0025ecd0(*(f32 *)&coord1, *((f32 *)&coord1 + 1), (f32)0xEA64, func_002b2a30(255, 255, 255, 255), 0xFF, 0x11, (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794CF0);
            }
        }
    }
    return 0;
}
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
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063F150), 0xF, 0, 0, func_002b4250, func_002b49e0, (u8 *)(work));
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

/* measured: fixed casts (void*)(u32) for 7th arg, 149 differing words (was 150/stub), obj 1244B/window 1248B (4B short), frame exact, branch targets at 108/172/184/284; f12 scheduling; production stays ASM. */
// FUN_002B4AD0 NONMATCHING
#ifdef NON_MATCHING
/* func_002b4ad0 best attempted body
   lane: Yajima_y_symbol
   object: 1244B, window: 1248B
   residual: ~4B (size short by 4B)
   differing words (reloc-masked): 150
   key offsets: branch targets at 108, 172, 184, 284; f12 scheduling around 428
   levers tried:
     - m2c generated body adapted to source types
     - s64 out/coord aggregate copy for func_0025ecd0
     - Vec2 v for second branch
     - goto var_3 pattern (closest: var_3 block matches first branch,
       second branch var_3 block 4B short due to missing nop)
     - m2c exact if/else var_3 pattern (caused s3 spill / 144B frame)
     - direct p[9]/p[0xA] without a/b locals (function shrank to 1220B)
*/
s32 func_002b4ad0(u8 *arg0)
{
    u8 *p;
    u8 base[8];
    s64 out;
    Vec2 temp;
    s64 coord;
    f32 keep;
    f32 tx;
    f32 ty;
    s32 dx;
    s32 dy;
    u8 a;
    u8 b;
    s8 p8;
    s32 var_3;
    Vec2 v;

    p = *(u8 **)(arg0 + 0x38);
    func_002b2bd0(&temp, 0, 136.0f, 136.0f, 21.0f, 22.0f);
    *(f32 *)(base + 0) = (tx = temp.x, ty = temp.y, tx);
    *(f32 *)(base + 4) = ty;
    if (func_002b2960() == 0) {
        return 0;
    }
    if (*(s32 *)((u8 *)&D_007E80A8 + p[0xB] * 0x168) == 1) {
        return 0;
    }
    p8 = p[8];
    if (p8 == 0) {
        b = p[0xA];
        a = p[9];
        if (func_00106330(0x1013) == 0) {
            if ((s8)func_002ac3c0(a, b) == 1) {
                var_3 = 1;
                goto vtest1;
            }
        } else {
            var_3 = 1;
            goto vtest1;
        }
        var_3 = 0;
vtest1:
        if (var_3 == 1) {
            dx = (s8)(p[9] - func_002b11c0((u8 *)func_0047a2f0(D_007EFA00[0]) + 0x30));
            dy = (s8)(p[0xA] - func_002b1210((u8 *)func_0047a2f0(D_007EFA00[0]) + 0x30));
            *(f32 *)(base + 0) += 17.0f;
            *(f32 *)(base + 4) += 264.0f;
            keep = *(f32 *)(base + 0) + 18.0f * (f32)dx -
                   func_002b13e0((u8 *)&D_007E80A0 + p[0xB] * 0x168 + 0x150, 18.0f);
            keep += func_002b1260(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 13.0f;
            *(f32 *)&out = keep;
            keep = *(f32 *)(base + 4) + 18.0f * (f32)dy -
                   func_002b1480((u8 *)&D_007E80A0 + p[0xB] * 0x168 + 0x150, 18.0f);
            keep += func_002b1320(*(s32 *)(*(u8 **)(D_007EFA04) + 0x220), 18.0f);
            keep -= 13.0f;
            *((f32 *)&out + 1) = keep;
            if (!(*(f32 *)&out < 1.0f) &&
                (*(f32 *)&out <= 164.0f) &&
                !(*((f32 *)&out + 1) < 248.0f) &&
                (*((f32 *)&out + 1) <= (f32)0x19B)) {
                coord = out;
                func_0025ecd0(
                    *(f32 *)&coord, *((f32 *)&coord + 1), (f32)0xEA65,
                    func_002b2a30(255, 255, 255, 255), 0xFF, 0x12,
                    (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                    D_00794DB0);
            }
        }
    } else if (p8 == 1) {
        b = p[0xA];
        a = p[9];
        if (func_00106330(0x1013) == 0) {
            if ((s8)func_002ac3c0(a, b) == 1) {
                var_3 = 1;
                goto vtest2;
            }
        } else {
            var_3 = 1;
            goto vtest2;
        }
        var_3 = 0;
vtest2:
        if (var_3 == 1) {
            v = *(Vec2 *)p;
            func_0025ecd0(
                v.x, v.y, (f32)0xEA65,
                func_002b2a30(255, 255, 255, 255), 0xFF, 0x12,
                (void *)(u32)func_002ac740(), 1, 0, 0, 0.0f, 1.0f, 1.0f,
                D_00794CF0);
        }
    }
end:
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/y_symbol", func_002b4ad0);
#endif
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
    ret = (s32)func_00451fc0((void *)(arg0), (const void *)(D_0063F160), 0xF, 0, 0, func_002b4ad0, func_002b4fb0, (u8 *)(work));
    *(Vec2 *)work = arg1;
    work[8] = 0;
    e = (u8 *)&D_007E80A0 + (arg2 & 0xFF) * 0x168 + 0x150;
    work[9] = func_002b11c0(e);
    work[0xA] = func_002b1210(e);
    work[0xB] = arg2;
    return ret;
}
