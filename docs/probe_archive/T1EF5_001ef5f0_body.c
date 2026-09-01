// FUN_001EF5F0
s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *current;
    u8 *entry;
    s32 total;
    s32 count;
    s32 mask;
    s32 count_mask;
    s32 value;

    total = 0;
    count = 0;
    current = *(u8 **)(iGpffffb3ac + 0x174);
    mask = arg0 & 0xFFFF;
    while (current != NULL) {
        if ((*(u16 *)(current + 0x1A) & 1) != 0) {
            entry = *(u8 **)(current + 0x30);
            if ((mask & (1 << *(u8 *)(entry + 0xA2))) != 0) {
                if ((arg2 == 0) ||
                    (func_00232710(*(s32 *)(entry + 0xA64), arg2) == 0)) {
                    total = (total +
                             (func_00232c70(*(s32 *)(entry + 0xA64), arg1) & 0xFF)) &
                            0xFFFF;
                    count = (count + 1) & 0xFFFF;
                }
            }
        }
        current = *(u8 **)(current + 0x450);
    }
    count_mask = count & 0xFFFF;
    if (count_mask == 0) {
        value = 1;
        goto done_value_5f0;
    }
    value = ((total & 0xFFFF) / count_mask) & 0xFFFF;
    if (value == 0)
        value = 1;
done_value_5f0:
    return value;
}
