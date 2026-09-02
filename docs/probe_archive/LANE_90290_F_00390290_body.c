/* object 56B / window 64B / normalized_diff 34; residual: sd $ra saved in prologue rather than beqz delay slot. First diffs: [10, 11, 12, 14, 15, 16, 18, 19, 20, 21, 22, 23, 28, 31, 32, 34]. */
/* LANE_90290_F: archive body under schedule on with -O2,p; the schedule may move sd $ra into the branch delay slot. */
#pragma push
#pragma schedule on
// FUN_00390290
s32 func_00390290(s32 arg0, s32 arg1)
{
    if (*(s32 *)(arg0 + arg1) != 0) {
        return func_0038fb20((u8 *)*(s32 *)(arg0 + arg1)) + 0x10;
    }
    return 0;
}
#pragma pop
