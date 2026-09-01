/* object 340B vs window 320B, normalized_diff 243, differing offsets first reported 0x00,0x04,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16-0x1c; classification oversized candidate/different function; ruled out further reordering after automatic archive threshold. */
/* Candidate attempted typed byte-pointer array traversal using iGpffffb748 and local helper prototypes. */

s32 func_003d7350(s32 arg0, s32 arg1)
{
    extern s32 func_003d5750(u8 *object);
    extern u8 *func_003d5790(s32 count, s32 stride);
    extern s32 func_003d59a0(u8 *dst, u8 *src);
    extern s32 func_003d7c50(u8 *object);
    extern void func_003d7cd0(u8 *object);
    s32 global_offset;
    s32 success;
    u32 cleanup_index;
    u32 index;
    u8 *source_entry;
    u8 *cleanup_entry;
    u8 *new_entry;
    u8 *object;
    u8 *source;
    u8 *base;
    u8 *dest;

    success = 1;
    index = 0;
    global_offset = iGpffffb748;
    base = (u8 *)(arg0 + global_offset);
    source = (u8 *)(arg1 + global_offset);
    dest = base;
loop_1:
    source_entry = *(u8 **)(source + 8);
    if (source_entry != NULL) {
        object = *(u8 **)(source_entry + 0);
        *(u8 **)(dest + 8) =
            func_003d5790(func_003d5750(object),
                          *(s32 *)(object + 4));
        new_entry = *(u8 **)(dest + 8);
        if (new_entry != NULL) {
            func_003d59a0(new_entry, source_entry);
            func_003d7cd0(object);
            goto block_4;
        }
        success = 0;
    } else {
        *(u8 **)(dest + 8) = NULL;
block_4:
        index += 1;
        source += 4;
        dest += 4;
        if (index < 8U) {
            goto loop_1;
        }
    }
    if (success != 0) {
        return arg0;
    }
    cleanup_index = 0;
    if (index != 0) {
        do {
            cleanup_entry = *(u8 **)(base + 8);
            if (cleanup_entry != NULL) {
                func_003d7c50(*(u8 **)(cleanup_entry + 0));
                func_003d5830(*(u8 **)(base + 8));
            }
            cleanup_index += 1;
            base += 4;
        } while (cleanup_index < index);
    }
    return 0;
}
