/* object 372B/window 352B, normalized_diff 257; differing byte offsets begin 0,4,8,10 and continue through 368; classification object oversized, archive immediately. Candidate used u8 * ABI (u8 *,u8 *), absolute jtbl_008873E8 allocator, func_003bfe60, func_003c2a60, and the linked-list duplicate scan, but emitted a 0x90 frame versus retail 0x80 and divergent saved-register/lifetime ordering. No movz/movn, COP1 accumulator, standalone MMI, or framed tail-jump floor observed. */
u8 *func_003bebb0(u8 *arg0, u8 *arg1) {
    extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
    extern s32 func_003c2a60(s32 arg0, s32 arg1);
    s32 alloc_size;
    s32 count;
    s32 id;
    s32 index;
    s32 found;
    s32 error_id;
    s32 error_value;
    s32 *items;
    s32 *scan;
    s32 *write;
    u8 *sentinel;
    u8 *node;

    alloc_size = func_003bfe60(arg1);
    if (alloc_size <= 0) {
        *(s32 **)arg0 = NULL;
        goto initialize;
    }
    alloc_size *= 4;
    *(s32 **)arg0 = (s32 *)jtbl_008873E8[0](alloc_size, 0x3000F);
    if (*(s32 **)arg0 == NULL) {
        error_id = 2;
        error_value = func_003df590(0x80000013, alloc_size);
        func_003df4d0(&error_id);
        return NULL;
    }
initialize:
    *(s32 *)(arg0 + 4) = 0;
    sentinel = arg1 + 8;
    node = *(u8 **)(arg1 + 8);
    items = *(s32 **)arg0;
    write = items;
    if (node != sentinel) {
        do {
            count = *(s32 *)(arg0 + 4);
            id = *(s32 *)(node - 0x28);
            index = 0;
            found = 0;
            if (count > 0) {
                scan = items;
                do {
                    if (*scan == id) {
                        found = 1;
                        break;
                    }
                    index += 1;
                    scan += 1;
                } while (index < count);
            }
            if (found == 0) {
                func_003c2a60(id, index);
                *write = id;
                write += 1;
                *(s32 *)(arg0 + 4) = count + 1;
            }
            node = *(u8 **)node;
        } while (node != sentinel);
    }
    return arg0;
}
