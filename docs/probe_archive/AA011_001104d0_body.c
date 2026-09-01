/* Archived candidate for func_001104d0; restored to bare INCLUDE_ASM after compile signature conflict. */
void func_001104d0(s16 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_8;
    s32 temp_9;
    s32 var_10;
    s32 var_11;
    s32 var_12;
    var_11 = arg0 % 365;
    var_12 = 3;
    var_10 = 0;
    do {
        if (var_10 >= 0xC) break;
        temp_9 = var_12 + 1;
        temp_8 = temp_9 - 1;
        if (var_11 < *((u8 *)(&D_005E45E0 + ((temp_8 % 12) * 4)))) break;
        var_11 -= (s32)(*((u8 *)(&D_005E45E0 + ((temp_8 % 12) * 4))));
        var_12 = temp_9;
        if (temp_9 >= 0xC) var_12 = 0;
        var_10 += 1;
    } while (1);
    *arg1 = var_12 + 1;
    *arg2 = var_11 + 1;
}
