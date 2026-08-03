/* Original translation unit datPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(const void *file, u32 line);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0023a620();
extern char D_005E4318[];
extern s16 D_00797F88[];
extern s16 D_00797F8C[];
extern s16 D_0079819C[];
extern u8 D_00796E50[];
extern u8 D_007973A0[];
extern u8 D_00797F8E[];
extern s32 D_0079B40C[];
extern u8 *DAT_007644c8;
extern u8 *DAT_007644c4;
extern u8 *DAT_007644cc;
extern u8 *DAT_007644d4;
extern u8 *iGpffffb3d8; /* gp -0x4C28 */
extern u8 *iGpffffb3d4; /* gp -0x4C2C */
extern u8 *iGpffffb3dc; /* gp -0x4C24 */
extern u8 *iGpffffb3e4; /* gp -0x4C1C */

extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0010c9e0(u8 *arg0);
extern void func_0010fde0(u8 *arg0);

extern s32 func_0010be20(u8 *arg0);
extern void func_0010fde0(u8 *arg0);
void func_0010cad0(); /* old-style: callers pass args raw */

extern u16 *func_0010ace0(s16 arg0);
extern s32 func_0010b5b0(void);
extern void func_0023a620();
extern s32 func_0010ae30(s32 arg0);
extern s32 func_0010b3b0(s32 arg0);
extern u16 func_0010b460(void);

extern u32 func_0010c750(u8 *arg0, s32 arg1);
extern void func_0010be60(u8 *arg0, u8 *arg1, s32 arg2);
extern void func_0010c5a0(u8 *arg0, u8 *arg1);
extern void func_0010d150(u8 *arg0);

extern f32 fGpffff8218; /* gp -0x7DF8 */
extern f32 fGpffff821c; /* gp -0x7DF4 */
extern f32 fGpffff8150; /* gp -0x7EB0 */
extern u8 *iGpffffb3e8; /* gp -0x4C18 */

s8 func_00109d20(u8 *arg0, s32 arg1);
s8 func_00109dd0(u8 *arg0, s32 arg1);
s8 func_00109e30(u8 *arg0, s32 arg1);

extern u8 *func_0010b060(); /* old-style: b010 jals with no arg setup */

u16 *func_0010a900(); /* old-style: every retail caller jals with no arg setup */

// FUN_001092F0
u16 func_001092f0(u32 arg0)
{
    return *(u16 *)(arg0 + 2);
}

// FUN_00109300
u16 func_00109300(s32 arg0)
{
    u16 *p = func_0010ace0(arg0);
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x3E);
    }
    return *(u16 *)((u8 *)p + 2);
}

// FUN_00109360
u16 func_00109360(void)
{
    return *(u16 *)((u8 *)func_0010a900() + 2);
}

// FUN_001093A0
u8 func_001093a0(s32 arg0)
{
    u16 *p = func_0010ace0(arg0);
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x5F);
    }
    return *(u8 *)((u8 *)p + 4);
}

// FUN_00109470
u16 func_00109470(s32 arg0)
{
    u16 *p = func_0010ace0(arg0);
    if (p == NULL) {
        func_0046d730(D_005E4318, 0xF1);
    }
    return *p;
}

/* measured: retail allocates arg0->$s1/arg2->$s6/id-as-temp with the m
   and n inits at their preheaders; mwcc b210 rotates the whole saved
   register map one slot (arg0->$s0/arg2->$s7) and spills arg1 to the
   stack instead of $fp. Tried id-local/inline/hybrid and init
   placements; nd 134-151. Saved-register rotation floor. */
// FUN_00109510
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109510);

// FUN_001097C0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_001097c0);

/* measured: same func_0023a620(0, value) move-vs-lhu order swap as
   func_001097c0; all six spellings give identical nd 5. Argument
   evaluation-order floor. */
// FUN_00109870
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109870);

// FUN_00109920
u8 func_00109920(u8 *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    return arg0[(u16)arg1 + 0x1C];
}

// FUN_00109980
s32 func_00109980(s32 arg0, s32 arg1)
{
    u16 *p = func_0010a900(arg0);
    u8 *base = (u8 *)p;
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    return base[(u16)arg1 + 0x1C];
}

