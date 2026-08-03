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
extern void func_002b6a70(s32, u8, u8, s32, s32, s32);
extern void func_002b6b40(s32, s32, s32, s32, f32, f32);
extern u8 *func_002b6150(s16);
extern s32 func_002b6970(s16, s32);
extern void func_002b7750(s32, s16);
extern void func_002b2a60(void *arg0, s32, s32, s32, s32);
extern u8 *func_002e4870(s8 arg0);
extern u8 *func_002e48a0(s8 arg0, s16 arg1);
extern u8 *func_0034ae50(u8 *arg0, s16 arg1);
extern void func_002ba970(u8 *, s64, s32);
extern s32 func_002b2a30(s32, s32, s32, s32);
extern s32 func_0010b5b0(void);
extern void func_0031e5b0(u8 *, s64, s32, s32, s32, s32, s32);
extern void func_002b6b90(s16, s32, s32, s32, s32, s32);
extern void func_002b8370(s32, s32, s32, s32, s32, s32);
extern void func_003191c0(u8 *, s64, s8, u16, u8, s32, s32, s8);
extern void func_0031ac10(u8 *, s64, s8, u16, u8, s32, s32, s8, s8, u8);
extern f32 D_006440F0[];
extern f32 D_006440F8[];
extern f32 D_00644290[];
extern f32 D_00644298[];
extern f32 D_00644350[];
extern void func_002b83e0(u8 *, s64, s64, s64, u8, u8, f32, f32, s32, s32, s64, s64);
extern void func_002b6af0(s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_002b69f0(s32, s64, s64, s32, s32, s32);
extern s32 func_0046d200(void *, s32);
extern f32 func_0046b260(void *);
extern f32 func_0046b2f0(void *);
extern void func_0046d280(s32);
extern void func_002b68d0(s32, s32, s32);
extern f32 D_007495C0[];
extern f32 D_00749600[];
extern void func_0045af60(s32, s32, s32, s32);
extern s32 func_00110140(void);
extern void func_002b6d60(s32);
extern s32 func_002b2cb0(s32, s32, s32, s32, s8);
extern s16 func_002b2d00(s32, s32, s32, s32, s8);
extern s16 func_002b2d50(s32, s32, s32, s32, s32);
extern void func_002b2e70(s16, s16, s32, s8, s16 *, s16 *);
extern void func_002b2f90(s16, s16, s32, s8, s16 *, s16 *);
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
extern f32 D_006440B8[];

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
void func_00317410(u8 *arg0, s8 arg1) {
    FclByte4 sp6C;
    FclByte4 sp68;
    FclByte4 sp64;
    FclByte4 sp60;
    FclByte4 sp5C;
    FclByte4 sp58;
    FclByte4 sp54;
    FclByte4 sp50;
    FclByte4 sp4C;
    FclByte4 sp48;
    FclByte4 sp44;
    u8 *p;
    u8 *t;
    u8 *q;
    s32 v;

    t = *(u8 **)(arg0 + 0x38);
    func_002b2a60(&sp6C, 0, 0, 0x66, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp6C;
    q = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(q + 0x85) = *(FclByte4 *)(p + 0x85);
    func_002b2a60(&sp68, 0xCC, 0xFF, 0xFF, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp68;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
            func_002b2a60(&sp64, 0xCC, 0xFF, 0xFF, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp64;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        func_002b2a60(&sp60, 0xCC, 0xFF, 0xFF, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp60;
    }
    func_002b2a60(&sp5C, 0x25, 0x2F, 0x94, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp5C;
    func_0045af60(0, 0, 0, 0);
    switch (arg1) {
    case 0:
        *(s8 *)(t + 0xB3) = (s8)func_002b2cb0(*(s8 *)(t + 0xB3), 1, 2, 0, 2);
        break;
    case 1:
        *(s8 *)(t + 0xB3) = (s8)func_002b2d00(*(s8 *)(t + 0xB3), 1, 0, 2, 2);
        break;
    case 2:
    case 3:
    default:
        break;
    }
    func_002b2a60(&sp58, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F4));
    *(FclByte4 *)(p + 0x85) = sp58;
    func_002b2a60(&sp54, 0xC6, 0xEE, 1, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) * 2 + 0x1F5));
    *(FclByte4 *)(p + 0x85) = sp54;
    func_002b2a60(&sp50, 0x2D, 0x2D, 0x2D, 0xFF);
    v = *(s8 *)(t + 0xB3) * 2;
    p = func_002b6150((s16)*(s16 *)(v + (s32)t + 0xB8));
    *(FclByte4 *)(p + 0x85) = sp50;
    if (*(s8 *)(t + 0xB3) == 1) {
        if (func_00106330(0x1305) != 0) {
            func_002b2a60(&sp4C, 0x2D, 0x2D, 0x2D, 0xFF);
            p = func_002b6150(0x2EB);
            *(FclByte4 *)(p + 0x85) = sp4C;
        }
    }
    if (*(s8 *)(t + 0xB3) == 2) {
        func_002b2a60(&sp48, 0x2D, 0x2D, 0x2D, 0xFF);
        p = func_002b6150(0x175);
        *(FclByte4 *)(p + 0x85) = sp48;
    }
    func_002b2a60(&sp44, 0x92, 0xC8, 7, 0xFF);
    p = func_002b6150((s16)(*(s8 *)(t + 0xB3) + 0x2FB));
    *(FclByte4 *)(p + 0x85) = sp44;
}


// FUN_00317900
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00317900);

/* measured: nd 427 — the FP-saved-register allocation differs and nothing
   source-shaped moves it. Retail spills the sp108 f32 local to its stack slot
   (swc1 0x108) and assigns FP saved regs in def order to [sp10C->$f23, v2->$f22,
   v1->$f21, v20->$f20, v24->$f24]; mwcc b210 keeps BOTH sp108/sp10C in saved FP
   regs ($f24/$f25, frame 0x110 vs retail 0x120, one extra swc1) and assigns
   [sp10C->$f25, sp108->$f24, v1->$f23, v2->$f22, v20->$f21, v24->$f20].
   Tried: declaration-order permutations of the f32 locals (sp108/sp10C/v1/v2/
   v20/v24 in all plausible orders), and fully inlining the 6.0f+sp108 /
   62.0f+sp10C / 33.0f+sp108 / 20.0f+sp108 / sp10C-44.0f expressions at the six
   2970 calls (mwcc CSEs them into the identical allocation) — all nd 427. The
   rest of the function (if/else chains, 6150/2970/68d0/6c30 chains, the
   adda.s/msub.s FPU-fusion expression (5.0f+sp108)-2.0f*(46b260(h)/10.0f), the
   FclByte4 copies) matches. FP saved-register rotation floor. */
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

/* measured: nd 194 — the whole body (both branches, all copy chains, call
   shapes) matches except a fixed saved-register rotation (6-declaration-order
   probe batch, all nd 194): retail allocates arg1->$s3, t->$s2, v17->$s1,
   v16a->$s0, v22->$s6, v20->$s4, chain->$s5, arg3->$s7; mwcc b210 always emits
   arg1->$s4, t->$s3, v17->$s2, v16a->$s1, v22->$s0, chain->$s5, arg3->$s6.
   Also the v20=0xFF / v16b=0x66 constants: retail materializes addiu +0xFF,
   normalizes with andi (u8 semantics) and keeps the value in a saved register
   across the second 6150 jal; mwcc always emits addiu -1 and re-materializes
   per use (the explicit &= 0xFF is DCE'd; (s8)(v20 & 0xFF) is constant-folded).
   Everything else — the FclByte4 copy chains (0x75/0x85 offsets), the
   (s8)arg1/(s16) casts, 2ba970/2a30/34ae50 calls, the andi after the first sb —
   reproduces exactly. Saved-register rotation + constant-materialization
   floor. */
// FUN_0031DDF0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0031ddf0);

/* measured: nd 83 — pure saved-register rotation + one 2-word arg-order swap.
   retail allocates [arg1->$s2, t->$s3, id->$s4] (ext->$s0, p->$s1); mwcc b210
   always emits [id->$s2, arg1->$s3, t->$s4] regardless of local declaration
   order (t/id swapped, both orders tried) or an s8 v=arg1 param-copy local
   (coalesced away). Also retail materializes the 6b90 call args in order
   (move $a0 first, then lwr/lwl $a1); mwcc schedules the unaligned load first.
   Real fixes applied along the way: arg0 must be s16 (s32 re-normalizes id with
   dsll32/dsra32 at each 6b90 call, nd 131), stack locals must be declared
   sp7C..sp6C top-down, and the unaligned 4B loads must be written at 0x85/0x75.
   Saved-register rotation + argument-order floor. */
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

/* measured: nd 415 — two interlocked allocation defects; all call shapes (the
   191c0 u16/u8 params, ac10 10-arg stack call, e5b0, the FclByte4 copies, the
   loop conditions) match. (1) mask-CSE floor: mwcc b210 hoists the loop-invariant
   v0&0xFF / v1&0xFF masks into saved registers ($s3/$s4 + raw copies in $s7/$fp,
   frame 0x120 vs retail 0x100); retail re-issues andi per 6a70 call site. The
   6a70 params are u8 (conversion per call) yet the CSE persists. (2) loop-counter
   rotation: retail keeps i->$s2 with the (s16)i norm copy in $s0 and h->$s1;
   mwcc always emits i->$s0, norm->$s1, h->$s2. Fixed along the way: arg2 must be
   s32 (an s8 param makes mwcc pre-extend it into an extra saved reg for the e5b0
   arg), 191c0/ac10 4th/5th params are u16/u8 (s32 params add andi conversions).
   Mask-CSE + saved-reg rotation floor. */
// FUN_00323D00
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00323d00);

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

