/* object 120B / window 128B / normalized_diff 40 / differing word offsets 0x20,0x44,0x48,0x4C,0x54,0x58,0x5C,0x60,0x64,0x68,0x6C,0x70,0x74,0x78,0x7C; schedule on + no_branch_likely on; block-scope func_0038fb50 prototype; ruled out opposite guard/inner branch layouts and O1/O3. Retail saves $ra with sd (MWCC shape). */
s32 func_003902d0(s32 arg0, s32 unused, s32 arg2, s32 arg3)
{
    s32 sp3C;
    u8 **temp_16;
    extern u8 *func_0038fb50(u8 *arg0, s32 arg1);

    temp_16 = (u8 **)(arg2 + arg3);
    if (*temp_16 != NULL) {
        goto retry;
    }
done:
    return arg0;
retry:
    sp3C = func_003e8920();
    if (func_003df240(arg0, &sp3C, 4) != 0) {
        goto check;
    }
    goto zero;
check:
    if (func_0038fb50(*temp_16, arg0) != 0) {
        goto retry;
    }
    goto zero;
zero:
    return 0;
}
