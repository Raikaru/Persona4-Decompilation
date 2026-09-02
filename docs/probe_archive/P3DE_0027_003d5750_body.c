/* Lane P3DE_0027: func_003d5750 under -O2,p. Tried: archive body with optimization_level 1 + opt_propagation off + schedule on (then off). Residual register allocation and branch-delay layout differed; no match. */
#pragma push
#pragma optimization_level 1
#pragma opt_propagation off
s32 func_003d5750(u8 *arg0) {
    u8 *obj;
    u8 *head;
    u8 *node;
    s32 stride;
    s32 count;
    obj = *(u8 **)arg0;
    head = *(u8 **)(arg0 + 0x10);
    stride = *(s32 *)(obj + 8);
    node = *(u8 **)head;
    count = 0;
    if (node != head) {
        do {
            node += stride;
            count += 1;
        } while (*(u8 **)node != head);
    }
    return count;
}
#pragma pop