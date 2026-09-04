/* measured: object 1008B, retail window 864B, normalized_diff 234; differing bytes across the whole function, prologue/epilogue/register layout (extra FPRs f22-f25, s0 save, ra slot) and FMA pattern differ. Manual C from m2c with M2C_FIELD removed and sum-of-products shape, explicit f20/f21 variables, temp_2 pointers. W39c1b 2026-09-03. */

s32 func_001b7520(u8 *arg0)
{
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 var_f0;
    f32 var_f1;
    f32 f20;
    f32 f21;
    s32 temp_3;
    u32 temp_4;
    u32 temp_2_3;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;

    temp_3 = *(s32 *)(D_0076449C + 0xC);
    if (!(temp_3 & 2)) {
        return 1;
    }
    if (!(temp_3 & 0x02000000)) {
        return 1;
    }
    if (*(u32 *)(arg0 + 0x64) == 0) {
        temp_2 = func_00149ca0();
        *(f32 *)(arg0 + 0x40) = *(f32 *)(temp_2 + 0);
        *(f32 *)(arg0 + 0x44) = *(f32 *)(temp_2 + 4);
        *(f32 *)(arg0 + 0x48) = *(f32 *)(temp_2 + 8);
        *(f32 *)(arg0 + 0x4C) = *(f32 *)(temp_2 + 0xC);
        temp_2_2 = func_00149ce0();
        *(f32 *)(arg0 + 0x50) = *(f32 *)(temp_2_2 + 0);
        *(f32 *)(arg0 + 0x54) = *(f32 *)(temp_2_2 + 4);
        *(f32 *)(arg0 + 0x58) = *(f32 *)(temp_2_2 + 8);
        *(f32 *)(arg0 + 0x5C) = *(f32 *)(temp_2_2 + 0xC);
        *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x40) * *(f32 *)(arg0 + 0);
        *(f32 *)(arg0 + 0x24) = *(f32 *)(arg0 + 0x44) * *(f32 *)(arg0 + 4);
        *(f32 *)(arg0 + 0x28) = *(f32 *)(arg0 + 0x48) * *(f32 *)(arg0 + 8);
        *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x4C) * *(f32 *)(arg0 + 0xC);
        *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x50) * *(f32 *)(arg0 + 0x10);
        *(f32 *)(arg0 + 0x34) = *(f32 *)(arg0 + 0x54) * *(f32 *)(arg0 + 0x14);
        *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x58) * *(f32 *)(arg0 + 0x18);
        *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg0 + 0x5C) * *(f32 *)(arg0 + 0x1C);
    }
    temp_4 = *(u32 *)(arg0 + 0x60);
    temp_2_3 = *(u32 *)(arg0 + 0x64);
    if (temp_2_3 < temp_4) {
        if ((s32) temp_2_3 >= 0) {
            var_f1 = (f32) temp_2_3;
        } else {
            var_f1 = 2.0f * (f32) ((temp_2_3 >> 1) | (temp_2_3 & 1));
        }
        if ((s32) temp_4 >= 0) {
            var_f0 = (f32) temp_4;
        } else {
            var_f0 = 2.0f * (f32) ((temp_4 >> 1) | (temp_4 & 1));
        }
        f21 = var_f1 / var_f0;
        f20 = 1.0f - f21;
        sp30 = (*(f32 *)(arg0 + 0x40) * f20) + (*(f32 *)(arg0 + 0x20) * f21);
        sp34 = (*(f32 *)(arg0 + 0x44) * f20) + (*(f32 *)(arg0 + 0x24) * f21);
        sp38 = (*(f32 *)(arg0 + 0x48) * f20) + (*(f32 *)(arg0 + 0x28) * f21);
        sp3C = (*(f32 *)(arg0 + 0x4C) * f20) + (*(f32 *)(arg0 + 0x2C) * f21);
        temp_2_4 = func_00149ca0();
        *(f32 *)(temp_2_4 + 0) = sp30;
        *(f32 *)(temp_2_4 + 4) = sp34;
        *(f32 *)(temp_2_4 + 8) = sp38;
        *(f32 *)(temp_2_4 + 0xC) = sp3C;
        sp30 = (*(f32 *)(arg0 + 0x30) * f21) + (*(f32 *)(arg0 + 0x50) * f20);
        sp34 = (*(f32 *)(arg0 + 0x34) * f21) + (*(f32 *)(arg0 + 0x54) * f20);
        sp38 = (*(f32 *)(arg0 + 0x38) * f21) + (*(f32 *)(arg0 + 0x58) * f20);
        sp3C = (*(f32 *)(arg0 + 0x3C) * f21) + (*(f32 *)(arg0 + 0x5C) * f20);
        temp_2_5 = func_00149ce0();
        *(f32 *)(temp_2_5 + 0) = sp30;
        *(f32 *)(temp_2_5 + 4) = sp34;
        *(f32 *)(temp_2_5 + 8) = sp38;
        *(f32 *)(temp_2_5 + 0xC) = sp3C;
        *(u32 *)(arg0 + 0x64) = *(u32 *)(arg0 + 0x64) + 1;
        return 0;
    }
    temp_2_6 = func_00149ca0();
    *(f32 *)(temp_2_6 + 0) = *(f32 *)(arg0 + 0x20);
    *(f32 *)(temp_2_6 + 4) = *(f32 *)(arg0 + 0x24);
    *(f32 *)(temp_2_6 + 8) = *(f32 *)(arg0 + 0x28);
    *(f32 *)(temp_2_6 + 0xC) = *(f32 *)(arg0 + 0x2C);
    temp_2_7 = func_00149ce0();
    *(f32 *)(temp_2_7 + 0) = *(f32 *)(arg0 + 0x30);
    *(f32 *)(temp_2_7 + 4) = *(f32 *)(arg0 + 0x34);
    *(f32 *)(temp_2_7 + 8) = *(f32 *)(arg0 + 0x38);
    *(f32 *)(temp_2_7 + 0xC) = *(f32 *)(arg0 + 0x3C);
    return 1;
}
