s32 func_001ef4d0(s32 arg0, s32 arg1)
{
    u8 *node;
    u32 total;
    u16 count;
    u16 average;

    total = 0;
    count = 0;
    node = *(u8 **)(iGpffffb3ac + 0x174);
    for (; node != NULL; node = *(u8 **)(node + 0x450))
    {
        u8 *entry;

        if ((*(u16 *)(node + 0x1A) & 1) == 0)
        {
            continue;
        }
        entry = *(u8 **)(node + 0x30);
        if ((((u32)arg0) & (1u << *(u8 *)(entry + 0xA2))) == 0)
        {
            continue;
        }
        if (arg1 != 0 &&
            func_00232710(*(s32 *)(entry + 0xA64), arg1) != 0)
        {
            continue;
        }
        total = (u16)(total + func_00231e20(*(s32 *)(entry + 0xA64)));
        count++;
    }
    if (count == 0)
    {
        return 1;
    }
    average = (u16)((s32)(u16)total / (s32)(u16)count);
    if (average == 0)
    {
        return 1;
    }
    return average;
}
