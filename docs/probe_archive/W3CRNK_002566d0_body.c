/* object 1264B, window 1296B, normalized_diff 735 (verify); abandoned alpha/register probe */
void func_002566d0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4) {
    Sp120 sp120;
    u8 spD0[0x48];
    u8 spB0[0x20];
    u8 sp70[0x40];
    u8 *src;
    u8 *dst;
    s32 count;
    s32 temp_3;
    f32 temp_f22;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 var_f0;
    s32 temp_2;
    u32 alpha_u;
    s32 call_x;
    s32 call_y;
    s16 call_w;
    s16 call_h;
    s32 call_alpha;
    void (*vt)(u32, u32);
    temp_f22 = fparg4;
    src = D_00636410;
    dst = spD0;
    count = 9;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    src = D_00636460;
    dst = spB0;
    count = 4;
    do {
        temp_3 = *(s32 *)src;
        temp_2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)dst = temp_3;
        *(s32 *)(dst + 4) = temp_2;
        dst += 8;
    } while (count > 0);
    temp_f21 = (f32)arg1 / 255.0f;
    temp_f20 = 0.25f * temp_f22;
    func_00252230(&sp120, (Sp120 *)spD0,
                  (Sp120 *)((u8 *)spD0 + 0x24), fparg3);
    func_003e0870(sp70, (u8 *)&sp120 + 0xC, sp120.f1C, 0);
    call_h = sp120.f22;
    call_w = sp120.f20;
    call_alpha = sp120.f18;
    call_x = (s32)sp120.f4;
    call_y = (s32)sp120.f8;
    alpha_u = call_alpha;
    temp_2 = alpha_u & 0xFF;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = (f32)(s32)(((u32)temp_2 >> 1) | ((u32)temp_2 & 1));
        var_f0 += var_f0;
    }
    func_00366c70(call_x, call_y,
                  call_w, call_h, call_alpha >> 8,
                  (s32)(var_f0 * temp_f21), 3,
                  (s16)(call_w >> 1), 0.0f,
                  (s16)(call_h >> 1), sp70, arg2, spB0);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70((s32)sp120.f4, (s32)sp120.f8,
                  sp120.f20, sp120.f22, sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f21), 5,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg3, spB0);
    vt = D_00887300[0];
    vt(6, 0);
    vt(8, 1);
    func_003f6440(3, 0x31003);
    func_003f6440(2, 0x48);
    temp_f21_2 = 1.0f + temp_f20;
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70(
                  (s32)((f32)sp120.f4 - (f32)sp120.f20 * temp_f20),
                  (s32)((f32)sp120.f8 - (f32)sp120.f22 * temp_f20),
                  (s32)((f32)sp120.f20 * temp_f21_2),
                  (s32)((f32)sp120.f22 * temp_f21_2), sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f22), 2,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg2, spB0);
    temp_2 = *(u8 *)&sp120.f18;
    alpha_u = temp_2;
    if (temp_2 >= 0) {
        var_f0 = (f32)temp_2;
    } else {
        var_f0 = 2.0f * (f32)(s32)((alpha_u >> 1) | (alpha_u & 1));
    }
    func_00366c70(
                  (s32)((f32)sp120.f4 - (f32)sp120.f20 * temp_f20),
                  (s32)((f32)sp120.f8 - (f32)sp120.f22 * temp_f20),
                  (s32)((f32)sp120.f20 * temp_f21_2),
                  (s32)((f32)sp120.f22 * temp_f21_2), sp120.f18 >> 8,
                  (s32)(var_f0 * temp_f22), 4,
                  (s16)(sp120.f20 >> 1), 0.0f,
                  (s16)(sp120.f22 >> 1), sp70, arg3, spB0);
}
