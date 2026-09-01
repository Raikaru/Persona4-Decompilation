/* Current-TU remeasure: object 168B/window 160B, normalized_diff 91; differing word offsets 16,20,24,36,48,52,68,76,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164. Object exceeds window; archived plain-C body is not viable under current declarations. Prior ruled-out probes remain below. */
s32 func_003bcbe0(s32 arg0, s32 arg1) {
    u8 *base;
    s32 count;
    s32 index;
    s32 offset;

    base = (u8 *)(arg0 + arg1);
    if (*(s32 *)(base + 4) != 0) {
        count = *(s32 *)(base + 0);
        if (count > 0) {
            index = 0;
            offset = 0;
            do {
                func_003bbea0(*(s32 *)(base + 4) + offset);
                index += 1;
                count = *(s32 *)(base + 0);
                offset += 0x10;
            } while (index < count);
        }
        jtbl_008873EC[0](*(u8 **)(base + 4));
    }
    *(s32 *)(base + 4) = 0;
    *(s32 *)(base + 0) = 0;
    return arg0;
}
