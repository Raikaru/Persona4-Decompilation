/* func_003b7060 current-TU remeasure: object 172B/window 176B, normalized_diff 78; differing offsets 24,28,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164. */
u64 func_003b7060(void) {
    s32 *temp_8;
    s32 *temp_4;
    u32 *temp_3_2;
    u32 *temp_4_2;
    u32 temp_4_3;
    u32 var_3;
    u32 raw;
    u32 max;
    s64 temp_2;
    u8 *temp_3;
    u8 *temp_5;

    temp_3 = D_008872E0 + iGpffffb618;
    temp_8 = *(s32 **)(temp_3 + 8);
    temp_4 = *(s32 **)(temp_3 + 4);
    *temp_4 = *temp_8 + *temp_4;
    temp_5 = D_008872E0 + iGpffffb618;
    temp_3_2 = *(u32 **)(temp_5 + 4);
    raw = *temp_3_2;
    temp_4_2 = temp_3_2 + 1;
    *(u32 **)(temp_5 + 4) = temp_4_2;
    max = *(u32 *)(temp_5 + 0xC);
    temp_2 = ((s64)(raw >> 1) << 0x21) >> 0x21;
    if ((u32)temp_4_2 < max) {
        temp_4_3 = *(u32 *)(temp_5 + 8) + 4;
        *(u32 *)(temp_5 + 8) = temp_4_3;
        if (temp_4_3 >= max) {
            var_3 = *(u32 *)temp_5;
            goto block_3;
        }
        return temp_2;
    }
    *(u32 **)(temp_5 + 4) = *(u32 **)(temp_5 + 0);
    var_3 = *(u32 *)(temp_5 + 8) + 4;
block_3:
    *(u32 *)(temp_5 + 8) = var_3;
    return temp_2;
}
