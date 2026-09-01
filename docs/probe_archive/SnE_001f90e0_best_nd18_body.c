/* Best measured body for func_001f90e0 before value-width probe.
 * object 472B, window 480B, normalized_diff 18 words.
 * fndiff differing offsets (bytes): 128, 300, 304, 324, 332, 336,
 * 340, 344, 348, 352, 356, 360, 364, 368, 372, 376, 380, 384, 388,
 * 392, 400, 424.
 * Ruled out: direct M2C/goto list form, pointer/integer array swaps,
 * direct declaration-order swaps, separate/combined null checks, explicit
 * work alias, register keyword, and u16 count. This form preserves the
 * retail list loop but the selected pointer remains v1 (retail a0) and
 * score remains a0 (retail a2).
 */
s32 func_001f90e0(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    u8 *var_17;
    s32 var_16;
    s32 var_5;
    s32 var_6;
    u8 *temp_3;
    u8 *temp_4_2;
    u8 *sp60[12];

    if (func_0045af90(3) == 1) {
        return -1;
    }
    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    if (func_00232710(*(s32 *)(temp_3 + 0xA64), 0x110) != 0) {
        return -1;
    }
    var_16 = 0;
    var_17 = *(u8 **)(iGpffffb3ac + 0x178);
    while (var_17 != NULL) {
        if ((func_002428f0(*(u8 **)(var_17 + 0xA64), 0) == 0) &&
            (func_00232710(*(s32 *)(var_17 + 0xA64), 0x1001D7) == 0) &&
            (*(u16 *)(var_17 + 0xA4) != 1) &&
            (var_17 != *(u8 **)(arg0 + 0x30))) {
            sp60[var_16 & 0xFFFF] = var_17;
            var_16 = (var_16 + 1) & 0xFFFF;
        }
        var_17 = *(u8 **)(var_17 + 0xA6C);
    }
    temp_4 = var_16 & 0xFFFF;
    if (temp_4 == 0) {
        return -1;
    }
    temp_4_2 = sp60[func_00231d70(temp_4)];
    if (temp_4_2 == NULL) {
        return -1;
    }
    var_6 = 0x32;
    var_5 = 1;
loop_24:
    if (var_5 < 9) {
        if (var_5 != *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
            if ((var_5 != 5) && (var_5 != *(u16 *)(temp_4_2 + 0xA4))) {
                var_6 += 3;
            }
            var_5 += 1;
            goto loop_24;
        }
    }
    temp_16 = var_6 + D_00624FC0[*(u16 *)(temp_4_2 + 0xA4)];
    return temp_16 + func_00231d70(3);
}
