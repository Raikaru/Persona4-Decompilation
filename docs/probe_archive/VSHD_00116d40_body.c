/* object 1112B; retail window 1152B; normalized_diff 274; differing offsets 0x000-0x0AC, 0x0B8, 0x0C0-0x0E0, 0x0EC-0x1EC, 0x1F4-0x238, 0x240-0x278, 0x280-0x2B0, 0x2B8-0x32C, 0x334-0x338, 0x340-0x358, 0x360-0x3A4, 0x3AC-0x41C, 0x424-0x470; int-to-float casts: retail 0x88 signed halfword `(f32)(s16)arg4`, retail 0xDC unsigned-byte/raw integer `(f32)(u32)arg1`; residual is hundreds across prologue, calls, and FP/register materialisation; corrected target declaration and callee declarations, ruled out further levers because automatic archive threshold was reached. */
void func_00116d40(I64 arg0, s32 arg1, u8 arg2, u8 arg3, s16 arg4, s32 arg5, f32 fparg0)
{
    f32 sp98[2];
    u8 colors[8];
    s32 spA0[4];
    f32 high;
    f32 rate;
    f32 value;
    s32 temp;
    s32 shade0;
    s32 shade2;

    *(I64 *)sp98 = arg0;
    if ((arg3 & 0xFF) > 0) {
        temp = ((arg2 & 0xFF) - (arg3 & 0xFF)) & 0xFF;
        colors[4] = 0x2D;
        colors[5] = 0x2D;
        colors[6] = 0x2D;
        colors[7] = (u8)arg1;
        shade0 = 140;
        shade2 = shade0;
        colors[0] = 0xFF;
        colors[1] = 0xFF;
        colors[2] = 0xFF;
        rate = (3.0f + func_0044b610((iGpffff82fc * (f32)(s16)arg4) / 30.0f)) / 4.0f;
        value = (f32)(u32)arg1;
        value *= rate;
        colors[3] = (u8)value;
    } else {
        colors[4] = 0xFF;
        colors[5] = 0xA0;
        colors[6] = 0x0B;
        colors[7] = (u8)arg1;
        shade0 = 255;
        shade2 = 129;
        colors[0] = 0xFF;
        colors[1] = 0xFF;
        colors[2] = 0x81;
        colors[3] = (u8)arg1;
        temp = arg2 & 0xFF;
    }
    high = sp98[1];
    func_0046d4c0(0, arg5, 0x3D, sp98[0], high, (0xFF - colors[3]) & 0xFF, colors[4], colors[5], colors[6], fparg0, 0);
    func_0046d4c0(0, arg5, 0x3E, 214.0f + sp98[0], high, (0xFF - colors[3]) & 0xFF, colors[4], colors[5], colors[6], fparg0, 0);
    func_0046d4c0(0, arg5, 0x3F, sp98[0], high, (0xFF - ((u8)arg1 & 0xFF)) & 0xFF, shade0, shade0, shade2, fparg0, 0);
    temp = (((temp & 0xFF) * 0xCC) / 99) + 0xA;
    sp98[0] += (f32)temp;
    spA0[0] = (s32)sp98[0];
    spA0[1] = (s32)(4.0f + high);
    spA0[2] = 214 - temp;
    spA0[3] = 9;
    D_00887300[0](1, 0);
    func_0045d6e0(&colors[4], spA0, 0, fparg0);
    if ((arg3 & 0xFF) > 0) {
        spA0[0] = (s32)sp98[0];
        spA0[1] = (s32)(5.0f + high);
        spA0[2] = spA0[1];
        spA0[3] = 7;
        D_00887300[0](1, 0);
        func_0045d6e0(&colors[0], spA0, 0, fparg0);
        sp98[0] += (f32)(((arg3 & 0xFF) * 0xCC) / 99);
    }
    func_0046d4c0(0, arg5, 0x40, sp98[0], high, (0xFF - colors[3]) & 0xFF, colors[0], colors[1], colors[2], fparg0, 0);
}
