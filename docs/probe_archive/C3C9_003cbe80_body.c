/* object 160 bytes, window 176 bytes, normalized_diff 57. */
u8 *func_003cbe80(u8 *arg0, u8 *arg1) {
    u8 *self;
    u8 *obj;
    u8 *link;
    u8 *temp;
    u8 *obj_link;
    s32 *next;

    self = arg0;
    *(s32 *)(arg1 + iGpffffb714) = (s32)self;
    obj = arg1;
    if (*(u8 *)(obj + 1) < 0x80)
        goto low;
    next = *(s32 **)(obj + 4);
    if (next != NULL)
        func_003e9680((u8 *)next);
    link = *(u8 **)(self + 0x34);
    temp = self + 0x34;
    obj_link = obj + 0x34;
    *(u8 **)(obj_link) = link;
    *(u8 **)(obj_link + 4) = temp;
    *(u8 **)(*(u8 **)(self + 0x34) + 4) = obj_link;
    *(u8 **)(self + 0x34) = obj_link;
    goto done;
low:
    link = *(u8 **)(self + 0x3c);
    temp = self + 0x3c;
    obj_link = obj + 0x34;
    *(u8 **)(obj_link) = link;
    *(u8 **)(obj_link + 4) = temp;
    *(u8 **)(*(u8 **)(self + 0x3c) + 4) = obj_link;
    *(u8 **)(self + 0x3c) = obj_link;
done:
    return self;
}
