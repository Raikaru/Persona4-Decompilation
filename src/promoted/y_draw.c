/* Consolidated Persona 4 source units. */
/* Original translation unit y_draw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern u8 *iGpffffb574;

typedef struct {
    f32 x, y;
} f2;

typedef struct {
    u8 c0, c1, c2, c3;
} u4;

typedef struct {
    f32 f[4];
} f4;


extern void func_002b82d0(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5);

extern void func_002b8300(u8 *arg0, u32 arg1, u32 arg2, s16 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern void func_0048a000(void);

extern void (*jtbl_008873EC[])(void *ptr);

extern u8 *D_0076DB7C;

extern void func_002b8270(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5);

extern void func_002b8340(u8 *arg0, u8 arg1, s16 arg2, s16 arg3, f32 fparg0, f32 fparg1);

extern void func_002b8370(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5);


extern void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                        void (*init)(u8 *), void (*close)(u8 *), u8 *arg7);
extern void func_003f6440(s32, s32);
extern void (*D_00887300[])(u32 state, u32 value);

extern s32 func_002b52a0(u8 *arg0);
extern void func_002b2970(void *, f32, f32);
extern s32 func_002b2a30(s32, s32, s32, s32);
extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
extern void func_002b7cd0(u8 *, s16, s16);
extern f32 func_002b2aa0(s32, f32, f32, f32, f32);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s16 func_002b2d00(s32, s32, s32, s32, s8);
extern void func_002b6180(void);
extern void func_002b6260(void);
extern void func_002b5c60(u8 *arg0);
extern s32 func_002b6340(u8 *arg0);
extern void func_002b6560(u8 *arg0);
extern s32 func_002b7f20(u8 *arg0);
extern s32 func_002b9e10(u8 *arg0);
extern void func_002b9ab0(u8 *arg0, u8 *arg1);
extern s32 func_002b6ec0(u8 *arg0);
extern void func_002b74c0(u8 *arg0);
extern void func_002b9f60(u8 *arg0);

extern u8 D_0063F178[];
extern u8 D_0063F188[];
extern u8 D_0063F1A0[];
extern u8 D_0063F1B0[];
extern u8 D_0063F1D0[];
extern u8 D_0063F1E0[];
void func_002b60f0(u8 *arg0, u8 arg1, u8 arg2, u32 arg3);

extern void func_00489f80(void);
extern u8 *func_00457120(void);
extern void func_0043f810(void *, s32, s32);
extern void *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern void *func_00461390(void *, s32, void *, s32);
extern f32 fGpffff8504;
extern f32 D_008872F8[];
extern u8 D_00793E80[];


/* measured: retail hoists the loop's 0xFF constant into the preheader (addiu before
   the entry branch) and emits base-first addu; mwcc b210 sinks the constant
   materialization into the loop body and emits index-first addu (8 differing words
   reloc-masked). Tried inline p[0x110 + i*4] literal, a pre-loop u8 val local, an
   s32 off local with plain assignment, and a u8 *q = p + off pointer local - all
   keep the sunk constant; best (8) is the inline literal form. Constant-sinking
   floor, cousin of the load-sinking wall. */
// FUN_002B5C90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b5c90);

// FUN_002B5DA0
u8 *func_002b5da0(u8 *arg0) {
    return *(u8 **)(arg0 + 0x38);
}

// FUN_002B5DB0
void func_002b5db0(u8 *arg0, f2 p1, f32 *p2) {
    f4 t;
    u8 *base;
    t = *(f4 *)p2;
    base = *(u8 **)(arg0 + 0x38);
    *(f2 *)(base + 0x134) = p1;
    *(f4 *)(base + 0x120) = t;
}

// FUN_002B5E20
void func_002b5e20(u8 *arg0, f32 fparg0) {
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x130) = fparg0;
}

// FUN_002B5E30
void func_002b5e30(u8 *arg0, u4 arg1) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s32 i;
    for (i = 0; i < 4; i++) {
        *(u4 *)(base + 0x110 + i * 4) = arg1;
    }
}
// FUN_002B5E90
void func_002b5e90(u8 *arg0, f2 p1, f2 p2, u32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg3;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    *(s16 *)(base + 0x156) = 2;
    base[0x154] = 0;
    base[0x0] = 2;
}

