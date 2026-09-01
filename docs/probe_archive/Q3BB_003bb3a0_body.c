/* object 296B/window 256B, normalized_diff 216; differing offsets 16-? with object oversized by 40B; classification: switch/stack aggregate/branch layout residual. Retail frame 0x50 saves $s0-$s2 and uses two s32 error pairs at sp+0x40/0x48; candidate uses same logical pair diagnostics but over-expands. Corrected func_003df590 variadic and absolute D_0070AF50 pointer. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor. Source restored to INCLUDE_ASM.
u8 *func_003bb3a0(u8 *arg0, s32 arg1, u8 *arg2) {
    extern s32 func_003df590(s64 arg0, ...);
    extern void func_003df4d0(s32 *arg0);
    extern u8 D_0070AF50[];
    s32 error_pair[2];
    s32 pair[2];
    s32 temp_3;
    s32 result;
    u8 *temp_3_2;

    if (arg1 < 0) goto block_9;
    temp_3 = *(s32 *)(arg0 + 0xC);
    switch (temp_3) {
    case 1: result = *(s32 *)(arg0 + 8) - 2; break;
    case 2: result = *(s32 *)(arg0 + 8) - 3; break;
    default:
        pair[0] = 0x102;
        pair[1] = func_003df590(1);
        func_003df4d0(pair);
        result = 0;
        break;
    }
    if (arg1 < result) {
        temp_3_2 = *(u8 **)(arg0 + 0x14) + arg1 * 0xC;
        *(f32 *)(arg2 + 0) = *(f32 *)(temp_3_2 + 0);
        *(f32 *)(arg2 + 4) = *(f32 *)(temp_3_2 + 4);
        *(f32 *)(arg2 + 8) = *(f32 *)(temp_3_2 + 8);
        return arg2;
    }
block_9:
    error_pair[0] = 0x102;
    error_pair[1] = func_003df590(0x80000003, D_0070AF50);
    func_003df4d0(error_pair);
    return NULL;
}
