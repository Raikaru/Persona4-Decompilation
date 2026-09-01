/* object 500B; retail window 560B; normalized_diff 384; first differing offsets 0x00, 0x04, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19; casts tested: (f32)(u32)arg1 for the incoming unsigned integer-to-float site, (u8)temp_f0 for the float-to-unsigned byte site, and (f32)var_3 for the resulting unsigned-byte-to-float site. The previous hand-written sign-fixup and bias paths were removed. */
void func_0034c270(s64 arg0, u32 arg1, s32 arg2, f32 fparg0) {
    u8 sp50[0x16A0];
    s64 sp48;
    s32 sp16D0;
    s16 sp16D4;
    f32 baseHi;
    f32 baseLo;
    f32 temp_f0;
    f32 var_f0;
    f32 alpha;
    s32 i;
    u8 var_3;
    u8 *dst;
    u8 *src;

    sp48 = arg0;
    D_0088467C[0] = fparg0;
    func_0043f9c8(sp50, 0, 0x16A0);
    if (arg2 <= 0 || arg2 >= 0x24) {
        func_0046d730(&iGpffffa950, 0x2B8);
    }
    sp16D0 = arg2;
    sp16D4 = (s16)(s32)*(f32 *)(D_007523C4 + arg2 * 0x10);
    baseHi = *(f32 *)((u8 *)&sp48 + 4);
    baseLo = *(f32 *)&sp48;
    for (i = 0; i < 0x14; i++) {
        dst = sp50 + i * 0x54;
        src = D_00749CC0 + arg2 * 0x3C0 + i * 0x30;
        *(f32 *)(dst + 8) = baseLo + *(f32 *)(src + 8);
        *(f32 *)(dst + 0xC) = baseHi + *(f32 *)(src + 0xC);
        *(f32 *)(dst + 0x34) = *(f32 *)(src + 0x18);
        *(s16 *)(dst + 0x48) = *(s16 *)(src + 0x1C);
        alpha = (f32)(u32)arg1;
        temp_f0 = (alpha * *(f32 *)(src + 0x24)) / 255.0f;
        var_3 = (u8)temp_f0;
        var_f0 = (f32)var_3;
        *(f32 *)(dst + 0x24) = var_f0;
    }
    func_0034c500(sp50, sp48, arg1);
    D_0088467C[0] = 0.0f;
}
