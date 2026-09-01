/* Best attempted reconstruction for func_003a2950; object 152B, retail window 160B, normalized_diff 10. Restored to INCLUDE_ASM because it did not match. */
/* measured: schedule on for func_003a2950; object 152B/window 160B/nd 10. */
#pragma schedule on
/* measured: no_branch_likely on for func_003a2950; object 152B/window 160B/nd 10. */
#pragma no_branch_likely on
s32 func_003a2950(s32 arg0, s32 arg1, s64 arg2)
{
    u8 *temp_7;
    u8 *temp_8;

    temp_8 = *(u8 **)(arg0 + iGpffffb610);
    temp_7 = *(u8 **)(temp_8 + 0x9C);
    switch (arg1) {
    case 1:
        *(s64 *)(temp_7 + 0xB8) =
            (s64)((arg2 & 0xFF) |
                  ((((u64)(arg2 << 0x20) >> 0x20) &
                    (0xFF00 << 0x10)) << 8));
        *(s32 *)(temp_8 + 0x40) &= 0xEFFFFFFF;
        goto ret_one;
    case 2: {
        u64 value;
        value = (u64)-0x10000 & *(s64 *)(temp_7 + 0xC8);
        *(s64 *)(temp_7 + 0xC8) = value;
        value = *(s64 *)(temp_7 + 0xC8) | (arg2 & 0xFFFF);
        *(s64 *)(temp_7 + 0xC8) = value;
        break;
    }
    default:
        goto ret_zero;
    }
ret_one:
    return 1;
ret_zero:
    return 0;
}
/* measured: closing no_branch_likely for func_003a2950; object 152B/window 160B/nd 10. */
#pragma no_branch_likely off
/* measured: closing schedule on for func_003a2950; object 152B/window 160B/nd 10. */
#pragma schedule off
