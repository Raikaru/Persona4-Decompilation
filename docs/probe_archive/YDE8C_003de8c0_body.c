/* hypothesis 4: volatile state-store lvalue; measured object 240B/window 240B/normalized_diff 0. */
#pragma no_branch_likely on
#pragma optimization_level 3
s32 func_003de8c0(u8 *arg0, s32 arg1) {
    extern s32 func_00427868(s32 arg0, s32 arg1, s32 *arg2);
    extern void func_003dd6d0(u8 *arg0);
    s32 result;
    s32 output;
    s32 state;
    result = 2;
    state = *(s32 *)(arg0 + 0x38);
    if (state != 3) goto block_return;
    if (*(s32 *)(arg0 + 0x40) != 4) goto block_helper;
    *(s32 *)(arg0 + 0x38) = 2;
block_check:
    state = *(s32 *)(arg0 + 0x38);
block_check_compare:
    if (state != 2) goto block_return;
    func_003dd6d0(arg0);
block_return:
    return result;
block_helper:
    func_00427868(*(s32 *)(arg0 + 0x60), 1, &output);
    if (output == 0) goto block_failure;
    *(s32 *)(arg0 + 0x44) = 0;
    result = 3;
    goto block_after_helper;
block_failure:
    result = 2;
    *(volatile s32 *)(arg0 + 0x38) = 2;
    if (5 == *(s32 *)(arg0 + 0x40)) {
        *(s32 *)(arg0 + 0x44) = (s32)(*(s64 *)(arg0 + 0x10) - *(s64 *)(arg0 + 0x20));
    }
block_after_helper:
    if (arg1 == 0) goto block_check;
    if (result == 3) goto block_helper;
    state = *(s32 *)(arg0 + 0x38);
    goto block_check_compare;
}
#pragma no_branch_likely off
#pragma optimization_level 2
