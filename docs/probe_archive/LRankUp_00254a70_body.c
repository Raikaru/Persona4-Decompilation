s32 func_00254a70(arg0, arg1, arg2)
s32 arg0;
u8 *arg1;
u8 *arg2;
{
    RankUp54Locals sp;
    s32 var_16;
    s32 temp_17;
    s32 i;
    s32 color;
    s32 temp_s0;
    s32 font;
    s32 asset;
    s32 count;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f14;
    f32 temp_f20;
    f32 temp_f21;
    void (**vtable)(u32, u32);
    u8 *src;
    u8 *dst;
    u8 *p;
    s32 n;

    var_16 = 0;
    if (*(s32 *)(arg2 + 8) == 0xA) {
        var_16 = 1;
    }
    temp_17 = *(s32 *)(arg1 + 4) - 0x3C;
    if (temp_17 < 0x13) {
        src = D_006362D0;
        dst = sp.sp120;
        n = 8;
        do {
            *(s32 *)dst = *(s32 *)src;
            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
            src += 8;
            dst += 8;
            n--;
        } while (n > 0);

        p = (u8 *)&sp.sp168;
        n = 4;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        sp.sp16C = sp.sp168;

        p = sp.sp100;
        n = 0x10;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        ((s32 *)sp.sp100)[0] = 0x15E;
        ((s32 *)sp.sp100)[1] = 0x17C;
        ((s32 *)sp.sp100)[2] = 0x122;
        ((s32 *)sp.sp100)[3] = 0x64;
        sp.sp110 = *(u_long128 *)sp.sp100;

        vtable = D_00887300;
        vtable[0](0xE, 0);
        vtable[0](0xC, 1);
        vtable[0](7, 2);
        vtable[0](9, 1);
        vtable[0](0x14, 1);
        vtable[0](6, 0);
        vtable[0](8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp.sp16C, &sp.sp110, 0, 5.0f);
        func_0048a000();

        i = 0;
        while (i < 8) {
            if (temp_17 < i) {
                func_0025f3f0(0xFFFFFF, 0xFF, i + 0xD, 0,
                              *(void **)(arg2 + 0x10), 1,
                              ((f32 *)sp.sp120)[i * 2],
                              ((f32 *)sp.sp120)[i * 2 + 1], 10.0f);
            } else if (temp_17 - i < 9) {
                temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - i)) / 8.0f);
                temp_f1 = ((f32 *)sp.sp120)[i * 2 + 1];
                temp_f13 = temp_f1 + 50.0f * temp_f0;
                func_0025f3f0(0xFFFFFF, 0xFF, i + 0xD, 0,
                              *(void **)(arg2 + 0x10), 1,
                              ((f32 *)sp.sp120)[i * 2], temp_f13, 10.0f);
            }
            i++;
        }

        p = (u8 *)&sp.sp160;
        n = 4;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        sp.sp164 = sp.sp160;

        p = sp.spE0;
        n = 0x10;
        if (p != NULL) {
            do {
                *p++ = 0;
                n--;
            } while (n != 0);
        }
        ((s32 *)sp.spE0)[0] = 0x15E;
        ((s32 *)sp.spE0)[1] = 0x17C;
        ((s32 *)sp.spE0)[2] = 0x122;
        ((s32 *)sp.spE0)[3] = 0x64;
        *(u_long128 *)sp.spF0 = *(u_long128 *)sp.spE0;

        vtable = D_00887300;
        vtable[0](0xE, 0);
        vtable[0](0xC, 1);
        vtable[0](7, 2);
        vtable[0](9, 1);
        vtable[0](0x14, 1);
        vtable[0](6, 0);
        vtable[0](8, 1);
        func_003f6440(3, 0x31003);
        func_003f6440(2, 0x44);
        func_00489f80();
        func_0045d6e0(&sp.sp164, &sp.spF0, 0, 0.0f);
        func_0048a000();
    }

    if (temp_17 < 0x19) {
        func_0025f3f0(0xFFFFFF, 0xFF, 0x29, 0,
                      *(void **)(arg2 + 0x10), 1, 0.0f, 375.0f, 0.0f);
    } else if (temp_17 < 0x24) {
        temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 0x19)) / 10.0f);
        temp_f12 = 640.0f * temp_f0;
        func_0025f3f0(0xFFFFFF, 0xFF, 0x29, 0,
                      *(void **)(arg2 + 0x10), 1, temp_f12, 375.0f, 0.0f);
    }
    if (temp_17 < 0x1E) {
        func_0025f3f0(0xFFFFFF, 0xFF, var_16 + 0x2A, 0,
                      *(void **)(arg2 + 0x10), 1, 0.0f, 380.0f, 0.0f);
    } else if (temp_17 < 0x24) {
        temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 0x1E)) / 5.0f);
        temp_f12 = 380.0f;
        temp_f13 = 375.0f + 10.0f * temp_f0;
        temp_f14 = temp_f12;
        func_0025f430(0xFFFFFF, 0xFF, var_16 + 0x2A, 0,
                      *(void **)(arg2 + 0x10), 1, 0, 0,
                      temp_f12, temp_f13, temp_f14, temp_f14, 1.0f,
                      1.0f - temp_f0);
    }

    if (temp_17 < 0x14) {
        if (var_16 == 0) {
            func_0025f3f0(0xFFFFFF, 0xFF, 1, 0,
                          *(void **)(arg2 + 0x10), 1, 188.0f, 375.0f, 0.0f);
        } else {
            func_0025f3f0(0xFFFFFF, 0xFF, 0x1A, 0,
                          *(void **)(arg2 + 0x10), 1, 184.0f, 336.0f, 0.0f);
        }
        if (var_16 == 0) {
            func_0025f3f0(0xFFFFFF, 0xFF, *(s32 *)(arg2 + 8) + 1, 0,
                          *(void **)(arg2 + 0x10), 1, 277.0f, 350.0f, 0.0f);
        }
    } else if (temp_17 < 0x1A) {
        temp_f0 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 0x14)) / 5.0f);
        temp_f20 = (f32)(s32)temp_f0;
        temp_f21 = 1.0f - temp_f0;
        if (var_16 == 0) {
            temp_f14 = 188.0f;
            temp_f13 = 375.0f + 28.0f * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, 1, 0,
                          *(void **)(arg2 + 0x10), 1, 0, 0,
                          temp_f14, temp_f13, temp_f14, temp_f14, 1.0f,
                          temp_f21);
        } else {
            temp_f14 = 184.0f;
            temp_f13 = 368.0f + 28.0f * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, 0x1A, 0,
                          *(void **)(arg2 + 0x10), 1, 0, 0,
                          temp_f14, temp_f13, temp_f14, temp_f14, 1.0f,
                          temp_f21);
        }
        if (var_16 == 0) {
            temp_f14 = 277.0f;
            temp_f13 = 350.0f + 28.0f * temp_f20;
            func_0025f430(0xFFFFFF, 0xFF, *(s32 *)(arg2 + 8) + 1, 0,
                          *(void **)(arg2 + 0x10), 1, 0, 0,
                          temp_f14, temp_f13, temp_f14, temp_f14, 1.0f,
                          temp_f21);
        }
    }

    if (temp_17 < 5) {
        src = D_00635CC0;
        dst = sp.spC0;
        n = 4;
        do {
            *(s32 *)dst = *(s32 *)src;
            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
            src += 8;
            dst += 8;
            n--;
        } while (n > 0);
        i = 0;
        while (i < 4) {
            ((f32 *)sp.spC0)[i * 2] += 218.0f;
            ((f32 *)sp.spC0)[i * 2 + 1] += 406.0f;
            p = sp.spB0 + i * 4;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0x99;
            i++;
        }
        func_0045dfd0(sp.spB0, sp.spC0, 4.0f, 4, 1, 0);
        temp_s0 = *(s32 *)(arg2 + 4);
        asset = *(s32 *)(arg2 + 0x10);
        font = func_0046a770(D_00635CE0);
        if (font == 0) {
            func_0046d730(D_00635CF8, 0x1E4);
        }
        temp_f20 = (f32)(299 - (((s32)func_0046b1f0(
            (void *)font,
            (s32)(((u8 *)func_002467b0(temp_s0 & 0xFFFF))[8]) + 0x20)) >> 1));
        func_0025e9e0(0xFFFFFF, 0xFF,
                      (s32)(((u8 *)func_002467b0(temp_s0 & 0xFFFF))[8]) + 0x20,
                      font, 1, temp_f20, 407.0f, 0.0f);
        func_0025f3f0(0xFFFFFF, 0xFF, 0x16, 0, (void *)asset, 1,
                      355.0f, 411.0f, 0.0f);
        func_00274ed0(-1, 0, 1, (s32)func_00246830(temp_s0 & 0xFFFF),
                      0, 0, 392.0f, 403.0f, 0.0f);

        i = 0;
        while (i < 0xA) {
            if (i >= *(s32 *)(arg2 + 8)) {
                color = 0xDE7201;
            } else {
                color = 0xFFFFFF;
            }
            func_0025f3f0(color, 0xFF, 0x15, 0, (void *)asset, 1,
                          (f32)(i * 0x17 + 0x162), 381.0f, 0.0f);
            i++;
        }
        count = *(s16 *)(arg2 + 0x3E) + 1;
        *(s16 *)(arg2 + 0x3E) = (s16)count;
        if ((s16)count >= 0x2D) {
            *(s16 *)(arg2 + 0x3E) = 0;
        }
        temp_f0 = func_0044b7b0(D_007612CC +
                                (D_007612D0 * (f32)*(s16 *)(arg2 + 0x3E)) / 45.0f);
        temp_f1 = (D_0076118C + D_00761288 * ((temp_f0 + 1.0f) / 2.0f));
        temp_f1 = 255.0f * temp_f1 *
                  (1.0f - (f32)temp_17 / 5.0f);
        if (!(temp_f1 >= 2147483648.0f)) {
            count = (s32)temp_f1 & 0xFF;
        } else {
            count = ((s32)(temp_f1 - 2147483648.0f) | 0x80000000) & 0xFF;
        }
        func_0025f3f0(color, count, 0x1C, 0, (void *)asset, 1,
                      (f32)((*(s32 *)(arg2 + 8) - 1) * 0x17 + 0x15D),
                      376.0f, 0.0f);
    } else if (temp_17 < 0x15) {
        temp_f20 = func_0044b7b0((D_00761184 * (f32)(temp_17 - 5)) / 15.0f);
        src = D_00635CC0;
        dst = sp.sp90;
        n = 4;
        do {
            *(s32 *)dst = *(s32 *)src;
            *(s32 *)(dst + 4) = *(s32 *)(src + 4);
            src += 8;
            dst += 8;
            n--;
        } while (n > 0);
        i = 0;
        while (i < 4) {
            ((f32 *)sp.sp90)[i * 2] += 218.0f + 500.0f * temp_f20;
            ((f32 *)sp.sp90)[i * 2 + 1] += 406.0f;
            p = sp.sp80 + i * 4;
            p[0] = 0;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0x99;
            i++;
        }
        func_0045dfd0(sp.sp80, sp.sp90, 4.0f, 4, 1, 0);
        temp_s0 = *(s32 *)(arg2 + 4);
        asset = *(s32 *)(arg2 + 0x10);
        font = func_0046a770(D_00635CE0);
        if (font == 0) {
            func_0046d730(D_00635CF8, 0x1E4);
        }
        temp_f0 = func_0046b1f0(
            (void *)font,
            (s32)(((u8 *)func_002467b0(temp_s0 & 0xFFFF))[8]) + 0x20);
        temp_s0 = (s32)(500.0f * temp_f20);
        temp_f21 = (f32)(temp_s0 + 299 - ((s32)temp_f0 >> 1));
        func_0025e9e0(0xFFFFFF, 0xFF,
                      (s32)(((u8 *)func_002467b0((*(s32 *)(arg2 + 4)) & 0xFFFF))[8]) + 0x20,
                      font, 1, temp_f21, 407.0f, 0.0f);
        func_0025f3f0(0xFFFFFF, 0xFF, 0x16, 0, (void *)asset, 1,
                      (f32)(temp_s0 + 355), 411.0f, 0.0f);
        func_00274ed0(-1, 0, 1,
                      (s32)func_00246830((*(s32 *)(arg2 + 4)) & 0xFFFF),
                      0, 0, (f32)(temp_s0 + 392), 403.0f, 0.0f);

        i = 0;
        while (i < 0xA) {
            if (i >= *(s32 *)(arg2 + 8)) {
                color = 0xDE7201;
            } else {
                color = 0xFFFFFF;
            }
            func_0025f3f0(color, 0xFF, 0x15, 0, (void *)asset, 1,
                          (f32)(i * 0x17 + 0x162) + temp_f20,
                          381.0f, 0.0f);
            i++;
        }
    }
    return 0;
}
Rejected: compiler rematerializes D_00887300 vtable base and rotates saved GPRs; normalized diff remained nonzero.
