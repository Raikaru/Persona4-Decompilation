/* object 256B/window 288B, normalized_diff 141, differing offsets 38,40,42,50,52,58,62,66,70,72,74,82,84,92,95,96...; classification UNDERSIZED/NEAR_MISS. Retail prologue frame 112B saves s5..s0 (six long-lived locals), incoming a0/a1; candidate frame exact but local register coloring (array/index/entry) and cleanup/allocation control-flow layout diverge. No movz/movn, COP1 accumulator, standalone MMI, framed tail-jump, or sd/sq mixed-unit floor. Ruled out schedule/no_branch_likely baseline, declaration-order permutations, generated-order locals, pointer-width variants, explicit cleanup labels, and callback table cast forms. */
u32 **func_003ce050(u32 **arg0, u32 arg1) {
    extern void func_003cc6e0(u8 *arg0);
    extern void func_003e1ea0(u8 *arg0);
    extern void func_0043f9c8(void *arg0, s32 arg1, s32 arg2);
    s32 index;
    u8 *array;
    u8 *entry;
    u32 *result;
    u32 count;
    u8 *node;

    array = *(u8 **)arg0;
    if (array != NULL) {
        count = *(u32 *)array;
        index = (s32)count - 1;
        if (count != 0) {
            entry = array + index * 4;
loop:
            node = *(u8 **)(entry + 4);
            if (node == NULL)
                goto advance;
            if (*(s32 *)node == 0)
                goto check_second;
            goto clear;
clear:
            *(s32 *)(node + 0x10) = 0;
            goto advance;
check_second:
            if (*(s32 *)(node + 4) != 0)
                goto clear;
            func_003cc6e0(node);
            func_003e1ea0(node);
advance:
            entry -= 4;
            if (index != 0)
                goto loop;
            index -= 1;
        }
        jtbl_008873EC[0](array);
        *arg0 = NULL;
    }
    result = ((u32 *(*)(u32, u32))jtbl_008873E8[0])((arg1 - 1) * 4 + 8, 0x3050D);
    *arg0 = result;
    if (result != NULL) {
        *result = arg1;
        func_0043f9c8(result + 1, 0, arg1 * 4);
    }
    return arg0;
}
