#include "include_asm.h"
#include "type.h"

extern void func_003cfa80(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern u8 *func_003dda50(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_004217e0(u8 *arg0);

extern s32 D_00887180[];
extern s32 D_00887184[];
extern s32 D_00887188[];
extern s32 D_0088718C[];
extern void *D_00887194[];
extern u8 D_008871A0[];
extern s32 D_008871A4[];
extern s32 D_008871A8[];
extern s32 D_00724840;
extern s32 D_00724844;


/* measured: schedule on is load-bearing for retail's b/exit delay-slot moves.
   NONMATCHING: retail keeps both null-returns out of line (beqz; lw; beqz;
   sw; b exit/move $v0,$a0; b exit/move $v0,$zero; move $v0,$zero; jr $ra,
   12 instr); b210 if-converts the branch to beql with the move annulled in
   its slot and merges the exits (11 instr, nd 19 -> 15 with schedule on).
   Residual: nd 15. */

#pragma schedule on
// FUN_003D38E0 NONMATCHING
#ifdef NON_MATCHING
u8 *func_003d38e0(u8 *arg0, s32 arg1) {
    u8 *p;

    if (arg0 != NULL) {
        p = *(u8 **)((u8 *)arg0 + 0x14);
        if (p != NULL) {
            *(s32 *)(p + 0x14) = arg1;
            return arg0;
        }
    }
    return NULL;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d38e0);
#endif
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


void func_003df7f0(s32 arg0);

/* measured: without #pragma schedule on, MWCC emits lw $a0, 0x10($a0) before
   the jal with a nop in its delay slot and leaves the jr slot unfilled;
   retail fills both slots (nd 17 -> 0). */

// FUN_003D3920
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3920);

/* measured: the call has a hidden first argument. Retail leaves $a0 holding
   this function's own arg0 at the jal and puts the 0 in $a1 with the floats in
   $f12/$f13, so func_003cfa80 takes (ptr, s32, f32, f32); every three-argument
   prototype, in any order of the classes, puts the 0 in $a0 instead (nd 1). The
   call is also placed out of line via a positive test, so the goto graph is
   needed - the plain if form costs nd 13. */
// FUN_003D3A90
#pragma schedule on
u8 *func_003d3a90(u8 *arg0)
{
    if (*(u8 *)(arg0 + 2) & 2) {
        goto call;
    }
ret:
    return arg0;
call:
    func_003cfa80(arg0, 0, 1.0f, 1.0f);
    goto ret;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

// FUN_003D4BF0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4bf0);

// FUN_003D6010
#pragma schedule on
s32 func_003d6010(u8 *arg0) {
    func_003df7f0(*(s32 *)(arg0 + 0x10));
    return 1;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 18 -> 0). */

// FUN_003D7C50
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d7c50);

// FUN_003D7CD0
#pragma schedule on
u8 **func_003d7cd0(u8 **arg0) {
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x14);
    *(s32 *)(p + 0x40) += 1;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_0072483C;

// FUN_003D8130
#pragma schedule on
s32 func_003d8130(s32 arg0, s32 arg1) {
    u32 *ptr;

    ptr = (u32 *)(arg0 + D_0072483C);
    return ptr[arg1 + 2];
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off

/* measured: schedule on is load-bearing (nd 18 -> 14; default keeps the
   b/exit structure but leaves its delay slot empty).  NONMATCHING: retail
   keeps the else body out of line (sltiu; beqz; nop; addiu; sllv;
   b exit/sll; move $v0,$zero; jr $ra); b210 if-converts the branch to
   beql with the move annulled in its slot across all probed shapes. */

#pragma schedule on
/* measured: nd 32 against retail's 80-byte window (object 56 vs retail's real
   68, so work is still missing). Retail booleanises the loaded word with
   sltu/xori before branching and keeps the scan pointer in $v1 with the index
   in $a1; the goto layout here reproduces the branch shape but not the
   register assignment or the extra normalisation. Probed do/while, plain for,
   named booleanised locals, u32 vs s32 for the loaded word, unsigned index
   compare, and several declaration orders. Committed at nd 32. */
// FUN_003D8150 NONMATCHING
#ifdef NON_MATCHING
s32 func_003d8150(s32 arg0) {
    u32 i;
    u32 *p;
    s32 nz;

    i = 0;
    p = (u32 *)(arg0 + D_0072483C);
scan:
    nz = (p[2] != 0);
    if (!nz) {
        goto step;
    }
    return 1;
step:
    p++;
    i++;
    if (i < 8) {
        goto scan;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8150);
#endif

// FUN_003D81A0
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003d81a0 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003d81a0(u32 arg0) {
    if (arg0 < 9U) {
        return (1 << arg0) * 4;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003d81a0). */
#pragma no_branch_likely off
#pragma schedule off


extern s32 D_0072484C;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 16 -> 0). */

// FUN_003DC490
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc490);

// FUN_003DC510
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc510);

// FUN_003DC590
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc590);