// FUN_001099F0
u8 func_001099f0(u8 *arg0, s32 arg1)
{
    s16 a;
    s16 b;
    s8 c;
    s16 sum;
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    a = (s16)arg0[(u16)arg1 + 0x1C];
    b = (s8)func_00109d20(arg0, arg1);
    c = (s8)func_00109dd0(arg0, arg1);
    sum = (s16)(a + b + c);
    if (sum >= 0x63) {
        sum = 0x63;
    }
    return (u8)sum;
}

// FUN_00109AD0
u8 func_00109ad0(u8 *arg0, s32 arg1)
{
    s16 a;
    s16 b;
    s16 c;
    s8 d;
    s16 sum;

    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    a = (s16)arg0[(u16)arg1 + 0x1C];
    b = (s8)func_00109d20(arg0, arg1);
    c = (s8)func_00109dd0(arg0, arg1);
    d = (s8)func_00109e30(arg0, arg1);
    sum = (s16)(a + b + c + d);
    if (sum > 0x63) {
        sum = 0x63;
    } else if (sum < 0) {
        sum = 0;
    }
    return (u8)sum;
}

// FUN_00109BF0
u8 func_00109bf0(u8 *arg0, s32 arg1)
{
    s16 a;
    s16 b;
    s16 c;
    s8 d;
    s16 sum;
    u8 *p = (u8 *)func_0010a900(arg0);

    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x1DE);
    }
    a = (s16)p[(u16)arg1 + 0x1C];
    b = (s8)func_00109d20(p, arg1);
    c = (s8)func_00109dd0(p, arg1);
    d = (s8)func_00109e30(p, arg1);
    sum = (s16)(a + b + c + d);
    if (sum > 0x63) {
        sum = 0x63;
    } else if (sum < 0) {
        sum = 0;
    }
    return (u8)sum;
}

// FUN_00109D20
s8 func_00109d20(u8 *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x268);
    }
    return (s8)arg0[(u16)arg1 + 0x21];
}

// FUN_00109DD0
s8 func_00109dd0(u8 *arg0, s32 arg1)
{
    if ((arg1 & 0xFFFF) >= 5) {
        func_0046d730(D_005E4318, 0x299);
    }
    return (s8)arg0[(u16)arg1 + 0x26];
}

// FUN_00109E30
INCLUDE_ASM("asm/nonmatchings/datPersona", func_00109e30);

/* measured: retail sign-extends the lbu load (dsll32/dsra32 0x10) before
   adding the s8 arg2, and computes the addr addu index-first; mwcc b210
   sinks the load, elides its s16 extension (raw + ext8 + trunc) and emits
   base-first addu. Tried cast/local/array-index spellings, all nd 25-28.
   Load-sinking/CSE floor. */
// FUN_0010A780
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010a780);

/* measured: same lbu-ext16-extension elision and addu order as func_0010a780;
   all spellings nd 25+. Load-sinking/CSE floor. */
// FUN_0010A840
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010a840);

// FUN_0010A900
u16 *func_0010a900(s32 arg0)
{
    u16 *p;
    s32 v = arg0 & 0xFFFF;

    if (v == 1) {
        p = func_0010ace0(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            func_0046d730(D_005E4318, 0x3A5);
        }
        p = (u16 *)((u8 *)D_00796E50 + (v - 2) * 0x88 + 0x54);
    }
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x3A9);
    }
    return p;
}

// FUN_0010A9B0
s32 func_0010a9b0(s32 arg0)
{
    u16 *p;
    s32 v = arg0 & 0xFFFF;

    if (v != 1) {
        return 0;
    }
    if (v == 1) {
        p = func_0010ace0(D_00797F88[0]);
    } else {
        if (v >= 0xB) {
            func_0046d730(D_005E4318, 0x3A5);
        }
        p = (u16 *)((u8 *)D_00796E50 + (v - 2) * 0x88 + 0x54);
    }
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x3A9);
    }
    return (*(u16 *)p & 4) != 0;
}

// FUN_0010AA80
s32 func_0010aa80(s32 arg0)
{
    s32 count = func_0010b5b0() & 0xFFFF;
    s32 i = 0;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
            return (s16)i;
        }
    }
    return -1;
}

// FUN_0010AB30
s32 func_0010ab30(void)
{
    s32 i = 0;

    while ((u16)i < (u16)func_0010b5b0()) {
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
            return (s16)i;
        }
        i = (i + 1) & 0xFFFF;
    }
    return -1;
}

