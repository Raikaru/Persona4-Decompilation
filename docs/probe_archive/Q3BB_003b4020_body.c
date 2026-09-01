/* object 240B/window 256B, normalized_diff 140; differing offsets 4-20,24-136,144-164,176-232, and tail; classification: aggregate/loop source ordering residual with a short candidate, not a compiler-floor signature. Retail frame 0x30 has $ra at sp+0 and eight f32 stack slots at sp+0x10..0x2c; corrected func_003a4ab0 to three arguments (u8*,s32,u8*) instead of the raw candidate's extra stride argument. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or other confirmed floor. Source restored to INCLUDE_ASM.
void func_003b4020(u8 *arg0, s32 arg1, u8 *arg2) {
    extern void func_003a4ab0(u8 *arg0, s32 arg1, u8 *arg2);
    f32 values[8];
    s32 stride;
    s32 count;
    u8 *src_0;
    u8 *src_1;
    u8 *dst_3;
    u8 *dst_2;
    u8 *dst_1;
    u8 *dst;

    stride = *(s32 *)(arg0 + 4);
    if (stride != 0x10) {
        dst = *(u8 **)arg0;
        src_0 = arg2 + 0x90;
        src_1 = arg2 + 0x98;
        count = 0;
        if (arg1 > 0) {
            do {
                dst_1 = dst + stride;
                dst_2 = dst_1 + stride;
                count += 1;
                dst_3 = dst_2 + stride;
                *(f32 *)(dst + 0) = *(f32 *)(src_0 + 0);
                *(f32 *)(dst + 4) = *(f32 *)(src_1 + 4);
                dst = dst_3 + stride;
                *(f32 *)(dst_1 + 0) = *(f32 *)(src_1 + 0);
                *(f32 *)(dst_1 + 4) = *(f32 *)(src_1 + 4);
                *(f32 *)(dst_2 + 0) = *(f32 *)(src_1 + 0);
                *(f32 *)(dst_2 + 4) = *(f32 *)(src_0 + 4);
                *(f32 *)(dst_3 + 0) = *(f32 *)(src_0 + 0);
                *(f32 *)(dst_3 + 4) = *(f32 *)(src_0 + 4);
            } while (count < arg1);
        }
    } else {
        values[0] = *(f32 *)(arg2 + 0x90);
        values[1] = *(f32 *)(arg2 + 0x9C);
        values[2] = *(f32 *)(arg2 + 0x98);
        values[3] = *(f32 *)(arg2 + 0x9C);
        values[4] = *(f32 *)(arg2 + 0x98);
        values[5] = *(f32 *)(arg2 + 0x94);
        values[6] = *(f32 *)(arg2 + 0x90);
        values[7] = *(f32 *)(arg2 + 0x94);
        func_003a4ab0(*(u8 **)arg0, *(s32 *)(arg0 + 4) * arg1 * 4,
                       (u8 *)values);
    }
}
