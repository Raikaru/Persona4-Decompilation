#include "include_asm.h"
#include "type.h"

extern s32 D_008866D8;

extern s32 D_0088731C;

extern s32 D_00886700;

extern s32 D_00887330;

extern u8 D_008872E0[];
extern s32 D_00724870;
extern s32 (*D_008873D4[])(char *arg0);
extern char D_00752FA8[];
extern u8 D_00887250[];
extern void *D_00887408[];
extern s32 D_00763C68;
extern s32 D_00763C6C;
extern s32 D_00764874;
extern s32 D_00764878;
extern s32 D_0076487C;
extern s32 D_00764884;
extern s32 D_00764888;
extern s32 D_00764890;
extern s32 D_00764898;
extern s32 D_0076489C;
extern s32 D_00763C54;
extern s32 D_00763C58;
extern s32 D_00763C70;
extern s32 D_00763C74;
extern s32 D_00764860;
extern void *D_00764864;
extern void *D_00764868;
extern s32 D_007648A0;
extern s32 D_007648A4;
extern s32 D_0070B800[];
extern u8 D_00887220[];
extern u8 D_00887280[];
extern s8 D_00754D88[];
extern s32 (*D_0088732C[])(s32, s32, s32);
extern s32 (*D_00887350[])(s32, s32, s32);
s32 func_003e1220(s32, s32, s32, s32, void *, s32);
void func_003e12f0(s32);
s32 func_003e1740(u8 *);
void func_003e1230(void *);
void func_003ed7e0(void);
void func_00410f40(s32);
u8 *func_003e1cb0(u8 *, void *);
void func_003e3dc0();
void func_003e3d00();
void func_003e3f00();
void func_003e3e60();


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
// FUN_003E1A70 NONMATCHING
#ifdef NON_MATCHING
/* measured: nd 45 of 112, guarded do/while summing func_003e1740(node-0x1C)
   when >0 over the D_00764868 circular list. schedule on gets the layout; the
   residual is register colouring - retail keeps node in  and sum in ,
   b210 assigns node to  and sum to  (and shrinks the slt to a blez). */
#pragma schedule on
s32 func_003e1a70(void) {
    s32 sum = 0;
    void **node = (void **)D_00764868;
    void **sentinel = (void **)&D_00764868;
    if (node != sentinel) {
        do {
            s32 r = func_003e1740((u8 *)node - 0x1C);
            if (0 < r) {
                sum += r;
            }
            node = (void **)node[0];
        } while (node != sentinel);
    }
    return sum;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e1a70);
#endif
/* measured: schedule + no_branch_likely are load-bearing - schedule fills both
   func_003e1230 jal delay slots with the cross-link sw, and no_branch_likely
   stops b210 turning the loop's beq/bne into beql/bnel. */
// FUN_003E1C30
#pragma schedule on
#pragma no_branch_likely on
void func_003e1c30(void) {
    void **node = (void **)D_00764868;
    if (node != (void **)&D_00764868) {
        do {
            ((void **)node[1])[0] = node[0];
            ((void **)node[0])[1] = node[1];
            func_003e1230((u8 *)node - 0x1C);
            node = (void **)D_00764868;
        } while (node != (void **)&D_00764868);
    }
    {
        u8 *obj = (u8 *)D_00764864;
        ((void **) *(void **)(obj + 0x20))[0] = *(void **)(obj + 0x1C);
        ((void **) *(void **)(obj + 0x1C))[1] = *(void **)(obj + 0x20);
        func_003e1230(obj);
    }
    D_00764864 = 0;
    D_00764860 = 0;
}
#pragma no_branch_likely off
#pragma schedule off
// FUN_003E1DB0
/* measured: no_branch_likely keeps the success test as retail's plain bnez. */
#pragma no_branch_likely on
#pragma schedule on
s32 func_003e1db0(u8 *arg0, s32 arg1) {
    D_00724870 = arg1;
    if (func_003e1cb0(D_008872E0 + arg1, D_00887408[0]) == 0) {
        return 0;
    }
    D_00764874++;
    return (s32)arg0;
}
/* measured: closes the no_branch_likely pragma above. */
#pragma no_branch_likely off
#pragma schedule off


/* measured: sum's initial load is written before base setup so b210 keeps
   the D_008872E0 + offset base in $v1 while retail uses $v0 for the running
   sum (nd 10 -> nd 7). The remaining difference is one missing nop before
   the jr: candidate branches to the return at +0x3c while retail has a nop
   at +0x3c and the jr at +0x40. Retail's three all-zero words after its jr
   are alignment padding, not missing body instructions. Tail/control-flow,
   declaration-order, base-local, O1/O3/CSE/loop-invariant/schedule probes
   did not improve nd 7. Object 68/window 80. Committed at nd 7. */
