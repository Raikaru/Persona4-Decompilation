/* object 476B / window 496B / normalized_diff 290; block-scope corrected callee declarations for the six census disagreements were measured once with no codegen movement; the 0x80 frame and 20B object deficit ruled out further grinding. */
u8 *func_0025ef20(u8 *arg0)
{
    u8 *func_0046b1f0(u8 *, u32);
    u8 *func_0046d5f0(u8 *, s32);
    u8 *func_0046af60(u32);
    u8 *func_00455f70(s32, s32 *);
    void *func_0046d730(void *, s32);
    s32 func_0046a750(s16 *);
    s32 count;
    s32 index;
    s32 offset;
    s32 length;
    s32 size;
    s32 totalSize;
    u8 *result;
    u8 *data;
    u8 *src;
    u8 *cursor;
    u8 *extra;

    size = 0x10;
    index = 0;
    for (;;) {
        count = *(s32 *)(arg0 + 4);
        if (index >= count) {
            break;
        }
        offset = index * 4;
        length = func_00442948(
            *(const char **)((u8 *)(u32)(*(s32 *)arg0) + offset));
        size += length + 1;
        index += 1;
    }
    totalSize = count * 8 + *(s32 *)(arg0 + 0xC) * 8 + 0x14 +
        size + (size & 1);
    func_0044ea90(&D_00637280, 0x7E);
    result = D_008873F4[0](1, totalSize, 0x40000);
    *(s32 *)result = 0;
    data = result + 0x14;
    *(u8 **)(result + 4) = data;
    *(u8 **)(result + 8) = data + 0x10;
    func_0043f810(*(void **)(result + 4), arg0, 0x10);
    src = *(u8 **)(result + 8) + count * 4;
    *(u8 **)(*(u8 **)(result + 4)) = src;
    cursor = src + count * 4;
    index = 0;
    for (;;) {
        count = *(s32 *)(arg0 + 4);
        if (index >= count) {
            break;
        }
        offset = index * 4;
        src = *(u8 **)((u8 *)(u32)(*(s32 *)arg0) + offset);
        length = func_00442948((const char *)src) + 1;
        func_0043f810(cursor, src, length);
        *(u8 **)(*(u8 **)(result + 4) + offset) = cursor;
        cursor += length;
        index += 1;
    }
    if (((u32)cursor & 1) != 0) {
        cursor += 1;
    }
    extra = *(u8 **)(arg0 + 8);
    if (extra != NULL) {
        func_0043f810(cursor, extra, *(s32 *)(arg0 + 0xC) * 8);
        *(u8 **)(*(u8 **)(result + 4) + 8) = cursor;
        *(u8 **)(result + 0xC) = *(u8 **)(*(u8 **)(result + 4) + 8);
    }
    *(s32 *)(result + 0x10) = *(s32 *)(arg0 + 0xC);
    return result;
}
