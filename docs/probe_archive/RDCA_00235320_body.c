/* Exact status/level selection, installed in datCalc.c.
 * MWCCPS2 b210 owner profile: 504B / 512B window; the only two differing
 * fndiff words are omitted zero tails at 0x1f8 and 0x1fc. The production
 * owner verifies at 69 MATCH / eleven ASM, with no regressions.
 * Signed-byte status/level merges, an unsigned-byte boolean merge and the
 * independent unsigned remainder argument close the old allocation floor.
 * GP relocation is B3C4; diagnostic filename is D_00635938. The diagnostic
 * is returning, so its calls and the subsequent resource-id reload remain.
 * Actual selector, status getter and diagnostic pass 1,114,112 native32
 * cases: packed status/level values, first-match precedence, entry 15,
 * exclusion of entry 16, thresholds 3/6, resource flags and id boundaries.
 * Preserve the existing s64 return contract; a successful index is first
 * narrowed to s8. The expanded active boundary follows func_00233a90.
 */
static inline s8 P4CalcLevel(u8 *unit, u8 index)
{
    u16 offset;
    /* Preserve the signed-byte getter conversion at the branch merge. */
    s32 level;
    if ((s32)index >= 24)
        func_0046d730(D_00635938, 0x42A);
    offset = index >> 1;
    if (index & 1)
        level = (s8)(*(u8 *)(unit + offset + 0x24) >> 4);
    else
        level = (s8)(*(u8 *)(unit + offset + 0x24) & 15);
    return (s8)level;
}

#pragma push
/* measured: b210 owner profile, 504B/512B, no differing emitted words;
   hoist the signed threshold comparison out of the loop. */
#pragma opt_loop_invariants on
// FUN_00235320
s64 func_00235320(u8 *unit)
{
    s32 checked;
    s8 threshold;
    u32 index;
    s8 active;
    s8 level;
    threshold = 3;
    if (*(u16 *)unit & 4) {
        if (*(u16 *)(unit + 2) >= 0x150)
            func_0046d730(D_00635938, 0x6D8);
        if (*(u16 *)(iGpffffb3c4 + *(u16 *)(unit + 2) * 0x3C) & 0x1000)
            threshold *= 2;
    }
    for (index = 0; index < 16; index++) {
        checked = (u8)index;
        if (checked >= 24)
            func_0046d730(D_00635938, 0x4C1);
        if (checked < 16)
            /* Keep the independently narrowed getter argument. */
            active = func_002332a0(unit, index % 256U);
        else {
            u8 result = (*(u32 *)(unit + 0x14) & (1 << checked)) != 0;
            active = result;
        }
        level = P4CalcLevel(unit, index);
        if (active != 0 && level >= threshold)
            return (s8)index;
    }
    return -1;
}
#pragma pop
