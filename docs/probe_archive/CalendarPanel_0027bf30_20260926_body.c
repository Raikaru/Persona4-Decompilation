// FUN_0027BF30
/* Needs code1_0027.c line 50 changed to: extern void func_001104d0(s32 date, s32 *month, s32 *day); */
static inline void func_0027bf30_clear(u8 *p, s32 n)
{
    if (p != NULL) {
        do {
            *p++ = 0;
        } while (--n != 0);
    }
}

void func_0027bf30(u8 *arg0, u8 *arg1)
{
    typedef struct {
        s32 x;
        s32 y;
        s32 w;
        s32 h;
    } Rect_bf30;
    extern u8 *func_002833b0(s32 arg0);
    extern f32 sinf(f32 arg0);
    extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2);
    extern u8 *func_0046a770(char *arg0);
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern s32 func_0025ea20(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern void func_00366380(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s16 arg8, void *arg9, f32 farg0, f32 farg1, f32 farg2, f32 farg3);
    extern s32 func_00110580(s32 arg0);
    extern s32 func_00110d30(s32 arg0);
    extern s32 func_00110c50(s32 arg0, s32 arg1);
    extern void func_00262de0(s32 x, s32 y, f32 depth, u8 alpha, s32 date, s32 enabled, f32 scaleX, f32 scaleY, s32 clipLeft, s32 clipRight, s32 fontWord, s32 forceWhite);
    extern void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2, s32 arg3, s32 arg4, f32 fparg1, f32 fparg2, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0);
    extern char D_0063BFB0[];
    extern u8 D_007482F0[];
    s32 month;
    s32 day;
    f32 depthColor;
    u8 color[4];
    s32 appear[6];
    f32 alpha;
    f32 x;
    f32 y;
    f32 rot;
    f32 fade;
    f32 t;
    u8 *font;
    s32 py;
    s32 mode;
    s32 date;
    s32 px;
    s32 today;
    s32 tile;
    s32 rgb;
    s32 week;
    s32 phase;
    s32 frame;
    s32 i;
    void (**table)(s32, s32);
    s32 lineRgb;
    u8 *handle;

    switch (*(s32 *)(arg1 + 4)) {
    case 4:
        handle = func_002833b0(0);
        if (handle == NULL) {
            break;
        }
        t = sinf(1.5707964f * (f32)*(s32 *)(arg1 + 0x10) / 20.0f);
        func_0027bf30_clear(color, 4);
        fade = 1.0f - t;
        alpha = 76.5f * fade;
        color[3] = alpha;
        depthColor = *(f32 *)color;
        {
            Rect_bf30 rect = {0, 0, 640, 480};

            func_0045d6e0((u8 *)&depthColor, (f32 *)&rect, 10.0f, 1);
        }
        phase = *(s32 *)(arg1 + 0x10) % 4;
        table = (void (**)(s32, s32))(u32)D_00887300;
        table[0](6, 1);
        table[0](8, 1);
        RpSkyRenderStateSet(3, 0x7000D);
        RpSkyRenderStateSet(2, 0x48);
        for (tile = 0; tile < 24; tile++) {
            x = (tile % 6) * 126;
            y = (tile / 6) * 126;
            func_0025ea20(x, y, 10.0f, 0xFFFFFF, alpha, phase, func_0046a770(D_0063BFB0), 0, 0, 0, 0.0f, 1.0f, 1.0f);
            phase = (phase + 1) % 4;
        }
        frame = (f32)*(s32 *)(arg1 + 0x10) + *(f32 *)(arg1 + 8);
        if ((f32)frame > 120.0f) {
            frame = (f32)frame - 120.0f;
        }
        rot = (f32)frame / 120.0f;
        if (handle == NULL) {
            func_0046d730(D_007482F0, 0x59);
        }
        func_0025ea20(-59.0f, -103.0f, 10.0f, 0xFFFFFF, 255.0f * fade, 2, **(void ***)(handle + 8), 1, 0x80, 0x80, 360.0f * rot, 1.0f, 1.0f);
        frame = *(s32 *)(arg1 + 0x10);
        if (frame < 4) {
            fade = sinf(1.5707964f * (f32)frame / 4.0f);
            if (handle == NULL) {
                func_0046d730(D_007482F0, 0x59);
            }
            rot = 1.0f - fade;
            func_0025ea20(165.0f, 244.0f + 95.0f * fade, 0.0f, 0, 0xCC, 1, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, rot);
            func_00366380(0xB0, 271 + 64.0f * fade, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 0.0f, 1.0f, 0.3f + 0.3f * rot);
        } else if (frame < 11) {
            t = (f32)(frame - 4) / 6.0f;
            func_00366380(176.0f * (1.0f - t), 0x14F, 0x1D6, 0x7E, 0, 0xCC, 1, 0, 0, NULL, 0.0f, 0.0f, 1.0f + t, 0.3f - 0.2f * t);
        }
        font = func_002833b0(1);
        func_0027bf30_clear((u8 *)appear, sizeof(appear));
        today = (s16)func_001060b0();
        for (i = 0; i < 6; i++) {
            s32 step;

            if (*(s32 *)(arg1 + 0x10) >= appear[i]) {
                step = *(s32 *)(arg1 + 0x10) - appear[i];
                if (step >= 5) {
                    step = 5;
                }
            } else {
                step = 0;
            }
            fade = 1.0f - sinf(1.5707964f * (f32)step / 5.0f);
            date = today + i + 1;
            week = func_00110580(date);
            if (week == 0 || func_00110d30(date) != 0) {
                rgb = 0xFFE92C;
                mode = 3;
            } else if (week == 6) {
                rgb = 0xFFE92C;
                mode = 2;
            } else {
                rgb = 0xFFE92C;
                mode = 1;
            }
            func_001104d0(date, &month, &day);
            if (day == 1) {
                if (handle == NULL) {
                    func_0046d730(D_007482F0, 0x59);
                }
                func_0025ea20(i * 0x53 + 0x4B, 69.0f, 0.0f, rgb, 255.0f * fade, month + 4, **(void ***)(handle + 8), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
            rot = 1.0f - fade;
            t = 64.0f * rot;
            py = 113.0f + t;
            px = i * 0x53;
            func_00366380(px + 0x5C, py, 0x50, 0x7F, rgb, 0xFF, 1, 0, 0, NULL, 0.0f, 0.0f, 1.0f, fade);
            func_00262de0(px + 0x6B, py, 0.0f, 0xFF, today + i + 1, 1, 1.0f, fade, 0, 0, (s32)font, 0);
            py = 163.0f - 5.0f * rot;
            func_00261560(px + 0x5D, py, 0.0f, 0xFF, func_00110c50(today + i + 1, today) & 0xFFFF, 1, 1.0f, fade * fade, 0, 0, (s32)font, mode);
        }
        week = func_00110580(today + 3);
        if (week == 0 || func_00110d30(today + 3) != 0) {
            lineRgb = 0xFFE92C;
        } else if (week == 6) {
            lineRgb = 0xFFE92C;
        } else {
            lineRgb = 0xFFE92C;
        }
        frame = *(s32 *)(arg1 + 0x10);
        if (frame >= 2) {
            if (frame < 0) {
                t = sinf(1.5707964f * (f32)(frame - 1) / 4.0f);
                func_00366380(0x12C, 145.0f + 24.0f * t, 0x50, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 0.0f, 1.0f, 0.5f - 0.2f * t);
            } else if (frame < 8) {
                t = (f32)(frame - 2) / 5.0f;
                func_00366380(300.0f * (1.0f - t), 0xA9, 80.0f + 640.0f * t, 0x7F, lineRgb, 0xFF, 1, 0, 0, NULL, 0.0f, 0.0f, 1.0f, 0.3f - 0.2f * t);
            }
        }
        break;
    }
}
