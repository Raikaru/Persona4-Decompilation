/* func_003cb870 near-match archive: object 84 bytes, window 96 bytes, normalized_diff 6; differing byte offsets 48,50,51,55,56,58; classification: conditional-move/branch-materialisation residual (retail movz $s1,$zero,$v0 versus MWCC branch+move); pointer-helper/result-local if body measured nd 6, while flat/goto/ternary result forms were already probed, so source shape, width, order, and schedule changes are ruled out; no compliant C form emits movz. */
s32 func_003cb870(s32 arg0, s32 arg1, u8 *arg2) {
    s32 result;
    u8 *temp_2;

    temp_2 = func_003c9c20((u32)arg2);
    result = func_003c5d10(arg0, temp_2, temp_2 + 0x10);
    *(s32 *)(arg2 + 0x78) = result;
    result = *(s32 *)(arg2 + 0x78);
    if (result == 0)
        arg0 = 0;
    return arg0;
}
