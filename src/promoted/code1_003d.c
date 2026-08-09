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
extern s32 func_003d2720(void);
extern s32 func_003dd530(u8 *arg0, s32 arg1);
extern s32 D_0070B470[];


// FUN_003D0140
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0140);
// FUN_003D0230
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0230);
// FUN_003D0460
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0460);
// FUN_003D0540
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0540);
// FUN_003D0790
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0790);
// FUN_003D0850
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0850);
// FUN_003D0930
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0930);
// FUN_003D0970
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0970);
// FUN_003D0FA0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0fa0);
// FUN_003D2010
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d2010);
// FUN_003D20D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d20d0);
// FUN_003D2240
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d2240);
// FUN_003D22F0
/* measured: tailcall on reproduces retail's frameless jump wrapper. */
#pragma tailcall on
s32 func_003d22f0(void) {
    return func_003d2720();
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off
// FUN_003D2300
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d2300);
// FUN_003D2710
/* measured: schedule on places the constant in the jr delay slot. */
#pragma schedule on
s32 func_003d2710(void) {
    return 1;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003D2720
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d2720);
// FUN_003D2C40
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d2c40);
// FUN_003D30B0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d30b0);
// FUN_003D3120
/* measured: schedule on places the zero result in the jr delay slot. */
#pragma schedule on
s32 func_003d3120(void) {
    return 0;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003D3130
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3130);
// FUN_003D3460
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3460);
// FUN_003D35F0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d35f0);
// FUN_003D3780
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3780);
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

// FUN_003D39A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d39a0);

// FUN_003D3A80
/* measured: schedule on places the address addiu in the jr delay slot. */
#pragma schedule on
s32 *func_003d3a80(void) {
    return D_0070B470;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
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

// FUN_003D3AE0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3ae0);
// FUN_003D3BD0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3bd0);
// FUN_003D3E60
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d3e60);
// FUN_003D48C0
/* measured: schedule on places the returned pointer move in the jr delay slot. */
#pragma schedule on
s32 func_003d48c0(s32 arg0, s32 arg1) {
    *(s32 *)(arg0 + arg1) = 0;
    return arg0;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003D48D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d48d0);
// FUN_003D4910
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4910);
// FUN_003D49B0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d49b0);
// FUN_003D4A60
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4a60);
// FUN_003D4B00
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4b00);
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

// FUN_003D4C70
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4c70);
// FUN_003D4EA0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4ea0);
// FUN_003D4F20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4f20);
// FUN_003D4F80
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4f80);
// FUN_003D4FC0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d4fc0);
// FUN_003D5000
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5000);
// FUN_003D5130
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5130);
// FUN_003D51C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d51c0);
// FUN_003D5300
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5300);
// FUN_003D5330
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5330);
// FUN_003D53C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d53c0);
// FUN_003D5600
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5600);
// FUN_003D5710
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5710);
// FUN_003D5750
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5750);
// FUN_003D5790
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5790);
// FUN_003D59A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d59a0);
// FUN_003D59D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d59d0);
// FUN_003D5BC0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5bc0);
// FUN_003D5E40
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5e40);
// FUN_003D5E90
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5e90);
// FUN_003D5F50
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5f50);
// FUN_003D5FB0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5fb0);
// FUN_003D6010
#pragma schedule on
s32 func_003d6010(u8 *arg0) {
    func_003df7f0(*(s32 *)(arg0 + 0x10));
    return 1;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 18 -> 0). */

// FUN_003D6030
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d6030);
// FUN_003D60D0
/* measured: schedule on places the field load in the jr delay slot. */
#pragma schedule on
s32 func_003d60d0(u8 *arg0) {
    return *(s32 *)(arg0 + 0x14);
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003D7B40
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d7b40);
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

// FUN_003D7CF0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d7cf0);
// FUN_003D8060
/* measured: schedule on places the field load in the jr delay slot. */
#pragma schedule on
s32 func_003d8060(u8 *arg0) {
    return *(s32 *)(arg0 + 0x14);
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003D8070
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8070);
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

