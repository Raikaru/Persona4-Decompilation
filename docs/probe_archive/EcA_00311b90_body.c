/* object 364 bytes, retail window 368 bytes, normalized_diff 65 (reloc-masked differing words); differing offsets: 24,32,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,324,328,332,336,352. Levers tried: idiomatic nested for loops, explicit outer/inner pointer locals, declaration-order swaps, preloaded global table, s16 count, s64 bit/constant locals, pointer-width variants, and second-parameter width. Both decompiler corpora agreed on control flow. Best residual remained 65; fallback source was restored. */
s32 func_00311b90(u16 *arg0, u16 *arg1, s32 arg2, s16 *arg3)
{
    s32 result;
    s16 i;
    s16 count;
    s64 value;
    s16 found;
    s16 j;
    s64 bit;
    s64 one;
    u16 candidate;
    u8 *base;
    u8 *table;
    u16 *entry;

    if (*arg0 == 0) {
        return 0;
    }
    count = 0;
    result = 0;
    base = (u8 *)arg0 + 4;
    i = 0;
    table = iGpffffb3d4;
    one = 1;
    for (; i < 8; i++) {
        entry = (u16 *)(base + (i * 2) + 4);
        value = *(s16 *)entry;
        if (value != 0) {
            found = 0;
            for (j = 0; j < arg2; j++) {
                bit = (s64)(u32)one << j;
                if ((result & bit) == 0) {
                    if (*(s8 *)((u8 *)entry + 1) != 0) {
                        candidate = *(u8 *)(table
                            + (*(u16 *)((u8 *)arg1 + (j * 2)) * 14) + 2);
                    } else {
                        candidate = *(u16 *)((u8 *)arg1 + (j * 2));
                    }
                    if ((candidate & 0xFFFF) == value) {
                        result |= bit;
                        count++;
                        found = 1;
                        break;
                    }
                }
            }
            if (*(s8 *)((u8 *)entry + 1) != 0 && found == 0) {
                return 0;
            }
        }
    }
    if (arg3 != 0) {
        *arg3 = count;
    }
    return result;
}
