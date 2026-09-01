/* Current best candidate: object 156B, retail window 160B, normalized_diff 81; differing offsets 16-140 (reloc-masked). Base-first/fn-load/call/index-init order improved prior nd 93 to 81. Schedule-on probe collapsed object to 132B and was ruled out; global-pointer and loop-layout residuals remain. */
s32 func_003dd390(s32 arg0) {
    extern s32 D_008873D4[];
    s32 (**fn)();
    s32 base;
    s32 index;
    s32 length;

    base = arg0;
    fn = (s32 (**)())D_008873D4;
    length = (*fn)();
    index = 0;
    if (0 < length) {
        do {
            if (*(s8 *)(base + index) == 0x3A) {
                base += index + 1;
                break;
            }
            index += 1;
            length = (*fn)(base);
        } while (index < length);
    }
    return base;
}
