// FUN_0026F5E0 NONMATCHING (probe KoE_f5e0_v2)
// residual: 9 words
// tried: distinct var_2_x, direct s64 cast expressions, first pointer swapped, loop assignments counter/dest/source
// remaining: loop source/dest/counter register mapping (a2/a1/a3 vs a3/a2/a1)
#ifdef NON_MATCHING
s32 func_0026f5e0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 sp20[5];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_2;
    s32 var_3;
    u8 *var_4;
    u8 *var_5;
    u8 *temp_3;

    if (func_002746a0() != 3) {
        return 0;
    }

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    switch (first) {
    case 0:
        var_3 = 5;
        var_5 = (u8 *)&sp20[0];
        var_4 = (u8 *)&D_0063BA30[0];
        do {
            temp_2 = *(s32 *)var_4;
            var_4 += 4;
            var_3 -= 1;
            *(s32 *)var_5 = temp_2;
            var_5 += 4;
        } while (var_3 > 0);
        func_00106390(third + sp20[second], fourth);
        break;
    case 1:
        if (fourth != 0) {
            func_00107ce0(func_00108e10());
        } else {
            func_00107dc0(func_00108e10());
        }
        break;
    case 2:
    case 3:
        func_00108290(func_00108e10(), fourth & 0xFFFF);
        break;
    case 6:
    default:
        break;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f5e0);
#endif
