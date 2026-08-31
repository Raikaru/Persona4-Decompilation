/* Consolidated Persona 4 source units. */
/* Original translation unit shdPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdktask.h"
#include "include_asm.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;
typedef unsigned int ShdByte __attribute__((mode(QI)));

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
void func_00115cb0(Vec2f, f32, s32, s16 *);
void func_00115e90(Vec2f, s32, s16 *, f32);
extern char iGpffff9c0c;
extern char iGpffff9c08;
void func_00275020(f32, f32, f32, s32, s32, s32, u8 *, s32, s32);
void *func_00109220(u16 arg0);
void func_00116190(s64, f32, s32, u8 *, s32 *);
void func_00116610(s64, f32, s32, u8 *, s32 *);
void func_001162f0(s64, f32, s32, u8 *, s32 *);
void func_001163e0(s64, f32, s32, u8 *, s32 *);
void func_00116820(s64, f32, s32, u8 *, s32 *);
typedef struct {
    s32 lo;
    s32 hi;
} I64;
void func_00116d40(I64, s32, u8, u8, s16, s32, f32);
void func_0045d6e0(void *, void *, s32, f32);
void func_0034c270(Vec2f, u8, s32, f32);
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
void func_00364680(f32, s32, f32, f32, f32, f32, f32, f32, s32, s32, s32);
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


void func_00115dc0(Vec2f, f32, s32, s16 *);

// FUN_00115C40
void func_00115c40(Vec2f arg0, s32 arg1, s16 *arg2, f32 farg3)
{
    switch (*arg2) {
    case 0:
        func_00115dc0(arg0, farg3, arg1, arg2);
        break;
    case 1:
        func_00115e90(arg0, arg1, arg2, farg3);
        break;
    case 2:
        func_00115cb0(arg0, farg3, arg1, arg2);
        break;
    }
}



/* measured: the 15cb0/15dc0 fp-colour family shares the Vec2f, six-GP/three-float
   renderer-call shape. The exact 15cb0 source uses the interleaved
   `(Vec2f,f32,s32,s16*)` formal order and the local interleaved
   `func_00275020(f32,f32,f32,s32,s32,s32,u8*,s32,s32)` declaration, so retail's
   f14 move precedes the six GP moves. MATCH, object 260B / window 272B; the
   remaining 12-byte tail is zero padding accepted by the verifier.
   The prior high-nd probes remain archived in `build/` for family history. */
// FUN_00115CB0
void func_00115cb0(Vec2f arg0, f32 farg3, s32 arg1, s16 *arg2)
{
    s32 var_16;
    s32 temp_2;
    s32 color;
    u8 sp60[0x100];

    color = -0x100;
    color |= (u32)((arg1 & 0xFF) * 0xFF) / 255U;
    temp_2 = (s32)func_00109220((u16)arg2[5]);
    switch (arg2[1]) {
    case 0:
        var_16 = 6;
        func_00442088(&sp60[0], &iGpffff9c08, temp_2);
        break;
    case 1:
        var_16 = 7;
        func_00442088(&sp60[0], &iGpffff9c08, temp_2);
        break;
    }
    func_00275020((f32)(s32)arg0.x, (f32)(s32)arg0.y, farg3, color, var_16, 1, &sp60[0], 0, -1);
}






void *func_00109220(u16 arg0);
/* measured: func_00115dc0 closes the 208B fp-colour member. Its final
   renderer declaration is interleaved as
   `func_00274ed0(f32,f32,f32,s32,s32,s32,void*,s32,s32)`, preserving the
   six GP register assignments while making the f14 move precede them. Keep
   `scale = fparg0` before the colour expression; this source shape matches
   the helper call, mode switch, and final six-GP/three-float setup exactly.
   MATCH, object 208B / window 208B. */
void func_00274ed0(f32, f32, f32, s32, s32, s32, void *, s32, s32);

// FUN_00115DC0
void func_00115dc0(Vec2f arg0, f32 fparg0, s32 arg1, s16 *arg2)
{
    s32 color;
    s32 var_16;
    s16 mode;
    s32 temp_2;
    f32 scale;

    scale = fparg0;
    color = -0x100;
    color |= (u32)((arg1 & 0xFF) * 0xFF) / 255U;
    mode = arg2[1];
    switch (mode) {
    case 0:
        var_16 = 0;
        break;
    case 1:
        var_16 = 7;
        break;
    }
    temp_2 = (s32)func_00109220(*(u16 *)(arg2 + 5));
    func_00274ed0((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, var_16, 1, (void *)temp_2, 0, 0);
}




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
/* measured: recipe B re-test OVERTURNED part of the old note — best nd 119
   (was 168). A u32 *base = (u32 *)D_00887300 local DOES hoist: retail's
   lui/addiu of the table base into $s0 with per-call lw $v0, ($s0) is
   reproduced (the old `void (**tbl)` spelling folded; the DATA-pointer type
   is the lever). FP saved regs also now match (y->$f20 via lwc1 0x5C,
   fparg0->$f21 via mov.s). Remaining, all measured: (1) the 8 table calls
   are D_00887300[0](N,M) — retail always loads the pointer at SLOT 0 (lw
   $v0, ($s0)) and passes the index as arg0 (m2c's `D_00887300(6, 0)` direct
   call shape); I used base[6] giving lw 0x18($s0) — write base[0] each
   call (~8 words, unmeasured but mechanical); (2) prologue save order:
   retail emits mov.s $f21 BEFORE the GP moves and materialises the base
   lui/addiu AFTER the 4th func_0046a770 call (assign base = ... after the
   sp60[0..3] stores); mwcc puts the moves first and hoists the base into
   the prologue (~6 words); (3) the sp78/sp7C pair must be ONE 8-byte
   object — separate f32 locals get slot-coalesced at 0x7C and the s64 read
   becomes ldr/ldl with the sp7C store dead-eliminated (f32/s64 TBAA); an
   f32 sp78[2] array read as *(s64 *)sp78 kept both stores. Layout 0x58
   arg0 home / 0x60 sp60[4] / 0x78 pair matches retail with declarations
   [base, y, sp78[2], sp60[4]]. Frame 0x80, all stores reproduce. */
/* measured: the unguarded nd 582 candidate (obj 796B / window 768B) was
   archived verbatim in build/WBShdPersona_func_00115e90_archive.txt and
   reverted to bare INCLUDE_ASM because it is oversized and above the
   nd-25 guarded-park threshold. */
// FUN_00115E90
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00115e90);



u8 *func_0010d6d0(s16 arg0);

/* measured: declaration-order lever assigns the input float to $f20 and
   delayed high-coordinate assignment keeps retail's $f21 load at the call
   site. Exact MATCH: object 344B against the 352B retail window. */
