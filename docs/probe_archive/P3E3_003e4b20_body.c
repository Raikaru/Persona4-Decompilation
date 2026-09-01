/* object_size=192B window=192B normalized_diff=n/a (conditional-move floor) differing_offsets=n/a; retail ends with movz $s1,$zero,$v0, while compliant C conditional expressions compile to branches; ruled out plain-C if/else/ternary forms, declaration/order, and scheduler probes. */
s32 *func_003e4b20(s32 *arg0, u32 arg1) {
    s32 *base;
    s32 size;
    base = arg0;
    if (base == NULL)
        base = (s32 *)D_00752FA8;
    size = (s32)((D_008873D4(base) + 4) & ~3);
    if (func_003deff0(arg1, 2, size, 0x37002, 0x37) == 0)
        return NULL;
    if (func_003e2ab0(arg1, base, size) == 0)
        return NULL;
    return base;
}
