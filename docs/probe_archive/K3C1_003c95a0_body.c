/* object 176B, window 160B, normalized_diff 100; differing offsets 0x0c-0x0f,0x12,0x13,0x18-0x1c,0x1e-0x20,0x23,0x28,0x2a. Automatic stop because object exceeded the window. Direct allocator reconstruction with corrected six-argument func_003e1220 prototype was oversized; no further source levers attempted. */
s32 func_003c95a0(s32 arg0, s32 arg1) {
    extern s32 func_003cc170(void);
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                             void *arg4, s32 arg5);
    extern u8 D_008865B0[];
    u8 *slot;
    s32 result;
    iGpffffb700 = arg1;
    if (func_003cc170() == 0)
        return 0;
    result = func_003e1220(0x10, 8, 4, 1, D_008865B0, 0x4000B);
    slot = D_008872E0 + iGpffffb700;
    *(s32 *)slot = result;
    result = *(s32 *)slot;
    if (result == 0)
        return 0;
    slot += 4;
    *(u8 **)(slot + 0) = slot;
    *(u8 **)(slot + 4) = slot;
    iGpffffb704 += 1;
    return arg0;
}