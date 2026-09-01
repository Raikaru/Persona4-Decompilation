/* object_size=160; window=176; normalized_diff=57; differing_offsets=0x50,0x58-0x68,0x70-0x9C; classification: exact prologue, first callback cleanup, allocation callback, and helper calls through the success/failure split; residual is MWCC branch-delay scheduling that tests the returned field before retail's store/reload/branch sequence, plus error-tail layout; tried direct field condition, explicit field reload, goto success/failure labels, block-scope callback/helper declarations, two-field stack aggregate, and no_branch_likely/opt_propagation probes; live source restored to INCLUDE_ASM. */
// FUN_00412520
u8 *func_00412520(u8 *arg0, u32 arg1)
{
    extern u8 *(*jtbl_008873E8[])(u32 size, u32 align);
    extern s32 func_003df590(s32 arg0, s32 arg1);
    extern void func_003df4d0(void *arg0);
    struct {
        s32 sp38;
        s32 sp3C;
    } stack;
    u8 *temp_4;
    u8 *result;

    temp_4 = *(u8 **)(arg0 + 0x20);
    if (temp_4 != NULL) {
        jtbl_008873EC[0](temp_4);
        *(u8 **)(arg0 + 0x20) = NULL;
        *(s32 *)(arg0 + 0x24) = 0;
    }
    temp_4 = jtbl_008873E8[0](arg1, 0x30409);
    *(u8 **)(arg0 + 0x20) = temp_4;
    if (*(u8 **)(arg0 + 0x20) == NULL)
        goto error;
    *(u32 *)(arg0 + 0x24) = arg1;
    result = *(u8 **)(arg0 + 0x20);
    goto done;
error:
    stack.sp38 = 1;
    stack.sp3C = func_003df590(0x80000013, arg1);
    func_003df4d0(&stack.sp38);
    result = NULL;
done:
    return result;
}
