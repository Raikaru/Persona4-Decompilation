#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);
extern s8 D_00641E60[];
extern s32 func_00246830();
extern u8 *iGpffffb3d4;
extern s16 D_006420A0[];
extern u32 D_00642EF0[];
extern u32 D_00642F00[];
extern s32 func_0010ac10();
extern u8 *func_002e48a0();
static inline s32 func_0031_ne(s32 value, s32 target)
{
    return value != target;
}

extern s32 func_0010c750(u8 *arg0, s32 arg1);
extern s32 func_00106330(s32 arg0);
extern u8 func_00106600(s16 arg0);
extern u16 func_00107ac0(s32 arg0);
extern u8 D_006432B0[];
extern u8 func_002e78a0();
extern u8 func_002e78e0();
extern void func_002e7920();
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */
// FUN_00311900
void func_00311900(s64 arg0)
{
    func_00246830(arg0 & 0xFFFF);
}
// FUN_00311930
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311930);
// FUN_00311B90
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311b90);
// FUN_00311D00
s64 func_00311d00(s32 arg0)
{
    s64 result;
    u16 flags = *(u16 *)(iGpffffb3d4 + ((arg0 & 0xFFFF) * 14));

    if (flags & 1) {
        result = 0;
        goto exit;
    }
    if (flags & 2) {
        result = 0;
        goto exit;
    }
    result = 1;
exit:
    return (s8)result;
}
// FUN_00311D60
s32 func_00311d60(s32 arg0)
{
    s16 temp_3;
    u32 var_18;
    s32 var_17;
    s32 value;
    u8 *temp_4;
    s32 result;

    var_17 = 1;
    var_18 = 0;
    value = arg0 & 0xFFFF;
    goto loop_test;
loop_body:
    temp_4 = (u8 *)D_006420A0 + (var_18 * 8);
    if (value != *(s16 *)(temp_4 + 4)) {
        goto block_8;
    }
    temp_3 = *(s16 *)(temp_4 + 6);
    if (temp_3 & 1) {
        if (func_00106330(*(s32 *)temp_4) == 0) {
            result = 0;
            goto done;
        }
    } else {
        if ((temp_3 & 2) == 0) {
            goto block_8;
        }
        var_17 = 0;
        if (func_00106330(*(s32 *)temp_4) == 1) {
            result = 1;
            goto done;
        }
    }
block_8:
    var_18 += 1;
loop_test:
    if (var_18 < 0x17U) {
        goto loop_body;
    }
    result = var_17;
done:
    return result;
}
/* measured: loop-invariant absolute table base requires the retail preheader. */
#pragma opt_loop_invariants on
// FUN_00311E40
s32 func_00311e40(s32 arg0)
{
    u32 i;

    i = 0;
    while (i < 0x17U) {
        if ((arg0 & 0xFFFF) == D_006420A0[i * 4 + 2]) {
            return 1;
        }
        i++;
    }
    return 0;
}
/* measured: restore the default invariant setting after this function. */
#pragma opt_loop_invariants off
// FUN_00313690
s8 func_00313690(s64 arg0)
{
    return D_00641E60[(s16)arg0];
}
// FUN_003136B0
s32 func_003136b0(u16 arg0)
{
    s32 value;
    s32 result;

    value = arg0 & 0xFFFF;
    if (value == 0x93) {
        result = (func_00106600(0x4A8) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0xB9) {
        result = (func_00106600(0x4A4) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x26) {
        result = (func_00106600(0x4A6) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x53) {
        result = (func_00106600(0x4AD) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x68) {
        result = (func_00106600(0x4AF) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0xA6) {
        if ((func_00107ac0(0x1E) & 0xFFFF) == 0xA) {
            result = 1;
        } else {
            result = func_00106330(0x1DD) != 0;
        }
        goto done;
    }
    result = 1;
done:
    return result;
}
// FUN_00313800
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313800);
// FUN_003139D0
s32 func_003139d0(s64 arg0, s64 arg1)
{
    s32 i;
    s32 start;
    s64 limit;
    s32 result;

    i = 0;
    start = (s8)arg1 + 1;
    limit = (s8)arg0;
    goto loop_test;
loop_body:
    if (func_0010ac10(*(u16 *)(func_002e48a0((s8)start, i) + 2)) == 0) {
        result = 0;
        goto done;
    }
    i = (s16)(i + 1);
loop_test:
    if ((s16)i < limit) {
        goto loop_body;
    }
    result = 1;
done:
    return result;
}
// FUN_00313A80
s32 func_00313a80(s64 arg0, s64 arg1)
{
    return func_0010ac10(*(u16 *)(*(u8 **)((u8 *)D_00642EF0 + ((s8)arg0 * 8)) + ((s8)arg1 * 0x20))) != 0;
}
// FUN_00313AE0
s64 func_00313ae0(s64 arg0, s32 arg1)
{
    s32 i;
    s64 result;
    u8 *table;

    i = 0;
    arg1 = (u16)arg1;
    table = (u8 *)D_00642F00 + ((s8)arg0 * 8);
    goto loop_test;
loop_body:
    if (func_0031_ne(*(u16 *)(*(u8 **)(table - 0x10) + (i * 0x20)), arg1)) {
        goto loop_next;
    }
    result = (s8)i;
    goto done;
loop_next:
    i++;
loop_test:
    if (i < 6) {
        goto loop_body;
    }
    result = 0;
done:
    return result;
}
// FUN_00313B50
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313b50);
// FUN_00313D20
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313d20);
// FUN_00313FB0
s32 func_00313fb0(u8 *arg0)
{
    s32 temp;

    temp = func_0010c750(arg0, (arg0[4] + 1) & 0xFFFF);
    return temp - func_0010c750(arg0, arg0[4]);
}
 
// FUN_00314010
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00314010);
// FUN_003142F0
void func_003142f0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
