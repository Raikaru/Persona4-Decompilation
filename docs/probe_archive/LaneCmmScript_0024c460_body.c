/* Closest clean-C probe for func_0024c460; object 3420B/window 3472B,
   normalized_diff 2423. The complete draw/update control flow compiles but
   does not match the retail scheduling/FPU accumulator sequence. Reverted
   to INCLUDE_ASM after the scoped probe; adjacent FUN_0024D1F0 note records
   the shared FPU/FMA compiler floor. */

s32 func_0024c460(u8 *arg0, u8 *arg1)
{
    f32 var_f20;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_16;
    s32 temp_2;
    s32 temp_16_2;
    s32 temp_3;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_18;
    s32 alpha;
    s16 frame16;
    s16 spark;

    temp_16 = func_00452380(D_00635A78);
    temp_2 = func_00452380(D_00635A78);
    if (temp_2 == 0) {
        func_0046d730(D_006359F0, 0x392);
    }
    temp_2_2 = (*(s32 *)func_00452560(temp_2) & 1) != 0;
    if (temp_2_2 == 0) {
        func_0046d730(D_006359F0, 0x39D);
    }
    temp_16_2 = *(s32 *)((u8 *)func_00452560(temp_16) + 0x24);
    temp_3 = *(s32 *)arg1;
    if (temp_3 & 2) {
        temp_2_2 = *(s32 *)(arg1 + 8);
        if (temp_2_2 < 5) {
            temp_f2 = (f32)temp_2_2;
            temp_f2 = (iGpffff8094 * temp_f2) / 5.0f;
            var_f20 = func_0044b7b0(temp_f2);
        } else {
            var_f20 = 1.0f;
        }
        alpha = (s32)(255.0f * var_f20);
        temp_f21 = (f32)(1.0f + ((0.5f * (f32)*(s32 *)(arg1 + 8)) / 5.0f));
        func_0025ecd0(0xFFFFFF, alpha & 0xFF, 1, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1B1, 163.0f, 0.0f, 0.0f,
                      1.0f, 1.0f);
        func_0025ecd0(0xFFFFFF, alpha & 0xFF, 2, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1B1,
                      139.0f - 5.0f * var_f20, 0.0f, 0.0f,
                      1.0f, 1.0f);
        temp_f20 = 177.0f - 24.0f * temp_f21;
        func_0025ecd0(0xF27400, alpha & 0xFF, 0xC, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)443 - 60.0f * temp_f21,
                      temp_f20, 0.0f, 0.0f, temp_f21, temp_f21);
        func_0025ecd0(0xF27400, alpha & 0xFF, 0xD, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1C5, temp_f20, 0.0f, 0.0f,
                      temp_f21, temp_f21);
        temp_f20 = 177.0f - 28.0f * temp_f21;
        func_0025ecd0(0xECF54D, alpha & 0xFF, 0xA, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)443 - 51.0f * temp_f21,
                      temp_f20, 0.0f, 0.0f, temp_f21, temp_f21);
        func_0025ecd0(0xECF54D, alpha & 0xFF, 0xB, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1C5, temp_f20, 0.0f, 0.0f,
                      temp_f21, temp_f21);
        temp_2_3 = *(s32 *)(arg1 + 8) + 1;
        *(s32 *)(arg1 + 8) = temp_2_3;
        if (temp_2_3 >= 5) {
            *(s32 *)arg1 &= ~2;
            *(s32 *)(arg1 + 8) = 0;
        }
        goto block_33;
    }
    if (temp_3 & 4) {
        temp_2_4 = *(s32 *)(arg1 + 8);
        if (temp_2_4 < 5) {
            temp_f2 = (f32)temp_2_4;
            temp_f2 = (iGpffff8094 * temp_f2) / 5.0f;
            var_f20 = func_0044b7b0(temp_f2);
        } else {
            var_f20 = 1.0f;
        }
        alpha = (s32)(255.0f * (1.0f - var_f20));
        temp_f21 = (f32)(1.0f + ((0.5f * (f32)*(s32 *)(arg1 + 8)) / 5.0f));
        func_0025ecd0(0xFFFFFF, alpha & 0xFF, 1, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1B1, 163.0f, 0.0f, 0.0f,
                      1.0f, 1.0f);
        func_0025ecd0(0xFFFFFF, alpha & 0xFF, 2, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1B1,
                      139.0f - 5.0f * var_f20, 0.0f, 0.0f,
                      1.0f, 1.0f);
        temp_f20 = 177.0f - 24.0f * temp_f21;
        func_0025ecd0(0xF27400, alpha & 0xFF, 0xC, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)443 - 60.0f * temp_f21,
                      temp_f20, 0.0f, 0.0f, temp_f21, temp_f21);
        func_0025ecd0(0xF27400, alpha & 0xFF, 0xD, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1C5, temp_f20, 0.0f, 0.0f,
                      temp_f21, temp_f21);
        temp_f20 = 177.0f - 28.0f * temp_f21;
        func_0025ecd0(0xECF54D, alpha & 0xFF, 0xA, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)443 - 51.0f * temp_f21,
                      temp_f20, 0.0f, 0.0f, temp_f21, temp_f21);
        func_0025ecd0(0xECF54D, alpha & 0xFF, 0xB, temp_16_2, 1, 0, 0,
                      D_00794E70, (f32)0x1C5, temp_f20, 0.0f, 0.0f,
                      temp_f21, temp_f21);
        temp_2_5 = *(s32 *)(arg1 + 8) + 1;
        *(s32 *)(arg1 + 8) = temp_2_5;
        if (temp_2_5 >= 5) {
            *(s32 *)arg1 &= ~4;
            *(s32 *)(arg1 + 8) = 0;
            return 1;
        }
        goto block_33;
    }

    temp_2_6 = *(s32 *)(arg1 + 8);
    if (temp_2_6 < 5) {
        temp_f2 = (f32)temp_2_6;
        temp_f2 = (iGpffff8094 * temp_f2) / 5.0f;
        func_0044b7b0(temp_f2);
    }
    temp_f21 = (f32)(1.0f + ((0.5f * (f32)*(s32 *)(arg1 + 8)) / 5.0f));
    func_0025ecd0(0xFFFFFF, 0xFF, 1, temp_16_2, 1, 0, 0,
                  D_00794E70, (f32)0x1B1, 163.0f, 0.0f, 0.0f,
                  1.0f, 1.0f);
    func_0025ecd0(0xFFFFFF, 0xFF, 2, temp_16_2, 1, 0, 0,
                  D_00794E70, (f32)0x1B1,
                  139.0f - 5.0f * temp_f21, 0.0f, 0.0f,
                  1.0f, 1.0f);
    temp_f20 = 177.0f - 24.0f * temp_f21;
    func_0025ecd0(0xF27400, 0xFF, 0xC, temp_16_2, 1, 0, 0,
                  D_00794E70, (f32)443 - 60.0f * temp_f21,
                  temp_f20, 0.0f, 0.0f, temp_f21, temp_f21);
    func_0025ecd0(0xF27400, 0xFF, 0xD, temp_16_2, 1, 0, 0,
                  D_00794E70, (f32)0x1C5, temp_f20, 0.0f, 0.0f,
                  temp_f21, temp_f21);
    temp_f20 = 177.0f - 28.0f * temp_f21;
    func_0025ecd0(0xECF54D, 0xFF, 0xA, temp_16_2, 1, 0, 0,
                  D_00794E70, (f32)443 - 51.0f * temp_f21,
                  temp_f20, 0.0f, 0.0f, temp_f21, temp_f21);
    func_0025ecd0(0xECF54D, 0xFF, 0xB, temp_16_2, 1, 0, 0,
                  D_00794E70, (f32)0x1C5, temp_f20, 0.0f, 0.0f,
                  temp_f21, temp_f21);
    temp_2_7 = *(s32 *)(arg1 + 8) + 1;
    *(s32 *)(arg1 + 8) = temp_2_7;
    if (temp_2_7 >= 5) {
        *(s32 *)(arg1 + 8) = 0;
    }
    if (*(s32 *)(arg1 + 0x10) > 0) {
        frame16 = *(s16 *)(arg1 + 0xC);
        if (frame16 < 5) {
            temp_f2 = (f32)frame16;
            temp_f2 = (iGpffff8094 * temp_f2) / 5.0f;
            alpha = (s32)(255.0f * func_0044b7b0(temp_f2));
        } else if (frame16 < 20) {
            alpha = 255;
        } else if (frame16 < 30) {
            temp_f2 = (f32)(frame16 - 20);
            temp_f2 = iGpffff8094 + (iGpffff8094 * temp_f2) / 10.0f;
            alpha = (s32)(255.0f * func_0044b7b0(temp_f2));
        }
        func_0025ecd0(0xFFFFFF, alpha & 0xFF,
                      *(s32 *)(arg1 + 0x10) + 13, temp_16_2, 1, 0, 0,
                      D_00794E70, 416.0f, 148.0f, 0.0f, 0.0f,
                      1.0f, 1.0f);
        if (*(s32 *)arg1 & 0x10) {
            spark = *(s16 *)(arg1 + 0xE);
            temp_f20 = (f32)(1.0f + (iGpffff809c * (f32)spark) / 10.0f);
            temp_18 = *(s32 *)(arg1 + 0x10) + 16;
            temp_f3 = (f32)spark;
            temp_f2 = iGpffff8094 + (iGpffff8094 * temp_f3) / 10.0f;
            alpha = (s32)(127.5f * func_0044b7b0(temp_f2));
            func_0025ecd0(0xFFFFFF, alpha & 0xFF, temp_18, temp_16_2,
                          1, 0, 0, D_00794E70,
                          448.0f - 32.0f * temp_f20,
                          177.0f - 29.0f * temp_f20, 0.0f, 0.0f,
                          temp_f20, temp_f20);
            spark = (s16)(spark + 1);
            *(s16 *)(arg1 + 0xE) = spark;
            if (spark >= 10) {
                *(s16 *)(arg1 + 0xE) = 0;
                *(s32 *)arg1 &= ~0x10;
            }
        }
        frame16 = (s16)(frame16 + 1);
        *(s16 *)(arg1 + 0xC) = frame16;
        if (frame16 >= 30) {
            *(s16 *)(arg1 + 0xC) = 0;
            *(s32 *)(arg1 + 0x10) = 0;
            *(s32 *)arg1 &= ~0x10;
        }
    }
block_33:
    return 0;
}
