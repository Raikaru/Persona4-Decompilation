// FUN_00483A00 archive (wave Io lane IoA cut off mid-work; body is the live state at cutoff, status COMPILE_ERROR).
// FUN_00483A00
u8 *func_00483a00(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 spDC;
    s32 spD8;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC0;
    s128 spB0;
    s128 spA0;
    s32 temp_22;
    s32 temp_21;
    u8 *temp_19;
    u8 *temp_18;
    s32 temp_17;
    s32 var_16;
    u8 *temp_2_2;
    f32 temp_f0;
    s128 temp_2;

    spCC = arg3;
    temp_22 = (arg1 & 0xFFFF) * (arg0 & 0xFFFF);
    if (temp_22 >= 0x10000) {
        func_0046d730(D_00713448, 0x1CB);
    }
    func_0044ea90(D_00713448, 0x1CD);
    temp_21 = arg0 & 0xFFFF;
    temp_19 = jtbl_008873E8[0](temp_21 * 4 + 0x58, 0x40000);
    spC0 = func_003e9320();
    temp_17 = func_003c00e0();
    temp_2 = (arg2 & 0xFFFF) * temp_21;
    spB0 = temp_2;
    spA0 = temp_19 + 0x58;
    var_16 = 0;
    while ((var_16 & 0xFFFF) < temp_21) {
        *(s32 *)(*(s32 *)&spA0 + ((var_16 & 0xFFFF) * 4)) = func_003c4140();
        var_16 = (var_16 + 1) & 0xFFFF;
    }
    func_003c1b90(temp_17, spC0);
    spD0 = 0;
    spD4 = 0;
    spD8 = 0;
    temp_f0 = fGpffff8078;
    spDC = temp_f0;
    temp_2_2 = *(u8 **)(temp_18 + 0x5C);
    *(s32 *)(temp_2_2 + 4) = spD0;
    *(s32 *)(temp_2_2 + 8) = spD4;
    *(s32 *)(temp_2_2 + 0xC) = spD8;
    *(f32 *)(temp_2_2 + 0x10) = temp_f0;
    func_003c0210(temp_17, temp_18, 0);
    func_003c2a80(temp_18);
    *(s16 *)(temp_19 + 0) = 5;
    *(s32 *)(temp_19 + 4) = spCC;
    *(s16 *)(temp_19 + 8) = arg1;
    *(s16 *)(temp_19 + 0xA) = arg2;
    *(s32 *)(temp_19 + 0xC) = spC0;
    *(s32 *)(temp_19 + 0x10) = temp_17;
    *(s32 *)(temp_19 + 0x14) = 0;
    *(s16 *)(temp_19 + 0x48) = arg0;
    *(s16 *)(temp_19 + 0x4A) = temp_22;
    *(s16 *)(temp_19 + 0x4C) = (s16)spB0;
    *(s32 *)(temp_19 + 0x54) = (s32)spA0;
    *(s8 *)(temp_19 + 0x4E) = -1;
    *(s8 *)(temp_19 + 0x4F) = -1;
    *(s8 *)(temp_19 + 0x50) = -1;
    *(s8 *)(temp_19 + 0x51) = -1;
    func_0043f9c8(temp_19 + 0x18, 0, 0x30);
    *(s16 *)(temp_19 + 0x30) = 0x15;
    *(u8 **)(temp_19 + 0x34) = temp_19;
    return temp_19;
}
