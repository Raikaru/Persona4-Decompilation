/* object 164 bytes, retail window 176 bytes, normalized_diff 19.
   Best reconstruction uses explicit stack traversal, schedule on, and
   no_branch_likely on. Retail has one extra nop before the common epilogue;
   direct loop/goto, return-label ordering, declaration ordering, and pragma
   variants were tried and ruled out. */
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
