/* object 1564B / window 1728B / normalized_diff 1204; differing offsets: 0x0, 0x4, 0x8, 0xA, 0xC, 0xE, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1A, 0x1C and throughout; classification: residual in hundreds after corrected helper declarations; ruled out: direct u8* signature, block-scope canonical draw/interpolation helper declarations, state flags/counters, packed color setup, and icon loop; archived immediately per residual-hundreds rule. */
void func_00384cc0(u8 *arg0)
{
    extern void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3,
                               s8 arg4, s64 arg5, f32 fparg0, f32 fparg1);
    extern void func_00364c90(s64 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                              f32 fparg2, f32 fparg3, s32 arg2);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern u8 D_0064ECC0[];
    extern u8 D_0064EEB0[];
    u8 *state = arg0 + 0x24;
    u8 *base = *(u8 **)arg0;
    u8 *entry;
    f32 point[2];
    f32 progress;
    f32 color_f;
    u16 flags;
    u16 counter;
    u8 color_a;
    u8 color_b;
    u8 color_c;
    u32 color;
    u32 mask;
    s32 i;
    s32 index;

    if (*(s32 *)(base + 0x1F2FC) != 4)
        func_0046d730(D_0064EEB0, 459);
    flags = *(u16 *)state;
    color_a = color_b = color_c = 0;
    if ((flags & 1) == 0) {
        progress = (f32)(u16)*(u16 *)(state + 2);
        color_a = (u8)(255.0f * func_00373cb0(progress, 0.0f, 10.0f, 1));
        color_b = 0;
        color_f = (f32)(u16)*(u16 *)(state + 2);
        counter = ++*(u16 *)(state + 2);
        if (counter >= 5) { *(u16 *)state |= 3; *(u16 *)(state + 2) = 0; }
    } else if (flags & 2) {
        progress = (f32)(u16)*(u16 *)(state + 2);
        color_b = (u8)(255.0f * func_00373cb0(progress, 0.0f, 3.0f, 1));
        color_a = 0xFF;
        color_f = 1.0f - func_00373cb0(progress, 10.0f, 20.0f, 1);
        counter = ++*(u16 *)(state + 2);
        if (counter >= 10) { *(u16 *)state &= 0xFFFD; *(u16 *)(state + 2) = 0; }
    } else if (flags & 4) {
        progress = (f32)(u16)*(u16 *)(state + 2);
        color_a = (u8)(255.0f * (1.0f - func_00373cb0(progress, 0.0f, 10.0f, 1)));
        color_b = color_a; color_c = color_a;
        counter = ++*(u16 *)(state + 2);
        if (counter >= 10) { *(u16 *)(arg0 + 0x4C) &= 0xFFBF; *(u16 *)(state + 2) = 0; }
    } else {
        color_a = 0xFF; color_b = 0xFF; color_c = 0;
    }
    color = ((u32)color_a & 0xFF) | 0x3767FF00;
    func_003f6440(3, 0x71801); func_003f6440(2, 0x48);
    point[0] = 314.0f; point[1] = 237.0f; mask = 0;
    if (*(u16 *)(base + 0x1F1D0) & 0x20) {
        if (color_a) func_00364c90(*(s64 *)point, color, 0.0f, 403.0f, 2.0f, 0.0f, 1);
        mask = 0x1F;
    }
    point[0] = 314.0f; point[1] = 236.0f;
    if (*(u16 *)(base + 0x1F1D0) & 0x10) {
        if (color_a) func_00364c90(*(s64 *)point, color, 0.0f, 485.0f, 2.0f, *(f32 *)(base + 0x1F2B0), 1);
        mask |= 0x1E1;
    }
    point[0] = 316.0f; point[1] = 236.0f;
    if (*(u16 *)(base + 0x1F1D0) & 0x40) {
        if (color_a) func_00364c90(*(s64 *)point, color, 0.0f, 485.0f, 2.0f, *(f32 *)(base + 0x1F2B4), 1);
        mask |= 0x1E01;
    }
    for (i = 0; i < 13; i++) if (mask & (1 << i)) {
        entry = D_0064ECC0 + i * 8;
        index = *(s32 *)entry; progress = *(f32 *)(entry + 4);
        func_0034f460(*(s32 *)(base + 0x1F2AC), 55, 255, 255, 255, color_b, (f32)index, progress);
        if (color_c) func_0034f460(*(s32 *)(base + 0x1F2AC), 55, 255, 255, 255, color_c, (f32)index, progress);
    }
    func_003f6440(3, 0x717FB); func_003f6440(2, 0x44);
}
