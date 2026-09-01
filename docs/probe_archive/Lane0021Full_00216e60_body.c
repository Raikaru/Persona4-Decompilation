/* Closest attempted candidate for func_00216e60; reverted because it did not match retail (object 4472B vs 4864B, nd 3317). */
void func_00216e60(u8 *arg0, u8 *arg1)
{
    typedef struct {
        u8 cB0[0x10];
        u8 cC0[0x10];
        u8 cD0[0x10];
        u8 cE0[0x10];
        u8 cF0[0x10];
        s32 flag100;
        s32 flag110;
        s32 box0;
        s32 box1;
        s32 box2;
        s32 box3;
        u8 c13c[4];
    } Work;
    extern s32 func_0019f050(u8 *arg0);
    extern void func_002012d0(u8 *arg0, f32 x, f32 y);
    extern void func_00201410(u8 *arg0, s32 font, s32 id, f32 x, f32 y);
    extern void func_00201820(s32 mode);
    extern s32 func_002340c0(s32 arg0, s32 mask);
    extern u8 *func_002724d0(u8 *text, s64 style, s32 mode, s32 arg3, u8 *arg4);
    extern void func_00272860(s32 arg0, s32 arg1);
    extern void func_00272950(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00272ba0(s32 arg0, s32 arg1);
    extern void func_00272c60(s32 arg0);
    extern void func_00272c80(s32 arg0);
    extern void func_00273170(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_002738d0(s32 arg0);
    extern void func_00274a20(s32 arg0, f32 width);
    extern void func_00274ed0(s32 color, s32 font, s32 mode, s32 glyph,
                               s32 arg4, s32 arg5, f32 x, f32 y, f32 scale);
    extern void func_002778c0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00278090(s32 arg0, s32 arg1, s32 arg2);
    extern void func_00278170(s32 arg0, s32 arg1);
    extern void func_00278ef0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_002791f0(f32 x, f32 y, f32 scale, s32 color, s32 arg4,
                             s32 arg5, s32 arg6, s32 arg7, s32 arg8);
    extern s32 func_00279690(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 arg3);
    extern u16 D_008C024E;
    extern void (*D_00887300[])(u32, u32);
    extern s32 iGpffffb4b0;
    extern f32 fGpffff8478;
    extern f32 fGpffff847c;
    extern f32 fGpffff8218;
    extern f32 fGpffffb47c;
    Work work;
    u8 *ctx;
    u8 *subctx;
    s32 *p;
    s32 n;
    s32 half;
    s32 old;
    s32 index;
    s32 color;
    s32 color2;
    s32 color3;
    s32 all;
    s32 pulse;
    s16 key;
    u16 count;
    f32 t;
    f32 fade;
    f32 pulsef;

    (void)arg0;
    ctx = func_00452560(*(s32 *)(arg1 + 0x3C));
    p = (s32 *)ctx;
    if ((*p & 1) == 0) {
        return;
    }
    func_00201350();
    func_002012d0((u8 *)p, 0.0f, 0.0f);
    index = *(u16 *)(arg1 + 0x14);
    if (index == 1) {
        if (*(s32 *)arg1 != 0) {
            func_00271b70(*(s32 *)arg1);
            *(s32 *)arg1 = 0;
        }
        func_00277ad0(*(s32 *)(arg1 + 0x18), 0);
        *(u16 *)(arg1 + 0x10) &= (u16)~2;
        *(s32 *)(arg1 + 8) = *(s32 *)(arg1 + 4);
        if (*(u16 *)(arg1 + 0x12) == 1) {
            if (*(s32 *)(arg1 + 0x20) != 0) {
                func_00278450((u8 *)(*(s32 *)(arg1 + 0x18)), 0,
                              (u8 *)func_0019f050((u8 *)*(s32 *)(arg1 + 0x20)));
            }
            func_00278ef0(*(s32 *)(arg1 + 0x18), 2, 0, 0xFF, 0xFF);
            func_002778c0(*(s32 *)(arg1 + 0x18), *(s32 *)(arg1 + 0x1C), 0);
            func_00278ef0(*(s32 *)(arg1 + 0x18), 2, 0, 0xFF, 0xFF);
            func_00278170(*(s32 *)(arg1 + 0x18), 0x800000);
            n = func_002787d0(*(s32 *)(arg1 + 0x18), *(s32 *)(arg1 + 0x1C), 0, 2);
            half = n >> 4;
            if (n < 0) {
                half = (n + 0xF) >> 4;
            }
            if (*(u16 *)(arg1 + 0x10) & 4) {
                old = half >> 1;
                if (half < 0) {
                    old = (half + 1) >> 1;
                }
                func_00278090(*(s32 *)(arg1 + 0x18), (0xD0 - old) << 4, 0x2A0);
            } else {
                old = half >> 1;
                if (half < 0) {
                    old = (half + 1) >> 1;
                }
                func_00278090(*(s32 *)(arg1 + 0x18), (0x12F - old) << 4, 0x2B0);
            }
        } else {
            func_00272c60(1);
            func_00272c80(2);
            iGpffffb4b0 = 120;
            *(s32 *)arg1 = (s32)func_002724d0((u8 *)*(s32 *)(arg1 + 0x24), 1, 0, 0, 0);
            iGpffffb4b0 = 0;
            func_00272860(*(s32 *)arg1, -1);
            func_00272c80(1);
            func_00272c60(2);
            n = func_002738d0(*(s32 *)arg1);
            half = n >> 1;
            if (n < 0) {
                half = (n + 1) >> 1;
            }
            if (*(u16 *)(arg1 + 0x10) & 4) {
                func_00272950(*(s32 *)arg1, (0xD1 - half) << 4, 0x2A0);
            } else {
                func_00272950(*(s32 *)arg1, (0x130 - half) << 4, 0x2A0);
            }
            func_00274a20(*(s32 *)arg1, 42.0f);
            func_00272ba0(*(s32 *)arg1, -1);
        }
        *(s32 *)(arg1 + 0xC) = half;
        *(s32 *)(arg1 + 8) = 0;
        *(u16 *)(arg1 + 0x14) = 2;
        *(u16 *)(arg1 + 0x10) |= 2;
        index = 2;
    }
    if (index == 2) {
        if ((*(u16 *)(arg1 + 0x10) & 1) == 0) {
            old = *(s32 *)(arg1 + 8);
            *(s32 *)(arg1 + 8) = old + 1;
            if (old >= *(s32 *)(arg1 + 4)) {
                subctx = func_00452560(*(s32 *)(arg1 + 0x3C)) + 0x84C;
                if (*(s32 *)subctx != 0) {
                    func_00271b70(*(s32 *)subctx);
                    *(s32 *)subctx = 0;
                }
                func_00277ad0(*(s32 *)(subctx + 0x18), 0);
                *(u16 *)(subctx + 0x10) &= (u16)~2;
                *(u16 *)(subctx + 0x16) = 0;
                *(s32 *)(subctx + 8) = *(s32 *)(subctx + 4);
                *(u16 *)(arg1 + 0x14) = 0;
            }
        } else if (*(u16 *)(arg1 + 0x10) & 2) {
            count = *(u16 *)(arg1 + 0x16);
            if (count < 4) {
                count++;
                *(u16 *)(arg1 + 0x16) = count;
                t = (f32)count / 4.0f;
                fade = 2.0f * t - t * t;
                if (*(u16 *)(arg1 + 0x12) != 1) {
                    work.c13c[0] = 0;
                    work.c13c[1] = 0;
                    work.c13c[2] = 0xFF;
                    work.c13c[3] = 0;
                    work.box0 = 104;
                    work.box1 = (s32)(83.0f - 16.0f * fade);
                    work.box2 = 400;
                    work.box3 = 20;
                    func_0045d6e0(work.c13c, &work.box0, 0, 0.0f);
                    work.box1 = (s32)(99.0f + 16.0f * fade);
                    func_0045d6e0(work.c13c, &work.box0, 0, 0.0f);
                    work.box1 = (s32)(83.0f - 16.0f * fade);
                    work.box3 = (s32)(99.0f + 16.0f * fade - (f32)work.box1);
                    func_0045d6e0(work.c13c, &work.box0, 0, 51.0f);
                    D_00887300[0](8, 0);
                }
                func_00201720((u8 *)p, 1.0f, fade);
                fade = 18.5f * (1.0f - fade);
                work.c13c[3] = 0;
                work.flag110 = 1;
            } else {
                fade = 0.0f;
                work.c13c[3] = 0xFF;
                work.flag110 = 0;
            }
            if (*(u16 *)(arg1 + 0x10) & 8) {
                func_002012d0((u8 *)p, 0.0f, 81.0f);
                func_00201410((u8 *)p, 10, 44, 186.0f, fade);
                func_00201410((u8 *)p, 10, 41, 402.0f, fade);
            } else {
                func_002012d0((u8 *)p, 94.0f, 81.0f);
                func_00201410((u8 *)p, 10, 40, 0.0f, fade);
                func_00201410((u8 *)p, 10, 41, 400.0f, fade);
                if ((*(u16 *)(arg1 + 0x10) & 4) && work.c13c[3] != 0) {
                    s32 bits = *(s32 *)(*(s32 *)(arg1 + 0x20) + 0xA64);
                    all = (func_002340c0(bits, 0x400) != 0 ||
                           func_002340c0(bits, 0x800) != 0);
                    if (func_002340c0(bits, 1) != 0 ||
                        func_002340c0(bits, 4) != 0) {
                        index = 0x25; color = 0xFF; color2 = 0x65; color3 = 0x74;
                    } else if (func_002340c0(bits, 2) != 0 ||
                               func_002340c0(bits, 8) != 0) {
                        index = 0x26; color = 0x79; color2 = 0xA1; color3 = 0xFF;
                    } else {
                        index = 0x27; color = 0x66; color2 = 0x66; color3 = 0x66;
                    }
                    if (func_002340c0(bits, 0x40) != 0) {
                        n = 0x25; old = 0xFF; work.cD0[0] = 0x65; work.cC0[0] = 0x74;
                    } else if (func_002340c0(bits, 0x80) != 0) {
                        n = 0x26; old = 0x79; work.cD0[0] = 0xA1; work.cC0[0] = 0xFF;
                    } else {
                        n = 0x27; old = 0x66; work.cD0[0] = 0x66; work.cC0[0] = 0x66;
                    }
                    if (func_002340c0(bits, 0x100) != 0 ||
                        func_002340c0(bits, 0x10) != 0) {
                        half = 0x25; pulse = 0xFF; work.cB0[0] = 0x65; work.cB0[1] = 0x74;
                    } else if (func_002340c0(bits, 0x200) != 0 ||
                               func_002340c0(bits, 0x20) != 0) {
                        half = 0x26; pulse = 0x79; work.cB0[0] = 0xA1; work.cB0[1] = 0xFF;
                    } else {
                        half = 0x27; pulse = 0x66; work.cB0[0] = 0x66; work.cB0[1] = 0x66;
                    }
                    if (index == 0x27 && n == 0x27 && half == 0x27 && !all) {
                        work.c13c[0] = 0x66;
                        work.c13c[1] = 0x66;
                        work.c13c[2] = 0x66;
                    } else {
                        work.c13c[0] = 0xFF;
                        work.c13c[1] = 0xFF;
                        work.c13c[2] = 0xFF;
                    }
                    func_00201650((u8 *)p, 10, 42, 222.0f, 6.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 43, 384.0f, 6.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 34, 233.0f, 8.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 35, 285.0f, 8.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, 36, 337.0f, 8.0f,
                                  work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                    func_00201650((u8 *)p, 10, n, 313.0f, 10.0f,
                                  old, work.cD0[0], work.cC0[0], work.c13c[3]);
                    func_00201650((u8 *)p, 10, half, 365.0f, 10.0f,
                                  pulse, work.cB0[0], work.cB0[1], work.c13c[3]);
                    if (!all) {
                        func_00201650((u8 *)p, 10, index, 261.0f, 10.0f,
                                      color, color2, color3, work.c13c[3]);
                    } else {
                        func_00201650((u8 *)p, 10, 0x56, 262.0f, -8.0f,
                                      work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                        func_00201650((u8 *)p, 10, 0x57, 252.0f, 26.0f,
                                      work.c13c[0], work.c13c[1], work.c13c[2], work.c13c[3]);
                        func_00201650((u8 *)p, 10, 0x25, 261.0f, 4.0f,
                                      0xFF, 0x65, 0x74, work.c13c[3]);
                        func_00201650((u8 *)p, 10, 0x25, 261.0f, 15.0f,
                                      0xFF, 0x65, 0x74, work.c13c[3]);
                        if (index == 0x25) {
                            pulsef = func_0044b7b0(fGpffff8478 * fGpffffb47c);
                            pulse = (s32)(255.0f * (fGpffff847c + fGpffff8218 * pulsef));
                            fGpffffb47c += 12.0f;
                            if (fGpffffb47c >= 180.0f) {
                                fGpffffb47c -= 180.0f;
                            }
                            func_00201820(2);
                            func_00201650((u8 *)p, 10, 0x58, 256.0f, -1.0f,
                                          0xFC, 0x30, 0x30, pulse & 0xFF);
                            func_00201820(0);
                        }
                    }
                }
            }
            if (*(s32 *)arg1 != 0) {
                func_00272c60(0x40);
                if (work.flag110 != 0) {
                    D_00887300[0](6, 1);
                    func_00273170(*(s32 *)arg1, 1, 0);
                    D_00887300[0](6, 0);
                } else {
                    func_00273170(*(s32 *)arg1, 1, 0);
                }
                func_00272c80(0x40);
            }
        }
    }
    if (*(u16 *)(arg1 + 0x10) & 0x10) {
        t = (f32)*(s32 *)(arg1 + 0x34) / 8.0f;
        fade = 1.0f;
        if (t <= 1.0f && t >= 0.0f) {
            fade = 2.0f * t - t * t;
        }
        func_002012d0((u8 *)p, 0.0f, -24.0f);
        func_00201720((u8 *)p, 1.0f, 1.0f);
        func_00201650((u8 *)p, 9, 0x52, 379.0f - 400.0f * (1.0f - fade),
                      303.0f, 0x21, 0x21, 0x21, 0xFF);
        t = (f32)(*(s32 *)(arg1 + 0x34) - 4) / 6.0f;
        fade = 1.0f;
        if (t <= 1.0f) {
            fade = 0.0f;
            if (t >= 0.0f) {
                fade = 2.0f * t - t * t;
            }
        }
        if (fade > 0.0f) {
            func_00201720((u8 *)p, 1.0f, fade);
            func_00201650((u8 *)p, 9, 0x50, 170.0f, 367.0f + 17.0f * (1.0f - fade),
                          0xFF, 0xF1, 0, 0xFF);
            func_00201650((u8 *)p, 9, 0x51, 473.0f, 367.0f + 17.0f * (1.0f - fade),
                          0xFF, 0xF1, 0, 0xFF);
            func_00201720((u8 *)p, 1.0f, 1.0f);
        }
        if (fade == 1.0f) {
            func_00201650((u8 *)p, 9, 0x53, 211.0f, 371.0f,
                          0xFF, 0xFF, 0xFF, 0xFF);
            func_00201650((u8 *)p, 9, 0x54, 328.0f, 371.0f,
                          0xFF, 0xFF, 0xFF, 0xFF);
            func_00274ed0(0x212121FF, 5, 0, (s32)iGpffffa598, 0, 0,
                          244.0f, 359.0f, 0.0f);
            func_00274ed0(0x212121FF, 5, 0, (s32)iGpffffa598, 0, 0,
                          361.0f, 359.0f, 0.0f);
            if (*(s32 *)(arg1 + 0x38) == 0) {
                func_00279690(*(s32 *)(arg1 + 0x2C), *(s32 *)(arg1 + 0x30), 1, 0xF561);
                *(s32 *)(arg1 + 0x38) = 1;
            }
            func_002791f0(-1.0f, 0.0f, 0.0f, 0, 0,
                          *(s32 *)(arg1 + 0x2C), *(s32 *)(arg1 + 0x30),
                          0x41F80000, 0x43960000);
            key = *(s16 *)(arg1 + 0x2A);
            if (key == 0) {
                if (*(s16 *)(arg1 + 0x28) == -1) {
                    if (D_008C024E & 0x40) {
                        *(s16 *)(arg1 + 0x28) = 0;
                    } else if (D_008C024E & 0x20) {
                        *(s16 *)(arg1 + 0x28) = 1;
                    }
                }
            } else {
                *(s16 *)(arg1 + 0x2A) = key - 1;
            }
        }
    (*(s32 *)(arg1 + 0x34))++;
    }
}
