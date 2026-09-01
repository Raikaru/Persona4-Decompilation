/* object 244B/window 240B, normalized_diff 131; differing offsets 4-44,52-60,64-220,232-236; classification: call-argument materialization and branch layout residual with a 4B oversized candidate. Retail frame 0x20 saves only $s0. Corrected D_0070AF70/D_0070AF90 as incomplete u8 arrays read through *(s32*) for absolute addressing; declared D_008864F0/D_00886520 arrays and GP aliases aa88/aa8c/aa90/aa94; func_003e1220 six-argument prototype and func_003e12f0(s32). No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor. Source restored to INCLUDE_ASM.
s32 func_003bfd00(s32 arg0, s32 arg1) {
    extern s32 func_003e1220(
        s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
    extern void func_003e12f0(s32 arg0);
    extern u8 D_0070AF70[];
    extern u8 D_0070AF90[];
    extern u8 D_008864F0[];
    extern u8 D_00886520[];
    extern s32 iGpffffaa88;
    extern s32 iGpffffaa8c;
    extern s32 iGpffffaa90;
    extern s32 iGpffffaa94;

    iGpffffb6c0 = arg1;
    *(s32 *)(D_008872E0 + iGpffffb6c0) = func_003e1220(
        *(s32 *)D_0070AF70, iGpffffaa88, 0x10, iGpffffaa8c, D_00886520, 0x40010);
    if (*(s32 *)(D_008872E0 + iGpffffb6c0) == 0) {
        goto done;
    }
    *(s32 *)(D_008872E0 + iGpffffb6c0 + 4) = func_003e1220(
        *(s32 *)D_0070AF90, iGpffffaa90, 0x10, iGpffffaa94, D_008864F0, 0x40014);
    if (*(s32 *)(D_008872E0 + iGpffffb6c0 + 4) != 0) {
        iGpffffb6c4 += 1;
        return arg0;
    }
    func_003e12f0(*(s32 *)(D_008872E0 + iGpffffb6c0));
    *(s32 *)(D_008872E0 + iGpffffb6c0) = 0;
done:
    return 0;
}
