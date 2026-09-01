/* object 204B/window 240B normalized_diff 56; differing offsets 4-12,20-88,96-196 and retail-only tail 204-236 (candidate is undersized); classification NEAR_MISS / prologue-and-control-flow residual. Retail has no movz/movn, COP1 accumulator chain, standalone MMI, framed tail-jump, or mixed-unit sd/sq floor. Best body uses schedule + no_branch_likely, do/while outer iteration, explicit search/after_search/increment/fail labels, block-scope func_003c47c0(s32 *) declaration, and separate base/target locals. Optimization_level 1 regressed to object 208B/nd 53; direct-goto and count/base declaration variants remained undersized. The durable residuals are retail's initial lw before sd $ra, literal-4/addiu-vs-li/addu setup, target-load delay nop, and out-of-line fail/epilogue placement. */
s32 func_003c4c00(u8 *arg0) {
    extern s32 func_003c47c0(s32 *arg0);
    u8 *self;
    s32 result;
    s32 index;
    s32 offset;
    s32 inner_index;
    s32 **p;
    s32 *current;
    s32 count;
    u8 *base_value;

    count = *(s32 *)(arg0 + 4);
    base_value = (u8 *)4;
    self = arg0;
    index = 0;
    result = (s32)(base_value + (count << 2));
    result += 12;
    if (count <= 0)
        goto return_result;
    offset = 0;
    do {
        inner_index = index - 1;
        if (index != 0) {
            s32 **base;
            base = *(s32 ***)self;
            p = base + inner_index;
            current = *(s32 **)((u8 *)base + offset);
search:
            if (*p == current)
                goto search_done;
            p -= 1;
            if (inner_index-- != 0)
                goto search;
        }
search_done:
        if (inner_index < 0)
            goto fail;
increment:
        index += 1;
        offset += 4;
    } while (index < *(s32 *)(self + 4));
return_result:
    return result;
fail:
    current = *(s32 **)((u8 *)(*(s32 ***)self) + offset);
    result += func_003c47c0(current) + 12;
    goto increment;
}
