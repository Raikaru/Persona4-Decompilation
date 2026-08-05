#include "include_asm.h"
#include "type.h"

extern s32 D_008866D8;

extern s32 D_0088731C;

extern s32 D_00886700;

extern s32 D_00887330;


// measured: removing this pragma takes func_003e05d0 nd 0 -> nd 16: retail fills the
// jr $ra delay slot with sw $v1, 0xc($a0) and hoists move $v0,$a0 before the and;
// baseline -O2 emits lw; lui; ori; and; sw; move; jr; nop.

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
extern void (*jtbl_008873EC[])(u8 *arg0);

// FUN_003E05D0
u8 *RwMatrixUpdate(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) &= 0xFFFDFFFC;
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: removing this pragma takes func_003e1020 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x54a0($gp); baseline -O2 emits sw; jr; nop.

#pragma optimization_level 3
// FUN_003E1020
void func_003e1020(s32 arg0) {
    D_008866D8 = arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2



/* measured: a plain linked-list search (walk arg0->f10 via f30 for f8 == arg1,
   then store arg2 at f18 and return f0, else -1). Two b210 codegen choices
   block it and they pull in opposite directions:

   At -O2 b210 fills the loop and exit delay slots with BRANCH-LIKELY forms
   (bnel/beql) retail never uses, collapsing the body to 60B against an 80B
   window (nd 15). `#pragma schedule off` removes them and reaches 72B / nd 9,
   but it also disables the delay-slot fill retail DOES have (retail puts the
   `lw $v0,($v1)` in the `b` delay slot), so scheduling cannot be both off and
   on. The 2-word residual after that is that fill plus a redundant `nop`
   retail emits between the loop exit and the join at 0x3e3094.

   Changed nothing here when probed: opt_peephole, opt_branch_likely,
   opt_branch_folding, opt_common_subs, opt_unroll_loops, optimize_for_size,
   opt_propagation. The nd-9 body is kept below so the next attempt starts from
   it instead of re-deriving. Branch-likely / delay-slot floor. */
// FUN_003E1A70
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1a70);

// FUN_003E1C30
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1c30);

// FUN_003E1DB0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1db0);

// FUN_003E23E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e23e0);

// FUN_003E2570
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2570);

// FUN_003E25F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e25f0);

/* measured: nd 20 of 20 words, everything correct but a one-word shift -
   retail has TWO consecutive nops between the search loop's bnez and the
   following null test, ours has one, and every instruction after slides. None
   of peephole off, no_branch_likely, opt_dead_code off, opt_propagation off,
   opt_common_subs off or optimize_for_size moves it, and schedule on shrinks
   the function to 68 bytes instead.
   Two things worth keeping: this function was previously measured at -O3
   because of a file-wide pragma span (nd 29 there), and the awkward
   `if (p == NULL) {} else goto` shape is load-bearing - rewriting the search as
   a plain while loop with a break costs nd 46. */
// FUN_003E3020
#ifdef NON_MATCHING
s32 func_003e3020(u8 *arg0, s32 key, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
scan:
        if (*(s32 *)(node + 8) != key) {
            node = *(u8 **)(node + 0x30);
            if (node == NULL) {

            } else {
                goto scan;
            }
        }
    }
    if (node != NULL) {
        *(s32 *)(node + 0xC) = arg2;
        *(s32 *)(node + 0x10) = arg3;
        *(s32 *)(node + 0x14) = arg4;
        return *(s32 *)node;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3020);
#endif

// FUN_003E3070 NONMATCHING
#ifdef NON_MATCHING
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
        do {
            if (*(s32 *)(node + 8) == arg1) {
                break;
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    if (node != NULL) {
        *(s32 *)(node + 0x18) = arg2;
        return *(s32 *)(node + 0);
    }
    return -1;
}
#pragma schedule on
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3070);
#endif

