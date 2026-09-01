/* object 124B/window 128B, normalized_diff 94; differing word offsets 4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120. Residual is preheader register assignment/order (retail slt/lw/addiu sequence versus candidate blez/addiu/lw), pointer register coloring through the loop, and branch orientation. Ruled out: direct loop reconstruction, declaration-order permutations, explicit positive/named-boolean guard, schedule on/off, no_branch_likely on/off, and pointer-typed stride probe. */
void func_003b64c0(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 count;
    u8 *src1;
    s32 stride;
    u8 *src0;
    u8 *dest;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    f32 value;

    dest = *(u8 **)arg0;
    stride = *(s32 *)(arg0 + 4);
    src0 = arg2 + 0x90;
    src1 = arg2 + 0x98;
    count = 0;
    if (arg1 > 0) {
        do {
            value = *(f32 *)(src0 + 0);
            p1 = dest + stride;
            p2 = p1 + stride;
            count += 1;
            p3 = p2 + stride;
            *(f32 *)(dest + 0) = value;
            value = *(f32 *)(src1 + 4);
            *(f32 *)(dest + 4) = value;
            value = *(f32 *)(src1 + 0);
            dest = p3;
            *(f32 *)(p1 + 0) = value;
            value = *(f32 *)(src1 + 4);
            *(f32 *)(p1 + 4) = value;
            value = *(f32 *)(src0 + 0);
            *(f32 *)(p2 + 0) = value;
            value = *(f32 *)(src0 + 4);
            *(f32 *)(p2 + 4) = value;
            value = *(f32 *)(src0 + 0);
            *(f32 *)(p3 + 0) = value;
            value = *(f32 *)(src0 + 4);
            *(f32 *)(p3 + 4) = value;
        } while (count < arg1);
    }
}
