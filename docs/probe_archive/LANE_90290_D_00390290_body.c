/* object 56B / window 64B / normalized_diff 34; residual: $sd $ra is saved in the prologue instead of the beqz branch delay slot.  First diffs: [10, 11, 12, 14, 15, 16, 18, 19, 20, 21, 22, 23, 28, 31, 32, 34]. */
/* LANE_90290_D: opt_propagation off keeps the loaded handle and arg0 distinct and may let the scheduler sink sd $ra into the beqz delay slot. */
#pragma push
#pragma opt_propagation off
// FUN_00390290
s32 func_00390290(s32 arg0, s32 arg1)
{
    if (*(s32 *)(arg0 + arg1) != 0) {
        return func_0038fb20((u8 *)*(s32 *)(arg0 + arg1)) + 0x10;
    }
    return 0;
}
#pragma pop
