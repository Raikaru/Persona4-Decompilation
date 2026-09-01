/*
 * target: func_001db360 @ 0x001db360
 * object/window: 544B/544B
 * normalized_diff: 19 words
 * differing offsets: 76, 80, 364, 368, 372, 376, 380, 392, 404, 408, 416, 420, 424, 428, 432, 452, 456, 460, 464
 * ruled out: u64 formation signature (extra low-half conversion); u32 loop_count (sltu and one-word regression); u32 key locals (one-word regression); reversed key declaration order (large regression); do/while and positive for/while spellings (larger residuals); switch (larger residuals); schedule/no_branch_likely/opt_rebuildconditionals (no effect on adjacent-load order); direct temp/index reshaping (no improvement)
 * retained: u32 formation, s64 index, s32 enabled; opt_propagation off; opt_common_subs off; explicit goto check loop; negated tail expression
 */
#pragma opt_common_subs off
s32 func_001db360(u32 formation, s64 index, s32 enabled) {
    extern s32 func_0010f420(u32 arg0, u32 arg1);
    extern s32 func_001f9ce0(u8 *arg0, s32 arg1);
    extern s8 func_00233a90(u8 *arg0, s32 arg1);
    extern s32 func_0023d6e0(s16 arg0);
    extern u32 func_0023e130(u8 *arg0);
    extern u8 *func_0023e140(u8 *arg0);
    extern s32 func_00242800(u8 *arg0, s32 arg1);
    u8 *temp_17;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_2;
    s32 var_8;
    u16 temp_3;
    s32 loop_count;
    s32 key_1;
    s32 key_2;
    s32 key_3;

    temp_17 = *(u8 **)((u8 *)formation + 0x30);
    if ((*(u8 *)(temp_17 + 0xA2) == 1) &&
        (func_001f9ce0((u8 *)formation, (s16)index) == 0) &&
        (func_0010f420(*(u16 *)(temp_17 + 0xA4), (u16)index) == 0)) {
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
        loop_count = temp_16_2 & 0xFFFF;
        key_1 = 0x1F8;
        key_2 = 0x1F7;
        key_3 = 0x1F6;
        goto L2;
L1: ;
        temp_3 = *(u16 *)(temp_2 + ((var_8 & 0xFFFF) * 2));
        if ((temp_3 == key_1) || (temp_3 == key_2) || (temp_3 == key_3)) {
            return 0;
        }
        var_8 = (var_8 + 1) & 0xFFFF;
L2: ;
        if ((var_8 & 0xFFFF) < loop_count) {
            goto L1;
        }
    }
block_24:
    return !(func_00242800(*(u8 **)(temp_17 + 0xA64), (s16)index) & 0x07000000);
}
#pragma pop
