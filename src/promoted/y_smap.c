#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit y_smap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern void (*D_00887304[])(s32, s32);

extern void (*D_00887300[])(s32 state, s32 value);

extern void (*jtbl_008873EC[])(void *);

extern u8 *(*D_008873F4[])(s32, s32, s32);

extern s32 D_00764640;   /* gp-relative, -0x4AB0 */
extern s32 D_00764644;   /* gp-relative, -0x4AAC */
extern s32 D_00764648;   /* gp-relative, -0x4AA8 */
extern s32 D_0076464C;   /* gp-relative, -0x4AA4 */
extern s32 D_00764650;   /* gp-relative, -0x4AA0 */
extern s16 *D_00764658;  /* gp-relative, -0x4A98 */
extern u8 D_00763928;    /* gp-relative, -0x57C8 */

extern u8 D_0063EF60[];
extern u8 D_0063EF70[];
extern u8 D_0063EF90[];
extern char D_0063EFB0[];
extern u8 D_0063EFC8[];
extern u8 D_00794C90[];
extern char D_0063F0F0[];

extern u8 *func_00457120(void);
extern s32 func_00461390(void *a, s32 b, void *c, s32 d);
extern s32 func_0046d200(s32 a, s32 b);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern f32 D_008872F8[];
extern u8 D_00794D50[];
extern s32 func_002b1520(u8 *arg0);
extern void func_0044ea90(void *msg, s32 id);
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c,
                         void *init, void *close, void *buf);
extern s32 func_00451fc0(s32, char *, s32, s32, s32,
                         void (*)(u8 *), void (*)(u8 *), u8 *);
extern void func_00460ac0(void *param, void *work);
extern void func_00440b68();
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_00454bd0(u8 *ptr);
extern s32 func_004553c0(u8 *ptr);
extern s32 func_0046a750(s32 param);
extern s32 func_0046aea0(const u8 *name);
extern void func_0046d280(s32 param);
extern void func_0046d730(void *msg, s32 id);
extern s32 func_004667d0(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern s32 func_004669d0(s32, s32 *, s32);
extern s32 func_002ac400(u8 *arg0);
extern s32 func_002b25d0(u8 *arg0);
extern void func_002b2800(u8 *arg0);
extern void func_002ac600(u8 *arg0);
extern void func_001687f0(u8 *arg0, u8 *arg1);
extern s32 func_001687d0(void *arg0);
extern s32 func_001687e0(void *arg0);

typedef struct YVec3f { f32 x, y, z; } YVec3f;
typedef struct YVec2f { f32 x, y; } YVec2f;
typedef struct YRGBA { u8 a, b, c, d; } YRGBA;

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};



// FUN_002AC400
s32 func_002ac400(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 x;

    switch (*(s8 *)(p + 4)) {
    case 0:
        D_00764640 = func_0046aea0(D_0063EF70);
        if (D_00764640 == 0) {
            func_0046d730(D_0063EF60, 0x93);
        }
        D_00764644 = func_0046aea0(D_0063EF90);
        if (D_00764644 == 0) {
            func_0046d730(D_0063EF60, 0x95);
        }
        *(s8 *)(p + 4) += 1;
        break;
    case 1:
        if (func_0046a750(D_00764640) != 0 && func_0046a750(D_00764644) != 0) {
            *(s8 *)(p + 4) += 1;
        }
        break;
    case 2:
        func_00440b68(&D_00763928, D_0063EF60, 0xA0);
        *(s32 *)p = (s32)func_00454a60((u8 *)D_0063EFB0, 0);
        *(s8 *)(p + 4) += 1;
        break;
    case 3:
        if (func_004553c0(*(u8 **)p) != 0) {
            *(s32 *)(p + 8) = func_004667d0(0, D_0063EFB0, 0, 0, 0, 0, 0, 0, 0, 0);
            *(s8 *)(p + 4) += 1;
        }
        break;
    case 4:
        D_00764648 = func_004669d0(*(s32 *)(p + 8), &x, 0);
        if (x != 0) {
            *(s32 *)(p + 8) = 0;
            func_00454bd0(*(u8 **)p);
            return -1;
        }
        break;
    }
    return 0;
}

// FUN_002AC600
void func_002ac600(u8 *arg0) {
    s16 i;

    func_0044ea90(D_0063EF60, 0x44);
    D_00764658 = (s16 *)D_008873F4[0](1, 0x30, 0x40000);
    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
    D_00764650 = 0;
}

// FUN_002AC6B0
void func_002ac6b0(void) {
    u8 *p;

    func_0044ea90(D_0063EF60, 0xD5);
    p = D_008873F4[0](1, 0xC, 0x40000);
    D_00764650 = (s32)func_00451de0(D_0063EFC8, 0xF, 0, 0,
                                    func_002ac400, func_002ac600, p);
    *(u8 *)(p + 4) = 0;
}

