// FUN_00130680
void func_00130680(u8 *arg0, s32 arg1)
{
    typedef struct
    {
        s16 id;
        s16 pad2;
        s16 unk4;
        s16 highlight;
        s32 mode;
    } LabelParam;
    typedef struct
    {
        f32 x;
        f32 y;
        u8 pad8[2];
        u8 alpha;
        u8 padB[0x25];
    } LabelSlot;
    s32 id;
    s32 highlight;
    u8 *color0;
    u8 *color1;
    u8 *color2;
    u8 n;
    u8 alpha;
    f32 dim;
    f32 fade;
    f32 x;
    f32 y;
    f32 yoff;
    f32 ty;
    LabelParam param;
    Vec2f pos;

    id = ((s16 *)(arg0 + 0x34))[arg1];
    dim = 1.0f;
    highlight = 0;
    func_0011fd30((u8 *)&param);
    param.mode = 1;
    param.id = id;
    x = *(f32 *)(arg0 + 4);
    y = *(f32 *)(arg0 + 8);
    fade = (f32)*(u8 *)arg0 / 255.0f;
    if (((*(s32 *)(arg0 + 0x14) & 0x10) != 0 && *(s16 *)(arg0 + 0x26) == arg1) || (*(s32 *)(arg0 + 0x14) & 0x20) != 0) {
        highlight = 1;
        param.highlight = highlight;
        color0 = D_0064B2E8;
        color1 = D_0064B2EC;
        color2 = D_0064B2FC;
    } else {
        param.highlight = 0;
        color0 = D_0064B2E0;
        color1 = D_0064B2F0;
        color2 = D_0064B308;
        dim = fGpffff82cc;
    }
    pos.x = 67.0f + (x + ((LabelSlot *)(arg0 + 0x16D8))[arg1].x);
    yoff = 75.0f * (f32)arg1;
    ty = 24.0f + (y + ((LabelSlot *)(arg0 + 0x16D8))[arg1].y);
    pos.y = ty + yoff;
    ty = ((LabelSlot *)(arg0 + 0x16D8))[arg1].alpha;
    func_0011fd50(pos, 0.0f, (u8)(ty * fade), (u8 *)&param, 0);
    alpha = (f32)(arg0 + 0x1622)[arg1 * 0x30] * fade;
    pos.x = 60.0f + (x + *(f32 *)(arg0 + 0x1618 + arg1 * 0x30));
    ty = y + *(f32 *)(arg0 + 0x161C + arg1 * 0x30);
    pos.y = 21.0f + (ty + yoff);
    func_0034f2e0(*(void **)(arg0 + 0x1B90), pos.x, pos.y, color0[0], color0[1], color0[2], alpha);
    if (highlight != 0) {
        pos.x = 2.0f + (x + *(f32 *)(arg0 + 0x1618 + arg1 * 0x30));
        ty = y + *(f32 *)(arg0 + 0x161C + arg1 * 0x30);
        pos.y = 27.0f + (ty + yoff);
        func_0034f2e0(*(void **)(arg0 + 0x1B94), pos.x, pos.y, 0x4C, 0x4C, 0x4C, alpha);
    }
    n = func_00104c70(id);
    pos.x = 43.0f + (x + *(f32 *)(arg0 + 0x1618 + arg1 * 0x30));
    ty = y + *(f32 *)(arg0 + 0x161C + arg1 * 0x30);
    pos.y = 25.0f + (ty + yoff);
    if (n < 10) {
        pos.x -= 11.0f;
    }
    while (n > 0) {
        func_0034f2e0(*(void **)(arg0 + (n % 10) * 4 + 0x1BA4), pos.x, pos.y, color1[0], color1[1], color1[2], alpha);
        pos.x -= 22.0f;
        n /= 10;
    }
    pos.x = 37.0f + (x + *(f32 *)(arg0 + 0x1618 + arg1 * 0x30));
    ty = y + *(f32 *)(arg0 + 0x161C + arg1 * 0x30);
    pos.y = 53.0f + (ty + yoff);
    func_0034f2e0(*(void **)(arg0 + 0x1BE0), pos.x, pos.y, color2[0], color2[1], color2[2], (u8)((f32)alpha * dim));
}
