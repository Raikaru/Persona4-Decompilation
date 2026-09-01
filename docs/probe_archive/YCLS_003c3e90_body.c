/* object 124 bytes, retail window 144 bytes, normalized_diff 17; differing words are the post-call store/reload/branch tail at offsets 76 through 124 (retail stores, reloads with lw, then bnez; candidate branches on the known result and shifts the tail). Schedule-on plus no_branch_likely-on reproduces the archived size. Plain s32 store/reload folds to nd 17; a narrow u16/mode-SI/may_alias union forces a reload but emits lhu at offset 80 (object 132B, nd 1). Global-scalar, shared-array, struct-field, pointer-alias, pointer-return, positive-branch, offset-local, optimization, and callee-prototype variants were ruled out. No conversion casts or volatile accesses. */
s32 func_003c3e90(s32 arg0, s32 arg1) {
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5);
    extern s32 iGpffffaa98;
    extern s32 iGpffffaa9c;
    extern s32 iGpffffb6d0;
    extern s32 iGpffffb6d4;
    extern u8 D_0070AFD0[];
    extern u8 D_00886550[];
    extern u8 D_008872E0[];
    s32 *temp_3;
    s32 result;

    iGpffffb6d0 = arg1;
    result = func_003e1220(
        *(s32 *)D_0070AFD0,
        iGpffffaa98,
        0x10,
        iGpffffaa9c,
        D_00886550,
        0x40012);
    temp_3 = (s32 *)(D_008872E0 + iGpffffb6d0);
    *temp_3 = result;
    goto reload_result;
reload_result:
    result = *temp_3;
    if (result == 0)
        return 0;
    iGpffffb6d4 += 1;
    return arg0;
}
