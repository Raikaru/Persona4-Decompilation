/* object 496 / window 544 / normalized_diff 352 / differing offsets 0-488 (first rows 0,4,8-24,25-100,104-488) / undersized by 48 bytes; prologue frame 0x50 with four saves s3..s0 vs retail frame 0x60 with five saves s4..s0 (all a0-a3 first-touched as args; arg2 raw lifetime was coalesced into idx s0); classification missing saved arg2/raw-parameter lifetime plus subsequent path/extension layout; ruled-outs: block-scope callee declarations, u32 booleanized flag (matched retail sltu), raw arg2 in entry/fallback expressions, 5th unused arg definition. */
// FUN_00241BC0
s32 func_00241bc0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    extern s64 func_00106a30(s16 arg0);
    extern u32 func_00106cd0(s16 arg0, s32 arg1);
    extern void func_0046d730(void *arg0, s32 arg1);
    u8 *entry;
    u32 flag1;
    s32 value;

    if ((arg2 & 0xFFFF) >= 0x1B8) {
        func_0046d730(D_00635938, 0x1305);
    }
    flag1 = *(u32 *)(arg1 + 0xC);
    if ((u32)((flag1 & 0x100000) != 0) != 0) {
        return 0;
    }
    if ((arg3 & 0xFFFF) != 1) {
        return 0;
    }
    if (*(u16 *)arg1 & 8) {
        return 0;
    }
    entry = iGpffffb3b8 + (arg2 & 0xFFFF) * 0x28;
    if (entry[0x11] == 0 &&
        (entry[0x18] != 1 || (*(s32 *)(entry + 0x1C) & 0x80000) == 0)) {
        return 0;
    }
    if (arg0 != 0 && (arg2 & 0xFFFF) < 0x1B8 && (entry[0] & 2)) {
        if (*(u16 *)arg0 & 4) {
            value = *(u8 *)(iGpffffb3c4 +
                             *(u16 *)(arg0 + 2) * 0x3C + 0x38);
        } else {
            value = func_00106a30((s16)(func_00106cd0(
                *(s16 *)(arg0 + 2), 0) & 0xFFFF));
        }
    } else {
        value = *(s8 *)(iGpffffb3cc + (arg2 & 0xFFFF) * 2);
    }
    if (value >= 0x13) {
        func_0046d730(D_00635938, 0xE47);
    }
    if ((1 << (value + 1)) & 0xE0001) {
        return 0;
    }
    return 1;
}
