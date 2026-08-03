/* Consolidated Persona 4 source units. */
/* Original translation unit shdPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdktask.h"
#include "include_asm.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

void func_0011e230();
void func_0011e240();
void func_0046d4c0(s32, s32, s32, f32, f32, u8, u8, u8, u8, f32, s32);
void func_0011e2b0(u8 *arg0, Vec2f *arg1, Vec2f *arg2);
void func_0011aaa0();
void func_0011ba40();
void func_0011e3c0(s32, s32);
void func_0011fd10(s32);
void func_00452080();
void func_0011bc70();
s32 func_00115020();
void func_0045af60(s32 a, s32 b, s32 c, s32 d);
s32 func_001152b0();
void func_00115cb0(Vec2f, s32, s16 *, f32);
void func_00115e90(Vec2f, s32, s16 *, f32);
void func_00275020(s32, s32, s32, u8 *, s32, s32, f32, f32, f32);
void *func_00109220(u16 arg0);
void func_00116190(s64, s32, u8 *, s32 *, f32);
void func_00116610(s64, s32, u8 *, s32 *, f32);
void func_001162f0(s64, s32, u8 *, s32 *, f32);
void func_001163e0(s64, f32, s32, u8 *, s32 *);
void func_00116820(s64, s32, u8 *, s32 *, f32);
typedef struct {
    s32 lo;
    s32 hi;
} I64;
void func_00116d40(I64, f32, s32, u8, u8, s32, s32);
void func_0045d6e0(f32, u8 *, s32 *, s32);
extern void (*D_00887300[])(u32, u32);
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern char D_005E57F0[];

void func_0046d730(const char *file, s32 line);
void func_0043f9c8(void *dst, s32 value, s32 size);
s32 func_0010cc20();
void func_00115420();
void func_00115940();
s32 func_0010c750();
s32 func_00109430();
s32 func_0010cd70(s32, s32, u8 *);
void func_00115500(s16, u8 *, u8 *);
s32 func_0011dfc0(s32, s32, char *);
void func_00454bd0();
void func_003ef3a0();
void func_0044ea90(const void *msg, s32 id);
extern u8 *(*D_008873F4[])(s32, s32, s32);
s32 func_00451de0(void *data, s32 a, s32 b, s32 c, void *init, void *close, void *buf);
extern char D_005E4810[];
extern char D_005E4EB0[];
extern char D_005E4F50[];
extern char D_005E4F10[];
void func_001175e0(u8 *, s32, s32, s32);
s32 func_001178a0(u8 *);
void func_0011b2d0(u8 *);
s32 func_0011d1f0(u8 *);
void func_0011d3c0(u8 *);
u8 *func_0011d460(s32, s32, f32, s32, s32);
void func_0011e390(u8 *, Vec2f);
void func_00364680(s32, s32 *, s32, s32, f32, f32, f32, f32, f32, f32, f32);
void func_003f6440(s32, s32);
s32 func_0011f5a0(u8 *);
void func_0011fb90(u8 *);
extern s32 D_005E4850[];
extern char iGpffff9c20;
extern u8 D_005E4950[];
extern u8 D_005E4880[];
extern u8 D_005E4A20[];
extern u8 D_005E4AF0[];
extern u8 D_005E4BC0[];
extern u8 D_005E4C90[];
void func_00442830(void *dst, s32 value);
void func_002bbd20(s32 param, void *text);
void func_00442088(void *dst, void *fmt, s32 value);
void func_002bad10(s32 param);
void func_002baf40(s32 a);
void func_002bb050(s32 a);
void func_002bbf60(void);
void *func_00243840(u16 a);
s32 func_0011e490(u8 *);
void func_0011c6e0(u8 *, s32);
void func_0011b480(u8 *, s32, u32, s32);
void func_0011d5b0(f32, s32, s32, f32, f32, s32, s32, s32);
u32 func_0011e3e0(u8 *);
f32 func_0044b7b0(f32 arg0);
f32 func_0044b610(f32 arg0);
extern f32 D_007613EC;
extern f32 D_00761184;
s32 func_004669d0();
s32 func_00440b68();
extern char D_005E4ED0[];
extern char D_005E4EF0[];
void func_0045aeb0(s16 channelIndex, const char *name);
extern char D_005E4868[];
extern char D_005E4E20[];
extern char D_005E4E40[];
extern u8 D_00793E80[];

extern void (*jtbl_008873EC[])(u8 *);





// FUN_00115890
s32 func_00115890(u8 *arg0, s32 arg1)
{
    u8 c = *(u8 *)(arg0 + 4);
    s32 s17;
    s32 r;
    if (c == 0x63) {
        return 0;
    }
    s17 = c + (arg1 & 0xFF);
    if (s17 > 0x63) {
        func_0046d730(D_005E4868, 0x65);
    }
    s17 = func_0010c750(arg0, (u16)(s17 + 1));
    r = s17 - func_00109430(arg0);
    if (r < 0) {
        return 0;
    }
    return r;
}



s8 func_00109390(u8 *arg0);
s8 func_00109920(u8 *arg0, s32 arg1);
s8 func_001099f0(u8 *arg0, s32 arg1);
s8 func_00109ad0(u8 *arg0, s32 arg1);
s32 func_001097c0(u8 *arg0, u16 arg1);
extern u16 D_007465D0[];
// FUN_00115940
void func_00115940(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 v2;
    u8 b4;
    s32 i;

    if (arg0 == NULL) {
        func_0046d730(D_005E4868, 0x76);
    }
    *(u16 *)(arg1 + 2) = *(u16 *)(arg0 + 2);
    *(s8 *)(arg1 + 4) = func_00109390(arg0);
    b4 = *(u8 *)(arg0 + 4);
    if (b4 == 0x63) {
        v2 = 0;
    } else {
        if ((s32)b4 > 0x63) {
            func_0046d730(D_005E4868, 0x65);
        }
        v2 = func_0010c750(arg0, (b4 + 1) & 0xFFFF) - func_00109430(arg0);
        if (v2 < 0) {
            v2 = 0;
        }
    }
    *(s32 *)(arg1 + 0x38) = v2;
    switch (arg2) {
    case 0:
        *(s8 *)(arg1 + 7) = func_00109920(arg0, 0);
        *(s8 *)(arg1 + 8) = func_00109920(arg0, 1);
        *(s8 *)(arg1 + 9) = func_00109920(arg0, 2);
        *(s8 *)(arg1 + 0xA) = func_00109920(arg0, 3);
        *(s8 *)(arg1 + 0xB) = func_00109920(arg0, 4);
        break;
    case 1:
        *(s8 *)(arg1 + 7) = func_001099f0(arg0, 0);
        *(s8 *)(arg1 + 8) = func_001099f0(arg0, 1);
        *(s8 *)(arg1 + 9) = func_001099f0(arg0, 2);
        *(s8 *)(arg1 + 0xA) = func_001099f0(arg0, 3);
        *(s8 *)(arg1 + 0xB) = func_001099f0(arg0, 4);
        break;
    case 2:
        *(s8 *)(arg1 + 7) = func_00109ad0(arg0, 0);
        *(s8 *)(arg1 + 8) = func_00109ad0(arg0, 1);
        *(s8 *)(arg1 + 9) = func_00109ad0(arg0, 2);
        *(s8 *)(arg1 + 0xA) = func_00109ad0(arg0, 3);
        *(s8 *)(arg1 + 0xB) = func_00109ad0(arg0, 4);
        break;
    default:
        func_0046d730(D_005E4868, 0x96);
        break;
    }
    for (i = 0; i < 7; i++) {
        *(s32 *)(arg1 + 0x14 + i * 4) = func_001097c0(arg0, D_007465D0[i]);
    }
}



// FUN_00115C00
void func_00115c00(u8 *arg0, u8 *arg1)
{
    s32 i = 0;
    while (i < 5) {
        *(u8 *)(arg1 + i + 0xC) = *(u8 *)(arg0 + i);
        i++;
    }
}



// FUN_00115C40
void func_00115c40(Vec2f arg0, s32 arg1, s16 *arg2, f32 farg3)
{
    switch (*arg2) {
    case 0:
        func_00115dc0(arg0, arg1, arg2);
        break;
    case 1:
        func_00115e90(arg0, arg1, arg2, farg3);
        break;
    case 2:
        func_00115cb0(arg0, arg1, arg2, farg3);
        break;
    }
}



/* measured: two known floor families. (1) retail reads the color from the
   live register (andi $v1, $a1, 0xff) and emits mov.s $f20, $f12 before
   move $s1, $a2; mwcc b210 marks the Vec2f param address-taken via
   &arg0.y (needed for the (f32)(s32) float round-trips that read the
   0x58/0x5C home) and emits lbu 0x5c + the GP move first — address-take
   registerisation floor, same family as func_001162f0; the prologue move
   order is the func_001171c0 scheduling family. (2) final-call arg
   materialisation order (retail mov.s $f14, $f20 before the GP args).
   Tried direct &arg0.y, struct-copy local (grew frame to 0x170), and
   m2c statement order (frame 0x150) — best nd 20. Note: the ABI-faithful
   4-param prototype + func_00115c40 farg3 pass-through are kept; the
   func_00115cb0 call site's $f12 is genuinely uninitialised in retail. */
// FUN_00115CB0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115cb0);



void *func_00109220(u16 arg0);
/* measured: the callee reads a 4th float argument ($f12 -> $f20 -> f14 of
   func_00274ed0) but every in-file caller (incl. matched func_00115c40) calls it
   with THREE args through an old-style () declaration, leaving $f12 as garbage;
   mwcc b210 rejects an old-style () prototype followed by a 4-param new-style
   definition ("redeclared", also K&R definitions unsupported), so the true
   prototype cannot be expressed without rewriting the matched caller. ABI
   prototype floor. */
// FUN_00115DC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115dc0);



