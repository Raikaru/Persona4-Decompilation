/* object_size=172B window=176B normalized_diff=104 differing_offsets=0x0c-0x98; baseline/direct-callback/no_branch_likely/schedule probes did not improve; ruled out callback spelling, local declaration order, base-local, and branch pragmas. */
s32 func_003e1ea0(u8 *arg0) {
    typedef void (*CallbackNoArg003e)(void);
    u8 *node;
    u8 *next;
    u8 *base;
    s32 *count;

    if (*(CallbackNoArg003e *)(arg0 + 0x14) != NULL) {
        (*(CallbackNoArg003e *)(arg0 + 0x14))();
    }
    count = *(s32 **)(arg0 + 0x10);
    if (count != NULL) {
        *count = 0;
    }
    node = *(u8 **)(arg0 + 0);
    if (node != NULL) {
        next = *(u8 **)(arg0 + 4);
        *(u8 **)next = node;
        *(u8 **)(node + 4) = next;
        base = (u8 *)D_008872E0 + (s32)iGpffffb780;
        *(s32 *)(base + 4) -= *(s32 *)(arg0 + 8);
        func_003e4520(arg0);
    } else {
        jtbl_008873EC[0](arg0);
    }
    return 1;
}