// FUN_002B5EF0
void func_002b5ef0(u8 *arg0, f2 p1, f2 p2, f32 *p3, f32 *p4, u32 arg5) {
    f4 a = *(f4 *)p3;
    f4 b = *(f4 *)p4;
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg5;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    *(f4 *)(base + 0x158) = a;
    *(f4 *)(base + 0x168) = b;
    *(s16 *)(base + 0x156) = 3;
    base[0x154] = 0;
    base[0x0] = 2;
}

// FUN_002B5FD0
void func_002b5fd0(u8 *arg0, f2 p1, f2 p2, f32 *p3, f32 *p4, u32 arg5, s16 arg6) {
    f4 a = *(f4 *)p3;
    f4 b = *(f4 *)p4;
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x14C) = 0;
    *(u32 *)(base + 0x150) = arg5;
    *(f2 *)(base + 0x13C) = p1;
    *(f2 *)(base + 0x144) = p2;
    *(f4 *)(base + 0x158) = a;
    *(f4 *)(base + 0x168) = b;
    *(s16 *)(base + 0x156) = 4;
    func_002b60f0(arg0, 0x80, 0, arg5);
    base[0x154] = 0;
    base[0x0] = 2;
    base[0x184] = 1;
    base[0x18C] = 1;
    *(s16 *)(base + 0x182) = arg6;
}

// FUN_002B60F0
void func_002b60f0(u8 *arg0, u8 arg1, u8 arg2, u32 arg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    base[0x178] = arg1;
    base[0x179] = arg2;
    *(s16 *)(base + 0x17A) = 0;
    *(u32 *)(base + 0x17C) = arg3;
    base[0x180] = 1;
}

// FUN_002B6120
void func_002b6120(u8 *arg0, u8 arg1) {
    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x154) = arg1;
}

// FUN_002B6130
void func_002b6130(u8 *arg0, u32 arg1) {
    *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x188) = arg1;
}

// FUN_002B6140
void func_002b6140(u8 *arg0, u8 arg1) {
    *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x184) = arg1;
}

// FUN_002B6150
u8 *func_002b6150(s16 arg0) {
    return (u8 *)((u32)(*(u8 **)(D_0076DB7C + 0x38)) + (u32)((s32)arg0 << 8) + 4);
}
// FUN_002B6180
void func_002b6180(void) {
    void (*const *tbl)(u32, u32) = D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x71009);
}

// FUN_002B6260
void func_002b6260(void) {
    void (*const *tbl)(u32, u32) = D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x7C003);
}

/* measured: retail materializes func_002b2a30's args constant-first (a0=0xFF before
   the lbu a1-a3) and func_0025ecd0's 14 args in a scrambled order [2, 7-addr,
   f12-f14, 0, 1, 3, 4, 5, 6, f15-f17] with the GPR block interleaved with FP; mwcc
   b210 always emits the b2a30 constant last and its own GPR-then-FPR order (nd 46,
   identical with inline args or a hoisted tab local). Same argument-evaluation-
   order floor documented in y_fclCombineDraw/y_fclItemShopDraw/y_fclShopDraw
   (func_0025ecd0/func_002b2a30 notes); also the first compare's two independent
   lwc1 loads swap (global first, nd 2, same family as func_002b9e10). */
// FUN_002B6340
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6340);

// FUN_002B6560
void func_002b6560(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

/* measured: retail anchors the loop's (s16)i sign-extend at the loop head into $s0
   (before the func_002b2970 call, live across it), then scales it post-call, and
   materializes func_0046d200's arg1 (dsll32/dsra32 of the s16 arg) before the arg0
   lw; mwcc b210 instead folds the loop-head extension into the bottom loop-test
   extension (slti on $s0) when written as a pre-call s32 ix statement (nd 85), or
   sinks it to first use after the call into $v1 when written inline (nd 12: 9
   words extension placement + 3 words arg-materialization order). Both residuals
   are the s16-index/arg-order floor family documented in y_fclCombineDraw. */
// FUN_002B6590
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6590);

