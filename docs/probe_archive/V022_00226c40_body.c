/* measured: object 1412B, retail window 1520B, normalized_diff 989; first differing offsets 0x0,0x1,0x4,0x8,0xA,0xC,0xE,0x10,0x12,0x14,0x16,0x18,0x1A,0x1B,0x1C,0x1D. Conversion sites used plain casts (f32)(u16) at the three integer-to-float conversion sites. Ruled out: corrected local callee declarations, direct integer-domain pointer arithmetic, explicit switch cases, plain pointer dereferences, saved-register/lifetime variants, and optimization-level/layout probes; body remained 108B smaller than retail and residual remained in the hundreds.

// FUN_00226C40
void func_00226c40(u8 *arg0)
{
    s8 sp11F;
    u8 sp11E;
    u8 sp11D;
    u8 sp11C;
    f32 sp108;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spBC;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    s32 temp_5;
    s32 var_17;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;
    u16 temp_2_3;
    u16 temp_2_5;
    u16 temp_2_7;
    u16 temp_3;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_16_5;
    u8 *temp_18;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_6;
    u8 *temp_3_2;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *var_4;
    extern void func_00194f60(u8 *arg0, s32 arg1);
    extern void func_00195590(void *arg0, const void *arg1);
    extern void func_0019d0c0(u8 *arg0);
    extern void func_0019de70(u8 *arg0, u16 arg1);
    extern void func_001c5110(u8 *arg0);
    extern s32 func_001c0e50(u8 *arg0);
    extern s32 func_0022f950(u8 *arg0, u8 *arg1);
    extern u32 func_00231d70(u32 arg0);

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_16 = *(u8 **)(temp_2 + 0x30);
    temp_18 = *(u8 **)(temp_16 + 0xA0C);
    if ((temp_2 != NULL) && (*(u8 *)(temp_16 + 0xA2) == 0)) {
        var_17 = 0;
        while ((var_17 & 0xFFFF) < *(u16 *)(temp_2 + 0x6A)) {
            temp_4 = temp_2 + ((var_17 & 0xFFFF) * 4);
            temp_4_2 = *(u8 **)(*(u8 **)(temp_4 + 0x38) + 0x30);
            if (*(u8 *)(temp_4_2 + 0xA2) == 1) {
                func_00195590(temp_4_2, temp_16 + 4);
            }
            var_17 = (var_17 + 1) & 0xFFFF;
        }
    }
    *(u16 *)(arg0 + 0x110) = func_001c0e50(arg0);
    var_2 = (temp_18 != NULL);
    if (var_2 != 0) {
        var_2 = (func_0022f950(*(u8 **)(arg0 + 0xE0), temp_18) != 0);
    }
    if ((var_2 != 0) && (*(u16 *)(arg0 + 0x110) != 1)) {
        func_0019d0c0(temp_18);
        sp11C = *(u8 *)(temp_18 + 0x30);
        sp11D = *(u8 *)(temp_18 + 0x31);
        sp11E = *(u8 *)(temp_18 + 0x32);
        sp11F = 0;
        func_00194f60(temp_18, (s32)sp11C);
    }
    func_0019de70(temp_18, 0);
    temp_3 = *(u16 *)(arg0 + 0x110);
    switch (temp_3) {
    case 0:
    case 1:
    case 2:
    case 4:
        func_001c5110(arg0);
        temp_4_3 = *(u8 **)(arg0 + 0xE0);
        if ((*(u16 *)(temp_4_3 + 0x6A) == 1) &&
            (*(u8 *)(*(u8 **)(temp_4_3 + 0x30) + 0xA2) == 0)) {
            temp_3_2 = *(u8 **)(temp_4_3 + 0x38);
            if ((temp_4_3 != temp_3_2) &&
                (*(u8 *)(*(u8 **)(temp_3_2 + 0x30) + 0xA2) == 0)) {
                func_001bcd40(temp_4_3, NULL, NULL, 8, 0);
                return;
            }
        }
        return;
    case 3:
    case 5:
        temp_16_2 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        temp_5 = func_00231d70(2) & 0xFFFF;
        if (*(u8 *)(temp_16_2 + 0xA2) != 0) {
            var_2_2 = 0;
        } else {
            var_3 = 0;
            var_4 = *(u8 **)(DAT_0076449c + 0x17C);
            while (var_4 != NULL) {
                if (temp_16_2 != var_4) {
                    var_3 = (var_3 + 1) & 0xFFFF;
                    var_4 = *(u8 **)(var_4 + 0xA68);
                } else {
                    break;
                }
            }
            var_2_2 = var_3 & 0xFFFF;
        }
        temp_2_2 = *(u8 **)(DAT_0076449c + 0xB98) + ((var_2_2 & 0xFFFF) * 0x68) + ((temp_5 & 0xFFFF) * 0x34);
        temp_16_3 = temp_2_2 + 0x3A8;
        func_001bd780(&spEC, temp_16_3 + 4, temp_16_3 + 0x10, D_0060A0E0);
        spE0 = *(f32 *)(temp_16_3 + 4);
        spE4 = *(f32 *)(temp_16_3 + 8);
        spE8 = *(f32 *)(temp_16_3 + 0xC);
        func_001bd780(&sp108, temp_16_3 + 0x1C, temp_16_3 + 0x28, D_0060A0E0);
        spFC = *(f32 *)(temp_16_3 + 0x1C);
        sp100 = *(f32 *)(temp_16_3 + 0x20);
        sp104 = *(f32 *)(temp_16_3 + 0x24);
        temp_2_3 = *(u16 *)(temp_2_2 + 0x3A8);
        var_f1 = (f32)(u16)temp_2_3;
        func_001bac20((u16 *)(DAT_0076449c + 0x24), &spE0, &spFC, 1);
        func_001bbef0(DAT_0076449c + 0x24, var_f1 / 30.0f);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
        return;
    case 6:
        temp_4_4 = *(u8 **)(arg0 + 0xE0);
        if (*(u16 *)(temp_4_4 + 0x1A) & 1) {
            if (*(u8 *)(*(u8 **)(temp_4_4 + 0x30) + 0xA2) == 0) {
                temp_2_4 = *(u8 **)(DAT_0076449c + 0xB98);
                temp_16_4 = temp_2_4 + 0x618;
                func_001bd780(&spAC, temp_16_4 + 4, temp_16_4 + 0x10, D_0060A0E0);
                spA0 = *(f32 *)(temp_16_4 + 4);
                spA4 = *(f32 *)(temp_16_4 + 8);
                spA8 = *(f32 *)(temp_16_4 + 0xC);
                func_001bd780(&spC8, temp_16_4 + 0x1C, temp_16_4 + 0x28, D_0060A0E0);
                spBC = *(f32 *)(temp_16_4 + 0x1C);
                spC0 = *(f32 *)(temp_16_4 + 0x20);
                spC4 = *(f32 *)(temp_16_4 + 0x24);
                temp_2_5 = *(u16 *)(temp_2_4 + 0x618);
                var_f1_2 = (f32)(u16)temp_2_5;
                func_001bac20((u16 *)(DAT_0076449c + 0x24), &spA0, &spBC, 1);
                func_001bbef0(DAT_0076449c + 0x24, var_f1_2 / 30.0f);
            } else {
                temp_2_6 = *(u8 **)(DAT_0076449c + 0xB98) + ((func_00231d70(2) & 0xFFFF) * 0x34);
                temp_16_5 = temp_2_6 + 0x64C;
                func_001bd780(&sp6C, temp_16_5 + 4, temp_16_5 + 0x10, D_0060A0E0);
                sp60 = *(f32 *)(temp_16_5 + 4);
                sp64 = *(f32 *)(temp_16_5 + 8);
                sp68 = *(f32 *)(temp_16_5 + 0xC);
                func_001bd780(&sp88, temp_16_5 + 0x1C, temp_16_5 + 0x28, D_0060A0E0);
                sp7C = *(f32 *)(temp_16_5 + 0x1C);
                sp80 = *(f32 *)(temp_16_5 + 0x20);
                sp84 = *(f32 *)(temp_16_5 + 0x24);
                temp_2_7 = *(u16 *)(temp_2_6 + 0x64C);
                var_f1_3 = (f32)(u16)temp_2_7;
                func_001bac20((u16 *)(DAT_0076449c + 0x24), &sp60, &sp7C, 1);
                func_001bbef0(DAT_0076449c + 0x24, var_f1_3 / 30.0f);
            }
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
        }
    default:
        return;
    }
}
