/* object 104B / window 112B / normalized_diff 4 / differing offsets 4,8 (fndiff also prints relocation-only offsets 64,72); casts written: none; levers ruled out: one-argument versus hidden first s32 argument, u16 signed/unsigned count tests, direct versus temporary first load, explicit out-of-line labels, schedule/no_branch_likely pragmas, optimization_level 1, opt_propagation off, condition polarity and goto layout. Residual: retail calls nothing before the initial lw $v1,0($a1), then saves $ra; MWCCPS2 saves $ra before that load (prologue scheduling floor). */
/* measured: schedule on fills the call and return delay slots for cc250. */
#pragma schedule on
/* measured: no_branch_likely on keeps cc250's tests as plain branches. */
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
/* measured: no_branch_likely off and schedule off close cc250's bracket. */
#pragma no_branch_likely off
#pragma schedule off
