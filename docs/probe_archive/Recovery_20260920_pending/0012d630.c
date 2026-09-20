s32 func_0012d630(u8 *arg0)
{
    typedef struct {
        u8 alpha;
        u8 pad01[0xB];
        u16 tally;
        u8 padE[0x30 - 0xE];
    } Rec0012d630;
    typedef struct {
        f32 x;
        f32 y;
    } Vec2f_0012d630;
    extern s32 func_0012e1d0(u8 *arg0);
    extern void func_0034f1e0(void);
    extern void func_0034f320(u8 *arg0, f32 farg0, f32 farg1, f32 farg2,
                              u8 arg1, u8 arg2, u8 arg3, u32 arg4, u16 arg5,
                              u16 arg6, s16 arg7, f32 farg3, s16 arg_sp0);
    extern void func_00364320(Vec2f_0012d630 pos, f32 z, s32 color, s32 num);
    extern void func_0034f9d0(Vec2f_0012d630 pos, f32 z, u32 arg1, s32 arg2, s32 arg3);
    Vec2f_0012d630 pos;
    Vec2f_0012d630 pos2;
    s32 result;
    u8 *p;
    s32 i;
    s32 count;
    s32 sel;
    s32 j;
    f32 x;
    f32 y;
    f32 labelY;

    result = 1;
    p = arg0;
    switch (*(s32 *)(p + 0x18)) {
    case 0:
        if (1) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 0);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    case 1:
        if (0) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 0);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    case 2:
        if (1) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 2);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    case 3:
        if (0) {
            if (func_0012e1d0(p) != 0) {
                func_0012dea0(p, 1);
                break;
            }
        }
        if (*(s16 *)(p + 0xC) < 100) {
            *(s16 *)(p + 0xC) = *(s16 *)(p + 0xC) + 1;
        }
        for (i = 0; i < 0xB; i++) {
            u8 *q = p + i * 0x30;
            func_001437b0(q + 0x94, *(s16 *)(p + 0xC), 0);
            if (*(u8 *)(q + 0xAE) != 0) {
                result = 0;
            }
        }
        break;
    }
    func_0034f1e0();
    sel = *(s32 *)(p + 0x10);
    count = *(s32 *)(p + 0x38);
    for (j = 0; j < count; j++) {
        u8 *q = p + j * 0x30;
        s32 idx;
        u8 *sprite;
        u32 alpha;

        x = *(f32 *)(p + 4) + 173.0f + *(f32 *)(q + 0xA4);
        pos.x = x;
        y = *(f32 *)(p + 8) + 52.0f + *(f32 *)(q + 0xA8) + (f32)(j * 0x16);
        pos.y = y;
        alpha = *(u8 *)(q + 0xAE);
        idx = *(s32 *)(p + j * 4 + 0x1C);
        if (j == sel) {
            pos.x += 2.0f;
            pos.y += 11.0f;
            sprite = *(u8 **)(p + idx * 4 + 0x58);
        } else {
            pos.x += 1.0f;
            if (sel < j) {
                pos.y += 45.0f;
            }
            sprite = *(u8 **)(p + idx * 4 + 0x3C);
        }
        func_0034f320(sprite, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF,
                      alpha, 0x1000, *(u16 *)(q + 0xBA), 0,
                      0.0f, 0);
    }
    pos.x = *(f32 *)(p + 4) + 173.0f + *(f32 *)(p + 0x1F4) + 3.0f;
    pos.y = *(f32 *)(p + 8) + 52.0f + *(f32 *)(p + 0x1F8) + 311.0f;
    func_0034f320(((u8 **)(p + 0x74))[*(s32 *)(p + *(s32 *)(p + 0x10) * 4 + 0x1C)],
                  pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF,
                  ((Rec0012d630 *)(p + 0xAE))[j].alpha, 0x1000,
                  ((Rec0012d630 *)(p + 0xAE))[j].tally, 0, 0.0f, 0);
    pos.x = *(f32 *)(p + 0x224) + 18.0f;
    labelY = (f32)0x17D;
    labelY += *(f32 *)(p + 0x228);
    pos.y = labelY;
    func_00364320(pos, 0.0f, *(u8 *)(p + 0x22E), -1);
    pos2.x = *(f32 *)(p + 0x254) + 640.0f;
    pos2.y = *(f32 *)(p + 0x258) + 400.0f;
    func_0034f9d0(pos2, 0.0f, *(u8 *)(p + 0x25E), 0, *(s32 *)(p + 0x90));
    return result;
}