/* measured: two documented floor families. (1) The D_00887300
   render-vtable base hoist — retail keeps lui/addiu of the table base in
   $s0 across all 8 jalr calls; mwcc b210 rematerialises lui/lw per call
   (brief's vtable-hoist floor; nd contribution ~16 words). (2) The
   &arg0.y address-take floor (func_00115cb0 family): retail keeps the
   colour in $s2 (move $s2, $a1) plus the sd $a0, 0x58 pair home; mwcc
   goes memory-only (frame 0x70 vs 0x80). Signature note: the s64-typed
   definition (s64 arg0, u8 *arg2, f32 fparg0) is ABI-correct and is what
   the family callees use, but mwcc b210 rejects both `()` and implicit
   int declarations followed by a typed definition, and the caller
   (matched func_00115c40) passes a Vec2f, so the definition must stay
   Vec2f-typed here. The 4-param prototype + farg3 pass-through is kept
   (ABI-faithful, func_00115c40 still matches). */
/* measured: fully decompiled, best nd 168 (obj 696B / window 768B). The
   frame 0x80, the sd $a0, 0x58 home, the 4 func_0046a770 stores, the
   func_00116190/16610/162f0/163e0/16820/16d40 call sequences and the loop all
   reproduce with `*(f32 *)&arg0.x` reads + `f32 y = arg0.y;`. Remaining:
   (1) the D_00887300 base hoist floor is CONFIRMED — retail keeps lui/addiu
   of the table base in $s0 with per-call `lw $v0, ($s0)`, and mwcc
   rematerialises lui/lw per call; even `void (**tbl)(u32,u32) = D_00887300;
   tbl[0](...)` folds back (it DID hoist in func_0011d5b0's context — the
   allocator gives the saved slots to arg1/arg2 first here, so the tbl gets no
   register and is folded); (2) FP saved-reg order: retail y->$f20, farg3->$f21
   (reverse first-use), mwcc puts farg3 in $f20 and re-reads y from the home
   per use; (3) arg registers: retail arg1->$s2, arg2->$s1, mwcc arg1->$s1,
   arg2->$s0. The family prototypes were corrected to 5-arg
   (s64, s32 colour, u8 *, s32 *, f32) and func_00116d40 to
   (I64, f32, s32, u8, u8, s32, s32) — the 4-arg forms in the old notes were
   wrong (the colour IS a register argument). */
// FUN_00115E90
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115e90);



u8 *func_0010d6d0(s16 arg0);
void func_00274ed0(s32, s64, s32, u8 *, s32, s32, f32, f32, f32);
/* measured: retail saves fparg0 FIRST into $f20 and gives the s64 home's high
   word $f21 with the (f32)(s32)(114.0f+low) result in $f22; mwcc b210 allocates
   the high-word local to $f20 and fparg0 to $f21, and reorders the prologue
   (sd $a0 home and move $s3 before mov.s), nd 78 with the whole body shifted.
   Tried FP declaration orders both ways — identical. FP-colouring floor. */
// FUN_00116190
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116190);



/* measured: nd 33. The right signature is (s64 arg0, s32 *arg3,
   u8 *arg2, f32 fparg0) — the colour and its float bits ride in arg0's
   HIGH WORD ($a1; the callers overwrite $a1 with the colour after their
   8-byte ld), and the $7 arg3 (lw $s1, ($a3)) is the third GP param.
   NOT tried with that shape: colour = ((s32 *)&arg0)[1] (pointer read;
   with the s32/s32 5-arg model the &arg1 address-take floor above
   applies: mwcc goes memory-only, lbu 0x4c + sw/sw pair). The s64 model
   registerizes the high word (see func_00116610/001163e0 notes) but the
   plain-move colour read still eludes mwcc (dsra32 or home read). */
// FUN_001162F0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001162f0);



s32 func_00109280();
f32 func_0046b1f0(s32, s32);
void func_001171c0(s64, s32, s32, s32, f32);
/* measured: FP/GP colouring residual, nd 99. The family's real signature
   IS (s64 arg0, u8 *arg2, s32 *arg3, f32 fparg0) with the color and its
   float bits coming from arg0's HIGH WORD (the callers clobber $a1 with
   the color after the 8-byte ld) — this removed the func_001162f0
   address-take floor entirely. What remains: (1) retail reads the high
   word via a plain move ($s3 = $a1) while mwcc emits dsra32 for
   (s32)(arg0 >> 32) — the untried spelling is c = ((s32 *)&arg0)[1]
   (pointer read, no shift); (2) the b1 bits local lands in $f22 (3rd FP
   saved reg, prologue swc1 $f22) instead of retail's $f20, and fparg0 in
   $f20 instead of $f21 — FP colouring floor family; (3) sp90/sp94 stay
   in registers instead of retail's store-and-reload (frame 0x90 vs
   0xA0). Tried s32/s64 arg0 models, param orders, b1/c locals first,
   inline bit-casts — best nd 99. */
/* measured: fully decompiled, best nd 6 (obj 552B / window 560B) — the ONLY
   residual is the func_001171c0 call's argument-materialisation ORDER: retail
   emits [ld $a0,0x90; mov.s $f12,$f21; lw $5,0x9c; lbu $a2,4($s2); move $a3],
   mwcc emits [lbu $a2 first; ld second; mov.s $f12 last] — pure scheduling
   swap, no semantics. The real signature IS (s64 arg0, f32 fparg0, s32 arg1,
   u8 *arg2, s32 *arg3) — colour is a separate 3rd GPR arg (the old 4-arg
   family notes were wrong); the declaration order (arg0 before fparg0)
   controls the prologue [sd $a0, 0x88; mov.s $f21] order. Also reproduced:
   fB = *((f32 *)&arg0 + 1) kept in $f20 with the high word re-read per use
   (same family idiom as func_00116820), the sp90[2] array for the s64 pair
   passed to func_001171c0, and the inv as TWO statements
   (temp_20_2 = arg1 & 0xFF; temp_20_2 = 0xFF - temp_20_2;) to get retail's
   [andi, addiu, subu] order. func_001171c0's real proto is (s64, s32, s32,
   s32, f32) — fixed in this file. */
// FUN_001163E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001163e0);



void func_00117310(I64, s32, s32, s32, s32, f32);
extern char iGpffff9c1c;
/* measured: same param address-take registerisation floor as
   func_001162f0 — retail keeps arg1 in $s1 across both asserts (move
   $s1, $a1 in the prologue, sd $a0, 0x88 pairing the arg0/arg1 homes)
   with the color math (andi/sll/subu/divu/mflo $s5) hoisted before the
   first assert; mwcc b210 sees &arg1 (the *(f32 *)&arg1 bit reads for
   sp194 and the final call) and goes memory-only (lbu/sw from the
   home, two sw instead of the sd pair, frame 0x170 vs 0x1A0, nd 121).
   Tried s32 and u8 arg1, a local copy, and a union-cast local (probe
   batch) — identical. Note: func_00117310's real signature is
   (s32, s32, s32, s32, s32, f32) — the caller's ld $4, 0x190 is an
   over-read whose high word is clobbered by the sp19C arg in $a1. */
/* measured: nd 121-124, FP/GP colouring + layout residual. The s64
   signature (s64 arg0, u8 *arg2, s32 *arg3, f32 fparg0) IS right — the
   colour and its float bits ride in arg0's HIGH WORD (callers clobber
   $a1 with the colour after their 8-byte ld) — and with it mwcc does
   registerize the high word (move $s4, $a1, frame 0x190) instead of the
   func_001162f0 address-take memory-only shape. What still differs:
   retail reads the colour via a plain move into $s1 while mwcc needs
   either dsra32 ((s32)(arg0 >> 32)) or a home read (((s32 *)&arg0)[1]);
   the b1 bits local lands in $f21 and the sp190/sp194 locals stay in
   registers (frame 0x190 vs 0x1A0, the sp90 buffer mis-laid-out). Best
   of 4 attempts (s32/s64 arg0, local copies, bit-casts). Next wave:
   try c via the low word of the colour expression or a union member. */
// FUN_00116610
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116610);



/* measured: fully decompiled, best nd 911 (obj 1200B / window 1312B). The real
   signature IS (s64 arg0, s32 arg1, u8 *arg2, s32 *arg3, f32 fparg0) — the colour
   is a separate s32 arg in $5 (the family floor notes claiming a 4-arg form do
   NOT apply here). func_0046d4c0's real prototype (matched in sdkSpr.c) is
   (s32,s32,s32,f32,f32,u8,u8,u8,u8,f32,s32) and func_00117310's arg0 is 8-byte
   (I64) — both prototypes fixed in this file. Residuals: (1) retail keeps the
   per-iteration spA4 load CSE'd into $f22 across the loop's calls, mwcc reloads
   per call (I64-struct) or keeps a permanent register (separate f32 locals);
   (2) retail hoists (65+fA)-0x13B and 152+(fB-88) into $f22/$f20 in loop2's
   preheader, mwcc rematerialises in the body (#pragma opt_loop_invariants
   untried within budget); (3) temp_22 lands $s4 and arg2 $s6, retail is the
   reverse (declaration orders tried: [temp_22,var_19,temp_18,temp_17]);
   (4) var_f0 negative path: retail doubles with add.s $f0,$f0,$f0, mwcc emits
   mul.s for 2.0f*x (x+x lever untried within budget). Note: m2c's var_6-as-arg3
   reading of the 0xDE call is wrong — that call's arg1 is the constant 0xDE and
   the var_6 chain is dead code retail kept; mwcc reproduces the dead chain. */
// FUN_00116820
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116820);



