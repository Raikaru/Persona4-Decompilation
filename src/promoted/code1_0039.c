#include "include_asm.h"
#include "type.h"

extern s32 func_003df360(s32 arg0, s32 *arg1, s32 arg2);
/* gp - 0x4A20 = 0x007690f0 - 0x4a20 = 0x007646d0 */
extern s32 iGpffffb5e0;
extern void func_0038fb10(s32 arg0);
extern s32 func_00399b10(s32 arg0);
extern s32 func_00399b80(s32 arg0);
extern void func_0039a8a0(s32 arg0);
/* gp - 0x4A1C = 0x007690f0 - 0x4A1C = 0x007646D4 */
extern s32 iGpffffb5e4;
/* gp - 0x4A18 = 0x007690f0 - 0x4A18 = 0x007646D8 */
extern s32 iGpffffb5e8;
u8 *func_0039aab0(u8 *arg0);

extern s32 D_007246B0;
extern s32 D_007246B4;
extern u8 D_008872E0[];

s32 func_00399530(void);

extern s32 D_007246EC;

s32 func_0039b6e0(s32 arg0);

extern s32 D_00884ACC[];
extern u8 *D_007646D0;
void *func_0039bb70(void *list, s32 key);


// measured: schedule on hoists the return-value move to the top,
// sinks the counter store, and fills the jr delay slot.
#pragma schedule on
// FUN_003901E0
s32 func_003901e0(s32 arg0)
{
    D_007246B0 += 1;
    *(s32 *)(D_008872E0 + D_007246B4) = 0;
    return arg0;
}
#pragma schedule off


// measured: schedule on hoists the return-value move before the
// counter arithmetic and fills the jr delay slot with the final sw.

#pragma schedule on
// FUN_00390210
s32 func_00390210(s32 arg0)
{
    D_007246B0 -= 1;
    return arg0;
}
#pragma schedule off


// measured: retail computes count*0x24 as lw/addiu/jr + EE 3-op mult in the
// return delay slot (16B). b210 strength-reduces every x*36 form to an
// sll/addu/sll chain -- probed ~30 shapes across O0/O1/O2/O3, schedule
// on/off, opt_rebuildconditionals, u8/u16/u32/s32/s64 casts, computed
// operands, address feeds, inlined getters, locals and consts -- so the
// mult cannot be reproduced and the shift chain cannot fit the 16B window.
// Compiler-version codegen floor. NONMATCHING

/* measured: nd 6 of 19 words - 16 are byte-exact and the whole residual is the
   last two: retail folds `addiu $sp, $sp, 0x30` into the jr $ra delay slot,
   b210 emits addiu then jr then nop. Not a general floor - 12 matched
   first-party functions save registers AND fold the teardown, four of them in
   this file (func_0039aab0, func_0039b510/540/570) - but none of the levers
   that produce it there work here: optimization_level 3 (which is what
   func_0039aab0 needs) and 4 both shrink the object to 72 bytes and leave the
   swap, schedule on (which is what func_003a0260 needs) leaves it, and three
   source shapes - early return, cached handle, uncached double load - all give
   the same 3 words. The difference from the matching examples is that this one
   holds arg0 in $s1 across a call inside a conditional and then returns it. */
// FUN_00390230
#ifdef NON_MATCHING
s32 func_00390230(s32 arg0, s32 arg1)
{
    s32 *slot;
    s32 handle;

    slot = (s32 *)(arg0 + arg1);
    handle = *slot;
    if (handle != 0) {
        func_0038fb10(handle);
        *slot = 0;
    }

    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00390230);
#endif

// FUN_003902D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003902d0);

/* measured: b210's O2 strength-reduces this constant multiply; O1 preserves
   the retail MMI multiply. schedule on places it in the jr delay slot, and
   the inline helper presents the multiplier first for retail operand order. */
#pragma optimization_level 1
#pragma schedule on
static inline s32 p4_mul_003963b0(s32 left, s32 right)
{
    return left * right;
}
// FUN_003963B0
s32 func_003963b0(u8 *arg0)
{
    s32 multiplier;
    s32 value;

    value = *(s32 *)(arg0 + 4);
    multiplier = 0x24;
    return p4_mul_003963b0(multiplier, value);
}
/* measured: closes the schedule-on bracket for the multiply body. */
#pragma schedule off
/* measured: closes the O1 bracket at the O2 baseline. */
#pragma optimization_level 2


