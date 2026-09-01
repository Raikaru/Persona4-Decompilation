/* remeasured 2026-08-14: object 68B/window 80B, normalized_diff 8, differing offsets 0x0C-0x13. Retail interleaves `move $s1,$a0` before `sq $s0`; first-statement object assignment (register/non-register/pointer-width cast), no_branch_likely, declaration order, and delayed object-copy probes did not alter the residual. Retail +0x44..+0x4C are zero padding; +0x50 starts func_003d6900. The field load plus `sll` is already exact with the narrow s32 access. */
s32 func_003d68b0(u8 *arg0)
{
    register u8 *object = arg0;
    s32 argument;
    s32 value;
    s32 result;

    argument = *(s32 *)(object + 0x14);
    value = 4;
    result = value + func_003d7b30(argument);
    argument = *(s32 *)(object + 4);
    return result + (argument << 5);
}