extern f32 iGpffff82fc;
/* measured: nd 231, the family colouring catch-22 (same as func_001162f0 /
   00116610): retail reads the colour once from the live register (move
   $s4, $a1) and the high-word float bits from the sd home (lwc1 0x9C);
   mwcc b210, once the arg0 pair is address-taken for the bit reads,
   keeps a second colour copy from the home (lw $s0, 0x9c or dsra32
   $s0, $a0, 0) and swaps the FP saved registers ($f20/$f21) plus the
   GP colouring. Tried s64, I64 struct, (s32)(arg0 >> 32),
   ((s32 *)&arg0)[1] and inline *(f32 *)&arg0 spellings (4 attempts) —
   nd 231 flat. The rest of the function decodes cleanly (the abs-bltz
   here is on the genuinely signed colour and survives). */
// FUN_00116D40
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116d40);



/* measured: retail emits the prologue saves in the order mov.s $f22/$f12 (fparg0),
   sw $a1,0x7c (cbytes), move $s4,$a2, move $s3,$a3, and sinks the per-iteration
   lbu cbytes[0] to the middle of func_0046d4c0's argument materialisation
   (after mov.s $f12/$f13, before move $t3); mwcc b210 always hoists the two GP
   arg saves above the cbytes store and emits the lbu before the $a0/$a1 moves
   (nd 15, all pure instruction-order swaps, no semantics). Tried 6 source
   orderings/type shapes incl. s64 5-arg, Vec2f, s32 5-arg, u8 vs s32 byte
   locals, statement permutations — all nd >= 15. Scheduling/materialisation
   order floor, same family as func_0011ded0. */
// FUN_001171C0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001171c0);



/* measured: same floor family as func_001171c0 — retail emits the prologue in
   the order mov.s $f22 (fparg0), sw $a1,0x7c (cbytes), then the GP arg saves,
   and hoists the loop's 16.0f/0xA constants BEFORE the initial branch to the
   while-test; mwcc b210 emits the GP saves before the FP save and places the
   constants after the branch (nd 20, all instruction-order rows). Tried
   declaration/statement orders — identical. Scheduling floor. */
// FUN_00117310
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117310);



// FUN_001174A0
f32 func_001174a0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (arg0 < arg1) {
        return 0.0f;
    }
    if (arg0 < arg2) {
        f32 f = (f32)(arg0 - arg1) / (f32)(arg2 - arg1);
        switch (arg3) {
        case 0:
            break;
        case 1:
            f = func_0044b7b0(D_00761184 * f);
            break;
        case 2:
            f = 1.0f - func_0044b610(D_00761184 * f);
            break;
        }
        return f;
    }
    return 1.0f;
}



// FUN_00117580
void func_00117580(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (!((arg1 & 0xFFFF) < 0xD8)) {
        func_0046d730(D_005E4868, 0x595);
    }
    *(u16 *)(b + 0x570) = arg1;
}



void func_00119e10(u8 *arg0);
void func_00113750(u8 *arg0);
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern char D_005E57F0[];
/* measured: retail hoists the D_005E4880 loop base (lui/addiu) into $a1 before
   the initial branch to the loop test; mwcc b210 rematerialises it in the body
   each iteration — #pragma opt_loop_invariants on restores the hoist. */
#pragma opt_loop_invariants on
// FUN_001175E0
void func_001175e0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *b;
    s32 i;
    u8 *src;
    u8 *dst;

    b = *(u8 **)(arg0 + 0x38);
    *(s32 *)(b + 0x52C) = arg1;
    *(s32 *)(b + 0x50C) = arg2;
    *(s32 *)(b + 0x510) = arg3;
    *(s16 *)(b + 0x508) = 0;
    *(s32 *)(b + 0x52C) = -1;
    *(s32 *)(b + 0x538) = 0;
    *(s32 *)(b + 0x534) = 0;
    func_0043f9c8(b + 0x540, 0, 0x30);
    *(void (**)(u8 *))(b + 0x548) = func_00119e10;
    *(u8 **)(b + 0x550) = b;
    *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x570) = 0xB1;
    *(u8 **)(b + 0x4F8) = func_0011d460((s32)arg0, 0xF, 0, 0, -0x100);
    func_0011b6d0(arg0, arg1);
    *(s32 *)(b + 0x2B8) = func_0046a770(D_005E5810);
    *(s32 *)(b + 0x2BC) = func_0046a770(D_005E5830);
    *(s32 *)(b + 0x2C0) = func_0046a770(D_005E5850);
    *(s32 *)(b + 0x2C4) = func_0046a770(D_005E57F0);
    for (i = 0; i < 0xA; i++) {
        src = D_005E4880 + i * 0x14;
        dst = b + i * 0x24;
        *(f32 *)(dst + 0x2DC) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x2E0) = *(f32 *)(src + 4);
        *(u8 *)(dst + 0x2E6) = *(u8 *)(src + 8);
    }
    func_00113750(b + 0x84);
    *(s32 *)(b + 0x444) = 0xC3E10000;
    *(s32 *)(b + 0x448) = 0x80000000;
    *(u8 *)(b + 0x44E) = 0xFF;
    *(s32 *)(b + 0x450) = 0;
    *(s32 *)(b + 0x454) = 0x40A00000;
}


#pragma opt_loop_invariants off


// FUN_00117780
u8 *func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *w;
    u8 *r;

    func_0044ea90(D_005E4868, 0x5ED);
    w = D_008873F4[0](1, 0x574, 0x40000);
    if (w == NULL) {
        func_0046d730(D_005E4868, 0x5EE);
    }
    r = (u8 *)func_00451fc0(arg0, D_005E4810, arg1, 0, 0, func_001178a0, func_0011b2d0, w);
    if (r == NULL) {
        func_0046d730(D_005E4868, 0x5F8);
    }
    func_001175e0(r, arg2, arg3, arg4);
    return r;
}



// FUN_001178A0
s32 func_001178a0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 off;
    *(s32 *)(b + 0x540) = 0;
    *(s32 *)(b + 0x544) = 0;
    off = 0x30 * *(u16 *)(b + 0x570);
    func_00460ac0(D_00793E80 + off, b + 0x540);
    switch (*(s32 *)(b + 0x538)) {
    case 0:
        *(s32 *)(b + 0x538) = 1;
        /* fallthrough */
    case 1:
        if (*(s32 *)(b + 0) != 0) {
            *(s32 *)(b + 0x538) = 2;
            *(s32 *)(b + 0x534) |= 8;
        }
        break;
    case 2:
        break;
    case 3:
        if (!(*(s32 *)(b + 0x534) & 1)) {
            return -1;
        }
        break;
    }
    return 0;
}



// FUN_00117980
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117980);



void func_0034f4a0(s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s64, s64);
/* measured: retail keeps only t16 and arg2 in saved registers (frame 0x60 with
   the two s64 homes at 0x50/0x58); mwcc b210 also saves arg0 (frame 0x80,
   homes at 0x70/0x78) and the whole body shifts (nd 147, obj 8B over window).
   Tried declaration orders — identical. FP/GP colouring floor. */
// FUN_001187B0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001187b0);



// FUN_00118A20
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00118a20);



void func_0045dfd0(f32, void *, void *, s32, s32, s32);
/* measured: FP-colouring/preheader floor, same family as func_0011c3e0.
   retail keeps the acc sum entirely in the FP accumulator (adda.s after
   each lwc1, madd.s $f0,$f4/$f1,$f2, acc seed in $f3, 2.0f in $f4, cvt
   results in $f2); mwcc b210 allocates acc to $f4 with add.s updates,
   emits a stray mov.s $f2,$f4 acc-seed copy, swaps 2.0f into $f3, and
   syncs ACC via adda.s $f2,$f4 — everything else (incl. the
   #pragma opt_loop_invariants on hoist of all six loop constants, which
   IS needed) matches. Tried acc+=x, acc=x+acc, and both add-operand
   orders (probe batch, 4 spellings) — best nd 20, then 70. */
// FUN_001190F0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001190f0);



s32 func_00107890(s32);
void func_0046d2b0(s32, s32, s32, f32, f32, u8, f32, s32);
void func_001190f0(f32 *, u8);
extern u8 D_005E4DB0[];
extern f32 iGpffff8394;
/* measured: fully decompiled, best nd 358 (obj 1128B / window 1536B). All four
   (f32)(s32) conversions of masked/loaded non-negative values (temp_21 & 0xFF
   x2, func_003b7060() & 0xFFF, u16 table element) lose their `bltz` sign-check
   AND their downstream (u8)/(u16)(s32) 0x4F000000 overflow branches to mwcc
   b210's range analysis, while retail keeps all of them — the same documented
   floor as func_0011e490. Tried s32/u8/s8 loads, (s8)/(s16) casts (those emit
   lb/lh + dsll32/dsra32 sign-extension instead), explicit if/else, inline
   masks — all eliminated. Everything else reproduced: the 10x8B D_005E4DB0
   copy loop (lw/lw/sw/sw), the adda.s/madd.s and adda.s/msub.s FPU fusions
   (1.0f+0.5f*(x/4096.0f), 448.0f-898*f), counter store order, call args.
   Useful facts for the next attempt: func_0046d2b0's real signature is
   (s32,s32,s32,f32,f32,u8,f32,s32) (matched in sdkSpr.c — the u8 param gives
   the per-call andi), func_001190f0(f32 *, u8), func_00107890(s32)->s32,
   D_005E4DB0 at 0x005e4db0 (declarations kept). */
// FUN_00119210
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119210);



/* measured: fully decompiled, best nd 197 (obj 1400B / window 1536B, attempt 3).
   Four residuals vs retail. (1) The (u8)(s32) 0x4F000000 overflow branches on
   `0.5f * (f32)lbu-0x505 * (1.0f - var_f22)` and `(f32)lbu-0x505 * var_f23` are
   eliminated by mwcc's float range analysis (products proven < 2^31) while
   retail keeps them; the (f32)(s32) bltz on the raw lbu is NOT eliminated
   (loads are opaque to the sign analysis) - so unlike func_00119210, do NOT
   mask the 0x505 byte, but the overflow checks are a separate, still-unbeaten
   analysis. (2) FP saved-register rotation: retail var_f20->$f20, 1.0f->$f21,
   var_f22->$f22, var_f23->$f23; mwcc assigns var_f21(1.0f)->$f20 first and
   rotates the rest (declaration orders tried incl. [var_f23,var_f22,var_f21,
   var_f20]). (3) the u16 counter read-back reloads (lhu) instead of retail's
   forwarded andi after sh. (4) chain-1's (f32)v1 conversion keeps an extra
   bltz (path-proven in retail). Fixed during the attempt: func_00274ed0's
   caller-side 2nd param is s64 (matched def in cmpConfig.c declares s32 but
   retail callers pass the s64 register with a plain move); func_0034f4a0's
   11th param is f32 ($f14 via mtc1); iGpffff8394 = gp-0x7C98 = 0x00761458
   (both prototypes and the symbol kept). */
