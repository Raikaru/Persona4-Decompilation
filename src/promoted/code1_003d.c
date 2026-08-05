#include "include_asm.h"
#include "type.h"


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

// FUN_003D3A90
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3a90);

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
// FUN_003D8150
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8150);

// FUN_003D81A0 NONMATCHING
#ifdef NON_MATCHING
s32 func_003d81a0(u32 arg0) {
    if (arg0 < 9U) {
        return (1 << arg0) * 4;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d81a0);
#endif
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
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd530);

// FUN_003DD5C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd5c0);

// FUN_003DD760
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd760);

// FUN_003DD7D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd7d0);

// FUN_003DDC20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddc20);

// FUN_003DDF20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddf20);

// FUN_003DDF80
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddf80);

// FUN_003DDFD0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddfd0);

// FUN_003DF440
#pragma schedule on
s32 func_003df440(s32 arg0) {
    D_0072484C += 1;
    return arg0;
}
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