// FUN_002AC740
s32 func_002ac740(void) {
    return D_00764644;
}

// FUN_002AC750
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ac750);
// FUN_002ADCF0
s64 func_002adcf0(u8 arg0) {
    return (s64)(s8)((arg0 & 0xFF) >> 4);
}



/* Floor: call-argument setup order before JAL — mwcc hoists the
 * input-derived addiu $a1 ahead of the constant addiu $a0; retail
 * materializes $a0 first. Tried temp vars, arg typing, order swaps. */
/* measured: retail materialises the constant first argument before computing the second;
   mwcc b210 evaluates the arithmetic argument first. Caching the function pointer in a
   local does not change the order (nd 4 either way). Argument-scheduling floor. */
// FUN_002ADD10
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002add10);

// FUN_002ADD60
void func_002add60(u8 *arg0, u8 *arg1) {
    D_00887300[0](0xE, *(s32 *)(arg1 + 0xB4));
}



// FUN_002ADD90
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002add90);

// FUN_002AE520
void func_002ae520(u8 *arg0) {
    u8 *p;
    s16 i;

    p = *(u8 **)(arg0 + 0x38);
    i = 0;
    while (i < 4) {
        func_0046d280(*(s32 *)(p + i * 4 + 0x24));
        i++;
    }
    i = 0;
    while (i < 6) {
        func_0046d280(*(s32 *)(p + i * 4 + 0x34));
        func_0046d280(*(s32 *)(p + i * 4 + 0x4C));
        func_0046d280(*(s32 *)(p + i * 4 + 0x64));
        i++;
    }
    func_0046d280(*(s32 *)(p + 0x7C));
    func_0046d280(*(s32 *)(p + 0x80));
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_002AE630
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ae630);

// FUN_002AF3E0
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002af3e0);
// FUN_002AFB70
void func_002afb70(u8 *arg0, s8 arg1) {
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x38);
    if (arg1 == 0) {
        *(s8 *)(temp_6 + 4) = 5;
    } else if (arg1 == 1) {
        *(s8 *)(temp_6 + 4) = 6;
    }
    *(s16 *)(temp_6 + 0x764) = 0;
}



// FUN_002AFBC0
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002afbc0);
// FUN_002B0220
void func_002b0220(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


#pragma push


// FUN_002B0250
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b0250);

// FUN_002B07A0
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b07a0);

// FUN_002B0B10
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b0b10);

// FUN_002B10A0
void func_002b10a0(u8 *arg0, YVec2f arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    *(YVec2f *)(p + 0x10) = arg1;
    *(s8 *)(p + 0x15A) = 1;
}

// FUN_002B10D0
void func_002b10d0(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x15A) = arg1;
}

// FUN_002B10E0
void func_002b10e0(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x143) = arg1;
}

// FUN_002B10F0
void func_002b10f0(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0x144) = arg1;
}
// FUN_002B1100
void func_002B1100(void *param_1,u32 param_2,u32 param_3)

{
  YVec3f vector;
  
  vector.y = 0.0f;
  vector.x = 1200.0f * (float)param_2;
  vector.z = 1200.0f * (float)param_3;
  *(YVec3f *)param_1 = vector;
}

#pragma pop


#pragma push


// FUN_002B11C0
int func_002B11C0(RwV3d param_1)

{
  return (int)((param_1.x + 600.0f) / 1200.0f);
}

#pragma pop


#pragma push


// FUN_002B1210
int func_002B1210(RwV3d param_1)

{
  return (int)((param_1.z + 600.0f) / 1200.0f);
}

#pragma pop

