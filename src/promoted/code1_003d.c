#include "include_asm.h"
#include "type.h"
typedef char *va_list;
#define va_start(ap, last) (ap = (va_list)(s32)(__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8))
#define va_end(ap) ((void)0)

extern void func_003cfa80(u8 *arg0, s32 arg1, f32 arg2, f32 arg3);
extern u8 *func_003dda50(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_004217e0(u8 *arg0);
extern s32 **func_003ce050();
extern s32 iGpffffb728;
extern s32 iGpffffb730;
extern s32 iGpffffb72c;
extern s32 iGpffffab50;

extern s32 D_00887180[];
extern s32 D_00887184[];
extern s32 D_00887188[];
extern s32 D_0088718C[];
extern void *D_00887194[];
extern u8 D_008871A0[];
extern s32 D_008871A4[];
extern s32 D_008871A8[];
extern s32 D_00724840;
extern u8 D_008872E0[];
extern u8 D_00887150[];
extern s32 iGpffffab1c;
extern s32 iGpffffab20;
extern s32 iGpffffb760;
extern s32 D_00724844;
extern u8 D_0070C260[];
extern s32 func_003d2720(void);
extern void func_003db360(u8 *arg0, u8 *arg1);
extern u8 *func_003d5790(s32 arg0, s32 arg1);
extern s32 func_003db480(s32 *arg0, s32 arg1);
extern s32 func_003dd530(u8 *arg0, s32 arg1);
extern s32 D_0070B470[];
extern void func_003d3e60(void);
extern void func_003d0fa0(void);
extern void func_003cdfa0(u8 *arg0);
extern s32 func_003e8930(s32 arg0, s32 arg1, void *arg2, void *arg3);
extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
extern s32 func_003d4f20(s32 arg0);
extern void (*jtbl_008873EC[])();
extern s32 func_003e2ab0();
extern s32 func_003de8c0(u8 *arg0, s32 arg1);
extern void func_003d59d0(f32 arg0);
extern void func_003d5bc0(f32 arg0);
extern s32 iGpffffb738;
extern s32 iGpffffb734;
extern void func_003e12f0();
extern void func_0043f810(void *dst, void *src, u32 size);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void func_00426f80(s32 arg0);
extern s32 func_003c1ab0();
extern s32 func_003c1b40();
extern s32 func_003c2b70();
extern s32 func_003c8d00();
extern s32 func_003c8d60();
extern s32 D_00886E50[];
extern s32 func_003df590(s64 arg0, ...);
extern u8 *func_003df4d0();
static inline s32 func_003d_add_offset(s32 base, s32 offset) {
    return base + offset;
}



// FUN_003D0140
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0140);
// FUN_003D0230
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0230);
// FUN_003D0460 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0460);
// FUN_003D0540
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0540);
// FUN_003D0790 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0790);
// FUN_003D0850 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0850);
/* measured: a local 0xFF limit plus schedule on reproduces retail's
   constant materialization and branch delay-slot layout exactly (nd 0). */
// FUN_003D0930
#pragma schedule on
void func_003d0930(u8 *arg0) {
    s32 limit;
    limit = 0xFF;
    if (*(u8 *)(*(u8 **)(arg0 + 8)) == limit) {
        func_003d3e60();
    } else {
        func_003d0fa0();
    }
}
/* measured: closes schedule around func_003d0930. */
#pragma schedule off
// FUN_003D0970
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0970);
// FUN_003D0FA0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d0fa0);
// FUN_003D2010 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d2010);
// FUN_003D20D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d20d0);
/* measured: object 160B vs 176B window, normalized_diff 64; schedule-on
   prologue/call ordering solved, but repeated pointer-load and tail residuals
   remain. Body archived in build/K3D5_003d2240_body.c. */
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
/* measured: F3D1 legal-C body archived in build/F3D1_003d30b0_body.c;
   object 112/window 112, normalized_diff 57; restored to ASM after callback branch/delay-slot and store-order probes. */
// FUN_003D30B0 NONMATCHING
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


s32 func_003df7f0();

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
/* measured: no_branch_likely and schedule on preserve retail's null branch
   and stack restore in the jr delay slot. */
