/* Fresh complete reference; production remains ASM.
 * 864/848 bytes; all 24 relocations resolved; 203 executable words differ,
 * three retail zero-tail words differ, and four words overrun the window.
 * Actual callback context is the third argument. Owner contracts must use
 * void func_00252230(...) and a 32-bit func_0025f360 return; the former does
 * not return its preserved context register. Sp120 is the owner state type.
 * This is not a standalone translation unit.
 */
extern u8 D_006361F0[];

// FUN_00252710
s32 func_00252710(u8 *base, u8 *entry, u8 *context) {
    struct {
        s32 uv[8];
        f32 matrix[16];
        Sp120 state;
    } work;
    u8 *src;
    u8 *dst;
    s32 count;
    s32 first;
    s32 second;
    s32 finished;
    s32 special;
    s32 time;
    s32 sprite;
    s32 x;
    s32 y;
    s16 width;
    s16 height;
    u32 color;

    finished = 0;
    special = 0;
    if (*(s32 *)(context + 8) == 10) {
        special = 1;
    }
    if (!(*(u32 *)entry & 2)) {
        *(u32 *)(entry + 4) += 1;
    }
    time = *(s32 *)(entry + 4);
    if (time >= 60) {
        finished = 1;
    }
    if (time >= 31) {
        func_00252230(&work.state, (Sp120 *)(entry + 0x30),
                     (Sp120 *)(entry + 0x54), (f32)(time - 30) / 30.0f);
    } else {
        func_00252230(&work.state, (Sp120 *)(entry + 0xC),
                     (Sp120 *)(entry + 0x30), (f32)time / 30.0f);
    }
    if (special != 0) {
        if ((u32)work.state.f18 == 0xFFE92CFF) {
            *(s32 *)(entry + 0xC) = 0;
            work.state.f18 = -1;
        } else {
            work.state.f18 = 0xBFBFBFFF;
        }
    }
    src = D_006361F0;
    dst = (u8 *)work.uv;
    count = 4;
    do {
        first = *(s32 *)(src + 0);
        second = *(s32 *)(src + 4);
        src += 8;
        count--;
        *(s32 *)(dst + 0) = first;
        *(s32 *)(dst + 4) = second;
        dst += 8;
    } while (count > 0);
    sprite = func_0025f360(24, 0, *(s32 *)(context + 0x10));
    func_003e0870(work.matrix, &work.state.fC, work.state.f1C, 0);
    if (*(s32 *)(entry + 0xC) == 1) {
        D_00887300[0](7, 2);
        D_00887300[0](9, 2);
        D_00887300[0](6, 1);
        D_00887300[0](8, 1);
        D_00887300[0](12, 1);
        D_00887300[0](2, 4);
        D_00887300[0](14, 0);
        func_003f6440(3, 0x7000D);
        func_003f6440(2, 0x48);
        height = work.state.f22;
        width = work.state.f20;
        color = work.state.f18;
        x = (s32)work.state.f4;
        y = (s32)work.state.f8;
        func_00366c70(x, y, width, height, color >> 8, color & 0xFF,
                     0, (s16)(width >> 1), 0.0f, (s16)(height >> 1),
                     work.matrix, sprite, work.uv);
    } else {
        height = work.state.f22;
        width = work.state.f20;
        color = work.state.f18;
        x = (s32)work.state.f4;
        y = (s32)work.state.f8;
        func_00366c70(x, y, width, height, color >> 8, color & 0xFF,
                     1, (s16)(width >> 1), 0.0f, (s16)(height >> 1),
                     work.matrix, sprite, work.uv);
    }
    return finished;
}