// FUN_00116190
void func_00116190(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    f32 high;
    f32 x;
    f32 y;
    s32 alpha;
    s32 color;
    s32 temp_18;

    alpha = arg1 & 0xFF;
    color = (u32)((alpha * 0xFF) / 255U);
    if (*(u16 *)arg2 != 0) {
        temp_18 = arg3[1];
        if (temp_18 == 0) {
            func_0046d730(D_005E4868, 0x171);
        }
        high = *((f32 *)&arg0 + 1);
        func_0046d4c0(0, temp_18, 0x59, 207.0f + *(f32 *)&arg0, high, (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
        x = (f32)(s32)(114.0f + *(f32 *)&arg0);
        y = (f32)(s32)(2.0f + high);
        func_00274ed0(x, y, fparg0, color | -0x100, 8, 1, func_0010d6d0(*(s16 *)arg2), 8, 0);
    }
}



// FUN_001162F0
void func_001162f0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    s32 t17;
    s32 c;
    u8 m;
    f32 hi;

    c = arg1;
    t17 = *arg3;
    if (t17 == 0) {
        func_0046d730(D_005E4868, 0x197);
    }
    m = c & 0xFF;
    c = 0xFF - m;
    hi = *((f32 *)&arg0 + 1);
    func_0046d4c0(0, t17, 0x47, *(f32 *)&arg0, hi, c, 0x2D, 0x2D, 0x2D, fparg0, 0);
    func_0046d4c0(0, t17, 0x41, 126.0f + *(f32 *)&arg0, hi, c, 0x2D, 0x2D, 0x2D, fparg0, 0);
}



s32 func_00109280();
f32 func_0046b1f0(s32, s32);
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
   [andi, addiu, subu] order. The discarded nd-6 spelling used a stale
   prototype and was not recovered. */
/* Measured ABI split for the coupled caller/callee declarations:
   func_001163e0 needs its block-scope `(s64, f32, s32, u8, s32)`
   declaration to preserve its exact argument materialisation, while the
   callee body is exact with `(s64, f32, s32, u32, u32)`. */
/* measured: corrected-prototype reconstruction is now exact after applying
   the float-second family declaration and the renderer's `(int,int,int,
   float,float,u8,u8,u8,u8,float,int)` call order. The added 83/36 coordinate
   materialisation and two-statement inverse produce object 552B / window
   560B, MATCH (normalized_diff 0). */
// FUN_001163E0
void func_001163e0(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    void func_001171c0(s64, f32, s32, u8, s32);
    f32 high;
    f32 sp90[2];
    u8 color[4];
    s32 id0;
    s32 id1;
    s32 count;
    s32 width;
    high = *((f32 *)&arg0 + 1);
    id0 = arg3[0];
    if (id0 == 0) {
        func_0046d730(D_005E4868, 0x1BF);
    }
    id1 = arg3[2];
    if (id1 == 0) {
        func_0046d730(D_005E4868, 0x1C1);
    }
    count = (s32)(func_00109280(*(u16 *)(arg2 + 2)) & 0xFF);
    if (count <= 0 || count >= 0x20) {
        func_0046d730(D_005E4868, 0x1E6);
    }
    sp90[1] = 6.0f + high;
    width = (((count & 0xFFFF) - 1) & 0xFFFF) + 0x21;
    sp90[0] = 80.0f + *(f32 *)&arg0 - func_0046b1f0(id0, width) / 2.0f;
    count = arg1 & 0xFF;
    count = 0xFF - count;
    func_0046d4c0(0, id0, width, sp90[0], sp90[1], count, 0xFF, 0xFF, 0xFF, fparg0, 0);
    sp90[0] = 53.0f + *(f32 *)&arg0;
    sp90[1] = 43.0f + high;
    func_0046d4c0(0, id1, 0x2A, sp90[0], sp90[1], count, 0xFF, 0xFF, 0xFF, fparg0, 0);
    sp90[0] = 83.0f + *(f32 *)&arg0;
    sp90[1] = 36.0f + high;
    color[0] = 0xFF;
    color[1] = 0xFF;
    color[2] = 0xFF;
    color[3] = (u8)arg1;
    func_001171c0(*(s64 *)sp90, fparg0, *(s32 *)color, *(u8 *)(arg2 + 4), id1);
}



void func_00117310(s64, f32, s32, s32, s32, s32);
/* measured: the float-second `(I64,f32,s32,s32,s32,s32)` declaration for
   func_00117310 reproduces its `ld $a0; mov.s $f12; lw/lw/move/addiu`
   materialisation. This body uses the float-first func_00275020 declaration
   and the direct `iGpffff9c0c` spelling for retail `-0x63F4($gp)`.
   Object 524B / window 528B, MATCH (nd 0). */
// FUN_00116610
void func_00116610(s64 arg0, f32 fparg0, s32 arg1, u8 *arg2, s32 *arg3)
{
    u8 sp90[0x100];
    f32 sp190[2];
    u8 sp19c[4];
    s32 alpha;
    s32 color;
    s32 id0;
    s32 id1;
    s32 temp;
    f32 high;

    high = *((f32 *)&arg0 + 1);
    alpha = arg1 & 0xFF;
    color = (u32)((alpha * 0xFF) / 255U);
    id0 = arg3[0];
    if (id0 == 0) {
        func_0046d730(D_005E4868, 0x235);
    }
    id1 = arg3[1];
    if (id1 == 0) {
        func_0046d730(D_005E4868, 0x237);
    }
    sp190[0] = 129.0f + *(f32 *)&arg0;
    sp190[1] = 39.0f + high;
    func_0046d4c0(0, id0, 0x39, sp190[0], sp190[1], (0xFF - alpha) & 0xFF, 0x2D, 0x2D, 0x2D, fparg0, 0);
    sp190[0] = 259.0f + *(f32 *)&arg0;
    sp190[1] = 43.0f + high;
    sp19c[0] = 0x2D;
    sp19c[1] = 0x2D;
    sp19c[2] = 0x2D;
    sp19c[3] = arg1;
    func_00117310(*(s64 *)sp190, fparg0, *(s32 *)sp19c, *(s32 *)(arg2 + 0x38), id1, 1);
    temp = (s32)func_00109220(*(u16 *)(arg2 + 2));
    func_00442088(&sp90[0], (void *)&iGpffff9c0c, temp);
    func_00275020((f32)((s32)*(f32 *)&arg0 + 0x86), (f32)((s32)high + 3), fparg0, color | -0x100, 7, 1, &sp90[0], 0, -1);
}



/* measured: fully decompiled candidate archived after the corrected
   `(s64,f32,s32,u8*,s32*)` declaration scored nd 943 (obj 1236B /
   window 1312B). The body was oversized relative to the useful park
   threshold and is preserved verbatim in
   build/WBShdPersona_func_00116820_archive.txt; the source remains a
   bare INCLUDE_ASM until a separately measured reconstruction closes the
   retail loop tail. */
// FUN_00116820
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00116820);



extern f32 iGpffff82fc;
/* measured: recipe A re-test — nd 271 (was 231, so the re-test is WORSE;
   the old note's spelling was structurally different). arg1 is the crux:
   with u8 arg1 the if(arg1>=0) abs arm is DUPLICATED by mwcc's range
   analysis (u8 params ARE analysed — bltz on var_22 + a second bltz on
   arg1, two conversions, nd 271); with s8 arg1 the bltz survives but every
   use (var_22 = arg1 & 0xFF, (f32)arg1) emits dsll32/dsra32 sign-extensions
   that retail never makes (retail: plain andi + bltz on the raw $5 value).
   Retail's original must have kept the raw register value — neither u8 nor
   s8 reproduces it. Also measured: (1) the u32 base = (u32)D_00887300 +
   *(u32 *)base per-call spelling DOES hoist the base into a saved register
   (recipe B refinement), but mwcc keeps base separate from var_17 where
   retail SHARES $17 (var_17 dies at the 3rd func_0046d4c0 call, base is
   lazily lui'd at 0x17064) — +1 saved GP, frame 0xF0 vs 0xC0; (2) the byte
   block spB8..spBF and the spA0..spAC s32 block need m2c's declaration
   order (bytes first, then s32s) or the slots scatter; (3) the
   func_0044b610/iGpffff82fc/func_0046d4c0/overflow-guard regions decode
   cleanly (c.ole.s vs retail c.le.s on the 0x4F guard is the only fp row).
   func_0046d4c0 11-arg call shapes and the odd-register arg mapping
   (arg5 in $9) verified against retail. */
// FUN_00116D40 NONMATCHING
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
static inline u8 shdPackedLow(s32 *value)
{
    return *((u8 *)value);
}