// FUN_00119810
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119810);



// FUN_00119E10
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119e10);



// FUN_0011AAA0
void func_0011aaa0(u8 *arg0, u32 arg1)
{
    u8 *p;
    f32 vf20;
    s32 i;
    u8 *t;
    u8 *d;

    p = NULL;
    for (i = 0; i < 0xA; i++) {
        t = arg0 + i * 0x24;
        *(f32 *)(t + 0x2CC) = *(f32 *)(t + 0x2DC);
        *(f32 *)(t + 0x2D0) = *(f32 *)(t + 0x2E0);
        *(u8 *)(t + 0x2E4) = *(u8 *)(t + 0x2E6);
    }
    switch (arg1) {
    case 0:
        p = D_005E4950;
        vf20 = (f32)*(s32 *)(arg0 + 0x50C);
        break;
    case 1:
        p = D_005E4880;
        vf20 = (f32)*(s32 *)(arg0 + 0x510);
        break;
    case 2:
        p = D_005E4A20;
        vf20 = 4.0f;
        break;
    case 3:
        p = D_005E4AF0;
        vf20 = 4.0f;
        break;
    case 4:
        p = D_005E4BC0;
        vf20 = (f32)*(s32 *)(arg0 + 0x50C);
        break;
    case 5:
        p = D_005E4C90;
        vf20 = (f32)*(s32 *)(arg0 + 0x510);
        break;
    default:
        func_0046d730(D_005E4868, 0xAA6);
        break;
    }
    if (p == NULL) {
        func_0046d730(D_005E4868, 0xAA9);
    }
    for (i = 0; i < 0xA; i++) {
        t = p + i * 0x14;
        d = arg0 + i * 0x24;
        *(f32 *)(d + 0x2D4) = *(f32 *)(t + 0);
        *(f32 *)(d + 0x2D8) = *(f32 *)(t + 4);
        *(u8 *)(d + 0x2E5) = *(u8 *)(t + 8);
        *(f32 *)(d + 0x2E8) = vf20 * *(f32 *)(t + 0xC);
        *(f32 *)(d + 0x2EC) = vf20 * *(f32 *)(t + 0x10);
    }
}



/* measured: retail keeps the per-iteration element pointer (arg0 + i*0x24) in
   $a2, surviving the func_0044b7b0 call (mwcc's reloadable-load caching in the
   arg registers) and saves only $s1=arg0/$s0=i; mwcc b210 colours the element
   pointer into a saved register $s0 (frame 0x40 vs 0x30, whole body shifted,
   nd ~40). Tried declaration orders — identical. Same a2-cache colouring floor
   as func_0011f5a0. Also: the m2c's 4-arg func_0044b7b0 call and the
   (u16)-cast var_6 pointer are hallucinated (real call is 1-arg). */
// FUN_0011AC70
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ac70);



extern f32 iGpffff8094;
/* measured: the documented a2-cache colouring floor (func_0011ac70 /
   func_0011f5a0 family) — retail keeps the per-iteration element pointer
   (arg0 + i*36) in a temp register across the func_0044b7b0 call and
   saves only $s1=arg0/$s0=i (frame 0x30); mwcc b210 colours the element
   pointer into a saved register (frame 0x40, whole body shifted, nd 158).
   The if/else-if/else lerp chain additionally lays the else-if body
   inline where retail places it out of line (bc1t to it after the 1.0f
   branch). Logic itself decodes cleanly: per-element lerp with the
   signed-byte abs construct, then the post-loop interpolate-or-clear
   with the four chained mask clears. */
// FUN_0011AE90
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ae90);



void func_0034c270(s64, u8, s32, f32);
/* measured: retail passes the zeroed 8-byte local as arg1 via a real
   ld $a0, 0x20($sp) and loads the 0x505 byte DIRECTLY into the s64's high
   word ($a1) at the func_0034c270 call (callee ABI (s64, u8, s32, f32) per
   the nLine prologue: sd $a0 pair save + bltz/andi/mtc1 on $a1 + $a2 index);
   mwcc b210 folds the zero local to `move $a0,$zero` when passed as
   (s64)sp20 (nd 103) and, with &sp20 address-taken, emits dsll32+or or
   unaligned ldr/ldl (nd 115); the s64 zero-init also compiles to one sd
   vs retail's two sw. Tried (s64)sp20, *(s64 *)&sp20, (s32)*(s64 *)&sp20,
   (x|b<<32) or-constructs, s64 vs s32-pair locals, 4 declaration orders
   (probe batches) — all nd 103-116. Memory-load fold/scheduling floor.
   The case-1 abs-style bltz construct survives here (unlike func_0011e490)
   but its register allocation still differs. */
// FUN_0011B110
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011b110);



// FUN_0011B2D0
void func_0011b2d0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = *(s32 *)(b + 0x52C);
    if (!(v == 1 || v == 4 || v == 3 || v == 2 || v == 0)) {
        func_0046d730(D_005E4868, 0xB59);
    }
    jtbl_008873EC[0](b);
}



// FUN_0011B360
void func_0011b360(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if ((*(s32 *)(b + 0x534) & 1) != 0 && *(s32 *)(b + 0x538) == 2) {
        func_0011bc70(arg0);
    } else {
        *(s32 *)(b + 0x534) &= ~1;
    }
    *(s32 *)(b + 0x538) = 3;
}