// FUN_002B67A0
void func_002b67a0(u8 *arg0, u32 arg1, s8 arg2) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    if (arg2 == 0) {
        *(s16 *)(base + 0x10) |= (s16)((1 << (arg1 & 0xFFFF)) & 0xFFFF);
        return;
    }
    if (arg2 == 1) {
        *(s16 *)(base + 0x10) &= (s16)((1 << (arg1 & 0xFFFF)) ^ 0xFFFF);
        return;
    }
}

// FUN_002B6820
s8 func_002b6820(u8 *arg0, u32 arg1) {
    u32 n = arg1 & 0xFFFF;
    return (s8)((s32)(*(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10) & ((1 << n) & 0xFFFF)) >> n);
}




// FUN_002B6850
s32 func_002b6850(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x10);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

/* measured: restructured with a p4 = p + 4 store pointer, s32 v for the loaded s16,
   and (s16) casts on the or/and masks - the entire body then matches retail exactly;
   the only residual is the prologue load-sinking wall: retail loads iGpffffb574 then
   the 0x38 table base before sign-extending arg0, mwcc sinks the 0x38 load below the
   shift and flips the addu operands (7 differing words reloc-masked). Same wall as
   func_002b6af0/002b6b40. */
// FUN_002B68D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b68d0);

// FUN_002B6970
s16 func_002b6970(s16 arg0, s16 arg1) {
    return (s16)((arg0 & ((1 << arg1) & 0xFFFF)) >> arg1);
}

// FUN_002B69B0
void func_002b69b0(u8 *arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    func_002b8270(*(u8 **)(arg0 + 0x38) + 0x10, p1, p2, arg3, arg4, arg5);
}

/* measured: argument-forwarding wrapper that must repeat func_002b8270's full
   parameter list (retail sets only $a0, sign-extends arg0/s16 and arg5/s16 in
   place); residual is the load-sinking wall - retail loads iGpffffb574 then the
   0x38 table base before touching arg0, mwcc sinks the 0x38 load below the shift
   and flips the addu operands (7 differing words reloc-masked, identical with the
   base hoisted into a local). Same wall as func_002b6af0/002b6b40. */
/* measured: re-tested recipe B (global-base hoist) with four spellings - typed
   u8 *base local, two-step u8 *g = iGpffffb574 then base, fully inline
   expression, and an s32 idx local for (s16)arg0 << 8 - all nd 7 reloc-masked,
   byte-identical apart from the load-sinking wall: retail loads iGpffffb574
   then the 0x38 table base BEFORE sign-extending arg0, mwcc b210 sinks the
   0x38 load below the dsll32/dsra32/sll and flips the addu operands (base in
   $v1, index in $v0 vs candidate index/base reversed). Same wall as
   func_002b68d0/6a70/6af0/6b40/6b90; nothing source-side moves it. */
// FUN_002B69F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b69f0);

// FUN_002B6A40
void func_002b6a40(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg5;
    func_002b82d0(base + 0x10, arg1, arg2, arg3, arg4, ext);
}




/* measured: argument-forwarding wrapper around func_002b82d0 (full parameter list
   repeated; retail sets only $a0, sign-extends arg0 and arg5 in place). Residual is
   the load-sinking wall: retail loads iGpffffb574 then the 0x38 table base before
   sign-extending arg0, mwcc sinks the 0x38 load below the shift and flips the addu
   operands (17 differing words reloc-masked). Same wall as func_002b6af0/002b6b40. */
// FUN_002B6A70
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6a70);

// FUN_002B6AC0
void func_002b6ac0(u8 *arg0, u32 arg1, u32 arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    s16 ext = (s16)arg3;
    func_002b8300(base + 0x10, arg1, arg2, ext, fparg0, fparg1, fparg2, fparg3);
}

/* measured: retail issues both indirections up front (lw gp, then lw 0x38) before touching
   arg0; mwcc b210 sinks the 0x38 load past the shift, which also flips the addu operand
   order. Hoisting the base into a local first does not move it (nd 9 either way). This is
   the load-sinking wall documented in docs/matching.md. */
// FUN_002B6AF0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6af0);

