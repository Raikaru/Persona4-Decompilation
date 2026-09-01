/* func_003c47c0: object_size=92, window=96, normalized_diff=8, differing_word_offsets=0x0c,0x10; retail saves `sq $s1,16($sp)` / `sq $s0,0($sp)` (not sd), then moves `$s1,$a0`; corrected block-scope func_003e6240(u8*) declaration, u8* versus s32* argument typing, schedule-on source shape, local declaration-order reversal, and delayed first parameter read were ruled out; residual is MWCCPS2 prologue move/sq-save order. */
s32 func_003c47c0(u8 *arg0) {
    extern s32 func_003e6240(u8 *arg0);
    s32 total;

    total = 0x28;
    if (*(u8 **)arg0 != NULL) {
        total += func_003e6240(*(u8 **)arg0) + 0xC;
    }
    return total + (func_003e3370(D_0070AFF0, arg0) + 0xC);
}