// FUN_0011B3D0
void func_0011b3d0(u8 *arg0, u8 *arg1)
{
    s32 v = *(s32 *)(arg0 + 0x52C);
    switch (v) {
    case 0:
    case 1:
    case 2:
        func_00115940(arg1, arg0 + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940(arg1, arg0 + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
}



void func_00113610(u16 *, u8 *);
void func_0011e0c0(u8 *, s32, s32);
s32 func_0011dec0(u8 *);
void func_0011cee0(u8 *);
// FUN_0011B480
void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s32 arg3)
{
    u8 *work;
    s32 t17;
    s32 t4;
    s32 state;
    u16 t3_2;

    work = ((SdkTask *)arg0)->work;
    t17 = func_0011dec0(*(u8 **)(work + 0x4F8));
    if (arg2 == 0) {
        func_0011e0c0(*(u8 **)(work + 0x4F8), 0, t17);
        *(s32 *)(work + 0x538) = 1;
        *(s32 *)(work + 0x534) &= ~8;
        return;
    }
    *(u16 **)(work + 0) = (u16 *)arg2;
    state = *(s32 *)(work + 0x52C);
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_00115940((u8 *)(u16 *)arg2, work + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940((u8 *)(u16 *)arg2, work + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
    *(s16 *)(work + 0xC) = (s16)arg1;
    func_00113610((u16 *)arg2, work + 0x8C);
    *(s8 *)(work + 0xEE) = (s8)arg3;
    func_0043f9c8(work + 0x4C0, 0, 0x30);
    func_0043f9c8(work + 0x4F0, 0, 6);
    if (!(**(u16 **)(work + 0) & 4)) {
        t4 = *(s32 *)(work + 0x534);
        if (t4 & 0x80000) {
            t3_2 = *(u16 *)(work + 0x458);
            if (!(t3_2 & 2)) {
                if (!(t3_2 & 1)) {
                    *(s32 *)(work + 0x534) = t4 & 0xFFF7FFFF;
                } else {
                    *(s16 *)(work + 0x45A) = 0;
                    *(u16 *)(work + 0x458) |= 2;
                }
            }
        }
    }
    if (**(u16 **)(work + 0) & 4) {
        *(s32 *)(work + 0x534) |= 0x80000;
        func_0043f9c8(work + 0x458, 0, 0x68);
    }
    func_0011e0c0(*(u8 **)(work + 0x4F8), *(u16 *)((u8 *)arg2 + 2), t17);
    func_0011c6e0(arg0, 0);
    func_0011cee0(arg0);
}



s32 func_0046a770(char *arg0);
extern char D_005E4E00[];
void func_0011e360(u8 *, s32);
// FUN_0011B6D0
s32 func_0011b6d0(u8 *arg0, s32 arg1)
{
    u8 *work;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;

    work = ((SdkTask *)arg0)->work;
    if (*(s32 *)(work + 0x52C) != arg1) {
        *(s32 *)(work + 0x52C) = arg1;
        switch (arg1) {
        case 0:
            t1 = *(s32 *)(work + 0x534) | 0x40;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x20;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x80;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x400;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x40000;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x200000;
            *(s32 *)(work + 0x534) = t6;
            break;
        case 1:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x80;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x400;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x40000;
            *(s32 *)(work + 0x534) = t6;
            t7 = t6 | 0x200000;
            *(s32 *)(work + 0x534) = t7;
            break;
        case 2:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x80;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x400;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x40000;
            *(s32 *)(work + 0x534) = t6;
            t7 = t6 | 0x200000;
            *(s32 *)(work + 0x534) = t7;
            break;
        case 3:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x80;
            *(s32 *)(work + 0x534) = t4;
            t5 = t4 | 0x100;
            *(s32 *)(work + 0x534) = t5;
            t6 = t5 | 0x200000;
            *(s32 *)(work + 0x534) = t6;
            t7 = func_0046a770(D_005E4E00);
            *(s32 *)(work + 0x2C8) = t7;
            if (t7 == 0) {
                func_0046d730(D_005E4868, 0xC02);
            }
            break;
        case 4:
            t1 = *(s32 *)(work + 0x534) | 0x10;
            *(s32 *)(work + 0x534) = t1;
            t2 = t1 | 0x40;
            *(s32 *)(work + 0x534) = t2;
            t3 = t2 | 0x20;
            *(s32 *)(work + 0x534) = t3;
            t4 = t3 | 0x200000;
            *(s32 *)(work + 0x534) = t4;
            break;
        default:
            func_0046d730(D_005E4868, 0xC0E);
            break;
        }
        func_0011e360(*(u8 **)(work + 0x4F8), 1);
    }
    return 0;
}



// FUN_0011B8F0
void func_0011b8f0(u8 *arg0, s32 arg1)
{
    u8 *work;
    u16 *ptr;
    s32 state;
    s32 i;

    work = ((SdkTask *)arg0)->work;
    ptr = *(u16 **)(work + 0);
    state = *(s32 *)(work + 0x52C);
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_00115940((u8 *)ptr, work + 0xC, 2);
        break;
    case 3:
    case 4:
        func_00115940((u8 *)ptr, work + 0xC, 1);
        break;
    default:
        func_0046d730(D_005E4868, 0xB91);
        break;
    }
    for (i = 0; i < 5; i++) {
        *(u8 *)(work + 0x18 + i) = *(u8 *)(arg1 + i);
    }
}



// FUN_0011BA00
s32 func_0011ba00(u8 *arg0)
{
    s32 flags = *(s32 *)(((SdkTask *)arg0)->work + 0x534);
    if ((flags & 2) || (flags & 4)) {
        return 1;
    }
    return 0;
}



// FUN_0011BA40
void func_0011ba40(u8 *arg0)
{
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 t7;
    s32 state;
    u16 *p;

    t1 = *(s32 *)(arg0 + 0x534) | 1;
    *(s32 *)(arg0 + 0x534) = t1;
    t2 = t1 | 2;
    *(s32 *)(arg0 + 0x534) = t2;
    t3 = t2 | 0x200000;
    *(s32 *)(arg0 + 0x534) = t3;
    t4 = t3 | 0x800000;
    *(s32 *)(arg0 + 0x534) = t4;
    t5 = t4 & ~4;
    *(s32 *)(arg0 + 0x534) = t5;
    t6 = t5 & ~0x4000;
    *(s32 *)(arg0 + 0x534) = t6;
    t7 = t6 & 0xFFBFFFFF;
    *(s32 *)(arg0 + 0x534) = t7;
    p = *(u16 **)(arg0 + 0);
    if (p != NULL && (*p & 4)) {
        *(s32 *)(arg0 + 0x534) |= 0x80000;
        func_0043f9c8(arg0 + 0x458, 0, 0x68);
    } else {
        *(s32 *)(arg0 + 0x534) &= 0xFFF7FFFF;
    }
    state = *(s32 *)(arg0 + 0x52C);
    switch (state) {
    case 0:
    case 1:
    case 2:
        func_0045af60(0, 1, 0, 3);
        return;
    default:
        func_0046d730(D_005E4868, 0xC8F);
        /* fallthrough */
    case 3:
    case 4:
        return;
    }
}



// FUN_0011BB90
void func_0011bb90(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (!(*(s32 *)(b + 0x534) & 2) && *(u8 *)(b + 0x505) != 0xFF) {
        f32 t;
        f32 u;
        Vec2f src;
        Vec2f dst;
        func_0011ba40(b);
        *(u16 *)(b + 0x508) = 0;
        *(u8 *)(b + 0x504) = *(u8 *)(b + 0x505);
        *(u8 *)(b + 0x506) = 0xFF;
        t = 131.0f + *(f32 *)(b + 0x4FC);
        src.x = t;
        u = -59.0f + *(f32 *)(b + 0x500);
        src.y = u;
        dst.x = 640.0f + t;
        dst.y = u;
        func_0011e2b0(*(u8 **)(b + 0x4F8), &dst, &src);
        func_0011e240(*(u8 **)(b + 0x4F8), 0);
        func_0011aaa0(b, 0);
    }
}



// FUN_0011BC70
void func_0011bc70(u8 *arg0)
{
    u8 *work;
    s32 flags;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 state;

    work = ((SdkTask *)arg0)->work;
    flags = *(s32 *)(work + 0x534);
    if (((flags & 1) != 0 && (flags & 4) == 0) || (flags & 0x400000) != 0) {
        t1 = *(s32 *)(((SdkTask *)arg0)->work + 0x534) | 4;
        *(s32 *)(work + 0x534) = t1;
        t2 = t1 & ~2;
        *(s32 *)(work + 0x534) = t2;
        t3 = t2 & ~0x800;
        *(s32 *)(work + 0x534) = t3;
        t4 = t3 & ~0x1000;
        *(s32 *)(work + 0x534) = t4;
        t5 = t4 & ~0x2000;
        *(s32 *)(work + 0x534) = t5;
        t6 = t5 & ~0x4000;
        *(s32 *)(work + 0x534) = t6;
        *(s8 *)(work + 0x88) = -1;
        *(s32 *)(work + 0x444) = 0xC3E10000;
        state = *(s32 *)(work + 0x52C);
        switch (state) {
        case 0:
            func_0045af60(0, 1, 0, 4);
            break;
        case 1:
        case 3:
        case 2:
        case 4:
            break;
        default:
            func_0046d730(D_005E4868, 0xCCC);
            break;
        }
        *(s16 *)(work + 0x508) = 0;
        *(u8 *)(work + 0x504) = *(u8 *)(work + 0x505);
        *(s8 *)(work + 0x506) = 0;
        func_0011aaa0(work, 1);
        *(s32 *)(work + 0x534) &= 0xFF7FFFFF;
    }
}



f32 func_0011de80(u8 *, Vec2f *);
void func_0011e370(u8 *);
/* measured: retail sinks the `lwc1 field, 0x4FC` load to AFTER the
   addiu/mtc1/cvt.s.w materialisation of (f32)0x303 in the then-branch
   (cvt -> $f1, load -> $f0); mwcc b210 always emits the field load first and
   swaps the two FP temps (cvt -> $f0, load -> $f1), nd 6, all the same six
   words. Tried: operand order both ways, cvt hoisted to a local, 0x303 as an
   int local — identical. Load-scheduling floor. */
// FUN_0011BDC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011bdc0);



/* measured: retail materialises (f32)0x303 (addiu/mtc1/cvt.s.w into $f1) BEFORE
   the lwc1 field load for sp20, and the (f32)(s32) round-trip casts m2c showed
   for sp24/sp28/sp2C are hallucinated (plain float adds in retail); mwcc b210
   emits the field load first and swaps the FP temps (nd 10+, obj over window).
   Same load-order floor as func_0011bdc0. The 0xFF byte store needs a u8-typed
   store or mwcc materialises -1. */
// FUN_0011BF10
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011bf10);



// FUN_0011C180
void func_0011c180(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 *src;
    s32 *dst;
    s32 temp;
    s32 n;
    u8 *work;

    work = ((SdkTask *)arg0)->work;
    if (!(*(s32 *)(work + 0x534) & 0x4000)) {
        func_0011aaa0(work, 2);
        *(f32 *)(work + 0x338) = (f32)0x28A;
        *(s32 *)(work + 0x33C) = 0;
        *(s32 *)(work + 0x2F0) = 0x42C80000;
        *(s32 *)(work + 0x2F4) = 0;
        *(u8 *)(work + 0x308) = 0;
        *(u8 *)(work + 0x32C) = 0;
        *(s32 *)(work + 0x410) = 0;
        *(s32 *)(work + 0x414) = 0;
        *(s32 *)(work + 0x3C8) = 0;
        *(s32 *)(work + 0x3CC) = 0;
        *(u8 *)(work + 0x3E0) = 0xFF;
        *(u8 *)(work + 0x404) = 0xFF;
        *(s16 *)(work + 0x516) = 0;
        *(s32 *)(work + 0x534) |= 0x4000;
    }
    src = (s32 *)(work + 0xC);
    dst = (s32 *)(work + 0x48);
    n = 0xF;
    do {
        temp = *src;
        src++;
        n--;
        *dst = temp;
        dst++;
    } while (n > 0);
    func_0011c6e0(arg0, 0);
    func_0011b480(arg0, arg1, arg2, arg3);
    func_0045af60(0, 2, 0, 5);
}



// FUN_0011C2C0
void func_0011c2c0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 *src;
    s32 *dst;
    s32 temp;
    s32 n;
    u8 *work;

    work = ((SdkTask *)arg0)->work;
    if (!(*(s32 *)(work + 0x534) & 0x4000)) {
        func_0011aaa0(work, 3);
        *(s32 *)(work + 0x338) = 0xC3480000;
        *(s32 *)(work + 0x33C) = 0;
        *(u8 *)(work + 0x350) = 0;
        *(s32 *)(work + 0x2F0) = 0xC2C80000;
        *(s32 *)(work + 0x2F4) = 0;
        *(u8 *)(work + 0x308) = 0;
        *(u8 *)(work + 0x32C) = 0;
        *(s32 *)(work + 0x410) = 0;
        *(s32 *)(work + 0x414) = 0;
        *(u8 *)(work + 0x428) = 0xFF;
        *(s32 *)(work + 0x3C8) = 0;
        *(s32 *)(work + 0x3CC) = 0;
        *(u8 *)(work + 0x3E0) = 0xFF;
        *(u8 *)(work + 0x404) = 0xFF;
        *(s16 *)(work + 0x516) = 0;
        *(s32 *)(work + 0x534) |= 0x4000;
    }
    src = (s32 *)(work + 0xC);
    dst = (s32 *)(work + 0x48);
    n = 0xF;
    do {
        temp = *src;
        src++;
        n--;
        *dst = temp;
        dst++;
    } while (n > 0);
    func_0011b480(arg0, arg1, arg2, arg3);
    func_0045af60(0, 2, 0, 5);
}



/* measured: retail hoists all four loop constants (1.0f, 0.0f, 0x4F000000,
   0x80000000) into $f3/$f4/$f1/$a1 BEFORE the initial branch to the loop test
   and keeps the 0x2E8 ratio in $f5; mwcc b210 rematerialises 0.0f inside the
   branch and shifts every FP temp register (nd 8+). Tried
   #pragma opt_loop_invariants on (hoists 2.0f instead, nd 20) — same
   preheader-hoist/FP-colouring floor as func_00117310. */
// FUN_0011C3E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c3e0);



// FUN_0011C610
u32 func_0011c610(u8 *arg0)
{
    return (*(s32 *)(((SdkTask *)arg0)->work + 0x534) & 0x800) != 0;
}



// FUN_0011C630
void func_0011c630(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = *(s32 *)(b + 0x534);
    if ((v & 0x20) != 0 && (v & 0x4000) == 0 && (v & 0x1000) == 0 && ((v & 0x800) == 0 || (v & 0x2000) != 0)) {
        *(f32 *)(b + 0x434) = *(f32 *)(b + 0x444);
        *(f32 *)(b + 0x438) = *(f32 *)(b + 0x448);
        *(s32 *)(b + 0x43C) = 0;
        *(u16 *)(b + 0x514) = 0;
        *(u8 *)(b + 0x88) = 0;
        *(s32 *)(b + 0x534) |= 0x1000;
        *(s32 *)(b + 0x534) |= 0x800;
        *(s32 *)(b + 0x534) &= ~0x2000;
        func_0045af60(0, 1, 0, 3);
    }
}



// FUN_0011C6E0
void func_0011c6e0(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = *(s32 *)(b + 0x534);
    if ((v & 0x20) != 0 && (v & 0x800) != 0 && (v & 0x2000) == 0) {
        *(f32 *)(b + 0x434) = *(f32 *)(b + 0x444);
        *(f32 *)(b + 0x438) = *(f32 *)(b + 0x448);
        *(s32 *)(b + 0x43C) = 0xC3E10000;
        *(u16 *)(b + 0x514) = 0;
        *(s32 *)(b + 0x534) |= 0x2000;
        *(s32 *)(b + 0x534) &= ~0x1000;
        if (arg1 != 0) {
            func_0045af60(0, 1, 0, 4);
        }
    }
}



/* measured: retail interleaves the f2 load (lwc1 0x450) between the lh 0x514
   and its mtc1/cvt.s.w, and colours the 0x44C byte into $a1 with the abs-else's
   srl/or into $t0; mwcc b210 emits the cvt before the f2 load and colours the
   byte into $v1 (nd 15, all instruction-order and register-name rows). Tried:
   declaration orders, s16 temp, u8/s8 byte typing, if/else forms — identical.
   Scheduling/colouring floor. */
// FUN_0011C780
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c780);



