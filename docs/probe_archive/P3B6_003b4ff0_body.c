/* object 304B/window 368B, normalized_diff 242; differing byte offsets 0,2-8,10,12-22 and continuing through 300 (92 differing words); classification residual in hundreds, archive immediately. Full 8-argument custom ABI signature used: (u8 *,u8 *,u8 *,s32,u8 *,f32,f32,f32), with source/aux/output stride fields reconstructed from retail. No callees to correct. Candidate emitted ordinary mul/add/sub only, with no movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor; FPU scheduling/register coloring and output-store ordering remained divergent. */
void func_003b4ff0(
    u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4,
    f32 arg5, f32 arg6, f32 arg7
) {
    u8 *out;
    s32 out_stride;
    u8 *source;
    s32 source_stride;
    u8 *aux;
    s32 aux_stride;
    s32 index;
    u8 *out1;
    u8 *out2;
    u8 *out3;
    f32 aux0;
    f32 aux1;
    f32 half_aux0;
    f32 half_aux1;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 q0;
    f32 q1;
    f32 q2;
    f32 np0;
    f32 np1;
    f32 np2;
    f32 source0;
    f32 source1;
    f32 source2;

    out = *(u8 **)arg0;
    out_stride = *(s32 *)(arg0 + 4);
    source = *(u8 **)(arg4 + 4);
    source_stride = *(s32 *)(arg4 + 8);
    aux = *(u8 **)(arg4 + 0x1C);
    aux_stride = *(s32 *)(arg4 + 0x20);
    index = 0;
    if (arg3 > 0) {
        do {
            out1 = out + out_stride;
            out2 = out1 + out_stride;
            out3 = out2 + out_stride;
            aux0 = *(f32 *)(aux + 0);
            aux1 = *(f32 *)(aux + 4);
            aux += aux_stride;
            half_aux0 = 0.5f * aux0;
            half_aux1 = 0.5f * aux1;
            p0 = *(f32 *)(arg1 + 0) * half_aux0;
            p1 = *(f32 *)(arg1 + 4) * half_aux0;
            p2 = *(f32 *)(arg1 + 8) * half_aux0;
            q0 = *(f32 *)(arg2 + 0) * half_aux1;
            q1 = *(f32 *)(arg2 + 8) * half_aux1;
            q2 = *(f32 *)(arg2 + 4) * half_aux1;
            np0 = -p0;
            np1 = -p1;
            np2 = -p2;
            source0 = *(f32 *)(source + 0);
            source1 = *(f32 *)(source + 4);
            source2 = *(f32 *)(source + 8);
            *(f32 *)(out + 0) = source0 + np0 - q0;
            *(f32 *)(out + 4) = source1 + np1 - q2;
            *(f32 *)(out + 8) = source2 + np2 - q1;
            *(f32 *)(out1 + 0) = source0 + p0 - q0;
            *(f32 *)(out1 + 4) = source1 + p1 - q2;
            *(f32 *)(out1 + 8) = source2 + p2 - q1;
            *(f32 *)(out2 + 0) = source0 + p0 + q0;
            *(f32 *)(out2 + 4) = source1 + p1 + q2;
            *(f32 *)(out2 + 8) = source2 + p2 + q1;
            *(f32 *)(out3 + 0) = source0 + np0 + q0;
            *(f32 *)(out3 + 4) = source1 + np1 + q2;
            *(f32 *)(out3 + 8) = source2 + np2 + q1;
            out = out3 + out_stride;
            source += source_stride;
            index += 1;
        } while (index < arg3);
    }
}
