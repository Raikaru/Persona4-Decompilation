/* Closest attempted candidate for func_002142b0; reverted because it did not match retail (object 7264B vs 6496B, nd 5666). */
void func_002142b0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1)
{
    typedef struct {
        s64 stat0[2];
        s64 stat1[2];
        u8 color[0x14];
        s32 status;
        f32 unused[2];
        f32 x[8];
        f32 y[8];
        f32 offset[8];
        f32 effect[8];
    } Work;
    extern void func_002012d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void func_00201300(s32 *arg0, f32 fparg0, f32 fparg1,
                              f32 fparg2, f32 fparg3);
    extern void func_00201410(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                              f32 fparg1);
    extern void func_00201650(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                              f32 fparg1, s32 arg5, s32 arg6, s32 arg7,
                              s32 arg8);
    extern void func_002016b0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
    extern void func_00201820(s32 arg0);
    extern void func_002019d0(u8 *arg0, f32 fparg0, f32 fparg1);
    extern s32 func_00231ed0(s32 arg0);
    extern s32 func_00231ee0(s32 arg0);
    extern s32 func_00231f80(s32 arg0);
    extern s32 func_00232290(s32 arg0);
    extern s32 func_00366c70(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                             s32 arg4, s32 arg5, s32 arg6, s16 arg7,
                             f32 fparg0, s16 arg_sp0, s32 *arg_sp8,
                             s32 arg_sp10, s32 *arg_sp18);
    extern void func_0043f9c8(void *dst, s32 value, u32 size);
    extern f32 fGpffff815c;
    extern f32 fGpffff8218;
    extern f32 fGpffff84b4;
    extern f32 fGpffff84b8;
    extern u8 D_00626CC0[];
    extern u8 D_00626DE0[];
    extern u8 D_00626F00[];
    extern u8 D_00626F60[];
    extern u8 D_00626FC0[];
    extern u8 D_00626FD0[];
    Work work;
    u8 *context;
    s32 hp;
    s32 sp;
    s32 state;
    s32 frame;
    s32 i;
    s32 alpha;
    s32 alpha2;
    s32 tile;
    f32 t;
    f32 smooth;
    f32 fade;
    f32 value;
    f32 value2;
    f32 baseX;
    f32 baseY;
    f32 temp;

    context = (u8 *)arg0 + 0x80C;
    func_00213e20(arg1, work.color);
    hp = func_00231ed0(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    sp = func_00231ee0(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    work.stat0[0] = func_00231f80(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    work.stat1[0] = func_00232290(*(s32 *)(arg1 + 0xA64)) & 0xFFFF;
    tile = *(u16 *)(arg1 + 0xA4);
    if (tile < 9) {
        tile -= 1;
    } else {
        tile = 0;
    }
    frame = *(s16 *)(arg1 + 0xA16);
    if (frame < -1) {
        return;
    }
    if (frame < 0x19) {
        frame = (s16)(frame - (s16)(arg2 * 2));
        state = *(s16 *)(arg1 + 0xA14);
        if (state > 0 && state < 9) {
            t = (f32)state;
            if (t <= 6.0f) {
                t = 1.0f;
            } else {
                t /= 6.0f;
            }
            smooth = 2.0f * t - t * t;
            fparg0 = fparg0 + smooth * (fGpffff84b4 - fparg0);
            t = (f32)(arg2 * 2);
            fparg1 = fparg1 + smooth * (fGpffff84b8 + 42.0f * t - fparg1);
            fade = fGpffff8218 - fGpffff8218 * smooth;
            func_002019d0((u8 *)arg0, fade, fade);
            value = (f32)frame;
            for (i = 0; i < 3; i++) {
                if (value <= 8.0f) {
                    if (value < 0.0f) {
                        temp = 0.0f;
                    } else {
                        temp = value / 8.0f;
                    }
                } else {
                    temp = 1.0f;
                }
                smooth = 1.0f - (2.0f * temp - temp * temp);
                work.offset[i * 2] = 180.0f * smooth;
                work.offset[i * 2 + 1] = 80.0f * smooth;
                if (*(s32 *)context & 1) {
                    value += 0.75f;
                } else {
                    value -= 0.75f;
                }
            }
            value = (f32)(frame - 3);
            if (value <= 8.0f) {
                if (value < 0.0f) {
                    temp = 0.0f;
                } else {
                    temp = value / 8.0f;
                }
            } else {
                temp = 1.0f;
            }
            smooth = 1.0f - (2.0f * temp - temp * temp);
            baseX = 180.0f * smooth;
            baseY = -(80.0f * smooth);
            value = (f32)frame;
            for (i = 0; i < 3; i++) {
                temp = value - 5.0f;
                if (temp <= 8.0f) {
                    if (temp < 0.0f) {
                        fade = 0.0f;
                    } else {
                        fade = temp / 8.0f;
                    }
                } else {
                    fade = 1.0f;
                }
                smooth = 1.0f - (2.0f * fade - fade * fade);
                work.y[i * 2] = 180.0f * smooth;
                work.y[i * 2 + 1] = -(80.0f * smooth);
                temp = value - 7.0f;
                if (temp <= 8.0f) {
                    if (temp < 0.0f) {
                        fade = 0.0f;
                    } else {
                        fade = temp / 8.0f;
                    }
                } else {
                    fade = 1.0f;
                }
                smooth = 1.0f - (2.0f * fade - fade * fade);
                work.x[i * 2] = 180.0f * smooth;
                work.x[i * 2 + 1] = -(80.0f * smooth);
                value += 1.0f;
            }
        } else {
            state = *(s16 *)(arg1 + 0xA14);
            if (state > 0 && state < 9) {
                if (*(s32 *)(context + 8) != (s32)arg1 &&
                    (*(s32 *)context & 2)) {
                    state -= 2;
                }
                t = (f32)state;
                if (t <= 6.0f) {
                    t = 1.0f;
                } else {
                    t /= 6.0f;
                }
                smooth = 2.0f * t - t * t;
                fparg0 = fparg0 + smooth * (fGpffff84b4 - fparg0);
                t = (f32)(arg2 * 2);
                fparg1 = fparg1 + smooth * (fGpffff84b8 + 42.0f * t - fparg1);
                fade = fGpffff8218 - fGpffff8218 * smooth;
                func_002019d0((u8 *)arg0, fade, fade);
                func_0043f9c8(work.offset, 0, 0x18);
                func_0043f9c8(work.y, 0, 0x18);
                func_0043f9c8(work.x, 0, 0x18);
                baseX = 0.0f;
                baseY = 0.0f;
            } else {
                func_002012d0((u8 *)arg0, fparg0, fparg1);
                func_0043f9c8(work.offset, 0, 0x18);
                func_0043f9c8(work.y, 0, 0x18);
                func_0043f9c8(work.x, 0, 0x18);
                baseX = 0.0f;
                baseY = 0.0f;
            }
        }
        state = *(s16 *)(context + 4);
        if (state > 0) {
            if (*(s32 *)context & 4) {
                value = (f32)state;
            } else {
                value = (f32)state - 2.5f;
            }
            if (*(s32 *)context & 4) {
                if (value <= 10.0f) {
                    if (value < 0.0f) {
                        t = 0.0f;
                    } else {
                        t = value / 10.0f;
                    }
                } else {
                    t = 1.0f;
                }
                smooth = 2.0f * t - t * t;
            } else {
                if (value <= 10.0f) {
                    if (value < 0.0f) {
                        t = 0.0f;
                    } else {
                        t = value / 10.0f;
                    }
                } else {
                    t = 1.0f;
                }
                smooth = 1.0f - (2.0f * t - t * t);
            }
            fade = 180.0f * smooth;
            baseX += fade;
            for (i = 0; i < 3; i++) {
                if (*(s32 *)context & 4) {
                    if (value <= 10.0f) {
                        if (value < 0.0f) {
                            t = 0.0f;
                        } else {
                            t = value / 10.0f;
                        }
                    } else {
                        t = 1.0f;
                    }
                    smooth = 2.0f * t - t * t;
                    value -= 1.25f;
                } else {
                    if (value <= 10.0f) {
                        if (value < 0.0f) {
                            t = 0.0f;
                        } else {
                            t = value / 10.0f;
                        }
                    } else {
                        t = 1.0f;
                    }
                    smooth = 1.0f - (2.0f * t - t * t);
                    value += 1.25f;
                }
                work.effect[i * 2] += 102.0f * smooth;
            }
        }
        if (*(s32 *)(arg1 + 0xA10) & 1) {
            tile = *(u16 *)(arg1 + 0xA18);
            value = func_0044b610(state) * fGpffff815c;
            value2 = func_0044b7b0(fGpffff815c);
            for (i = 0; i < 3; i++) {
                temp = (f32)D_00626FC0[i] *
                       (f32)D_00626CC0[tile * 24 + i * 24];
                work.effect[i * 2] = temp * value;
                work.effect[i * 2 + 1] = -temp * value2;
                work.effect[i * 2 + 1] -=
                    (f32)D_00626FD0[i] *
                    (f32)D_00626CC0[tile * 24 + i * 24];
            }
            alpha = (s32)(64.0f * (f32)D_00626F00[tile]) & 0xFF;
            tile = (s16)tile + 1;
            *(u16 *)(arg1 + 0xA18) = (u16)tile;
            if ((s16)tile >= 0x18) {
                *(s32 *)(arg1 + 0xA10) &= ~1;
            }
        } else {
            func_0043f9c8(work.effect, 0, 0x18);
        }
        func_00201300(arg0, fparg0, fparg1, 0x43080000, 0x43080000);
        if (*(s32 *)(arg1 + 0xA10) & 0x200) {
            func_00201650((u8 *)arg0, 8, 0xE, 0x9D, 0xFF, 0x22, 0xFF,
                          29.0f, 27.0f);
        }
        if (*(s32 *)(arg1 + 0xA10) & 2) {
            temp = (f32)D_00626F60[(*(s16 *)(arg1 + 0xA1A)) * 4];
            alpha = (s32)(160.0f * temp) & 0xFF;
            alpha2 = (s32)(255.0f * temp) & 0xFF;
            func_00201650((u8 *)arg0, 8, 0xE, 0x9D, 0xFF, 0x22, alpha,
                          29.0f, 27.0f);
            *(s16 *)(arg1 + 0xA1A) += 1;
            if (*(s16 *)(arg1 + 0xA1A) >= 0x18) {
                *(s32 *)(arg1 + 0xA10) &= ~2;
            }
        }
        if (work.status != 0) {
            func_00201650((u8 *)arg0, 0xB, 0, work.color[0xC],
                          work.color[0xD], work.color[0xE], 0xFF,
                          29.0f + work.effect[0] + work.offset[0],
                          27.0f + work.effect[1] + work.offset[1]);
        }
        func_00201650((u8 *)arg0, tile, 1, work.color[4], work.color[5],
                      work.color[6], 0xFF, 27.0f + work.effect[6] + work.y[6],
                      16.0f + work.effect[7] + work.y[7]);
        func_00201650((u8 *)arg0, tile, 1, work.color[0], work.color[1],
                      work.color[2], 0xFF, 20.0f + work.effect[4] + work.y[4],
                      20.0f + work.effect[5] + work.y[5]);
        func_00201410((u8 *)arg0, tile, 0,
                      20.0f + work.effect[0] + work.offset[0],
                      20.0f + work.effect[1] + work.offset[1]);
        if (work.status != 0) {
            func_00201820(2);
            func_00201650((u8 *)arg0, tile, 0, work.color[8],
                          work.color[9], work.color[0xA], 0xFF,
                          20.0f + work.effect[0] + work.offset[0],
                          20.0f + work.effect[1] + work.offset[1]);
            func_00201820(0);
        }
        if (*(s32 *)(arg1 + 0xA10) & 3) {
            func_00201820(2);
            func_00201650((u8 *)arg0, tile, 0, 0xFF, 0xFF, 0xFF, alpha,
                          20.0f + work.effect[0], 20.0f + work.effect[1]);
            func_00201820(0);
        }
        if (work.status != 0) {
            baseX = work.effect[0] + work.offset[0];
            baseY = work.effect[1] + work.offset[1];
            switch (work.status) {
            case 2:
                func_00201410((u8 *)arg0, 0xB, 0xA, 89.0f + baseX, 25.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0xC, 66.0f + baseX, 53.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0xB, 48.0f + baseX, 22.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 9, 27.0f + baseX, 86.0f + baseY);
                break;
            case 4:
                func_00201410((u8 *)arg0, 0xB, 0xE, 59.0f + baseX, 18.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0xF, 46.0f + baseX, 77.0f + baseY);
                break;
            case 8:
                func_00201410((u8 *)arg0, 0xB, 0xD, 73.0f + baseX, 25.0f + baseY);
                break;
            case 0x10:
                func_00201410((u8 *)arg0, 0xB, 5, 36.0f + baseX, 27.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 6, 87.0f + baseX, 27.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 8, 32.0f + baseX, 88.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 7, 65.0f + baseX, 67.0f + baseY);
                break;
            case 1:
                func_00201410((u8 *)arg0, 0xB, 0x10, 59.0f + baseX, 21.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x12, 109.0f + baseX, 38.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x14, 46.0f + baseX, 27.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x11, 23.0f + baseX, 76.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x13, 38.0f + baseX, 99.0f + baseY);
                break;
            case 0x20:
                func_00201410((u8 *)arg0, 0xB, 1, 82.0f + baseX, 22.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 2, 47.0f + baseX, 23.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 3, 31.0f + baseX, 91.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 4, 31.0f + baseX, 44.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 4, 65.0f + baseX, 84.0f + baseY);
                break;
            case 0x40:
                func_00201410((u8 *)arg0, 0xB, 0x15, 73.0f + baseX, 22.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x16, 60.0f + baseX, 51.0f + baseY);
                break;
            case 0x80:
                func_00201410((u8 *)arg0, 0xB, 0x17, 83.0f + baseX, 30.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x18, 62.0f + baseX, 50.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x19, 78.0f + baseX, 26.0f + baseY);
                func_00201410((u8 *)arg0, 0xB, 0x1A, 32.0f + baseX, 88.0f + baseY);
                break;
            case 0x80000:
                func_00201410((u8 *)arg0, 0xB, 0x1B, 29.0f + baseX, 27.0f + baseY);
                break;
            }
        }
        func_00201650((u8 *)arg0, 8, 0xA, work.color[0x10],
                      work.color[0x11], work.color[0x12], 0xFF,
                      63.0f + baseX, 82.0f + baseY);
        func_00201650((u8 *)arg0, 8, 0xB, 0x26, 0x26, 0x26, 0xFF,
                      66.0f + baseX, 85.0f + baseY);
        value = (f32)work.stat0[0];
        temp = 54.0f * (f32)hp / value;
        if (temp < 5.0f) {
            value = 0.0f;
        }
        func_002016b0((u8 *)arg0, 8, 0xC, (s32)value);
        func_00201650((u8 *)arg0, 8, 0xC, 0xFF, 0xE0, 0x51, 0xFF,
                      70.0f + baseX, 88.0f + baseY);
        value2 = (f32)work.stat1[0];
        temp = 54.0f * (f32)sp / value2;
        if (temp < 5.0f) {
            value2 = 0.0f;
        }
        func_002016b0((u8 *)arg0, 8, 0xC, (s32)value2);
        func_00201650((u8 *)arg0, 8, 0xC, 0xB7, 0xFF, 0x54, 0xFF,
                      70.0f + baseX, 94.0f + baseY);
        func_00201410((u8 *)arg0, 8, sp % 10,
                      121.0f + work.x[0], 64.0f + work.x[1]);
        if (sp / 10 != 0) {
            func_00201410((u8 *)arg0, 8, (sp / 10) % 10,
                          108.0f + work.x[2], 69.0f + work.x[3]);
        }
        if (sp / 100 != 0) {
            func_00201410((u8 *)arg0, 8, (sp / 100) % 10,
                          95.0f + work.x[4], 74.0f + work.x[5]);
        }
        func_00201410((u8 *)arg0, 8, hp % 10,
                      122.0f + work.y[0], 47.0f + work.y[1]);
        if (hp / 10 != 0) {
            func_00201410((u8 *)arg0, 8, (hp / 10) % 10,
                          109.0f + work.y[2], 52.0f + work.y[3]);
        }
        if (hp / 100 != 0) {
            func_00201410((u8 *)arg0, 8, (hp / 100) % 10,
                          96.0f + work.y[4], 57.0f + work.y[5]);
        }
    }
}
