/* object 124 bytes, retail window 144 bytes, normalized_diff 17; differing words are the post-call store/reload/branch tail at offsets 76 through 124 (retail stores, reloads with lw, then bnez; candidate branches on the known result and shifts the tail). O1, schedule-on, no_branch_likely-on, and opt_common_subs-off reproduce the archived size; typed six-argument helper setup, branch/schedule forms, declaration order, pointer aliases, direct stores, and reload variants were ruled out. No conversion casts. The live source body is restored to the bare INCLUDE_ASM fallback while this candidate remains archived. */
s32 func_003c4040(s32 arg0, s32 arg1) {
    extern s32 iGpffffaaa0;
    extern s32 iGpffffaaa4;
    extern u8 D_00886580[];
    s32 result;
    s32 *base;

    iGpffffb6e0 = arg1;
    result = func_003e1220(
        *(s32 *)D_0070AFF0,
        iGpffffaaa0,
        4,
        iGpffffaaa4,
        D_00886580,
        0x40007);
    base = (s32 *)(D_008872E0 + iGpffffb6e0);
    *base = result;
    if (*base == 0)
        return 0;
    iGpffffb6e4 += 1;
    return arg0;
}