// FUN_0010ABD0
s32 func_0010abd0(s16 arg0)
{
    return (*(u16 *)((u8 *)D_00797F8C + (s32)arg0 * 0x30) & 1) != 0;
}

// FUN_0010AC10
u16 *func_0010ac10(s32 arg0)
{
    s32 count = func_0010b5b0() & 0xFFFF;
    s32 i = 0;
    s16 found;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;

    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 &&
            *(u16 *)(base + 0xBEC + off + 2) == id) {
            found = (s16)i;
            goto done;
        }
    }
    found = -1;
done:
    if (found == -1) {
        return NULL;
    }
    return func_0010ace0(found);
}

// FUN_0010ACE0
u16 *func_0010ace0(s16 arg0)
{
    s32 v = (s32)arg0;

    if (v < 0 || v >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x3FE);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + v * 0x30) & 1) == 0) {
        return NULL;
    }
    return (u16 *)((u8 *)D_007973A0 + v * 0x30 + 0xBEC);
}

// FUN_0010AD80
s32 func_0010ad80(s32 arg0)
{
    s32 count = func_0010b5b0() & 0xFFFF;
    s32 i = 0;
    s32 arg;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
            arg = (s16)i;
            goto done;
        }
    }
    arg = -1;
done:
    return func_0010ae30(arg);
}

/* measured: retail keeps raw arg0 in $s1 and the (s16)arg0 idx in $s0;
   mwcc b210 allocates arg0 to $s0 and idx to $s1, rotating every later
   register. Tried declaration orders, i-variable forms, inline (s16)arg0,
   base-local vs inline; nd 77-107. Saved-register rotation floor. */
// FUN_0010AE30
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010ae30);

// FUN_0010B010
u8 *func_0010b010(void)
{
    u8 *p = func_0010b060();
    if (p == NULL) {
        func_0046d730(D_005E4318, 0x43A);
    }
    return p;
}

// FUN_0010B060
u8 *func_0010b060(u8 *arg0)
{
    s32 i = 0;
    s16 found;
    u8 *entry;

    while ((u16)i < (u16)func_0010b5b0()) {
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
            found = (s16)i;
            goto done;
        }
        i = (i + 1) & 0xFFFF;
    }
    found = -1;
done:
    if (found == -1) {
        return NULL;
    }
    entry = (u8 *)D_007973A0 + found * 0x30 + 0xBEC;
    func_0010cad0(entry, arg0);
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) &= 0xC;
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) |= 1;
    func_0010fde0(entry);
    return entry;
}

// FUN_0010B190
s32 func_0010b190(u8 *arg0)
{
    s32 i;
    s16 found;
    u8 *entry;

    if (arg0 == NULL) {
        func_0046d730(D_005E4318, 0x464);
    }
    if (*(u16 *)(arg0 + 2) == 0 || *(u16 *)(arg0 + 2) >= 0x100) {
        func_0046d730(D_005E4318, 0x465);
    }
    i = 0;
    while ((u16)i < (u16)func_0010b5b0()) {
        if ((*(u16 *)((u8 *)D_007973A0 + (i & 0xFFFF) * 0x30 + 0xBEC) & 1) == 0) {
            found = (s16)i;
            goto done;
        }
        i = (i + 1) & 0xFFFF;
    }
    found = -1;
done:
    if (found == -1) {
        return 0;
    }
    entry = (u8 *)D_007973A0 + found * 0x30 + 0xBEC;
    func_0043f810(entry, arg0, 0x30);
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) &= 0xC;
    *(u16 *)((u8 *)D_00797F8C + found * 0x30) |= 1;
    func_0010fde0(entry);
    return 1;
}

// FUN_0010B300
s32 func_0010b300(s32 arg0)
{
    s32 count = func_0010b5b0() & 0xFFFF;
    s32 i = 0;
    s32 arg;
    s32 id = (s16)arg0;
    u8 *base = D_007973A0;
    s32 off;
    for (; (u16)i < count; i = (u16)(i + 1)) {
        off = (i & 0xFFFF) * 0x30;
        if ((*(u16 *)(base + 0xBEC + off) & 1) != 0 && *(u16 *)(base + 0xBEC + off + 2) == id) {
            arg = (s16)i;
            goto done;
        }
    }
    arg = -1;
done:
    return func_0010b3b0(arg);
}

