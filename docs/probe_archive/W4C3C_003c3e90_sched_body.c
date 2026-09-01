/* measured: probe schedule and branch form for func_003c3e90. */
#pragma schedule on
#pragma no_branch_likely on
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
#pragma no_branch_likely off
#pragma schedule off
