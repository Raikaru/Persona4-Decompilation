s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node == NULL) goto fail;
scan:
    if (*(s32 *)(node + 8) == arg1) goto found;
    node = *(u8 **)(node + 0x30);
    if (node == NULL) goto fail;
    goto scan;
found:
    *(s32 *)(node + 0x18) = arg2;
    return *(s32 *)node;
fail:
    return -1;
}
