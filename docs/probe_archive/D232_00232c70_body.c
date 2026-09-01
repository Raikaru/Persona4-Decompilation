/* object_size 260, window 272, normalized_diff 2; differing offsets 208, 232.
   Retail at +0xD0/+0xE8 uses daddiu $v0,$zero,1 / daddiu $v0,$zero,0x63;
   at +0xDC/+0xE0 it uses slti $at,$v1,0x64 / bnez $at,.L00232D5C.
   Candidate uses addiu at both constants and slti/bnez with $v1. This is
   a late clamp-constant/compare-register residual, not a store pair.
   Corrected func_0046d730 declaration to (void *, s32) and func_00109bf0
   declaration to (u8 *, s32). Newly ruled out: u8 return (both daddiu words
   become exact, but register allocation differs from +0x64 through +0xC8,
   normalized_diff 12); u16/s16/s8 returns; narrow (u8) return expressions;
   s32 return with a returned u8 local (daddiu exact, normalized_diff 29);
   s64/u64 return/result forms, typed 64-bit destinations, branch-local s64
   constants, u8 working locals, hidden-return/direct-return forms, u8 flag,
   direct flag/if (!flag)/goto guard, direct versus named clamp values,
   declaration/order and callee-prototype changes. Re-tested u32/full-width
   and plain s32 returns, u8 constant casts, const-u8 clamp locals, enum
   clamp constants, returned u8 clamp locals (object 268, nd 12), strict
   <0x64/>=0x64 guard spellings (object 260, nd 7), and the typedconst-shaped
   u32 variant (direct u32 flag tail, cast-free helper assignments, u32
   func_00109bf0 view); none improved nd 2. A simple u8-return retest emitted
   both daddiu constants but was object 264/272, normalized_diff 33, and
   introduced one caller MISMATCH, so it is also ruled out. opt_propagation off
   regressed to object 264, nd 57. No honest source probe improved nd 2. */
// FUN_00232C70 NONMATCHING
u32 func_00232c70(u8 *arg0, s32 arg1)
{
    u32 v;
    s32 temp_3;
    u8 flag;

    if (((s32)(arg1 & 0xFFFF) < 0) || ((arg1 & 0xFFFF) >= 5)) {
        func_0046d730(D_00635938, 0x313);
    }
    if ((*(u16 *)arg0 & 4) != 0) {
        v = (u32)func_00232b40(arg0, arg1);
        v &= 0xFF;
    } else {
        if (*(u16 *)(arg0 + 2) >= 0xB) {
            func_0046d730(D_00635938, 0x31A);
        }
        v = (u32)func_00109bf0((u8 *)(u32)*(u16 *)(arg0 + 2), arg1);
        v &= 0xFF;
    }
    flag = (*(s32 *)(arg0 + 0xC) & 0x80) != 0;
    if (!flag) {
        goto no_shift;
    }
    v = (u32)((u32)v >> 1);
    v &= 0xFF;
no_shift:
    temp_3 = (u32)v & 0xFF;
    if (temp_3 > 0) {
        goto clamp_value;
    }
    v = 1;
    goto done_value;
clamp_value:
    if (temp_3 <= 0x63) {
        goto done_value;
    }
    v = 0x63;
done_value:
    return v;
}
