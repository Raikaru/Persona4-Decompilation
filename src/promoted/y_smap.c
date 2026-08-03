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
extern char D_0063EFD8[];
extern void func_003f6440(s32 a, s32 b);
extern s32 func_00442088(void *dst, const char *fmt, s32 value);
extern u8 *func_003ef6d0(void);
extern s32 *func_003ef650(u8 *a, void *b);
extern char D_0063EFF0[];
extern char D_0063F010[];
extern char D_0063F030[];
extern char D_0063F050[];
extern char D_0063F070[];
extern char D_0063F090[];
extern char D_0063F0B0[];
extern char D_0063F0D0[];
extern f32 D_008872F8[];
extern u8 D_00794D50[];
extern void func_002b1520(s32, u8 *);
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

/* func_002afbc0 callees */
extern s32 func_002b2a30(s32, s32, s32, s32);
extern void func_002b2bd0(f32 *, s32, f32, f32, f32, f32);
extern s32 func_00106330(s32);
extern u8 *func_00155280(void);
extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
extern void func_002b0b10(u8 *, YVec2f, u8, s32, s8, s32, f32, f32, f32, f32);
extern u8 D_00794DB0[];
extern u8 D_00794CF0[];
extern u8 D_0076465C;   /* gp-relative, -0x4A94 */
extern u8 D_00764660;   /* gp-relative, -0x4A90 */

/* func_002b1520 callees */
extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
extern void func_0046b380(u8 *, s32);
extern void func_002b3c60(s32, s32);
extern u8 *func_002b2940(s32);
extern s64 iGpffffa840;  /* gp-relative, -0x57C0 */
extern s64 iGpffffa848;  /* gp-relative, -0x57B8 */
extern f32 iGpffff84f4;  /* gp-relative, -0x7B0C */

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

/* measured: full transcription of the M2C_ERROR-free 574-line draft
   (nd 1239 -> 1255). All branch structure, func_00155280 re-call sites,
   func_002adcf0/002b2d00/002b2cb0 calls, the 0x58<7/<9/>=9 dispatch, the
   0x59 sub-switches, and the search loops are right. Residuals:
   (1) the prologue arg-save pattern — retail saves raw arg0/arg1 into
   $s4/$s3 first and re-derives (arg0&0xFF)/(arg1&0xFF) at every later
   site; mwcc CSEs my masked temps and rotates the saved registers
   (t18=$s4 vs $s2, t17=$s1, t16=$s0, t20=$s3 vs $s0) — rotation floor
   family; (2) the u16 bit-sets on D_00764658 — retail emits lhu/or/shu
   with the &0xFFFF mask at the first use only, then re-masks per
   later site; mwcc emits lh or adds dsll32/dsra32 extension dances
   depending on the local's type (tried u16 and s32 forms, nd 1239 and
   1255). Remaining ~1240 differing words are these two families
   cascading through 1384 words. */
// FUN_002AC750
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ac750);

// FUN_002ADCF0
s64 func_002adcf0(u8 arg0) {
    return (s64)(s8)((arg0 & 0xFF) >> 4);
}



/* measured: re-tested wave 4 (nd 4, unchanged) — call 1 arg setup is the
   only diff: retail materialises addiu $a0,$0,0xE before the addiu
   $a1,$a1,0xB4; mwcc b210 emits the arithmetic arg first (call 2 (0xE,0)
   already matches). Tried old-style () fn-ptr local, dual s32 temps,
   s32 arg1 typing, cached fn-ptr — all nd 4. Matched sibling
   func_002add60 emits const-first because its 2nd arg is a load.
   Argument-scheduling floor. */
// FUN_002ADD10
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002add10);

// FUN_002ADD60
void func_002add60(u8 *arg0, u8 *arg1) {
    D_00887300[0](0xE, *(s32 *)(arg1 + 0xB4));
}



/* measured: full state-machine structure reconstructed (nd 409 -> 327 ->
   315; best 315 with 3 declaration orders, all identical). Residuals:
   (1) pervasive saved-register rotation — p in $s2 vs retail $s1, arg0 in
   $s7 vs $s5, x/$s4 vs $s2, y/$s3 vs $s4, t19/$s6 vs $s3, t16/$s1 vs $s0;
   reordering locals 3 ways (incl. i-first) never moved a single register —
   saved-register-rotation floor family; (2) the i-loop: retail materialises
   q+0xD8 into a saved reg before func_002b4a10 and stores through it, mwcc
   folds the displacement into lw/sw (loop body 1 word short; obj 1928B vs
   window 1936B); forcing the address into a local made it worse (nd 347).
   Stack layout, switch dispatch, and all call sites otherwise match. */
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

