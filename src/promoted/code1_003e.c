#include "include_asm.h"
#include "type.h"

extern s32 D_008866D8;

extern s32 D_0088731C;

extern s32 D_00886700;

extern s32 D_00887330;


// measured: removing this pragma takes func_003e05d0 nd 0 -> nd 16: retail fills the
// jr $ra delay slot with sw $v1, 0xc($a0) and hoists move $v0,$a0 before the and;
// baseline -O2 emits lw; lui; ori; and; sw; move; jr; nop.
#pragma optimization_level 3

// FUN_003E05D0
u8 *RwMatrixUpdate(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) &= 0xFFFDFFFC;
    return arg0;
}


// measured: removing this pragma takes func_003e1020 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x54a0($gp); baseline -O2 emits sw; jr; nop.
#pragma optimization_level 3

// FUN_003E1020
void func_003e1020(s32 arg0) {
    D_008866D8 = arg0;
}



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

// FUN_003E3020
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3020);

// FUN_003E3070 NONMATCHING
#ifdef NON_MATCHING
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

// FUN_003E3370
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3370);

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

// FUN_003E43A0
s32 func_003e43a0(s32 arg0) {
    D_0088731C -= 1;
    return arg0;
}


// measured: removing this pragma takes func_003e4510 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with addiu $v0, $zero, 1; baseline -O2 emits addiu; jr; nop.
#pragma optimization_level 3

// FUN_003E43C0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e43c0);

// FUN_003E44B0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e44b0);

// FUN_003E4510
s32 func_003e4510(void) {
    return 1;
}


// measured: removing this pragma takes func_003e5510 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with sw $a0, -0x5478($gp); baseline -O2 emits sw; jr; nop.
#pragma optimization_level 3

// FUN_003E46E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e46e0);

// FUN_003E4760
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4760);

// FUN_003E4880
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4880);

// FUN_003E48D0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e48d0);

// FUN_003E4AC0
void func_003e4ac0(void)
{
}

// FUN_003E4AD0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e4ad0);

// FUN_003E50A0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e50a0);

// FUN_003E5510
void func_003e5510(s32 arg0) {
    D_00886700 = arg0;
}


// measured: removing this pragma takes func_003e6750 nd 0 -> nd 15: retail fills the
// jr $ra delay slot with sw $v1, ($a1) and hoists move $v0,$a0 before the addiu;
// baseline -O2 emits lw; addiu; sw; move; jr; nop.
#pragma optimization_level 3

// FUN_003E5990
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5990);

// FUN_003E59E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e59e0);

// FUN_003E6240
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e6240);

// FUN_003E6750
s32 func_003e6750(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}


// measured: removing this pragma takes func_003e8910 nd 0 -> nd 6: retail fills the
// jr $ra delay slot with lw $v0, -0x4848($gp); baseline -O2 emits lw; jr; nop.
#pragma optimization_level 3

// FUN_003E7EE0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7ee0);

// FUN_003E7F50
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7f50);

// FUN_003E7FB0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e7fb0);

// FUN_003E8010
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e8010);

// FUN_003E8910
s32 func_003e8910(void) {
    return D_00887330;
}
