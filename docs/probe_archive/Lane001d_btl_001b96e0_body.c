/* Archived nonmatching candidate for func_001b96e0.
 * Tried BtlMainColorLerpWork plus volatile RwV4d temporaries; scoped lverify
 * measured object 680B vs retail 704B, normalized_diff 377.
 */
u32 func_001b96e0(void* work)
{
    BtlMainColorLerpWork* param_1 = (BtlMainColorLerpWork*)work;
    volatile RwV4d colors;
    RwV4d results;
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    u32 totalFrames;
    u32 currentFrame;
    u32 byte;
    f32 value;

    if (param_1->currentFrame == 0)
    {
        *(RwV4d*)&param_1->value0 = *(RwV4d*)(iGpffffb3ac + 0x25c);
    }

    byte = *(u8 *)((u8 *)&iGpffffb450 + 0xC);
    if (byte >= 0)
        value = (f32)byte;
    else
    {
        byte = (byte >> 1) | (byte & 1);
        value = (f32)byte;
        value += value;
    }
    colors.x = fGpffff81f4 * value;

    byte = *(u8 *)((u8 *)&iGpffffb450 + 0xD);
    if (byte >= 0)
        value = (f32)byte;
    else
    {
        byte = (byte >> 1) | (byte & 1);
        value = (f32)byte;
        value += value;
    }
    colors.y = fGpffff81f4 * value;

    byte = *(u8 *)((u8 *)&iGpffffb450 + 0xE);
    if (byte >= 0)
        value = (f32)byte;
    else
    {
        byte = (byte >> 1) | (byte & 1);
        value = (f32)byte;
        value += value;
    }
    colors.z = fGpffff81f4 * value;

    byte = *(u8 *)((u8 *)&iGpffffb450 + 0xF);
    if (byte >= 0)
        value = (f32)byte;
    else
    {
        byte = (byte >> 1) | (byte & 1);
        value = (f32)byte;
        value += value;
    }
    colors.w = fGpffff81f4 * value;

    totalFrames = param_1->totalFrames;
    currentFrame = param_1->currentFrame;
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results.x = colors.x * ratio + param_1->value0 * inverse;
        results.y = colors.y * ratio + param_1->value1 * inverse;
        results.z = colors.z * ratio + param_1->value2 * inverse;
        results.w = colors.w * ratio + param_1->value3 * inverse;
        *(RwV4d*)(iGpffffb3ac + 0x25c) = results;
        param_1->currentFrame++;
        return 0;
    }

    *(RwV4d*)(iGpffffb3ac + 0x25c) = colors;
    return 1;
}