// FUN_003DD530
/* measured: b210 if-converts the ret==0 return into a beql with the move
   annulled in its slot; retail uses a plain beqz with the return-0 block out
   of line.  `no_branch_likely on` (with `schedule on` for the prologue's
   arg-setup interleave and the jal delay-slot move) reproduces retail (nd 60
   -> 20 with schedule on -> MATCH with both). */
#pragma no_branch_likely on
#pragma schedule on
s32 func_003dd530(u8 *arg0, s32 arg1) {
    u8 *ret = func_003dda50(arg0, arg1, 1, 0, 0);
    if (ret != NULL) {
        ((void (*)(u8 *))(*(void **)(arg0 + 0x2C)))(ret);
        return 1;
    }
    return 0;
}
/* measured: closes the schedule/no_branch_likely brackets above. */
#pragma schedule off
#pragma no_branch_likely off

// FUN_003DD5C0
/* measured: b210 emits a branch-likely (beql) for the case-1 test and
   if-converts the short case-1 body into its delay slot; retail uses a plain
   beq with a nop and keeps both case bodies out of line.  `no_branch_likely on`
   + `schedule on` reproduces retail exactly (switch, cases declared ascending
   1,2; nd 49 -> MATCH). */
#pragma no_branch_likely on
#pragma schedule on
void func_003dd5c0(u8 **arg0, s32 arg1) {
    switch (arg1) {
    case 1:
        if (arg0[8] != NULL) {
            ((void (*)(u8 *))arg0[8])((u8 *)arg0 + 0x50);
        }
        break;
    case 2:
        if (arg0[9] != NULL) {
            ((void (*)(u8 *))arg0[9])((u8 *)arg0 + 0x50);
        }
        break;
    }
}
/* measured: closes the schedule/no_branch_likely brackets above. */
#pragma schedule off
#pragma no_branch_likely off

/* measured: the statement sequence and every store are right (obj 112 in a
   112-byte window) but b210 pairs the %hi/%lo halves of the first two globals
   the other way round from retail (retail stores D_00887184 through the
   SECOND lui and D_00887188 through the first; b210 pairs each store with its
   own lui), transposes the `addiu $v1,1` and the D_008871A8 lui, and puts the
   trailing constant 1 in $a0 instead of reusing $v0 after the call result is
   stored. Measured identical at nd 45-49: a named `one` constant local, a
   named result local for the func_004217e0 return, and 0 instead of NULL.
   All three residual clusters are register/schedule choices with the same
   addresses in both builds. Allocation floor. */
// FUN_003DD760 NONMATCHING
#ifdef NON_MATCHING
void func_003dd760(s32 arg0) {
    D_00887184[0] = arg0;
    D_00887188[0] = 0;
    D_00887180[0] = 0;
    D_00887194[0] = NULL;
    D_008871A8[0] = 1;
    D_00724840 = 0;
    D_008871A4[0] = 1;
    D_00724844 = func_004217e0(D_008871A0);
    D_0088718C[0] = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd760);