/* measured: skipped — the m2c draft hits M2C_ERROR at the two FPU
   multiply-accumulate sites in the D_007E80A0 loop (adda.s $f0,$f1;
   madd.s $f20,$f12,$f2 wrapping the func_002b11c0/func_002b13e0 and
   func_002b1210/func_002b1480 call pairs), so the operand structure of
   those two sp1F8/sp1FC expressions is unrecoverable from the draft;
   the madd.s family is the same canonicalization floor as func_002b13e0/
   002b1480 (recorded above). Rest of the draft (func_002b0250 8-arg tile
   loop, func_002b2970/2a60/2830/3990 calls, D_007E8C00/D_007E80A0 loops)
   is intact but untestable without the two expressions. */
// FUN_002AE630
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002ae630);

/* measured: full structure reconstructed (nd 414 -> 405 -> 408 -> 408).
   opt_loop_invariants + s32 arg1 + stack-slot order (w2,w4,w1,w3,w5,w6,
   w7,w8,w9) made the prologue, frame, f20 hoist, and every func_002b2970/
   69b0/6ac0/6a40/6be0/46d200 block byte-match. Residuals: (1) the j/k/row
   saved-register rotation in both nested loops — mwcc allocates k=$s2,
   j=$s3, row=$s4/$s5 while retail has row=$s0/$s2, k=$s3, j=$s4; hoisting
   row to function level (decl before j/k) changed nothing — rotation
   floor family; (2) the `ok == 1` test: retail booleanizes with
   sltu $r,$0,$ok then bne vs 1; mwcc emits addiu/bne or folds (ok!=0)==1
   to beqz (1 word). All other code matches modulo the rotation. */
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



/* measured: recipe C re-test (4 attempts, nd 333->349->352; best body below
   is the if-chain variant, nd 349, obj 1644B/window 1632B). The ldr/ldl pair
   IS reproduced by the 8-byte YVec2f-by-value arg (recipe C mechanism 1:
   func_002b0b10(arg0, *(YVec2f *)(t17 + 8), ...) at 8-aligned disp 0x8), the
   frame is 0x70 with retail's saved-reg set, and the recipe-A guard compiles
   as a single bare bltz with the doubled arm out of line. Residuals, all
   scheduling/allocation families: (1) the buf[2]=buf[0]/buf[3]=buf[1] copy
   emits load-store-load-store (or with temps, loads 0x64-before-0x60 with
   $f1/$f0 swapped) vs retail load-load-store-store; (2) the doubled arm
   allocates or/mtc1/cvt into $v0/$f0 then add.s $f3,$f0,$f0 vs retail's
   $v1/$f3 with add.s $f3,$f3,$f3 (4 words); (3) the if-chain dispatch adds a
   move $v1,$v0 after the lb (a named s8 sw local instead spills $s0 and
   emits dsll32/dsra32 — 2 words worse); (4) func_0025ecd0's $t3 (D_00794DB0)
   materializes before mov.s $f17; (5) func_002b0b10's GPR args emit grouped
   before the FP args where retail interleaves (f12,f13,a2,f15,a3,t0,t1). */
// FUN_002AFBC0
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002afbc0);

// FUN_002B0220
void func_002b0220(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}


#pragma push


/* measured: 4 attempts (nd 284 -> 272 -> 180 -> 178) got everything but
   four source-drivable residuals: (1) the case 13/14 dispatch — retail tests
   (arg4&0xFF)==1 then !=3 with shared fallthrough body, mwcc b210 emits a
   switch chain testing 2,3,1 (8B longer); (2) saved-reg order ret/$s7 vs
   arg1/$s6 swapped; (3) the &f8/u8 stack locals land 4B higher; (4) the
   (a7+j)<<8 loop-invariant needs the opt_loop_invariants pragma to hoist at
   retail's position. All switch bodies, the v>=7/v==2/default chains, and
   the nested byte-scan loop match when aligned. */
// FUN_002B0250
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b0250);

