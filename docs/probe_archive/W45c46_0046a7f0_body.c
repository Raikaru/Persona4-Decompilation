/* func_0046a7f0 probe archive: object 836B / window 848B / nd 102; levers: generated M2C, nested angle normalization, integer matrix handle, direct middle copy, u32 stack arrays, direct Horner/FMA expressions. */
// FUN_0046A7F0
void func_0046a7f0(u8 *arg0, f32 *arg1) {
    u32 input[12];
    u32 output[12];
    f32 var_f3;
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_2;
    s32 var_4;
    s32 var_5;
    s32 var_5_2;
    s32 var_8;
    f32 *pfVar3;
    f32 *pInput;
    f32 *pOutput;

    for (var_5 = 0; var_5 < 4; var_5++) {
        pfVar3 = (f32 *)((u8 *)arg1 + var_5 * 8);
        pInput = ((f32 *)input) + var_5 * 3;
        pInput[0] = pfVar3[0];
        pInput[1] = pfVar3[1];
    }
    var_f3 = *(f32 *)(arg0 + 0x18);
    if (var_f3 != 0.0f) {
        do {
            var_4 = 0;
            if (var_f3 <= 180.0f) {
                if (var_f3 < -180.0f) {
                    var_f3 += 360.0f;
                    var_4 = 1;
                }
            } else {
                var_f3 -= 360.0f;
                var_4 = 1;
            }
        } while (var_4 != 0);
        temp_f21 = (fGpffff8084 * var_f3) / 180.0f;
        temp_f20 = temp_f21 * temp_f21;
        temp_2 = (s32)func_003e0f80();
        temp_2 = (s32)func_003e0680(
            (f32 *)(u32)temp_2,
            (f32 *)D_007130B8,
            0,
            1.0f -
                (1.0f -
                 (temp_f20 * 0.5f -
                  temp_f20 * temp_f20 *
                  (temp_f20 *
                   (temp_f20 *
                    (temp_f20 *
                     (temp_f20 *
                      (fGpffff81b0 * temp_f20 + fGpffff81b4 + 0.0f) +
                      fGpffff81b8 + 0.0f) +
                     fGpffff81bc + 0.0f) +
                    fGpffff81c0 + 0.0f) +
                   fGpffff81c4 + 0.0f))),
            temp_f20 * temp_f21 *
                (temp_f20 *
                 (temp_f20 *
                  (temp_f20 *
                   (temp_f20 *
                    (fGpffff81c8 * temp_f20 + fGpffff8054 + 0.0f) +
                    fGpffff8058 + 0.0f) +
                   fGpffff805c + 0.0f) +
                  fGpffff8060 + 0.0f) +
                 fGpffff81cc + 0.0f) +
                temp_f21 + 0.0f);
        func_003e42e0((f32 *)output, (f32 *)input, 4, (void *)(u32)temp_2);
        func_003e0f40((void *)(u32)temp_2);
        for (var_5_2 = 0; var_5_2 < 4; var_5_2++) {
            pOutput = ((f32 *)output) + var_5_2 * 3;
            pInput = ((f32 *)input) + var_5_2 * 3;
            pInput[0] = pOutput[0];
            pInput[1] = pOutput[1];
            pInput[2] = pOutput[2];
        }
    }
    for (var_8 = 0; var_8 < 4; var_8++) {
        pfVar3 = (f32 *)((u8 *)arg1 + var_8 * 8);
        pInput = ((f32 *)input) + var_8 * 3;
        pfVar3[0] =
            (f32)(*(f32 *)(arg0 + 0x8) +
                  ((f32)(s32)*(s16 *)(arg0 + 0x1C) + pInput[0])) +
            (f32)*(s32 *)(*(u8 **)arg0 + 0x204 +
                          (*(s32 *)(arg0 + 4) << 7) + 0x44);
        pfVar3[1] =
            (f32)(*(f32 *)(arg0 + 0xC) +
                  ((f32)(s32)*(s16 *)(arg0 + 0x1E) + pInput[1])) +
            (f32)*(s32 *)(*(u8 **)arg0 + 0x204 +
                          (*(s32 *)(arg0 + 4) << 7) + 0x48);
    }
}