// FUN_003E23E0 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
s32 func_003e23e0(void) {
    u8 *base;
    u8 *head;
    u8 *node;
    s32 sum;

    sum = *(s32 *)(D_008872E0 + D_00724870 + 8);
    base = D_008872E0 + D_00724870;
    head = *(u8 **)(base + 0x24);
    node = *(u8 **)head;
    if (node != head) {
        do {
            sum += *(s32 *)(node + 8);
            node = *(u8 **)node;
        } while (node != head);
    }
    return sum;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e23e0);
#endif

/* measured: discarded nonvolatile candidate nd 31, object 120/128; the nd 0
   volatile spelling is rejected by H001 (ordinary-data compiler steering). */
// FUN_003E2570
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e2570);
// FUN_003E25F0
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003e25f0(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_00764878];
    if (v != 0) {
        func_003e12f0(v);
    }
    D_0076487C--;
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off






/* measured: recovered guarded body scores nd 20 at object 80/window 80.
   Retail has TWO consecutive nops between the search loop's bnez and the
   following null test; b210 emits one, shifting every later instruction.
   Peephole off, no_branch_likely, opt_dead_code off, opt_propagation off,
   opt_common_subs off, optimize_for_size, schedule, empty-branch, goto and
   loop-shape probes did not add the missing nop. The awkward
   `if (p == NULL) {} else goto` shape remains load-bearing. Committed at nd 20. */
// FUN_003E3020 NONMATCHING
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

/* measured: nd 16 of 80 bytes. The C body reproduces the linked-list search and store, but b210 omits retail's two nops between the loop exit and the final null test. Probed do/while, goto, schedule on/off, and no_branch_likely; committed at nd 16. */
// FUN_003E3070 NONMATCHING
#ifdef NON_MATCHING
s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
scan3070:
        if (*(s32 *)(node + 8) != arg1) {
            node = *(u8 **)(node + 0x30);
            if (node == NULL) {

            } else {
                goto scan3070;
            }
        }
    }
    if (node != NULL) {
        *(s32 *)(node + 0x18) = arg2;
        return *(s32 *)(node + 0);
    }
    return -1;
}
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

/* measured: recovered guarded body scores nd 22 at object 120/window 128.
   Every emitted instruction is right, but retail has one extra nop between
   the loop-exit branch and `move $v0, $s1`, shifting the epilogue by one word.
   do-while, while, explicit-goto, empty-statement and label probes remain
   nd 22-23 under schedule+no_branch_likely; schedule alone costs nd 32.
   This is the same loop-exit block-join artifact as func_003e3020. Committed at nd 22. */
// FUN_003E3370 NONMATCHING
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
#pragma schedule on
s32 func_003e3630(void) {
    s32 r;
    r = func_003e1220(0x3C, D_00763C68, 4, D_00763C6C, D_00887250, 0x40000);
    D_00764888 = r;
    if (r != 0) {
        D_00764884 = 0;
        return 1;
    }
    return 0;
}
#pragma schedule off


// FUN_003E3C20 NONMATCHING
#ifdef NON_MATCHING
/* measured: nd 22 of 112. Walks arg0->f14 calling each node's f24 fnptr
   (arg1, f0, f4) then following f34. schedule+no_branch_likely get the whole
   body; the residual is a single extra nop - retail has TWO nops after the
   loop's bnez (pipeline stall before the epilogue), b210 emits one, so the
   epilogue slides one word (same floor as func_003e3020). */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e3c20(s32 arg0, s32 arg1) {
    s32 node = *(s32 *)(arg0 + 0x14);
    if (node) {
        do {
            ((s32 (*)(s32, s32, s32))(*(s32 *)(node + 0x24)))(arg1, *(s32 *)(node + 0), *(s32 *)(node + 4));
            node = *(s32 *)(node + 0x34);
        } while (node);
    }
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e3c20);
#endif
/* measured: schedule+no_branch_likely load-bearing - schedule fills the
   jalr delay slot, no_branch_likely keeps the loop bnez plain. */
// FUN_003E3C90
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e3c90(s32 arg0, s32 arg1, s32 arg2) {
    s32 node = *(s32 *)(arg0 + 0x10);
    if (node) {
        do {
            ((s32 (*)(s32, s32, s32, s32))(*(s32 *)(node + 0x28)))(arg1, arg2, *(s32 *)(node + 0), *(s32 *)(node + 4));
            node = *(s32 *)(node + 0x30);
        } while (node);
    }
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off


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

// FUN_003E43C0 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
void *func_003e43c0(u8 *arg0, s32 arg1, s32 arg2) {
    void **p = (void **)&D_008872E0[arg1];
    D_00764890 = arg1;
    p[2] = (void *)func_003e3dc0;
    p[3] = (void *)func_003e3d00;
    p[4] = (void *)func_003e3f00;
    p[5] = (void *)func_003e3e60;
    D_0088731C++;
    return arg0;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e43c0);
#endif




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

/* measured: discarded nonvolatile candidate nd 31, object 120/128; the nd 0
   volatile spelling is rejected by H001 (ordinary-data compiler steering). */
// FUN_003E46E0
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e46e0);
// FUN_003E4760
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003e4760(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_00764898];
    if (v != 0) {
        func_003e12f0(v);
    }
    D_0076489C--;
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off


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

