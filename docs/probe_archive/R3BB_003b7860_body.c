/* 003b7860: object 288B/window 272B, normalized_diff 191, first differing offsets 4,6-8,10-12,14,16-19,22-23,26-27; oversized by 16B. Retail prologue frame 0x30 saves exactly s0/s1 (plus ra), candidate saves exactly s0/s1 (saved-local count correct). Classification: block layout/prologue scheduling residual; block-scope GP aliases iGpffffaa80/aa84 fixed translation, absolute globals/old-style six-arg helper declarations supplied; branch-shape, goto layout and opt_rebuildconditionals probes ruled out. */
s32 func_003b7860(s32 arg0) {
    extern s32 func_003b8d20(s32 arg0);
    extern s32 func_003e1220(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5);
    extern s32 func_003e8960(s32 arg0);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    extern s32 iGpffffaa80;
    extern s32 iGpffffaa84;
    extern u8 D_00886460[];
    extern s32 D_0088649C[];
    extern u8 *D_008864A0[];
    extern s32 D_008864A8[];
    extern s32 D_008864B0[];
    extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
    s32 flags;

    if (D_008864B0[0] != 0) {
        goto increment;
    }
initialize:
    flags = 1;
    if (func_003e8960(0x120) != -1) {
        flags |= 2;
    }
    if (func_003e8960(0x12E) != -1) {
        flags |= 4;
    }
    func_003b8d20(flags);
    D_008864A8[0] = func_003e1220(0x48, iGpffffaa80, 4, iGpffffaa84, D_00886460, 0x40116);
    D_008864A0[0] = jtbl_008873E8[0](0x400F, 0x40116);
    func_0043f9c8(D_008864A0[0], 0, 0x400F);
    D_0088649C[0] = (s32)(D_008864A0[0] + 0xF) & ~0xF;
increment:
    D_008864B0[0] += 1;
    return arg0;
}