/* measured: nd 259 — one large saved-register allocation cascade, decl-order
   insensitive (6-candidate probe, all nd 259): retail reuses t's $s0 for v16 and
   keeps arg2 in $s3, v23 in $s7, v30 in $fp, and the (s16)v17 test temp in $v1
   (dies before the jal, slti reads it); mwcc b210 always keeps t in $s0, moves
   v16 to $s3, spills arg2, puts v23 in $fp and spills v30, and CSEs the loop
   increment onto the test temp (forcing $s1 saved) with the slti on the raw
   value. Also: the spD8->spE8 FclVec2 copy compiles interleaved
   (load-store-load-store) or merged/ld-sd instead of retail's
   load-load-store-store lwc1/swc1 batch, and the f20 y-load is hoisted above
   the 9.0f lui with an addiu+lwc1 pair instead of retail's lui/mtc1/lwc1
   direct-offset order. Everything else reproduces exactly: both loops' shapes,
   the v18==0x14B->0x14C adjust, 61*v21 and i2*3 strength reductions, the
   (s16)((s16)x+0xF1)+0x1F4 double-truncation pattern, D_007495C0/D_00749600
   absolute array addressing, the 3x func_002b77d0 11-arg calls with sp0/sp8
   s64 stack args, the >=3 && !=12 if/else branch layout. Saved-register
   rotation + load-scheduling floor. */
