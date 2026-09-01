/* archived candidate for func_003c4040: object 124B, window 144B, nd 17; no match */
s32 func_003c4040(s32 arg0, s32 arg1) {
    extern s32 iGpffffaaa0;
    extern s32 iGpffffaaa4;
    extern u8 D_00886580[];
    s32 *base;
    s32 result;
    iGpffffb6e0 = arg1;
    result = func_003e1220(*(s32 *)D_0070AFF0, iGpffffaaa0, 4, iGpffffaaa4, D_00886580, 0x40007);
    base = (s32 *)(D_008872E0 + iGpffffb6e0);
    *base = result;
    if (*base == 0) return 0;
    iGpffffb6e4 += 1;
    return arg0;
}
