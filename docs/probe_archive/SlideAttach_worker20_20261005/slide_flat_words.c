typedef struct SlideEnt {
    s32 f0, f1, f2, f3, f4, f5;
} SlideEnt;
void func_0029fbb0(u8 *arg0, s32 arg1) {
    s32 tbl[36];
    f32 stack[2];
    u8 *base;
    u8 *temp_18;
    u8 *temp_19;
    s16 *p22;
    s16 *p16;
    u8 color;
    u8 var23;
    s32 temp30;
    s32 temp22;
    s32 t18;
    s32 t17;
    s32 f2v;
    s32 f3v;
    s32 y2;
    s32 x2;
    f32 ret;
    s32 ix;
    s32 iy;
    s32 off4;
    s32 *srcw;
    s32 *dstw;
    s32 ncopy;
    s32 tmpc;
    s32 tmpd;
    base = *(u8 **)(arg0 + 0x38);
    srcw = D_0063E830;
    dstw = tbl;
    ncopy = 0x12;
do_copy:
    tmpc = srcw[0];
    tmpd = srcw[1];
    srcw += 2;
    ncopy -= 1;
    dstw[0] = tmpc;
    dstw[1] = tmpd;
    dstw += 2;
    if (ncopy > 0) {
        goto do_copy;
    }
    temp_18 = base + arg1 * 0x130 + 0x1510;
    temp_19 = base + arg1 * 0x130 + 0x15A8;
    off4 = arg1 * 4;
    p22 = (s16 *)(base + off4 + 0x1C38);
    p16 = (s16 *)(base + off4 + 0x1C3A);
    {
        s32 v0 = *p22;
        if (v0 == 3) {
            if (v0 != *p16) {
                s32 a0 = tbl[arg1 * 6 + 4];
                s32 a1 = tbl[arg1 * 6 + 5];
                func_002a2780((s32)temp_18);
                func_002a27c0((s32)temp_18, a0, a1 + 0x1E, a0, a1, fGpffff8204, 0, 0, 0xA);
                *p16 = *p22;
            }
            func_002a2980(temp_18);
            ret = func_002a2cd0(temp_18);
            color = (u8)(255.0f * ret);
            func_002a2c10(temp_18, stack);
            ix = (s32)stack[0];
            iy = (s32)stack[1];
            func_0025e9e0((f32)ix, (f32)iy, 0.0f, 0x2D2D2D, color, tbl[arg1 * 6 + 1], iGpffffb540, 1);
            func_0025e9e0((f32)((ix + tbl[arg1 * 6 + 2]) - tbl[arg1 * 6 + 4]), (f32)((iy + tbl[arg1 * 6 + 3]) - tbl[arg1 * 6 + 5]), 0.0f, 0x8F8F8F, color, tbl[arg1 * 6 + 0], iGpffffb540, 1);
            return;
        }
        if (v0 != *p16) {
            if (v0 == 0) {
                s32 a0 = tbl[arg1 * 6 + 4];
                s32 a1 = tbl[arg1 * 6 + 5];
                func_002a2780((s32)temp_18);
                if (*p16 == 3) {
                    func_002a27c0((s32)temp_18, a0, a1, a0, a1, fGpffff8204, 0, 0, 1);
                } else {
                    func_002a27c0((s32)temp_18, a0, a1, a0, a1, fGpffff8204, 0, 0, 0xA);
                }
            }
            *p16 = *p22;
        }
        func_002a2980(temp_18);
        ret = func_002a2cd0(temp_18);
        if (*p16 == 0) {
            f32 t = 1.0f - ret;
            u32 iv = (u32)(255.0f * t);
            color = (iv >> 1) & 0xFF;
        } else {
            color = 0xFF;
        }
        var23 = color & 0xFF;
        func_002a2c10(temp_18, stack);
        ix = (s32)stack[0];
        iy = (s32)stack[1];
        temp30 = tbl[arg1 * 6 + 1];
        func_0025e9e0((f32)ix, (f32)iy, 0.0f, 0x2D2D2D, 0xFF, temp30, iGpffffb540, 1);
        temp22 = tbl[arg1 * 6 + 0];
        t18 = tbl[arg1 * 6 + 5];
        f3v = tbl[arg1 * 6 + 3];
        y2 = (iy + f3v) - t18;
        t17 = tbl[arg1 * 6 + 4];
        f2v = tbl[arg1 * 6 + 2];
        x2 = (ix + f2v) - t17;
        func_0025e9e0((f32)x2, (f32)y2, 0.0f, 0x8F8F8F, 0xFF, temp22, iGpffffb540, 1);
        func_0025e9e0((f32)ix, (f32)iy, 0.0f, 0x99, var23, temp30, iGpffffb540, 1);
        func_0025e9e0((f32)x2, (f32)y2, 0.0f, 0xCCFFFF, var23, temp22, iGpffffb540, 1);
        {
            u8 *b2 = code29AddOff(off4, base);
            s32 *pflag = (s32 *)(b2 + 0x1C50);
            if (*pflag != 0) {
                *pflag = 0;
                ix = t17;
                iy = t18;
                func_002a2780((s32)temp_19);
                func_002a27c0((s32)temp_19, t17, t18, t17, t18, fGpffff8204, 0, 0, 2);
            }
        }
        if ((func_002a2ca0(temp_19) == 0) && (func_002a2c70(temp_19) != 0)) {
            func_002a2980(temp_19);
            func_002a2cd0(temp_19);
            var23 = 0xFF;
            func_002a2c10(temp_19, stack);
            ix = (s32)stack[0];
            iy = (s32)stack[1];
            func_0025ea20((f32)ix, (f32)iy, 0.0f, 0xCCFF33, 0xFF, temp30, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            func_0025ea20((f32)((ix + f2v) - t17), (f32)((iy + f3v) - t18), 0.0f, 0x2D2D2D, 0xFF, temp22, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        }
        if ((arg1 == 0) || (arg1 == 1) || (arg1 == 3)) {
            func_0025e9e0((f32)((ix + f2v) - t17), (f32)((iy + f3v) - t18), 0.0f, 0xCCFFFF, var23, temp22 + 0xB2, iGpffffb540, 1);
        }
    }
}