// measured: optimization_level 3 is load-bearing -- b210 at -O2 always
// emits jal + frame for a trailing call; retail is a tail j.

// FUN_00396E80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396e80);

// FUN_003982E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003982e0);

// FUN_00398540
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398540);

/* measured: retail lays the three exits out of line in the order
   [return arg0][return 0][call + jump back], which the explicit gotos below
   reproduce; the plain nested-if spelling merges them (nd 58). schedule on
   fills the jal and b delay slots (without it nd 84, obj 128), and
   no_branch_likely on stops b210 turning both tests into beql/bnel
   (nd 35 -> 0). Note the first argument: retail passes arg0 to
   func_003df360 unchanged in $a0, which the m2c draft dropped. */
// FUN_003992B0
#pragma schedule on
#pragma no_branch_likely on
s32 func_003992b0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;

    if (func_003df360(arg0, &sp3C, 4) == 0) {
        goto ret0;
    }
    if (sp3C != 0) {
        goto docall;
    }
retarg:
    return arg0;
ret0:
    return 0;
docall:
    func_00399b10(arg2);
    goto retarg;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: retail lays the three exits out of line in the order
   [return arg0][return 0][call + jump back], which the explicit gotos below
   reproduce; the plain nested-if spelling merges them (nd 58). schedule on
   fills the jal and b delay slots (without it nd 84, obj 128), and
   no_branch_likely on stops b210 turning both tests into beql/bnel
   (nd 35 -> 0). Note the first argument: retail passes arg0 to
   func_003df360 unchanged in $a0, which the m2c draft dropped. */
// FUN_003993E0
#pragma schedule on
#pragma no_branch_likely on
s32 func_003993e0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;

    if (func_003df360(arg0, &sp3C, 4) == 0) {
        goto ret0;
    }
    if (sp3C != 0) {
        goto docall;
    }
retarg:
    return arg0;
ret0:
    return 0;
docall:
    func_00399b80(arg2);
    goto retarg;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: nd 43 against retail's 112-byte window. The control flow is right -
   set the flag and return the object when the initialiser succeeds, otherwise
   return zero - but retail places the already-initialised case out of line
   while b210 inlines it, and the two returns are coloured the other way round.
   Committed at nd 43. */
// FUN_00399B10 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
s32 func_00399b10(s32 arg0)
{
    s32 *p = (s32 *)(arg0 + iGpffffb5e4);
    if (*p == 0) {
        if (func_0039aab0((u8 *)arg0)) {
            *p = 1;
            return arg0;
        }
        return 0;
    }
    return arg0;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399b10);
#endif

// FUN_00399B80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399b80);

/* measured: retail enters the slot loop directly (proves i=0<2, no pre-test)
   and hoists the compare constant (addiu $v1,$zero,1) into the preheader;
   b210 materialises the constant in the body and emits a `b` to the bottom
   test, plus prologue scheduling order and epilogue delay-slot ordering.
   Probed: do/while (nd 55), schedule on (nd 64), opt_loop_invariants (nd 54),
   optimization O1 (nd 61) / O3 (nd 56), no_branch_likely. Same family floor as
   the parked a090/a340/a3a0/a400/a630 (nd 36-46). Committed at nd 44. */
// FUN_00399FD0 NONMATCHING
#ifdef NON_MATCHING
s32 func_00399fd0(s32 arg0, s32 arg1)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            goto found;
        }
    }
    e = NULL;
found:
    *(s32 *)(e + 0) = arg1;
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399fd0);
#endif

