/* object 288B / window 288B / normalized_diff 45 / differing offsets 49,53,58,62,66,86,102,106,110,114,118,134,138,166,169,198 / classification register-coloring and argument-materialisation near-miss; best alias-base spelling measured, no confirmed compiler floor. */
u8 *func_001dea90(u8 *p, u16 index)
{
    extern u32 func_00231d70();
    u8 *node;
    u8 *base;
    u8 *result;
    u32 i;
    u32 sum;
    u32 random;
    u32 weight;

    node = iGpffffb3d0 + *(u16 *)(*(u32 *)(p + 0x30) + 0xA4) * 164;
    base = node;
    sum = 0;
    i = 0;
    node += (index & 0xffff) * 40;
    while ((u16)i < 5) {
        sum = (sum + *(u8 *)(node + (i & 0xffff) * 8 + 0x2c)) & 0xffff;
        i = (i + 1) & 0xffff;
    }
    if ((sum & 0xffff) != 0)
        goto choose;
    result = (u8 *)&iGpffffa2a8;
    goto ret;
choose:
    random = func_00231d70((u32)base) & 0xffff;
    sum = 0;
    i = 0;
    while ((u16)i < 5) {
        weight = *(u8 *)(node + (i & 0xffff) * 8 + 0x2c);
        sum = (sum + weight) & 0xffff;
        if (sum < random)
            goto advance;
        if (weight <= 0)
            goto advance;
        result = node + (i & 0xffff) * 8 + 0x2c;
        goto ret;
advance:
        i = (i + 1) & 0xffff;
    }
    result = 0;
ret:
    return result;
}