/* measured: callee-side u32/u32 declaration closes func_001171c0 at object
   328B / window 336B, normalized_diff 0. */

void func_001171c0(s64, f32, s32, u32, u32);
// FUN_001171C0
void func_001171c0(s64 arg0, f32 fparg0, s32 arg1, u32 arg2, u32 arg3)
{
    s64 sp70;
    s32 packed;
    f32 farg;
    f32 f;
    s32 n;
    s32 id;
    u8 b2;
    u8 b1;
    s32 inv;
    s32 rem;
    f32 y;

    sp70 = arg0;
    farg = fparg0;
    packed = arg1;
    n = arg2;
    id = arg3;
    y = *((f32 *)&sp70 + 1);
    if (id == 0) {
        func_0046d730(D_005E4868, 0x400);
    }
    rem = n & 0xFF;
    if (rem < 10) {
        f = 11.0f + *((f32 *)&sp70 + 0);
    } else {
        f = 22.0f + *((f32 *)&sp70 + 0);
    }
    b2 = *((u8 *)&packed + 2);
    b1 = *((u8 *)&packed + 1);
    inv = 0xFF;
    inv -= *((u8 *)&packed + 3);
    do {
        func_0046d4c0(0, id, (rem % 10) + 0x1D, f, y, inv,
                      shdPackedLow(&packed), b1, b2, farg, 0);
        n = ((u32)(n & 0xFF) / 10U) & 0xFF;
        f -= 22.0f;
        rem = n;
    } while (n > 0);
}
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



void func_00119e10(u8 *, u8 *);
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
    *(void (**)(u8 *))(b + 0x548) = (void (*)(u8 *))func_00119e10;
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



extern u8 iGpffff9c10;
extern u8 iGpffff9c11;
extern u8 iGpffff9c12;
extern u8 iGpffff9c13;
extern f32 iGpffff81e0;
extern f32 iGpffff8094;
extern f32 iGpffff82fc;
extern f32 D_005E4D70;
extern f32 D_005E4D74;
extern f32 D_005E4D78;
extern f32 D_005E4D7C;
extern f32 D_005E4D80;
extern f32 D_005E4D84;
extern f32 D_005E4D88;
extern u8 D_005E4D90[];
extern s16 D_005E4D58[];
void func_003657d0(s64, f32, s32, f32, f32, s32, f32, f32);
s32 func_003b7060();
void func_0045dfd0(f32, void *, void *, s32, s32, s32);
void func_0034f4a0(s32, s32, s8, s8, s8, s64, s64, s16, f32, f32, f32, f32, s16, s16);
/* measured: fully decoded, best nd 858 (obj 2992B / window 3632B) at attempt 2.
   The sp120-sp12B byte block and the spE0-spF4 float block must be ARRAYS
   (`u8 sp120[16]; f32 spE0[6];`) or mwcc dead-store-eliminates all but the
   address-taken element (frame drops to 0xD0 vs retail 0x140). Remaining
   floors, all documented families: (1) the (u8)(s32) 0x4F000000 overflow
   branches on `255.0f * (f/255.0f)` and `(f1/30.0f) * ((f*f)/255.0f)` style
   products are eliminated by mwcc's float range analysis (the func_00119210
   family — retail keeps them); the bltz abs-else on the raw lbu 0x505 DOES
   survive; (2) the mula.s/msub.s accumulator pairs (the f21 = a*b - c*d
   chains in the <5 branch and the sp134 = f - f21*f1 expressions) need the
   exact product-operand order; (3) the D_00887300 base hoist (same as
   19e10 — retail caches the base in a saved reg, mwcc rematerialises);
   (4) the loop's adda.s/madd.s fusions for sp130/sp134 (91.0f/0x22D seeds
   are mwcc's acc seeds — the source is `0.0f + seed + a*b` forms per the
   func_00118a20 finding). func_0044b7b0 calls in the loop are ONE-arg
   (m2c's 2-arg forms were hallucinations); func_00117980 is
   (u8 *) single-arg (the m2c's 2-arg call in func_00119e10 was stale
   registers); func_0045dfd0's first arg is the f32 0.0f. New symbols:
   iGpffff9c10-13 = gp-0x63F0..-0x63ED = 0x00762D00..03, iGpffff81e0 =
   gp-0x7E20 = 0x007612D0 (added to symbol_data_addrs). */
// FUN_00117980
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00117980);



void func_0034f4a0(s32, s32, s8, s8, s8, s64, s64, s16, f32, f32, f32, f32, s16, s16);
/* measured: retail keeps only t16 and arg2 in saved registers (frame 0x60 with
   the two s64 homes at 0x50/0x58); mwcc b210 also saves arg0 (frame 0x80,
   homes at 0x70/0x78) and the whole body shifts (nd 147, obj 8B over window).
   Tried declaration orders — identical. FP/GP colouring floor. */
// FUN_001187B0
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_001187b0);



void func_001187b0(u8 *, s64, u8, s64, f32);
void func_0045dfd0(f32, void *, void *, s32, s32, s32);
extern f32 iGpffff8364;
extern f32 iGpffff8094;
/* measured: best nd 221 (obj 1720B / window 1744B) at attempt 4. The FMA
   blocks now match byte-for-byte once each fused value is a NAMED local
   (e.g. `x = 135.0f + 516.0f * f25;` then store x twice + `516.0f + x`):
   an inline repeated expression gets CSE'd and mwcc then emits mul.s+
   add.s instead of adda.s/madd.s — probed directly against b210. The
   multiplier is 516.0f (0x44010000), NOT 512.0f. Remaining residuals,
   all documented scheduling/colouring rows: (1) arg0 saves $s2 vs retail
   $s1 (and the loop counter k $s1 vs $s2) — a two-saved-register swap;
   (2) the 0x522/0x524 increment: retail [addiu in place; sh; dsll32;
   dsra32; slti], mwcc [addiu $v1; dsll32/dsra32 on a copy; sh $v1] — the
   store lands after the sign-extend; (3) the -11.0f block: retail emits
   [lui; mtc1 $f1; sw] with the mtc1 before the first sw, mwcc sinks the
   mtc1; and `484.0f + -11.0f` must NOT be a literal pair — mwcc folds it
   to (f32)473 via addiu+cvt — an untried `f32 m11 = -11.0f;` local shared
   by the sw stores and the final add would reproduce the lui/mtc1/sw/add.s
   sequence (retail's $-register reuse). The lerp chains need the temp
   + join form (`if (v<0) x=0; else if (v<6) x=func(...); else x=1;
   f25 = 1.0f - x;`) or the branches write the saved FP regs directly.
   func_00364c50/70 are 0-arg (m2c's 3-arg call is a hallucination from
   stale loop registers); func_001187b0 is (u8*, s64, u8, s64, f32);
   iGpffff8364 = gp-0x7C9C = 0x00761454 (added to symbol_data_addrs). */
// FUN_00118A20
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00118a20);



void func_0045dfd0(f32, void *, void *, s32, s32, s32);
/* measured: rule 2 applied — the madd.s operand order IS source-driven:
   retail `madd.s $f0,$f4,$f2` (2.0f first) needs `arg0[0] + 2.0f * x` with
   the CONSTANT first; the old probe batch only transposed the ADD operands
   (acc += x / x + acc). The FMA fusion (adda.s $f3,$f0 + madd.s) requires
   #pragma opt_loop_invariants on (the old note's "six loop constants" hoist:
   2.0f/$f4, 0.0f/$f3, -450.0f/$f1, 0x5A/$7, 0xFF/$6, 1/$3).
   Removing the pragma was measured at nd 0 -> nd 136: the accumulator seed
   sinks into the loop and the fusion breaks into add.s + adda.s + madd.s. */
