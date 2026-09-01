/* object 300B vs window 288B, normalized_diff 191, differing offsets first reported 0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x19,0x1d,0x2c,0x2d,0x2e,0x30,0x32,0x33; classification oversized candidate/different function; ruled out further reordering after automatic archive threshold. */
/* Candidate attempted typed byte-pointer translation of the M2C loop, with block-scope old-style helper declarations and explicit goto-shaped cleanup/allocation paths. */

u8 *func_003d7490(u8 *arg0)
{
    extern void func_003e0f40();
    extern u8 *func_003e0f80();
    u8 **slot;
    u8 *slot_value;
    s32 found;
    u32 outer;
    u32 index;
    u32 resource;
    u8 *entry;
    u8 *object;
    u32 offset;

    outer = 0;
    slot = (u8 **)arg0;
loop_1:
    resource = 0;
    index = 0;
    found = 0;
loop_2:
    entry = *(u8 **)((u8 *)arg0 + (resource * 4) + 8);
    if (entry != NULL) {
        object = *(u8 **)entry;
        offset = index * 4;
        if (outer != *(u32 *)(*(u8 **)(object + 0x14) + offset + 0x20)) {
            index += 1;
            if (index >= *(u32 *)(entry + 0x2C)) {
                index = 0;
                resource += 1;
            }
            goto block_6;
        }
        found = 1;
    } else {
        resource += 1;
block_6:
        if (resource < 8U) {
            goto loop_2;
        }
    }
    if (found != 0) {
        goto block_found;
    }
    if (found != 0) {
        goto block_after;
    }
    slot_value = *slot;
    if (slot_value != NULL) {
        func_003e0f40(slot_value, found, index, resource);
        *slot = NULL;
    }
    goto block_after;
block_found:
    if (*slot != NULL) {
        goto block_after;
    }
    *slot = (u8 *)func_003e0f80(entry, found, index, resource);
    if (*slot != NULL) {
        goto block_after;
    }
    return NULL;
block_after:
    outer += 1;
    slot += 1;
    if (outer < 2U) {
        goto loop_1;
    }
    return arg0;
}