#pragma no_branch_likely on
#pragma schedule on
u8 *func_003d48d0(u8 *arg0, s32 arg1) {
    u8 *p;
    p = *(u8 **)(arg0 + arg1);
    if (p == NULL) {
        goto done;
    }
    func_003cdfa0(p);
done:
    return arg0;
}
/* measured: closes the no_branch_likely/schedule brackets. */
#pragma schedule off
#pragma no_branch_likely off
/* measured probe: schedule/no_branch_likely tested for 003d4910 branch graph. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003D4910
u8 *func_003d4910(u8 *arg0) {
    u8 *saved_arg0;
    u8 *temp5;
    s32 **var4;
    s32 **result;
    u8 *flag;

    saved_arg0 = arg0;
    temp5 = *(u8 **)(arg0 + 0x54);
    if (temp5 == NULL) goto clear_temp;
    var4 = (s32 **)(saved_arg0 + iGpffffb730);
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
    if (*result != NULL) goto ret_arg0;
    return NULL;
ret_arg0:
    return saved_arg0;
clear_temp:
    *(s32 *)(saved_arg0 + iGpffffb730) = 0;
    goto ret_arg0;
}
/* measured probe: close schedule/no_branch_likely around 003d4910. */
#pragma schedule off
#pragma no_branch_likely off
/* measured probe: schedule/no_branch_likely tested for 003d49b0 branch graph. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003D49B0
u8 *func_003d49b0(u8 *arg0) {
    u8 *saved_arg0;
    u8 *object;
    u8 *temp5;
    s32 value;
    s32 **var4;
    s32 **result;
    u8 *flag;
    saved_arg0 = arg0;
    object = *(u8 **)(arg0 + 0x18);
    temp5 = *(u8 **)(object + 0x54);
    if (temp5 == NULL) goto clear_temp;
    value = *(s32 *)(object + 0x18);
    if (value <= 1) goto clear_temp;
    var4 = (s32 **)(saved_arg0 + iGpffffb72c);
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
    if (*result != NULL) goto ret_arg0;
    return NULL;
ret_arg0:
    return saved_arg0;
clear_temp:
    *(s32 *)(saved_arg0 + iGpffffb72c) = 0;
    goto ret_arg0;
}
/* measured probe: close schedule/no_branch_likely around 003d49b0. */
#pragma schedule off
#pragma no_branch_likely off
/* measured probe: schedule/no_branch_likely tested for 003d4a60 branch graph. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003D4A60
u8 *func_003d4a60(u8 *arg0) {
    u8 *saved_arg0;
    u8 *temp5;
    s32 **var4;
    s32 **result;
    u8 *flag;

    saved_arg0 = arg0;
    temp5 = *(u8 **)(arg0 + 0x78);
    if (temp5 == NULL) goto clear_temp;
    var4 = (s32 **)(saved_arg0 + iGpffffb728);
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
    if (*result != NULL) goto ret_arg0;
    return NULL;
ret_arg0:
    return saved_arg0;
clear_temp:
    *(s32 *)(saved_arg0 + iGpffffb728) = 0;
    goto ret_arg0;
}
/* measured probe: close schedule/no_branch_likely around 003d4a60. */
#pragma schedule off
#pragma no_branch_likely off
/* measured probe: no_branch_likely and schedule tested for 003d4b00 branch graph. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003D4B00
s32 func_003d4b00(u8 *arg0) {
    u8 *object;
    u8 *temp6;
    s32 count;
    s32 one;
    s32 **var4;
    s32 **result;
    u8 *flag;

    object = *(u8 **)(arg0 + 0x18);
    temp6 = *(u8 **)(object + 0x54);
    if (temp6 == NULL) goto ret_one;
    count = *(s32 *)(object + 0x18);
    one = 1;
    if (count != one) goto second_path;
    var4 = (s32 **)(object + iGpffffb730);
    flag = NULL;
    if (*var4 == NULL) goto first_flag_done;
    if (*(u16 *)(temp6 + 4) != **var4) goto first_flag_done;
    flag = (u8 *)one;
first_flag_done:
    if (flag != NULL) {
        result = var4;
    } else {
        result = func_003ce050(var4, *(u16 *)(temp6 + 4), temp6, flag);
    }
    if (*result != NULL) goto ret_one;
    return 0;
ret_one:
    return 1;
second_path:
    var4 = (s32 **)(arg0 + iGpffffb72c);
    flag = NULL;
    if (*var4 == NULL) goto second_flag_done;
    if (*(u16 *)(temp6 + 4) != **var4) goto second_flag_done;
    flag = (u8 *)one;
second_flag_done:
    if (flag != NULL) {
        result = var4;
    } else {
        result = func_003ce050(var4, *(u16 *)(temp6 + 4), temp6, flag);
    }
    if (*result != NULL) goto ret_one;
    return 0;
}
/* measured probe: close no_branch_likely/schedule around 003d4b00. */
#pragma schedule off
#pragma no_branch_likely off
// FUN_003D4BF0
/* measured: no_branch_likely and schedule on reproduce retail's explicit
   result-pointer branch/call layout (MATCH; normalized_diff 0, object 124
   bytes in the 128-byte retail slot). */
#pragma no_branch_likely on
/* measured: schedule knob retains the func_003d4bf0 bracket. */
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

/* measured: schedule and no_branch_likely probe for func_003d4c70. */
#pragma schedule on
/* measured: no_branch_likely probe for func_003d4c70. */
#pragma no_branch_likely on
// FUN_003D4C70
s32 func_003d4c70(void) {
    s32 temp_17;
    s32 var_16;
    s32 aggregate;

    var_16 = 0;
    temp_17 = 0;
    iGpffffb730 = func_003c2b70(4, 0x50F, func_003d48c0, func_003d48d0, func_003d4910);
    iGpffffb72c = func_003c1ab0(4, 0x50F, func_003d48c0, func_003d48d0, func_003d49b0);
    iGpffffb728 = func_003c8d00(4, 0x50F, func_003d48c0, func_003d48d0, func_003d4a60);
    temp_17 |= func_003c1b40(0x50F, func_003d4b00);
    aggregate = temp_17 | func_003c8d60(0x50F, func_003d4bf0);
    if ((aggregate | (iGpffffb728 | (iGpffffb730 | iGpffffb72c))) >= 0) {
        var_16 = 1;
    }
    return var_16;
}
/* measured: closes schedule around func_003d4c70. */
#pragma schedule off
/* measured: closes no_branch_likely around func_003d4c70. */
#pragma no_branch_likely off
/* measured: schedule/no_branch_likely preserves 4ea0's callback branch and
   stack-local call sequence. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003D4EA0
s32 func_003d4ea0(void) {
    extern s32 func_0039b6e0(s32 arg0);
    extern void func_003cc070(s32 arg0);
    extern s32 func_003df590(s32 arg0, void *arg1);
    extern u8 *func_003df4d0(s32 *arg0);
    extern u8 D_0070B5D0[];
    extern s32 iGpffffb9b8;
    struct {
        s32 sp18;
        s32 sp1C;
    } frame;
    s32 temp_2;
    u8 *base;

    temp_2 = func_0039b6e0(0x1002);
    base = D_008872E0 + iGpffffb9b8;
    *(s32 *)(base + 0x54) = temp_2;
    if (temp_2 != 0) {
        func_003cc070(temp_2);
        return 1;
    }
    func_003cc070(0);
    frame.sp18 = 2;
    frame.sp1C = func_003df590(0x80000006, D_0070B5D0);
    func_003df4d0(&frame.sp18);
    return 1;
}
/* measured: closes no_branch_likely/schedule around func_003d4ea0. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: opt_propagation off probe keeps the callback result live
   through the explicit branch graph. */
