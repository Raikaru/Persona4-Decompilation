#include "include_asm.h"
/* Persona 4 USA decompilation - y_fclCombineDraw.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} FclVec2;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} FclByte4;



extern void func_0044ea90(const void *arg0, u32 arg1);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern s32 func_00451fc0(s32, char *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern s32 func_00117780(s32, s32, s32, s32, s32);
extern void func_00314010(u8 *arg0);
extern void func_003142f0(u8 *arg0);
extern s32 func_00106330(s32);
extern s32 func_00452490(s32);
extern void func_0011b9e0(u8 *arg0);
extern void func_0011d100(u8 *arg0, f32 *arg1);
extern void func_0011b480(s32, s32, s32, s32);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(s32, s32, s32, s8);
extern void func_0011c2c0(s32, s32, s32, s8);
extern void func_0011bdc0(u8 *arg0);
extern void func_0011bf10(u8 *arg0);
extern void func_002b2970(s64 *out, f32 x, f32 y);
extern void func_002b6c30(s32 a, s64 b, s32 c, f32 d);
extern void func_002b6a70(s32, s32, s32, s32, s32, s32);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern u8 *func_002b6150(s16);
extern s32 func_002b6970(s16, s32);
extern void func_002b7750(s32, s16);
extern void func_002b2a60(void *arg0, s32, s32, s32, s32);
extern f32 iGpffff8360;
extern s64 func_00331560();
extern void func_002b77d0(s32, s64, s32, s32, s32, s64, s32, s32, f32, s32, s64);
extern void func_0025ecd0(s32, s32, s16, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_0046b0d0(u8 *arg0);
extern void func_003ef3a0(u8 *arg0);
extern void func_002777f0(s8 arg0);
extern void func_00454bd0(u8 *arg0);
extern u8 *(*D_008873EC[])(u8 *);
extern char D_00644D30[];
extern char D_00644D50[];
extern char D_00644DB0[];
extern char D_00644DD0[];
extern char D_00644DF0[];
extern char D_00644E10[];
extern char D_00644E30[];
extern char D_00644E48[];
extern char D_00644E60[];
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern f32 D_00644C90[];
extern f32 D_00644020[];
extern f32 D_00644098[];
extern f32 D_00644AD0[];
extern f32 D_00644B00[];
extern s8 D_00749530[];
extern s64 iGpffffa900;
extern s64 iGpffffa908;
extern s32 iGpffffa910;
extern s32 iGpffffb598;
extern s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern void func_00440b68();
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_003312e0(u8 *);
extern char D_00644D70[];
extern char D_00644D90[];
extern f32 D_00644880[];
extern f32 D_00644888[];
extern f32 D_00644890[];
extern f32 D_00644898[];

// FUN_00314320
s32 func_00314320(s32 arg0) {
    s32 ret;
    u8 *p;

    func_0044ea90(D_00644D30, 0x16D);
    p = (u8 *)D_008873F4[0](1, 0x14, 0x40000);
    func_0043f9c8(p, 0, 0x14);
    ret = func_00451fc0(arg0, D_00644D50, 0xF, 0, 0, func_00314010,
                       func_003142f0, p);
    *(s8 *)p = 7;
    *(s32 *)(p + 4) = func_00117780(ret, 0xF, 3, 5, 5);
    *(s8 *)(p + 0xD) = 0;
    return ret;
}

// FUN_00314400
void func_00314400(u8 *arg0, s8 arg1) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    *(s8 *)(t + 0) = 0x10;
    if (arg1 == 1) {
        *(s8 *)(t + 0) = 0xF;
        func_0011bc70((u8 *)*(u32 *)(t + 4));
    }
}

/* measured: retail keeps the deref'd object pointer in $a0 (reusing the dead param
   register) and the zero-loop buffer pointer in $v1; mwcc b210 always allocates
the object to $v1 and the buffer to $a0, swapping 9 words with identical
instruction order/semantics. Tried: local t, arg0 reassignment, local declaration
order, statement order, u8 pointers, &buf[0], hoisted call-arg local, m2c scalar
locals (worse). All give the identical nd 9. $v0/$v1-family allocation floor. */
// FUN_00314450
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00314450);
/* measured: same $a0/$v1 allocation swap as func_00314450 above; retail keeps the
   object pointer in $a0 across the loop and stores, mwcc b210 forces it into $v1
   with the buffer pointer in $a0. Same 12 words swapped, all spellings tried
   (incl. u8 pointers, declaration-order and statement-order variants) give the
   identical nd 12. $v0/$v1-family allocation floor. */
