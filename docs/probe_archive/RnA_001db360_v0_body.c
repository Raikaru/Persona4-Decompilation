/* object 544B / window 544B / normalized_diff 318 / differing offsets 25,29,32,33,34,35,36,37,38,39,40,42,43,44,46,47 / initial live candidate; archived before source-shape probing. */
s32 func_001db360(u64 formation, u16 index, s32 enabled) {
    extern s32 func_0010f420(u32 arg0, u32 arg1);
    extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
    extern s8 func_00233a90(u8 *arg0, s32 arg1);
    extern s32 func_0023d6e0(s16 arg0);
    extern u32 func_0023e130(u8 *arg0);
    extern u8 *func_0023e140(u8 *arg0);
    extern s32 func_00242800(u8 *arg0, s32 arg1);
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_2;
    s32 var_8;
    u16 temp_3;
    u8 *temp_17;

    temp_17 = *(u8 **)((u8 *)formation + 0x30);
    if ((*(u8 *)(temp_17 + 0xA2) == 1) &&
        (func_001f9ce0((u8 *)formation, (s16)index) == 0) &&
        (func_0010f420(*(u16 *)(temp_17 + 0xA4), index) == 0)) {
        return 1;
    }
    temp_16 = func_0023d6e0((s16)index);
    if ((enabled == 1) && !(temp_16 & 0xE0001)) {
        if (temp_16 & 2) {
            if (func_00233a90(*(u8 **)(temp_17 + 0xA64), 0x10) > 0) {
                return 0;
            }
            goto block_12;
        }
        if (!(temp_16 & 0x40) &&
            (func_00233a90(*(u8 **)(temp_17 + 0xA64), 0x11) > 0)) {
            return 0;
        }
        goto block_12;
    }
block_12:
    if (temp_16 & 2) {
        if (*(u8 *)(temp_17 + 0xA2) == 1) {
            if (**(u16 **)(temp_17 + 0xA64) & 0x100) {
                return 0;
            }
            goto block_24;
        }
        temp_16_2 = (s32)(func_0023e130(*(u8 **)(temp_17 + 0xA64)) & 0xFFFF);
        temp_2 = (s32)func_0023e140(*(u8 **)(temp_17 + 0xA64));
        var_8 = 0;
loop_23:
        if ((var_8 & 0xFFFF) >= (temp_16_2 & 0xFFFF)) {
            goto block_24;
        }
        temp_3 = *(u16 *)(temp_2 + ((var_8 & 0xFFFF) * 2));
        if ((temp_3 != 0x1F8) && (temp_3 != 0x1F7) && (temp_3 != 0x1F6)) {
            var_8 = (var_8 + 1) & 0xFFFF;
            goto loop_23;
        }
        return 0;
    }
block_24:
    return (func_00242800(*(u8 **)(temp_17 + 0xA64), (s16)index) & 0x07000000) == 0;
}