// FUN_002B07A0
void func_002b07a0(u8 *arg0, u8 *arg1) {
    u8 *fp;
    u8 buf[0x80];
    u8 v;

    fp = (u8 *)D_00887300;
    ((void (**)(s32, s32))fp)[0](6, 1);
    ((void (**)(s32, s32))fp)[0](7, 2);
    ((void (**)(s32, s32))fp)[0](8, 1);
    ((void (**)(s32, s32))fp)[0](9, 2);
    ((void (**)(s32, s32))fp)[0](0xC, 1);
    ((void (**)(s32, s32))fp)[0](2, 3);
    ((void (**)(s32, s32))fp)[0](0xB, 6);
    ((void (**)(s32, s32))fp)[0](0xA, 5);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x717FB);
    if (*(u8 *)(arg1 + 5) == 3) {
        *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x28);
        *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg1 + 0x110) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0x114) = *(f32 *)(arg1 + 0x28);
    } else {
        *(f32 *)(arg1 + 0x50) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0x54) = *(f32 *)(arg1 + 0x28);
        *(f32 *)(arg1 + 0x90) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0x94) = *(f32 *)(arg1 + 0x28);
        *(f32 *)(arg1 + 0xD0) = *(f32 *)(arg1 + 0x24);
        *(f32 *)(arg1 + 0xD4) = *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg1 + 0x110) = *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg1 + 0x114) = *(f32 *)(arg1 + 0x20);
    }
    v = *(u8 *)(arg1 + 4);
    if (v >= 9) {
        if (*(u8 *)(arg1 + 5) == 1) {
            switch (v) {
            case 9:
            case 10:
                func_00442088(buf, D_0063EFF0, v);
                break;
            case 11:
            case 12:
                func_00442088(buf, D_0063F010, v);
                break;
            case 13:
            case 14:
                func_00442088(buf, D_0063EFF0, v);
                break;
            }
        } else if (*(u8 *)(arg1 + 5) == 3) {
            func_00442088(buf, D_0063EFF0, v);
        } else {
            switch (v) {
            case 9:
            case 10:
                func_00442088(buf, D_0063F030, v);
                break;
            case 11:
            case 12:
                func_00442088(buf, D_0063F050, v);
                break;
            case 13:
            case 14:
                func_00442088(buf, D_0063F070, v);
                break;
            }
        }
    } else if (v == 2) {
        if (*(u8 *)(arg1 + 5) == 1) {
            func_00442088(buf, D_0063F090, v);
        } else {
            func_00442088(buf, D_0063F0B0, v);
        }
    } else {
        func_00442088(buf, D_0063F0D0, v);
    }
    ((void (**)(s32, s32))fp)[0](1, *(s32 *)func_003ef650(func_003ef6d0(), buf));
}

/* measured: full structure matches (nd 345 -> 99): the 4-case switch, all
   mode sub-cases, the mask-first byte extraction, the byte-to-float idiom
   loop, and the final func_00461390 call. Residuals: (1) the documented
   D_008872F8 lui-hoist floor (retail hoists to the preheader, b210 keeps it
   in the loop); (2) arg3/arg4 saved-register order swapped ($s2/$s3) with the
   prologue move order (GPRs-then-FPs vs retail's interleave), which cascades
   register names through the loop body. Tried param types u32/s32/s8 and
   statement orders — all nd 99. Register-allocation + invariant-hoist floor. */
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

/* measured: re-tested wave 4 (nd 11, was recorded nd 1). The lwc1-copy
   shape is the u8 buf[0xC] + `v2 = *(YVec3f *)buf` spelling (local-to-local
   struct copies compile to ld/sd, pointer/buf-source copies to lwc1 x3);
   with that copy the mul.s $f1,$f2,$f0 (const-in-fs) MATCHES retail — the
   old note's "mul canonicalization floor" is wrong. The residual is the
   p-load: retail lwc1 0x40($sp) sits after sub.s $f1,$f1,$f0, mwcc b210
   hoists it into the post-cvt nop slot (obj 188B vs window 192B), which
   also rotates the two subs (sub.s $f0,$f1,$f0 / sub.s $f3,$f3,$f0 vs
   retail $f1/$f0). Tried 6 orderings (q-before-p, k-split, x-local,
   reversed decls, buf-indexed read, computed ptr) — all nd 11-38.
   Load-hoist/schedule floor. */
// FUN_002B1260
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1260);

/* measured: re-tested wave 4 (nd 11, was recorded nd 1) — same result as
   func_002b1260: u8 buf[0xC] + `v2 = *(YVec3f *)buf` reproduces the lwc1
   copy and the mul.s $f1,$f2,$f0 (const-in-fs) matches retail; the residual
   is mwcc b210 hoisting the p-load (lwc1 0x48($sp)) into the FP-latency
   nop (obj 188B vs window 192B) with the two sub.s registers rotated
   ($f0/$f3 vs retail $f1/$f0). Self-referential t = t*1200.0f sinks the
   load to mid-chain but flips const to $f4/result $f2 (nd 10); const-first
   and named-m variants stay nd 11. Load-hoist/schedule floor, same as
   func_002b1260. */
