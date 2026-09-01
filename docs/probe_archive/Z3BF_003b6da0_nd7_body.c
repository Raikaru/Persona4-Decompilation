/* CURRENT RECHECK: object 84B/window 96B, normalized_diff 7; first_diffs bytes 32,76,78,79,80,82,83. Best shape uses #pragma opt_propagation off plus #pragma schedule on around the function. The archived nd6 figure was stale under the current TU. Ruled out: plain O2, schedule-on alone, opt-propagation-off alone, optimization-level 1, no-branch-likely, base/store pointer forms, declaration-order variants, explicit else, self-assignment/zero-add, and explicit epilogue goto. */
void func_003b6da0(s32 arg0) {
    u8 *base;
    s32 value;
    s32 *ptr;
    s32 count;
    s32 factor;

    base = (u8 *)D_00885A90;
    value = arg0 | 1;
    iGpffffb680 = 0;
    ptr = (s32 *)(base + 4);
    count = 0x270;
    count -= 1;
    *(s32 *)D_00885A90 = value;
    if (count == 0) {
        goto done;
    }
    factor = 0x10DCD;
    do {
        value *= factor;
        count -= 1;
        *ptr = value;
        ptr += 1;
    } while (count != 0);
done:
    return;
}
