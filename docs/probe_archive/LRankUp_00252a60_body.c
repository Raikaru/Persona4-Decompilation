s32 func_00252a60(s32 arg0, u8 *arg1, u8 *arg2) {
    RankUpLocals stack;
#define sp1F0 (stack.result)
#define sp1B0 (stack.sp1B0)
#define sp170 (stack.sp170)
#define sp130 (stack.sp130)
#define sp110 (stack.sp110)
#define spF0 (stack.spF0)
#define spC0 (stack.spC0)
#define sp218 (stack.sp218)
#define sp220 (stack.sp220)
#define sp228 (stack.sp228)
#define sp22C (stack.sp22C)
#define sp230 (stack.sp230)
#define sp238 (stack.sp238)
    u8 *src;
    u8 *dst;
    u8 *src2;
    u8 *dst2;
    u8 *src3;
    u8 *dst3;
    s32 count;
    s32 temp1;
    s32 temp2;
    s32 temp3;
    s32 rank;
    s32 done;
    s32 is10;
    s32 alpha_i;
    u32 alpha_u;
    s32 rnd;
    f32 f0;
    f32 f1;
    f32 f20;
    f32 f21;
    s64 call1;
    s64 call2;
    s64 call3;
    u_long128 *qsrc;
    u_long128 *qdst;
    void (**vt)(u32, u32);

    done = 0;
    is10 = 0;
    if (*(s32 *)(arg2 + 8) == 0xA) {
        is10 = 1;
    }
    if (!(*(s32 *)arg1 & 2)) {
        *(s32 *)(arg1 + 4) = *(s32 *)(arg1 + 4) + 1;
    }
    rank = *(s32 *)(arg1 + 4);
    if (rank >= 0x3C) {
        done = 1;
    }
    if (rank >= 0x1F) {
        func_00252230(&sp1F0, (Sp120 *)(arg1 + 0x30), (Sp120 *)(arg1 + 0x54),
                      (f32)(rank - 0x1E) / 30.0f);
    } else {
        f20 = (D_00761184 * (f32)rank) / 30.0f;
        f20 = func_0044b7b0(f20);
        func_00252230(&sp1F0, (Sp120 *)(arg1 + 0xC), (Sp120 *)(arg1 + 0x30), f20);
    }

    src = D_00636210;
    dst = sp110;
    count = 4;
    do {
        temp1 = *(s32 *)(src + 0);
        temp2 = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)(dst + 0) = temp1;
        *(s32 *)(dst + 4) = temp2;
        dst += 8;
    } while (count > 0);

    src2 = D_00636230;
    dst2 = spF0;
    count = 4;
    do {
        temp1 = *(s32 *)(src2 + 0);
        temp2 = *(s32 *)(src2 + 4);
        src2 += 8;
        count--;
        *(s32 *)(dst2 + 0) = temp1;
        *(s32 *)(dst2 + 4) = temp2;
        dst2 += 8;
    } while (count > 0);

    if (rank < 0x1F) {
        func_003e0870(sp1B0, (u8 *)&sp1F0 + 0xC, sp1F0.f1C, 0);
    } else {
        temp1 = rank - 0x1E;
        sp218 = D_00636250[0];
        sp220 = D_00636258[0];
        sp230 = sp218;
        sp238 = D_00636258[0];
        func_003e0870(sp1B0, (u8 *)&sp1F0 + 0xC, sp1F0.f1C, 0);
        f20 = (-90.0f * (f32)temp1) / 30.0f;
        func_003e0870(sp1B0, &sp230, f20, 2);
    }

    call1 = func_0035afa0(*(s32 *)(arg2 + 0x14));
    call2 = func_0035afa0(*(s32 *)(arg2 + 0x18));
    if (rank >= 0x19) {
        call3 = func_0025f360(0x19, 0, *(s32 *)(arg2 + 0x10));
        if (rank < 0x1F) {
            f21 = (f32)(rank - 0x19) / 5.0f;
        } else {
            f0 = (f32)(rank - 0x1E);
            if (f0 < 5.0f) {
                f21 = 1.0f - (f0 / 5.0f);
            } else {
                f21 = 0.0f;
            }
        }
        f20 = D_007613A0 * f21;
        func_003e0870(sp170, (u8 *)&sp1F0 + 0xC, f20, 0);
        func_003e05f0(sp130, sp170, sp1B0);
        qsrc = (u_long128 *)sp130;
        qdst = (u_long128 *)sp170;
        count = 4;
        do {
            *qdst = *qsrc;
            qsrc++;
            count--;
            qdst++;
        } while (count > 0);
        func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                      0x73, 0x90, 0xFFFFFF,
                      *(u8 *)&sp1F0.f18, 1, 0x39, 0.0f, 0x48,
                      sp170, call3, spF0);
        if (is10 != 0) {
            func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                          0x6D, 0x89, 0x7F7F7F,
                          0xFF, 1, 0x37, 0.0f, 0x45,
                          sp1B0, call3, spF0);
        } else {
            func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                          0x6D, 0x89, 0xFF9C35,
                          0xFF, 1, 0x37, 0.0f, 0x45,
                          sp1B0, call3, spF0);
        }
    }

    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8,
                  ((u32)sp1F0.f18) & 0xFF, 3,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call1, sp110);
    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8,
                  ((u32)sp1F0.f18) & 0xFF, 5,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call2, sp110);

    vt = D_00887300;
    vt[0](7, 2);
    vt[0](9, 2);
    vt[0](6, 0);
    vt[0](8, 0);
    vt[0](0xC, 1);
    vt[0](2, 4);
    vt[0](0xE, 0);
    func_003f6440(3, 0x30003);
    func_003f6440(2, 0x48);

    temp1 = *(s16 *)(arg2 + 0x3C) + 1;
    *(s16 *)(arg2 + 0x3C) = (s16)temp1;
    if ((s16)temp1 >= 0x78) {
        *(s16 *)(arg2 + 0x3C) = 0;
    }
    f20 = (f32)(*(s16 *)(arg2 + 0x3C));
    f20 = (D_007612D0 * f20) / 120.0f;
    f20 = D_007612CC + f20;
    f20 = func_0044b7b0(f20);
    f20 = (1.0f + f20) / 2.0f;

    alpha_i = (u32)sp1F0.f18 & 0xFF;
    if (alpha_i >= 0) {
        f21 = (f32)alpha_i;
    } else {
        alpha_u = (u32)alpha_i;
        f21 = 2.0f * (f32)((alpha_u >> 1) | (alpha_u & 1));
    }
    alpha_i = (s32)(D_0076120C * f21 * f20);
    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8, alpha_i, 2,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call1, sp110);

    alpha_i = (u32)sp1F0.f18 & 0xFF;
    if (alpha_i >= 0) {
        f21 = (f32)alpha_i;
    } else {
        alpha_u = (u32)alpha_i;
        f21 = 2.0f * (f32)((alpha_u >> 1) | (alpha_u & 1));
    }
    alpha_i = (s32)(D_0076120C * f21 * f20);
    func_00366c70((s32)sp1F0.f4, (s32)sp1F0.f8,
                  sp1F0.f20, sp1F0.f22,
                  ((u32)sp1F0.f18) >> 8, alpha_i, 4,
                  (s16)(sp1F0.f20 >> 1), 0.0f,
                  (s16)(sp1F0.f22 >> 1), sp1B0, call2, sp110);

    rnd = func_003b7060();
    if (rnd >= 0) {
        f21 = (f32)rnd;
    } else {
        f21 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
    }
    f20 = D_007612D0 * (f21 / 2147483600.0f);
    rnd = func_003b7060();
    if (rnd >= 0) {
        f21 = (f32)rnd;
    } else {
        f21 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
    }
    if ((f21 / 2147483600.0f) < D_00761288) {
        rnd = func_003b7060();
        if (rnd >= 0) {
            f0 = (f32)rnd;
        } else {
            f0 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
        }
        f0 = 46.0f * (f0 / 2147483600.0f);
        if (!(f0 >= 2147483600.0f)) {
            temp1 = (s32)f0;
        } else {
            temp1 = (s32)(f0 - 2147483600.0f);
            temp1 |= (s32)0x80000000;
        }
        temp1 += 0x46;
        if (temp1 >= 0) {
            f21 = (f32)temp1;
        } else {
            f21 = 2.0f * (f32)(((u32)temp1 >> 1) | (temp1 & 1));
        }
    } else {
        rnd = func_003b7060();
        if (rnd >= 0) {
            f0 = (f32)rnd;
        } else {
            f0 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
        }
        f0 = 40.0f * (f0 / 2147483600.0f);
        if (!(f0 >= 2147483600.0f)) {
            temp1 = (s32)f0;
        } else {
            temp1 = (s32)(f0 - 2147483600.0f);
            temp1 |= (s32)0x80000000;
        }
        temp1 += 0x1E;
        if (temp1 >= 0) {
            f21 = (f32)temp1;
        } else {
            f21 = 2.0f * (f32)(((u32)temp1 >> 1) | (temp1 & 1));
        }
    }
    sp228 = f21 * func_0044b610(f20);
    f1 = -f21 * func_0044b7b0(f20);
    sp22C = f1;

    if (rank < 0x29) {
        u8 *p = func_00251570(arg0, 0);
        if (p != NULL) {
            *(f32 *)(p + 4) = sp1F0.f4 + sp228;
            *(f32 *)(p + 8) = sp1F0.f8 + f1;
        }
        src3 = D_00636260;
        dst3 = spC0;
        count = 5;
        do {
            temp1 = *(s32 *)(src3 + 0);
            temp2 = *(s32 *)(src3 + 4);
            src3 += 8;
            count--;
            *(s32 *)(dst3 + 0) = temp1;
            *(s32 *)(dst3 + 4) = temp2;
            dst3 += 8;
        } while (count > 0);
        rnd = func_003b7060();
        if (rnd >= 0) {
            f21 = (f32)rnd;
        } else {
            f21 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
        }
        temp1 = (s32)(5.0f * (f21 / 2147483600.0f));
        f20 = *(f32 *)(spC0 + temp1 * 8 + 4);
        sp228 = *(f32 *)(spC0 + temp1 * 8);
        sp22C = f20;
        p = func_00251570(arg0, 3);
        if (p != NULL) {
            rnd = func_003b7060();
            if (rnd >= 0) {
                f21 = (f32)rnd;
            } else {
                f21 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
            }
            *(f32 *)(p + 0xC) = 100.0f * (f21 / 2147483600.0f);
            *(f32 *)(p + 4) = sp228;
            *(f32 *)(p + 8) = f20;
        }
    }

    if (rank == 0x14) {
        u8 *p = func_00251570(arg0, 1);
        if (p != NULL) {
            *(u32 *)p |= 2;
            rnd = func_003b7060();
            if (rnd >= 0) {
                f21 = (f32)rnd;
            } else {
                f21 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
            }
            *(f32 *)(p + 0xC) = 100.0f * (f21 / 2147483600.0f);
            *(f32 *)(p + 4) = 112.0f;
            *(f32 *)(p + 8) = 272.0f;
        }
        p = func_00251570(arg0, 2);
        if (p != NULL) {
            *(u32 *)p |= 4;
            rnd = func_003b7060();
            if (rnd >= 0) {
                f21 = (f32)rnd;
            } else {
                f21 = 2.0f * (f32)(((u32)rnd >> 1) | (rnd & 1));
            }
            *(f32 *)(p + 0xC) = 100.0f * (f21 / 2147483600.0f);
            *(f32 *)(p + 4) = 68.0f;
            *(f32 *)(p + 8) = 419.0f;
        }
    } else if (rank == 0x1F) {
        func_00251850(arg0);
    }
#undef sp1F0
#undef sp1B0
#undef sp170
#undef sp130
#undef sp110
#undef spF0
#undef spC0
#undef sp218
#undef sp220
#undef sp228
#undef sp22C
#undef sp230
#undef sp238
    return done;
Archived aggregate-stack candidate; rejected for frame/register mismatch.
