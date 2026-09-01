/* measured: object 1248B, retail window 1344B, normalized_diff 839; first differing offsets 0x0,0x4,0x8,0xA,0xC,0xE,0x10,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A. Conversion sites used plain casts (f32)(u16) at all three lhu/cvt.s.w/or/mtc1 sequences. Ruled out: corrected callee widths and argument counts (including func_002266b0's four float parameters), explicit switch cases, guard polarity, pointer/address materialization, local lifetime/overlap, global addressing mode, and measured optimization-level probes. Candidate remained undersized with a hundreds-level residual, so this body is archived per campaign stop condition. */
// FUN_00227230
void func_00227230(u8 *arg0)
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
    extern void func_0019de70(u8 *arg0, u16 arg1);
    extern s32 func_0019fc70(u8 *arg0);
    extern void func_001bac20(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4);
    extern void func_001bbef0(u8 *arg0, f32 arg1);
    extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, s32 arg3, f32 arg4);
    extern void func_001bd780(void *out, const void *first, const void *second, const void *config);
    extern s32 func_001c0e50(u8 *arg0);
    extern void func_001c5110(u8 *arg0);
    extern u16 func_001eb440(u8 *arg0);
    extern u32 func_00231d70(u32 arg0);
    extern s32 func_00243ce0(u8 *arg0);
    extern void func_002250a0(u8 *arg0, f32 arg1, f32 arg2);
    extern void func_002266b0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    *(u16 *)(arg0 + 0x110) = func_001c0e50(arg0);
    temp_16 = (s32)(func_001eb440(*(u8 **)(arg0 + 0xE0) + 0x38) & 0xFFFF);
    *(s32 *)(arg0 + 0x12C) = 0;
    if (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 0x10) {
        func_0019de70(*(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(arg0 + 0x110)) {
    case 1:
        if (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 0x10) {
            func_001c5110(arg0);
            return;
        }
    case 2:
        if (!(temp_16 & 0xFFFF & 2)) {
            func_002266b0(arg0, 0.0f, 3.0f, 0.0f, 2.0f);
            return;
        }
    case 4:
        if (!(temp_16 & 0xFFFF & 2)) {
            if ((func_00243ce0((u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64)) != 0) &&
                (func_0019fc70(*(u8 **)(arg0 + 0xE0)) != 0)) {
                func_002250a0(arg0, 0.0f, 0.75f);
                return;
            }
            func_002266b0(arg0, 0.0f, 3.0f, 0.0f, 2.0f);
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
            if (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA2) == 0) {
                u8 *temp_2_3;
                u8 *temp_16_3;
                u16 temp_2_4;
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
