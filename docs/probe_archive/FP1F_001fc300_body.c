/* Best candidate for func_001fc300: object 396B, window 416B, normalized_diff 245. */
s64 func_001fc300(u8 *arg0, u8 *arg1)
{
    u8 *table;
    u8 *temp_8;
    s32 var_10;
    s32 one;
    s64 var_2;
    s64 var_2_2;
    u32 temp_6;
    u8 temp_3;
    u8 temp_3_2;
    if (*(u8 *)(arg1 + 3) != 0) return 1;
    var_10 = 0;
    table = D_00881440_abs;
    one = 1;
    goto loop_test;
loop_body:
    temp_8 = *(u8 **)(table + (temp_6 * 4) + 8);
    if (temp_8 != 0) {
        if ((*(u8 *)(arg1 + 2) & (one << temp_6)) && (temp_8 == arg0)) return 1;
        var_10 = (var_10 + 1) & 0xFFFF;
        goto loop_test;
    }
    goto block_9;
loop_test:
    temp_6 = var_10 & 0xFFFF;
    if (temp_6 < 3U) goto loop_body;
block_9:
    if ((*(u8 **)(D_00881440_abs) != 0) &&
        (*(u8 *)(arg0 + 0xA2) == *(u8 *)(*(u8 **)(D_00881440_abs) + 0xA2))) {
        temp_3 = *(u8 *)(arg1 + 0);
        switch (temp_3) {
        case 0: return 0;
        case 1:
            var_2_2 = 1;
            if (*(u8 **)(D_00881440_abs) != arg0) var_2_2 = 0;
            return (s64)(var_2_2 << 0x38) >> 0x38;
        case 2: return 1;
        }
    }
    if ((*(u8 **)(D_00881444_abs) != 0) &&
        (*(u8 *)(arg0 + 0xA2) == *(u8 *)(*(u8 **)(D_00881444_abs) + 0xA2))) {
        temp_3_2 = *(u8 *)(arg1 + 1);
        switch (temp_3_2) {
        case 0: return 0;
        case 1:
            var_2 = 1;
            if (*(u8 **)(D_00881444_abs) != arg0) var_2 = 0;
            return (s64)(var_2 << 0x38) >> 0x38;
        case 2: return 1;
        }
    }
    return 0;
}
