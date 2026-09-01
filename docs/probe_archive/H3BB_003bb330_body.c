/* func_003bb330 best plain-C attempt: object 104B/window 112B, normalized_diff 56. */
/* Probed with optimization_level 1, schedule on, and no_branch_likely on. */
s32 func_003bb330(u8 *arg0) {
    s32 pair[2];
    s32 temp_3;

    temp_3 = *(s32 *)(arg0 + 0xC);
    if (temp_3 == 2) {
        return *(s32 *)(arg0 + 8) - 3;
    }
    if (temp_3 == 1) {
        return *(s32 *)(arg0 + 8) - 2;
    }
    pair[0] = 0x102;
    pair[1] = func_003df590(1);
    func_003df4d0(pair);
    return 0;
}