// FUN_00329310
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329310);

/* measured: nd 333 — two interlocked allocation defects, everything else (all
   2970/6c30/6150/69f0 chains, ldr/ldl unaligned s64 loads, the switch) matches.
   (1) D_006440B8[1] address: retail materializes lui/addiu into $s1 ONCE at the
   top and reuses it across all ~12 sites; mwcc b210 rematerializes lui per use.
   A f32 *q = D_006440B8 local makes mwcc keep q in a saved reg but it still
   rematerializes the FIRST use and grows the frame 0xE0->0xF0 (5th saved reg),
   nd 345. (2) the (s8)arg2 byte-extension: retail sign-extends IN PLACE on the
   saved arg2 register ($s0); mwcc allocates a separate saved register for the
   CSE'd extension (raw kept live) unless pressure forces coalescing. Tried
   inline (s8)arg2 casts, bare arg2==0 (s8 param), and the q-local variants —
   all nd >= 333. Constant-address rematerialization + saved-reg rotation floor. */
// FUN_003297F0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003297f0);

// FUN_00329E40
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00329e40);

/* measured: nd 356 — the frame stays 0x60 vs retail 0x70 because mwcc b210
   refuses two saved values: (1) the per-block 0x66 constant (sb p+0x6E + 6a70
   arg) is sunk AFTER the second func_002b6150 jal into a dead temp ($a2), while
   retail materializes addiu $s1,0x66 BEFORE the jal and keeps it in $17 across
   it — tried named s32 local and inline 0x66, both sink; (2) the 11.0f+sp50.x
   value used by both the 0x2E2 and 0x2E3 2970 calls is coalesced onto the dead
   f21 register instead of retail's fresh $f22. Also the sp40->sp50 FclVec2 copy
   never reproduces retail's batched lwc1/lwc1/swc1/swc1 (struct assignment gives
   ld/sd, field-wise and cast forms give interleaved load-store-load-store).
   Everything else reproduces exactly: all 6 if/else blocks' 6c30/2a60/6150/
   FclByte4-copy/6a70 sequences, the (f32)0x125/(f32)0x11D cvt.s.w idiom, the
   1.0f swc1s at 0xAC/0xA0, 7750(0x2E2,0x9E)/7750(0x2E3,0xA0), 6d60, else-branch
   lbu p+0x6E args. Saved-register rotation + load-scheduling floor. */
