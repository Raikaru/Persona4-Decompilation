/* Best attempted reconstruction for func_003a2950 under -O2,p; object 152B, retail window 160B, normalized_diff 11. Tried explicit u64 low/mask/upper/lowbyte locals and ((u64)(arg2 << 0x20) >> 0x20) for low-32 zero-extension. Residual: dsll32 uses  instead of , mask materialization order differs, and 2 trailing nops are missing. */
// FUN_003A2950
#pragma schedule on
/* measured: no_branch_likely on for func_003a2950; object 160B/window 160B. */
#pragma no_branch_likely on
s32 func_003a2950(s32 arg0, s32 arg1, s64 arg2)
{
    u8 *temp_7;
    u8 *temp_8;

    temp_8 = *(u8 **)(arg0 + iGpffffb610);
    temp_7 = *(u8 **)(temp_8 + 0x9C);
    switch (arg1) {
    case 1: {
        u64 low;
        u64 mask;
        u64 upper;
        u64 lowbyte;
        low = ((u64)(arg2 << 0x20) >> 0x20);
        mask = (u64)0xFF00 << 0x10;
        upper = (low & mask) << 8;
        lowbyte = arg2 & 0xFF;
        *(s64 *)(temp_7 + 0xB8) = lowbyte | upper;
        *(s32 *)(temp_8 + 0x40) &= 0xEFFFFFFF;
        goto ret_one;
    }
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
