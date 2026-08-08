#include "include_asm.h"
#include "type.h"

extern void func_003cfa80(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern u8 *func_003dda50(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_004217e0(u8 *arg0);
extern s32 **func_003ce050();
extern s32 iGpffffb728;

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
extern u8 D_0070C260[];


/* measured: separate goto labels preserve retail's distinct null-return targets; exact match nd 0 (obj 52B/window 64B). */
// FUN_003D38E0
/* measured: opening branch-shape pragmas preserve retail's two out-of-line null returns (nd 0). */
#pragma no_branch_likely on
#pragma schedule on
u8 *func_003d38e0(u8 *arg0, s32 arg1) {
    u8 *temp_2;

    if (arg0 == NULL) {
        goto block_1;
    }
    temp_2 = *(u8 **)(arg0 + 0x14);
    if (temp_2 == NULL) {
        goto block_2;
    }
    *(s32 *)(temp_2 + 0x14) = arg1;
    return arg0;
block_1:
    return NULL;
block_2:
    return NULL;
}
/* measured: closes the branch-shape pragma bracket (nd 0). */
#pragma schedule off
#pragma no_branch_likely off


void func_003df7f0(s32 arg0);

/* measured: explicit block labels, no_branch_likely, schedule, and the direct
   default-path store `*(s32 *)(*(u8 **)(arg0 + 0x14) + 0x1C) = 0x20` reproduce
   retail exactly. Compiled C MATCH, object 116B/window 128B. */

// FUN_003D3920
/* measured: probe branch form */
#pragma no_branch_likely on
/* measured: probe schedule */
#pragma schedule on
u8 *func_003d3920(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *temp_7;
    if (arg0 == NULL) goto block_1;
    temp_7 = *(u8 **)(arg0 + 0x14);
    if (temp_7 == NULL) goto block_2;
    if (arg1 == NULL) goto block_default;
    if (arg2 != 0) goto block_custom;
    return NULL;
block_1:
    return NULL;
block_2:
    return NULL;
block_custom:
    *(u8 **)(temp_7 + 0x18) = arg1;
    temp_7 = *(u8 **)(arg0 + 0x14);
    *(s32 *)(temp_7 + 0x1C) = arg2;
    goto block_return;
block_return:
    return arg0;
block_default:
    *(u8 **)(temp_7 + 0x18) = D_0070C260;
    *(s32 *)(*(u8 **)(arg0 + 0x14) + 0x1C) = 0x20;
    goto block_return;
}
/* measured: close schedule */
#pragma schedule off
/* measured: close branch form */
#pragma no_branch_likely off


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
/* measured: no_branch_likely and schedule on reproduce retail's explicit
   result-pointer branch/call layout (MATCH; normalized_diff 0, object 124
   bytes in the 128-byte retail slot). */
#pragma no_branch_likely on
#pragma schedule on
s32 func_003d4bf0(u8 *arg0) {
    u8 *temp5;
    s32 **var4;
    s32 **result;
    u8 *flag;

    temp5 = *(u8 **)(arg0 + 0x78);
    if (temp5 == NULL) goto ret_one;
    var4 = (s32 **)(arg0 + iGpffffb728);
    flag = NULL;
    if (*var4 == NULL) goto flag_done;
    if (*(u16 *)(temp5 + 4) != **var4) goto flag_done;
    flag = (u8 *)1;
flag_done:
    if (flag != NULL) {
        result = var4;
    } else {
        result = func_003ce050(var4, *(u16 *)(temp5 + 4), flag);
    }
    if (*result != NULL) goto ret_one;
    return 0;
ret_one:
    return 1;
}
/* measured: closes the no_branch_likely/schedule brackets above. */
#pragma schedule off
#pragma no_branch_likely off

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


/* measured: the XOR booleanisation plus schedule/no_branch_likely reproduce
   retail's sltu/xori and plain branch sequence. Compiled C MATCH, object 68B
   in the 80B window. */
// FUN_003D8150
/* measured: schedule on for func_003d8150. */
#pragma schedule on
/* measured: no_branch_likely on for func_003d8150. */
#pragma no_branch_likely on
s32 func_003d8150(s32 arg0) {
    u32 i;
    u32 *p;
    u32 nz;
    i = 0;
    p = (u32 *)(arg0 + D_0072483C);
scan:
    nz = (p[2] != 0);
    nz ^= 1;
    if (nz != 0)
        goto step;
    return 1;
step:
    p++;
    i++;
    if (i < 8)
        goto scan;
    return 0;
}
/* measured: close no_branch_likely for func_003d8150. */
#pragma no_branch_likely off
/* measured: close schedule for func_003d8150. */
#pragma schedule off

/* measured: schedule on remains required by func_003d81a0 (nd 18 -> MATCH);
   the existing schedule-off close follows that function. */
#pragma schedule on
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

/* measured: retail uses the custom R5900 c1 opcode 0x500C4 for reciprocal-
   square-root refinement; MWCCPS2 b210 emits no equivalent from legal C.
   Bare INCLUDE_ASM is retained. */

// FUN_003DC490
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc490);

/* measured: retail uses the custom R5900 c1 opcode 0x500C4 for reciprocal-
   square-root refinement; MWCCPS2 b210 emits no equivalent from legal C.
   Bare INCLUDE_ASM is retained. */
// FUN_003DC510
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc510);

