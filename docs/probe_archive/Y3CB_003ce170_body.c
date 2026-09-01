/* object 208B, window 192B, normalized_diff 49; differing offsets 0x00-0x04, 0x0C-0x34, 0x3C-0x48, 0x50-0xCC; casts written: none; levers ruled out: direct M2C switch candidate (oversized-object archive condition). */
s32 func_003ce170(u32 *arg0) {
    s32 temp_6_3;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;
    u32 temp_6;
    u32 temp_6_2;
    u8 *var_5;

    var_5 = *(u8 **)(arg0 + 2);
    var_3 = 0;
    var_2 = 1;
    do {
        temp_6 = *(u32 *)var_5;
        temp_6_2 = (temp_6 >> 0x1C) & 7;
        switch (temp_6_2) {
        case 0:
            var_3 = 1;
            break;
        case 1:
            var_5 += ((temp_6 & 0xFFFF) + 1) * 0x10;
            break;
        case 3:
            temp_6_3 = *(s32 *)(var_5 + 4) - *(s32 *)(arg0 + 2);
            var_2_2 = temp_6_3 >> 4;
            if (temp_6_3 < 0)
                var_2_2 = (temp_6_3 + 0xF) >> 4;
            *(s32 *)(var_5 + 4) = var_2_2;
            var_2 = 0;
            var_5 += 0x10;
            break;
        case 6:
            var_3 = 1;
            break;
        case 7:
            var_3 = 1;
            break;
        }
    } while (var_3 == 0);
    return var_2;
}
