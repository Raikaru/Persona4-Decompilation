// FUN_003E3830
s32 func_003e3830(u8 *arg0, s32 arg1) {
    if (*(u8 **)(arg0 + 0x10) != NULL) {
        u8 *node = *(u8 **)(arg0 + 0x10);
        do {
            if (*(s32 *)(node + 8) == arg1) return *(s32 *)node;
            node = *(u8 **)(node + 0x30);
        } while (node != NULL);
    }
    return -1;
}