// FUN_003144D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003144d0);
// FUN_00314560
void func_00314560(u8 *arg0, s32 arg1, s8 arg2, s8 arg3) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (arg3 == 0) {
        *(s32 *)(t + 8) = arg1;
        *(s8 *)(t + 0xC) = arg2;
        func_0011c180(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
        return;
    }
    *(s32 *)(t + 8) = arg1;
    *(s8 *)(t + 0xC) = arg2;
    func_0011c2c0(*(u32 *)(t + 4), 0, *(s32 *)(t + 8), arg2);
}
// FUN_003145E0
s32 func_003145e0(u8 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (func_00452490((s32)arg0) == 0) {
        return 0;
    }
    if (*(u32 *)(arg0 + 0x38) == 0) {
        return 0;
    }
    return *(s8 *)(*(u32 *)(arg0 + 0x38)) < 6;
}

// FUN_00314660
s8 func_00314660(u8 *arg0) {
    return *(s8 *)(*(u8 **)(arg0 + 0x38));
}

// FUN_00314670
void func_00314670(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38)) = arg1;
}

// FUN_00314680
void func_00314680(u8 *arg0) {
    s64 sp18;
    f32 *p;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp18, (sp18 = iGpffffa900, p)));
}
// FUN_003146C0
void func_003146c0(u8 *arg0) {
    func_0011b9e0(*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
}

/* measured: retail copies arg2 into $v1 up front and sign-extends it into $a3 last, right
   before the call; mwcc b210 sign-extends into $a3 first and then reuses $a2 for the load.
   Same instructions, different order. A named s8 local and an explicit (s8) cast at the
   callsite both give the identical nd 17. Argument-scheduling floor. */
// FUN_003146F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003146f0);

// FUN_00314740
void func_00314740(u8 *arg0, s8 arg1) {
    *(s8 *)(*(u8 **)(arg0 + 0x38) + 0xD) = arg1;
}

// FUN_00314750
void func_00314750(u8 *arg0, s8 arg1) {
    u8 *t;
    s64 sp38;
    f32 *p;

    t = *(u8 **)(arg0 + 0x38);
    func_0011d100((u8 *)*(u32 *)(t + 4),
                  (p = (f32 *)&sp38, (sp38 = iGpffffa908, p)));
    if (arg1 == 0) {
        func_0011bdc0((u8 *)*(u32 *)(t + 4));
    } else {
        func_0011bf10((u8 *)*(u32 *)(t + 4));
    }
}

// FUN_003147D0
u32 func_003147d0(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38) + 4);
}

// FUN_003147E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003147e0);

/* measured: nd 156 cascades from two allocation/scheduling decisions in the first
   block: (1) retail allocates v22 (v17*2) to $s6 and the CSE'd v16+2 to $s7, mwcc
   b210 always reverses them; (2) retail normalizes v16 (dsll32/dsra32 in place) and
   computes v16+2 immediately after the func_002b7750 call, mwcc defers both to the
   func_002b77d0 arg materialization (v23 as a local — s16 or s32 — adds extra
   normalizations, nd 195). All later blocks cascade from these two. Tried v23
   local (s32 nd 147/156, s16 nd 195), inline (s16)(v16+2) (nd 156), slot reorder.
   Saved-register rotation + normalization-placement floor. */
// FUN_00314EF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00314ef0);

/* measured: nd 21 (16 loop-body words + 5 padding): retail computes the
   (s16)i*2 CSE (sll $s0,$v1,1) right after the loop's (s16)i normalization and
   before the func_002b2970 f13 expression; mwcc b210 folds (s16)i*2*0x11 into
   i*0x22 (sll4/addu/sll1) and emits the i*2 sll at the func_003147e0 args instead.
   Tried *2*0x11 (nd 21), <<1*0x11 (nd 86), a separate s16 i2 statement (nd 176 —
   allocates $s5 and grows the frame), s16/s32 v17 — v17 must be s32 or mwcc
   re-normalizes it at the addu (nd 144). Load/scheduling-order floor. */
// FUN_00315310
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315310);

// FUN_00315600
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00315600);

// FUN_00316470
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316470);

