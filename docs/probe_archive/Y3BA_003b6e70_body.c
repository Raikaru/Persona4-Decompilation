/* Current-TU remeasure: object 164B/window 144B, normalized_diff 122; differing offsets 0,4,6,7,10,11,12,13,14,15,16,17,18,19,22,23,24,25,26,27,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160. Object exceeds window; archived plain-C body below is not viable under current declarations. */
s32 func_003b6e70(s32 arg0) {
    u8 **base;
    extern u8 *(*jtbl_008873E8[])(s32 size, s32 align);

    base = (u8 **)(D_008872E0 + iGpffffb618);
    *base = jtbl_008873E8[0](0x7C, 0x4010C);
    if (*base != NULL) {
        base[1] = *base + 0xC;
        base[2] = *base;
        base[3] = *base + 0x7C;
        func_003b6f00(0x9A319039, (u8 *)base);
        return arg0;
    }
    return 0;
}
