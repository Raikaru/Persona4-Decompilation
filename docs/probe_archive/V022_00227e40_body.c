/* measured: object 1084B, retail window 1168B, normalized_diff 753; first differing offsets begin 0x0,0x4,0x8,0xC,0x10,0x14,0x18,0x20,0x24,0x28,0x2C,0x30,0x34,0x38,0x3C,0x40. Ruled out: plain (f32)(u16) casts at all three integer-to-float conversion sites, corrected func_001c0e50 return width, restored explicit cases 1 and 2, corrected callee parameter declarations, guard polarity, argument staging, local lifetime/overlap, global addressing mode, and measured optimization-level probes. Candidate remained undersized with a hundreds-level residual, so this body is archived per campaign stop condition. */
// FUN_00227E40
void func_00227e40(u8 *arg0)
{
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    f32 spCC;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    s32 temp_16;
    extern void func_002240e0(u8 *arg0);
    extern s32 func_001c0e50(u8 *arg0);

    *(u16 *)(arg0 + 0x110) = func_001c0e50(arg0);
    temp_16 = (s32)(func_001eb440((BtlTarget *)(*(u8 **)(arg0 + 0xE0) + 0x38)) & 0xFFFF);
    *(s32 *)(arg0 + 0x12C) = 0;
    if (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 0x10) {
        func_0019de70(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(arg0 + 0x110)) {
    case 1:
    case 2:
        if (!(temp_16 & 0xFFFF & 2)) {
            func_002240e0(arg0);
            return;
        }
    case 4:
        if (!(temp_16 & 0xFFFF & 2)) {
            func_002240e0(arg0);
            return;
        }
    case 3:
    case 5:
        if (temp_16 & 0xFFFF & 2) {
            u16 temp_2_2;
            u8 *temp_2;
            u8 *temp_16_2;
            f32 var_f1;
            temp_16 = 0;
            temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
                     ((func_00231d70(2) & 0xFFFF) * 0x34);
            temp_16_2 = temp_2 + 0x5B0;
            func_001bd780(&spCC, temp_16_2 + 4, temp_16_2 + 0x10, D_0060A0E0);
            spC0 = *(f32 *)(temp_16_2 + 4);
            spC4 = *(f32 *)(temp_16_2 + 8);
            spC8 = *(f32 *)(temp_16_2 + 0xC);
            func_001bd780(&spE8, temp_16_2 + 0x1C, temp_16_2 + 0x28, D_0060A0E0);
            spDC = *(f32 *)(temp_16_2 + 0x1C);
            spE0 = *(f32 *)(temp_16_2 + 0x20);
            spE4 = *(f32 *)(temp_16_2 + 0x24);
            temp_2_2 = *(u16 *)(temp_2 + 0x5B0);
            var_f1 = (f32)(u16)temp_2_2;
            func_001bac20((u16 *)(DAT_0076449c + 0x24), &spC0, &spDC, 1);
            func_001bbef0(DAT_0076449c + 0x24, var_f1 / 30.0f);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
            return;
        }
    case 6:
        if (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) {
            if (*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA2) == 0) {
                u16 temp_2_4;
                u8 *temp_2_3;
                u8 *temp_16_3;
                f32 var_f1_2;

                temp_2_3 = *(u8 **)(DAT_0076449c + 0xB98);
                temp_16_3 = temp_2_3 + 0x618;
                func_001bd780(&sp8C, temp_16_3 + 4, temp_16_3 + 0x10, D_0060A0E0);
                sp80 = *(f32 *)(temp_16_3 + 4);
                sp84 = *(f32 *)(temp_16_3 + 8);
                sp88 = *(f32 *)(temp_16_3 + 0xC);
                func_001bd780(&spA8, temp_16_3 + 0x1C, temp_16_3 + 0x28, D_0060A0E0);
                sp9C = *(f32 *)(temp_16_3 + 0x1C);
                spA0 = *(f32 *)(temp_16_3 + 0x20);
                spA4 = *(f32 *)(temp_16_3 + 0x24);
                temp_2_4 = *(u16 *)(temp_2_3 + 0x618);
                var_f1_2 = (f32)(u16)temp_2_4;
                func_001bac20((u16 *)(DAT_0076449c + 0x24), &sp80, &sp9C, 1);
                func_001bbef0(DAT_0076449c + 0x24, var_f1_2 / 30.0f);
            } else {
                u16 temp_2_6;
                u8 *temp_2_5;
                u8 *temp_16_4;
                f32 var_f1_3;

                temp_2_5 = *(u8 **)(DAT_0076449c + 0xB98) +
                           ((func_00231d70(2) & 0xFFFF) * 0x34);
                temp_16_4 = temp_2_5 + 0x64C;
                func_001bd780(&sp4C, temp_16_4 + 4, temp_16_4 + 0x10, D_0060A0E0);
                sp40 = *(f32 *)(temp_16_4 + 4);
                sp44 = *(f32 *)(temp_16_4 + 8);
                sp48 = *(f32 *)(temp_16_4 + 0xC);
                func_001bd780(&sp68, temp_16_4 + 0x1C, temp_16_4 + 0x28, D_0060A0E0);
                sp5C = *(f32 *)(temp_16_4 + 0x1C);
                sp60 = *(f32 *)(temp_16_4 + 0x20);
                sp64 = *(f32 *)(temp_16_4 + 0x24);
                temp_2_6 = *(u16 *)(temp_2_5 + 0x64C);
                var_f1_3 = (f32)(u16)temp_2_6;
                func_001bac20((u16 *)(DAT_0076449c + 0x24), &sp40, &sp5C, 1);
                func_001bbef0(DAT_0076449c + 0x24, var_f1_3 / 30.0f);
            }
            func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0x100, 0);
        }
    default:
        return;
    }
}
