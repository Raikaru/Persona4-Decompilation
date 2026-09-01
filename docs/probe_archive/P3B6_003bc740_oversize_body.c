/* object 328B/window 320B, normalized_diff 167; differing byte offsets begin 0,4,8,10 and continue through 316; classification object oversized, archive immediately. Retail frame is 0x80 (ra+s0..s6 saves); candidate frame is 0x90 due local declaration/lifetime layout. Retail callback table is jtbl_008873EC and all cleanup paths were reconstructed, but saved-register mapping and callback/base loads differ. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
void func_003bc740(u8 *arg0) {
    s32 index;
    s32 offset;
    s32 inner_index;
    s32 count;
    u8 *base;
    u8 *entry;
    u8 *inner;

    base = *(u8 **)(arg0 + 4);
    if (base != NULL) {
        index = 0;
        count = *(s32 *)arg0;
        if (count > 0) {
            offset = 0;
            do {
                entry = base + offset;
                if (*(u8 **)entry != NULL) {
                    jtbl_008873EC[0](*(u8 **)entry);
                    *(u8 **)entry = NULL;
                }
                if (*(s32 *)(entry + 4) == 3) {
                    inner = *(u8 **)(entry + 0xC);
                    inner_index = 0;
                    if (*(s32 *)(entry + 8) > 0) {
                        do {
                            if (*(u8 **)inner != NULL) {
                                jtbl_008873EC[0](*(u8 **)inner);
                            }
                            inner_index += 1;
                            inner += 4;
                        } while (inner_index < *(s32 *)(entry + 8));
                    }
                }
                if (*(u8 **)(entry + 0xC) != NULL) {
                    jtbl_008873EC[0](*(u8 **)(entry + 0xC));
                    *(u8 **)(entry + 0xC) = NULL;
                }
                index += 1;
                offset += 0x10;
            } while (index < count);
        }
        jtbl_008873EC[0](base);
    }
    *(u8 **)(arg0 + 4) = NULL;
    *(s32 *)arg0 = 0;
}