#pragma opt_propagation off
#pragma schedule on
// FUN_003D4F20
s32 func_003d4f20(s32 arg0) {
    s32 temp;

    temp = func_003e1220(0x18, iGpffffab1c, 4, iGpffffab20, D_00887150, 0x4001B);
    iGpffffb738 = temp;
    if (temp != 0) {
        goto return_arg0_4f20;
    }
    goto fail_4f20;
return_arg0_4f20:
    return arg0;
fail_4f20:
    arg0 = 0;
    goto return_arg0_4f20;
}
/* measured: closes opt_propagation around func_003d4f20. */
#pragma opt_propagation on
#pragma schedule off
/* measured: schedule on moves the independent GP store into the retail branch
   delay slot and preserves the saved callback argument across the call. */
#pragma schedule on
// FUN_003D4F80
s32 func_003d4f80(s32 arg0) {
    s32 temp_4;

    temp_4 = iGpffffb738;
    iGpffffb734 = 0;
    if (temp_4 != 0) {
        func_003e12f0(temp_4);
        iGpffffb738 = 0;
    }
    return arg0;
}
/* measured: closes the single-function schedule bracket for func_003d4f80. */
#pragma schedule off
/* measured: schedule on hoists callback address materialisation before the
   save and fills the final call setup as retail does. */
#pragma schedule on
// FUN_003D4FC0
s32 func_003d4fc0(void) {
    return func_003e8930(0, 0x1B7, func_003d4f20, func_003d4f80) > 0;
}
/* measured: closes the schedule bracket. */
#pragma schedule off
// FUN_003D5000
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5000);
/* measured: object 148B vs 144B window, normalized_diff 91; oversized
   reconstruction archived in build/K3D5_003d5130_body.c. */
// FUN_003D5130 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5130);
// FUN_003D51C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d51c0);
/* measured: schedule on reproduces the callback address-load, branch delay,
   and epilogue order for func_003d5300; exact MATCH (48B). */
#pragma schedule on
// FUN_003D5300
s32 func_003d5300(u8 *arg0) {
    jtbl_008873EC[0]();
    return 1;
}
/* measured: closes schedule around func_003d5300. */
#pragma schedule off
/* measured: object 136B vs 144B window, normalized_diff 23; the
   schedule/no_branch_likely residual and two-word tail padding are archived
   in build/K3D5_003d5330_body.c. */
// FUN_003D5330
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5330);
// FUN_003D53C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d53c0);
// FUN_003D5600
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5600);
// FUN_003D5710 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5710);
// FUN_003D5750 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5750);
/* measured: object 164B vs 160B window, normalized_diff 70; oversized
   reconstruction archived in build/K3D5_003d5790_body.c. */
// FUN_003D5790
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5790);
// FUN_003D59A0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d59a0);
// FUN_003D59D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d59d0);
// FUN_003D5BC0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5bc0);
/* measured: schedule on reproduces the retail float helper's branch and
   fills the final stack-restore delay slot; probe matched at nd 0. */
// FUN_003D5E40
#pragma schedule on
s32 func_003d5e40(u8 *arg0, f32 fparg0) {
    f32 value;

    value = fparg0 - *(f32 *)(arg0 + 4);
    if (value < 0.0f) {
        func_003d59d0(-value);
    } else {
        func_003d5bc0(value);
    }
    return 1;
}
/* measured: closes the single-function schedule bracket for func_003d5e40. */
#pragma schedule off
// FUN_003D5E90 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5e90);
/* measured: the explicit -1 fallback and scheduled callback setup reproduce
   the 96-byte retail frame and call delay slot exactly. */
#pragma schedule on
// FUN_003D5F50
void func_003d5f50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_7;
    u8 *temp_2;

    var_7 = arg3;
    if (var_7 == -1) {
        var_7 = *(s32 *)(arg0 + 0x20);
    }
    temp_2 = func_003d5790(arg2, var_7);
    *(u8 **)(temp_2 + 0x38) = arg0;
    *(s32 *)(temp_2 + 0x34) = arg1;
    *(s32 *)(temp_2 + 0x30) = 1;
}
/* measured: closes the single-function schedule bracket for func_003d5f50. */
#pragma schedule off
// FUN_003D5FB0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d5fb0);
// FUN_003D6010
/* measured: schedule bracket retained for func_003d6010. */
#pragma schedule on
s32 func_003d6010(u8 *arg0) {
    func_003df7f0(*(s32 *)(arg0 + 0x10));
    return 1;
}
/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 18 -> 0). */
#pragma schedule off

/* measured: no_branch_likely/schedule preserve 6030's plain scan and
   callback delay-slot setup. */
