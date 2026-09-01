/* object 1504B / window 1648B / normalized_diff 1149; differing offsets: 0x0, 0x4, 0x8, 0xA, 0xC, 0xE, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1A, 0x1B, 0x1C and throughout; classification: residual in hundreds after corrected helper declarations; ruled out: direct u8* signature, block-scope canonical draw helper declarations, state offset map, unsigned float/byte casts, and all four flag branches; archived immediately per residual-hundreds rule. */
void func_0038c100(u8 *arg0)
{
    extern void func_0034f460(s32 arg0, s32 arg1, s8 arg2, s8 arg3,
                               s8 arg4, s64 arg5, f32 fparg0, f32 fparg1);
    extern void func_0034f4a0(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                               f32 fparg2, s8 arg2, s8 arg3, s8 arg4,
                               s64 arg5, s64 arg6, s32 arg7, f32 fparg3,
                               s16 arg_sp0, s16 arg_sp8);
    extern f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_0046d730(void *arg0, s32 arg1);
    extern u8 D_0064F0E0[];
    u8 *state;
    u8 *data;
    s32 base;
    u16 flags;
    u16 counter;
    u16 item;
    u8 color;
    f32 progress;
    f32 fade;
    f32 factor;
    u16 width;
    u16 height;
    s32 i;

    state = arg0 + 0x1A4;
    base = *(s32 *)(*(u8 **)arg0 + 0x1F2AC);
    data = *(u8 **)arg0 + 0x1F1D0;
    if (*(s32 *)(*(u8 **)arg0 + 0x1F2FC) != 3) {
        func_0046d730(D_0064F0E0, 1101);
    }
    flags = *(u16 *)(state + 2);
    if ((flags & 1) == 0) {
        progress = (f32)(u16)*(u16 *)state;
        factor = func_00373cb0(0.0f, progress, 4.0f, 8);
        progress = (f32)(u16)*(u16 *)state;
        color = (u8)(255.0f * func_00373cb0(1.0f, progress, 0.0f, 8));
        fade = factor;
        counter = ++*(u16 *)state;
        if (counter >= 8) {
            *(u16 *)(state + 2) |= 1;
            *(u16 *)state = 0;
        }
    } else if (flags & 2) {
        fade = 1.0f;
        progress = (f32)(u16)*(u16 *)state;
        color = (u8)(255.0f *
                     (1.0f - func_00373cb0(1.0f, progress, 0.0f, 5)));
        counter = ++*(u16 *)state;
        if (counter >= 5) {
            *(u16 *)arg0 &= 0xFFFD;
        }
    } else if (flags & 4) {
        progress = (f32)(u16)*(u16 *)state;
        factor = func_00373cb0(0.0f, progress, 4.0f, 8);
        progress = (f32)(u16)*(u16 *)state;
        fade = 1.0f + factor -
               func_00373cb0(0.0f, progress, 0.0f, 4);
        color = 0xFF;
        counter = ++*(u16 *)state;
        if (counter >= 8) {
            *(u16 *)(state + 2) &= 0xFFFB;
            *(u16 *)state = 0;
        } else if (counter == 4) {
            *(u16 *)(state + 4) = *(u16 *)(data + 8);
        }
    } else {
        fade = 1.0f;
        color = 0xFF;
        if (*(u16 *)(data + 8) != *(u16 *)(state + 4)) {
            *(u16 *)(state + 2) = flags | 4;
        }
    }
    func_0034f460(base, 43, 142, 49, 0, color, 578.0f, 417.0f);
    func_0034f460(base, 42, 142, 49, 0, color, 543.0f, 408.0f);
    item = *(u16 *)(data + 0xA);
    func_0034f460(base, item + 31, 142, 49, 0, color, 559.0f, 414.0f);
    width = (u16)(4096.0f * fade);
    height = (u16)4096.0f;
    i = (item + 45) - *(u16 *)(state + 4);
    func_0034f4a0(base, i, 515.0f + ((1.0f - fade) * 29.0f) / 2.0f,
                  407.0f, 0.0f, 0, 0, 0, color, width, height,
                  0.0f, 0, 0);
}
