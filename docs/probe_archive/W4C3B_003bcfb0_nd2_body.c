/* CURRENT RECHECK: object 76B/window 80B, normalized_diff 32; differing word offsets (fndiff, relocation-masked) 0,4,16,20,24,52,56,60,64,68. The archived nd2 result is stale in the current TU. */
s32 func_003bcfb0(s32 arg0) {
    s32 count;
    s32 index;
    s32 length;
    u8 *base;
    u8 *entry;

    count = 0;
    base = (u8 *)(arg0 + iGpffffb680);
    length = *(s32 *)(base + 0);
    index = count;
    if (index < length) {
        entry = *(u8 **)(base + 4);
        do {
            if (*(s32 *)(entry + 0xC) == 0) goto no_count;
            count += 1;
no_count:
            index += 1;
            entry += 0x10;
        } while (index < length);
    }
    return count;
}
/*
Ruled out during this recheck: count-vs-index guard polarity, positive and
zero-left relational guards, guarded do/while and early-goto forms,
base/count statement order, a global temporary, signed versus unsigned count,
local declaration-order permutations, schedule-on, and opt_propagation-off.
The direct archived body and all these source-level variants remained
object 76B/window 80B or worse; no source change was retained.
*/
