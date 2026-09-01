/* object 1264B / window 1264B / normalized_diff 872; differing offsets: 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2A, 0x2C, 0x2E, 0x30, 0x32, 0x34, 0x36 and throughout; classification: residual in hundreds after corrected helper declarations; ruled out: 5-argument state signature, block-scope func_00364c90/func_00373cb0/fGpffff83b8/D_0064F090 declarations, unsigned-float conversion casts, five-entry loops, and packed point call shape; archived immediately per residual-hundreds rule. */
void func_0038acd0(u8 *arg0)
{
    extern void func_00364c90(s64 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                               f32 fparg2, f32 fparg3, s32 arg2);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern f32 fGpffff83b8;
    extern u8 D_0064F090[];
    f32 factors[5];
    f32 point[2];
    u8 *state;
    u8 *entry;
    u16 flags;
    u16 counter;
    s32 type;
    s32 span;
    s32 i;
    f32 progress;
    f32 scale;
    f32 lower;
    f32 upper;

    state = arg0 + 0x1B4;
    type = *(s32 *)(*(u8 **)arg0 + 0x1F2FC);
    span = 0;
    lower = 0.0f;
    upper = 0.0f;
    switch (type) {
    case 3:
        span = 20;
        lower = 196.0f;
        upper = 320.0f;
        break;
    case 4:
        span = 20;
        lower = 185.0f;
        upper = fGpffff83b8;
        break;
    }
    flags = *(u16 *)(state + 2);
    if ((flags & 1) == 0) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            progress = (f32)(u16)*(u16 *)state;
            scale = (f32)span;
            factors[i] = func_00373cb0(
                progress, scale * *(f32 *)(entry + 8),
                scale * *(f32 *)(entry + 0xC), 1);
        }
        progress = (f32)(u16)*(u16 *)state;
        scale = (f32)span;
        lower = func_00373cb0(progress, 0.25f * scale, scale, 1);
        counter = ++*(u16 *)state;
        if (counter >= span) {
            *(u16 *)(state + 2) |= 1;
            *(u16 *)state = 0;
        }
    } else if (flags & 2) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            progress = (f32)(u16)*(u16 *)state;
            scale = (f32)span;
            factors[i] = 1.0f - func_00373cb0(
                progress, scale * *(f32 *)(entry + 8),
                scale * *(f32 *)(entry + 0xC), 1);
        }
        progress = (f32)(u16)*(u16 *)state;
        scale = (f32)span;
        lower = 1.0f - func_00373cb0(progress, 0.25f * scale, scale, 1);
        counter = ++*(u16 *)state;
        if (counter >= span) {
            *(u16 *)arg0 &= 0xFFDF;
        }
    } else {
        for (i = 0; i < 5; i++) {
            factors[i] = 1.0f;
        }
        lower = 1.0f;
    }
    func_003f6440(3, 0x71801);
    func_003f6440(2, 0x48);
    point[1] = 224.0f;
    for (i = 0; i < 5; i++) {
        progress = factors[i];
        entry = D_0064F090 + i * 0x10;
        scale = *(f32 *)(entry + 4) * progress;
        point[0] = upper + ((lower / 2.0f) + *(f32 *)entry) * progress;
        func_00364c90(*(s64 *)point, 0xFF403DFF, 0.0f, 0.0f,
                      scale, 224.0f, 0);
        point[0] = upper - ((lower / 2.0f) + *(f32 *)entry) * progress;
        func_00364c90(*(s64 *)point, 0xFF403DFF, 0.0f, 0.0f,
                      scale, 224.0f, 0);
    }
    point[0] = upper;
    func_00364c90(*(s64 *)point, 0xFF403DFF, 0.0f, 0.0f,
                  lower * *(f32 *)&factors[0], 224.0f, 0);
    func_003f6440(3, 0x717FB);
    func_003f6440(2, 0x44);
}
