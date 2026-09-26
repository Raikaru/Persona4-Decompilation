#pragma push
#pragma opt_loop_invariants on
// FUN_002A4F20
s32 func_002a4f20(s32 arg0)
{
    extern f32 D_00761304;
    extern f32 D_00761308;
    extern f32 D_0076130C;
    extern f32 D_00761120;
    s32 i;
    f32 x;
    s32 target;
    f32 fade;
    f32 slide;
    f32 y;
    f32 scale;
    f32 wave;
    s32 idx;
    s32 cur;
    s32 alpha;
    s32 step;
    s32 diff;
    u8 *p;

    p = (u8 *)func_00452560((void *)arg0);
    func_002a6b10(0, 0, 0xFF, p);
    func_002a7710(0xFF, p);
    if (*(s32 *)(p + 0x568) < 10) {
        fade = (f32)*(s32 *)(p + 0x568) / 10.0f;
    } else {
        fade = 1.0f;
    }
    alpha = 255.0f * fade;
    func_002a6b60(0, 0, alpha, p);
    func_002a6c30(0, 0, alpha, p);
    slide = sinf(D_00761184 * (f32)*(s32 *)(p + 0x568) / 30.0f);
    target = *(s32 *)(p + 0x3AC) << 16;
    if (*(s32 *)(p + 0x3B4) != target) {
        diff = target - *(s32 *)(p + 0x3B4);
        if ((f32)func_0043c6a0(diff) <= D_00761304 * (f32)target) {
            *(s32 *)(p + 0x3B4) = target;
        } else {
            f32 d = (f32)diff;
            f32 s = D_00761308 * d;

            if (s < D_0076130C) {
                step = d * 0.5f;
            } else {
                step = s;
            }
            *(s32 *)(p + 0x3B4) += step;
        }
    }
    cur = *(s32 *)(p + 0x3B4) >> 16;
    for (i = 0; i < 7; i++) {
        idx = cur + i - 3;
        if (idx < 0 || idx >= 0x10) {
            continue;
        }
        if ((i == 0 || i == 6) && (u16)*(s32 *)(p + 0x3B4) == 0) {
            continue;
        }
        func_002a6960(0, 0, 0x280, 0x1C0, 5.0f);
        func_002a6960(0, 0, 0x280, 0x2D, 0.0f);
        func_002a6960(0, 0x195, 0x280, 0x30, 0.0f);
        diff = (cur << 16) - *(s32 *)(p + 0x3B4);
        x = -59.0f + (f32)(i * 26) + (f32)(diff * 26) / 65536.0f;
        y = -152.0f + (f32)(i * 94) + (f32)(diff * 94) / 65536.0f;
        func_002a7920(0xFF, p + 0x14, idx, 0, p, x - 350.0f * (1.0f - slide), y, 0.0f, 1.0f);
        func_002a9f50(x, y, 5.0f, alpha, p + 0x14, idx, 0, p);
    }
    func_0025f3f0(0.0f, 131.0f, 0.0f, 0xFFFFFF, 0xFF, 0x22, 0, *(u8 **)(p + 0x398), 1);
    for (i = 0; i < 7; i++) {
        idx = cur + i - 3;
        if (idx < 0 || idx >= 0x10) {
            continue;
        }
        diff = (cur << 16) - *(s32 *)(p + 0x3B4);
        x = -59.0f + (f32)(i * 26) + (f32)(diff * 26) / 65536.0f;
        y = -152.0f + (f32)(i * 94) + (f32)(diff * 94) / 65536.0f;
        if (idx == cur || idx == cur + 1) {
            func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
            func_002a6960(0, 0x83, 0x280, 0x5E, 10.0f);
            func_002a9f50(x, y, 5.0f, alpha, p + 0x14, idx, 1, p);
        }
    }
    if (*(s32 *)(p + 0x3AC) + 1 != 0) {
        func_002a6960(0, 0, 0x280, 0x1C0, 0.0f);
        if (*(s32 *)(p + 0x3B8) > 0) {
            (*(s32 *)(p + 0x3B8))--;
        }
        wave = D_00761120 * sinf((D_00761174 * (f32)*(s32 *)(p + 0x3B8)) / 10.0f);
        scale = 1.0f + wave;
        x = 400.0f * (1.0f - slide);
        func_002a66d0(72.0f - x, 179.0f, 0.0f, 124.0f * scale, 116.0f * scale, 0x2D2D2D, 0xFF, 1);
        func_002a7920(0xFF, p + 0x14, *(s32 *)(p + 0x3AC), 1, p, 19.0f - x, 130.0f, 0.0f, scale);
    }
    if (++*(s32 *)(p + 0x568) >= 30) {
        *(s32 *)(p + 0x568) = 0;
        return 1;
    }
    return 0;
}
#pragma pop
