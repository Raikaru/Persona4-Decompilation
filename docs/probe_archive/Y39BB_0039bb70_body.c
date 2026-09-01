// FUN_0039BB70 NONMATCHING
u8 *func_0039bb70(u8 **arg0, s32 arg1)
{
    u8 *base;
    u8 *entry;
    u32 count;
    u32 index;
    count = *(u32 *)((u8 *)arg0 + 4);
    index = 0;
    if (count != 0) {
        base = *arg0;
        entry = base;
        do {
            if (arg1 == *(s32 *)(entry + 8)) return base + index * 0x14;
            index += 1;
            entry += 0x14;
        } while (index < count);
    }
    return NULL;
}
