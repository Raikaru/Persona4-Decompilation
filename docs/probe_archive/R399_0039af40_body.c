/* object 192 / window 320 / normalized_diff 142; differing offsets 0x00-0x13c; undersized 128 bytes: separate temporary loads optimized away because only first scalar was passed; classification raw temporary layout/aggregate width and missing saved locals; ruled out none (initial plain-C reconstruction). */
s32 func_0039af40(s32 arg0, s32 unused, s32 arg2)
{
    s32 count, index, value2, value1, value0, temp, delta, offset, i;
    f32 value;
    u8 *base, *records;
    extern s32 func_003e2ab0(s32 arg0, void *arg1, s32 arg2);
    base = (u8 *)(arg2 + iGpffffb5f0);
    if (func_003df240(arg0, &count, 4) == 0) return 0;
    if (count <= 0) return arg0;
    i = 0; offset = 0;
    do {
        records = *(u8 **)(base + 8);
        value0 = *(s32 *)(records + offset);
        value1 = (s32)*(s16 *)(records + offset + 4);
        value2 = (s32)*(s16 *)(records + offset + 6);
        value = *(f32 *)(records + offset + 8);
        temp = *(s32 *)(records + offset + 0x10);
        delta = temp - (s32)records;
        index = (delta / 20) + ((u32)delta >> 31);
        if (func_003e2ab0(arg0, &value0, 0x14) == 0) return 0;
        i += 1; offset += 0x14;
        if (i >= count) return arg0;
    } while (1);
}
