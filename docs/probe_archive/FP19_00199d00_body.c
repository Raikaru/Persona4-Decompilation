/* Best attempt: object 300B, window 336B, normalized_diff 185. Reverted because the candidate remained non-exact. */
s32 func_00199d00(s32 unused, s32 arg1, s32 arg2, s32 arg3)
{
    s32 temp_16;
    u16 temp_3;
    s64 raw_3;
    s16 narrowed_3;
    register u8 *saved_arg1;
    register s32 saved_arg2;
    register s32 saved_arg3;

    saved_arg1 = (u8 *)arg1;
    saved_arg2 = arg2;
    saved_arg3 = arg3;
    temp_16 = (s64)(s16)saved_arg2;
    if (func_001f11e0(saved_arg2) != 0) {
        temp_3 = *(u16 *)p4_table_addr_00199d00(
            temp_16 * 4, 2, iGpffffb3bc);
        if ((temp_3 & 0x200) == 0) {
            if ((saved_arg3 == 0) || ((temp_3 & 1) == 0)) {
                return 1;
            }
            return 2;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0 &&
            saved_arg3 == 0) {
            return 1;
        }
        return 0;
    }
    raw_3 = func_0023d8e0(*(s32 *)((u8 *)arg1 + 0xA64),
                          (u16)saved_arg2);
    narrowed_3 = (s16)raw_3;
    switch (narrowed_3) {
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 3;
    }
}