/* measured: same load-sinking wall as func_002b6af0 - retail loads the table base before
   using arg0, mwcc sinks it to its use. nd 9 with and without a hoisted base local. */
// FUN_002B6B40
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6b40);

/* measured: argument-forwarding wrapper around func_002b8370 (full parameter list
   repeated with u4 struct args; retail sets only $a0, sign-extends arg0 and arg5 in
   place). Residual is the load-sinking wall: retail loads iGpffffb574 then the 0x38
   table base before sign-extending arg0, mwcc sinks the 0x38 load below the shift
   and flips the addu operands (7 differing words reloc-masked). Same wall as
   func_002b6af0/002b6b40. */
// FUN_002B6B90
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6b90);

// FUN_002B6BE0
void func_002b6be0(u8 *arg0, f2 p1, u32 arg2, f32 fparg0) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    *(s16 *)(base + 0x10) |= 1;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x14) = fparg0;
    *(u32 *)(*(u8 **)(arg0 + 0x38) + 0x8) = arg2;
    *(f2 *)(base + 0x38) = p1;
}

/* measured: retail emits the func_0046d200 call's arg1 chain (lw 0x38 base reload,
   addu, lh 8($v0)) BEFORE the arg0 load (lw $a0, ($a3) from the prologue-hoisted
   base, which retail keeps in $a3); mwcc b210 schedules the arg0 load first and
   colors the hoisted base $a1, flipping the addu at the first store (9 differing
   words reloc-masked). Tried full-deref stores, q = base+off+0x10 hoisted pre-call,
   b = base hoisted pre-call, and a pre-call s32 v = lh load - all keep mwcc's
   arg0-first order. Argument-materialization-order floor, cousin of the
   load-sinking wall. */
/* measured: re-tested recipe B (base hoist) with four spellings. A single typed
   u8 *p local keeps the base in $s0 across the calls (frame 0x40, nd 71);
   full-deref stores re-derive the base per store but mwcc still keeps the
   first base in $v0 and the pair reloads split (nd 70); the closest shape is
   pre-call b = *(u8 **)(iGpffffb574 + 0x38) hoists before func_0046b260/2f0
   plus full derefs elsewhere: frame 0x50, prologue through the 0xC store and
   every post-call chain byte-identical, nd 46 of which ~6 are real - retail
   CSEs the iGpffffb574 gp load between the p1 pair and the lh chain (lw $v1
   once, 0x38 reloaded), mwcc reloads gp, and retail loads the p1 pair into
   $f1/$f0 before both swc1s. A *(f2 *) struct assignment for the pair does
   produce retail's batched loads, but hoisting g = iGpffffb574 into a local
   for the CSE makes it live across the whole function ($s1, frame 0x60,
   worse). Remaining levers: deferred g local scoped to the pair+chain only.
   Same argument-materialization family as the old nd 9 note. */
// FUN_002B6C30
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6c30);

/* measured: retail loads iGpffffb574 and the 0x38 table base before sign-extending
   arg0, hoists the 1.0f constant before the addu, and re-loads the table for the
   third store; mwcc b210 sinks both table loads below the shift and reorders the
   constant (12 differing words reloc-masked, identical with a hoisted base local).
   Load-sinking wall, same family as func_002b6af0/002b6b40. */
// FUN_002B6D60
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6d60);

