// FUN_00222210
typedef struct { f32 x, y; } Vec2f_2210;
typedef struct { u8 r, g, b, a; } Rgba_2210;
extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);

#pragma push
#pragma opt_loop_invariants on
static inline void func_00222210_logo(u8 *work, Vec2f_2210 offset, Rgba_2210 color, Vec2f_2210 origin)
{
    s32 res = *(s32 *)(work + 0x50);
    Vec2f_2210 pos;
    f32 x;

    pos.x = offset.x + origin.x;
    pos.y = offset.y + origin.y;
    func_0034f4a0(*(s32 *)(work + 0x54), 0x1D, pos.x, pos.y, 0.0f, color.r, color.g, color.b, color.a, 0x1000, 0x1000, 37.0f, (s16)(origin.x - pos.x), (s16)(origin.y - pos.y));
    x = (207.0f + pos.x) - 6.0f;
    func_0034f4a0(res, 0xB2, x, pos.y, 0.0f, color.r, color.g, color.b, color.a, 0x1000, 0x1000, 37.0f, (s16)(origin.x - x), (s16)(origin.y - pos.y));
    x = (300.0f + pos.x) - 6.0f;
    func_0034f4a0(res, 0xB3, x, pos.y, 0.0f, color.r, color.g, color.b, color.a, 0x1000, 0x1000, 37.0f, (s16)(origin.x - x), (s16)(origin.y - pos.y));
    x = (314.0f + pos.x) - 6.0f;
    func_0034f4a0(res, 0xB3, x, pos.y, 0.0f, color.r, color.g, color.b, color.a, 0x1000, 0x1000, 37.0f, (s16)(origin.x - x), (s16)(origin.y - pos.y));
}

void func_00222210(u8 *work, u32 alpha)
{
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void func_00364c50(void);
    extern void func_00364c70(void);
    extern void func_0045dfd0(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4);
    f32 fade0;
    f32 fade1;
    f32 fade2;
    f32 fade3;
    f32 scroll;
    Vec2f_2210 ofs;
    Vec2f_2210 pos;
    Rgba_2210 color;
    u8 colors[3][4];
    f32 coords[3][2];
    s32 i;
    s32 j;
    s32 k;

    if ((*(u16 *)work & 8) == 0) {
        fade0 = 1.0f - func_00373cb0((f32)*(u16 *)(work + 0x46), 0.0f, 6.0f, 1);
        fade1 = 1.0f - func_00373cb0((f32)*(u16 *)(work + 0x46), 0.0f, 6.0f, 1);
        fade2 = 1.0f - func_00373cb0((f32)*(u16 *)(work + 0x46), 7.0f, 17.0f, 1);
        fade3 = 1.0f - func_00373cb0((f32)*(u16 *)(work + 0x46), 13.0f, 25.0f, 1);
        if (*(u16 *)(work + 0x46) >= 7) {
            if (++*(u16 *)(work + 0x48) >= 40) {
                *(u16 *)(work + 0x48) = 0;
            }
            scroll = func_00373cb0((f32)*(u16 *)(work + 0x48), 0.0f, 40.0f, 0);
        }
    } else {
        fade0 = 0.0f;
        fade1 = fade0;
        fade2 = fade0;
        fade3 = fade0;
        if (++*(u16 *)(work + 0x48) >= 40) {
            *(u16 *)(work + 0x48) = 0;
        }
        scroll = func_00373cb0((f32)*(u16 *)(work + 0x48), 0.0f, 40.0f, 0);
    }
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);

    ofs.x = 0.0f + (f32)265 + (f32)375 * fade1;
    ofs.y = 0.0f;
    coords[0][0] = ofs.x;
    coords[0][1] = ofs.y;
    coords[1][0] = (f32)375 + ofs.x;
    coords[1][1] = ofs.y;
    coords[2][0] = (f32)375 + ofs.x;
    coords[2][1] = (f32)281 + ofs.y;
    for (j = 0; j < 3; j++) {
        u8 *p = colors[j];
        p[0] = 0xFF;
        p[1] = 0xFF;
        p[2] = 0xFF;
        p[3] = alpha;
    }
    func_00364c50();
    func_0045dfd0((u8 *)colors, (u8 *)coords, 0.0f, 3, 5, 0);
    func_00364c70();

    ofs.x = 0.0f + 348.0f + 292.0f * fade0;
    ofs.y = 0.0f;
    coords[0][0] = ofs.x;
    coords[0][1] = ofs.y;
    coords[1][0] = 292.0f + ofs.x;
    coords[1][1] = ofs.y;
    coords[2][0] = 292.0f + ofs.x;
    coords[2][1] = 220.0f + ofs.y;
    for (k = 0; k < 3; k++) {
        u8 *p = colors[k];
        p[0] = 0xED;
        p[1] = 0x36;
        p[2] = 0x11;
        p[3] = alpha;
    }
    func_00364c50();
    func_0045dfd0((u8 *)colors, (u8 *)coords, 0.0f, 3, 5, 0);
    func_00364c70();

    pos.x = (0.0f + 220.0f + 562.5f * fade2) - 9.0f;
    pos.y = 0.0f + -94.0f + 421.5f * fade2;
    ofs.x = -(394.0f * scroll);
    ofs.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xD4;
    color.b = 0x00;
    color.a = alpha;
    for (i = 0; i < 3; i++) {
        func_00222210_logo(work, ofs, color, pos);
        ofs.x += 394.0f;
    }

    pos.x = 1.0f + (0.0f + (f32)389 + 562.5f * fade3);
    pos.y = (0.0f + -5.0f + 421.5f * fade3) - 1.0f;
    ofs.x = 0.0f;
    ofs.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xFF;
    color.b = 0xFF;
    color.a = alpha;
    func_00222210_logo(work, ofs, color, pos);
}
#pragma pop
