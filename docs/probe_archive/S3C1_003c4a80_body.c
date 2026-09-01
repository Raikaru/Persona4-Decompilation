/* object 272B/window 320B normalized_diff 125; differing words 56; first differing offsets 16-23,26,30,33-34,38,41-42; instruction deficit 12 (undersized). Classification UNDERSIZED: retail saves s2/s1/s0 and has a duplicated successful-store/increment path; this transcription merged the growth and append tails. Prologue saved-register count 3 (s2,s1,s0); arguments (u8 *arg0, s32 arg1). Block-scope declarations: D_008873F0 as absolute pointer array, func_003df590(s32,s32), func_003df4d0(s32 *). schedule + no_branch_likely measured. The prior archived body was oversized; no live body retained. */
s32 func_003c4a80(u8 *arg0, s32 arg1) {
    extern u8 *D_008873F0[];
    extern s32 func_003df590(s32 arg0, s32 arg1);
    extern void func_003df4d0(s32 *arg0);
    u8 *self;
    s32 index;
    s32 size;
    u8 *result;
    s32 stack[2];

    self = arg0;
    index = *(s32 *)(self + 4);
    if (index < *(s32 *)(self + 8))
        goto append;
    size = (*(s32 *)(self + 8) + 20) * 4;
    if (*(u8 **)self != NULL)
        result = ((u8 *(*)(u8 *, s32, s32))D_008873F0[0])(*(u8 **)self, size, 0x01030008);
    else
        result = ((u8 *(*)(u8 *, s32))jtbl_008873E8[0])((u8 *)size, 0x01030008);
    if (result == NULL)
        goto failure;
    *(u8 **)self = result;
    *(s32 *)(self + 8) = *(s32 *)(self + 8) + 20;
    *(u8 **)(result + (*(s32 *)(self + 4) * 4)) = (u8 *)arg1;
    goto increment;
append:
    *(u8 **)(*(u8 **)self + (index * 4)) = (u8 *)arg1;
increment:
    *(s16 *)((u8 *)arg1 + 0x18) += 1;
    *(s32 *)(self + 4) += 1;
    return *(s32 *)(self + 4) - 1;
failure:
    stack[0] = 2;
    stack[1] = func_003df590(0x80000013, size);
    func_003df4d0(stack);
    return -1;
}
