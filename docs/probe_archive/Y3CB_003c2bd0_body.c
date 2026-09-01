/* object 204B, window 192B, normalized_diff 49; differing offsets 0x00-0x18, 0x20-0xB4, 0xC0-0xC8; casts written: none; levers ruled out: direct branch-shape probe (oversized-object archive condition). */
s32 func_003c2bd0(u8 *arg0) {
    s32 temp_4;
    s32 temp_6;
    s32 temp_5_2;
    s32 temp_5;
    s32 var_2;
    s32 var_7;
    u8 *var_6;

    temp_6 = *(s32 *)(arg0 + 8);
    if (temp_6 & 0x01000000) {
        var_2 = 0x10;
        goto masked;
    }
    var_2 = 0x10;
    temp_5 = *(s32 *)(arg0 + 0x14);
    if (temp_5 != 0) {
        if (temp_6 & 8)
            var_2 = (temp_5 * 4) + 0x10;
        var_2 = var_2 + (*(s32 *)(arg0 + 0x1C) * (temp_5 * 8)) + (*(s32 *)(arg0 + 0x10) * 8);
    }
    temp_5_2 = *(s32 *)(arg0 + 0x18);
    var_7 = 0;
    if (temp_5_2 > 0) {
        var_6 = *(u8 **)(arg0 + 0x5C);
        temp_4 = *(s32 *)(arg0 + 0x14) * 0xC;
        do {
            var_2 += 0x18;
            if (*(s32 *)(var_6 + 0x14) != 0)
                var_2 += temp_4;
            if (*(s32 *)(var_6 + 0x18) != 0)
                var_2 += temp_4;
            var_7 += 1;
            var_6 += 0x1C;
        } while (var_7 < temp_5_2);
    }
    goto done;
masked:
    var_2 += 0x18;
done:
    return var_2;
}
