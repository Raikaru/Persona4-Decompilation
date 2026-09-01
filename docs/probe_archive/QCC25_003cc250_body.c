/* object 104B / window 112B / normalized_diff 4; residual is prologue load ordering: retail loads lw v1,0(a1) before saving ra, while MWCCPS2 saves ra first. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003CC250
s32 func_003cc250(s32 arg0, u8 **arg1) {
    extern void (*D_00887300[])(u32 arg0, u32 arg1);
    u8 *temp_3;

    temp_3 = *arg1;
    if ((s32)*(u16 *)(temp_3 + 0) <= 0)
        goto zero;
    *(s32 *)(temp_3 + 0x18) = *(s32 *)(temp_3 + 4);
    if ((*(s32 *)(temp_3 + 0xC) & 1) == 0)
        goto call;
    goto one;
one:
    return 1;
zero:
    return 0;
call:
    D_00887300[0](1, 0);
    goto one;
}
#pragma no_branch_likely off
#pragma schedule off
