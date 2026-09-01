/* func_003c4040 near-match archive: object 124B, window 144B, normalized_diff 31. */
s32 func_003c4040(s32 arg0, s32 arg1)
{
    extern s32 iGpffffaaa0;
    extern s32 iGpffffaaa4;
    extern u8 D_00886580[];
    s32 temp_3;

    iGpffffb6e0 = arg1;
    temp_3 = func_003e1220(*(s32 *)D_0070AFF0, iGpffffaaa0, 4,
                           iGpffffaaa4, D_00886580, 0x40007);
    *(s32 *)(D_008872E0 + iGpffffb6e0) = temp_3;
    if (*(s32 *)(D_008872E0 + iGpffffb6e0) == 0) {
        return 0;
    }
    iGpffffb6e4 += 1;
    return arg0;
}