// FUN_002B1320
INCLUDE_ASM("asm/nonmatchings/y_smap", func_002b1320);
// FUN_002B13E0
f32 func_002b13e0(YVec3f *arg0, f32 arg1) {
    YVec3f v1, v2;
    f32 t, p, q;

    v1 = *arg0;
    v2 = v1;
    t = (s32)((v2.x + 600.0f) / 1200.0f);
    p = v1.x - (t * 1200.0f - 600.0f);
    q = arg1 / 1200.0f;
    return arg1 / 2.0f - p * q;
}

// FUN_002B1480
f32 func_002b1480(YVec3f *arg0, f32 arg1) {
    YVec3f v2, v3, v1;
    f32 t, p, q;

    v1 = *arg0;
    v2 = v1;
    v3 = v1;
    t = (s32)((v3.z + 600.0f) / 1200.0f);
    p = v2.z - (t * 1200.0f - 600.0f);
    q = arg1 / 1200.0f;
    return arg1 / 2.0f - p * q;
}

/* measured: recipe B re-test with the u32-cast base form (4 attempts, nd
   699 -> 632 -> 612 -> 603; best body below, nd 603, obj 3320B/window 3360B).
   The u32 base = (u32)D_00887300 + ((void (*)(s32,s32))*(u32 *)base)(a,b)
   spelling reproduces retail's single lui/addiu hoist into $17 with lw/jalr
   per call; the one-array sp[0x10] + cast accesses keep retail's two dead
   prologue s64 gp-relative ld/sd pairs (separate s64 locals get DCE'd), and
   the case-0/1 empty labels make mwcc emit the jtbl_007488A0 jump table
   (sltiu 7/beqz/lui/addiu/sll/addu/lw/jr). The (u8)(s32) saturation guard
   needs the explicit `if (2.1474836e9f > x) {plain} else {overflow}` spelling
   to emit c.ole.s $f1,$f2 + bc1t (the plain (u8)(s32)x form alone lets the
   range analysis drop the guard; `x < 2^31` emits c.olt.s + bc1f instead).
   Residuals: (1) the guard conversions allocate mfc1 $v0/andi $v1,$v0 (and
   or $v0,$v1,$v0) where retail uses $v1 throughout — 4 words per guard;
   (2) the fill-loop guard (2^31 const + c.ole.s + lui 0x8000) is NOT hoisted
   out of the loop by b210 here (retail hoists it before the loop-entry
   branch); (3) the clear-loop counters land in $s2/$s1 vs retail $s3/$s2. */
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

/* measured: retail computes z = -99.0f + 108.0f*j as mul.s+add.s with the
   constant as the add's first operand (add.s $f20,$f0,$f1) and re-sign-extends
   the s16 counter at the loop top (dsll32/dsra32 before sll); mwcc b210 fuses
   the 1-statement `const + var*const` into adda.s/madd.s (nd 149) and for
   statement-separated forms emits add.s with the product first (add.s
   $f20,$f1,$f0) plus reuses the loop-test sign-extension across the back
   edge, shrinking the body by 2 words (nd 97). Tried 1-statement both orders,
   2-statement, +=, and variable addend — all nd 97. FPU-add-operand-order /
   loop-sign-extend-lifetime floor. */
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

/* measured: re-tested wave 4 (nd 48 -> 45 with `#pragma opt_loop_invariants on`,
   which hoists the lui %hi(D_008872F8) to the preheader as retail does, but
   ALSO hoists the lwc1 itself — retail re-loads in the loop (lwc1 $f1,
   %lo($v0) at loop top), keeping the base $v0 live across iterations, which
   is what pushes its registers up to $a2/$a1/$v1/$a0; with the load hoisted
   the base dies and mwcc packs the loop one register lower ($a1/$a0/$v0/$v1)
   — ~40 words of pure rotation, and the count can never reach 0 while the
   load is out of the loop. Manual bases (u32 gbase = (u32)D_008872F8;
   f32 *gp = D_008872F8;) keep the reload but materialise lui+addiu into
   $a1 instead of retail's lui-only $v0 (nd 121). Tried: 4 decl orders,
   gbase/gp forms with and without the pragma. Load-hoist + register-
   rotation floor (same family as func_002b0b10). */
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
