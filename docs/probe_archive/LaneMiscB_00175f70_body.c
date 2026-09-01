/* Attempted C reconstruction for func_00175f70; not a confirmed MATCH (nd=431). Archived before restoring INCLUDE_ASM. */
s32 func_00175f70(u8 *arg0, s32 *arg1, f32 arg2, f32 arg3)
{
    u8 *work;
    s32 *src;
    s32 count;
    s32 i;
    s32 wrap;
    f32 first;
    f32 second;
    f32 diff;
    f32 other;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 0x40) == 1)
        return 0;
    src = arg1;
    count = 8;
    do {
        *(s32 *)(work + 0) = src[0];
        *(s32 *)(work + 4) = src[1];
        src += 2;
        work += 8;
        count -= 1;
    } while (count > 0);
    if (arg2 > 360.0f)
        arg2 -= 360.0f;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x4C) = arg2;
    if (arg3 > 360.0f)
        arg3 -= 360.0f;
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x50) = arg3;
    if (arg2 < arg3) {
        if (arg2 > fGpffff8558)
            arg2 = 0.0f;
        if (arg3 > fGpffff8558)
            arg3 = 360.0f;
        if (arg2 < fGpffff8214)
            arg2 = 0.0f;
        if (arg3 < fGpffff8214)
            arg3 = 360.0f;
        diff = arg3 - arg2;
        other = arg2 + (360.0f - arg3);
        wrap = 0;
    } else {
        if (arg2 > fGpffff8558)
            arg2 = 360.0f;
        if (arg3 > fGpffff8558)
            arg3 = 0.0f;
        if (arg2 < fGpffff8214)
            arg2 = 360.0f;
        if (arg3 < fGpffff8214)
            arg3 = 0.0f;
        diff = arg2 - arg3;
        other = arg3 + (360.0f - arg2);
        wrap = 1;
    }
    if (fabsf(diff) < fabsf(other)) {
        *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x54) = diff;
        if (wrap == 1)
            *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x54) *= -1.0f;
    } else {
        *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x54) = other;
        if (wrap == 0)
            *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x54) *= -1.0f;
    }
    first = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x54);
    if (fabsf(first) > 45.0f) {
        i = (s32)fabsf(first) / 30;
        if (i < 1)
            i = 1;
        *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x5C) = i;
        *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x58) = 0;
        *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x54) = first / (f32)i;
        *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x40) = 1;
        return 1;
    }
    return 0;
}