/* measured: nd 12 (10 words + 2 padding) — the func_002b6a70 else-branch arg order:
   retail materializes the constant a0 (addiu $a0, 0x8B) BEFORE the lbu of the
   second arg; mwcc b210 always emits the lbu first (same family as the measured
   func_00317240 note — hoisted b local also nd 12). The D_006441xx addresses DID
   match once hoisted into f32 * pointer locals before the inner checks (5 blocks
   otherwise byte-perfect). Argument-evaluation-order floor. */
// FUN_00316E80
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00316e80);

/* measured: retail materializes the constant first arg (addiu $a0, 0x1E4) BEFORE
the lbu of the second arg; mwcc b210 evaluates call args right-to-left and always
emits the lbu first. Tried inline call, hoisted b local, hoisted v local, hoisted
id local — all give the identical nd 3 (same 2-word swap). Argument evaluation
order floor. */
// FUN_00317240
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317240);
/* measured: same constant-vs-load arg order swap as func_00317240; mwcc b210
emits lbu $a1 before addiu $a0, retail the reverse. All spellings give nd 5
(2 swapped words + 3 window padding). Argument evaluation order floor. */
// FUN_00317320
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317320);
// FUN_00317410
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317410);

// FUN_00317900
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);

// FUN_00318840
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00318840);

// FUN_00318F30
void func_00318f30(s16 arg0) {
    s16 var;
    u8 *p;
    f32 fv;
    FclVec2 sp40;
    FclByte4 sp4C;
    s64 sp38;

    var = (s16)(arg0 * 2 + 0xDF);
    if (arg0 == 6) {
        var = 0xEF;
    } else if (arg0 == 7) {
        var = 0xEB;
    } else if (arg0 == 8) {
        var = 0xED;
    }
    func_002b7750(0x2F2, (s16)(var + 1));
    p = func_002b6150(var);
    sp40 = *(FclVec2 *)(p + 0x38);
    func_002b2970(&sp38, sp40.x - 15.0f, sp40.y - 7.0f);
    func_002b6c30(0x2F2, sp38, 0xAB, 58.0f);
    func_002b6a70(0x2F2, 0xFF, 0, 0, 0xF, 0);
    fv = iGpffff8360;
    *(f32 *)(func_002b6150(0x2F2) + 0xA0) = fv;
    *(f32 *)(func_002b6150(0x2F2) + 0xAC) = fv;
    func_002b2a60(&sp4C, 0xE0, 0xFF, 0x33, 0xFF);
    *(FclByte4 *)(func_002b6150(0x2F2) + 0x85) = sp4C;
}

// FUN_003190D0
s32 func_003190d0(u8 *arg0) {
    u8 *t;
    s16 i;

    t = *(u8 **)(arg0 + 0x38);
    for (i = 0; i < *(s8 *)(t + 0xB5); i++) {
        if (*(s8 *)(t + 0xB4) != i) {
            if ((s16)func_002b6970(*(s16 *)(func_002b6150((s16)(*(s16 *)(t + i * 10 + 0xC8) + 0x20D)) + 0x10), 1) == 1) {
                return 1;
            }
        }
    }
    return (s16)func_002b6970(*(s16 *)(func_002b6150(0x1DC) + 0x10), 1) == 1;
}
// FUN_003191C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003191c0);

// FUN_0031AC10
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ac10);

// FUN_0031C2B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031c2b0);

// FUN_0031CCE0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031cce0);

// FUN_0031D630
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031d630);

// FUN_0031DDF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ddf0);

/* measured: nd 50 (48 rotated words + 2 padding) — a 3-way saved-register
   rotation: retail allocates arg1->$s2, id->$s4, p->$s3 (v16->$s0, t->$s1 match);
   mwcc b210 always emits arg1->$s3, id->$s2, p->$s4 regardless of declaration
   order (p/id swapped), s16 vs s32 param/local types, or inline vs hoisted casts.
   Everything else (lwr/lwl unaligned loads, (s8) cast, per-iteration (s16) ids)
   reproduces exactly. Saved-register rotation floor. */
// FUN_0031E320
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e320);

// FUN_0031E5B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031e5b0);

// FUN_0031FA20
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031fa20);