// FUN_0032A960
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032a960);

/* measured: nd 395 — the f32-pair stack-slot placement is unmovable and breaks
   the s64 recombination. Retail keeps the 2970 output copy as f32s at 0xD0/0xD4
   (adjacent, read back as one s64 `ld $a1, 0xd0` for 6c30 and re-read as halves);
   mwcc b210 places the two f32 locals at 0xD8 and 0xCC (non-adjacent, the
   *(s64 *)&spD0 read then spans spDC, corrupting every downstream block ~20
   words), regardless of declaration order. An f32 spD0[2] array grows the frame
   0xE0->0xF0 (array placed at 0xE0); declaring the pair as one s64 adds a saved
   register (digit value gets a fresh $s3 instead of reusing t's $s2, frame
   0x100). Constants verified against retail during the attempts: 0x43850000 is
   266.0f, 0x43570000 215.0f, 0x43540000 148.0f, 0x43550000 149.0f, 0x43530000
   147.0f (my initial decode was off by one); the (s8)arg1 ext IS in-place on
   $s0. Stack-slot placement floor. */
// FUN_0032B000
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b000);

// FUN_0032B770
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b770);

// FUN_0032B9D0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032b9d0);

/* measured: nd 4 (2-word swap + 1 padding word): case 4's r test — retail stores
   sh $v0 first, then truncates $v0 IN PLACE (dsll32/dsra32) for the bnez; mwcc
   b210 always precomputes the truncated value into $v1 before the sh, regardless
   of spelling (inline (s16)r cast, s16/s32 r, inverted if/else, explicit
   r = (s16)r statement). Everything else — all 5 case bodies, jump table, FMA
   madd.s f20,f20,f21, v17 normalization at (s16)((s16)v17-1) — matches exactly.
   $v0/$v1-family scheduling floor. */
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
/* measured: nd 176 — one fixed saved-register rotation: retail allocates t to $s7
   and the six inner-loop func_0034ae50 results to $fp/$s0/$s5/$s6 (e4/e5 spill to
   0xD0/0xC0, frame 0x110); mwcc b210 always gives t $fp and spills e0/e1 (frame
   0x120). Declaration order has ZERO effect (6-order probe batch, all nd 178),
   and the (s16)j loop-test temp lands in $s7 instead of reusing the dead e1 $s0.
   Also the v11 lb $t3 arg-8 load is emitted after the (s8)i dsll (retail before),
   and the inner pre-header emits sll/addu before the j=0 move (retail after).
   Everything else reproduces exactly: func_003191c0 8th stack-arg-in-$t3 call,
   p2 = t + (s16)i*4 hoist, ldr/ldl unaligned s64 args, lbu/lwc1 arg block,
   sp0/sp8 s64 stack args, FMA madd.s f12,f3,f2 + cvt.s.w 329.0f, div.s /2.0f,
   i2*23 strength-reduced mul, loop shapes. Saved-register rotation +
   load-scheduling floor. */
// FUN_0032FBC0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_0032fbc0);

/* measured: nd 126 — three interlocked register/scheduling rotations; all
   logic (jtbl switch cases, both loops, the FclByte4 chains, the tail
   adda.s/madd.s FPU-fusion store) matches. (1) p (the *(u8**)(arg0+0x38) load)
   lands in $s4 in mwcc b210 vs $s3 in retail: mwcc gives the loop's (s16)j
   normalized copy a fresh saved register ($s2) where retail reuses arg1's dead
   $s1, shifting t18->$s3/p->$s4. (2) loop 22's counter: retail keeps the raw
   counter in $s0 and normalizes into a temp per use; mwcc keeps the raw in a
   temp and the normalized copy in $s0. (3) case stores: retail stores the raw
   2cb0/2d00 result (sh $v0) BEFORE the (s16) normalize for the 2d50 arg; mwcc
   always normalizes first. Tried: declaration orders, s16/s32 r and lim (lim
   MUST be s32 — s16 adds a spurious normalize and grew nd to 243->126 cascade;
   r s32/s16 no effect), named lim local (kills the per-iteration t18+6
   recompute — big win, 414->243). Saved-register rotation + scheduling floor. */
// FUN_00330060
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_00330060);

// FUN_003307B0
INCLUDE_ASM("asm/nonmatchings/y_fclCombineDraw", func_003307b0);

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