/* measured: a plain linked-list search (walk arg0->f10 via f30 for f8 == arg1,
   then store arg2 at f18 and return f0, else -1). Two b210 codegen choices
   block it and they pull in opposite directions:

   At -O2 b210 fills the loop and exit delay slots with BRANCH-LIKELY forms
   (bnel/beql) retail never uses, collapsing the body to 60B against an 80B
   window (nd 15). `#pragma schedule off` removes them and reaches 72B / nd 9,
   but it also disables the delay-slot fill retail DOES have (retail puts the
   `lw $v0,($v1)` in the `b` delay slot), so scheduling cannot be both off and
   on. The 2-word residual after that is that fill plus a redundant `nop`
   retail emits between the loop exit and the join at 0x3e3094.

   Changed nothing here when probed: opt_peephole, opt_branch_likely,
   opt_branch_folding, opt_common_subs, opt_unroll_loops, optimize_for_size,
   opt_propagation. The nd-9 body is kept below so the next attempt starts from
   it instead of re-deriving. Branch-likely / delay-slot floor. */
// FUN_003E30C0 NONMATCHING
#ifdef NON_MATCHING
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
s32 func_003e30c0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
        do {
            if (*(s32 *)(node + 8) == arg1) {
                break;
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    if (node != NULL) {
        *(s32 *)(node + 0x18) = arg2;
        return *(s32 *)(node + 0);
    }
    return -1;
}
#pragma schedule on
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e30c0);
#endif

// FUN_003E32F0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e32f0);

/* measured: nd 22 of 32 words, and every instruction is right - retail has one
   extra nop between the loop's exit branch and the `move $v0, $s1` that
   materialises the return value, so the whole epilogue slides one word. This is
   the SECOND function in this file with that exact artifact (see func_003e3020,
   which has two consecutive nops at its own loop exit), which makes it look like
   a b210-vs-retail behaviour at a loop-exit block join rather than anything the
   source controls. Confirmed not source-driven here: do-while, while and an
   explicit goto loop all give nd 22-23 under schedule+no_branch_likely, and
   schedule alone costs nd 32. */
// FUN_003E3370
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e3370(u8 *arg0, s32 arg1)
{
    s32 (*fn)(s32, s32, s32);
    s32 got;
    s32 total;
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    total = 0;
    if (node != NULL) {
        do {
            fn = *(s32 (**)(s32, s32, s32))(node + 0x14);
            if (fn != NULL) {
                got = fn(arg1, *(s32 *)node, *(s32 *)(node + 4));
                if (got > 0) {
                    total += got + 0xC;
                }
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }

    return total;
}
/* measured: closes the bracket noted above the marker. */
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3370);
#endif

// FUN_003E3630
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3630);

// FUN_003E3C20
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3c20);

// FUN_003E3C90
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3c90);

// FUN_003E3F00
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3f00);

