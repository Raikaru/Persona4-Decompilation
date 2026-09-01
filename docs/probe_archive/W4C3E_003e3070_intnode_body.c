s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    s32 node;

    node = *(s32 *)(arg0 + 0x10);
    if (node != 0) {
loop_1:
        if (*(s32 *)((u8 *)node + 8) != arg1) {
            node = *(s32 *)((u8 *)node + 0x30);
            if (node == 0) {
            } else {
                goto loop_1;
            }
        }
    }
    if (node != 0) {
        *(s32 *)((u8 *)node + 0x18) = arg2;
        return *(s32 *)((u8 *)node + 0);
    }
    return -1;
}
