/* object 220B/window 224B, normalized_diff 147; differing offsets 4-208 with retail-only final 4B epilogue padding. Classification: source branch/return layout and saved-register coloring residual; frame is 0x40 with exactly three saved registers ($s0-$s2). Corrected func_003df240 calls to three arguments (arg0, descriptor field, 4), corrected byte offsets on temp descriptor, and block-scope func_003e2ab0(s32,s32,s32). No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor. Source restored to INCLUDE_ASM.
s32 *func_003b71b0(s32 *arg0, u8 *arg1) {
    extern s32 func_003e2ab0(s32 arg0, s32 arg1, s32 arg2);
    u8 *saved_arg1;
    u8 *temp_17;
    s32 *saved_arg0;

    saved_arg1 = arg1;
    temp_17 = saved_arg1 + 0x2C;
    saved_arg0 = arg0;
    if (func_003df240((s32)saved_arg0, (s32)temp_17, 4) == 0) {
        goto block_9;
    }
    if (func_003df240((s32)saved_arg0, (s32)(temp_17 + 4), 4) == 0) {
        goto block_9;
    }
    if (func_003df240((s32)saved_arg0, (s32)(temp_17 + 8), 4) != 0) {
        if (*(s32 *)(saved_arg1 + 0x30) == 0) {
            goto block_6;
        }
        if (func_003e2ab0(
                (s32)saved_arg0,
                *(s32 *)(temp_17 + 0xC),
                *(s32 *)saved_arg1 + (*(s32 *)(temp_17 + 4) * 2) +
                    (*(s32 *)(temp_17 + 8) * 2)) == 0) {
            goto block_9;
        }
block_6:
        return saved_arg0;
    }
block_9:
    return NULL;
}
