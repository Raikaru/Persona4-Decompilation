#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])();
extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 D_007647CC;
extern s32 D_007647C8;


extern s32 D_007647BC;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 15 -> 0). */


// FUN_003C1D20
#pragma schedule on
s32 func_003c1d20(s32 arg0) {
    D_007647BC--;
    return arg0;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 13 -> 0). */

// FUN_003C2130
#pragma schedule on
s32 func_003c2130(s32 arg0, u8 *arg1, s16 arg2, s16 arg3, s16 arg4) {
    ((s16 *)arg1)[0] = arg2;
    ((s16 *)arg1)[1] = arg3;
    ((s16 *)arg1)[2] = arg4;
    return arg0;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colors the halfword scratch $v0; retail fills the slot
   with the final store and colors it $v1 (nd 15 -> 0). */

// FUN_003C2290
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2290);

// FUN_003C2A60
#pragma schedule on
u8 *func_003c2a60(u8 *arg0) {
    ((s16 *)arg0)[7] = (s16)(((s16 *)arg0)[7] + 1);
    return arg0;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 11 -> 0). */

// FUN_003C2C90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2c90);

// FUN_003C38B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c38b0);

// FUN_003C3CC0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3cc0);

// FUN_003C3E10
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3e10);

/* measured: same shape as func_003bd470 in code1_003b.c; see that note. nd 43. */
// FUN_003C3F20
#ifdef NON_MATCHING
#pragma no_branch_likely on
s32 func_003c3f20(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647CC, 4) == 0) {
        return 0;
    }
    if (arg1 != 8) {
        return arg0;
    }
    if (func_003df360(arg0, &D_007647C8, 4) == 0) {
        return 0;
    }
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3f20);
#endif

// FUN_003C3FA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3fa0);

// FUN_003C40D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c40d0);

// FUN_003C42B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c42b0);

// FUN_003C47C0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c47c0);

/* measured: without schedule on, b210 leaves the jr $ra delay slot unfilled
   (nop); retail fills it with the final store (nd 15 -> 0). */
// FUN_003C4A40
#pragma schedule on
u8 *func_003c4a40(u8 *arg0) {
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_007647EC;

// FUN_003C54A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c54a0);

// FUN_003C5700
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5700);

/* measured: the OR chain's five tests all branch POSITIVELY to a shared call
   block placed after the return path, so each test needs its own
   `if (...) goto call;` - written as one `if (a || b || ...)` the last test is
   inverted and the body goes inline (nd 22). The jal delay slot and the
   table's lui/lw need schedule on. The table must also be called through the
   pointer: `jtbl_008873EC()` is an implicit call to the SYMBOL. */
// FUN_003C5760
#pragma schedule on
s32 func_003c5760(u8 *arg0)
{
    if (*(s32 *)arg0 != 0) {
        goto call;
    }
    if (*(u16 *)(arg0 + 4) != 0) {
        goto call;
    }
    if (*(u16 *)(arg0 + 6) != 0) {
        goto call;
    }
    if (*(s32 *)(arg0 + 8) != 0) {
        goto call;
    }
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto call;
    }
ret:
    return 1;
call:
    (*jtbl_008873EC)();
    goto ret;
}
#pragma schedule off

/* measured: without schedule on, b210 leaves the jr $ra delay slot unfilled
   and colours the increment $v0; retail fills the slot with the store. */
// FUN_003C8CA0
#pragma schedule on
s32 func_003c8ca0(s32 arg0) {
    D_007647EC++;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


void func_003cc460();
void func_003d4e00();
void func_003d4e90();
void func_003d4d70();

/* measured: without #pragma schedule on, MWCC emits ld $ra / addiu $sp /
   jr $ra / nop; retail restores sp in the jr delay slot (nd 6 -> 0). */

// FUN_003C9530
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9530);

// FUN_003C96D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c96d0);

// FUN_003CA830
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca830);

// FUN_003CA890
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca890);

// FUN_003CA8E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca8e0);

// FUN_003CA960
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca960);

// FUN_003CA9D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca9d0);

// FUN_003CB720
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb720);

// FUN_003CB820
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb820);

// FUN_003CB870
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb870);

// FUN_003CBC10
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbc10);

// FUN_003CBC90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbc90);

// FUN_003CC010
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc010);

// FUN_003CC070
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc070);

// FUN_003CC0D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc0d0);

// FUN_003CC130
#pragma schedule on
void func_003cc130(void) {
    func_003cc460();
    func_003d4e00();
    func_003d4e90();
    func_003d4d70();
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC emits addiu $v0, 1 before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CC240
#pragma schedule on
s32 func_003cc240(void) {
    return 1;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


void func_003f32d0();

/* measured (merged TU): schedule on was load-bearing per-unit for the
   jal/jr $ra delay slots, but in the merged TU it worsens the near-miss
   (nd 17 with vs nd 15 without), so the pragma was removed.
   NONMATCHING: retail sinks the if-body out of line (bnez/ b exit; ld ra /
   body / b back / jr ra; addiu sp, 15 instr); b210 compiles every honest
   form of this if inline as a beql skip (13 instr) across 30+ probe
   shapes, so the layout is not reproducible.  Residual: nd 15. */

// FUN_003CC250
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc250);

// FUN_003CC500
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc500);

// FUN_003CC680
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc680);

// FUN_003CC6E0 NONMATCHING
#ifdef NON_MATCHING
void func_003cc6e0(u8 *arg0) {
    if (((s32 *)arg0)[6] != 0) {
        func_003f32d0();
        func_003f32d0();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc6e0);
#endif


extern s32 D_0070B110[];

/* measured: without #pragma schedule on, MWCC emits lui / addiu before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

/* measured: nd 2 of 32 words. schedule on plus no_branch_likely on gets the
   delay slots and the plain bne/bnez; the rest was the shape of the four
   un-merged `return NULL` blocks, which retail keeps separate and in a specific
   order. Reaching the arg2 == 0 case through a goto is what stops case 1's null
   return from pushing case 2's body down - `if (arg2 != 0) {...} return NULL;`
   inside the case costs nd 19 and `break` into a shared tail costs nd 26.
   The residual is two swapped branch targets: retail sends arg0 == NULL to the
   earlier block and arg2 == 0 to the later one, and neither placing the label
   inside the switch nor at the end of the function reverses that. */
// FUN_003CF9B0
#ifdef NON_MATCHING
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003cf9b0(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *sub;

    if (arg0 != NULL) {
        sub = *(u8 **)(arg0 + 0x14);
        if (sub != NULL) {
            switch (arg1) {
            case 1:
                if (arg2 == 0) {
                    goto none;
                }
                *(s32 *)(sub + 0x10) = arg2;
                return arg0;
            case 2:
                *(s32 *)(sub + 0x14) = arg2;
                return arg0;
            default:
                return NULL;
            }
none:
            return NULL;
        }
        return NULL;
    }
    return NULL;
}
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf9b0);
#endif

// FUN_003CFA70
#pragma schedule on
s32 *func_003cfa70(void) {
    return D_0070B110;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