#pragma no_branch_likely on
#pragma schedule on
// FUN_003D6030
u8 *func_003d6030(u8 *arg0, u8 *arg1) {
    extern s32 func_003df860(u8 *arg0);
    extern s32 *func_003df870(s32 *arg0, s32 arg1);
    extern s32 func_003df890(s32 *arg0);
    extern s32 func_003df8a0(s32 *arg0);
    extern void func_003df7e0(s32 arg0, s32 arg1);
    s32 *start;
    s32 *end;
    u8 *self;

    self = arg0;
    start = (s32 *)func_003df890(*(s32 **)(self + 0x10));
    end = (s32 *)func_003df8a0(*(s32 **)(self + 0x10));
    if (start != end) {
        do {
            if (arg1 == (u8 *)start[0]) {
                start[0] = *func_003df870(*(s32 **)(self + 0x10),
                    func_003df860(*(u8 **)(self + 0x10)) - 1);
                func_003df7e0((s32)*(s32 **)(self + 0x10), 1);
                return self;
            }
            start += 1;
        } while (start != end);
    }
    return NULL;
}
/* measured: closes no_branch_likely/schedule around func_003d6030. */
#pragma schedule off
#pragma no_branch_likely off
#pragma schedule on
// FUN_003D60D0
s32 func_003d60d0(u8 *arg0) {
    return *(s32 *)(arg0 + 0x14);
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003D7B40
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d7b40);
/* measured: best body archived in build/H3D3_003d7c50_body.c; object 128B/window 128B, normalized_diff 0 under assembly fallback. */
// FUN_003D7C50 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d7c50);
// FUN_003D7CD0
/* measured: schedule bracket retained for func_003d7cd0. */
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
// FUN_003D8070 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d8070);
// FUN_003D8130
/* measured: schedule bracket retained for func_003d8130. */
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
/* measured: schedule/no_branch_likely preserve the helper-call argument
   order and the two out-of-line null-return paths. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003D96B0
u8 *func_003d96b0(u8 *arg0, s32 arg1) {
    u8 *temp2;
    s32 var16;
    extern u8 *func_003e2f60(s32, s32, s32);
    extern void func_003d81d0(u8 *, s32, u8 *);
    extern void func_003d8300(u8 *, s32, u8 *);
    extern s32 func_003d86a0(s8 *, s32, u8 *);
    extern s32 func_003d81a0(s32);
    extern void func_003e2e40(u8 *, s32);

    temp2 = func_003e2f60(2, 2, arg1);
    if (temp2 == NULL) {
        goto done;
    }
    var16 = 0x18;
    if (*(s32 *)(arg0 + 0x18) != 0) {
        var16 = *(s32 *)(arg0 + 0xC);
    }
    func_003d81d0(temp2, var16, arg0);
    func_003d8300(temp2, var16, arg0);
    func_003d86a0((s8 *)temp2, var16, arg0);
    func_003d81a0(var16);
    func_003e2e40(temp2, 0);
    return arg0;
done:
    return NULL;
}
/* measured: closes schedule/no_branch_likely around func_003d96b0. */
#pragma no_branch_likely off
#pragma schedule off
// FUN_003D9760
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d9760);
// FUN_003D9F30
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003d9f30);
// FUN_003DB190
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db190);
// FUN_003DB360
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003db360);
/* measured: the callback setup and hidden two-argument func_003db360 call
   require schedule on to match retail's prologue and jal delay slot. */
#pragma schedule on
// FUN_003DB440
s32 func_003db440(s32 arg0, u8 *arg1) {
    *(s32 (**)(s32 *, s32))(arg1 + 0x18) = func_003db480;
    func_003db360((u8 *)arg0, arg1);
    return arg0;
}
/* measured: closes the schedule bracket around func_003db440. */
#pragma schedule off
// FUN_003DB480
/* measured: schedule on places the comparison result in the jr delay slot. */
#pragma schedule on
s32 func_003db480(s32 *arg0, s32 arg1) {
    return *arg0 == arg1;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off
// FUN_003DB490 NONMATCHING
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
/* measured: corrected sqrtf/sqrt.s reconstruction is archived in
   build/W3RSQ_003dc490_body.c (object 124/window 128, normalized_diff 24).
   The source fallback remains ASM after the capped register-pressure probes. */
/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
// FUN_003DC490 NONMATCHING
#ifdef NON_MATCHING
u8 *func_003dc490(u8 *arg0, u8 *arg1) {
    f32 m00;
    f32 m11;
    f32 m22;
    f32 m21;
    f32 m12;
    f32 m01;
    f32 m10;
    f32 m02;
    f32 m20;
    f32 root;
    f32 scale;
    extern f32 sqrtf(f32);

    m00 = *(f32 *)(arg1 + 0x00);
    m11 = *(f32 *)(arg1 + 0x14);
    m22 = *(f32 *)(arg1 + 0x28);
    m21 = *(f32 *)(arg1 + 0x18);
    m12 = *(f32 *)(arg1 + 0x24);
    m01 = *(f32 *)(arg1 + 0x04);
    m10 = *(f32 *)(arg1 + 0x10);
    m02 = *(f32 *)(arg1 + 0x08);
    m20 = *(f32 *)(arg1 + 0x20);
    root = sqrtf(1.0f + (m00 - (m11 + m22)));
    *(f32 *)(arg0 + 0x00) = 0.5f * root;
    scale = 0.5f / root;
    *(f32 *)(arg0 + 0x0C) = scale * (m21 - m12);
    *(f32 *)(arg0 + 0x04) = scale * (m01 + m10);
    *(f32 *)(arg0 + 0x08) = scale * (m02 + m20);
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc490);
#endif
/* measured: corrected sqrtf branch archived in
   build/W3RSQ_003dc510_body.c (object 136/window 128, normalized_diff 33);
   retained ASM after the capped transfer probe. */
/* corrected sqrtf quaternion candidate: object 124B / window 128B / normalized_diff 24 */
// FUN_003DC510 NONMATCHING
#ifdef NON_MATCHING
u8 *func_003dc510(u8 *arg0, u8 *arg1) {
    f32 diff;
    f32 root;
    f32 scale;
    extern f32 sqrtf(f32);

    diff = *(f32 *)(arg1 + 0x20) - *(f32 *)(arg1 + 0x8);
    root = sqrtf(1.0f + (*(f32 *)(arg1 + 0x14) - (*(f32 *)(arg1 + 0x28) + *(f32 *)(arg1 + 0x0))));
    *(f32 *)(arg0 + 0x4) = 0.5f * root;
    scale = 0.5f / root;
    *(f32 *)(arg0 + 0xC) = scale * diff;
    *(f32 *)(arg0 + 0x8) = scale * (*(f32 *)(arg1 + 0x18) + *(f32 *)(arg1 + 0x24));
    *(f32 *)(arg0 + 0x0) = scale * (*(f32 *)(arg1 + 0x10) + *(f32 *)(arg1 + 0x4));
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc510);
#endif
/* measured: no corrected candidate was retained within the capped transfer
   probe; ASM fallback remains. */
/* corrected sqrtf quaternion candidate: object 124B / window 128B / normalized_diff 24 */
// FUN_003DC590 NONMATCHING
#ifdef NON_MATCHING
u8 *func_003dc590(u8 *arg0, u8 *arg1) {
    f32 diff;
    f32 root;
    f32 scale;
    extern f32 sqrtf(f32);

    diff = *(f32 *)(arg1 + 0x4) - *(f32 *)(arg1 + 0x10);
    root = sqrtf(1.0f + (*(f32 *)(arg1 + 0x28) - (*(f32 *)(arg1 + 0x0) + *(f32 *)(arg1 + 0x14))));
    *(f32 *)(arg0 + 0x8) = 0.5f * root;
    scale = 0.5f / root;
    *(f32 *)(arg0 + 0xC) = scale * diff;
    *(f32 *)(arg0 + 0x0) = scale * (*(f32 *)(arg1 + 0x20) + *(f32 *)(arg1 + 0x8));
    *(f32 *)(arg0 + 0x4) = scale * (*(f32 *)(arg1 + 0x24) + *(f32 *)(arg1 + 0x18));
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dc590);
#endif

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
/* measured: object 136B vs 160B window, normalized_diff 79; global-pointer,
   scheduler, and guard-polarity probes archived with residual loop layout in
   build/K3D5_003dd390_body.c. */
// FUN_003DD390
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd390);
// FUN_003DD430 NONMATCHING
#ifdef NON_MATCHING
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define CLZ(x) (0)
s32 func_00442948();                             /* extern */
extern M2C_UNK D_008873AC();
s32 func_003dd430(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    s32 temp_17;
    s32 temp_2;
    s32 var_6;
    s8 *var_5;
    s8 temp_4;

    temp_17 = func_00442948(arg2);
    temp_2 = func_00442948(arg3);
    if ((arg1 - 1) < (temp_17 + temp_2)) {
        return 0;
    }
    D_008873AC(arg0, arg2);
    var_6 = 0;
    if (temp_2 >= 0) {
        var_5 = (s8 *)(arg0 + temp_17);
        do {
            temp_4 = *((u8 *)(arg3 + var_6));
            if ((temp_4 != 0x2F) && (temp_4 != 0x5C)) {
                *var_5 = temp_4;
            } else {
                *var_5 = arg4;
            }
            var_6 += 1;
            var_5 += 1;
        } while (temp_2 >= var_6);
    }
    return arg0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd430);
