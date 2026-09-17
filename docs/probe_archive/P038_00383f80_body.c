/* 727 differing words over 145 edit instructions, 785 emitted (3140B) against retail 846 (3392B window), from a first reconstruction. arg0 is u8 * (m2c u8 ** scales arg0+0x20 by four); window scales f20 (animation) and f21 (1/div) both live, unlike func_0038c100 scaleY literal. Sibling func_0038cab0 Vertex_0038CAB0 work[4] gives 0x1A0 frame (scalar locals: 266 emitted, 0x90 frame, dead stores). D_00887310 3-arg; unsigned-to-float (f32)(u32) exact; (f32)0x1D9 for 473.0f. WALL: redundant second andi (8 sites), sh/andi order (2), $at-vs-$v0 clamp, $s1/$s2/$s3 colour. See owner note above // FUN_00383F80 for full residual. */
void func_00383f80(u8 *arg0)
{
    extern f32 func_00373cb0(f32 t, f32 a, f32 b, s32 mode);
    extern s32 func_00378530(s32 a, s32 b);
    extern void func_00377930(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern u8 *func_00457120(void);
    extern f32 D_008872F8[];
    extern s32 (*D_00887310[])(s32, void *, s32);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        f32 color[4];
        u32 tail[4];
    } Vertex;
    u8 *ctx;
    u8 *state;
    u8 *info;
    u8 colors[4];
    Vertex work[4];
    f32 f22;
    f32 f21;
    f32 scale;
    s32 alpha;
    s32 var17;
    s32 count;
    s32 tmp;
    s32 i;
    s32 lo;
    s32 hi;
    u16 flags;
    u16 v18;

    state = arg0 + 0x20;
    ctx = *(u8 **)arg0;
    info = ctx + 0x1F1D0;
    flags = *(u16 *)state;
    if (!(flags & 1)) {
        scale = func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        alpha = (u8)(u32)(255.0f * scale);
        *(u16 *)(state + 2) = *(u16 *)(state + 2) + 1;
        if ((*(u16 *)(state + 2) & 0xFFFF) >= 0xA) {
            *(u16 *)state = *(u16 *)state | 1;
            *(u16 *)(state + 2) = 0;
        }
    } else if (flags & 2) {
        scale = 1.0f - func_00373cb0((f32)(u32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        alpha = (u8)(u32)(255.0f * scale);
        *(u16 *)(state + 2) = *(u16 *)(state + 2) + 1;
        if ((*(u16 *)(state + 2) & 0xFFFF) >= 0xA) {
            *(u16 *)(arg0 + 0x4C) = *(u16 *)(arg0 + 0x4C) & 0xFFDF;
        }
    } else {
        scale = 1.0f;
        alpha = 0xFF;
    }
    v18 = *(u16 *)(info + 4);
    if ((s32)v18 < 3) {
    } else {
        v18 = 2;
    }
    tmp = *(s32 *)(ctx + 0x1F304);
    if (tmp < 6) {
        var17 = tmp * 2;
    } else {
        var17 = tmp;
    }
    count = func_00378530(tmp, *(s32 *)(ctx + 0x1F2FC));
    f22 = D_008872F8[0];
    f21 = 1.0f / *(f32 *)(func_00457120() + 0x80);
    colors[0] = 0x5F;
    colors[1] = 0x31;
    colors[2] = 0;
    colors[3] = (u8)(((alpha & 0xFF) * 0xC0) / 255);
    lo = var17 * (v18 + 1);
    hi = count;
    for (i = lo; i < hi; i++) {
        func_00377930(ctx, i, 0, colors, 0);
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    colors[0] = 0x50;
    colors[1] = 0x4B;
    colors[2] = 0x3C;
    colors[3] = (u8)(((alpha & 0xFF) << 7) / 255);
    lo = var17 * v18;
    hi = var17 * (v18 + 1);
    for (i = lo; i < hi; i++) {
        func_00377930(ctx, i, 0, colors, 0);
    }
    colors[0] = 0xFF;
    colors[1] = 0xC5;
    colors[2] = 0x50;
    work[0].x = 156.0f;
    work[0].y = 0.0f;
    work[0].z = f22;
    work[0].scale = f21;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    work[1].x = (f32)0x1D9;
    work[1].y = 0.0f;
    work[1].z = f22;
    work[1].scale = f21;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    work[2].x = 156.0f;
    work[2].y = 84.0f;
    work[2].z = f22;
    work[2].scale = f21;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = 0.0f;
    work[3].x = (f32)0x1D9;
    work[3].y = 84.0f;
    work[3].z = f22;
    work[3].scale = f21;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = 0.0f;
    D_00887310[0](4, work, 4);
    work[0].x = 156.0f;
    work[0].y = 364.0f;
    work[0].z = f22;
    work[0].scale = f21;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = 0.0f;
    work[1].x = (f32)0x1D9;
    work[1].y = 364.0f;
    work[1].z = f22;
    work[1].scale = f21;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = 0.0f;
    work[2].x = 156.0f;
    work[2].y = 448.0f;
    work[2].z = f22;
    work[2].scale = f21;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    work[3].x = (f32)0x1D9;
    work[3].y = 448.0f;
    work[3].z = f22;
    work[3].scale = f21;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = (f32)(u32)(u8)(u32)(192.0f * scale);
    D_00887310[0](4, work, 4);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
