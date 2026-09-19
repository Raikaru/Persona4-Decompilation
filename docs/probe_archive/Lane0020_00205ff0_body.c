/* Lane0020_00205ff0 v8_fix floor; fnalign retail 886 / object 867 (-19, -2.1%) INSIDE band 859-913; jal 24 both, jalr 10 both (7x base $v0 + 3x cb $s5, count-loop cb shared via flag/goto); edits 303 (was 422 on v7/v3); grows +42 via x0 0.0 base for all X, s32 pos[4]/u8 col[4] struct, var_f22 duplication; remaining FPR/s-reg coloring + clamp c.le/bc1t vs c.olt/bc1f polarity + schedule floors; production stays INCLUDE_ASM (not MATCH). */
void func_00205ff0(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1, void (*callback)(void), u8 *arg3)
{
    extern f32 fGpffff809c;
    extern f32 fGpffff8198;
    void (*cb)(u8 *, s16, s8, s32, s32, f32, f32);
    void (**base)(u32, u32);
    u8 *work;
    f32 raw;
    f32 clamped;
    f32 shape;
    f32 var_f21;
    f32 var_f22;
    f32 f27;
    f32 f25;
    f32 f24;
    f32 f20;
    s32 var_19;
    s32 var_22;
    s32 var_23;
    s32 i;
    s32 count;
    s16 limit;
    s16 cur;
    s32 pos[4];
    u8 col[4];
    f32 x0;

    cb = (void (*)(u8 *, s16, s8, s32, s32, f32, f32))callback;
    work = (u8 *)func_00452560(*(s32 *)(arg0 + 0x5B0));
    var_22 = 1;
    var_19 = 1;
    if (*(s32 *)(arg0 + 4) & 4) {
        raw = (f32)*(s16 *)(arg0 + 0x16) / 4.0f;
        if (1.0f < raw) {
            clamped = 1.0f;
        } else {
            clamped = 0.0f;
            if (0.0f <= raw) {
                clamped = raw;
            }
        }
        shape = (2.0f * clamped) - (clamped * clamped);
        x0 = 0.0f;
        var_f22 = -50.0f * shape;
        var_f21 = var_f22;
    } else {
        raw = 1.0f - (f32)*(s16 *)(arg0 + 0x16) / 4.0f;
        if (1.0f < raw) {
            clamped = 1.0f;
        } else {
            clamped = 0.0f;
            if (0.0f <= raw) {
                clamped = raw;
            }
        }
        shape = 1.0f - ((2.0f * clamped) - (clamped * clamped));
        x0 = 0.0f;
        var_f22 = -50.0f * shape;
        var_f21 = var_f22;
    }
    var_23 = 1;
    if (shape <= 0.0f) {
        var_23 = 0;
    }
    if (arg1 == arg0 + 0xDC) {
        var_f21 += 16.0f;
        var_22 = 0;
        var_19 = 0;
    }
    func_002012d0(work, farg0, farg1);
    func_002019e0(work, 50.0f);
    if (var_19 != 0) {
        func_00201650(work, 9, 0x18, 261.0f, 410.0f, 0x21, 0x21, 0x21, 0xFF);
        func_00201650(work, 9, 0x2A, 261.0f, 410.0f, 0xFF, 0x7F, 0xE9, 0xFF);
        if (arg1 != arg0 + 0x144) {
            if (*(s32 *)(arg0 + 4) & 4) {
                func_00201410(work, 9, 0x2B, 283.0f, 410.0f);
            } else {
                func_00201410(work, 9, 0x2C, 283.0f, 410.0f);
            }
        } else {
            func_00201410(work, 9, 0x4D, 283.0f, 413.0f);
        }
    }
    raw = (f32)*(s16 *)(arg0 + 0x20) / 4.0f;
    if (1.0f < raw) {
        clamped = 1.0f;
    } else {
        clamped = 0.0f;
        if (0.0f <= raw) {
            clamped = raw;
        }
    }
    f27 = 1.0f - ((2.0f * clamped) - (clamped * clamped));
    base = D_00887300;
    base[0](6, 1);
    f24 = 70.0f * f27;
    f25 = 129.0f + var_f22 + f24;
    f20 = 476.0f + x0;
    func_00201410(work, 9, 0x26, f20, f25);
    f24 = (274.0f + var_f22) - f24;
    func_00201410(work, 9, 0x26, f20, f24);
    if (!(f27 <= 0.0f)) {
        base[0](1, 0);
        base[0](8, 1);
        col[0] = 0;
        col[1] = 0;
        col[2] = 0xFF;
        col[3] = 0;
        pos[0] = (s32)(32.0f + x0);
        pos[2] = 0x1E0;
        pos[3] = 0x46;
        pos[1] = (s32)(8.0f + (f25 - 70.0f));
        func_0045d6e0(col, (f32 *)(void *)pos, 0.0f, 0);
        pos[1] = (s32)(3.0f + f24);
        func_0045d6e0(col, (f32 *)(void *)pos, 0.0f, 0);
        base[0](8, 0);
    }
    func_00201650(work, 9, 0x24, (f32)0x1DF + x0, 135.0f + var_f22, 0x1B, 0x1B, 0x1B, 0xFF);
    base[0](6, 0);
    raw = (f32)*(s16 *)(arg0 + 0x22) / 10.0f;
    if (1.0f < raw) {
        clamped = 1.0f;
    } else {
        clamped = 0.0f;
        if (0.0f <= raw) {
            clamped = raw;
        }
    }
    clamped = 1.0f - ((2.0f * clamped) - (clamped * clamped));
    {
        f32 bright;
        f32 y;
        f32 x;
        u8 alpha;
        bright = (1.0f - clamped) * 255.0f;
        if (bright >= 2147483648.0f) {
            alpha = (u8)((s32)(bright - 2147483648.0f) | 0x80000000);
        } else {
            alpha = (u8)(s32)bright;
        }
        y = 113.0f + var_f22;
        x = (410.0f + x0) - clamped * 200.0f;
        func_00201650(work, 9, 0x29, x, y, 0x1B, 0x1B, 0x1B, alpha);
    }
    base[0](6, 1);
    limit = *(s16 *)(arg1 + 8);
    cur = *(s16 *)(arg1 + 6);
    if (limit >= cur) {
        limit = cur;
    }
    count = (s32)limit;
    if (count > 0) {
        s32 flag;
        for (i = 0; i < count; i++) {
            s16 slot = (s16)(*(s16 *)(arg1 + 2) + i);
            f32 yy = 31.0f * (f32)i + 145.0f + var_f22;
            if (*(s16 *)(arg1 + 4) == slot) {
                if (var_23 != 0) {
                    goto next_iter;
                }
                func_00201410(work, 9, 0x27, (f32)0x1DF + x0, 31.0f * (f32)i + 143.0f + var_f21);
                flag = 1;
                goto do_cb;
            } else {
                flag = 0;
            }
        do_cb:
            cb(arg0, slot, 0xFF, flag, 0, 97.0f + x0, yy);
        next_iter:
            ;
        }
    }
    if (var_23 != 0) {
        f32 shape2;
        f32 base2;
        f32 span;
        f32 fx;
        f32 fy;
        s32 tailflag;
        if (*(s32 *)(arg0 + 4) & 4) {
            raw = (f32)*(s16 *)(arg0 + 0x18) / 7.0f;
            if (1.0f < raw) {
                clamped = 1.0f;
            } else {
                clamped = 0.0f;
                if (0.0f <= raw) {
                    clamped = raw;
                }
            }
            shape2 = (2.0f * clamped) - (clamped * clamped);
            base2 = -410.0f;
        } else {
            raw = 1.0f - (f32)*(s16 *)(arg0 + 0x18) / 7.0f;
            if (1.0f < raw) {
                clamped = 1.0f;
            } else {
                clamped = 0.0f;
                if (0.0f <= raw) {
                    clamped = raw;
                }
            }
            shape2 = 1.0f - ((2.0f * clamped) - (clamped * clamped));
            base2 = -530.0f;
        }
        {
            f32 h = base2 * (1.0f - shape2);
            span = 31.0f * (f32)(*(s16 *)(arg1 + 4) - *(s16 *)(arg1 + 2));
            fx = 97.0f + x0;
            fy = 145.0f + var_f22 + span;
            func_00201650(work, 9, 0x25, 489.0f + h, 50.0f + (88.0f + span + var_f22), 0x28, 0x28, 0x28, 0xF2);
            func_00201410(work, 9, 0x26, 486.0f + h, 50.0f + (214.0f + span + var_f22));
            tailflag = 1;
            if (shape2 < 1.0f) {
                if (!(shape2 <= fGpffff809c)) {
                    f32 t = (shape2 - fGpffff809c) / fGpffff8198;
                    f32 yy = 50.0f + (120.0f + span + var_f22) - (1.0f - t) * 25.0f;
                    func_00201650(work, 9, 0x28, 68.0f, yy, 0xF3, 0, 0x0B, 0xFF);
                    {
                        u8 a2;
                        f32 _b;
                        _b = 255.0f * t;
                        if (_b >= 2147483648.0f) {
                            a2 = (u8)((s32)(_b - 2147483648.0f) | 0x80000000);
                        } else {
                            a2 = (u8)(s32)_b;
                        }
                        cb(arg0, *(s16 *)(arg1 + 4), a2, 1, 1, fx, fy);
                    }
                }
                tailflag = 0;
            } else {
                func_00201650(work, 9, 0x28, 68.0f, 50.0f + (120.0f + span + var_f22), 0xF3, 0, 0x0B, 0xFF);
            }
            {
                f32 hh;
                if (h < -10.0f) {
                    hh = 0.0f;
                } else {
                    hh = 10.0f + h;
                }
                func_00201410(work, 9, 0x27, (f32)0x1DF + x0 + hh, 143.0f + span + var_f21);
                cb(arg0, *(s16 *)(arg1 + 4), 0xFF, 1, tailflag, fx, fy);
            }
        }
    }
    if (var_22 != 0) {
        f32 xx = (f32)0x1CD + x0;
        func_00201410(work, 9, 0x2D, xx, 164.0f + var_f22);
        func_00201410(work, 9, 0x2E, xx, 236.0f + var_f22);
        {
            f32 ratio;
            if (*(s16 *)(arg1 + 6) < *(s16 *)(arg1 + 8)) {
                ratio = (f32)*(s16 *)(arg1 + 2) / (f32)(*(s16 *)(arg1 + 8) - *(s16 *)(arg1 + 6));
            } else {
                ratio = 0.0f;
            }
            func_00201410(work, 9, 0x2F, (f32)0x1CF + x0, ratio * 57.0f + 166.0f + var_f22);
        }
    }
    base[0](6, 0);
    func_002019e0(work, 0.0f);
}
