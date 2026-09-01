extern void func_0043f810(void *arg0, s32 arg1, s32 arg2);
// FUN_0039AE90
s32 func_0039ae90(s32 arg0, s32 arg1)
{
    s32 temp_18;
    s32 temp_2;
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_17;

    temp_2 = iGpffffb5f0;
    temp_16 = (u8 *)(arg1 + temp_2);
    temp_4 = *(s32 *)temp_16;
    temp_17 = (u8 *)(arg0 + temp_2);
    if (temp_4 > 0) {
        temp_18 = temp_4 * 0x14;
        *(u8 **)(temp_17 + 8) = (*jtbl_008873E8)((u32)temp_18, 0x30105);
        if (*(u8 **)(temp_17 + 8) == NULL) {
            return 0;
        }
        *(s32 *)temp_17 = temp_4;
        func_0043f810(*(u8 **)(temp_17 + 8),
                      *(s32 *)(temp_16 + 8), temp_18);
    }
    return arg0;
}