/* measured: identical residuals to func_0011c780 (same body shape): retail
   interleaves the f2 load between lh 0x514 and its cvt, and colours the 0x44C
   byte into $a1 with the abs-else's srl/or into $t0; mwcc b210 emits the cvt
   before the f2 load and colours the byte $v1 (nd 15, instruction-order and
   register-name rows only). Tried declaration orders and load orders —
   identical. Same scheduling/colouring floor as func_0011c780. */
// FUN_0011C930
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c930);



/* measured: retail booleanizes the first guard (andi $v1, 0x800 then
   sltu $v1, $zero, $v1 before beqz) and lays the second return out as a
   branch-to-branch node with bne-to-body; mwcc b210 emits plain
   andi+beqz and an inverted beq-to-return. Tried !(x&0x800)||, a saved
   bool local, two separate if-returns, nested if, switch-case -1 and
   && forms (5 spellings, probe batch), all nd 25-26 — the single sltu
   controls every other word via the shift. Condition-booleanization
   floor. */
// FUN_0011CAF0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011caf0);



// FUN_0011CB70
s32 func_0011cb70(u8 *arg0, u8 *arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0xE21);
    }
    if (func_0010cc20(*(s32 *)b, arg1) != 0) {
        func_00115420(arg1, b + 0x8C);
        return 1;
    }
    return 0;
}



// FUN_0011CC00
s32 func_0011cc00(u8 *arg0, s16 arg1, u8 *arg2)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)b == 0) {
        func_0046d730(D_005E4868, 0xE45);
    }
    if (func_0010cd70(*(s32 *)b, arg1, arg2) != -1) {
        func_00115500(arg1, arg2, b + 0x8C);
        return 1;
    }
    return 0;
}



// FUN_0011CCB0
s32 func_0011ccb0(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x534);
    if (v & 0x2000) {
        return 0;
    }
    if ((v & 0x100000) != 0 && *(s8 *)(arg0 + 0x88) == 8) {
        return *(u16 *)(arg0 + 0x4F4);
    }
    return func_001152b0(arg0 + 0x84);
}



// FUN_0011CD20
void func_0011cd20(u8 *arg0)
{
    f32 f1 = (f32)*(s16 *)(arg0 + 0x518);
    if (f1 > 25.0f) {
        *(s32 *)(arg0 + 0x534) &= ~0x8000;
    } else if (f1 > 25.0f) {
        f1 = 25.0f;
    }
    *(f32 *)(arg0 + 0x51C) = func_0044b7b0(D_007613EC * f1 / 25.0f);
}



// FUN_0011CDD0
void func_0011cdd0(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0x534) |= 0x100000;
    func_0043f9c8(b + 0x4F0, 0, 6);
    *(u16 *)(b + 0x4F4) = arg1;
}



// FUN_0011CE30
void func_0011ce30(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(u16 *)(b + 0x4F2) = 0;
    *(u16 *)(b + 0x4F0) |= 2;
}



// FUN_0011CE50
void func_0011ce50(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x534);
    if ((v & 0x10000) != 0) {
        if (*(s16 *)(arg0 + 0x520) == 10) {
            func_0045aeb0(2, D_005E4E20);
        }
    } else if ((v & 0x20000) != 0) {
        if (*(s16 *)(arg0 + 0x520) >= 50) {
            *(s32 *)(arg0 + 0x534) &= ~0x200;
        }
    }
}



// FUN_0011CEE0
void func_0011cee0(u8 *arg0)
{
    u8 *work;
    s32 flags;
    s32 state;
    u16 t17;

    work = ((SdkTask *)arg0)->work;
    flags = *(s32 *)(work + 0x534);
    if (flags & 0x40000) {
        state = *(s32 *)(work + 0x52C);
        switch (state) {
        case 0:
            if (*(u16 *)(work + 0xC) == 1) {
                if ((func_0010b6f0(1, state) & 0xFFFF) == 1) {
                    *(s32 *)(work + 0x528) = 0xD;
                    return;
                }
                *(s32 *)(work + 0x528) = 9;
                return;
            }
            *(s32 *)(work + 0x528) = -1;
            return;
        case 1:
            if ((func_0010b6f0(1, state) & 0xFFFF) == 1) {
                *(s32 *)(work + 0x528) = 0xA;
                return;
            }
            t17 = *(u16 *)(*(u8 **)(work + 0) + 2);
            if (t17 == (func_00109360(1) & 0xFFFF)) {
                *(s32 *)(work + 0x528) = 0xB;
                return;
            }
            *(s32 *)(work + 0x528) = 9;
            return;
        case 2:
            *(s32 *)(work + 0x528) = 0xC;
            return;
        case 3:
        case 4:
            if ((func_0010b6f0(flags, state) & 0xFFFF) == 1) {
                *(s32 *)(work + 0x528) = 0xA;
                return;
            }
            *(s32 *)(work + 0x528) = 9;
            return;
        default:
            func_0046d730(D_005E4868, 0xF87);
            break;
        }
    }
}



// FUN_0011D080
void func_0011d080(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0x534) |= arg1;
}



// FUN_0011D0A0
void func_0011d0a0(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0x534) &= ~arg1;
}



// FUN_0011D0C0
u8 func_0011d0c0(u8 *arg0)
{
    return *(u8 *)(((SdkTask *)arg0)->work + 0x505);
}



// FUN_0011D0D0
void func_0011d0d0(u8 *arg0)
{
    func_0011e240(*(s32 *)(((SdkTask *)arg0)->work + 0x4F8));
}

// FUN_0011D100
void func_0011d100(u8 *arg0, f32 *arg1)
{
    u8 *temp_3;

    temp_3 = ((SdkTask *)arg0)->work;
    if (arg1 == NULL) {
        *(f32 *)(temp_3 + 0x4FC) = 0.0f;
        *(f32 *)(temp_3 + 0x500) = 0.0f;
        return;
    }
    *(f32 *)(temp_3 + 0x4FC) = arg1[0];
    *(f32 *)(temp_3 + 0x500) = arg1[1];
}





// FUN_0011D140
void func_0011d140(u8 *arg0)
{
    func_0011e230(*(s32 *)(((SdkTask *)arg0)->work + 0x4F8));
}

// FUN_0011D170
/* Kept as a raw deref on purpose: through SdkTask::work mwcc hoists arg0 + 0x38
   into a saved register and reuses it, where retail re-issues lw 0x38 for each
   of the two reads. The typed form is not codegen-neutral here. */
void func_0011d170(u8 *arg0, s32 arg1, s32 arg2)
{
    func_0011e230(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
    func_0011e3c0(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8), arg2);
}





// FUN_0011D1D0
void func_0011d1d0(u8 *arg0, f32 arg1)
{
    *(f32 *)(((SdkTask *)arg0)->work + 0x53C) = arg1;
}



// FUN_0011D1E0
s32 func_0011d1e0(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 0x4F8);
}



