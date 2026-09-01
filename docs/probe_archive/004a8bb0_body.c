#pragma optimization_level 1
void func_004a8bb0(u8 *a, u8 *b) {
    int *param_1 = (int *)a;
    float *param_2 = (float *)b;
    int iVar4;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } uVar2;
    int iVar1;
    float fVar6;
    float alphaF;
    float temp_f1;
    u32 alpha;
    s32 var_4;

    iVar1 = *param_1;
    if (!(iVar1 <= 0x64)) {
        func_0046d730(D_00714380, 0x190);
    }
    uVar2.packed = (u32)param_1[3];
    alpha = (u32)uVar2.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        if (((int *)param_2)[0] == 0) {
            float threshold;
            if (!(param_2[1] <= fGpffff8084)) {
                func_004a8a50(a, (u8 *)param_2);
            }
            fVar6 = func_0044b7b0(param_2[1]);
            param_2[6] = 1.0f + ((float *)param_1)[6] * fVar6;
            temp_f1 = alphaF * func_0044e7d8(func_0044e168(fGpffff8018, func_0044e100(fGpffff8020, func_0044b310(func_0044dcd8(param_2[1])))));
            threshold = 2.1474836e9f;
            if (threshold <= temp_f1) {
                goto alpha_big;
            }
            var_4 = (s32)temp_f1;
            var_4 &= 0xFF;
            goto alpha_done;
        alpha_big:
            var_4 = (s32)(temp_f1 - threshold);
            var_4 |= 0x80000000;
            var_4 &= 0xFF;
        alpha_done:
            *((u8 *)param_2 + 0xF) = (u8)var_4;
            param_2[1] = param_2[1] + ((float *)param_1)[2];
        } else {
            *((u8 *)param_2 + 0xF) = 0;
            ((int *)param_2)[0] = ((int *)param_2)[0] - 1;
        }
        param_2 = param_2 + 0x34 / 4;
    }
}
#pragma optimization_level 2