#endif
// FUN_003DD530
/* measured: b210 if-converts the ret==0 return into a beql with the move
   annulled in its slot; retail uses a plain beqz with the return-0 block out
   of line.  `no_branch_likely on` (with `schedule on` for the prologue's
   arg-setup interleave and the jal delay-slot move) reproduces retail (nd 60
   -> 20 with schedule on -> MATCH with both). */
/* measured: schedule/no_branch_likely bracket retained for func_003dd530. */
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

/* measured: full s64 temporaries preserve retail's ld/slt comparison and
   schedule/no_branch_likely reproduce the branch and delay-slot shape.
   Exact MATCH at nd 0 (object 44 bytes in the 48-byte window). */
// FUN_003DD590
/* measured: schedule/no_branch_likely bracket retained for func_003dd590. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003dd590(u8 *arg0) {
    s64 temp_3;
    temp_3 = *(s64 *)((u8 *)(arg0) + 0x10);
    if (temp_3 == -1) {
        return 1;
    }
    return (s32)(temp_3 >= *(s64 *)((u8 *)(arg0) + 0));
}
/* measured: closes schedule/no_branch_likely around func_003dd590. */
#pragma schedule off
#pragma no_branch_likely off
// FUN_003DD5C0
/* measured: b210 emits a branch-likely (beql) for the case-1 test and
   if-converts the short case-1 body into its delay slot; retail uses a plain
   beq with a nop and keeps both case bodies out of line.  `no_branch_likely on`
   + `schedule on` reproduces retail exactly (switch, cases declared ascending
   1,2; nd 49 -> MATCH). */
/* measured: schedule/no_branch_likely bracket retained for func_003dd6d0. */
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
/* measured: closes schedule/no_branch_likely around func_003dd5c0. */
#pragma schedule off
#pragma no_branch_likely off
// FUN_003DD620 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd620);
/* measured: schedule/no_branch_likely reproduce func_003dd6d0's branch graph. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003DD6D0
void func_003dd6d0(u8 *arg0)
{
    s32 temp_7;
    s32 var_5;

    if (arg0 == NULL) {
        goto block_exit;
    }
    if (*(s32 *)(arg0 + 0x30) == 0) {
        goto block_exit;
    }
    temp_7 = *(s32 *)(arg0 + 0x40);
    if ((temp_7 != 1) &&
        (*(u32 *)(arg0 + 0x48) != 0)) {
        if (temp_7 == 4) {
            var_5 = *(s32 *)(arg0 + 0x10);
        } else {
            var_5 = *(s32 *)(arg0 + 0x44);
        }
        *(s32 *)(arg0 + 0x40) = 1;
        ((void (*)(u8 *, s32, s32, s32, s32))(*(u32 *)(arg0 + 0x48)))(
            arg0, var_5, *(s32 *)(arg0 + 0x38), temp_7,
            *(s32 *)(arg0 + 0x4C));
        goto block_shared;
    }
    goto block_set;
block_shared:
    return;
block_set:
    *(s32 *)(arg0 + 0x40) = 1;
    goto block_shared;
block_exit:
    return;
}
/* measured: closes schedule/no_branch_likely around func_003dd6d0. */
#pragma schedule off
#pragma no_branch_likely off


