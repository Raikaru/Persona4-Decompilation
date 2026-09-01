/* Closest clean-C candidate for func_003d0540; skipped after five attempts (normalized_diff remained nonzero). */
s32 func_003d0540(u8 *arg0, s32 *arg1) {
    u8 *saved_arg0;
    s32 *saved_arg1;
    u8 *temp_16;
    u8 *object;
    s32 **cache;
    s32 *cached;
    s32 flag;
    s32 status;
    s32 remaining;
    u8 *transform;
    u8 *sphere;
    u8 *table;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;

    saved_arg1 = arg1;
    temp_16 = *(u8 **)(arg0 + 8);
    object = *(u8 **)(temp_16 + 0x18);
    *(u32 *)(arg0 + 0xC) = *(u32 *)(object + 0x54);
    saved_arg0 = arg0;
    if (*(s32 *)(object + 0x18) != 1) {
        goto second_cache;
    }
    cache = (s32 **)(object + iGpffffb730);
    cached = *cache;
    flag = 0;
    if (cached == NULL) {
        goto first_flag_done;
    }
    if (*(u16 *)(*(u8 **)(object + 0x54) + 4) != *(u16 *)cached) {
        goto first_flag_done;
    }
    flag = 1;
first_flag_done:
    if (flag == 0) {
        cache = func_003ce050(
            cache, *(u16 *)(*(u8 **)(object + 0x54) + 4), object, flag);
    }
cache_store:
    *(s32 *)(saved_arg0 + 0x10) = (s32)*cache;
    *(s32 *)(saved_arg0 + 0x20) =
        *(s32 *)(*(u8 **)(temp_16 + 0x18) + 0x18);
    if (*(s32 *)(saved_arg0 + 0x20) >= 2) {
        *(f32 *)(saved_arg0 + 0x1C) =
            *(f32 *)(temp_16 + 0x58) * *(f32 *)(temp_16 + 0x5C);
    }
    func_003cfff0(temp_16, saved_arg0);
    *(s16 *)(*(u8 **)(temp_16 + 0x18) + 0xC) = 0;
    *(s32 *)(temp_16 + 0x4C) &= ~1;
    transform = *(u8 **)D_008872E0 + 0x20;
    func_003e05f0(
        (void *)(*saved_arg1), func_003e9700(*(s32 *)(temp_16 + 4)),
        transform);
    sphere = func_003bfae0(temp_16);
    status = 2;
    remaining = 5;
    table = transform + iGpffffb934 + 0x40;
    for (;;) {
        f0 = *(f32 *)(sphere + 0xC);
        f4 = -f0;
        f7 = *(f32 *)(sphere + 4);
        f6 = *(f32 *)(sphere + 0);
        f5 = *(f32 *)(sphere + 8);
        f1 = *(f32 *)(table + 4);
        f2 = *(f32 *)(table + 0);
        f3 = *(f32 *)(table + 8);
        f0 = *(f32 *)(table + 0xC);
        f1 = f7 * f1 + f6 * f2 + f5 * f3;
        f0 = f1 - f0;
        if (f0 <= f4) {
            if (remaining == 0) {
                break;
            }
            table += 0x14;
            remaining -= 1;
        } else {
            status = 1;
            break;
        }
    }
    func_003d0140(saved_arg0, (s64)status);
    *(u8 *)(saved_arg0 + 0x2A) =
        ((*(u32 *)(*(u8 **)(temp_16 + 0x18) + 8) & 0x40) != 0);
    func_003d0230(saved_arg0);
    return 1;

second_cache:
    cache = (s32 **)(temp_16 + iGpffffb72c);
    cached = *cache;
    flag = 0;
    if (cached == NULL) {
        goto second_flag_done;
    }
    if (*(u16 *)(*(u8 **)(object + 0x54) + 4) != *(u16 *)cached) {
        goto second_flag_done;
    }
    flag = 1;
second_flag_done:
    if (flag == 0) {
        cache = func_003ce050(
            cache, *(u16 *)(*(u8 **)(object + 0x54) + 4), object, flag);
    }
    goto cache_store;
}
