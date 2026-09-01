/* Fresh scoped measurement of this alternate body: object 104B / window 96B / normalized_diff 37; differing byte offsets 12,24,27,28,29,60,61,62,63,64,65,67,69,71,75,76. Oversized automatic archive; direct result-local layout adds 8B versus retail's movz-based conditional return. */
s32 func_003f6990(s32 arg0, s32 arg1, s32 *arg2)
{
    extern s32 func_003df240(s32 arg0, s32 *arg1, s32 arg2);
    s32 result;
    s32 value;

    result = arg0;
    if (arg2 == NULL) {
        goto zero;
    }
    if (*arg2 == 0) {
        goto zero;
    }
    value = *(u16 *)((u8 *)*arg2 + iGpffffb938 + 0x14);
    if (func_003df240(arg0, &value, 4) == 0) {
        result = 0;
    }
    return result;
zero:
    return 0;
}
