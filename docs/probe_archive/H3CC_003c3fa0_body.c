/* object 112B, window 112B, normalized_diff 48; differing offsets 4, 6, 7, 8, 10, 11, 12, 14, 16, 17, 18, 19, 20, 21, 22; schedule on + no_branch_likely on. */
s32 func_003c3fa0(s32 arg0, s32 unused, u8 *arg2) {
    s32 result;

    result = arg0;
    if (func_003df240(arg0, *(s32 *)(arg2 + 8) + 0x2C, 4) == 0)
        goto retzero;
    goto second;
retzero:
    return 0;
second:
    if (func_003df240(arg0, *(s32 *)(arg2 + 8) + 0x30, 4) == 0)
        result = 0;
    return result;
}
