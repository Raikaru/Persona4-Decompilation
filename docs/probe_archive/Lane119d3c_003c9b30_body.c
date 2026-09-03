/* object_size=224 window=240 normalized_diff=120 differing_offsets=32,44,76,77,78,79,80,81,82,83,84,87,88,89,90,91 classification=branch-layout-and-call-order; ruled_out=while-structured,check-bltz,opt_rebuildconditionals; measured_compiles=5 */
/* measured: b119 stack-walk probe for c9b30; residual is first-loop branch targets
   (0x9b8c vs 0x9b90, 0x9b94 vs 0x9b98), the bgez placement, and missing nops before/after branches. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_003C9B30
u8 *func_003c9b30(u8 *arg0) {
    extern u8 *func_003c55f0(u16 arg0);
    extern u8 *func_003c8eb0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    u8 *self;
    u8 *current;
    s32 depth;
    u8 *temp;
    u8 *base;
    u8 *stack[64];

    self = arg0;
    current = *(u8 **)(arg0 + 0x1C);
    depth = 0;
    if (current == NULL)
        goto initial_null;
loop:
    if (*(s32 *)(current + 0) < 0)
        goto negative;
    temp = *(u8 **)(current + 0xC);
    depth += 1;
    current = *(u8 **)(current + 8);
    stack[depth] = temp;
check:
    if (depth >= 0)
        goto loop;
    return self;
initial_null:
    return NULL;
negative:
    base = *(u8 **)(self + 0x10) + (*(u16 *)(current + 0x80) * 4);
    if (*(s32 *)(current + 0x78) == 0) {
        temp = func_003c55f0(*(u16 *)(current + 0x84));
        if (temp == NULL)
            goto done_null;
        self = func_003c8eb0(self, temp, current, base);
        if (self == NULL)
            goto done_null;
    }
    current = stack[depth];
    depth -= 1;
    goto check;
done_null:
    return NULL;
}
/* measured: close c9b30 stack-walk probe. */
#pragma no_branch_likely off
#pragma schedule off