// FUN_0010B3B0
s32 func_0010b3b0(s32 arg0)
{
    s32 idx = (s16)arg0;
    if (idx < 0 || idx >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x47E);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + idx * 0x30) & 1) == 0) {
        return 0;
    }
    D_00797F88[0] = (s16)arg0;
    return 1;
}

// FUN_0010B460
u16 func_0010b460(void)
{
    s32 v = D_00797F88[0];
    s32 off;

    if (v < 0 || v >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x491);
    }
    off = v * 0x30;
    if ((*(u16 *)((u8 *)D_00797F8C + off) & 1) == 0) {
        func_0046d730(D_005E4318, 0x492);
    }
    return *(u16 *)((u8 *)D_00797F8E + off);
}

// FUN_0010B510
s32 func_0010b510(void)
{
    s32 v = D_00797F88[0];

    if (v < 0 || v >= (u16)func_0010b5b0()) {
        func_0046d730(D_005E4318, 0x49C);
    }
    if ((*(u16 *)((u8 *)D_00797F8C + v * 0x30) & 1) == 0) {
        func_0046d730(D_005E4318, 0x49D);
    }
    return v;
}

// FUN_0010B5B0
s32 func_0010b5b0(void)
{
    s32 v = D_0079B40C[0];
    if (v & 4) {
        return 0xC;
    }
    if (v & 2) {
        return 0xA;
    }
    if (v & 1) {
        return 8;
    }
    return 6;
}

/* measured: mwcc b210 folds a register OR-chain (flags|1, |2, |4) into a
   single ori when any def is single-use (case 2 needs an f2 intermediate,
   case 3 always folds to |6; AND-chains do not fold, OR-chains do). Tried
   intermediates, plain assignments, single expressions; nd 17-46. OR-chain
   constant-folding floor. */
// FUN_0010B610
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b610);
/* measured: retail loads the count constants with daddiu into $v1 (reusing
   the dead test register) and hoists (u16)count to a preheader mask; mwcc
   b210 allocates count to $a2 with addiu and re-masks inside the loop. Tried
   s64/u16/s32 count, declaration orders, base-assignment placements;
   nd 33-51. Saved-register/temp allocation floor. */
// FUN_0010B6F0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b6f0);
// FUN_0010B7C0
void func_0010b7c0(void)
{
    func_0043f9c8((void *)D_00797F8C, 0, 0x240);
}

/* measured: retail loads the count-select constants with daddiu (the
   b5b0-return form) inside the ||; mwcc b210 emits addiu for ternary/local
   forms and hoists the D_0079B40C load. Tried ternary/u16/s64 arms and
   assignment forms; nd 104-106. Same daddiu-local floor as func_0010b6f0. */
// FUN_0010B7F0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b7f0);

/* measured: retail loads the count-select ternary arms with daddiu into
   $v0 and hoists (u16)count/base to the search-loop preheader; mwcc b210
   emits addiu into $a1 and re-masks/re-bases inside the loop (same
   daddiu-local floor as func_0010b6f0/0010b7f0). nd 165-215. */
// FUN_0010B9A0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010b9a0);

// FUN_0010BD90
void func_0010bd90(s16 arg0)
{
    s32 v = (s32)arg0;

    if (v == 1) {
        D_00797F88[0] = -1;
        func_0043f9c8((void *)D_00797F8C, 0, 0x240);
    } else {
        func_0043f9c8((void *)((u8 *)D_00796E50 + (v - 2) * 0x88 + 0x54), 0, 0x30);
    }
}

// FUN_0010BE20
s32 func_0010be20(u8 *arg0)
{
    u16 v = *(u16 *)(arg0 + 2);

    if (v >= 0xC0 && v < 0xD8) {
        return 1;
    }
    return 0;
}

// FUN_0010BE60
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010be60);