// FUN_002B6DA0
void func_002b6da0(void) {
    void (*const *tbl)(u32, u32) = D_00887300;
    tbl[0](6, 1);
    tbl[0](7, 2);
    tbl[0](8, 1);
    tbl[0](0xA, 5);
    tbl[0](0xB, 6);
    tbl[0](9, 2);
    tbl[0](0xC, 1);
    tbl[0](1, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
    func_00489f80();
}

// FUN_002B6EA0
void func_002b6ea0(void) {
    func_0048a000();
}

/* measured: three attempts (e-pointer local + full-deref re-derivations +
   declaration reorders), best nd 350. Structure fully decompiled: outer s16
   loop 0..0x30B, per-index clear at 0x30C06, flag-bit dispatch (0x4000 ->
   func_002b6260 object, 0x2000 -> func_002b6180 object, else the 0x72/0xA4/
   0xB0 spawn check), the 14-arg func_0025ecd0 call, and the count update.
   Residual walls: (1) retail re-derives the iGpffffb574 base into a fresh
   saved register after every call and keeps $s1 across the func_0043f810
   call, mwcc keeps the loop-head e pointer live in $s2 across calls (nd
   unchanged with full derefs - mwcc CSEs them); (2) the bit-scan loop
   (found=0 exit-edge sink + constant-1 CSE) appears FOUR times - the same
   wall as func_002b7cd0's measured nd 133 in isolation; (3) the func_0025ecd0
   14-arg materialization order. Loop-register + bit-scan + arg-order floor. */
// FUN_002B6EC0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b6ec0);

// FUN_002B74C0
void func_002b74c0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

/* measured: retail anchors the inner loop's (s16)j sign-extend at the loop head
   into $s0 (before the func_002b2970 call, live across it) and re-issues the table
   load before each store with the 0xFF constant between the loads and the addu;
   mwcc b210 emits the j-extend at first use after the call (or sinks a pre-call
   jx statement into the bottom test, nd 102) and materializes the constants before
   the table loads (nd 91-95 across inline/jx/while/for spellings, ix-first addu,
   and j=0-before-ix ordering). Same s16-index-extension family as func_002b6590's
   measured note. */
// FUN_002B74F0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b74f0);


/* measured: four spellings (s32 idx local, fully inline (s32)arg0 << 8,
   first-store u8 *b base local, combined u8 *d = base + idx local) all nd 9
   reloc-masked. Everything from the first sh onward is byte-identical - the
   five subsequent base re-derivations (lw gp + lw 0x38 per store) match
   exactly. The 9 words are the first store's preamble: retail loads the
   iGpffffb574/0x38 chain into $v1/$a2 BEFORE the dsll32/dsra32/sll index
   chain (addu $v1, $a2, $a0); mwcc b210 always emits the index chain first
   and sinks the two loads below it (addu $v1, $v1, $a0). Load-sinking wall,
   same family as func_002b69f0/6a70/6af0/6b40/6b90/6d60. */
// FUN_002B7750
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7750);

/* measured: both branches fully decompiled (retail's arg5==1 branch mirrors
   func_002b6c30's store chain - |= 1, fparg0, (s16)arg4, p1 f2 pair, second
   func_0046d200, /2.0f cvt chains, func_002b82d0/8300/2970/8270 calls with the
   f2 out/t copy; the else branch adds func_002b7750's reset stores and the
   arg3 u4 stores - every chain is understood and matches the floored sibling
   patterns byte-for-byte in isolation). The block is mwcc b210 register
   allocation: retail keeps 7 saved registers ($16=h, $17=arg5, $18=arg4 then
   h2, $19=arg2, $20=arg0, $21=arg6, $22=arg7) with arg_sp0 re-loaded per
   branch, frame 0xC0; mwcc keeps 8 saved + $fp with arg_sp0 saved across the
   whole if/else (frame 0xF0, obj 1332B vs window 1280B, nd 295-299 across
   base-local, full-deref and reordered declarations). Register-pressure wall
   on top of the same load-sinking/base-reload walls as func_002b6c30/7750. */
// FUN_002B77D0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b77d0);

/* measured: retail sinks found=0 into the loop's exit edge (test fall-through) and
   CSEs the constant 1 from i's init ($a0 = i's 1) into both the sllv base and the
   bne compare, keeping $a3=flags unextended (lh already sign-extends); mwcc b210
   keeps found=0 before the loop (or folds it when written after: nd 133) and
   rematerializes the 1 inside the body (nd 100-133 across s16/s32 flags and
   per-iteration found=0 spellings). Also retail re-loads iGpffffb574's table per
   compare and keeps $18 = arg2's sign-extend across calls. Loop-init-sinking +
   constant-LICM floor, cousin of the load-sinking wall. */
