/* object_size=240B window=240B normalized_diff=152 differing_offsets=0,4,8,12,16,20,24,28,32,36,40,48,56,76,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,156,160,164,168,172,176,180,184,188,192,196,204,208,212,216,220,224,228,236; classification=MWCC caller-saved/callee-saved coloring floor candidate: retail keeps base/result/list in $t0/$a0/$a2 across func_003e4420 with a 16-byte frame, while b210 emits a 48-byte frame and $s1/$s0. Ruled out direct and goto control-flow shapes, pointer/s32 scalar widths, declaration orders, result-parameter reuse, 0/2-argument block callee declarations, and scoped -O1/-O3 probes; prior CL3EA probe set also retained the same fallback. */
s32 func_003e45f0(u8 *arg0, s32 arg1) {
    s32 aligned;
    u8 *found;
    u8 *node;

    aligned = (arg1 + 0x1F) & ~0x1F;
    node = *(u8 **)(arg0 + 4);
    found = NULL;
search:
    if (node == NULL || found != NULL) {
        goto search_done;
    }
    if ((~(*(s32 *)(node + 0x10)) & 1) != 0 &&
        (u32)*(s32 *)(node + 0xC) >= (u32)aligned) {
        found = node;
    }
    node = *(u8 **)(node + 4);
    goto search;
search_done:
    if (found == NULL) {
        return 0;
    }
    if ((u32)(aligned + 0x40) < (u32)*(s32 *)(found + 0xC)) {
        {
            extern void func_003e4420();
            func_003e4420(found, aligned);
        }
    }
unlink_start:
    node = *(u8 **)(arg0 + 4);
unlink_check:
    if (found != node) {
        goto mark;
    }
    *(u8 **)(arg0 + 4) = *(u8 **)(node + 4);
    node = *(u8 **)(arg0 + 4);
    if (node == NULL) {
        goto mark;
    }
    if ((*(s32 *)(node + 0x10) & 1) != 0) {
        goto unlink_check;
    }
mark:
    *(s32 *)(found + 0x10) = 1;
    return (s32)(found + 0x20);
}
