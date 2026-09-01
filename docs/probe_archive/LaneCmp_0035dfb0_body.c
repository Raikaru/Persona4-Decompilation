/* Closest reconstruction attempt for FUN_0035DFB0; reverted because scoped lverify remained MISMATCH (normalized_diff 1183). */

void func_0035dfb0(u8* arg0, s32 arg1, s32 arg2) {
    u8 spBF;
    u8 spBE;
    u8 spBD;
    u8 spBC;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f20;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f24;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f15;
    f32 var_f15_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f21;
    s32 var_19;
    s32 var_3;
    s32 var_3_2;
    u16 temp_2_3;
    u16 temp_2_4;
    u8 temp_20;
    u8 temp_2;
    u8 temp_2_2;
    u8 temp_2_5;
    u8 var_21;
    u8 *temp_3;
    u8 *temp_3_2;

    temp_f23 = *(f32 *)(arg0 + 8);
    temp_f22 = *(f32 *)(arg0 + 0xC);
    temp_f24 = (f32)*arg0 / 255.0f;
    if (arg2 != 1) {
        temp_3 = (u8 *)(arg1 * 0x30 + arg0);
        var_f21 = 60.0f + (464.0f + (temp_f23 + *(f32 *)(temp_3 + 0x208)));
        var_f20 = 119.0f + (temp_f22 + *(f32 *)(temp_3 + 0x20C)) +
                  32.0f * (f32)arg1;
        temp_f1 = (f32)*(u8 *)(temp_3 + 0x212) * temp_f24;
        var_3 = (s32)temp_f1;
        var_19 = *(s32 *)(arg0 + 0x45C);
        temp_2_3 = *(u16 *)(arg0 + arg1 * 2 + 0x3A);
        if ((s32)temp_2_3 < 5)
            var_f1_2 = func_0044b7b0((iGpffff8094 * (f32)temp_2_3) / 5.0f);
        else
            var_f1_2 = 1.0f;
        if (*(s32 *)(arg0 + arg1 * 4 + 0x48) != 0)
            var_f15 = 180.0f * var_f1_2 - 90.0f;
        else
            var_f15 = 180.0f * var_f1_2 - 270.0f;
        func_0034f320((u8 *)var_19, 0xFF, 0xFF, 0xFF, var_3 & 0xFF,
                      0x1000, 0x1000, 0x11, var_f21, var_f20, 0.0f, var_f15, 0);
    }
    if (arg2 == 2) {
        func_00489f80();
        D_00887300[0](1, 0);
        spBC = 0;
        spBD = 0;
        spBE = 0;
        spBF = 0;
        func_0045c870(&spBC, 0);
        temp_2_4 = *(u16 *)(arg0 + arg1 * 2 + 0x3A);
        if ((s32)temp_2_4 < 5)
            var_f1_3 = func_0044b7b0((iGpffff8094 * (f32)temp_2_4) / 5.0f);
        else
            var_f1_3 = 1.0f;
        if (*(s32 *)(arg0 + arg1 * 4 + 0x48) != 0)
            var_f15_2 = 180.0f * var_f1_3 - 90.0f;
        else
            var_f15_2 = 180.0f * var_f1_3 - 270.0f;
        func_0034f320((u8 *)var_19, 0xFF, 0xFF, 0xFF, 0xFF,
                      0x1000, 0x1000, 0x11, var_f21, var_f20, 0.0f, var_f15_2, 0);
        func_0048a000();
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
    temp_f1_2 = (f32)*(u8 *)(arg0 + arg1 * 0x30 + 0xC2) * temp_f24;
    var_3_2 = (s32)temp_f1_2;
    temp_20 = var_3_2 & 0xFF;
    if (arg2 == 1) {
        spBC = 0x80; spBD = 0x80; spBE = 0x80; var_21 = 0x80;
    } else if (arg2 == 2) {
        spBC = 0xFF; spBD = 0xFF; spBE = 0xFF; var_21 = 0xFF;
    } else if (*(s32 *)(arg0 + arg1 * 4 + 0x48) != 0) {
        spBC = 0xFF; spBD = 0xFF; spBE = 0xFF; var_21 = 0x80;
    } else {
        spBC = 0x80; spBD = 0x80; spBE = 0x80; var_21 = 0xFF;
    }
    temp_3_2 = (u8 *)(arg1 * 0x30 + arg0);
    temp_f20 = 32.0f * (f32)arg1;
    func_0034f2e0(*(u8 **)(arg0 + 0x454), spBC, spBD, spBE, temp_20,
                   477.0f + (temp_f23 + *(f32 *)(temp_3_2 + 0x208)),
                   temp_f20 + (121.0f + (temp_f22 + *(f32 *)(temp_3_2 + 0x20C))));
    func_0034f2e0(*(u8 **)(arg0 + 0x458), var_21, var_21, var_21, temp_20,
                   556.0f + (temp_f23 + *(f32 *)(temp_3_2 + 0x208)),
                   temp_f20 + (131.0f + (temp_f22 + *(f32 *)(temp_3_2 + 0x20C))));
    if (arg2 == 2) {
        func_003f6440(3, 0x717FB);
        func_003f6440(2, 0x44);
    }
}
