/* object 64B / window 64B / normalized_diff 38 / differing offsets 4,8,12,16,20,28,36,40,44,48,52,56; O1 probe; ruled out schedule off, no_branch_likely off, direct return/goto layouts, named handle, and declaration-order variants. Retail saves $ra with sd, confirming MWCC shape. */
s32 func_00390290(s32 arg0, s32 arg1)
{
    s32 *slot;
    s32 handle;

    slot = (s32 *)(arg0 + arg1);
    handle = *slot;
    if (handle != 0) {
        return func_0038fb20((u8 *)handle) + 16;
    }
    return 0;
}
