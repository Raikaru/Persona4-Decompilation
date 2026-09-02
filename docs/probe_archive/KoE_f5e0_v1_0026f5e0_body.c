// FUN_0026F5E0 NONMATCHING (probe KoE_f5e0_v1)
// residual: 23 words
// retail register list: s0 (arg1/fourth), a0 first, v1 second, v0 third
// issues: var_2 allocated to t0 instead of v0/a1; first pointer addu operand order; loop a2/a1/a3 instead of a3/a2/a1
// tried: initial reconstruction with reused var_2 and do-while copy
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
    s32 var_2;
    s32 temp_index;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_q3;
    s32 temp_q4;
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
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_index = (((var_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    first = temp_q1;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_index = (((var_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));
    temp_q2 = (s64)(s16)temp_index;
    second = temp_q2;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_index = (((var_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));
    temp_q3 = (s64)(s16)temp_index;
    third = temp_q3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_index = (((var_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));
    temp_q4 = (s64)(s16)temp_index;
    fourth = temp_q4;

    switch (first) {
    case 0:
        var_4 = (u8 *)&D_0063BA30[0];
        var_5 = (u8 *)&sp20[0];
        var_3 = 5;
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
