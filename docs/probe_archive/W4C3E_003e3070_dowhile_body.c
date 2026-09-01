s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
        do {
            if (*(s32 *)(node + 8) == arg1) {
                break;
            }
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    if (node != NULL) {
        *(s32 *)(node + 0x18) = arg2;
        return *(s32 *)node;
    }
    return -1;
}
