u32 func_0019ff60(u8 *arg0)
{
    u8 *root = iGpffffb3ac;
    u8 *current;
    u8 *unit;
    u16 enemyCount;

    if (func_002428f0(*(u8 **)(*(u8 **)(root + 0x170) + 0x30), 0) != 0 ||
        func_00232710(*(s32 *)(*(u8 **)(root + 0x170) + 0x30), 0x100117, 0) != 0) {
        return 0;
    }
    if (*(u8 **)(arg0 + 0x30) != NULL &&
        *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1 &&
        func_002428f0(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64), 0) != 0) {
        return 0;
    }
    *(s16 *)(root + 0xC58) = 0;
    enemyCount = 0;
    current = *(u8 **)(root + 0x174);
    for (; current != NULL; current = *(u8 **)(current + 0x450)) {
        if ((*(u16 *)(current + 0x1A) & 1) == 0) continue;
        unit = *(u8 **)(current + 0x30);
        if ((*(s32 *)(unit + 0x9C) & 8) == 0 ||
            func_002428f0(*(u8 **)(unit + 0xA64), 0) != 0) continue;
        if (*(u8 *)(unit + 0xA2) == 1) {
            if (func_00232710(*(s32 *)(unit + 0xA64), 0x100000, 0) == 0) return 0;
            enemyCount++;
        } else if (func_00232710(*(s32 *)(unit + 0xA64), 0x100117, 0) == 0 &&
                   root != current) {
            *(u8 **)(root + (*(u16 *)(root + 0xC58) * 4) + 0xC48) = current;
            (*(s16 *)(root + 0xC58))++;
        }
    }
    if (enemyCount == 0) return 0;
    return *(u16 *)(root + 0xC58) >= 1;
}