/* measured: nd 124 — everything matches except D_00644CA0's address: retail
   materializes lui/addiu into $16 ONCE per if-block and reuses it across the two
   func_002b2970 calls (the render-vtable-hoist pattern); mwcc b210 always
   rematerializes the constant address into $v0 at each call (4 extra lui/addiu
   pairs), shifting every branch target after the first beqz. Tried a vec16 local
   (nd 124) and inline (FclVec2 *)D_00644CA0 casts (nd 132) — both rematerialize.
   Constant-address rematerialization floor. */
// FUN_003205F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003205f0);

/* measured: retail evaluates func_002b2970's args as [array lui/addiu] [addiu a0]
   [lwc1 f12] [lwc1 f13] (address computation hoisted above the pointer arg); mwcc
   b210 always emits [addiu a0] [lui/addiu] [lwc1] [lwc1] — 4 words swapped at each
   of the 4 call sites (nd 19 = 16 + 3 padding). Tried direct D_00644020[0] spelling
   and a hoisted f32 * pointer local (both sunk into the arg list): identical order.
   Argument-evaluation-order scheduling floor, same family as the func_002b2a30 /
   func_0025ecd0 notes in y_fclItemShopDraw.c. */
// FUN_00320970
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320970);

// FUN_00320B80
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00320b80);

// FUN_003212E0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003212e0);

// FUN_003218A0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003218a0);

// FUN_00321E60
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00321e60);

// FUN_003233D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003233d0);

// FUN_00323D00
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00323d00);

/* measured: nd 83, all downstream -4 branch offsets trace to ONE block: retail
   schedules the v298.y load BEFORE the 20.0f constant materialization and leaves
   an unfillable mtc1-delay nop (lwc1 f1,0x6c; lui; mtc1 f0; nop; add.s f20,f0,f1),
   mwcc b210 emits the constant first and fills the delay with the load (lui; mtc1
   f1; lwc1 f0; add.s f20,f1,f0). Tried 20.0f+x, x+20.0f, and s16-param externs
   (conversions fixed), FclVec2 struct copy (frame fixed) — the schedule is fixed.
   Also retail's addu $v1,$s1,$v1 (arg2+t) is canonicalized by mwcc to $v1,$v1,$s1
   regardless of source order. Load-scheduling floor. */
// FUN_00324410
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324410);

// FUN_00324680
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00324680);

// FUN_00324F80
void func_00324f80(u8 *arg0, FclVec2 arg1, s32 arg2, s32 arg3) {
    s32 sp8C, sp88, sp84, sp80, sp7C;
    s64 sp70, sp68, sp60, sp58, sp50, sp48;
    s16 v17;
    f32 f20;

    v17 = (s8)arg2;
    if (v17 == 0) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xAA, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970(&sp70, arg1.x, arg1.y);
            func_002b6c30(0xAA, sp70, 0x41, 168.0f);
            func_002b2a60(&sp8C, 0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xAA) + 0x85) = *(FclByte4 *)&sp8C;
            func_002b6a70(0xAA, 0, 0xFF, 0, 6, 0);
        }
    } else if (v17 == 1) {
        if ((s8)arg3 == 1) {
            func_002b6a70(0xA9, 0xFF, 0, 0, 6, 0);
        } else {
            func_002b2970(&sp68, arg1.x, arg1.y);
            func_002b6c30(0xA9, sp68, 0x41, 168.0f);
            func_002b2a60(&sp88, 0, 0, 0x99, 0xFF);
            *(FclByte4 *)(func_002b6150(0xA9) + 0x85) = *(FclByte4 *)&sp88;
            func_002b6a70(0xA9, 0, 0xFF, 0, 6, 0);
        }
    }
    arg3 = (s8)arg3;
    if (arg3 == 1) {
        func_002b6a70(0xAD, 0xFF, 0, 0, 6, 0);
    } else {
        f20 = arg1.y;
        func_002b2970(&sp60, arg1.x, 176.0f + f20);
        func_002b6c30(0xAD, sp60, 0x41, 169.0f);
        if (v17 == 1) {
            func_002b2970(&sp58, arg1.x, 194.0f + f20);
            func_002b6c30(0xAD, sp58, 0x41, 169.0f);
        }
        func_002b2a60(&sp84, 0, 0, 0x99, 0xFF);
        *(FclByte4 *)(func_002b6150(0xAD) + 0x85) = *(FclByte4 *)&sp84;
        func_002b6a70(0xAD, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB1, 0xFF, 0, 0, 6, 0);
    } else {
        func_002b2970(&sp50, arg1.x, arg1.y);
        func_002b6c30(0xB1, sp50, 0x56, 166.0f);
        func_002b2a60(&sp80, 0x49, 0x72, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0xB1) + 0x85) = *(FclByte4 *)&sp80;
        func_002b6a70(0xB1, 0, 0xFF, 0, 6, 0);
    }
    if (arg3 == 1) {
        func_002b6a70(0xB5, 0xFF, 0, 0, 6, 0);
        return;
    }
    func_002b2970(&sp48, arg1.x, 52.0f + arg1.y);
    func_002b6c30(0xB5, sp48, 0x56, 167.0f);
    func_002b2a60(&sp7C, 0x49, 0x72, 0xFF, 0xFF);
    *(FclByte4 *)(func_002b6150(0xB5) + 0x85) = *(FclByte4 *)&sp7C;
    func_002b6a70(0xB5, 0, 0xFF, 0, 6, 0);
}