/* This is the head of the 0039A0xx-0039A8xx slot-search family (about
   fifteen functions): every one of them loads a 64-byte-strided table through
   the gp-relative pointer at gp-0x4A20, scans at most two entries for a
   given type code at offset 0x20, falls back to a NULL slot, and then does
   one small thing to the slot. The addressing, the `(i + 1) & 0xFF` counter,
   the `slti 2` bound and the whole prologue are byte-exact here, so this body
   is the template for the rest of the family.
   measured: residual nd 46, obj 84 in a 96-byte window. Retail reaches the
   store block from the found path through an out-of-line `b` and fills BOTH
   that branch's delay slot and the fallthrough with a duplicated
   `neg.s $f0,$f12`; b210 computes the negation once and lets the found path
   fall through, which is exactly the two missing words. It also materialises
   the comparison constant inside the loop where retail hoists it into the
   preheader. Measured identical at nd 46: a hoisted `one` local, the
   inverted-test form, an explicit goto to the store label, a single-case
   switch on the type code, and a do/while bottom test; dropping
   no_branch_likely costs three more words and dropping schedule costs
   twenty-three. Committed at nd 46. */
// FUN_0039A030 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
s32 func_0039a030(s32 arg0, f32 fparg0) {
    u8 *base;
    u8 *slot;
    s32 i;

    base = *(u8 **)(arg0 + iGpffffb5e0);
    i = 0;
loop:
    slot = base + ((i & 0xFF) << 6);
    if (*(s32 *)(slot + 0x20) == 1) {
        goto store;
    }
    i = (i + 1) & 0xFF;
    if (i < 2) {
        goto loop;
    }
    slot = NULL;
store:
    *(f32 *)(slot + 0xC) = -fparg0;
    return arg0;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a030);
#endif

/* measured: nd 17 of 24 words, and the first thing to know is that this
   function compiles at -O3, not -O2: the `#pragma optimization_level 3` far
   above (opened for an unrelated function) is still in scope here, and every
   probe made against it is measuring the wrong compiler. Scoping -O2 back over
   the body takes nd 38 -> 36 on its own and is why the shape below reads
   straight. Five functions in this file share the shape and differ only in the
   returned field offset and the compared constant, so the residual is worth
   five. What is left: retail hoists the compared constant into the preheader
   (addiu $v1,$zero,1 before the loop) and enters the body without a pre-test,
   knowing i=0 < 2 statically; b210 materialises the constant inside the body
   and emits a `b` to the bottom test. opt_loop_invariants makes it worse
   (nd 43), and the do/while spelling that removes the pre-test costs more than
   it saves (nd 59 at -O2, obj 80 of 96). */
// FUN_0039A090
#ifdef NON_MATCHING
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2
u32 func_0039a090(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            goto found;
        }
    }
    e = NULL;
found:
    return *(u32 *)(e + 0);
}
/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a090);
#endif

/* measured: read-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant; b210 emits a pre-test `b`, materialises the constant in the body,
   and schedules the prologue differently. Probed: do/while, schedule on,
   opt_loop_invariants, O1/O3, no_branch_likely; none beat the for+goto form.
   Committed at nd 42. */
// FUN_0039A0F0 NONMATCHING
#ifdef NON_MATCHING
f32 func_0039a0f0(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            goto found;
        }
    }
    e = NULL;
found:
    return -*(f32 *)(e + 0xC);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a0f0);
#endif

/* measured: store-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant (addiu $v1,$zero,2); b210 emits a pre-test `b`, materialises the
   constant in the body, and schedules the prologue/epilogue differently.
   Probed: do/while, schedule on, opt_loop_invariants, O1/O3,
   no_branch_likely; none beat the for+goto form. Committed at nd 44. */
// FUN_0039A200 NONMATCHING
#ifdef NON_MATCHING
s32 func_0039a200(s32 arg0, s32 arg1)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            goto found;
        }
    }
    e = NULL;
found:
    *(s32 *)(e + 0) = arg1;
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a200);
#endif

// FUN_0039A260
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a260);

/* measured: store-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant (addiu $v1,$zero,2); b210 emits a pre-test `b`, materialises the
   constant in the body, and schedules the prologue/epilogue differently.
   Probed: do/while, schedule on, opt_loop_invariants, O1/O3,
   no_branch_likely; none beat the for+goto form. Committed at nd 44. */
// FUN_0039A2E0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0039a2e0(s32 arg0, f32 fparg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            goto found;
        }
    }
    e = NULL;
found:
    *(f32 *)(e + 0x8) = fparg0;
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a2e0);
#endif

/* measured: same shape as func_0039a090; see that note. nd 36. */
// FUN_0039A340
#ifdef NON_MATCHING
#pragma optimization_level 2
u32 func_0039a340(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            goto found;
        }
    }
    e = NULL;
