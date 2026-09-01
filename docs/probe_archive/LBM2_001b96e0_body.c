/* Closest clean C candidate; reverted because lverify remained MISMATCH (object 680, window 704, normalized_diff 378). */
// FUN_001B96E0
u32 func_001b96e0(u8* arg0)
{
    f32 results[4];
    f32 scaled[4];
    f32 currentFloat;
    f32 totalFloat;
    f32 ratio;
    f32 inverse;
    u32 totalFrames;
    u32 currentFrame;
    u8* global;
    f32 var_f1;
    u8 temp_2_2;
    u8 temp_2_3;
    u8 temp_2_4;
    u8 temp_2_5;

    if (*(u32*)(arg0 + 0x14) == 0)
    {
        global = iGpffffb3ac;
        *(RwV4d*)arg0 = *(RwV4d*)(global + 0x25c);
    }

    temp_2_2 = bGpffffb45c;
    var_f1 = (f32)temp_2_2;
    scaled[0] = fGpffff81f4 * var_f1;
    temp_2_3 = bGpffffb45d;
    var_f1 = (f32)temp_2_3;
    scaled[1] = fGpffff81f4 * var_f1;
    temp_2_4 = bGpffffb45e;
    var_f1 = (f32)temp_2_4;
    scaled[2] = fGpffff81f4 * var_f1;
    temp_2_5 = bGpffffb45f;
    var_f1 = (f32)temp_2_5;
    scaled[3] = fGpffff81f4 * var_f1;

    totalFrames = *(u32*)(arg0 + 0x10);
    currentFrame = *(u32*)(arg0 + 0x14);
    if (currentFrame < totalFrames)
    {
        currentFloat = (f32)currentFrame;
        totalFloat = (f32)totalFrames;
        ratio = currentFloat / totalFloat;
        inverse = 1.0f - ratio;
        results[0] = *(f32*)(arg0 + 0x00) * inverse + scaled[0] * ratio;
        results[1] = *(f32*)(arg0 + 0x04) * inverse + scaled[1] * ratio;
        results[2] = *(f32*)(arg0 + 0x08) * inverse + scaled[2] * ratio;
        results[3] = *(f32*)(arg0 + 0x0c) * inverse + scaled[3] * ratio;
        global = iGpffffb3ac;
        *(RwV4d*)(global + 0x25c) = *(RwV4d*)results;
        *(u32*)(arg0 + 0x14) = *(u32*)(arg0 + 0x14) + 1;
        return 0;
    }

    global = iGpffffb3ac;
    *(RwV4d*)(global + 0x25c) = *(RwV4d*)scaled;
    return 1;
}