/* measured: re-tested recipe B (base hoist). Natural full-deref spelling
   (flags = *(s16 *)(*(u8 **)(iGpffffb574 + 0x38) + idx + 0x14), per-compare
   re-derivation) is nd 133; a typed u8 *tbl local hoisted for all uses is nd
   132 - retail re-loads iGpffffb574's table per compare, so the hoist is the
   wrong shape. The residual is the loop-init/constant wall: retail sinks
   found=0 into the loop's exit edge (test fall-through), CSEs the constant 1
   from i's init into the sllv base, the bne compare and the found value, and
   extends (s16)i at both the body head and the bottom test; mwcc b210 keeps
   found=0 before the loop, rematerializes the 1 inside the body, and merges
   the loop-head extension into the test. Everything after the found-check
   (func_0046d200 chain, v[] stack loop, four compare chains with the base
   re-derived per compare, &= ~1, func_0046d280) is byte-identical. Same
   loop-init-sinking + constant-LICM floor as recorded; cousin of the
   load-sinking wall. */
// FUN_002B7CD0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7cd0);

/* measured: retail compiles the u8->float c-check (lbu 0x125 + bltz, round-to-even
   trick via srl/andi/or, doubling via add.s) as a standard if/else - one bltz, direct
   path inline, trick out of line, single join store; mwcc b210 duplicates the else
   block and emits TWO bltz on the same lbu result for every spelling tried (>= / <
   condition, u8/u32 c, v2 local or inline doubled expression, u32 shift casts; nd
   111-129). Also retail hoists the D_008872F8 lui into the loop preheader and loads
   the LHS operand first (sub.s $f1, $f0 order), mwcc keeps the lui in the body and
   loads RHS first (nd 12 in the loop alone, same floor family as func_002b9e10's
   operand-order note). Else-duplication + loop-operand-order floor. */
/* measured: recipe A (s32 v = lbu load, u32 c copy, (f32)(s32)((c >> 1) | (c & 1)),
   f = f + f doubling, direct-path-first if (v >= 0)) DOES fix the old bltz
   duplication - mwcc now emits retail's single bare bltz, direct path inline,
   trick out of line, byte-identical conversion (nd 111-129 before, 0 here).
   Residual is the loop triple-wall: (1) retail re-sign-extends (s16)i at the
   body head (dsll32/dsra32 before the sll) while mwcc b210 folds that extension
   into the bottom test (2 words/iter x4); (2) retail hoists the D_008872F8 lui
   alone into the preheader and reloads lwc1 %lo per iteration, mwcc either
   rematerializes lui+addiu in the body (nd 59 best) or, with a typed f32 *dv
   local, hoists the full address into $s1 growing the frame (nd 59), or, with
   opt_loop_invariants on, hoists the whole lwc1 out of the loop (nd 106);
   (3) sub.s operand order: retail loads the D LHS first, mwcc loads the RHS
   (p+0x18) first - also survives (0.0f - x) + D reassociation (nd 108).
   lb for the 0x124 check needs the (s8) cast (lbu otherwise). Tail after the
   loop is byte-identical once aligned. Loop walls, s16-index-extension +
   operand-order family, same as func_002b6590/002b9ab0/002b9e10 notes. */
// FUN_002B7F20
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7f20);