// FUN_003D81D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d81d0);
// FUN_003D8300
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8300);
// FUN_003D8500
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8500);
// FUN_003D86A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d86a0);
// FUN_003D8760
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8760);
// FUN_003D8C00
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8c00);
// FUN_003D96B0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d96b0);
// FUN_003D9760
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d9760);
// FUN_003D9F30
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d9f30);
// FUN_003DB190
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db190);
// FUN_003DB360
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db360);
// FUN_003DB440
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db440);
// FUN_003DB480
/* measured: schedule on places the comparison result in the jr delay slot. */
#pragma schedule on
s32 func_003db480(s32 *arg0, s32 arg1) {
    return *arg0 == arg1;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003DB490
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db490);
// FUN_003DB550
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db550);
// FUN_003DB630
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db630);
// FUN_003DBBC0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dbbc0);
// FUN_003DBE40
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dbe40);
// FUN_003DC370
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc370);
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

// FUN_003DC610
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc610);
// FUN_003DC740
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc740);
// FUN_003DCB40
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dcb40);
// FUN_003DCC70
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dcc70);
// FUN_003DD290
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd290);
// FUN_003DD390
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd390);
// FUN_003DD430
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd430);
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

// FUN_003DD590
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd590);
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
// FUN_003DD620
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd620);

// FUN_003DD6D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd6d0);

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

// FUN_003DD830
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd830);
// FUN_003DD900
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd900);
// FUN_003DD990
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd990);
// FUN_003DDA50
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dda50);
// FUN_003DDC10
/* measured: schedule on places the global address addiu in the jr delay slot. */
#pragma schedule on
s32 **func_003ddc10(void) {
    return (s32 **)&D_00887180;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
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

// FUN_003DDCA0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddca0);
// FUN_003DDDE0
/* measured: schedule on places the global store in the jr delay slot. */
#pragma schedule on
void func_003ddde0(s32 arg0) {
    D_00724840 = arg0;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003DDDF0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dddf0);
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

// FUN_003DE020
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de020);
// FUN_003DE100
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de100);
// FUN_003DE110
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de110);
// FUN_003DE280
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de280);
// FUN_003DE2C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de2c0);
// FUN_003DE2D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de2d0);
// FUN_003DE4C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de4c0);
// FUN_003DE4D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de4d0);
// FUN_003DE6A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de6a0);
// FUN_003DE740
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de740);
// FUN_003DE8C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de8c0);
// FUN_003DE9B0
/* measured: schedule on places the field store in the jr delay slot and
   preserves the result in $v0. */
#pragma schedule on
s32 func_003de9b0(u8 *arg0) {
    *(s32 *)(arg0 + 0x38) = 1;
    return 1;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003DE9C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de9c0);
// FUN_003DEA10
/* measured: tailcall on reproduces retail's frameless jump wrapper. */
#pragma tailcall on
s32 func_003dea10(u8 *arg0, s32 arg1) {
    return func_003dd530(arg0, arg1);
}
/* measured: tailcall off closes the single-function bracket. */
#pragma tailcall off
// FUN_003DEA20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dea20);
// FUN_003DED20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ded20);
// FUN_003DEEA0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003deea0);
// FUN_003DEFF0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003deff0);
// FUN_003DF050
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df050);
// FUN_003DF1A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df1a0);
// FUN_003DF240
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df240);
// FUN_003DF270
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df270);
// FUN_003DF2A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df2a0);
// FUN_003DF300
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df300);
// FUN_003DF360
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df360);
// FUN_003DF3C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df3c0);
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

// FUN_003DF480
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df480);
// FUN_003DF4B0
#pragma schedule on
s32 func_003df4b0(s32 arg0) {
    D_00724854 -= 1;
    return arg0;
}
// FUN_003DF4D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df4d0);
// FUN_003DF550
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df550);
// FUN_003DF590
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df590);
// FUN_003DF5D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df5d0);
// FUN_003DF6E0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df6e0);
// FUN_003DF7F0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df7f0);
// FUN_003DF860
s32 func_003df860(u8 *arg0) {
    return *(s32 *)(arg0 + 4);
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


// FUN_003DF890
/* measured: schedule on places the load in the jr delay slot. */
#pragma schedule on
s32 func_003df890(s32 *arg0) {
    return *arg0;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off

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

// FUN_003DF8C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df8c0);
// FUN_003DF9F0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df9f0);
// FUN_003DFF20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dff20);