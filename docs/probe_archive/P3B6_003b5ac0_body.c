/* object 296B/window 304B, normalized_diff 237; differing byte offsets 4-284 (fndiff reports 73 differing words); classification residual in hundreds, archive immediately. Full 8-argument custom ABI signature used: (u8 *,u8 *,u8 *,s32,u8 *,f32,f32,f32), with block-independent arg1/arg2/float args unused as in the function-pointer table. Reconstructed output-stride loop and 0.5f arithmetic from retail. Candidate lacked retail's exact initialization/scheduling and emitted the wrong FPU/load/store order. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
void func_003b5ac0(
    u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4,
    f32 arg5, f32 arg6, f32 arg7
) {
    u8 *out;
    s32 stride;
    u8 *src;
    s32 src_stride;
    s32 index;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    f32 f;
    f32 half_a;
    f32 half_c;
    f32 half_b;
    f32 half_d;
    f32 half_e;
    f32 half_f;
    f32 sum_a;
    f32 diff_a;
    f32 sum_d;
    f32 diff_d;
    f32 sum_b;
    f32 diff_b;

    out = *(u8 **)arg0;
    stride = *(s32 *)(arg0 + 4);
    src = *(u8 **)(arg4 + 0xC);
    src_stride = *(s32 *)(arg4 + 0x10);
    index = 0;
    if (arg3 > 0) {
        do {
            u8 *out1;
            u8 *out2;
            u8 *out3;
            u8 *src_next;

            out1 = out + stride;
            out2 = out1 + stride;
            out3 = out2 + stride;
            src_next = src + 0x30;
            a = *(f32 *)(src + 0);
            b = *(f32 *)(src + 8);
            c = *(f32 *)(src + 16);
            d = *(f32 *)(src + 4);
            e = *(f32 *)(src + 20);
            f = *(f32 *)(src + 24);
            half_a = 0.5f * a;
            half_c = 0.5f * c;
            half_b = 0.5f * b;
            half_d = 0.5f * d;
            half_e = 0.5f * e;
            half_f = 0.5f * f;
            sum_a = half_a + half_c;
            diff_a = half_a - half_c;
            sum_d = half_d + half_e;
            diff_d = half_d - half_e;
            sum_b = half_b + half_f;
            diff_b = half_b - half_f;
            *(f32 *)(out + 0) = *(f32 *)(src_next + 0) + diff_a;
            *(f32 *)(out + 4) = *(f32 *)(src_next + 4) + diff_d;
            *(f32 *)(out + 8) = *(f32 *)(src_next + 8) + diff_b;
            *(f32 *)(out1 + 0) = *(f32 *)(src_next + 0) - sum_a;
            *(f32 *)(out1 + 4) = *(f32 *)(src_next + 4) - sum_d;
            *(f32 *)(out1 + 8) = *(f32 *)(src_next + 8) - sum_b;
            *(f32 *)(out2 + 0) = *(f32 *)(src_next + 0) - diff_a;
            *(f32 *)(out2 + 4) = *(f32 *)(src_next + 4) - diff_d;
            *(f32 *)(out2 + 8) = *(f32 *)(src_next + 8) - diff_b;
            *(f32 *)(out3 + 0) = *(f32 *)(src_next + 0) + sum_a;
            *(f32 *)(out3 + 4) = *(f32 *)(src_next + 4) + sum_d;
            *(f32 *)(out3 + 8) = *(f32 *)(src_next + 8) + sum_b;
            out = out3 + stride;
            src += src_stride;
            index += 1;
        } while (index < arg3);
    }
}
