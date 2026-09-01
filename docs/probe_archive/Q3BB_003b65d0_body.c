/* object 168B/window 176B, normalized_diff 104; differing word offsets 2,4,5,6,7,8,10,12,13,14,15,16,18,19,20,22,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152; classification: structural loop register coloring and pointer/store ordering residual, not a compiler-floor signature. Confirmed retail has no stack frame or saved registers; argument first touches are arg0 destination descriptor, arg1 signed count, arg2 source descriptor. Ruled out movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump, and mixed-unit callee/global declaration defects. Best candidate retained here for reproducibility; source restored to INCLUDE_ASM.
void func_003b65d0(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 stride;
    s32 count;
    u8 *dst4;
    u8 *dst3;
    u8 *dst2;
    u8 *dst1;
    u8 *src;

    dst1 = *(u8 **)arg0;
    stride = *(s32 *)(arg0 + 4);
    src = *(u8 **)(arg2 + 0x14);
    count = 0;
    if (arg1 > 0) {
        do {
            dst2 = dst1 + stride;
            dst3 = dst2 + stride;
            count += 1;
            dst4 = dst3 + stride;
            *(f32 *)(dst1 + 0) = *(f32 *)(src + 0);
            *(f32 *)(dst1 + 4) = *(f32 *)(src + 4);
            *(f32 *)(dst1 + 8) = *(f32 *)(src + 8);
            dst1 = dst4 + stride;
            *(f32 *)(dst2 + 0) = *(f32 *)(src + 0);
            *(f32 *)(dst2 + 4) = *(f32 *)(src + 4);
            *(f32 *)(dst2 + 8) = *(f32 *)(src + 8);
            *(f32 *)(dst3 + 0) = *(f32 *)(src + 0);
            *(f32 *)(dst3 + 4) = *(f32 *)(src + 4);
            *(f32 *)(dst3 + 8) = *(f32 *)(src + 8);
            *(f32 *)(dst4 + 0) = *(f32 *)(src + 0);
            *(f32 *)(dst4 + 4) = *(f32 *)(src + 4);
            *(f32 *)(dst4 + 8) = *(f32 *)(src + 8);
            src += *(s32 *)(arg2 + 0x18);
        } while (count < arg1);
    }
}
