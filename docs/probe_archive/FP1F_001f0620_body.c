/* Best candidate for func_001f0620: object 664B, window 672B, normalized_diff 22. */
s32 func_001f0620(u8 *arg0, s64 arg1)
{
    s32 temp_3_2;
    s64 temp_2;
    u16 temp_6;
    u8 *temp_3;
    u8 *temp_5;

    temp_6 = *(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8);
    if ((temp_6 == 0x215) && ((s16)arg1 != 2)) {
        return 0;
    }
    temp_2 = (s16)arg1;
    switch (temp_2) {
    case 1:
        return 1;
    case 2:
        return (s32)(func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 8) == 0);
    case 3:
        return func_00106330(0x1438) == 0;
    case 4:
        temp_3 = *(u8 **)(arg0 + 0x30);
        if (temp_3[0xA2] != 0) return 0;
        if (*(u16 *)(temp_3 + 0xA4) != 1) return 0;
        if ((func_001ef720(1, 0) & 0xFFFF) < 2) return 0;
        return func_00106330(0x1438) == 0;
    case 5:
        temp_5 = *(u8 **)(arg0 + 0x30);
        if (temp_5[0xA2] != 0) return 0;
        if (*(u16 *)(temp_5 + 0xA4) != 1) return 0;
        if ((*(u16 *)(arg0 + 0x18) & 0x400) == 0) return 0;
        if (func_00232710(*(s32 *)(temp_5 + 0xA64), 8) != 0) return 0;
        return func_00106330(0x1438) == 0;
    case 6:
        temp_3_2 = *(s32 *)(iGpffffb414 + ((temp_6 & 0xFFFF) * 0x18));
        if (temp_3_2 & 0x20) return 0;
        if ((temp_3_2 & 1) == 0) return 0;
        return func_001f5ea0(0) == 0;
    case 7:
    case 8:
    case 11:
    case 12:
        return 1;
    case 10:
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) return 0;
        return func_00106330(0x1438) == 0;
    case 13:
        return 1;
    default:
        return 0;
    }
}