#endif

// FUN_003DD7D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd7d0);

// FUN_003DDC20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddc20);

// FUN_003DDF20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddf20);

/* measured: nd 38 (37 under schedule on, which also shrinks the object below
   retail's). Dispatches through the +0x50 vtable slot at +0x30 and divides the
   unsigned result by the same factor the third argument was scaled with, so
   the factor has to stay live across the call - retail parks it in $s0, which
   this shape reproduces. The residual is the argument shuffle before the jalr:
   retail routes the first parameter through $v0 and rebuilds $a0/$a1 from the
   fourth, b210 moves them directly. Committed at nd 37. */
// FUN_003DDF80 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule on fills one more delay slot retail fills, nd 38 -> 37. */
#pragma schedule on
u32 func_003ddf80(s32 arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 (*fn)(u8 *, s32, s32);

    fn = *(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x30);
    return fn(arg3, arg0, arg1 * arg2) / arg1;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddf80);
#endif

/* measured: nd 38, the +0x34 sibling of func_003ddf80 above with the identical
   residual and the identical response to schedule on. Committed at nd 37. */
// FUN_003DDFD0 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule on fills one more delay slot retail fills, nd 38 -> 37. */
#pragma schedule on
u32 func_003ddfd0(s32 arg0, u32 arg1, s32 arg2, u8 *arg3) {
    u32 (*fn)(u8 *, s32, s32);

    fn = *(u32 (**)(u8 *, s32, s32))(*(u8 **)(arg3 + 0x50) + 0x34);
    return fn(arg3, arg0, arg1 * arg2) / arg1;
}
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddfd0);
#endif

// FUN_003DF440
#pragma schedule on
s32 func_003df440(s32 arg0) {
    D_0072484C += 1;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_0072484C;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 16 -> 0). */

// FUN_003DF460
#pragma schedule on
s32 func_003df460(s32 arg0) {
    D_0072484C -= 1;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_00724854;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 16 -> 0). */

// FUN_003DF4B0
#pragma schedule on
s32 func_003df4b0(s32 arg0) {
    D_00724854 -= 1;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


/* NONMATCHING: retail schedules the result addu into the jr $ra delay slot
   (lw 0xc; mult; lw 0; jr; addu).  #pragma schedule on fills the slot but
   hoists the independent base load above the mult and recolors the stride
   load to $v1 (nd 8 -> 9); every probed expression order/temp form does the
   same, and default leaves the slot as nop (nd 8).  Floor.
   P3FES donor FUN_004c21b0 (rwplcore.c:2337) is itself an inline-asm body
   emitting the retail 3-operand mult $3,$2,$5 (0x00451818) -- a MIPS32r2
   rd-form multiply MWCC cannot emit from C.  Blocked per wave rule; not a
   matching gap.  Residual nd 8 (the mult word). */

// FUN_003DF870 NONMATCHING
#ifdef NON_MATCHING
s32 func_003df870(s32 *arg0, s32 arg1) {
    return arg0[0] + arg0[3] * arg1;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df870);
#endif


/* NONMATCHING: retail schedules the result addu into the jr $ra delay slot
   (lw 0xc; lw 4; mult; lw 0; jr; addu).  #pragma schedule on fills the slot
   but hoists the independent base load above the mult and recolors the
   stride load to $v1 (nd 8 -> 10); default leaves the slot as nop (nd 8).
   Floor.
   P3FES donor FUN_004c21e0 (rwplcore.c:2357) is itself an inline-asm body
   emitting the retail 3-operand mult $3,$3,$2 (0x00621818) -- the same
   MIPS32r2 rd-form multiply MWCC cannot emit from C.  Blocked per wave
   rule; not a matching gap.  Residual nd 8 (the mult word). */

// FUN_003DF8A0 NONMATCHING
#ifdef NON_MATCHING
s32 func_003df8a0(s32 *arg0) {
    return arg0[0] + arg0[3] * arg0[1];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df8a0);
#endif
