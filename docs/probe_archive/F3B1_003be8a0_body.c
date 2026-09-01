/* object 112B/window 112B, normalized_diff 48; differing offsets 4,8,12,16,20,48,76,80,84,88,92,96,100,104,108; residual is prologue load/save order, branch layout, and movz conditional move. Ruled out: shared 003bd4f0 shape, s32/u8* and direct-load variants, schedule on/off, no_branch_likely on/off, local declaration-order and delayed-read probes; retail uses movz $s1,$zero,$v0 while plain b210 C emits branch/move. */
s32 func_003be8a0(s32 arg0, s32 arg1, u8 *arg2)
{
    s32 result;
    u8 *base = *(u8 **)(arg2 + 0x6C);

    result = func_003df240(arg0, (s32)(base + 0x2C), 4);
    if (result == 0) {
        return 0;
    }
    base = *(u8 **)(arg2 + 0x6C);
    result = func_003df240(arg0, (s32)(base + 0x30), 4);
    return result == 0 ? 0 : arg0;
}
