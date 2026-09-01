/* object 80B, window 80B, normalized_diff 42, differing word offsets 4,5,6,7,8,10,11,24,36,38,39,40,42,43,44,46; ruled out cursor increment width, parameter-walk spelling, test-first/goto guard forms, explicit success labels/result locals, schedule on/off, no_branch_likely, and optimization level 1. */
// FUN_003E5990 NONMATCHING
s32 func_003e5990(u8 *arg0, s32 arg1, s32 *arg2) {
    s32 *var_4;
    s32 temp_3;
    s32 var_7;

    temp_3 = *(s32 *)(arg0 + 4);
    if (temp_3 > 0) {
        var_7 = 0;
        var_4 = *(s32 **)arg0;
loop_2:
        if (*var_4 == arg1) {
            *arg2 = var_7;
            return 1;
        }
        var_7 += 1;
        var_4 += 1;
        if (var_7 >= temp_3) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return 0;
}