#pragma opt_loop_invariants on
// FUN_001190F0
void func_001190f0(f32 *arg0, u8 arg1)
{
    f32 sp30[12];
    u8 sp10[24];
    f32 *dstf;
    u8 *dstb;
    s32 i;
    s32 x;
    s32 n2;
    s32 n;

    for (i = 0; i < 6; i++) {
        dstf = &sp30[2 * i];
        x = i & 1;
        if (i < 0 && (i & 1)) {
            x -= 2;
        }
        *dstf = arg0[0] + 2.0f * (f32)x;
        n2 = i / 3;
        *(dstf + 1) = arg0[1] + 450.0f * (f32)n2;
        dstb = &sp10[4 * i];
        dstb[0] = 0x5A;
        dstb[1] = 0x5A;
        dstb[2] = 0xFF;
        n = i / 2;
        if (n == 1) {
            dstb[3] = arg1;
        } else {
            dstb[3] = 0;
        }
    }
    func_0045dfd0(0.0f, sp10, sp30, 6, 4, 0);
}
/* Closes the measured opt_loop_invariants scope opened for func_001190f0 above.
   It must stay scoped: leaving it on regresses the neighbouring functions. */
#pragma opt_loop_invariants off



s32 func_00107890(s32);
void func_0046d2b0(s32, s32, s32, f32, f32, u8, f32, s32);
void func_001190f0(f32 *, u8);
extern u8 D_005E4DB0[];
extern f32 iGpffff8368;
/* measured: recipe A re-test — nd 362-363 (vs recorded 358). PARTIAL
   OVERTURN: with the exact retail spelling the four abs bltzs SURVIVE —
   `s32 temp_5 = temp_21 & 0xFF;` (temp_21 a u8 lbu local — the mask of an
   opaque u8 is NOT range-proven), `func_003b7060() & 0xFFF` inline, and the
   u16 sp80 element — all keep their bltz + srl/andi/or/mtc1/cvt/add.s arms
   (the old note's claim that they are eliminated was spelling-dependent).
   What still dies: the (u8)/(u16)(s32) 0x4F000000 overflow guards — the abs
   construct's own result is range-bounded [0,255] so the c.le.s/bc1t guard
   is eliminated (same mechanism as func_00119810 re-test). NEW residual:
   the TWO textually-identical abs constructs (var_f1/var_f1_2) get CSE'd to
   ONE abs + one guard (retail emits both — ~30B missing); the explicit
   if/else guard form (m2c's `if (!(var_f1 >= 2.1474836e9f))`) was NOT
   retried within budget. Layout: u8 spD0[16]/s32 spE0[8] arrays keep the
   byte/word stores live (separate s8/s32 locals dead-store-eliminate) but
   the candidate saves 8 GP regs (temp_5 in $s2 etc.) vs retail's 6 — frame
   0x130 vs 0x110; the previous nd-358 attempt's register structure was not
   recovered. Everything else (the 10x8B copy loop, the adda.s/madd.s and
   adda.s/msub.s fusions, the func_0046d2b0 8-arg calls with the u8 param's
   per-call andi, the func_0045dfd0 f32-first call, the divu loop) verifies
   against retail. */
// FUN_00119210
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119210);



/* measured: recipe A re-test — nd 351-356, WORSE than the recorded 197
   (my structural variants regressed the FP allocation; the old note's
   exact spelling was not recovered). Measured facts: (1) the (f32)(s32)
   bltz on the raw lbu 0x505 survives in BOTH spellings (u8 temp_2_5 and
   recipe A's s32 v + u32 c locals); (2) the (u8)(s32) 0x4F000000 overflow
   guards on `0.5f * (f32)lbu-0x505 * (1.0f - var_f22)` and `(f32)lbu-0x505
   * var_f23` are eliminated in BOTH — the abs construct's own result is
   range-bounded to [0,255] by mwcc, so the recipe's s32 local does NOT
   keep the guard; residual (1) of the old note stands. (3) NEW: the FIRST
   0x505 chain DUPLICATES the bltz arm (if-test bltz + conversion-guard
   bltz) and allocates var_f1 to $f24 (extra saved FP, frame 0x80 vs 0x70)
   while the SECOND chain emits a single bltz with a temp $f0 — asymmetry
   unexplained, present in both spellings. (4) the FP rotation: mwcc
   assigns [1.0f->$f20, var_f20->$f21, var_f23->$f22, var_f22->$f23] vs
   retail [var_f20->$f20, 1.0f->$f21, var_f22->$f22, var_f23->$f23].
   (5) chain-1's u16-counter (f32) conversion keeps an extra abs bltz
   (chains 2/3 do not — the (temp-8) subtraction defeats it). The
   func_00274ed0 9-arg s64-odd-register call, the func_0034f4a0 14-arg
   call, var_18 = (s64)(8 << 0x38) >> 0x38 (dsll32/dsra32) and the
   func_0046d4c0 11-arg calls all verify against retail. */
// FUN_00119810
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_00119810);
void func_0011ac70(u8 *);
void func_0011ae90(u8 *);
void func_0011c780(u8 *);
void func_0011c930(u8 *);
void func_0011c3e0(u8 *);
void func_0011cd20(u8 *);
void func_0011ce50(u8 *);
void func_0011b110(u8 *);
void func_0011de40(u8 *, s32);
void func_0011dd50(u8 *);
void func_00118a20(u8 *);
void func_0011dc50(u8 *);
void func_0011e400(u8 *, u8 *);
s32 func_0011e460(u8 *);
s32 func_0011ccb0(u8 *);
void func_00114e50(s64, u8, s32, s32);
void func_00113ef0(s64, u8, u8 *, u8, s32, f32);
void func_00114460(s64, u8, u8 *, s32, f32);
void func_00119210(u8 *);
void func_00119810(u8 *);
void func_00117980(u8 *);
void func_0034f9d0(s64, u8, s32, s32, s32);
/* measured: fully decoded, best nd 830 (obj 3844B / window 3216B, frame 0xA0
   vs 0x90) at attempt 3. The TRUE signature is `void func_00119e10(u8 *arg0,
   u8 *arg1)` with the USED base in $5 (the m2c's arg1 — a leading param was
   dropped; the vtable callers pass the work in $5). Fixed during the attempt:
   func_00364680 is (s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32) (2nd param a
   value, not s32*), func_001163e0 is (s64,s32,u8*,s32*,f32) (fparg0 LAST — the
   odd-register rule puts arg1 in $5), func_00116d40 is (I64,u8,u8,u8,s16,s32,
   f32). Remaining allocation cascade: (1) the D_00887300 base — retail caches
   it in $s1 (lazily lui'd at the first call, per-call `lw $v0,($s1)`), mwcc
   without a local rematerialises lui/lw per call (~72B), and with the local
   `tbl = D_00887300; tbl[N](0,0)` it hoists into $s0 with arg1 pushed to $s1
   (retail: arg1 $s0, base $s1 — one register swap that shifts the whole body);
   (2) the candidate needs ONE extra saved GP (5 vs retail's 4 — frame 0xA0);
   (3) the sp88/sp8C pair homes land at 0x78 instead of 0x88 (layout order).
   All the (f32)(s32) cvt pairs, the 0x4F guard on `(u8)(s32)(204.0f*(1-f20))`
   (survives — the value mixes a call result), the sp78/sp70/sp68 s64 copies,
   and the family calls (16610/163e0/16820/16d40/14e50/13ef0/14460/34f9d0)
   decode per the draft; the `(u32)(b18 * 0xFF) / 255U` and
   `*(*(u16 **)arg1) & 4` shapes reproduced. */
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
/* Wave-14 re-measure: frame fix confirmed — lever 6 (inline element
   pointer `arg0 + i*36 + off` as an integer-domain address, NO named `p`
   local) drops the frame 0x40 -> 0x30 (retail's) and the element pointer
   is recomputed in a temp per side of the func_0044b7b0 call like retail
   (nd 158 -> 126). Remaining 126: (1) the top-of-loop load order — retail
   [lh 0x508; sll/addu ptr; lwc1 0x2e8; mtc1; cvt] defers the cvt.s.w,
   mwcc converts immediately after the lh; (2) the post-call element
   pointer lands in $a3 vs retail $a2; (3) the lerp FMA + iGpffff8094 mul
   register allocation. opt_propagation off (FLYDraw's lever) is NOT
   applicable here — multi-use loop, not a single-use base wrapper. */
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
/* Wave-14 re-measure: lever 6 (inline integer-domain element pointer
   `arg0 + i*36 + off`, no named `p` local) applied — measured nd 149
   (vs recorded 158), same family floor as func_0011ac70 (identical loop;
   the post-loop differs: 0x510 vs 0x50C and the four chained mask clears
   ~4/~0x80000/~0x200000/~0x800000 + the 0x505==0 ?? 0x400000 clear/or).
   opt_propagation off (FLYDraw) does NOT apply — multi-use loop base. */