/* measured: schedule on is load-bearing (nd 55 without it, and the object
   overflows the window at 84 bytes); the default-argument substitution is
   reached by goto so it lands out of line after the call, as retail has it. */
// FUN_003E4AD0
#pragma schedule on
s32 func_003e4ad0(char *arg0) {
    s32 r;

    if (arg0 == NULL) {
        goto setdef;
    }
call:
    r = D_008873D4[0](arg0);
    return (r + 4) & -4;
setdef:
    arg0 = D_00752FA8;
    goto call;
}
#pragma schedule off

/* measured: schedule on + no_branch_likely on are load-bearing for this body
   (nd 76 without them) - they place result=0 in the beqz  delay slot and
   keep the arg0[1]==0x3A test's xori/sltiu out of a branch-likely. */
// FUN_003E50A0
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e50a0(s8 *arg0) {
    s32 result = 0;
    if (arg0 != 0) {
        s32 flag = 1;
        if (arg0[0] != 0x5C) {
            s32 cond = (D_00754D88[arg0[0]] & 3) != 0;
            if (cond) {
                cond = (arg0[1] == 0x3A);
            }
            if (!cond) {
                flag = 0;
            }
        }
        if (flag) {
            result = 1;
        }
    }
    return result;
}
#pragma no_branch_likely off
#pragma schedule off
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

/* measured: the m2c draft advanced the s32* cursor by 4 ELEMENTS (16 bytes)
   where retail advances one element; with `p++` the loop body, the found-exit
   `*arg2 = i; return 1` and the count/limit registers are all correct and the
   object is exactly the 80-byte window without any scheduling pragma (nd 43).
   Two residuals remain: retail materialises the entry guard as
   `slt $at,$zero,$v1; beqz $at` where b210 emits a single `blez` for `n > 0`,
   `0 < n` and `!(n <= 0)` alike, and retail's in-loop mismatch test is a plain
   `bne` + nop while b210 wants `bnel`. Adding no_branch_likely fixes the
   second but costs the first (nd 49); schedule on shrinks the object to
   64 bytes (nd 46). Entry-guard materialisation floor.
   Committed at nd 43. */
// FUN_003E5990 NONMATCHING
#ifdef NON_MATCHING
s32 func_003e5990(u8 *arg0, s32 arg1, s32 *arg2) {
    s32 n;
    s32 *p;
    s32 i;

    n = *(s32 *)(arg0 + 4);
    i = 0;
    if (n > 0) {
        p = *(s32 **)arg0;
        do {
            if (*p == arg1) {
                *arg2 = i;
                return 1;
            }
            i++;
            p++;
        } while (i < n);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003e", func_003e5990);
#endif

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

/* measured: schedule on is load-bearing - it hoists move $s1,$a0 before the
   first call and fills each jal delay slot with the running-total addu. */
// FUN_003E6240
#pragma schedule on
s32 func_003e6240(s32 arg0) {
    s32 total = 0x10;
    total += func_003e4ad0((char *)(arg0 + 0x10)) + 0xC;
    total += func_003e4ad0((char *)(arg0 + 0x30)) + 0xC;
    total += func_003e3370((u8 *)D_0070B800, arg0) + 0xC;
    return total;
}
#pragma schedule off



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

/* measured: schedule+no_branch_likely load-bearing; flipped guard polarity so
   the D_008872E0=0 work lands out of line after the early return 0. */
// FUN_003E7F50
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e7f50(u8 *arg0) {
    if (D_00887350[0](0, (s32)arg0, 0) == 0) {
        return 0;
    }
    *(s32 *)D_008872E0 = 0;
    return (s32)arg0;
}
#pragma no_branch_likely off
#pragma schedule off






/* measured: schedule+no_branch_likely load-bearing - schedule puts the
   D_008872E0 store in the func_003ed7e0 jal delay slot. */
// FUN_003E7FB0
#pragma schedule on
#pragma no_branch_likely on
s32 func_003e7fb0(u8 *arg0) {
    *(s32 *)D_008872E0 = (s32)arg0;
    func_003ed7e0();
    if (D_0088732C[0](0, (s32)arg0, 0) == 0) {
        return 0;
    }
    func_00410f40((s32)arg0);
    return (s32)arg0;
}
#pragma no_branch_likely off
#pragma schedule off


/* measured: schedule+no_branch_likely load-bearing, same shape as func_003e25f0
   but with a D_008872E0[D_007648A0]=0 store inside the guard. */
// FUN_003E8010
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003e8010(u8 *arg0) {
    s32 v = *(s32 *)&D_008872E0[D_007648A0];
    if (v != 0) {
        func_003e12f0(v);
        *(s32 *)&D_008872E0[D_007648A0] = 0;
    }
    D_007648A4--;
    return arg0;
}
#pragma no_branch_likely off
#pragma schedule off


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
