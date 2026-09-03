/* Lane119c3e 2026-09-03 (b119, schedule on, fresh cw119 unit): object 176B / window 192B,
   normalized_diff 41. Lane died on a provider rate limit before iterating; only spelling tried. */
// FUN_003E02C0
#pragma schedule on
s32 func_003e02c0(s32 arg0, s32 arg1) {
    extern s32 func_003e1220(s32, s32, s32, s32, void *, s32);
    extern s32 func_003e03b0(const MatrixTolerance003e *, u8 *);
    extern s64 D_0070B6E0;
    extern f32 D_0070B6E8;
    u8 *p;
    s32 result;
    MatrixTolerance003e tmp;

    iGpffffb768 = arg1;
    *(s32 *)(D_008872E0 + iGpffffb768) = func_003e1220(0x40, iGpffffab58, 0x10, iGpffffab5c, &D_008871C0, 0x4000d);
    p = (u8 *)(D_008872E0 + iGpffffb768);
    result = arg0;
    if (*(s32 *)p == 0) {
        result = 0;
    } else {
        *(s32 *)(p + 4) = 0x20000;
        *(s32 *)(p + 8) = (s32)func_003df8c0;
        *(s64 *)&tmp = D_0070B6E0;
        tmp.identity = D_0070B6E8;
        func_003e03b0(&tmp, p);
        iGpffffb76c += 1;
    }
    return result;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

