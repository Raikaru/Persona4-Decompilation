/*
 * Probe archive: func_00378280 @ 0x00378280
 * Candidate object/window: 632B / 640B
 * normalized_diff: 105 differing words (reloc-masked)
 * COP1 chain: reproduced exactly (adda.s, msuba.s, msub.s; 3/3 chain ops)
 * Key differing offsets: 0-8 pointer register; 48-160 induction/half/rem register
 * colouring; 176-204 address/result registers; 196-244 byte conversion registers;
 * 260-316 clamp comparison/control/result registers; repeated lanes 324-628;
 * candidate ended 8B before retail tail (retail had two additional nops).
 * Ruled out: direct vs decomposed signed half/rem spelling; u8/u32/s32 result
 * locals; u8 vs u32 byte temporaries; pointer, pointer-to-pointer, and direct
 * pointer loads; declaration reordering; register qualifier; opt_propagation off.
 * Kept probe: opt_loop_invariants on (hoisted constants/GP float loads).
 * Residual was ordinary register colouring/control spelling, not a COP1 floor.
 */
void func_00378280(u8 *arg0, u8 arg1) {
    u8 *temp_4;
    u8 *temp_11;
    u8 *temp_10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 global_a;
    f32 global_b;
    s32 var_5;
    s32 temp_8;
    u32 var_6;
    u32 var_6_2;
    u32 var_6_3;
    u32 temp_6;
    u32 temp_6_2;
    u32 temp_6_3;

    temp_4 = *(u8 **)(arg0 + 0x38);
    temp_4[0x11F] = arg1;
    if (*(s32 *)(temp_4 + 4) != 0) {
        global_a = DAT_007613f8;
        global_b = iGpffff8218;
    } else {
        global_a = 0.0f;
        global_b = 0.0f;
    }
    for (var_5 = 0; var_5 < 4; var_5++) {
        temp_8 = 3 - var_5;
        temp_f4 = (1.0f + 0.0f) - global_a * (f32)(temp_8 % 2) -
            global_b * (f32)(temp_8 / 2);

        temp_11 = temp_4 + var_5 * 0x24;
        temp_10 = temp_11 + 0x12C;

        temp_6 = temp_4[0x11C];
        if (temp_6 >= 0) {
            var_f0 = (f32)temp_6;
        } else {
            temp_6 = (temp_6 >> 1) | (temp_6 & 1);
            var_f0 = (f32)temp_6;
            var_f0 += var_f0;
        }
        temp_f0 = var_f0 * temp_f4;
        if (!(temp_f0 >= 2147483648.0f)) {
            var_6 = (s32)temp_f0 & 0xFF;
        } else {
            var_6 = ((s32)(temp_f0 - 2147483648.0f) |
                0x80000000) & 0xFF;
        }
        temp_10[0] = (u8)var_6;

        temp_6_2 = temp_4[0x11D];
        if (temp_6_2 >= 0) {
            var_f0_2 = (f32)temp_6_2;
        } else {
            temp_6_2 = (temp_6_2 >> 1) | (temp_6_2 & 1);
            var_f0_2 = (f32)temp_6_2;
            var_f0_2 += var_f0_2;
        }
        temp_f0_2 = var_f0_2 * temp_f4;
        if (!(temp_f0_2 >= 2147483648.0f)) {
            var_6_2 = (s32)temp_f0_2 & 0xFF;
        } else {
            var_6_2 = ((s32)(temp_f0_2 - 2147483648.0f) |
                0x80000000) & 0xFF;
        }
        temp_10[1] = (u8)var_6_2;

        temp_6_3 = temp_4[0x11E];
        if (temp_6_3 >= 0) {
            var_f0_3 = (f32)temp_6_3;
        } else {
            temp_6_3 = (temp_6_3 >> 1) | (temp_6_3 & 1);
            var_f0_3 = (f32)temp_6_3;
            var_f0_3 += var_f0_3;
        }
        temp_f0_3 = var_f0_3 * temp_f4;
        if (!(temp_f0_3 >= 2147483648.0f)) {
            var_6_3 = (s32)temp_f0_3 & 0xFF;
        } else {
            var_6_3 = ((s32)(temp_f0_3 - 2147483648.0f) |
                0x80000000) & 0xFF;
        }
        temp_10[2] = (u8)var_6_3;

        temp_10[3] = temp_4[0x11F];
        temp_11[0x1BC] = 0xFF;
        temp_11[0x1BD] = 0xFF;
        temp_11[0x1BE] = 0xFF;
        temp_11[0x1BF] = temp_4[0x11F];
    }
}
