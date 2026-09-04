u8 *func_00377eb0(u8 *arg0, s32 arg1) {
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
    u8 sp[0xB0];

    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    s32 sp8C;
    f32 sp88;
    f32 sp84;
    s32 sp80;
    f32 sp7C;
    f32 sp78;
    s32 sp74;
    f32 sp70;
    f32 sp6C;
    s32 sp68;
    f32 sp64;
    f32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    u8 *temp_2_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 var_5;
    s32 var_5_2;
    u8 *temp_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_4;
    u8 *temp_4_2;

    func_0044ea90(D_0064EA20, 0x76C);
    temp_2_2 = D_008873F4[0](1, 0x240, 0x40000);
    if (temp_2_2 == NULL) {
        func_0046d730(D_0064EA20, 0x76D);
    }
    temp_2 = (u8 *)(func_00451fc0(arg0, D_0064EA60, 0x12, 0, 0, (void *)func_00377e10, (void *)func_00377e60, temp_2_2));
    if (temp_2 == NULL) {
        func_0046d730(D_0064EA20, 0x777);
    }
    func_003781d0(temp_2, arg1);
    func_00378260(temp_2, 0xFF, 0xFF, 0xFF, 0);
    temp_f1 = -30.0f;
    sp60 = temp_f1;
    temp_f0 = (f32)(s32)(iGpffff83e0);
    sp64 = temp_f0;
    sp68 = 0;
    sp50 = 0x3F7E0000;
    sp40 = 0;
    sp6C = 30.0f;
    sp70 = temp_f0;
    sp74 = 0;
    sp54 = 0;
    sp44 = 0;
    sp78 = temp_f1;
    temp_f0_2 = -temp_f0;
    sp7C = temp_f0_2;
    sp80 = 0;
    sp58 = 0x3F7E0000;
    sp48 = 0x3F250000;
    sp84 = 30.0f;
    sp88 = temp_f0_2;
    sp8C = 0;
    sp5C = 0;
    sp4C = 0x3F250000;
    var_5 = 0;
loop_6:
    if (var_5 < 4) {
        temp_2_3 = (u8 *)((var_5 * 0xC) + sp);
        temp_2_4 = (u8 *)(temp_2_3 + 0x60);
        spA0 = (f32)(s32)(M2C_FIELD(temp_2_3, f32 *, 0x60));
        spA4 = (f32)(s32)(M2C_FIELD(temp_2_4, f32 *, 4));
        temp_f0_3 = (f32)(s32)(M2C_FIELD(temp_2_4, f32 *, 8));
        spA8 = temp_f0_3;
        temp_4 = (u8 *)(temp_2_2 + (var_5 * 0x24));
        M2C_FIELD(temp_4, f32 *, 0x120) = spA0;
        M2C_FIELD(temp_4, f32 *, 0x124) = spA4;
        M2C_FIELD(temp_4, f32 *, 0x128) = temp_f0_3;
        M2C_FIELD(temp_4, s8 *, 0x12C) = 0xFF;
        M2C_FIELD(temp_4, s8 *, 0x12D) = 0xFF;
        M2C_FIELD(temp_4, s8 *, 0x12E) = 0xFF;
        M2C_FIELD(temp_4, s8 *, 0x12F) = 0xFF;
        temp_2_5 = (u8 *)((var_5 * 4) + sp);
        M2C_FIELD(temp_4, f32 *, 0x13C) = (f32) M2C_FIELD(temp_2_5, f32 *, 0x50);
        M2C_FIELD(temp_4, f32 *, 0x140) = (f32) M2C_FIELD(temp_2_5, f32 *, 0x40);
        var_5 += 1;
        goto loop_6;
    }
    sp60 = 30.0f;
    temp_f0_4 = (f32)(s32)(iGpffff83e0);
    sp64 = temp_f0_4;
    sp68 = 0;
    sp50 = 0x3F7E0000;
    sp40 = 0;
    temp_f1_2 = -30.0f;
    sp6C = temp_f1_2;
    sp70 = temp_f0_4;
    sp74 = 0;
    sp54 = 0;
    sp44 = 0;
    sp78 = 30.0f;
    temp_f0_5 = -temp_f0_4;
    sp7C = temp_f0_5;
    sp80 = 0;
    sp58 = 0x3F7E0000;
    sp48 = 0x3F250000;
    sp84 = temp_f1_2;
    sp88 = temp_f0_5;
    sp8C = 0;
    sp5C = 0;
    sp4C = 0x3F250000;
    var_5_2 = 0;
loop_9:
    if (var_5_2 < 4) {
        temp_2_6 = (u8 *)((var_5_2 * 0xC) + sp);
        temp_2_7 = (u8 *)(temp_2_6 + 0x60);
        sp90 = (f32)(s32)(M2C_FIELD(temp_2_6, f32 *, 0x60));
        sp94 = (f32)(s32)(M2C_FIELD(temp_2_7, f32 *, 4));
        temp_f0_6 = (f32)(s32)(M2C_FIELD(temp_2_7, f32 *, 8));
        sp98 = temp_f0_6;
        temp_4_2 = (u8 *)(temp_2_2 + (var_5_2 * 0x24));
        M2C_FIELD(temp_4_2, f32 *, 0x1B0) = sp90;
        M2C_FIELD(temp_4_2, f32 *, 0x1B4) = sp94;
        M2C_FIELD(temp_4_2, f32 *, 0x1B8) = temp_f0_6;
        M2C_FIELD(temp_4_2, s8 *, 0x1BC) = 0xFF;
        M2C_FIELD(temp_4_2, s8 *, 0x1BD) = 0xFF;
        M2C_FIELD(temp_4_2, s8 *, 0x1BE) = 0xFF;
        M2C_FIELD(temp_4_2, s8 *, 0x1BF) = 0xFF;
        temp_2_8 = (u8 *)((var_5_2 * 4) + sp);
        M2C_FIELD(temp_4_2, f32 *, 0x1CC) = (f32) M2C_FIELD(temp_2_8, f32 *, 0x50);
        M2C_FIELD(temp_4_2, f32 *, 0x1D0) = (f32) M2C_FIELD(temp_2_8, f32 *, 0x40);
        var_5_2 += 1;
        goto loop_9;
    }
    return (u8 *)(temp_2);
}

