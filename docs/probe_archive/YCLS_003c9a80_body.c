/* object 164 bytes, retail window 176 bytes, normalized_diff 19; differing words at offsets 80, 88 and 140-164: one compiler-emitted nop/branch-target displacement before the common epilogue shifts the tail, while retail has the callback jal and full epilogue. Schedule-on reproduces the archived size; loop shape, return-label order, declaration order, schedule/no_branch variants, and callback/null-test forms were ruled out. No conversion casts. */
u8 *func_003c9a80(u8 *arg0) {
    u8 *stack[64];
    u8 *self;
    u8 *current;
    s32 depth;
    s32 value;
    u8 *temp;

    self = arg0;
    current = *(u8 **)(self + 0x1C);
    depth = 0;
    if (current == NULL)
        goto done_null;
loop:
    if (*(s32 *)current < 0)
        goto negative;
    value = *(s32 *)(current + 0xC);
    depth += 1;
    current = *(u8 **)(current + 8);
    stack[depth] = (u8 *)value;
check:
    if (depth >= 0)
        goto loop;
    goto done_self;
done_self:
    return self;
done_null:
    return NULL;
negative:
    temp = *(u8 **)(current + 0x78);
    if (temp != NULL) {
        func_003c5760(temp);
        *(u8 **)(current + 0x78) = NULL;
    }
    current = stack[depth];
    depth -= 1;
    goto check;
}
