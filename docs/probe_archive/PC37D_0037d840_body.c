// object_size=540 window=544 normalized_diff=2; best plain-C body before ASM fallback.
void func_0037d840(u8 *arg0) {
    u8 buf[0xFB0];
    u8 *var_8;
    u8 *var_7;
    u8 *var_6;
    s32 var_5;
    s32 n;
    s32 var_18;
    s32 var_16;
    s32 temp_3;
    s32 t1;
    s32 t2;
    f32 var_f1;
    f32 temp_f0;

    if (*(s32 *)(arg0 + 0x1F2FC) != 3) {
        func_0046d730(&D_0064EB20[0], 0x23B);
    }
    n = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    var_18 = n - 1;
    while (var_18 > 0) {
        temp_3 = func_003b7060() & 0xFFF;
        var_f1 = (f32)(u32)temp_3;
        temp_f0 = var_f1 / 4096.0f;
        temp_f0 = (f32)(var_18 + 1) * temp_f0;
        var_16 = (s32)temp_f0;
        if ((var_18 < 0) || (var_18 >= n)) {
            func_0046d730(&D_0064EB20[0], 0x243);
        }
        if ((var_16 < 0) || (var_16 >= n)) {
            func_0046d730(&D_0064EB20[0], 0x244);
        }
        var_8 = arg0 + var_18 * 0xFB0;
        var_6 = buf;
        var_5 = 0x1F6;
        var_7 = var_8;
        do {
            t1 = *(s32 *)(var_7 + 0);
            t2 = *(s32 *)(var_7 + 4);
            var_7 += 8;
            var_5 -= 1;
            *(s32 *)(var_6 + 0) = t1;
            *(s32 *)(var_6 + 4) = t2;
            var_6 += 8;
        } while (var_5 > 0);
        var_7 = arg0 + var_16 * 0xFB0;
        var_5 = 0x1F6;
        var_6 = var_7;
        do {
            t1 = *(s32 *)(var_6 + 0);
            t2 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_5 -= 1;
            *(s32 *)(var_8 + 0) = t1;
            *(s32 *)(var_8 + 4) = t2;
            var_8 += 8;
        } while (var_5 > 0);
        var_6 = buf;
        var_5 = 0x1F6;
        do {
            t1 = *(s32 *)(var_6 + 0);
            t2 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_5 -= 1;
            *(s32 *)(var_7 + 0) = t1;
            *(s32 *)(var_7 + 4) = t2;
            var_7 += 8;
        } while (var_5 > 0);
        var_18 -= 1;
    }
}