// FUN_002B1260 NONMATCHING
// // Floor: mwcc hoists the 1200.0f lui/mtc1 into the post-call bubble
// (after func_001687d0's jal) where retail emits mtc1 $v0/cvt.s.w first and
// materializes 1200 after the conversion; plus the msub.s operand orientation
// (f2*f3 vs retail f3*f2) which is a canonicalization floor. The u8 buf copy is
// needed to reproduce retail's lwc1 x3/swc1 x3 12-byte copy (a typed local-to-
// local copy compiles to ld/sd instead).
#ifdef NON_MATCHING
f32 func_002b1260(void *arg0, f32 arg1) {
    YVec3f v2;
    u8 buf[0xC];
    s32 r;

    func_001687f0(buf, arg0);
    v2 = *(YVec3f *)buf;
    r = func_001687d0(arg0);
    return arg1 / 2.0f - (v2.x - ((f32)r * 1200.0f - 600.0f)) * (arg1 / 1200.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1260);
#endif

// FUN_002B1320 NONMATCHING
// // Floor: same mwcc post-call constant hoist + msub.s operand orientation
// as func_002b1260 (2 real differing words).
#ifdef NON_MATCHING
f32 func_002b1320(void *arg0, f32 arg1) {
    YVec3f v2;
    u8 buf[0xC];
    s32 r;

    func_001687f0(buf, arg0);
    v2 = *(YVec3f *)buf;
    r = func_001687e0(arg0);
    return arg1 / 2.0f - (v2.z - ((f32)r * 1200.0f - 600.0f)) * (arg1 / 1200.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1320);
#endif

// FUN_002B13E0 NONMATCHING
// // Floor: single residual msub.s operand orientation - retail msub.s
// $f0,$f3,$f2 (sub result first), b210 canonicalizes to $f0,$f2,$f3 regardless
// of source operand order (tried both multiply orders, temps, parens).
#ifdef NON_MATCHING
f32 func_002b13e0(YVec3f *arg0, f32 arg1) {
    YVec3f v1, v2;
    f32 t;

    v1 = *arg0;
    v2 = v1;
    t = (s32)((v2.x + 600.0f) / 1200.0f);
    return arg1 / 2.0f - (v1.x - (t * 1200.0f - 600.0f)) * (arg1 / 1200.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b13e0);
#endif

// FUN_002B1480 NONMATCHING
// // Floor: same msub.s operand orientation floor as func_002b13e0 (1 real
// differing word).
#ifdef NON_MATCHING
f32 func_002b1480(YVec3f *arg0, f32 arg1) {
    YVec3f v2, v3, v1;
    f32 t;

    v1 = *arg0;
    v2 = v1;
    v3 = v1;
    t = (s32)((v3.z + 600.0f) / 1200.0f);
    return arg1 / 2.0f - (v2.z - (t * 1200.0f - 600.0f)) * (arg1 / 1200.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1480);
#endif

// FUN_002B1520
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1520);

// FUN_002B2240
void func_002b2240(u8 *arg0) {
    u8 *q = *(u8 **)(arg0 + 0x38);

    if (D_0076464C != 0) {
        *(s32 *)(q + 0x84) = 0;
        *(s32 *)(q + 0x88) = 0;
        func_00460ac0(&D_00794C90[0], q + 0x84);
    }
}

// FUN_002B2290
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b2290);

// FUN_002B2500
void func_002b2500(void) {
    u8 *fp = (u8 *)D_00887300;

    ((void (**)(s32, s32))fp)[0](6, 1);
    ((void (**)(s32, s32))fp)[0](7, 2);
    ((void (**)(s32, s32))fp)[0](8, 1);
    ((void (**)(s32, s32))fp)[0](9, 2);
    ((void (**)(s32, s32))fp)[0](0xC, 1);
    ((void (**)(s32, s32))fp)[0](0xB, 6);
    ((void (**)(s32, s32))fp)[0](0xA, 5);
    ((void (**)(s32, s32))fp)[0](1, 0);
}

/* measured: retail hoists the `lui %hi(D_008872F8)` global-address into the loop
   preheader and allocates $a2/$a1/$v1 for counter/q/byte; mwcc b210 keeps the
   lui inside the loop body and shifts every loop register down by one
   ($a1/$a0/$v0), with the sub.s operand registers (f0/f1) swapped to match —
   48 reloc-masked differing words. Tried: u8/u32/s32/s8 byte locals, `(s32)b>=
   0` vs bare `>=0` compares, named-temp `t+t` vs `2.0f*` doubling, g-temp and
   v-temp statement orderings for the subtract, inline-address stores, `s32 off`
   addu lever, cached `f32 *gp` pointer (121), nested-block and 3 declaration
   orders (all 48). Loop-invariant-address-hoist/allocation floor. */
// FUN_002B25D0
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b25d0);
// FUN_002B2830
void func_002b2830(u8 *arg0, YVec2f arg1, f32 arg2, f32 arg3, u32 arg4) {
    u8 *p;

    func_0044ea90(D_0063EF60, 0x97A);
    p = D_008873F4[0](1, 0x120, 0x40000);
    func_00451fc0((s32)arg0, D_0063F0F0, 0xF, 0, 0,
                  (void (*)(u8 *))func_002b25d0, func_002b2800, p);
    *(u32 *)p = (u32)p;
    *(YVec2f *)(p + 4) = arg1;
    *(f32 *)(p + 0xC) = arg2;
    *(f32 *)(p + 0x10) = arg3;
    *(YRGBA *)(p + 0x14) = *(YRGBA *)&arg4;
    *(f32 *)(p + 0x18) = 60000.0f;
}