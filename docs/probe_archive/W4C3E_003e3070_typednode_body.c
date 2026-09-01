s32 func_003e3070(s32 *arg0, s32 arg1, s32 arg2) {
    s32 *node;

    node = (s32 *)arg0[4];
    if (node != NULL) {
loop_1:
        if (node[2] != arg1) {
            node = (s32 *)node[12];
            if (node == NULL) {
            } else {
                goto loop_1;
            }
        }
    }
    if (node != NULL) {
        node[6] = arg2;
        return node[0];
    }
    return -1;
}
