// object 400B/window 448B/normalized_diff 81
// differing offsets: prologue frame size (-0x60 vs -0x70) due to missing
//   dead stores sp+0x60/0x64/0x68, constant materialisation order, and
//   post-call schedule around func_003c54a0 and the D_008872E0 loads.
// levers ruled out: #pragma schedule on, #pragma no_branch_likely on,
//   local copy of arg0/state, declaration-order permutations, reuse of a
//   single temp for temp_2_3/4/5, including dead s32 sp60/sp64/sp68
//   (compiler eliminated them under -O2,p).
// remaining: the dead stack stores and the exact constant scheduling are
//   not reproduced; this looks like a scheduling floor.
s32 func_003a8340(u8 *arg0, s32 arg1)
{
    extern u8 *func_003c2630(s32, s32, s32);
    extern s32 func_003c22f0(u8 *);
    extern u8 *func_003c4140(void);
    extern u8 *func_003c54a0(s32, s32);
    extern s16 func_003c6060();
    extern void func_003c4a80(u8 *, u8 *);
    extern void func_003c4220(u8 *);
    extern void func_003c0210(u8 *, u8 *, s32);
    extern void func_003c2a80(u8 *);
    u8 *node;
    u8 *old_sub;
    u8 *frame;
    u8 *sub;
    s32 temp_4;
    s32 temp_7;
    u8 temp_5;
    u8 *temp_6;
    s32 sp60;
    s32 sp64;
    s32 sp68;

    node = func_003c2630(0, 0, 0);
    if (node != NULL) {
        old_sub = *(u8 **)(node + 0x5C);
        *(s32 *)(old_sub + 4) = 0;
        *(s32 *)(old_sub + 8) = 0;
        *(s32 *)(old_sub + 0xC) = 0;
        *(s32 *)(old_sub + 0x10) = 0x3F800000;
        if (func_003c22f0(node) != 0) {
            goto proceed;
        }
    }
    return 0;
proceed:
    frame = func_003c4140();
    *(s32 *)(frame + 0xC) = 0x3E99999A;
    *(s32 *)(frame + 0x10) = 0x3F800000;
    sp60 = 0x3E99999A;
    sp68 = 0x3F800000;
    sp64 = 0x3F800000;
    *(s32 *)(frame + 0x14) = 0x3F800000;
    sub = func_003c54a0(0x1C, 0x3E99999A);
    temp_7 = iGpffffb6f0;
    temp_6 = &D_008872E0[temp_7];
    temp_5 = temp_6[0x2D];
    *(s32 *)sub = ((*(s32 *)sub & ~0xFF) | temp_5);
    temp_4 = *(s32 *)sub | 0x100;
    *(s32 *)sub = temp_4;
    *(s16 *)(sub + 4) = 1;
    *(s16 *)(sub + 6) = func_003c6060(temp_4, temp_5, temp_6, temp_7);
    *(s32 *)(sub + 0xC) = 0;
    *(s32 *)(sub + 8) = 0;
    *(s32 *)(sub + 0x14) = arg1 * 4;
    *(s32 *)(sub + 0x10) = 0;
    *(u8 **)(sub + 0x18) = frame;
    *(u8 **)(node + 0x54) = sub;
    *(s32 *)(frame + 0x8) = *(s32 *)(*(s32 *)(&D_008872E0[iGpffffb614]) + 0xC);
    if (frame != NULL) {
        func_003c4a80(node + 0x20, frame);
        func_003c4220(frame);
        func_003c0210(arg0, node, 0);
        *(s32 *)(arg0 + 0x6C) = *(s32 *)(*(s32 *)(&D_008872E0[iGpffffb614]) + 0x10);
        func_003c2a80(node);
        return 1;
    }
    return 0;
}
