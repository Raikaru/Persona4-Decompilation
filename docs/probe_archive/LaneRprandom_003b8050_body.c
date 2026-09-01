/* Closest plain-C candidate for func_003b8050; retained after scoped lverify mismatch (object 596/608, nd 231). */
u8 *func_003b8050(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    u8 *object;
    s32 count;
    s32 header;
    u8 *resource;
    s32 loop_count;
    s32 offset;
    u8 temp_70[264];
    u32 sp178;
    u32 sp17c;
    u8 *result;

    object = *(u8 **)(arg2 + 0x18);
    if (func_003b83f0((s32)object) != 0) {
        if (func_003e2ce0(arg0, arg4) == 0) {
            result = NULL;
            goto block_done;
        }
        goto block_4;
    }
    if (func_003df360(arg0, &sp17c, 4) == 0) {
        result = NULL;
        goto block_done;
    }
    count = *(s32 *)(object + 0x14);
    header = sp17c;
    sp178 = header;
    resource = D_008873F8[0](D_008864A8[0], 0x30116);
    func_0043f9c8(resource, 0, 0x48);
    if (sp178 == 0) {
        func_003b7590(resource, NULL, NULL, temp_70, &sp178, count);
    }
    if (func_003b7680(resource, header, sp178, count,
                      temp_70, NULL, NULL, 0) == 0) {
        goto block_cleanup;
    }
block_post:
    if (func_003e2ce0(arg0, 4) == 0) {
        result = NULL;
        goto block_done;
    }
    if (func_003df360(arg0, *(void **)(resource + 0x14), count * 4) == 0) {
        result = NULL;
        goto block_done;
    }
    if (func_003df300(arg0, *(void **)(resource + 0x18), count * 0x10) == 0) {
        result = NULL;
        goto block_done;
    }
    if (*(u32 *)resource == 0) {
        goto block_19;
    }
    loop_count = 0;
    offset = 0;
    while (1) {
        if (func_003e2ce0(arg0, 12) == 0) {
            result = NULL;
            goto block_done;
        }
        if (func_003df300(arg0, *(u8 **)(resource + 0x0C) + offset, 0x40) == 0) {
            result = NULL;
            goto block_done;
        }
        loop_count++;
        offset += 0x40;
        if (loop_count >= *(u32 *)resource) {
            break;
        }
    }
block_19:
    func_003b7510(resource, *(u32 *)(resource + 0x18), count);
    func_003b7590(resource, *(void **)(resource + 0x14),
                  *(void **)(resource + 0x18), *(void **)(resource + 8),
                  (void *)(resource + 4), count);
    func_003b8410(object, resource);
    goto block_4;
block_cleanup:
    jtbl_008873FC[0](D_008864A8[0], resource);
    resource = NULL;
    goto block_post;
block_4:
    result = arg0;
block_done:
    return result;
}