// FUN_003E4030
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4030);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E43A0
s32 func_003e43a0(s32 arg0) {
    D_0088731C -= 1;
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: removing this pragma takes func_003e4510 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with addiu $v0, $zero, 1; baseline -O2 emits addiu; jr; nop.

// FUN_003E43C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e43c0);

/* measured: same out-of-line-body shape as func_003e59e0 - retail branches to
   the initialisation block and falls into the early `return 0`, so the goto
   graph is needed and the plain `if (size < 0x20) return 0;` form is not
   (nd 23 with it). schedule on fills the branch delay slot with the first store
   as retail does, and no_branch_likely is then needed to stop b210 turning the
   test into a beql, which was the last differing word. */
// FUN_003E44B0
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e44b0(u8 *arg0, s32 arg1)
{
    s32 *base;
    s32 size;

    base = (s32 *)(((s32)arg0 + 0x27) & ~0x1F);
    size = ((((s32)arg0 + arg1) & ~0x1F) - (s32)base) - 0x20;
    if (size >= 0x20) {
        goto init;
    }
    return 0;
init:
    base[0] = (s32)arg0;
    base[1] = 0;
    base[2] = 0;
    base[4] = 0;
    base[3] = size;
    *(s32 *)arg0 = (s32)base;
    *(s32 *)(arg0 + 4) = (s32)base;
    return 1;
}
#pragma no_branch_likely off
#pragma schedule off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E4510
s32 func_003e4510(void) {
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: removing this pragma takes func_003e5510 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x5478($gp); baseline -O2 emits sw; jr; nop.

// FUN_003E46E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e46e0);

// FUN_003E4760
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4760);

/* measured: schedule on plus no_branch_likely on. schedule alone gets nd 26
   (retail fills the loop's branch delay slots), and b210 then wants beql/bnel
   where retail has plain bne/bnez, which is the rest of it. */
// FUN_003E4880
#pragma schedule on
#pragma no_branch_likely on
s8 *func_003e4880(s8 *arg0) {
    s8 *var_5;
    s8 temp_3;

    if (arg0 != NULL) {
        var_5 = (s8 *)(arg0);
        if (*arg0 != 0) {
            do {
                temp_3 = (s8)(*var_5);
                if ((temp_3 >= 0x61) && (temp_3 < 0x7B)) {
                    *var_5 = temp_3 - 0x20;
                }
                var_5 += 1;
            } while (*var_5 != 0);
        }
    }
    return (s8 *)(arg0);
}
#pragma no_branch_likely off
#pragma schedule off

/* measured: schedule on plus no_branch_likely on. schedule alone gets nd 26
   (retail fills the loop's branch delay slots), and b210 then wants beql/bnel
   where retail has plain bne/bnez, which is the rest of it. */
// FUN_003E48D0
#pragma schedule on
#pragma no_branch_likely on
s8 *func_003e48d0(s8 *arg0) {
    s8 *var_5;
    s8 temp_3;

    if (arg0 != NULL) {
        var_5 = (s8 *)(arg0);
        if (*arg0 != 0) {
            do {
                temp_3 = (s8)(*var_5);
                if ((temp_3 >= 0x41) && (temp_3 < 0x5B)) {
                    *var_5 = temp_3 + 0x20;
                }
                var_5 += 1;
            } while (*var_5 != 0);
        }
    }
    return (s8 *)(arg0);
}
#pragma no_branch_likely off
#pragma schedule off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E4AC0
void func_003e4ac0(void)
{
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

// FUN_003E4AD0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4ad0);

// FUN_003E50A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e50a0);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E5510
void func_003e5510(s32 arg0) {
    D_00886700 = arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: removing this pragma takes func_003e6750 nd 0 -> nd 15: retail fills the
// jr $ra delay slot with sw $v1, ($a1) and hoists move $v0,$a0 before the addiu;
// baseline -O2 emits lw; addiu; sw; move; jr; nop.

// FUN_003E5990
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5990);

/* measured: two things are load-bearing here. Retail tests POSITIVELY and puts
   the indirect call out of line after the return path, then jumps back to it -
   the plain `if (cond) { call(); } return arg0;` form compiles inline with a
   negated skip and scores nd 31, while the goto graph below is exact. And the
   jal and branch delay slots are filled, which needs schedule on. */
// FUN_003E59E0
#pragma schedule on
u8 *func_003e59e0(u8 *arg0)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        goto call;
    }
ret:
    return arg0;
call:
    (*jtbl_008873EC)(*(u8 **)arg0);
    goto ret;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

// FUN_003E6240
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6240);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E6750
s32 func_003e6750(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: removing this pragma takes func_003e8910 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with lw $v0, -0x4848($gp); baseline -O2 emits lw; jr; nop.

#pragma optimization_level 3
// FUN_003E7EE0
u8 *func_003e7ee0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x14) == 1) {
        func_003e7680();
        func_003e6e70(arg0);
    } else {
        func_003e7d50();
        func_003e7810(arg0);
    }
    func_003e5110(arg0 + 0x10C, arg0 + 0x124, 8);
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

// FUN_003E7F50
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7f50);

// FUN_003E7FB0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7fb0);

// FUN_003E8010
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8010);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_003E8910
s32 func_003e8910(void) {
    return D_00887330;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2
