/* Closest clean-C probe for func_0024c0e0; object 884B/window 896B,
   normalized_diff 220. Explicit boolean conversion and arithmetic source
   ordering match the retail prologue and FMA sequence, but MWCC still
   differs in call-address scheduling, branch layout, and float-to-byte
   conversion coloring. Reverted to INCLUDE_ASM after five scoped probes. */
// FUN_0024C0E0
s32 func_0024c0e0(u8 *arg0, u8 *arg1)
{
    f32 temp_f1;
    f32 var_f0;
    s32 temp_16;
    s32 temp_2;
    s32 temp_16_2;
    s32 temp_3;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 var_5;

    temp_2 = func_00452380(D_00635A78);
    temp_16 = func_00452380(D_00635A78);
    if (temp_16 == 0) {
        func_0046d730(D_006359F0, 0x392);
    }
    temp_2_2 = (*(s32 *)func_00452560(temp_16) & 1) != 0;
    if (temp_2_2 != 0) {
        goto block_1;
    }
    func_0046d730(D_006359F0, 0x39D);
block_1:
    temp_16_2 = *(s32 *)((u8 *)func_00452560(temp_2) + 0x24);
    temp_3 = *(s32 *)arg1;
    if (temp_3 & 2) {
        temp_2_2 = *(s32 *)(arg1 + 8);
        if (temp_2_2 < 10) {
            temp_f1 = (f32)temp_2_2;
            temp_f1 = (iGpffff8094 * temp_f1) / 10.0f;
            var_f0 = func_0044b7b0(temp_f1);
        } else {
            var_f0 = 1.0f;
        }
        func_0025ecd0(0xFFFFFF, 0xFF, 0, temp_16_2, 1, 0, 0,
                      D_00794E70, 512.0f,
                      418.0f + 200.0f * (1.0f - var_f0),
                      0.0f, -30.0f, 1.0f, 1.0f);
        temp_2_3 = *(s32 *)(arg1 + 8) + 1;
        *(s32 *)(arg1 + 8) = temp_2_3;
        if (temp_2_3 >= 10) {
            *(s32 *)arg1 &= ~2;
            *(s32 *)(arg1 + 8) = 0;
        }
        goto block_20;
    }
    if (temp_3 & 4) {
        temp_2_4 = *(s32 *)(arg1 + 8);
        if (temp_2_4 < 10) {
            temp_f1 = (f32)temp_2_4;
            temp_f1 = (iGpffff8094 * temp_f1) / 10.0f;
            var_f0 = func_0044b7b0(temp_f1);
        } else {
            var_f0 = 1.0f;
        }
        temp_f1 = (1.0f - var_f0) * 255.0f;
        if (!(2147483600.0f <= temp_f1)) {
            var_5 = (s32)temp_f1;
        } else {
            var_5 = (s32)(temp_f1 - 2147483600.0f) | 0x80000000;
        }
        func_0025ecd0(0xFFFFFF, var_5 & 0xFF, 0, temp_16_2, 1, 0, 0,
                      D_00794E70, 512.0f, 418.0f, 0.0f, -30.0f,
                      1.0f, 1.0f);
        temp_2_5 = *(s32 *)(arg1 + 8) + 1;
        *(s32 *)(arg1 + 8) = temp_2_5;
        if (temp_2_5 >= 10) {
            *(s32 *)arg1 &= ~4;
            *(s32 *)(arg1 + 8) = 0;
            return 1;
        }
    } else {
        func_0025ecd0(0xFFFFFF, 0xFF, 0, temp_16_2, 1, 0, 0,
                      D_00794E70, 512.0f, 418.0f, 0.0f, -30.0f,
                      1.0f, 1.0f);
    }
block_20:
    return 0;
}
