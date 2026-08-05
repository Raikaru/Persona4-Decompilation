#include "include_asm.h"
#include "type.h"

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

// FUN_00390230
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00390230);

// FUN_003902D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003902d0);

// FUN_003963B0 NONMATCHING
#ifdef NON_MATCHING
s32 func_003963b0(u8 *arg0)
{
    return 0x24 * *(s32 *)(arg0 + 4);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003963b0);
#endif


// measured: optimization_level 3 is load-bearing -- b210 at -O2 always
// emits jal + frame for a trailing call; retail is a tail j.
#pragma optimization_level 3

// FUN_00396E80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396e80);

// FUN_003982E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003982e0);

// FUN_00398540
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398540);

// FUN_003992B0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003992b0);

// FUN_003993E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003993e0);

// FUN_00399B10
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399b10);

// FUN_00399B80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399b80);

// FUN_00399FD0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399fd0);

// FUN_0039A030
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a030);

/* measured: nd 17 of 24 words, and the first thing to know is that this
   function compiles at -O3, not -O2: the `#pragma optimization_level 3` far
   above (opened for an unrelated function) is still in scope here, and every
   probe made against it is measuring the wrong compiler. Scoping -O2 back over
   the body takes nd 38 -> 17 on its own and is why the shape below reads
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
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a090);
#endif

// FUN_0039A0F0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a0f0);

// FUN_0039A200
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a200);

// FUN_0039A260
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a260);

// FUN_0039A2E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a2e0);

/* measured: same shape as func_0039a090; see that note. nd 17. */
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
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a340);
#endif

/* measured: same shape as func_0039a090; see that note. nd 17. */
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
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a3a0);
#endif

/* measured: same shape as func_0039a090; see that note. nd 17. */
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
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a400);
#endif

// FUN_0039A460
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a460);

/* measured: same shape as func_0039a090; see that note. nd 17. */
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
#pragma optimization_level 3
#else
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a630);
#endif

// FUN_0039A690
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a690);

// FUN_0039A700
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a700);

// FUN_0039A760
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a760);

// FUN_0039A7E0
s32 func_0039a7e0(void)
{
    return 1;
}

// FUN_0039A8A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a8a0);

// FUN_0039AA30
s32 func_0039aa30(void)
{
    return 1;
}

// FUN_0039AA40
s32 func_0039aa40(void)
{
    return 1;
}

// FUN_0039AA50
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039aa50);

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

// FUN_0039AB10
void func_0039ab10(void)
{
    func_00399530();
}
/* measured: optimization_level 3 is load-bearing for all four functions in
   this scope, not just func_0039a7e0 -- at -O2 the three `return 1` leaves
   emit addiu; jr; nop against an 8-byte window and func_0039ab10 gets a
   frame plus jal where retail tail-jumps. Closing the scope here; -O2 is
/* At -O2 the three `return 1` leaves emit addiu; jr; nop against an 8-byte
   window, and func_0039ab10 gets a frame plus jal where retail tail-jumps.
   measured: optimization_level 3 is load-bearing for all four functions in
   this scope; closing it here, -O2 is the documented baseline. */
#pragma optimization_level 2


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
#pragma optimization_level 3

// FUN_0039AE30
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039ae30);

// FUN_0039B450
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b450);

// FUN_0039B4B0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b4b0);

// FUN_0039B510
s32 func_0039b510(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 8) = func_0039b6e0(arg3);
    return 1;
}
#pragma optimization_level 2


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.
#pragma optimization_level 3

// FUN_0039B540
s32 func_0039b540(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x6C) = func_0039b6e0(arg3);
    return 1;
}
#pragma optimization_level 2


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.
#pragma optimization_level 3

// FUN_0039B570
s32 func_0039b570(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x7C) = func_0039b6e0(arg3);
    return 1;
}
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