found:
    return *(u32 *)(e + 4);
}
/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a340);
#endif

/* measured: same shape as func_0039a090; see that note. nd 36. */
// FUN_0039A3A0
#ifdef NON_MATCHING
#pragma optimization_level 2
u32 func_0039a3a0(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            goto found;
        }
    }
    e = NULL;
found:
    return *(u32 *)(e + 0);
}
/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a3a0);
#endif

/* measured: same shape as func_0039a090; see that note. nd 36. */
// FUN_0039A400
#ifdef NON_MATCHING
#pragma optimization_level 2
u32 func_0039a400(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            goto found;
        }
    }
    e = NULL;
found:
    return *(u32 *)(e + 12);
}
/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a400);
#endif

/* measured: read-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant (addiu $v1,$zero,2); b210 emits a pre-test `b`, materialises the
   constant in the body, and schedules the prologue differently. This is the
   cleanest of the six (epilogue jr/nop already matches); residual is purely
   the pre-test + constant hoist + register allocation. Probed: do/while,
   schedule on, opt_loop_invariants, O1/O3, no_branch_likely. Committed at
   nd 36. */
// FUN_0039A460 NONMATCHING
#ifdef NON_MATCHING
f32 func_0039a460(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            goto found;
        }
    }
    e = NULL;
found:
    return *(f32 *)(e + 0x8);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a460);
#endif

/* measured: same shape as func_0039a090; see that note. nd 36. */
// FUN_0039A630
#ifdef NON_MATCHING
#pragma optimization_level 2
u32 func_0039a630(s32 arg0)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 4) {
            goto found;
        }
    }
    e = NULL;
found:
    return *(u32 *)(e + 0);
}
/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a630);
#endif

/* measured: store-through-pointer variant of the 0039A0xx slot-search family,
   same floor as func_00399fd0 - retail enters the loop directly (i=0<2, no
   pre-test) and hoists the compare constant (addiu $v1,$zero,4); b210 emits a
   pre-test `b`, materialises the constant in the body, and schedules the
   prologue/epilogue differently. Probed base for+goto form only. Committed at
   nd 56. */
// FUN_0039A690 NONMATCHING
#ifdef NON_MATCHING
s32 func_0039a690(s32 arg0, s32 *arg1, s32 *arg2)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 4) {
            goto found;
        }
    }
    e = NULL;
found:
    *arg1 = *(s32 *)(e + 0x4);
    *arg2 = *(s32 *)(e + 0x8);
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a690);
#endif

/* measured: store-variant of the 0039A0xx slot-search family with a second
   store (arg2 at 0x4) in the shared epilogue, same floor as func_00399fd0 -
   retail enters the loop directly (i=0<2, no pre-test) and hoists the compare
   constant (addiu $v1,$zero,5); b210 emits a pre-test `b`, materialises the
   constant in the body, and the extra store adds register pressure to the
   allocation. Probed: do/while, schedule on, opt_loop_invariants, O1/O3,
   no_branch_likely; none beat the for+goto form. Committed at nd 49. */
// FUN_0039A700 NONMATCHING
#ifdef NON_MATCHING
s32 func_0039a700(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 5) {
            goto found;
        }
    }
    e = NULL;
found:
    *(s32 *)(e + 0) = arg1;
    *(s32 *)(e + 4) = arg2;
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a700);
#endif

/* measured: conditional-store variant of the 0039A0xx slot-search family
   (the found path has an empty body - retail `b found` with a nop delay slot -
   then stores through non-NULL arg1/arg2 pointers), same floor as
   func_00399fd0 - retail enters the loop directly (i=0<2, no pre-test) and
   hoists the compare constant (addiu $v1,$zero,5); b210 emits a pre-test `b`
   and materialises the constant in the body. Probed base for+goto form only.
   Committed at nd 46. */