// FUN_0011AE90
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011ae90);



void func_0034c270(Vec2f, u8, s32, f32);
/* measured: reconstructed plain-C body, nd 18 (obj 444B / window 448B),
   improved from nd 21 by bracketing only this function with
   `#pragma opt_common_subs off` (restored after the body). The remaining
   fndiff rows are the two call-site argument-materialization swaps at offsets
   88/92 and 120/124 (retail prepares the stack aggregate before loading
   $f12), the signed-byte negative-path colouring at 192/196 (`or` and `mtc1`
   use retail $v1 while MWCC uses $v0), and the relocation-owned global-address
   pair at 360/364. The object remains four bytes short at the tail. No source
   spelling tested changed these residuals. Committed at nd 18. */
/* archived body: build/VSHD_0011b110_body.c; object 444B; retail window 448B;
   normalized_diff 16; differing offsets 0x58, 0x5C, 0x78, 0x7C; retail-only
   tail 0x1AC. The int-to-float idiom is `(f32)(u32)*(u8 *)(arg0 + 0x505)`.
   Residual is call-site Vec2f aggregate/float argument materialisation order
   plus tail padding; declaration, pragma, direct-float, aggregate-dereference,
   duplicate-local, and initializer alternatives were ruled out. */
// FUN_0011B110 NONMATCHING
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
/* measured: fully decompiled, nd 19 (obj 336B / window 336B). The only
   residual is a six-word FP scheduling/allocation permutation at offsets
   188, 192, 196, 200, 204, and 208. Retail emits addiu/mtc1/nop/cvt.s.w
   for integer 0x303 into $f1, then lwc1 0x4FC into $f0, then add.s
   $f0,$f1,$f0. MWCC emits the same multiset as lwc1 into $f1, addiu/mtc1/
   nop/cvt.s.w into $f0, then add.s $f0,$f0,$f1. Nothing is missing or
   extra: the values own the opposite FP temporaries, and retail hoists the
   conversion chain over the field load to cover the mtc1-to-cvt.s.w hazard.
   Operand transpositions are canonicalised; naming field/constant locals,
   integer versus 771.0f spellings, split expressions, address-domain forms,
   and all thirteen pragma wrappers did not change nd. Function-wide FP
   liveness/scheduling floor. Committed at nd 19. */
// FUN_0011BDC0
void func_0011bdc0(u8 *arg0)
{
  u8 *baseWork;
  f32 *xField;
  Vec2f v2;
  Vec2f v;
  f32 result;
  int isZero;
    baseWork = (*((SdkTask *) arg0)).work;
  if (!((*((s32 *) (baseWork + 0x534))) & 2))
  {
    func_0011ba40(baseWork);
    *((u16 *) (baseWork + 0x508)) = 0;
    *((u8 *) (baseWork + 0x504)) = *((u8 *) (baseWork + 0x505));
    *((u8 *) (baseWork + 0x506)) = 0xFF;
    func_0011aaa0(baseWork, 4);
    v.x = 131.0f + (*((f32 *) (baseWork + 0x4FC)));
    v.y = (-59.f) + (*((f32 *) (baseWork + 0x500)));
    result = func_0011de80(*((u8 **) (baseWork + 0x4F8)), &v2);
    isZero = result == 0.0f;
    if (isZero || (result == 1.0f))
    {
      xField = (f32 *) (baseWork + 0x4FC);
      result = 771.0f;
      result = result + (*xField);
      v2.x = result;
        v2.y = (-59.0f) + (*((f32 *) (baseWork + 0x500)));
        func_0011e2b0(*((u8 **) (baseWork + 0x4F8)), &v2, &v);
        func_0011e370(*((u8 **) (baseWork + 0x4F8)));
    }
    else
    {
      func_0011e2b0(*((u8 **) (0x4F8 + baseWork)), &v2, &v);
    }
    *((s32 *) (baseWork + 0x534)) |= 0x200000;
  }
}




/* measured: fully decompiled, nd 19 (obj 620B / window 624B). Offsets 292,
   296, 300, 304, 308, and 312 have the same six-word FP permutation as
   func_0011bdc0: retail emits addiu/mtc1/nop/cvt.s.w for integer 0x303 into
   $f1, then lwc1 0x4FC into $f0, then add.s $f0,$f1,$f0; MWCC emits lwc1
   into $f1, addiu/mtc1/nop/cvt.s.w into $f0, then add.s $f0,$f0,$f1.
   Nothing is missing or extra in those six words; the opposite FP
   temporary ownership prevents operand transposition from changing the
   result, and retail's conversion-chain hoist covers the mtc1-to-cvt.s.w
   hazard. The object is four bytes short at tail offset 620. Naming
   field/constant locals, integer versus 771.0f spellings, split expressions,
   address-domain forms, and all thirteen pragma wrappers did not change nd.
   Function-wide FP liveness/scheduling floor. Committed at nd 19. */
