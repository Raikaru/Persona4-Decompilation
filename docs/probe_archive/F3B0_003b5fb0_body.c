/* object 112B/window 112B, normalized_diff 26; differing word offsets 0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,104 (fndiff reloc-masked). Best current-TU probe used opt_propagation off; declaration-order, signed pointer, stride-local, loop-shape, schedule, optimization-level 1, and guard-rebuild variants were ruled out. */
#pragma opt_propagation off
void func_003b5fb0(u8 *arg0, s32 arg1, u8 *arg2) {
    u8 *src_entry;
    u8 *dst1;
    u8 *dst2;
    u8 *dst3;
    u8 *src;
    u8 *dst;
    s32 dst_stride;
    s32 src_stride;
    s32 value;
    s32 index;
    s32 positive;

    dst = *(u8 **)arg0;
    positive = 0 < arg1;
    if (positive == 0) {
        return;
    }
    dst_stride = *(s32 *)(arg0 + 4);
    src = *(u8 **)(arg2 + 0x2C);
    src_stride = *(s32 *)(arg2 + 0x30);
    index = 0;
    do {
        src_entry = src;
        dst1 = dst + dst_stride;
        value = *(s32 *)(src_entry + 0);
        dst2 = dst1 + dst_stride;
        index += 1;
        dst3 = dst2 + dst_stride;
        src += src_stride;
        *(s32 *)dst = value;
        dst = dst3 + dst_stride;
        *(s32 *)dst1 = *(s32 *)(src_entry + 4);
        *(s32 *)dst2 = *(s32 *)(src_entry + 8);
        *(s32 *)dst3 = *(s32 *)(src_entry + 0xC);
    } while (index < arg1);
}
#pragma opt_propagation on