s32 func_00452380(void *arg0);
s32 func_004553c0(s32 arg0);
s32 func_00454a60(u8 *arg0, s32 arg1);
s32 func_004667d0(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern char D_005E4E60[];
extern char D_005E4E90[];
extern char iGpffff9c18;
// FUN_0011D1F0
s32 func_0011d1f0(u8 *arg0)
{
    u8 *work;
    s32 state;
    s32 temp_2;
    s32 sp4C;

    work = ((SdkTask *)arg0)->work;
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        if (*(s32 *)(work + 4) != 0) {
            if (func_00452380(D_005E4E40) != 0) {
                func_00440b68(D_005E4E60);
            } else {
                func_00442088(work + 0x54, D_005E4E90, *(s32 *)(work + 4));
                func_00440b68(&iGpffff9c18, D_005E4868, 0x1046);
                temp_2 = func_00454a60(work + 0x54, 0);
                *(s32 *)(work + 0x4C) = temp_2;
                if (temp_2 == 0) {
                    func_0046d730(D_005E4868, 0x1047);
                }
                func_0011e240(arg0, NULL);
                *(s32 *)(work + 0) = 1;
            }
        } else {
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 1:
        if (func_004553c0(*(s32 *)(work + 0x4C)) != 0) {
            *(s32 *)(work + 0x48) = func_004667d0(0, (const char *)(work + 0x54), 0, 0, 0, 0, 0, 0, 0, 0);
            *(s32 *)(work + 0) = 2;
        }
        break;
    case 2:
        *(s32 *)(work + 0x50) = func_004669d0(*(s32 *)(work + 0x48), &sp4C, 0);
        if (sp4C != 0) {
            *(s32 *)(work + 0x48) = 0;
            func_00454bd0(*(s32 *)(work + 0x4C));
            *(s32 *)(work + 0x4C) = 0;
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 3:
        break;
    }
    return 0;
}



// FUN_0011D3C0
void func_0011d3c0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)(b + 0x48) != 0) {
        func_0011dfc0(*(s32 *)(b + 0x48), *(s32 *)(b + 0x4C), D_005E4E40);
        *(s32 *)(b + 0x48) = 0;
        *(s32 *)(b + 0x4C) = 0;
        *(s32 *)(b + 0x50) = 0;
    } else {
        if (*(s32 *)(b + 0x4C) != 0) {
            func_00454bd0(*(s32 *)(b + 0x4C));
            *(s32 *)(b + 0x4C) = 0;
        }
        if (*(s32 *)(b + 0x50) != 0) {
            func_003ef3a0(*(s32 *)(b + 0x50));
            *(s32 *)(b + 0x50) = 0;
        }
    }
    jtbl_008873EC[0](b);
}



// FUN_0011D460
u8 *func_0011d460(s32 arg0, s32 arg1, f32 fparg0, s32 arg2, s32 arg3)
{
    Vec2f v;
    u8 *r;
    u8 *w;

    func_0044ea90(D_005E4868, 0x1090);
    w = D_008873F4[0](1, 0x154, 0x40000);
    if (w == NULL) {
        return NULL;
    }
    r = (u8 *)func_00451fc0(arg0, D_005E4EB0, arg1, 0, 0, func_0011d1f0, func_0011d3c0, w);
    if (r == NULL) {
        return NULL;
    }
    *(s32 *)(w + 4) = arg2;
    *(s32 *)(w + 8) = arg3;
    *(s32 *)(w + 0xC) = (arg3 & 0xFF) | ~0x7EFF;
    *(f32 *)(w + 0x18) = fparg0;
    *(s32 *)&v.x = 0x43030000;
    *(s32 *)&v.y = 0xC26C0000;
    func_0011e240(r, (u8 *)&v);
    *(s32 *)&v.x = 0xC1880000;
    *(s32 *)&v.y = 0x41500000;
    func_0011e390(r, v);
    return r;
}



u8 *func_00457120();
extern f32 D_008872F8;
extern void (*D_00887310[])(s32, void *, s32);
/* measured: fully decompiled, best nd 593 (obj 2596B / window 1696B — the
   object is OVER window because mwcc emits extra instructions, not missing
   ones). The signature (f32, s32, s32, f32, f32, s32, s32, s32) is CORRECT
   (matched caller func_0011dc50 + callee prologue agree). Everything structural
   reproduced: the shifted-masked color conversions ((arg0 >> N) & 0xFF) KEEP
   their bltz sign-checks (complex shift chains defeat the range analysis —
   unlike func_00119210's simple-mask case), the spA0 16-f32 fill, the 4-block
   loop writes into spE0/sp1E0, and the D_00887300/D_00887310 call shape via
   table-pointer locals (`void (**tbl)(u32,u32) = D_00887300; tbl[0](...)` —
   reproduces retail's base-in-$s0 + per-call lw; direct calls rematerialise).
   Residuals: (1) the neg-path `2.0f * (f32)(((u32)x >> 1) | bit)` emits an
   EXTRA bltz+neg-template for the or-result (retail converts it directly) —
   16 conversions x 2; (2) color saved-reg allocation: retail assigns the mask
   registers descending $s5(temp_21)..$s1(temp_17), mwcc puts temp_18 in $s5
   (declaration orders tried); (3) loop FP temp choices ($f1/$f2 vs $f0).
   Declarations kept: D_008872F8 (GPREL scalar), D_00887310, func_00457120. */
// FUN_0011D5B0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011d5b0);



// FUN_0011DC50
void func_0011dc50(u8 *arg0)
{
    u8 *work;
    f32 f20;
    f32 t;
    f32 d;
    s32 a;

    work = ((SdkTask *)arg0)->work;
    if (func_0011e3e0(arg0) != 0 && *(s32 *)(work + 4) != 0) {
        t = (f32)*(s32 *)(work + 0x10);
        if (t < 10.0f) {
            *(s32 *)(work + 0x10) += 1;
            f20 = *(f32 *)(work + 0x20);
            t = func_0044b7b0(D_007613EC * (f32)*(s32 *)(work + 0x10) / 10.0f);
            d = *(f32 *)(work + 0x30) - f20;
            *(f32 *)(work + 0x28) = f20 + d * t;
        } else {
            *(f32 *)(work + 0x28) = *(f32 *)(work + 0x30);
        }
        a = *(s32 *)(work + 8);
        func_0011d5b0(*(f32 *)(work + 0x18), a, a,
                      *(f32 *)(work + 0x28), *(f32 *)(work + 0x2C),
                      0x200, 0x200, *(s32 *)(work + 0x50));
    }
}



/* measured: everything matches except the work-pointer base register — retail
   keeps `lw $a1, 0x38($a0)` in $a1 (first free arg reg after $a0) for all 12
   loads/stores; mwcc b210 always colours it $t0 (nd 24, every row is the same
   instruction with $t0 vs $a1). Tried: declaration order both ways, SdkTask
   typed form vs raw deref (per assignment note), s32 vs u8 byte locals —
   identical. Register-colouring floor. */
// FUN_0011DD50
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011dd50);



// FUN_0011DE40
void func_0011de40(u8 *arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    s32 v = arg1 & 0xFF;
    *(s32 *)(b + 8) = (*(s32 *)(b + 8) & ~0xFF) | v;
    *(s32 *)(b + 0xC) = (*(s32 *)(b + 0xC) & ~0xFF) | v;
}

// FUN_0011DE80
f32 func_0011de80(u8 *arg0, Vec2f *arg1)
{
    u8 *temp_2;

    temp_2 = ((SdkTask *)arg0)->work;
    *arg1 = *(Vec2f *)(temp_2 + 0x28);
    return (f32)(*(s32 *)(temp_2 + 0x10)) / 10.0f;
}





// FUN_0011DEC0
s32 func_0011dec0(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 8);
}



/* measured: retail materialises the D_005E4ED0 address (lui+addiu $a0) BEFORE the
   addiu $a1, $v0, 0x10 at the func_00440b68 call; mwcc b210 always emits the
   computed operand first and the constant global address last (nd 3, the three
   swapped words). Tried: hoisting arg1 to a local, hoisting the address to a
   char* local, inverting the if/else (nd 5) — constant-vs-computed argument
   materialisation order floor per operand-order skill. */
// FUN_0011DED0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ded0);

// FUN_0011DF90
void func_0011df90(u8 *arg0)
{
    jtbl_008873EC[0](((SdkTask *)arg0)->work);
}





/* measured: retail materialises the D_005E4F10 address (lui+addiu $a0) BEFORE the
   addiu $a1, $s0, 0x10 at the func_00440b68 call; mwcc b210 always emits the
   computed operand first and the constant global address last (nd 5, three
   swapped words plus their reloc pair). Tried: hoisting the address to a char*
   local (nd 58), hoisting arg1+0x10 to a local (nd 61) — constant-vs-computed
   argument materialisation order floor, same family as func_0011ded0. */
// FUN_0011DFC0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011dfc0);



void func_0011ded0(u8 *arg0);
// FUN_0011E0C0
void func_0011e0c0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *w = ((SdkTask *)arg0)->work;
    s32 p48;
    s32 p4c;
    u8 *r;

    if (*(s32 *)(w + 4) != arg1 || (*(s32 *)(w + 8) & ~0xFF) != (arg2 & ~0xFF)) {
        p48 = *(s32 *)(w + 0x48);
        if (p48 != 0) {
            p4c = *(s32 *)(w + 0x4C);
            func_0044ea90(D_005E4868, 0x11B2);
            r = D_008873F4[0](1, 8, 0x40000);
            if (r != 0 && func_00451de0(D_005E4E40, 0xF, 0, 0, func_0011ded0, func_0011df90, r) != 0) {
                if (p4c != 0) {
                    func_00440b68((s32)D_005E4F10, (s32)(p4c + 0x10));
                }
                *(s32 *)r = p48;
                *(s32 *)(r + 4) = p4c;
            }
            *(s32 *)(w + 0x48) = 0;
            *(s32 *)(w + 0x4C) = 0;
            *(s32 *)(w + 0x50) = 0;
        } else {
            p4c = *(s32 *)(w + 0x4C);
            if (p4c != 0) {
                func_00454bd0(p4c);
                *(s32 *)(w + 0x4C) = 0;
            }
            p4c = *(s32 *)(w + 0x50);
            if (p4c != 0) {
                func_003ef3a0(p4c);
                *(s32 *)(w + 0x50) = 0;
            }
        }
        *(s32 *)(w + 8) = arg2;
        *(s32 *)(w + 4) = arg1;
        *(s32 *)(w + 0) = 0;
    }
}
// FUN_0011E230
void func_0011e230(u8 *arg0, s32 arg1)
{
    *(s32 *)(((SdkTask *)arg0)->work + 8) = arg1;
}