/* measured: best body archived in build/H3D3_003dd760_body.c; object 104B/window 112B, normalized_diff 13. */
// FUN_003DD760 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dd760);

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
/* measured: schedule/no_branch_likely reproduce DD830's guard, saved-self
   callback, and global-list insertion layout. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003dd830(u8 *arg0) {
    s32 state;
    s32 count;
    s32 next;
    void (*fn)(s32);
    extern u8 *func_003dd900(u8 *arg0);
    extern void func_003dd5c0(u8 **arg0, s32 arg1);

    count = D_00887184[0];
    if (count <= 0)
        goto set_one;
    next = D_00887188[0] + 1;
    if (count >= next)
        goto set_one;
    fn = (void (*)(s32))D_00887194[0];
    if (fn != NULL)
        fn(5);
    state = 0;
check_state:
    if (state != 0)
        goto proceed;
    return 0;
set_one:
    state = 1;
    goto check_state;
proceed:
    if (func_003dd900(arg0 + 0x50) != NULL)
        return 0;
    func_003dd5c0((u8 **)arg0, 1);
    *(u8 **)arg0 = (u8 *)D_00887180[0];
    D_00887180[0] = (s32)arg0;
    D_00887188[0] += 1;
    return 1;
}
/* measured: closes schedule/no_branch_likely around func_003dd830. */
#pragma no_branch_likely off
#pragma schedule off
extern s32 (*D_008873C8[])(u8 *, u8 *);
/* measured: schedule/no_branch_likely reproduce DD900's saved-self callback
   loop, linked-list traversal, and fallback callback placement. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003DD900
u8 *func_003dd900(u8 *arg0) {
    u8 *self;
    u8 *node;
    s32 (**table)(u8 *, u8 *);

    node = (u8 *)D_00887180[0];
    self = arg0;
    if (node != NULL) {
        table = D_008873C8;
        do {
            if (table[0](node + 0x50, self) == 0) {
                return node;
            }
            node = *(u8 **)node;
        } while (node != NULL);
    }
    if (D_00887194[0] != NULL) {
        ((void (*)(s32))D_00887194[0])(6);
    }
    return NULL;
}
/* measured: closes schedule/no_branch_likely around func_003dd900. */
#pragma no_branch_likely off
#pragma schedule off
// FUN_003DD990 NONMATCHING
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

/* measured: F3D1 legal-C body archived in build/F3D1_003ddf80_body.c;
   object 76/window 80, normalized_diff 38; restored to ASM after prologue/epilogue ordering probes. */
// FUN_003DDF80 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddf80);
/* measured: F3D1 legal-C body archived in build/F3D1_003ddfd0_body.c;
   object 76/window 80, normalized_diff 38; restored to ASM after the same ordering residual. */
// FUN_003DDFD0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003ddfd0);


// FUN_003DE020
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de020);
// FUN_003DE100
/* measured: tailcall on reproduces retail's frameless indirect jump. */
#pragma tailcall on
void func_003de100(u8 *arg0) {
    ((void (*)(u8 *))(*(void **)(*(u8 **)(arg0 + 0x50) + 0x44)))(arg0);
}
/* measured: closes the single-function tailcall bracket. */
#pragma tailcall off
// FUN_003DE110
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de110);
/* measured: object 52B/window 64B, normalized_diff 5; best direct-load
   candidate archived in build/F3D0_003de280_body.c with load/shift ORDER
   residual at offsets 16 and 20. */
// FUN_003DE280 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de280);
/* measured: scalar GP slot address and schedule on reproduce retail's
   addiu $v0,$gp,-0x54B0 in the jr delay slot. */
// FUN_003DE2C0
#pragma schedule on
s32 *func_003de2c0(void) {
    return &iGpffffab50;
}
/* measured: closes the single-function schedule bracket. */
#pragma schedule off
// FUN_003DE2D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de2d0);
/* Measured candidate archived in build/WI003d_de4c0_restore.txt: the isolated
   body measured nd 8, but the in-file committed figure was nd 38, above the
   nd 25 park limit. Retained as the bare assembly fallback. */
/* measured: schedule on with tailcall on places the field load in the jump delay slot. */
#pragma schedule on
#pragma tailcall on
// FUN_003DE4C0
void func_003de4c0(u8 *arg0) {
    *(s32 *)(arg0 + 0x38) = 1;
    func_00426f80(*(s32 *)(arg0 + 0x60));
}
/* measured: closes the single-function tailcall/schedule brackets. */
#pragma tailcall off
#pragma schedule off
// FUN_003DE4D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003de4d0);
/* measured: no_branch_likely keeps DE6A0's plain conditional branches. */
#pragma no_branch_likely on
/* measured: schedule reproduces DE6A0's callback-live argument and store
   delay-slot ordering. */
#pragma schedule on
// FUN_003DE6A0
s64 func_003de6a0(u8 *arg0, s32 arg1, s64 arg2) {
    extern s64 sceWrite(s32 arg0);
    s64 temp_4;
    s64 var_17;
    s64 result;

    *(s32 *)(arg0 + 0x38) = 3;
    var_17 = arg2;
    result = sceWrite(*(s32 *)(arg0 + 0x60));
    if (*(s32 *)(arg0 + 0x30) != 0) {
        if (result < 0) {
            var_17 = 0;
        }
        result = var_17;
    }
    *(s32 *)(arg0 + 0x38) = 2;
    if (result > 0) {
        *(s64 *)(arg0 + 0x10) += (s32)result;
        temp_4 = *(s64 *)(arg0 + 0x10);
        if (temp_4 > *(s64 *)arg0) {
            goto block_update;
        }
        goto block_finish;
block_finish:
        return result;
block_update:
        *(s64 *)arg0 = temp_4;
        goto block_finish;
    }
    return 0;
}
/* measured: closes schedule around func_003de6a0. */
#pragma schedule off
/* measured: closes no_branch_likely around func_003de6a0. */
#pragma no_branch_likely off
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
/* measured: schedule reproduces DE9C0's constant/prologue order and
   call-preserving saved-self delay slot. */
