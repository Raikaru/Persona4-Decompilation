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


// FUN_002B7750
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b7750);

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

// FUN_002B83E0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b83e0);

// FUN_002B89A0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b89a0);

/* measured: retail keeps the loop's (s16)i sign-extend at the loop head (separate
   from the bottom test's extension), hoists the D_008872F8 lui into the preheader,
   and loads the sub's LHS operand first (lwc1 D before lwc1 0x108); mwcc b210 merges
   the loop-head extension into the test, keeps the lui in the body, and loads the
   RHS first (nd 133-140 across inline (s32)i, an ix statement, a per-iteration
   dv = D_008872F8[0] local, and cast-free u32 byte checks - the cast-free form does
   fix the byte-conversion if/else duplication from nd 275 to the standard single
   bltz shape). Same three walls as func_002b6590/func_002b74f0/func_002b7f20. */
// FUN_002B9AB0
INCLUDE_ASM("asm/nonmatchings/y_draw", func_002b9ab0);


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