// FUN_00325450
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00325450);

// FUN_00329310
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329310);

// FUN_003297F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003297f0);

// FUN_00329E40
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329e40);

// FUN_0032A960
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032a960);

// FUN_0032B000
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b000);

/* measured: everything matches (nd 18 = 16 rotated words + 2 padding) except a
   saved-register rotation: retail allocates arg1 to $s1 (with the (s16)arg1
   normalization in place: dsll32 $s1,$s1) and t to $s2; mwcc b210 always gives
   arg1 $s2 (normalizing into a fresh $s6) and t $s1, and rotates the dead-mult
   operands accordingly. Tried s32 params (nd 18), s64 params (nd 142), local v17
   (nd 87), declaration/statement orders — all keep the rotation. Saved-register
   rotation floor; note the dead mult (i*(s16)arg1) and the adda.s/madd.s FMA
   pattern both reproduce exactly. */
// FUN_0032B770
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b770);

// FUN_0032B9D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b9d0);

// FUN_0032C0C0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c0c0);

/* measured: retail allocates p (func_002b2a30 result) to $s0 and t (the
   *(u8 **)(arg0+0x38) load) to $s1; mwcc b210 always creates t first and gives it
   $s0 / p $s1 regardless of declaration order (p,t / t,p) or statement order (t
   load moves after the jal if p is assigned first, nd 93). Also: retail emits the
   D_00796310 lui/addiu for func_00330e50's a5 AFTER the f13/f14 mov.s pair, mwcc
   before; and retail evaluates func_0034a640's a0 load before a1, mwcc after. All
   tried variants nd 28. Saved-register rotation + argument-evaluation-order
   floors. */
// FUN_0032C480
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c480);

// FUN_0032C660
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032c660);

// FUN_0032E570
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032e570);

// FUN_0032F060
void func_0032f060(u8 *arg0, s32 arg1) {
    s32 sp6C, sp68, sp64, sp60, sp5C;
    s64 sp50, sp48, sp40, sp38, sp30;
    s32 v16;
    f32 *p;
    f32 f20;

    p = D_00644880;
    v16 = (s8)arg1;
    if (v16 == 0) {
        func_002b2970(&sp50, p[0], p[1]);
        func_002b6c30(0x162, sp50, 0xA1, 147.0f);
        func_002b2a60(&sp6C, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x162) + 0x85) = *(FclByte4 *)&sp6C;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x162) + 0xD0) = f20;
        func_002b6a70(0x162, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x162, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644888;
    if (v16 == 0) {
        func_002b2970(&sp48, p[0], p[1]);
        func_002b6c30(0x163, sp48, 0xA2, 146.0f);
        func_002b2a60(&sp68, 0, 0, 0x66, 0xFF);
        *(FclByte4 *)(func_002b6150(0x163) + 0x85) = *(FclByte4 *)&sp68;
        f20 = -15.0f;
        *(f32 *)(func_002b6150(0x163) + 0xD0) = f20;
        func_002b6a70(0x163, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x163, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644890;
    if (v16 == 0) {
        func_002b2970(&sp40, p[0], p[1]);
        func_002b6c30(0x164, sp40, 0x59, 145.0f);
        func_002b2a60(&sp64, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x164) + 0x85) = *(FclByte4 *)&sp64;
        func_002b6a70(0x164, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x164, 0xFF, 0, 0, 0xA, 0);
    }
    p = D_00644898;
    if (v16 == 0) {
        func_002b2970(&sp38, p[0], p[1]);
        func_002b6c30(0x165, sp38, 0x59, 145.0f);
        func_002b2a60(&sp60, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x165) + 0x85) = *(FclByte4 *)&sp60;
        func_002b6a70(0x165, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x165, 0xFF, 0, 0, 0xA, 0);
    }
    if (v16 == 0) {
        func_002b2970(&sp30, 0.0f, 65.0f);
        func_002b6c30(0x2DA, sp30, 0x59, 145.0f);
        func_002b2a60(&sp5C, 0xFF, 0xCC, 0xFF, 0xFF);
        *(FclByte4 *)(func_002b6150(0x2DA) + 0x85) = *(FclByte4 *)&sp5C;
        func_002b6a70(0x2DA, 0, 0xFF, 0, 0xA, 0);
    } else {
        func_002b6a70(0x2DA, 0xFF, 0, 0, 0xA, 0);
    }
}