#pragma schedule on
// FUN_003DE9C0
s32 func_003de9c0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x38) != 1) {
        goto block_call;
    }
    goto block_done;
block_done:
    return *(s32 *)(arg0 + 0x38);
block_call:
    func_003de8c0(arg0, 0);
    goto block_done;
}
/* measured: closes schedule around func_003de9c0. */
#pragma schedule off
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
/* measured: moving the second-field store after the base packing
   computation lets schedule on reproduce the retail aggregate order exactly
   (nd 0, object 88 bytes/window 96 bytes). */
// FUN_003DEFF0
/* measured: schedule bracket retained for func_003deff0. */
#pragma schedule on
s32 func_003deff0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_8;
    u32 temp_7;
    struct {
        s32 first;
        s32 second;
        s32 third;
    } data;

    temp_8 = arg3 + 0xFFFD0000;
    data.first = arg1;
    temp_7 = (temp_8 & 0x3FF00) << 0xE;
    data.second = arg2;
    data.third = (arg4 & 0xFFFF) | (temp_7 | ((arg3 & 0x3F) << 0x10));
    func_003e2ab0(arg0, &data.first, 0xC);
}
/* measured: closes schedule around func_003deff0. */
#pragma schedule off
// FUN_003DF050
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df050);
/* measured: object 184B vs 160B window, normalized_diff 139; oversized
   reconstruction archived in build/K3D5_003df1a0_body.c. */
// FUN_003DF1A0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df1a0);
/* measured: schedule on is required for the callback's call delay slot,
   copied from the exact 003bf330 twin. */
#pragma schedule on
// FUN_003DF240
s32 func_003df240(s32 arg0) {
    func_003e2ab0((u8 *)arg0);
    return arg0;
}
/* measured: close schedule around func_003df240. */
#pragma schedule off
/* measured: schedule on is required for the callback's call delay slot,
   copied from the exact 003bf330 twin. */
#pragma schedule on
// FUN_003DF270
s32 func_003df270(s32 arg0) {
    func_003e2ab0((u8 *)arg0);
    return arg0;
}
/* measured: close schedule around func_003df270. */
#pragma schedule off
/* measured: an 8-byte leading pad keeps sp28/sp2c at the retail local
   offsets inside the compact 0x30-byte frame. schedule/no_branch_likely
   reproduce the callback branch; tail padding is all-zero. Exact MATCH nd 0. */
// FUN_003DF2A0
/* measured: schedule/no_branch_likely bracket retained for func_003df2a0. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003df2a0(s32 arg0) {
    extern s32 func_003df590(s32 arg0);
    struct {
        u8 pad[8];
        s32 sp28;
        s32 sp2C;
    } frame;
    if (func_003e2910() != 0) {
        return arg0;
    }
    frame.sp28 = 1;
    frame.sp2C = func_003df590(0x8000001A);
    func_003df4d0(&frame.sp28);
    return 0;
}
/* measured: closes schedule/no_branch_likely around func_003df2a0. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: sibling of func_003df2a0; compact 8-byte leading pad pins
   sp28/sp2c and schedule/no_branch_likely reproduce the same exact body.
   MATCH nd 0; retail's trailing words are zero padding. */
// FUN_003DF300
/* measured: schedule/no_branch_likely bracket retained for func_003df300. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003df300(s32 arg0) {
    extern s32 func_003df590(s32 arg0);
    struct {
        u8 pad[8];
        s32 sp28;
        s32 sp2C;
    } frame;
    if (func_003e2910() != 0) {
        return arg0;
    }
    frame.sp28 = 1;
    frame.sp2C = func_003df590(0x8000001A);
    func_003df4d0(&frame.sp28);
    return 0;
}
/* measured: closes schedule/no_branch_likely around func_003df300. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: sibling of func_003df2a0; the same compact frame and
   schedule/no_branch_likely bracket reproduce MATCH nd 0. */
// FUN_003DF360
#pragma schedule on
/* measured: no_branch_likely knob retains the func_003df360 bracket. */
#pragma no_branch_likely on
s32 func_003df360(s32 arg0) {
    extern s32 func_003df590(s32 arg0);
    struct {
        u8 pad[8];
        s32 sp28;
        s32 sp2C;
    } frame;
    if (func_003e2910() != 0) {
        return arg0;
    }
    frame.sp28 = 1;
    frame.sp2C = func_003df590(0x8000001A);
    func_003df4d0(&frame.sp28);
    return 0;
}
/* measured: closes schedule/no_branch_likely around func_003df360. */
#pragma no_branch_likely off
#pragma schedule off
/* measured: func_003deea0 retains the incoming arg0 as its hidden first
   argument before four stack-output pointers. Preserving that ABI order with
   schedule/no_branch_likely yields exact MATCH at nd 0, object/window 128B. */
// FUN_003DF3C0
/* measured: schedule/no_branch_likely bracket retained for func_003df3c0. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003df3c0(s32 arg0, u32 *arg1) {
    u32 sp3C;
    u32 sp38;
    u32 sp34;
    u32 sp30;
    if (func_003deea0(arg0, &sp3C, &sp38, &sp34, &sp30) == 0) {
        return 0;
    }
    *(u32 *)((u8 *)(arg1) + 0) = sp3C;
    *(u32 *)((u8 *)(arg1) + 4) = sp38;
    *(u32 *)((u8 *)(arg1) + 8) = sp34;
    *(u32 *)((u8 *)(arg1) + 0xC) = sp30;
    *(s32 *)((u8 *)(arg1) + 0x10) = func_003ded20(arg1);
    return arg0;
}
/* measured: closes schedule/no_branch_likely around func_003df3c0. */
#pragma no_branch_likely off
#pragma schedule off
// FUN_003DF440
/* measured: schedule bracket retained for func_003df440. */
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
/* measured: schedule bracket retained for func_003df460. */
#pragma schedule on
s32 func_003df460(s32 arg0) {
    D_0072484C -= 1;
    return arg0;
}
/* measured: closes the bracket noted above the marker. */
#pragma schedule off


