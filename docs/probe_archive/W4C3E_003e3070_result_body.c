#pragma schedule on
s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *node;
    s32 result;

    node = *(u8 **)(arg0 + 0x10);
    if (node != NULL) {
scan:
        if (*(s32 *)(node + 8) != arg1) {
            node = *(u8 **)(node + 0x30);
            if (node == NULL) {
            } else {
                goto scan;
            }
        }
    }
    if (node != NULL) {
        *(s32 *)(node + 0x18) = arg2;
        result = *(s32 *)node;
        return result;
    }
    return -1;
}
#pragma schedule off
