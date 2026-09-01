/* N3B: the archived W3C3B body no longer compiles as written — its implicit int->u8* call argument predates the typed func_003bbea0(u8*) prototype; with the required cast it measures 168B/160B nd91 (object overflows window). ~40 distinct mined shapes measure 152B/nd7 or overflow; fresh guard spellings (`count>0`, `>=1`, while-form, cached-count) all land in the same tier. Retail needs slt $at,$zero,$v0;beqz $at with s2=0 in the delay slot, and lw v0,4(s0) reloaded AFTER the loop before jalr. Best stale archive: build/WV08_003b_bcbe0_nd5.c (172B/105 under current TU). */
s32 func_003bcbe0(s32 arg0, s32 arg1) {
    u8 *base;
    s32 count;
    s32 index;
    s32 offset;
    s32 positive;

    base = (u8 *)(arg0 + arg1);
    if (*(s32 *)(base + 4) != 0) {
        count = *(s32 *)(base + 0);
        positive = 0 < count;
        if (positive == 0) goto callback;
        index = 0;
        offset = 0;
        do {
            func_003bbea0((u8 *)(*(s32 *)(base + 4) + offset));
            index += 1;
            count = *(s32 *)(base + 0);
            offset += 0x10;
        } while (index < count);
callback:
        jtbl_008873EC[0](*(u8 **)(base + 4));
    }
    *(s32 *)(base + 4) = 0;
    *(s32 *)(base + 0) = 0;
    return arg0;
}
