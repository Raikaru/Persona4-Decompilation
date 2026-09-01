/* Archived nonmatching candidate for func_001d4eb0.
 * Tried consolidated Frame locals and C floor/interpolation expressions;
 * scoped lverify measured object 664B vs retail 640B, normalized_diff 364.
 */
void func_001d4eb0(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3)
{
    struct Frame {
        f32 value60;
        f32 value64;
        f32 value68;
        f32 pad6c;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 pad7c;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 pad8c;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 pad9c;
    } frame;
    u8 *temp_16;
    u8 *temp_2;
    u16 temp_4;
    f32 temp_f1;
    f32 temp_f20;

    temp_16 = arg2 + 8;
    if ((*(u8 *)(arg2 + 0xA) == 1) &&
        (*(s32 *)(arg2 + 0x10) + 2 != *(s32 *)(arg0 + 0xC)))
    {
        arg3[0] = *(f32 *)(arg0 + 0x5C);
        arg3[1] = *(f32 *)(arg0 + 0x60);
        arg3[2] = *(f32 *)(arg0 + 0x64);
        return;
    }

    if ((*(s32 *)(arg1 + 0x98) & 2) == 0)
    {
        func_00195850(arg1, &frame.value90);
    }
    else if (func_0047a6d0(*(u8 **)(arg1 + 0xA00),
                           *(u16 *)(temp_16 + 4),
                           &frame.value90) == 0)
    {
        temp_f1 = (f32)(s32)*(f32 *)(arg0 + 0x50);
        frame.value70 = (f32)(s32)(*(f32 *)(arg0 + 0x20) * temp_f1);
        frame.value74 = (f32)(s32)(*(f32 *)(arg0 + 0x24) * temp_f1);
        frame.value78 = (f32)(s32)(*(f32 *)(arg0 + 0x28) * temp_f1);
        func_003dcb40(&frame.value60, &frame.value70, 1, arg0 + 0x40);
        frame.value90 = (f32)(s32)(frame.value60 + *(f32 *)(arg0 + 0x34));
        frame.value94 = (f32)(s32)(frame.value64 + *(f32 *)(arg0 + 0x38));
        frame.value98 = (f32)(s32)(frame.value68 + *(f32 *)(arg0 + 0x3C));
    }

    arg3[0] = frame.value90;
    arg3[1] = frame.value94;
    arg3[2] = frame.value98;
    temp_4 = *(u16 *)(temp_16 + 6);
    if (temp_4 != 0)
    {
        temp_f20 = (f32)(s32)temp_4;
        temp_2 = *(u8 **)(func_00457120(temp_4) + 4);
        frame.value80 = (f32)(s32)(*(f32 *)(temp_2 + 0x40) - frame.value90);
        frame.value84 = (f32)(s32)(*(f32 *)(temp_2 + 0x44) - frame.value94);
        frame.value88 = (f32)(s32)(*(f32 *)(temp_2 + 0x48) - frame.value98);
        func_003e40b0(&frame.value80, &frame.value80);
        arg3[0] = arg3[0] - frame.value80 * temp_f20;
        arg3[1] = arg3[1] - frame.value84 * temp_f20;
        arg3[2] = arg3[2] - frame.value88 * temp_f20;
    }

    if ((*(u8 *)(temp_16 + 2) == 1) &&
        (*(s32 *)(arg2 + 0x10) + 2 == *(s32 *)(arg0 + 0xC)))
    {
        *(f32 *)(arg0 + 0x5C) = arg3[0];
        *(f32 *)(arg0 + 0x60) = arg3[1];
        *(f32 *)(arg0 + 0x64) = arg3[2];
    }
}
