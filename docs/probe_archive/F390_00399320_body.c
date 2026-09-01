/* object 36B / window 32B / normalized_diff 29 / differing offsets 0,4,8,12,16,20,24,28; plain C branch candidate; object exceeded window. Retail uses movn in the return delay slot; direct return, ternary, local declaration, and pragma probes remained larger or branch-shaped. */
s32 func_00399320(s32 arg0)
{
    s32 result;
    s32 value;

    result = 4;
    value = *(s32 *)(arg0 + iGpffffb5e4);
    if (value == 0) {
        result = 0;
    }
    return result;
}