/* measured: nd 154 — one fixed saved-register rotation: retail allocates t to $s0
   and the loop counter i to $s1 (v16 reuses $s0); mwcc b210 always gives t $s1 and
   i $s0, cascading through ~150 words. All declaration orders and statement orders
   tried. Everything else reproduces once the shape is right: the tbl is FclVec2[5]
   at 0x50 (stores at b7=5/6 are out-of-bounds writes overlapping sp78/sp80), the
   f20=-14.0f must be the LAST statement INSIDE the func_00106330(0x1306) if (else
   mwcc DCEs the live-on-skip-path f20=0.0f), and the loop reads tbl[i] as
   *(s64 *)&tbl[i] (mwcc proves alignment and emits ld, retail emits ldr/ldl —
   the u8*-pointer spelling doesn't change it). Saved-register rotation floor. */
// FUN_0032F4D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032f4d0);

// FUN_0032FA30
void func_0032fa30(u8 *arg0, s16 arg1, u32 arg2, u32 arg3, u32 arg4) {
    u8 *t;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    s32 idx;

    t = *(u8 **)(arg0 + 0x38);
    p1 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F5));
    *(FclByte4 *)(p1 + 0x85) = *(FclByte4 *)&arg2;
    p2 = func_002b6150((s16)((arg1 + 4) * 2 + 0x1F4));
    *(FclByte4 *)(p2 + 0x85) = *(FclByte4 *)(p1 + 0x85);
    idx = arg1 * 2;
    p3 = func_002b6150(*(s16 *)(idx + (s32)t + 0xB8));
    *(FclByte4 *)(p3 + 0x85) = *(FclByte4 *)&arg3;
    p4 = func_002b6150((s16)(arg1 + 0x2FF));
    *(FclByte4 *)(p4 + 0x85) = *(FclByte4 *)&arg4;
}
// FUN_0032FB60
s8 func_0032fb60(s8 arg0) {
    if (func_00106330(0x1306)) {
        arg0 = (s8)(D_00749530[arg0] - 4);
    }
    return arg0;
}
// FUN_0032FBC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032fbc0);

// FUN_00330060
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330060);

// FUN_003307B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003307b0);

/* measured: retail evaluates func_0025ecd0's 14 args as [0.0f, f12-f14, a0,a1,a3,
   t0,t1,t2, f16-f17, t3]; mwcc b210 always emits the GPR block (a0..t3) before the
   FPR block (f12..f17) regardless of spelling. Prologue + everything else matches
   exactly (nd 14 = the 12-word arg-materialization permutation + 2 padding): tried
   direct call, hoisted float locals (nd 44), s64 param + union (nd 22), interleaved
   declaration (nd 22), FclVec2 by-value param (fixes prologue, nd 14). Same
   argument-evaluation-order family as the measured note on func_0033cc40 in
   y_fclItemShopDraw.c. */
