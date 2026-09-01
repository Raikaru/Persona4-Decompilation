/* Closest clean-C candidate for func_00164880; reverted because lverify normalized_diff remained 990 (object 1392B vs 1728B window). */
// FUN_00164880
u8 *func_00164880(s32 unused, u32 arg1, f32 arg2)
{
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 var_f22;
    s32 var_16_3;
    s32 var_18_2;
    s32 var_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    u32 temp_16;
    u32 var_16_2;
    u32 var_17_2;
    u32 var_17_3;
    u32 var_17_4;
    u32 var_18_3;
    u8 *temp_17;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *var_16;
    u8 *var_17;
    u8 *var_18;
    u8 *var_19;
    u8 *var_2;

    func_001452b0(0xF);
    var_16 = NULL;
    func_0015a160();
    var_f22 = 1.1754944e-38f;
    if (func_0014a200() == 1) {
        if (func_00164f40() < (s32)arg1) {
            var_18 = func_001452b0(0xF);
loop_44:
            if (var_18 == NULL) goto block_71;
            spA0 = *(f32 *)(var_18 + 0x140);
            spA4 = *(f32 *)(var_18 + 0x144);
            spA8 = *(f32 *)(var_18 + 0x148);
            var_17_2 = 0;
loop_10:
            if (var_17_2 < 4U) {
                var_4 = 0;
                temp_3 = D_007EF9B0 + var_17_2 * 0x750;
                if (*(s32 *)(temp_3 + 0x48) != 0 && *(s32 *)(temp_3 + 0x54) != 0) var_4 = 1;
                if (var_4 != 0) {
                    temp_2 = D_007EF9B0 + var_17_2 * 0x750;
                    temp_2_2 = func_0047a2f0(*(s32 *)(temp_2 + 0x50));
                    sp90 = spA0 - *(f32 *)(temp_2_2 + 0x30);
                    temp_2_3 = func_0047a2f0(*(s32 *)(temp_2 + 0x50));
                    sp94 = spA4 - *(f32 *)(temp_2_3 + 0x34);
                    temp_2_4 = func_0047a2f0(*(s32 *)(temp_2 + 0x50));
                    sp98 = spA8 - *(f32 *)(temp_2_4 + 0x38);
                    if (func_003e4180(&sp90) < 3000.0f) goto loop_12;
                }
                var_17_2 += 1;
                goto loop_10;
            }
loop_12:
            if (var_17_2 < 4U) {
                var_18 = *(u8 **)(var_18 + 0x138);
                goto loop_44;
            }
            if (func_00164f40() == 0) {
loop_14:
                var_16_2 = 0;
                var_18_2 = 0;
                var_2 = func_001452b0(0xF);
loop_16:
                if (var_2 != NULL) {
                    var_16_2 += 1;
                    var_2 = *(u8 **)(var_2 + 0x138);
                    goto loop_16;
                }
                temp_16 = func_003b7060() % var_16_2;
                var_17 = func_001452b0(0xF);
                var_3 = 0;
loop_19:
                if (var_3 < (s32)temp_16) {
                    var_17 = *(u8 **)(var_17 + 0x138);
                    var_3 += 1;
                    goto loop_19;
                }
                var_16_3 = 0;
loop_27:
                if (var_16_3 < 4) {
                    var_4_2 = 0;
                    temp_3_2 = D_007EF9B0 + var_16_3 * 0x750;
                    if (*(s32 *)(temp_3_2 + 0x48) != 0 && *(s32 *)(temp_3_2 + 0x54) != 0) var_4_2 = 1;
                    if (var_4_2 != 0) {
                        temp_2_2 = D_007EF9B0 + var_16_3 * 0x750;
                        temp_2_3 = func_0047a2f0(*(s32 *)(temp_2_2 + 0x50));
                        sp90 = *(f32 *)(var_17 + 0x140) - *(f32 *)(temp_2_3 + 0x30);
                        temp_2_4 = func_0047a2f0(*(s32 *)(temp_2_2 + 0x50));
                        sp94 = *(f32 *)(var_17 + 0x144) - *(f32 *)(temp_2_4 + 0x34);
                        temp_2_5 = func_0047a2f0(*(s32 *)(temp_2_2 + 0x50));
                        sp98 = *(f32 *)(var_17 + 0x148) - *(f32 *)(temp_2_5 + 0x38);
                        if (func_003e4180(&sp90) < 3000.0f) goto loop_28;
                    }
                    var_16_3 += 1;
                    goto loop_27;
                }
loop_28:
                if (var_16_3 < 4) var_18_2 = 1;
                if (func_0014cfd0(var_17 + 0x140) == 1) goto loop_14;
                if (var_18_2 == 1) goto loop_14;
                return var_17;
            }
            if (func_0014cfd0(var_18 + 0x140) == 1) {
                var_18 = *(u8 **)(var_18 + 0x138);
                goto loop_44;
            }
            temp_f24 = var_f22;
            temp_19 = var_16;
            var_17_3 = 0;
loop_42:
            if (var_17_3 < 0xFU) {
                temp_3_3 = D_007E8C00 + var_17_3 * 0x750;
                if (*(s32 *)(temp_3_3 + 0x48) != 0) {
                    temp_2_3 = *(u8 **)(temp_3_3 + 0x1AC);
                    sp90 = spA0 - *(f32 *)(temp_2_3 + 0x140);
                    sp94 = spA4 - *(f32 *)(temp_2_3 + 0x144);
                    sp98 = spA8 - *(f32 *)(temp_2_3 + 0x148);
                    temp_f0 = func_003e4180(&sp90);
                    if (temp_f0 > var_f22) { var_f22 = temp_f0; var_16 = var_18; }
                    if (temp_f0 < arg2) { var_f22 = temp_f24; var_16 = temp_19; goto block_41; }
                }
block_41:
                var_17_3 += 1;
                goto loop_42;
            }
            var_18 = *(u8 **)(var_18 + 0x138);
            goto loop_44;
        }
    }
    if (func_0014a270() == 1 && func_00164f40() < (s32)arg1) {
        var_19 = func_001452b0(0xF);
loop_70:
        if (var_19 == NULL) goto block_71;
        sp80 = *(f32 *)(var_19 + 0x140);
        sp84 = *(f32 *)(var_19 + 0x144);
        sp88 = *(f32 *)(var_19 + 0x148);
        var_17_4 = 0;
loop_56:
        if (var_17_4 < 4U) {
            var_4_3 = 0;
            temp_3_4 = D_007EF9B0 + var_17_4 * 0x750;
            if (*(s32 *)(temp_3_4 + 0x48) != 0 && *(s32 *)(temp_3_4 + 0x54) != 0) var_4_3 = 1;
            if (var_4_3 != 0) {
                temp_2_4 = D_007EF9B0 + var_17_4 * 0x750;
                temp_2_5 = func_0047a2f0(*(s32 *)(temp_2_4 + 0x50));
                sp70 = sp80 - *(f32 *)(temp_2_5 + 0x30);
                temp_2_3 = func_0047a2f0(*(s32 *)(temp_2_4 + 0x50));
                sp74 = sp84 - *(f32 *)(temp_2_3 + 0x34);
                temp_2_2 = func_0047a2f0(*(s32 *)(temp_2_4 + 0x50));
                sp78 = sp88 - *(f32 *)(temp_2_2 + 0x38);
                if (func_003e4180(&sp70) < 3000.0f) goto loop_58;
            }
            var_17_4 += 1;
            goto loop_56;
        }
loop_58:
        if (var_17_4 < 4U) {
            var_19 = *(u8 **)(var_19 + 0x138);
            goto loop_70;
        }
        if (func_00164f40() == 0) return var_19;
        temp_f24_2 = var_f22;
        temp_17 = var_16;
        var_18_3 = 0;
loop_68:
        if (var_18_3 < 0xFU) {
            temp_3_5 = D_007E8C00 + var_18_3 * 0x750;
            if (*(s32 *)(temp_3_5 + 0x48) != 0) {
                temp_2_5 = *(u8 **)(temp_3_5 + 0x1AC);
                sp70 = sp80 - *(f32 *)(temp_2_5 + 0x140);
                sp74 = sp84 - *(f32 *)(temp_2_5 + 0x144);
                sp78 = sp88 - *(f32 *)(temp_2_5 + 0x148);
                temp_f0_2 = func_003e4180(&sp70);
                if (temp_f0_2 > var_f22) { var_f22 = temp_f0_2; var_16 = var_19; }
                if (temp_f0_2 < arg2) { var_f22 = temp_f24_2; var_16 = temp_17; goto block_67; }
            }
block_67:
            var_18_3 += 1;
            goto loop_68;
        }
        var_19 = *(u8 **)(var_19 + 0x138);
        goto loop_70;
    }
block_71:
    return var_16;
}