// FUN_0039A760 NONMATCHING
#ifdef NON_MATCHING
s32 func_0039a760(s32 arg0, s32 *arg1, s32 *arg2)
{
    u8 *p;
    u8 *e;
    u8 i;

    p = *(u8 **)(arg0 + D_007646D0);
    for (i = 0; i < 2; i++) {
        e = p + i * 0x40;
        if (*(s32 *)(e + 0x20) == 5) {
            goto found;
        }
    }
    e = NULL;
found:
    if (arg1) {
        *arg1 = *(s32 *)(e + 0x0);
    }
    if (arg2) {
        *arg2 = *(s32 *)(e + 0x4);
    }
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a760);
#endif

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039A7E0
s32 func_0039a7e0(void)
{
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

// FUN_0039A8A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a8a0);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AA30
s32 func_0039aa30(void)
{
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AA40
s32 func_0039aa40(void)
{
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: schedule on plus no_branch_likely on - schedule fills retail's
   delay slots and b210 then wants beql/bnel where retail has plain branches. */
// FUN_0039AA50
#pragma schedule on
#pragma no_branch_likely on
u8 *func_0039aa50(u8 *arg0) {
    s32 var_2;

    if (*(s32 *)((u8 *)(func_003c9c20()) + 8) & 0x80) {
        var_2 = func_0039b6e0(0x11010);
    } else {
        var_2 = func_0039b6e0(0x1100F);
    }
    *(s32 *)((u8 *)(arg0) + 0x7C) = var_2;
    return (u8 *)(arg0);
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AAB0
u8 *func_0039aab0(u8 *arg0) {
    s32 var_2;

    if (*(s32 *)((u8 *)(*(u8 **)(arg0 + 0x18)) + 8) & 0x80) {
        var_2 = func_0039b6e0(0x1100E);
    } else {
        var_2 = func_0039b6e0(0x1100D);
    }
    *(s32 *)(arg0 + 0x6C) = var_2;
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AB10
void func_0039ab10(void)
{
    func_00399530();
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2
/* measured: optimization_level 3 is load-bearing for all four functions in
   this scope, not just func_0039a7e0 -- at -O2 the three `return 1` leaves
   emit addiu; jr; nop against an 8-byte window and func_0039ab10 gets a
   frame plus jal where retail tail-jumps. Closing the scope here; -O2 is
/* At -O2 the three `return 1` leaves emit addiu; jr; nop against an 8-byte
   window, and func_0039ab10 gets a frame plus jal where retail tail-jumps.
   measured: optimization_level 3 is load-bearing for all four functions in
   this scope; closing it here, -O2 is the documented baseline. */


// measured: schedule on hoists the return-value move before the
// counter arithmetic and fills the jr delay slot with the final sw.

#pragma schedule on
// FUN_0039AC20
s32 func_0039ac20(s32 arg0)
{
    D_007246EC += 1;
    return arg0;
}
#pragma schedule off


// measured: schedule on hoists the return-value move before the
// counter arithmetic and fills the jr delay slot with the final sw.

#pragma schedule on
// FUN_0039AC40
s32 func_0039ac40(s32 arg0)
{
    D_007246EC -= 1;
    return arg0;
}
#pragma schedule off


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.

// FUN_0039AE30
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039ae30);

// FUN_0039B450
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b450);

// FUN_0039B4B0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b4b0);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039B510
s32 func_0039b510(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 8) = func_0039b6e0(arg3);
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039B540
s32 func_0039b540(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x6C) = func_0039b6e0(arg3);
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039B570
s32 func_0039b570(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x7C) = func_0039b6e0(arg3);
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: optimization_level 3 gave the right prologue, absolute
// lui/addiu addressing for &D_00884ACC (array decl), and arg order.
// Residual: retail keeps the if-body as beqz + nop + b .Lend with the lw
// in the b's delay slot and the return-0 block out-of-line (14 instr);
// every if/else/switch/goto/ternary form at O2/O2+schedule/O3 compiles the
// same selection to beql $v0,$zero + move-in-delay + inline lw (12 instr,
// nd 17). Scheduler branch-shape floor. NONMATCHING
// (pragma dropped in whole-file merge: function is INCLUDE_ASM fallback, not load-bearing)

// FUN_0039B680
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b680);

// FUN_0039B6E0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0039b6e0(s32 arg0)
{
    u8 *temp_2;

    temp_2 = (u8 *)(func_0039bb70(D_00884ACC, arg0));
    if (temp_2 != NULL)
    {
        return (s32)(*(s32 *)(temp_2 + 0x10));
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b6e0);
#endif
