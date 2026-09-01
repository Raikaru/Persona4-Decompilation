/* object 100B / window 112B / normalized_diff 76 / differing word offsets 0x00-0x6C; best plain-C 64-bit paired-store body; ruled out direct/64-bit ternaries, split/assigned s64/u64 locals, reused value local, scheduler and conditional-branch probes. Retail uses movz for both conditional stores, a b210 floor. */
void func_0039a8a0(s32 arg0)
{
    u8 *p;
    s64 value;

    p = *(u8 **)(arg0 + iGpffffb5e0);
    value = ((s64)0x80 << 32) | 0x68;
    if (*(s32 *)(p + 0x80) == 3) {
        if (*(s32 *)(p + 0x4C) != 0)
            value = 0x58;
        *(s64 *)(p + 0x68) = value;
    } else {
        if (*(s32 *)(p + 0xC) != 0)
            value = 0x58;
        *(s64 *)(p + 0x28) = value;
    }
}