// FUN_0010C5A0
void func_0010c5a0(u8 *arg0, u8 *arg1)
{
    s32 i;
    s32 j;
    s32 k;

    if (*(u16 *)(arg0 + 2) == 0 || *(u16 *)(arg0 + 2) >= 0x100) {
        func_0046d730(D_005E4318, 0x62E);
    }
    *(u8 *)(arg0 + 4) += *(u8 *)(arg1 + 0);
    i = 0;
    while ((u16)i < 5) {
        *(u8 *)(arg0 + 0x1C + (u16)i) += *(u8 *)(arg1 + 0x82 + (u16)i);
        i = (i + 1) & 0xFFFF;
    }
    j = 0;
    while ((u16)j < 0x20) {
        if (*(u16 *)(arg1 + (j & 0xFFFF) * 2 + 0x42) != 0) {
            func_0010ccc0(arg0, *(u16 *)(arg1 + (j & 0xFFFF) * 2 + 0x42));
        }
        j = (j + 1) & 0xFFFF;
    }
    k = 0;
    while ((u16)k < 0x20) {
        if (*(u16 *)(arg1 + (k & 0xFFFF) * 2 + 0x2) != 0) {
            func_0010cc20(arg0, *(u16 *)(arg1 + (k & 0xFFFF) * 2 + 0x2));
        }
        k = (k + 1) & 0xFFFF;
    }
}

/* measured: retail allocates the f32 locals to $f4/$f3 and evaluates the
   madd/msub accumulator chain msub-part-first; mwcc b210 picks $f1/$f4 and
   hoists the C2*f4^3 chain before the msub. Tried term orders, t3 splits,
   parens, decl orders; nd 74-128. FP register/scheduling floor. */
// FUN_0010C750
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010c750);

// FUN_0010C980
void func_0010c980(u8 *arg0, s32 arg1)
{
    if (arg1 < 0) {
        func_0046d730(D_005E4318, 0x689);
    }
    *(s32 *)(arg0 + 8) += arg1;
}

/* measured: retail hoists the beq's 8-constant to the preheader and
   allocates i/j/addr one register higher ($a3/$a2/$a1); mwcc b210 keeps
   8 at the use site and rotates i/j/addr down. Tried decl orders and
   for-loop forms; nd 31-49. Temp-register rotation floor. */
// FUN_0010C9E0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010c9e0);

/* measured: retail loads the c750 second argument (lbu) before the arg0
   move; mwcc b210 sinks the load after the move. Tried v3 locals and
   inline forms; nd 2. Load-sinking floor. */
// FUN_0010CAD0
INCLUDE_ASM("asm/nonmatchings/datPersona", func_0010cad0);

// FUN_0010CC20
s32 func_0010cc20(u8 *arg0, u32 arg1)
{
    s32 i;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x6E0);
    }
    i = 0;
    while (i < 8) {
        if (*(u16 *)(arg0 + i * 2 + 0xC) == 0) {
            *(u16 *)(arg0 + i * 2 + 0xC) = (u16)arg1;
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_0010CCC0
s32 func_0010ccc0(u8 *arg0, u32 arg1)
{
    s32 i;
    s32 key;
    u16 v2;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x6EE);
    }
    i = 0;
    key = arg1 & 0xFFFF;
    while (i < 8) {
        v2 = *(u16 *)(arg0 + i * 2 + 0xC);
        if (v2 == key) {
            *(u16 *)(arg0 + i * 2 + 0xC) = 0;
            func_0010c9e0(arg0);
            return 1;
        }
        i++;
    }
    return 0;
}

// FUN_0010CD70
void func_0010cd70(u8 *arg0, s32 arg1, u32 arg2)
{
    if (arg0 == NULL || (s16)arg1 == 0 || (arg2 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x6FE);
    }
    {
        s32 r = func_0010ce10(arg0, (u16)arg1);
        if (r != -1) {
            s32 off = r * 2;
            *(u16 *)(off + (s32)arg0 + 0xC) = (u16)arg2;
        }
    }
}

// FUN_0010CE10
s32 func_0010ce10(u8 *arg0, u32 arg1)
{
    s32 i;
    u32 key;

    if (arg0 == NULL || (arg1 & 0xFFFF) == 0) {
        func_0046d730(D_005E4318, 0x70A);
    }
    i = 0;
    key = arg1 & 0xFFFF;
    while (i < 8) {
        u16 v = *(u16 *)(arg0 + i * 2 + 0xC);
        if (v == key) {
            return i;
        }
        i++;
    }
    return -1;
}

