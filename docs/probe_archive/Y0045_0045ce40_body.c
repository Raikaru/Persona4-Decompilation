/* Closest non-matching reconstruction archived before reverting to INCLUDE_ASM. */
void func_0045ce40(f32 *arg0, u8 *arg1, s32 *arg2, f32 farg0)
{
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f1_8;
    f32 var_f1_9;
    f32 var_f1_10;
    f32 var_f1_11;
    f32 var_f1_12;
    f32 var_f1_13;
    f32 var_f1_14;
    f32 var_f1_15;
    f32 var_f1_16;
    u32 temp_3;
    u32 temp_3_2;
    u32 temp_3_3;
    u32 temp_3_4;
    u32 temp_3_5;
    u32 temp_3_6;
    u32 temp_3_7;
    u32 temp_3_8;
    u32 temp_3_9;
    u32 temp_3_10;
    u32 temp_3_11;
    u32 temp_3_12;
    u32 temp_3_13;
    u32 temp_3_14;
    u32 temp_3_15;
    u32 temp_3_16;

    temp_f0 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    temp_f20 = *(f32 *)D_008872F8_abs - farg0;
    arg0[0] = (f32)arg2[0];
    arg0[1] = (f32)arg2[1];
    arg0[2] = temp_f20;
    temp_3 = arg1[0];
    if (temp_3 >= 0) {
        var_f1 = (f32)temp_3;
    } else {
        temp_3 = (temp_3 >> 1) | (temp_3 & 1);
        var_f1 = (f32)temp_3;
        var_f1 += var_f1;
    }
    arg0[8] = var_f1;
    temp_3_2 = arg1[1];
    if (temp_3_2 >= 0) {
        var_f1 = (f32)temp_3_2;
    } else {
        temp_3_2 = (temp_3_2 >> 1) | (temp_3_2 & 1);
        var_f1 = (f32)temp_3_2;
        var_f1 += var_f1;
    }
    arg0[9] = var_f1;
    temp_3_3 = arg1[2];
    if (temp_3_3 >= 0) {
        var_f1 = (f32)temp_3_3;
    } else {
        temp_3_3 = (temp_3_3 >> 1) | (temp_3_3 & 1);
        var_f1 = (f32)temp_3_3;
        var_f1 += var_f1;
    }
    arg0[10] = var_f1;
    temp_3_4 = arg1[3];
    if (temp_3_4 >= 0) {
        var_f1 = (f32)temp_3_4;
    } else {
        temp_3_4 = (temp_3_4 >> 1) | (temp_3_4 & 1);
        var_f1 = (f32)temp_3_4;
        var_f1 += var_f1;
    }
    arg0[11] = var_f1;
    arg0[6] = temp_f0;
    arg0[16] = (f32)(arg2[0] + arg2[2]);
    arg0[17] = (f32)arg2[1];
    arg0[18] = temp_f20;
    temp_3_5 = arg1[0];
    if (temp_3_5 >= 0) {
        var_f1 = (f32)temp_3_5;
    } else {
        temp_3_5 = (temp_3_5 >> 1) | (temp_3_5 & 1);
        var_f1 = (f32)temp_3_5;
        var_f1 += var_f1;
    }
    arg0[24] = var_f1;
    temp_3_6 = arg1[1];
    if (temp_3_6 >= 0) {
        var_f1 = (f32)temp_3_6;
    } else {
        temp_3_6 = (temp_3_6 >> 1) | (temp_3_6 & 1);
        var_f1 = (f32)temp_3_6;
        var_f1 += var_f1;
    }
    arg0[25] = var_f1;
    temp_3_7 = arg1[2];
    if (temp_3_7 >= 0) {
        var_f1 = (f32)temp_3_7;
    } else {
        temp_3_7 = (temp_3_7 >> 1) | (temp_3_7 & 1);
        var_f1 = (f32)temp_3_7;
        var_f1 += var_f1;
    }
    arg0[26] = var_f1;
    temp_3_8 = arg1[3];
    if (temp_3_8 >= 0) {
        var_f1 = (f32)temp_3_8;
    } else {
        temp_3_8 = (temp_3_8 >> 1) | (temp_3_8 & 1);
        var_f1 = (f32)temp_3_8;
        var_f1 += var_f1;
    }
    arg0[27] = var_f1;
    arg0[22] = temp_f0;
    arg0[32] = (f32)arg2[0];
    arg0[33] = (f32)(arg2[1] + arg2[3]);
    arg0[34] = temp_f20;
    temp_3_9 = arg1[0];
    if (temp_3_9 >= 0) {
        var_f1 = (f32)temp_3_9;
    } else {
        temp_3_9 = (temp_3_9 >> 1) | (temp_3_9 & 1);
        var_f1 = (f32)temp_3_9;
        var_f1 += var_f1;
    }
    arg0[40] = var_f1;
    temp_3_10 = arg1[1];
    if (temp_3_10 >= 0) {
        var_f1 = (f32)temp_3_10;
    } else {
        temp_3_10 = (temp_3_10 >> 1) | (temp_3_10 & 1);
        var_f1 = (f32)temp_3_10;
        var_f1 += var_f1;
    }
    arg0[41] = var_f1;
    temp_3_11 = arg1[2];
    if (temp_3_11 >= 0) {
        var_f1 = (f32)temp_3_11;
    } else {
        temp_3_11 = (temp_3_11 >> 1) | (temp_3_11 & 1);
        var_f1 = (f32)temp_3_11;
        var_f1 += var_f1;
    }
    arg0[42] = var_f1;
    temp_3_12 = arg1[3];
    if (temp_3_12 >= 0) {
        var_f1 = (f32)temp_3_12;
    } else {
        temp_3_12 = (temp_3_12 >> 1) | (temp_3_12 & 1);
        var_f1 = (f32)temp_3_12;
        var_f1 += var_f1;
    }
    arg0[43] = var_f1;
    arg0[38] = temp_f0;
    arg0[48] = (f32)(arg2[0] + arg2[2]);
    arg0[49] = (f32)(arg2[1] + arg2[3]);
    arg0[50] = temp_f20;
    temp_3_13 = arg1[0];
    if (temp_3_13 >= 0) {
        var_f1 = (f32)temp_3_13;
    } else {
        temp_3_13 = (temp_3_13 >> 1) | (temp_3_13 & 1);
        var_f1 = (f32)temp_3_13;
        var_f1 += var_f1;
    }
    arg0[56] = var_f1;
    temp_3_14 = arg1[1];
    if (temp_3_14 >= 0) {
        var_f1 = (f32)temp_3_14;
    } else {
        temp_3_14 = (temp_3_14 >> 1) | (temp_3_14 & 1);
        var_f1 = (f32)temp_3_14;
        var_f1 += var_f1;
    }
    arg0[57] = var_f1;
    temp_3_15 = arg1[2];
    if (temp_3_15 >= 0) {
        var_f1 = (f32)temp_3_15;
    } else {
        temp_3_15 = (temp_3_15 >> 1) | (temp_3_15 & 1);
        var_f1 = (f32)temp_3_15;
        var_f1 += var_f1;
    }
    arg0[58] = var_f1;
    temp_3_16 = arg1[3];
    if (temp_3_16 >= 0) {
        var_f1 = (f32)temp_3_16;
    } else {
        temp_3_16 = (temp_3_16 >> 1) | (temp_3_16 & 1);
        var_f1 = (f32)temp_3_16;
        var_f1 += var_f1;
    }
    arg0[59] = var_f1;
    arg0[54] = temp_f0;
}
