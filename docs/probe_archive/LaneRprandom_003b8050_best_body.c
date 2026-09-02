/* Best measured probe for func_003b8050: object 596B / window 608B / 46 differing words. */
/* Retail saved-register assignment: s2=arg0, s1=object, s0=arg4 then count,
   s4=resource, s3=header then offset, s5=loop_count. Stack: input 0x17c,
   output 0x178, scratch temp_70 at 0x70. */
u8 *func_003b8050(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    u8 *object;
    s32 count;
    s32 header;
    u32 loop_count;
    u8 *resource;
    s32 offset;
    u8 temp_70[264];
    u32 input;
    u32 output;
    u8 has_blocks;

    object = *(u8 **)(arg2 + 0x18);
    if (func_003b83f0((s32)object) == 0) {
        goto parse_body;
    }
    if (func_003e2ce0(arg0, arg4) == 0) {
        goto fast_fail;
    }
    goto fast_success;
fast_fail:
    return NULL;
fast_success:
    return arg0;
parse_body:
    if (func_003df360(arg0, &input, 4) == 0) {
        goto fail_read;
    }
    count = *(s32 *)(object + 0x14);
    header = input;
    output = header;
    resource = D_008873F8[0](D_008864A8[0], 0x30116);
    func_0043f9c8(resource, 0, 0x48);
    if (output == 0) {
        func_003b7590(resource, NULL, NULL, temp_70, &output, count);
    }
    if (func_003b7680(resource, header, output, count,
                      temp_70, NULL, NULL, 0) == 0) {
        goto block_cleanup;
    }
block_post:
    if (func_003e2ce0(arg0, 4) == 0) {
        goto fail_post_read;
    }
    if (func_003df360(arg0, *(void **)(resource + 0x14), count * 4) == 0) {
        goto fail_post_table;
    }
    if (func_003df300(arg0, *(void **)(resource + 0x18), count * 0x10) == 0) {
        goto fail_post_records;
    }
    loop_count = 0;
    has_blocks = *(u32 *)resource != 0;
    if (has_blocks == 0) {
        goto block_19;
    }
    offset = 0;
    do {
        if (func_003e2ce0(arg0, 12) == 0) {
            goto fail_loop_read;
        }
        if (func_003df300(arg0, *(u8 **)(resource + 0x0C) + offset, 0x40) == 0) {
            goto fail_loop_block;
        }
        loop_count++;
        offset += 0x40;
    } while (loop_count < *(u32 *)resource);
block_19:
    func_003b7510(resource, *(u32 *)(resource + 0x18), count);
    func_003b7590(resource, *(void **)(resource + 0x14),
                  *(void **)(resource + 0x18), *(void **)(resource + 8),
                  (void *)(resource + 4), count);
    func_003b8410(object, resource);
    goto fast_success;
fail_read:
    return NULL;
block_cleanup:
    jtbl_008873FC[0](D_008864A8[0], resource);
    resource = NULL;
    goto block_post;
fail_post_read:
    return NULL;
fail_post_table:
    return NULL;
fail_post_records:
    return NULL;
fail_loop_read:
    return NULL;
fail_loop_block:
    return NULL;
}
