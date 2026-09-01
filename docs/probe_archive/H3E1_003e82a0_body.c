/* object_size=64B window=64B normalized_diff=42 differing_offsets=4,6,7,8,10,11,12,13,14,15,18,19,24,25,26,28; ruled out ternary, if, pointer/s32 return types, schedule/no_branch_likely, and local-result probes; residual is retail movz $s0,$zero,$v0. */
s32 func_003e82a0(s32 arg0) {
    s32 result;
    result = arg0;
    if (D_0088737C() == 0) {
        result = 0;
    }
    return result;
}