/* measured: retail uses the custom R5900 c1 opcode 0x500C4 for reciprocal-
   square-root refinement; MWCCPS2 b210 emits no equivalent from legal C.
   Bare INCLUDE_ASM is retained. */
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

/* measured: schedule-on direct-global reconstruction improved nd 49 to nd 18;
   candidate object 104B versus the 112B retail window, so it is parked below
   the nd 25 limit. Body archived in build/W9Code1_003dd760_archive.txt.
   Residual rows are the global-address register/order differences at offsets
   0x10-0x1c, 0x28-0x2c, 0x4c, and 0x54-0x58, plus the missing final padding.
   Ruled out: no_branch_likely alone, no_branch_likely with schedule, 0 versus
   NULL, and moving the A4 store after the call. Committed at nd 18. */
// FUN_003DD760 NONMATCHING
#ifdef NON_MATCHING
/* measured: schedule on for func_003dd760. */
#pragma schedule on
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
/* measured: schedule off for func_003dd760. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd760);
#endif

// FUN_003DD7D0
/* measured: probe */
#pragma no_branch_likely on
#pragma schedule on
s32 func_003dd7d0(void) {
    s32 count;
    s32 next;
    void (*fn)(s32);

    count = D_00887184[0];
    if (count <= 0) goto ret_one;
    next = D_00887188[0] + 1;
    if (count >= next) goto ret_one;
    fn = (void (*)(s32))D_00887194[0];
    if (fn == NULL) goto ret_zero;
    fn(5);
ret_zero:
    return 0;
ret_one:
    return 1;
}
/* measured: probe close */
#pragma schedule off
#pragma no_branch_likely off

// FUN_003DDC20
extern s32 (*D_008873D0[])(u8 *, s32);
/* measured: retail's saved self assignment is in the initial branch delay slot;
   schedule and no_branch_likely reproduce the callback loop layout. */
#pragma schedule on
#pragma no_branch_likely on
s32 *func_003ddc20(u8 *arg0) {
    u8 *self;
    u8 *node;
    s32 (**table)(u8 *, s32);

    node = (u8 *)D_00887180[0];
    self = arg0;
    if (node != NULL) {
        table = D_008873D0;
        do {
            if (table[0](self, *(s32 *)(node + 0xC)) == 0) {
                return (s32 *)node;
            }
            node = *(u8 **)node;
        } while (node != NULL);
    }
    return NULL;
}
/* measured: closes the schedule/no_branch_likely bracket for func_003ddc20. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_003DDF20
extern void func_00421800(s32 arg0);
extern void func_00421820(s32 arg0);
extern s32 iGpffffb754;
/* measured: the wide argument on both 004218x0 calls fills the two retail
   jal delay slots; schedule on reproduces the saved-register dispatch. */
#pragma schedule on
s32 func_003ddf20(u8 *arg0) {
    u8 *temp;
    void (*fn)(u8 *);

    temp = (u8 *)(*(s32 *)(arg0 + 0x50) + 0x28);
    func_00421820(iGpffffb754);
    *(s32 *)(arg0 + 0x38) = 1;
    fn = *(void (**)(u8 *))(temp + 4);
    fn(arg0);
    func_00421800(iGpffffb754);
    return 0;
}
/* measured: closes the schedule bracket for func_003ddf20. */
#pragma schedule off

/* measured: retail uses the three-operand R5900 `mult $6,$16,$6`; MWCCPS2
   b210 cannot emit this form from legal C. Bare INCLUDE_ASM is retained. */
// FUN_003DDF80
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddf80);

/* measured: retail uses the three-operand R5900 `mult $6,$16,$6`; MWCCPS2
   b210 cannot emit this form from legal C. Bare INCLUDE_ASM is retained. */
// FUN_003DDFD0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddfd0);

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
   matching gap.  Residual nd 8 (the mult word).
   Committed at nd 8. */

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