// FUN_0011E240
void func_0011e240(u8 *arg0, u8 *arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    f32 v0;
    f32 v1;
    if (arg1 != NULL) {
        *(f32 *)(b + 0x30) = *(f32 *)(arg1 + 0);
        *(f32 *)(b + 0x34) = *(f32 *)(arg1 + 4);
    *(f32 *)(b + 0x20) = 640.0f + *(f32 *)(b + 0x30);
    *(f32 *)(b + 0x24) = *(f32 *)(b + 0x34);
    }
    v0 = *(f32 *)(b + 0x20);
    *(f32 *)(b + 0x28) = v0;
    *(f32 *)(b + 0x40) = v0;
    v1 = *(f32 *)(b + 0x24);
    *(f32 *)(b + 0x2C) = v1;
    *(f32 *)(b + 0x44) = v1;
    *(f32 *)(b + 0x1C) = 15.0f;
    *(s32 *)(b + 0x10) = 0;
}



// FUN_0011E2B0
void func_0011e2b0(u8 *arg0, Vec2f *arg1, Vec2f *arg2)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (arg1 == NULL) {
        func_0046d730(D_005E4868, 0x120A);
    }
    if (arg2 == NULL) {
        func_0046d730(D_005E4868, 0x120B);
    }
    *(Vec2f *)(b + 0x20) = *arg1;
    *(Vec2f *)(b + 0x28) = *arg1;
    *(Vec2f *)(b + 0x30) = *arg2;
    *(s32 *)(b + 0x10) = 0;
}



// FUN_0011E360
void func_0011e360(u8 *arg0, s32 arg1)
{
    *(s32 *)(((SdkTask *)arg0)->work + 0x14) = arg1;
}



// FUN_0011E370
void func_0011e370(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(f32 *)(b + 0x40) = *(f32 *)(b + 0x28);
    *(f32 *)(b + 0x44) = *(f32 *)(b + 0x2C);
}



// FUN_0011E390
void func_0011e390(u8 *arg0, Vec2f arg1)
{
    f32 *b = *(f32 **)(arg0 + 0x38);
    b[0xE] = arg1.x;
    b[0xF] = arg1.y;
}



// FUN_0011E3C0
void func_0011e3c0(s32 arg0, s32 arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    *(s32 *)(b + 0xC) = (arg1 & 0xFFFFFF00) | *(u8 *)(b + 8);
}



// FUN_0011E3E0
u32 func_0011e3e0(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 0) == 3;
}



// FUN_0011E400
void func_0011e400(u8 *arg0, u8 *arg1)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (arg1 == NULL) {
        func_0046d730(D_005E4868, 0x124F);
    }
    *(Vec2f *)arg1 = *(Vec2f *)(b + 0x28);
}



// FUN_0011E460
s32 func_0011e460(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)b != 3) {
        return 0;
    }
    return *(s32 *)(b + 0x50);
}



s32 func_003b7060();
u8 *func_001094d0(u16 *arg0);
extern u8 *iGpffffb3ec;
/* measured: retail keeps the `bltz` sign-check and the full else-branch
   (srl/andi/or/mtc1/cvt/add.s x2) of an abs-style conditional on
   `func_003b7060() & 0x1000` (and & 0xFFF); mwcc b210's range analysis proves
   the masked value non-negative and eliminates both branches entirely
   (object 100B under window, nd > 300 with the whole body shifted). Tried the
   conditional in every spelling (>=0/<0, if/else, ternary, s32/u32 locals,
   cast-to-s32 compare, macro form) — all eliminated. Also the ptr in $s0
   colouring differed. Range-analysis elimination floor. */
// FUN_0011E490
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e490);



// FUN_0011E740
void func_0011e740(u8 *arg0)
{
    u8 *base;
    u8 buf[0x80];
    s32 idx;
    s32 t3;

    base = *(u8 **)(arg0 + 0x20);
    while ((idx = *(s32 *)(arg0 + 0xC)) < 5 && *(u8 *)(base + idx + 0x82) == 0) {
        *(s32 *)(arg0 + 0xC) += 1;
    }
    if (idx < 5) {
        func_00442830(buf, D_005E4850[idx]);
        func_002bbd20(0, buf);
        func_00442088(buf, &iGpffff9c20, base[*(s32 *)(arg0 + 0xC) + 0x82]);
        func_002bbd20(1, buf);
        func_002bad10(*(s32 *)(arg0 + 0x34));
        *(s16 *)(arg0 + 2) = 0;
        *(s32 *)(arg0 + 0x14) = 3;
        return;
    }
    t3 = *(s32 *)(arg0 + 0x10);
    if (t3 < 0x20 && ((u16 *)(base + 2))[t3] != 0) {
        *(s16 *)(arg0 + 2) = 0;
        *(s32 *)(arg0 + 0x14) = 4;
        return;
    }
    if (func_0011e490(arg0) != 0) {
        func_002bbd20(1, func_00243840(*(u16 *)(arg0 + 6)));
        func_002bad10(*(s32 *)(arg0 + 0x4C));
        func_002baf40(*(s32 *)(arg0 + 0x2C));
        func_002bb050(1);
        func_002bbf60();
        *(s32 *)(arg0 + 0x14) = 8;
        return;
    }
    *(s32 *)(arg0 + 0x14) = 0xC;
}



// FUN_0011E8E0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e8e0);



// FUN_0011F3C0
void func_0011f3c0(u8 *arg0)
{
    u8 *b = ((SdkTask *)arg0)->work;
    if (*(s32 *)(b + 0x18) != 0) {
        func_0011fd10(*(s32 *)(b + 0x18));
        *(s32 *)(b + 0x18) = 0;
    }
    jtbl_008873EC[0](b);
}



extern char D_005E4F30[];
void func_0011e8e0(u8 *);
void func_0011f3c0(u8 *);
// FUN_0011F410
u8 *func_0011f410(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    u8 *w;
    u8 *r;
    s32 i;

    func_0044ea90(D_005E4868, 0x1464);
    w = D_008873F4[0](1, 0x58, 0x40000);
    if (w == NULL) {
        func_0046d730(D_005E4868, 0x1465);
    }
    r = (u8 *)func_00451fc0(arg0, D_005E4F30, 0xF, 0, 0, func_0011e8e0, func_0011f3c0, w);
    if (r == NULL) {
        func_0046d730(D_005E4868, 0x146F);
    }
    *(s32 *)(w + 0x1C) = arg1;
    *(s32 *)(w + 0x20) = arg2;
    *(s32 *)(w + 0x24) = arg3;
    *(s32 *)(w + 0x28) = arg4;
    for (i = 0; i < 0xB; i++) {
        *(s32 *)(w + 0x2C + i * 4) = *(s32 *)(arg5 + i * 4);
    }
    return r;
}



// FUN_0011F560
u32 func_0011f560(u8 *arg0)
{
    return *(s32 *)(((SdkTask *)arg0)->work + 0x14) == 0xE;
}



// FUN_0011F580
void func_0011f580(void)
{
    func_00452080();
}



u16 func_00115750();
void func_002baac0(s32 arg0);
void func_002bb7c0();
void func_002bb4e0();
s32 func_002bb600(void);
void func_002bb1e0(s32 arg0);
s32 func_002bb140(void);
s32 func_0011ccb0(u8 *arg0);
void func_00115760(u8 *arg0);
s32 func_001092f0(u8 *arg0);
s16 func_00115380();
extern u16 D_008C024E;
extern u16 D_008C024C;
void func_0011c630(u8 *arg0);
/* measured: retail keeps the derived work->0xC->0x38 base pointer cached in $a2
   (not saved, survives calls — mwcc's reloadable-load caching in the arg
   registers) and saves only t18 in $s2; mwcc b210 colours this pointer into a
   saved register $s2 in this function, cascading the whole body (nd ~60, obj
   16B over window). Tried declaration orders and dropping the phantom
   args/hallucinated 3-arg calls m2c invented from leftover registers
   (func_002bb7c0/00115380/00115020/002bb4e0 are 1- or 2-arg, and the switch
   needs the empty case 8 for sltiu 9) — the colouring itself is the floor. */
// FUN_0011F5A0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011f5a0);



// FUN_0011FB90
void func_0011fb90(u8 *arg0)
{
    jtbl_008873EC[0](((SdkTask *)arg0)->work);
}



// FUN_0011FBC0
u8 *func_0011fbc0(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3)
{
    u8 *w;
    u8 *r;
    s32 i;

    func_0044ea90(D_005E4868, 0x1551);
    w = D_008873F4[0](1, 0x44, 0x40000);
    if (w == NULL) {
        func_0046d730(D_005E4868, 0x1552);
    }
    r = (u8 *)func_00451fc0(arg0, D_005E4F50, 0xF, 0, 0, func_0011f5a0, func_0011fb90, w);
    if (r == NULL) {
        func_0046d730(D_005E4868, 0x155C);
    }
    *(u8 **)(w + 0xC) = arg1;
    *(s32 *)(w + 0x14) = arg2;
    for (i = 0; i < 0xB; i++) {
        *(s32 *)(w + 0x18 + i * 4) = *(s32 *)(arg3 + i * 4);
    }
    return r;
}