// FUN_0010CEB0
s32 func_0010ceb0(u8 *arg0)
{
    s32 count = 0;
    s32 i;

    if (arg0 == NULL) {
        func_0046d730(D_005E4318, 0x717);
    }
    i = 0;
    while (i < 8) {
        if (*(u16 *)(arg0 + i * 2 + 0xC) != 0) {
            count++;
        }
        i++;
    }
    return count;
}

// FUN_0010CF40
u16 func_0010cf40(u8 *arg0, s16 arg1)
{
    s32 index = arg1;
    s32 off;

    if (index >= 8) {
        func_0046d730(D_005E4318, 0x723);
    }
    off = index * 2;
    return *(u16 *)(off + (s32)arg0 + 0xC);
}
// FUN_0010CFA0
s32 func_0010cfa0(u8 *arg0, s32 arg1, u8 *arg2)
{
    s32 i;
    s32 i2;
    s32 v;
    s32 *sp2;
    s32 *dp2;
    s32 t0;
    s32 t1;
    s32 n;
    u8 *src;
    u8 *dst;
    u8 entry[0x30];
    u8 buf[0x90];

    if (arg0 == NULL) {
        func_0046d730(D_005E4318, 0x7AF);
    }
    if (arg2 == NULL) {
        func_0046d730(D_005E4318, 0x7B0);
    }
    v = *(s32 *)(arg2 + 8);
    func_0010cad0(entry, arg1);
    func_0010be60(entry, buf, v);
    func_0010c5a0(entry, buf);
    if (v < 0) {
        func_0046d730(D_005E4318, 0x689);
    }
    *(s32 *)(entry + 8) += v;
    src = arg2 + 0xC;
    dst = entry + 0xC;
    for (i = 0; i < 8; i++) {
        *(u16 *)(dst + i * 2) = *(u16 *)(src + i * 2);
    }
    if (entry == NULL || arg2 == NULL) {
        func_0046d730(D_005E4318, 0x778);
    }
    for (i2 = 0; i2 < 5; i2++) {
        *(u8 *)(entry + 0x21 + i2) = *(u8 *)(arg2 + 0x21 + i2);
        *(u8 *)(entry + 0x26 + i2) = *(u8 *)(arg2 + 0x26 + i2);
    }
    sp2 = (s32 *)entry;
    dp2 = (s32 *)arg0;
    n = 6;
    do {
        t0 = sp2[0];
        t1 = sp2[1];
        sp2 += 2;
        n--;
        dp2[0] = t0;
        dp2[1] = t1;
        dp2 += 2;
    } while (n > 0);
    return 1;
}

// FUN_0010D150
void func_0010d150(u8 *arg0)
{
    s32 i;
    s32 j;
    s32 b;
    u16 n;
    u8 *entry;
    u16 id = *(u16 *)(arg0 + 2);

    if (id >= 0xC0 && id < 0xD8) {
        b = 1;
    } else {
        b = 0;
    }
    if (b) {
        entry = (u8 *)iGpffffb3e4 + (id - 0xC0) * 0x26E + 4;
        for (i = 0; i < 0x20; i++) {
            if (*(u8 *)(entry + i * 4) == 0 && *(s8 *)(entry + i * 4 + 1) == 1) {
                n = *(u16 *)(entry + i * 4 + 2);
                if (arg0 == NULL || (n & 0xFFFF) == 0) {
                    func_0046d730(D_005E4318, 0x6E0);
                }
                for (j = 0; j < 8; j++) {
                    if (*(u16 *)(arg0 + j * 2 + 0xC) == 0) {
                        *(u16 *)(arg0 + j * 2 + 0xC) = n;
                        break;
                    }
                }
            }
        }
    } else {
        entry = (u8 *)iGpffffb3dc + (id & 0xFFFF) * 0x46 + 6;
        for (i = 0; i < 0x10; i++) {
            if (*(u8 *)(entry + i * 4) == 0 && *(s8 *)(entry + i * 4 + 1) == 1) {
                n = *(u16 *)(entry + i * 4 + 2);
                if (arg0 == NULL || (n & 0xFFFF) == 0) {
                    func_0046d730(D_005E4318, 0x6E0);
                }
                for (j = 0; j < 8; j++) {
                    if (*(u16 *)(arg0 + j * 2 + 0xC) == 0) {
                        *(u16 *)(arg0 + j * 2 + 0xC) = n;
                        break;
                    }
                }
            }
        }
    }
}