// FUN_0011BF10
void func_0011bf10(u8 *arg0)
{
  u8 *w;
  int new_var27;
  int new_var8;
  s32 flags;
  int new_var11;
  s32 t1;
  u8 *new_var13;
  f32 *new_var12;
  s32 *new_var19;
  u16 t7;
  int new_var24;
  unsigned char new_var22;
  s32 t2;
  s32 *new_var21;
  u8 **new_var30;
  int new_var23;
  u8 *new_var2;
  float new_var9;
  s32 *new_var7;
  int new_var;
  s32 t3;
  u8 *new_var15;
  u8 *new_var20;
  u8 *new_var3;
  unsigned int t4;
  int new_var14;
  u8 *new_var4;
  int new_var26;
  u8 *new_var5;
  int new_var10;
  s32 t5;
  int new_var18;
  float new_var28;
  u8 *new_var16;
  s32 t6;
  u8 *new_var25;
  s32 state;
  s32 new_var17;
  u8 *new_var6;
  Vec2f v2;
  s32 *new_var29;
  f32 ret;
  Vec2f v;
  if ((((!new_var2) && (!new_var2)) && (!new_var2)) != 0)
  {
  }
  ret++;
  ret--;
  w = ((SdkTask *) arg0)->work;
  flags = *((s32 *) (w + 0x534));
  ;
  if ((((flags & 1) != 0) && ((flags & 4) == 0)) && (((state = flags) & 0x400000) == 0))
  {
    if (new_var15)
    {
    }
    t1 = (*((s32 *) (w - -0x534)) = flags | 4);
    new_var19 = (s32 *) (w + 0x52C);
    new_var15 = w - -0x534;
    *((s32 *) (w + 0x534)) = (t2 = t1 & (~2));
    t3 = (*((s32 *) new_var15) = t2 & (~0x800));
    *((s32 *) (w + 0x534)) = (t4 = t3 & (~0x1000));
    new_var21 = (s32 *) (w + 0x534);
    *new_var21 = (t5 = t4 & (~0x2000));
    t6 = (*new_var21 = t5 & (~0x4000));
    t6 = 0x88;
    new_var7 = new_var19;
    new_var10 = -1;
    *((s8 *) (w + t6)) = new_var10;
    new_var24 = 0x444 & 0xFFFFFFFF;
 goto dummy_label_194269;
 dummy_label_194269: ;
    t2 = (0, 0);
    new_var29 = &(*new_var7);
    *((s32 *) (w + new_var24)) = 0xC3E10000;
    state = *new_var29;
    switch (state)
    {
      case 0:
        if (new_var2)
      {
      }
        func_0045af60(0, 1, t2 & 0xFFFFFFFFFFFFFFFF, 4);
        break;

      case 1:
        new_var17 = t1;
      {
      }

 do { case 3: case 2: case 4: break; default: arg0++; arg0--; func_0046d730(D_005E4868, 0xCCC & 0xFFFFFFFFFFFFFFFF); if (1) { } break; }
 while (0 * (!new_var2));
    }

    *((u16 *) (w + 0x508)) = (t6 = 0);
    new_var2 = w;
    new_var22 = t3 & (~0x1000);
    new_var2 = w;
    new_var16 = w;
    *((u8 *) (new_var16 + 0x504)) = *((u8 *) (new_var4 = new_var16 + 0x505));
    *((u8 *) (new_var16 + 0x506)) = 0xFF & 0xFFFFFFFFu;
    t2 = 771.0f;
    new_var6 = new_var16;
    func_0011aaa0(new_var6, 5);
    new_var20 = new_var16 - -0x4FC;
    new_var5 = new_var20;
    v.x = t2 + (*((f32 *) new_var5));
    new_var27 = 0xFFFFu & 0xFFFFFFFFu;
    new_var10 = ((new_var16 && new_var16) && w) != 0U;
    if (new_var10)
    {
    }
    ;
    v.y = (new_var9 = -59.0f) + (*((f32 *) (new_var2 + 0x500)));
    new_var = 2;
    ret = func_0011de80(*((u8 **) (new_var2 + 0x4F8)), &v2);
    new_var11 = ret == 0.f;
    if (new_var11 || (1.0f == ret))
    {
      new_var30 = (u8 **) (new_var2 + 0x4F8);
      new_var3 = new_var2;
      new_var13 = new_var2;
      new_var13 = new_var13 + 0x4F8;
      new_var28 = -59.0f;
      if (w != 0)
      {
 do { } while (0);
      }
      v2.x = 131.0f + (*((f32 *) (new_var2 + 0x4FC)));
      v2.y = new_var28 + (*((f32 *) (new_var3 + 0x500)));
      func_0011e2b0(*new_var30, &v2, &v);
      func_0011e370(*((u8 **) new_var13));
    }
    else
    {
      func_0011e2b0(*((u8 **) (new_var2 + 0x4F8)), &v2, &v);
    }
    t4 = new_var22;
    flags = *((s32 *) (new_var2 + 0x534));
    if ((0x80000 & flags) != 0)
    {
      new_var14 = (!new_var2) * 0;
      t7 = *((u16 *) (new_var2 + 0x458));
      if ((t7 & new_var) == 0)
      {
        if (((unsigned int) ((new_var17 = t1) && t1)) && t1)
        {
        }
        if ((t7 & 1) == ((!new_var2) * 0))
        {
          *((s32 *) (w + 0x534)) = flags & (~0x80000);
        }
        else
        {
          new_var25 = w;
          new_var22 = t3 & (~0x1000);
          new_var18 = new_var27;
          *((0, (u16 *) (new_var25 + 0x45A))) = 0;
          new_var8 = new_var18;
          new_var26 = 0x458;
          *((u16 *) (w + new_var26)) |= 2 & new_var8;
          if ((double) (!new_var25))
          {
          }
 do { } while (new_var14);
        }
        new_var5 = new_var20;
      }
    }
  }
}
#ifdef NON_MATCHING
void func_0011bf10(u8 *arg0)
{
    u8 *w;
    s32 flags;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 state;
    u16 t7;
    Vec2f v2;
    Vec2f v;
    f32 ret;

    w = ((SdkTask *)arg0)->work;
    flags = *(s32 *)(w + 0x534);
    if ((flags & 1) != 0 && (flags & 4) == 0 && (flags & 0x400000) == 0) {
        t1 = flags | 4;
        *(s32 *)(w + 0x534) = t1;
        t2 = t1 & ~2;
        *(s32 *)(w + 0x534) = t2;
        t3 = t2 & ~0x800;
        *(s32 *)(w + 0x534) = t3;
        t4 = t3 & ~0x1000;
        *(s32 *)(w + 0x534) = t4;
        t5 = t4 & ~0x2000;
        *(s32 *)(w + 0x534) = t5;
        t6 = t5 & ~0x4000;
        *(s32 *)(w + 0x534) = t6;
        *(s8 *)(w + 0x88) = -1;
        *(s32 *)(w + 0x444) = 0xC3E10000;
        state = *(s32 *)(w + 0x52C);
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
        *(u16 *)(w + 0x508) = 0;
        *(u8 *)(w + 0x504) = *(u8 *)(w + 0x505);
        *(u8 *)(w + 0x506) = 0xFF;
        func_0011aaa0(w, 5);
        v.x = 771.0f + *(f32 *)(w + 0x4FC);
        v.y = -59.0f + *(f32 *)(w + 0x500);
        ret = func_0011de80(*(u8 **)(w + 0x4F8), &v2);
        if (ret == 0.0f || ret == 1.0f) {
            v2.x = 131.0f + *(f32 *)(w + 0x4FC);
            v2.y = -59.0f + *(f32 *)(w + 0x500);
            func_0011e2b0(*(u8 **)(w + 0x4F8), &v2, &v);
            func_0011e370(*(u8 **)(w + 0x4F8));
        } else {
            func_0011e2b0(*(u8 **)(w + 0x4F8), &v2, &v);
        }
        flags = *(s32 *)(w + 0x534);
        if ((flags & 0x80000) != 0) {
            t7 = *(u16 *)(w + 0x458);
            if ((t7 & 2) == 0) {
                if ((t7 & 1) == 0) {
                    *(s32 *)(w + 0x534) = flags & ~0x80000;
                } else {
                    *(u16 *)(w + 0x45A) = 0;
                    *(u16 *)(w + 0x458) |= 2;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011bf10);
#endif


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



/* measured: rule 2 confirmed for the FMA sites — with the multiplications
   written ratio-first (`base + r * delta`, `f + r * diff`) AND
   #pragma opt_loop_invariants on, the adda.s $f4,$f2 / madd.s $f0,$f5,$f0
   pairs match retail byte-for-byte (without the pragma the acc seed lands
   inside the loop and the fusion breaks into add.s+adda.s+madd.s, nd 136;
   with the pragma the FMA block matches and the residual drops to ~15
   naming/order rows). Best nd 112 (obj 540B / window 560B) at attempt 4,
   still short of the old wave's 8. Remaining rows, all the documented
   scheduling/colouring family: (1) statement order at the loop top — retail
   [lh 0x516; i*36 math; lwc1 0x2E8; mtc1; cvt], the v-load must precede the
   e1 computation (untried with the pragma); (2) the neg-path abs or-dest
   $a2 vs $v1 (1 word); (3) the guard test encodes c.olt.s+bc1f where retail
   has c.ole.s+bc1t (1 word, same as func_0011c930 — small-path-inline layout
   is right either way); (4) prologue length: with the pragma the four loop
   constants (1.0f/0.0f/0x4F000000/0x80000000) still do not all hoist. The
   e1/e2 double address computation, `f += f` doubling, (u32)a >> 1,
   `r = acc` sharing, and sign-in-$a1 (or $v1,$v1,$a1) all reproduced.
   The function is back to INCLUDE_ASM, so no pragma is carried here: one
   wrapped around an INCLUDE_ASM does nothing except risk leaking into a
   neighbour. Re-add it with this note if the body is attempted again. */
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



/* measured: reconstructed plain-C body, nd 18 (obj 428B / window 432B).
   The raw s16 load ordering (raw; lo; ratio = (f32)raw; hi) first improved
   nd 48 to 43; `~0x1000` then emitted retail's -0x1001 at offset 396, and
   `2147483648.0f > acc` emitted retail c.ole.s plus bc1t at 288/292,
   reaching nd 38. The final nd 38 -> 18 fix nests the high-bound load/test
   inside the `else` after the low clamp, so the low path emits retail's
   mtc1 $zero,$f0 / b / nop at offsets 48/52/56 and defers lwc1 0x454 to 60.
   Remaining fndiff rows are the prologue load swap at 16/20; relocation-owned
   iGpffff8094 GPREL materialization at 108; negative-path coloring at
   240/244, 252/256; and output $v1/$a0 coloring at 304, 312, 340, 344, 348.
   The object remains four bytes short at tail offset 428. In-place OR,
   compound-assignment, reused-local, dual-result-zero, and all thirteen
   pragma wrappers were flat or worse. Committed at nd 18. */
/* archived body: build/VSHD_0011c780_body.c; object 428B; retail window 432B;
   normalized_diff 13; differing offsets 0x10, 0x14, 0x132, 0x13A, 0x155,
   0x15A, 0x15E. The int-to-float idiom is `(f32)(u32)a` for the unsigned
   byte absolute-value site; the signed halfword ratio stays `(f32)raw`.
   Residual is prologue load order, GPREL relocation, and output colouring. */
// FUN_0011C780 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c780);
/* measured: rule 2 confirmed — with the multiplications written ratio-first
   (`base + ratio * delta`, `f + ratio * diff`), the adda.s/madd.s pairs match
   retail byte-for-byte (madd.s $f1,$f0,$f3). Best nd 15 (obj 448B / window
   448B) with `f32 diff;` declared FIRST (declaration order fixed the whole
   post-jal FP rotation: diff→$f3, f_abs→$f2, acc→$f1). Remaining floor, all
   documented scheduling/colouring rows: (1) the top load interleave — retail
   [lh 0x514; lwc1 0x450; mtc1; nop; cvt], mwcc emits the lwc1 either before
   the lh (v-local + lo-local order) or after the cvt (inline conversion),
   never in the lh→mtc1 slot; (2) the neg-path abs: retail or-dest $a0 and
   in-place cvt $f2/add $f2, mwcc emits or $v1 and cvt $f1/add.s $f2,$f1,$f1;
   (3) the 0x4F000000 guard: `if (f < 2147483648.0f)` small-first gives
   retail's layout (small inline, big out of line) but mwcc encodes c.olt.s+
   bc1f where retail has c.ole.s+bc1t (1 word), and the n local colours $v1
   vs retail $a0 (the big-first `f >= C` form flips the layout instead —
   tried, nd 27); (4) the 0x88 store must be `*(s8 *)&0x88 = -1` (addiu -1,
   not 0xff). The func_0044b7b0 call must sit INSIDE the else-if branch or the
   div-destination register and the nop-after-div vanish. */
/* measured: nested high-bound load/test plus the proven constant-left strict
   guard (`2147483648.0f > acc`) and `~0x800`/`~0x2000` masks reduce this
   body from nd 49 to nd 23 (obj 448B / window 448B). The nested `else`
   fixes the pre-interpolation load schedule; the guard and masks reproduce
   retail c.ole.s/bc1t and -0x801/-0x2001. Remaining fndiff rows are
   20/24/28/32, relocation-owned 108 (iGpffff8094), 240/244/252/256,
   and 304/312/340/344/348: prologue FP load interleave, negative-path
   abs colouring, and output $a0 versus MWCC $v1 colouring. Strict,
   inclusive, negated-strict, mask-only, constant-left-inclusive, and all
   pragma-wrapper probes were ruled out or worse. Committed at nd 23. */
/* archived body: build/VSHD_0011c930_body.c; object 448B; retail window 448B;
   normalized_diff 13; differing offsets 0x10, 0x14, 0x132, 0x13A, 0x155,
   0x15A, 0x15E. The int-to-float idiom is `(f32)(u32)a`; the signed halfword
   ratio stays `(f32)(s16)*(s16 *)`. Source-ordered `lo` load versus halfword
   conversion leaves the prologue pair; remaining residual is GPREL/output
   coloring. Retail parameter audit uses only `$a0` (arg0); no hidden args or
   mixed-class order. Direct stores, raw staging, declaration reorder, and
   pragma alternatives were ruled out. */
// FUN_0011C930 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011c930);
// FUN_0011CAF0
void func_0011caf0(u8 *arg0)
{
    s32 flags;
    u8 *work;
    s32 bit800;
    s32 bit100000;

    work = *(u8 **)(arg0 + 0x38);
    flags = *(s32 *)(work + 0x534);
    bit800 = !!(flags & 0x800);
    if (bit800 == 0 || *(s8 *)(work + 0x88) == -1) {
        return;
    }
    bit100000 = (flags & 0x100000) != 0;
    if (func_00115020(work + 0x84, bit100000, work) != 0) {
        func_0045af60(0, 0, 0, 0);
    }
}
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
            t = func_0044b7b0(iGpffff8094 * (f32)*(s32 *)(work + 0x10) / 10.0f);
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
/* measured: full body decompiled (guard chain, two float lerps, func_00364680 + two func_003f6440 calls all reproduce). every remaining row is the work-pointer base register: retail keeps `lw $a1, 0x38($a0)` in $a1 (first free arg reg after $a0) for all 12 loads/stores; mwcc b210 always colours it $t0. Tried declaration order both ways, SdkTask typed form vs raw deref, s32 vs u8 byte locals, half as 3.0f literal vs local — identical $t0. Register-colouring floor (same family as func_0011dc50 note). Committed at nd 53. */
// FUN_0011DD50
void func_0011dd50(u8 *arg0)
{
    u8 *work;
    s32 first;

    work = ((SdkTask *)arg0)->work;
    if (*(s32 *)work == 3 && *(s32 *)(work + 4) != 0 &&
        *(s32 *)(work + 0x14) != 0) {
        *(f32 *)(work + 0x40) +=
            (*(f32 *)(work + 0x28) - *(f32 *)(work + 0x40)) / 3.0f;
        *(f32 *)(work + 0x44) +=
            (*(f32 *)(work + 0x2C) - *(f32 *)(work + 0x44)) / 3.0f;
        first = *(s32 *)(work + 0x0C);
        func_00364680(*(f32 *)(work + 0x18), first,
                      *(f32 *)(work + 0x40) + *(f32 *)(work + 0x38),
                      *(f32 *)(work + 0x44) + *(f32 *)(work + 0x3C),
                      *(f32 *)(work + 0x28), *(f32 *)(work + 0x2C),
                      512.0f, 512.0f, *(s32 *)(work + 0x50), 1, 0);
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
}





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



// FUN_0011DED0
s32 func_0011ded0(u8 *arg0)
{
    u8 *w;
    s32 out;
    s32 p4c;
    s32 r;

    w = *(u8 **)(arg0 + 0x38);
    r = func_004669d0(*(s32 *)w, &out, 0);
    if (out != 0) {
        p4c = *(s32 *)(w + 4);
        if (p4c != 0) {
            func_00440b68((s32)D_005E4ED0, (s32)(p4c + 0x10));
        } else {
            func_00440b68((s32)D_005E4EF0);
        }
        if (r != 0) {
            func_003ef3a0(r);
        }
        if (*(s32 *)(w + 4) != 0) {
            func_00454bd0(*(s32 *)(w + 4));
        }
        return -1;
    }
    return 0;
}

// FUN_0011DF90
void func_0011df90(u8 *arg0)
{
    jtbl_008873EC[0](((SdkTask *)arg0)->work);
}





// FUN_0011DFC0
s32 func_0011dfc0(s32 arg0, s32 arg1, char *arg2)
{
    s32 r;
    u8 *buf;

    func_0044ea90(D_005E4868, 0x11B2);
    buf = D_008873F4[0](1, 8, 0x40000);
    if (buf == NULL) {
        return 0;
    }
    r = func_00451de0(arg2, 0xF, 0, 0, func_0011ded0, func_0011df90, buf);
    if (r == 0) {
        return 0;
    }
    if (arg1 != 0) {
        func_00440b68((s32)D_005E4F10, (s32)(arg1 + 0x10));
    }
    *(s32 *)buf = arg0;
    *(s32 *)(buf + 4) = arg1;
    return r;
}



s32 func_0011ded0(u8 *arg0);
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
u16 *func_001094d0(s32 arg0);
extern u16 *iGpffffb3ec;
/* measured: retail keeps the `bltz` sign-check and the full else-branch
   (srl/andi/or/mtc1/cvt/add.s x2) of an abs-style conditional on
   `func_003b7060() & 0x1000` (and & 0xFFF); mwcc b210's range analysis proves
   the masked value non-negative and eliminates both branches entirely
   (object 100B under window, nd > 300 with the whole body shifted). Tried the
   conditional in every spelling (>=0/<0, if/else, ternary, s32/u32 locals,
   cast-to-s32 compare, macro form) — all eliminated. Also the ptr in $s0
   colouring differed. Range-analysis elimination floor. */
/* measured: opt_loop_invariants hoists the per-iteration `andi (temp_4 &
   0xFFFF)` and the `1` constant used for var_4=1/var_4_2=1 into the
   preheader (retail keeps them in $6/$7 across the loop); without it they
   are rematerialised in the body (nd 142 -> lower measured below). */
#pragma opt_loop_invariants on
/* measured: nd 364 with a full C body, object 596B against a 688B window, so work is still missing.
   Wave 7 ran out of turns here and left it uncommitted, so this is a
   partial adaptation rather than a floor: re-attempt from the m2c draft
   with the wave's recipes before treating any of it as settled. */
// FUN_0011E490 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/shdPersona", func_0011e490);

/* Closes the measured opt_loop_invariants scope opened for func_0011e490
   above. It must stay scoped: leaving it on regresses neighbours. */
#pragma opt_loop_invariants off



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



s32 func_0010a780(u8 *, s32, s32);
s32 func_0010ceb0(u8 *);
s32 func_0011fcf0(u8 *);
u8 *func_0011fbc0(s32, u8 *, s32, u8 *);
u16 func_00115750();
s16 func_00115380();
void func_002baac0(s32);
void func_002bb7c0();
void func_002bb4e0();
s32 func_002bb600(void);
void func_002bb1e0(s32);
s32 func_002bb140(void);
s32 func_001092f0(u8 *);
extern u16 D_008C024E;
extern u16 D_008C024C;
/* measured: fully decoded, best nd 566 (obj 2684B / window 2784B) at attempt 4.
   The prologue saved-reg order matches retail (s->$s0, p->$s1, b->$s2, e->$s3
   with the case-0 loop counter REUSING $s3) once the case-12 loop counter is a
   SEPARATE local (the m2c's var_3 vs var_19) — with one i the allocator gives
   e $s4. The ONE remaining structural difference: retail saves SIX GP regs
   (frame 0x70) — e2 stays live across func_0011b3d0/func_00115c00 because the
   final store re-derives e3 from e2 (`lw $2, 0x38($21); sw $19, 0x44($2)`), so
   the source's last case-0 statement must be
   `*(s32 *)(*(u8 **)(e2 + 0x38) + 0x44) = r;` (writing it via e3 kills e2's
   live range and drops the frame to 0x60). Everything else reproduced:
   the 16-case switch with the 0->1, 4->5->6, 9->0xA->0xB, 0xC->0xD
   fallthroughs (case 0xE empty), the (s16) dsll32/dsra32 casts, the
   `c = (u16)(*(u16 *)(b + 4) + 1)` comma-sequence in case 1's condition, the
   inner 9-slot jump table switch, the u16 counter patterns, and the jtbl
   relocs (masked). Casts needed for the shared (wrong-typed) declarations:
   func_0010cd70(..., (u8 *)(u32)c) and func_00115500((s16)n, (u8 *)(u32)c, ...)
   — mwcc rejects implicit ptr<->int both ways. func_0011e8e0 returns s32
   (epilogue `daddu $2,$0,$0`); declaration fixed. */
s32 func_0010a780(u8 *, s32, s32);
s32 func_0010ceb0(u8 *);
s32 func_0011fcf0(u8 *);
u8 *func_0011fbc0(s32, u8 *, s32, u8 *);
u16 func_00115750();
s16 func_00115380();
void func_002baac0(s32);
void func_002bb7c0();
void func_002bb4e0();
s32 func_002bb600(void);
void func_002bb1e0(s32);
s32 func_002bb140(void);
s32 func_001092f0(u8 *);
extern u16 D_008C024E;
extern u16 D_008C024C;
/* measured: fully decoded, best nd 566 (obj 2684B / window 2784B) at attempt 4.
   The prologue saved-reg order matches retail (s->$s0, p->$s1, b->$s2, e->$s3
   with the case-0 loop counter REUSING $s3) once the case-12 loop counter is a
   SEPARATE local (the m2c's var_3 vs var_19) — with one i the allocator gives
   e $s4. The ONE remaining structural difference: retail saves SIX GP regs
   (frame 0x70) — e2 stays live across func_0011b3d0/func_00115c00 because the
   final store re-derives e3 from e2 (`lw $2, 0x38($21); sw $19, 0x44($2)`), so
   the source's last case-0 statement must be
   `*(s32 *)(*(u8 **)(e2 + 0x38) + 0x44) = r;` (writing it via e3 kills e2's
   live range and drops the frame to 0x60). Everything else reproduced:
   the 16-case switch with the 0->1, 4->5->6, 9->0xA->0xB, 0xC->0xD
   fallthroughs (case 0xE empty), the (s16) dsll32/dsra32 casts, the
   `c = (u16)(*(u16 *)(b + 4) + 1)` comma-sequence in case 1's condition, the
   inner 9-slot jump table switch, the u16 counter patterns, and the jtbl
   relocs (masked). Casts needed for the shared (wrong-typed) declarations:
   func_0010cd70(..., (u8 *)(u32)c) and func_00115500((s16)n, (u8 *)(u32)c, ...)
   — mwcc rejects implicit ptr<->int both ways. func_0011e8e0 returns s32
   (epilogue `daddu $2,$0,$0`); declaration fixed. */
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
s32 func_0011e8e0(u8 *);
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
