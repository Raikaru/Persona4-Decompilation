// FUN_00266CC0
void func_00266cc0(s32 arg0, u8 *arg1)
{
    u8 *temp_2;
    u8 *temp_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 var_17;
    s32 var_18;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s16 temp_date;

    temp_2 = func_00452560(arg1);
    var_18 = *(s32 *)(temp_2 + 0xC);
    var_17 = *(s32 *)(temp_2 + 0x10);
    temp_date = (s16)func_001060b0();
    if (func_00110d30(temp_date) != 0) {
        if (*(s32 *)(temp_2 + 0xC) == 3) {
            var_18 = 6;
        }
        if (*(s32 *)(temp_2 + 0x10) == 3) {
            var_17 = 6;
        }
    }
    if (*(s32 *)temp_2 != 2) {
        return;
    }
    temp_3 = *(s32 *)(temp_2 + 0x14);
    if (temp_3 < 0xF) {
        temp_f20 = func_0044b7b0((fGpffff84a4 * (f32)temp_3) / 15.0f);
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 200.0f * (1.0f - temp_f20), 0.0f, 0.0f,
                      0.0f, temp_f20, 1.0f);
        temp_3_2 = *(s32 *)(temp_2 + 0x14);
        if (temp_3_2 >= 0xB) {
            temp_f1 = 255.0f * ((f32)(temp_3_2 - 0xA) / 5.0f);
            var_3 = (s32)temp_f1;
            func_0025f430(0, var_3 & 0xFF, var_18 + 1, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
        }
        return;
    }
    if (temp_3 < 0x14) {
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        func_0025f430(0, 0xFF, var_18 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        return;
    }
    if (temp_3 < 0x19) {
        temp_f20 = func_0044b7b0((fGpffff84a4 * (f32)(temp_3 - 0x14)) / 5.0f);
        temp_f21 = 1.0f - temp_f20;
        temp_3_2 = func_0025f2c0(0, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20,
                      0.0f, 0.0f, 0.0f, temp_f21, 1.0f);
        temp_3_2 = func_0025f2c0(var_18 + 1, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0, 0xFF, var_18 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20,
                      0.0f, 0.0f, 0.0f, temp_f21, 1.0f);
        return;
    }
    if (temp_3 < 0x1E) {
        temp_f20_2 = 1.0f -
                     func_0044b7b0((fGpffff84a4 * (f32)(temp_3 - 0x19)) / 5.0f);
        temp_f21_2 = 1.0f - temp_f20_2;
        temp_3_2 = func_0025f2c0(0, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20_2,
                      0.0f, 0.0f, 0.0f, temp_f21_2, 1.0f);
        temp_3_2 = func_0025f2c0(var_17 + 1, 0, *(u8 **)(temp_2 + 4));
        func_0025f430(0, 0xFF, var_17 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, ((f32)temp_3_2 / 2.0f) * temp_f20_2,
                      0.0f, 0.0f, 0.0f, temp_f21_2, 1.0f);
        return;
    }
    if (temp_3 < 0x28) {
        func_0025f430(0xFFFFFF, 0xFF, 0, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        func_0025f430(0, 0xFF, var_17 + 1, 0, *(u8 **)(temp_2 + 4), 1,
                      0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
        return;
    }
    if (temp_3 < 0x3C) {
        temp_f0_2 = func_0044b7b0((fGpffff84a4 * (f32)(temp_3 - 0x28)) / 20.0f);
        temp_f16 = 1.0f - temp_f0_2;
        temp_f2 = 255.0f * temp_f16;
        var_3_2 = (s32)temp_f2;
        func_0025f430(0xFFFFFF, var_3_2 & 0xFF, 0, 0,
                      *(u8 **)(temp_2 + 4), 1,
                      0, 0, -200.0f * temp_f0_2, 0.0f, 0.0f, 0.0f,
                      temp_f16, 1.0f);
        temp_3_3 = *(s32 *)(temp_2 + 0x14);
        if (temp_3_3 < 0x2D) {
            temp_f1_2 = 255.0f *
                        (1.0f - (f32)(temp_3_3 - 0x28) / 5.0f);
            var_3_3 = (s32)temp_f1_2;
            func_0025f430(0, var_3_3 & 0xFF, var_17 + 1, 0,
                          *(u8 **)(temp_2 + 4), 1,
                          0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                          1.0f, 1.0f);
        }
    }
}
