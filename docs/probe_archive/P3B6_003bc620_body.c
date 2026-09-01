/* object 268B/window 288B, normalized_diff 193; differing byte offsets 0,4,8,10-27 and continuing through 276; classification residual in hundreds, archive immediately. Retail logic was reconstructed from the switch and loops; D_008873D4 was declared as an absolute function-pointer array at block scope. Frame/saved-register footprint, switch case layout, pointer/global materialization, and loop register/scheduling remained divergent. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
s32 func_003bc620(u8 *arg0) {
    extern s32 (*D_008873D4[])(u32 arg0);
    s32 total;
    s32 base;
    s32 type;
    s32 count;
    s32 index;
    u8 *entry;

    total = 0;
    if (arg0 != NULL) {
        base = 4;
        if (*(u32 *)arg0 != 0) {
            base += D_008873D4[0](*(u32 *)arg0) + 1;
        }
        type = *(s32 *)(arg0 + 4);
        switch (type) {
        case 1:
        case 2:
            total = base + (*(s32 *)(arg0 + 8) * 4);
            break;
        case 3:
            total = base + 8;
            entry = *(u8 **)(arg0 + 0xC);
            index = 0;
            count = *(s32 *)(arg0 + 8);
            if (0 < count) {
                do {
                    total += 4;
                    if (*(u32 *)entry != 0) {
                        total += D_008873D4[0](*(u32 *)entry) + 1;
                    }
                    index += 1;
                    entry += 4;
                } while (index < count);
            }
            break;
        default:
            total = base;
            break;
        }
    }
    return total;
}
