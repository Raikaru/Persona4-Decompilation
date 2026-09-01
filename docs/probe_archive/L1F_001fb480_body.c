/* Closest retained probe: explicit scale temporaries; object 1732B/window 1744B, normalized_diff 126. Reverted because not an exact MATCH. */
// FUN_001FB480
#define packet work.values
void func_001fb480(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fparg0)
{
    struct {
        f32 values[60];
        f32 tail[4];
    } work;
    
    f32 temp_f0;
    f32 var_f20;
    f32 var_f21;
    f32 var_f22;
    f32 var_f23;
    f32 var_f24;
    f32 var_f25;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;
    f32 var_f2_5;
    f32 var_f2_6;
    f32 var_f2_7;
    f32 var_f2_8;
    f32 var_f2_9;
    f32 var_f2_10;
    f32 var_f2_11;
    f32 var_f2_12;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    u32 temp_2;
    u32 temp_2_2;
    u32 temp_2_3;
    u32 temp_2_4;
    u32 temp_2_5;
    u32 temp_2_6;
    u32 temp_2_7;
    u32 temp_2_8;
    u32 temp_2_9;
    u32 temp_2_10;
    u32 temp_2_11;
    u32 temp_2_12;
    u32 temp_2_13;
    u32 temp_2_14;
    u32 temp_2_15;
    u32 temp_2_16;
    u32 temp_2_17;
    u8 *temp_16;
    u32 renderState;
    u8 *temp_22;
    f32 renderGlobal;
    f32 xScale;
    f32 yScale;

    temp_22 = func_00457120();
    temp_16 = func_00401b80();
    var_f20 = 640.0f / (f32)*(s32 *)(temp_16 + 0xC);
    var_f24 = 640.0f;
    var_f21 = 448.0f / (f32)*(s32 *)(temp_16 + 0x10);
    var_f25 = 448.0f;
    if (fparg0 == 0.0f) {
        var_f22 = 0.0f;
        var_f23 = 0.0f;
    } else {
        xScale = 320.0f;
        yScale = 224.0f;
        var_f22 = fGpffff82b4 + (-xScale) * fparg0;
        var_f23 = fGpffff82b8 + (-yScale) * fparg0;
        var_f24 = fGpffff82b4 + xScale * fparg0;
        var_f25 = fGpffff82b8 + yScale * fparg0;
    }
    renderState = (u32)D_00887300;
    ((void (*)(u32, u32))*(u32 *)renderState)(7, 2);
    ((void (*)(u32, u32))*(u32 *)renderState)(0x14, 1);
    ((void (*)(u32, u32))*(u32 *)renderState)(0xE, 0);
    ((void (*)(u32, u32))*(u32 *)renderState)(6, 0);
    ((void (*)(u32, u32))*(u32 *)renderState)(8, 0);
    ((void (*)(u32, u32))*(u32 *)renderState)(9, (u32)arg3);
    ((void (*)(u32, u32))*(u32 *)renderState)(0xC, 1);
    ((void (*)(u32, u32))*(u32 *)renderState)(1, (u32)temp_16);
    func_003f6440(2, arg1);
    func_003f6440(3, arg2);
    renderGlobal = D_008872FC[0];
    temp_f0 = 1.0f / *(f32 *)(temp_22 + 0x84);
    packet[0] = var_f22;
    packet[1] = var_f23;
    packet[2] = renderGlobal;
    temp_2 = arg0[0];
    if (temp_2 >= 0) {
        var_f2 = (f32)temp_2;
    } else {
        var_f2 = 2.0f * (f32)((temp_2 >> 1) | (temp_2 & 1));
    }
    packet[8] = var_f2;
    temp_2_2 = arg0[1];
    if (temp_2_2 >= 0) {
        var_f2_2 = (f32)temp_2_2;
    } else {
        var_f2_2 = 2.0f * (f32)((temp_2_2 >> 1) | (temp_2_2 & 1));
    }
    packet[9] = var_f2_2;
    temp_2_3 = arg0[2];
    if (temp_2_3 >= 0) {
        var_f2_3 = (f32)temp_2_3;
    } else {
        var_f2_3 = 2.0f * (f32)((temp_2_3 >> 1) | (temp_2_3 & 1));
    }
    packet[10] = var_f2_3;
    temp_2_4 = arg0[3];
    if (temp_2_4 >= 0) {
        var_f2_4 = (f32)temp_2_4;
    } else {
        var_f2_4 = 2.0f * (f32)((temp_2_4 >> 1) | (temp_2_4 & 1));
    }
    packet[11] = var_f2_4;
    packet[6] = temp_f0;
    packet[4] = 0.0f;
    packet[5] = 0.0f;
    packet[16] = var_f22;
    packet[17] = var_f25;
    packet[18] = renderGlobal;
    temp_2_5 = arg0[0];
    if (temp_2_5 >= 0) {
        var_f2_5 = (f32)temp_2_5;
    } else {
        var_f2_5 = 2.0f * (f32)((temp_2_5 >> 1) | (temp_2_5 & 1));
    }
    packet[24] = var_f2_5;
    temp_2_6 = arg0[1];
    if (temp_2_6 >= 0) {
        var_f2_6 = (f32)temp_2_6;
    } else {
        var_f2_6 = 2.0f * (f32)((temp_2_6 >> 1) | (temp_2_6 & 1));
    }
    packet[25] = var_f2_6;
    temp_2_7 = arg0[2];
    if (temp_2_7 >= 0) {
        var_f2_7 = (f32)temp_2_7;
    } else {
        var_f2_7 = 2.0f * (f32)((temp_2_7 >> 1) | (temp_2_7 & 1));
    }
    packet[26] = var_f2_7;
    temp_2_8 = arg0[3];
    if (temp_2_8 >= 0) {
        var_f2_8 = (f32)temp_2_8;
    } else {
        var_f2_8 = 2.0f * (f32)((temp_2_8 >> 1) | (temp_2_8 & 1));
    }
    packet[27] = var_f2_8;
    packet[22] = temp_f0;
    packet[20] = 0.0f;
    packet[21] = var_f21;
    packet[32] = var_f24;
    packet[33] = var_f23;
    packet[34] = renderGlobal;
    temp_2_9 = arg0[0];
    if (temp_2_9 >= 0) {
        var_f2_9 = (f32)temp_2_9;
    } else {
        var_f2_9 = 2.0f * (f32)((temp_2_9 >> 1) | (temp_2_9 & 1));
    }
    packet[40] = var_f2_9;
    temp_2_10 = arg0[1];
    if (temp_2_10 >= 0) {
        var_f2_10 = (f32)temp_2_10;
    } else {
        var_f2_10 = 2.0f * (f32)((temp_2_10 >> 1) | (temp_2_10 & 1));
    }
    packet[41] = var_f2_10;
    temp_2_11 = arg0[2];
    if (temp_2_11 >= 0) {
        var_f2_11 = (f32)temp_2_11;
    } else {
        var_f2_11 = 2.0f * (f32)((temp_2_11 >> 1) | (temp_2_11 & 1));
    }
    packet[42] = var_f2_11;
    temp_2_12 = arg0[3];
    if (temp_2_12 >= 0) {
        var_f2_12 = (f32)temp_2_12;
    } else {
        var_f2_12 = 2.0f * (f32)((temp_2_12 >> 1) | (temp_2_12 & 1));
    }
    packet[43] = var_f2_12;
    packet[38] = temp_f0;
    packet[36] = var_f20;
    packet[37] = 0.0f;
    packet[48] = var_f24;
    packet[49] = var_f25;
    packet[50] = renderGlobal;
    temp_2_13 = arg0[0];
    if (temp_2_13 >= 0) {
        var_f1 = (f32)temp_2_13;
    } else {
        var_f1 = 2.0f * (f32)((temp_2_13 >> 1) | (temp_2_13 & 1));
    }
    packet[56] = var_f1;
    temp_2_14 = arg0[1];
    if (temp_2_14 >= 0) {
        var_f1_2 = (f32)temp_2_14;
    } else {
        var_f1_2 = 2.0f * (f32)((temp_2_14 >> 1) | (temp_2_14 & 1));
    }
    packet[57] = var_f1_2;
    temp_2_15 = arg0[2];
    if (temp_2_15 >= 0) {
        var_f1_3 = (f32)temp_2_15;
    } else {
        var_f1_3 = 2.0f * (f32)((temp_2_15 >> 1) | (temp_2_15 & 1));
    }
    packet[58] = var_f1_3;
    temp_2_16 = arg0[3];
    if (temp_2_16 >= 0) {
        var_f1_4 = (f32)temp_2_16;
    } else {
        var_f1_4 = 2.0f * (f32)((temp_2_16 >> 1) | (temp_2_16 & 1));
    }
    packet[59] = var_f1_4;
    packet[54] = temp_f0;
    packet[52] = var_f20;
    packet[53] = var_f21;
    D_00887310[0](4, &packet[0], 4);
    ((void (*)(u32, u32))*(u32 *)renderState)(1, 0);
}