// FUN_002B8120
void func_002b8120(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// FUN_002B8150
void func_002b8150(s32 arg0) {
    u8 *p;
    func_0044ea90(&D_0063F178, 0x4A2);
    p = D_008873F4[0](1, 0x130, 0x40000);
    func_00451fc0(arg0, D_0063F1D0, 0xF, 0, 0, (void (*)(u8 *))func_002b7f20,
                   (void (*)(u8 *))func_002b8120, p);
    p[0x124] = 1;
    p[0x125] = 0;
}

// FUN_002B81F0
u8 *func_002b81f0(u8 *arg0) {
    return *(u8 **)(arg0 + 0x38);
}

// FUN_002B8200
void func_002b8200(u8 *arg0, f2 p1, u4 arg2, f32 fparg0, f32 fparg1, f32 fparg2) {
    *(f2 *)(arg0 + 0x28) = p1;
    *(f32 *)(arg0 + 0x9C) = fparg0;
    *(f32 *)(arg0 + 0x90) = fparg0;
    arg0[0x5E] = arg2.c3;
    *(u4 *)(arg0 + 0x75) = arg2;
    *(f32 *)(arg0 + 0xC0) = fparg1;
    *(f32 *)(arg0 + 0x4) = fparg2;
    *(s16 *)(arg0 + 0x0) |= 1;
}

// FUN_002B8270
void func_002b8270(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5) {
    *(f32 *)(arg0 + 0x18) = p1.x;
    *(f32 *)(arg0 + 0x1C) = p1.y;
    *(f32 *)(arg0 + 0x20) = p2.x;
    *(f32 *)(arg0 + 0x24) = p2.y;
    *(f32 *)(arg0 + 0x28) = p1.x;
    *(f32 *)(arg0 + 0x2C) = p1.y;
    *(s16 *)(arg0 + 0x32) = 0;
    *(s16 *)(arg0 + 0x30) = arg4;
    *(s16 *)(arg0 + 0x34) = arg5;
    arg0[0x36] = arg3;
    *(s16 *)(arg0 + 0x0) |= 2;
}

// FUN_002B82D0
void func_002b82d0(u8 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s16 arg5) {
    arg0[0x5C] = arg1;
    arg0[0x5D] = arg2;
    arg0[0x5E] = arg1;
    *(s16 *)(arg0 + 0x5A) = 0;
    *(s16 *)(arg0 + 0x58) = arg4;
    *(s16 *)(arg0 + 0x60) = arg5;
    arg0[0x62] = arg3;
    *(s16 *)(arg0 + 0x0) |= 4;
}

// FUN_002B8300
void func_002b8300(u8 *arg0, u32 arg1, u32 arg2, s16 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    *(f32 *)(arg0 + 0x88) = fparg0;
    *(f32 *)(arg0 + 0x8C) = fparg1;
    *(f32 *)(arg0 + 0x90) = fparg0;
    *(f32 *)(arg0 + 0x94) = fparg2;
    *(f32 *)(arg0 + 0x98) = fparg3;
    *(f32 *)(arg0 + 0x9C) = fparg2;
    *(s16 *)(arg0 + 0x84) = 0;
    *(s16 *)(arg0 + 0x82) = arg2;
    *(s16 *)(arg0 + 0xA0) = arg3;
    arg0[0xA2] = arg1;
    *(s16 *)(arg0 + 0x0) |= 0x10;
}

// FUN_002B8340
void func_002b8340(u8 *arg0, u8 arg1, s16 arg2, s16 arg3, f32 fparg0, f32 fparg1) {
    *(f32 *)(arg0 + 0xB8) = fparg0;
    *(f32 *)(arg0 + 0xBC) = fparg1;
    *(f32 *)(arg0 + 0xC0) = fparg0;
    *(s16 *)(arg0 + 0xC4) = 0;
    *(s16 *)(arg0 + 0xC6) = arg2;
    *(s16 *)(arg0 + 0xC8) = arg3;
    arg0[0xCA] = arg1;
    *(s16 *)(arg0 + 0x0) |= 8;
}

// FUN_002B8370
void func_002b8370(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s32 arg5) {
    arg0[0x6D] = arg1.c0;
    arg0[0x6E] = arg1.c1;
    arg0[0x6F] = arg1.c2;
    arg0[0x71] = arg2.c0;
    arg0[0x72] = arg2.c1;
    arg0[0x73] = arg2.c2;
    arg0[0x75] = arg1.c0;
    arg0[0x76] = arg1.c1;
    arg0[0x77] = arg1.c2;
    *(s16 *)(arg0 + 0x7A) = arg4;
    *(s16 *)(arg0 + 0x7C) = 0;
    *(s16 *)(arg0 + 0x7E) = arg5;
    arg0[0x80] = arg3;
    *(s16 *)(arg0 + 0x0) |= 0x200;
}

/* measured: all four branches (sp0/sp8 combos) fully decompiled - every store
   matches retail's semantics (0x88-0x9C 1.0f/fGpffff8504 pattern, the 2970 f2
   result copied to 0x18/0x28 vs p2 to 0x20, the u4 a2/a3 copies at 0x6D-0x77,
   the 0x7E arg6/2 sra pattern, the swapped 0x94/0x98 order and swapped
   0x18/0x20 placement in the sp0!=0 branches, fparg1 to +4, |= 1 tail). The
   block is mwcc b210's stack layout: retail allocates the per-branch f2/u4
   locals (p2/t/out/a3/a2) at FRESH slots per branch (out@B8/B0/A8/A0, t@98/
   88/70/60, p2@90/80/78/68, a3@D8/D0/C8/C0, a2@DC/D4/CC/C4 - the whole
   0x60-0xDF band, frame 0xE0), while mwcc liveness-merges the mutually
   exclusive branch slots into one 0x60-0x7F band (frame 0xD0, nd 327 across
   function-level and block-scoped local spellings, with and without hoisted
   x6/x7 s16 extensions - retail's arg6/arg7 extensions are hoisted temps
   used only at 0x82/0xA0). No source spelling forces fresh per-branch slots. */
// FUN_002B83E0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b83e0);

/* measured: complete six-chain state machine decompiled (0x2/0x80/0x4/0x200/
   0x10/8 flag dispatches, recipe-A byte conversions at 0x5C-0x77 - single bare
   bltz, direct inline, doubled arm out of line, byte-exact - the (u8)(s32)tf
   clamp, the 5-arg func_002b2aa0/2cb0/2d00 calls, the 0x100 special). The
   prologue through the first 2aa0 call is byte-identical; nd 907 from there
   (obj 3924B vs window 4368B, 111 instructions short). Residuals: (1) the
   2aa0 argument-materialization order - retail computes the 0x32 cvt ($f14)
   BEFORE the 0x30/2 sra chain ($f15), mwcc b210 always emits the long /2
   chain first (same wall as func_002b6340's note); (2) my tf = f intermediate
   for the conversion result adds mov.s where retail's $f12/$f13 flow directly
   (m2c's var_f12/var_f13 are single assignments); (3) the size deficit
   propagates through every branch's scheduling. Not reachable in the four-
   attempt budget; arg-order + scheduling floor. */
// FUN_002B89A0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b89a0);

// FUN_002B9AB0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9ab0);


/* measured: four attempts, best nd 7 with only 6 real words - everything but
   the first float-compare chain is byte-identical (declarations q,p,i,r,e
   give retail's $s0..$s3 colors; the spawn's q recompute needs the inline
   p + i * 0x220 spelling or mwcc reuses the loop-head q, nd 58). The residual:
   retail loads lwc1 $f0, 0x194(q) then lwc1 $f1, fGpffff8504, c.ole.s
   $f0,$f1, bc1t, and reuses $f0/$f1 for the 0x1A0 compare (lwc1 $f0, 0x1A0
   after the branch - no speculative load). mwcc b210, with a/b member locals,
   speculatively hoists the 0x1A0 load ABOVE the first compare and colors it
   $f2 (c.ole.s $f2,$f1); with the members inline it loads fGpffff8504 first
   (RHS-first). Both spellings nd 7. Likely fix (untried, budget): hoist only
   a = *(f32 *)(q + 0x194) into a local and keep the 0x1A0 compare inline -
   the a-statement should pull the 0x194 load above the global load while the
   inline 0x1A0 load stays after the first branch. c.ole/bc1t need the
   !(member <= global) form, NOT the >= flip (that gives c.olt + bc1f). */
// FUN_002B9E10
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9e10);

// FUN_002B9F60
void func_002b9f60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    jtbl_008873EC[0](p);
}

// FUN_002B9F90
void func_002b9f90(s32 arg0, s16 arg1, s32 arg2) {
    u8 *p;
    s32 i;
    func_0044ea90(&D_0063F178, 0x693);
    p = D_008873F4[0](1, 0x6610, 0x40000);
    func_00451fc0(arg0, D_0063F1E0, 0xF, 0, 0, (void (*)(u8 *))func_002b9e10,
                  (void (*)(u8 *))func_002b9f60, p);
    for (i = 0; i < 0x30; i++) {
        *(s16 *)(p + i * 0x220 + 0x104) = 0;
        *(u32 *)(p + i * 0x220 + 0x214) = arg2;
    }
    *(s16 *)(p + 0x6600) = arg1;
}

