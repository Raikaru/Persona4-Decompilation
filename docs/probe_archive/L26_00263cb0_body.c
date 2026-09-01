/* Closest attempted body; reverted because scoped normalized_diff was nonzero. */
// FUN_00263CB0
void func_00263cb0(s32 arg0, u8 *arg1)
{
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    s128 spD0;
s32 spCC;
s32 spC8;
s32 spC4;
s32 spC0;
    s128 spB0;
s32 spAC;
s32 spA8;
s32 spA4;
s32 spA0;
    f32 *var_3;
    f32 *var_3_3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f20;
    f32 temp_f21;
    u8 *var_3_2;
    u8 *var_3_4;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_17;
    s32 temp_17_10;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_17_5;
    s32 temp_17_6;
    s32 temp_17_7;
    s32 temp_17_8;
    s32 temp_17_9;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_18_3;
    s32 temp_18_4;
    s32 temp_18_5;
    s32 temp_18_6;
    s32 temp_19;
    s32 temp_19_2;
    s32 temp_21;
    s32 temp_22;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 var_17;
    s32 var_18;
    s32 var_21;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s64 temp_20;
    s64 temp_20_2;
    u8 *temp_2;
    s32 temp_3;

    temp_2 = func_00452560(arg1);
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 3:
        temp_17 = *(s32 *)(temp_2 + 0x18);
        temp_2_2 = *(s32 *)(temp_2 + 0x20);
        if (temp_2_2 < 5) {
            temp_f20 = func_0044b7b0((fGpffff84a4 * (f32)temp_2_2) / 5.0f);
            temp_f0 = (f32)func_0025f2c0(2, 0, *(u8 **)(temp_2 + 4)) / 2.0f;
            temp_f13 = 1.0f - temp_f20;
            temp_f13_2 = 88.0f + temp_f0 * temp_f13;
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, temp_f13_2, 0.0f, 0.0f, 0.0f,
                          temp_f20, 1.0f);
        } else {
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, 88.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
        }
        temp_3_2 = *(s32 *)(temp_2 + 0x20);
        if (temp_3_2 >= 2) {
            temp_f0 = 255.0f * ((f32)(temp_3_2 - 1) / 9.0f);
            func_00263730(0, 0, (s32)temp_f0 & 0xFF, temp_17, 0,
                          temp_2, 0.0f);
        }
        break;
    case 4:
    case 9:
        temp_17_2 = *(s32 *)(temp_2 + 0x18);
        func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 88.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        func_00263730(0, 0, 0xFF, temp_17_2, 0, temp_2, 0.0f);
        break;
    case 5:
        temp_17_3 = *(s32 *)(temp_2 + 0xC);
        temp_3_4 = *(s32 *)(temp_2 + 0x10);
        if (temp_3_4 - temp_17_3 == 1) {
            if (*(s32 *)(temp_2 + 0x18) == temp_3_4) {
                var_18 = -0x5E;
            } else {
                var_18 = -*(s32 *)(temp_2 + 0x1C);
            }
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            func_00263730(var_18, 0, 0xFF, temp_17_3, 0, temp_2, 0.0f);
        } else {
            temp_17_4 = *(s32 *)(temp_2 + 0x18);
            temp_18 = -*(s32 *)(temp_2 + 0x1C);
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            func_00263730(temp_18, 0, 0xFF, temp_17_4, 0, temp_2, 0.0f);
        }
        break;
    case 8:
        temp_18_2 = *(s32 *)(temp_2 + 0x18);
        temp_3_3 = *(s32 *)(temp_2 + 0x20);
        if (temp_3_3 < 0xA) {
            temp_f0 = 255.0f * (1.0f - (f32)temp_3_3 / 10.0f);
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            var_21 = 0;
            while (var_21 < 7) {
                temp_20 = temp_18_2 - 1 + var_21;
                if ((temp_20 >= 0) && (var_21 != 1)) {
                    temp_19 = var_21 * 0x5E;
                    func_00262de0(temp_19 + 0xF, 0xF5, (s32)temp_f0 & 0xFF, (s32)temp_20, 0, 0x58, 0x5A, *(s32 *)(temp_2 + 4), 0.0f, 1.0f, 1.0f, 0);
                    temp_22 = *(s32 *)(temp_2 + 4);
                    func_00261560(temp_19, 0x127, (s32)temp_f0 & 0xFF, func_00110c50((s32)temp_20, temp_18_2) & 0xFFFF, 0, 0x58, 0x5A, temp_22, 0.0f, 1.0f, 1.0f, 0);
                }
                var_21 += 1;
            }
            func_00262de0(0x6D, 0xF5, 0xFF, temp_18_2, 1, 0, 0x58, *(s32 *)(temp_2 + 4), 0.0f, 1.0f, 1.0f, 0);
            temp_16 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0xFF, func_00110c50(temp_18_2, temp_18_2) & 0xFFFF, 1, 0, 0x58, temp_16, 0.0f, 1.0f, 1.0f, 0);
        } else if (temp_3_3 < 0x19) {
            func_0025f3f0(0xFFFFFF, 0xFF, 2, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          88.0f, 0.0f, 0.0f);
            var_3 = &spE8;
            var_2 = 4;
            if (var_3 != NULL) {
                do {
                    *(u8 *)var_3 = 0;
                    var_3 = (f32 *)((u8 *)var_3 + 1);
                    var_2 -= 1;
                } while (var_2 != 0);
            }
            spEC = spE8;
            var_3_2 = (u8 *)&spC0;
            var_2_2 = 0x10;
            if (var_3_2 != NULL) {
                do {
                    *var_3_2 = 0;
                    var_3_2 += 1;
                    var_2_2 -= 1;
                } while (var_2_2 != 0);
            }
            spC0 = 0;
            spC4 = 0;
            spC8 = 0x280;
            spCC = 0x1E0;
            spD0 = *(s128 *)&spC0;
            (*D_00887300)(0xE, 0);
            (*D_00887300)(0xC, 1);
            (*D_00887300)(7, 2);
            (*D_00887300)(9, 1);
            (*D_00887300)(0x14, 1);
            (*D_00887300)(6, 0);
            (*D_00887300)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x44);
            func_00489f80();
            func_0045d6e0(&spEC, &spD0, 10.0f, 0);
            func_0048a000();
            func_00262de0(0x6D, 0xF5, 0xFF, temp_18_2, 1, 0, 0x58, *(s32 *)(temp_2 + 4), 0.0f, 1.0f, 1.0f, 0);
            temp_16_2 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, 0xFF, func_00110c50(temp_18_2, temp_18_2) & 0xFFFF, 1, 0, 0x58, temp_16_2, 0.0f, 1.0f, 1.0f, 0);
        } else if (temp_3_3 < 0x1E) {
            temp_f20 = (f32)(temp_3_3 - 0x19) / 5.0f;
            temp_f0_2 = 1.0f - temp_f20;
            temp_f13_2 = 255.0f * temp_f0_2;
            temp_f0 = (f32)func_0025f2c0(2, 0, *(u8 **)(temp_2 + 4)) / 2.0f;
            temp_f13 = 88.0f + temp_f0 * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, 2, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          0, 0, temp_f13, 0.0f, 0.0f, 0.0f,
                          temp_f0_2, 1.0f);
            var_3_3 = &spE0;
            var_2_3 = 4;
            if (var_3_3 != NULL) {
                do {
                    *(u8 *)var_3_3 = 0;
                    var_3_3 = (f32 *)((u8 *)var_3_3 + 1);
                    var_2_3 -= 1;
                } while (var_2_3 != 0);
            }
            spE4 = spE0;
            var_3_4 = (u8 *)&spA0;
            var_2_4 = 0x10;
            if (var_3_4 != NULL) {
                do {
                    *var_3_4 = 0;
                    var_3_4 += 1;
                    var_2_4 -= 1;
                } while (var_2_4 != 0);
            }
            spA0 = 0;
            spA4 = 0;
            spA8 = 0x280;
            spAC = 0x1E0;
            spB0 = *(s128 *)&spA0;
            (*D_00887300)(0xE, 0);
            (*D_00887300)(0xC, 1);
            (*D_00887300)(7, 2);
            (*D_00887300)(9, 1);
            (*D_00887300)(0x14, 1);
            (*D_00887300)(6, 0);
            (*D_00887300)(8, 1);
            func_003f6440(3, 0x31003);
            func_003f6440(2, 0x44);
            func_00489f80();
            func_0045d6e0(&spE4, &spB0, 10.0f, 0);
            func_0048a000();
            func_00262de0(0x6D, 0xF5, (s32)temp_f13_2 & 0xFF, temp_18_2, 1, 0, 0x58, *(s32 *)(temp_2 + 4), 0.0f, 1.0f, 1.0f, 0);
            temp_16_3 = *(s32 *)(temp_2 + 4);
            func_00261560(0x5E, 0x127, (s32)temp_f13_2 & 0xFF, func_00110c50(temp_18_2, temp_18_2) & 0xFFFF, 1, 0, 0x58, temp_16_3, 0.0f, 1.0f, 1.0f, 0);
        }
        break;
    case 6:
        temp_17_5 = *(s32 *)(temp_2 + 0xC);
        if (*(s32 *)(temp_2 + 0x10) - temp_17_5 == 1) {
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, 88.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
            func_00263730(-0x5E, 0, 0xFF, temp_17_5, 0, temp_2, 0.0f);
        } else {
            temp_17_6 = *(s32 *)(temp_2 + 0x18);
            temp_18_3 = -*(s32 *)(temp_2 + 0x1C);
            func_0025f430(0xFFFFFF, 0xFF, 2, 0, *(u8 **)(temp_2 + 4), 1,
                          0, 0, 88.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
            func_00263730(temp_18_3, 0, 0xFF, temp_17_6, 0, temp_2, 0.0f);
        }
        break;
    case 0:
    case 1:
    case 2:
        break;
    default:
        break;
    }
}