// FUN_00330E50
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330e50);
// FUN_00330F20
s32 func_00330f20(u8 *arg0) {
    s32 sp3C, sp38, sp34, sp30;
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    if (*(s8 *)(t + 0x45) == 1) {
        return -1;
    }
    switch (*(s8 *)(t + 0)) {
    case 0:
        if (func_004553c0(*(u32 *)(t + 0xC)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x10)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x14)) == 0) {
            return 0;
        }
        if (func_004553c0(*(u32 *)(t + 0x18)) == 0) {
            return 0;
        }
        *(u32 *)(t + 4) = func_0046aea0(D_00644D70);
        *(u32 *)(t + 8) = func_0046aea0(D_00644D90);
        *(u32 *)(t + 0x34) = func_004667d0(0, D_00644DB0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x38) = func_004667d0(0, D_00644DD0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x3C) = func_004667d0(0, D_00644DF0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(u32 *)(t + 0x40) = func_004667d0(0, D_00644E10, 0, 0, 0, 0, 0, 0, 0, 0);
        *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
    case 1:
        if (func_0046a750(*(u32 *)(t + 4)) != 0 && func_0046a750(*(u32 *)(t + 8)) != 0) {
            *(u32 *)(t + 0x24) = func_004669d0(*(u32 *)(t + 0x34), &sp3C, 0);
            if (sp3C != 0) {
                func_00454bd0((u8 *)*(u32 *)(t + 0xC));
                *(u32 *)(t + 0xC) = 0;
                *(u32 *)(t + 0x34) = 0;
                *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
            }
        }
        break;
    case 2:
        *(u32 *)(t + 0x28) = func_004669d0(*(u32 *)(t + 0x38), &sp38, 0);
        if (sp38 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x10));
            *(u32 *)(t + 0x10) = 0;
            *(u32 *)(t + 0x38) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 3:
        *(u32 *)(t + 0x2C) = func_004669d0(*(u32 *)(t + 0x3C), &sp34, 0);
        if (sp34 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x14));
            *(u32 *)(t + 0x14) = 0;
            *(u32 *)(t + 0x3C) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 4:
        *(u32 *)(t + 0x30) = func_004669d0(*(u32 *)(t + 0x40), &sp30, 0);
        if (sp30 != 0) {
            func_00454bd0((u8 *)*(u32 *)(t + 0x18));
            *(u32 *)(t + 0x18) = 0;
            *(u32 *)(t + 0x40) = 0;
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 5:
        if (func_004553c0(*(u32 *)(t + 0x1C)) != 0 && func_004553c0(*(u32 *)(t + 0x20)) != 0) {
            *(s8 *)(t + 0x44) = func_002774d0(func_00455f70(D_00644E30, 0));
            *(s8 *)(t + 0) = (s8)(*(s8 *)(t + 0) + 1);
        }
        break;
    case 6:
        break;
    }
    return 0;
}

// FUN_003312E0
void func_003312e0(u8 *arg0) {
    u8 *t;

    t = *(u8 **)(arg0 + 0x38);
    func_0046b0d0((u8 *)*(u32 *)(t + 4));
    func_0046b0d0((u8 *)*(u32 *)(t + 8));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x24));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x28));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x2C));
    func_003ef3a0((u8 *)*(u32 *)(t + 0x30));
    func_002777f0(*(s8 *)(t + 0x44));
    func_00454bd0((u8 *)*(u32 *)(t + 0x1C));
    func_00454bd0((u8 *)*(u32 *)(t + 0x20));
    D_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00331390
void func_00331390(void) {
    u8 *p;

    if (iGpffffb598 != 0) {
        iGpffffb598 = 0;
    }
    func_0044ea90(D_00644D30, 0x16A4);
    p = D_008873F4[0](1, 0x48, 0x40000);
    iGpffffb598 = func_00451de0(D_00644E48, 0xF, 0, 0, (void *)func_00330f20, (void *)func_003312e0, p);
    *(s8 *)(p + 0) = 0;
    *(s8 *)(p + 0x45) = 0;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B2);
    *(s32 *)(p + 0xC) = (s32)func_00454a60((u8 *)D_00644DB0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B3);
    *(s32 *)(p + 0x10) = (s32)func_00454a60((u8 *)D_00644DD0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B4);
    *(s32 *)(p + 0x14) = (s32)func_00454a60((u8 *)D_00644DF0, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B5);
    *(s32 *)(p + 0x18) = (s32)func_00454a60((u8 *)D_00644E10, 0);
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B7);
    *(s32 *)(p + 0x1C) = (s32)func_00454a60((u8 *)D_00644E30, 0);
    *(s8 *)(p + 0x44) = -1;
    func_00440b68(&iGpffffa910, D_00644D30, 0x16B9);
    *(s32 *)(p + 0x20) = (s32)func_00454a60((u8 *)D_00644E60, 0);
}
