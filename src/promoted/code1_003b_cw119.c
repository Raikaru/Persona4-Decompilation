#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_003b. */

extern u8 D_008872E0[];
extern u8 D_00885A90[];
extern s32 iGpffffaa7c;
extern s32 iGpffffb618;
extern s32 func_003b6e70(s32 arg0);
extern s32 func_003b6e00(s32 arg0);
extern void func_003b6f00(s32 arg0, u8 *arg1);
extern s32 iGpffffb6c0;
extern s32 iGpffffb6c4;
extern void func_003e18c0(u8 *arg0, void *arg1, s32 arg2);
extern void func_003e12f0(u8 *arg0);
extern s32 func_003e9700(s32 arg0);
extern s32 D_00764758;
extern s32 iGpffffb668;
extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003df590(s64 arg0, ...);
extern void func_003df4d0(s32 *arg0);
extern void func_003bbea0(u8 *arg0);
extern void func_003c2a80(s32 arg0);
extern s32 D_00764794;
extern s32 D_00764790;
extern s32 D_0076478C;
extern s32 D_00764788;
extern s32 D_007647AC;
extern s32 D_007647A8;
extern s32 D_00764784;
extern s32 D_0076479C;
extern u8 D_00886498[];
extern u8 **func_003c22f0(u8 *arg0);
extern s32 func_003c0700(u8 *arg0);
extern s32 func_003c02e0(u8 *arg0);
extern s32 iGpffffb6b0;
extern s32 func_003bc880(s32 arg0, s32 arg1);
extern s32 func_003bff30(void *arg0, s32 (*arg1)(s32, s32 *), s32 *arg2);
extern s32 D_00764770;
extern s32 func_003e8930(s32 a, s32 b, void *c, void *d);
extern s32 func_003bb0d0(s32 arg0);
extern s32 func_003bb030(s32 arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern void func_003bf930(void);
extern s32 func_003b84a0(u8 *arg0);
extern s32 iGpffffb654;
extern s32 iGpffffb61c;
extern u8 D_008864E8[];
extern s32 func_003e8960(s32 arg0);
extern u8 *func_003b8d40(u8 *arg0, s32 arg1);
extern s32 func_003e8410(s32 arg0, s32 arg1, void *arg2, void *arg3, s32 arg4);
extern s32 func_003c3920(s32 arg0, s32 arg1, void *arg2, void *arg3, s32 arg4);
extern s32 func_003bf1d0(s32 arg0);
extern s32 iGpffffb6b4;
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern s32 iGpffffb6f0;
extern s32 iGpffffb610;
extern s32 func_003e3370(void *arg0, s32 arg1);
extern void func_003b4ab0(void);
extern void func_003b4c10(void);
extern void func_003b4db0(void);
extern void func_003b4ff0(void);
extern void func_003b5160(void);
extern void func_003b53b0(void);
extern void func_003b5650(void);
extern void func_003b5820(void);
extern void func_003b5ac0(void);
extern void func_003b5bf0(void);
extern void func_003b5d20(void);
extern void func_003b5fb0(void);
extern void func_003b6020(void);
extern void func_003b61e0(void);
extern void func_003b6390(void);
extern void func_003b6420(void);
extern void func_003b64c0(void);
extern void func_003b6540(void);
extern void func_003b65d0(void);
extern void func_003b6680(void);
extern u8 **func_003b6cb0(void *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
static inline s32 add003b(s32 left, s32 right) {
    return left + right;
}
extern u8 D_0070AF70[];

// FUN_003B6DA0
/* N3B best: object 84B/window 96B, normalized_diff 7 (exact Z3BF archive text, reproduced under current TU). Requires #pragma schedule on + #pragma opt_propagation off, and the head store must go through the D_00885A90 symbol, not the base local (base-local store = nd45). Residual 2 words: retail puts jr $ra in the beqz delay slot and pads nop;nop;nop after the loop vs our nop;jr;nop — b210 will not place an epilogue instruction in that delay slot. All 156 archived 84B shapes measure nd>=7; dead-multiply spellings nd44-53. */
#pragma schedule on
#pragma opt_propagation off
void func_003b6da0(s32 arg0) {
    u8 *base;
    s32 value;
    s32 *ptr;
    s32 count;
    s32 factor;

    base = (u8 *)D_00885A90;
    value = arg0 | 1;
    iGpffffaa7c = 0;
    ptr = (s32 *)(base + 4);
    count = 0x270;
    count -= 1;
    *(s32 *)D_00885A90 = value;
    if (count == 0) {
        goto done;
    }
    factor = 0x10DCD;
    do {
        value *= factor;
        count -= 1;
        *ptr = value;
        ptr += 1;
    } while (count != 0);
done:
    return;
}
#pragma opt_propagation on
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

extern u64 func_003b7060(void);
extern u64 func_003b88c0(void);
extern u64 func_003bf1c0(u64 value);
extern u64 func_003bf1f0(u64 value);
extern s32 func_003b8d20(void);
/* Archived b210 near-miss (R3BB_003b7860); exact under b119 with schedule on. */
// FUN_003B7860
#pragma schedule on
s32 func_003b7860(s32 arg0) {
    extern s32 func_003b8d20(s32 arg0);
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
    extern s32 func_003e8960(s32 arg0);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    extern s32 iGpffffaa80;
    extern s32 iGpffffaa84;
    extern u8 D_00886460[];
    extern s32 D_0088649C[];
    extern u8 *D_008864A0[];
    extern s32 D_008864A8[];
    extern s32 D_008864B0[];
    extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
    s32 flags;

    if (D_008864B0[0] != 0) {
        goto increment;
    }
initialize:
    flags = 1;
    if (func_003e8960(0x120) != -1) {
        flags |= 2;
    }
    if (func_003e8960(0x12E) != -1) {
        flags |= 4;
    }
    func_003b8d20(flags);
    D_008864A8[0] = func_003e1220(0x48, iGpffffaa80, 4, iGpffffaa84, D_00886460, 0x40116);
    D_008864A0[0] = jtbl_008873E8[0](0x400F, 0x40116);
    func_0043f9c8(D_008864A0[0], 0, 0x400F);
    D_0088649C[0] = (s32)(D_008864A0[0] + 0xF) & ~0xF;
increment:
    D_008864B0[0] += 1;
    return arg0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

/* Archived b210 near-miss (F3B1_003bf360); exact under b119 with schedule on. */
// FUN_003BF360
#pragma schedule on
u8 *func_003bf360(u8 *arg0, s32 *arg1) {
    extern u8 D_0070AF70[];
    extern s32 func_003e3370(u8 *desc, u8 *arg1);

    *arg1 += 0xC;
    *arg1 += 0x1C;
    *arg1 += func_003e3370(D_0070AF70, arg0) + 0xC;
    return arg0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003BFFC0
/* measured: no_branch_likely on selects retail's plain beqz/bne branches. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003bffc0(u8 *arg0, s32 (*arg1)(s32, s32 *), s32 *arg2) {
    u8 *current;
    u8 *sentinel;
    u8 *next;

    sentinel = arg0 + 0x18;
    current = *(u8 **)sentinel;
    if (current == sentinel)
        goto done;
loop:
    next = *(u8 **)current;
    if (arg1((s32)(current - 4) - iGpffffb6b0, arg2) == 0)
        return (s32)arg0;
    current = next;
    if (current != sentinel)
        goto loop;
done:
    return (s32)arg0;
}
/* measured: close no_branch_likely around func_003bffc0. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003BFF30
/* measured: no_branch_likely on selects retail's plain beqz/bne branches. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_003bff30(void *arg0, s32 (*arg1)(s32, s32 *), s32 *arg2) {
    u8 *current;
    u8 *sentinel;
    u8 *next;

    sentinel = (u8 *)arg0 + 8;
    current = *(u8 **)((u8 *)arg0 + 8);
    if (current == sentinel)
        goto done;
loop:
    next = *(u8 **)current;
    if (arg1((s32)(current - 0x40), arg2) == 0)
        return (s32)arg0;
    current = next;
    if (current != sentinel)
        goto loop;
done:
    return (s32)arg0;
}
/* measured: close no_branch_likely around func_003bff30. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003BFE90
/* measured: schedule on + no_branch_likely on; retail uses plain beq/bne and a delay-slot move. */
#pragma schedule on
#pragma no_branch_likely on
u8 *func_003bfe90(u8 *arg0) {
    s32 (*callback)(u8 *);
    u8 *result;
    u8 *current;
    u8 *entry;
    u8 *sentinel;

    sentinel = arg0 + 8;
    current = *(u8 **)sentinel;
    result = arg0;
    if (current == sentinel)
        goto empty;
loop:
    entry = current - 0x40;
    if ((*(u8 *)(current - 0x3E) & 4) != 0)
        goto callback_block;
advance:
    current = *(u8 **)current;
    if (current != sentinel)
        goto loop;
    if (current == sentinel)
        goto empty;
    result = result;
empty:
    goto done;
done:
    return result;
callback_block:
    func_003e9700(*(s32 *)(entry + 4));
    callback = *(s32 (**)(u8 *))(entry + 0x48);
    if (callback(entry) != 0)
        goto advance;
    result = NULL;
    goto advance;
}
/* measured: closes the no_branch_likely bracket for func_003bfe90. */
#pragma no_branch_likely off
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off


// FUN_003BB4A0
#pragma schedule on
#pragma opt_propagation off
u8 *func_003bb4a0(u8 *arg0, s32 arg1, f32 *arg2) {
    s32 err[2];
    s32 pair[2];
    s32 temp_3;
    s32 count;
    u8 *temp_2;
    f32 f2;
    f32 f1;
    f32 f0;
    extern s32 func_003b9a40(u8 *arg0, u8 *arg1);
    extern s32 func_003df590(s32 arg0, ...);
    extern void func_003df4d0(s32 *arg0);
    extern u8 D_0070AF50[];

    if (arg1 < 0) {
        goto block_9;
    }
    temp_3 = *(s32 *)(arg0 + 0xC);
    switch (temp_3) {
    case 1:
        count = *(s32 *)(arg0 + 8) - 2;
        break;
    case 2:
        count = *(s32 *)(arg0 + 8) - 3;
        break;
    default:
        pair[0] = 0x102;
        pair[1] = func_003df590(1);
        func_003df4d0(pair);
        count = 0;
        break;
    }
    if (arg1 < count) {
        temp_2 = *(u8 **)(arg0 + 0x14) + arg1 * 0xC;
        f2 = arg2[0];
        f1 = arg2[1];
        f0 = arg2[2];
        *(f32 *)(temp_2 + 0) = f2;
        *(f32 *)(temp_2 + 4) = f1;
        *(f32 *)(temp_2 + 8) = f0;
        return func_003b9a40(arg0, *(u8 **)(arg0 + 0x14)) ? arg0 : NULL;
    }
block_9:
    err[0] = 0x102;
    err[1] = func_003df590(0x80000003, D_0070AF50);
    func_003df4d0(err);
    return NULL;
}
#pragma opt_propagation on
#pragma schedule off