extern s32 D_00724854;

/* measured: schedule on keeps the initial arg1 store and final counter store
   in the retail order while retaining the returned arg0. */
#pragma schedule on
// FUN_003DF480
s32 func_003df480(s32 arg0, s32 arg1) {
    s32 counter;

    iGpffffb760 = arg1;
    counter = D_00724854;
    *(s32 *)(D_008872E0 + arg1) = 0;
    *(s32 *)(D_008872E0 + arg1 + 4) = 0x80000000;
    D_00724854 = counter + 1;
    return arg0;
}
// FUN_003DF4B0
s32 func_003df4b0(s32 arg0) {
    D_00724854 -= 1;
    return arg0;
}
/* measured: no_branch_likely on preserves retail's plain branch chain. */
#pragma no_branch_likely on
// FUN_003DF4D0
u8 *func_003df4d0(s32 *arg0) {
    u8 *input;
    u8 *base;
    u8 *base2;
    input = (u8 *)arg0;
    base = D_008872E0 + iGpffffb760;
    if (*(s32 *)(base + 0) != 0) {
        goto done;
    }
    if (*(s32 *)(base + 4) != 0x80000000) {
        goto done;
    }
    if ((*(s32 *)(input + 4) & 0x80000000) != 0) {
        goto zero;
    }
    *(s32 *)(base + 0) = *(s32 *)(input + 0);
final_store:
    base2 = D_008872E0 + iGpffffb760;
    *(s32 *)(base2 + 4) = *(s32 *)(input + 4);
done:
    return input;
zero:
    *(s32 *)(base + 0) = 0;
    goto final_store;
}
/* measured: closes the no_branch_likely bracket opened above func_003df4d0. */
#pragma no_branch_likely off
/* measured: opt_propagation off probe preserves retail's paired float loads. */
#pragma opt_propagation off
// FUN_003DF550
u8 *func_003df550(u8 *arg0) {
    f32 value0;
    f32 value1;
    u8 *base;
    base = D_008872E0 + iGpffffb760;
    value1 = *(f32 *)(base + 0);
    value0 = *(f32 *)(base + 4);
    *(f32 *)(arg0 + 0) = value1;
    *(f32 *)(arg0 + 4) = value0;
    base = D_008872E0 + iGpffffb760;
    *(s32 *)(base + 0) = 0;
    *(s32 *)(base + 4) = 0x80000000;
    return arg0;
}
/* measured: closes the opt_propagation bracket. */
#pragma opt_propagation on
/* measured: closes schedule around func_003df550. */
#pragma schedule off
/* measured: schedule on preserves func_003df590's return sequence. */
#pragma schedule on
// FUN_003DF590
s32 func_003df590(s64 arg0, ...) {
    va_list args;
    va_start(args, arg0);
    va_end(args);
    return (s32)(((s64)arg0 << 0x20) >> 0x20);
}
/* measured: closes schedule around func_003df590. */
#pragma schedule off
// FUN_003DF5D0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df5d0);
// FUN_003DF6E0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df6e0);
/* measured: schedule on preserves func_003df7f0/860's callback sequence. */
#pragma schedule on
/* measured: no_branch_likely preserves 7f0's two callback paths. */
#pragma no_branch_likely on
// FUN_003DF7F0
s32 func_003df7f0(u8 *arg0) {
    u8 *self;
    u8 *temp_4;

    self = arg0;
    temp_4 = *(u8 **)self;
    if ((temp_4 != NULL) && (*(s32 *)(self + 8) != 0)) {
        jtbl_008873EC[0](temp_4);
        *(s32 *)self = 0;
        *(s32 *)(self + 8) = 0;
    }
    jtbl_008873EC[0](self);
    return 1;
}
/* measured: closes no_branch_likely around func_003df7f0. */
#pragma no_branch_likely off
// FUN_003DF860
s32 func_003df860(u8 *arg0) {
    return *(s32 *)(arg0 + 4);
}

/* measured: closes the bracket noted above the marker. */
#pragma schedule off


/* measured: plain C emits retail's rd-form mult word for 003df870; the
   remaining normalized_diff 8 is a scheduler residual. Retail keeps the
   addu in the jr delay slot after lw/mult/lw, while MWCC's default C lowering
   emits addu before jr; schedule-on reorders earlier loads and is worse.
   Local-product, direct-expression, pointer, declaration, opt_propagation,
   and optimization probes were ruled out. No inline asm or volatile. */
// FUN_003DF870 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df870);
// FUN_003DF890
/* measured: schedule on places the load in the jr delay slot. */
#pragma schedule on
s32 func_003df890(s32 *arg0) {
    return *arg0;
}
/* measured: schedule off closes the single-function bracket. */
#pragma schedule off

/* measured: plain C emits retail's rd-form mult word for 003df8a0; the
   remaining normalized_diff 8 is a scheduler residual. Retail keeps the
   addu in the jr delay slot after lw/lw/mult/lw, while MWCC's default C
   lowering emits addu before jr; schedule-on and opt_serializeassignments
   reorder the earlier loads and are worse. Local-product, direct-expression,
   pointer, declaration, and optimization probes were ruled out. No inline
   asm or volatile. */
// FUN_003DF8A0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df8a0);

// FUN_003DF8C0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df8c0);
// FUN_003DF9F0
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003df9f0);
// FUN_003DFF20
INCLUDE_ASM("asm/nonmatchings/code1_003d", func_003dff20);
