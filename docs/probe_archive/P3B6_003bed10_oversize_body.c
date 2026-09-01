/* object 392B/window 368B, normalized_diff 278; differing byte offsets begin 4,6-34 and continue through 388; classification object oversized, archive immediately. Candidate matched retail frame 0x70 but emitted a longer control-flow/loop sequence. Corrected block-scope declarations: func_003c2c90(u8 *), func_003c2cf0(u8 *,s32), func_003deff0(s32,s32,s32,s32,s32), func_003e2ab0(s32,s32 *,s32). No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
u8 *func_003bed10(u8 *arg0, s32 arg1) {
    extern s32 func_003c2c90(u8 *arg0);
    extern s32 func_003c2cf0(u8 *arg0, s32 arg1);
    extern s32 func_003deff0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 func_003e2ab0(s32 arg0, s32 *arg1, s32 arg2);
    s32 total;
    s32 index;
    s32 offset;
    s32 count;

    total = 0x10;
    index = 0;
    if (*(s32 *)(arg0 + 4) > 0) {
        offset = 0;
        do {
            total += func_003c2c90(*(u8 **)(*(u8 **)arg0 + offset)) + 0xC;
            index += 1;
            offset += 4;
        } while (index < *(s32 *)(arg0 + 4));
    }
    if (func_003deff0(arg1, 0x1A, total, 0x37002, 0x37) == 0) {
        return NULL;
    }
    if (func_003deff0(arg1, 1, 4, 0x37002, 0x37) == 0) {
        return NULL;
    }
    count = *(s32 *)(arg0 + 4);
    if (func_003e2ab0(arg1, &count, 4) == 0) {
        return NULL;
    }
    index = 0;
    if (count > 0) {
        offset = 0;
        do {
            if (func_003c2cf0(*(u8 **)(*(u8 **)arg0 + offset), arg1) == 0) {
                return NULL;
            }
            index += 1;
            offset += 4;
        } while (index < count);
    }
    return arg0;
}
